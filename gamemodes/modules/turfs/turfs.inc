//Turf system
ShowTurfsOnMap(playerid, enable)
{
	for(new i = 0; i < MAX_TURFS; i ++)
	{
	    if(TurfInfo[i][E_FACTION_TURFEXISTS])
	    {
	    	if(enable)
			{
				GangZoneShowForPlayer(playerid, TurfInfo[i][E_FACTION_TURFZONE], GetTurfColor(i));

				if(TurfInfo[i][E_FACTION_TURFCAPTURER] == INVALID_PLAYER_ID)
				{
	                GangZoneStopFlashForPlayer(playerid, TurfInfo[i][E_FACTION_TURFZONE]);
				}
				else
				{
				    if(PlayerInfo[TurfInfo[i][E_FACTION_TURFCAPTURER]][E_CHARACTER_FACTION] == -1 && ReturnFactionType(TurfInfo[i][E_FACTION_TURFCAPTURER]) == FACTION_TYPE_POLICE)
				        GangZoneFlashForPlayer(playerid, TurfInfo[i][E_FACTION_TURFZONE], 0x0000000A);
					else if(PlayerInfo[TurfInfo[i][E_FACTION_TURFCAPTURER]][E_CHARACTER_FACTION] >= 0)
						GangZoneFlashForPlayer(playerid, TurfInfo[i][E_FACTION_TURFZONE], (FactionInfo[PlayerInfo[TurfInfo[i][E_FACTION_TURFCAPTURER]][E_CHARACTER_FACTION]][E_FACTION_COLORHEX] & ~0xff) + 0x0A);
				}
			}
			else
			{
			   	GangZoneHideForPlayer(playerid, TurfInfo[i][E_FACTION_TURFZONE]);
			}
		}
	}
	return 1;
}

stock IsPlayerNearTurf(playerid)
{
	for(new i; i < MAX_TURFS; i ++)
	{
		if(TurfInfo[i][E_FACTION_TURFEXISTS] && IsPlayerInDynamicArea(playerid, TurfInfo[i][E_FACTION_TURFAREA]))
		{
		    return i;
		}
	}

	return -1;
}

GetTurfColor(turfid)
{
	if(TurfInfo[turfid][E_FACTION_TURFGANG] >= 0)
	{
	    return (FactionInfo[TurfInfo[turfid][E_FACTION_TURFGANG]][E_FACTION_COLORHEX] & ~0xAA) + 0x0A;
	}

	return 0xAAAAAA0A;
}

ReloadTurf(turfid)
{
	if(TurfInfo[turfid][E_FACTION_TURFEXISTS])
	{
	    DestroyDynamicArea(TurfInfo[turfid][E_FACTION_TURFAREA]);
	    GangZoneDestroy(TurfInfo[turfid][E_FACTION_TURFZONE]);

	    TurfInfo[turfid][E_FACTION_TURFAREA] = CreateDynamicRectangle(TurfInfo[turfid][E_FACTION_TURFMINX], TurfInfo[turfid][E_FACTION_TURFMINY], TurfInfo[turfid][E_FACTION_TURFMAXX], TurfInfo[turfid][E_FACTION_TURFMAXY]);
	    TurfInfo[turfid][E_FACTION_TURFZONE] = GangZoneCreate(TurfInfo[turfid][E_FACTION_TURFMINX], TurfInfo[turfid][E_FACTION_TURFMINY], TurfInfo[turfid][E_FACTION_TURFMAXX], TurfInfo[turfid][E_FACTION_TURFMAXY]);
		
		foreach(new i : Player)
	    {
	        ShowTurfsOnMap(i, true);
		}
	}
}


function:InsertGangTurf(playerid, turfid, type, Float:minx, Float:miny, Float:maxx, Float:maxy, Float:height)
{
	strcat(TurfInfo[turfid][E_FACTION_TURFCAPTUREDBY], "No-one", MAX_PLAYER_NAME);

	TurfInfo[turfid][E_FACTION_TURFEXISTS] = 1;
	TurfInfo[turfid][E_FACTION_TURFGANG] = -1;
	TurfInfo[turfid][E_FACTION_TURFTYPE] = type;
	TurfInfo[turfid][E_FACTION_TURFMINX] = minx;
	TurfInfo[turfid][E_FACTION_TURFMINY] = miny;
	TurfInfo[turfid][E_FACTION_TURFMAXX] = maxx;
	TurfInfo[turfid][E_FACTION_TURFMAXY] = maxy;
	TurfInfo[turfid][E_FACTION_TURFHEIGHT] = height;
	TurfInfo[turfid][E_FACTION_TURFZONE] = -1;
	TurfInfo[turfid][E_FACTION_TURFAREA] = -1;
	TurfInfo[turfid][E_FACTION_TURFTIME] = 0;
	TurfInfo[turfid][E_FACTION_TURFCAPTURER] = INVALID_PLAYER_ID;

	TurfInfo[turfid][E_FACTION_TURFDRUGSACTOR] = INVALID_ACTOR_ID;
    TurfInfo[turfid][E_FACTION_TURFDRUGSTYPE] = 0;
    TurfInfo[turfid][E_FACTION_TURFDRUGS] = 0;
    TurfInfo[turfid][E_FACTION_TURFDRUGSEXISTS] = 0;

	TurfInfo[turfid][E_FACTION_TURFGANGTYPE][0] = 0;
    TurfInfo[turfid][E_FACTION_TURFGANGTYPE][1] = 0;
    TurfInfo[turfid][E_FACTION_TURFGANGTYPE][2] = 0;
    TurfInfo[turfid][E_FACTION_TURFGANGTYPE][3] = 0;
    TurfInfo[turfid][E_FACTION_TURFGANGTYPE][4] = 0;
    TurfInfo[turfid][E_FACTION_TURFGANGTYPE][5] = 0;
    TurfInfo[turfid][E_FACTION_TURFGANGTYPE][6] = 0;
    TurfInfo[turfid][E_FACTION_TURFGANGTYPE][7] = 0;
    TurfInfo[turfid][E_FACTION_TURFGANGTYPE][8] = 0;

	TurfInfo[turfid][E_FACTION_TURFDBID] = cache_insert_id();

	ReloadTurf(turfid);
	new str[128];
	format(str, sizeof(str), "%s has created turf ID %d.", ReturnSettingsName(playerid, playerid), turfid);
	SendAdminMessage(4, str);
	return 1;
}

function:Query_LoadTurf()
{
	if(!cache_num_rows())
		return printf("[SERVER]: No turf were loaded from \"%s\" database...", SQL_DATABASE);
		
	new rows, fields;

	cache_get_row_count(rows);
	cache_get_field_count(fields);

	for(new i = 0; i < rows && i < MAX_TURFS; i ++)
	{
	    cache_get_value_name_int(i, "id", TurfInfo[i][E_FACTION_TURFDBID]);
        cache_get_value_name(i, "capturedby", TurfInfo[i][E_FACTION_TURFCAPTUREDBY], MAX_PLAYER_NAME);
        cache_get_value_name_int(i, "capturedgang", TurfInfo[i][E_FACTION_TURFGANG]);
        cache_get_value_name_int(i, "type", TurfInfo[i][E_FACTION_TURFTYPE]);
        cache_get_value_name_float(i, "min_x", TurfInfo[i][E_FACTION_TURFMINX]);
        cache_get_value_name_float(i, "min_y", TurfInfo[i][E_FACTION_TURFMINY]);
        cache_get_value_name_float(i, "max_x", TurfInfo[i][E_FACTION_TURFMAXX]);
        cache_get_value_name_float(i, "max_y", TurfInfo[i][E_FACTION_TURFMAXY]);
        cache_get_value_name_float(i, "height", TurfInfo[i][E_FACTION_TURFHEIGHT]);

		cache_get_value_name_int(i, "gsf", TurfInfo[i][E_FACTION_TURFGANGTYPE][0]);
        cache_get_value_name_int(i, "sbf", TurfInfo[i][E_FACTION_TURFGANGTYPE][1]);
        cache_get_value_name_int(i, "tdf", TurfInfo[i][E_FACTION_TURFGANGTYPE][2]);
        cache_get_value_name_int(i, "ktb", TurfInfo[i][E_FACTION_TURFGANGTYPE][3]);
        cache_get_value_name_int(i, "rhb", TurfInfo[i][E_FACTION_TURFGANGTYPE][4]);
        cache_get_value_name_int(i, "fyb", TurfInfo[i][E_FACTION_TURFGANGTYPE][5]);
        cache_get_value_name_int(i, "tdb", TurfInfo[i][E_FACTION_TURFGANGTYPE][6]);
        cache_get_value_name_int(i, "lsv", TurfInfo[i][E_FACTION_TURFGANGTYPE][7]);
        cache_get_value_name_int(i, "vla", TurfInfo[i][E_FACTION_TURFGANGTYPE][8]);
        cache_get_value_name_int(i, "point", TurfInfo[i][E_FACTION_TURFGANGTYPE][9]);

        cache_get_value_name_float(i, "drugsx", TurfInfo[i][E_FACTION_TURFDRUGSX]);
        cache_get_value_name_float(i, "drugsy", TurfInfo[i][E_FACTION_TURFDRUGSY]);
        cache_get_value_name_float(i, "drugsz", TurfInfo[i][E_FACTION_TURFDRUGSZ]);
        cache_get_value_name_float(i, "drugsa", TurfInfo[i][E_FACTION_TURFDRUGSA]);

        TurfInfo[i][E_FACTION_TURFZONE] = -1;
        TurfInfo[i][E_FACTION_TURFAREA] = -1;
        TurfInfo[i][E_FACTION_TURFTIME] = 0;
		TurfInfo[i][E_FACTION_TURFCAPTURER] = INVALID_PLAYER_ID;
        TurfInfo[i][E_FACTION_TURFEXISTS] = 1;
        
        TurfInfo[i][E_FACTION_TURFDRUGSACTOR] = INVALID_ACTOR_ID;
        TurfInfo[i][E_FACTION_TURFDRUGSTYPE] = 0;
        TurfInfo[i][E_FACTION_TURFDRUGS] = 0;
        TurfInfo[i][E_FACTION_TURFDRUGSEXISTS] = 0;

        ReloadTurf(i);
	}
	printf("[SERVER]: %i turf were loaded from \"%s\" database...", rows, SQL_DATABASE);
	return 1;
}

function:Query_LoadGlobalTurf()
{
	if(!cache_num_rows())
		return printf("[SERVER]: No turf global timer were loaded from \"%s\" database...", SQL_DATABASE);

    cache_get_value_name_int(0, "Turfwars", GlobalTurf);
    cache_get_value_name_int(0, "Start", GlobalTurfStart);
    cache_get_value_name_int(0, "End", GlobalTurfEnd);
	printf("[SERVER]: turf global timer were loaded from \"%s\" database...", SQL_DATABASE);
	return 1;
}

stock TurfsPoints(playerid, turfid)
{
	new queryBuffer[1024];

	if(PlayerInfo[playerid][E_CHARACTER_FACTION] == 3)
	{
		TurfInfo[turfid][E_FACTION_TURFGANGTYPE][0]++;
		mysql_format(ourConnection, queryBuffer, sizeof(queryBuffer), "UPDATE turfs SET gsf = %d WHERE id = %i", TurfInfo[turfid][E_FACTION_TURFGANGTYPE][0], turfid);
		mysql_pquery(ourConnection, queryBuffer);
	}
	else if(PlayerInfo[playerid][E_CHARACTER_FACTION] == 6)
	{
		TurfInfo[turfid][E_FACTION_TURFGANGTYPE][1]++;
		mysql_format(ourConnection, queryBuffer, sizeof(queryBuffer), "UPDATE turfs SET sbf = %d WHERE id = %i", TurfInfo[turfid][E_FACTION_TURFGANGTYPE][1], turfid);
		mysql_pquery(ourConnection, queryBuffer);
	}
	else if(PlayerInfo[playerid][E_CHARACTER_FACTION] == 10)
	{
		TurfInfo[turfid][E_FACTION_TURFGANGTYPE][2]++;
		mysql_format(ourConnection, queryBuffer, sizeof(queryBuffer), "UPDATE turfs SET tdf = %d WHERE id = %i", TurfInfo[turfid][E_FACTION_TURFGANGTYPE][2], turfid);
		mysql_pquery(ourConnection, queryBuffer);
	}
	else if(PlayerInfo[playerid][E_CHARACTER_FACTION] == 4)
	{
		TurfInfo[turfid][E_FACTION_TURFGANGTYPE][3]++;
		mysql_format(ourConnection, queryBuffer, sizeof(queryBuffer), "UPDATE turfs SET ktb = %d WHERE id = %i", TurfInfo[turfid][E_FACTION_TURFGANGTYPE][3], turfid);
		mysql_pquery(ourConnection, queryBuffer);
	}
	else if(PlayerInfo[playerid][E_CHARACTER_FACTION] == 5)
	{
		TurfInfo[turfid][E_FACTION_TURFGANGTYPE][4]++;
		mysql_format(ourConnection, queryBuffer, sizeof(queryBuffer), "UPDATE turfs SET rhb = %i WHERE id = %i", TurfInfo[turfid][E_FACTION_TURFGANGTYPE][4], turfid);
		mysql_pquery(ourConnection, queryBuffer);
	}
	else if(PlayerInfo[playerid][E_CHARACTER_FACTION] == 9)
	{
		TurfInfo[turfid][E_FACTION_TURFGANGTYPE][5]++;
		mysql_format(ourConnection, queryBuffer, sizeof(queryBuffer), "UPDATE turfs SET fyb = %i WHERE id = %i", TurfInfo[turfid][E_FACTION_TURFGANGTYPE][5], turfid);
		mysql_pquery(ourConnection, queryBuffer);
	}
	else if(PlayerInfo[playerid][E_CHARACTER_FACTION] == 11)
	{
		TurfInfo[turfid][E_FACTION_TURFGANGTYPE][6]++;
		mysql_format(ourConnection, queryBuffer, sizeof(queryBuffer), "UPDATE turfs SET tdb = %i WHERE id = %i", TurfInfo[turfid][E_FACTION_TURFGANGTYPE][6], turfid);
		mysql_pquery(ourConnection, queryBuffer);
	}
	else if(PlayerInfo[playerid][E_CHARACTER_FACTION] == 7)
	{
		TurfInfo[turfid][E_FACTION_TURFGANGTYPE][7]++;
		mysql_format(ourConnection, queryBuffer, sizeof(queryBuffer), "UPDATE turfs SET lsv = %i WHERE id = %i", TurfInfo[turfid][E_FACTION_TURFGANGTYPE][7], turfid);
		mysql_pquery(ourConnection, queryBuffer);
	}
	else if(PlayerInfo[playerid][E_CHARACTER_FACTION] == 8)
	{
		TurfInfo[turfid][E_FACTION_TURFGANGTYPE][8]++;
		mysql_format(ourConnection, queryBuffer, sizeof(queryBuffer), "UPDATE turfs SET vla = %d WHERE id = %i", TurfInfo[turfid][E_FACTION_TURFGANGTYPE][8], turfid);
		mysql_pquery(ourConnection, queryBuffer);
	}

	return 1;
}

stock TurfsPointsMinus(playerid, turfid)
{
	new queryBuffer[1024];

	if(PlayerInfo[playerid][E_CHARACTER_FACTION] == 3)
	{
		TurfInfo[turfid][E_FACTION_TURFGANGTYPE][0]--;
		mysql_format(ourConnection, queryBuffer, sizeof(queryBuffer), "UPDATE turfs SET gsf = %d WHERE id = %i", TurfInfo[turfid][E_FACTION_TURFGANGTYPE][0], turfid);
		mysql_pquery(ourConnection, queryBuffer);
	}
	else if(PlayerInfo[playerid][E_CHARACTER_FACTION] == 6)
	{
		TurfInfo[turfid][E_FACTION_TURFGANGTYPE][1]--;
		mysql_format(ourConnection, queryBuffer, sizeof(queryBuffer), "UPDATE turfs SET sbf = %d WHERE id = %i", TurfInfo[turfid][E_FACTION_TURFGANGTYPE][1], turfid);
		mysql_pquery(ourConnection, queryBuffer);
	}
	else if(PlayerInfo[playerid][E_CHARACTER_FACTION] == 10)
	{
		TurfInfo[turfid][E_FACTION_TURFGANGTYPE][2]--;
		mysql_format(ourConnection, queryBuffer, sizeof(queryBuffer), "UPDATE turfs SET tdf = %d WHERE id = %i", TurfInfo[turfid][E_FACTION_TURFGANGTYPE][2], turfid);
		mysql_pquery(ourConnection, queryBuffer);
	}
	else if(PlayerInfo[playerid][E_CHARACTER_FACTION] == 4)
	{
		TurfInfo[turfid][E_FACTION_TURFGANGTYPE][3]--;
		mysql_format(ourConnection, queryBuffer, sizeof(queryBuffer), "UPDATE turfs SET ktb = %d WHERE id = %i", TurfInfo[turfid][E_FACTION_TURFGANGTYPE][3], turfid);
		mysql_pquery(ourConnection, queryBuffer);
	}
	else if(PlayerInfo[playerid][E_CHARACTER_FACTION] == 5)
	{
		TurfInfo[turfid][E_FACTION_TURFGANGTYPE][4]--;
		mysql_format(ourConnection, queryBuffer, sizeof(queryBuffer), "UPDATE turfs SET rhb = %i WHERE id = %i", TurfInfo[turfid][E_FACTION_TURFGANGTYPE][4], turfid);
		mysql_pquery(ourConnection, queryBuffer);
	}
	else if(PlayerInfo[playerid][E_CHARACTER_FACTION] == 9)
	{
		TurfInfo[turfid][E_FACTION_TURFGANGTYPE][5]--;
		mysql_format(ourConnection, queryBuffer, sizeof(queryBuffer), "UPDATE turfs SET fyb = %i WHERE id = %i", TurfInfo[turfid][E_FACTION_TURFGANGTYPE][5], turfid);
		mysql_pquery(ourConnection, queryBuffer);
	}
	else if(PlayerInfo[playerid][E_CHARACTER_FACTION] == 11)
	{
		TurfInfo[turfid][E_FACTION_TURFGANGTYPE][6]--;
		mysql_format(ourConnection, queryBuffer, sizeof(queryBuffer), "UPDATE turfs SET tdb = %i WHERE id = %i", TurfInfo[turfid][E_FACTION_TURFGANGTYPE][6], turfid);
		mysql_pquery(ourConnection, queryBuffer);
	}
	else if(PlayerInfo[playerid][E_CHARACTER_FACTION] == 7)
	{
		TurfInfo[turfid][E_FACTION_TURFGANGTYPE][7]--;
		mysql_format(ourConnection, queryBuffer, sizeof(queryBuffer), "UPDATE turfs SET lsv = %i WHERE id = %i", TurfInfo[turfid][E_FACTION_TURFGANGTYPE][7], turfid);
		mysql_pquery(ourConnection, queryBuffer);
	}
	else if(PlayerInfo[playerid][E_CHARACTER_FACTION] == 8)
	{
		TurfInfo[turfid][E_FACTION_TURFGANGTYPE][8]--;
		mysql_format(ourConnection, queryBuffer, sizeof(queryBuffer), "UPDATE turfs SET vla = %d WHERE id = %i", TurfInfo[turfid][E_FACTION_TURFGANGTYPE][8], turfid);
		mysql_pquery(ourConnection, queryBuffer);
	}

	return 1;
}

stock TurfCaptured(playerid, turfid)
{
	new queryBuffer[1024];
	if(TurfInfo[turfid][E_FACTION_TURFGANGTYPE][0] > TurfInfo[turfid][E_FACTION_TURFGANGTYPE][1] && TurfInfo[turfid][E_FACTION_TURFGANGTYPE][0] > TurfInfo[turfid][E_FACTION_TURFGANGTYPE][2] && TurfInfo[turfid][E_FACTION_TURFGANGTYPE][0] > TurfInfo[turfid][E_FACTION_TURFGANGTYPE][3] && TurfInfo[turfid][E_FACTION_TURFGANGTYPE][0] > TurfInfo[turfid][E_FACTION_TURFGANGTYPE][4]
		&& TurfInfo[turfid][E_FACTION_TURFGANGTYPE][0] > TurfInfo[turfid][E_FACTION_TURFGANGTYPE][5] && TurfInfo[turfid][E_FACTION_TURFGANGTYPE][0] > TurfInfo[turfid][E_FACTION_TURFGANGTYPE][6] && TurfInfo[turfid][E_FACTION_TURFGANGTYPE][0] > TurfInfo[turfid][E_FACTION_TURFGANGTYPE][7] && TurfInfo[turfid][E_FACTION_TURFGANGTYPE][0] > TurfInfo[turfid][E_FACTION_TURFGANGTYPE][8]
		&& TurfInfo[turfid][E_FACTION_TURFGANGTYPE][0] > TurfInfo[turfid][E_FACTION_TURFGANGTYPE][9])
	{
		GetPlayerName(playerid, TurfInfo[turfid][E_FACTION_TURFCAPTUREDBY], MAX_PLAYER_NAME);

		TurfInfo[turfid][E_FACTION_TURFGANG] = 3;

		ReloadTurf(turfid);
		new str[128];
		format(str, sizeof(str), "Street's News: %s has been take over by %s for %s", ReturnLocationStreet(playerid), ReturnSettingsName(playerid, playerid), ReturnFactionName(playerid));
		SendClientMessageToAll(COLOR_POINT, str);
	}
	else if(TurfInfo[turfid][E_FACTION_TURFGANGTYPE][1] > TurfInfo[turfid][E_FACTION_TURFGANGTYPE][0] && TurfInfo[turfid][E_FACTION_TURFGANGTYPE][1] > TurfInfo[turfid][E_FACTION_TURFGANGTYPE][2] && TurfInfo[turfid][E_FACTION_TURFGANGTYPE][1] > TurfInfo[turfid][E_FACTION_TURFGANGTYPE][3] && TurfInfo[turfid][E_FACTION_TURFGANGTYPE][1] > TurfInfo[turfid][E_FACTION_TURFGANGTYPE][4] 
		&& TurfInfo[turfid][E_FACTION_TURFGANGTYPE][1] > TurfInfo[turfid][E_FACTION_TURFGANGTYPE][5] && TurfInfo[turfid][E_FACTION_TURFGANGTYPE][1] > TurfInfo[turfid][E_FACTION_TURFGANGTYPE][6] && TurfInfo[turfid][E_FACTION_TURFGANGTYPE][1] > TurfInfo[turfid][E_FACTION_TURFGANGTYPE][7] && TurfInfo[turfid][E_FACTION_TURFGANGTYPE][1] > TurfInfo[turfid][E_FACTION_TURFGANGTYPE][8]
		&& TurfInfo[turfid][E_FACTION_TURFGANGTYPE][1] > TurfInfo[turfid][E_FACTION_TURFGANGTYPE][9])
	{
		GetPlayerName(playerid, TurfInfo[turfid][E_FACTION_TURFCAPTUREDBY], MAX_PLAYER_NAME);

		TurfInfo[turfid][E_FACTION_TURFGANG] = 6;

		ReloadTurf(turfid);
		new str[128];
		format(str, sizeof(str), "Street's News: %s has been take over by %s for %s", ReturnLocationStreet(playerid), ReturnSettingsName(playerid, playerid), ReturnFactionName(playerid));
		SendClientMessageToAll(COLOR_POINT, str);
	}
	else if(TurfInfo[turfid][E_FACTION_TURFGANGTYPE][2] > TurfInfo[turfid][E_FACTION_TURFGANGTYPE][0] && TurfInfo[turfid][E_FACTION_TURFGANGTYPE][2] > TurfInfo[turfid][E_FACTION_TURFGANGTYPE][1] && TurfInfo[turfid][E_FACTION_TURFGANGTYPE][2] > TurfInfo[turfid][E_FACTION_TURFGANGTYPE][3] && TurfInfo[turfid][E_FACTION_TURFGANGTYPE][2] > TurfInfo[turfid][E_FACTION_TURFGANGTYPE][4] 
		&& TurfInfo[turfid][E_FACTION_TURFGANGTYPE][2] > TurfInfo[turfid][E_FACTION_TURFGANGTYPE][5] && TurfInfo[turfid][E_FACTION_TURFGANGTYPE][2] > TurfInfo[turfid][E_FACTION_TURFGANGTYPE][6] && TurfInfo[turfid][E_FACTION_TURFGANGTYPE][2] > TurfInfo[turfid][E_FACTION_TURFGANGTYPE][7] && TurfInfo[turfid][E_FACTION_TURFGANGTYPE][2] > TurfInfo[turfid][E_FACTION_TURFGANGTYPE][8]
		&& TurfInfo[turfid][E_FACTION_TURFGANGTYPE][2] > TurfInfo[turfid][E_FACTION_TURFGANGTYPE][9])
	{
		GetPlayerName(playerid, TurfInfo[turfid][E_FACTION_TURFCAPTUREDBY], MAX_PLAYER_NAME);

		TurfInfo[turfid][E_FACTION_TURFGANG] = 10;

		ReloadTurf(turfid);
		new str[128];
		format(str, sizeof(str), "Street's News: %s has been take over by %s for %s", ReturnLocationStreet(playerid), ReturnSettingsName(playerid, playerid), ReturnFactionName(playerid));
		SendClientMessageToAll(COLOR_POINT, str);
	}
	else if(TurfInfo[turfid][E_FACTION_TURFGANGTYPE][3] > TurfInfo[turfid][E_FACTION_TURFGANGTYPE][0] && TurfInfo[turfid][E_FACTION_TURFGANGTYPE][3] > TurfInfo[turfid][E_FACTION_TURFGANGTYPE][1] && TurfInfo[turfid][E_FACTION_TURFGANGTYPE][3] > TurfInfo[turfid][E_FACTION_TURFGANGTYPE][2] && TurfInfo[turfid][E_FACTION_TURFGANGTYPE][3] > TurfInfo[turfid][E_FACTION_TURFGANGTYPE][4] 
		&& TurfInfo[turfid][E_FACTION_TURFGANGTYPE][3] > TurfInfo[turfid][E_FACTION_TURFGANGTYPE][5] && TurfInfo[turfid][E_FACTION_TURFGANGTYPE][3] > TurfInfo[turfid][E_FACTION_TURFGANGTYPE][6] && TurfInfo[turfid][E_FACTION_TURFGANGTYPE][3] > TurfInfo[turfid][E_FACTION_TURFGANGTYPE][7] && TurfInfo[turfid][E_FACTION_TURFGANGTYPE][3] > TurfInfo[turfid][E_FACTION_TURFGANGTYPE][8]
		&& TurfInfo[turfid][E_FACTION_TURFGANGTYPE][3] > TurfInfo[turfid][E_FACTION_TURFGANGTYPE][9])
	{
		GetPlayerName(playerid, TurfInfo[turfid][E_FACTION_TURFCAPTUREDBY], MAX_PLAYER_NAME);

		TurfInfo[turfid][E_FACTION_TURFGANG] = 4;

		ReloadTurf(turfid);
		new str[128];
		format(str, sizeof(str), "Street's News: %s has been take over by %s for %s", ReturnLocationStreet(playerid), ReturnSettingsName(playerid, playerid), ReturnFactionName(playerid));
		SendClientMessageToAll(COLOR_POINT, str);
	}
	else if(TurfInfo[turfid][E_FACTION_TURFGANGTYPE][4] > TurfInfo[turfid][E_FACTION_TURFGANGTYPE][0] && TurfInfo[turfid][E_FACTION_TURFGANGTYPE][4] > TurfInfo[turfid][E_FACTION_TURFGANGTYPE][1] && TurfInfo[turfid][E_FACTION_TURFGANGTYPE][4] > TurfInfo[turfid][E_FACTION_TURFGANGTYPE][2] && TurfInfo[turfid][E_FACTION_TURFGANGTYPE][4] > TurfInfo[turfid][E_FACTION_TURFGANGTYPE][3] 
		&& TurfInfo[turfid][E_FACTION_TURFGANGTYPE][4] > TurfInfo[turfid][E_FACTION_TURFGANGTYPE][5] && TurfInfo[turfid][E_FACTION_TURFGANGTYPE][4] > TurfInfo[turfid][E_FACTION_TURFGANGTYPE][6] && TurfInfo[turfid][E_FACTION_TURFGANGTYPE][4] > TurfInfo[turfid][E_FACTION_TURFGANGTYPE][7] && TurfInfo[turfid][E_FACTION_TURFGANGTYPE][4] > TurfInfo[turfid][E_FACTION_TURFGANGTYPE][8]
		&& TurfInfo[turfid][E_FACTION_TURFGANGTYPE][4] > TurfInfo[turfid][E_FACTION_TURFGANGTYPE][9])
	{
		GetPlayerName(playerid, TurfInfo[turfid][E_FACTION_TURFCAPTUREDBY], MAX_PLAYER_NAME);

		TurfInfo[turfid][E_FACTION_TURFGANG] = 5;

		ReloadTurf(turfid);
		new str[128];
		format(str, sizeof(str), "Street's News: %s has been take over by %s for %s", ReturnLocationStreet(playerid), ReturnSettingsName(playerid, playerid), ReturnFactionName(playerid));
		SendClientMessageToAll(COLOR_POINT, str);
	}
	else if(TurfInfo[turfid][E_FACTION_TURFGANGTYPE][5] > TurfInfo[turfid][E_FACTION_TURFGANGTYPE][0] && TurfInfo[turfid][E_FACTION_TURFGANGTYPE][5] > TurfInfo[turfid][E_FACTION_TURFGANGTYPE][1] && TurfInfo[turfid][E_FACTION_TURFGANGTYPE][5] > TurfInfo[turfid][E_FACTION_TURFGANGTYPE][2] && TurfInfo[turfid][E_FACTION_TURFGANGTYPE][5] > TurfInfo[turfid][E_FACTION_TURFGANGTYPE][3] 
		&& TurfInfo[turfid][E_FACTION_TURFGANGTYPE][5] > TurfInfo[turfid][E_FACTION_TURFGANGTYPE][4] && TurfInfo[turfid][E_FACTION_TURFGANGTYPE][5] > TurfInfo[turfid][E_FACTION_TURFGANGTYPE][6] && TurfInfo[turfid][E_FACTION_TURFGANGTYPE][5] > TurfInfo[turfid][E_FACTION_TURFGANGTYPE][7] && TurfInfo[turfid][E_FACTION_TURFGANGTYPE][5] > TurfInfo[turfid][E_FACTION_TURFGANGTYPE][8]
		&& TurfInfo[turfid][E_FACTION_TURFGANGTYPE][5] > TurfInfo[turfid][E_FACTION_TURFGANGTYPE][9])
	{
		GetPlayerName(playerid, TurfInfo[turfid][E_FACTION_TURFCAPTUREDBY], MAX_PLAYER_NAME);

		TurfInfo[turfid][E_FACTION_TURFGANG] = 9;

		ReloadTurf(turfid);
		new str[128];
		format(str, sizeof(str), "Street's News: %s has been take over by %s for %s", ReturnLocationStreet(playerid), ReturnSettingsName(playerid, playerid), ReturnFactionName(playerid));
		SendClientMessageToAll(COLOR_POINT, str);
	}
	else if(TurfInfo[turfid][E_FACTION_TURFGANGTYPE][6] > TurfInfo[turfid][E_FACTION_TURFGANGTYPE][0] && TurfInfo[turfid][E_FACTION_TURFGANGTYPE][6] > TurfInfo[turfid][E_FACTION_TURFGANGTYPE][1] && TurfInfo[turfid][E_FACTION_TURFGANGTYPE][6] > TurfInfo[turfid][E_FACTION_TURFGANGTYPE][2] && TurfInfo[turfid][E_FACTION_TURFGANGTYPE][6] > TurfInfo[turfid][E_FACTION_TURFGANGTYPE][3] 
		&& TurfInfo[turfid][E_FACTION_TURFGANGTYPE][6] > TurfInfo[turfid][E_FACTION_TURFGANGTYPE][4] && TurfInfo[turfid][E_FACTION_TURFGANGTYPE][6] > TurfInfo[turfid][E_FACTION_TURFGANGTYPE][5] && TurfInfo[turfid][E_FACTION_TURFGANGTYPE][6] > TurfInfo[turfid][E_FACTION_TURFGANGTYPE][7] && TurfInfo[turfid][E_FACTION_TURFGANGTYPE][6] > TurfInfo[turfid][E_FACTION_TURFGANGTYPE][8]
		&& TurfInfo[turfid][E_FACTION_TURFGANGTYPE][6] > TurfInfo[turfid][E_FACTION_TURFGANGTYPE][9])
	{
		GetPlayerName(playerid, TurfInfo[turfid][E_FACTION_TURFCAPTUREDBY], MAX_PLAYER_NAME);

		TurfInfo[turfid][E_FACTION_TURFGANG] = 11;

		ReloadTurf(turfid);
		new str[128];
		format(str, sizeof(str), "Street's News: %s has been take over by %s for %s", ReturnLocationStreet(playerid), ReturnSettingsName(playerid, playerid), ReturnFactionName(playerid));
		SendClientMessageToAll(COLOR_POINT, str);
	}
	else if(TurfInfo[turfid][E_FACTION_TURFGANGTYPE][7] > TurfInfo[turfid][E_FACTION_TURFGANGTYPE][0] && TurfInfo[turfid][E_FACTION_TURFGANGTYPE][7] > TurfInfo[turfid][E_FACTION_TURFGANGTYPE][1] && TurfInfo[turfid][E_FACTION_TURFGANGTYPE][7] > TurfInfo[turfid][E_FACTION_TURFGANGTYPE][2] && TurfInfo[turfid][E_FACTION_TURFGANGTYPE][7] > TurfInfo[turfid][E_FACTION_TURFGANGTYPE][3] 
		&& TurfInfo[turfid][E_FACTION_TURFGANGTYPE][7] > TurfInfo[turfid][E_FACTION_TURFGANGTYPE][4] && TurfInfo[turfid][E_FACTION_TURFGANGTYPE][7] > TurfInfo[turfid][E_FACTION_TURFGANGTYPE][5] && TurfInfo[turfid][E_FACTION_TURFGANGTYPE][7] > TurfInfo[turfid][E_FACTION_TURFGANGTYPE][6] && TurfInfo[turfid][E_FACTION_TURFGANGTYPE][7] > TurfInfo[turfid][E_FACTION_TURFGANGTYPE][8]
		&& TurfInfo[turfid][E_FACTION_TURFGANGTYPE][7] > TurfInfo[turfid][E_FACTION_TURFGANGTYPE][9])
	{
		GetPlayerName(playerid, TurfInfo[turfid][E_FACTION_TURFCAPTUREDBY], MAX_PLAYER_NAME);

		TurfInfo[turfid][E_FACTION_TURFGANG] = 7;

		ReloadTurf(turfid);
		new str[128];
		format(str, sizeof(str), "Street's News: %s has been take over by %s for %s", ReturnLocationStreet(playerid), ReturnSettingsName(playerid, playerid), ReturnFactionName(playerid));
		SendClientMessageToAll(COLOR_POINT, str);
	}
	else if(TurfInfo[turfid][E_FACTION_TURFGANGTYPE][8] > TurfInfo[turfid][E_FACTION_TURFGANGTYPE][0] && TurfInfo[turfid][E_FACTION_TURFGANGTYPE][8] > TurfInfo[turfid][E_FACTION_TURFGANGTYPE][1] && TurfInfo[turfid][E_FACTION_TURFGANGTYPE][8] > TurfInfo[turfid][E_FACTION_TURFGANGTYPE][2] && TurfInfo[turfid][E_FACTION_TURFGANGTYPE][8] > TurfInfo[turfid][E_FACTION_TURFGANGTYPE][3] 
		&& TurfInfo[turfid][E_FACTION_TURFGANGTYPE][8] > TurfInfo[turfid][E_FACTION_TURFGANGTYPE][4] && TurfInfo[turfid][E_FACTION_TURFGANGTYPE][8] > TurfInfo[turfid][E_FACTION_TURFGANGTYPE][5] && TurfInfo[turfid][E_FACTION_TURFGANGTYPE][8] > TurfInfo[turfid][E_FACTION_TURFGANGTYPE][6] && TurfInfo[turfid][E_FACTION_TURFGANGTYPE][8] > TurfInfo[turfid][E_FACTION_TURFGANGTYPE][7]
		&& TurfInfo[turfid][E_FACTION_TURFGANGTYPE][8] > TurfInfo[turfid][E_FACTION_TURFGANGTYPE][9])
	{
		GetPlayerName(playerid, TurfInfo[turfid][E_FACTION_TURFCAPTUREDBY], MAX_PLAYER_NAME);

		TurfInfo[turfid][E_FACTION_TURFGANG] = 8;

		ReloadTurf(turfid);
		new str[128];
		format(str, sizeof(str), "Street's News: %s has been take over by %s for %s", ReturnLocationStreet(playerid), ReturnSettingsName(playerid, playerid), ReturnFactionName(playerid));
		SendClientMessageToAll(COLOR_POINT, str);
	}
	else
	{
		return 0;
	}
	mysql_format(ourConnection, queryBuffer, sizeof(queryBuffer), "UPDATE turfs SET capturedby = '%s', capturedgang = %i, time = 0 WHERE id = %i", TurfInfo[turfid][E_FACTION_TURFCAPTUREDBY], TurfInfo[turfid][E_FACTION_TURFGANG], turfid);
	mysql_pquery(ourConnection, queryBuffer);

	ReloadTurf(turfid);
	return 1;
}

//Turfsystem

CMD:turf(playerid, params[])
{
	new turfid, str[1024], caption[1024];

	if((turfid = IsPlayerNearTurf(playerid)) == -1)
	{
	    return SendErrorMessage(playerid, "You are not in range of any turfs.");
	}

	format(caption, sizeof(caption), "Factions in %s:", ReturnLocationStreet(playerid));

	format(str, sizeof(str), "Factions\tInfluenced\n");

	if (!TurfInfo[turfid][E_FACTION_TURFGANGTYPE][0])
	    format(str, sizeof(str), "%s\n", str);
	else
        format(str, sizeof(str), "%s{00B10E}Grove Street Famillies\t%d\n", str, TurfInfo[turfid][E_FACTION_TURFGANGTYPE][0]);

    if (!TurfInfo[turfid][E_FACTION_TURFGANGTYPE][1])
	    format(str, sizeof(str), "%s\n", str);
	else
        format(str, sizeof(str), "%s{98ED8E}Seville Boulevard Famillies\t%d\n", str, TurfInfo[turfid][E_FACTION_TURFGANGTYPE][1]);

    if (!TurfInfo[turfid][E_FACTION_TURFGANGTYPE][2])
	    format(str, sizeof(str), "%s\n", str);
	else
        format(str, sizeof(str), "%s{447c15}Temple Drive Famillies\t%d\n", str, TurfInfo[turfid][E_FACTION_TURFGANGTYPE][2]);

    if (!TurfInfo[turfid][E_FACTION_TURFGANGTYPE][3])
	    format(str, sizeof(str), "%s\n", str);
	else
        format(str, sizeof(str), "%s{8B15DC}Kilo Tray Ballas\t%d\n", str, TurfInfo[turfid][E_FACTION_TURFGANGTYPE][3]);

    if (!TurfInfo[turfid][E_FACTION_TURFGANGTYPE][4])
	    format(str, sizeof(str), "%s\n", str);
	else
        format(str, sizeof(str), "%s{73389C}Rollin Height Ballas\t%d\n", str, TurfInfo[turfid][E_FACTION_TURFGANGTYPE][4]);

    if (!TurfInfo[turfid][E_FACTION_TURFGANGTYPE][5])
	    format(str, sizeof(str), "%s\n", str);
	else
        format(str, sizeof(str), "%s{69157c}Front Yard Ballas\t%d\n", str, TurfInfo[turfid][E_FACTION_TURFGANGTYPE][5]);

    if (!TurfInfo[turfid][E_FACTION_TURFGANGTYPE][6])
	    format(str, sizeof(str), "%s\n", str);
	else
        format(str, sizeof(str), "%s{00B10E}Temple Drive Ballas\t%d\n", str, TurfInfo[turfid][E_FACTION_TURFGANGTYPE][6]);

    if (!TurfInfo[turfid][E_FACTION_TURFGANGTYPE][7])
	    format(str, sizeof(str), "%s\n", str);
	else
        format(str, sizeof(str), "%s{DDC66B}Los Santos Vagos\t%d\n", str, TurfInfo[turfid][E_FACTION_TURFGANGTYPE][7]);

    if (!TurfInfo[turfid][E_FACTION_TURFGANGTYPE][8])
	    format(str, sizeof(str), "%s\n", str);
	else
        format(str, sizeof(str), "%s{6BD3DD}Varrios Los Aztecas\t%d\n", str, TurfInfo[turfid][E_FACTION_TURFGANGTYPE][8]);

    ShowPlayerDialog(playerid, DIALOG_DEFAULT, DIALOG_STYLE_TABLIST_HEADERS, caption, str, "Select", "Close");
	return 1;
}

CMD:cltw(playerid, params[]) return cmd_claimturfwars(playerid, params);
CMD:claimturfwars(playerid, params[])
{
	new turfid, count;

    if(!PlayerInfo[playerid][E_CHARACTER_FACTION])
	    return SendErrorMessage(playerid, "You are not apart in a faction");

	if(FactionInfo[PlayerInfo[playerid][E_CHARACTER_FACTION]][E_FACTION_TYPE] != FACTION_TYPE_ILLEGAL)
		return SendErrorMessage(playerid, "You can't claim because you are not apart in a gang."); 

	if((turfid = IsPlayerNearTurf(playerid)) == -1)
		return SendErrorMessage(playerid, "You are not in range of any turfs which you can claim.");

	if(GetPlayerTeam(playerid) == PLAYER_STATE_WOUNDED)
	    return SendErrorMessage(playerid, "You can't claim a turf while injured.");

	if(GlobalTurf == 1)
	    return SendErrorMessage(playerid, "There is turfwars conflict has deactive.");

	if(TurfInfo[turfid][E_FACTION_TURFTYPE] == 1)
	    return SendErrorMessage(playerid, "This is a locked turf and therefore cannot be claimed.");

	if(TurfInfo[turfid][E_FACTION_TURFGANG] == PlayerInfo[playerid][E_CHARACTER_FACTION])
	    return SendErrorMessage(playerid, "This turf is already being claimed by your faction.");

	if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT)
	    return SendErrorMessage(playerid, "You must be onfoot in order to use this command.");

	if(PlayerInfo[playerid][E_CHARACTER_FACTION] > 0)
	{
	    foreach(new i : Player)
	    {
	        if(IsPlayerNearTurf(i) == turfid && PlayerInfo[i][E_CHARACTER_FACTION] == PlayerInfo[playerid][E_CHARACTER_FACTION])
	        {
	            count++;
			}
		}

		if(count < 4)
		{
		    return SendErrorMessage(playerid, "You need at least 4 members of your gang in this turf to claim it.");
		}
		else
		{
			
		}
	}
	TurfInfo[turfid][E_FACTION_TURFCAPTURER] = playerid;
	TurfInfo[turfid][E_FACTION_TURFTIME] = 30;
	ReloadTurf(turfid);
	return 1;
}