
new HotwireActive[MAX_PLAYERS][8];
new HotwireClicked[MAX_PLAYERS];
new HotwireFirstClick[MAX_PLAYERS];

function:StartHotwire(playerid)
{
    HotwireClicked[playerid] = 0;
    HotwireFirstClick[playerid] = -1;

    new indices[8];
    for (new i = 0; i < 8; i++)
    {
        indices[i] = i;
    }

    // Shuffling the indices
    for (new i = 0; i < 8; i++)
    {
        new rnd = random(8);
        new temp = indices[i];
        indices[i] = indices[rnd];
        indices[rnd] = temp;
    }

    for (new i = 0; i < 8; i++)
    {
        PlayerTextDrawFont(playerid, HotwireCable[playerid][i], 4);
		PlayerTextDrawColor(playerid, HotwireCable[playerid][i], -764862721);
		PlayerTextDrawTextSize(playerid, HotwireCable[playerid][i], 9.500000, 41.000000);

        PlayerTextDrawColor(playerid, HotwireTD[playerid][0], 0xFF0000FF);
        PlayerTextDrawColor(playerid, HotwireTD[playerid][1], 0x00FF00FF);
        PlayerTextDrawColor(playerid, HotwireTD[playerid][2], 0xFFFF00FF);
        PlayerTextDrawColor(playerid, HotwireTD[playerid][3], 0x00FFFF00);
        PlayerTextDrawColor(playerid, HotwireTD[playerid][4], 0xFF0000FF);
        PlayerTextDrawColor(playerid, HotwireTD[playerid][5], 0x00FF00FF);
        PlayerTextDrawColor(playerid, HotwireTD[playerid][6], 0xFFFF00FF);
        PlayerTextDrawColor(playerid, HotwireTD[playerid][7], 0x00FFFF00);

        PlayerTextDrawFont(playerid, HotwireTD[playerid][i], 4);
		PlayerTextDrawSetSelectable(playerid, HotwireTD[playerid][i], true);
		PlayerTextDrawTextSize(playerid, HotwireTD[playerid][i], 18.500000, 41.000000);

        PlayerTextDrawColor(playerid, HotwireTDB[playerid][i], 0x000000FF);
        PlayerTextDrawFont(playerid, HotwireTDB[playerid][i], 4);
		PlayerTextDrawSetSelectable(playerid, HotwireTDB[playerid][i], true);
		PlayerTextDrawTextSize(playerid, HotwireTDB[playerid][i], 20.000000, 45.000000);

        PlayerTextDrawShow(playerid, HotwireTD[playerid][i]);
        PlayerTextDrawShow(playerid, HotwireTDB[playerid][i]);
        PlayerTextDrawShow(playerid, HotwireCable[playerid][i]);
        HotwireActive[playerid][i] = indices[i % (8 / 2)];
    }
    SelectTextDraw(playerid, COLOR_YELLOW);
    return 1;
}

function:StopHotwire(playerid)
{
    for (new i = 0; i < 8; i++)
    {
        PlayerTextDrawHide(playerid, HotwireTD[playerid][i]);
        PlayerTextDrawHide(playerid, HotwireTDB[playerid][i]);
        PlayerTextDrawHide(playerid, HotwireCable[playerid][i]);
        HotwireActive[playerid][i] = -1;
    }
    HotwireClicked[playerid] = 0;
    HotwireFirstClick[playerid] = -1;
    CancelSelectTextDraw(playerid);
    return 1;
}

CMD:hotwire(playerid, params[])
{
    new vehicleid = GetPlayerVehicleID(playerid);
    if(!IsPlayerInAnyVehicle(playerid) && GetPlayerState(playerid) != PLAYER_STATE_DRIVER)
        return SendErrorMessage(playerid, "You aren't in any vehicles.");

    if (!IsEngineVehicle(vehicleid))
		return SendErrorMessage(playerid, "You are not in any vehicle.");

    if(VehicleInfo[vehicleid][E_VEHICLE_ENGINE])
        return SendErrorMessage(playerid, "This vehicles already engine on");
        
    if(!Inventory_Count(playerid, "Screwdriver") && PlayerInfo[playerid][E_CHARACTER_EQUIPITEMS] != SCREWDRIVER)
        return SendErrorMessage(playerid, "You must hold screwdriver in your hand.");

    StartHotwire(playerid);
    return 1;
}
