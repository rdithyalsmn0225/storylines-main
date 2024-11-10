new Float:ALPR_RANGE = 15.0;

stock DetectVehicleInFront(playerid)
{
    new vehicleid = GetPlayerVehicleID(playerid);
    if (vehicleid == INVALID_VEHICLE_ID) return 0;

    new Float:x, Float:y, Float:z, Float:angle;
    GetVehiclePos(vehicleid, x, y, z);
    GetVehicleZAngle(vehicleid, angle);

    new Float:rearX = x - (floatsin(-angle, degrees) * ALPR_RANGE);
    new Float:rearY = y - (floatcos(-angle, degrees) * ALPR_RANGE);

    new Float:frontX = x + (floatsin(-angle, degrees) * ALPR_RANGE);
    new Float:frontY = y + (floatcos(-angle, degrees) * ALPR_RANGE);

    for (new i = 1; i < MAX_VEHICLES; i++)
    {
        if (i == vehicleid) continue;

        new Float:vX, Float:vY, Float:vZ;
        GetVehiclePos(i, vX, vY, vZ);

        static
            Float:fSpeed,
            Float:fVelocity[3];

        GetVehicleVelocity(i, fVelocity[0], fVelocity[1], fVelocity[2]);
        fSpeed = floatmul(floatsqroot((fVelocity[0] * fVelocity[0]) + (fVelocity[1] * fVelocity[1]) + (fVelocity[2] * fVelocity[2])), 100.0);

        if (GetDistanceBetweenPoints(frontX, frontY, z, vX, vY, vZ) <= ALPR_RANGE || GetDistanceBetweenPoints(rearX, rearY, z, vX, vY, vZ) <= ALPR_RANGE)
        {
            new str[128];
            format(str, sizeof(str), "%s", VehicleInfo[i][E_VEHICLE_PLATES]);
            PlayerTextDrawSetString(playerid, ALPR[3][playerid], str);

            new str2[128];
            format(str2, sizeof(str2), "%s", ReturnVehicleName(i));
            PlayerTextDrawSetString(playerid, ALPR[9][playerid], str2);

            new str3[128];
            format(str3, sizeof(str3), "%.0f", fSpeed);
            PlayerTextDrawSetString(playerid, ALPR[12][playerid], str3);

            new str4[128];
            format(str4, sizeof(str4), "%s", VehicleInfo[i][E_VEHICLE_PLATES]);
            PlayerTextDrawSetString(playerid, ALPR[4][playerid], str4);

            new str5[128];
            format(str5, sizeof(str5), "%s", ReturnVehicleName(i));
            PlayerTextDrawSetString(playerid, ALPR[17][playerid], str5);

            new str6[128];
            format(str6, sizeof(str6), "%.0f", fSpeed);
            PlayerTextDrawSetString(playerid, ALPR[13][playerid], str6);

            for(new b = 0; b < 18; b++)
            {
                PlayerTextDrawShow(playerid, ALPR[b][playerid]);
            }
            return 1;
        }
        else
        {
            for(new a = 0; a < 18; a++)
            {
                PlayerTextDrawHide(playerid, ALPR[a][playerid]);
            }
        }
    }
    return 0;
}