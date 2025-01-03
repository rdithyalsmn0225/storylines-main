CMD:buymats(playerid, params[])
{
	if(!IsPlayerInRangeOfPoint(playerid, 3.0, -576.3427,-505.8364,25.5234))
		return SendErrorMessage(playerid, "You aren't near materials point.");

    if(!ServerInfo[0][E_SERVER_FABRIC])
		return SendErrorMessage(playerid, "Materials is out of stock.");

	Dialog_Show(playerid, DialogMatsStore, DIALOG_STYLE_INPUT, "Materials:", "Materials price: $20 / 1 gram of materials\nPlease input the amount of materials you want to buy:", "Submit", "Cancel");
	return 1;
}

CMD:creategun(playerid, params[])
{
	if(!IsPlayerInBusiness(playerid) && !IsPlayerNearCashiers(playerid))
		return SendErrorMessage(playerid, "You aren't in a business.");
		
	if(BusinessInfo[IsPlayerInBusiness(playerid)][E_BUSINESS_TYPE] != BUSINESS_TYPE_GUNSTORE)
		return SendErrorMessage(playerid, "You aren't in an gunstore."); 

	if(BusinessInfo[IsPlayerInBusiness(playerid)][E_BUSINESS_ROBBERYTIME] > 0)
		return SendErrorMessage(playerid, "This Business has been robbery.");

	new str[512];
	strcat(str, "Weapons\tMaterials\tWeapon Ammo\n");
	strcat(str, "Colt 45\t80 grams\t9x19mm Parabellum\n");
    strcat(str, "Silenced Colt\t90 grams\t9x19mm Parabellum\n");
	strcat(str, "Uzi Submachine gun\t120 grams\t9x19mm Parabellum\n");
    strcat(str, "Desert Eagle's\t120 grams\t.44 Magnum\n");
    strcat(str, "Shotgun\t100 grams\t12 Gauge\n");
	strcat(str, "Regular Ammo (10x)\t10 grams\tNo Buffs\n");
	strcat(str, "Surplus (10x)\t10 grams\t+10% Damages\n");
	Dialog_Show(playerid, DialogGunStore, DIALOG_STYLE_TABLIST_HEADERS, "Gunstore:", str, "Select", "Close");
	return 1;
}

Dialog:DialogMatsStore(playerid, response, listitem, inputtext[])
{
	if(response)
	{
		new total = strval(inputtext) * 20;
		new Cents = floatround(total * 100, floatround_round);

		if (isnull(inputtext))
			return Dialog_Show(playerid, DialogMatsStore, DIALOG_STYLE_INPUT, "Materials:", "Materials price: $0.10 / 1 gram of materials\nPlease input the amount of materials you want to buy:", "Enter", "Cancel");
	
		if(Cents > PlayerInfo[playerid][E_CHARACTER_MONEY])
			return SendErrorMessage(playerid, "You can't afford this. (Cost: $%s, Total: $%s)", FormatMoney(Cents), FormatMoney(PlayerInfo[playerid][E_CHARACTER_MONEY]));
		
		GiveMoney(playerid, -Cents);
		Inventory_Add(playerid, "Materials", 3014, strval(inputtext));
	}
	return 1;
}

Dialog:DialogGunStore(playerid, response, listitem, inputtext[])
{
	if (response)
	{
		new str[256];
		switch(listitem)
		{
			case 0:
			{
				format(str, sizeof(str), "Are you sure you want to purchase a Colt 45 for 80 gram materials?");
				ConfirmDialog(playerid, "Confirmation", str, "OnPlayerCreateWeapon", WEAPON_COLT45, 10, 80, 1); 
			}
			case 1:
			{
				format(str, sizeof(str), "Are you sure you want to purchase a Silenced Colt for 90 gram materials?");
				ConfirmDialog(playerid, "Confirmation", str, "OnPlayerCreateWeapon", WEAPON_COLT45, 10, 90, 1); 
			}
			case 2:
			{
				format(str, sizeof(str), "Are you sure you want to purchase a Uzi for 120 gram materials?");
				ConfirmDialog(playerid, "Confirmation", str, "OnPlayerCreateWeapon", WEAPON_UZI, 10, 120, 1); 
			}
			case 3:
			{
				format(str, sizeof(str), "Are you sure you want to purchase a Deagle for 120 gram materials?");
				ConfirmDialog(playerid, "Confirmation", str, "OnPlayerCreateWeapon", WEAPON_DEAGLE, 10, 120, 1); 
			}
			case 4:
			{
				format(str, sizeof(str), "Are you sure you want to purchase a Shotgun for 100 gram materials?");
				ConfirmDialog(playerid, "Confirmation", str, "OnPlayerCreateWeapon", WEAPON_SHOTGUN, 10, 100, 1); 
			}
			case 5:
			{
				format(str, sizeof(str), "Are you sure you want to buy ammo for 10 gram materials?");
				ConfirmDialog(playerid, "Confirmation", str, "OnPlayerCreateAmmo", 0, 10); 
			}
			case 6:
			{
				format(str, sizeof(str), "Are you sure you want to buy ammo for 10 gram materials?");
				ConfirmDialog(playerid, "Confirmation", str, "OnPlayerCreateAmmo", 1, 10); 
			}
		}
	}
	return 1;
}