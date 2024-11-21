function:OnPlayerCreateWeapon(playerid, response, weapon, ammo, price, type)
{
	if(response)
	{
		new Cents = floatround(price * 100, floatround_round);

		if(weapon == WEAPON_COLT45 && type == 1)
		{
			if(price > PlayerInfo[playerid][E_CHARACTER_MONEY])
				return SendErrorMessage(playerid, "You can't afford this. (Cost: $%s, Total: $%s)", FormatMoney(Cents), FormatMoney(PlayerInfo[playerid][E_CHARACTER_MONEY]));

			if(Inventory_Count(playerid, "Materials") < 50)
				return SendErrorMessage(playerid, "You must have 50 gram of materials.");

			if(ReturnFactionType(playerid) == FACTION_TYPE_ILLEGAL)
			{
    			GiveMoney(playerid, -Cents);
				Inventory_Add(playerid, "Colt 45", -2205, 1);
				Inventory_Add(playerid, "Regular Ammo", 2040, ammo);
				Inventory_Remove(playerid, "Materials", 50);
				SaveCharacter(playerid);
			}
			else
			{
				
    			GiveMoney(playerid, -Cents);
				Inventory_Add(playerid, "Colt 45", -2205, 1);
				Inventory_Add(playerid, "Regular Ammo", 2040, ammo);
				Inventory_Remove(playerid, "Materials", 50);

				SaveCharacter(playerid);
			}
		}
		else if(weapon == WEAPON_SILENCED && type == 1)
		{
			if(price > PlayerInfo[playerid][E_CHARACTER_MONEY])
				return SendErrorMessage(playerid, "You can't afford this. (Cost: $%s, Total: $%s)", FormatMoney(Cents), FormatMoney(PlayerInfo[playerid][E_CHARACTER_MONEY]));

			if(Inventory_Count(playerid, "Materials") < 60)
				return SendErrorMessage(playerid, "You must have 60 gram of materials.");

			if(ReturnFactionType(playerid) == FACTION_TYPE_ILLEGAL)
			{
				
    			GiveMoney(playerid, -Cents);
				Inventory_Add(playerid, "Silenced Colt", -2207, 1);
				Inventory_Add(playerid, "Regular Ammo", 2040, ammo);
				Inventory_Remove(playerid, "Materials", 60);

				SaveCharacter(playerid);
			}
			else
			{
				
    			GiveMoney(playerid, -Cents);
				Inventory_Add(playerid, "Silenced Colt", -2207, 1);
				Inventory_Add(playerid, "Regular Ammo", 2040, ammo);
				Inventory_Remove(playerid, "Materials", 60);

				SaveCharacter(playerid);
			}
		}
		if(weapon == WEAPON_DEAGLE && type == 1)
		{
			if(price > PlayerInfo[playerid][E_CHARACTER_MONEY])
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
			}
			else
			{
    			GiveMoney(playerid, -Cents);
				Inventory_Add(playerid, "Desert Eagle", -2205, 1);
				Inventory_Add(playerid, "Regular Ammo", 2040, ammo);
				Inventory_Remove(playerid, "Materials", 50);

				SaveCharacter(playerid);
			}
		}
		else if(weapon == WEAPON_UZI && type == 1)
		{
			if(price > PlayerInfo[playerid][E_CHARACTER_MONEY])
				return SendErrorMessage(playerid, "You can't afford this. (Cost: $%s, Total: $%s)", FormatMoney(Cents), FormatMoney(PlayerInfo[playerid][E_CHARACTER_MONEY]));

			if(Inventory_Count(playerid, "Materials") < 80)
				return SendErrorMessage(playerid, "You must have 80 gram of materials.");

			if(ReturnFactionType(playerid) == FACTION_TYPE_ILLEGAL)
			{
				
    			GiveMoney(playerid, -Cents);
				Inventory_Add(playerid, "Uzi", -2207, 1);
				Inventory_Add(playerid, "Regular Ammo", 2040, ammo);
				Inventory_Remove(playerid, "Materials", 80);

				SaveCharacter(playerid);
			}
			else
			{
				
    			GiveMoney(playerid, -Cents);
				Inventory_Add(playerid, "Uzi", -2207, 1);
				Inventory_Add(playerid, "Regular Ammo", 2040, ammo);
				Inventory_Remove(playerid, "Materials", 80);

				SaveCharacter(playerid);
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
			if(price > PlayerInfo[playerid][E_CHARACTER_MONEY])
				return SendErrorMessage(playerid, "You can't afford this. (Cost: $%s, Total: $%s)", FormatMoney(Cents), FormatMoney(PlayerInfo[playerid][E_CHARACTER_MONEY]));

			if(Inventory_Count(playerid, "Materials") < 20)
				return SendErrorMessage(playerid, "You must have 20 grams of materials.");

			if(ReturnFactionType(playerid) == FACTION_TYPE_ILLEGAL)
			{
				
    			GiveMoney(playerid, -Cents);
				Inventory_Add(playerid, "Regular Ammo", 2040, ammo);
				Inventory_Remove(playerid, "Materials", 20);
				SaveCharacter(playerid);
			}
			else
			{
				
    			GiveMoney(playerid, -Cents);
				Inventory_Add(playerid, "Regular Ammo", 2040, ammo);
				Inventory_Remove(playerid, "Materials", 20);
				SaveCharacter(playerid);
			}
		}
		else if(type == 1)
		{
			if(Inventory_Count(playerid, "Materials") < 30)
				return SendErrorMessage(playerid, "You must have 30 grams of materials.");

			if(price > PlayerInfo[playerid][E_CHARACTER_MONEY])
				return SendErrorMessage(playerid, "You can't afford this. (Cost: $%s, Total: $%s)", FormatMoney(Cents), FormatMoney(PlayerInfo[playerid][E_CHARACTER_MONEY]));
			
			if(ReturnFactionType(playerid) == FACTION_TYPE_ILLEGAL)
			{
				
    			GiveMoney(playerid, -Cents);
				Inventory_Add(playerid, "Surplus Ammo", 2040, ammo);
				Inventory_Remove(playerid, "Materials", 30);
				SaveCharacter(playerid);
			}
			else
			{
				
    			GiveMoney(playerid, -Cents);
				Inventory_Add(playerid, "Surplus Ammo", 2040, ammo);	
				Inventory_Remove(playerid, "Materials", 30);
				SaveCharacter(playerid);
			}
		}
	}
	return 1;
}