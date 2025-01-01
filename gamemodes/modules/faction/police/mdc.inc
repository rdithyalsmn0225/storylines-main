//Function
stock AddWanted(targetid[], const description[])
{
	new string[512];

	format(string, sizeof(string), "INSERT INTO `criminal_record` (`player_name`, `add_date`, `charge_reason`) VALUES('%s', '%s', '%s')", targetid, ReturnDate(), description);
	mysql_pquery(ourConnection, string);
}

function:OnViewCharges(extraid, name[])
{
	if (ReturnFactionType(extraid) != FACTION_TYPE_POLICE)
	    return 0;

	static
	    rows,
	    fields;

	cache_get_row_count(rows);
	cache_get_field_count(fields);

	if (!rows)
	    return SendErrorMessage(extraid, "No results found for charges on \"%s\".", name);

	static
	    string[512],
		desc[128],
		date[36];

	string[0] = 0;

	for (new i = 0; i < rows; i ++) {
	    cache_get_value_name(i, "charge_reason", desc, 128);
	    cache_get_value_name(i, "add_date", date, 36);

	    format(string, sizeof(string), "%s%s (%s)\n", string, desc, date);
	}
	format(desc, sizeof(desc), "Charges: %s", name);
	ShowPlayerDialog(extraid, DIALOG_DEFAULT, DIALOG_STYLE_LIST, desc, string, "Close", "");
	return 1;
}

stock ViewCharges(playerid, name[])
{
	new
	    string[128];

	format(string, sizeof(string), "SELECT * FROM `criminal_record` WHERE `player_name` = '%s' ORDER BY `idx` DESC", name);
	mysql_pquery(ourConnection, string, "OnViewCharges", "ds", playerid, name);
	return 1;
}

stock ShowPlayerMDC(playerid)
{
	forex(i, 14)
	{
		PlayerTextDrawShow(playerid, MDC[i][playerid]);
	}
	return 1;
}

stock HidePlayerMDC(playerid)
{
	forex(i, 14)
	{
		PlayerTextDrawHide(playerid, MDC[i][playerid]);
	}
	return 1;
}

function:OnMDCPlate(playerid)
{	
	if(!cache_num_rows())
	{
		for(new i = 0; i < 5; i++) PlayerPlateSaver[playerid][i] = "";
		format(PlayerInfo[playerid][E_CHARACTER_MDCPLAYER], 32, ""); 
		
		return Dialog_Show(playerid, DialogMDCPlate, DIALOG_STYLE_INPUT, "View Plates:", "The plate you inputted was not found.\nPlease enter the vehicle plates:", "Submint", "Cancel"); 
	}
	
	new rows, fields, str[128];
	cache_get_row_count(rows);
	cache_get_field_count(fields);
	
	for(new i = 0; i < rows; i++)
	{
		cache_get_value_name(i, "VehiclePlates", PlayerPlateSaver[playerid][i], 20); 
	}
	
	for(new i = 0; i < 5; i++)
	{
		if(!isnull(PlayerPlateSaver[playerid][i]))
		{
			format(str, sizeof(str), "%s%s\n", str, PlayerPlateSaver[playerid][i]);
		}
	}
	
	Dialog_Show(playerid, DialogMDCPlateList, DIALOG_STYLE_LIST, "View Plates", str, "Select", "<<"); 
	return 1;
}

function:OnPlateSelect(playerid, listitem)
{
	new rows, fields;
	cache_get_row_count(rows);
	cache_get_field_count(fields);
	
	new
		model, 
		owner,
		impounded,
		
		primary_str[128],
		sub_str[128]
	;
	
	cache_get_value_name_int(0, "VehicleModel", model);
	cache_get_value_name_int(0, "VehicleOwnerDBID", owner);
	cache_get_value_name_int(0, "VehicleImpounded", impounded);
	
	format(sub_str, sizeof(sub_str), "Plate: %s\n", PlayerPlateSaver[playerid][listitem]);
	strcat(primary_str, sub_str);
	
	format(sub_str, sizeof(sub_str), "Registered owner: %s\n", ReturnDBIDName(owner));
	strcat(primary_str, sub_str); 
	
	if(impounded)
		strcat(primary_str, "Impounded: Yes\n"); 
		
	else strcat(primary_str, "Impounded: No\n");
	
	for(new i = 0; i < 5; i++) PlayerPlateSaver[playerid][i] = "";
	format(PlayerInfo[playerid][E_CHARACTER_MDCPLAYER], 32, ""); 
	
	ShowPlayerDialog(playerid, DIALOG_DEFAULT, DIALOG_STYLE_MSGBOX, "Mobile Database Computer:", primary_str, "Close", "");
	return 1;
}

CMD:mdc(playerid, params[])
{
   	if(ReturnFactionType(playerid) != FACTION_TYPE_POLICE)
		return SendUnauthMessage(playerid);
		
	if(!IsPlayerInAnyVehicle(playerid))
		return SendErrorMessage(playerid, "You aren't in a vehicle.");
		
	if(GetPlayerVehicleSeat(playerid) > 1)
		return SendErrorMessage(playerid, "You can't use the MDC from back there.");
		
	if(!IsPoliceVehicle(GetPlayerVehicleID(playerid)))
		return SendErrorMessage(playerid, "This vehicle doesn't have mdc!");

	SelectTextDraw(playerid, COLOR_YELLOW);
	ShowPlayerMDC(playerid);
	return 1;
}