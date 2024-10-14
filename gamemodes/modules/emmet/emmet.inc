new Emmet[8];

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

InsertEmmetInit()
{
    for(new i = 0; i < sizeof(EmmetInfo); i++)
    {
        Emmet[i] = CreateDynamicActor(EmmetInfo[i][EMMET_SKIN], EmmetInfo[i][EMMET_POSX], EmmetInfo[i][EMMET_POSY], EmmetInfo[i][EMMET_POSZ], EmmetInfo[i][EMMET_POSA]);
        CreateDynamic3DTextLabel(EmmetInfo[i][EMMET_TEXT], COLOR_DARKGREEN, EmmetInfo[i][EMMET_POSX], EmmetInfo[i][EMMET_POSY], EmmetInfo[i][EMMET_POSZ], 3.0);
		SetDynamicActorVirtualWorld(Emmet[i], 0);
		ApplyDynamicActorAnimation(Emmet[i], "MISC", "IDLE_CHAT_02", 4.0999, 1, 0, 0, 0, 0);
	}
    return 1;
}

stock BuyGunFromEmmet(playerid)
{
    new str1[512];
	format(str1, sizeof(str1), "Faction Storage: %d supplies", FactionInfo[PlayerInfo[playerid][E_CHARACTER_FACTION]][E_FACTION_STORAGE]);
	if(!PlayerInfo[playerid][E_CHARACTER_FACTION])
	{
        Dialog_Show(playerid, Emmets, DIALOG_STYLE_TABLIST, "Emmet Hardware:", "Emmet Colt\tGlock 17\nMagazine\t9mm clip", "Select", "Cancel");
    }
    return 1;
}

CMD:buymats(playerid, params[])
{
	if(!IsPlayerInRangeOfPoint(playerid, 3.0, -576.3427,-505.8364,25.5234))
		return SendErrorMessage(playerid, "You aren't near materials point.");

    if(!ServerInfo[0][E_SERVER_PRODUCTS])
		return SendErrorMessage(playerid, "Materials is out of stock.");

	Dialog_Show(playerid, BuyMats, DIALOG_STYLE_INPUT, "Materials:", "Materials price: $5 / 1 gram of materials\nPlease input the amount of materials you want to buy:", "Enter", "Cancel");
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
	strcat(str, "Glock-19\tMaterials 50\t$6.000\n");
	strcat(str, "Glock-17\tMaterials 55\t$6.500\n");
	strcat(str, "Glock-P80\tMaterials 60\t$7.000\n");
	strcat(str, "MAC-11\tMaterials 100\t$7.000\n");
	strcat(str, "MAC-10\tMaterials 110\t$7.500\n");
	strcat(str, "Socimi T821\tMaterials 120\t$7.500\n");
    strcat(str, "Deagle\tMaterials 80\t$7.000\n");
	strcat(str, "9mm 50x\tMaterials 50\t$1.000\n");
	strcat(str, "9x19mm 100x\tMaterials 50\t$1.000\n");
	Dialog_Show(playerid, BuyGuns, DIALOG_STYLE_TABLIST_HEADERS, "Gunstore:", str, "Select", "Close");
	return 1;
}

CMD:buygun(playerid, params[])
{
	if(PlayerInfo[playerid][E_CHARACTER_LEVEL] < 5)
		return SendErrorMessage(playerid, "You don't have permission to use this command."); 

	if(IsPlayerInRangeOfPoint(playerid, 3.0, EmmetInfo[0][EMMET_POSX], EmmetInfo[0][EMMET_POSY], EmmetInfo[0][EMMET_POSZ]))
	{
		BuyGunFromEmmet(playerid);
	}
	return 1;
}

Dialog:BuyMats(playerid, response, listitem, inputtext[])
{
	if(response)
	{
		new total = strval(inputtext) * 5;

		if (isnull(inputtext))
			return Dialog_Show(playerid, BuyMats, DIALOG_STYLE_INPUT, "Materials:", "Materials price: $5 / 1 gram of materials\nPlease input the amount of materials you want to buy:", "Enter", "Cancel");
	
		if(total > PlayerInfo[playerid][E_CHARACTER_MONEY])
			return SendErrorMessage(playerid, "You can't afford this. (Cost: $%s, Total: $%s)", FormatMoney(total), FormatMoney(PlayerInfo[playerid][E_CHARACTER_MONEY]));
		
		GiveMoney(playerid, -total);
		Inventory_Add(playerid, "Materials", 3014, strval(inputtext));
	}
	return 1;
}

Dialog:BuyGuns(playerid, response, listitem, inputtext[])
{
    if (response)
    {
        new str[512];
        switch(listitem)
        {
            case 0:
            {
                format(str, sizeof(str), "Are you sure you want to purchase a Glock 19 for $%d?", GLOCK19);
                ConfirmDialog(playerid, "Confirmation", str, "OnPlayerPurchaseWeapon", WEAPON_COLT45, 10, GLOCK19, 1); 
            }
            case 1:
            {
                format(str, sizeof(str), "Are you sure you want to purchase a Glock 17 for $%d?", GLOCK17);
                ConfirmDialog(playerid, "Confirmation", str, "OnPlayerPurchaseWeapon", WEAPON_COLT45, 10, GLOCK17, 2); 
            }
            case 2:
            {
                format(str, sizeof(str), "Are you sure you want to purchase a Glock P80 for $%d?", GLOCKP80);
                ConfirmDialog(playerid, "Confirmation", str, "OnPlayerPurchaseWeapon", WEAPON_COLT45, 10, GLOCKP80, 3); 
            }
            case 3:
            {
                format(str, sizeof(str), "Are you sure you want to purchase a Mac-11 for $%d?", MAC11);
                ConfirmDialog(playerid, "Confirmation", str, "OnPlayerPurchaseWeapon", WEAPON_UZI, 10, MAC11, 1); 
            }
            case 4:
            {
                format(str, sizeof(str), "Are you sure you want to purchase a Mac-11 for $%d?", MAC10);
                ConfirmDialog(playerid, "Confirmation", str, "OnPlayerPurchaseWeapon", WEAPON_UZI, 10, MAC10, 2); 
            }
            case 5:
            {
                format(str, sizeof(str), "Are you sure you want to purchase a Mac-11 for $%d?", SOCIMIT821);
                ConfirmDialog(playerid, "Confirmation", str, "OnPlayerPurchaseWeapon", WEAPON_UZI, 10, SOCIMIT821, 3); 
            }
            case 6:
            {
                format(str, sizeof(str), "Are you sure you want to purchase a Deagle for $%d?", SOCIMIT821);
                ConfirmDialog(playerid, "Confirmation", str, "OnPlayerPurchaseWeapon", WEAPON_DEAGLE, 10, DEAGLES, 2); 
            }
            case 7:
            {
                format(str, sizeof(str), "Are you sure you want to buy ammo for $%d?", A9MM); 
                ConfirmDialog(playerid, "Confirmation", str, "OnPlayerPurchaseAmmo", 0, 50, A9MM); 
            }
            case 8:
            {
                format(str, sizeof(str), "Are you sure you want to buy ammo for $%d?", A9X19MM); 
                ConfirmDialog(playerid, "Confirmation", str, "OnPlayerPurchaseAmmo", 1, 100, A9X19MM); 
            }
        }
    }
    return 1;
}

Dialog:Emmets(playerid, response, listitem, inputtext[])
{
    if (response)
    {
        switch(listitem)
        {
            case 0:
            {
                new str[512];
                format(str, sizeof(str), "Are you sure you want to purchase a Emmet Pistol for $%d?", 4000);
                ConfirmDialog(playerid, "Confirmation", str, "OnPlayerPurchaseWeapon", WEAPON_COLT45, 25, 4000, 1); 
            }
            case 1:
            {
                new str[512];
                format(str, sizeof(str), "Are you sure you want to buy ammo for $%d?", A9MM); 
                ConfirmDialog(playerid, "Confirmation", str, "OnPlayerPurchaseAmmo", 0, 25, A9MM); 
            }
        }
    }
    return 1;
}