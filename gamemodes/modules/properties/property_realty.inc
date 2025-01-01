CMD:listings(playerid, params[])
{
	if (!IsPlayerInRangeOfPoint(playerid, 5.0, 1778.0038,-1663.6217,14.4355))
	    return SendErrorMessage(playerid, "You aren't near pattersons realty estate.");
	
	ShowPlayerRealty(playerid);
	return 1;
}

stock ShowPlayerRealty(playerid) 
{
    new str[3000], resultcount;
    for(new idx = 1; idx < MAX_PROPERTY; idx++)
    {
        if(!PropertyInfo[idx][E_PROPERTY_OWNERDBID] && PropertyInfo[idx][E_PROPERTY_DBID])
        {
            new Float:x = PropertyInfo[idx][E_PROPERTY_ENTRANCEPOS][0],
                Float:y = PropertyInfo[idx][E_PROPERTY_ENTRANCEPOS][1],
                Float:z = PropertyInfo[idx][E_PROPERTY_ENTRANCEPOS][2],
                price = PropertyInfo[idx][E_PROPERTY_PRICE];
            
            PlayerPropertyFound[resultcount] = idx;
            resultcount++;
            format(str, sizeof(str), "%s(House) %s, %s\t{52B788}$%s\n", str, GetZoneName(x, y, z), GetStreetName(x, y), FormatMoney(price));
            
        }
    }
    Dialog_Show(playerid, DialogRealty, DIALOG_STYLE_TABLIST, "Pattersons Realtystate:", str, "Select", "Close");
    return 1;
}

Dialog:DialogRealty(playerid, response, listitem, inputtext[])
{
    if(response)
    {
        new idx = PlayerPropertyFound[listitem],
            Float:x = PropertyInfo[idx][E_PROPERTY_ENTRANCEPOS][0],
            Float:y = PropertyInfo[idx][E_PROPERTY_ENTRANCEPOS][1],
            Float:z = PropertyInfo[idx][E_PROPERTY_ENTRANCEPOS][2];

        GPS_SetPlayerRaceCheckPoint(playerid, 1, x, y, z, 0.0, 0.0, 0.0);
        SendTipMessage(playerid, "You can buy property by type /buyproperty.");
    }
    return 1;
}