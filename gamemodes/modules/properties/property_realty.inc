CMD:listings(playerid, params[])
{
	if (!IsPlayerInRangeOfPoint(playerid, 5.0, 1778.0038,-1663.6217,14.4355))
	    return SendErrorMessage(playerid, "You aren't near radeetz realty estate.");
	
	ShowPlayerRealty(playerid);
	return 1;
}

stock ShowPlayerRealty(playerid) 
{
    new str[2024], resultcount;
    for(new idx = 1; idx != MAX_PROPERTY; idx++)
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
            ShowPlayerDialog(playerid, DIALOG_REALTY, DIALOG_STYLE_TABLIST, "Radeetz Realty Estate:", str, "Select", "Close");
        }
    }
    return 1;
}