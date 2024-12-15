
function:Query_LoadPropertiesStorage(houseid)
{
	new rows, fields; 
	cache_get_row_count(rows);
	cache_get_field_count(fields);
	new countpsafe = 0;
	for (new i = 0; i != rows; i ++) {
		PropertyStorage[houseid][i][E_PSTORAGE_EXISTS] = true;
        cache_get_value_name_int(i, "itemID", PropertyStorage[houseid][i][E_PSTORAGE_ITEMID]);
        cache_get_value_name_int(i, "itemModel", PropertyStorage[houseid][i][E_PSTORAGE_MODEL]);
        cache_get_value_name_int(i, "itemQuantity", PropertyStorage[houseid][i][E_PSTORAGE_QUANTITY]);
        cache_get_value_name(i, "itemName", PropertyStorage[houseid][i][E_PSTORAGE_NAME], 128);
		countpsafe++;
	}
	printf("[SERVER]: %i property storage were loaded from \"%s\" database...", countpsafe, SQL_DATABASE);
	return 1;
}

stock Property_ShowItems(playerid, houseid)
{
    if (houseid == -1)
	    return 0;

	static
	    string[MAX_PROPERTY_STORAGE * 32],
		name[32];

	string[0] = 0;

	for (new i = 0; i != MAX_PROPERTY_STORAGE; i ++)
	{
	    if (!PropertyStorage[houseid][i][E_PSTORAGE_EXISTS])
	        format(string, sizeof(string), "%s[SLOT]: <Empty>\n", string);

		else {
			strunpack(name, PropertyStorage[houseid][i][E_PSTORAGE_NAME]);

			if (PropertyStorage[houseid][i][E_PSTORAGE_QUANTITY] == 1) {
			    format(string, sizeof(string), "%s[SLOT]: %s\n", string, name);
			}
			else format(string, sizeof(string), "%s[SLOT]: %s\t%d\n", string, name, PropertyStorage[houseid][i][E_PSTORAGE_QUANTITY]);
		}
	}
	ShowPlayerDialog(playerid, DIALOG_PROPERTY_ITEMS, DIALOG_STYLE_LIST, "Item Storage:", string, "Select", "Cancel");
	return 1;
}

stock Property_GetItemID(houseid, item[])
{
	if (houseid == -1)
	    return 0;

	for (new i = 0; i < MAX_PROPERTY_STORAGE; i ++)
	{
	    if (!PropertyStorage[houseid][i][E_PSTORAGE_EXISTS])
	        continue;

		if (!strcmp(PropertyStorage[houseid][i][E_PSTORAGE_NAME], item)) return i;
	}
	return -1;
}

stock Property_GetFreeID(houseid)
{
	if (houseid == -1)
	    return 0;

	for (new i = 0; i < MAX_PROPERTY_STORAGE; i ++)
	{
	    if (!PropertyStorage[houseid][i][E_PSTORAGE_EXISTS])
	        return i;
	}
	return -1;
}

stock Property_AddItem(houseid, item[], model, quantity = 1, slotid = -1)
{
    if (houseid == -1)
	    return 0;

	new
		itemid = Property_GetItemID(houseid, item),
		string[128];

	if (itemid == -1)
	{
	    itemid = Property_GetFreeID(houseid);

	    if (itemid != -1)
	    {
	        if (slotid != -1)
	            itemid = slotid;

	        PropertyStorage[houseid][itemid][E_PSTORAGE_EXISTS] = true;
	        PropertyStorage[houseid][itemid][E_PSTORAGE_MODEL] = model;
	        PropertyStorage[houseid][itemid][E_PSTORAGE_QUANTITY] = quantity;

	        strpack(PropertyStorage[houseid][itemid][E_PSTORAGE_NAME], item, 32 char);

			format(string, sizeof(string), "INSERT INTO `propertiesstorage` (`ID`, `itemName`, `itemModel`, `itemQuantity`) VALUES('%d', '%s', '%d', '%d')", PropertyInfo[houseid][E_PROPERTY_DBID], item, model, quantity);
			mysql_pquery(ourConnection, string, "OnStorageAdd", "dd", houseid, itemid);

	        return itemid;
		}
		return -1;
	}
	else
	{
	    format(string, sizeof(string), "UPDATE `propertiesstorage` SET `itemQuantity` = `itemQuantity` + %d WHERE `ID` = '%d' AND `itemID` = '%d'", quantity, PropertyInfo[houseid][E_PROPERTY_DBID], PropertyStorage[houseid][itemid][E_PSTORAGE_ITEMID]);
	    mysql_pquery(ourConnection, string);

	    PropertyStorage[houseid][itemid][E_PSTORAGE_QUANTITY] += quantity;
	}
	return itemid;
}

function:OnStorageAdd(houseid, itemid)
{
	PropertyStorage[houseid][itemid][E_PSTORAGE_ITEMID] = cache_insert_id();
	return 1;
}

stock Property_RemoveItem(houseid, item[], quantity = 1)
{
    if (houseid == -1)
	    return 0;

	new
		itemid = Property_GetItemID(houseid, item),
		string[128];

	if (itemid != -1)
	{
	    if (PropertyStorage[houseid][itemid][E_PSTORAGE_QUANTITY] > 0)
	    {
	        PropertyStorage[houseid][itemid][E_PSTORAGE_QUANTITY] -= quantity;
		}
		if (quantity == -1 || PropertyStorage[houseid][itemid][E_PSTORAGE_QUANTITY] < 1)
		{
		    PropertyStorage[houseid][itemid][E_PSTORAGE_EXISTS] = false;
		    PropertyStorage[houseid][itemid][E_PSTORAGE_MODEL] = 0;
		    PropertyStorage[houseid][itemid][E_PSTORAGE_QUANTITY] = 0;

		    format(string, sizeof(string), "DELETE FROM `propertiesstorage` WHERE `ID` = '%d' AND `itemID` = '%d'", PropertyInfo[houseid][E_PROPERTY_DBID], PropertyStorage[houseid][itemid][E_PSTORAGE_ITEMID]);
	        mysql_pquery(ourConnection, string);
		}
		else if (quantity != -1 && PropertyStorage[houseid][itemid][E_PSTORAGE_QUANTITY] > 0)
		{
			format(string, sizeof(string), "UPDATE `propertiesstorage` SET `itemQuantity` = `itemQuantity` - %d WHERE `ID` = '%d' AND `itemID` = '%d'", quantity, PropertyInfo[houseid][E_PROPERTY_DBID], PropertyStorage[houseid][itemid][E_PSTORAGE_ITEMID]);
            mysql_pquery(ourConnection, string);
		}
		return 1;
	}
	return 0;
}

Property_RemoveAllItems(houseid)
{
	static
	    query[64];

	for (new i = 0; i != MAX_PROPERTY_STORAGE; i ++) {
        PropertyStorage[houseid][i][E_PSTORAGE_EXISTS] = false;
        PropertyStorage[houseid][i][E_PSTORAGE_MODEL] = 0;
        PropertyStorage[houseid][i][E_PSTORAGE_QUANTITY] = 0;
	}
	format(query, 64, "DELETE FROM `propertiesstorage` WHERE `ID` = '%d'", PropertyInfo[houseid][E_PROPERTY_DBID]);
	mysql_pquery(ourConnection, query);
	return 1;
}