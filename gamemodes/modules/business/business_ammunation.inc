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
				Inventory_Add(playerid, "Glock 19", -2205, 1);
				Inventory_Add(playerid, "9mm", 2040, ammo);
				Inventory_Remove(playerid, "Materials", 50);
				SaveCharacter(playerid);
			}
			else
			{
				
    			GiveMoney(playerid, -Cents);
				Inventory_Add(playerid, "Glock 19", -2205, 1);
				Inventory_Add(playerid, "9mm", 2040, ammo);
				Inventory_Remove(playerid, "Materials", 50);

				SaveCharacter(playerid);
			}
		}
		else if(weapon == WEAPON_COLT45 && type == 2)
		{
			if(price > PlayerInfo[playerid][E_CHARACTER_MONEY])
				return SendErrorMessage(playerid, "You can't afford this. (Cost: $%s, Total: $%s)", FormatMoney(Cents), FormatMoney(PlayerInfo[playerid][E_CHARACTER_MONEY]));
			
			if(Inventory_Count(playerid, "Materials") < 55)
				return SendErrorMessage(playerid, "You must have 50 gram of materials.");

			if(ReturnFactionType(playerid) == FACTION_TYPE_ILLEGAL)
			{
				
    			GiveMoney(playerid, -Cents);
				Inventory_Add(playerid, "Glock 17", -2204, 1);
				Inventory_Add(playerid, "9mm", 2040, ammo);
				Inventory_Remove(playerid, "Materials", 55);

				SaveCharacter(playerid);
			}
			else
			{
				
    			GiveMoney(playerid, -Cents);
				Inventory_Add(playerid, "Glock 17", -2204, 1);
				Inventory_Add(playerid, "9mm", 2040, ammo);
				Inventory_Remove(playerid, "Materials", 55);

				SaveCharacter(playerid);
			}
		}
		else if(weapon == WEAPON_COLT45 && type == 3)
		{
			if(price > PlayerInfo[playerid][E_CHARACTER_MONEY])
				return SendErrorMessage(playerid, "You can't afford this. (Cost: $%s, Total: $%s)", FormatMoney(Cents), FormatMoney(PlayerInfo[playerid][E_CHARACTER_MONEY]));

			if(Inventory_Count(playerid, "Materials") < 60)
				return SendErrorMessage(playerid, "You must have 50 gram of materials.");

			if(ReturnFactionType(playerid) == FACTION_TYPE_ILLEGAL)
			{
				
    			GiveMoney(playerid, -Cents);
				Inventory_Add(playerid, "Glock P80", -2206, 1);
				Inventory_Add(playerid, "9mm", 2040, ammo);
				Inventory_Remove(playerid, "Materials", 60);

				SaveCharacter(playerid);
			}
			else
			{
				
    			GiveMoney(playerid, -Cents);
				Inventory_Add(playerid, "Glock P80", -2206, 1);
				Inventory_Add(playerid, "9mm", 2040, ammo);
				Inventory_Remove(playerid, "Materials", 60);

				SaveCharacter(playerid);
			}
		}
		if(weapon == WEAPON_DEAGLE && type == 2)
		{
			if(price > PlayerInfo[playerid][E_CHARACTER_MONEY])
				return SendErrorMessage(playerid, "You can't afford this. (Cost: $%s, Total: $%s)", FormatMoney(Cents), FormatMoney(PlayerInfo[playerid][E_CHARACTER_MONEY]));

			if(Inventory_Count(playerid, "Materials") < 80)
				return SendErrorMessage(playerid, "You must have 50 gram of materials.");

			if(ReturnFactionType(playerid) == FACTION_TYPE_ILLEGAL)
			{
				
    			GiveMoney(playerid, -Cents);
				Inventory_Add(playerid, "Deagle", 348, 1);
				Inventory_Add(playerid, "9mm", 2040, ammo);
				Inventory_Remove(playerid, "Materials", 80);
				SaveCharacter(playerid);
			}
			else
			{
				
    			GiveMoney(playerid, -Cents);
				Inventory_Add(playerid, "Glock 19", -2205, 1);
				Inventory_Add(playerid, "9mm", 2040, ammo);
				Inventory_Remove(playerid, "Materials", 50);

				SaveCharacter(playerid);
			}
		}
		else if(weapon == WEAPON_UZI && type == 1)
		{
			if(price > PlayerInfo[playerid][E_CHARACTER_MONEY])
				return SendErrorMessage(playerid, "You can't afford this. (Cost: $%s, Total: $%s)", FormatMoney(Cents), FormatMoney(PlayerInfo[playerid][E_CHARACTER_MONEY]));

			if(Inventory_Count(playerid, "Materials") < 100)
				return SendErrorMessage(playerid, "You must have 50 gram of materials.");

			if(ReturnFactionType(playerid) == FACTION_TYPE_ILLEGAL)
			{
				
    			GiveMoney(playerid, -Cents);
				Inventory_Add(playerid, "Mac 11", -2207, 1);
				Inventory_Add(playerid, "9x19mm", 2040, ammo);
				Inventory_Remove(playerid, "Materials", 100);

				SaveCharacter(playerid);
			}
			else
			{
				
    			GiveMoney(playerid, -Cents);
				Inventory_Add(playerid, "Mac 11", -2207, 1);
				Inventory_Add(playerid, "9x19mm", 2040, ammo);
				Inventory_Remove(playerid, "Materials", 100);

				SaveCharacter(playerid);
			}
		}
		else if(weapon == WEAPON_UZI && type == 2)
		{
			if(price > PlayerInfo[playerid][E_CHARACTER_MONEY])
				return SendErrorMessage(playerid, "You can't afford this. (Cost: $%s, Total: $%s)", FormatMoney(Cents), FormatMoney(PlayerInfo[playerid][E_CHARACTER_MONEY]));
			
			if(Inventory_Count(playerid, "Materials") < 110)
				return SendErrorMessage(playerid, "You must have 50 gram of materials.");

			if(ReturnFactionType(playerid) == FACTION_TYPE_ILLEGAL)
			{
				
    			GiveMoney(playerid, -Cents);
				Inventory_Add(playerid, "Mac 12", -2208, 1);
				Inventory_Add(playerid, "9x19mm", 2040, ammo);
				Inventory_Remove(playerid, "Materials", 110);

				SaveCharacter(playerid);
			}
			else
			{
				
    			GiveMoney(playerid, -Cents);
				Inventory_Add(playerid, "Mac 12", -2208, 1);
				Inventory_Add(playerid, "9x19mm", 2040, ammo);
				Inventory_Remove(playerid, "Materials", 110);

				SaveCharacter(playerid);
			}
		}
		else if(weapon == WEAPON_UZI && type == 3)
		{
			if(Inventory_Count(playerid, "Materials") < 120)
				return SendErrorMessage(playerid, "You must have 50 gram of materials.");

			if(price > PlayerInfo[playerid][E_CHARACTER_MONEY])
				return SendErrorMessage(playerid, "You can't afford this. (Cost: $%s, Total: $%s)", FormatMoney(Cents), FormatMoney(PlayerInfo[playerid][E_CHARACTER_MONEY]));
			
			if(ReturnFactionType(playerid) == FACTION_TYPE_ILLEGAL)
			{
				
    			GiveMoney(playerid, -Cents);
				Inventory_Add(playerid, "Socimi Type 821", -2209, 1);
				Inventory_Add(playerid, "9x19mm", 2040, ammo);
				Inventory_Remove(playerid, "Materials", 120);

				SaveCharacter(playerid);
			}
			else
			{
				
    			GiveMoney(playerid, -Cents);
				Inventory_Add(playerid, "Socimi Type 821", -2209);
				Inventory_Add(playerid, "9x19mm", 2040, ammo);
				Inventory_Remove(playerid, "Materials", 120);

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

			if(Inventory_Count(playerid, "Materials") < 120)
				return SendErrorMessage(playerid, "You must have 50 gram of materials.");

			if(ReturnFactionType(playerid) == FACTION_TYPE_ILLEGAL)
			{
				
    			GiveMoney(playerid, -Cents);
				Inventory_Add(playerid, "9mm", 2040, ammo);
				Inventory_Remove(playerid, "Materials", 35);
				SaveCharacter(playerid);
			}
			else
			{
				
    			GiveMoney(playerid, -Cents);
				Inventory_Add(playerid, "9mm", 2040, ammo);
				Inventory_Remove(playerid, "Materials", 35);
				SaveCharacter(playerid);
			}
		}
		else if(type == 1)
		{
			if(Inventory_Count(playerid, "Materials") < 120)
				return SendErrorMessage(playerid, "You must have 50 gram of materials.");

			if(price > PlayerInfo[playerid][E_CHARACTER_MONEY])
				return SendErrorMessage(playerid, "You can't afford this. (Cost: $%s, Total: $%s)", FormatMoney(Cents), FormatMoney(PlayerInfo[playerid][E_CHARACTER_MONEY]));
			
			if(ReturnFactionType(playerid) == FACTION_TYPE_ILLEGAL)
			{
				
    			GiveMoney(playerid, -Cents);
				Inventory_Add(playerid, "9x19mm", 2040, ammo);
				Inventory_Remove(playerid, "Materials", 30);
				SaveCharacter(playerid);
			}
			else
			{
				
    			GiveMoney(playerid, -Cents);
				Inventory_Add(playerid, "9x19mm", 2040, ammo);	
				Inventory_Remove(playerid, "Materials", 30);
				SaveCharacter(playerid);
			}
		}
	}
	return 1;
}