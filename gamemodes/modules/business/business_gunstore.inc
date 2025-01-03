function:OnPlayerCreateWeapon(playerid, response, weapon, ammo, material, type)
{
	if(response)
	{
		if(weapon == WEAPON_COLT45 && type == 1)
		{
			if(Inventory_Count(playerid, "Materials") < material)
				return SendErrorMessage(playerid, "You must have %d gram of materials.", material);

			if(ReturnFactionType(playerid) == FACTION_TYPE_ILLEGAL)
			{
    			
				Inventory_Add(playerid, "Colt 45", 346, 1);
				Inventory_Add(playerid, "Regular Ammo", 2040, ammo);
				Inventory_Remove(playerid, "Materials", material);
				SaveCharacter(playerid);

				SendCrimeMessage(playerid, "[WEAPONS] You've create Colt's for %d gram materials.", material);
			}
			else
			{
				Inventory_Add(playerid, "Colt 45", 346, 1);
				Inventory_Add(playerid, "Regular Ammo", 2040, ammo);
				Inventory_Remove(playerid, "Materials", material);
				SaveCharacter(playerid);

				SendCrimeMessage(playerid, "[WEAPONS] You've create Colt's for %d gram materials.", material);
			}
		}
		else if(weapon == WEAPON_SILENCED && type == 1)
		{
			if(Inventory_Count(playerid, "Materials") < material)
				return SendErrorMessage(playerid, "You must have %d gram of materials.", material);

			if(ReturnFactionType(playerid) == FACTION_TYPE_ILLEGAL)
			{
				Inventory_Add(playerid, "Silenced Colt", 347, 1);
				Inventory_Add(playerid, "Regular Ammo", 2040, ammo);
				Inventory_Remove(playerid, "Materials", material);

				SaveCharacter(playerid);
				SendCrimeMessage(playerid, "[WEAPONS] You've create Silence Colt's for %d gram materials.", material);
			}
			else
			{
				Inventory_Add(playerid, "Silenced Colt", 347, 1);
				Inventory_Add(playerid, "Regular Ammo", 2040, ammo);
				Inventory_Remove(playerid, "Materials", material);

				SaveCharacter(playerid);
				SendCrimeMessage(playerid, "[WEAPONS] You've create Silence Colt's for %d gram materials.", material);
			}
		}
		else if(weapon == WEAPON_DEAGLE && type == 1)
		{
			if(Inventory_Count(playerid, "Materials") < material)
				return SendErrorMessage(playerid, "You must have %d gram of materials.", material);

			if(ReturnFactionType(playerid) == FACTION_TYPE_ILLEGAL)
			{
				Inventory_Add(playerid, "Desert Eagle", 348, 1);
				Inventory_Add(playerid, "Regular Ammo", 2040, ammo);
				Inventory_Remove(playerid, "Materials", material);
				SaveCharacter(playerid);

				SendCrimeMessage(playerid, "[WEAPONS] You've create Desert Eagle's for %d gram materials.", material);
			}
			else
			{
				Inventory_Add(playerid, "Desert Eagle", 348, 1);
				Inventory_Add(playerid, "Regular Ammo", 2040, ammo);
				Inventory_Remove(playerid, "Materials", material);
				SaveCharacter(playerid);

				SendCrimeMessage(playerid, "[WEAPONS] You've create Desert Eagle's for %d gram materials.", material);
			}
		}
		else if(weapon == WEAPON_UZI && type == 1)
		{
			if(Inventory_Count(playerid, "Materials") < material)
				return SendErrorMessage(playerid, "You must have %d gram of materials.", material);

			if(ReturnFactionType(playerid) == FACTION_TYPE_ILLEGAL)
			{
				Inventory_Add(playerid, "Uzi", 352, 1);
				Inventory_Add(playerid, "Regular Ammo", 2040, ammo);
				Inventory_Remove(playerid, "Materials", material);

				SaveCharacter(playerid);
				SendCrimeMessage(playerid, "[WEAPONS] You've create Uzi's for %d gram materials.", material);
			}
			else
			{
				Inventory_Add(playerid, "Uzi", 352, 1);
				Inventory_Add(playerid, "Regular Ammo", 2040, ammo);
				Inventory_Remove(playerid, "Materials", 80);

				SaveCharacter(playerid);
				SendCrimeMessage(playerid, "[WEAPONS] You've create Uzi's for %d gram materials.", material);
			}
		}
		else if(weapon == WEAPON_SHOTGUN && type == 1)
		{
			if(Inventory_Count(playerid, "Materials") < material)
				return SendErrorMessage(playerid, "You must have %d gram of materials.", material);

			if(ReturnFactionType(playerid) == FACTION_TYPE_ILLEGAL)
			{

				Inventory_Add(playerid, "Shotgun", 349, 1);
				Inventory_Add(playerid, "Regular Ammo", 2040, ammo);
				Inventory_Remove(playerid, "Materials", material);

				SaveCharacter(playerid);
				SendCrimeMessage(playerid, "[WEAPONS] You've create Shotgun for %d gram materials.", material);
			}
			else
			{
				Inventory_Add(playerid, "Shotgun", 349, 1);
				Inventory_Add(playerid, "Regular Ammo", 2040, ammo);
				Inventory_Remove(playerid, "Materials", 100);

				SaveCharacter(playerid);
				SendCrimeMessage(playerid, "[WEAPONS] You've create Shotgun for %d gram materials.", material);
			}
		}
	}
	return 1;
}

function:OnPlayerCreateAmmo(playerid, response, type, ammo, price)
{
	if(response)
	{
		if(type == 0)
		{
			if(Inventory_Count(playerid, "Materials") < 10)
				return SendErrorMessage(playerid, "You must have 10 grams of materials.");

			if(ReturnFactionType(playerid) == FACTION_TYPE_ILLEGAL)
			{
				
    			
				Inventory_Add(playerid, "Regular Ammo", 2040, ammo);
				Inventory_Remove(playerid, "Materials", 10);
				SaveCharacter(playerid);

				SendCrimeMessage(playerid, "[WEAPONS] You've create Regular Ammo for 10 grams materials");
			}
			else
			{
				
    			
				Inventory_Add(playerid, "Regular Ammo", 2040, ammo);
				Inventory_Remove(playerid, "Materials", 20);
				SaveCharacter(playerid);

				SendCrimeMessage(playerid, "[WEAPONS] You've create Regular Ammo for 10 grams materials");
			}
		}
		else if(type == 1)
		{
			if(Inventory_Count(playerid, "Materials") < 30)
				return SendErrorMessage(playerid, "You must have 30 grams of materials.");

						
			if(ReturnFactionType(playerid) == FACTION_TYPE_ILLEGAL)
			{
				
    			
				Inventory_Add(playerid, "Surplus Ammo", 2040, ammo);
				Inventory_Remove(playerid, "Materials", 30);
				SaveCharacter(playerid);

				SendCrimeMessage(playerid, "[WEAPONS] You've create Regular Ammo for 10 grams materials");
			}
			else
			{
				
    			
				Inventory_Add(playerid, "Surplus Ammo", 2040, ammo);	
				Inventory_Remove(playerid, "Materials", 30);
				SaveCharacter(playerid);

				SendCrimeMessage(playerid, "[WEAPONS] You've create Regular Ammo for 10 grams materials");
			}
		}
	}
	return 1;
}