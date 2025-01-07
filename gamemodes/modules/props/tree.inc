stock IsPlayerNearestTree(playerid)
{
	forex(i, MAX_TREES) if(TreeInfo[i][E_TREE_EXISTS]) if(IsPlayerInDynamicArea(playerid, TreeInfo[i][E_TREE_AREA]))
		return i;

	return -1;
}

stock Tree_Create(playerid)
{
	new Float:x, Float:y, Float:z, Float:a;
	if(GetPlayerPos(playerid, x, y, z) && GetPlayerFacingAngle(playerid, a))
	{
		forex(i, MAX_TREES) if(!TreeInfo[i][E_TREE_EXISTS])
		{
			TreeInfo[i][E_TREE_EXISTS] = true;

			TreeInfo[i][E_TREE_POS][0] = x;
			TreeInfo[i][E_TREE_POS][1] = y;
			TreeInfo[i][E_TREE_POS][2] = z;
			TreeInfo[i][E_TREE_POS][3] = 0.0;
			TreeInfo[i][E_TREE_POS][4] = 0.0;
			TreeInfo[i][E_TREE_POS][5] = a;
			TreeInfo[i][E_TREE_TIMER] = 0;
			TreeInfo[i][E_TREE_CUTTED] = false;
			TreeInfo[i][E_TREE_CUTTIMER] = 0;
			TreeInfo[i][E_TREE_PROGRESS] = 0;

			Tree_Spawn(i);
			mysql_tquery(ourConnection, "INSERT INTO `tree` (`time`) VALUES(0)", "OnTreeCreated", "d", i);
			return i;
		}
	}
	return -1;
}

function:Query_LoadTree()
{
    if(!cache_num_rows())
		return printf("[SERVER]: No trees were loaded from \"%s\" database...", SQL_DATABASE); 

	new rows = cache_num_rows();
	if(rows)
	{
		forex(i, rows)
		{
			TreeInfo[i][E_TREE_EXISTS] = true;
			TreeInfo[i][E_TREE_CUTTED] = false;
			cache_get_value_name_int(i, "id", TreeInfo[i][E_TREE_DBID]);
			cache_get_value_name_float(i, "posx", TreeInfo[i][E_TREE_POS][0]);
			cache_get_value_name_float(i, "posy", TreeInfo[i][E_TREE_POS][1]);
			cache_get_value_name_float(i, "posz", TreeInfo[i][E_TREE_POS][2]);
			cache_get_value_name_float(i, "posrx", TreeInfo[i][E_TREE_POS][3]);
			cache_get_value_name_float(i, "posry", TreeInfo[i][E_TREE_POS][4]);
			cache_get_value_name_float(i, "posrz", TreeInfo[i][E_TREE_POS][5]);
			cache_get_value_name_int(i, "time", TreeInfo[i][E_TREE_TIMER]);
			Tree_Spawn(i);
		}
		printf("[SERVER]: %i tree were loaded from \"%s\" database...", rows, SQL_DATABASE);
	}
	return 1;
}

stock Tree_Refresh(id)
{
	if(TreeInfo[id][E_TREE_EXISTS])
	{
		Streamer_SetFloatData(STREAMER_TYPE_OBJECT, TreeInfo[id][E_TREE_OBJECT], E_STREAMER_X, TreeInfo[id][E_TREE_POS][0]);
		Streamer_SetFloatData(STREAMER_TYPE_OBJECT, TreeInfo[id][E_TREE_OBJECT], E_STREAMER_Y, TreeInfo[id][E_TREE_POS][1]);
		Streamer_SetFloatData(STREAMER_TYPE_OBJECT, TreeInfo[id][E_TREE_OBJECT], E_STREAMER_Z, TreeInfo[id][E_TREE_POS][2]);
		Streamer_SetFloatData(STREAMER_TYPE_OBJECT, TreeInfo[id][E_TREE_OBJECT], E_STREAMER_R_X, TreeInfo[id][E_TREE_POS][3]);
		Streamer_SetFloatData(STREAMER_TYPE_OBJECT, TreeInfo[id][E_TREE_OBJECT], E_STREAMER_R_Y, TreeInfo[id][E_TREE_POS][4]);
		Streamer_SetFloatData(STREAMER_TYPE_OBJECT, TreeInfo[id][E_TREE_OBJECT], E_STREAMER_R_Z, TreeInfo[id][E_TREE_POS][5]);

		Streamer_SetFloatData(STREAMER_TYPE_AREA, TreeInfo[id][E_TREE_AREA], E_STREAMER_X, TreeInfo[id][E_TREE_POS][0]);
		Streamer_SetFloatData(STREAMER_TYPE_AREA, TreeInfo[id][E_TREE_AREA], E_STREAMER_Y, TreeInfo[id][E_TREE_POS][1]);
		Streamer_SetFloatData(STREAMER_TYPE_AREA, TreeInfo[id][E_TREE_AREA], E_STREAMER_Z, TreeInfo[id][E_TREE_POS][2]);
	}
	return 1;
}

function:OnTreeCreated(id)
{
	TreeInfo[id][E_TREE_DBID] = cache_insert_id();
	Tree_Save(id);
}

stock Tree_Spawn(id)
{
	if(TreeInfo[id][E_TREE_EXISTS])
	{
		TreeInfo[id][E_TREE_AREA] = CreateDynamicSphere(TreeInfo[id][E_TREE_POS][0], TreeInfo[id][E_TREE_POS][1], TreeInfo[id][E_TREE_POS][2], 2.5);

		if(TreeInfo[id][E_TREE_TIMER] < 1)
			TreeInfo[id][E_TREE_OBJECT] = CreateDynamicObject(657, TreeInfo[id][E_TREE_POS][0], TreeInfo[id][E_TREE_POS][1], TreeInfo[id][E_TREE_POS][2], TreeInfo[id][E_TREE_POS][3], TreeInfo[id][E_TREE_POS][4], TreeInfo[id][E_TREE_POS][5], -1, -1, -1, 500.0, 500.0);	
	}
	return 1;
}

stock Tree_Delete(id)
{
	if(!TreeInfo[id][E_TREE_EXISTS])
		return 0;

	if(IsValidDynamicObject(TreeInfo[id][E_TREE_OBJECT]))
		DestroyDynamicObject(TreeInfo[id][E_TREE_OBJECT]);

	if(IsValidDynamicArea(TreeInfo[id][E_TREE_AREA]))
		DestroyDynamicArea(TreeInfo[id][E_TREE_AREA]);

	new str[64];
	mysql_format(ourConnection, str, sizeof(str), "DELETE FROM `tree`  WHERE `id` = '%d'", TreeInfo[id][E_TREE_DBID]);
	mysql_tquery(ourConnection, str);

	TreeInfo[id][E_TREE_DBID] = 0;
	TreeInfo[id][E_TREE_EXISTS] = false;
	return 1;
}

function:OnTreeUpdate()
{
    forex(i, MAX_TREES) if(TreeInfo[i][E_TREE_EXISTS] && TreeInfo[i][E_TREE_TIMER] > 0)
	{
		TreeInfo[i][E_TREE_TIMER]--;
		if(TreeInfo[i][E_TREE_TIMER] <= 0)
		{
			TreeInfo[i][E_TREE_CUTTED] = false;
			TreeInfo[i][E_TREE_OBJECT] = CreateDynamicObject(657, TreeInfo[i][E_TREE_POS][0], TreeInfo[i][E_TREE_POS][1], TreeInfo[i][E_TREE_POS][2], TreeInfo[i][E_TREE_POS][3], TreeInfo[i][E_TREE_POS][4], TreeInfo[i][E_TREE_POS][5], -1, -1, -1, 500.0, 500.0);
			Tree_Refresh(i);
		}
	}
	return 1;
}

CMD:createtree(playerid, params[])
{
	if(IsPlayerAdmins(playerid) < 4)
		return SendUnauthMessage(playerid);

	new id;

	id = Tree_Create(playerid);

	if(id == -1)
		return SendErrorMessage(playerid, "You can't make anymore trees.");

	PlayerInfo[playerid][E_CHARACTER_EDITINGOBJECT] = 4;
    PlayerInfo[playerid][E_CHARACTER_OBJECTID] = id;
	EditDynamicObject(playerid, TreeInfo[id][E_TREE_OBJECT]);
	SendServerMessage(playerid, "You created tree ID #%i. To configure, use \"/destroytree\"", id);
	return 1;
}

CMD:destroytree(playerid, params[])
{
	if(IsPlayerAdmins(playerid) < 4)
		return 0;

	new id;
	if(sscanf(params, "d", id))
		return SendUsageMessage(playerid, "/destroytree [Tree ID]");

	if(id > MAX_TREES || !TreeInfo[id][E_TREE_EXISTS])
		return SendErrorMessage(playerid, "You specified an invalid tree ID.");

	Tree_Delete(id);
	SendServerMessage(playerid, "You have destroyed tree ID #%d", id);
	return 1;	
}