stock IsPlayerNearGates(playerid)
{
	if(IsPlayerInAnyVehicle(playerid))
	{
		for (new i = 0; i != MAX_GATES; i ++) if (IsPlayerInRangeOfPoint(playerid, 10.0, GateInfo[i][E_GATE_POS][0], GateInfo[i][E_GATE_POS][1], GateInfo[i][E_GATE_POS][2]))
		{
			if (GetPlayerInterior(playerid) == GateInfo[i][E_GATE_INTERIOR] && GetPlayerVirtualWorld(playerid) == GateInfo[i][E_GATE_WORLD])
				return i;
		}
	}
	else
	{
		for (new i = 0; i != MAX_GATES; i ++) if (IsPlayerInRangeOfPoint(playerid, 5.0, GateInfo[i][E_GATE_POS][0], GateInfo[i][E_GATE_POS][1], GateInfo[i][E_GATE_POS][2]))
		{
			if (GetPlayerInterior(playerid) == GateInfo[i][E_GATE_INTERIOR] && GetPlayerVirtualWorld(playerid) == GateInfo[i][E_GATE_WORLD])
				return i;
		}
	}
	return -1;
}

function:Query_LoadGates()
{
    if(!cache_num_rows())
		return printf("[SERVER]: No gates were loaded from \"%s\" database...", SQL_DATABASE); 

	static
	    rows,
	    fields;

	cache_get_row_count(rows);
	cache_get_field_count(fields);

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

		GateInfo[i][E_GATE_EXISTS] = true;
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
	if (gid != -1 && GateInfo[gid][E_GATE_EXISTS])
	{
		if (!GateInfo[gid][E_GATE_STATUS])
		{
		    GateInfo[gid][E_GATE_STATUS] = true;
		    MoveDynamicObject(GateInfo[gid][E_GATE_OBJECT], GateInfo[gid][E_GATE_MOVE][0], GateInfo[gid][E_GATE_MOVE][1], GateInfo[gid][E_GATE_MOVE][2], 1.7, GateInfo[gid][E_GATE_MOVE][3], GateInfo[gid][E_GATE_MOVE][4], GateInfo[gid][E_GATE_MOVE][5]);

			GateInfo[gid][E_GATE_TIMER] = SetTimerEx("CloseGate", 5000, false, "dfffffff", gid, GateInfo[gid][E_GATE_POS][0], GateInfo[gid][E_GATE_POS][1], GateInfo[gid][E_GATE_POS][2], 1.7, GateInfo[gid][E_GATE_POS][3], GateInfo[gid][E_GATE_POS][4], GateInfo[gid][E_GATE_POS][5]);
		}
		else if (GateInfo[gid][E_GATE_STATUS])
		{
		    GateInfo[gid][E_GATE_STATUS] = false;
		    MoveDynamicObject(GateInfo[gid][E_GATE_OBJECT], GateInfo[gid][E_GATE_POS][0], GateInfo[gid][E_GATE_POS][1], GateInfo[gid][E_GATE_POS][2], 1.7, GateInfo[gid][E_GATE_POS][3], GateInfo[gid][E_GATE_POS][4], GateInfo[gid][E_GATE_POS][5]);
            
			KillTimer(GateInfo[gid][E_GATE_TIMER]);
		}
	}
	return 1;
}

stock Gates_Refresh(id)
{
	if(GateInfo[id][E_GATE_EXISTS])
	{
		if(IsValidDynamicObject(GateInfo[id][E_GATE_OBJECT]))
			DestroyDynamicObject(GateInfo[id][E_GATE_OBJECT]);

		GateInfo[id][E_GATE_OBJECT] = CreateDynamicObject(GateInfo[id][E_GATE_MODELID], GateInfo[id][E_GATE_POS][0], GateInfo[id][E_GATE_POS][1], GateInfo[id][E_GATE_POS][2], GateInfo[id][E_GATE_POS][3], GateInfo[id][E_GATE_POS][4], GateInfo[id][E_GATE_POS][5], GateInfo[id][E_GATE_WORLD], GateInfo[id][E_GATE_INTERIOR], -1, 500.0, 500.0);
	}
	return 1;
}

stock Gates_Create(playerid)
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
			if(!GateInfo[i][E_GATE_EXISTS])
			{
				GateInfo[i][E_GATE_MODELID] = 970;
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

				GateInfo[i][E_GATE_FACTION] = -1;
				GateInfo[i][E_GATE_EXISTS] = true;

				Gates_Refresh(i);
				mysql_pquery(ourConnection, "INSERT INTO `gates` (`modelid`) VALUES('970')", "OnGateCreated", "d", i);
				return i;
			}
		}
	}
	return -1;
}

function:OnGateCreated(id)
{
	GateInfo[id][E_GATE_DBID] = cache_insert_id();
	Gates_Save(id);
	return 1;
}

stock Gates_Delete(gid)
{
	if (gid != -1 && GateInfo[gid][E_GATE_EXISTS])
	{
		new
		    query[64];

		mysql_format(ourConnection, query, sizeof(query), "DELETE FROM `gates` WHERE `dbid` = '%d'", GateInfo[gid][E_GATE_DBID]);
		mysql_tquery(ourConnection, query);

		if (IsValidDynamicObject(GateInfo[gid][E_GATE_OBJECT]))
		    DestroyDynamicObject(GateInfo[gid][E_GATE_OBJECT]);

		if (GateInfo[gid][E_GATE_STATUS] && GateInfo[gid][E_GATE_TIMER] > 0) {
		    KillTimer(GateInfo[gid][E_GATE_TIMER]);
		}

		GateInfo[gid][E_GATE_EXISTS] = false;
	    GateInfo[gid][E_GATE_DBID] = 0;
	    GateInfo[gid][E_GATE_STATUS] = 0;
	}
	return 1;
}

CMD:door(playerid, params[]) return cmd_gate(playerid, params);
CMD:gate(playerid, params[])
{
	new id = IsPlayerNearGates(playerid);

	if (id != -1)
	{
        if (GateInfo[id][E_GATE_FACTION] != -1 && ReturnFactionType(playerid) != GateInfo[id][E_GATE_FACTION])
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
	static
	    id = -1;

    if(IsPlayerAdmins(playerid) < 4)
		return 0;

	id = Gates_Create(playerid);

	if (id == -1)
	    return SendErrorMessage(playerid, "You can't make anymore gates.");

	SendServerMessage(playerid, "You created gates ID #%i. To configure, use \"/editgate\"", id);
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
	SendServerMessage(playerid, "You have destroyed gates ID #%d.", id);
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
	    new
	        model;

		if (sscanf(string, "d", model))
		    return SendUsageMessage(playerid, "/editgate [id] [modelid] [objectid]");

        GateInfo[id][E_GATE_MODELID] = model;

		Gates_Save(id);
        Gates_Refresh(id);
        SendServerMessage(playerid, "You changed gates #%i's modelid to %i.", id, model);
		return 1;
	}
    else if (!strcmp(type, "pos", true))
	{
	   	EditDynamicObject(playerid, GateInfo[id][E_GATE_OBJECT]);

		PlayerInfo[playerid][E_CHARACTER_EDITINGOBJECT] = 9;
		PlayerInfo[playerid][E_CHARACTER_OBJECTID] = id;

		SendServerMessage(playerid, "You are now adjusting the position of gate ID: %d.", id);
		return 1;
	}
	else if (!strcmp(type, "move", true))
	{
	   	EditDynamicObject(playerid, GateInfo[id][E_GATE_OBJECT]);

		PlayerInfo[playerid][E_CHARACTER_EDITINGOBJECT] = 10;
		PlayerInfo[playerid][E_CHARACTER_OBJECTID] = id;

		SendServerMessage(playerid, "You are now adjusting the moving position of gate ID: %d.", id);
		return 1;
	}
	else if (!strcmp(type, "faction", true))
	{
	    new
	        factionid = -1;

		if (sscanf(string, "d", factionid))
        {
            SendUsageMessage(playerid, "/editgate [id] [faction] [factionid]");
			SendTipMessage(playerid, "1.Illegal, 2.Police, 3.Medical");
		    return 1;
        }

       	if(!FactionInfo[factionid][E_FACTION_DBID]) return SendErrorMessage(playerid, "The faction you specified doesn't exist.");

        GateInfo[id][E_GATE_FACTION] = factionid;
		Gates_Save(id);

		SendServerMessage(playerid, "You are now adjusting the faction %s of gate ID: %d.", ReturnFactionTypeEx(factionid), id);
		return 1;
	}
	return 1;
}