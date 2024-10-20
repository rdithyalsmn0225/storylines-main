//Admin commands:


CMD:ahelp(playerid, params[])
{
	if(!IsPlayerAdmins(playerid))
		return 0;
		
	if(IsPlayerAdmins(playerid) >= 1)
	{
		SendClientMessage(playerid, COLOR_HEADER, "Staff Commands:");
		SendClientMessage(playerid, COLOR_DARKGREEN, "Helper:{ffffff} /aduty, /forumname, /goto, /gethere, /bring, /a (achat), /showmain, /kick, /(o)ban, /(o)ajail,"); 
		SendClientMessage(playerid, COLOR_DARKGREEN, "Helper:{ffffff} /rjail, /rprison, /setint, /setvw, /skin, /health, /reports, /ar (accept), /dr (disregard),"); 
		SendClientMessage(playerid, COLOR_DARKGREEN, "Helper:{ffffff} /slap, /mute, /freeze, /unfreeze, /spec, /specoff, /stats (id), /gotols, /respawncar, /respawnstatic,"); 
		SendClientMessage(playerid, COLOR_DARKGREEN, "Helper:{ffffff} /gotocar, /getcar, /listmasks, /aooc, /revive, /listweapons");
	}
	if(IsPlayerAdmins(playerid) >= 2)
	{
		SendClientMessage(playerid, COLOR_DARKGREEN, "Admin:{ffffff} /armor, /clearreports, /p2p, /gotoproperty, /gotofaction, /xyz,");
		SendClientMessage(playerid, COLOR_DARKGREEN, "Admin:{ffffff} /gotobusiness, /noooc, /backup, /repair.");
	}
	if(IsPlayerAdmins(playerid) >= 3)
	{
		SendClientMessage(playerid, COLOR_DARKGREEN, "Operator:{ffffff} /spawncar, /despawncar, /createpcar, /setstats, /givemoney, /setcar, /setcarparams, /setpfaction, /setinv, /respawnpacket, /afindpacket.");
	}
	if(IsPlayerAdmins(playerid) >= 4)
	{
		SendClientMessage(playerid, COLOR_DARKGREEN, "Owner:{ffffff} /createfaction, /editfaction, /createproperty, /editproperty.");
		SendClientMessage(playerid, COLOR_DARKGREEN, "Owner:{ffffff} /createbusiness, /editbusiness, /callpaycheck, /gotomark, /loadturf, /turfwarscancel, /editturfwars, /destroyturfwars, /gototurfwars.");
		SendClientMessage(playerid, COLOR_DARKGREEN, "Owner:{ffffff} /createcourt, /editcourt.");
	}
	 
	return 1; 
}

CMD:aduty(playerid, params[])
{
	if(!IsPlayerAdmins(playerid))
		return 0;
		
	new str[128];
		
	if(PlayerInfo[playerid][E_CHARACTER_ADMINDUTY])
	{
		PlayerInfo[playerid][E_CHARACTER_ADMINDUTY] = false;
		
		format(str, sizeof(str), "%s is now off admin duty.", ReturnSettingsName(playerid, playerid)); 
		SendAdminMessage(1, str);
		UpdateTabListForOthers(playerid);
		SetPlayerHealthEx(playerid, PlayerInfo[playerid][E_CHARACTER_HEALTH]); 
	}
	else
	{
		PlayerInfo[playerid][E_CHARACTER_ADMINDUTY] = true;
		
		format(str, sizeof(str), "%s is now on admin duty.", ReturnSettingsName(playerid, playerid)); 
		SendAdminMessage(1, str);
		UpdateTabListForOthers(playerid);
	}
	
	return 1; 
}

CMD:a(playerid, params[])
{
	if(!IsPlayerAdmins(playerid))
		return 0;
		
	if(isnull(params)) return SendUsageMessage(playerid, "/a (admin chat) [text]"); 
	
	if(strlen(params) > 89)
	{
		SendAdminMessageEx(COLOR_ADMIN, 1, "A-CHAT: %s (%s): %.89s", ReturnSettingsName(playerid, playerid), AccountInfo[playerid][E_MASTERS_FORUMNAME], params);
		SendAdminMessageEx(COLOR_ADMIN, 1, "A-CHAT: %s (%s): ... %s", ReturnSettingsName(playerid, playerid), AccountInfo[playerid][E_MASTERS_FORUMNAME], params[89]);
	}
	else SendAdminMessageEx(COLOR_ADMIN, 1, "A-CHAT: %s (%s): %s", ReturnSettingsName(playerid, playerid), AccountInfo[playerid][E_MASTERS_FORUMNAME], params);
	return 1;
}

CMD:forumname(playerid, params[])
{
	if(!IsPlayerAdmins(playerid))
		return SendUnauthMessage(playerid);
		
	if(isnull(params))
		return SendUsageMessage(playerid, "/forumname [forum name]");
		
	if(strlen(params) > 60)
		return SendErrorMessage(playerid, "Your forum name needs to be shorter.");
	
	format(AccountInfo[playerid][E_MASTERS_FORUMNAME], 60, "%s", params);
	SendInfoMessage(playerid, "Your forum name was changed to: %s.", params);  
	
	SaveCharacter(playerid);
	return 1;
}

//Level 1 Admin commands:
CMD:goto(playerid, params[])
{
	if(!IsPlayerAdmins(playerid))
		return SendUnauthMessage(playerid); 
		
	new playerb;
	
	if (sscanf(params, "u", playerb)) 
		return SendUsageMessage(playerid, "/goto [playerid OR name]"); 
	
	if(!IsPlayerConnected(playerb))
		return SendErrorMessage(playerid, "The player you specified isn't connected."); 
		
	if(AccountInfo[playerid][E_MASTERS_LOGGED] == false)
		return SendErrorMessage(playerid, "The player you specified hasn't logged in yet.");
		
	GetPlayerPos(playerb, PlayerInfo[playerb][E_CHARACTER_LASTPOS][0], PlayerInfo[playerb][E_CHARACTER_LASTPOS][1], PlayerInfo[playerb][E_CHARACTER_LASTPOS][2]);
	//Using the player variable to avoid making other variables; 
	
	if(GetPlayerState(playerid) == PLAYER_STATE_DRIVER)
		SetVehiclePos(GetPlayerVehicleID(playerid), PlayerInfo[playerb][E_CHARACTER_LASTPOS][0], PlayerInfo[playerb][E_CHARACTER_LASTPOS][1] - 1, PlayerInfo[playerb][E_CHARACTER_LASTPOS][2]);
	
	else
		SetPlayerPosEx(playerid, PlayerInfo[playerb][E_CHARACTER_LASTPOS][0], PlayerInfo[playerb][E_CHARACTER_LASTPOS][1] - 1, PlayerInfo[playerb][E_CHARACTER_LASTPOS][2]);
		
	SetPlayerVirtualWorld(playerid, GetPlayerVirtualWorld(playerb));
	
	if(GetPlayerInterior(playerb) != 0)
		SetPlayerInterior(playerid, GetPlayerInterior(playerb)); 
		
	SendTeleportMessage(playerid);	
	
	if(PlayerInfo[playerid][E_CHARACTER_INSIDEPROP] || PlayerInfo[playerid][E_CHARACTER_INSIDEBIZ])
	{
		PlayerInfo[playerid][E_CHARACTER_INSIDEPROP] = 0; PlayerInfo[playerid][E_CHARACTER_INSIDEBIZ] = 0;
	}
	return 1;
}

CMD:bring(playerid, params[]) {

	return cmd_gethere(playerid, params);
}

CMD:gethere(playerid, params[])
{
	if(!IsPlayerAdmins(playerid))
		return SendUnauthMessage(playerid); 
		
	new playerb;
	
	if (sscanf(params, "u", playerb)) 
		return SendUsageMessage(playerid, "/gethere [playerid OR name]"); 
	
	if(!IsPlayerConnected(playerb))
		return SendErrorMessage(playerid, "The player you specified isn't connected."); 
		
	if(AccountInfo[playerid][E_MASTERS_LOGGED] == false)
		return SendErrorMessage(playerid, "The player you specified hasn't logged in yet.");
		
	GetPlayerPos(playerid, PlayerInfo[playerid][E_CHARACTER_LASTPOS][0], PlayerInfo[playerid][E_CHARACTER_LASTPOS][1], PlayerInfo[playerid][E_CHARACTER_LASTPOS][2]);

	
	if(GetPlayerState(playerb) == PLAYER_STATE_DRIVER)
		SetVehiclePos(GetPlayerVehicleID(playerb), PlayerInfo[playerid][E_CHARACTER_LASTPOS][0], PlayerInfo[playerid][E_CHARACTER_LASTPOS][1] - 1, PlayerInfo[playerid][E_CHARACTER_LASTPOS][2]);
		
	else
		SetPlayerPosEx(playerb, PlayerInfo[playerid][E_CHARACTER_LASTPOS][0], PlayerInfo[playerid][E_CHARACTER_LASTPOS][1] - 1, PlayerInfo[playerid][E_CHARACTER_LASTPOS][2]);
		
	SetPlayerVirtualWorld(playerb, GetPlayerVirtualWorld(playerid));
	
	if(GetPlayerInterior(playerid) != 0)
		SetPlayerInterior(playerb, GetPlayerInterior(playerid)); 
		
	SendTeleportMessage(playerb);
	SendInfoMessage(playerid, "%s was teleported to you.", ReturnSettingsName(playerb, playerid));
	
	return 1;
}

CMD:showmain(playerid, params[])
{
	if(!IsPlayerAdmins(playerid))
		return SendUnauthMessage(playerid); 
		
	new playerb;
	
	if (sscanf(params, "u", playerb)) 
		return SendUsageMessage(playerid, "/showmain [playerid OR name]"); 
	
	if(!IsPlayerConnected(playerb))
		return SendErrorMessage(playerid, "The player you specified isn't connected."); 
		
	if(AccountInfo[playerb][E_MASTERS_LOGGED] == false)
		return SendErrorMessage(playerid, "The player you specified hasn't logged in yet.");
	
	SendInfoMessage(playerid, "%s's Master account is \"%s\" (DBID: %i).", ReturnSettingsName(playerid, playerid), AccountInfo[playerid][E_MASTERS_ACCNAME], AccountInfo[playerid][E_MASTERS_DBID]);	
	return 1;
}

CMD:kick(playerid, params[])
{
	if(!IsPlayerAdmins(playerid))
		return SendUnauthMessage(playerid); 
		
	new playerb, reason[120];
	
	if (sscanf(params, "us[120]", playerb, reason)) 
		return SendUsageMessage(playerid, "/kick [playerid OR name] [reason]"); 
	
	if(!IsPlayerConnected(playerb))
		return SendErrorMessage(playerid, "The player you specified isn't connected."); 
		
	if(PlayerInfo[playerb][E_CHARACTER_ADMIN] > PlayerInfo[playerid][E_CHARACTER_ADMIN])
		return SendErrorMessage(playerid, "You can't kick %s.", ReturnSettingsName(playerb, playerid)); 
		
	if(strlen(reason) > 56)
	{
		SendClientMessageToAllEx(COLOR_RED, "AdmCmd: %s was kicked by %s, Reason: %.56s", ReturnSettingsName(playerb, playerid), ReturnSettingsName(playerid, playerid), reason);
		SendClientMessageToAllEx(COLOR_RED, "AdmCmd: ...%s", reason[56]); 
	}
	else SendClientMessageToAllEx(COLOR_RED, "AdmCmd: %s was kicked by %s, Reason: %s", ReturnSettingsName(playerb, playerid), ReturnSettingsName(playerid, playerid), reason);
	
	new insertLog[256];
	
	if(AccountInfo[playerb][E_MASTERS_LOGGED] == false)
	{
		SendInfoMessage(playerid, "The player (%s) you kicked was not logged in.", ReturnSettingsName(playerb, playerid));
	}
	
	mysql_format(ourConnection, insertLog, sizeof(insertLog), "INSERT INTO kick_logs (`KickedDBID`, `KickedName`, `Reason`, `KickedBy`, `Date`) VALUES(%i, '%e', '%e', '%e', '%e')",
		PlayerInfo[playerid][E_CHARACTER_DBID], ReturnSettingsName(playerb, playerid), reason, ReturnSettingsName(playerid, playerid), ReturnDate()); 
		
	mysql_pquery(ourConnection, insertLog); 

	KickEx(playerb);
	return 1;
}

CMD:oban(playerid, params[])
{
	if(!IsPlayerAdmins(playerid))
		return SendUnauthMessage(playerid); 
		
	new 
		insertQuery[256], 
		infoQuery[128], 
		playerb[32], 
		reason[120],
		masterDBID
	;
	
	if(sscanf(params, "s[32]s[120]", playerb, reason))
		return SendUsageMessage(playerid, "/offlineban [players name] [reason]");
		
	foreach(new i : Player)
	{
		if(!strcmp(ReturnSettingsName(i, i), playerb))
		{
			SendInfoMessage(playerid, "%s is connected to the server. (ID: %i)", playerb, i);
			return 1;
		}
	}
	
	if(!DoesPlayerExist(playerb))
		return SendErrorMessage(playerid, "%s doesn't exist in the database.", playerb); 
		
	mysql_format(ourConnection, infoQuery, sizeof(infoQuery), "SELECT master_dbid FROM characters WHERE char_name = '%e'", playerb);
	new Cache:cache = mysql_query(ourConnection, infoQuery); 
	
	cache_get_value_name_int(0, "master_dbid", masterDBID);
	cache_delete(cache);
	
	mysql_format(ourConnection, insertQuery, sizeof(insertQuery), "INSERT INTO bannedlist (CharacterDBID, MasterDBID, CharacterName, Reason, Date, BannedBy, IPAddress) VALUES(%i, %i, '%e', '%e', '%e', '%e', 'Offline')",
		ReturnDBIDFromName(playerb), masterDBID, playerb, reason, ReturnDate(), ReturnSettingsName(playerid, playerid));
		
	mysql_pquery(ourConnection, insertQuery, "OnOfflineBan", "isiiss", playerid, playerb, ReturnDBIDFromName(playerb), masterDBID, reason, ReturnDate()); 
	return 1;
}

CMD:ban(playerid, params[])
{
	if(!IsPlayerAdmins(playerid))
		return SendUnauthMessage(playerid); 
		
	new playerb, reason[120];
	
	if (sscanf(params, "us[120]", playerb, reason)) 
		return SendUsageMessage(playerid, "/ban [playerid OR name] [reason]"); 
	
	if(!IsPlayerConnected(playerb))
		return SendErrorMessage(playerid, "The player you specified isn't connected."); 
		
	if(PlayerInfo[playerb][E_CHARACTER_ADMIN] > PlayerInfo[playerid][E_CHARACTER_ADMIN])
		return SendErrorMessage(playerid, "You can't ban %s.", ReturnSettingsName(playerb, playerid)); 
		
	if(strlen(reason) > 56)
	{
		SendClientMessageToAllEx(COLOR_RED, "AdmCmd: %s was banned by %s, Reason: %.56s", ReturnSettingsName(playerb, playerid), ReturnSettingsName(playerid, playerid), reason);
		SendClientMessageToAllEx(COLOR_RED, "AdmCmd: ...%s", reason[56]); 
	}
	else SendClientMessageToAllEx(COLOR_RED, "AdmCmd: %s was banned by %s, Reason: %s", ReturnSettingsName(playerb, playerid), ReturnSettingsName(playerid, playerid), reason);
	
	new insertLog[256];
	
	if(AccountInfo[playerb][E_MASTERS_LOGGED] == false)
	{
		SendInfoMessage(playerid, "The player (%s) you selected isn't logged in.", ReturnSettingsName(playerb, playerid));
		SendInfoMessage(playerid, "Kick them OR use adminsys for further details.");
		return 1;
	}
	
	mysql_format(ourConnection, insertLog, sizeof(insertLog), "INSERT INTO bannedlist (`CharacterDBID`, `MasterDBID`, `CharacterName`, `Reason`, `Date`, `BannedBy`, `IpAddress`) VALUES(%i, %i, '%e', '%e', '%e', '%e', '%e')",
		PlayerInfo[playerb][E_CHARACTER_DBID], AccountInfo[playerid][E_MASTERS_DBID], ReturnSettingsName(playerb, playerid), reason, ReturnDate(), ReturnSettingsName(playerid, playerid), ReturnIP(playerb));
	
	mysql_pquery(ourConnection, insertLog); 
	
	mysql_format(ourConnection, insertLog, sizeof(insertLog), "INSERT INTO ban_logs (`CharacterDBID`, `MasterDBID`, `CharacterName`, `Reason`, `BannedBy`, `Date`) VALUES(%i, %i, '%e', '%e', '%e', '%e')",
		PlayerInfo[playerb][E_CHARACTER_DBID], AccountInfo[playerid][E_MASTERS_DBID], ReturnSettingsName(playerb, playerid), reason, ReturnSettingsName(playerid, playerid), ReturnDate());
		
	mysql_pquery(ourConnection, insertLog); 
	
	KickEx(playerb);
	return 1;
}

CMD:oajail(playerid, params[])
{
	if(!IsPlayerAdmins(playerid))
		return SendUnauthMessage(playerid); 
		
	new insertQuery[256], playerb[32], length, reason[128]; 
	
	if(sscanf(params, "s[32]ds[128]", playerb, length, reason))
		return SendUsageMessage(playerid, "/offlineajail [player name] [time in minutes] [reason]"); 
		
	foreach(new i : Player)
	{
		if(!strcmp(ReturnSettingsName(i, i), playerb))
		{
			SendInfoMessage(playerid, "%s is connected to the server. (ID: %i)", playerb, i);
			return 1;
		}
	}
	
	if(!DoesPlayerExist(playerb))
		return SendErrorMessage(playerid, "%s doesn't exist in the database.", playerb); 
		
	mysql_format(ourConnection, insertQuery, sizeof(insertQuery), "UPDATE characters SET pOfflinejailed = 1, pOfflinejailedReason = '%e', E_CHARACTER_ADMINJAIL = %i WHERE char_masters = '%e'", reason, length * 60, playerb);
	mysql_pquery(ourConnection, insertQuery, "OnOfflineAjail", "issi", playerid, playerb, reason, length); 

	return 1;
}

CMD:ajail(playerid, params[])
{
	if(!IsPlayerAdmins(playerid))
		return SendUnauthMessage(playerid); 
		
	new playerb, length, reason[120];
	
	if (sscanf(params, "uds[120]", playerb, length, reason)) 
		return SendUsageMessage(playerid, "/ajail [playerid OR name] [time in minutes] [reason]"); 
	
	if(!IsPlayerConnected(playerb))
		return SendErrorMessage(playerid, "The player you specified isn't connected."); 
		
	if(AccountInfo[playerb][E_MASTERS_LOGGED] == false)
		return SendErrorMessage(playerid, "The player you specified isn't logged in."); 
		
	if(length < 1)
		return SendErrorMessage(playerid, "You can't admin jail players for under a minute."); 
		
	if(strlen(reason) > 45)
	{
		SendClientMessageToAllEx(COLOR_RED, "AdmCmd: %s was admin jailed by %s for %d mintues, Reason: %.56s", ReturnSettingsName(playerb, playerid), ReturnSettingsName(playerid, playerid), length, reason);
		SendClientMessageToAllEx(COLOR_RED, "AdmCmd: ...%s", reason[56]); 
	}
	else SendClientMessageToAllEx(COLOR_RED, "AdmCmd: %s was admin jailed by %s for %d mintues, Reason: %s", ReturnSettingsName(playerb, playerid), ReturnSettingsName(playerid, playerid), length, reason);
	
	ClearAnimations(playerb); 
	
	SetPlayerPosEx(playerb, -10.5146,2337.2961,24.3034);
	SetPlayerInterior(playerb, 0); SetPlayerVirtualWorld(playerb, 999);
	
	PlayerInfo[playerb][E_CHARACTER_ADMINJAILED] = true;
	PlayerInfo[playerb][E_CHARACTER_ADMINJAIL] = length * 60; 
		
	SaveCharacter(playerb);
	
	new insertLog[250];
	
	mysql_format(ourConnection, insertLog, sizeof(insertLog), "INSERT INTO ajail_logs (`JailedDBID`, `JailedName`, `Reason`, `Date`, `JailedBy`, `Time`) VALUES(%i, '%e', '%e', '%e', '%e', %i)",
		PlayerInfo[playerb][E_CHARACTER_DBID], ReturnSettingsName(playerb, playerid), reason, ReturnDate(), ReturnSettingsName(playerid, playerid), length);
		
	mysql_pquery(ourConnection, insertLog);
	return 1;
}

CMD:rjail(playerid, params[])
{
	if(!IsPlayerAdmins(playerid))
		return SendUnauthMessage(playerid); 
		
	new playerb;
	
	if (sscanf(params, "u", playerb)) 
		return SendUsageMessage(playerid, "/rjail [playerid OR name]"); 
	
	if(!IsPlayerConnected(playerb))
		return SendErrorMessage(playerid, "The player you specified isn't connected."); 
		
	if(AccountInfo[playerb][E_MASTERS_LOGGED] == false)
		return SendErrorMessage(playerid, "The player you specified isn't logged in."); 
	
	if(PlayerInfo[playerb][E_CHARACTER_ADMINJAILED] == false)
		return SendErrorMessage(playerid, "The player you specified isn't admin jailed."); 
		
	SetPlayerVirtualWorld(playerb, 0); SetPlayerInterior(playerb, 0);
	SetPlayerPosEx(playerb, 1553.0421, -1675.4706, 16.1953);
	
	PlayerInfo[playerb][E_CHARACTER_ADMINJAILED] = false;
	PlayerInfo[playerb][E_CHARACTER_ADMINJAIL] = 0;
	
	SaveCharacter(playerb);
	SendClientMessageToAllEx(COLOR_RED, "AdmCmd: %s has been released from admin jail by %s.", ReturnSettingsName(playerb, playerid), ReturnSettingsName(playerid, playerid));
	return 1;
}

CMD:rprison(playerid, params[])
{
	if(!IsPlayerAdmins(playerid))
		return SendUnauthMessage(playerid); 
		
	new playerb;
	
	if (sscanf(params, "u", playerb)) 
		return SendUsageMessage(playerid, "/rprison [playerid OR name]"); 
	
	if(!IsPlayerConnected(playerb))
		return SendErrorMessage(playerid, "The player you specified isn't connected."); 
		
	if(AccountInfo[playerb][E_MASTERS_LOGGED] == false)
		return SendErrorMessage(playerid, "The player you specified isn't logged in."); 
	
	if(PlayerInfo[playerb][E_CHARACTER_PRISONED] == false)
		return SendErrorMessage(playerid, "The player you specified isn't prisoned."); 
		
	SetPlayerVirtualWorld(playerb, 0); SetPlayerInterior(playerb, 0);
	SetPlayerPosEx(playerb, 1797.4276,-1578.8496,14.0764);

	PlayerInfo[playerb][E_CHARACTER_PRISONED] = false;
	PlayerInfo[playerb][E_CHARACTER_PRISON] = 0;
	
	SaveCharacter(playerb);
	SendClientMessageToAllEx(COLOR_RED, "AdmCmd: %s has been released from prison by %s.", ReturnSettingsName(playerb, playerid), ReturnSettingsName(playerid, playerid));
	return 1;
}

CMD:setint(playerid, params[])
{
	if(!IsPlayerAdmins(playerid))
		return SendUnauthMessage(playerid); 
		
	new playerb, int, str[128];
	
	if (sscanf(params, "ud", playerb, int)) 
		return SendUsageMessage(playerid, "/setint [playerid OR name] [interior]"); 
	
	if(!IsPlayerConnected(playerb))
		return SendErrorMessage(playerid, "The player you specified isn't connected."); 
		
	if(AccountInfo[playerb][E_MASTERS_LOGGED] == false)
		return SendErrorMessage(playerid, "The player you specified isn't logged in."); 
	
	SetPlayerInterior(playerb, int);
	
	format(str, sizeof(str), "%s set %s's interior to %d.", ReturnSettingsName(playerid, playerid), ReturnSettingsName(playerb, playerid), int);
	SendAdminMessage(1, str);
	return 1;
}

CMD:setvw(playerid, params[])
{
	if(!IsPlayerAdmins(playerid))
		return SendUnauthMessage(playerid); 
		
	new playerb, world, str[128];
	
	if (sscanf(params, "ud", playerb, world)) 
		return SendUsageMessage(playerid, "/setvw [playerid OR name] [world]"); 
	
	if(!IsPlayerConnected(playerb))
		return SendErrorMessage(playerid, "The player you specified isn't connected."); 
		
	if(AccountInfo[playerb][E_MASTERS_LOGGED] == false)
		return SendErrorMessage(playerid, "The player you specified isn't logged in."); 
	
	SetPlayerVirtualWorld(playerb, world);
	
	format(str, sizeof(str), "%s set %s's local world to %d.", ReturnSettingsName(playerid, playerid), ReturnSettingsName(playerb, playerid), world);
	SendAdminMessage(1, str);
	return 1;
}

CMD:skin(playerid, params[])
{
	if(!IsPlayerAdmins(playerid))
		return SendUnauthMessage(playerid); 
		
	new playerb, skinid, str[128];
	
	if (sscanf(params, "ud", playerb, skinid)) 
		return SendUsageMessage(playerid, "/skin [playerid OR name] [skinid]"); 
	
	if(!IsPlayerConnected(playerb))
		return SendErrorMessage(playerid, "The player you specified isn't connected."); 
		
	if(AccountInfo[playerb][E_MASTERS_LOGGED] == false)
		return SendErrorMessage(playerid, "The player you specified isn't logged in."); 
		
	PlayerInfo[playerb][E_CHARACTER_LASTSKIN] = skinid; SetPlayerSkin(playerb, skinid);
	
	format(str, sizeof(str), "%s set %s's skin to %d.", ReturnSettingsName(playerid, playerid), ReturnSettingsName(playerb, playerid), skinid);
	SendAdminMessage(1, str);
	return 1;
}

CMD:health(playerid, params[])
{
	if(!IsPlayerAdmins(playerid))
		return SendUnauthMessage(playerid); 
		
	new playerb, health, str[128];
	
	if (sscanf(params, "ud", playerb, health)) 
		return SendUsageMessage(playerid, "/health [playerid OR name] [health]"); 
	
	if(!IsPlayerConnected(playerb))
		return SendErrorMessage(playerid, "The player you specified isn't connected."); 
		
	if(AccountInfo[playerb][E_MASTERS_LOGGED] == false)
		return SendErrorMessage(playerid, "The player you specified isn't logged in."); 
		
	if(health > 150)
		return SendErrorMessage(playerid, "You can't set health over 150."); 
		
	SetPlayerHealthEx(playerb, health);
	
	format(str, sizeof(str), "%s set %s's health to %d.", ReturnSettingsName(playerid, playerid), ReturnSettingsName(playerb, playerid), health);
	SendAdminMessage(1, str);
	return 1;
}

CMD:reports(playerid, params[])
{
	if(!IsPlayerAdmins(playerid))
		return 0;
		
	SendClientMessage(playerid, COLOR_DARKGREEN, "____________________REPORTS____________________");
		
	for (new i = 0; i < sizeof(ReportInfo); i ++)
	{
		if(ReportInfo[i][E_REPORT_EXISTS] == true)
		{
			if(strlen(ReportInfo[i][E_REPORT_DETAILS]) > 65)
			{
				SendClientMessageEx(playerid, COLOR_REPORT, "%s (ID: %d) | RID: %d | Report: %.65s", ReturnSettingsName(ReportInfo[i][E_REPORT_BY], playerid), ReportInfo[i][E_REPORT_BY], i, ReportInfo[i][E_REPORT_DETAILS]);
				SendClientMessageEx(playerid, COLOR_REPORT, "...%s | Pending: %d Sec ago", ReportInfo[i][E_REPORT_DETAILS][65], gettime() - ReportInfo[i][E_REPORT_TIME]);
			}
			else SendClientMessageEx(playerid, COLOR_REPORT, "%s (ID: %d) | RID: %d | Report: %s | Pending: %d Sec ago", ReturnSettingsName(ReportInfo[i][E_REPORT_BY], playerid), ReportInfo[i][E_REPORT_BY], i, ReportInfo[i][E_REPORT_DETAILS], gettime() - ReportInfo[i][E_REPORT_TIME]);
		}
	}
	return 1;
}

CMD:ar(playerid, params[])
{
	if(!IsPlayerAdmins(playerid))
		return 0;
		
	new reportid;
	
	if (sscanf(params, "d", reportid))
		return SendUsageMessage(playerid, "/acceptreport [report id]"); 
	
	if(ReportInfo[reportid][E_REPORT_EXISTS] == false)
		return SendErrorMessage(playerid, "The report ID you specified doesn't exist."); 
		
	SendAdminMessageEx(COLOR_RED, 1, "[Report] Admin %s has accepted report %d", ReturnSettingsName(playerid, playerid), reportid);
	SendClientMessageEx(playerid, COLOR_DARKGREEN, "[Report] You accepted %s's report. [Report: %s]", ReturnSettingsName(ReportInfo[reportid][E_REPORT_BY], playerid), ReportInfo[reportid][E_REPORT_DETAILS]);
	
	ReportInfo[reportid][E_REPORT_EXISTS] = false;
	ReportInfo[reportid][E_REPORT_BY] = INVALID_PLAYER_ID; 
	
	//You can include a message to the reporter if you would like;
	return 1; 
}

CMD:dr(playerid, params[])
{
	if(!IsPlayerAdmins(playerid))
		return 0;
		
	new reportid;
	
	if (sscanf(params, "d", reportid))
		return SendUsageMessage(playerid, "/disregardreport [report id]"); 
	
	if(ReportInfo[reportid][E_REPORT_EXISTS] == false)
		return SendErrorMessage(playerid, "The report ID you specified doesn't exist."); 
		
	SendAdminMessageEx(COLOR_RED, 1, "[Report] Admin %s has disregarded report %d", ReturnSettingsName(playerid, playerid), reportid);
	
	ReportInfo[reportid][E_REPORT_EXISTS] = false;
	ReportInfo[reportid][E_REPORT_BY] = INVALID_PLAYER_ID; 
	
	//You can include a message to the reporter if you would like;
	return 1; 
}

CMD:slap(playerid, params[])
{
	if(!IsPlayerAdmins(playerid))
		return SendUnauthMessage(playerid);
		
	new playerb;
	
	if (sscanf(params, "u", playerb))
		return SendUsageMessage(playerid, "/slap [playerid OR name]");
		
	if(!IsPlayerConnected(playerb))
		return SendErrorMessage(playerid, "The player you specified isn't connected."); 
		
	if(AccountInfo[playerb][E_MASTERS_LOGGED] == false)
		return SendErrorMessage(playerid, "The player you specified isn't logged in."); 
		
	GetPlayerPos(playerb, PlayerInfo[playerb][E_CHARACTER_LASTPOS][0], PlayerInfo[playerb][E_CHARACTER_LASTPOS][1], PlayerInfo[playerb][E_CHARACTER_LASTPOS][2]);
	//Using the player variable to avoid making other variables; 
	
	SetPlayerPosEx(playerb, PlayerInfo[playerb][E_CHARACTER_LASTPOS][0], PlayerInfo[playerb][E_CHARACTER_LASTPOS][1], PlayerInfo[playerb][E_CHARACTER_LASTPOS][2] + 5); 
	PlayNearbySound(playerb, 1130); //Slap sound;
	
	SendInfoMessage(playerid, "%s slapped %s", ReturnSettingsName(playerid, playerid), ReturnSettingsName(playerb, playerid));
	if(playerb != playerid) SendInfoMessage(playerb, "%s slapped %s", ReturnSettingsName(playerid, playerid), ReturnSettingsName(playerb, playerid));

	PauseAC(playerb);
	return 1;
}



CMD:freeze(playerid, params[])
{
	if(!IsPlayerAdmins(playerid))
		return SendUnauthMessage(playerid);
		
	new playerb, str[128];
	
	if (sscanf(params, "u", playerb))
		return SendUsageMessage(playerid, "/freeze [playerid OR name]");
		
	if(!IsPlayerConnected(playerb))
		return SendErrorMessage(playerid, "The player you specified isn't connected."); 
		
	if(AccountInfo[playerb][E_MASTERS_LOGGED] == false)
		return SendErrorMessage(playerid, "The player you specified isn't logged in."); 
		
	TogglePlayerControllable(playerid, false);
	
	format(str, sizeof(str), "%s froze player %s.", ReturnSettingsName(playerid, playerid), ReturnSettingsName(playerb, playerid));
	SendAdminMessage(1, str);
	return 1;
}

CMD:unfreeze(playerid, params[])
{
	if(!IsPlayerAdmins(playerid))
		return SendUnauthMessage(playerid);
		
	new playerb, str[128];
	
	if (sscanf(params, "u", playerb))
		return SendUsageMessage(playerid, "/unfreeze [playerid OR name]");
		
	if(!IsPlayerConnected(playerb))
		return SendErrorMessage(playerid, "The player you specified isn't connected."); 
		
	if(AccountInfo[playerb][E_MASTERS_LOGGED] == false)
		return SendErrorMessage(playerid, "The player you specified isn't logged in."); 
		
	TogglePlayerControllable(playerb, true);
	
	format(str, sizeof(str), "%s unfroze player %s.", ReturnSettingsName(playerid, playerid), ReturnSettingsName(playerb, playerid));
	SendAdminMessage(1, str);
	return 1;
}

UpdateSpectatorPanel(playerid, targetid) 
{

	if(PlayerInfo[playerid][E_CHARACTER_SPECTATE] != targetid) 
	{
		for (new i, j = 5; i < j ; i ++ ) 
		{
			PlayerTextDrawHide(playerid, gui_spec_label[playerid][i]);
		}
		return 1;
	}

	new 
		interiorid = GetPlayerInterior(targetid), 
		worldid = GetPlayerVirtualWorld(targetid),
		Float:health = PlayerInfo[targetid][E_CHARACTER_HEALTH],
		Float:armour = PlayerInfo[targetid][E_CHARACTER_ARMOUR],
		Float:packet_loss = NetStats_PacketLossPercent(targetid),
		ping = GetPlayerPing(targetid),
		drunk_lvl = GetPlayerDrunkLevel(targetid);

	new coords[64], Float:x, Float:y, Float:z, Float:a;
	GetPlayerPos(targetid, x, y, z);
	GetPlayerFacingAngle(targetid, a);
	format(coords, sizeof (coords), "<%0.2f, %0.2f, %0.2f, %0.2f>", x, y, z, a);

	new vehicleid = GetPlayerVehicleID (targetid), 
	vehiclemodel = GetVehicleModel(vehicleid), Float: veh_health;
	GetVehicleHealth(vehicleid, veh_health);
	new vehiclename[128];
	format(vehiclename, sizeof(vehiclename), "Disabled");

	new Float: clienthealth, Float: clientarmour ;
	GetPlayerHealth(targetid, clienthealth);
	GetPlayerArmour(targetid, clientarmour);

	new td_string[1024];
	format (td_string, sizeof (td_string), "(%d) %s (%s)", targetid, PlayerInfo[targetid][E_CHARACTER_NAME], AccountInfo[targetid][E_MASTERS_ACCNAME]);
	PlayerTextDrawSetString(playerid, gui_spec_label[playerid][0], td_string);

	format (td_string, sizeof (td_string), "~w~Interior ~p~<%d> ~w~World ~p~<%d> ~w~Coords: ~p~%s", interiorid, worldid, coords);
	PlayerTextDrawSetString(playerid, gui_spec_label[playerid][1], td_string);

	format (td_string, sizeof(td_string), "~w~Health: ~r~%0.1f (client: %0.1f)~w~ Armour: ~r~%0.1f (client: %0.1f)", health, clienthealth, armour, clientarmour);
	PlayerTextDrawSetString(playerid, gui_spec_label[playerid][2], td_string);

	format (td_string, sizeof(td_string), "Packet Loss:~g~ %0.2f'/.~w~ Ping:~g~ %d~w~ Drunk Level: ~g~%d", packet_loss, ping, drunk_lvl);
	PlayerTextDrawSetString(playerid, gui_spec_label[playerid][3], td_string);

	format (td_string, sizeof(td_string), "Vehicle:~b~ %s: ~y~MOD: %d, VID: %d~w~ Vehicle Health:~b~ %0.2f", vehiclename, vehiclemodel, vehicleid, veh_health );
	PlayerTextDrawSetString(playerid, gui_spec_label[playerid][4], td_string);

	return 1;
}

CMD:spec(playerid, params[])
{
	if(!IsPlayerAdmins(playerid))
		return SendUnauthMessage(playerid);
		
	new playerb;
	
	if (sscanf(params, "u", playerb))
		return SendUsageMessage(playerid, "/spec [playerid OR name]");
		
	if(!IsPlayerConnected(playerb))
		return SendErrorMessage(playerid, "The player you specified isn't connected."); 
		
	if(AccountInfo[playerb][E_MASTERS_LOGGED] == false)
		return SendErrorMessage(playerid, "The player you specified isn't logged in."); 
		
	if(PlayerInfo[playerb][E_CHARACTER_SPECTATE] != INVALID_PLAYER_ID)
		return SendErrorMessage(playerid, "That player is spectating another player."); 
		
	//if(playerb == playerid) return SendErrorMessage(playerid, "You can't spectate yourself.");
		
	if(GetPlayerState(playerid) != PLAYER_STATE_SPECTATING)
	{
		GetPlayerPos(playerid, PlayerInfo[playerid][E_CHARACTER_LASTPOS][0], PlayerInfo[playerid][E_CHARACTER_LASTPOS][1], PlayerInfo[playerid][E_CHARACTER_LASTPOS][2]);
		
		PlayerInfo[playerid][E_CHARACTER_LASTINTERIOR] = GetPlayerInterior(playerid);
		PlayerInfo[playerid][E_CHARACTER_LASTWORLD] = GetPlayerVirtualWorld(playerid);
	}

	for ( new i, j = 5; i < j ; i ++ ) {
		PlayerTextDrawShow(playerid, gui_spec_label[playerid][i]);
	}
	UpdateSpectatorPanel(playerid, playerb); 
	
	SetPlayerInterior(playerid, GetPlayerInterior(playerb));
	SetPlayerVirtualWorld(playerid, GetPlayerVirtualWorld(playerb));
	
	TogglePlayerSpectating(playerid, true); 
	PlayerSpectatePlayer(playerid, playerb);
		
	PlayerInfo[playerid][E_CHARACTER_SPECTATE] = playerb; 
	SendInfoMessage(playerid, "You're now spectating %s. To stop, use \"/specoff\".", ReturnSettingsName(playerb, playerid));
	return 1;
}

CMD:specoff(playerid, params[])
{
	if(!IsPlayerAdmins(playerid))
		return SendUnauthMessage(playerid);
		
	if (GetPlayerState(playerid) != PLAYER_STATE_SPECTATING)
		return SendErrorMessage(playerid, "You aren't spectating anyone."); 
		
	SendInfoMessage(playerid, "You stopped spectating %s.", ReturnSettingsName(PlayerInfo[playerid][E_CHARACTER_SPECTATE], playerid));
	
	PlayerInfo[playerid][E_CHARACTER_SPECTATE] = INVALID_PLAYER_ID;
	TogglePlayerSpectating(playerid, false); 
	DestroySpectatorPanel(playerid);
	return 1;
}

CMD:gotols(playerid, params[])
{
	if(!IsPlayerAdmins(playerid))
		return SendUnauthMessage(playerid);
		
	SetPlayerPosEx(playerid, 1514.1836, -1677.8027, 14.0469);
	SetPlayerInterior(playerid, 0); SetPlayerVirtualWorld(playerid, 0);
	
	if(PlayerInfo[playerid][E_CHARACTER_INSIDEPROP] || PlayerInfo[playerid][E_CHARACTER_INSIDEBIZ])
	{
		PlayerInfo[playerid][E_CHARACTER_INSIDEPROP] = 0; PlayerInfo[playerid][E_CHARACTER_INSIDEBIZ] = 0;
	}
	
	SendTeleportMessage(playerid);
	return 1;
}

CMD:respawncar(playerid, params[])
{
	new option[10], param[12], str[256];

    if(!IsPlayerAdmins(playerid))
		return SendUnauthMessage(playerid);

	if(sscanf(params, "s[10]S()[12]", option, param))
	{
	    return SendUsageMessage(playerid, "/respawncar [job | faction | nearby | all]");
	}
	if(!strcmp(option, "job", true))
	{
		for(new i = 1; i < MAX_VEHICLES; i ++)
		{
	    	if(IsValidVehicle(i) && !IsVehicleOccupied(i))
		    {
		        if((Jobs_vehicles[0] <= i <= Jobs_vehicles[11]) || (g_Vehicle[0] <= i <= g_Vehicle[37]))
		        {
	        		SetVehicleToRespawnEx(i);
				}
	 		}
		}

		format(str, sizeof(str), "%s respawned static vehicle.", ReturnSettingsName(playerid, playerid));
		SendAdminMessage(1, str);
	}
	else if(!strcmp(option, "faction", true))
	{
	    for(new i = 1; i < MAX_VEHICLES; i ++)
		{
	    	if(IsValidVehicle(i) && !IsVehicleOccupied(i))
		    {
		        if((GSF_Vehicles[0] <= i <= GSF_Vehicles[6]) || (KTB_Vehicles[0] <= i <= KTB_Vehicles[4]) || (JB_Vehicles[0] <= i <= JB_Vehicles[6]) || (SBF_Vehicles[0] <= i <= SBF_Vehicles[6]) || (VLA_Vehicles[0] <= i <= VLA_Vehicles[5]) || (ELSV_Vehicles[0] <= i <= ELSV_Vehicles[5]) \
				|| (FYB_Vehicles[0] <= i <= FYB_Vehicles[5]) || (TDB_Vehicles[0] <= i <= TDB_Vehicles[5]) || (TDF_Vehicles[0] <= i <= TDF_Vehicles[5]) || (LSPDVehicles[0] <= i <= LSPDVehicles[17]))
		        {
	        		SetVehicleToRespawnEx(i);
				}
	 		}
		}

		format(str, sizeof(str), "%s respawned faction vehicle.", ReturnSettingsName(playerid, playerid));
		SendAdminMessage(1, str);
	}
	else if(!strcmp(option, "nearby", true))
	{
		for(new i = 1; i < MAX_VEHICLES; i ++)
		{
	    	if(IsValidVehicle(i) && !IsVehicleOccupied(i) && IsVehicleStreamedIn(i, playerid))
		    {
				SetVehicleToRespawnEx(i);
			}
		}

		format(str, sizeof(str), "%s respawned nearest vehicle.", ReturnSettingsName(playerid, playerid));
		SendAdminMessage(1, str);
	}
	else if(!strcmp(option, "all", true))
	{
		for(new i = 1; i < MAX_VEHICLES; i ++)
		{
	    	if(IsValidVehicle(i) && !IsVehicleOccupied(i))
		    {
				SetVehicleToRespawnEx(i);
			}
		}

		format(str, sizeof(str), "%s respawned all vehicle.", ReturnSettingsName(playerid, playerid));
		SendAdminMessage(1, str);
	}
	
	return 1;
}

CMD:gotocar(playerid, params[])
{
	if(!IsPlayerAdmins(playerid))
		return SendUnauthMessage(playerid);
		
	new vehicleid;
	
	if(sscanf(params, "d", vehicleid))
		return SendUsageMessage(playerid, "/gotocar [vehicleid]");
		
	if(!IsValidVehicle(vehicleid))
		return SendErrorMessage(playerid, "You specified an invalid vehicle.");
		
	new Float: fetchPos[3];
	GetVehiclePos(vehicleid, fetchPos[0], fetchPos[1], fetchPos[2]);
	
	if(GetPlayerState(playerid) == PLAYER_STATE_DRIVER)
		SetVehiclePos(GetPlayerVehicleID(playerid), fetchPos[0], fetchPos[1], fetchPos[2]);
	
	else
		SetPlayerPosEx(playerid, fetchPos[0], fetchPos[1], fetchPos[2]);
		
	SendTeleportMessage(playerid);
	
	if(PlayerInfo[playerid][E_CHARACTER_INSIDEPROP] || PlayerInfo[playerid][E_CHARACTER_INSIDEBIZ])
	{
		PlayerInfo[playerid][E_CHARACTER_INSIDEPROP] = 0; PlayerInfo[playerid][E_CHARACTER_INSIDEBIZ] = 0;
	}
	return 1;
}

CMD:getcar(playerid, params[])
{
	if(!IsPlayerAdmins(playerid))
		return SendUnauthMessage(playerid);
		
	new 
		vehicleid,
		Float:x,
		Float:y,
		Float:z,
		str[128]
	;
	
	if(sscanf(params, "d", vehicleid))
		return SendUsageMessage(playerid, "/gotocar [vehicleid]");
		
	if(!IsValidVehicle(vehicleid))
		return SendErrorMessage(playerid, "You specified an invalid vehicle.");
	
	GetPlayerPos(playerid, x, y, z);
	
	SetVehiclePos(vehicleid, x, y, z);
	LinkVehicleToInterior(vehicleid, GetPlayerInterior(playerid)); 
	
	format(str, sizeof(str), "%s teleported vehicle ID %i", ReturnSettingsName(playerid, playerid), vehicleid);
	SendAdminMessage(1, str); 
	
	foreach(new i : Player)
	{
		if(!IsPlayerInAnyVehicle(i))
			continue;
			
		if(GetPlayerVehicleID(i) == vehicleid)
		{
			SendInfoMessage(i, "The vehicle you were in (%i) was teleported.", vehicleid); 
		}
	}
	return 1;
}

CMD:aooc(playerid, params[])
{
	if(!IsPlayerAdmins(playerid))
		return SendUnauthMessage(playerid);
		
	if(isnull(params)) return SendUsageMessage(playerid, "/aooc [text]"); 
	
	if(strcmp(AccountInfo[playerid][E_MASTERS_FORUMNAME], "Null"))
		SendClientMessageToAllEx(COLOR_RED, "[AOOC] Admin %s (%s): %s", ReturnSettingsName(playerid, playerid), AccountInfo[playerid][E_MASTERS_FORUMNAME], params);
		
	else SendClientMessageToAllEx(COLOR_RED, "[AOOC] Admin %s: %s", ReturnSettingsName(playerid, playerid), params);
	return 1;
}

CMD:revive(playerid, params[])
{
	new 
		playerb,
		str[128];

	if(!IsPlayerAdmins(playerid))
		return SendUnauthMessage(playerid);
		
	if(sscanf(params, "u", playerb))
		return SendUsageMessage(playerid, "/revive [playerid OR name]"); 
		
	if(!IsPlayerConnected(playerb))
		return SendErrorMessage(playerid, "The player you specified isn't connected."); 
		
	if(AccountInfo[playerid][E_MASTERS_LOGGED] == false)
		return SendErrorMessage(playerid, "The player you specified isn't logged in."); 
		
	if(GetPlayerTeam(playerb) == PLAYER_STATE_ALIVE)
		return SendErrorMessage(playerid, "That player isn't dead or brutally wounded.");
	
	format(str, sizeof(str), "%s revived player %s.", ReturnSettingsName(playerid, playerid), ReturnSettingsName(playerb, playerid));
	SendAdminMessage(1, str); 
	
	SetPlayerTeam(playerb, PLAYER_STATE_ALIVE); 
	SetPlayerHealthEx(playerb, 100); 
	
	TogglePlayerControllable(playerb, true); 
	
	SetPlayerChatBubble(playerb, "(( Respawned ))", COLOR_WHITE, 21.0, 3000); 
	ShowBoxMessage(playerb, "~b~You were revived", 3);
	
	ClearDamages(playerb);
	return 1;
}

//Level 2 Admin commands:
CMD:armor(playerid, params[])
{
	if(IsPlayerAdmins(playerid) < ADMINS_HIGH)
		return SendUnauthMessage(playerid); 
		
	new playerb, armor, str[128];
	
	if (sscanf(params, "ud", playerb, armor)) 
		return SendUsageMessage(playerid, "/armor [playerid OR name] [armor]"); 
	
	if(!IsPlayerConnected(playerb))
		return SendErrorMessage(playerid, "The player you specified isn't connected."); 
		
	if(AccountInfo[playerb][E_MASTERS_LOGGED] == false)
		return SendErrorMessage(playerid, "The player you specified isn't logged in."); 
		
	if(armor > 200)
		return SendErrorMessage(playerid, "You can't set armor above 200."); 
		
	SetPlayerArmourEx(playerb, armor);
	
	format(str, sizeof(str), "%s set %s's Armor to %d.", ReturnSettingsName(playerid, playerid), ReturnSettingsName(playerb, playerid), armor);
	SendAdminMessage(1, str);
	return 1;
}

CMD:clearreports(playerid, params[])
{
	if(IsPlayerAdmins(playerid) < ADMINS_HIGH)
		return 0;
		
	new reportCount = 0;
	
	for (new i = 0; i < sizeof(ReportInfo); i ++)
	{
		if(ReportInfo[i][E_REPORT_EXISTS] == true)
		{
			reportCount++;
		}
	}
	if(reportCount)
	{
		new string[128]; 
		
		format(string, sizeof(string), "{FFFFFF}Are you sure you want to clear ALL active reports?\n\nThere are {FF6347}%d{FFFFFF} report(s).", reportCount);
		ConfirmDialog(playerid, "Confirmation", string, "ClearReports", reportCount); 
	}
	else return SendInfoMessage(playerid, "There are no active reports to clear.");
	return 1;
}

CMD:p2p(playerid, params[])
{
	if(IsPlayerAdmins(playerid) < ADMINS_HIGH)
		return SendUnauthMessage(playerid);
		
	new playerb, targetid, str[128]; 
	
	if(sscanf(params, "uu", playerb, targetid))
		return SendUsageMessage(playerid, "/p2p [playerid] [targetid]");
	
	if (!IsPlayerConnected(playerb) || !IsPlayerConnected(targetid))
		return SendErrorMessage(playerid, "A player you specified isn't connected to the server."); 
		
	if (AccountInfo[playerb][E_MASTERS_LOGGED] == false || AccountInfo[targetid][E_MASTERS_LOGGED] == false)
		return SendErrorMessage(playerid, "A player you specified isn't logged in."); 
		
	format(str, sizeof(str), "%s teleported player %s to %s.", ReturnSettingsName(playerid, playerid), ReturnSettingsName(playerb, playerid), ReturnSettingsName(targetid, playerid));
	SendAdminMessage(1, str);
	
	GetPlayerPos(targetid, PlayerInfo[targetid][E_CHARACTER_LASTPOS][0], PlayerInfo[targetid][E_CHARACTER_LASTPOS][1], PlayerInfo[targetid][E_CHARACTER_LASTPOS][2]);
	//Using the player variable to avoid making other variables; 
	
	SetPlayerPosEx(playerb, PlayerInfo[targetid][E_CHARACTER_LASTPOS][0], PlayerInfo[targetid][E_CHARACTER_LASTPOS][1], PlayerInfo[targetid][E_CHARACTER_LASTPOS][2]);
	SetPlayerInterior(playerb, GetPlayerInterior(targetid)); SetPlayerVirtualWorld(playerb, GetPlayerVirtualWorld(targetid)); 
	
	SendTeleportMessage(playerb);
	return 1;
}

CMD:setinv(playerid, params[]) return cmd_setinventory(playerid, params);
CMD:setinventory(playerid, params[])
{
	static
	    userid,
		item[32],
		amount;

	if(IsPlayerAdmins(playerid) < ADMINS_OPERATOR)
		return SendUnauthMessage(playerid);

	if (sscanf(params, "uds[32]", userid, amount, item))
	    return SendUsageMessage(playerid, "/setinventory [playerid/name] [amount] [item name]");

	for (new i = 0; i < sizeof(g_aInventoryItems); i ++) if (!strcmp(g_aInventoryItems[i][E_INVENTORY_ITEM], item, true))
	{
        Inventory_Set(userid, g_aInventoryItems[i][E_INVENTORY_ITEM], g_aInventoryItems[i][E_INVENTORY_MODEL], amount, g_aInventoryItems[i][E_INVENTORY_TYPE]);

		return SendInfoMessage(playerid, "You have set %s's \"%s\" to %d.", ReturnSettingsName(userid, playerid), item, amount);
	}
	SendErrorMessage(playerid, "Invalid item name (use /itemlist for a list).");
	return 1;
}

CMD:itemlist(playerid, params[])
{
	new
	    string[512];

	if (!strlen(string)) {
		for (new i = 0; i < sizeof(g_aInventoryItems); i ++) {
			format(string, sizeof(string), "%s%s\n", string, g_aInventoryItems[i][E_INVENTORY_ITEM]);
		}
	}
	return ShowPlayerDialog(playerid, DIALOG_DEFAULT, DIALOG_STYLE_LIST, "List of Items:", string, "Select", "Cancel");
}

CMD:gotoentrance(playerid, params[])
{
	new id;
	
	if(IsPlayerAdmins(playerid) < ADMINS_HIGH)
		return SendUnauthMessage(playerid);
	
	if(sscanf(params, "i", id))
		return SendUsageMessage(playerid, "/gotoentrance [entrance ID]");
		
	if(!EntranceInfo[id][E_ENTRANCE_DBID] || id > MAX_ENTRANCE)
		return SendErrorMessage(playerid, "The entrance you specified doesn't exist.");
		
	SetPlayerPosEx(playerid, EntranceInfo[id][E_ENTRANCE_POS][0], EntranceInfo[id][E_ENTRANCE_POS][1], EntranceInfo[id][E_ENTRANCE_POS][2]);
	
	SendInfoMessage(playerid, "You teleported to entrance %i.", id);
	
	if(PlayerInfo[playerid][E_CHARACTER_INSIDEPROP] || PlayerInfo[playerid][E_CHARACTER_INSIDEBIZ] || PlayerInfo[playerid][E_CHARACTER_INSIDEENT])
	{
		PlayerInfo[playerid][E_CHARACTER_INSIDEPROP] = 0; PlayerInfo[playerid][E_CHARACTER_INSIDEBIZ] = 0; PlayerInfo[playerid][E_CHARACTER_INSIDEENT] = 0;
	}
	return 1;
}

CMD:gotoproperty(playerid, params[])
{
	new id;
	
	if(IsPlayerAdmins(playerid) < ADMINS_HIGH)
		return SendUnauthMessage(playerid);
	
	if(sscanf(params, "i", id))
		return SendUsageMessage(playerid, "/gotoproperty [property ID]");
		
	if(!PropertyInfo[id][E_PROPERTY_DBID] || id > MAX_PROPERTY)
		return SendErrorMessage(playerid, "The property you specified doesn't exist.");
		
	SetPlayerPosEx(playerid, PropertyInfo[id][E_PROPERTY_ENTRANCEPOS][0], PropertyInfo[id][E_PROPERTY_ENTRANCEPOS][1], PropertyInfo[id][E_PROPERTY_ENTRANCEPOS][2]);
	
	SetPlayerVirtualWorld(playerid, PropertyInfo[id][E_PROPERTY_ENTRANCEWORLD]);
	SetPlayerInterior(playerid, PropertyInfo[id][E_PROPERTY_ENTRANCEINTERIOR]);
	
	SendInfoMessage(playerid, "You teleported to Property %i.", id);
	
	if(PlayerInfo[playerid][E_CHARACTER_INSIDEPROP] || PlayerInfo[playerid][E_CHARACTER_INSIDEBIZ] || PlayerInfo[playerid][E_CHARACTER_INSIDEENT])
	{
		PlayerInfo[playerid][E_CHARACTER_INSIDEPROP] = 0; PlayerInfo[playerid][E_CHARACTER_INSIDEBIZ] = 0; PlayerInfo[playerid][E_CHARACTER_INSIDEENT] = 0;
	}
	return 1;
}

CMD:gotobusiness(playerid, params[])
{
	new id;
	
	if(IsPlayerAdmins(playerid) < ADMINS_HIGH)
		return SendUnauthMessage(playerid);
	
	if(sscanf(params, "i", id))
		return SendUsageMessage(playerid, "/gotobusiness [business ID]");
		
	if(!BusinessInfo[id][E_BUSINESS_DBID] || id > MAX_BUSINESS)
		return SendErrorMessage(playerid, "The business you specified doesn't exist.");
		
	SetPlayerPosEx(playerid, BusinessInfo[id][E_BUSINESS_ENTRANCEPOS][0], BusinessInfo[id][E_BUSINESS_ENTRANCEPOS][1], BusinessInfo[id][E_BUSINESS_ENTRANCEPOS][2]); 
	SendInfoMessage(playerid, "You teleported to business %i.", id); 
	
	if(PlayerInfo[playerid][E_CHARACTER_INSIDEPROP] || PlayerInfo[playerid][E_CHARACTER_INSIDEBIZ] || PlayerInfo[playerid][E_CHARACTER_INSIDEENT])
	{
		PlayerInfo[playerid][E_CHARACTER_INSIDEPROP] = 0; PlayerInfo[playerid][E_CHARACTER_INSIDEBIZ] = 0; PlayerInfo[playerid][E_CHARACTER_INSIDEENT] = 0;
	}
	return 1;
}

CMD:gotofaction(playerid, params[])
{
	new id;
	
	if(IsPlayerAdmins(playerid) < ADMINS_HIGH)
		return SendUnauthMessage(playerid);
	
	if(sscanf(params, "i", id))
		return SendUsageMessage(playerid, "/gotofaction [faction ID]");
		
	if(!FactionInfo[id][E_FACTION_DBID] || id > MAX_FACTIONS)
		return SendErrorMessage(playerid, "The faction you specified doesn't exist.");
		
	SetPlayerPosEx(playerid, FactionInfo[id][E_FACTION_SPAWN][0], FactionInfo[id][E_FACTION_SPAWN][1], FactionInfo[id][E_FACTION_SPAWN][2]);
	
	SetPlayerVirtualWorld(playerid, FactionInfo[id][E_FACTION_SPAWNWORLD]);
	SetPlayerInterior(playerid, FactionInfo[id][E_FACTION_SPAWNINT]); 
	
	SendInfoMessage(playerid, "You teleported to %s's spawn point.", ReturnFactionNameEx(id)); 

	if(PlayerInfo[playerid][E_CHARACTER_INSIDEPROP] || PlayerInfo[playerid][E_CHARACTER_INSIDEBIZ])
	{
		PlayerInfo[playerid][E_CHARACTER_INSIDEPROP] = 0; PlayerInfo[playerid][E_CHARACTER_INSIDEBIZ] = 0;
	}
	return 1;
}

CMD:xyz(playerid, params[])
{
	if(IsPlayerAdmins(playerid) < ADMINS_HIGH)
		return SendUnauthMessage(playerid);

	new
		Float:x,
		Float:y,
		Float:z,
		interior
	; 
	
	if(sscanf(params, "fffi", x, y, z, interior))
		return SendUsageMessage(playerid, "/xyz [x] [y] [z] [interior id]"); 
		
	SetPlayerPosEx(playerid, x, y, z);
	SetPlayerInterior(playerid, interior);
	
	SendTeleportMessage(playerid);
	
	if(PlayerInfo[playerid][E_CHARACTER_INSIDEPROP] || PlayerInfo[playerid][E_CHARACTER_INSIDEBIZ])
	{
		PlayerInfo[playerid][E_CHARACTER_INSIDEPROP] = 0; PlayerInfo[playerid][E_CHARACTER_INSIDEBIZ] = 0;
	}
	return 1;
}

CMD:backup(playerid, params[])
{
	if(IsPlayerAdmins(playerid) < ADMINS_HIGH)
		return SendUnauthMessage(playerid);
	
	if(isnull(params))
		return SendUsageMessage(playerid, "/backup [players, all]"); 
		
	new 
		str[128];
		
	if(!strcmp(params, "players"))
	{
		foreach(new i : Player)
		{
			if(!PlayerInfo[playerid][E_CHARACTER_DBID])
				continue;
				
			SaveCharacter(i); 
		}
		
		format(str, sizeof(str), "%s backed up player data. (%i)", ReturnSettingsName(playerid, playerid), GetPlayerPoolSize());
		SendAdminMessage(1, str); 
	}
	else if(!strcmp(params, "all"))
	{
		SaveFactions();
		SaveProperties();
		SaveBusinesses();
		
		SendClientMessageToAllEx(COLOR_RED, "Admin %s backed up server data.", ReturnSettingsName(playerid, playerid));
	}
	else return SendErrorMessage(playerid, "Invalid Paramater.");	
	return 1;
}

CMD:repair(playerid, params[])
{
	if(IsPlayerAdmins(playerid) < ADMINS_HIGH)
		return SendUnauthMessage(playerid);
		
	new 
		str[128],
		vehicleid,
		Float:angle
	;
	
	if(sscanf(params, "i", vehicleid))
		return SendUsageMessage(playerid, "/repair [vehicle id]"); 
		
	if(!IsValidVehicle(vehicleid))
		return SendErrorMessage(playerid, "You specified an invalid vehicle."); 
		
	format(str, sizeof(str), "%s repaired vehicle ID %i.", ReturnSettingsName(playerid, playerid), vehicleid);
	SendAdminMessage(1, str);
	
	RepairVehicle(vehicleid);
	SetVehicleHealthEx(vehicleid, 900); 
	
	GetVehicleZAngle(vehicleid, angle);
	SetVehicleZAngle(vehicleid, angle);
	return 1; 
}

//Level 3 Admin commands:
CMD:spawncar(playerid, params[])
{
	if(IsPlayerAdmins(playerid) < ADMINS_OPERATOR)
		return 0;
		
	new modelid, color1, color2, siren, str[128], vehicleid = GetPlayerVehicleID(playerid); 
	
	if(sscanf(params, "iiiI(0)", modelid, color1, color2, siren))
	{
		SendUsageMessage(playerid, "/spawncar [model id] [color1] [color2] [siren default 0]");
		SendInfoMessage(playerid, "These vehicles are temporary. Siren allows you to turn sirens on using horn."); 
		return 1;
	}
	
	if(gettime() - lastVehicleSpawn[playerid] < 5)
		return SendInfoMessage(playerid, "You need to wait before spawning another vehicle.");
	
	if(modelid < 400 || modelid > 611)
		return SendErrorMessage(playerid, "You specified an invalid model.");
		
	if(color1 < 0 || color2 < 0 || color1 > 255 || color2 > 255)
		return SendErrorMessage(playerid, "A color you specified was invalid."); 
		
	GetPlayerPos(playerid, PlayerInfo[playerid][E_CHARACTER_LASTPOS][0], PlayerInfo[playerid][E_CHARACTER_LASTPOS][1], PlayerInfo[playerid][E_CHARACTER_LASTPOS][2]);
	
	
	VehicleInfo[vehicleid][E_VEHICLE_ADMINVEH] = CreateVehicle(modelid, PlayerInfo[playerid][E_CHARACTER_LASTPOS][0], PlayerInfo[playerid][E_CHARACTER_LASTPOS][1], PlayerInfo[playerid][E_CHARACTER_LASTPOS][2], 0, color1, color2, -1, siren);
	
	if(VehicleInfo[vehicleid][E_VEHICLE_ADMINVEH] != INVALID_VEHICLE_ID)
	{
		VehicleInfo[VehicleInfo[vehicleid][E_VEHICLE_ADMINVEH]][E_VEHICLE_ADMIN] = true;
		VehicleInfo[VehicleInfo[vehicleid][E_VEHICLE_ADMINVEH]][E_VEHICLE_MODEL] = modelid;
		
		VehicleInfo[VehicleInfo[vehicleid][E_VEHICLE_ADMINVEH]][E_VEHICLE_COLOR1] = color1;
		VehicleInfo[VehicleInfo[vehicleid][E_VEHICLE_ADMINVEH]][E_VEHICLE_COLOR2] = color2;
	}
	PlayerPutIntoVehicle(playerid, VehicleInfo[vehicleid][E_VEHICLE_ADMINVEH], 0);
	
	format(str, sizeof(str), "%s spawned a temporary %s.", ReturnSettingsName(playerid, playerid), ReturnVehicleName(VehicleInfo[vehicleid][E_VEHICLE_ADMINVEH]));
	SendAdminMessage(3, str);
	
	lastVehicleSpawn[playerid] = gettime();
	return 1;
}

CMD:despawncars(playerid, params[])
{
	if(IsPlayerAdmins(playerid) < ADMINS_OPERATOR)
		return 0;

	new vehicleCount, str[512];

	for(new i = 0; i != MAX_VEHICLES; ++i)
	{
 		if(VehicleInfo[i][E_VEHICLE_ADMIN])
		{
			DestroyVehicle(VehicleInfo[i][E_VEHICLE_ADMINVEH]);
			VehicleInfo[i][E_VEHICLE_ADMIN] = false;
			vehicleCount++;
		}
	}

	if(!vehicleCount) return SendErrorMessage(playerid, "No admin vehicles found.");

	format(str, sizeof(str), "%s destroyed %d admin temporary vehicles.", ReturnSettingsName(playerid, playerid), vehicleCount);
	SendAdminMessage(3, str);
	return 1;
}

CMD:despawncar(playerid, params[])
{
	if(IsPlayerAdmins(playerid) < ADMINS_OPERATOR)
		return 0;
		
	new vehicleid, str[128];
	
	if(sscanf(params, "d", vehicleid))
		return SendUsageMessage(playerid, "/despawncar [vehicleid]");
	
	if(!IsValidVehicle(vehicleid))
		return SendErrorMessage(playerid, "You specified an invalid vehicle.");
		
	if(VehicleInfo[vehicleid][E_VEHICLE_ADMIN] == false)
		return SendErrorMessage(playerid, "You can't despawn a private / faction vehicle."); 
	
	format(str, sizeof(str), "%s despawned %s (%d).", ReturnSettingsName(playerid, playerid), ReturnVehicleName(vehicleid), vehicleid);
	SendAdminMessage(3, str);
		
	ResetVehicleVars(vehicleid); DestroyVehicle(vehicleid);
	return 1;
}

CMD:createpcar(playerid, params[])
{
	if(IsPlayerAdmins(playerid) < ADMINS_OPERATOR)
		return SendUnauthMessage(playerid);
		
	new playerb, modelid, color1, color2;
	
	if(sscanf(params, "uiii", playerb, modelid, color1, color2))
	{
		SendUsageMessage(playerid, "/createpcar [playerid OR name] [model id] [color1] [color2]");
		SendTipMessage(playerid, "This issues a permanent vehicle to a player.");
		return 1;
	}
	
	if (!IsPlayerConnected(playerb))
		return SendErrorMessage(playerid, "A player you specified isn't connected to the server."); 
		
	if (AccountInfo[playerb][E_MASTERS_LOGGED] == false)
		return SendErrorMessage(playerid, "A player you specified isn't logged in."); 
	
	if(modelid < 400 || modelid > 611)
		return SendErrorMessage(playerid, "You specified an invalid model.");
		
	if(color1 < 0 || color2 < 0 || color1 > 255 || color2 > 255)
		return SendErrorMessage(playerid, "A color you specified was invalid."); 
		
	for(new i = 1; i < MAX_PLAYER_VEHICLES; i++)
	{
		if(!PlayerInfo[playerb][E_CHARACTER_OWNEDVEHICLE][i])
		{
			playerInsertID[playerb] = i;
			break;
		}
	}
	if(!playerInsertID[playerb])
	{
		SendErrorMessage(playerid, "%s doesn't have any free vehicle slots.", ReturnSettingsName(playerb, playerid));
	}
	else
	{
		new insertQuery[256];
		
		mysql_format(ourConnection, insertQuery, sizeof(insertQuery), "INSERT INTO vehicles (`VehicleOwnerDBID`, `VehicleModel`, `VehicleColor1`, `VehicleColor2`, `VehicleParkPosX`, `VehicleParkPosY`, `VehicleParkPosZ`, `VehicleParkPosA`) VALUES(%i, %i, %i, %i, 1705.4175, -1485.9148, 13.3828, 87.5097)",
			PlayerInfo[playerb][E_CHARACTER_DBID], modelid, color1, color2);
		mysql_pquery(ourConnection, insertQuery, "Query_AddPlayerVehicle", "ii", playerid, playerb); 
	}
	
	return 1;
}

CMD:setstats(playerid, params[])
{
	if(IsPlayerAdmins(playerid) < ADMINS_OPERATOR)
		return SendUnauthMessage(playerid);
		
	new 
		playerb, 
		statid, 
		value,
		str[128]
	;
	
	if(sscanf(params, "uiI(-1)", playerb, statid, value))
	{
		SendUsageMessage(playerid, "/setstats [playerid OR name] [stat code] [value]"); 
		SendClientMessage(playerid, COLOR_WHITE, "1. Faction Rank, 2. Radio, 3. Bank Money, 4. Level,");
		SendClientMessage(playerid, COLOR_WHITE, "5. Paycheck, 6. Jobs, 7. Hoodrats");
		return 1;
	}
	
	if(!IsPlayerConnected(playerb))
		return SendErrorMessage(playerid, "The player you specified isn't connected.");
		
	if(AccountInfo[playerid][E_MASTERS_LOGGED] == false)
		return SendErrorMessage(playerid, "The player you specified isn't logged in."); 
	
	switch(statid)
	{
		case 1: 
		{
			if(value == -1)
				return SendUsageMessage(playerid, "/setstats [playerid OR name] 1 [value required]"); 
		
			if(value < 1 && value != -1 || value > 20)
				return SendErrorMessage(playerid, "You specified an invalid rank. (1-20)");
				
			PlayerInfo[playerb][E_CHARACTER_FACTIONRANK] = value;
			SaveCharacter(playerb); 
			
			format(str, sizeof(str), "%s set %s's faction rank to %i.", ReturnSettingsName(playerid, playerid), ReturnSettingsName(playerb, playerid), value); 
			SendAdminMessage(3, str); 
		}
		case 2:
		{
			if(!PlayerInfo[playerb][E_CHARACTER_HASRADIO])
				PlayerInfo[playerb][E_CHARACTER_HASRADIO] = true;
				
			else PlayerInfo[playerb][E_CHARACTER_HASRADIO] = false;
			
			format(str, sizeof(str), "%s %s %s's Radio.", ReturnSettingsName(playerid, playerid), (PlayerInfo[playerb][E_CHARACTER_HASRADIO] != true) ? ("took") : ("set"), ReturnSettingsName(playerb, playerid));
			SendAdminMessage(3, str);
		}
		case 3:
		{
			if(value == -1)
				return SendUsageMessage(playerid, "/setstats [playerid OR name] 3 [value required]"); 
		
			format(str, sizeof(str), "%s set %s's bank money: $%s (Previously $%s)", ReturnSettingsName(playerid, playerid), ReturnSettingsName(playerb, playerid), FormatMoney(value), FormatMoney(PlayerInfo[playerb][E_CHARACTER_BANK])); 
			SendAdminMessage(3, str);
			
			PlayerInfo[playerb][E_CHARACTER_BANK] = value;
			SaveCharacter(playerb);
		}
		case 4:
		{
			if(value == -1)
				return SendUsageMessage(playerid, "/setstats [playerid OR name] 4 [value required]"); 
		
			if(value < 1 && value != -1)
				return SendErrorMessage(playerid, "Player levels can't go below one.");

			format(str, sizeof(str), "%s set %s's level: %i (Previously %i)", ReturnSettingsName(playerid, playerid), ReturnSettingsName(playerb, playerid), value, PlayerInfo[playerb][E_CHARACTER_LEVEL]);
			SendAdminMessage(3, str); 
			
			PlayerInfo[playerb][E_CHARACTER_LEVEL] = value; SetPlayerScore(playerb, value);
			SaveCharacter(playerb);
		}
		case 5:
		{
			if(value == -1)
				return SendUsageMessage(playerid, "/setstats [playerid OR name] 7 [value required]");
				
			format(str, sizeof(str), "%s set %s's paycheck: %i (Previously %i)", ReturnSettingsName(playerid, playerid), ReturnSettingsName(playerb, playerid), value, PlayerInfo[playerb][E_CHARACTER_PAYCHECK]);
			SendAdminMessage(3, str);
			
			PlayerInfo[playerb][E_CHARACTER_PAYCHECK] = value; 
			SaveCharacter(playerb);
		}
		case 6:
		{
			if(value == -1)
				return SendUsageMessage(playerid, "/setstats [playerid OR name] 9 [value required]");
				
			format(str, sizeof(str), "%s set %s's jobs: %s (Previously %s)", ReturnSettingsName(playerid, playerid), ReturnSettingsName(playerb, playerid), ReturnJobName(value), ReturnJobName(PlayerInfo[playerb][E_CHARACTER_JOBS]));
			SendAdminMessage(3, str);
			
			PlayerInfo[playerb][E_CHARACTER_JOBS] = value;
			SaveCharacter(playerid);
		}
		case 7:
		{
			if(value == -1)
				return SendUsageMessage(playerid, "/setstats [playerid OR name] 9 [value required]");
				
			format(str, sizeof(str), "%s set %s's hoodrat's: %i (Previously %d)", ReturnSettingsName(playerid, playerid), ReturnSettingsName(playerb, playerid), value, ReturnFactionName(playerid));
			SendAdminMessage(3, str);
			
			PlayerInfo[playerb][E_CHARACTER_FACTION] = 0;
			PlayerInfo[playerb][E_CHARACTER_FACTIONRANK] = 0; 
		}
	}
	return 1;
}

CMD:givemoney(playerid, params[])
{
	if(IsPlayerAdmins(playerid) < ADMINS_OPERATOR)
		return SendUnauthMessage(playerid);
		
	new playerb, value, str[128];
	
	if(sscanf(params, "ui", playerb, value))
		return SendUsageMessage(playerid, "/givemoney [playerid OR name] [amount]");
		
	if(!IsPlayerConnected(playerb))
		return SendErrorMessage(playerid, "The player you specified isn't connected.");
		
	if(AccountInfo[playerid][E_MASTERS_LOGGED] == false)
		return SendErrorMessage(playerid, "The player you specified isn't logged in."); 
		
	GiveMoney(playerb, value);
	SendInfoMessage(playerb, "You received $%s from Admin %s.", FormatMoney(value), ReturnSettingsName(playerid, playerid));

	format(str, sizeof(str), "%s gave $%s to %s", ReturnSettingsName(playerid, playerid), FormatMoney(value), ReturnSettingsName(playerb, playerid));
	SendAdminMessage(3, str);
	return 1;
}

CMD:setcar(playerid, params[])
{
	new	vehicleid, a_str[60], b_str[60];
	new str[128], value, Float: value2; 
	
	if(IsPlayerAdmins(playerid) < ADMINS_OPERATOR)
		return SendUnauthMessage(playerid);
		
	if(sscanf(params, "is[60]S()[60]", vehicleid, a_str, b_str))
	{
		SendUsageMessage(playerid, "/setcar [vehicleid] [params]");
		SendClientMessage(playerid, COLOR_WHITE, "timesdestroyed, color1, color2, paintjob, plates");

		return 1;
	}
	
	if(!IsValidVehicle(vehicleid))
		return SendErrorMessage(playerid, "You specified an invalid vehicle ID."); 
		
	if(VehicleInfo[vehicleid][E_VEHICLE_ADMIN])
		return SendErrorMessage(playerid, "The vehicle you specified is admin spawned.");
		
	
	if(!strcmp(a_str, "timesdestroyed"))
	{
		if(sscanf(b_str, "i", value))
			return SendUsageMessage(playerid, "/setcar vehicleid timesdestroyed [value]");
			
		format(str, sizeof(str), "%s set vehicle ID %i's time destroyed to %i. (Previously %i)", ReturnSettingsName(playerid, playerid), vehicleid, value, VehicleInfo[vehicleid][E_VEHICLE_DESTROYED]); 
		SendAdminMessage(3, str); 
		
		VehicleInfo[vehicleid][E_VEHICLE_DESTROYED] = value; 
		SaveVehicle(vehicleid);
	}
	else if(!strcmp(a_str, "color1"))
	{
		if(sscanf(b_str, "i", value))
			return SendUsageMessage(playerid, "/setcar vehicleid color1 [value]");
			
		if(value > 255 || value < 0)
			return SendErrorMessage(playerid, "You specified an invalid color. (0-255)");
			
		format(str, sizeof(str), "%s set vehicle ID %i's color1 to %i. (Previously %i)", ReturnSettingsName(playerid, playerid), vehicleid, value, VehicleInfo[vehicleid][E_VEHICLE_COLOR1]);
		SendAdminMessage(3, str);
		
		SendClientMessage(playerid, COLOR_WHITE, "The vehicle needs to be respawned to take affect.");
		
		VehicleInfo[vehicleid][E_VEHICLE_COLOR1] = value;
		SaveVehicle(vehicleid);
	}
	else if(!strcmp(a_str, "color2"))
	{
		if(sscanf(b_str, "i", value))
			return SendUsageMessage(playerid, "/setcar vehicleid color2 [value]");
			
		if(value > 255 || value < 0)
			return SendErrorMessage(playerid, "You specified an invalid color. (0-255)");
			
		format(str, sizeof(str), "%s set vehicle ID %i's color2 to %i. (Previously %i)", ReturnSettingsName(playerid, playerid), vehicleid, value, VehicleInfo[vehicleid][E_VEHICLE_COLOR2]);
		SendAdminMessage(3, str);
		
		SendClientMessage(playerid, COLOR_WHITE, "The vehicle needs to be respawned to take affect.");
		
		VehicleInfo[vehicleid][E_VEHICLE_COLOR2] = value;
		SaveVehicle(vehicleid);
	}
	else if(!strcmp(a_str, "paintjob"))
	{
		if(sscanf(b_str, "i", value))
			return SendUsageMessage(playerid, "/setcar vehicleid paintjob [0-2, 3 to remove]");
			
		if(value > 3 || value < 0)
			return SendErrorMessage(playerid, "You specified an invalid color. (0-255)");
			
		format(str, sizeof(str), "%s set vehicle ID %i's paintjob to %i. (Previously %i)", ReturnSettingsName(playerid, playerid), vehicleid, value, VehicleInfo[vehicleid][E_VEHICLE_PAINTJOB]);
		SendAdminMessage(3, str);
		
		SendClientMessage(playerid, COLOR_WHITE, "The vehicle needs to be respawned to take affect.");
		
		VehicleInfo[vehicleid][E_VEHICLE_PAINTJOB] = value;
		SaveVehicle(vehicleid);
	}
	else if(!strcmp(a_str, "plates"))
	{
		new
			plates[32]; 
			
		if(sscanf(b_str, "s[32]", plates))
			return SendUsageMessage(playerid, "/setcar vehicleid plates [plates]"); 
			
		if(strlen(plates) > 6 || strlen(plates) < 6)
			return SendErrorMessage(playerid, "You need to provide a 6 digit plate. (California license plate: Q123Q1)");
			
		format(str, sizeof(str), "%s set vehicle ID %i's plates to \"%s\". (Previously %s)", ReturnSettingsName(playerid, playerid), vehicleid, plates, VehicleInfo[vehicleid][E_VEHICLE_PLATES]);
		SendAdminMessage(3, str);
		
		format(VehicleInfo[vehicleid][E_VEHICLE_PLATES], 32, "%s", plates); 
		SaveVehicle(vehicleid);
	}
	else if(!strcmp(a_str, "fuel"))
	{
		if(sscanf(b_str, "f", value2))
			return SendUsageMessage(playerid, "/setcar vehicleid fuel [value ex: 50.0]");
			
		if(value2 > 100.0 || value2 < 0.0)
			return SendErrorMessage(playerid, "You specified an invalid color. (0-255)");
			
		format(str, sizeof(str), "%s set vehicle ID %i's fuel to %i. (Previously %i)", ReturnSettingsName(playerid, playerid), vehicleid, value2, VehicleInfo[vehicleid][E_VEHICLE_FUEL]);
		SendAdminMessage(3, str);
		
		VehicleInfo[vehicleid][E_VEHICLE_FUEL] = value;
		SaveVehicle(vehicleid);
	}
	return 1;
}

CMD:setcarparams(playerid, params[])
{
	if(IsPlayerAdmins(playerid) < ADMINS_OPERATOR)
		return SendUnauthMessage(playerid);
	
	new vehicleid, a_str[60], b_str[60]; 
	new str[128];
	
	if(sscanf(params, "is[60]S()[60]", vehicleid, a_str, b_str))
	{
		SendUsageMessage(playerid, "/setcarparams [vehicleid] [params]");
		SendClientMessage(playerid, COLOR_RED, "[!]{ffffff} engine, lights, lock, health"); 
		return 1;
	}
		
	if(!IsValidVehicle(vehicleid))
		return SendErrorMessage(playerid, "You specified an invalid vehicleid."); 
		
	if(!strcmp(a_str, "engine"))
	{
		if(!VehicleInfo[vehicleid][E_VEHICLE_ENGINE])
		{
			ToggleVehicleEngine(vehicleid, true); VehicleInfo[vehicleid][E_VEHICLE_ENGINE] = true;
			format(str, sizeof(str), "%s turned vehicle ID %i's engine on.", ReturnSettingsName(playerid, playerid), vehicleid);
		}
		else
		{
			ToggleVehicleEngine(vehicleid, false); VehicleInfo[vehicleid][E_VEHICLE_ENGINE] = false;
			format(str, sizeof(str), "%s turned vehicle ID %i's engine off.", ReturnSettingsName(playerid, playerid), vehicleid);
		}
		
		SendAdminMessage(3, str); 
	}
	else if(!strcmp(a_str, "lights"))
	{
		if(VehicleInfo[vehicleid][E_VEHICLE_LIGHTS] == false)
			ToggleVehicleLights(vehicleid, true);
			
		else ToggleVehicleLights(vehicleid, false);
		
		format(str, sizeof(str), "%s turned vehicle ID %i's lights %s.", ReturnSettingsName(playerid, playerid), vehicleid, (VehicleInfo[vehicleid][E_VEHICLE_LIGHTS] != true) ? ("off") : ("on"));
		SendAdminMessage(3, str);
	}
	else if(!strcmp(a_str, "lock"))
	{
		new engine, lights, alarm, doors, bonnet, boot, objective; 
	
		GetVehicleParamsEx(vehicleid, engine, lights, alarm, doors, bonnet, boot, objective);
			
		if(VehicleInfo[vehicleid][E_VEHICLE_LOCKED])
		{
			SetVehicleParamsEx(vehicleid, engine, lights, alarm, false, bonnet, boot, objective);
			VehicleInfo[vehicleid][E_VEHICLE_LOCKED] = false;
		}
		else 
		{
			SetVehicleParamsEx(vehicleid, engine, lights, alarm, true, bonnet, boot, objective);
			VehicleInfo[vehicleid][E_VEHICLE_LOCKED] = true;
		}
		
		format(str, sizeof(str), "%s %s vehicle ID %i.", ReturnSettingsName(playerid, playerid), (VehicleInfo[vehicleid][E_VEHICLE_LOCKED] != false) ? ("locked") : ("unlocked")); 
		SendAdminMessage(3, str);
	}
	else if(!strcmp(a_str, "health"))
	{
		new Float:health;
		
		if(sscanf(b_str, "f", health))
			return SendUsageMessage(playerid, "/setcar vehicleid health [value]");
			
		SetVehicleHealthEx(vehicleid, health); 
		
		format(str, sizeof(str), "%s set vehicle ID %i's health to %.2f.", ReturnSettingsName(playerid, playerid), vehicleid, health);
		SendAdminMessage(3, str);
	}

	return 1;
}

//Level 4 Admin commands:

CMD:gotomark(playerid, params[])
{
	if(IsPlayerAdmins(playerid) < ADMINS_OWNER)
		return 0;		
    new
        str[1536];

	str[0] = '\0';

	for (new i = 0; i < sizeof(g_arrInteriorData); i ++)
	{
	    strcat(str, g_arrInteriorData[i][E_INT_NAME]);
	    strcat(str, "\n");
    }
   	ShowPlayerDialog(playerid, DIALOG_INTERIOR, DIALOG_STYLE_LIST, "Teleport:", str, "Select", "Cancel");
    return 1;
}

CMD:createfaction(playerid, params[])
{
	if(IsPlayerAdmins(playerid) < ADMINS_OWNER)
		return 0;
		
	new varAbbrev[32], varName[128]; 
	
	if(sscanf(params, "s[30]s[90]", varAbbrev, varName))
	{
		SendUsageMessage(playerid, "/createfaction [faction abbreviation] [faction name]");
		SendClientMessage(playerid, COLOR_RED, "[!]{ffffff} Do not use spaces for the abbreviation.");
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
		return SendInfoMessage(playerid, "The server has met the maximum amount of factions."); 
	}

	SendInfoMessage(playerid, "Creating the faction..."); 	
	
	new thread[256]; 
	
	mysql_format(ourConnection, thread, sizeof(thread), "INSERT INTO factions (`FactionName`, `FactionAbbrev`) VALUES('%s', '%s')", varName, varAbbrev);
	mysql_pquery(ourConnection, thread, "Query_InsertFaction", "issi", playerid, varName, varAbbrev, idx);
	
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
		SendClientMessage(playerid, COLOR_WHITE, "type, color, spawn"); 
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
		
		SendInfoMessage(playerid, "You set faction %d's type to %s.", factionid, typeName);
		SaveFaction(factionid);
	}
	else if(!strcmp(oneString, "color"))
	{
		new hexcolor; 
		
		if(sscanf(secString, "x", hexcolor))
		{
			SendUsageMessage(playerid, "/editfaction factionid color [hexcode]");
			SendInfoMessage(playerid, "This is the color faction chat is shown in. Example: 0x8D8DFFFF"); 
			return 1;
		}
		
		FactionInfo[factionid][E_FACTION_COLORHEX] = hexcolor;
		SendInfoMessage(playerid, "You set faction %d's chat color to \"%x\". ", factionid, hexcolor);
		
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
		
		SendInfoMessage(playerid, "You changed faction %d's spawn point.", factionid); 

		if(IsValidDynamicPickup(FactionInfo[factionid][E_FACTION_SPAWNPICKUP]))
			DestroyDynamicPickup(FactionInfo[factionid][E_FACTION_SPAWNPICKUP]); 
		if(IsValidDynamic3DTextLabel(FactionInfo[factionid][E_FACTION_SPAWNTEXT]))
			DestroyDynamic3DTextLabel(FactionInfo[factionid][E_FACTION_SPAWNTEXT]);

		FactionInfo[factionid][E_FACTION_SPAWNPICKUP] = CreateDynamicPickup(1239, 1, FactionInfo[factionid][E_FACTION_SPAWN][0], FactionInfo[factionid][E_FACTION_SPAWN][1], FactionInfo[factionid][E_FACTION_SPAWN][2], FactionInfo[factionid][E_FACTION_SPAWNWORLD], FactionInfo[factionid][E_FACTION_SPAWNINT]);
		FactionInfo[factionid][E_FACTION_SPAWNTEXT] = CreateDynamic3DTextLabel("Faction Spawn Point\n{ffffff}Available Commands: Use /factionhelp to see faction commands", COLOR_POINT, FactionInfo[factionid][E_FACTION_SPAWN][0], FactionInfo[factionid][E_FACTION_SPAWN][1], FactionInfo[factionid][E_FACTION_SPAWN][2], 5.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, FactionInfo[factionid][E_FACTION_SPAWNWORLD], FactionInfo[factionid][E_FACTION_SPAWNINT]);

		SaveFaction(factionid);
	}
	else return SendErrorMessage(playerid, "Invalid Parameter.");
	return 1;
}

CMD:setpadmin(playerid, params[])
{
	if(IsPlayerAdmins(playerid) < ADMINS_OWNER)
		return SendUnauthMessage(playerid);
		
	new playerb, adminid, str[128];
	
	if(sscanf(params, "ud", playerb, adminid))
		return SendUsageMessage(playerid, "/setpadmin [playerid OR name] [admin id]");
		
	if(!IsPlayerConnected(playerb))
		return SendErrorMessage(playerid, "The player you specified isn't connected.");
		
	if(AccountInfo[playerb][E_MASTERS_LOGGED] == false)
		return SendErrorMessage(playerid, "The player you specified isn't logged in."); 

	if(adminid > 4)
		return SendErrorMessage(playerid, "Invalid admin level.");

	PlayerInfo[playerb][E_CHARACTER_ADMIN] = adminid;
	
	SaveCharacter(playerb);
		
	format(str, sizeof(str), "%s set %s's admin to %d.", ReturnSettingsName(playerid, playerid), ReturnSettingsName(playerb, playerid), adminid);
	SendAdminMessage(4, str);
	
	SendInfoMessage(playerb, "You were set to admin %d by Admin %s.", adminid, ReturnSettingsName(playerid, playerid));
	
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
		
		format(detailStr, sizeof(detailStr), "{FFFFFF}%s is already in a faction. Would you like to continue?", ReturnSettingsName(playerb, playerid));
		ConfirmDialog(playerid, "Confirmation", detailStr, "OnSetFaction", playerb, factionid);
		return 1;
	}
	

	PlayerInfo[playerb][E_CHARACTER_FACTION] = factionid;
	PlayerInfo[playerb][E_CHARACTER_FACTIONRANK] = 4; 
	
	SaveCharacter(playerb);
		
	format(str, sizeof(str), "%s set %s's faction to %d.", ReturnSettingsName(playerid, playerid), ReturnSettingsName(playerb, playerid), factionid);
	SendAdminMessage(4, str);
	
	SendInfoMessage(playerb, "You were set to faction %d by Admin %s.", factionid, ReturnSettingsName(playerid, playerid));
	
	return 1;
}

CMD:afklist(playerid, params[])
{
	if(IsPlayerAdmins(playerid) < ADMINS_HIGH)
	    return 0;

	SendClientMessage(playerid, COLOR_GREY, "AFK List:");

	foreach(new i : Player)
	{
	    if(PlayerInfo[i][E_CHARACTER_AFK])
	    {
	        SendClientMessageEx(playerid, COLOR_DARKGREEN, "(ID: %i) %s - Time: %i seconds", i, ReturnSettingsName(i, i), PlayerInfo[i][E_CHARACTER_AFKTIME]);
		}
	}

	return 1;
}
