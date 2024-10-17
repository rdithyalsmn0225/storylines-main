
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
	Dialog_Show(playerid, PropertyItems, DIALOG_STYLE_LIST, "Item Storage:", string, "Select", "Cancel");
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

Dialog:PropertyItems(playerid, response, listitem, inputtext[])
{
    static
	    houseid = -1,
		string[64];

	if ((houseid = IsPlayerInProperty(playerid)) != -1 && (PropertyInfo[houseid][E_PROPERTY_OWNERDBID] == PlayerInfo[playerid][E_CHARACTER_DBID]) || ReturnFactionType(playerid) == FACTION_TYPE_POLICE)
	{
		if (response)
		{
    		if (PropertyStorage[houseid][listitem][E_PSTORAGE_EXISTS])
			{
   				PlayerInfo[playerid][E_CHARACTER_STORAGEITEM] = listitem;

				strunpack(string, PropertyStorage[houseid][listitem][E_PSTORAGE_NAME]);

				format(string, sizeof(string), "%s (Quantity: %d)", string, PropertyStorage[houseid][listitem][E_PSTORAGE_QUANTITY]);
				Dialog_Show(playerid, StorageOptions, DIALOG_STYLE_LIST, string, "Take Item\nStore Item", "Select", "Back");
			}
			else 
            {
   				OpenInventory(playerid);
				PlayerInfo[playerid][E_CHARACTER_STORAGESELECT] = 2;
			}
		}
	}
	return 1;
}

Dialog:StorageOptions(playerid, response, listitem, inputtext[])
{
    static
	    houseid = -1,
		itemid = -1,
		string[32];

	if ((houseid = IsPlayerInProperty(playerid)) != -1 && (PropertyInfo[houseid][E_PROPERTY_OWNERDBID] == PlayerInfo[playerid][E_CHARACTER_DBID]) || ReturnFactionType(playerid) == FACTION_TYPE_POLICE)
	{
	    itemid = PlayerInfo[playerid][E_CHARACTER_STORAGEITEM];

	    strunpack(string, PropertyStorage[houseid][itemid][E_PSTORAGE_NAME]);

		if (response)
		{
			switch (listitem)
			{
			    case 0:
			    {
			        if (PropertyStorage[houseid][itemid][E_PSTORAGE_QUANTITY] == 1)
			        {
			            new id = Inventory_Add(playerid, string, PropertyStorage[houseid][itemid][E_PSTORAGE_MODEL], 1);

						if (id == -1)
        					return SendErrorMessage(playerid, "You don't have any inventory slots left.");

			            Property_RemoveItem(houseid, string);

						Property_ShowItems(playerid, houseid);
			        }
			        else
			        {
                        new str[512];
						format(str, sizeof(str), "Item: %s (Quantity: %d)\n\nPlease enter the quantity that you wish to take for this item:", string, PropertyStorage[houseid][itemid][E_PSTORAGE_QUANTITY]);
			            Dialog_Show(playerid, PropertyTake, DIALOG_STYLE_INPUT, "Property Safe Take:", str, "Take", "Back");
			        }
			    }
				case 1:
				{
					new id = Inventory_GetItemID(playerid, string);

					if (id == -1) {
						Property_ShowItems(playerid, houseid);

						return SendErrorMessage(playerid, "You don't have anymore of this item to store!");
					}
					else if (InventoryInfo[playerid][id][E_INVENTORY_QUANTITY] == 1)
					{
					    Property_AddItem(houseid, string, InventoryInfo[playerid][id][E_INVENTORY_MODEL]);
						Inventory_Remove(playerid, string);

						Property_ShowItems(playerid, houseid);
					}
					else if (InventoryInfo[playerid][id][E_INVENTORY_QUANTITY] > 1) {
					    PlayerInfo[playerid][E_CHARACTER_LISTITEM] = id;

                        new str[512];
				        format(str, sizeof(str), "Item: %s (Quantity: %d)\n\nPlease enter the quantity that you wish to store for this item:", string, InventoryInfo[playerid][id][E_INVENTORY_QUANTITY]);
                        Dialog_Show(playerid, PropertyDeposit, DIALOG_STYLE_INPUT, "Property Safe Place:", str, "Place", "Back");
					}
				}
			}
		}
		else
		{
		    Property_ShowItems(playerid, houseid);
		}
	}
	return 1;
}

Dialog:PropertyDeposit(playerid, response, listitem, inputtext[])
{
	static
	    houseid = -1,
	    string[32];

    if ((houseid = IsPlayerInProperty(playerid)) != -1 && (PropertyInfo[houseid][E_PROPERTY_OWNERDBID] == PlayerInfo[playerid][E_CHARACTER_DBID]) || ReturnFactionType(playerid) == FACTION_TYPE_POLICE)
	{
	    strunpack(string, InventoryInfo[playerid][PlayerInfo[playerid][E_CHARACTER_LISTITEM]][E_INVENTORY_ITEM]);

		if (response)
		{
			new amount = strval(inputtext);

			if (amount < 1 || amount > InventoryInfo[playerid][PlayerInfo[playerid][E_CHARACTER_LISTITEM]][E_INVENTORY_QUANTITY])
            {
                new str[512];
				format(str, sizeof(str), "Item: %s (Quantity: %d)\n\nPlease enter the quantity that you wish to store for this item:", string, InventoryInfo[playerid][PlayerInfo[playerid][E_CHARACTER_LISTITEM]][E_INVENTORY_QUANTITY]);
			    return Dialog_Show(playerid, PropertyDeposit, DIALOG_STYLE_INPUT, "Property Safe Place:", str, "Place", "Back");
            }

			Property_AddItem(houseid, string, InventoryInfo[playerid][PlayerInfo[playerid][E_CHARACTER_LISTITEM]][E_INVENTORY_MODEL], amount);
			Inventory_Remove(playerid, string, amount);

			Property_ShowItems(playerid, houseid);
		}
	}
	return 1;
}

Dialog:PropertyTake(playerid, response, listitem, inputtext[])
{
	static
	    houseid = -1,
	    string[32];

    if ((houseid = IsPlayerInProperty(playerid)) != -1 && (PropertyInfo[houseid][E_PROPERTY_OWNERDBID] == PlayerInfo[playerid][E_CHARACTER_DBID]) || ReturnFactionType(playerid) == FACTION_TYPE_POLICE)
	{
	    strunpack(string, PropertyStorage[houseid][PlayerInfo[playerid][E_CHARACTER_STORAGEITEM]][E_PSTORAGE_NAME]);

		if (response)
		{
			new amount = strval(inputtext);

			if (amount < 1 || amount > PropertyStorage[houseid][PlayerInfo[playerid][E_CHARACTER_STORAGEITEM]][E_PSTORAGE_QUANTITY])
            {
                new str[512];
				format(str, sizeof(str), "Item: %s (Quantity: %d)\n\nPlease enter the quantity that you wish to take for this item:", string, PropertyStorage[houseid][PlayerInfo[playerid][E_CHARACTER_LISTITEM]][E_PSTORAGE_QUANTITY]);
			    return Dialog_Show(playerid, PropertyTake, DIALOG_STYLE_INPUT, "Property Safe Take:", str, "Take", "Back");
            }

			new id = Inventory_Add(playerid, string, PropertyStorage[houseid][PlayerInfo[playerid][E_CHARACTER_STORAGEITEM]][E_PSTORAGE_MODEL], amount);

			if (id == -1)
				return SendErrorMessage(playerid, "You don't have any inventory slots left.");

			Property_RemoveItem(houseid, string, amount);
			
			Property_ShowItems(playerid, houseid);
		}
	}
	return 1;
}