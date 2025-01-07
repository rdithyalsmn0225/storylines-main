function:Query_LoadEntrance()
{
	if(!cache_num_rows())
		return printf("[SERVER]: No entrance were loaded from \"%s\" database...", SQL_DATABASE);
	
	new rows, fields; 
	cache_get_row_count(rows);
	cache_get_field_count(fields);
	new countEntrance = 0;

	for(new i = 0; i < rows && i < MAX_ENTRANCE; i++)
	{
		cache_get_value_name_int(i, "ID", EntranceInfo[i+1][E_ENTRANCE_DBID]);

		cache_get_value_name_float(i, "posx", EntranceInfo[i+1][E_ENTRANCE_POS][0]);
		cache_get_value_name_float(i, "posy", EntranceInfo[i+1][E_ENTRANCE_POS][1]);
		cache_get_value_name_float(i, "posz", EntranceInfo[i+1][E_ENTRANCE_POS][2]);
		
		cache_get_value_name_float(i, "intx", EntranceInfo[i+1][E_ENTRANCE_INT][0]);
		cache_get_value_name_float(i, "inty", EntranceInfo[i+1][E_ENTRANCE_INT][1]);
		cache_get_value_name_float(i, "intz", EntranceInfo[i+1][E_ENTRANCE_INT][2]);
		
		cache_get_value_name_int(i, "interior", EntranceInfo[i+1][E_ENTRANCE_INTERIOR]);
		cache_get_value_name_int(i, "world", EntranceInfo[i+1][E_ENTRANCE_WORLD]);
        cache_get_value_name_int(i, "icon", EntranceInfo[i+1][E_ENTRANCE_ICON]);
		cache_get_value_name_int(i, "garage", EntranceInfo[i+1][E_ENTRANCE_GARAGE]);
	
		EntranceInfo[i+1][E_ENTRANCE_PICKUP] = CreateDynamicPickup(19198, 1, EntranceInfo[i+1][E_ENTRANCE_POS][0], EntranceInfo[i+1][E_ENTRANCE_POS][1], EntranceInfo[i+1][E_ENTRANCE_POS][2], 0, 0, -1, 5.0);
        
		countEntrance++; 
	}
	
	printf("[SERVER]: %i entrance were loaded from \"%s\" database...", countEntrance, SQL_DATABASE);
	return 1;
}

function:OnEntranceCreate(playerid, newid, icon)
{	
	EntranceInfo[newid][E_ENTRANCE_DBID] = cache_insert_id(); 
    EntranceInfo[newid][E_ENTRANCE_ICON] = icon;
	SendServerMessage(playerid, "You created entrance ID #%i. To configure, use \"/editentrance\". ", newid); 
	return 1;
}

function:OnENTEntranceChange(playerid, response, newid)
{
	if(response)
	{
		GetPlayerPos(playerid, EntranceInfo[newid][E_ENTRANCE_POS][0], EntranceInfo[newid][E_ENTRANCE_POS][1], EntranceInfo[newid][E_ENTRANCE_POS][2]);
		
		if(IsValidDynamicPickup(EntranceInfo[newid][E_ENTRANCE_PICKUP]))
			DestroyDynamicPickup(EntranceInfo[newid][E_ENTRANCE_PICKUP]); 
        
		EntranceInfo[newid][E_ENTRANCE_PICKUP] = CreateDynamicPickup(19130, 1, EntranceInfo[newid][E_ENTRANCE_POS][0], EntranceInfo[newid][E_ENTRANCE_POS][1], EntranceInfo[newid][E_ENTRANCE_POS][2], 0, 0, -1, 5.0);
        
		SaveEntrance(newid);
		SendServerMessage(playerid, "You set entrance #%i's entrance.", newid);
	}
	return 1;
}

function:OnENTInteriorChange(playerid, response, newid)
{
	if(response)
	{
		GetPlayerPos(playerid, EntranceInfo[newid][E_ENTRANCE_INT][0], EntranceInfo[newid][E_ENTRANCE_INT][1], EntranceInfo[newid][E_ENTRANCE_INT][2]);
		
		EntranceInfo[newid][E_ENTRANCE_INTERIOR] = GetPlayerInterior(playerid);
		EntranceInfo[newid][E_ENTRANCE_WORLD] = GetPlayerVirtualWorld(playerid);
		
		foreach(new i : Player) if(IsPlayerInEntrance(i) == newid)
		{
			SetPlayerPosEx(i, EntranceInfo[newid][E_ENTRANCE_INT][0], EntranceInfo[newid][E_ENTRANCE_INT][1], EntranceInfo[newid][E_ENTRANCE_INT][2]);
			SetPlayerInteriorEx(i, GetPlayerInterior(playerid)); SetPlayerVirtualWorldEx(i, GetPlayerVirtualWorld(playerid)); 
			
			SendServerMessage(i, "The entrance you were in was amended."); 
		}
		
		SaveEntrance(newid);
		SendServerMessage(playerid, "You set entrance #%i's interior.", newid);
	}
	return 1;
}

stock IsPlayerInEntrance(playerid)
{
	if(PlayerInfo[playerid][E_CHARACTER_INSIDEENT])
	{
		for(new i = 1; i < MAX_ENTRANCE; i++)
		{
			if(i == PlayerInfo[playerid][E_CHARACTER_INSIDEENT] && GetPlayerVirtualWorld(playerid) == EntranceInfo[i][E_ENTRANCE_WORLD])
				return i;
		}
	}
	return 0;
}

stock IsPlayerNearEntrance(playerid)
{
	for(new i = 1; i < MAX_ENTRANCE; i++)
	{
		if(IsPlayerInRangeOfPoint(playerid, 3.0, EntranceInfo[i][E_ENTRANCE_POS][0], EntranceInfo[i][E_ENTRANCE_POS][1], EntranceInfo[i][E_ENTRANCE_POS][2]))
			return i;
	} 
	return 0; 
}

function:OnPlayerEnterEntrance(playerid, id)
{
	PlayerEnterTimer[playerid] = false;
	return TogglePlayerControllable(playerid, true);
}

CMD:createentrance(playerid, params[])
{
	if(IsPlayerAdmins(playerid) < ADMINS_OWNER)
		return SendUnauthMessage(playerid);
		
	new 
		icon, 
		idx,
		query[128]
	; 
	
	if(sscanf(params, "i", icon))
	{
		SendUsageMessage(playerid, "/createentrance [mapicon]");
		return 1;
	}

	for(new i = 1; i < MAX_ENTRANCE; i++)
	{
		if(!EntranceInfo[i][E_ENTRANCE_DBID])
		{
			idx = i;
			break;
		}
	}
		
	if(idx == 0)
		return SendErrorMessage(playerid, "You can't make anymore entrance."); 

	mysql_format(ourConnection, query, sizeof(query), "INSERT INTO entrance (`icon`) VALUES(%i)", icon);
	mysql_pquery(ourConnection, query, "OnEntranceCreate", "iii", playerid, idx, icon);
	return 1;
}

CMD:editentrance(playerid, params[])
{
	if(IsPlayerAdmins(playerid) < ADMINS_OWNER)
		return SendUnauthMessage(playerid);
		
	new id, indx[60], specifier[60];
	
	if(sscanf(params, "is[60]S()[60]", id, indx, specifier))
	{
		SendUsageMessage(playerid, "/editentrance [property id] [configuration]");
		SendTipMessage(playerid, "Entrance, Interior, MapIcon");
		return 1; 
	}
	
	if(!EntranceInfo[id][E_ENTRANCE_DBID] || id > MAX_ENTRANCE)
		return SendErrorMessage(playerid, "That Property doesn't exist.");
	
	if(!strcmp(indx, "entrance"))
	{
		ConfirmDialog(playerid, "Confirmation", "Are you sure you want to set this properties entrance?", "OnENTEntranceChange", id); 
	}
	else if(!strcmp(indx, "interior"))
	{
		ConfirmDialog(playerid, "Confirmation", "Are you sure you want to set this properties entrance?", "OnENTInteriorChange", id); 
	}
	else if(!strcmp(indx, "icon"))
	{
		new icon;
		
		if(sscanf(specifier, "i", icon))
		{
			SendUsageMessage(playerid, "/editentrance %i icon [mapicon]", id);
			return 1;
		}
		
		EntranceInfo[id][E_ENTRANCE_MAPICON] = icon;
		SaveProperty(id);
		
		SendServerMessage(playerid, "You set entrance #%i's icon to %s.", id, icon);	
	}
	else return SendErrorMessage(playerid, "Invalid Paramater.");	
	return 1;
}