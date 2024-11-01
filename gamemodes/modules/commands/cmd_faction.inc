//Faction commands:
CMD:factions(playerid, params[])
{
	new str[512], longstr[512]; 

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
	SendInfoMessage(playerid, "You invited {d7d292}%s{cdd0d1} to join the {d7d292}%s{cdd0d1}.", ReturnName(playerb), ReturnFactionName(playerid));
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
	
	SendInfoMessage(playerid, "You were uninvited from the {d7d292}%s{cdd0d1} by {d7d292}%s{cdd0d1}!", ReturnFactionNameEx(PlayerInfo[playerid][E_CHARACTER_FACTION]), ReturnName(playerid));
	SendInfoMessage(playerid, "You uninvited {d7d292}%s{cdd0d1}!", ReturnName(playerb));
	
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
		
	SendInfoMessage(playerb, "Your rank has been upgraded from {d7d292}%s{cdd0d1} to {d7d292}%s{cdd0d1} by {d7d292}%s{cdd0d1}!", FactionRanks[PlayerInfo[playerb][E_CHARACTER_FACTION]][PlayerInfo[playerb][E_CHARACTER_FACTIONRANK]], FactionRanks[PlayerInfo[playerb][E_CHARACTER_FACTION]][rank], ReturnName(playerid)); 
	SendInfoMessage(playerid, "You upgraded {d7d292}%s{cdd0d1} rank from {d7d292}%s{cdd0d1} to {d7d292}%s{cdd0d1}!", ReturnName(playerb), FactionRanks[PlayerInfo[playerb][E_CHARACTER_FACTION]][PlayerInfo[playerb][E_CHARACTER_FACTIONRANK]], FactionRanks[PlayerInfo[playerb][E_CHARACTER_FACTION]][rank]);
		
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
		
		new lstr[512], str[256];
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
CMD:fduty(playerid, params[])
{
	if(!IsPlayerFaction(playerid))
		return SendErrorMessage(playerid, "You aren't in any faction.");
		
	if(ReturnFactionType(playerid) != FACTION_TYPE_POLICE || ReturnFactionType(playerid) != FACTION_TYPE_MEDICAL)
		return SendErrorMessage(playerid, "You can't use this command."); 
		
	if(PlayerInfo[playerid][E_CHARACTER_POLICEDUTY])
		return SendErrorMessage(playerid, "You're already on duty."); 

	if(!PlayerInfo[playerid][E_CHARACTER_FACSKIN])
		return SendErrorMessage(playerid, "You don't have faction uniform");
		
	if(!IsPlayerInRangeOfPoint(playerid, 5.0, FactionInfo[PlayerInfo[playerid][E_CHARACTER_FACTION]][E_FACTION_SPAWN][0], FactionInfo[PlayerInfo[playerid][E_CHARACTER_FACTION]][E_FACTION_SPAWN][1], FactionInfo[PlayerInfo[playerid][E_CHARACTER_FACTION]][E_FACTION_SPAWN][2]))
		return SendErrorMessage(playerid, "You aren't near your faction spawn.");
	
    if(ReturnFactionType(playerid) == FACTION_TYPE_POLICE)
    {
        SendPoliceMessage(COLOR_COP, "** HQ: %s %s is now On Duty! **", IsPlayerFactionRank(playerid), ReturnName(playerid));
        SendClientMessage(playerid, COLOR_FACTION, "You can use /tazer or /riotgun.");
        
        SetPlayerHealthEx(playerid, 100);
        SetPlayerArmourEx(playerid, 100);
        
        PlayerInfo[playerid][E_CHARACTER_POLICEDUTY] = true; 

        SetPlayerSkin(playerid, PlayerInfo[playerid][E_CHARACTER_FACSKIN]); 

        if(!Inventory_Count(playerid, "Night Hawk"))
        {
            Inventory_Add(playerid, "Night Hawk", 348, 1);
        }
        Inventory_Add(playerid, "9mm", 2040, 50);
    }
    if(ReturnFactionType(playerid) == FACTION_TYPE_MEDICAL)
    {
        SendMedicMessage(COLOR_MEDIC, "** HQ: %s %s is now On Duty! **", IsPlayerFactionRank(playerid), ReturnName(playerid));
        
        SetPlayerHealthEx(playerid, 100);
        SetPlayerArmourEx(playerid, 100);

        Inventory_Set(playerid, "Medkits", 17738, 10);

        PlayerInfo[playerid][E_CHARACTER_MEDICDUTY] = true; 

        SetPlayerSkin(playerid, PlayerInfo[playerid][E_CHARACTER_FACSKIN]); 
    }
	
	return 1;
}

CMD:offduty(playerid, params[])
{
	if(!IsPlayerFaction(playerid))
		return SendErrorMessage(playerid, "You aren't in any faction.");
		
	if(ReturnFactionType(playerid) != FACTION_TYPE_POLICE)
		return SendErrorMessage(playerid, "You can't use this command."); 
		
	if(!PlayerInfo[playerid][E_CHARACTER_POLICEDUTY])
		return SendErrorMessage(playerid, "You aren't on duty."); 
		
	if(!IsPlayerInRangeOfPoint(playerid, 5.0, FactionInfo[PlayerInfo[playerid][E_CHARACTER_FACTION]][E_FACTION_SPAWN][0], FactionInfo[PlayerInfo[playerid][E_CHARACTER_FACTION]][E_FACTION_SPAWN][1], FactionInfo[PlayerInfo[playerid][E_CHARACTER_FACTION]][E_FACTION_SPAWN][2]))
		return SendErrorMessage(playerid, "You aren't near your faction spawn.");
		
	PlayerInfo[playerid][E_CHARACTER_POLICEDUTY] = false;
	
	ResetPlayerWeapons(playerid); 
	
	SendPoliceMessage(COLOR_COP, "** HQ: %s %s is now Off Duty! **", IsPlayerFactionRank(playerid), ReturnName(playerid)); 
	
	SetPlayerArmour(playerid, 0);
	SetPlayerHealthEx(playerid, 100); 
	
	SetPlayerSkin(playerid, PlayerInfo[playerid][E_CHARACTER_LASTSKIN]); 
	
	if(Inventory_Count(playerid, "Night Hawk"))
	{
		Inventory_Remove(playerid, "Night Hawk", 1);
	}
	Inventory_Remove(playerid, "9mm", 50);
	return 1;
}

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
	
	SendInfoMessage(playerb, "You were handcuffed by {d7d292}%s{cdd0d1}.", ReturnName(playerid)); 
	SendInfoMessage(playerid, "You handcuffed {d7d292}%s{cdd0d1}.", ReturnName(playerb));
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
	SendInfoMessage(playerid, "You unhandcuffed {d7d292}%s{cdd0d1}.", ReturnName(playerb));
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
	SendClientMessageEx(playerb, COLOR_WHITE, "  Name: %s", ReturnMixedName(playerid));
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
		
	if(!IsPlayerInRangeOfPoint(playerid, 5.0, FactionInfo[PlayerInfo[playerid][E_CHARACTER_FACTION]][E_FACTION_SPAWN][0], FactionInfo[PlayerInfo[playerid][E_CHARACTER_FACTION]][E_FACTION_SPAWN][1], FactionInfo[PlayerInfo[playerid][E_CHARACTER_FACTION]][E_FACTION_SPAWN][2]))
		return SendErrorMessage(playerid, "You aren't near your faction spawn.");
		
    
	if(ReturnFactionType(playerid) == FACTION_TYPE_POLICE)
	{
        Dialog_Show(playerid, FactionLockers, DIALOG_STYLE_LIST, "Faction Lockers:", "Faction Duty\nUniform", "Select", "Cancel");
	}
    if(ReturnFactionType(playerid) == FACTION_TYPE_MEDICAL)
	{
        Dialog_Show(playerid, FactionLockers, DIALOG_STYLE_LIST, "Faction Lockers:", "Faction Duty\nUniform", "Select", "Cancel");
	}
		
	return 1;
}

Dialog:FactionLockers(playerid, response, listitem, inputtext[])
{
    if(response)
    {
        switch(listitem)
        {
            case 0:
            {
                cmd_fduty(playerid, "");
            }
            case 1:
            {
                if(ReturnFactionType(playerid) == FACTION_TYPE_POLICE)
                {
					if(PlayerInfo[playerid][E_CHARACTER_GENDER] == 1)
					{
						new str[1024];
						for(new i; i < sizeof(g_aLspdSkins); i++)
						{
							format(str, sizeof(str), "%s%d\n", str, g_aLspdSkins[i]);
						}
						Dialog_Show(playerid, LSPDMaleSkins, DIALOG_STYLE_PREVIEW_MODEL, "Choose your skins:", str, "Select", "Close");
					}
					else if(PlayerInfo[playerid][E_CHARACTER_GENDER] == 2)
					{
						new str[1024];
						for(new i; i < sizeof(g_aLspdFemSkins); i++)
						{
							format(str, sizeof(str), "%s%d\n", str, g_aLspdFemSkins[i]);
						}
						Dialog_Show(playerid, LSPDFemaleSkins, DIALOG_STYLE_PREVIEW_MODEL, "Choose your skins:", str, "Select", "Close");
					}
                }
                if(ReturnFactionType(playerid) == FACTION_TYPE_MEDICAL)
                {
					if(PlayerInfo[playerid][E_CHARACTER_GENDER] == 2)
					{
						new str[512];
						for(new i; i < sizeof(g_aLsmdSkins); i++)
						{
							format(str, sizeof(str), "%s%d\n", str, g_aLsmdSkins[i]);
						}
						Dialog_Show(playerid, LSMDMaleSkins, DIALOG_STYLE_PREVIEW_MODEL, "Choose your skins:", str, "Select", "Close");
					}
					else if(PlayerInfo[playerid][E_CHARACTER_GENDER] == 2)
					{
						new str[512];
						for(new i; i < sizeof(g_aLsmdFemSkins); i++)
						{
							format(str, sizeof(str), "%s%d\n", str, g_aLsmdFemSkins[i]);
						}
						Dialog_Show(playerid, LSMDFemaleSkins, DIALOG_STYLE_PREVIEW_MODEL, "Choose your skins:", str, "Select", "Close");
					}
                }
            }
        }
    }
    return 1;
}

Dialog:LSPDMaleSkins(playerid, response, listitem, inputtext[])
{
	if(response)
    {
		SetPlayerSkin(playerid, g_aLspdSkins[listitem]);
		PlayerInfo[playerid][E_CHARACTER_FACSKIN] = g_aLspdSkins[listitem];
		SaveCharacter(playerid);
	}
	return 1;
}

Dialog:LSPDFemaleSkins(playerid, response, listitem, inputtext[])
{
	if(response)
    {
		SetPlayerSkin(playerid, g_aLspdFemSkins[listitem]);
		PlayerInfo[playerid][E_CHARACTER_FACSKIN] = g_aLspdFemSkins[listitem];
		SaveCharacter(playerid);
	}
	return 1;
}

Dialog:LSMDMaleSkins(playerid, response, listitem, inputtext[])
{
	if(response)
    {
		SetPlayerSkin(playerid, g_aLsmdSkins[listitem]);
		PlayerInfo[playerid][E_CHARACTER_FACSKIN] = g_aLsmdSkins[listitem];
		SaveCharacter(playerid);
	}
	return 1;
}

Dialog:LSMDFemaleSkins(playerid, response, listitem, inputtext[])
{
	if(response)
    {
		SetPlayerSkin(playerid, g_aLsmdFemSkins[listitem]);
		PlayerInfo[playerid][E_CHARACTER_FACSKIN] = g_aLsmdFemSkins[listitem];
		SaveCharacter(playerid);
	}
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

CMD:take(playerid, params[])
{
	if(ReturnFactionType(playerid) != FACTION_TYPE_POLICE)
		return SendUnauthMessage(playerid);
	
	new 
		playerb,
		a_str[60]
	; 
		
	if(sscanf(params, "us[60]", playerb, a_str))
	{
		SendUsageMessage(playerid, "/take [playerid OR name] [item]");
		SendTipMessage(playerid, "driverlicense, weaponlicense, weapons"); 
		return 1;
	}
	
	if(!IsPlayerConnected(playerb))
		return SendErrorMessage(playerid, "You specified an invalid player.");
		
	if(AccountInfo[playerb][E_MASTERS_LOGGED] == false)
		return SendErrorMessage(playerid, "You specified a player that isn't logged in.");
		
	if(!IsPlayerNearPlayer(playerid, playerb, 4.0))
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
	else if(!strcmp(a_str, "weapons"))
	{
		ResetPlayerWeapons(playerid);
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
		
	if(PlayerInfo[playerid][E_CHARACTER_FACTIONRANK] < 2)
		return SendErrorMessage(playerid, "Your rank doesn't have permission for this."); 
	
	new 
		playerb; 
		
	if (sscanf(params, "u", playerb))
	{
		SendUsageMessage(playerid, "/givelicense [playerid OR name]");
		SendTipMessage(playerid, "This issues a weapon's license to players. "); 
		return 1;
	}
		
	if(!IsPlayerConnected(playerb))
		return SendErrorMessage(playerid, "You specified an invalid player.");
		
	if(AccountInfo[playerb][E_MASTERS_LOGGED] == false)
		return SendErrorMessage(playerid, "You specified a player that isn't logged in.");
		
	if(!PlayerInfo[playerid][E_CHARACTER_WEAPLICENSE]) {
		PlayerInfo[playerid][E_CHARACTER_WEAPLICENSE] = 1;
		
		SendPoliceMessage(COLOR_COP, "** HQ: %s %s issued %s a weapon's license! **", IsPlayerFactionRank(playerid), ReturnName(playerid), ReturnName(playerb)); 
	}
	else {
		PlayerInfo[playerid][E_CHARACTER_WEAPLICENSE] = 0; 
		
		SendPoliceMessage(COLOR_COP, "** HQ: %s %s removed %s's weapon's license! **", IsPlayerFactionRank(playerid), ReturnName(playerid), ReturnName(playerb)); 
	}
		
	return 1;
}

CMD:checkvehicle(playerid, params[])
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
	
	SendClientMessageEx(playerid, COLOR_DARKGREEN, "You impounded %s's %s", ReturnDBIDName(VehicleInfo[vehicleid][E_VEHICLE_OWNERDBID]), ReturnVehicleName(vehicleid)); 
	
	foreach(new i : Player) if(PlayerInfo[i][E_CHARACTER_DBID] == VehicleInfo[vehicleid][E_VEHICLE_OWNERDBID])
		SendClientMessageEx(i, COLOR_DARKGREEN, "Your %s was impounded by %s", ReturnVehicleName(vehicleid), ReturnName(playerid)); 

	return 1;
}

// Medicals commands:
CMD:loadinjured(playerid, params[])
{
    static
        seatid,
		otherid;

    if(ReturnFactionType(playerid) != FACTION_TYPE_MEDICAL)
        return SendUnauthMessage(playerid);

    if(sscanf(params, "u", otherid))
        return SendUsageMessage(playerid, "/loadinjured [playerid/PartOfName]");

    if(otherid == INVALID_PLAYER_ID || !IsPlayerNearPlayer(playerid, otherid, 10.0))
        return SendErrorMessage(playerid, "Player tersebut tidak berada didekat mu.");

    if(otherid == playerid)
        return SendErrorMessage(playerid, "You can't load yourself into an ambulance.");

    if(!PlayerInfo[otherid][E_CHARACTER_INJURED] || !PlayerInfo[otherid][E_CHARACTER_DEATH])
        return SendErrorMessage(playerid, "That player is not injured or death.");
	
	if(!IsPlayerInAnyVehicle(playerid))
	{
	    return SendErrorMessage(playerid, "You must be in a Ambulance to load patient!");
	}
		
	new i = GetPlayerVehicleID(playerid);
    if(GetVehicleModel(i) == 416)
    {
        seatid = GetAvailableSeat(i, 2);

        if(seatid == -1)
            return SendErrorMessage(playerid, "There is no room for the patient.");

        ClearAnimations(otherid);

        PlayerPutIntoVehicle(otherid, i, seatid);
    
        TogglePlayerControllable(otherid, false);
        SetPlayerHealth(otherid, 100.0);
        SendInfoMessage(otherid, "You're injured now you're on ambulance.");
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

    if(!PlayerInfo[otherid][E_CHARACTER_INJURED] || !PlayerInfo[otherid][E_CHARACTER_DEATH])
        return SendErrorMessage(playerid, "That player is not injured or death.");

    if(IsPlayerInRangeOfPoint(playerid, 5.0, 2035.0732,-1414.0488,16.9922))
    {
		RemovePlayerFromVehicle(otherid);

		PlayerInfo[otherid][E_CHARACTER_INJURED] = 0;
        PlayerInfo[otherid][E_CHARACTER_DEATH] = 0;
        SetPlayerTeam(otherid, PLAYER_STATE_ALIVE);

        GiveMoney(playerid, -250);

        SendInfoMessage(playerid, "You have delivered {d7d292}%s{cdd0d1} to the hospital.", ReturnName(otherid, playerid));
        SendInfoMessage(otherid, "You have recovered at the nearest hospital by officer {d7d292}%s{cdd0d1}.", ReturnName(playerid));
    }
    else SendErrorMessage(playerid, "You must be near a hospital deliver location.");
    return 1;
}

CMD:rescue(playerid, params[])
{
	if(ReturnFactionType(playerid) != FACTION_TYPE_MEDICAL)
        return SendUnauthMessage(playerid);
	
	if(Inventory_Count(playerid, "Medkits") < 1) return SendErrorMessage(playerid, "You must have medkits.");

	new otherid;
	if(sscanf(params, "u", otherid))
        return SendUsageMessage(playerid, "/rescue [playerid/PartOfName]");

    if(otherid == INVALID_PLAYER_ID || !IsPlayerNearPlayer(playerid, otherid, 5.0))
        return SendErrorMessage(playerid, "You aren't near of any player.");

    if(otherid == playerid)
        return SendErrorMessage(playerid, "You can't rescue yourself.");

    if(!PlayerInfo[otherid][E_CHARACTER_INJURED])
        return SendErrorMessage(playerid, "That player is not injured.");
	
	Inventory_Remove(playerid, "Medkits", 1);
	
	SetPlayerHealthEx(otherid, 50.0);
    PlayerInfo[otherid][E_CHARACTER_INJURED] = 0;
    SetPlayerTeam(otherid, PLAYER_STATE_ALIVE);

    ClearAnimations(otherid);
	ApplyAnimation(otherid, "CARRY", "crry_prtial", 4.0, 0, 0, 0, 0, 0, 1);
	
	SendNearbyMessage(playerid, 30.0, COLOR_EMOTE, "* %s has rescuered %s with medkit tools.", ReturnName(playerid), ReturnName(otherid, playerid));
    SendInfoMessage(otherid, "Officer {d7d292}%s{cdd0d1} has rescue your character.", ReturnName(playerid));
	return 1;
}