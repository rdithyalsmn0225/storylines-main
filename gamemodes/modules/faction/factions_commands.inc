CMD:createfaction(playerid, params[])
{
	if(IsPlayerAdmins(playerid) < ADMINS_OWNER)
		return 0;
		
	new varAbbrev[32], varName[128]; 
	
	if(sscanf(params, "s[32]s[90]", varAbbrev, varName))
	{
		SendUsageMessage(playerid, "/createfaction [faction abbreviation] [faction name]");
		SendTipMessage(playerid, "Do not use spaces for the abbreviation.");
		return 1; 
	}
	
	if(strlen(varName) > 90)
		return SendErrorMessage(playerid, "Your factions name needs to be shorter."); 
		
	new idx = 0;
	
	for (new i = 1; i < MAX_FACTIONS; i ++)
	{
		if(!FactionInfo[i][E_FACTION_DBID])
		{
			idx = i; 
			break;
		}
	}
	if(idx == 0)
	{
		return SendErrorMessage(playerid, "The server has met the maximum amount of factions."); 
	}

	SendInfoMessage(playerid, "Creating the faction..."); 	
	
	format(FactionInfo[idx][E_FACTION_NAME], 128, "%s", varName);
	format(FactionInfo[idx][E_FACTION_ABBREV], 32, "%s", varAbbrev); 

	new thread[256]; 
	mysql_format(ourConnection, thread, sizeof(thread), "INSERT INTO factions (`FactionName`, `FactionAbbrev`) VALUES('%s', '%s')", FactionInfo[idx][E_FACTION_NAME], FactionInfo[idx][E_FACTION_ABBREV]);
	mysql_pquery(ourConnection, thread, "Query_InsertFaction", "issi", playerid, FactionInfo[idx][E_FACTION_NAME], FactionInfo[idx][E_FACTION_ABBREV], idx);
	return 1;
}

CMD:editfaction(playerid, params[])
{
	if(IsPlayerAdmins(playerid) < ADMINS_OWNER)
		return 0;
		
	new factionid, oneString[60], secString[90]; 
		
	if (sscanf(params, "ds[60]S()[90]", factionid, oneString, secString))
	{
		SendUsageMessage(playerid, "/editfaction [faction id] [configuration]");
		SendTipMessage(playerid, "type, color, spawn"); 
		return 1;
	}
	
	if(!FactionInfo[factionid][E_FACTION_DBID])
		return SendErrorMessage(playerid, "The faction you specified doesn't exist.");
	
	if(!strcmp(oneString, "type"))
	{
		new type;
		
		if(sscanf(secString, "d", type))
		{
			SendUsageMessage(playerid, "/editfaction factionid type [type id]");
			SendInfoMessage(playerid, "1. Illegal, 2. Police, 3. Medical"); 
			return 1;
		}
		
		if(type > 3 || type < 1)
			return SendErrorMessage(playerid, "You specified an invalid faction type."); 
			
		FactionInfo[factionid][E_FACTION_TYPE] = type; 
		
		new 
			typeName[32];
		
		if(type == 1) typeName = "Illegal";
		if(type == 2) typeName = "Police";
		if(type == 3) typeName = "Medical";
		
		SendInfoMessage(playerid, "You set faction #%d type to %s.", factionid, typeName);
		SaveFaction(factionid);
	}
	else if(!strcmp(oneString, "color"))
	{
		new hexcolor; 
		
		if(sscanf(secString, "x", hexcolor))
		{
			SendUsageMessage(playerid, "/editfaction factionid color [hexcode]");
			SendTipMessage(playerid, "This is the color faction chat is shown in. Example: 0x8D8DFFFF"); 
			return 1;
		}
		
		FactionInfo[factionid][E_FACTION_COLORHEX] = hexcolor;
		SendInfoMessage(playerid, "You set faction #%d chat color to \"%x\". ", factionid, hexcolor);
		
		SaveFaction(factionid);
	}
	else if(!strcmp(oneString, "spawn"))
	{
		GetPlayerPos(playerid, FactionInfo[factionid][E_FACTION_SPAWN][0], FactionInfo[factionid][E_FACTION_SPAWN][1], FactionInfo[factionid][E_FACTION_SPAWN][2]);
		
		FactionInfo[factionid][E_FACTION_SPAWNINT] = GetPlayerInterior(playerid);
		FactionInfo[factionid][E_FACTION_SPAWNWORLD] = GetPlayerVirtualWorld(playerid);
		
		if(GetPlayerInterior(playerid) != 0)
			FactionInfo[factionid][E_FACTION_SPAWNWORLD] = 0; 
		
		else FactionInfo[factionid][E_FACTION_SPAWNWORLD] = GetPlayerVirtualWorld(playerid);
		
		SendInfoMessage(playerid, "You changed faction #%d spawn point.", factionid); 

		if(IsValidDynamicPickup(FactionInfo[factionid][E_FACTION_SPAWNPICKUP]))
			DestroyDynamicPickup(FactionInfo[factionid][E_FACTION_SPAWNPICKUP]); 
		if(IsValidDynamic3DTextLabel(FactionInfo[factionid][E_FACTION_SPAWNTEXT]))
			DestroyDynamic3DTextLabel(FactionInfo[factionid][E_FACTION_SPAWNTEXT]);

		FactionInfo[factionid][E_FACTION_SPAWNPICKUP] = CreateDynamicPickup(1314, 1, FactionInfo[factionid][E_FACTION_SPAWN][0], FactionInfo[factionid][E_FACTION_SPAWN][1], FactionInfo[factionid][E_FACTION_SPAWN][2], FactionInfo[factionid][E_FACTION_SPAWNWORLD], FactionInfo[factionid][E_FACTION_SPAWNINT]);
		FactionInfo[factionid][E_FACTION_SPAWNTEXT] = CreateDynamic3DTextLabel("[Faction Spawn Point]", COLOR_3DTEXT, FactionInfo[factionid][E_FACTION_SPAWN][0], FactionInfo[factionid][E_FACTION_SPAWN][1], FactionInfo[factionid][E_FACTION_SPAWN][2], 5.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, FactionInfo[factionid][E_FACTION_SPAWNWORLD], FactionInfo[factionid][E_FACTION_SPAWNINT]);

		SaveFaction(factionid);
	}
	else return SendErrorMessage(playerid, "Invalid Parameter.");
	return 1;
}

CMD:setpfaction(playerid, params[])
{
	if(IsPlayerAdmins(playerid) < ADMINS_OPERATOR)
		return SendUnauthMessage(playerid);
		
	new playerb, factionid, str[128];
	
	if(sscanf(params, "ud", playerb, factionid))
		return SendUsageMessage(playerid, "/setpfaction [playerid OR name] [faction id]");
		
	if(!IsPlayerConnected(playerb))
		return SendErrorMessage(playerid, "The player you specified isn't connected.");
		
	if(AccountInfo[playerb][E_MASTERS_LOGGED] == false)
		return SendErrorMessage(playerid, "The player you specified isn't logged in."); 
		
	if(!FactionInfo[factionid][E_FACTION_DBID]) return SendErrorMessage(playerid, "The faction you specified doesn't exist.");
	
	if(PlayerInfo[playerb][E_CHARACTER_FACTION] != 0)
	{
		new detailStr[128];
		
		format(detailStr, sizeof(detailStr), "{FFFFFF}%s is already in a faction. Would you like to continue?", ReturnName(playerb));
		ConfirmDialog(playerid, "Confirmation", detailStr, "OnSetFaction", playerb, factionid);
		return 1;
	}
	

	PlayerInfo[playerb][E_CHARACTER_FACTION] = factionid;
	PlayerInfo[playerb][E_CHARACTER_FACTIONRANK] = 4; 
	
	SaveCharacter(playerb);
		
	format(str, sizeof(str), "%s set %s's faction to %d.", ReturnName(playerid), ReturnName(playerb), factionid);
	SendAdminMessage(4, str); SendClientMessage(playerb, COLOR_YELLOW, str);
	
	SendInfoMessage(playerb, "You were set to faction %d by Admin %s.", factionid, ReturnName(playerid));
	
	return 1;
}