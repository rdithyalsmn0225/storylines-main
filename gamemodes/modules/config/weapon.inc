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

Dialog:WeaponColt(playerid, response, listitem, inputtext[])
{
	if(response)
	{
		switch(listitem)
		{
			case 0:
			{
				if(!Inventory_Count(playerid, "Regular Ammo"))
					return SendErrorMessage(playerid, "You don't have normal magazine in your inventory");

				GivePlayerWeapon(playerid, 22, 999999);
				PlayerInfo[playerid][E_CHARACTER_WEAPONTYPE] = 1;
				PlayerInfo[playerid][E_CHARACTER_AMMOTYPE] = AMMO_TYPE_NORMAL;
				PlayerInfo[playerid][E_CHARACTER_EQUIPITEMS] = PISTOL;
			}
			case 1:
			{
				if(!Inventory_Count(playerid, "Surplus Ammo"))
					return SendErrorMessage(playerid, "You don't have surplus magazine in your inventory");

				GivePlayerWeapon(playerid, 22, 999999);
				PlayerInfo[playerid][E_CHARACTER_WEAPONTYPE] = 1;
				PlayerInfo[playerid][E_CHARACTER_AMMOTYPE] = AMMO_TYPE_SURPLUS;
				PlayerInfo[playerid][E_CHARACTER_EQUIPITEMS] = PISTOL;
			}
			case 2:
			{
				if(!Inventory_Count(playerid, "JHP Ammo"))
					return SendErrorMessage(playerid, "You don't have jhp magazine in your inventory");

				GivePlayerWeapon(playerid, 22, 999999);
				PlayerInfo[playerid][E_CHARACTER_WEAPONTYPE] = 1;
				PlayerInfo[playerid][E_CHARACTER_AMMOTYPE] = AMMO_TYPE_JHP;
				PlayerInfo[playerid][E_CHARACTER_EQUIPITEMS] = PISTOL;
			}
			case 3:
			{
				if(!Inventory_Count(playerid, "Rubber Ammo"))
					return SendErrorMessage(playerid, "You don't have rubber magazine in your inventory");

				GivePlayerWeapon(playerid, 22, 999999);
				PlayerInfo[playerid][E_CHARACTER_WEAPONTYPE] = 1;
				PlayerInfo[playerid][E_CHARACTER_AMMOTYPE] = AMMO_TYPE_RUBBER;
				PlayerInfo[playerid][E_CHARACTER_EQUIPITEMS] = PISTOL;
			}
		}
	}
	return 1;
}

Dialog:BeerBottle(playerid, response, listitem, inputtext[])
{
	if(response)
	{
		switch(listitem)
		{
			case 0:
			{
				if(PlayerInfo[playerid][E_CHARACTER_EQUIPITEMS] == INVENTORY_NONE)
				{
					if(!Inventory_Count(playerid, "Beer Bottle"))
						return SendErrorMessage(playerid, "You don't have any beer in inventory.");

					if(PlayerInfo[playerid][E_CHARACTER_DRINKING] > 0)
						return SendErrorMessage(playerid, "You are already drinking a beer.");

					if(gettime() - PlayerInfo[playerid][E_CHARACTER_DRINKCD] < 60)
						return SendErrorMessage(playerid, "You've only been drink beer for %i seconds. You need to wait at least 60 sec to drink beer.", gettime() - PlayerInfo[playerid][E_CHARACTER_DRINKCD]); 

					PlayerInfo[playerid][E_CHARACTER_DRINKING] = 5;
					Inventory_Remove(playerid, "Beer Bottle", 1);

					SetPlayerSpecialAction(playerid, SPECIAL_ACTION_DRINK_BEER);

					SendTipMessage(playerid, "Press 'LMB' to drink beer.");
				}
				else SendErrorMessage(playerid, "You must store your items in inventory first.");
			}
			case 1:
			{
				if(PlayerInfo[playerid][E_CHARACTER_EQUIPITEMS] == INVENTORY_NONE)
				{
					GivePlayerWeapon(playerid, 4, 999999);
					PlayerInfo[playerid][E_CHARACTER_WEAPONTYPE] = 1;
					PlayerInfo[playerid][E_CHARACTER_EQUIPITEMS] = KNIFE;
				}
				else SendErrorMessage(playerid, "You must store your items in inventory first.");
			}
		}
	}
	return 1;
}

Dialog:WeaponSLC(playerid, response, listitem, inputtext[])
{
	if(response)
	{
		switch(listitem)
		{
			case 0:
			{
				if(!Inventory_Count(playerid, "Regular Ammo"))
					return SendErrorMessage(playerid, "You don't have normal magazine in your inventory");

				GivePlayerWeapon(playerid, 23, 999999);
				PlayerInfo[playerid][E_CHARACTER_WEAPONTYPE] = 1;
				PlayerInfo[playerid][E_CHARACTER_AMMOTYPE] = AMMO_TYPE_NORMAL;
				PlayerInfo[playerid][E_CHARACTER_EQUIPITEMS] = SLC;
			}
			case 1:
			{
				if(!Inventory_Count(playerid, "Surplus Ammo"))
					return SendErrorMessage(playerid, "You don't have surplus magazine in your inventory");

				GivePlayerWeapon(playerid, 23, 999999);
				PlayerInfo[playerid][E_CHARACTER_WEAPONTYPE] = 1;
				PlayerInfo[playerid][E_CHARACTER_AMMOTYPE] = AMMO_TYPE_SURPLUS;
				PlayerInfo[playerid][E_CHARACTER_EQUIPITEMS] = SLC;
			}
			case 2:
			{
				if(!Inventory_Count(playerid, "JHP Ammo"))
					return SendErrorMessage(playerid, "You don't have jhp magazine in your inventory");

				GivePlayerWeapon(playerid, 23, 999999);
				PlayerInfo[playerid][E_CHARACTER_WEAPONTYPE] = 1;
				PlayerInfo[playerid][E_CHARACTER_AMMOTYPE] = AMMO_TYPE_JHP;
				PlayerInfo[playerid][E_CHARACTER_EQUIPITEMS] = SLC;
			}
			case 3:
			{
				if(!Inventory_Count(playerid, "Rubber Ammo"))
					return SendErrorMessage(playerid, "You don't have rubber magazine in your inventory");

				GivePlayerWeapon(playerid, 23, 999999);
				PlayerInfo[playerid][E_CHARACTER_WEAPONTYPE] = 1;
				PlayerInfo[playerid][E_CHARACTER_AMMOTYPE] = AMMO_TYPE_RUBBER;
				PlayerInfo[playerid][E_CHARACTER_EQUIPITEMS] = SLC;
			}
		}
	}
	return 1;
}

Dialog:WeaponDeagle(playerid, response, listitem, inputtext[])
{
	if(response)
	{
		switch(listitem)
		{
			case 0:
			{
				if(!Inventory_Count(playerid, "Regular Ammo"))
					return SendErrorMessage(playerid, "You don't have normal magazine in your inventory");

				GivePlayerWeapon(playerid, 24, 999999);
				PlayerInfo[playerid][E_CHARACTER_WEAPONTYPE] = 1;
				PlayerInfo[playerid][E_CHARACTER_AMMOTYPE] = AMMO_TYPE_NORMAL;
				PlayerInfo[playerid][E_CHARACTER_EQUIPITEMS] = DEAGLE;
			}
			case 1:
			{
				if(!Inventory_Count(playerid, "Surplus Ammo"))
					return SendErrorMessage(playerid, "You don't have surplus magazine in your inventory");

				GivePlayerWeapon(playerid, 22, 999999);
				PlayerInfo[playerid][E_CHARACTER_WEAPONTYPE] = 1;
				PlayerInfo[playerid][E_CHARACTER_AMMOTYPE] = AMMO_TYPE_SURPLUS;
				PlayerInfo[playerid][E_CHARACTER_EQUIPITEMS] = DEAGLE;
			}
			case 2:
			{
				if(!Inventory_Count(playerid, "JHP Ammo"))
					return SendErrorMessage(playerid, "You don't have jhp magazine in your inventory");

				GivePlayerWeapon(playerid, 22, 999999);
				PlayerInfo[playerid][E_CHARACTER_WEAPONTYPE] = 1;
				PlayerInfo[playerid][E_CHARACTER_AMMOTYPE] = AMMO_TYPE_JHP;
				PlayerInfo[playerid][E_CHARACTER_EQUIPITEMS] = DEAGLE;
			}
			case 3:
			{
				if(!Inventory_Count(playerid, "Rubber Ammo"))
					return SendErrorMessage(playerid, "You don't have rubber magazine in your inventory");

				GivePlayerWeapon(playerid, 22, 999999);
				PlayerInfo[playerid][E_CHARACTER_WEAPONTYPE] = 1;
				PlayerInfo[playerid][E_CHARACTER_AMMOTYPE] = AMMO_TYPE_RUBBER;
				PlayerInfo[playerid][E_CHARACTER_EQUIPITEMS] = DEAGLE;
			}
		}
	}
	return 1;
}

Dialog:WeaponUzi(playerid, response, listitem, inputtext[])
{
	if(response)
	{
		switch(listitem)
		{
			case 0:
			{
				if(!Inventory_Count(playerid, "Regular Ammo"))
					return SendErrorMessage(playerid, "You don't have normal magazine in your inventory");

				GivePlayerWeapon(playerid, 27, 999999);
				PlayerInfo[playerid][E_CHARACTER_WEAPONTYPE] = 1;
				PlayerInfo[playerid][E_CHARACTER_AMMOTYPE] = AMMO_TYPE_NORMAL;
				PlayerInfo[playerid][E_CHARACTER_EQUIPITEMS] = UZI;
			}
			case 1:
			{
				if(!Inventory_Count(playerid, "Surplus Ammo"))
					return SendErrorMessage(playerid, "You don't have surplus magazine in your inventory");

				GivePlayerWeapon(playerid, 27, 999999);
				PlayerInfo[playerid][E_CHARACTER_WEAPONTYPE] = 1;
				PlayerInfo[playerid][E_CHARACTER_AMMOTYPE] = AMMO_TYPE_SURPLUS;
				PlayerInfo[playerid][E_CHARACTER_EQUIPITEMS] = UZI;
			}
			case 2:
			{
				if(!Inventory_Count(playerid, "JHP Ammo"))
					return SendErrorMessage(playerid, "You don't have jhp magazine in your inventory");

				GivePlayerWeapon(playerid, 27, 999999);
				PlayerInfo[playerid][E_CHARACTER_WEAPONTYPE] = 1;
				PlayerInfo[playerid][E_CHARACTER_AMMOTYPE] = AMMO_TYPE_JHP;
				PlayerInfo[playerid][E_CHARACTER_EQUIPITEMS] = UZI;
			}
			case 3:
			{
				if(!Inventory_Count(playerid, "Rubber Ammo"))
					return SendErrorMessage(playerid, "You don't have rubber magazine in your inventory");

				GivePlayerWeapon(playerid, 27, 999999);
				PlayerInfo[playerid][E_CHARACTER_WEAPONTYPE] = 1;
				PlayerInfo[playerid][E_CHARACTER_AMMOTYPE] = AMMO_TYPE_RUBBER;
				PlayerInfo[playerid][E_CHARACTER_EQUIPITEMS] = UZI;
			}
		}
	}
	return 1;
}

Dialog:WeaponShotgun(playerid, response, listitem, inputtext[])
{
	if(response)
	{
		switch(listitem)
		{
			case 0:
			{
				if(!Inventory_Count(playerid, "Regular Ammo"))
					return SendErrorMessage(playerid, "You don't have normal magazine in your inventory");

				GivePlayerWeapon(playerid, 25, 999999);
				PlayerInfo[playerid][E_CHARACTER_WEAPONTYPE] = 1;
				PlayerInfo[playerid][E_CHARACTER_AMMOTYPE] = AMMO_TYPE_NORMAL;
				PlayerInfo[playerid][E_CHARACTER_EQUIPITEMS] = SHOTGUN;
			}
			case 1:
			{
				if(!Inventory_Count(playerid, "Surplus Ammo"))
					return SendErrorMessage(playerid, "You don't have surplus magazine in your inventory");

				GivePlayerWeapon(playerid, 25, 999999);
				PlayerInfo[playerid][E_CHARACTER_WEAPONTYPE] = 1;
				PlayerInfo[playerid][E_CHARACTER_AMMOTYPE] = AMMO_TYPE_SURPLUS;
				PlayerInfo[playerid][E_CHARACTER_EQUIPITEMS] = SHOTGUN;
			}
			case 2:
			{
				if(!Inventory_Count(playerid, "JHP Ammo"))
					return SendErrorMessage(playerid, "You don't have jhp magazine in your inventory");

				GivePlayerWeapon(playerid, 25, 999999);
				PlayerInfo[playerid][E_CHARACTER_WEAPONTYPE] = 1;
				PlayerInfo[playerid][E_CHARACTER_AMMOTYPE] = AMMO_TYPE_JHP;
				PlayerInfo[playerid][E_CHARACTER_EQUIPITEMS] = SHOTGUN;
			}
			case 3:
			{
				if(!Inventory_Count(playerid, "Rubber Ammo"))
					return SendErrorMessage(playerid, "You don't have rubber magazine in your inventory");

				GivePlayerWeapon(playerid, 25, 999999);
				PlayerInfo[playerid][E_CHARACTER_WEAPONTYPE] = 1;
				PlayerInfo[playerid][E_CHARACTER_AMMOTYPE] = AMMO_TYPE_RUBBER;
				PlayerInfo[playerid][E_CHARACTER_EQUIPITEMS] = SHOTGUN;
			}
		}
	}
	return 1;
}