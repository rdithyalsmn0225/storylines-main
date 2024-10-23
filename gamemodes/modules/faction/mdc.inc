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

function:OnMDCPlate(playerid)
{	
	if(!cache_num_rows())
	{
		for(new i = 0; i < 5; i++) PlayerPlateSaver[playerid][i] = "";
		format(PlayerInfo[playerid][E_CHARACTER_MDCPLAYER], 32, ""); 
		
		return ShowPlayerDialog(playerid, DIALOG_MDC_PLATE, DIALOG_STYLE_INPUT, "View Plates:", "The plate you inputted was not found.\nPlease enter the vehicle plates:", "Submint", "Cancel"); 
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
	
	ShowPlayerDialog(playerid, DIALOG_MDC_PLATELIST, DIALOG_STYLE_LIST, "View Plates", str, "Select", "<<"); 
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
		
		primary_str[512],
		sub_str[512]
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

	ShowPlayerDialog(playerid, DIALOG_MDC, DIALOG_STYLE_LIST, "Mobile Data Computer:", "Place Charges\nView Charges\nView Plates", "Select", "Cancel");
	return 1;
}

CMD:charge(playerid, params[])
{
	new
	    userid;

    if(!PlayerInfo[playerid][E_CHARACTER_FACTION])
		return SendErrorMessage(playerid, "You aren't in any faction.");
		
	if(FactionInfo[PlayerInfo[playerid][E_CHARACTER_FACTION]][E_FACTION_TYPE] != FACTION_TYPE_POLICE)
		return SendErrorMessage(playerid, "You can't use this command."); 

	if(sscanf(params, "u", userid))
		return SendUsageMessage(playerid, "/charge [playerid OR name]"); 

	if (!IsPlayerNearPlayer(playerid, userid, 10.0))
	    return SendErrorMessage(playerid, "The player is disconnected or not near you.");

	//if (!PlayerInfo[userid][E_CHARACTER_HANDCUFF])
	    //return SendErrorMessage(playerid, "The player must be cuffed before an arrest is made.");

	if (!IsPlayerInRangeOfPoint(playerid, 4.0, 252.9687,90.9530,1002.4453))
	    return SendErrorMessage(playerid, "You aren't near charge point.");

	PlayerInfo[playerid][E_CHARACTER_MDCSELECT] = userid;

	new str[2048];
	strcat(str, "Description\n");
	forex(i, sizeof(PenalInfo)){
		format(str, sizeof(str), "%s%s\n", str, PenalInfo[i][E_PENALCODES_TYPE]);
    }
	Dialog_ShowPages(playerid, Charges, DIALOG_STYLE_TABLIST_HEADERS, "State Penal Code (Arrest Offesenses):", str, "Select", "Cancel");
    return 1;
}

Dialog:Charges(playerid, response, listitem, inputtext[]) 
{
	if(response)
	{
		new str[256];
		PlayerInfo[playerid][E_CHARACTER_MDCCHARGE] = PenalInfo[listitem][E_PENALCODES_CHARGES];
		PlayerInfo[playerid][E_CHARACTER_MDCTIME] = PenalInfo[listitem][E_PENALCODES_JAILTIME];
		format(PlayerInfo[playerid][E_CHARACTER_MDCPLAYER], 32, "%s", PlayerInfo[PlayerInfo[playerid][E_CHARACTER_MDCSELECT]][E_CHARACTER_STREETNAME]);
		format(PlayerInfo[playerid][E_CHARACTER_MDCDESC], 128, "%s", PenalInfo[listitem][E_PENALCODES_TYPE]);

		format(str, sizeof(str), "Suspect: %s\nDescription: (%s) %.150s\nCharges: {B3C99E}$%d{ffffff}\nJail Times: %d Month (Minutes)", PlayerInfo[PlayerInfo[playerid][E_CHARACTER_MDCSELECT]][E_CHARACTER_STREETNAME], PenalInfo[listitem][E_PENALCODES_TYPE], PenalInfo[listitem][E_PENALCODES_NAME], PenalInfo[listitem][E_PENALCODES_CHARGES], PenalInfo[listitem][E_PENALCODES_JAILTIME]);
		Dialog_Show(playerid, ChargesSelect, DIALOG_STYLE_MSGBOX, "State Penal Code (Arrest Offesenses):", str, "Enter", "Cancel");
	}
	return 1;
}

Dialog:ChargesSelect(playerid, response, listitem, inputtext[]) 
{
	if(response)
	{
		SetPlayerInPrison(PlayerInfo[playerid][E_CHARACTER_MDCSELECT]);
		
		ResetPlayerWeapons(PlayerInfo[playerid][E_CHARACTER_MDCSELECT]);
		SaveCharacter(PlayerInfo[playerid][E_CHARACTER_MDCSELECT]);
		RemovePlayerAttachedObject(playerid, 0);
		PlayerInfo[PlayerInfo[playerid][E_CHARACTER_MDCSELECT]][E_CHARACTER_HANDCUFF] = false;
		SetPlayerSpecialAction(PlayerInfo[playerid][E_CHARACTER_MDCSELECT], SPECIAL_ACTION_NONE);

		GiveMoney(PlayerInfo[playerid][E_CHARACTER_MDCSELECT], -PlayerInfo[playerid][E_CHARACTER_MDCCHARGE]);

		AddWanted(PlayerInfo[playerid][E_CHARACTER_MDCPLAYER], PlayerInfo[playerid][E_CHARACTER_MDCDESC]);
	}
	return 1;
}