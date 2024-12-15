//Weapon system

stock GetWeaponType(playerid, weaponid)
{
	new idx = ReturnWeaponIDSlot(weaponid); 
 	new astring[128];
 	if(GetPlayerWeapon(weaponid) == 22)
 	{ 
 		if (PlayerInfo[playerid][E_CHARACTER_WEAPONTYPE] == 1)format(astring, sizeof(astring), "Colt 45");
	}
	else if(GetPlayerWeapon(weaponid) == 23)
 	{ 
 		if (PlayerInfo[playerid][E_CHARACTER_WEAPONTYPE] == 1)format(astring, sizeof(astring), "Silenced Colt");
	}
	else if(GetPlayerWeapon(weaponid) == 24)
 	{ 
 		if (PlayerInfo[playerid][E_CHARACTER_WEAPONTYPE] == 1)format(astring, sizeof(astring), "Desert Eagle");
	}
	else if(GetPlayerWeapon(weaponid) == 28)
 	{ 
 		if (PlayerInfo[playerid][E_CHARACTER_WEAPONTYPE] == 1)format(astring, sizeof(astring), "UZI");
	}
	else if(GetPlayerWeapon(weaponid) == 25)
 	{ 
 		if (PlayerInfo[playerid][E_CHARACTER_WEAPONTYPE] == 1)format(astring, sizeof(astring), "Shotgun");
	}
	else if(GetPlayerWeapon(weaponid) == 32)
 	{ 
 		if (PlayerInfo[playerid][E_CHARACTER_WEAPONTYPE] == 1)format(astring, sizeof(astring), "TEC9");
	}
	else if(GetPlayerWeapon(weaponid) == 29)
 	{ 
 		if (PlayerInfo[playerid][E_CHARACTER_WEAPONTYPE] == 1)format(astring, sizeof(astring), "MP5");
	}
	else if(GetPlayerWeapon(weaponid) == 5)
 	{ 
 		if (PlayerInfo[playerid][E_CHARACTER_WEAPONTYPE] == 1)format(astring, sizeof(astring), "Spike Bat");
 		else if (PlayerInfo[playerid][E_CHARACTER_WEAPONTYPE] == 2)format(astring, sizeof(astring), "Cutscene Bat");
 		else if (PlayerInfo[playerid][E_CHARACTER_WEAPONTYPE] == 3)format(astring, sizeof(astring), "Baseball Bat");
	}
	else if(GetPlayerWeapon(weaponid) == 4)
 	{ 
 		if (PlayerInfo[playerid][E_CHARACTER_WEAPONTYPE] == 1)format(astring, sizeof(astring), "Beer Bottle");
 		else if (PlayerInfo[playerid][E_CHARACTER_WEAPONTYPE] == 2)format(astring, sizeof(astring), "Marcos Knife");
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
	Inventory_Set(playerid, "Extinguisher", 366, 0);
	Inventory_Set(playerid, "Beer Bottle", 2040, 0);
	Inventory_Set(playerid, "Marcos Knife", 2040, 0);
	Inventory_Set(playerid, "Knife", 2040, 0);
	Inventory_Set(playerid, "Spike Bat", 2040, 0);
	Inventory_Set(playerid, "Cutscene Bat", 2040, 0);
	Inventory_Set(playerid, "Baseball Bat", 2040, 0);
	Inventory_Set(playerid, "Colt 45", 346, 0);
	Inventory_Set(playerid, "Silenced Colt", 347, 0);
	Inventory_Set(playerid, "Desert Eagle", 384, 0);
	Inventory_Set(playerid, "Uzi", 352, 0);
	Inventory_Set(playerid, "Shotgun", 349, 0);
	Inventory_Set(playerid, "Regular Ammo", 2040, 0);
	Inventory_Set(playerid, "Surplus Ammo", 2040, 0);
	Inventory_Set(playerid, "JHP Ammo", 2040, 0);
	Inventory_Set(playerid, "Rubber Ammo", 2040, 0);
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

SetPlayerWeaponSkill(playerid, skill)
{
	switch(skill)
	{
	    case NORMAL_SKILL:
		{
			SetPlayerSkillLevel(playerid, WEAPONSKILL_PISTOL, 0);
			SetPlayerSkillLevel(playerid, WEAPONSKILL_PISTOL_SILENCED, 100);
			SetPlayerSkillLevel(playerid, WEAPONSKILL_DESERT_EAGLE, 100);
			SetPlayerSkillLevel(playerid, WEAPONSKILL_SHOTGUN, 100);
			SetPlayerSkillLevel(playerid, WEAPONSKILL_SAWNOFF_SHOTGUN, 100);
			SetPlayerSkillLevel(playerid, WEAPONSKILL_SPAS12_SHOTGUN, 100);
			SetPlayerSkillLevel(playerid, WEAPONSKILL_MICRO_UZI, 0);
			SetPlayerSkillLevel(playerid, WEAPONSKILL_MP5, 100);
			SetPlayerSkillLevel(playerid, WEAPONSKILL_AK47, 100);
			SetPlayerSkillLevel(playerid, WEAPONSKILL_M4, 100);
			SetPlayerSkillLevel(playerid, WEAPONSKILL_SNIPERRIFLE, 100);
	    }
	    case MEDIUM_SKILL:
		{
			SetPlayerSkillLevel(playerid, WEAPONSKILL_PISTOL, 200);
			SetPlayerSkillLevel(playerid, WEAPONSKILL_PISTOL_SILENCED, 500);
			SetPlayerSkillLevel(playerid, WEAPONSKILL_DESERT_EAGLE, 200);
			SetPlayerSkillLevel(playerid, WEAPONSKILL_SHOTGUN, 200);
			SetPlayerSkillLevel(playerid, WEAPONSKILL_SAWNOFF_SHOTGUN, 200);
			SetPlayerSkillLevel(playerid, WEAPONSKILL_SPAS12_SHOTGUN, 200);
			SetPlayerSkillLevel(playerid, WEAPONSKILL_MICRO_UZI, 50);
			SetPlayerSkillLevel(playerid, WEAPONSKILL_MP5, 250);
			SetPlayerSkillLevel(playerid, WEAPONSKILL_AK47, 200);
			SetPlayerSkillLevel(playerid, WEAPONSKILL_M4, 200);
			SetPlayerSkillLevel(playerid, WEAPONSKILL_SNIPERRIFLE, 300);
	    }
	    case FULL_SKILL:
		{
			SetPlayerSkillLevel(playerid, WEAPONSKILL_PISTOL, 998);
			SetPlayerSkillLevel(playerid, WEAPONSKILL_PISTOL_SILENCED, 998);
			SetPlayerSkillLevel(playerid, WEAPONSKILL_DESERT_EAGLE, 999);
			SetPlayerSkillLevel(playerid, WEAPONSKILL_SHOTGUN, 999);
			SetPlayerSkillLevel(playerid, WEAPONSKILL_SAWNOFF_SHOTGUN, 999);
			SetPlayerSkillLevel(playerid, WEAPONSKILL_SPAS12_SHOTGUN, 999);
			SetPlayerSkillLevel(playerid, WEAPONSKILL_MICRO_UZI, 50);
			SetPlayerSkillLevel(playerid, WEAPONSKILL_MP5, 999);
			SetPlayerSkillLevel(playerid, WEAPONSKILL_AK47, 999);
			SetPlayerSkillLevel(playerid, WEAPONSKILL_M4, 999);
			SetPlayerSkillLevel(playerid, WEAPONSKILL_SNIPERRIFLE, 999);
	    }
	}
}