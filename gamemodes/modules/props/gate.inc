stock IsPlayerNearGates(playerid)
{
    for (new i = 0; i != MAX_GATES; i ++) if (IsPlayerInRangeOfPoint(playerid, 5.0, GateInfo[i][E_GATE_POS][0], GateInfo[i][E_GATE_POS][1], GateInfo[i][E_GATE_POS][2]))
	{
		if (GetPlayerInterior(playerid) == GateInfo[i][E_GATE_INTERIOR] && GetPlayerVirtualWorld(playerid) == GateInfo[i][E_GATE_WORLD])
			return i;
	}
	return -1;
}

function:Query_LoadGates()
{
    if(!cache_num_rows())
		return printf("[SERVER]: No gates were loaded from \"%s\" database...", SQL_DATABASE); 

	new rows, field;
	cache_get_row_count(rows);
	cache_get_field_count(field);

    for (new i = 0; i < rows; i ++) if (i < MAX_GATES)
	{
        cache_get_value_name_int(i, "dbid", GateInfo[i][E_GATE_DBID]);
        cache_get_value_name_int(i, "modelid", GateInfo[i][E_GATE_MODELID]);
        cache_get_value_name_int(i, "interior", GateInfo[i][E_GATE_INTERIOR]);
        cache_get_value_name_int(i, "world", GateInfo[i][E_GATE_WORLD]);
        cache_get_value_name_int(i, "faction", GateInfo[i][E_GATE_FACTION]);
        cache_get_value_name_int(i, "status", GateInfo[i][E_GATE_STATUS]);

	    cache_get_value_name_float(i, "posx", GateInfo[i][E_GATE_POS][0]);
        cache_get_value_name_float(i, "posy", GateInfo[i][E_GATE_POS][1]);
        cache_get_value_name_float(i, "posz", GateInfo[i][E_GATE_POS][2]);
        cache_get_value_name_float(i, "posrx", GateInfo[i][E_GATE_POS][3]);
        cache_get_value_name_float(i, "posry", GateInfo[i][E_GATE_POS][4]);
        cache_get_value_name_float(i, "posrz", GateInfo[i][E_GATE_POS][5]);

        cache_get_value_name_float(i, "movex", GateInfo[i][E_GATE_MOVE][0]);
        cache_get_value_name_float(i, "movey", GateInfo[i][E_GATE_MOVE][1]);
        cache_get_value_name_float(i, "movez", GateInfo[i][E_GATE_MOVE][2]);
        cache_get_value_name_float(i, "moverx", GateInfo[i][E_GATE_MOVE][3]);
        cache_get_value_name_float(i, "movery", GateInfo[i][E_GATE_MOVE][4]);
        cache_get_value_name_float(i, "moverz", GateInfo[i][E_GATE_MOVE][5]);

        Gates_Refresh(i);
    }
    printf("[SERVER]: %i gates were loaded from \"%s\" database...", rows, SQL_DATABASE);
    return 1;
}

function:CloseGate(gid, Float:fX, Float:fY, Float:fZ, Float:speed, Float:fRotX, Float:fRotY, Float:fRotZ)
{
	if (GateInfo[gid][E_GATE_STATUS])
 	{
	 	MoveDynamicObject(GateInfo[gid][E_GATE_OBJECT], fX, fY, fZ, speed, fRotX, fRotY, fRotZ);
		GateInfo[gid][E_GATE_STATUS] = 0;
		return 1;
	}
	return 0;
}

stock Gates_Operate(gid)
{
	if (gid != -1)
	{
		if (!GateInfo[gid][E_GATE_STATUS])
		{
		    GateInfo[gid][E_GATE_STATUS] = true;
		    MoveDynamicObject(GateInfo[gid][E_GATE_OBJECT], GateInfo[gid][E_GATE_MOVE][0], GateInfo[gid][E_GATE_MOVE][1], GateInfo[gid][E_GATE_MOVE][2], 0.003, GateInfo[gid][E_GATE_MOVE][3], GateInfo[gid][E_GATE_MOVE][4], GateInfo[gid][E_GATE_MOVE][5]);

			GateInfo[gid][E_GATE_TIMER] = SetTimerEx("CloseGate", 5000, false, "dfffffff", gid, GateInfo[gid][E_GATE_POS][0], GateInfo[gid][E_GATE_POS][1], GateInfo[gid][E_GATE_POS][2], 0.003, GateInfo[gid][E_GATE_POS][3], GateInfo[gid][E_GATE_POS][4], GateInfo[gid][E_GATE_POS][5]);
		}
		else if (GateInfo[gid][E_GATE_STATUS])
		{
		    GateInfo[gid][E_GATE_STATUS] = false;
		    MoveDynamicObject(GateInfo[gid][E_GATE_OBJECT], GateInfo[gid][E_GATE_POS][0], GateInfo[gid][E_GATE_POS][1], GateInfo[gid][E_GATE_POS][2], 0.003, GateInfo[gid][E_GATE_POS][3], GateInfo[gid][E_GATE_POS][4], GateInfo[gid][E_GATE_POS][5]);
            
			KillTimer(GateInfo[gid][E_GATE_TIMER]);
		}
	}
	return 1;
}

stock Gates_Refresh(id)
{
    if(IsValidDynamicObject(GateInfo[id][E_GATE_OBJECT]))
        DestroyDynamicObject(GateInfo[id][E_GATE_OBJECT]);

    GateInfo[id][E_GATE_OBJECT] = CreateDynamicObject(GateInfo[id][E_GATE_MODELID], GateInfo[id][E_GATE_POS][0], GateInfo[id][E_GATE_POS][1], GateInfo[id][E_GATE_POS][2], GateInfo[id][E_GATE_POS][3], GateInfo[id][E_GATE_POS][4], GateInfo[id][E_GATE_POS][5], GateInfo[id][E_GATE_WORLD], GateInfo[id][E_GATE_INTERIOR], -1, 500.0, 500.0);
    return 1;
}

stock Gates_Create(playerid, modelid)
{
	new
	    Float:x,
	    Float:y,
	    Float:z,
	    Float:angle;

	if (GetPlayerPos(playerid, x, y, z) && GetPlayerFacingAngle(playerid, angle))
	{
		for (new i = 0; i < MAX_GATES; i ++)
		{
			GateInfo[i][E_GATE_MODELID] = modelid;
			GateInfo[i][E_GATE_STATUS] = 0;
			GateInfo[i][E_GATE_TIMER] = 0;

			GateInfo[i][E_GATE_POS][0] = x + (3.0 * floatsin(-angle, degrees));
			GateInfo[i][E_GATE_POS][1] = y + (3.0 * floatcos(-angle, degrees));
			GateInfo[i][E_GATE_POS][2] = z;
			GateInfo[i][E_GATE_POS][3] = 0.0;
			GateInfo[i][E_GATE_POS][4] = 0.0;
			GateInfo[i][E_GATE_POS][5] = angle;

			GateInfo[i][E_GATE_MOVE][0] = x + (3.0 * floatsin(-angle, degrees));
			GateInfo[i][E_GATE_MOVE][1] = y + (3.0 * floatcos(-angle, degrees));
			GateInfo[i][E_GATE_MOVE][2] = z - 10.0;
			GateInfo[i][E_GATE_MOVE][3] = -1000.0;
			GateInfo[i][E_GATE_MOVE][4] = -1000.0;
			GateInfo[i][E_GATE_MOVE][5] = -1000.0;

            GateInfo[i][E_GATE_INTERIOR] = GetPlayerInterior(playerid);
            GateInfo[i][E_GATE_WORLD] = GetPlayerVirtualWorld(playerid);

            GateInfo[i][E_GATE_FACTION] = 0;

            Gates_Refresh(i);

			mysql_tquery(ourConnection, "INSERT INTO `gates` (`modelid`) VALUES(%d)", "OnGateCreated", "dd", i, modelid);
			return i;
		}
	}
	return -1;
}

function:OnGateCreated(id, modelid)
{
	GateInfo[id][E_GATE_DBID] = cache_insert_id();
	Gates_Save(id);
}

stock Gates_Delete(gid)
{
	if (gid != -1)
	{
		new
		    query[64];

		mysql_format(ourConnection, query, sizeof(query), "DELETE FROM `gates` WHERE `E_GATE_DBID` = '%d'", GateInfo[gid][E_GATE_DBID]);
		mysql_tquery(ourConnection, query);

		if (IsValidDynamicObject(GateInfo[gid][E_GATE_OBJECT]))
		    DestroyDynamicObject(GateInfo[gid][E_GATE_OBJECT]);

		if (GateInfo[gid][E_GATE_STATUS] && GateInfo[gid][E_GATE_TIMER] > 0) {
		    KillTimer(GateInfo[gid][E_GATE_TIMER]);
		}

	    GateInfo[gid][E_GATE_DBID] = 0;
	    GateInfo[gid][E_GATE_STATUS] = 0;
	}
	return 1;
}

CMD:gate(playerid, params[])
{
	new id = IsPlayerNearGates(playerid);

	if (id != -1)
	{
        if (GateInfo[id][E_GATE_FACTION] != -1 && PlayerInfo[playerid][E_CHARACTER_FACTION] != FactionInfo[GateInfo[id][E_GATE_FACTION]][E_FACTION_DBID])
            return SendUnauthMessage(playerid);

        Gates_Operate(id);

        switch (GateInfo[id][E_GATE_STATUS])
        {
            case 0:
                ShowBoxMessage(playerid, "You have ~r~closed~w~ the gate!", 3);

            case 1:
                ShowBoxMessage(playerid, "You have ~g~opened~w~ the gate!", 3);
        }
	}
	return 1;
}

CMD:creategate(playerid, params[])
{
	new
	    id = -1;

    if(IsPlayerAdmins(playerid) < 4)
		return 0;

	id = Gates_Create(playerid, 975);

	if (id == -1)
	    return SendErrorMessage(playerid, "You can't make anymore gates.");

	SendInfoMessage(playerid, "You created gates ID #%i. To configure, use \"/editgate\"", id);
	return 1;
}

CMD:destroygate(playerid, params[])
{
	new
	    id = 0;

    if(IsPlayerAdmins(playerid) < 4)
		return 0;

	if (sscanf(params, "d", id))
	    return SendUsageMessage(playerid, "/destroygate [gate id]");

	if ((id < 0 || id >= MAX_GATES))
	    return SendErrorMessage(playerid, "You have specified an invalid gate ID.");

	Gates_Delete(id);
	SendInfoMessage(playerid, "You have destroyed gates ID #%d.", id);
	return 1;
}

CMD:editgate(playerid, params[])
{
	new
	    id,
	    type[24],
	    string[128];

	if(IsPlayerAdmins(playerid) < 4)
		return 0;
	if (sscanf(params, "ds[24]S()[128]", id, type, string))
 	{
	 	SendUsageMessage(playerid, "/editgate [gates id] [configuration]");
	    SendTipMessage(playerid, "modelid, pos, move, faction");
		return 1;
	}
	if ((id < 0 || id >= MAX_GATES))
	    return SendErrorMessage(playerid, "You have specified an invalid gate ID.");

	if (!strcmp(type, "modelid", true))
	{
	    static
	        model;

		if (sscanf(string, "d", model))
		    return SendUsageMessage(playerid, "/editgate [id] [modelid] [objectid]");

        GateInfo[id][E_GATE_MODELID] = model;

		Gates_Save(id);
        Gates_Refresh(id);
        SendInfoMessage(playerid, "You changed gates #%i's modelid to %i.", id, model);
		return 1;
	}
    else if (!strcmp(type, "pos", true))
	{
	   	EditDynamicObject(playerid, GateInfo[id][E_GATE_OBJECT]);

		PlayerInfo[playerid][E_CHARACTER_EDITINGOBJECT] = 9;
		PlayerInfo[playerid][E_CHARACTER_OBJECTID] = id;

		SendInfoMessage(playerid, "You are now adjusting the position of gate ID: %d.", id);
		return 1;
	}
	else if (!strcmp(type, "move", true))
	{
	   	EditDynamicObject(playerid, GateInfo[id][E_GATE_OBJECT]);

		PlayerInfo[playerid][E_CHARACTER_EDITINGOBJECT] = 10;
		PlayerInfo[playerid][E_CHARACTER_OBJECTID] = id;

		SendInfoMessage(playerid, "You are now adjusting the moving position of gate ID: %d.", id);
		return 1;
	}
	else if (!strcmp(type, "faction", true))
	{
	    static
	        factionid = -1;

		if (sscanf(string, "d", factionid))
        {
            SendUsageMessage(playerid, "/editgate [id] [faction] [factionid]");
            SendTipMessage(playerid, "Type 0 for gates factionid to 'NONE'");
		    return 1;
        }

        if ((factionid < 0 || factionid >= MAX_FACTIONS) || (factionid != 0))
	    	return SendErrorMessage(playerid, "You have specified an invalid faction ID.");

        GateInfo[id][E_GATE_FACTION] = (factionid == -1) ? (-1) : (FactionInfo[factionid][E_FACTION_DBID]);
		Gates_Save(id);

		if (factionid == 0)
			SendInfoMessage(playerid, "You are now adjusting the factionid 'NONE' of gate ID: #%d.", id);

		else
		    SendInfoMessage(playerid, "You are now adjusting the faction %s of gate ID: %d.", ReturnFactionAbbrev(factionid), id);

		return 1;
	}
	return 1;
}