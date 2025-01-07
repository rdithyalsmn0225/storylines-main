stock Item_Delete(itemid)
{
    new
	    query[64];

    if (itemid != -1 && DroppedInfo[itemid][E_DROPPED_MODEL])
	{
        DroppedInfo[itemid][E_DROPPED_MODEL] = 0;
		DroppedInfo[itemid][E_DROPPED_QUANTITY] = 0;
	    DroppedInfo[itemid][E_DROPPED_POS][0] = 0.0;
	    DroppedInfo[itemid][E_DROPPED_POS][1] = 0.0;
	    DroppedInfo[itemid][E_DROPPED_POS][2] = 0.0;
	    DroppedInfo[itemid][E_DROPPED_INTERIOR] = 0;
	    DroppedInfo[itemid][E_DROPPED_WORLD] = 0;

		DestroyDynamic3DTextLabel(DroppedInfo[itemid][E_DROPPED_3DTEXT]);
	    DestroyDynamicObject(DroppedInfo[itemid][E_DROPPED_OBJECT]);

		if(DroppedInfo[itemid][E_DROPPED_TYPE] == E_DROPPED_TYPE_BOOMBOX)
		{
			if(IsValidDynamicArea(BoomboxInfo[itemid][E_BOOMBOX_AREA])) {

				DestroyDynamicArea(BoomboxInfo[itemid][E_BOOMBOX_AREA]) ;
				BoomboxInfo[itemid][E_BOOMBOX_AREA] = -1;
			}
			BoomboxInfo[itemid][E_BOOMBOX_STATUS] = false;
		}


	    mysql_format(ourConnection, query, sizeof(query), "DELETE FROM `dropped` WHERE `ID` = '%d'", DroppedInfo[itemid][E_DROPPED_DBID]);
	    mysql_pquery(ourConnection, query);
	}
	return 1;
}

stock Item_Nearest(playerid)
{
    for (new i = 0; i != MAX_DROPPED_ITEMS; i ++) if (DroppedInfo[i][E_DROPPED_MODEL] && IsPlayerInRangeOfPoint(playerid, 1.5, DroppedInfo[i][E_DROPPED_POS][0], DroppedInfo[i][E_DROPPED_POS][1], DroppedInfo[i][E_DROPPED_POS][2]))
	{
	    if (GetPlayerInterior(playerid) == DroppedInfo[i][E_DROPPED_INTERIOR] && GetPlayerVirtualWorld(playerid) == DroppedInfo[i][E_DROPPED_WORLD])
	        return i;
	}
	return -1;
}

stock PickupItem(playerid, itemid)
{
	if (itemid != -1 && DroppedInfo[itemid][E_DROPPED_MODEL])
	{
	    new id = Inventory_Add(playerid, DroppedInfo[itemid][E_DROPPED_ITEM], DroppedInfo[itemid][E_DROPPED_MODEL], DroppedInfo[itemid][E_DROPPED_QUANTITY], DroppedInfo[itemid][E_DROPPED_AMOUNT]);

	    if (id == -1)
	        return SendErrorMessage(playerid, "You don't have any inventory slots left.");

	    Item_Delete(itemid);
		StopAudioStreamForPlayer(playerid);
	}
	return 1;
}

function:Query_LoadDropped()
{
	static
	    rows,
	    fields;

    cache_get_row_count(rows);
	cache_get_field_count(fields);

	for (new i = 0; i < rows; i ++) if (i < MAX_DROPPED_ITEMS)
	{
	    cache_get_value_name_int(i, "ID", DroppedInfo[i][E_DROPPED_DBID]);

		cache_get_value_name(i, "itemName", DroppedInfo[i][E_DROPPED_ITEM], 32);
		cache_get_value_name(i, "itemPlayer", DroppedInfo[i][E_DROPPED_PLAYER], 24);

		cache_get_value_name_int(i, "itemModel", DroppedInfo[i][E_DROPPED_MODEL]);
		cache_get_value_name_int(i, "itemQuantity", DroppedInfo[i][E_DROPPED_QUANTITY]);
		cache_get_value_name_int(i, "itemType", DroppedInfo[i][E_DROPPED_TYPE]);
		cache_get_value_name_int(i, "itemAmount", DroppedInfo[i][E_DROPPED_AMOUNT]);
		cache_get_value_name_float(i, "itemX", DroppedInfo[i][E_DROPPED_POS][0]);
		cache_get_value_name_float(i, "itemY", DroppedInfo[i][E_DROPPED_POS][1]);
		cache_get_value_name_float(i, "itemZ", DroppedInfo[i][E_DROPPED_POS][2]);
		cache_get_value_name_float(i, "itemRX", DroppedInfo[i][E_DROPPED_POS][3]);
		cache_get_value_name_float(i, "itemRY", DroppedInfo[i][E_DROPPED_POS][4]);
		cache_get_value_name_float(i, "itemRZ", DroppedInfo[i][E_DROPPED_POS][5]);
		cache_get_value_name_int(i, "itemInt", DroppedInfo[i][E_DROPPED_INTERIOR]);
		cache_get_value_name_int(i, "itemWorld", DroppedInfo[i][E_DROPPED_WORLD]);

		if(DroppedInfo[i][E_DROPPED_TYPE] == E_DROPPED_TYPE_BOOMBOX)
		{
			new str[128];
			format(str, sizeof(str), "[%s]\n{ffffff}Available Commands: /boombox", DroppedInfo[i][E_DROPPED_ITEM]);
			DroppedInfo[i][E_DROPPED_3DTEXT] = CreateDynamic3DTextLabel(str, COLOR_3DTEXT, DroppedInfo[i][E_DROPPED_POS][0], DroppedInfo[i][E_DROPPED_POS][1], DroppedInfo[i][E_DROPPED_POS][2], 3.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, DroppedInfo[i][E_DROPPED_WORLD], DroppedInfo[i][E_DROPPED_INTERIOR]);
			DroppedInfo[i][E_DROPPED_OBJECT] = CreateDynamicObject(DroppedInfo[i][E_DROPPED_MODEL], DroppedInfo[i][E_DROPPED_POS][0], DroppedInfo[i][E_DROPPED_POS][1], DroppedInfo[i][E_DROPPED_POS][2], DroppedInfo[i][E_DROPPED_POS][3], DroppedInfo[i][E_DROPPED_POS][4], DroppedInfo[i][E_DROPPED_POS][5], DroppedInfo[i][E_DROPPED_WORLD], DroppedInfo[i][E_DROPPED_INTERIOR]);
		}
		else if(DroppedInfo[i][E_DROPPED_TYPE] == E_DROPPED_TYPE_DRUGS_PIZZA || DroppedInfo[i][E_DROPPED_TYPE] == E_DROPPED_TYPE_DRUGS_BURGER || DroppedInfo[i][E_DROPPED_TYPE] == E_DROPPED_TYPE_DRUGS_SHOE)
		{
			new str[128];
			format(str, sizeof(str), "[%s]\n{ffffff}Available Commands: /getdrugs", DroppedInfo[i][E_DROPPED_ITEM]);
			DroppedInfo[i][E_DROPPED_3DTEXT] = CreateDynamic3DTextLabel(str, COLOR_3DTEXT, DroppedInfo[i][E_DROPPED_POS][0], DroppedInfo[i][E_DROPPED_POS][1], DroppedInfo[i][E_DROPPED_POS][2], 3.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, DroppedInfo[i][E_DROPPED_WORLD], DroppedInfo[i][E_DROPPED_INTERIOR]);
			DroppedInfo[i][E_DROPPED_OBJECT] = CreateDynamicObject(1582, DroppedInfo[i][E_DROPPED_POS][0], DroppedInfo[i][E_DROPPED_POS][1], DroppedInfo[i][E_DROPPED_POS][2], DroppedInfo[i][E_DROPPED_POS][3], DroppedInfo[i][E_DROPPED_POS][4], DroppedInfo[i][E_DROPPED_POS][5], DroppedInfo[i][E_DROPPED_WORLD], DroppedInfo[i][E_DROPPED_INTERIOR]);
		}
		else if(DroppedInfo[i][E_DROPPED_TYPE] == E_DROPPED_TYPE_DRUGS_BURGER)
		{
			new str[128];
			format(str, sizeof(str), "[%s]\n{ffffff}Available Commands: /getdrugs", DroppedInfo[i][E_DROPPED_ITEM]);
			DroppedInfo[i][E_DROPPED_3DTEXT] = CreateDynamic3DTextLabel(str, COLOR_3DTEXT, DroppedInfo[i][E_DROPPED_POS][0], DroppedInfo[i][E_DROPPED_POS][1], DroppedInfo[i][E_DROPPED_POS][2], 3.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, DroppedInfo[i][E_DROPPED_WORLD], DroppedInfo[i][E_DROPPED_INTERIOR]);
			DroppedInfo[i][E_DROPPED_OBJECT] = CreateDynamicObject(19811, DroppedInfo[i][E_DROPPED_POS][0], DroppedInfo[i][E_DROPPED_POS][1], DroppedInfo[i][E_DROPPED_POS][2], DroppedInfo[i][E_DROPPED_POS][3], DroppedInfo[i][E_DROPPED_POS][4], DroppedInfo[i][E_DROPPED_POS][5], DroppedInfo[i][E_DROPPED_WORLD], DroppedInfo[i][E_DROPPED_INTERIOR]);
		}
		else if(DroppedInfo[i][E_DROPPED_TYPE] == E_DROPPED_TYPE_DRUGS_SHOE)
		{
			new str[128];
			format(str, sizeof(str), "[%s]\n{ffffff}Available Commands: /getdrugs", DroppedInfo[i][E_DROPPED_ITEM]);
			DroppedInfo[i][E_DROPPED_3DTEXT] = CreateDynamic3DTextLabel(str, COLOR_3DTEXT, DroppedInfo[i][E_DROPPED_POS][0], DroppedInfo[i][E_DROPPED_POS][1], DroppedInfo[i][E_DROPPED_POS][2], 3.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, DroppedInfo[i][E_DROPPED_WORLD], DroppedInfo[i][E_DROPPED_INTERIOR]);
			DroppedInfo[i][E_DROPPED_OBJECT] = CreateDynamicObject(2694, DroppedInfo[i][E_DROPPED_POS][0], DroppedInfo[i][E_DROPPED_POS][1], DroppedInfo[i][E_DROPPED_POS][2], DroppedInfo[i][E_DROPPED_POS][3], DroppedInfo[i][E_DROPPED_POS][4], DroppedInfo[i][E_DROPPED_POS][5], DroppedInfo[i][E_DROPPED_WORLD], DroppedInfo[i][E_DROPPED_INTERIOR]);
		}
		else if(DroppedInfo[i][E_DROPPED_TYPE] == E_DROPPED_TYPE_PISH)
		{
			new str[128];
			format(str, sizeof(str), "[%s]\n{ffffff}Available Commands: /getdrink", DroppedInfo[i][E_DROPPED_ITEM]);
			DroppedInfo[i][E_DROPPED_3DTEXT] = CreateDynamic3DTextLabel(str, COLOR_3DTEXT, DroppedInfo[i][E_DROPPED_POS][0], DroppedInfo[i][E_DROPPED_POS][1], DroppedInfo[i][E_DROPPED_POS][2], 3.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, DroppedInfo[i][E_DROPPED_WORLD], DroppedInfo[i][E_DROPPED_INTERIOR]);
			DroppedInfo[i][E_DROPPED_OBJECT] = CreateDynamicObject(DroppedInfo[i][E_DROPPED_MODEL], DroppedInfo[i][E_DROPPED_POS][0], DroppedInfo[i][E_DROPPED_POS][1], DroppedInfo[i][E_DROPPED_POS][2], DroppedInfo[i][E_DROPPED_POS][3], DroppedInfo[i][E_DROPPED_POS][4], DroppedInfo[i][E_DROPPED_POS][5], DroppedInfo[i][E_DROPPED_WORLD], DroppedInfo[i][E_DROPPED_INTERIOR]);
			SetDynamicObjectMaterial(DroppedInfo[i][E_DROPPED_OBJECT], 0, 1551, "cj_bar", "CJ_old_pish", 0xFFFFFFFF);
		}
		else if(DroppedInfo[i][E_DROPPED_TYPE] == E_DROPPED_TYPE_SPRUNK)
		{
			new str[128];
			format(str, sizeof(str), "[%s]\n{ffffff}Available Commands: /getdrink", DroppedInfo[i][E_DROPPED_ITEM]);
			DroppedInfo[i][E_DROPPED_3DTEXT] = CreateDynamic3DTextLabel(str, COLOR_3DTEXT, DroppedInfo[i][E_DROPPED_POS][0], DroppedInfo[i][E_DROPPED_POS][1], DroppedInfo[i][E_DROPPED_POS][2], 3.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, DroppedInfo[i][E_DROPPED_WORLD], DroppedInfo[i][E_DROPPED_INTERIOR]);
			DroppedInfo[i][E_DROPPED_OBJECT] = CreateDynamicObject(DroppedInfo[i][E_DROPPED_MODEL], DroppedInfo[i][E_DROPPED_POS][0], DroppedInfo[i][E_DROPPED_POS][1], DroppedInfo[i][E_DROPPED_POS][2], DroppedInfo[i][E_DROPPED_POS][3], DroppedInfo[i][E_DROPPED_POS][4], DroppedInfo[i][E_DROPPED_POS][5], DroppedInfo[i][E_DROPPED_WORLD], DroppedInfo[i][E_DROPPED_INTERIOR]);
			SetDynamicObjectMaterial(DroppedInfo[i][E_DROPPED_OBJECT], 0, 2354, "burger_tray", "sprunk_cb", 0xFFFFFFFF);
		}
		else
		{
			new str[128];
			format(str, sizeof(str), "[%s]", DroppedInfo[i][E_DROPPED_ITEM]);
			DroppedInfo[i][E_DROPPED_3DTEXT] = CreateDynamic3DTextLabel(str, COLOR_3DTEXT, DroppedInfo[i][E_DROPPED_POS][0], DroppedInfo[i][E_DROPPED_POS][1], DroppedInfo[i][E_DROPPED_POS][2], 3.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, DroppedInfo[i][E_DROPPED_WORLD], DroppedInfo[i][E_DROPPED_INTERIOR]);
		}
	}
	printf("[SERVER]: %i dropped items were loaded from \"%s\" database...", rows, SQL_DATABASE);
	return 1;
}

DropItem(item[], player[], model, quantity, Float:x, Float:y, Float:z, Float:rx, Float:ry, Float:rz, interior, world, type = 0, amount = 0)
{
	new
	    query[512];

	for (new i = 0; i != MAX_DROPPED_ITEMS; i ++) if (!DroppedInfo[i][E_DROPPED_MODEL])
	{
	    format(DroppedInfo[i][E_DROPPED_ITEM], 32, item);
	    format(DroppedInfo[i][E_DROPPED_PLAYER], 24, player);

		DroppedInfo[i][E_DROPPED_MODEL] = model;
		DroppedInfo[i][E_DROPPED_QUANTITY] = quantity;
		DroppedInfo[i][E_DROPPED_AMOUNT] = amount;
  		DroppedInfo[i][E_DROPPED_TYPE] = type;
		DroppedInfo[i][E_DROPPED_POS][0] = x;
		DroppedInfo[i][E_DROPPED_POS][1] = y;
		DroppedInfo[i][E_DROPPED_POS][2] = z;
		DroppedInfo[i][E_DROPPED_POS][3] = rx;
		DroppedInfo[i][E_DROPPED_POS][4] = ry;
		DroppedInfo[i][E_DROPPED_POS][5] = rz;

		DroppedInfo[i][E_DROPPED_INTERIOR] = interior;
		DroppedInfo[i][E_DROPPED_WORLD] = world;

		if(type == E_DROPPED_TYPE_BOOMBOX)
		{
			new str[128];
			format(str, sizeof(str), "[%s]\n{ffffff}Available Commands: /boombox", item);
			DroppedInfo[i][E_DROPPED_3DTEXT] = CreateDynamic3DTextLabel(str, COLOR_3DTEXT, x, y, z, 3.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, world, interior);
			BoomboxInfo[i][E_BOOMBOX_STATUS] = false;
			format(BoomboxInfo[i][E_BOOMBOX_STATUS], 256, "");
			BoomboxInfo[i][E_BOOMBOX_AREA] = CreateDynamicCircle(x, y, 30.0, world, interior);
			DroppedInfo[i][E_DROPPED_OBJECT] = CreateDynamicObject(model, x, y, z, rx, ry, rz, world, interior);
		}
		else if(type == E_DROPPED_TYPE_DRUGS_PIZZA)
		{
			new str[128];
			format(str, sizeof(str), "[%s]\n{ffffff}Available Commands: /getdrugs", item);
			DroppedInfo[i][E_DROPPED_3DTEXT] = CreateDynamic3DTextLabel(str, COLOR_3DTEXT, x, y, z, 3.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, world, interior);
			DroppedInfo[i][E_DROPPED_OBJECT] = CreateDynamicObject(1582, x, y, z, rx, ry, rz, world, interior);
		}
		else if(type == E_DROPPED_TYPE_DRUGS_BURGER)
		{
			new str[128];
			format(str, sizeof(str), "[%s]\n{ffffff}Available Commands: /getdrugs", item);
			DroppedInfo[i][E_DROPPED_3DTEXT] = CreateDynamic3DTextLabel(str, COLOR_3DTEXT, x, y, z, 3.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, world, interior);
			DroppedInfo[i][E_DROPPED_OBJECT] = CreateDynamicObject(19811, x, y, z, rx, ry, rz, world, interior);
		}
		else if(type == E_DROPPED_TYPE_DRUGS_SHOE)
		{
			new str[128];
			format(str, sizeof(str), "[%s]\n{ffffff}Available Commands: /getdrugs", item);
			DroppedInfo[i][E_DROPPED_3DTEXT] = CreateDynamic3DTextLabel(str, COLOR_3DTEXT, x, y, z, 3.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, world, interior);
			DroppedInfo[i][E_DROPPED_OBJECT] = CreateDynamicObject(2694, x, y, z, rx, ry, rz, world, interior);
		}
		else if(type == E_DROPPED_TYPE_PISH)
		{
			new str[128];
			format(str, sizeof(str), "[%s]\n{ffffff}Available Commands: /getdrink", item);
			DroppedInfo[i][E_DROPPED_3DTEXT] = CreateDynamic3DTextLabel(str, COLOR_3DTEXT, x, y, z, 3.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, world, interior);
			DroppedInfo[i][E_DROPPED_OBJECT] = CreateDynamicObject(model, x, y, z, rx, ry, rz, world, interior);
			SetDynamicObjectMaterial(DroppedInfo[i][E_DROPPED_OBJECT], 0, 1551, "cj_bar", "CJ_old_pish", 0xFFFFFFFF);
		}
		else if(type == E_DROPPED_TYPE_SPRUNK)
		{
			new str[128];
			format(str, sizeof(str), "[%s]\n{ffffff}Available Commands: /getdrink", item);
			DroppedInfo[i][E_DROPPED_3DTEXT] = CreateDynamic3DTextLabel(str, COLOR_3DTEXT, x, y, z, 3.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, world, interior);
			DroppedInfo[i][E_DROPPED_OBJECT] = CreateDynamicObject(model, x, y, z, rx, ry, rz, world, interior);
			SetDynamicObjectMaterial(DroppedInfo[i][E_DROPPED_OBJECT], 0, 2354, "burger_tray", "sprunk_cb", 0xFFFFFFFF);
		}
		else 
		{
			new str[128];
			format(str, sizeof(str), "[%s]", item);
			DroppedInfo[i][E_DROPPED_3DTEXT] = CreateDynamic3DTextLabel(str, COLOR_3DTEXT, x, y, z, 3.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, world, interior);
			DroppedInfo[i][E_DROPPED_OBJECT] = CreateDynamicObject(model, x, y, z, rx, ry, rz, world, interior);
		}

 		format(query, sizeof(query), "INSERT INTO `dropped` (`itemName`, `itemPlayer`, `itemModel`, `itemQuantity`, `itemAmount`, `itemType`, `itemX`, `itemY`, `itemZ`, `itemRX`, `itemRY`, `itemRZ`, `itemInt`, `itemWorld`) VALUES('%s', '%s', '%d', '%d', '%d', '%d', '%.4f', '%.4f', '%.4f', '%.4f', '%.4f', '%.4f', '%d', '%d')", item, player, model, quantity, amount, type, x, y, z, rx, ry, rz, interior, world);
		mysql_pquery(ourConnection, query, "OnDroppedItem", "d", i);
		return i;
	}
	return -1;
}

function:OnDroppedItem(itemid)
{
	if (itemid == -1 || !DroppedInfo[itemid][E_DROPPED_MODEL])
	    return 0;

	DroppedInfo[itemid][E_DROPPED_DBID] = cache_insert_id();
	return 1;
}

DropPlayerItem(playerid, itemid, quantity = 1, type = 0)
{
	if (itemid == -1 || !InventoryInfo[playerid][itemid][E_INVENTORY_EXISTS])
	    return 0;

    new
		Float:x,
  		Float:y,
    	Float:z,
		Float:angle,
		string[32];

	strunpack(string, InventoryInfo[playerid][itemid][E_INVENTORY_ITEM]);

	GetPlayerPos(playerid, x, y, z);
	GetPlayerFacingAngle(playerid, angle);

	PlayerInfo[playerid][E_CHARACTER_OBJECTID] = InventoryInfo[playerid][itemid][E_INVENTORY_MODEL];
	PlayerInfo[playerid][E_CHARACTER_OBJECTQUANTITY] = quantity;
	PlayerInfo[playerid][E_CHARACTER_OBJECTAMOUNT] = InventoryInfo[playerid][itemid][E_INVENTORY_AMOUNT];
	PlayerInfo[playerid][E_CHARACTER_OBJECTTYPE] = type;
	format(PlayerInfo[playerid][E_CHARACTER_OBJECTSTRING], 512, string);

	Dialog_Show(playerid, DialogDropitems, DIALOG_STYLE_MSGBOX, "Dropped Items:", "Select your dropped items type 'Static' or 'Cursor'.", "Static", "Cursor");
	return 1;
}