//Spraytags
stock Spraytags_Delete(spid)
{
	if (spid != -1 && SpraytagsInfo[spid][E_SPRAYTAGS_EXISTS])
	{
	    new
	        string[64];

		format(string, sizeof(string), "DELETE FROM `spray_tags` WHERE `id` = '%d'", SpraytagsInfo[spid][E_SPRAYTAGS_DBID]);
		mysql_pquery(ourConnection, string);

        for(new i = 0; i < 32; i++)
        {
            if (IsValidDynamicObject(SpraytagsInfo[spid][E_SPRAYTAGS_OBJECT]))
	            DestroyDynamicObject(SpraytagsInfo[spid][E_SPRAYTAGS_OBJECT]);
        }

	    SpraytagsInfo[spid][E_SPRAYTAGS_EXISTS] = false;
	    SpraytagsInfo[spid][E_SPRAYTAGS_DBID] = 0;
	}
	return 1;
}

Spraytags_Nearest(playerid)
{
    for (new i = 0; i != MAX_SPRAYTAGS; i ++) if (SpraytagsInfo[i][E_SPRAYTAGS_EXISTS] && IsPlayerInRangeOfPoint(playerid, 2.5, SpraytagsInfo[i][E_SPRAYTAGS_POS][0], SpraytagsInfo[i][E_SPRAYTAGS_POS][1], SpraytagsInfo[i][E_SPRAYTAGS_POS][2]))
	{
		if (GetPlayerInterior(playerid) == SpraytagsInfo[i][E_SPRAYTAGS_INTERIOR] && GetPlayerVirtualWorld(playerid) == SpraytagsInfo[i][E_SPRAYTAGS_WORLD])
			return i;
	}
	return -1;
}

stock Spraytags_Create(playerid, modelid, owner, Float:x, Float:y, Float:z, Float:rx, Float:ry, Float:rz)
{
	DestroyDynamicObject(PlayerInfo[playerid][E_CHARACTER_ADDOBJECT]); 
	PlayerInfo[playerid][E_CHARACTER_EDITINGOBJECT] = 0; 
	PlayerInfo[playerid][E_CHARACTER_OBJECTID] = 0;
	PlayerInfo[playerid][E_CHARACTER_OBJECTTYPE] = 0;

	for (new i = 0; i < MAX_SPRAYTAGS; i ++) if (!SpraytagsInfo[i][E_SPRAYTAGS_EXISTS])
	{
	    SpraytagsInfo[i][E_SPRAYTAGS_EXISTS] = true;
	    SpraytagsInfo[i][E_SPRAYTAGS_OBJECTID]	= modelid;
	    SpraytagsInfo[i][E_SPRAYTAGS_TYPE]	= 1;
	    SpraytagsInfo[i][E_SPRAYTAGS_OWNER] = owner;
        SpraytagsInfo[i][E_SPRAYTAGS_POS][0] = x;
        SpraytagsInfo[i][E_SPRAYTAGS_POS][1] = y;
        SpraytagsInfo[i][E_SPRAYTAGS_POS][2] = z;
        SpraytagsInfo[i][E_SPRAYTAGS_POS][3] = rx;
        SpraytagsInfo[i][E_SPRAYTAGS_POS][4] = ry;
        SpraytagsInfo[i][E_SPRAYTAGS_POS][5] = rz;

        SpraytagsInfo[i][E_SPRAYTAGS_INTERIOR] = GetPlayerInterior(playerid);
        SpraytagsInfo[i][E_SPRAYTAGS_WORLD] = GetPlayerVirtualWorld(playerid);

		Spraytags_Refresh(i, modelid);
		mysql_pquery(ourConnection, "INSERT INTO `spray_tags` (`interior`) VALUES(0)", "OnSpraytagsCreated", "d", i);

		return i;
	}
	return -1;
}

stock Spraytags_Refresh(spid, modelid)
{
	if (spid != -1 && SpraytagsInfo[spid][E_SPRAYTAGS_EXISTS])
	{
        if (IsValidDynamicObject(SpraytagsInfo[spid][E_SPRAYTAGS_OBJECT]))
	        DestroyDynamicObject(SpraytagsInfo[spid][E_SPRAYTAGS_OBJECT]);

        if(SpraytagsInfo[spid][E_SPRAYTAGS_TYPE] == 1)
        {
		    SpraytagsInfo[spid][E_SPRAYTAGS_OBJECT] = CreateDynamicObject(modelid, SpraytagsInfo[spid][E_SPRAYTAGS_POS][0], SpraytagsInfo[spid][E_SPRAYTAGS_POS][1], SpraytagsInfo[spid][E_SPRAYTAGS_POS][2], SpraytagsInfo[spid][E_SPRAYTAGS_POS][3], SpraytagsInfo[spid][E_SPRAYTAGS_POS][4], SpraytagsInfo[spid][E_SPRAYTAGS_POS][5], SpraytagsInfo[spid][E_SPRAYTAGS_WORLD], SpraytagsInfo[spid][E_SPRAYTAGS_INTERIOR]);
        }
        else if(SpraytagsInfo[spid][E_SPRAYTAGS_TYPE] == 2)
        {
            SpraytagsInfo[spid][E_SPRAYTAGS_OBJECT] = CreateDynamicObject(19482, SpraytagsInfo[spid][E_SPRAYTAGS_POS][0], SpraytagsInfo[spid][E_SPRAYTAGS_POS][1], SpraytagsInfo[spid][E_SPRAYTAGS_POS][2], SpraytagsInfo[spid][E_SPRAYTAGS_POS][3], SpraytagsInfo[spid][E_SPRAYTAGS_POS][4], SpraytagsInfo[spid][E_SPRAYTAGS_POS][5]+180, SpraytagsInfo[spid][E_SPRAYTAGS_WORLD], SpraytagsInfo[spid][E_SPRAYTAGS_INTERIOR]);
            SetDynamicObjectMaterialText(SpraytagsInfo[spid][E_SPRAYTAGS_OBJECT], 0, SpraytagsInfo[spid][E_SPRAYTAGS_TEXT], OBJECT_MATERIAL_SIZE_512x256, SpraytagsInfo[spid][E_SPRAYTAGS_FONT], 40, 1, SpraytagsInfo[spid][E_SPRAYTAGS_COLOR], 0, OBJECT_MATERIAL_TEXT_ALIGN_CENTER);
        }
        return 1;
	}
	return 0;
}

stock Spraytags_Save(spid)
{
	new
	    query[512];

	format(query, sizeof(query), "UPDATE `spray_tags` SET `posx` = '%.4f', `posy` = '%.4f', `posz` = '%.4f', `posrx` = '%.4f', `posry` = '%.4f', `posrz` = '%.4f', `interior` = '%d', `vw` = '%d', `models` = '%d', `Type` = '%d', `Text` = '%s', `Font` = '%s', `color` = '%d', `owner` = '%d'  WHERE `id` = '%d'",
	    SpraytagsInfo[spid][E_SPRAYTAGS_POS][0],
	    SpraytagsInfo[spid][E_SPRAYTAGS_POS][1],
	    SpraytagsInfo[spid][E_SPRAYTAGS_POS][2],
	    SpraytagsInfo[spid][E_SPRAYTAGS_POS][3],
	    SpraytagsInfo[spid][E_SPRAYTAGS_POS][4],
	    SpraytagsInfo[spid][E_SPRAYTAGS_POS][5],
	    SpraytagsInfo[spid][E_SPRAYTAGS_INTERIOR],
	    SpraytagsInfo[spid][E_SPRAYTAGS_WORLD],
	    SpraytagsInfo[spid][E_SPRAYTAGS_OBJECTID],
	    SpraytagsInfo[spid][E_SPRAYTAGS_TYPE],
        SpraytagsInfo[spid][E_SPRAYTAGS_TEXT],
        SpraytagsInfo[spid][E_SPRAYTAGS_FONT],
        SpraytagsInfo[spid][E_SPRAYTAGS_COLOR],
	    SpraytagsInfo[spid][E_SPRAYTAGS_OWNER],
	    SpraytagsInfo[spid][E_SPRAYTAGS_DBID]
	);
	return mysql_pquery(ourConnection, query);
}

function:Query_SpraytagsLoad()
{
    static
	    rows,
	    fields;

	cache_get_row_count(rows);
	cache_get_field_count(fields);

	for (new i = 0; i < rows; i ++) if (i < MAX_SPRAYTAGS)
	{
	    SpraytagsInfo[i][E_SPRAYTAGS_EXISTS] = true;
	    cache_get_value_name_int(i, "id", SpraytagsInfo[i][E_SPRAYTAGS_DBID]);
	    cache_get_value_name_float(i, "posx", SpraytagsInfo[i][E_SPRAYTAGS_POS][0]);
        cache_get_value_name_float(i, "posy", SpraytagsInfo[i][E_SPRAYTAGS_POS][1]);
        cache_get_value_name_float(i, "posz", SpraytagsInfo[i][E_SPRAYTAGS_POS][2]);
        cache_get_value_name_float(i, "posrx", SpraytagsInfo[i][E_SPRAYTAGS_POS][3]);
        cache_get_value_name_float(i, "posry", SpraytagsInfo[i][E_SPRAYTAGS_POS][4]);
        cache_get_value_name_float(i, "posrz", SpraytagsInfo[i][E_SPRAYTAGS_POS][5]);
        cache_get_value_name_int(i, "interior", SpraytagsInfo[i][E_SPRAYTAGS_INTERIOR]);
		cache_get_value_name_int(i, "vw", SpraytagsInfo[i][E_SPRAYTAGS_WORLD]);
		cache_get_value_name_int(i, "models", SpraytagsInfo[i][E_SPRAYTAGS_OBJECTID]);
		cache_get_value_name_int(i, "type", SpraytagsInfo[i][E_SPRAYTAGS_TYPE]);
        cache_get_value_name(i, "text", SpraytagsInfo[i][E_SPRAYTAGS_TEXT], 128);
        cache_get_value_name(i, "font", SpraytagsInfo[i][E_SPRAYTAGS_FONT], 128);
        cache_get_value_name_int(i, "color", SpraytagsInfo[i][E_SPRAYTAGS_COLOR]);
		cache_get_value_name_int(i, "owner", SpraytagsInfo[i][E_SPRAYTAGS_OWNER]);

		Spraytags_Refresh(i, SpraytagsInfo[i][E_SPRAYTAGS_OBJECTID]);
	}
	return 1;
}

function:OnSpraytagsCreated(spid)
{
    if (spid == -1 || !SpraytagsInfo[spid][E_SPRAYTAGS_EXISTS])
		return 0;

	SpraytagsInfo[spid][E_SPRAYTAGS_DBID] = cache_insert_id();
 	Spraytags_Save(spid);

	return 1;
}

function:SprayingTags(playerid, inputtext[], type, Float:x, Float:y, Float:z, Float:rx, Float:ry, Float:rz)
{
    new id = Spraytags_Nearest(playerid);

    switch(type)
    {
        case 1: //Static Spraytags
        {
			if(id != -1)
			{
                if (IsValidDynamicObject(SpraytagsInfo[id][E_SPRAYTAGS_OBJECT]))
                    DestroyDynamicObject(SpraytagsInfo[id][E_SPRAYTAGS_OBJECT]);

                if(SpraytagsInfo[id][E_SPRAYTAGS_TYPE] == 1)
                {
				    SpraytagsInfo[id][E_SPRAYTAGS_OBJECT] = CreateDynamicObject(PlayerInfo[playerid][E_CHARACTER_OBJECTID], SpraytagsInfo[id][E_SPRAYTAGS_POS][0], SpraytagsInfo[id][E_SPRAYTAGS_POS][1], SpraytagsInfo[id][E_SPRAYTAGS_POS][2], SpraytagsInfo[id][E_SPRAYTAGS_POS][3], SpraytagsInfo[id][E_SPRAYTAGS_POS][4], SpraytagsInfo[id][E_SPRAYTAGS_POS][5], SpraytagsInfo[id][E_SPRAYTAGS_WORLD], SpraytagsInfo[id][E_SPRAYTAGS_INTERIOR]);
                }
                else if(SpraytagsInfo[id][E_SPRAYTAGS_TYPE] == 2)
                {
				    SpraytagsInfo[id][E_SPRAYTAGS_OBJECT] = CreateDynamicObject(PlayerInfo[playerid][E_CHARACTER_OBJECTID], SpraytagsInfo[id][E_SPRAYTAGS_POS][0], SpraytagsInfo[id][E_SPRAYTAGS_POS][1], SpraytagsInfo[id][E_SPRAYTAGS_POS][2], SpraytagsInfo[id][E_SPRAYTAGS_POS][3], SpraytagsInfo[id][E_SPRAYTAGS_POS][4], SpraytagsInfo[id][E_SPRAYTAGS_POS][5], SpraytagsInfo[id][E_SPRAYTAGS_WORLD], SpraytagsInfo[id][E_SPRAYTAGS_INTERIOR]);
                }

                SpraytagsInfo[id][E_SPRAYTAGS_OBJECTID] = PlayerInfo[playerid][E_CHARACTER_OBJECTID];
                SpraytagsInfo[id][E_SPRAYTAGS_OWNER] = PlayerInfo[playerid][E_CHARACTER_OBJECTOWN];
                SpraytagsInfo[id][E_SPRAYTAGS_TYPE] = 1;

                format(SpraytagsInfo[id][E_SPRAYTAGS_TEXT], 128, inputtext);

                PlayerInfo[playerid][E_CHARACTER_EDITINGOBJECT] = 0; 
                PlayerInfo[playerid][E_CHARACTER_OBJECTTYPE] = 0;

                RemovePlayerAttachedObject(playerid, 8);
                RemovePlayerAttachedObject(playerid, 9);
                ClearAnimations(playerid);
                Spraytags_Save(id);
				//TurfsPoints(playerid, IsPlayerNearTurf(playerid));
                
				if(PlayerInfo[playerid][E_CHARACTER_EQUIPITEMS] > INVENTORY_NONE)
				{
					ResetVarInventory(playerid);
				}

				Inventory_Remove(playerid, "Spraycan", 1);
            }
        }
        case 2: //Custom Spraytags
        {
			if(id != -1)
			{
                if (IsValidDynamicObject(SpraytagsInfo[id][E_SPRAYTAGS_OBJECT]))
                    DestroyDynamicObject(SpraytagsInfo[id][E_SPRAYTAGS_OBJECT]);
            
                if(SpraytagsInfo[id][E_SPRAYTAGS_TYPE] == 1)
                {
                    SpraytagsInfo[id][E_SPRAYTAGS_OBJECT] = CreateDynamicObject(19482, SpraytagsInfo[id][E_SPRAYTAGS_POS][0], SpraytagsInfo[id][E_SPRAYTAGS_POS][1], SpraytagsInfo[id][E_SPRAYTAGS_POS][2], SpraytagsInfo[id][E_SPRAYTAGS_POS][3], SpraytagsInfo[id][E_SPRAYTAGS_POS][4], SpraytagsInfo[id][E_SPRAYTAGS_POS][5]+180, SpraytagsInfo[id][E_SPRAYTAGS_WORLD], SpraytagsInfo[id][E_SPRAYTAGS_INTERIOR]);
                    SetDynamicObjectMaterialText(SpraytagsInfo[id][E_SPRAYTAGS_OBJECT], 0, PlayerInfo[playerid][E_CHARACTER_OBJECTSTRING], OBJECT_MATERIAL_SIZE_512x256, PlayerInfo[playerid][E_CHARACTER_OBJECTFONT], 40, 1, PlayerInfo[playerid][E_CHARACTER_OBJECTCOLOR], 0, OBJECT_MATERIAL_TEXT_ALIGN_CENTER);
                }
                else if(SpraytagsInfo[id][E_SPRAYTAGS_TYPE] == 2)
                {
                    SpraytagsInfo[id][E_SPRAYTAGS_OBJECT] = CreateDynamicObject(19482, SpraytagsInfo[id][E_SPRAYTAGS_POS][0], SpraytagsInfo[id][E_SPRAYTAGS_POS][1], SpraytagsInfo[id][E_SPRAYTAGS_POS][2], SpraytagsInfo[id][E_SPRAYTAGS_POS][3], SpraytagsInfo[id][E_SPRAYTAGS_POS][4], SpraytagsInfo[id][E_SPRAYTAGS_POS][5], SpraytagsInfo[id][E_SPRAYTAGS_WORLD], SpraytagsInfo[id][E_SPRAYTAGS_INTERIOR]);
                    SetDynamicObjectMaterialText(SpraytagsInfo[id][E_SPRAYTAGS_OBJECT], 0, PlayerInfo[playerid][E_CHARACTER_OBJECTSTRING], OBJECT_MATERIAL_SIZE_512x256, PlayerInfo[playerid][E_CHARACTER_OBJECTFONT], 40, 1, PlayerInfo[playerid][E_CHARACTER_OBJECTCOLOR], 0, OBJECT_MATERIAL_TEXT_ALIGN_CENTER);
                }

                SpraytagsInfo[id][E_SPRAYTAGS_OBJECTID] = 19482;
                SpraytagsInfo[id][E_SPRAYTAGS_OWNER] = PlayerInfo[playerid][E_CHARACTER_OBJECTOWN];
                SpraytagsInfo[id][E_SPRAYTAGS_TYPE] = 2;
                
                format(SpraytagsInfo[id][E_SPRAYTAGS_TEXT], 128, PlayerInfo[playerid][E_CHARACTER_OBJECTSTRING]);
                SpraytagsInfo[id][E_SPRAYTAGS_COLOR] = PlayerInfo[playerid][E_CHARACTER_OBJECTCOLOR];
                format(SpraytagsInfo[id][E_SPRAYTAGS_FONT], 128, PlayerInfo[playerid][E_CHARACTER_OBJECTFONT]);

                PlayerInfo[playerid][E_CHARACTER_EDITINGOBJECT] = 0; 
                PlayerInfo[playerid][E_CHARACTER_OBJECTTYPE] = 0;

                RemovePlayerAttachedObject(playerid, 8);
                RemovePlayerAttachedObject(playerid, 9);
                ClearAnimations(playerid);
                Spraytags_Save(id);
				
                if(PlayerInfo[playerid][E_CHARACTER_EQUIPITEMS] > INVENTORY_NONE)
                {
                    ResetVarInventory(playerid);
                    format(SpraytagsInfo[id][E_SPRAYTAGS_TEXT], 32, "");
                    format(SpraytagsInfo[id][E_SPRAYTAGS_FONT], 32, "");
                }
                Inventory_Remove(playerid, "Spraycan", 1);
            }
        }
        case 3: //Admin Creator
        {
			id = Spraytags_Create(playerid, PlayerInfo[playerid][E_CHARACTER_OBJECTID], PlayerInfo[playerid][E_CHARACTER_OBJECTOWN], x, y, z, rx, ry, rz);
	    			
	    	if (id == -1)
	    		return SendErrorMessage(playerid, "You can't make anymore spraytags.");	

            RemovePlayerAttachedObject(playerid, 8);
            RemovePlayerAttachedObject(playerid, 9);
            ClearAnimations(playerid);
			Inventory_Remove(playerid, "Spraycan", 1);

			if(PlayerInfo[playerid][E_CHARACTER_EQUIPITEMS] > INVENTORY_NONE)
			{
				ResetVarInventory(playerid);
			}
        }
    }
    return 1;
}

CMD:spray(playerid, params[])
{
	if(PlayerInfo[playerid][E_CHARACTER_EQUIPITEMS] != SPRAYCAN)
		return SendErrorMessage(playerid, "You must hold the spraycan in your hands.");

    if(ReturnFactionType(playerid) != FACTION_TYPE_ILLEGAL)
        return SendErrorMessage(playerid, "You can't make spraytags because you are not apart in a gang."); 

    if(!Inventory_Count(playerid, "Spraycan"))
        return SendErrorMessage(playerid, "You don't have any spraycan in your inventory."); 
        
    ShowModelSelectionMenu(playerid, "Spraytags", MODEL_SELECTION_SPRAYTAGS, g_aSpraytags, sizeof(g_aSpraytags), -5.0, -4.0, -89);
	return 1;
}