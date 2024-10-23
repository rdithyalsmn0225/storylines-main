//Client messages:
#define SendUsageMessage(%0,%1) \
	SendClientMessageEx(%0, COLOR_WHITE, "USAGE: "%1) 
	
#define SendErrorMessage(%0,%1) \
	SendClientMessageEx(%0, COLOR_RED, "ERROR: "%1)

#define SendInfoMessage(%0,%1) \
	SendClientMessageEx(%0, COLOR_INFO, "INFO:{FFFFFF} "%1) 

#define SendTipMessage(%0,%1) \
	SendClientMessageEx(%0, COLOR_DARKGREEN, "Tip: "%1) 

#define SendServerMessage(%0,%1) \
	SendClientMessageEx(%0, COLOR_INFO, ""%1) 

#define SendDebugMessage(%0)	\
	SendClientMessageToAllEx(COLOR_GREY, "Debug: "%0)

#define SendStreetMessage(%0)	\
	SendClientMessageToAllEx(COLOR_DARKGREEN, "[Word on the Streetz]: "%0)

#define forex(%0,%1) for(new %0 = 0; %0 < %1; %0++)	

stock SendClientMessageEx(playerid, color, const str[], {Float,_}:...)
{
	static
	    args,
	    start,
	    end,
	    string[156]
	;
	#emit LOAD.S.pri 8
	#emit STOR.pri args

	if (args > 12)
	{
		#emit ADDR.pri str
		#emit STOR.pri start

	    for (end = start + (args - 12); end > start; end -= 4)
		{
	        #emit LREF.pri end
	        #emit PUSH.pri
		}
		#emit PUSH.S str
		#emit PUSH.C 156
		#emit PUSH.C string
		#emit PUSH.C args
		#emit SYSREQ.C format

		SendClientMessage(playerid, color, string);

		#emit LCTRL 5
		#emit SCTRL 4
		#emit RETN
	}
	return SendClientMessage(playerid, color, str);
} // Credits to Emmet, South Central Roleplay

stock SendClientMessageToAllEx(color, const str[], {Float,_}:...)
{
	static
	    args,
	    start,
	    end,
	    string[144]
	;
	#emit LOAD.S.pri 8
	#emit STOR.pri args

	if (args > 8)
	{
		#emit ADDR.pri str
		#emit STOR.pri start

	    for (end = start + (args - 8); end > start; end -= 4)
		{
	        #emit LREF.pri end
	        #emit PUSH.pri
		}
		#emit PUSH.S str
		#emit PUSH.C 144
		#emit PUSH.C string

		#emit LOAD.pri args
		#emit ADD.C 4
		#emit PUSH.pri
		#emit SYSREQ.C format

        #emit LCTRL 5
		#emit SCTRL 4

		foreach (new i : Player) {
			SendClientMessage(i, color, string);
		}
		return 1;
	}
	return SendClientMessageToAll(color, str);
} // Credits to Emmet, South Central Roleplay

stock SendNearbyMessage(playerid, Float:radius, color, const str[], {Float,_}:...)
{
	static
	    args,
	    start,
	    end,
	    string[144]
	;
	#emit LOAD.S.pri 8
	#emit STOR.pri args

	if (args > 16)
	{
		#emit ADDR.pri str
		#emit STOR.pri start

	    for (end = start + (args - 16); end > start; end -= 4)
		{
	        #emit LREF.pri end
	        #emit PUSH.pri
		}
		#emit PUSH.S str
		#emit PUSH.C 144
		#emit PUSH.C string

		#emit LOAD.S.pri 8
		#emit CONST.alt 4
		#emit SUB
		#emit PUSH.pri

		#emit SYSREQ.C format
		#emit LCTRL 5
		#emit SCTRL 4

        foreach (new i : Player)
		{
			if (IsPlayerNearPlayer(i, playerid, radius)) {
  				SendClientMessage(i, color, string);
			}
		}
		return 1;
	}
	foreach (new i : Player)
	{
		if (IsPlayerNearPlayer(i, playerid, radius)) {
			SendClientMessage(i, color, str);
		}
	}
	return 1;
} // Credits to Emmet, South Central Roleplay

stock SendAdminMessage(level, const str[])
{
	new 
		newString[128]
	;
	
	format(newString, sizeof(newString), "[Staff #%i]: %s", level, str);
	
	foreach(new i : Player)
	{
		if(PlayerInfo[i][E_CHARACTER_TOGADMIN] == false && PlayerInfo[i][E_CHARACTER_ADMINDUTY] == true)
		{
			if(PlayerInfo[i][E_CHARACTER_ADMIN] >= level)
			{
				SendClientMessage(i, COLOR_RED, newString);
			}
		}
	}
	return 1;
}

stock SendAdminMessageEx(color, level, const str[], {Float,_}:...)
{
	static
	    args,
	    start,
	    end,
	    string[144]
	;
	#emit LOAD.S.pri 8
	#emit STOR.pri args

	if (args > 8)
	{
		#emit ADDR.pri str
		#emit STOR.pri start

	    for (end = start + (args - 8); end > start; end -= 4)
		{
	        #emit LREF.pri end
	        #emit PUSH.pri
		}
		#emit PUSH.S str
		#emit PUSH.C 144
		#emit PUSH.C string

		#emit LOAD.S.pri 8
		#emit ADD.C 4
		#emit PUSH.pri

		#emit SYSREQ.C format
		#emit LCTRL 5
		#emit SCTRL 4

        foreach (new i : Player)
		{
			if(PlayerInfo[i][E_CHARACTER_TOGADMIN] == false && PlayerInfo[i][E_CHARACTER_ADMINDUTY] == true)
			{
				if (PlayerInfo[i][E_CHARACTER_ADMIN] >= level) {
  					SendClientMessage(i, color, string);
				}
			}
		}
		return 1;
	}
	foreach (new i : Player)
	{
		if(PlayerInfo[i][E_CHARACTER_TOGADMIN] == false && PlayerInfo[i][E_CHARACTER_ADMINDUTY] == true)
		{
			if (PlayerInfo[i][E_CHARACTER_ADMIN] >= level) {
				SendClientMessage(i, color, str);
			}
		}
	}
	return 1;
}

stock SendFactionMessage(playerid, const str[], {Float,_}:...)
{
	static
	    args,
	    start,
	    end,
	    string[144]
	;
	#emit LOAD.S.pri 8
	#emit STOR.pri args

	if (args > 8)
	{
		#emit ADDR.pri str
		#emit STOR.pri start

	    for (end = start + (args - 8); end > start; end -= 4)
		{
	        #emit LREF.pri end
	        #emit PUSH.pri
		}
		#emit PUSH.S str
		#emit PUSH.C 144
		#emit PUSH.C string

		#emit LOAD.S.pri 8
		#emit ADD.C 4
		#emit PUSH.pri

		#emit SYSREQ.C format
		#emit LCTRL 5
		#emit SCTRL 4

        foreach (new i : Player)
		{
			if (PlayerInfo[i][E_CHARACTER_FACTION] == PlayerInfo[playerid][E_CHARACTER_FACTION]) {
				if(PlayerInfo[i][E_CHARACTER_TOGFMS] == false)
  				{ 
					SendClientMessage(i, COLOR_FCHAT, string);
				}
			}
		}
		return 1;
	}
	foreach (new i : Player)
	{
		if (PlayerInfo[i][E_CHARACTER_FACTION] == PlayerInfo[playerid][E_CHARACTER_FACTION]) {
			if(PlayerInfo[i][E_CHARACTER_TOGFMS] == false)
  			{ 
				SendClientMessage(i, COLOR_FCHAT, str);
			}
		}
	}
	return 1;
} // Credits to Emmet, South Central Roleplay

stock SendFactionMessageEx(playerid, color, const str[], {Float,_}:...)
{
	static
	    args,
	    start,
	    end,
	    string[144]
	;
	#emit LOAD.S.pri 8
	#emit STOR.pri args

	if (args > 8)
	{
		#emit ADDR.pri str
		#emit STOR.pri start

	    for (end = start + (args - 8); end > start; end -= 4)
		{
	        #emit LREF.pri end
	        #emit PUSH.pri
		}
		#emit PUSH.S str
		#emit PUSH.C 144
		#emit PUSH.C string

		#emit LOAD.S.pri 8
		#emit ADD.C 4
		#emit PUSH.pri

		#emit SYSREQ.C format
		#emit LCTRL 5
		#emit SCTRL 4

        foreach (new i : Player)
		{
			if (PlayerInfo[i][E_CHARACTER_FACTION] == PlayerInfo[playerid][E_CHARACTER_FACTION]) {
  				SendClientMessage(i, color, string);
			}
		}
		return 1;
	}
	foreach (new i : Player)
	{
		if (PlayerInfo[i][E_CHARACTER_FACTION] == PlayerInfo[playerid][E_CHARACTER_FACTION]) {
			SendClientMessage(i, color, str);
		}
	}
	return 1;
} // Credits to Emmet, South Central Roleplay

stock SendPoliceMessage(color, const str[], {Float,_}:...)
{
	static
	    args,
	    start,
	    end,
	    string[144]
	;
	#emit LOAD.S.pri 8
	#emit STOR.pri args

	if (args > 8)
	{
		#emit ADDR.pri str
		#emit STOR.pri start

	    for (end = start + (args - 8); end > start; end -= 4)
		{
	        #emit LREF.pri end
	        #emit PUSH.pri
		}
		#emit PUSH.S str
		#emit PUSH.C 144
		#emit PUSH.C string

		#emit LOAD.S.pri 8
		#emit ADD.C 4
		#emit PUSH.pri

		#emit SYSREQ.C format
		#emit LCTRL 5
		#emit SCTRL 4

        foreach (new i : Player)
		{
			if (FactionInfo[PlayerInfo[i][E_CHARACTER_FACTION]][E_FACTION_TYPE] == FACTION_TYPE_POLICE) {
  				SendClientMessage(i, color, string);
			}
		}
		return 1;
	}
	foreach (new i : Player)
	{
		if (FactionInfo[PlayerInfo[i][E_CHARACTER_FACTION]][E_FACTION_TYPE] == FACTION_TYPE_POLICE) {
			SendClientMessage(i, color, str);
		}
	}
	return 1;
}

stock SendMedicMessage(color, const str[], {Float,_}:...)
{
	static
	    args,
	    start,
	    end,
	    string[144]
	;
	#emit LOAD.S.pri 8
	#emit STOR.pri args

	if (args > 8)
	{
		#emit ADDR.pri str
		#emit STOR.pri start

	    for (end = start + (args - 8); end > start; end -= 4)
		{
	        #emit LREF.pri end
	        #emit PUSH.pri
		}
		#emit PUSH.S str
		#emit PUSH.C 144
		#emit PUSH.C string

		#emit LOAD.S.pri 8
		#emit ADD.C 4
		#emit PUSH.pri

		#emit SYSREQ.C format
		#emit LCTRL 5
		#emit SCTRL 4

        foreach (new i : Player)
		{
			if (FactionInfo[PlayerInfo[i][E_CHARACTER_FACTION]][E_FACTION_TYPE] == FACTION_TYPE_MEDICAL) {
  				SendClientMessage(i, color, string);
			}
		}
		return 1;
	}
	foreach (new i : Player)
	{
		if (FactionInfo[PlayerInfo[i][E_CHARACTER_FACTION]][E_FACTION_TYPE] == FACTION_TYPE_MEDICAL) {
			SendClientMessage(i, color, str);
		}
	}
	return 1;
}

stock SendUnauthMessage(playerid)
{
	return SendErrorMessage(playerid, "You aren't authorized to use this.");
}

stock SendTeleportMessage(playerid)
{
	return SendClientMessage(playerid, COLOR_GREY, "You were teleported."); 
}

//Local functions:
ProxDetectorEx(playerid, Float:max_range, color, const prefix[], const string[], showid = false, annonated=false, inverted=false, showtagcolor=false, autospacing=true, chat=false) 
{
	
	new prox[256];
	if(annonated) {
		if(chat) format(prox, sizeof(prox), "%s", string);
		else format(prox, sizeof(prox), "> %s", string);

		// remove "says"
		if(strfind(prox, "says:", true) != -1) {
			strdel(prox, 0, 5);
		}

		SetPlayerChatBubble(playerid, prox, color, 7.5, 3000 + (strlen(string) * 60));
	}

	new Float:pos_x, Float:pos_y, Float:pos_z, Float:range, Float:range_ratio, Float:max_ratio = 1.6, Float:range_with_ratio = (max_range * max_ratio), final_color;
	new clr_r, clr_g, clr_b, Float:color_r = float(color >> 24 & 0xFF), Float:color_g = float(color >> 16 & 0xFF), Float:color_b = float(color >> 8 & 0xFF);

	if(!GetPlayerPos(playerid, pos_x, pos_y, pos_z)) return 0;
 
	foreach(new i: Player) {
		range = GetPlayerDistanceFromPoint(i, pos_x, pos_y, pos_z);

		if (range > max_range || GetPlayerInterior(i) != GetPlayerInterior(playerid) ||  GetPlayerVirtualWorld(i) != GetPlayerVirtualWorld(playerid)) {
			continue ;
		}

		range_ratio = (range_with_ratio - range) / range_with_ratio;
		clr_r = floatround(range_ratio * color_r);
		clr_g = floatround(range_ratio * color_g);
		clr_b = floatround(range_ratio * color_b);
		final_color = (color & 0xFF) | (clr_b << 8) | (clr_g << 16) | (clr_r << 24);

		if(strlen(prefix) < 1) {
			if(autospacing) {
				if(showid) format(prox, sizeof(prox), "(%d) %s{%06x} %s", playerid, ReturnSettingsName(playerid, i, showtagcolor), (final_color >>> 8), string);
				else format(prox, sizeof(prox), "%s{%06x} %s", ReturnSettingsName(playerid, i, showtagcolor), (final_color >>> 8), string);

				if(inverted) {
					format(prox, sizeof(prox), "%s (( %s{%06x} ))", string, ReturnSettingsName(playerid, i, showtagcolor), (final_color >>> 8));
				}
			} else {
				if(showid) format(prox, sizeof(prox), "(%d) %s{%06x}%s", playerid, ReturnSettingsName(playerid, i, showtagcolor), (final_color >>> 8), string);
				else format(prox, sizeof(prox), "%s{%06x}%s", ReturnSettingsName(playerid, i, showtagcolor), (final_color >>> 8), string);

				if(inverted) {
					format(prox, sizeof(prox), "%s (( %s{%06x} ))", string, ReturnSettingsName(playerid, i, showtagcolor), (final_color >>> 8));
				}
			}
		} else {
			if(autospacing) {
				if(showid) format(prox, sizeof(prox), "%s (%d) %s{%06x} %s", prefix, playerid, ReturnSettingsName(playerid, i, showtagcolor), (final_color >>> 8), string);
				else format(prox, sizeof(prox), "%s %s{%06x} %s", prefix, ReturnSettingsName(playerid, i, showtagcolor), (final_color >>> 8), string);

				if(inverted) {
					format(prox, sizeof(prox), "%s %s (( %s{%06x} )) %s", prefix, string, ReturnSettingsName(playerid, i, showtagcolor), (final_color >>> 8));
				}
			} else {
				if(showid) format(prox, sizeof(prox), "%s (%d) %s{%06x}%s", prefix, playerid, ReturnSettingsName(playerid, i, showtagcolor), (final_color >>> 8), string);
				else format(prox, sizeof(prox), "%s %s{%06x}%s", prefix, ReturnSettingsName(playerid, i, showtagcolor), (final_color >>> 8), string);

				if(inverted) {
					format(prox, sizeof(prox), "%s %s (( %s{%06x} ))", prefix, string, ReturnSettingsName(playerid, i, showtagcolor), (final_color >>> 8));
				}
			}
		}

		SendClientMessageEx(i, final_color, prox);
	}
	return 1;
}

ProxDetectorXYZ(Float: pos_x, Float: pos_y, Float: pos_z, int, world, Float:max_range, color, const string[]) 
{

	new Float:range, Float:range_ratio, Float:max_ratio = 1.6, Float:range_with_ratio = (max_range * max_ratio) ;
	new clr_r, clr_g, clr_b, Float:color_r = float(color >> 24 & 0xFF), Float:color_g = float(color >> 16 & 0xFF), Float:color_b = float(color >> 8 & 0xFF);

	foreach (new i : Player) {

		range = GetPlayerDistanceFromPoint(i, pos_x, pos_y, pos_z);
		if (range > max_range || int != GetPlayerInterior(i) || world != GetPlayerVirtualWorld(i) ) {
			continue ;
		}

		range_ratio = (range_with_ratio - range) / range_with_ratio;
		clr_r = floatround(range_ratio * color_r);
		clr_g = floatround(range_ratio * color_g);
		clr_b = floatround(range_ratio * color_b);

		SendClientMessage(i, (color & 0xFF) | (clr_b << 8) | (clr_g << 16) | (clr_r << 24), string);
	}

	return 1;
}

SendPlayerChatText(playerid, text[], toid=INVALID_PLAYER_ID)
{
	if(PlayerInfo[playerid][E_CHARACTER_SPECTATE] != INVALID_PLAYER_ID)
	{
		SendErrorMessage(playerid, "You can't type while you're spectating.");
		return 0;
	}

	if (playerMakingCharacter[playerid] == true)
	{
		switch (playerCharacterStep[playerid])
		{
			case 1:
			{
				if(strlen(text) > MAX_PLAYER_NAME + 1 || strlen(text) < 3)
				{
					SendErrorMessage(playerid, "Your characters name must be at least 3 characters and no more than %i characters.", MAX_PLAYER_NAME);
					return 0;
				}
				
				if(!IsValidRoleplayName(text))
				{
					SendErrorMessage(playerid, "Please follow the Firstname_Lastname format to make your character."); 
					return 0;
				}
				
				foreach (new i : Player)
				{
					if(!strcmp(text, ReturnSettingsName(i, playerid)))
					{
						SendErrorMessage(playerid, "That character already exists. Please try again."); 
						return 0;
					}
				}
				
				new
					threadSearch[128]
				;
				
				format(playerCharactersName[playerid], 128, "%s", text); 
				
				mysql_format(ourConnection, threadSearch, sizeof(threadSearch), "SELECT char_dbid FROM characters WHERE char_name = '%e'", text);
				mysql_pquery(ourConnection, threadSearch, "Query_CreateCharacter", "i", playerid);
				
				return 0;
			}
			case 2:
			{
				if(strlen(text) > MAX_PLAYER_NAME + 1 || strlen(text) < 3)
				{
					SendErrorMessage(playerid, "Your characters street name must be at least 3 characters and no more than %i characters.", MAX_PLAYER_NAME);
					return 0;
				}
				
				foreach (new i : Player)
				{
					if(!strcmp(text, ReturnSettingsName(i, playerid)))
					{
						SendErrorMessage(playerid, "That characters street name already exists. Please try again."); 
						return 0;
					}
				}
				
				new
					threadSearch[128]
				;
				
				format(playerCharactersStreetName[playerid], 128, "%s", text); 
				
				mysql_format(ourConnection, threadSearch, sizeof(threadSearch), "SELECT char_dbid FROM characters WHERE char_masters = '%e'", text);
				mysql_pquery(ourConnection, threadSearch, "Query_CreateStreetNames", "ii", playerid, text);
				
				return 0;
			}
			case 3:
			{
				if(strlen(text) > 10)
				{
					SendErrorMessage(playerid, "Please follow the correct date format: 02/02/1960"); 
					return 0; 
				}
				
				new bool:keyFound = false;
				
				for(new i = 0; i < strlen(text); i++)
				{
					if(text[2] == '/' && text[5] == '/')
						continue; 
						
					if(text[i] < '0' || text[i] > '9')
						keyFound = true;
				}
				
				if(keyFound)
				{
					SendErrorMessage(playerid, "Please follow the correct date format: 02/02/1960"); 
					return 0; 
				}
				
				format(playerCharactersAge[playerid], 20, "%s", text);
				playerCharacterStep[playerid] = 4; 
				
				for (new i = 0; i < 20; i++){SendClientMessage(playerid, -1, " "); }
				
				new 
					string[128]
				;
		
				format (string, sizeof(string), "Your new characters date of birth will be: {B3C99E}%s", playerCharactersAge[playerid]);
				SendClientMessage(playerid, -1, string); 
				
				SendClientMessage(playerid, -1, " "); 
				SendClientMessage(playerid, -1, "This next step will require your characters origin details. ");
				SendClientMessage(playerid, -1, "Please provide your characters origin. Example: {B3C99E}Los santos");
				SendClientMessage(playerid, -1, "Press {B3C99E}'T'{ffffff} to inputtext for character creation.");
			
				return 0;
			}
			case 4:
			{
				if(strlen(text) < 3)
				{
					SendErrorMessage(playerid, "Your characters origin must be longer than 3 characters."); 
					return 0;
				}
				
				format(playerCharacterOrigin[playerid], 60, "%s", text);
				playerCharacterStep[playerid] = 5; 
				
				new 
					string[128]
				;
				
				for (new i = 0; i < 20; i++){SendClientMessage(playerid, -1, " "); }
				
				format (string, sizeof(string), "Your new characters origin will be: {B3C99E}%s", playerCharacterOrigin[playerid]);
				SendClientMessage(playerid, -1, string);
				
				SendClientMessage(playerid, -1, " "); 
				SendClientMessage(playerid, -1, "This next step will allow you the opportunity of writing a background story.");
				SendClientMessage(playerid, -1, "In no more than three (3) paragraphs, introduce your characters story."); 
				SendClientMessage(playerid, -1, "This step is {B3C99E}optional{FFFFFF} and not required. Type {B3C99E}\"skip\" {FFFFFF}to continue.");
				SendClientMessage(playerid, -1, "Press {B3C99E}'T'{ffffff} to inputtext for character creation.");

				ClearLines(playerid, 2);

				return 0;
			}
			case 5:
			{
				if(!strcmp(text, "skip"))
				{
					for (new i = 0; i < 20; i++){SendClientMessage(playerid, -1, " "); }
					playerCharacterStep[playerid] = 6; 
					
					SendClientMessage(playerid, -1, "You have chosen to skip your characters background story.");
					SendClientMessage(playerid, -1, "This concludes your characters creation.");
					
					SendClientMessage(playerid, -1, " "); 
					SendClientMessage(playerid, -1, "This next step will require your characters faction details. ");
					SendClientMessage(playerid, -1, "Please provide your characters faction. either type:");
					SendClientMessage(playerid, -1, "- Press \"LEFT\" or \"RIGHT\" to switch faction.");
					SendClientMessage(playerid, -1, "- Press \"SELECT\" to select.");		

					PlayerInfo[playerid][E_CHARACTER_FACTION] = 0;
					characterSelection[playerid] = true;
					playerMakingCharacter[playerid] = false;
					playerCharacterStep[playerid] = 0; 
					PlayerInfo[playerid][E_CHARACTER_SPAWNPOINT] = 0;
					new rand = random(sizeof(g_aHoodRatsSkins));
					PlayerInfo[playerid][E_CHARACTER_LASTSKIN] = g_aHoodRatsSkins[rand];
					ClearLines(playerid, 17); 
									
					SendInfoMessage(playerid, "You successfully created a new character. Please wait while your list is rebuilt.");
			
					new query[512];

					new fid; 
							
					fid = PlayerInfo[playerid][E_CHARACTER_FACTION];
									
					mysql_format(ourConnection, query, sizeof(query), "INSERT INTO characters (`master_dbid`, `char_name`, `char_masters`, `pAge`, `pOrigin`, `pFaction`, `pLastSkin`, `pStory`, `pStoryTwo`, `create_date`, `create_ip`, `pPhone`, pSpawnPoint, pLastPosX, pLastPosY, pLastPosZ) VALUES(%i, '%e', '%e', '%e', '%e', '%d', '%d', '%e', '%e', '%e', '%e', %i, %d, %f, %f, %f)", AccountInfo[playerid][E_MASTERS_DBID], playerCharactersName[playerid], playerCharactersStreetName[playerid], playerCharactersAge[playerid],
					playerCharacterOrigin[playerid], PlayerInfo[playerid][E_CHARACTER_FACTION], PlayerInfo[playerid][E_CHARACTER_LASTSKIN], playerCharacterStory[playerid][0], playerCharacterStory[playerid][1], ReturnDate(), ReturnIP(playerid), 94000+random(6999), PlayerInfo[playerid][E_CHARACTER_SPAWNPOINT], FactionInfo[fid][E_FACTION_SPAWN][0], FactionInfo[fid][E_FACTION_SPAWN][1], FactionInfo[fid][E_FACTION_SPAWN][2]);				
					mysql_pquery(ourConnection, query); 
									
					SetTimerEx("RefreshCharacters", 1000, false, "i", playerid);
					return 0;
				}
				
				new string[128], bool:foundSpace = false, idx = 0; 
				
				for (new i = 0; i < 2; i ++)
				{
					if(isnull(playerCharacterStory[playerid][i]))
					{
						foundSpace = true;
						idx = i;
						break; 
					}
				}
				
				if (foundSpace)
				{
					SendClientMessage(playerid, COLOR_YELLOW, "[Background Story]");
					format(playerCharacterStory[playerid][idx], 90, "%s", text);
					SendClientMessage(playerid, -1, playerCharacterStory[playerid][idx]); 
				}
				else
				{
					for (new i = 0; i < 20; i++){SendClientMessage(playerid, -1, " "); }
				
					format (string, sizeof(string), "Your succesfully introduce characters story.");
					SendClientMessage(playerid, -1, string);
					
					SendClientMessage(playerid, -1, " "); 
					SendClientMessage(playerid, -1, "This next step will require your characters faction details. ");
					SendClientMessage(playerid, -1, "Please provide your characters faction. either type:");
					SendClientMessage(playerid, -1, "- Press \"LEFT\" or \"RIGHT\" to switch faction.");
					SendClientMessage(playerid, -1, "- Press \"SELECT\" to select.");
					//playerCharacterStep[playerid] = 6; 
					
					//if(PlayerInfo[playerid][E_CHARACTER_SELECTCHAR] == -1) 
					//{
					//	PlayerInfo[playerid][E_CHARACTER_SELECTCHAR] = SELECT_HOODRATS;
					//}
					//ShowCharacterSelection(playerid);

					PlayerInfo[playerid][E_CHARACTER_FACTION] = 0;
					characterSelection[playerid] = true;
					playerMakingCharacter[playerid] = false;
					playerCharacterStep[playerid] = 0; 
					PlayerInfo[playerid][E_CHARACTER_SPAWNPOINT] = 0;
					new rand = random(sizeof(g_aHoodRatsSkins));
					PlayerInfo[playerid][E_CHARACTER_LASTSKIN] = g_aHoodRatsSkins[rand];
					ClearLines(playerid, 17); 
									
					SendInfoMessage(playerid, "You successfully created a new character. Please wait while your list is rebuilt.");
									
					new query[512];

					new fid; 
							
					fid = PlayerInfo[playerid][E_CHARACTER_FACTION];
									
					mysql_format(ourConnection, query, sizeof(query), "INSERT INTO characters (`master_dbid`, `char_name`, `char_masters`, `pAge`, `pOrigin`, `pFaction`, `pLastSkin`, `pStory`, `pStoryTwo`, `create_date`, `create_ip`, `pPhone`, pSpawnPoint, pLastPosX, pLastPosY, pLastPosZ) VALUES(%i, '%e', '%e', '%e', '%e', '%d', '%d', '%e', '%e', '%e', '%e', %i, %d, %f, %f, %f)", AccountInfo[playerid][E_MASTERS_DBID], playerCharactersName[playerid], playerCharactersStreetName[playerid], playerCharactersAge[playerid],
					playerCharacterOrigin[playerid], PlayerInfo[playerid][E_CHARACTER_FACTION], PlayerInfo[playerid][E_CHARACTER_LASTSKIN], playerCharacterStory[playerid][0], playerCharacterStory[playerid][1], ReturnDate(), ReturnIP(playerid), 94000+random(6999), PlayerInfo[playerid][E_CHARACTER_SPAWNPOINT], FactionInfo[fid][E_FACTION_SPAWN][0], FactionInfo[fid][E_FACTION_SPAWN][1], FactionInfo[fid][E_FACTION_SPAWN][2]);				
					mysql_pquery(ourConnection, query); 
									
					SetTimerEx("RefreshCharacters", 1000, false, "i", playerid);
				}
				return 0;
			}
			case 6:
			{
				if(GetPlayerState(playerid) != PLAYER_STATE_SPECTATING) 
				{
					TogglePlayerControllable(playerid, true);
		    		PlayerInfo[playerid][E_CHARACTER_SELECTCHAR] = -1;
				}
				return 0;
			}
		}

		if(!AccountInfo[playerid][E_MASTERS_LOGGED] || PlayerInfo[playerid][E_CHARACTER_TUTORIALSTEP] && !PlayerInfo[playerid][E_CHARACTER_TUTORIAL])
		{
			return SendErrorMessage(playerid, "You can't talk when you aren't login.");
		}
		return 0;
	}

    if(GetPlayerTeam(playerid) != PLAYER_STATE_ALIVE)
	{
		return SendErrorMessage(playerid, "You can't talk when you aren't alive.");
	}

	new vehicleid = GetPlayerVehicleID(playerid);
	new string[256];

	if(PlayerInfo[playerid][E_CHARACTER_PHONELINE] != INVALID_PLAYER_ID && !PlayerInfo[playerid][E_CHARACTER_CALL])
	{
		if(PlayerInfo[playerid][E_CHARACTER_PHONELINE] == 911)
		{
			format(string, sizeof(string), "says (phone): %s", text);
			ProxDetectorEx(playerid, 10.0, 0xDEDEDEFF, "", string, .showtagcolor=true, .annonated=true, .chat=true);

			switch(Player911Type[playerid])
			{
				case 0: // 0 service, 1 - emergency, 2 - location
				{
					if(strfind(text, "Police", true) != -1 || strfind(text, "Cops", true) != -1 || strfind(text, "Law enforcement", true) != -1)
					{
						format(Player911Text[playerid][0], 128, "%s", text);
							
						SendClientMessage(playerid, COLOR_YELLOW, "911 Operator says: You're being transferred to the police. What's your emergency?"); 
						Player911Type[playerid] = 1; 
					}
					else if(strfind(text, "Medics", true) != -1 || strfind(text, "Paramedics", true) != -1 || strfind(text, "Ambulance", true) != -1 || strfind(text, "Fire", true) != -1)
					{
						format(Player911Text[playerid][0], 128, "%s", text);
							
						SendClientMessage(playerid, COLOR_YELLOW, "911 Operator says: You're being transferred to the fire department. What's your emergency?"); 
						Player911Type[playerid] = 2;
					}
					else SendClientMessage(playerid, COLOR_YELLOW, "911 Operator says: Repeat that, please."); 
				}
				case 1: //Police input;
				{
					if(strlen(text) < 3)
						return SendErrorMessage(playerid, "Please input actual text."); 
							
					format(Player911Text[playerid][1], 128, "%s", text);
						
					SendClientMessage(playerid, COLOR_YELLOW, "911 Operator says: What's your location?"); 
					Player911Type[playerid] = 911; 
				}
				case 911: //Police;
				{
					if(strlen(text) < 3)
						return SendErrorMessage(playerid, "Please input actual text."); 
							
					format(Player911Text[playerid][2], 128, "%s", text);
					SendClientMessage(playerid, COLOR_YELLOW, "911 Operator says: Police units were dispatched."); 
						
					Send911Message(playerid, 911); 
				}
				case 2: //Medic input;
				{
					if(strlen(text) < 3)
						return SendErrorMessage(playerid, "Please input actual text."); 
							
					format(Player911Text[playerid][1], 128, "%s", text);
						
					SendClientMessage(playerid, COLOR_YELLOW, "911 Operator says: What's your location?"); 
					Player911Type[playerid] = 811; 
				}
				case 811: // Medic;
				{
					if(strlen(text) < 3)
						return SendErrorMessage(playerid, "Please input actual text."); 
							
					format(Player911Text[playerid][2], 128, "%s", text);
					SendClientMessage(playerid, COLOR_YELLOW, "911 Operator says: Medical units were dispatched."); 
						
					Send911Message(playerid, 811); 
				}
			}
		}
		else
		{
			if (vehicleid && IsPlayerInAnyVehicle(playerid) && IsWindowedVehicle(vehicleid)) 
			{
				if (vehicleid != INVALID_VEHICLE_ID ) 
				{
					if (VehicleInfo[vehicleid][E_VEHICLE_WINDOWS]) 
					{
						foreach(new targetid: Player) 
						{
							if (GetPlayerVehicleID(targetid) == GetPlayerVehicleID(playerid)) {

								if (PlayerInfo[playerid][E_CHARACTER_PHONELINE] != INVALID_PLAYER_ID) {
									format ( string, sizeof ( string ), "(Windows Closed) %s{DEDEDE} says (phone): %s", ReturnSettingsName(playerid, targetid, true), text ) ;
								}
								else {

									if (toid != INVALID_PLAYER_ID) {
										if(playerid == toid) {
											format (string, sizeof (string), "(Windows Closed) %s says (to self): %s",  ReturnSettingsName(playerid, targetid, true), text ) ;
										} 
										else format (string, sizeof (string), "(Windows Closed) %s says (to %s): %s",  ReturnSettingsName(playerid, targetid, true), ReturnSettingsName(toid, targetid, true), text ) ;
									}

									else format (string, sizeof(string), "(Windows Closed) %s{DEDEDE} says: %s",  ReturnSettingsName(playerid, targetid, true), text ) ;
								}

								SendClientMessageEx(targetid, 0xDEDEDEFF, string);
							}
						}
					}
					else if (!VehicleInfo[vehicleid][E_VEHICLE_WINDOWS]) 
					{
						if (PlayerInfo[playerid][E_CHARACTER_PHONELINE] == INVALID_PLAYER_ID) 
						{
							if (toid != INVALID_PLAYER_ID) {
								format(string, sizeof(string), "says (to %s): %s", ReturnMixedName(toid), text);
								ProxDetectorEx(playerid, 15.0, 0xDEDEDEFF, "(Windows Open)", string, .showtagcolor=true, .annonated=true, .chat=true);
							} 
							else 
							{
								format(string, sizeof(string), "says: %s", text);
								ProxDetectorEx(playerid, 15.0, 0xDEDEDEFF, "(Windows Open)", string, .showtagcolor=true, .annonated=true, .chat=true);
							}
						}

						else 
						{
							format(string, sizeof(string), "says (phone): %s", text);
							ProxDetectorEx(playerid, 15.0, 0xDEDEDEFF, "(Windows Open)", string, .showtagcolor=true, .annonated=true, .chat=true);
						}
					}
				}
			}
			else
			{
				format(string, sizeof(string), "says (phone): %s", text);

				if ( GetPlayerVirtualWorld(playerid) == 0) {
					ProxDetectorEx(playerid, 15.0, 0xDEDEDEFF, "", string, .showtagcolor=true, .annonated=true, .chat=true);
				}
				else ProxDetectorEx(playerid, 10.0, 0xDEDEDEFF, "", string, .showtagcolor=true, .annonated=true, .chat=true);
			}
		}
	}
	else 
	{
		new Float:range = 15.0;

		if (PlayerInfo[playerid][E_CHARACTER_PRISON]) range = 7.5;
		else if (GetPlayerVirtualWorld(playerid) != 0) range = 10.0;

		if(toid != INVALID_PLAYER_ID) 
		{
			format(string, sizeof(string), "says (to %s): %s", ReturnMixedName(toid), text);
			ProxDetectorEx(playerid, range, 0xDEDEDEFF, "", string, .showtagcolor=true, .annonated=true, .chat=true);
		} 
		else 
		{
			format(string, sizeof(string), "says: %s", text);
			ProxDetectorEx(playerid, range, 0xDEDEDEFF, "", string, .showtagcolor=true, .annonated=true, .chat=true);
			ChatAnimation(playerid, strlen(text));
		}
	}
	return 1;
}