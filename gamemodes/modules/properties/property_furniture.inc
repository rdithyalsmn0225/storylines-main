Streamer_GetExtraInt(objectid, type)
{
	new extra[11];

	if(Streamer_GetArrayData(STREAMER_TYPE_OBJECT, objectid, E_STREAMER_EXTRA_ID, extra, sizeof(extra)))
	{
		return extra[type];
	}

	return 0;
}

Streamer_SetExtraInt(objectid, type, value)
{
	new extra[11];

    if(Streamer_GetArrayData(STREAMER_TYPE_OBJECT, objectid, E_STREAMER_EXTRA_ID, extra, sizeof(extra)))
    {
	    extra[type] = value;
		return Streamer_SetArrayData(STREAMER_TYPE_OBJECT, objectid, E_STREAMER_EXTRA_ID, extra, sizeof(extra));
	}

	return 0;
}

GetPropertyFurniture(propid)
{
	switch(PropertyInfo[propid][E_PROPERTY_TYPE])
	{
	    case 1: return 30;
	    case 2: return 50;
	    case 3: return 75;
	}
	return 0;
}

RemoveFurniture(objectid)
{
    if(IsValidDynamicObject(objectid) && Streamer_GetExtraInt(objectid, E_OBJECT_TYPE) == E_OBJECT_FURNITURE)
	{
 		new
	        id = Streamer_GetExtraInt(objectid, E_OBJECT_INDEX_ID);

	    DeleteFurnitureObject(objectid);

		new queryBuffer[512];
	    mysql_format(ourConnection, queryBuffer, sizeof(queryBuffer), "DELETE FROM furniture WHERE id = %i", id);
	    mysql_tquery(ourConnection, queryBuffer);
	}
}

DeleteFurnitureObject(objectid)
{
	if(IsValidDynamicObject(objectid) && Streamer_GetExtraInt(objectid, E_OBJECT_TYPE) == E_OBJECT_FURNITURE)
	{
    	new Text3D:textid = Text3D:Streamer_GetExtraInt(objectid, E_OBJECT_3DTEXT_ID);

        if(IsValidDynamic3DTextLabel(textid))
        {
            DestroyDynamic3DTextLabel(textid);
        }

        DestroyDynamicObject(objectid);
	}
}

SetFurnitureMaterial(playerid, objectid, materialslot, modelid, txd[], texturename[])
{
	new gquery[512];
	if(IsValidDynamicObject(objectid) && Streamer_GetExtraInt(objectid, E_OBJECT_TYPE) == E_OBJECT_FURNITURE)
	{
		SetDynamicObjectMaterial(objectid, materialslot, modelid, txd, texturename, HexToInt("0xFFFFFFFF"));

		mysql_format(ourConnection, gquery, sizeof(gquery), "UPDATE `furniture` SET `matModel%i` = '%i', `matTxd%i` = '%e', `matTexture%i` = '%e' WHERE `id` = '%i'",
			materialslot,
			modelid,
			materialslot,
			txd,
			materialslot,
			texturename,
			Streamer_GetExtraInt(objectid, E_OBJECT_INDEX_ID)
		);
		mysql_pquery(ourConnection, gquery);
	}
	SendPropertyMessage(playerid, "[Property] {cdcdcd}You are added material texture for #%d index #%d set into %d %s %s.", objectid, materialslot, modelid, txd, texturename);
}

RemoveAllFurniture(propid)
{  
	for(new i = 0; i <= Streamer_GetUpperBound(STREAMER_TYPE_OBJECT); i ++)
	{
		if(IsValidDynamicObject(i) && Streamer_GetExtraInt(i, E_OBJECT_TYPE) == E_OBJECT_FURNITURE && Streamer_GetExtraInt(i, E_OBJECT_EXTRA_ID) == PropertyInfo[propid][E_PROPERTY_DBID] && Streamer_GetExtraInt(i, E_OBJECT_TYPE_ID) == 0)
		{
			DeleteFurnitureObject(i);
		}
	}

	new queryBuffer[512];
	mysql_format(ourConnection, queryBuffer, sizeof(queryBuffer), "DELETE FROM furniture WHERE propertydbid = %i AND type = %i", PropertyInfo[propid][E_PROPERTY_DBID], 0);
	mysql_tquery(ourConnection, queryBuffer);
}


ReloadFurniture(objectid, labels)
{
	if(IsValidDynamicObject(objectid) && Streamer_GetExtraInt(objectid, E_OBJECT_TYPE) == E_OBJECT_FURNITURE)
	{
	    new
	        id = Streamer_GetExtraInt(objectid, E_OBJECT_INDEX_ID);

	    DeleteFurnitureObject(objectid);

		new queryBuffer[512];
	    mysql_format(ourConnection, queryBuffer, sizeof(queryBuffer), "SELECT * FROM furniture WHERE id = %i", id);
	    mysql_tquery(ourConnection, queryBuffer, "Query_LoadFurniture", "i", labels);
	}
}

ReloadAllFurniture(propid)
{
	for(new i = 0; i <= Streamer_GetUpperBound(STREAMER_TYPE_OBJECT); i ++)
	{
		 if(IsValidDynamicObject(i) && Streamer_GetExtraInt(i, E_OBJECT_TYPE) == E_OBJECT_FURNITURE && Streamer_GetExtraInt(i, E_OBJECT_EXTRA_ID) == PropertyInfo[propid][E_PROPERTY_DBID])
		{
			DeleteFurnitureObject(i);
		}
	}

	new queryBuffer[512];
	mysql_format(ourConnection, queryBuffer, sizeof(queryBuffer), "SELECT * FROM furniture WHERE propertydbid = %i", PropertyInfo[propid][E_PROPERTY_DBID]);
	mysql_tquery(ourConnection, queryBuffer, "Query_LoadFurniture", "i", PropertyInfo[propid][E_PROPERTY_LABELS]);
}

function:Query_LoadFurniture(labels)
{
	new rows; 
	cache_get_row_count(rows);
	
	for(new i = 0; i < rows; i++)
	{
		new Float: pos[6], dbid, propdbid, modelid, world, int, prices, type, objectid;

		cache_get_value_name_int(i, "id", dbid);
		cache_get_value_name_int(i, "propertydbid", propdbid);
		cache_get_value_name_int(i, "modelid", modelid);
		cache_get_value_name_int(i, "price", prices);
		cache_get_value_name_int(i, "type", type);
		cache_get_value_name_float(i, "pos_x", pos[0]);
		cache_get_value_name_float(i, "pos_y", pos[1]);
		cache_get_value_name_float(i, "pos_z", pos[2]);
		cache_get_value_name_float(i, "rot_x", pos[3]);
		cache_get_value_name_float(i, "rot_y", pos[4]);
		cache_get_value_name_float(i, "rot_z", pos[5]);		
		cache_get_value_name_int(i, "world", world);
		cache_get_value_name_int(i, "interior", int);

		new matmodels, mattxds[32], mattexture[32], str[128], str1[128], str2[128];

		objectid = CreateDynamicObject(modelid, pos[0], pos[1], pos[2], pos[3], pos[4], pos[5], world, int);
		Streamer_SetExtraInt(objectid, E_OBJECT_TYPE, E_OBJECT_FURNITURE);
		Streamer_SetExtraInt(objectid, E_OBJECT_INDEX_ID, dbid);
		Streamer_SetExtraInt(objectid, E_OBJECT_EXTRA_ID, propdbid);
		Streamer_SetExtraInt(objectid, E_OBJECT_TYPE_ID, type);

		for(new a; a < 15; a++)
		{
			format(str, sizeof(str), "matModel%d", a);
			cache_get_value_name_int(i, str, matmodels);

			format(str1, sizeof(str1), "matTxd%d", a);
			cache_get_value_name(i, str1, mattxds, 32);

			format(str2, sizeof(str2), "matTexture%d", a);
			cache_get_value_name(i, str2, mattexture, 32);

			SetDynamicObjectMaterial(objectid, a, matmodels, mattxds, mattexture, 0);
		}

		if(labels == 1)
		{
			new string[128], name[128], Text3D:text3ds;
			cache_get_value_name(i, "name", name, 128);
			format(string, sizeof(string), "[%i]\n{ffffff}%s", objectid, name);
			text3ds = CreateDynamic3DTextLabel(string, COLOR_3DTEXT, pos[0], pos[1], pos[2], 10.0, .worldid = world, .interiorid = int);
			Streamer_SetExtraInt(objectid, E_OBJECT_3DTEXT_ID, text3ds);
		}
	}
	return 1;
}

function:FurnitureSell(playerid)
{
	new rows;
	if(cache_get_row_count(rows))
	{
		new prices;
		cache_get_value_name_int(0, "price", prices);
		new name[32], price = percent(prices, 75);

		cache_get_value_name(0, "name", name);
		GiveMoney(playerid, price);

		SendServerMessage(playerid, "[Furniture] {cdcdcd}You have sold %s and received a 75 percent refund of $%i.", name, price);
		RemoveFurniture(PlayerInfo[playerid][E_CHARACTER_LISTITEM]);
	}
	return 1;
}

function:FurnitureClear(playerid)
{
	new rows;
	cache_get_row_count(rows);
	if(!rows)
		return SendErrorMessage(playerid, "There is no furniture in your properties.");
	else
	{
		new price, propid = IsPlayerInProperty(playerid);
		new prices;
		for(new i = 0; i < rows; i ++)
		{
			cache_get_value_name_int(i, "price", prices);
			price += percent(prices, 75);
		}

		RemoveAllFurniture(propid);

		GiveMoney(playerid, price);
		SendServerMessage(playerid, "[Furniture] {cdcdcd}You have sold a total of %i items and received $%i.", rows, price);
	}
	return 1;
}

function:FurnitureCount(playerid)
{
	new houseid = IsPlayerInProperty(playerid);
	new rows;
	if(cache_get_row_count(rows) >= GetPropertyFurniture(houseid))
	{
		return SendErrorMessage(playerid, "Your properties is only allowed up to %i furniture.", GetPropertyFurniture(houseid));
	}
	else
	{
		ShowFurnituresCategories(playerid);
	}
	return 1;
}

ShowFurnituresCategories(playerid)
{
	new string[512];
	for(new i = 0; i < sizeof(g_aFurnitureCategories); i ++)
	{
		format(string, sizeof(string), "%s%s\n", string, g_aFurnitureCategories[i]);
	}

	ShowPlayerDialog(playerid, DIALOG_FURNITURE_PURCHASE, DIALOG_STYLE_LIST, "Furnitures Categories:", string, "Select", "Cancel");
	return 1;
}