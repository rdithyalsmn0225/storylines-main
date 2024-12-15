InsertModshops()
{
    CreateDynamic3DTextLabel("[ModShops]\n{ffffff}Available Commands: '/mods'", COLOR_3DTEXT, 2331.8369,-1991.6169,13.5745, 5.0);
    CreateDynamicPickup(1239, 1, 2331.8369,-1991.6169,13.5745, -1, -1, -1, 5.0);
    CreateDynamic3DTextLabel("[ModShops]\n{ffffff}Available Commands: '/mods'", COLOR_3DTEXT, 1619.4454,-1889.9126,13.5482, 5.0);
    CreateDynamicPickup(1239, 1, 1619.4454,-1889.9126,13.5482, -1, -1, -1, 5.0);
    CreateDynamic3DTextLabel("[ModShops]\n{ffffff}Available Commands: '/mods'", COLOR_3DTEXT, 1828.9535,-1398.1777,13.4297, 5.0);
    CreateDynamicPickup(1239, 1, 1828.9535,-1398.1777,13.4297, -1, -1, -1, 5.0);
}

CMD:mods(playerid, params[])
{
    if(!IsPlayerInRangeOfPoint(playerid, 2.0,2331.8369,-1991.6169,13.5745) && !IsPlayerInRangeOfPoint(playerid, 2.0,1619.4454,-1889.9126,13.5482) && !IsPlayerInRangeOfPoint(playerid, 2.0,1828.9535,-1398.1777,13.4297))
        return SendErrorMessage(playerid, "You aren't near modshop.");

    if(IsPlayerInVehicle(playerid, GetPlayerVehicleID(playerid)))
    {
        ShowPlayerDialog(playerid, DIALOG_MODSHOP, DIALOG_STYLE_TABLIST, "Pay n Spray:", "Add Modifications", "Select", "Close");
    }
    return 1;
}