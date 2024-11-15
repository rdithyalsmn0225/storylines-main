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

        if(IsPlayerInAnyVehicle(playerid))
        {
            if (GetDistanceBetweenPoints(frontX, frontY, z, vX, vY, vZ) <= ALPR_RANGE)
            {
                new str3[128];
                format(str3, sizeof(str3), "Model :  ~w~%s", ReturnVehicleName(i));
                PlayerTextDrawSetString(playerid, ALPR[2][playerid], str3);

                new str[128];
                format(str, sizeof(str), "Plates :   ~w~%s", VehicleInfo[i][E_VEHICLE_PLATES]);
                PlayerTextDrawSetString(playerid, ALPR[3][playerid], str);

                if(!VehicleInfo[i][E_VEHICLE_PLATESSTATUS])
                {
                    new str2[128];
                    format(str2, sizeof(str2), "R.O :        ~w~Unregistered");
                    PlayerTextDrawSetString(playerid, ALPR[4][playerid], str2);
                }
                else
                {
                    new str2[128];
                    format(str2, sizeof(str2), "R.O :        ~w~Registered");
                    PlayerTextDrawSetString(playerid, ALPR[4][playerid], str2);
                }
                for(new b = 0; b < 5; b++)
                {
                    PlayerTextDrawShow(playerid, ALPR[b][playerid]);
                }
                return 1;
            }
            else
            {
                for(new a = 0; a < 5; a++)
                {
                    PlayerTextDrawHide(playerid, ALPR[a][playerid]);
                }
            }
        }
        else
        {
            for(new a = 0; a < 5; a++)
            {
                PlayerTextDrawHide(playerid, ALPR[a][playerid]);
            }
        }
    }
    return 0;
}