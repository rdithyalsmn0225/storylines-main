
InsertTrashmaster()
{
    for(new i = 0; i < sizeof(GarbageLocations); i++)
    {
        Garbage[i] = CreateDynamicPickup(1265, 1, GarbageLocations[i][0], GarbageLocations[i][1], GarbageLocations[i][2], -1, -1, -1, 3.0);
    }
    return 1;
}

Trashmaster_FetchNewPoint(playerid) 
{
    if(PlayerInfo[playerid][E_CHARACTER_TRASHMASTER_VALUE] == 1)
    {
        new Float:x, Float:y, Float:z;
		GetVehiclePos(PlayerInfo[playerid][E_CHARACTER_JOBSVEHICLE], x, y, z);
		GetVehicleBoot(PlayerInfo[playerid][E_CHARACTER_JOBSVEHICLE], x, y, z);
		GPS_SetPlayerRaceCheckPoint(playerid, 1, x, y, z, 0.0, 0.0, 0.0, GPS_GARBAGE);
    }
    return 1;
}