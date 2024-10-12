//Functions

stock Items_Color(const name[])
{
    new color;

    if (strfind(name, "Cellphone", true) != -1 || strfind(name, "Portable Radio", true) != -1)
        color = 0xdcd5e5FF;
	//Weapons
	else if (strfind(name, "Broken Bottle", true) != -1 || strfind(name, "Glass", true) != -1 || strfind(name, "Knife", true) != -1)
        color = 0xe5d5d6FF;
	else if (strfind(name, "Spike Bat", true) != -1 || strfind(name, "Nail Bat", true) != -1 || strfind(name, "Wooden", true) != -1)
        color = 0xe5d5d6FF;
	else if (strfind(name, "Glock 17", true) != -1 || strfind(name, "Glock 19", true) != -1 || strfind(name, "Glock P80", true) != -1)
        color = 0xe5d5d6FF;
	else if (strfind(name, "Mac 11", true) != -1 || strfind(name, "Mac 12", true) != -1 || strfind(name, "Socimi Type 821", true) != -1)
        color = 0xe5d5d6FF;
	else if (strfind(name, "Night Hawk", true) != -1 || strfind(name, "9mm", true) != -1 || strfind(name, "9x19mm", true) != -1)
        color = 0xe5d5d6FF;
	else if (strfind(name, "12G Rubber", true) != -1)
        color = 0xe5d5d6FF;
	else if (strfind(name, "Marijuana", true) != -1 || strfind(name, "Cocaine", true) != -1 || strfind(name, "Heroin", true) != -1)
        color = 0xD9B7CCFF;
	else if (strfind(name, "PCP", true) != -1 || strfind(name, "Cocaine Crack", true) != -1)
        color = 0xD9B7CCFF;
    else
        color = 0xd5e1e5FF;

    return color;
}

stock Inventory_Clear(playerid)
{
	static
	    string[64];

	for (new i = 0; i < MAX_INVENTORY; i ++)
	{
	    if (InventoryInfo[playerid][i][E_INVENTORY_EXISTS])
	    {
	        InventoryInfo[playerid][i][E_INVENTORY_EXISTS] = 0;
	        InventoryInfo[playerid][i][E_INVENTORY_MODEL] = 0;
	        InventoryInfo[playerid][i][E_INVENTORY_QUANTITY] = 0;
			InventoryInfo[playerid][i][E_INVENTORY_TYPE] = 0;
		}
	}
	format(string, sizeof(string), "DELETE FROM `inventory` WHERE `ID` = '%d'", PlayerInfo[playerid][E_CHARACTER_DBID]);
	return mysql_pquery(ourConnection, string);
}

stock Inventory_GetItemID(playerid, item[])
{
	for (new i = 0; i < MAX_INVENTORY; i ++)
	{
	    if (!InventoryInfo[playerid][i][E_INVENTORY_EXISTS])
	        continue;

		if (!strcmp(InventoryInfo[playerid][i][E_INVENTORY_ITEM], item)) return i;
	}
	return -1;
}

stock Inventory_GetFreeID(playerid)
{
	if (Inventory_Items(playerid) >= 20)
		return -1;

	for (new i = 0; i < MAX_INVENTORY; i ++)
	{
	    if (!InventoryInfo[playerid][i][E_INVENTORY_EXISTS])
	        return i;
	}
	return -1;
}

stock Inventory_GetItemName(playerid, itemid, output[])
{
    new itemName[128];


    if (itemid < 0 || itemid >= MAX_INVENTORY)
        return 0;

    if (!strunpack(itemName, InventoryInfo[playerid][itemid][E_INVENTORY_ITEM]))
        return 0;

    format(output, 512, "%s", itemName);
    return 1;
}

stock Inventory_Items(playerid)
{
    new count;

    for (new i = 0; i != MAX_INVENTORY; i ++) if (InventoryInfo[playerid][i][E_INVENTORY_EXISTS]) {
        count++;
	}
	return count;
}

stock Inventory_Count(playerid, item[])
{
	new itemid = Inventory_GetItemID(playerid, item);

	if (itemid != -1)
	    return InventoryInfo[playerid][itemid][E_INVENTORY_QUANTITY];

	return 0;
}

stock PlayerHasItem(playerid, item[])
{
	return (Inventory_GetItemID(playerid, item) != -1);
}

stock Inventory_Set(playerid, item[], model, amount, type=0)
{
	new itemid = Inventory_GetItemID(playerid, item);

	if (itemid == -1 && amount > 0)
		Inventory_Add(playerid, item, model, amount, type);

	else if (amount > 0 && itemid != -1)
	    Inventory_SetQuantity(playerid, item, amount, type);

	else if (amount < 1 && itemid != -1)
	    Inventory_Remove(playerid, item, -1);

	return 1;
}

stock Inventory_SetQuantity(playerid, item[], quantity, type=0)
{
	new
	    itemid = Inventory_GetItemID(playerid, item),
	    string[128];

	if (itemid != -1)
	{
	    format(string, sizeof(string), "UPDATE `inventory` SET `invQuantity` = %d, `invType` = %d WHERE `ID` = '%d' AND `invID` = '%d'", quantity, type, PlayerInfo[playerid][E_CHARACTER_DBID], InventoryInfo[playerid][itemid][E_INVENTORY_DBID]);
	    mysql_pquery(ourConnection, string);

	    InventoryInfo[playerid][itemid][E_INVENTORY_QUANTITY] = quantity;
		InventoryInfo[playerid][itemid][E_INVENTORY_TYPE] = type;
	}
	return 1;
}

stock Inventory_Remove(playerid, item[], quantity = 1)
{
	new
		itemid = Inventory_GetItemID(playerid, item),
		string[128];

	if (itemid != -1)
	{
	    if (InventoryInfo[playerid][itemid][E_INVENTORY_QUANTITY] > 0)
	    {
	        InventoryInfo[playerid][itemid][E_INVENTORY_QUANTITY] -= quantity;
		}
		if (quantity == -1 || InventoryInfo[playerid][itemid][E_INVENTORY_QUANTITY] < 1)
		{
		    InventoryInfo[playerid][itemid][E_INVENTORY_EXISTS] = false;
		    InventoryInfo[playerid][itemid][E_INVENTORY_MODEL] = 0;
		    InventoryInfo[playerid][itemid][E_INVENTORY_QUANTITY] = 0;
			InventoryInfo[playerid][itemid][E_INVENTORY_QUANTITY] = 0;

		    format(string, sizeof(string), "DELETE FROM `inventory` WHERE `ID` = '%d' AND `invID` = '%d'", PlayerInfo[playerid][E_CHARACTER_DBID], InventoryInfo[playerid][itemid][E_INVENTORY_DBID]);
	        mysql_pquery(ourConnection, string);
		}
		else if (quantity != -1 && InventoryInfo[playerid][itemid][E_INVENTORY_QUANTITY] > 0)
		{
			format(string, sizeof(string), "UPDATE `inventory` SET `invQuantity` = `invQuantity` - %d WHERE `ID` = '%d' AND `invID` = '%d'", quantity, PlayerInfo[playerid][E_CHARACTER_DBID], InventoryInfo[playerid][itemid][E_INVENTORY_DBID]);
            mysql_pquery(ourConnection, string);
		}
		return 1;
	}
	return 0;
}

stock Inventory_Add(playerid, item[], model, quantity = 1, type = 0)
{
	new
		itemid = Inventory_GetItemID(playerid, item),
		string[128];

	if (itemid == -1)
	{
	    itemid = Inventory_GetFreeID(playerid);

	    if (itemid != -1)
	    {
	        InventoryInfo[playerid][itemid][E_INVENTORY_EXISTS] = true;
	        InventoryInfo[playerid][itemid][E_INVENTORY_MODEL] = model;
	        InventoryInfo[playerid][itemid][E_INVENTORY_QUANTITY] = quantity;
			InventoryInfo[playerid][itemid][E_INVENTORY_TYPE] = type;

	        strpack(InventoryInfo[playerid][itemid][E_INVENTORY_ITEM], item, 32 char);

			format(string, sizeof(string), "INSERT INTO `inventory` (`ID`, `invItem`, `invModel`, `invQuantity`, `invType`) VALUES('%d', '%s', '%d', '%d', '%d')", PlayerInfo[playerid][E_CHARACTER_DBID], item, model, quantity, type);
			mysql_pquery(ourConnection, string, "OnInventoryAdd", "dd", playerid, itemid);
	        return itemid;
		}
		return -1;
	}
	else
	{
	    format(string, sizeof(string), "UPDATE `inventory` SET `invQuantity` = `invQuantity` + %d WHERE `ID` = '%d' AND `invID` = '%d'", quantity, PlayerInfo[playerid][E_CHARACTER_DBID], InventoryInfo[playerid][itemid][E_INVENTORY_DBID]);
	    mysql_pquery(ourConnection, string);

	    InventoryInfo[playerid][itemid][E_INVENTORY_QUANTITY] += quantity;
	}
	return itemid;
}

function:OnInventoryAdd(playerid, itemid)
{
	InventoryInfo[playerid][itemid][E_INVENTORY_DBID] = cache_insert_id();
	return 1;
}

stock ShowInventory(playerid, targetid)
{
    if (!IsPlayerConnected(playerid))
	    return 0;

	new
	    items[MAX_INVENTORY],
		amounts[MAX_INVENTORY],
		str[512],
		string[352],
		count = 0;

	format(str, sizeof(str), "Name\tAmount\n");
	format(str, sizeof(str), "%s\nMoney\t$%s\n", str, FormatMoney(PlayerInfo[targetid][E_CHARACTER_MONEY]));
    for (new i = 0; i < MAX_INVENTORY; i ++)
	{
 		if (InventoryInfo[targetid][i][E_INVENTORY_EXISTS])
        {
            count++;
   			items[i] = InventoryInfo[targetid][i][E_INVENTORY_MODEL];
   			amounts[i] = InventoryInfo[targetid][i][E_INVENTORY_QUANTITY];
   			strunpack(string, InventoryInfo[targetid][i][E_INVENTORY_ITEM]);
   			format(str, sizeof(str), "%s[SLOT]: %s\t%d\n", str, string, amounts[i]);
		}
	}
	ShowPlayerDialog(playerid, DIALOG_DEFAULT, DIALOG_STYLE_TABLIST_HEADERS,"Inventory:", str,  "Close", "");
	return 1;

}

stock OpenInventory(playerid)
{
    if (!IsPlayerConnected(playerid))
	    return 0;

	new
		amounts[MAX_INVENTORY],
		str[512],
		string[256];

	format(str, sizeof(str), "Name\tAmount\n");
    for (new i = 0; i < MAX_INVENTORY; i ++)
	{
	    if (!InventoryInfo[playerid][i][E_INVENTORY_EXISTS])
	        format(str, sizeof(str), "%s[SLOT]: <EMPTY>\n", str);

		else
		{
			amounts[i] = InventoryInfo[playerid][i][E_INVENTORY_QUANTITY];
			strunpack(string, InventoryInfo[playerid][i][E_INVENTORY_ITEM]);
			format(str, sizeof(str), "%s[SLOT]: %s\t%d\n", str, string, amounts[i]);
		}
	}
	ShowPlayerDialog(playerid, DIALOG_INVENTORY, DIALOG_STYLE_TABLIST_HEADERS, "Inventory:", str, "Select", "Close");
	return 1;
}

function:LoadPlayerItems(playerid)
{
	new name[32];
    new rows, fields;
	cache_get_row_count(rows);
	cache_get_field_count(fields);

	for (new i = 0; i < rows && i < MAX_INVENTORY; i ++) 
	{
	    InventoryInfo[playerid][i][E_INVENTORY_EXISTS] = true;
	    cache_get_value_name_int(i, "invID", InventoryInfo[playerid][i][E_INVENTORY_DBID]);
	    cache_get_value_name_int(i, "invModel", InventoryInfo[playerid][i][E_INVENTORY_MODEL]);
        cache_get_value_name_int(i, "invQuantity", InventoryInfo[playerid][i][E_INVENTORY_QUANTITY]);
		cache_get_value_name_int(i, "invType", InventoryInfo[playerid][i][E_INVENTORY_TYPE]);

		cache_get_value_name(i, "invItem", name, sizeof(name));
		strpack(InventoryInfo[playerid][i][E_INVENTORY_ITEM], name, 32 char);
	}
	printf("[SERVER]: %s inventory were loaded from \"%s\" database...", ReturnSettingsName(playerid, playerid), SQL_DATABASE);
	return 1;
}

function:OnPlayerUseItem(playerid, itemid, name[])
{
	if(!strcmp(name, "Portable Radio"))
	{
        if(PlayerInfo[playerid][E_CHARACTER_EQUIPITEMS] == INVENTORY_NONE)
		{
			PlayerInfo[playerid][E_CHARACTER_EQUIPITEMS] = PORTABLE_RADIO;
			SetPlayerAttachedObject(playerid, ATTACH_HAND, 330, 6, 0.000000, -0.015000, 0.000000, 0.000000, 0.000000, 0.000000, 1.000000, 1.000000, 1.000000);
		}
		else SendErrorMessage(playerid, "You must store your items in inventory first.");
	}
	else if(!strcmp(name, "Cellphone"))
	{
		if(PlayerInfo[playerid][E_CHARACTER_EQUIPITEMS] == INVENTORY_NONE)
		{
			ShowPhone(playerid, 0);
			SelectTextDraw(playerid, COLOR_YELLOW);
			PlayerInfo[playerid][E_CHARACTER_EQUIPITEMS] = CELLPHONE;
			SetPlayerAttachedObject(playerid, ATTACH_HAND, 18868, 6, 0.093000, 0.000000, 0.005000, 96.799995, -178.100006, 7.199999, 1.000000, 1.000000, 1.000000);
		}
		else SendErrorMessage(playerid, "You must store your items in inventory first.");
	}
	else if(!strcmp(name, "Marijuana"))
	{
		IsPlayerUsingDrugs(playerid, 1);
	}
	else if(!strcmp(name, "Cocaine Crack"))
	{
        IsPlayerUsingDrugs(playerid, 4);
	}
	else if(!strcmp(name, "Cocaine"))
	{
		IsPlayerUsingDrugs(playerid, 2);
	}
	else if(!strcmp(name, "Heroin"))
	{
       	IsPlayerUsingDrugs(playerid, 3);
	}
	else if(!strcmp(name, "PCP"))
	{
		IsPlayerUsingDrugs(playerid, 5);
	}
    else if (!strcmp(name, "Fishing rod", true)) 
	{
        if(PlayerInfo[playerid][E_CHARACTER_EQUIPITEMS] == INVENTORY_NONE)
		{
			PlayerInfo[playerid][E_CHARACTER_EQUIPITEMS] = FISHING_ROD;
			SetPlayerAttachedObject(playerid, ATTACH_HAND, 18632,6,0.079376,0.037070,0.007706,181.482910,0.000000,0.000000,1.000000,1.000000,1.000000, 0xFFFFFFFF, 0xFFFFFFFF);
		}
		else SendErrorMessage(playerid, "You must store your items in inventory first.");
    }
	else if(!strcmp(name, "Beer"))
	{
		if(PlayerInfo[playerid][E_CHARACTER_EQUIPITEMS] == INVENTORY_NONE)
		{
			if(!Inventory_Count(playerid, "Beer"))
				return SendErrorMessage(playerid, "You don't have any beer in inventory.");

			if(PlayerInfo[playerid][E_CHARACTER_DRINKING] > 0)
				return SendErrorMessage(playerid, "You are already drinking a beer.");

			if(gettime() - PlayerInfo[playerid][E_CHARACTER_DRINKCD] < 60)
				return SendErrorMessage(playerid, "You've only been drink beer for %i seconds. You need to wait at least 60 sec to drink beer.", gettime() - PlayerInfo[playerid][E_CHARACTER_DRINKCD]); 

			PlayerInfo[playerid][E_CHARACTER_DRINKING] = 5;
			Inventory_Remove(playerid, "Beer", 1);

			SetPlayerSpecialAction(playerid, SPECIAL_ACTION_DRINK_BEER);
		}
		else SendErrorMessage(playerid, "You must store your items in inventory first.");
	}
	else if(!strcmp(name, "Sprunk"))
	{
		if(PlayerInfo[playerid][E_CHARACTER_EQUIPITEMS] == INVENTORY_NONE)
		{
			if(!Inventory_Count(playerid, "Sprunk"))
				return SendErrorMessage(playerid, "You don't have any beer in inventory.");

			if(PlayerInfo[playerid][E_CHARACTER_DRINKING] > 0)
				return SendErrorMessage(playerid, "You are already drinking a sprunk.");

			if(gettime() - PlayerInfo[playerid][E_CHARACTER_DRINKCD] < 60)
				return SendErrorMessage(playerid, "You've only been drink beer for %i seconds. You need to wait at least 60 sec to drink beer.", gettime() - PlayerInfo[playerid][E_CHARACTER_DRINKCD]); 

			PlayerInfo[playerid][E_CHARACTER_DRINKING] = 5;
			Inventory_Remove(playerid, "Sprunk", 1);

			SetPlayerSpecialAction(playerid, SPECIAL_ACTION_DRINK_SPRUNK);
		}
		else SendErrorMessage(playerid, "You must store your items in inventory first.");
	}
	else if(!strcmp(name, "Spraycan"))
	{
       	if(PlayerInfo[playerid][E_CHARACTER_EQUIPITEMS] == INVENTORY_NONE)
		{
			PlayerInfo[playerid][E_CHARACTER_EQUIPITEMS] = SPRAYCAN;
			SetPlayerAttachedObject(playerid, ATTACH_HAND, 365, 6, 0.0000, 0.0000, 0.0360, 0.0000, 0.0000, 0.0000, 1.0000, 1.0000, 1.0000, 0xFFFFFFFF, 0xFFFFFFFF);
			SendServerMessage(playerid, "You can start spraying by type /spray.");
		}
		else SendErrorMessage(playerid, "You must store your items in inventory first.");
	}
	else if(!strcmp(name, "Crowbar"))
	{
        if(PlayerInfo[playerid][E_CHARACTER_EQUIPITEMS] == INVENTORY_NONE)
		{
			PlayerInfo[playerid][E_CHARACTER_EQUIPITEMS] = CROWBAR;
			SetPlayerAttachedObject(playerid, ATTACH_HAND, 18634, 6, 0.081000, 0.000000, 0.000000, 81.899993, -81.500007, 0.000000, 1.000000, 1.000000, 1.000000);
		}
		else SendErrorMessage(playerid, "You must store your items in inventory first.");
	}
	else if(!strcmp(name, "Gascan"))
	{
		if(PlayerInfo[playerid][E_CHARACTER_EQUIPITEMS] == INVENTORY_NONE)
		{
			PlayerInfo[playerid][E_CHARACTER_EQUIPITEMS] = GASCAN;
			SetPlayerAttachedObject(playerid, ATTACH_HAND, 1650, 6, 0.121999, 0.020000, 0.047999, 0.000000, -99.899986, 1.999995, 1.000000, 1.000000, 1.000000);
		}
		else SendErrorMessage(playerid, "You must store your items in inventory first.");
	}

	else if(!strcmp(name, "Repair Kits"))
	{
		if(PlayerInfo[playerid][E_CHARACTER_EQUIPITEMS] == INVENTORY_NONE)
		{
			PlayerInfo[playerid][E_CHARACTER_EQUIPITEMS] = REPAIR_KITS;
			SetPlayerAttachedObject(playerid, ATTACH_HAND, 19627, 6, 0.069999, 0.020000, 0.023000, 0.000000, 84.800018, 0.000000, 1.000000, 1.000000, 1.000000);
		}
		else SendErrorMessage(playerid, "You must store your items in inventory first.");
	}
	//Weapons Inventory
	else if(!strcmp(name, "Broken Bottle"))
	{
		if(PlayerInfo[playerid][E_CHARACTER_EQUIPITEMS] == INVENTORY_NONE)
		{
			GivePlayerWeapon(playerid, 4, 999999);
			PlayerInfo[playerid][E_CHARACTER_WEAPONTYPE] = 1;
			PlayerInfo[playerid][E_CHARACTER_EQUIPITEMS] = KNIFE;
		}
		else SendErrorMessage(playerid, "You must store your items in inventory first.");
	}
	else if(!strcmp(name, "Glass"))
	{
		if(PlayerInfo[playerid][E_CHARACTER_EQUIPITEMS] == INVENTORY_NONE)
		{
			GivePlayerWeapon(playerid, 4, 999999);
			PlayerInfo[playerid][E_CHARACTER_WEAPONTYPE] = 2;
			PlayerInfo[playerid][E_CHARACTER_EQUIPITEMS] = KNIFE;
		}
		else SendErrorMessage(playerid, "You must store your items in inventory first.");
	}
	else if(!strcmp(name, "Knife"))
	{
		if(PlayerInfo[playerid][E_CHARACTER_EQUIPITEMS] == INVENTORY_NONE)
		{
			GivePlayerWeapon(playerid, 4, 999999);
			PlayerInfo[playerid][E_CHARACTER_WEAPONTYPE] = 3;
			PlayerInfo[playerid][E_CHARACTER_EQUIPITEMS] = KNIFE;
		}
		else SendErrorMessage(playerid, "You must store your items in inventory first.");
	}

	//Bat
	else if(!strcmp(name, "Spike Bat"))
	{
		if(PlayerInfo[playerid][E_CHARACTER_EQUIPITEMS] == INVENTORY_NONE)
		{
			GivePlayerWeapon(playerid, 5, 999999);
			PlayerInfo[playerid][E_CHARACTER_WEAPONTYPE] = 1;
			PlayerInfo[playerid][E_CHARACTER_EQUIPITEMS] = BAT;
		}
		else SendErrorMessage(playerid, "You must store your items in inventory first.");
	}
	else if(!strcmp(name, "Wooden"))
	{
		if(PlayerInfo[playerid][E_CHARACTER_EQUIPITEMS] == INVENTORY_NONE)
		{
			GivePlayerWeapon(playerid, 5, 999999);
			PlayerInfo[playerid][E_CHARACTER_WEAPONTYPE] = 2;
			PlayerInfo[playerid][E_CHARACTER_EQUIPITEMS] = BAT;
		}
		else SendErrorMessage(playerid, "You must store your items in inventory first.");
	}
	else if(!strcmp(name, "Nail Bat"))
	{
		if(PlayerInfo[playerid][E_CHARACTER_EQUIPITEMS] == INVENTORY_NONE)
		{
			GivePlayerWeapon(playerid, 5, 999999);
			PlayerInfo[playerid][E_CHARACTER_WEAPONTYPE] = 3;
			PlayerInfo[playerid][E_CHARACTER_EQUIPITEMS] = BAT;
		}
		else SendErrorMessage(playerid, "You must store your items in inventory first.");
	}
	//Deagle
	else if(!strcmp(name, "Night Hawk"))
	{
		if(PlayerInfo[playerid][E_CHARACTER_EQUIPITEMS] == INVENTORY_NONE)
		{
			if(!Inventory_Count(playerid, "9mm"))
				return SendErrorMessage(playerid, "You don't have 9mm magazine in your inventory");

			GivePlayerWeapon(playerid, 24, 999999);
			PlayerInfo[playerid][E_CHARACTER_WEAPONTYPE] = 1;
			PlayerInfo[playerid][E_CHARACTER_EQUIPITEMS] = DEAGLE;
		}
		else SendErrorMessage(playerid, "You must store your items in inventory first.");
	}
	//Colt
	else if(!strcmp(name, "Glock 19"))
	{
		if(PlayerInfo[playerid][E_CHARACTER_EQUIPITEMS] == INVENTORY_NONE)
		{
			if(!Inventory_Count(playerid, "9mm"))
				return SendErrorMessage(playerid, "You don't have 9mm magazine in your inventory");

			GivePlayerWeapon(playerid, 22, 999999);
			PlayerInfo[playerid][E_CHARACTER_WEAPONTYPE] = 1;
			PlayerInfo[playerid][E_CHARACTER_EQUIPITEMS] = PISTOL;
		}
		else SendErrorMessage(playerid, "You must store your items in inventory first.");
	}
	else if(!strcmp(name, "Glock 17"))
	{
		if(PlayerInfo[playerid][E_CHARACTER_EQUIPITEMS] == INVENTORY_NONE)
		{
			if(!Inventory_Count(playerid, "9mm"))
				return SendErrorMessage(playerid, "You don't have 9mm magazine in your inventory");

			GivePlayerWeapon(playerid, 22, 999999);
			PlayerInfo[playerid][E_CHARACTER_WEAPONTYPE] = 2;
			PlayerInfo[playerid][E_CHARACTER_EQUIPITEMS] = PISTOL;
		}
		else SendErrorMessage(playerid, "You must store your items in inventory first.");
	}
	else if(!strcmp(name, "Glock P80"))
	{
		if(PlayerInfo[playerid][E_CHARACTER_EQUIPITEMS] == INVENTORY_NONE)
		{
			if(!Inventory_Count(playerid, "9mm"))
				return SendErrorMessage(playerid, "You don't have 9mm magazine in your inventory");

			GivePlayerWeapon(playerid, 22, 999999);
			PlayerInfo[playerid][E_CHARACTER_WEAPONTYPE] = 3;
			PlayerInfo[playerid][E_CHARACTER_EQUIPITEMS] = PISTOL;
		}
		else SendErrorMessage(playerid, "You must store your items in inventory first.");
	}

	//Uzi
	else if(!strcmp(name, "Mac 11"))
	{
		if(PlayerInfo[playerid][E_CHARACTER_EQUIPITEMS] == INVENTORY_NONE)
		{
			if(!Inventory_Count(playerid, "9x19mm"))
				return SendErrorMessage(playerid, "You don't have 9x19mm magazine in your inventory");

			GivePlayerWeapon(playerid, 28, 999999);
			PlayerInfo[playerid][E_CHARACTER_WEAPONTYPE] = 1;
			PlayerInfo[playerid][E_CHARACTER_EQUIPITEMS] = UZI;
		}
		else SendErrorMessage(playerid, "You must store your items in inventory first.");
	}
	else if(!strcmp(name, "Mac 12"))
	{
		if(PlayerInfo[playerid][E_CHARACTER_EQUIPITEMS] == INVENTORY_NONE)
		{
			if(!Inventory_Count(playerid, "9x19mm"))
				return SendErrorMessage(playerid, "You don't have 9x19mm magazine in your inventory");

			GivePlayerWeapon(playerid, 28, 999999);
			PlayerInfo[playerid][E_CHARACTER_WEAPONTYPE] = 2;
			PlayerInfo[playerid][E_CHARACTER_EQUIPITEMS] = UZI;
		}
		else SendErrorMessage(playerid, "You must store your items in inventory first.");
	}
	else if(!strcmp(name, "Socimi Type 821"))
	{
		if(PlayerInfo[playerid][E_CHARACTER_EQUIPITEMS] == INVENTORY_NONE)
		{
			if(!Inventory_Count(playerid, "9x19mm"))
				return SendErrorMessage(playerid, "You don't have 9x19mm magazine in your inventory");

			GivePlayerWeapon(playerid, 28, 999999);
			PlayerInfo[playerid][E_CHARACTER_WEAPONTYPE] = 3;
			PlayerInfo[playerid][E_CHARACTER_EQUIPITEMS] = UZI;
		}
		else SendErrorMessage(playerid, "You must store your items in inventory first.");
	}
	return 1;
}