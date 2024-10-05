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

	    DestroyDynamicObject(DroppedInfo[itemid][E_DROPPED_OBJECT]);

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
	    new id = Inventory_Add(playerid, DroppedInfo[itemid][E_DROPPED_ITEM], DroppedInfo[itemid][E_DROPPED_MODEL], DroppedInfo[itemid][E_DROPPED_QUANTITY]);

	    if (id == -1)
	        return SendErrorMessage(playerid, "You don't have any inventory slots left.");

	    Item_Delete(itemid);
	}
	return 1;
}

function:Query_DroppedLoad()
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

		
		DroppedInfo[i][E_DROPPED_OBJECT] = CreateDynamicObject(DroppedInfo[i][E_DROPPED_MODEL], DroppedInfo[i][E_DROPPED_POS][0], DroppedInfo[i][E_DROPPED_POS][1], DroppedInfo[i][E_DROPPED_POS][2], DroppedInfo[i][E_DROPPED_POS][3], DroppedInfo[i][E_DROPPED_POS][4], DroppedInfo[i][E_DROPPED_POS][5], DroppedInfo[i][E_DROPPED_WORLD], DroppedInfo[i][E_DROPPED_INTERIOR]);
	}
	printf("[SERVER]: %i dropped items were loaded from \"%s\" database...", rows, SQL_DATABASE);
	return 1;
}

DropItem(item[], player[], model, quantity, Float:x, Float:y, Float:z, Float:rx, Float:ry, Float:rz, interior, world, type = 0)
{
	new
	    query[1024];

	for (new i = 0; i != MAX_DROPPED_ITEMS; i ++) if (!DroppedInfo[i][E_DROPPED_MODEL])
	{
	    format(DroppedInfo[i][E_DROPPED_ITEM], 32, item);
	    format(DroppedInfo[i][E_DROPPED_PLAYER], 24, player);

		DroppedInfo[i][E_DROPPED_MODEL] = model;
		DroppedInfo[i][E_DROPPED_QUANTITY] = quantity;
  		DroppedInfo[i][E_DROPPED_TYPE] = type;
		DroppedInfo[i][E_DROPPED_POS][0] = x;
		DroppedInfo[i][E_DROPPED_POS][1] = y;
		DroppedInfo[i][E_DROPPED_POS][2] = z;
		DroppedInfo[i][E_DROPPED_POS][3] = rx;
		DroppedInfo[i][E_DROPPED_POS][4] = ry;
		DroppedInfo[i][E_DROPPED_POS][5] = rz;

		DroppedInfo[i][E_DROPPED_INTERIOR] = interior;
		DroppedInfo[i][E_DROPPED_WORLD] = world;

		DroppedInfo[i][E_DROPPED_OBJECT] = CreateDynamicObject(model, x, y, z, rx, ry, rz, world, interior);

 		format(query, sizeof(query), "INSERT INTO `dropped` (`itemName`, `itemPlayer`, `itemModel`, `itemQuantity`, `itemType`, `itemX`, `itemY`, `itemZ`, `itemRX`, `itemRY`, `itemRZ`, `itemInt`, `itemWorld`) VALUES('%s', '%s', '%d', '%d', '%d', '%.4f', '%.4f', '%.4f', '%.4f', '%.4f', '%.4f', '%d', '%d')", item, player, model, quantity, type, x, y, z, rx, ry, rz, interior, world);
		mysql_pquery(ourConnection, query, "OnE_DROPPED_ITEM", "d", i);
		return i;
	}
	return -1;
}

function:OnE_DROPPED_ITEM(itemid)
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
	PlayerInfo[playerid][E_CHARACTER_OBJECTTYPE] = type;
	format(PlayerInfo[playerid][E_CHARACTER_OBJECTSTRING], 512, string);

	if(PlayerInfo[playerid][E_CHARACTER_EQUIPITEMS] > INVENTORY_NONE)
	{
		ResetVarInventory(playerid);
	}

	PlayerInfo[playerid][E_CHARACTER_ADDOBJECT] = CreateDynamicObject(InventoryInfo[playerid][itemid][E_INVENTORY_MODEL], x, y, z, 0.0, 0.0, 0.0, GetPlayerVirtualWorld(playerid), GetPlayerInterior(playerid)); 
	EditDynamicObject(playerid, PlayerInfo[playerid][E_CHARACTER_ADDOBJECT]); 
	PlayerInfo[playerid][E_CHARACTER_EDITINGOBJECT] = 5;
	return 1;
}