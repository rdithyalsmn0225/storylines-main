// Function:

function:VehicleStorage_Load(vehicleid)
{
	new
	    rows,
	    fields,
		str[32];

	cache_get_row_count(rows);
	cache_get_field_count(fields);

	for (new i = 0; i != rows; i ++) 
    {
		VstorageInfo[vehicleid][i][E_VEHICLE_TRUNKEXISTS] = true;
		cache_get_value_name_int(i, "itemID", VstorageInfo[vehicleid][i][E_VEHICLE_TRUNKDBID]);
		cache_get_value_name_int(i, "itemModel", VstorageInfo[vehicleid][i][E_VEHICLE_TRUNKMODEL]);
		cache_get_value_name_int(i, "itemQuantity", VstorageInfo[vehicleid][i][E_VEHICLE_TRUNKQUANTITY]);
		cache_get_value_name_int(i, "type", VstorageInfo[vehicleid][i][E_VEHICLE_TRUNKTYPE]);

		cache_get_value_name(i, "itemName", str, sizeof(str));
		strpack(VstorageInfo[vehicleid][i][E_VEHICLE_TRUNKNAME], str, 32 char);
	}

	VehicleObjectUpdates(vehicleid);
	printf("[SERVER]: %s vehicle storage were loaded from \"%s\" database...", ReturnVehicleName(vehicleid), SQL_DATABASE);
	return 1;
}

stock VS_GetItemID(carid, item[])
{
	if (carid == -1 || !VehicleInfo[carid][E_VEHICLE_EXISTS])
	    return 0;

	for (new i = 0; i < MAX_CAR_STORAGE; i ++)
	{
	    if (!VstorageInfo[carid][i][E_VEHICLE_TRUNKEXISTS])
	        continue;

		if (!strcmp(VstorageInfo[carid][i][E_VEHICLE_TRUNKNAME], item)) return i;
	}
	return -1;
}

stock VS_GetFreeID(carid)
{
	if (carid == -1 || !VehicleInfo[carid][E_VEHICLE_EXISTS])
	    return 0;

	for (new i = 0; i < MAX_CAR_STORAGE; i ++)
	{
	    if (!VstorageInfo[carid][i][E_VEHICLE_TRUNKEXISTS])
	        return i;
	}
	return -1;
}

stock VS_Count(carid, item[])
{
	new itemid = VS_GetItemID(carid, item);

	if (itemid != -1)
	    return VstorageInfo[carid][itemid][E_VEHICLE_TRUNKQUANTITY];

	return 0;
}

function:OnVehicleStorageAdd(carid, itemid)
{
	VstorageInfo[carid][itemid][E_VEHICLE_TRUNKDBID] = cache_insert_id();
	return 1;
}

stock VS_AddItem(carid, item[], model, quantity = 1)
{
    if (carid == -1 || !VehicleInfo[carid][E_VEHICLE_EXISTS])
	    return 0;

	new
		itemid = VS_GetItemID(carid, item),
		string[128];

	if (itemid == -1)
	{
	    itemid = VS_GetFreeID(carid);

	    if (itemid != -1)
	    {
	        VstorageInfo[carid][itemid][E_VEHICLE_TRUNKEXISTS] = true;
	        VstorageInfo[carid][itemid][E_VEHICLE_TRUNKMODEL] = model;
	        VstorageInfo[carid][itemid][E_VEHICLE_TRUNKQUANTITY] = quantity;
	
	        strpack(VstorageInfo[carid][itemid][E_VEHICLE_TRUNKNAME], item, 32 char);

			format(string, sizeof(string), "INSERT INTO `vstorage` (`ID`, `itemName`, `itemModel`, `itemQuantity`) VALUES('%d', '%s', '%d', '%d')", VehicleInfo[carid][E_VEHICLE_DBID], item, model, quantity);
			mysql_pquery(ourConnection, string, "OnVehicleStorageAdd", "dd", carid, itemid);
	        return itemid;
		}
		return -1;
	}
	else
	{
	    format(string, sizeof(string), "UPDATE `vstorage` SET `itemQuantity` = `itemQuantity` + %d WHERE `ID` = '%d' AND `itemID` = '%d'", quantity, VehicleInfo[carid][E_VEHICLE_DBID], VstorageInfo[carid][itemid][E_VEHICLE_TRUNKDBID]);
	    mysql_pquery(ourConnection, string);

	    VstorageInfo[carid][itemid][E_VEHICLE_TRUNKQUANTITY] += quantity;
	}
	return itemid;
}

stock VS_RemoveItem(carid, item[], quantity = 1)
{
    if (carid == -1 || !VehicleInfo[carid][E_VEHICLE_EXISTS])
	    return 0;

	new
		itemid = VS_GetItemID(carid, item),
		string[128];

	if (itemid != -1)
	{
	    if (VstorageInfo[carid][itemid][E_VEHICLE_TRUNKQUANTITY] > 0)
	    {
	        VstorageInfo[carid][itemid][E_VEHICLE_TRUNKQUANTITY] -= quantity;
		}
		if (quantity == -1 || VstorageInfo[carid][itemid][E_VEHICLE_TRUNKQUANTITY] < 1)
		{
		    VstorageInfo[carid][itemid][E_VEHICLE_TRUNKEXISTS] = false;
		    VstorageInfo[carid][itemid][E_VEHICLE_TRUNKMODEL] = 0;
		    VstorageInfo[carid][itemid][E_VEHICLE_TRUNKQUANTITY] = 0;

		    format(string, sizeof(string), "DELETE FROM `vstorage` WHERE `ID` = '%d' AND `itemID` = '%d'", VehicleInfo[carid][E_VEHICLE_DBID], VstorageInfo[carid][itemid][E_VEHICLE_TRUNKDBID]);
	        mysql_pquery(ourConnection, string);
		}
		else if (quantity != -1 && VstorageInfo[carid][itemid][E_VEHICLE_TRUNKQUANTITY] > 0)
		{
			format(string, sizeof(string), "UPDATE `vstorage` SET `itemQuantity` = `itemQuantity` - %d WHERE `ID` = '%d' AND `itemID` = '%d'", quantity, VehicleInfo[carid][E_VEHICLE_DBID], VstorageInfo[carid][itemid][E_VEHICLE_TRUNKDBID]);
            mysql_pquery(ourConnection, string);
		}
		return 1;
	}
	return 0;
}

VS_RemoveAllItems(carid)
{
	static
	    query[64];

	for (new i = 0; i != MAX_CAR_STORAGE; i ++) {
        VstorageInfo[carid][i][E_VEHICLE_TRUNKEXISTS] = false;
        VstorageInfo[carid][i][E_VEHICLE_TRUNKMODEL] = 0;
        VstorageInfo[carid][i][E_VEHICLE_TRUNKQUANTITY] = 0;
	}
	format(query, 64, "DELETE FROM `vstorage` WHERE `ID` = '%d'", VehicleInfo[carid][E_VEHICLE_DBID]);
	mysql_pquery(ourConnection, query);
	return 1;
}

stock ShowVehicleStorage(playerid, carid)
{
	static string[MAX_CAR_STORAGE * 32], name[32];

	string[0] = 0;

    format(string, sizeof(string), "Name\tAmount\n");
	for (new i = 0; i != MAX_CAR_STORAGE; i ++)
	{
	    if (!VstorageInfo[carid][i][E_VEHICLE_TRUNKEXISTS])
	        format(string, sizeof(string), "%s[SLOT]: <Empty>\n", string);

		else {
			strunpack(name, VstorageInfo[carid][i][E_VEHICLE_TRUNKNAME]);

			if (VstorageInfo[carid][i][E_VEHICLE_TRUNKQUANTITY] == 1) {
                format(string, sizeof(string), "%s[SLOT]: %s\n", string, name);
			}
			else format(string, sizeof(string), "%s[SLOT]: %s\t%d\n", string, name, VstorageInfo[carid][i][E_VEHICLE_TRUNKQUANTITY]);
		}
	}
	PlayerInfo[playerid][E_CHARACTER_STORAGESELECT] = 0;
	ShowPlayerDialog(playerid, DIALOG_VSTORAGE, DIALOG_STYLE_TABLIST_HEADERS, "Vehicle Storage:", string, "Select", "Cancel");
	return 1;
}

stock CheckVehicleStorage(playerid, carid)
{
	static string[MAX_CAR_STORAGE * 32], name[32];

	string[0] = 0;

    format(string, sizeof(string), "Name\tAmount\n");
	for (new i = 0; i != MAX_CAR_STORAGE; i ++)
	{
	    if (!VstorageInfo[carid][i][E_VEHICLE_TRUNKEXISTS])
	        format(string, sizeof(string), "%s[SLOT]: <Empty>\n", string);

		else {
			strunpack(name, VstorageInfo[carid][i][E_VEHICLE_TRUNKNAME]);

			if (VstorageInfo[carid][i][E_VEHICLE_TRUNKQUANTITY] == 1) {
                format(string, sizeof(string), "%s[SLOT]: %s\n", string, name);
			}
			else format(string, sizeof(string), "%s[SLOT]: %s\t%d\n", string, name, VstorageInfo[carid][i][E_VEHICLE_TRUNKQUANTITY]);
		}
	}
	PlayerInfo[playerid][E_CHARACTER_STORAGESELECT] = 0;
	ShowPlayerDialog(playerid, DIALOG_DEFAULT, DIALOG_STYLE_TABLIST_HEADERS, "Vehicle Storage:", string, "Select", "Cancel");
	return 1;
}