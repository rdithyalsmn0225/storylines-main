//Faction commands:
CMD:factions(playerid, params[])
{
	new str[256], longstr[256]; 

	for (new i = 1; i < MAX_FACTIONS; i ++)
	{
		if(!FactionInfo[i][E_FACTION_DBID])
			continue;
			
		format(str, sizeof(str), "%d\t%s\t[%d out of %d]\n", i, FactionInfo[i][E_FACTION_NAME], ReturnOnlineMembers(i), ReturnTotalMembers(i));
		strcat(longstr, str);
	}
	
	ShowPlayerDialog(playerid, DIALOG_DEFAULT, DIALOG_STYLE_TABLIST, "Factions:", longstr, "Select", ""); 
	return 1;
}

CMD:faction(playerid, params[]) cmd_f(playerid, params);
CMD:f(playerid, params[])
{
	if(!IsPlayerFaction(playerid))
		return SendErrorMessage(playerid, "You aren't in any faction."); 

	if(isnull(params)) return SendUsageMessage(playerid, "/f [text]");
	
	if(FactionInfo[PlayerInfo[playerid][E_CHARACTER_FACTION]][E_FACTION_CHATSTATUS] == true)
	{
			
		if(strlen(params) > 79)
		{
			SendFactionMessage(playerid, "**(( %s %s: %.79s ))**", IsPlayerFactionRank(playerid), ReturnName(playerid), params); 
			SendFactionMessage(playerid, "**(( %s %s: ...%s ))**", IsPlayerFactionRank(playerid), ReturnName(playerid), params[79]); 
		}
		else SendFactionMessage(playerid, "**(( %s %s: %s ))**", IsPlayerFactionRank(playerid), ReturnName(playerid), params); 
		return 1;
	}
	
	if(strlen(params) > 79)
	{
		SendFactionMessage(playerid, "**(( %s %s: %.79s ))**", IsPlayerFactionRank(playerid), ReturnName(playerid), params); 
		SendFactionMessage(playerid, "**(( %s %s: ...%s ))**", IsPlayerFactionRank(playerid), ReturnName(playerid), params[79]); 
	}
	else SendFactionMessage(playerid, "**(( %s %s: %s ))**", IsPlayerFactionRank(playerid), ReturnName(playerid), params); 		
	return 1;
}

CMD:finvite(playerid, params[])
{
	new playerb;
	
	if(!IsPlayerFaction(playerid))
		return SendErrorMessage(playerid, "You aren't in any faction.");
		
	if(PlayerInfo[playerid][E_CHARACTER_FACTIONRANK] < 4)
		return SendErrorMessage(playerid, "You don't have permission to use this command."); 
	
	if(sscanf(params, "u", playerb))
		return SendUsageMessage(playerid, "/finvite [playerid OR name]");
		
	if(!IsPlayerConnected(playerb))
		return SendErrorMessage(playerid, "The player you specified isn't connected."); 
		
	if(AccountInfo[playerb][E_MASTERS_LOGGED] == false)
		return SendErrorMessage(playerid, "The player you specified hasn't logged in yet.");
		
	if(PlayerInfo[playerb][E_CHARACTER_FACTION])
		return SendErrorMessage(playerid, "The player you specified IS already in a faction."); 
		
	PlayerInfo[playerb][E_CHARACTER_FACTIONINVITE] = PlayerInfo[playerid][E_CHARACTER_FACTION];	
	PlayerInfo[playerb][E_CHARACTER_FACTIONINVITED] = playerid;
	
	SendTipMessage(playerb, "%s has invited you to join the %s, type /approve faction to join.", ReturnName(playerid), ReturnFactionName(playerid));
	SendServerMessage(playerid, "You invited %s to join the %s.", ReturnName(playerb), ReturnFactionName(playerid));
	return 1;
}

CMD:funinvite(playerid, params[])
{
	new playerb;
	
	if(!IsPlayerFaction(playerid))
		return SendErrorMessage(playerid, "You aren't in any faction.");
		
	if(PlayerInfo[playerid][E_CHARACTER_FACTIONRANK] < 4)
		return SendErrorMessage(playerid, "You don't have permission to use this command."); 
	
	if(sscanf(params, "u", playerb))
		return SendUsageMessage(playerid, "/uninvite [playerid OR name]");
		
	if(!IsPlayerConnected(playerb))
		return SendErrorMessage(playerid, "The player you specified isn't connected."); 
		
	if(AccountInfo[playerb][E_MASTERS_LOGGED] == false)
		return SendErrorMessage(playerid, "The player you specified hasn't logged in yet.");
		
	if(PlayerInfo[playerb][E_CHARACTER_FACTION] != PlayerInfo[playerid][E_CHARACTER_FACTION])
		return SendErrorMessage(playerid, "The player you specified IS not in your faction.");
	
	SendServerMessage(playerid, "You were uninvited from the %s by %s!", ReturnFactionNameEx(PlayerInfo[playerid][E_CHARACTER_FACTION]), ReturnName(playerid));
	SendServerMessage(playerid, "You uninvited %s!", ReturnName(playerb));
	
	PlayerInfo[playerb][E_CHARACTER_FACTION] = 0;
	PlayerInfo[playerb][E_CHARACTER_FACTIONRANK] = 0;

	SetPlayerSkin(playerb, PlayerInfo[playerb][E_CHARACTER_LASTSKIN]);
	SaveCharacter(playerb);
	return 1;
}

CMD:founinvite(playerid, params[])
{
	if(!IsPlayerFaction(playerid))
		return SendErrorMessage(playerid, "You aren't in any faction.");
		
	if(PlayerInfo[playerid][E_CHARACTER_FACTIONRANK] < 4)
		return SendErrorMessage(playerid, "You don't have permission to use this command."); 
		
	new thread[128];
		
	if(isnull(params))
		return SendUsageMessage(playerid, "/ouninvite [Firstname_Lastname]"); 
		
	foreach(new i : Player)
	{
		if(!strcmp(ReturnName(i, i), params))
		{
			SendClientMessageEx(playerid, COLOR_FACTION, "%s is connected to the server. (ID: %i)", ReturnName(i, i), i);
			return 1;
		}
	}
	
	mysql_format(ourConnection, thread, sizeof(thread), "SELECT char_dbid, pFaction, pFactionRank FROM characters WHERE char_name = '%e'", params);
	new Cache:cache = mysql_query(ourConnection, thread);
	
	if(!cache_num_rows())
	{
		SendClientMessageEx(playerid, COLOR_FACTION, "%s does not exist in the database.", params);
		cache_delete(cache);
		return 1;
	}
	
	new playerDBID, playerRank, playerFaction;
	
	cache_get_value_name_int(0, "char_dbid", playerDBID); 
	cache_get_value_name_int(0, "pFaction", playerFaction);
	cache_get_value_name_int(0, "pFactionRank", playerRank);
	
	if(playerFaction != PlayerInfo[playerid][E_CHARACTER_FACTION])
		return SendErrorMessage(playerid, "%s is not in your faction.", params); 
		
	if(playerRank > PlayerInfo[playerid][E_CHARACTER_FACTIONRANK])
		return SendErrorMessage(playerid, "%s exceeds your faction rank.", params);
		
	
	mysql_format(ourConnection, thread, sizeof(thread), "UPDATE characters SET pFaction = 0, pFactionRank = 0, pLastSkin = 252 WHERE char_dbid = %i", playerDBID);
	mysql_pquery(ourConnection, thread); cache_delete(cache);
	
	SendClientMessageEx(playerid, COLOR_FACTION, "%s was removed from the faction.", params);
	return 1;
}

CMD:frank(playerid, params[])
{
	new playerb, rank;
	
	if(!IsPlayerFaction(playerid))
		return SendErrorMessage(playerid, "You aren't in any faction.");
		
	if(PlayerInfo[playerid][E_CHARACTER_FACTIONRANK] < 4)
		return SendErrorMessage(playerid, "You don't have permission to use this command."); 
	
	if(sscanf(params, "ui", playerb, rank))
	{
		SendUsageMessage(playerid, "/frank [playerid OR name] [rank id 1 > 4]");
		return 1;
	}
	
	if(rank < 1 || rank > 4)
		return SendErrorMessage(playerid, "You specified an invalid rank."); 
		
	if(!IsPlayerConnected(playerb))
		return SendErrorMessage(playerid, "The player you specified isn't connected."); 

	if (playerb == INVALID_PLAYER_ID)
	    return SendErrorMessage(playerid, "That player is disconnected.");

	if (playerb == playerid)
	    return SendErrorMessage(playerid, "You cannot set your own rank.");
		
	if(AccountInfo[playerb][E_MASTERS_LOGGED] == false)
		return SendErrorMessage(playerid, "The player you specified hasn't logged in yet.");
		
	if(PlayerInfo[playerb][E_CHARACTER_FACTION] != PlayerInfo[playerid][E_CHARACTER_FACTION])
		return SendErrorMessage(playerid, "The player you specified Is not in your faction.");
		
	if(PlayerInfo[playerb][E_CHARACTER_FACTIONRANK] > 4)
		return SendErrorMessage(playerid, "You can't alter 4 rank.", ReturnName(playerb)); 
		
	SendServerMessage(playerb, "Your rank has been upgraded from %s to %s by %s!", FactionRanks[PlayerInfo[playerb][E_CHARACTER_FACTION]][PlayerInfo[playerb][E_CHARACTER_FACTIONRANK]], FactionRanks[PlayerInfo[playerb][E_CHARACTER_FACTION]][rank], ReturnName(playerid)); 
	SendServerMessage(playerid, "You upgraded %s rank from %s to %s!", ReturnName(playerb), FactionRanks[PlayerInfo[playerb][E_CHARACTER_FACTION]][PlayerInfo[playerb][E_CHARACTER_FACTIONRANK]], FactionRanks[PlayerInfo[playerb][E_CHARACTER_FACTION]][rank]);
		
	PlayerInfo[playerb][E_CHARACTER_FACTIONRANK] = rank; 
	SaveCharacter(playerb);
	return 1;
}

CMD:factionon(playerid, params[])
{
	new factionid;
	
	if(sscanf(params, "I(-1)", factionid))
		return SendUsageMessage(playerid, "/factionon [factionid]");
		
	if(factionid == -1)
	{
		if(!IsPlayerFaction(playerid))
			return SendErrorMessage(playerid, "You aren't in any faction.");
		
		new lstr[256], str[256];
		format(str, sizeof(str), "%s online:", ReturnFactionName(playerid));
		format(lstr, sizeof(lstr), "ID\tRank\tName\n");
		foreach(new i : Player)
		{
			if(PlayerInfo[i][E_CHARACTER_FACTION] != PlayerInfo[playerid][E_CHARACTER_FACTION])
				continue;
				
			if(PlayerInfo[i][E_CHARACTER_ADMINDUTY])
			{
				format(lstr, sizeof(lstr), "%s(%d)\t%s\t%s", lstr, i, IsPlayerFactionRank(i), ReturnName(i, i));
				format(lstr, sizeof(lstr), "%s\n", lstr);
				ShowPlayerDialog(playerid, DIALOG_DEFAULT, DIALOG_STYLE_TABLIST_HEADERS, "Faction Online:", lstr, "Close", "");
			}	
			else
			{
				format(lstr, sizeof(lstr), "%s(%d)\t%s\t%s", lstr, i, IsPlayerFactionRank(i), ReturnName(i, i));
				format(lstr, sizeof(lstr), "%s\n", lstr);
				ShowPlayerDialog(playerid, DIALOG_DEFAULT, DIALOG_STYLE_TABLIST_HEADERS, str, lstr, "Close", "");
			}
		}
		
		return 1;
	}

	if(!FactionInfo[factionid][E_FACTION_DBID])
		return SendErrorMessage(playerid, "The faction you specified doesn't exist.");
		
	new lstr[256], str[256];
	format(str, sizeof(str), "%s online:", ReturnFactionName(playerid));
	format(lstr, sizeof(lstr), "There is no one online in this faction", lstr);
	ShowPlayerDialog(playerid, DIALOG_DEFAULT, DIALOG_STYLE_MSGBOX, str, lstr, "Close", "");
	return 1;
}

// Police commands:

CMD:handcuff(playerid, params[])
{
	if(!IsPlayerFaction(playerid))
		return SendErrorMessage(playerid, "You aren't in any faction.");

	if(!PlayerInfo[playerid][E_CHARACTER_POLICEDUTY])
		return SendErrorMessage(playerid, "You aren't on duty."); 
		
	if(ReturnFactionType(playerid) != FACTION_TYPE_POLICE)
		return SendErrorMessage(playerid, "You can't use this command."); 
		
	new playerb;
	
	if(sscanf(params, "u", playerb))
		return SendUsageMessage(playerid, "/handcuff [playerid OR name]"); 
		
	if(!IsPlayerConnected(playerb))
		return SendErrorMessage(playerid, "The player you specified isn't connected.");
		
	if(AccountInfo[playerb][E_MASTERS_LOGGED] == false)
		return SendErrorMessage(playerid, "The player you specified isn't logged in."); 
		
	if(!IsPlayerNearPlayer(playerid, playerb, 5.0))
		return SendErrorMessage(playerid, "You aren't near that player.");
		
	if(PlayerInfo[playerb][E_CHARACTER_HANDCUFF])
		return SendErrorMessage(playerid, "That player's already handcuffed."); 
		
	if(GetPlayerSpecialAction(playerb) != SPECIAL_ACTION_HANDSUP && GetPlayerSpecialAction(playerb) != SPECIAL_ACTION_DUCK)
		return SendErrorMessage(playerid, "That player isn't crouched or with their hands up."); 
	
	SetPlayerAttachedObject(playerb, 0, 19418,6, -0.031999, 0.024000, -0.024000, -7.900000, -32.000011, -72.299987, 1.115998, 1.322000, 1.406000);
	SetPlayerSpecialAction(playerb, SPECIAL_ACTION_CUFFED);
	
	PlayerInfo[playerb][E_CHARACTER_HANDCUFF] = true;
	
	SendServerMessage(playerb, "You were handcuffed by %s.", ReturnName(playerid)); 
	SendServerMessage(playerid, "You handcuffed %s.", ReturnName(playerb));
	return 1;
}

CMD:unhandcuff(playerid, params[])
{
	if(!IsPlayerFaction(playerid))
		return SendErrorMessage(playerid, "You aren't in any faction.");
		
	if(ReturnFactionType(playerid) != FACTION_TYPE_POLICE)
		return SendErrorMessage(playerid, "You can't use this command."); 
		
	new playerb;
	
	if(sscanf(params, "u", playerb))
		return SendUsageMessage(playerid, "/unhandcuff [playerid OR name]"); 
		
	if(!IsPlayerConnected(playerb))
		return SendErrorMessage(playerid, "The player you specified isn't connected.");
		
	if(AccountInfo[playerb][E_MASTERS_LOGGED] == false)
		return SendErrorMessage(playerid, "The player you specified isn't logged in."); 
		
	if(!IsPlayerNearPlayer(playerid, playerb, 5.0))
		return SendErrorMessage(playerid, "You aren't near that player.");
		
	if(!PlayerInfo[playerb][E_CHARACTER_HANDCUFF])
		return SendErrorMessage(playerid, "That player isn't handcuffed.");

	RemovePlayerAttachedObject(playerb, 0); 
	SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE); 
	
	PlayerInfo[playerb][E_CHARACTER_HANDCUFF] = false;
	SendServerMessage(playerid, "You unhandcuffed %s.", ReturnName(playerb));
	return 1;
}


CMD:badge(playerid, params[])
{
	if(!IsPlayerFaction(playerid))
		return SendErrorMessage(playerid, "You aren't in any faction.");
		
	if(ReturnFactionType(playerid) != FACTION_TYPE_POLICE)
		return SendErrorMessage(playerid, "You can't use this command."); 
		
	new playerb;
	
	if(sscanf(params, "u", playerb))
		return SendUsageMessage(playerid, "/badge [playerid OR name]"); 
		
	if(!IsPlayerConnected(playerb))
		return SendErrorMessage(playerid, "The player you specified isn't connected.");
		
	if(AccountInfo[playerb][E_MASTERS_LOGGED] == false)
		return SendErrorMessage(playerid, "The player you specified isn't logged in."); 
		
	if(!IsPlayerNearPlayer(playerid, playerb, 5.0))
		return SendErrorMessage(playerid, "You aren't near that player.");
		
	if(playerb == playerid)
		SendNearbyMessage(playerid, 20.0, COLOR_EMOTE, "* %s looks at their badge.", ReturnName(playerid));
	
	else SendNearbyMessage(playerid, 20.0, COLOR_EMOTE, "* %s shows %s their badge.", ReturnName(playerid), ReturnName(playerb));
	
	SendClientMessage(playerb, COLOR_COP, "|__________ Badge __________|");
	SendClientMessageEx(playerb, COLOR_WHITE, "  Name: %s", ReturnSignName(playerid));
	SendClientMessageEx(playerb, COLOR_GREY, "  Rank: %s", IsPlayerFactionRank(playerid));
	SendClientMessageEx(playerb, COLOR_WHITE, "  Agency: %s", ReturnFactionName(playerid));
	return 1;
}

CMD:flocker(playerid, params[])
{
	if(!IsPlayerFaction(playerid))
		return SendErrorMessage(playerid, "You aren't in any faction.");
		
	if(ReturnFactionType(playerid) != FACTION_TYPE_POLICE && ReturnFactionType(playerid) != FACTION_TYPE_MEDICAL)
		return SendErrorMessage(playerid, "You can't use this command."); 
		
	if(IsPlayerInRangeOfPoint(playerid, 5.0, 253.9264,79.1226,1003.6406))
	{
		if(ReturnFactionType(playerid) == FACTION_TYPE_POLICE)
		{
			ShowPlayerDialog(playerid, DIALOG_FACTIONLOCKER, DIALOG_STYLE_LIST, "Faction Lockers:", "Faction Duty\nUniform\nTake Desert Eagle\nTake Shotgun\nTake Regular Ammo\nTake Surplus Ammo\nTake JHP Ammo\nTake Rubber Ammo", "Select", "Cancel");
		}
	}
	else if(IsPlayerInRangeOfPoint(playerid, 5.0, 1833.1627,-1072.3607,41.6537) || IsPlayerInRangeOfPoint(playerid, 5.0, 1269.3730,-1307.3560,1061.1392))
	{
		if(ReturnFactionType(playerid) == FACTION_TYPE_MEDICAL)
		{
			ShowPlayerDialog(playerid, DIALOG_FACTIONLOCKER, DIALOG_STYLE_LIST, "Faction Lockers:", "Faction Duty\nUniform\nTake Bandage (10 Pcs)\nTake Fire Extinguisher", "Select", "Cancel");
		}
	}
	else return SendErrorMessage(playerid, "You aren't near your faction spawn.");
	return 1;
}

CMD:m(playerid, params[]) return cmd_megaphone(playerid, params);
CMD:megaphone(playerid, params[])
{
	if(!IsPlayerFaction(playerid))
		return SendErrorMessage(playerid, "You aren't in any faction.");
		
	if(ReturnFactionType(playerid) != FACTION_TYPE_POLICE && ReturnFactionType(playerid) != FACTION_TYPE_MEDICAL)
		return SendErrorMessage(playerid, "You can't use this command."); 
		
	if(!IsPlayerInAnyVehicle(playerid))
		return SendErrorMessage(playerid, "You aren't in any vehicle.");
		
	if(isnull(params))
		return SendUsageMessage(playerid, "/megaphone [text]"); 
		
	SendNearbyMessage(playerid, 40.0, COLOR_YELLOW, "[ (MEGAPHONE)%s %s: %s ]", IsPlayerFactionRank(playerid), ReturnName(playerid), params);
	return 1;
}

CMD:dep(playerid, params[]) return cmd_department(playerid, params);
CMD:department(playerid, params[])
{
	if(!IsPlayerFaction(playerid))
		return SendErrorMessage(playerid, "You aren't in any faction.");
		
	if(ReturnFactionType(playerid) != FACTION_TYPE_POLICE && ReturnFactionType(playerid) != FACTION_TYPE_MEDICAL)
		return SendErrorMessage(playerid, "You can't use this command."); 
		
	if(isnull(params))
		return SendUsageMessage(playerid, "/department [text]");

	foreach(new i : Player)
	{
		new
			factionid;
			
		factionid = PlayerInfo[i][E_CHARACTER_FACTION];
			
		if(FactionInfo[factionid][E_FACTION_TYPE] == FACTION_TYPE_POLICE || FactionInfo[factionid][E_FACTION_TYPE] == FACTION_TYPE_MEDICAL)
		{
			SendClientMessageEx(playerid, COLOR_DEPT, "** [%s] %s %s: %s", FactionInfo[factionid][E_FACTION_ABBREV], IsPlayerFactionRank(i), ReturnName(playerid), params); 
		}
	}
	
	new Float:posx, Float:posy, Float:posz;
	GetPlayerPos(playerid, posx,posy,posz);

	foreach(new i : Player)
	{
 		if(i == playerid)
   			continue;

		else if(IsPlayerInRangeOfPoint(i, 20.0, posx,posy,posz))
		{
  			SendClientMessageEx(i, COLOR_GRAD1, "%s says (radio): %s", ReturnName(playerid), params);
 		}
	}
		
	return 1;
}


CMD:tracenumber(playerid, params[])
{
	new targetNumber, targetid;

	if(ReturnFactionType(playerid) != FACTION_TYPE_POLICE)
		return SendUnauthMessage(playerid);
		
	if(!PlayerInfo[playerid][E_CHARACTER_POLICEDUTY])
		return SendUnauthMessage(playerid);

	if(sscanf(params, "i", targetNumber))
        return SendUsageMessage(playerid, "/tracenumber [phone number]");

    for(new i = 0; i < MAX_PLAYERS; i++)
    {
        if(IsPlayerConnected(i) && PlayerInfo[i][E_CHARACTER_PHONE] == targetNumber)
        {
            targetid = i;
            break;
        }
    }

	if(targetid == -1)
        return SendErrorMessage(playerid, "No player found with this phone number.");

	new Float:x, Float:y, Float:z;
    GetPlayerPos(targetid, x, y, z);

    SendInfoMessage(playerid, "[TRACE] Phone number %s belongs to %s located at %s, %s.", targetNumber, ReturnName(playerid, 0), ReturnLocationStreet(playerid), ReturnLocation(playerid));
	return 1;
}

CMD:carsign(playerid, params[])
{
	if(!IsPlayerInAnyVehicle(playerid))
		return SendErrorMessage(playerid, "You aren't in any vehicle.");
		
	new
		vehicleid = GetPlayerVehicleID(playerid);
		
	if(ReturnFactionType(playerid) != FACTION_TYPE_POLICE && ReturnFactionType(playerid) != FACTION_TYPE_MEDICAL)
		return SendErrorMessage(playerid, "You can't use this command."); 
		
	if(isnull(params))
		return SendUsageMessage(playerid, "/carsign [text]"); 
		
	if(strlen(params) < 2 || strlen(params) >= 50)
		return SendErrorMessage(playerid, "Your text has to be greater than 1 char and less than 50.");
		
	if(!IsPlayerInAnyVehicle(playerid))
		return SendErrorMessage(playerid, "You aren't in a vehicle.");
		
	if(VehicleInfo[vehicleid][E_VEHICLE_CARSIGN])
		Update3DTextLabelText(VehicleInfo[vehicleid][E_VEHICLE_CARSIGNDISPLAY], COLOR_WHITE, params); 
	
	else
	{
		SendClientMessageEx(playerid, COLOR_FACTION, "Use \"/remove_carsign\" to destroy it next."); 
		
		VehicleInfo[vehicleid][E_VEHICLE_CARSIGNDISPLAY] = Create3DTextLabel(params, COLOR_WHITE, 0.0, 0.0, 0.0, 25.0, GetPlayerVirtualWorld(playerid), 0); 
		Attach3DTextLabelToVehicle(VehicleInfo[vehicleid][E_VEHICLE_CARSIGNDISPLAY], vehicleid, -0.7, -1.9, -0.3); 
		
		VehicleInfo[vehicleid][E_VEHICLE_CARSIGN] = true;
	}

	return 1;
}

CMD:removecarsign(playerid, params[])
{
	if(!IsPlayerInAnyVehicle(playerid))
		return SendErrorMessage(playerid, "You aren't in any vehicle.");
		
	new
		vehicleid = GetPlayerVehicleID(playerid);
		
	if(ReturnFactionType(playerid) != FACTION_TYPE_POLICE && ReturnFactionType(playerid) != FACTION_TYPE_MEDICAL)
		return SendErrorMessage(playerid, "You can't use this command."); 
		
	if(!IsPlayerInAnyVehicle(playerid))
		return SendErrorMessage(playerid, "You aren't in a vehicle.");
		
	if(!VehicleInfo[vehicleid][E_VEHICLE_CARSIGN])
		return SendErrorMessage(playerid, "Your vehicle doesn't have a carsign."); 
	
	Delete3DTextLabel(VehicleInfo[vehicleid][E_VEHICLE_CARSIGNDISPLAY]); 
	VehicleInfo[vehicleid][E_VEHICLE_CARSIGN] = true;

	SendClientMessageEx(playerid, COLOR_FACTION, "You deleted your vehicles carsign."); 
	return 1;
}

CMD:tazer(playerid, params[])
{
	if(ReturnFactionType(playerid) != FACTION_TYPE_POLICE)
		return SendErrorMessage(playerid, "You can't use this command."); 
		
	if(!PlayerInfo[playerid][E_CHARACTER_POLICEDUTY])
		return SendErrorMessage(playerid, "You can't use this command."); 
	
	if(!PlayerInfo[playerid][E_CHARACTER_POLICEGUN])
	{
		PlayerInfo[playerid][E_CHARACTER_POLICEGUN] = true;
		GivePlayerWeapon(playerid, 23, 999999); 
		PlayerInfo[playerid][E_CHARACTER_WEAPONTYPE] = 1;
		PlayerInfo[playerid][E_CHARACTER_POLICEAMMO] = 5;
	}
	else
	{
		ResetPlayerWeapons(playerid);
		PlayerInfo[playerid][E_CHARACTER_POLICEGUN] = false;
		PlayerInfo[playerid][E_CHARACTER_WEAPONTYPE] = 0;
		PlayerInfo[playerid][E_CHARACTER_POLICEAMMO] = 0;
		GivePlayerWeapon(playerid, 3, 1);
		GivePlayerWeapon(playerid, WEAPON_CAMERA, 10);
		GivePlayerWeapon(playerid, WEAPON_DEAGLE, 100);
	}
	return 1; 
}

CMD:riotgun(playerid, params[])
{
	if(ReturnFactionType(playerid) != FACTION_TYPE_POLICE)
		return SendErrorMessage(playerid, "You can't use this command."); 
		
	if(!PlayerInfo[playerid][E_CHARACTER_POLICEDUTY])
		return SendErrorMessage(playerid, "You can't use this command."); 
	
	if(!PlayerInfo[playerid][E_CHARACTER_POLICEGUN])
	{
		PlayerInfo[playerid][E_CHARACTER_POLICEGUN] = true;
		GivePlayerWeapon(playerid, 25, 999999); 
		PlayerInfo[playerid][E_CHARACTER_WEAPONTYPE] = 1;
		PlayerInfo[playerid][E_CHARACTER_POLICEAMMO] = 5;
	}
	else
	{
		ResetPlayerWeapons(playerid);
		PlayerInfo[playerid][E_CHARACTER_POLICEGUN] = false;
		PlayerInfo[playerid][E_CHARACTER_WEAPONTYPE] = 0;
		PlayerInfo[playerid][E_CHARACTER_POLICEAMMO] = 0;
		GivePlayerWeapon(playerid, 3, 1);
		GivePlayerWeapon(playerid, WEAPON_CAMERA, 10);
		GivePlayerWeapon(playerid, WEAPON_DEAGLE, 100);
	}
	return 1; 
}

CMD:dgf(playerid, params[])
{
	if(!PlayerInfo[playerid][E_CHARACTER_POLICEGUN])
	{
		PlayerInfo[playerid][E_CHARACTER_POLICEGUN] = true;
		GivePlayerWeapon(playerid, 30, 999999); 
		PlayerInfo[playerid][E_CHARACTER_WEAPONTYPE] = 1;
	}
	else
	{
		ResetPlayerWeapons(playerid);
		PlayerInfo[playerid][E_CHARACTER_POLICEGUN] = false;
		PlayerInfo[playerid][E_CHARACTER_WEAPONTYPE] = 0;
	}
	return 1; 
}

CMD:revoke(playerid, params[])
{
	if(ReturnFactionType(playerid) != FACTION_TYPE_POLICE)
		return SendUnauthMessage(playerid);
	
	new 
		playerb,
		a_str[60]
	; 
		
	if(sscanf(params, "us[60]", playerb, a_str))
	{
		SendUsageMessage(playerid, "/revoke [playerid OR name] [item]");
		SendTipMessage(playerid, "driverlicense, weaponlicense, truckerlicense, weapons"); 
		return 1;
	}
	
	if(!IsPlayerConnected(playerb))
		return SendErrorMessage(playerid, "You specified an invalid player.");
		
	if(AccountInfo[playerb][E_MASTERS_LOGGED] == false)
		return SendErrorMessage(playerid, "You specified a player that isn't logged in.");
		
	if(!IsPlayerNearPlayer(playerid, playerb, 5.0))
		return SendErrorMessage(playerid, "You aren't near that player.");
	
	if(!strcmp(a_str, "driverlicense"))
	{
		if(!PlayerInfo[playerb][E_CHARACTER_DRIVELICENSE])
			return SendErrorMessage(playerid, "%s doesn't have a driver's license.", ReturnName(playerb)); 
			
		PlayerInfo[playerb][E_CHARACTER_DRIVELICENSE] = 0;
		SendNearbyMessage(playerid, 20.0, COLOR_EMOTE, "* %s %s took %s's driver's license.", IsPlayerFactionRank(playerid), ReturnName(playerid), ReturnName(playerb));
	}
	else if(!strcmp(a_str, "weaponlicense"))
	{
		if(!PlayerInfo[playerb][E_CHARACTER_WEAPLICENSE])
			return SendErrorMessage(playerid, "%s doesn't have a weapons license.", ReturnName(playerb)); 
			
		PlayerInfo[playerb][E_CHARACTER_WEAPLICENSE] = 0;
		SendNearbyMessage(playerid, 20.0, COLOR_EMOTE, "* %s %s took %s's weapons license.", IsPlayerFactionRank(playerid), ReturnName(playerid), ReturnName(playerb));
	}
	else if(!strcmp(a_str, "truckerlicense"))
	{
		if(!PlayerInfo[playerb][E_CHARACTER_TRUCKERLICENSE])
			return SendErrorMessage(playerid, "%s doesn't have a truckers license.", ReturnName(playerb)); 
			
		PlayerInfo[playerb][E_CHARACTER_TRUCKERLICENSE] = 0;
		SendNearbyMessage(playerid, 20.0, COLOR_EMOTE, "* %s %s took %s's truckers license.", IsPlayerFactionRank(playerid), ReturnName(playerid), ReturnName(playerb));
	}
	else if(!strcmp(a_str, "weapons"))
	{
		ResetPlayerWeaponEx(playerid);
		SendNearbyMessage(playerid, 20.0, COLOR_EMOTE, "* %s %s took %s's weapons.", IsPlayerFactionRank(playerid), ReturnName(playerid), ReturnName(playerb));
		return 1;
	}
	else return SendErrorMessage(playerid, "Invalid Parameter.");
	return 1;
}

CMD:givelicense(playerid, params[])
{
	if(ReturnFactionType(playerid) != FACTION_TYPE_POLICE)
		return SendUnauthMessage(playerid);
	
	new 
		playerb,
		a_str[60]
	; 
		
	if(sscanf(params, "us[60]", playerb, a_str))
	{
		SendUsageMessage(playerid, "/givelicense [playerid OR name] [item]");
		SendTipMessage(playerid, "weaponlicense, truckerlicense"); 
		return 1;
	}
	
	if(!IsPlayerConnected(playerb))
		return SendErrorMessage(playerid, "You specified an invalid player.");
		
	if(AccountInfo[playerb][E_MASTERS_LOGGED] == false)
		return SendErrorMessage(playerid, "You specified a player that isn't logged in.");
		
	if(!IsPlayerNearPlayer(playerid, playerb, 5.0))
		return SendErrorMessage(playerid, "You aren't near that player.");
	
	if(!strcmp(a_str, "weaponlicense"))
	{
		if(!PlayerInfo[playerb][E_CHARACTER_WEAPLICENSE])
			return SendErrorMessage(playerid, "%s already have a weapons license.", ReturnName(playerb)); 
			
		PlayerInfo[playerb][E_CHARACTER_WEAPLICENSE] = 1;
		SendNearbyMessage(playerid, 20.0, COLOR_EMOTE, "* %s %s given %s's weapons license.", IsPlayerFactionRank(playerid), ReturnName(playerid), ReturnName(playerb));
	}
	else if(!strcmp(a_str, "truckerlicense"))
	{
		if(PlayerInfo[playerb][E_CHARACTER_TRUCKERLICENSE])
			return SendErrorMessage(playerid, "%s already have a truckers license.", ReturnName(playerb)); 
			
		PlayerInfo[playerb][E_CHARACTER_TRUCKERLICENSE] = 1;
		SendNearbyMessage(playerid, 20.0, COLOR_EMOTE, "* %s %s given %s's truckers license.", IsPlayerFactionRank(playerid), ReturnName(playerid), ReturnName(playerb));
	}
	else return SendErrorMessage(playerid, "Invalid Parameter.");
	return 1;
}

CMD:searchproperty(playerid, params[])
{
	if(ReturnFactionType(playerid) != FACTION_TYPE_POLICE)
		return SendUnauthMessage(playerid);
		
	if(!PlayerInfo[playerid][E_CHARACTER_POLICEDUTY])
		return SendUnauthMessage(playerid);

	new propid = IsPlayerInProperty(playerid);

	if(!IsPlayerInProperty(playerid))
		return SendErrorMessage(playerid, "You aren't in any property");

	Property_ShowItems(playerid, propid);
	return 1;
}

CMD:checktrunk(playerid, params[])
{
	if(ReturnFactionType(playerid) != FACTION_TYPE_POLICE)
		return SendUnauthMessage(playerid);
		
	if(!PlayerInfo[playerid][E_CHARACTER_POLICEDUTY])
		return SendUnauthMessage(playerid);

	new carid = IsPlayerNearVehicle(playerid);

	if(!IsPlayerInAnyVehicle(playerid) && IsPlayerNearVehicle(playerid) != INVALID_VEHICLE_ID)
	{
		CheckVehicleStorage(playerid, carid);
	}
	return 1;
}

CMD:impound(playerid, params[])
{
	if(ReturnFactionType(playerid) != FACTION_TYPE_POLICE)
		return SendUnauthMessage(playerid);
		
	if(!PlayerInfo[playerid][E_CHARACTER_POLICEDUTY])
		return SendUnauthMessage(playerid);
		
	if(GetPlayerState(playerid) != PLAYER_STATE_DRIVER)
		return SendErrorMessage(playerid, "You aren't driving a vehicle.");
		
	new	
		vehicleid = GetPlayerVehicleID(playerid);
		
	if(!VehicleInfo[vehicleid][E_VEHICLE_DBID] && !VehicleInfo[vehicleid][E_VEHICLE_ADMIN])
		return SendErrorMessage(playerid, "This command can only be used for private vehicles. You are in a public static vehicle."); 
		
	if(!IsPlayerInDynamicArea(playerid, ImpoundLotArea))
		return SendErrorMessage(playerid, "You aren't in the impound lot area."); 
		
	GetPlayerPos(playerid, VehicleInfo[vehicleid][E_VEHICLE_IMPOUNDPOS][0], VehicleInfo[vehicleid][E_VEHICLE_IMPOUNDPOS][1], VehicleInfo[vehicleid][E_VEHICLE_IMPOUNDPOS][2]); 
	VehicleInfo[vehicleid][E_VEHICLE_IMPOUND] = true; 
	
	SendServerMessage(playerid, "You impounded %s's %s", ReturnDBIDName(VehicleInfo[vehicleid][E_VEHICLE_OWNERDBID]), ReturnVehicleName(vehicleid)); 
	
	foreach(new i : Player) if(PlayerInfo[i][E_CHARACTER_DBID] == VehicleInfo[vehicleid][E_VEHICLE_OWNERDBID])
		SendServerMessage(i, "Your %s was impounded by %s", ReturnVehicleName(vehicleid), ReturnName(playerid)); 

	return 1;
}

// Medical commands:

CMD:treatment(playerid, params[])
{
	if(ReturnFactionType(playerid) != FACTION_TYPE_MEDICAL)
        return SendUnauthMessage(playerid);

	if(!PlayerInfo[playerid][E_CHARACTER_MEDICDUTY])
		return SendErrorMessage(playerid, "You must be faction duty first!");

	new targetid;
	if(sscanf(params, "u", targetid))
		return SendUsageMessage(playerid, "/treatment [playerid/PartOfName]");

	if(!IsPlayerNearPlayer(playerid, targetid, 5.0) || targetid == INVALID_PLAYER_ID)
		return SendErrorMessage(playerid, "You must be close to that player!");

	PlayerInfo[playerid][E_CHARACTER_TARGETID] = targetid;
	ShowPlayerDialog(playerid, DIALOG_TREATMENT, DIALOG_STYLE_LIST, "Treatment Menu:", "Check Patient\nRevive Patient\nHeal Patient\nSurgery Patient", "Select", "Close");
	return 1;
}

function:Treatments(playerid, targetid)
{
	new text[256];
	PlayerInfo[playerid][E_CHARACTER_LOADINGCOUNT]++;

	switch(PlayerInfo[playerid][E_CHARACTER_LOADINGCOUNT])
	{
		case 2: text = "Loading operate process\n(( ||----- ))";
		case 3: text = "Loading operate process\n(( |||---- ))";
		case 4: text = "Loading operate process\n(( ||||--- ))";
		case 5: text = "Loading operate process\n(( |||||-- ))";
		case 6: text = "Loading operate process\n(( ||||||- ))";
		case 7: text = "Loading operate process\n(( ||||||| ))";
		case 8:
		{
			TogglePlayerControllable(playerid, true);
			TogglePlayerControllable(targetid, true);

			Delete3DTextLabel(PlayerInfo[playerid][E_CHARACTER_LOADINGDISPLAY]); 
			KillTimer(PlayerInfo[playerid][E_CHARACTER_LOADINGTIMER]);

			for(new i; i < 8; i++)
			{
				PlayerInfo[targetid][E_CHARACTER_BODYPART][i] = 100;
				PlayerInfo[targetid][E_CHARACTER_WOUND][i] = 100;
			}
			
			SendInfoMessage(playerid, "[TREATMENT] You have operating %s.", ReturnName(targetid));
			SendInfoMessage(targetid, "[TREATMENT] You have been operated by %s.", ReturnName(playerid));
		}
	}
	Update3DTextLabelText(PlayerInfo[playerid][E_CHARACTER_LOADINGDISPLAY], COLOR_3DTEXT, text); 
	return 1;
}

CMD:loadinjured(playerid, params[])
{
    static
        seatid,
		otherid;

    if(ReturnFactionType(playerid) != FACTION_TYPE_MEDICAL)
        return SendUnauthMessage(playerid);

    if(sscanf(params, "u", otherid))
        return SendUsageMessage(playerid, "/loadinjured [playerid/PartOfName]");

    if(otherid == INVALID_PLAYER_ID || !IsPlayerNearPlayer(playerid, otherid, 5.0))
        return SendErrorMessage(playerid, "You aren't near of any player.");

    if(otherid == playerid)
        return SendErrorMessage(playerid, "You can't load yourself into an ambulance.");

    if(!PlayerInfo[otherid][E_CHARACTER_INJURED] && !PlayerInfo[otherid][E_CHARACTER_DEATH])
        return SendErrorMessage(playerid, "That player is not injured or death.");
	
	if(!IsPlayerInAnyVehicle(playerid))
	    return SendErrorMessage(playerid, "You must be in a Ambulance to load patient!");
		
	new i = GetPlayerVehicleID(playerid);
    if(IsMedicalVehicle(i))
    {
        seatid = GetAvailableSeat(i, 2);

        if(seatid == -1)
            return SendErrorMessage(playerid, "There is no room for the patient.");

        ClearAnimations(otherid);

        PlayerPutIntoVehicle(otherid, i, seatid);
    
        TogglePlayerControllable(otherid, false);
        SetPlayerHealthEx(otherid, 100.0);
        SendServerMessage(otherid, "You're injured now you're on ambulance.");
        return 1;
    }
    else SendErrorMessage(playerid, "You must be in an ambulance.");
    return 1;
}

CMD:dropinjured(playerid, params[])
{
    if(ReturnFactionType(playerid) != FACTION_TYPE_MEDICAL)
        return SendUnauthMessage(playerid);

	new otherid;
    if(sscanf(params, "u", otherid))
        return SendUsageMessage(playerid, "/dropinjured [playerid/PartOfName]");

    if(otherid == INVALID_PLAYER_ID || !IsPlayerInVehicle(playerid, GetPlayerVehicleID(playerid)))
        return SendErrorMessage(playerid, "You aren't near of any player.");

    if(otherid == playerid)
        return SendErrorMessage(playerid, "You can't deliver yourself to the hospital.");

    if(!PlayerInfo[otherid][E_CHARACTER_INJURED] && !PlayerInfo[otherid][E_CHARACTER_DEATH])
        return SendErrorMessage(playerid, "That player is not injured or death.");

    if(IsPlayerInRangeOfPoint(playerid, 5.0, 2035.0732,-1414.0488,16.9922))
    {
		RemovePlayerFromVehicle(otherid);

		PlayerInfo[otherid][E_CHARACTER_INJURED] = 0;
        PlayerInfo[otherid][E_CHARACTER_DEATH] = 0;
        SetPlayerTeam(otherid, PLAYER_STATE_ALIVE);

		new Cents = floatround(250 * 100, floatround_round);

        GiveMoney(playerid, -Cents);

        SendServerMessage(playerid, "You have delivered %s to the hospital.", ReturnName(otherid, playerid));
        SendServerMessage(otherid, "You have recovered at the nearest hospital by officer %s.", ReturnName(playerid));
    }
    else SendErrorMessage(playerid, "You must be near a hospital deliver location.");
    return 1;
}