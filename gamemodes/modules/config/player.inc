
//Function
function:SetPlayerCamera(playerid)
{
    if(cameraIndex[playerid] < 5)
    {
        new Float:fromX = cameraPositions[cameraIndex[playerid]][0];
        new Float:fromY = cameraPositions[cameraIndex[playerid]][1];
        new Float:fromZ = cameraPositions[cameraIndex[playerid]][2];
        new Float:toX = cameraPositions[cameraIndex[playerid]][3];
        new Float:toY = cameraPositions[cameraIndex[playerid]][4];
        new Float:toZ = cameraPositions[cameraIndex[playerid]][5];
        new Float:lookFromX = cameraPositions[cameraIndex[playerid]][6];
        new Float:lookFromY = cameraPositions[cameraIndex[playerid]][7];
        new Float:lookFromZ = cameraPositions[cameraIndex[playerid]][8];
        new Float:lookToX = cameraPositions[cameraIndex[playerid]][9];
        new Float:lookToY = cameraPositions[cameraIndex[playerid]][10];
        new Float:lookToZ = cameraPositions[cameraIndex[playerid]][11];

        InterpolateCameraPos(playerid, fromX, fromY, fromZ, toX, toY, toZ, 20000, CAMERA_MOVE);
        InterpolateCameraLookAt(playerid, lookFromX, lookFromY, lookFromZ, lookToX, lookToY, lookToZ, 20000, CAMERA_MOVE);
        
        cameraIndex[playerid]++;
    }
    else
    {
		cameraIndex[playerid] = 0;
	}
	return 1;
}

function:OnOfflineAjail(playerid, jailing[], reason[], length)
{
	SendServerMessage(playerid, "[Jail] {cdd0d1}%s was successfully admin jailed.", jailing); 
	
	new
		logQuery[256]
	;
	
	mysql_format(ourConnection, logQuery, sizeof(logQuery), "INSERT INTO ajail_logs (JailedDBID, JailedName, Reason, Date, JailedBy) VALUES(%i, '%e', '%e', '%e', '%e')", ReturnDBIDFromName(jailing), jailing, reason, ReturnDate(), ReturnName(playerid));
	mysql_pquery(ourConnection, logQuery); 
	return 1;
}

function:OnOfflineBan(playerid, banning[], dbid, masterdbid, reason[], date[])
{
	SendServerMessage(playerid, "[Banned] {cdd0d1}%s was successfully banned.", banning);
	
	new
		logQuery[256]
	;
	
	mysql_format(ourConnection, logQuery, sizeof(logQuery), "INSERT INTO ban_logs (CharacterDBID, MasterDBID, CharacterName, Reason, BannedBy, Date) VALUES(%i, %i, '%e', '%e', '%e', '%e')",
		dbid, masterdbid, banning, reason, date);
		
	mysql_pquery(ourConnection, logQuery);
	return 1;
}

function:SetPlayersSpawn(playerid)
{
	switch(PlayerInfo[playerid][E_CHARACTER_SPAWNPOINT])
	{
		case SPAWN_POINT_HOODRATS:
		{
			SetPlayerPosEx(playerid, 1685.6182,-2334.3035,-2.6797);
			SetPlayerFacingAngle(playerid, 2.2789);
			SetPlayerInterior(playerid, 0);
			SetPlayerVirtualWorld(playerid, 0);
		}
		case SPAWN_POINT_LAST:
		{
			SetPlayerPosEx(playerid, PlayerInfo[playerid][E_CHARACTER_LASTPOS][0], PlayerInfo[playerid][E_CHARACTER_LASTPOS][1], PlayerInfo[playerid][E_CHARACTER_LASTPOS][2]);
			SetPlayerInterior(playerid, PlayerInfo[playerid][E_CHARACTER_LASTINTERIOR]);
			SetPlayerVirtualWorld(playerid, PlayerInfo[playerid][E_CHARACTER_LASTWORLD]);
		}
		case SPAWN_POINT_FACTION:
		{
			if(!IsPlayerFaction(playerid))
			{
				PlayerInfo[playerid][E_CHARACTER_SPAWNPOINT] = SPAWN_POINT_HOODRATS;
				return SetPlayersSpawn(playerid);
			}
			else 
			{
				new idx; 
				
				idx = PlayerInfo[playerid][E_CHARACTER_FACTION];
				
				if(!FactionInfo[idx][E_FACTION_DBID])
				{
					PlayerInfo[playerid][E_CHARACTER_SPAWNPOINT] = SPAWN_POINT_HOODRATS;
					return SetPlayersSpawn(playerid);
				}

				SetPlayerInterior(playerid, FactionInfo[idx][E_FACTION_SPAWNINT]);
				SetPlayerVirtualWorld(playerid, FactionInfo[idx][E_FACTION_SPAWNWORLD]); 
				SetPlayerPosEx(playerid, FactionInfo[idx][E_FACTION_SPAWN][0], FactionInfo[idx][E_FACTION_SPAWN][1], FactionInfo[idx][E_FACTION_SPAWN][2]);
			}
		}
	}
	return 1;
}

public OnPlayerClickMap(playerid, Float:fX, Float:fY, Float:fZ)
{
	if(PlayerInfo[playerid][E_CHARACTER_ADMINDUTY])
	{
    	new vehicleid = GetPlayerVehicleID(playerid);
        if(vehicleid > 0 && GetPlayerState(playerid) == PLAYER_STATE_DRIVER)
        {
                SetVehiclePos(vehicleid, fX, fY, fZ+10);
        }
        else
        {
                SetPlayerPosFindZ(playerid, fX, fY, 999.0);
                SetPlayerVirtualWorld(playerid, 0);
                SetPlayerInterior(playerid, 0);
        }
    }
    return 1;
}

function:Float:GetDistanceBetweenPoints(Float:rx1,Float:ry1,Float:rz1,Float:rx2,Float:ry2,Float:rz2)
{
	return floatadd(floatadd(floatsqroot(floatpower(floatsub(rx1,rx2),2)),floatsqroot(floatpower(floatsub(ry1,ry2),2))),floatsqroot(floatpower(floatsub(rz1,rz2),2)));
}

function:OnAjailRecord(playerid)
{
	if(!cache_num_rows())
		return SendClientMessage(playerid, COLOR_RED, "[!] {FFFFFF}This player hasn't been admin jailed.");
	
	new rows, fields;
	cache_get_row_count(rows);
	cache_get_field_count(fields);
	
	new
		JailedName[32], 
		Reason[128],
		Date[90],
		JailedBy[32],
		Time
	;
	
	for(new i = 0; i < rows; i++)
	{
		cache_get_value_name(i, "JailedName", JailedName, 32); 
		cache_get_value_name(i, "Reason", Reason, 128);
		
		cache_get_value_name(i, "Date", Date, 90);
		cache_get_value_name(i, "JailedBy", JailedBy, 32); 
		
		cache_get_value_name_int(i, "Time", Time); 
		
		SendServerMessage(playerid, "[Jail] {cdd0d1}[%s] %s was admin jailed by {d7d292}%s{cdd0d1} for {d7d292}%d{cdd0d1} minutes, Reason: {d7d292}%d{cdd0d1}", Date, JailedName, JailedBy, Time, Reason);
	}
		
	return 1;
}

function:KickTimer(playerid) { return Kick(playerid); }

ResetVarInventory(playerid)
{
	if(PlayerInfo[playerid][E_CHARACTER_EQUIPITEMS] > INVENTORY_NONE)
	{
		RemovePlayerAttachedObject(playerid, 9);
		RemovePlayerAttachedObject(playerid, 8);
		RemovePlayerAttachedObject(playerid, ATTACH_CARGO);
		ResetPlayerWeapons(playerid);
		HidePlayerPhone(playerid);
		CancelSelectTextDraw(playerid);
		SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
		PlayerInfo[playerid][E_CHARACTER_EQUIPITEMS] = INVENTORY_NONE;
		PlayerInfo[playerid][E_CHARACTER_WEAPONTYPE] = 0;
		
	}
	return 1;
}
function:ResetPlayer(playerid)
{
	for (new i = 0; i < MAX_LISTED_ITEMS; i ++) {
	    NearestItems[playerid][i] = -1;
	}
	
	//Anticheat
	CurrentHealthVar[playerid] = 0;
	CurrentArmourVar[playerid] = 0;
	ResetPlayerJump(playerid);
	ResetTeleportAC(playerid);
	
	KillTimer(cameraTimer[playerid]);

	HeaderBar[playerid] = INVALID_PLAYER_BAR_ID;
	//Master accounts:
	AccountInfo[playerid][E_MASTERS_DBID] = 0; 
	AccountInfo[playerid][E_MASTERS_LOGGED] = false; 
	
	playerLogin[playerid] = 0; 
	playerMakingCharacter[playerid] = false;
	playerCharacterStep[playerid] = 0;
	
	for(new i = 0; i < 2 ; i++) 
	{ 
		format(playerCharacterStory[playerid][i], 90, ""); 
	}
	
	//Prevents;
	loginTime[playerid] = 0;
	registerTime[playerid] = 0;
	characterPickTime[playerid] = 0;
	
	ResetDealershipVars(playerid);
	ClearDamages(playerid);
	
	playerPhone[playerid] = 0;
	
	format(PlayerInfo[playerid][E_CHARACTER_MDCPLAYER], 32, "");
	
	//Player characters:
	PlayerInfo[playerid][E_CHARACTER_DBID] = 0; 
	PlayerInfo[playerid][E_CHARACTER_ADMIN] = 0;
	PlayerInfo[playerid][E_CHARACTER_ADMINDUTY] = false; 
	
	PlayerInfo[playerid][E_CHARACTER_LASTPOS][0] = 1642.02;
	PlayerInfo[playerid][E_CHARACTER_LASTPOS][1] = -2334.05;
	PlayerInfo[playerid][E_CHARACTER_LASTPOS][2] = 13.5469;
	
	PlayerInfo[playerid][E_CHARACTER_LASTINTERIOR] = 0;
	PlayerInfo[playerid][E_CHARACTER_LASTWORLD] = 0;
	
	PlayerInfo[playerid][E_CHARACTER_LEVEL] = 1; 
	PlayerInfo[playerid][E_CHARACTER_AGE] = 20; 
	
	PlayerInfo[playerid][E_CHARACTER_MONEY] = 250;
	PlayerInfo[playerid][E_CHARACTER_BANK] = 250;
	PlayerInfo[playerid][E_CHARACTER_PAYCHECK] = 0; 
	
	PlayerInfo[playerid][E_CHARACTER_PHONE] = 94000+random(6999);
	PlayerInfo[playerid][E_CHARACTER_PHONEOFF] = false; 
	PlayerInfo[playerid][E_CHARACTER_PHONESPEAKER] = false; 
	
	PlayerInfo[playerid][E_CHARACTER_CALL] = 0;
	PlayerInfo[playerid][E_CHARACTER_PHONELINE] = INVALID_PLAYER_ID;

	
	PlayerInfo[playerid][E_CHARACTER_SPECTATE] = INVALID_PLAYER_ID;
	
	PlayerInfo[playerid][E_CHARACTER_FACTION] = 0;
	PlayerInfo[playerid][E_CHARACTER_FACTIONRANK] = 0;
	PlayerInfo[playerid][E_CHARACTER_FACTIONINVITE] = 0;
	PlayerInfo[playerid][E_CHARACTER_FACTIONINVITED] = INVALID_PLAYER_ID;

	PlayerInfo[playerid][E_CHARACTER_TAXICALLED] = 0;
	PlayerInfo[playerid][E_CHARACTER_TAXIFARE] = 0;
	PlayerInfo[playerid][E_CHARACTER_TAXITIMER] = 0;
	PlayerInfo[playerid][E_CHARACTER_TAXIPLAYER] = INVALID_PLAYER_ID;

	for(new i = 1; i < MAX_PLAYER_VEHICLES; i++) { 
		PlayerInfo[playerid][E_CHARACTER_OWNEDVEHICLE][i] = 0; 
	}
	
	PlayerInfo[playerid][E_CHARACTER_VEHICLESPAWNED] = false;
	PlayerInfo[playerid][E_CHARACTER_VEHICLESPAWN] = INVALID_VEHICLE_ID;
	PlayerInfo[playerid][E_CHARACTER_DUPLICATEKEY] = INVALID_VEHICLE_ID;
	
	
	PlayerInfo[playerid][E_CHARACTER_POLICEDUTY] = false;
	PlayerInfo[playerid][E_CHARACTER_MEDICDUTY] = false;
	PlayerInfo[playerid][E_CHARACTER_HAVEBALL] = 0;
	PlayerInfo[playerid][E_CHARACTER_TIMEPLAYED] = 0;

	PlayerInfo[playerid][E_CHARACTER_LOOPANIM] = 0;

	PlayerInfo[playerid][E_CHARACTER_DRINKING] = 0;
	
	PlayerInfo[playerid][E_CHARACTER_INSIDEPROP] = 0; 
	PlayerInfo[playerid][E_CHARACTER_INSIDEBIZ] = 0;
	PlayerInfo[playerid][E_CHARACTER_INSIDEENT] = 0;

	PlayerInfo[playerid][E_CHARACTER_TARGET] = 0;
	PlayerInfo[playerid][E_CHARACTER_LISTITEM] = 0;
	PlayerInfo[playerid][E_CHARACTER_STORAGESELECT] = 0;
	PlayerInfo[playerid][E_CHARACTER_STORAGEITEM] = 0;

	PlayerInfo[playerid][E_CHARACTER_MASKID] = 200000+random(199991);

	PlayerInfo[playerid][E_CHARACTER_OFFJAILED] = false;
	
	PlayerInfo[playerid][E_CHARACTER_LASTDAMAGE] = 0;
	
	PlayerInfo[playerid][E_CHARACTER_OBJECTID] = 0;
	PlayerInfo[playerid][E_CHARACTER_OBJECTTYPE] = 0;
	PlayerInfo[playerid][E_CHARACTER_OBJECTOWN] = 0;
	PlayerInfo[playerid][E_CHARACTER_ADDOBJECT] = INVALID_OBJECT_ID;
	PlayerInfo[playerid][E_CHARACTER_EDITINGOBJECT] = 0;
	
	PlayerInfo[playerid][E_CHARACTER_SELECTITEMS] = 0;
	
	PlayerInfo[playerid][E_CHARACTER_HASRADIO] = false;
	PlayerInfo[playerid][E_CHARACTER_MAINSLOT] = 1; 
	
	for(new i = 1; i < 3; i++){
		PlayerInfo[playerid][E_CHARACTER_RADIO][i] = 0;
	}
	
	PlayerInfo[playerid][E_CHARACTER_RESPAWNTIME] = 0;
	PlayerInfo[playerid][E_CHARACTER_DRINKCD] = 0;
	PlayerInfo[playerid][E_CHARACTER_DRUGSCD] = 0;

	PlayerInfo[playerid][E_CHARACTER_SPAWNPOINT] = 0; 
	
	PlayerInfo[playerid][E_CHARACTER_POLICEGUN] = false;
	PlayerInfo[playerid][E_CHARACTER_POLICEAMMO] = 0;  
	
	PlayerInfo[playerid][E_CHARACTER_WEAPLICENSE] = 0;
	PlayerInfo[playerid][E_CHARACTER_DRIVELICENSE] = 0;
	PlayerInfo[playerid][E_CHARACTER_ACTIVELIST] = 0;
	PlayerInfo[playerid][E_CHARACTER_PRISON] = false;
	PlayerInfo[playerid][E_CHARACTER_PRISON] = 0;
	PlayerMenuSelection[playerid] = -1;
	PlayerHasMenuSelection[playerid] = 0;
	PlayerLastMenuSelectionTick[playerid] = GetTickCount();
	PlayerInfo[playerid][E_CHARACTER_SELECTCHAR] = -1;
	PlayerInfo[playerid][E_CHARACTER_HASROBBIZ] = false;
	PlayerInfo[playerid][E_CHARACTER_ROBBERYACTOR] = -1;
	PlayerInfo[playerid][E_CHARACTER_HASROBBERY] = -1;
	PlayerInfo[playerid][E_CHARACTER_PURCHASE] = 0;
	PlayerInfo[playerid][E_CHARACTER_FISHING] = false;
	PlayerInfo[playerid][E_CHARACTER_LOADINGCOUNT] = 0;
	PlayerInfo[playerid][E_CHARACTER_LOADINGTIMER] = false;
	PlayerInfo[playerid][E_CHARACTER_WEAPONTYPE] = 0;
	PlayerInfo[playerid][E_CHARACTER_EQUIPITEMS] = INVENTORY_NONE;
	PlayerInfo[playerid][E_CHARACTER_TEMPMODEL] = 0;
	PlayerInfo[playerid][E_CHARACTER_EXTORTION] = false;
	PlayerInfo[playerid][E_CHARACTER_EXTORTIONID] = 0;
	PlayerInfo[playerid][E_CHARACTER_EXTORTIONPOINT] = 0;
	PlayerInfo[playerid][E_CHARACTER_TOGPHONE] = true;

	pCBugging[playerid] = false;
	KillTimer(ptmCBugFreezeOver[playerid]);
	ptsLastFiredWeapon[playerid] = 0;

	for(new i; i < 4; i++)
	{
		format(characterLister[playerid][i], 128, "");
		characterSkin[playerid][i] = 0;
		characterFaction[playerid][i] = 0;
	}

	//Offer
	PlayerInfo[playerid][E_CHARACTER_FRISKOFFER] = INVALID_PLAYER_ID;
	PlayerInfo[playerid][E_CHARACTER_SHAKEOFFER] = INVALID_PLAYER_ID;
	PlayerInfo[playerid][E_CHARACTER_SHAKETYPE] = 0;

	KillTimer(PlayerTimerGym[playerid]);
    PlayerGymMachine[playerid] = -1;
    PlayerPointGym[playerid] = 0;  
    PlayerUsingGym[playerid] = false;

	PlayerInfo[playerid][E_CHARACTER_TOGMENU] = false;
	PlayerInfo[playerid][E_CHARACTER_TOGADMIN] = false;
	PlayerInfo[playerid][E_CHARACTER_TOGHUD] = false;
	PlayerInfo[playerid][E_CHARACTER_TOGJOIN] = false;
	PlayerInfo[playerid][E_CHARACTER_TOGFMS] = false;
	PlayerInfo[playerid][E_CHARACTER_TOGDMS] = false;
	PlayerInfo[playerid][E_CHARACTER_TOGPMS] = false;
	PlayerInfo[playerid][E_CHARACTER_TOGDD] = false;
	PlayerInfo[playerid][E_CHARACTER_TOGTURF] = false;

	PlayerInfo[playerid][E_CHARACTER_SPAWNED] = false;

	PlayerInfo[playerid][E_CHARACTER_DEATH] = 0;
	PlayerInfo[playerid][E_CHARACTER_INJURED] = 0;
	PlayerInfo[playerid][E_CHARACTER_DIEUNKNOWN] = false;

	PlayerInfo[playerid][E_CHARACTER_HEALTH] = 100.0;
	PlayerInfo[playerid][E_CHARACTER_ARMOUR] = 0.0;

	PlayerInfo[playerid][E_CHARACTER_AFK] = 0;
    PlayerInfo[playerid][E_CHARACTER_AFKTIME] = 0;

    PlayerInfo[playerid][E_CHARACTER_JOBSTIME] = 0;
    PlayerInfo[playerid][E_CHARACTER_GARBAGEMAN] = false;
	PlayerInfo[playerid][E_CHARACTER_DOCKSWORK] = false;
	PlayerInfo[playerid][E_CHARACTER_GARBAGEMAN_VALUE] = 0;

	PlayerInfo[playerid][E_CHARACTER_COURT] = 0;
	PlayerInfo[playerid][E_CHARACTER_HAVEBALL] = 0;
    PlayerInfo[playerid][E_CHARACTER_ANIMBALL] = 0;
	PlayerInfo[playerid][E_CHARACTER_COURTTEAM] = 0;

	PlayerInfo[playerid][E_CHARACTER_TUTORIALSTEP] = 0;

	ResetLotteryVar(playerid);
	return 1;
}

//Stock functions:

stock IsPlayerNearPlayer(playerid, targetid, Float:radius)
{
	static
		Float:fX,
		Float:fY,
		Float:fZ;

	GetPlayerPos(targetid, fX, fY, fZ);

	return (GetPlayerInterior(playerid) == GetPlayerInterior(targetid) && GetPlayerVirtualWorld(playerid) == GetPlayerVirtualWorld(targetid)) && IsPlayerInRangeOfPoint(playerid, radius, fX, fY, fZ);
}

stock IsValidRoleplayName(const name[]) {
	if (!name[0] || strfind(name, "_") == -1)
	    return 0;

	else for (new i = 0, len = strlen(name); i != len; i ++) {
	    if ((i == 0) && (name[i] < 'A' || name[i] > 'Z'))
	        return 0;

		else if ((i != 0 && i < len  && name[i] == '_') && (name[i + 1] < 'A' || name[i + 1] > 'Z'))
		    return 0;

		else if ((name[i] < 'A' || name[i] > 'Z') && (name[i] < 'a' || name[i] > 'z') && name[i] != '_' && name[i] != '.')
		    return 0;
	}
	return 1;
}

stock KickEx(playerid)
{
	return SetTimerEx("KickTimer", 100, false, "i", playerid);
}

stock ClearLines(playerid, lines)
{
	if (lines > 20 || lines < 1)
		return 0;
		
	for (new i = 0; i < lines; i++)
	{
		SendClientMessage(playerid, -1, " ");
	}
	return 1;
}

stock ShowCharacterStats(playerid, playerb)
{
	new 
		vehicle_key[20],
		duplicate_key[20],
		business_key[20] = "None",
		gender[20];
	
	if(!PlayerInfo[playerid][E_CHARACTER_VEHICLESPAWNED])
		vehicle_key = "None";
	else format(vehicle_key, 32, "%d", PlayerInfo[playerid][E_CHARACTER_VEHICLESPAWN]);

	if(PlayerInfo[playerid][E_CHARACTER_GENDER] == 1) format(gender, 20, "Male");
	else if(PlayerInfo[playerid][E_CHARACTER_GENDER] == 2) format(gender, 20, "Female");
	else format(gender, 20, "Unknown");
	
	if(PlayerInfo[playerid][E_CHARACTER_DUPLICATEKEY] == INVALID_VEHICLE_ID)
		duplicate_key = "None";
	else format(duplicate_key, 32, "%d", PlayerInfo[playerid][E_CHARACTER_DUPLICATEKEY]); 
	
	for(new i = 1; i < MAX_BUSINESS; i++)
	{
		if(!BusinessInfo[i][E_BUSINESS_DBID])
			continue;
			
		if(BusinessInfo[i][E_BUSINESS_OWNERDBID] == PlayerInfo[playerid][E_CHARACTER_DBID])
			format(business_key, 20, "%d", BusinessInfo[i][E_BUSINESS_DBID]); 
	}
	
	SendClientMessageEx(playerid, COLOR_DARKGREEN, "|______________________________ (%d) %s Statistics ______________________________|", playerid, AccountInfo[playerid][E_MASTERS_ACCNAME]);
	SendClientMessageEx(playerb, COLOR_WHITE, "[ACCOUNT]:{ffffff} [Streetname: %s] - [Account: %s] - [Date: %s]", ReturnName(playerid), AccountInfo[playerid][E_MASTERS_ACCNAME], ReturnDate());	
	SendClientMessageEx(playerb, COLOR_GREY, "[SESSION]:{ffffff} [Gender: %s] [Level: %d] [EXP: %d/10] [Time played: %d hours]", gender, PlayerInfo[playerid][E_CHARACTER_LEVEL], PlayerInfo[playerid][E_CHARACTER_EXP], PlayerInfo[playerid][E_CHARACTER_TIMEPLAYED]);
	SendClientMessageEx(playerb, COLOR_WHITE, "[FINANCIAL]:{ffffff} [Cash Hand: $%s] [Cash Bank: $%s] [Paycheck: $%s]", FormatMoney(PlayerInfo[playerid][E_CHARACTER_MONEY]), FormatMoney(PlayerInfo[playerid][E_CHARACTER_BANK]), FormatMoney(PlayerInfo[playerid][E_CHARACTER_PAYCHECK]));
	SendClientMessageEx(playerb, COLOR_GREY, "[JOBS]:{ffffff} [Jobs: %s] [Skills: %s]", ReturnJobName(PlayerInfo[playerid][E_CHARACTER_JOBS]), ReturnJobSkill(playerid, PlayerInfo[playerid][E_CHARACTER_JOBS]));
	SendClientMessageEx(playerb, COLOR_WHITE, "[KEYS]:{ffffff} VehicleKey:[%s] DuplicateKey:[%s] BusinessKey:[%s]", vehicle_key, duplicate_key, business_key);	
	if(PlayerInfo[playerb][E_CHARACTER_FACTION])
	{
		SendClientMessageEx(playerb, COLOR_GREY, "[FACTION]:{ffffff} [Faction: %s] [Rank: %s]", ReturnFactionName(playerid), IsPlayerFactionRank(playerid));
	}
	SendTipMessage(playerb, "/inventory or press 'Y' to open inventory.");
	
	if(PlayerInfo[playerb][E_CHARACTER_ADMINDUTY])
	{
		SendClientMessageEx(playerb, COLOR_WHITE, "[FOR ADMIN]: DBID:[%d] Master:[%s (%d)] Interior:[%d] Local:[%d]", PlayerInfo[playerid][E_CHARACTER_DBID], AccountInfo[playerid][E_MASTERS_ACCNAME], AccountInfo[playerid][E_MASTERS_DBID], GetPlayerInterior(playerid), GetPlayerVirtualWorld(playerid));
		
		SendClientMessageEx(playerb, COLOR_GREY, "[CONNECTION]: IP:[%s] Last Online:[%s] Duration:[%d Minutes]", ReturnIP(playerid), ReturnLastOnline(playerid), PlayerInfo[playerid][E_CHARACTER_LASTONLINE]);
		
		SendClientMessageEx(playerb, COLOR_WHITE, "[MISC]: InsideProperty:[%i] InsideBusiness:[%i]", IsPlayerInProperty(playerid), IsPlayerInBusiness(playerid)); 
	}
	return 1;
}


stock PlayNearbySound(playerid, sound)
{
	new
	    Float:x,
	    Float:y,
	    Float:z;

	GetPlayerPos(playerid, x, y, z);

	foreach (new i : Player) if (IsPlayerInRangeOfPoint(i, 15.0, x, y, z)) {
	    PlayerPlaySound(i, sound, x, y, z);
	}
	return 1;
}

stock SetMoney(playerid, cash)
{
	PauseAC(playerid);
	PlayerInfo[playerid][E_CHARACTER_MONEY] = cash;
	ResetPlayerMoney(playerid);
	GivePlayerMoney(playerid, cash);
}

stock GiveMoney(playerid, amount)
{
	PauseAC(playerid);
	PlayerInfo[playerid][E_CHARACTER_MONEY] += amount;
	GivePlayerMoney(playerid, amount);
	
	new string[128]; 
	
	if(amount < 0) {
		format(string, sizeof(string), "~r~$%d", amount);
		GameTextForPlayer(playerid, string, 2000, 1);
	}
	else{
		format(string, sizeof(string), "~g~$%d", amount);
		GameTextForPlayer(playerid, string, 2000, 1);
	}
	return 1;
}

stock HexToInt(string[])
{
    if(!string[0]) return 0;
    new cur = 1, res = 0;
    for(new i = strlen(string); i > 0; i--)
    {
        res += cur * (string[i - 1] - ((string[i - 1] < 58) ? (48) : (55)));
        cur = cur * 16;
    }
    return res;
}

stock DoesPlayerExist(name[])
{
	new checkQuery[128];
	
	mysql_format(ourConnection, checkQuery, sizeof(checkQuery), "SELECT char_name FROM characters WHERE char_name = '%e'", name); 
	new Cache:cache = mysql_query(ourConnection, checkQuery); 
	
	if(cache_num_rows())
	{
		cache_delete(cache); 
		return 1; 
	}
	
	cache_delete(cache);
	return 0;	
}

stock FormatMoney(integer)
{
	new value[20], string[20];

	valstr(value, integer);

	new charcount;

	for(new i = strlen(value); i >= 0; i --)
	{
		format(string, sizeof(string), "%c%s", value[i], string);
		if(charcount == 3)
		{
			if(i != 0)
				format(string, sizeof(string), ",%s", string);
			charcount = 0;
		}
		charcount ++;
	}

	return string;
}
stock IsChannelSlot(playerid, chan)
{
	for(new i = 1; i < 3; i++)
	{
		if(PlayerInfo[playerid][E_CHARACTER_RADIO][i] == chan)
			return i;
	}
	return 0; 
}

stock FilterInputText(const inputtext[])
{
    new len = strlen(inputtext);
    for (new i = 0; i < len; i++)
    {
        new c = inputtext[i];
        if (!(c >= 'A' && c <= 'Z') &&  // Huruf A-Z
			!(c >= 'a' && c <= 'z') && // Huruf a-z
            !(c >= '0' && c <= '9') &&  // Angka 0-9
            !(c == '(' || c == ')' || c == '?' || c == '!' || c == '-' || c == '=' || c == ' ')) // Simbol !?-= SPASI
        {
            return false;
        }
    }
    return true; // Semua karakter valid
}

stock FilterInputFont(const inputtext[])
{
    new len = strlen(inputtext);
    for (new i = 0; i < len; i++)
    {
        new c = inputtext[i];
        if (!(c >= 'A' && c <= 'Z') &&  // Huruf A-Z
			!(c >= 'a' && c <= 'z') && // Huruf a-z
            !(c >= '0' && c <= '9'))
        {
            return false;
        }
    }
    return true; // Semua karakter valid
}

stock IsNumeric(const str[])
{
	for (new i = 0, l = strlen(str); i != l; i ++)
	{
	    if (i == 0 && str[0] == '-')
			continue;

	    else if (str[i] < '0' || str[i] > '9')
			return 0;
	}
	return 1;
}

stock ShowPlayerPlates(playerid, str[])
{
	ShowBoxMessage(playerid, str, 5);
	return 1;
}

stock ShowGeneralList(playerid, type)
{
	if(BusinessInfo[IsPlayerInBusiness(playerid)][E_BUSINESS_STOCK] < 1)
		return SendErrorMessage(playerid, "This business is out of stock"); 

	new str[128];

	switch(type)
	{
		case 0:
		{
			/*if(IsPlayerInRangeOfPoint(playerid, 3.0, 1861.9351,-1699.4071,13.5860) || IsPlayerInRangeOfPoint(playerid, 3.0, 1924.5963,-1770.1909,13.5988) || IsPlayerInRangeOfPoint(playerid, 3.0, 1735.7974,-1698.2885,13.5316) || IsPlayerInRangeOfPoint(playerid, 3.0, 2726.9329,-2034.2412,13.6482) || IsPlayerInRangeOfPoint(playerid, 3.0, 2427.8018,-1745.1559,13.6681))
			{
				//format(str, sizeof(str), "General:");
				//ShowPlayerDialog(playerid, DIALOG_BUY_LIST, DIALOG_STYLE_TABLIST_HEADERS, str, "Product\tPrice\nCellphone\t$500\n2 Slot Radio\t$1,000\nGas Can\t$500\nRepair Kits\t$500\nSpraycan\t$250\nCrowbar\t$500", "Select", "Cancel");
			}*/
		}
		case 1: //Spraycan & Crowbar
		{
			if(IsPlayerInBusiness(playerid))
			{	
				if(IsPlayerInRangeOfPoint(playerid, 2.0, -48.1108,5.5907,203.2633))
				{
					format(str, sizeof(str), "%s:", BusinessInfo[IsPlayerInBusiness(playerid)][E_BUSINESS_NAME]);
					ShowPlayerDialog(playerid, DIALOG_GENERALSTORE4, DIALOG_STYLE_TABLIST_HEADERS, str, "Product\tPrice\nSpraycan\t$250\nCrowbar\t$500", "Select", "Cancel"); 
				}
			}
		}
		case 2: //Cellphone & Portable Radio
		{
			if(IsPlayerInBusiness(playerid))
			{	
				if(IsPlayerInRangeOfPoint(playerid, 2.0, -51.4530,5.4811,203.2633))
				{
					format(str, sizeof(str), "%s:", BusinessInfo[IsPlayerInBusiness(playerid)][E_BUSINESS_NAME]);
					ShowPlayerDialog(playerid, DIALOG_GENERALSTORE1, DIALOG_STYLE_TABLIST_HEADERS, str, "Product\tPrice\nCellphone\t$500\nPortable Radio\t$500\nGascan\t$250\nRepair Kits\t$500", "Select", "Cancel"); 
				}
			}
		}
		case 3: //Baseball
		{
			if(IsPlayerInBusiness(playerid))
			{	
				if(IsPlayerInRangeOfPoint(playerid, 2.0, -53.7646,5.2118,203.2633))
				{
					format(str, sizeof(str), "%s:", BusinessInfo[IsPlayerInBusiness(playerid)][E_BUSINESS_NAME]);
					ShowPlayerDialog(playerid, DIALOG_GENERALSTORE2, DIALOG_STYLE_TABLIST_HEADERS, str, "Product\tPrice\nSpike Bat\t$350\nWooded\t$500\nNail Bat\t$350", "Select", "Cancel"); 
				}
			}
		}
		case 4: //Raw Meat
		{
			if(IsPlayerInBusiness(playerid))
			{	
				if(IsPlayerInRangeOfPoint(playerid, 2.0, -48.4748,-1.1597,203.2633))
				{
					format(str, sizeof(str), "%s:", BusinessInfo[IsPlayerInBusiness(playerid)][E_BUSINESS_NAME]);
					ShowPlayerDialog(playerid, DIALOG_GENERALSTORE3, DIALOG_STYLE_TABLIST_HEADERS, str, "Product\tPrice\nRaw Meat\t$50\nParsley\t$250\nMint\t$50\nOregano\t$250\nBaking Soda\t$100", "Select", "Cancel"); 
				}
			}
		}
		case 5: //Sprunk
		{
			if(IsPlayerInBusiness(playerid))
			{	
				if(IsPlayerInRangeOfPoint(playerid, 2.0, -53.7980,2.8393,203.2633))
				{
					format(str, sizeof(str), "%s:", BusinessInfo[IsPlayerInBusiness(playerid)][E_BUSINESS_NAME]);
					ShowPlayerDialog(playerid, DIALOG_GENERALSTORE5, DIALOG_STYLE_TABLIST_HEADERS, str, "Product\tPrice\nSprunk\t$2", "Select", "Cancel"); 
				}
			}
		}
	}
	return 1;
}

stock ShowBeerlist(playerid)
{ 
	new str[128];

	if(IsPlayerInBusiness(playerid))
	{	
		format(str, sizeof(str), "%s:", BusinessInfo[IsPlayerInBusiness(playerid)][E_BUSINESS_NAME]);
		ShowPlayerDialog(playerid, DIALOG_BAR, DIALOG_STYLE_TABLIST_HEADERS, str, "Product\tPrice\nBudWeiser (Beer)\t$100\nCorona Extra (Beer)\t$150\nPeroni (Beer)\t$200", "Select", "Cancel");
	}
	else if(IsPlayerInRangeOfPoint(playerid, 3.0, 2130.7271,-1769.0083,13.5510) || IsPlayerInRangeOfPoint(playerid, 3.0, 2139.9614,-1769.1486,13.5510))
	{
		format(str, sizeof(str), "Liquor:");
		ShowPlayerDialog(playerid, DIALOG_BAR, DIALOG_STYLE_TABLIST_HEADERS, str, "Product\tPrice\nBudWeiser (Beer)\t$100\nCorona Extra (Beer)\t$150\nPeroni (Beer)\t$200", "Select", "Cancel");
	}
	return 1;
}

stock ShowFoodMenu(playerid)
{ 
	new str[128];

	if(IsPlayerInBusiness(playerid))
	{	
		format(str, sizeof(str), "%s:", BusinessInfo[IsPlayerInBusiness(playerid)][E_BUSINESS_NAME]);
		ShowPlayerDialog(playerid, DIALOG_DINNER, DIALOG_STYLE_TABLIST_HEADERS, str, "Product\tPrice\nAmerican Classic Burger's\t$50\nAmerican Classic Pizza's\t$80\nCoca Cola Large\t$20", "Select", "Cancel");
	}
	else if(IsPlayerInRangeOfPoint(playerid, 3.0, 1705.7178,-1650.0876,13.5276) || IsPlayerInRangeOfPoint(playerid, 3.0, 2106.5166,-1797.5454,13.5625) || IsPlayerInRangeOfPoint(playerid, 3.0, 2414.0591,-1504.1791,24.0031) || IsPlayerInRangeOfPoint(playerid, 3.0, 2392.0125,-1905.1108,13.5234) || IsPlayerInRangeOfPoint(playerid, 3.0, 1859.9919,-1670.8585,13.3731) || IsPlayerInRangeOfPoint(playerid, 3.0, 1035.1194,-1346.8387,13.7469))
	{
		format(str, sizeof(str), "Food & Drinks Menu:");
		ShowPlayerDialog(playerid, DIALOG_DINNER, DIALOG_STYLE_TABLIST_HEADERS, str, "Product\tPrice\nAmerican Classic Burger's\t$50\nAmerican Classic Donut's\t$50\nAmerican Classic Pizza's\t$80\nCoca Cola Large\t$20", "Select", "Cancel");
	}
	return 1;
}

stock ShowClothesMenu(playerid)
{ 
	new id = IsPlayerInBusiness(playerid), str[128];

	format(str, sizeof(str), "%s:", BusinessInfo[id][E_BUSINESS_NAME]);
	Dialog_Show(playerid, BuySkins, DIALOG_STYLE_TABLIST_HEADERS, str, "Product\tPrice\nClassic Clothes\t$250\nToys\t$500", "Select", "Cancel");
	return 1;
}

Dialog:BuySkins(playerid, response, listitem, inputtext[])
{
	if(response)
	{
		switch(listitem)
		{
			case 0:
			{
				SetPlayerPos(playerid, 217.5163,-98.4308,1005.2578);
				SetPlayerFacingAngle(playerid, 94.6310);

				SetPlayerCameraPos(playerid, 214.387527, -99.966537, 1005.545410);
				SetPlayerCameraLookAt(playerid, 217.848388, -97.962821, 1005.458129, 1);

				if(PlayerInfo[playerid][E_CHARACTER_GENDER] == 1)
				{
					new str[1024];
					for(new i; i < sizeof(g_aMaleSkins); i++)
					{
						format(str, sizeof(str), "%s%d\n", str, g_aMaleSkins[i]);
					}
					Dialog_Show(playerid, BuyMaleSkinsModel, DIALOG_STYLE_PREVIEW_MODEL, "Choose your skins:", str, "Select", "Close");
				}
				else if(PlayerInfo[playerid][E_CHARACTER_GENDER] == 2)
				{
					new str[1024];
					for(new i; i < sizeof(g_aFemaleSkins); i++)
					{
						format(str, sizeof(str), "%s%d\n", str, g_aFemaleSkins[i]);
					}
					Dialog_Show(playerid, BuyFemaleSkinsModel, DIALOG_STYLE_PREVIEW_MODEL, "Choose your skins:", str, "Select", "Close");
				}
			}
			case 1:
			{
				SetPlayerPos(playerid, 217.5163,-98.4308,1005.2578);
				SetPlayerFacingAngle(playerid, 94.6310);

				SetPlayerCameraPos(playerid, 214.387527, -99.966537, 1005.545410);
				SetPlayerCameraLookAt(playerid, 217.848388, -97.962821, 1005.458129, 1);
				new str[1024];
				for(new i; i < sizeof(g_aClothingCustom); i++)
				{
					format(str, sizeof(str), "%s%d\n", str, g_aClothingCustom[i]);
				}
				Dialog_Show(playerid, BuyAccModel, DIALOG_STYLE_PREVIEW_MODEL, "Choose your clothing:", str, "Select", "Close");
			}
		}
	}
	return 1;
}

Dialog:BuyMaleSkinsModel(playerid, response, listitem, inputtext[])
{
	if(response)
	{
		if(250 > PlayerInfo[playerid][E_CHARACTER_MONEY])
		{
			SetCameraBehindPlayer(playerid);
			SendErrorMessage(playerid, "You can't afford a clothes.");
			return 1;
		}

		if(BusinessInfo[IsPlayerInBusiness(playerid)][E_BUSINESS_STOCK] < 1)
		{
			SetCameraBehindPlayer(playerid);
			return SendErrorMessage(playerid, "This business is out of stock");
		}

		SetTimerEx("EnterFittingRoom", 1000, false, "ii", playerid, g_aMaleSkins[listitem]);
	}
	else
	{
		SetCameraBehindPlayer(playerid);
		TogglePlayerControllable(playerid, true);
	}
	return 1;
}

Dialog:BuyFemaleSkinsModel(playerid, response, listitem, inputtext[])
{
	if(response)
	{
		if(250 > PlayerInfo[playerid][E_CHARACTER_MONEY])
		{
			SetCameraBehindPlayer(playerid);
			SendErrorMessage(playerid, "You can't afford a clothes.");
			return 1;
		}

		if(BusinessInfo[IsPlayerInBusiness(playerid)][E_BUSINESS_STOCK] < 1)
		{
			SetCameraBehindPlayer(playerid);
			return SendErrorMessage(playerid, "This business is out of stock");
		}

		SetTimerEx("EnterFittingRoom", 1000, false, "ii", playerid, g_aFemaleSkins[listitem]);
	}
	else
	{
		SetCameraBehindPlayer(playerid);
		TogglePlayerControllable(playerid, true);
	}
	return 1;
}

Dialog:BuyAccModel(playerid, response, listitem, inputtext[])
{
	if(response)
	{
		if(250 > PlayerInfo[playerid][E_CHARACTER_MONEY])
		{
			SetCameraBehindPlayer(playerid);
			SendErrorMessage(playerid, "You can't afford a clothing.");
			return 1;
		}

		if(BusinessInfo[IsPlayerInBusiness(playerid)][E_BUSINESS_STOCK] < 1)
		{
			SetCameraBehindPlayer(playerid);
			return SendErrorMessage(playerid, "This business is out of stock");
		}
		if(GetPlayerFreeToySlot(playerid) == -1)
		{
			SetCameraBehindPlayer(playerid);
			return SendErrorMessage(playerid, "You already have full slot of accessories!");
		}

		GiveMoney(playerid, -300);
		ApplyAnimation(playerid, "CLOTHES", "CLO_Buy", 4.0, 0, 0, 0, 0, 0);
    	SetCameraBehindPlayer(playerid);
		BusinessInfo[IsPlayerInBusiness(playerid)][E_BUSINESS_STOCK]--;
		ShowPlayerDialog(playerid, DIALOG_BUYCLOTHING, DIALOG_STYLE_LIST, "Bone Selection:", "Spine\nHead\nLeft upper arm\nRight upper arm\nLeft hand\nRight hand\nLeft thigh\nRight thigh\nLeft foot\nRight foot\nRight calf\nLeft calf\nLeft forearm\nRight forearm\nLeft shoulder\nRight shoulder\nNeck\nJaw", "Choose", "Cancel");
		PlayerInfo[playerid][E_CHARACTER_TEMPMODEL] = g_aClothingCustom[listitem];
	}
	else
	{
		SetCameraBehindPlayer(playerid);
		TogglePlayerControllable(playerid, true);
	}
	return 1;
}

stock ShowFightStyleMenu(playerid)
{ 
	new id = IsPlayerInBusiness(playerid), str[128];

	format(str, sizeof(str), "%s:", BusinessInfo[id][E_BUSINESS_NAME]);
	ShowPlayerDialog(playerid, DIALOG_FIGHTSTYLE, DIALOG_STYLE_TABLIST_HEADERS, str, "Product\tPrice\nBoxing\t$1000\nKneehead\t$2500\nGrabKick\t$3000\nReset\t$500", "Select", "Cancel");
	return 1;
}

stock IsPlayerAdmins(playerid)
{
	return PlayerInfo[playerid][E_CHARACTER_ADMIN];
}

stock IsPlayerFaction(playerid)
{
	return PlayerInfo[playerid][E_CHARACTER_FACTION];
}

stock IsPlayerStreetName(playerid)
{
 	new astring[28];
 	if(PlayerInfo[playerid][E_CHARACTER_FACTION] == 0) format(astring, sizeof(astring), "");
	else if (PlayerInfo[playerid][E_CHARACTER_FACTION] == 1)format(astring, sizeof(astring), "[LSPD]");
	else if (PlayerInfo[playerid][E_CHARACTER_FACTION] == 2)format(astring, sizeof(astring), "[LSMD]");
	else if (PlayerInfo[playerid][E_CHARACTER_FACTION] == 3)
	{
		if (PlayerInfo[playerid][E_CHARACTER_FACTIONSUBSETS] == 1)
		{
			format(astring, sizeof(astring), "[OGF]");
		}
		else
			format(astring, sizeof(astring), "[GSF]");
	}
	else if (PlayerInfo[playerid][E_CHARACTER_FACTION] == 4)format(astring, sizeof(astring), "[KTB]");
	else if (PlayerInfo[playerid][E_CHARACTER_FACTION] == 5)format(astring, sizeof(astring), "[RHB]");
	else if (PlayerInfo[playerid][E_CHARACTER_FACTION] == 6)format(astring, sizeof(astring), "[SBF]");
	else if (PlayerInfo[playerid][E_CHARACTER_FACTION] == 7)format(astring, sizeof(astring), "[LSV]");
	else if (PlayerInfo[playerid][E_CHARACTER_FACTION] == 8)format(astring, sizeof(astring), "[VLA]");
	else if (PlayerInfo[playerid][E_CHARACTER_FACTION] == 9)format(astring, sizeof(astring), "[FYB]");
	else if (PlayerInfo[playerid][E_CHARACTER_FACTION] == 10)format(astring, sizeof(astring), "[TDF]");
	else if (PlayerInfo[playerid][E_CHARACTER_FACTION] == 11)format(astring, sizeof(astring), "[TDB]");
	return astring;
}

stock IsPlayerFactionRank(playerid)
{
 	new astring[28];
 	if(FactionInfo[PlayerInfo[playerid][E_CHARACTER_FACTION]][E_FACTION_TYPE] == FACTION_TYPE_ILLEGAL)
 	{ 
 		if (PlayerInfo[playerid][E_CHARACTER_FACTIONRANK] == 0)format(astring, sizeof(astring), "Hoodrats");
 		else if (PlayerInfo[playerid][E_CHARACTER_FACTIONRANK] == 1)format(astring, sizeof(astring), "Local");
 		else if (PlayerInfo[playerid][E_CHARACTER_FACTIONRANK] == 2)format(astring, sizeof(astring), "Official Members");
 		else if (PlayerInfo[playerid][E_CHARACTER_FACTIONRANK] == 3)format(astring, sizeof(astring), "Original Baby Gangster");
 		else if (PlayerInfo[playerid][E_CHARACTER_FACTIONRANK] == 4)format(astring, sizeof(astring), "Original Gangster");
	}
	else if(FactionInfo[PlayerInfo[playerid][E_CHARACTER_FACTION]][E_FACTION_TYPE] == FACTION_TYPE_POLICE)
 	{ 
 		if (PlayerInfo[playerid][E_CHARACTER_FACTIONRANK] == 0)format(astring, sizeof(astring), "Training");
 		else if (PlayerInfo[playerid][E_CHARACTER_FACTIONRANK] == 1)format(astring, sizeof(astring), "Police Officer");
 		else if (PlayerInfo[playerid][E_CHARACTER_FACTIONRANK] == 2)format(astring, sizeof(astring), "Police Commander");
 		else if (PlayerInfo[playerid][E_CHARACTER_FACTIONRANK] == 3)format(astring, sizeof(astring), "Deputy Chief of Police");
 		else if (PlayerInfo[playerid][E_CHARACTER_FACTIONRANK] == 4)format(astring, sizeof(astring), "Chief of Police");
	}
	else if(FactionInfo[PlayerInfo[playerid][E_CHARACTER_FACTION]][E_FACTION_TYPE] == FACTION_TYPE_MEDICAL)
 	{ 
 		if (PlayerInfo[playerid][E_CHARACTER_FACTIONRANK] == 0)format(astring, sizeof(astring), "Training");
 		else if (PlayerInfo[playerid][E_CHARACTER_FACTIONRANK] == 1)format(astring, sizeof(astring), "Doctor");
 		else if (PlayerInfo[playerid][E_CHARACTER_FACTIONRANK] == 2)format(astring, sizeof(astring), "Hospital Executive");
 		else if (PlayerInfo[playerid][E_CHARACTER_FACTIONRANK] == 3)format(astring, sizeof(astring), "Deputy Chief of Medical");
 		else if (PlayerInfo[playerid][E_CHARACTER_FACTIONRANK] == 4)format(astring, sizeof(astring), "Chief of Medical");
	}
	else
	{
		format(astring, sizeof(astring), "Hoodrats");
	}
	return astring;
}

stock randomEx(min, max)
{
    return random(max - min) + min;
}

stock GetCount() { return GetTickCount(); }

stock SetPlayerToFacePlayer(playerid, targetid)
{
	new
	    Float:x[2],
	    Float:y[2],
	    Float:z[2],
	    Float:angle;

	GetPlayerPos(targetid, x[0], y[0], z[0]);
	GetPlayerPos(playerid, x[1], y[1], z[1]);

	angle = (180.0 - atan2(x[1] - x[0], y[1] - y[0]));
	SetPlayerFacingAngle(playerid, angle + (5.0 * -1));
}

function:StopChatting(playerid)
{
	if(GetPlayerState(playerid) == PLAYER_STATE_ONFOOT && GetPlayerSpecialAction(playerid) != SPECIAL_ACTION_DUCK)
	{
		if(GetPlayerAnimationIndex(playerid) != 0)
		{
			ApplyAnimationEx(playerid, "CARRY", "crry_prtial", 4.0, 0, 0, 0, 0, 0);
		}
	}
}

stock ChatAnimation(playerid, lenght)
{
	if(GetPlayerState(playerid) == PLAYER_STATE_ONFOOT && GetPlayerSpecialAction(playerid) != SPECIAL_ACTION_DUCK)
	{
		if(GetPlayerTeam(playerid) == PLAYER_STATE_ALIVE)
		{

			ApplyAnimation(playerid, "GANGS", "prtial_gngtlkC", 4.0, 1, 1, 1, 1, 1, 1);

			SetTimerEx("StopChatting", floatround(lenght) * 100, false, "i", playerid);
		}
	}
	return 1;
}

stock SetDynamicActorAngleToPlayer(actorid, playerid)
{
	new Float:pX, Float:pY, Float:pZ;
    GetPlayerPos(playerid, pX, pY, pZ);

    return SetFacingPoint(actorid, pX, pY);
}

stock SetFacingPoint(actorid, Float:x, Float:y)
{

    new Float:pX, Float:pY, Float:pZ;
    GetDynamicActorPos(actorid, pX, pY, pZ);

    new Float:angle;

    if( y > pY ) angle = (-acos((x - pX) / floatsqroot((x - pX)*(x - pX) + (y - pY)*(y - pY))) - 90.0);
    else if( y < pY && x < pX ) angle = (acos((x - pX) / floatsqroot((x - pX)*(x - pX) + (y - pY)*(y - pY))) - 450.0);
    else if( y < pY ) angle = (acos((x - pX) / floatsqroot((x - pX)*(x - pX) + (y - pY)*(y - pY))) - 90.0);

    if(x > pX) angle = (floatabs(floatabs(angle) + 180.0));
    else angle = (floatabs(angle) - 180.0);

    return SetDynamicActorFacingAngle(actorid, angle);
}

stock SetPlayerPosEx(playerid, Float:x, Float:y, Float:z)
{	
	PlayerTextDrawFade(playerid, Fades[playerid], 0x000000FF, 0x00000000, fade_type_box, 50, 5, 255, 0x00000000);
	Streamer_UpdateEx(playerid, x, y, z, GetPlayerVirtualWorld(playerid), GetPlayerInterior(playerid), STREAMER_TYPE_OBJECT);
	PauseAC(playerid);
    SetPlayerPos(playerid, x, y, z - 0.3);
	TogglePlayerControllable(playerid, false);
	ShowBoxMessage(playerid, "Please wait....", 3);
	SetTimerEx("PlayerPosTimer", 2500, false, "i", playerid);
    return 1;
}

function:PlayerPosTimer(playerid)
{
	TogglePlayerControllable(playerid, true);
	return 1;
}

stock ConvertHBEColor(value) 
{
    new color;
    if(value >= 90 && value <= 100)
        color = 0x15a014FF;
    else if(value >= 80 && value < 90)
        color = 0x1b9913FF;
    else if(value >= 70 && value < 80)
        color = 0x1a7f08FF;
    else if(value >= 60 && value < 70)
        color = 0x326305FF;
    else if(value >= 50 && value < 60)
        color = 0x375d04FF;
    else if(value >= 40 && value < 50)
        color = 0x603304FF;
    else if(value >= 30 && value < 40)
        color = 0xd72800FF;
    else if(value >= 10 && value < 30)
        color = 0xfb3508FF;
    else if(value >= 0 && value < 10)
        color = 0xFF0000FF;
    else 
        color = COLOR_WHITE;

    return color;
}

stock Repeat(const text[], count)
{
    new result[32];
    for (new i = 0; i < count; i++) 
	{
        strcat(result, text);
    }
    return result;
}