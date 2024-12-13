function:OnPlayerCreateWeapon(playerid, response, weapon, ammo, price, type)
{
	if(response)
	{
		new Cents = floatround(price * 100, floatround_round);

		if(weapon == WEAPON_COLT45 && type == 1)
		{
			if(Cents > PlayerInfo[playerid][E_CHARACTER_MONEY])
				return SendErrorMessage(playerid, "You can't afford this. (Cost: $%s, Total: $%s)", FormatMoney(Cents), FormatMoney(PlayerInfo[playerid][E_CHARACTER_MONEY]));

			if(Inventory_Count(playerid, "Materials") < 50)
				return SendErrorMessage(playerid, "You must have 50 gram of materials.");

			if(ReturnFactionType(playerid) == FACTION_TYPE_ILLEGAL)
			{
    			GiveMoney(playerid, -Cents);
				Inventory_Add(playerid, "Colt 45", 346, 1);
				Inventory_Add(playerid, "Regular Ammo", 2040, ammo);
				Inventory_Remove(playerid, "Materials", 50);
				SaveCharacter(playerid);

				SendEmmetMessage(playerid, "[Weapons] {cdcdcd} You've create colt 45 for 50g Materials and $%s.", Cents);
			}
			else
			{
				
    			GiveMoney(playerid, -Cents);
				Inventory_Add(playerid, "Colt 45", 346, 1);
				Inventory_Add(playerid, "Regular Ammo", 2040, ammo);
				Inventory_Remove(playerid, "Materials", 50);
				SaveCharacter(playerid);

				SendEmmetMessage(playerid, "[Weapons] {cdcdcd} You've create colt 45 for 50g Materials and $%s.", Cents);
			}
		}
		else if(weapon == WEAPON_SILENCED && type == 1)
		{
			if(Cents > PlayerInfo[playerid][E_CHARACTER_MONEY])
				return SendErrorMessage(playerid, "You can't afford this. (Cost: $%s, Total: $%s)", FormatMoney(Cents), FormatMoney(PlayerInfo[playerid][E_CHARACTER_MONEY]));

			if(Inventory_Count(playerid, "Materials") < 60)
				return SendErrorMessage(playerid, "You must have 60 gram of materials.");

			if(ReturnFactionType(playerid) == FACTION_TYPE_ILLEGAL)
			{
    			GiveMoney(playerid, -Cents);
				Inventory_Add(playerid, "Silenced Colt", 347, 1);
				Inventory_Add(playerid, "Regular Ammo", 2040, ammo);
				Inventory_Remove(playerid, "Materials", 60);

				SaveCharacter(playerid);
				SendEmmetMessage(playerid, "[Weapons] {cdcdcd} You've create Silenced Colt for 60g Materials and $%s.", Cents);
			}
			else
			{
				
    			GiveMoney(playerid, -Cents);
				Inventory_Add(playerid, "Silenced Colt", 347, 1);
				Inventory_Add(playerid, "Regular Ammo", 2040, ammo);
				Inventory_Remove(playerid, "Materials", 60);

				SaveCharacter(playerid);
				SendEmmetMessage(playerid, "[Weapons] {cdcdcd} You've create Silenced Colt for 60g Materials and $%s.", Cents);
			}
		}
		if(weapon == WEAPON_DEAGLE && type == 1)
		{
			if(Cents > PlayerInfo[playerid][E_CHARACTER_MONEY])
				return SendErrorMessage(playerid, "You can't afford this. (Cost: $%s, Total: $%s)", FormatMoney(Cents), FormatMoney(PlayerInfo[playerid][E_CHARACTER_MONEY]));

			if(Inventory_Count(playerid, "Materials") < 80)
				return SendErrorMessage(playerid, "You must have 80 gram of materials.");

			if(ReturnFactionType(playerid) == FACTION_TYPE_ILLEGAL)
			{
				
    			GiveMoney(playerid, -Cents);
				Inventory_Add(playerid, "Desert Eagle", 348, 1);
				Inventory_Add(playerid, "Regular Ammo", 2040, ammo);
				Inventory_Remove(playerid, "Materials", 80);
				SaveCharacter(playerid);

				SendEmmetMessage(playerid, "[Weapons] {cdcdcd} You've create Desert Eagle for 80g Materials and $%s.", Cents);
			}
			else
			{
    			GiveMoney(playerid, -Cents);
				Inventory_Add(playerid, "Desert Eagle", 348, 1);
				Inventory_Add(playerid, "Regular Ammo", 2040, ammo);
				Inventory_Remove(playerid, "Materials", 50);
				SaveCharacter(playerid);

				SendEmmetMessage(playerid, "[Weapons] {cdcdcd} You've create Desert Eagle for 80g Materials and $%s.", Cents);
			}
		}
		else if(weapon == WEAPON_UZI && type == 1)
		{
			if(Cents > PlayerInfo[playerid][E_CHARACTER_MONEY])
				return SendErrorMessage(playerid, "You can't afford this. (Cost: $%s, Total: $%s)", FormatMoney(Cents), FormatMoney(PlayerInfo[playerid][E_CHARACTER_MONEY]));

			if(Inventory_Count(playerid, "Materials") < 80)
				return SendErrorMessage(playerid, "You must have 80 gram of materials.");

			if(ReturnFactionType(playerid) == FACTION_TYPE_ILLEGAL)
			{
				
    			GiveMoney(playerid, -Cents);
				Inventory_Add(playerid, "Uzi", 352, 1);
				Inventory_Add(playerid, "Regular Ammo", 2040, ammo);
				Inventory_Remove(playerid, "Materials", 80);

				SaveCharacter(playerid);
				SendEmmetMessage(playerid, "[Weapons] {cdcdcd} You've create Uzi's for 80g Materials and $%s.", Cents);
			}
			else
			{
				
    			GiveMoney(playerid, -Cents);
				Inventory_Add(playerid, "Uzi", 352, 1);
				Inventory_Add(playerid, "Regular Ammo", 2040, ammo);
				Inventory_Remove(playerid, "Materials", 80);

				SaveCharacter(playerid);
				SendEmmetMessage(playerid, "[Weapons] {cdcdcd} You've create Uzi's for 80g Materials and $%s.", Cents);
			}
		}
		else if(weapon == WEAPON_SHOTGUN && type == 1)
		{
			if(Cents > PlayerInfo[playerid][E_CHARACTER_MONEY])
				return SendErrorMessage(playerid, "You can't afford this. (Cost: $%s, Total: $%s)", FormatMoney(Cents), FormatMoney(PlayerInfo[playerid][E_CHARACTER_MONEY]));

			if(Inventory_Count(playerid, "Materials") < 100)
				return SendErrorMessage(playerid, "You must have 100 gram of materials.");

			if(ReturnFactionType(playerid) == FACTION_TYPE_ILLEGAL)
			{
				
    			GiveMoney(playerid, -Cents);
				Inventory_Add(playerid, "Shotgun", 349, 1);
				Inventory_Add(playerid, "Regular Ammo", 2040, ammo);
				Inventory_Remove(playerid, "Materials", 100);

				SaveCharacter(playerid);
				SendEmmetMessage(playerid, "[Weapons] {cdcdcd} You've create Shotgun for 100g Materials and $%s.", Cents);
			}
			else
			{
				
    			GiveMoney(playerid, -Cents);
				Inventory_Add(playerid, "Shotgun", 349, 1);
				Inventory_Add(playerid, "Regular Ammo", 2040, ammo);
				Inventory_Remove(playerid, "Materials", 100);

				SaveCharacter(playerid);
				SendEmmetMessage(playerid, "[Weapons] {cdcdcd} You've create Shotgun for 100g Materials and $%s.", Cents);
			}
		}
	}
	return 1;
}

function:OnPlayerCreateAmmo(playerid, response, type, ammo, price)
{
	if(response)
	{
		new Cents = floatround(price * 100, floatround_round);

		if(type == 0)
		{
			if(Cents > PlayerInfo[playerid][E_CHARACTER_MONEY])
				return SendErrorMessage(playerid, "You can't afford this. (Cost: $%s, Total: $%s)", FormatMoney(Cents), FormatMoney(PlayerInfo[playerid][E_CHARACTER_MONEY]));

			if(Inventory_Count(playerid, "Materials") < 20)
				return SendErrorMessage(playerid, "You must have 20 grams of materials.");

			if(ReturnFactionType(playerid) == FACTION_TYPE_ILLEGAL)
			{
				
    			GiveMoney(playerid, -Cents);
				Inventory_Add(playerid, "Regular Ammo", 2040, ammo);
				Inventory_Remove(playerid, "Materials", 20);
				SaveCharacter(playerid);

				SendEmmetMessage(playerid, "[Weapons] {cdcdcd} You've create Regular Ammo for 20g Materials and $%s.", Cents);
			}
			else
			{
				
    			GiveMoney(playerid, -Cents);
				Inventory_Add(playerid, "Regular Ammo", 2040, ammo);
				Inventory_Remove(playerid, "Materials", 20);
				SaveCharacter(playerid);

				SendEmmetMessage(playerid, "[Weapons] {cdcdcd} You've create Regular Ammo for 20g Materials and $%s.", Cents);
			}
		}
		else if(type == 1)
		{
			if(Inventory_Count(playerid, "Materials") < 30)
				return SendErrorMessage(playerid, "You must have 30 grams of materials.");

			if(Cents > PlayerInfo[playerid][E_CHARACTER_MONEY])
				return SendErrorMessage(playerid, "You can't afford this. (Cost: $%s, Total: $%s)", FormatMoney(Cents), FormatMoney(PlayerInfo[playerid][E_CHARACTER_MONEY]));
			
			if(ReturnFactionType(playerid) == FACTION_TYPE_ILLEGAL)
			{
				
    			GiveMoney(playerid, -Cents);
				Inventory_Add(playerid, "Surplus Ammo", 2040, ammo);
				Inventory_Remove(playerid, "Materials", 30);
				SaveCharacter(playerid);

				SendEmmetMessage(playerid, "[Weapons] {cdcdcd} You've create Surplus Ammo for 20g Materials and $%s.", Cents);
			}
			else
			{
				
    			GiveMoney(playerid, -Cents);
				Inventory_Add(playerid, "Surplus Ammo", 2040, ammo);	
				Inventory_Remove(playerid, "Materials", 30);
				SaveCharacter(playerid);

				SendEmmetMessage(playerid, "[Weapons] {cdcdcd} You've create Surplus Ammo for 30g Materials and $%s.", Cents);
			}
		}
	}
	return 1;
}