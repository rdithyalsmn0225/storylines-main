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
        CreateDynamic3DTextLabel(EmmetInfo[i][EMMET_TEXT], COLOR_3DTEXT, EmmetInfo[i][EMMET_POSX], EmmetInfo[i][EMMET_POSY], EmmetInfo[i][EMMET_POSZ], 3.0);
		SetDynamicActorVirtualWorld(Emmet[i], 0);
		ApplyDynamicActorAnimation(Emmet[i], "MISC", "IDLE_CHAT_02", 4.0999, 1, 0, 0, 0, 0);
	}
    return 1;
}

CMD:buymats(playerid, params[])
{
	if(!IsPlayerInRangeOfPoint(playerid, 3.0, -576.3427,-505.8364,25.5234))
		return SendErrorMessage(playerid, "You aren't near materials point.");

    if(!ServerInfo[0][E_SERVER_FABRIC])
		return SendErrorMessage(playerid, "Materials is out of stock.");

	ShowPlayerDialog(playerid, DIALOG_MATSSTORE, DIALOG_STYLE_INPUT, "Materials:", "Materials price: $5 / 1 gram of materials\nPlease input the amount of materials you want to buy:", "Enter", "Cancel");
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
	ShowPlayerDialog(playerid, DIALOG_GUNSTORE, DIALOG_STYLE_TABLIST_HEADERS, "Gunstore:", str, "Select", "Close");
	return 1;
}

CMD:buygun(playerid, params[])
{
	if(PlayerInfo[playerid][E_CHARACTER_LEVEL] < 5)
		return SendErrorMessage(playerid, "Your level is minimum to access this gunshop."); 

	if(IsPlayerInRangeOfPoint(playerid, 3.0, EmmetInfo[0][EMMET_POSX], EmmetInfo[0][EMMET_POSY], EmmetInfo[0][EMMET_POSZ]))
	{
		ShowPlayerDialog(playerid, DIALOG_EMMETSTORE, DIALOG_STYLE_TABLIST, "Emmet Hardware:", "Emmet Colt\tGlock 17\nMagazine\t9mm clip", "Select", "Cancel");
	}
	return 1;
}