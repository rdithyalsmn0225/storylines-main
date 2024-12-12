stock Trashcan_Create(playerid)
{
	for (new i = 0; i != MAX_TRASH; i ++) if (!TrashInfo[i][E_TRASH_EXISTS])
	{
	    TrashInfo[i][E_TRASH_EXISTS] = true;
	    TrashInfo[i][E_TRASH_CAPACITY] = 0;

	    GetPlayerPos(playerid, TrashInfo[i][E_TRASH_POS][0], TrashInfo[i][E_TRASH_POS][1], TrashInfo[i][E_TRASH_POS][2]);
	    GetPlayerFacingAngle(playerid, TrashInfo[i][E_TRASH_POS][3]);
		
        TrashInfo[i][E_TRASH_POS][0] = TrashInfo[i][E_TRASH_POS][0] + (1.8 * floatsin(-TrashInfo[i][E_TRASH_POS][3], degrees));
        TrashInfo[i][E_TRASH_POS][1] = TrashInfo[i][E_TRASH_POS][1] + (1.8 * floatcos(-TrashInfo[i][E_TRASH_POS][3], degrees));
			
		Trashcan_Refresh(i);
		mysql_tquery(ourConnection, "INSERT INTO `trashcan` (`capacity`) VALUES(0)", "OnTrashcanCreated", "d", i);
		return i;
	}
	return -1;
}

function:Query_LoadTrashcan()
{
    if(!cache_num_rows())
		return printf("[SERVER]: No trachcan were loaded from \"%s\" database...", SQL_DATABASE); 

	new rows = cache_num_rows();
	if(rows)
	{
		forex(i, rows)
		{
			TrashInfo[i][E_TRASH_EXISTS] = true;
			cache_get_value_name_int(i, "DBID", TrashInfo[i][E_TRASH_DBID]);
            cache_get_value_name_int(i, "capacity", TrashInfo[i][E_TRASH_CAPACITY]);
			cache_get_value_name_float(i, "posx", TrashInfo[i][E_TRASH_POS][0]);
			cache_get_value_name_float(i, "posy", TrashInfo[i][E_TRASH_POS][1]);
			cache_get_value_name_float(i, "posz", TrashInfo[i][E_TRASH_POS][2]);
			cache_get_value_name_float(i, "posa", TrashInfo[i][E_TRASH_POS][3]);
			Trashcan_Refresh(i);
		}
		printf("[SERVER]: %i trashcan were loaded from \"%s\" database...", rows, SQL_DATABASE);
	}
	return 1;
}

function:OnTrashcanCreated(id)
{
	if (id == -1 || !TrashInfo[id][E_TRASH_EXISTS])
	    return 0;

	TrashInfo[id][E_TRASH_DBID] = cache_insert_id();
	Trashcan_Save(id);
	return 1;
}

stock Trashcan_Delete(id)
{
	if (id != -1 && TrashInfo[id][E_TRASH_EXISTS])
	{
	    new
	        string[64];

		format(string, sizeof(string), "DELETE FROM `trashcan` WHERE `DBID` = '%d'", TrashInfo[id][E_TRASH_DBID]);
		mysql_pquery(ourConnection, string);

        if (IsValidDynamic3DTextLabel(TrashInfo[id][E_TRASH_TEXT3D]))
	        DestroyDynamic3DTextLabel(TrashInfo[id][E_TRASH_TEXT3D]);

		if (IsValidDynamicObject(TrashInfo[id][E_TRASH_OBJECT]))
		    DestroyDynamicObject(TrashInfo[id][E_TRASH_OBJECT]);

	    TrashInfo[id][E_TRASH_EXISTS] = false;
	    TrashInfo[id][E_TRASH_CAPACITY] = 0;
	    TrashInfo[id][E_TRASH_DBID] = 0;
	}
	return 1;
}

stock IsPlayerNearTrashcan(playerid)
{
    for (new i = 0; i != MAX_TRASH; i ++) if (TrashInfo[i][E_TRASH_EXISTS])
	{
		if(IsPlayerInRangeOfPoint(playerid, 3.0, TrashInfo[i][E_TRASH_POS][0], TrashInfo[i][E_TRASH_POS][1], TrashInfo[i][E_TRASH_POS][2]))
			return i;
	}
	return -1;
}

stock Trashcan_Refresh(id)
{
	if (id != -1 && TrashInfo[id][E_TRASH_EXISTS])
	{
	    if (IsValidDynamic3DTextLabel(TrashInfo[id][E_TRASH_TEXT3D]))
	        DestroyDynamic3DTextLabel(TrashInfo[id][E_TRASH_TEXT3D]);

		if (IsValidDynamicObject(TrashInfo[id][E_TRASH_OBJECT]))
		    DestroyDynamicObject(TrashInfo[id][E_TRASH_OBJECT]);

		new
			string[64];

		format(string, sizeof(string), "[Trashcan]\n{FFFFFF}Trash Capacity: %d/20", TrashInfo[id][E_TRASH_CAPACITY]);
		TrashInfo[id][E_TRASH_TEXT3D] = CreateDynamic3DTextLabel(string, COLOR_3DTEXT, TrashInfo[id][E_TRASH_POS][0], TrashInfo[id][E_TRASH_POS][1], TrashInfo[id][E_TRASH_POS][2], 15.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1, -1);
		TrashInfo[id][E_TRASH_OBJECT] = CreateDynamicObject(1236, TrashInfo[id][E_TRASH_POS][0], TrashInfo[id][E_TRASH_POS][1], TrashInfo[id][E_TRASH_POS][2] - 0.6, 0.0, 0.0, TrashInfo[id][E_TRASH_POS][3], -1, -1);

		Streamer_SetFloatData(STREAMER_TYPE_OBJECT, TrashInfo[id][E_TRASH_OBJECT], E_STREAMER_X, TrashInfo[id][E_TRASH_POS][0]);
		Streamer_SetFloatData(STREAMER_TYPE_OBJECT, TrashInfo[id][E_TRASH_OBJECT], E_STREAMER_Y, TrashInfo[id][E_TRASH_POS][1]);
		Streamer_SetFloatData(STREAMER_TYPE_OBJECT, TrashInfo[id][E_TRASH_OBJECT], E_STREAMER_Z, TrashInfo[id][E_TRASH_POS][2]);

        Streamer_SetFloatData(STREAMER_TYPE_AREA, TrashInfo[id][E_TRASH_AREA], E_STREAMER_X, TrashInfo[id][E_TRASH_POS][0]);
		Streamer_SetFloatData(STREAMER_TYPE_AREA, TrashInfo[id][E_TRASH_AREA], E_STREAMER_Y, TrashInfo[id][E_TRASH_POS][1]);
		Streamer_SetFloatData(STREAMER_TYPE_AREA, TrashInfo[id][E_TRASH_AREA], E_STREAMER_Z, TrashInfo[id][E_TRASH_POS][2]);    
    }
	return 1;
}

CMD:creategarbage(playerid, params[])
{
	new
	    id = -1;

    if (IsPlayerAdmins(playerid) < ADMINS_OWNER)
	    return 0;

	id = Trashcan_Create(playerid);

	if (id == -1)
	    return SendErrorMessage(playerid, "You can't make anymore trashcan.");

	SendServerMessage(playerid, "You have successfully created garbage bin ID: %d.", id);
	return 1;
}

CMD:destroygarbage(playerid, params[])
{
	new
	    id = 0;

    if (IsPlayerAdmins(playerid) < ADMINS_OWNER)
	    return 0;

	if (sscanf(params, "d", id))
	    return SendUsageMessage(playerid, "/destroygarbage [garbage id]");

	if ((id < 0 || id >= MAX_TRASH) || !TrashInfo[id][E_TRASH_EXISTS])
	    return SendErrorMessage(playerid, "You have specified an invalid trashcan ID.");

	Trashcan_Delete(id);
	SendServerMessage(playerid, "You have successfully destroyed garbage bin ID: %d.", id);
	return 1;
}