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
    {6, "[Emmet's Hardware]\n{ffffff}Available Commands: /buygun", 2442.4590,-1969.1083,13.5469,180.6462},
    {20033, "[TDF Gun's Dealer]\n{ffffff}Available Commands: /buygun", 1125.0013,-1023.2226,31.1027,86.1012},
    {20090, "[KTB Gun's Dealer]\n{ffffff}Available Commands: /buygun", 2015.2699,-1284.4753,23.9844,263.7494},
    {20085, "[RHB Gun's Dealer]\n{ffffff}Available Commands: /buygun", 2168.6335,-1506.7484,23.9284,41.4714},
    {20092, "[FYB Gun's Dealer]\n{ffffff}Available Commands: /buygun", 1964.3077,-1605.5304,13.5442,50.1477}, 
    {20095, "[TDB Gun's Dealer]\n{ffffff}Available Commands: /buygun", 1180.1652,-1222.2889,18.5547,263.2347}, 
    {116, "[VLA Gun's Dealer]\n{ffffff}Available Commands: /buygun", 1813.9130,-2020.5454,13.5720,255.5141}, 
    {110, "[LSV Gun's Dealer]\n{ffffff}Available Commands: /buygun", 2579.7588,-1443.6919,24.0000,91.1754} 
};

InsertEmmetInit()
{
    for(new i = 0; i < sizeof(EmmetInfo); i++)
    {
        Emmet[i] = CreateDynamicActor(EmmetInfo[i][EMMET_SKIN], EmmetInfo[i][EMMET_POSX], EmmetInfo[i][EMMET_POSY], EmmetInfo[i][EMMET_POSZ], EmmetInfo[i][EMMET_POSA]);
        CreateDynamic3DTextLabel(EmmetInfo[i][EMMET_TEXT], COLOR_POINT, EmmetInfo[i][EMMET_POSX], EmmetInfo[i][EMMET_POSY], EmmetInfo[i][EMMET_POSZ], 3.0);
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
        ShowPlayerDialog(playerid, DIALOG_EMMET, DIALOG_STYLE_TABLIST, "Emmet Hardware:", "Emmet Colt\tGlock 17\nMagazine\t9mm clip", "Select", "Cancel");
    }
    else if(PlayerInfo[playerid][E_CHARACTER_FACTION] == 7 || PlayerInfo[playerid][E_CHARACTER_FACTION] == 8)
	{
		new str[512];
		strcat(str, "Glock-19 (Ammo: 25)\n");
		strcat(str, "Glock-17 (Ammo: 25)\n");
		strcat(str, "Glock-P80 (Ammo: 25)\n");
		strcat(str, "MAC-11 (Ammo: 50)\n");
		strcat(str, "MAC-10 (Ammo: 50)\n");
		strcat(str, "Socimi T821 (Ammo: 50)\n");
		strcat(str, "9mm (Ammo: 25)\n");
		strcat(str, "9x19mm (Ammo: 50)\n");
		strcat(str, "Marijuana (5g)\n");
		strcat(str, "Heroin (5g)\n");
		ShowPlayerDialog(playerid, DIALOG_BUYGUN, DIALOG_STYLE_LIST, str1, str, "Select", "Close");
	}
	else
	{
		new str[512];
		strcat(str, "Glock-19 (Ammo: 25)\n");
		strcat(str, "Glock-17 (Ammo: 25)\n");
		strcat(str, "Glock-P80 (Ammo: 25)\n");
		strcat(str, "MAC-11 (Ammo: 50)\n");
		strcat(str, "MAC-10 (Ammo: 50)\n");
		strcat(str, "Socimi T821 (Ammo: 50)\n");
		strcat(str, "9mm (Ammo: 25)\n");
		strcat(str, "9x19mm (Ammo: 50)\n");
		strcat(str, "Marijuana (5g)\n");
		strcat(str, "Cocaine (5g)\n");
		ShowPlayerDialog(playerid, DIALOG_BUYGUN, DIALOG_STYLE_LIST, str1, str, "Select", "Close");
	}
    return 1;
}