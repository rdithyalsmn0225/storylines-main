//Functions

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
		amounts[MAX_INVENTORY],
		str[2024],
		string[256],
		count = 0;

	format(str, sizeof(str), "Index\tItems\tQuantity\n");
	format(str, sizeof(str), "[SLOT]: Money\t$%s\n", FormatMoney(PlayerInfo[targetid][E_CHARACTER_MONEY]));
    for (new i = 0; i < MAX_INVENTORY; i ++)
	{
 		if (InventoryInfo[targetid][i][E_INVENTORY_EXISTS])
        {
			if (!InventoryInfo[targetid][i][E_INVENTORY_EXISTS] && InventoryInfo[targetid][i][E_INVENTORY_MODEL] == 0)
	        	format(str, sizeof(str), "%s[SLOT]:\t<EMPTY>\n", str);
			else
			{
				count++;
				amounts[i] = InventoryInfo[targetid][i][E_INVENTORY_QUANTITY];
				strunpack(string, InventoryInfo[targetid][i][E_INVENTORY_ITEM]);
				format(str, sizeof(str), "%s[SLOT]:\t%s\t%d\n", str, string, amounts[i]);
			}
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
		str[2024],
		string[256];

	format(str, sizeof(str), "Index\tItems\tQuantity\n");
    for (new i = 0; i < MAX_INVENTORY; i ++)
	{
		if (!InventoryInfo[playerid][i][E_INVENTORY_EXISTS] && InventoryInfo[playerid][i][E_INVENTORY_MODEL] == 0)
	        format(str, sizeof(str), "%s[SLOT]:\t<EMPTY>\n", str);
		else
		{
			amounts[i] = InventoryInfo[playerid][i][E_INVENTORY_QUANTITY];
			strunpack(string, InventoryInfo[playerid][i][E_INVENTORY_ITEM]);
			format(str, sizeof(str), "%s[SLOT]:\t%s\t%d\n", str, string, amounts[i]);
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
	printf("[SERVER]: %s inventory were loaded from \"%s\" database...", ReturnName(playerid), SQL_DATABASE);
	return 1;
}

function:OnPlayerUseItem(playerid, itemid, name[])
{
	if(!strcmp(name, "Radio"))
	{
        if(PlayerInfo[playerid][E_CHARACTER_EQUIPITEMS] == INVENTORY_NONE)
		{
			PlayerInfo[playerid][E_CHARACTER_EQUIPITEMS] = PORTABLE_RADIO;
			SetPlayerAttachedObject(playerid, ATTACH_HAND, 330, 6, 0.000000, -0.015000, 0.000000, 0.000000, 0.000000, 0.000000, 1.000000, 1.000000, 1.000000);

			SendInventoryMessage(playerid, "Type /(r)adio /setchannel /setslot to using Radio.");
		}
		else SendErrorMessage(playerid, "You must store your items in inventory first.");
	}
	else if(!strcmp(name, "Cellphone"))
	{
		if(PlayerInfo[playerid][E_CHARACTER_EQUIPITEMS] == INVENTORY_NONE)
		{
			if(PlayerInfo[playerid][E_CHARACTER_TOGPHONE])
			{
				ShowPlayerPhone(playerid);
				SelectTextDraw(playerid, COLOR_YELLOW);
			}
			else
			{
				new str[60];
				format(str, sizeof(str), "Phone Config #%d", PlayerInfo[playerid][E_CHARACTER_PHONE]);
				ShowPlayerDialog(playerid, DIALOG_PHONE, DIALOG_STYLE_LIST, str, "Dial Number\nSend Text Message\nMy Contacts\nSettings\nTurn on/off", "Select", "Close");
			}
			PlayerInfo[playerid][E_CHARACTER_EQUIPITEMS] = CELLPHONE;
			SetPlayerAttachedObject(playerid, ATTACH_HAND, 18868, 6, 0.093000, 0.000000, 0.005000, 96.799995, -178.100006, 7.199999, 1.000000, 1.000000, 1.000000);
		}
		else SendErrorMessage(playerid, "You must store your items in inventory first.");
	}
	else if(!strcmp(name, "Mask"))
	{
		if(PlayerInfo[playerid][E_CHARACTER_MASKON])
		{
			PlayerInfo[playerid][E_CHARACTER_MASKON] = false;
			SendInfoMessage(playerid, "[MASK] Mask has been Disable.");
		}
		else
		{
			PlayerInfo[playerid][E_CHARACTER_MASKON] = true;
			SendInfoMessage(playerid, "[MASK] Mask has been Enable.");
		}
	}
	else if(!strcmp(name, "Marijuana"))
	{
		IsPlayerUsingDrugs(playerid, 1);
	}
	else if(!strcmp(name, "Cocaine"))
	{
		IsPlayerUsingDrugs(playerid, 2);
	}
	else if(!strcmp(name, "Heroin"))
	{
       	IsPlayerUsingDrugs(playerid, 3);
	}
	else if(!strcmp(name, "Cocaine Crack"))
	{
        IsPlayerUsingDrugs(playerid, 4);
	}
	else if(!strcmp(name, "PCP"))
	{
		IsPlayerUsingDrugs(playerid, 5);
	}
    else if (!strcmp(name, "Fishing Rod", true)) 
	{
        if(PlayerInfo[playerid][E_CHARACTER_EQUIPITEMS] == INVENTORY_NONE)
		{
			PlayerInfo[playerid][E_CHARACTER_EQUIPITEMS] = FISHING_ROD;
			SetPlayerAttachedObject(playerid, ATTACH_HAND, 18632,6,0.079376,0.037070,0.007706,181.482910,0.000000,0.000000,1.000000,1.000000,1.000000, 0xFFFFFFFF, 0xFFFFFFFF);

			SendInventoryMessage(playerid, "Type /fish to start fishing nearest water or santa maria fishing area.");
		}
		else SendErrorMessage(playerid, "You must store your items in inventory first.");
    }
	else if(!strcmp(name, "Sprunk"))
	{
		if(PlayerInfo[playerid][E_CHARACTER_EQUIPITEMS] == INVENTORY_NONE)
		{
			if(!Inventory_Count(playerid, "Sprunk"))
				return SendErrorMessage(playerid, "You don't have any beer in inventory.");

			if(GetPlayerSpecialAction(playerid) == SPECIAL_ACTION_DRINK_SPRUNK)
				return SendErrorMessage(playerid, "You are already drinking a sprunk.");

			if(gettime() - PlayerInfo[playerid][E_CHARACTER_DRINKCD] < 60)
				return SendErrorMessage(playerid, "You've only been drink beer for %i seconds. You need to wait at least 60 sec to drink beer.", gettime() - PlayerInfo[playerid][E_CHARACTER_DRINKCD]); 

			Inventory_Remove(playerid, "Sprunk", 1);

			SetPlayerSpecialAction(playerid, SPECIAL_ACTION_DRINK_SPRUNK);

			SendInventoryMessage(playerid, "Press 'LMB' to drink sprunk.");
		}
		else SendErrorMessage(playerid, "You must store your items in inventory first.");
	}
	else if(!strcmp(name, "Spraycan"))
	{
       	if(PlayerInfo[playerid][E_CHARACTER_EQUIPITEMS] == INVENTORY_NONE)
		{
			PlayerInfo[playerid][E_CHARACTER_EQUIPITEMS] = SPRAYCAN;
			SetPlayerAttachedObject(playerid, ATTACH_HAND, 365, 6, 0.0000, 0.0000, 0.0360, 0.0000, 0.0000, 0.0000, 1.0000, 1.0000, 1.0000, 0xFFFFFFFF, 0xFFFFFFFF);
			SendInventoryMessage(playerid, "Type /spray to start spraying tags.");
		}
		else SendErrorMessage(playerid, "You must store your items in inventory first.");
	}
	else if(!strcmp(name, "Chainsaw"))
	{
       	if(PlayerInfo[playerid][E_CHARACTER_EQUIPITEMS] == INVENTORY_NONE)
		{
			PlayerInfo[playerid][E_CHARACTER_EQUIPITEMS] = CHAINSAW;
			SetPlayerAttachedObject(playerid, ATTACH_HAND, 341, 6, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 1.000000, 1.000000, 0.759999, 0xFFFFFFFF, 0xFFFFFFFF);
			SendInventoryMessage(playerid, "Press 'ALT' to cut the trees & take the timber.");
		}
		else SendErrorMessage(playerid, "You must store your items in inventory first.");
	}
	else if(!strcmp(name, "Extinguisher"))
	{
       	if(PlayerInfo[playerid][E_CHARACTER_EQUIPITEMS] == INVENTORY_NONE)
		{
			PlayerInfo[playerid][E_CHARACTER_EQUIPITEMS] = FIRE_EXTINGUISHER;
			GivePlayerWeapon(playerid, 42, 999999);
			SendInventoryMessage(playerid, "Press 'LMB' to extinguiher the fire.");
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
	else if(!strcmp(name, "Pisswasher"))
	{
		ShowPlayerDialog(playerid, DIALOG_BEERBOTTLE, DIALOG_STYLE_LIST, "Choose your beer use:", "Drink Beer\nMelee Bottle", "Select", "Cancel");
	}
	else if(!strcmp(name, "Marcos Knife"))
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

	//Glove
	else if(!strcmp(name, "Glove"))
	{
		if(PlayerInfo[playerid][E_CHARACTER_EQUIPITEMS] == INVENTORY_NONE)
		{
			GivePlayerWeapon(playerid, 1, 999999);
			PlayerInfo[playerid][E_CHARACTER_WEAPONTYPE] = 1;
			PlayerInfo[playerid][E_CHARACTER_EQUIPITEMS] = GLOVE;
		}
		else SendErrorMessage(playerid, "You must store your items in inventory first.");
	}

	//Dildoh AOKWKWKWKWK
	else if(!strcmp(name, "Hammer"))
	{
		if(PlayerInfo[playerid][E_CHARACTER_EQUIPITEMS] == INVENTORY_NONE)
		{
			GivePlayerWeapon(playerid, 11, 999999);
			PlayerInfo[playerid][E_CHARACTER_WEAPONTYPE] = 1;
			PlayerInfo[playerid][E_CHARACTER_EQUIPITEMS] = DILDO;
		}
		else SendErrorMessage(playerid, "You must store your items in inventory first.");
	}
	else if(!strcmp(name, "Wrench"))
	{
		if(PlayerInfo[playerid][E_CHARACTER_EQUIPITEMS] == INVENTORY_NONE)
		{
			GivePlayerWeapon(playerid, 11, 999999);
			PlayerInfo[playerid][E_CHARACTER_WEAPONTYPE] = 2;
			PlayerInfo[playerid][E_CHARACTER_EQUIPITEMS] = DILDO;
		}
		else SendErrorMessage(playerid, "You must store your items in inventory first.");
	}
	else if(!strcmp(name, "Broom"))
	{
		if(PlayerInfo[playerid][E_CHARACTER_EQUIPITEMS] == INVENTORY_NONE)
		{
			GivePlayerWeapon(playerid, 11, 999999);
			PlayerInfo[playerid][E_CHARACTER_WEAPONTYPE] = 3;
			PlayerInfo[playerid][E_CHARACTER_EQUIPITEMS] = DILDO;
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
	else if(!strcmp(name, "Cutscene Bat"))
	{
		if(PlayerInfo[playerid][E_CHARACTER_EQUIPITEMS] == INVENTORY_NONE)
		{
			GivePlayerWeapon(playerid, 5, 999999);
			PlayerInfo[playerid][E_CHARACTER_WEAPONTYPE] = 2;
			PlayerInfo[playerid][E_CHARACTER_EQUIPITEMS] = BAT;
		}
		else SendErrorMessage(playerid, "You must store your items in inventory first.");
	}
	else if(!strcmp(name, "Baseball Bat"))
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
	else if(!strcmp(name, "Desert Eagle"))
	{
		if(PlayerInfo[playerid][E_CHARACTER_EQUIPITEMS] == INVENTORY_NONE)
		{
			ShowPlayerDialog(playerid, DIALOG_WEAPONDEAGLE, DIALOG_STYLE_TABLIST, "Choose your ammo type:", "Regular Ammo\tNo Buffs\nSurplus Ammo\t+10% Damages\nJHP Ammo\t+20% Damages\nRubber Ammo\t+5% Damages", "Select", "Cancel");
		}
		else SendErrorMessage(playerid, "You must store your items in inventory first.");
	}

	//Colt
	else if(!strcmp(name, "Colt 45"))
	{
		if(PlayerInfo[playerid][E_CHARACTER_EQUIPITEMS] == INVENTORY_NONE)
		{
			ShowPlayerDialog(playerid, DIALOG_WEAPONCOLT, DIALOG_STYLE_TABLIST, "Choose your ammo type:", "Regular Ammo\tNo Buffs\nSurplus Ammo\t+10% Damages\nJHP Ammo\t+20% Damages\nRubber Ammo\t+5% Damages", "Select", "Cancel");
		}
		else SendErrorMessage(playerid, "You must store your items in inventory first.");
	}

	else if(!strcmp(name, "Silenced Colt"))
	{
		if(PlayerInfo[playerid][E_CHARACTER_EQUIPITEMS] == INVENTORY_NONE)
		{
			ShowPlayerDialog(playerid, DIALOG_WEAPONSLC, DIALOG_STYLE_TABLIST, "Choose your ammo type:", "Regular Ammo\tNo Buffs\nSurplus Ammo\t+10% Damages\nJHP Ammo\t+20% Damages\nRubber Ammo\t+5% Damages", "Select", "Cancel");
		}
		else SendErrorMessage(playerid, "You must store your items in inventory first.");
	}

	//Uzi
	else if(!strcmp(name, "Uzi"))
	{
		if(PlayerInfo[playerid][E_CHARACTER_EQUIPITEMS] == INVENTORY_NONE)
		{
			ShowPlayerDialog(playerid, DIALOG_WEAPONUZI, DIALOG_STYLE_TABLIST, "Choose your ammo type:", "Regular Ammo\tNo Buffs\nSurplus Ammo\t+10% Damages\nJHP Ammo\t+20% Damages\nRubber Ammo\t+5% Damages", "Select", "Cancel");
		}
		else SendErrorMessage(playerid, "You must store your items in inventory first.");
	}
	else if(!strcmp(name, "Shotgun"))
	{
		if(PlayerInfo[playerid][E_CHARACTER_EQUIPITEMS] == INVENTORY_NONE)
		{
			ShowPlayerDialog(playerid, DIALOG_WEAPONSHOTGUN, DIALOG_STYLE_TABLIST, "Choose your ammo type:", "Regular Ammo\tNo Buffs\nSurplus Ammo\t+10% Damages\nJHP Ammo\t+20% Damages\nRubber Ammo\t+5% Damages", "Select", "Cancel");
		}
		else SendErrorMessage(playerid, "You must store your items in inventory first.");
	}
	return 1;
}