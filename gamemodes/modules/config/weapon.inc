//Weapon system

stock GetWeaponType(playerid, weaponid)
{
	new idx = ReturnWeaponIDSlot(weaponid); 
 	new astring[128];
 	if(GetPlayerWeapon(weaponid) == 22)
 	{ 
 		if (PlayerInfo[playerid][E_CHARACTER_WEAPONTYPE] == 1)format(astring, sizeof(astring), "Glock 19");
 		else if (PlayerInfo[playerid][E_CHARACTER_WEAPONTYPE] == 2)format(astring, sizeof(astring), "Glock 17");
 		else if (PlayerInfo[playerid][E_CHARACTER_WEAPONTYPE] == 3)format(astring, sizeof(astring), "Glock P80");
	}
	else if(GetPlayerWeapon(weaponid) == 23)
 	{ 
 		if (PlayerInfo[playerid][E_CHARACTER_WEAPONTYPE] == 1)format(astring, sizeof(astring), "SIG P226");
 		else if (PlayerInfo[playerid][E_CHARACTER_WEAPONTYPE] == 2)format(astring, sizeof(astring), "SW1911");
 		else if (PlayerInfo[playerid][E_CHARACTER_WEAPONTYPE] == 3)format(astring, sizeof(astring), "H&K USP");
	}
	else if(GetPlayerWeapon(weaponid) == 24)
 	{ 
 		if (PlayerInfo[playerid][E_CHARACTER_WEAPONTYPE] == 1)format(astring, sizeof(astring), "Night Hawk .50c");
 		else if (PlayerInfo[playerid][E_CHARACTER_WEAPONTYPE] == 2)format(astring, sizeof(astring), "Desert Eagle");
 		else if (PlayerInfo[playerid][E_CHARACTER_WEAPONTYPE] == 3)format(astring, sizeof(astring), "S&W Model 625");
	}
	else if(GetPlayerWeapon(weaponid) == 28)
 	{ 
 		if (PlayerInfo[playerid][E_CHARACTER_WEAPONTYPE] == 1)format(astring, sizeof(astring), "MAC-11");
 		else if (PlayerInfo[playerid][E_CHARACTER_WEAPONTYPE] == 2)format(astring, sizeof(astring), "MAC-10");
 		else if (PlayerInfo[playerid][E_CHARACTER_WEAPONTYPE] == 3)format(astring, sizeof(astring), "Socimi Type 821");
	}
	else if(GetPlayerWeapon(weaponid) == 32)
 	{ 
 		if (PlayerInfo[playerid][E_CHARACTER_WEAPONTYPE] == 1)format(astring, sizeof(astring), "PP-90");
 		else if (PlayerInfo[playerid][E_CHARACTER_WEAPONTYPE] == 2)format(astring, sizeof(astring), "KGP-9");
 		else if (PlayerInfo[playerid][E_CHARACTER_WEAPONTYPE] == 3)format(astring, sizeof(astring), "Berreta M12");
	}
	else if(GetPlayerWeapon(weaponid) == 29)
 	{ 
 		if (PlayerInfo[playerid][E_CHARACTER_WEAPONTYPE] == 1)format(astring, sizeof(astring), "HK-53");
 		else if (PlayerInfo[playerid][E_CHARACTER_WEAPONTYPE] == 2)format(astring, sizeof(astring), "UMP9");
 		else if (PlayerInfo[playerid][E_CHARACTER_WEAPONTYPE] == 3)format(astring, sizeof(astring), "AKS 74U");
	}
	else if(GetPlayerWeapon(weaponid) == 5)
 	{ 
 		if (PlayerInfo[playerid][E_CHARACTER_WEAPONTYPE] == 1)format(astring, sizeof(astring), "Spike Bat");
 		else if (PlayerInfo[playerid][E_CHARACTER_WEAPONTYPE] == 2)format(astring, sizeof(astring), "Wooden");
 		else if (PlayerInfo[playerid][E_CHARACTER_WEAPONTYPE] == 3)format(astring, sizeof(astring), "Nail Bat");
	}
	else if(GetPlayerWeapon(weaponid) == 4)
 	{ 
 		if (PlayerInfo[playerid][E_CHARACTER_WEAPONTYPE] == 1)format(astring, sizeof(astring), "Broken Bottle");
 		else if (PlayerInfo[playerid][E_CHARACTER_WEAPONTYPE] == 2)format(astring, sizeof(astring), "Glasses");
 		else if (PlayerInfo[playerid][E_CHARACTER_WEAPONTYPE] == 3)format(astring, sizeof(astring), "Knife");
	}
	else ReturnWeaponName(weaponid);
	return astring;
}

stock RemovePlayerWeapon(playerid, weaponid)
{
	if(!IsPlayerConnected(playerid) || weaponid < 0 || weaponid > 50)
	    return;
	new saveweapon[13], saveammo[13];
	for(new slot = 0; slot < 13; slot++)
	    GetPlayerWeaponData(playerid, slot, saveweapon[slot], saveammo[slot]);
	ResetPlayerWeapons(playerid);
	for(new slot; slot < 13; slot++)
	{
		if(saveweapon[slot] == weaponid || saveammo[slot] == 0)
			continue;
		GivePlayerWeapon(playerid, saveweapon[slot], saveammo[slot]);
	}

	GivePlayerWeapon(playerid, 0, 1);
}

ResetPlayerWeaponEx(playerid)
{
	Inventory_Set(playerid, "Broken Bottle", 2040, 0);
	Inventory_Set(playerid, "Glass", 2040, 0);
	Inventory_Set(playerid, "Knife", 2040, 0);
	Inventory_Set(playerid, "Spike Bat", 2040, 0);
	Inventory_Set(playerid, "Wooden", 2040, 0);
	Inventory_Set(playerid, "Nail Bat", 2040, 0);
	Inventory_Set(playerid, "Glock 17", -2204, 0);
	Inventory_Set(playerid, "Glock 19", -2205, 0);
	Inventory_Set(playerid, "Glock P80", -2206, 0);
	Inventory_Set(playerid, "Deagle", 384, 0);
	Inventory_Set(playerid, "MAC 11", -2207, 0);
	Inventory_Set(playerid, "MAC 12", -2208, 0);
	Inventory_Set(playerid, "Socimi Type 821", -2208, 0);
	Inventory_Set(playerid, "Night Hawk", 348, 0);
	Inventory_Set(playerid, "9mm", 2040, 0);
	Inventory_Set(playerid, "9x19mm", 2040, 0);
	Inventory_Set(playerid, "12G Rubber", 2040, 0);
	return 1;
}

stock ReturnWeaponName(weaponid)
{
	new weapon[22];
    switch(weaponid)
    {
        case 0: weapon = "Fists";
        case 18: weapon = "Molotov Cocktail";
        case 44: weapon = "Night Vision Goggles";
        case 45: weapon = "Thermal Goggles";
		case 54: weapon = "Fall";
        default: GetWeaponName(weaponid, weapon, sizeof(weapon));
    }
    return weapon;
}

stock ReturnWeaponsModel(weaponid)
{
    new WeaponModels[] =
    {
        0, 331, 333, 334, 335, 336, 337, 338, 339, 341, 321, 322, 323, 324,
        325, 326, 342, 343, 344, 0, 0, 0, 346, 347, 348, 349, 350, 351, 352,
        353, 355, 356, 372, 357, 358, 359, 360, 361, 362, 363, 364, 365, 366,
        367, 368, 368, 371
    };
    return WeaponModels[weaponid];
}