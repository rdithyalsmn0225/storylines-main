enum E_EMMET_DATA
{
    EMMET_SKIN,
    EMMET_TEXT[128],
    Float: EMMET_POSX,
    Float: EMMET_POSY,
    Float: EMMET_POSZ,
    Float: EMMET_POSA
};

new const EmmetInfo[][E_EMMET_DATA] =
{
    {6, "[Emmet's Hardware]\n{ffffff}Available Commands: /buygun", 2442.4590,-1969.1083,13.5469,180.6462}
};

CMD:buymats(playerid, params[])
{
	if(!IsPlayerInRangeOfPoint(playerid, 3.0, -576.3427,-505.8364,25.5234))
		return SendErrorMessage(playerid, "You aren't near materials point.");

    if(ServerInfo[0][E_SERVER_FABRIC] < 1)
		return SendErrorMessage(playerid, "Materials is out of stock.");

	Dialog_Show(playerid, DialogMatsStore, DIALOG_STYLE_INPUT, "Materials:", "Materials price: $5 / 1 gram of materials\nPlease input the amount of materials you want to buy:", "Enter", "Cancel");
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
	strcat(str, "Weapons\tIngredient\tPrice\n");
	strcat(str, "Colt 45\tMaterials 50\t$2,000.00\n");
    strcat(str, "Silenced Colt\tMaterials 60\t$2,500.00\n");
	strcat(str, "Uzi\tMaterials 70\t$4,000.00\n");
    strcat(str, "Desert Eagle\tMaterials 80\t$5,000.00\n");
    strcat(str, "Desert Eagle\tMaterials 100\t$3,000.00\n");
	strcat(str, "Reguler Ammo (10x)\tMaterials 10\t$100.00\n");
	strcat(str, "Surplus (10x)\tMaterials 10\t$250.00\n");
	Dialog_Show(playerid, DialogGunStore, DIALOG_STYLE_TABLIST_HEADERS, "Gunstore:", str, "Select", "Close");
	return 1;
}

Dialog:DialogMatsStore(playerid, response, listitem, inputtext[])
{
	if(response)
	{
		new total = strval(inputtext) * 10;
		new Cents = floatround(total * 100, floatround_round);

		if (isnull(inputtext))
			return Dialog_Show(playerid, DialogMatsStore, DIALOG_STYLE_INPUT, "Materials:", "Materials price: $0.10 / 1 gram of materials\nPlease input the amount of materials you want to buy:", "Enter", "Cancel");
	
		if(total > PlayerInfo[playerid][E_CHARACTER_MONEY])
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
				new Cents = floatround(WEAPON_SLC * 100, floatround_round);
				format(str, sizeof(str), "Are you sure you want to purchase a Colt 45 for {33AA33}$%s{ffffff}?", FormatMoney(Cents));
				ConfirmDialog(playerid, "Confirmation", str, "OnPlayerCreateWeapon", WEAPON_COLT45, 10, WEAPON_COLT, 1); 
			}
			case 1:
			{
				new Cents = floatround(WEAPON_SLC * 100, floatround_round);
				format(str, sizeof(str), "Are you sure you want to purchase a Silenced Colt for {33AA33}$%s{ffffff}?", FormatMoney(Cents));
				ConfirmDialog(playerid, "Confirmation", str, "OnPlayerCreateWeapon", WEAPON_COLT45, 10, WEAPON_SLC, 1); 
			}
			case 2:
			{
				new Cents = floatround(WEAPON_UZIS * 100, floatround_round);
				format(str, sizeof(str), "Are you sure you want to purchase a Uzi for {33AA33}$%s{ffffff}?", FormatMoney(Cents));
				ConfirmDialog(playerid, "Confirmation", str, "OnPlayerCreateWeapon", WEAPON_UZI, 10, WEAPON_UZIS, 1); 
			}
			case 3:
			{
				new Cents = floatround(WEAPON_DEAGLES * 100, floatround_round);
				format(str, sizeof(str), "Are you sure you want to purchase a Deagle for {33AA33}$%s{ffffff}?", FormatMoney(Cents));
				ConfirmDialog(playerid, "Confirmation", str, "OnPlayerCreateWeapon", WEAPON_DEAGLE, 10, WEAPON_DEAGLES, 1); 
			}
			case 4:
			{
				new Cents = floatround(WEAPON_SHOTGUNS * 100, floatround_round);
				format(str, sizeof(str), "Are you sure you want to purchase a Shotgun for {33AA33}$%s{ffffff}?", FormatMoney(Cents));
				ConfirmDialog(playerid, "Confirmation", str, "OnPlayerCreateWeapon", WEAPON_SHOTGUN, 10, WEAPON_DEAGLES, 1); 
			}
			case 5:
			{
				new Cents = floatround(A9MM * 100, floatround_round);
				format(str, sizeof(str), "Are you sure you want to buy ammo for {33AA33}$%s{ffffff}?", FormatMoney(Cents)); 
				ConfirmDialog(playerid, "Confirmation", str, "OnPlayerCreateAmmo", 0, 10, A9MM); 
			}
			case 6:
			{
				new Cents = floatround(A9X19MM * 100, floatround_round);
				format(str, sizeof(str), "Are you sure you want to buy ammo for {33AA33}$%s{ffffff}?", FormatMoney(Cents)); 
				ConfirmDialog(playerid, "Confirmation", str, "OnPlayerCreateAmmo", 1, 10, A9X19MM); 
			}
		}
	}
	return 1;
}