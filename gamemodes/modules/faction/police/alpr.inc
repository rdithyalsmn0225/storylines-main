new Float:ALPR_RANGE = 15.0;

stock DetectVehicleInFront(playerid)
{
    new vehicleid = GetPlayerVehicleID(playerid);
    if (vehicleid == INVALID_VEHICLE_ID) return 0;

    new Float:x, Float:y, Float:z, Float:angle;
    GetVehiclePos(vehicleid, x, y, z);
    GetVehicleZAngle(vehicleid, angle);

    new Float:frontX = x + (floatsin(-angle, degrees) * ALPR_RANGE);
    new Float:frontY = y + (floatcos(-angle, degrees) * ALPR_RANGE);

    for (new i = 1; i < MAX_VEHICLES; i++)
    {
        if (i == vehicleid) continue;

        new Float:vX, Float:vY, Float:vZ;
        GetVehiclePos(i, vX, vY, vZ);

        if(IsPlayerInAnyVehicle(playerid) && !PlayerInfo[playerid][E_CHARACTER_TOGALPR])
        {
            if (GetDistanceBetweenPoints(frontX, frontY, z, vX, vY, vZ) <= ALPR_RANGE)
            {
                new str3[128]; new str2[128]; new str[128];
                format(str3, sizeof(str3), "Model : %s", ReturnVehicleName(i));
                PlayerTextDrawSetString(playerid, ALPR[1][playerid], str3);

                
                format(str, sizeof(str), "Plates : %s", VehicleInfo[i][E_VEHICLE_PLATES]);
                PlayerTextDrawSetString(playerid, ALPR[2][playerid], str);

                if(!VehicleInfo[i][E_VEHICLE_PLATESSTATUS])
                {
                    
                    format(str2, sizeof(str2), "R.O : Unregistered");
                    PlayerTextDrawSetString(playerid, ALPR[3][playerid], str2);
                }
                else
                {
                    format(str2, sizeof(str2), "R.O : Registered");
                    PlayerTextDrawSetString(playerid, ALPR[3][playerid], str2);
                }
                
                new str4[256];
                format(str4, sizeof(str4), "%s~n~%s~n~%s", str, str2, str3);
                ShowHeaderMessage(playerid, "Alpr", str4, 1);
                return 1;
            }
            else
            {
                HideHeaderMessage(playerid);
            }
        }
        else
        {
            HideHeaderMessage(playerid);
        }
    }
    return 1;
}