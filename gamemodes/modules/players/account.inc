function:LoginTimer(playerid, rcc)
{
	if(rcc != g_RaceCheck{playerid})
	    return Kick(playerid);

	cameraIndex[playerid] = 0;
	InterpolateCameraPos(playerid, 2467.694091, -1680.678100, 22.207088, 2470.404296, -1640.607177, 23.310541, 15000, 1);
	InterpolateCameraLookAt(playerid, 2471.343017, -1681.534667, 20.810289, 2472.477294, -1643.914062, 22.434955, 15000, 1);
	cameraTimer[playerid] = SetTimerEx("SetPlayerCamera", 10000, true, "i", playerid);

	new existCheck[256]; 
	mysql_format(ourConnection, existCheck, sizeof(existCheck), "SELECT * FROM bannedlist WHERE IpAddress = '%e'", ReturnIP(playerid));
	mysql_pquery(ourConnection, existCheck, "CheckBanList", "i", playerid);
	return 1;
}

function:CheckBanList(playerid)
{	
	if(!cache_num_rows())
	{
		new existCheck[512];
		for(new i = 0; i < 4; i ++) {PlayerTextDrawShow(playerid, LoginScreen[i][playerid]);}
		
		mysql_format(ourConnection, existCheck, sizeof(existCheck), "SELECT acc_dbid, secret_word, verified FROM masters WHERE acc_name = '%e'", ReturnName(playerid, 1));
		mysql_pquery(ourConnection, existCheck, "LogPlayerIn", "i", playerid);
	}
	else
	{
		new banDate[90], banner[32];
		
		cache_get_value_name(0, "Date", banDate, 90);
		cache_get_value_name(0, "BannedBy", banner, 32);
	
		SendServerMessage(playerid, "[Banned] {a4a4a4}Your IP %s is banned from our servers.", ReturnIP(playerid));
		SendServerMessage(playerid, "[Banned] {a4a4a4}Your account %s is banned from our server.", ReturnName(playerid));
		SendServerMessage(playerid, "[Banned] {a4a4a4}You were banned on %s by %s.", banDate, banner); 
		SendServerMessage(playerid, "[Banned] {a4a4a4}You may appeal your ban on our forums."); 
		return KickEx(playerid);
	}
	return 1;
}

function:LogPlayerIn(playerid)
{		
	if(cache_num_rows())
	{
		loginTime[playerid] = 1; 
		for(new i = 0; i < 20; i ++) { SendClientMessage(playerid, -1, " "); }
		
		new str[1024];
		format(str, sizeof(str), "You are registered user! Plase log in!", ReturnName(playerid));
		Dialog_Show(playerid, Login, DIALOG_STYLE_PASSWORD, "Log in to your account:", str, "Confirm", "");
	}
	else
	{
		for(new i = 0; i < 20; i ++) { SendClientMessage(playerid, -1, " "); }	
		registerTime[playerid] = 1;	
		Dialog_Show(playerid, DIALOG_DEFAULT, DIALOG_STYLE_MSGBOX, "Connection:", "Your account was not registered, Please registration in official discord Storylines.", "Close", "");
	}
	return 1;
}

function:OnPlayerRegister(playerid)
{
	AccountInfo[playerid][E_MASTERS_DBID] = cache_insert_id(); 
	format(AccountInfo[playerid][E_MASTERS_ACCNAME], 32, "%s", ReturnName(playerid, 1)); 
	
	registerTime[playerid] = 0;
	loginTime[playerid] = 1; 
	
	new str[1024];
	format(str, sizeof(str), "You are registered user! Plase log in!", ReturnName(playerid));
	SendInfoMessage(playerid, "You successfully registered as %s. You need to login to continue:", ReturnName(playerid)); 
	return Dialog_Show(playerid, Login, DIALOG_STYLE_PASSWORD, "Login:", str, "Confirm", "");
}

function:LoggingIn(playerid)
{
	if (!IsPlayerConnected(playerid))
	    return 0;

	if(!cache_num_rows())
	{
		playerLogin[playerid]++;
		if(playerLogin[playerid] == 3)
		{
			SendErrorMessage(playerid, "You were kicked for bad password attempts.");
			return KickEx(playerid);
		}
		
		new str[1024];
		format(str, sizeof(str), "You are registered user! Plase log in!", ReturnName(playerid));
		return Dialog_Show(playerid, Login, DIALOG_STYLE_PASSWORD, "Log in to your account:", str, "Confirm", "");
	}
	
	new rows, fields, fetchChars[128];
	cache_get_row_count(rows);
	cache_get_field_count(fields);
	
	new ActiveIP[60];
	
	cache_get_value_name_int(0, "acc_dbid", AccountInfo[playerid][E_MASTERS_DBID]); 
	cache_get_value_name(0, "forum_name", AccountInfo[playerid][E_MASTERS_FORUMNAME], 60);

	cache_get_value_name_int(0, "secret_word", AccountInfo[playerid][E_MASTERS_CODE]);
	cache_get_value_name(0, "active_ip", ActiveIP);
	
	format(AccountInfo[playerid][E_MASTERS_ACCNAME], 32, "%s", ReturnName(playerid, 1));

	if (AccountInfo[playerid][E_MASTERS_LOGGED] == false)
	{
		AccountInfo[playerid][E_MASTERS_LOGGED] = true;
	}
	KillTimer(cameraTimer[playerid]);
	SetCameraBehindPlayer(playerid); 

	mysql_format(ourConnection, fetchChars, sizeof(fetchChars), "SELECT * FROM bannedlist WHERE MasterDBID = %d", AccountInfo[playerid][E_MASTERS_DBID]);
	mysql_pquery(ourConnection, fetchChars, "Query_CheckBannedAccount", "i", playerid); 
	return 1;
}

function:Query_CheckBannedAccount(playerid)
{
	new rows, fields;
	cache_get_row_count(rows);
	cache_get_field_count(fields);

	if(!cache_num_rows())
	{
		loginTime[playerid] = 0; 
		characterPickTime[playerid] = 1;
		
		new fetchChars[512];
	
		mysql_format(ourConnection, fetchChars, sizeof(fetchChars), "SELECT * FROM characters WHERE `master_dbid` = '%d' LIMIT 4", AccountInfo[playerid][E_MASTERS_DBID]);
		mysql_pquery(ourConnection, fetchChars, "DB_ListCharacters", "i", playerid);
	}
	else
	{	
		new banDate[90], banner[32];
		
		cache_get_value_name(0, "Date", banDate, 90);
		cache_get_value_name(0, "BannedBy", banner, 32);
	
		SendServerMessage(playerid, "[Banned] {a4a4a4}Your account %s is banned from our server.", ReturnName(playerid));
		SendServerMessage(playerid, "[Banned] {a4a4a4}You were banned on %s by %s.", banDate, banner); 
		return KickEx(playerid);
	}
	return 1;
}

function:DB_ListCharacters(playerid)
{
	new rows;
	cache_get_row_count(rows);
	
	new vwid = AccountInfo[playerid][E_MASTERS_DBID];
	SetPlayerVirtualWorld(playerid, vwid);
	SetPlayerInterior(playerid, 11);

	if(!rows)
	{
		SendInfoMessage(playerid, "You don't have any existing characters.");
		
		PlayerTextDrawSetString(playerid, SelectFactionName[playerid], "Hoodrats");
		PlayerTextDrawSetString(playerid, SelectFactionLocation[playerid], "Empty_Characters");
		PlayerTextDrawColor(playerid,SelectFactionName[playerid], COLOR_WHITE);
	}

	for (new i = 0; i < 4; i ++)
	{
		characterLister[playerid][i][0] = EOS;
	}

	for (new i = 0; i < cache_num_rows(); i ++)
	{
		cache_get_value_name(i, "char_name", characterLister[playerid][i], 128); 
		cache_get_value_name_int(i, "pLastSkin", characterSkin[playerid][i]);
		cache_get_value_name_int(i, "pFaction", characterFaction[playerid][i]);
	}

	CreatePlayerActor(playerid, characterSkin[playerid][0]);
	ShowCharacterSelection(playerid);
	
	KillTimer(cameraTimer[playerid]);
	return 1;
}

function:Query_SelectCharacter(playerid)
{
	new rows, fields, thread[512]; 
	cache_get_row_count(rows);
	cache_get_field_count(fields);

	if (!rows)
	{
		SendErrorMessage(playerid, "An error occurred processing your character. Returning you to your character list...");
			
		return ShowCharacterSelection(playerid);
	}
	
	if(rows)
	{
		mysql_format(ourConnection, thread, sizeof(thread), "SELECT * FROM characters WHERE char_name = '%e'", ReturnName(playerid, 1));
		mysql_pquery(ourConnection, thread, "Query_LoadCharacter", "i", playerid);
	}
	return 1;
}

stock LoadCharacter(playerid)
{
	SetPlayerScore(playerid, PlayerInfo[playerid][E_CHARACTER_LEVEL]);

	if(PlayerInfo[playerid][E_CHARACTER_INJURED] == 1)
	{
		SetPlayerTeam(playerid, PLAYER_STATE_WOUNDED);
	}
	else if(PlayerInfo[playerid][E_CHARACTER_DEATH] == 1)
	{
		SetPlayerTeam(playerid, PLAYER_STATE_DEAD);
	}
	else
	{
		SetPlayerTeam(playerid, PLAYER_STATE_ALIVE);
	}

	SetPlayerHealthEx(playerid, PlayerInfo[playerid][E_CHARACTER_HEALTH]);
	SetPlayerArmourEx(playerid, PlayerInfo[playerid][E_CHARACTER_ARMOUR]);

	PauseAC(playerid);

	StopAudioStreamForPlayer(playerid);

	ResetPlayerMoney(playerid); 
	GivePlayerMoney(playerid, PlayerInfo[playerid][E_CHARACTER_MONEY]);

	new stri[256];
	format(stri, sizeof stri, ".:. %s has joined the GTA Storylines (joined)", AccountInfo[playerid][E_MASTERS_ACCNAME]);
	if(PlayerInfo[playerid][E_CHARACTER_TOGJOIN] == false)
	{
		SendClientMessageToAll(COLOR_DARKGREEN, stri);
	}	

	for(new i = 0; i < 20; i ++) { SendClientMessage(playerid, -1, " "); }
	SendClientMessageEx(playerid, COLOR_WHITE, "Hey {9CC8E9}%s{ffffff}, Welcome back to {4cb989}GTA Storylines{ffffff}.", AccountInfo[playerid][E_MASTERS_ACCNAME]);
	SendClientMessageEx(playerid, COLOR_WHITE, "You are logged in as a {b7b94c}%s{ffffff}, playing as {9CC8E9}%s{ffffff}!", ReturnFactionName(playerid), ReturnName(playerid));
	SendClientMessageEx(playerid, COLOR_WHITE, "[Player MOTD]: {4cb989}%s", PLAYER_MOTD);
	SendClientMessage(playerid, -1, " ");
	SendClientMessage(playerid, COLOR_WHITE, "Visit us and register on our discord at {4ca5b9}discord.gg/storylines{ffffff} to stay updated.");

	if(PlayerInfo[playerid][E_CHARACTER_VEHICLESPAWNED] == true)
	{
		if(!IsValidVehicle(PlayerInfo[playerid][E_CHARACTER_VEHICLESPAWN]))
			PlayerInfo[playerid][E_CHARACTER_VEHICLESPAWNED] = false; 
			
		else
			SendInfoMessage(playerid, "Your vehicle is still spawned.");
	}
	
	SetCameraBehindPlayer(playerid);
	SetPlayerSkin(playerid, PlayerInfo[playerid][E_CHARACTER_LASTSKIN]);
	SetPlayerPosEx(playerid, PlayerInfo[playerid][E_CHARACTER_LASTPOS][0], PlayerInfo[playerid][E_CHARACTER_LASTPOS][1], PlayerInfo[playerid][E_CHARACTER_LASTPOS][2]);
	
	if(PlayerInfo[playerid][E_CHARACTER_OFFJAILED])
	{
		if(strlen(PlayerInfo[playerid][E_CHARACTER_OFFJAILREASON]) > 1)
		{
			SendClientMessageToAllEx(COLOR_RED, "AdmCmd: %s was admin jailed by SYSTEM for %d minutes, Reason: %.56s", ReturnName(playerid), PlayerInfo[playerid][E_CHARACTER_ADMINJAIL] / 60, PlayerInfo[playerid][E_CHARACTER_OFFJAILREASON]);
			SendClientMessageToAllEx(COLOR_RED, "AdmCmd: ...%s", PlayerInfo[playerid][E_CHARACTER_OFFJAILREASON][56]); 
		}
		else SendClientMessageToAllEx(COLOR_RED, "AdmCmd: %s was admin jailed by SYSTEM for %d minutes, Reason: %s", ReturnName(playerid), PlayerInfo[playerid][E_CHARACTER_ADMINJAIL] / 60, PlayerInfo[playerid][E_CHARACTER_OFFJAILREASON]);
		
		ClearAnimations(playerid);
		
		SetPlayerPosEx(playerid, 264.4271,78.0998,1001.0391);
		SetPlayerInterior(playerid, 0); SetPlayerVirtualWorld(playerid, 999);
		
		PlayerInfo[playerid][E_CHARACTER_OFFJAILED] = false; 
		PlayerInfo[playerid][E_CHARACTER_ADMINJAILED] = true; 
		SaveCharacter(playerid);
	}
	
	SetPlayerFightingStyle(playerid, PlayerInfo[playerid][E_CHARACTER_FIGHTSTYLE]);
	format(PlayerInfo[playerid][E_CHARACTER_ACTIVEIP], 60, "%s", ReturnIP(playerid)); 

	new str[1024];
    format(str, sizeof(str), "%s", PlayerInfo[playerid][E_CHARACTER_NAME]);
    SetPlayerName(playerid, str);

	KillTimer(cameraTimer[playerid]);
	SetCameraBehindPlayer(playerid); 

	TogglePlayerControllable(playerid, true);

	if(PlayerInfo[playerid][E_CHARACTER_AOE] == 0)
	{
		CreatePlayerToy(playerid);
	}
	LoadPlayerToys(playerid);
	
	return 1;
}

function:Query_LoadCharacter(playerid)
{
	cache_get_value_name_int(0, "char_dbid", PlayerInfo[playerid][E_CHARACTER_DBID]);
	cache_get_value_name(0, "char_name", PlayerInfo[playerid][E_CHARACTER_NAME], 32);
	cache_get_value_name(0, "char_masters", PlayerInfo[playerid][E_CHARACTER_STREETNAME], 32);
	cache_get_value_name_int(0, "pAdmin", PlayerInfo[playerid][E_CHARACTER_ADMIN]);
	cache_get_value_name_int(0, "pLastSkin", PlayerInfo[playerid][E_CHARACTER_LASTSKIN]);
	cache_get_value_name_int(0, "pGender", PlayerInfo[playerid][E_CHARACTER_GENDER]);
	cache_get_value_name_int(0, "pFacSkin", PlayerInfo[playerid][E_CHARACTER_FACSKIN]);
	cache_get_value_name_float(0, "pLastPosX", PlayerInfo[playerid][E_CHARACTER_LASTPOS][0]);
	cache_get_value_name_float(0, "pLastPosY", PlayerInfo[playerid][E_CHARACTER_LASTPOS][1]);
	cache_get_value_name_float(0, "pLastPosZ", PlayerInfo[playerid][E_CHARACTER_LASTPOS][2]);
	cache_get_value_name_int(0, "pLastInterior", PlayerInfo[playerid][E_CHARACTER_LASTINTERIOR]);
	cache_get_value_name_int(0, "pLastWorld", PlayerInfo[playerid][E_CHARACTER_LASTWORLD]);
	cache_get_value_name_int(0, "pLevel", PlayerInfo[playerid][E_CHARACTER_LEVEL]);
	cache_get_value_name(0, "pAge", PlayerInfo[playerid][E_CHARACTER_AGE], 20);
	cache_get_value_name(0, "pOrigin", PlayerInfo[playerid][E_CHARACTER_ORIGIN], 60);
	cache_get_value_name(0, "pStory", PlayerInfo[playerid][E_CHARACTER_STORY], 90);
	cache_get_value_name(0, "pStoryTwo", PlayerInfo[playerid][E_CHARACTER_STORYTWO], 90);
	cache_get_value_name_int(0, "pMoney", PlayerInfo[playerid][E_CHARACTER_MONEY]);
	cache_get_value_name_int(0, "pBank", PlayerInfo[playerid][E_CHARACTER_BANK]); 
	cache_get_value_name_int(0, "pPaycheck", PlayerInfo[playerid][E_CHARACTER_PAYCHECK]);
	cache_get_value_name_int(0, "pPhone", PlayerInfo[playerid][E_CHARACTER_PHONE]); 
	cache_get_value_name(0, "pLastOnline", PlayerInfo[playerid][E_CHARACTER_LASTONLINEDATE], 90);
	cache_get_value_name_int(0, "pLastOnlineTime", PlayerInfo[playerid][E_CHARACTER_LASTONLINE]); 
	cache_get_value_name_bool(0, "pAdminjailed", PlayerInfo[playerid][E_CHARACTER_ADMINJAILED]);
	cache_get_value_name_int(0, "pAdminJailTime", PlayerInfo[playerid][E_CHARACTER_ADMINJAIL]);
	cache_get_value_name_bool(0, "pOfflinejailed", PlayerInfo[playerid][E_CHARACTER_OFFJAILED]);
	cache_get_value_name(0, "pOfflinejailedReason", PlayerInfo[playerid][E_CHARACTER_OFFJAILREASON], 128);
	cache_get_value_name_int(0, "pFaction", PlayerInfo[playerid][E_CHARACTER_FACTION]);
	cache_get_value_name_int(0, "pFactionRank", PlayerInfo[playerid][E_CHARACTER_FACTIONRANK]);
	cache_get_value_name_int(0, "pFactionSubsets", PlayerInfo[playerid][E_CHARACTER_FACTIONSUBSETS]);
	cache_get_value_name_bool(0, "pVehicleSpawned", PlayerInfo[playerid][E_CHARACTER_VEHICLESPAWNED]);
	cache_get_value_name_int(0, "pVehicleSpawnedID", PlayerInfo[playerid][E_CHARACTER_VEHICLESPAWN]);
	cache_get_value_name_int(0, "pTimeplayed", PlayerInfo[playerid][E_CHARACTER_TIMEPLAYED]);
	cache_get_value_name_int(0, "pMaskID", PlayerInfo[playerid][E_CHARACTER_MASKID]);
	cache_get_value_name_int(0, "pInProperty", PlayerInfo[playerid][E_CHARACTER_INSIDEPROP]);
	cache_get_value_name_int(0, "pInBusiness", PlayerInfo[playerid][E_CHARACTER_INSIDEBIZ]);
	cache_get_value_name_int(0, "pInEntrance", PlayerInfo[playerid][E_CHARACTER_INSIDEENT]);
	cache_get_value_name_int(0, "pMainSlot", PlayerInfo[playerid][E_CHARACTER_MAINSLOT]);
	cache_get_value_name_int(0, "pRobberyCooldown", PlayerInfo[playerid][E_CHARACTER_ROBBERYCD]);
	cache_get_value_name_int(0, "pSpawnPoint", PlayerInfo[playerid][E_CHARACTER_SPAWNPOINT]);
	cache_get_value_name_int(0, "pWeaponsLicense", PlayerInfo[playerid][E_CHARACTER_WEAPLICENSE]);
	cache_get_value_name_int(0, "pDriversLicense", PlayerInfo[playerid][E_CHARACTER_DRIVELICENSE]); 
	cache_get_value_name_int(0, "pTruckerLicense", PlayerInfo[playerid][E_CHARACTER_TRUCKERLICENSE]); 
	cache_get_value_name_int(0, "pActiveListings", PlayerInfo[playerid][E_CHARACTER_ACTIVELIST]); 
	cache_get_value_name_bool(0, "pPrison", PlayerInfo[playerid][E_CHARACTER_PRISONED]);
	cache_get_value_name_int(0, "pPrisonTimes", PlayerInfo[playerid][E_CHARACTER_PRISON]); 
	cache_get_value_name_int(0, "pHasInjured", PlayerInfo[playerid][E_CHARACTER_INJURED]); 
	cache_get_value_name_int(0, "pHasDeath", PlayerInfo[playerid][E_CHARACTER_DEATH]); 
	cache_get_value_name_float(0, "pHealth", PlayerInfo[playerid][E_CHARACTER_HEALTH]); 
	cache_get_value_name_float(0, "pMaxHealth", PlayerInfo[playerid][E_CHARACTER_MAXHEALTH]); 
	cache_get_value_name_float(0, "pArmor", PlayerInfo[playerid][E_CHARACTER_ARMOUR]); 
	cache_get_value_name_int(0, "pFightstyle", PlayerInfo[playerid][E_CHARACTER_FIGHTSTYLE]); 
	cache_get_value_name_int(0, "pHasAoe", PlayerInfo[playerid][E_CHARACTER_AOE]); 
	cache_get_value_name_int(0, "pEXP", PlayerInfo[playerid][E_CHARACTER_EXP]); 
	cache_get_value_name_int(0, "pJobs", PlayerInfo[playerid][E_CHARACTER_JOBS]); 
	cache_get_value_name_int(0, "pJobsCD", PlayerInfo[playerid][E_CHARACTER_JOBSCD]); 
	cache_get_value_name_int(0, "pSweeperCD", PlayerInfo[playerid][E_CHARACTER_SWEEPERCD]); 
	cache_get_value_name_int(0, "pGarbageCD", PlayerInfo[playerid][E_CHARACTER_GARBAGECD]); 
	cache_get_value_name_int(0, "pBusdriverCD", PlayerInfo[playerid][E_CHARACTER_BUSDRIVERCD]); 
	cache_get_value_name_int(0, "pTutorial", PlayerInfo[playerid][E_CHARACTER_TUTORIAL]); 

	new str[128];
	
	for(new i = 1; i < 3; i++)
	{
		format(str, sizeof(str), "pRadio%i", i);
		cache_get_value_name_int(0, str, PlayerInfo[playerid][E_CHARACTER_RADIO][i]);
	}

	for(new i = 1; i < 8; i++)
	{
		format(str, sizeof(str), "pBodyPart%i", i);
		cache_get_value_name_int(0, str, PlayerInfo[playerid][E_CHARACTER_BODYPART][i]);

		format(str, sizeof(str), "pWound%i", i);
		cache_get_value_name_int(0, str, PlayerInfo[playerid][E_CHARACTER_WOUND][i]);
	}
	
	for(new i = 1; i < MAX_PLAYER_VEHICLES; i++)
	{	
		format(str, sizeof(str), "pOwnedVehicles%d", i);
		cache_get_value_name_int(0, str, PlayerInfo[playerid][E_CHARACTER_OWNEDVEHICLE][i]); 
	}
	
	if(!PlayerInfo[playerid][E_CHARACTER_MASKID])
	{
		PlayerInfo[playerid][E_CHARACTER_MASKID] = 200000+random(199991);
	}
	new query[256];
	mysql_format(ourConnection, query, sizeof(query), "SELECT * FROM `inventory` WHERE `ID` = '%d'", PlayerInfo[playerid][E_CHARACTER_DBID]);
	mysql_pquery(ourConnection, query, "LoadPlayerItems", "d", playerid);

	new qquery[256];
	mysql_format(ourConnection, qquery, sizeof(qquery), "SELECT * FROM `contacts` WHERE `ID` = '%d'", PlayerInfo[playerid][E_CHARACTER_DBID]);
	mysql_pquery(ourConnection, qquery, "LoadPlayerContacts", "d", playerid);

	new pquery[256];
	mysql_format(ourConnection, pquery, sizeof(qquery), "SELECT * FROM `relations` WHERE `relationsID` = '%i'", PlayerInfo[playerid][E_CHARACTER_DBID]);
	mysql_pquery(ourConnection, pquery, "Query_LoadRelations", "d", playerid);

	new rquery[256];
	mysql_format(ourConnection, rquery, sizeof(qquery), "SELECT * FROM `tickets` WHERE `ID` = '%i'", PlayerInfo[playerid][E_CHARACTER_DBID]);
	mysql_pquery(ourConnection, rquery, "Query_LoadTicket", "d", playerid);
	
	TogglePlayerSpectating(playerid, false);
	return Dialog_Show(playerid, Spawns, DIALOG_STYLE_TABLIST, "Spawn Option:", "#1\tLos Santos Airport\t{93C47D}PUBLIC{ffffff}\n#2\tLast Position\t{93C47D}PUBLIC{ffffff}\n#3\tFaction Spawn\t{93C47D}FACTION{ffffff}", "Select", "Close");
}

// Dialog:
Dialog:Login(playerid, response, listitem, inputtext[])
{
    if (!response)
    {
        SendErrorMessage(playerid, "You were kicked for not logging in."); 
        return KickEx(playerid);
    }
    
    new continueCheck[211]; 
    
    mysql_format(ourConnection, continueCheck, sizeof(continueCheck), "SELECT acc_dbid, forum_name, secret_word, active_ip FROM masters WHERE acc_name = '%e' AND acc_pass = sha1('%e') LIMIT 1", 
        ReturnName(playerid, 1), inputtext);
        
    mysql_pquery(ourConnection, continueCheck, "LoggingIn", "i", playerid);
    return 1;
}

Dialog:Spawns(playerid, response, listitem, inputtext[])
{
	if (!response)
	{
		SendErrorMessage(playerid, "You were kicked for not selection spawn."); 
		return KickEx(playerid);
	}
	switch(listitem)
	{
		case 0:
		{
			PlayerInfo[playerid][E_CHARACTER_SPAWNPOINT] = 0; 
			LoadCharacter(playerid);
		}
		case 1:
		{
			PlayerInfo[playerid][E_CHARACTER_SPAWNPOINT] = 1; 
			LoadCharacter(playerid);
		}
		case 2:
		{
			if(!PlayerInfo[playerid][E_CHARACTER_FACTION])
				return Dialog_Show(playerid, Spawns, DIALOG_STYLE_TABLIST, "Spawn Option:", "#1\tLos Santos Airport\t{93C47D}PUBLIC{ffffff}\n#2\tLast Position\t{93C47D}PUBLIC{ffffff}\n#3\tFaction Spawn\t{93C47D}FACTION{ffffff}", "Select", "Close");

			PlayerInfo[playerid][E_CHARACTER_SPAWNPOINT] = 2;
			LoadCharacter(playerid);
		}
	}
	return 1;
}