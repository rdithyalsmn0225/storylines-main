#define MAX_FACTION_VEHICLES 38

enum E_FACTIONVEHICLE_DATA
{
    E_FACVEHICLE_DBID,
    E_FACVEHICLE_MODEL,
    E_FACVEHICLE_PLATES[16],
    E_FACVEHICLE_TYPE,
    Float:E_FACVEHICLE_POSX,
    Float:E_FACVEHICLE_POSY,
    Float:E_FACVEHICLE_POSZ,
    Float:E_FACVEHICLE_ROT,
    E_FACVEHICLE_COLOR1,
    E_FACVEHICLE_COLOR2,
    E_FACVEHICLE_VEH,
    bool:E_FACVEHICLE_SPAWNED,
    E_FACVEHICLE_LASTUSED
};

new FactionVehicle[MAX_FACTION_VEHICLES][E_FACTIONVEHICLE_DATA] =
{
    {0, 596, "LINCON-1", 2,  1602.3312, -1684.0071, 5.6185, 91.2188,0,1}, // Vehicle 1
    {1, 596, "LINCON-2", 2,  1602.5184, -1687.9525, 5.6098, 89.0430,0,1}, // Vehicle 2
    {2, 596, "LINCON-3", 2,  1602.3141, -1692.2067, 5.6149, 89.1927,0,1}, // Vehicle 3
    {3, 596, "LINCON-4", 2,  1602.2833, -1696.3682, 5.6286, 90.2932,0,1}, // Vehicle 4
    {4, 596, "LINCON-5", 2,  1602.1863, -1700.2629, 5.6161, 88.2802,0,1}, // Vehicle 5
    {5, 596, "LINCON-6", 2,  1595.1029, -1711.1693, 5.6132, 358.1242,0,1}, // Vehicle 6
    {6, 596, "LINCON-7", 2,  1591.2061, -1711.1152, 5.6060, 357.9518,0,1}, // Vehicle 7
    {7, 596, "LINCON-8", 2,  1587.8042, -1711.0640, 5.6139, 0.4377,0,1}, // Vehicle 8
    {8, 596, "LINCON-9", 2,  1583.5166, -1710.9095, 5.6262, 357.2809,0,1}, // Vehicle 9

    {9, 601, "KING-3", 2,  1526.5850, -1644.1801, 5.6494, 180.3210,0,1}, // Vehicle 10
    {10, 601, "KING-4", 2,  1530.7244, -1644.2538, 5.6494, 179.6148,0,1}, // Vehicle 11
    {11, 427, "KING-5", 2,  1534.8553, -1644.8682, 6.0226, 180.7921,0,1}, // Vehicle 12
    {12, 427, "KING-6", 2,  1538.9325, -1644.9508, 6.0226, 179.5991,0,1}, // Vehicle 13

    {13, 497, "CHOPPER-1", 2,  1565.0839, -1643.2800, 28.5921, 89.4944,0,1}, // Vehicle 14
    {14, 497, "CHOPPER-2", 2,  1564.4895, -1703.4138, 28.5848, 87.6184,0,1}, // Vehicle 15

    {15, 490, "KING-1", 2,  1545.7213, -1655.0195, 6.0814, 90.4218,0,1}, // Vehicle 16
    {16, 490, "KING-2", 2,  1545.8069, -1651.1516, 6.0790, 88.2897,0,1}, // Vehicle 17

    {17, 525, "ZEUS-1", 2,  1528.3439, -1684.0914, 5.7702, 269.9949,0,1}, // Vehicle 18
    {18, 525, "ZEUS-2", 2,  1528.6476, -1688.2294, 5.7698, 269.9370,0,1}, // Vehicle 19

    {19, 468, "TEU-1", 2,  1544.0415, -1708.5723, 5.5538, 156.7939,0,1}, // Vehicle 20
    {20, 468, "TEU-2", 2,  1542.7850, -1707.5076, 5.5622, 158.1278,0,1}, // Vehicle 21
    {21, 468, "TEU-3", 2,  1542.0917, -1707.0608, 5.5511, 154.1654,0,1}, // Vehicle 22
    {22, 522, "TEU-4", 2,  1540.4431, -1705.9148, 5.4508, 156.6729,0,1}, // Vehicle 23
    {23, 522, "TEU-5", 2,  1539.9655, -1705.2487, 5.4344, 156.1196,0,1}, // Vehicle 24
    {24, 522, "TEU-6", 2,  1539.1798, -1704.4395, 5.4616, 154.4021,0,1}, // Vehicle 25

    {25, 560, "Chief SAPD", 2,  1546.3962, -1668.0127, 5.5955, 89.4513,0,1}, // Vehicle 26
    {26, 560, "Deputy SAPD", 2,  1546.2767, -1663.0496, 5.5966, 90.1683,0,1},  // Vehicle 27

    {27, 416, "SAMD-1", 3,  1116.0294, -1296.6489, 13.6160, 179.4438, 1, 3}, // Vehicle 28
    {28, 416, "SAMD-2", 3,  1125.8785, -1296.2780, 13.6160, 179.4438, 1, 3}, // Vehicle 29
    {29, 416, "SAMD-3", 3,  1121.1556, -1296.4138, 13.6160, 179.4438, 1, 3}, // Vehicle 30
    {30, 442, "SAMD-4", 3,  1111.1719, -1296.7606, 13.4886, 185.0000, 1, 3}, // Vehicle 31
    {31, 426, "SAMD-5", 3,  1136.0360, -1341.2158, 13.3050, 0.0000, 1, 3}, // Vehicle 32
    {32, 586, "SAMD-6", 3,  1130.7795, -1330.4045, 13.3639, 0.0000, 1, 3}, // Vehicle 33
    {33, 563, "SAMD-7", 3,  1162.9077, -1313.8203, 32.1891, 270.6980, 1, 3}, // Vehicle 34
    {34, 487, "SAMD-8", 3,  1163.0469, -1297.5098, 31.5550, 269.6279, 1, 3}, // Vehicle 35
    {35, 407, "SAMD-9", 3,  1098.8644, -1295.2787, 13.7938, 273.7230, 1, 3}, // Vehicle 36
    {36, 407, "SAMD-10", 3,  1097.8621, -1303.2229, 13.8167, 273.2676, 1, 3}, // Vehicle 37
    {37, 407, "SAMD-11", 3,  1097.5540, -1312.1210, 13.8991, 270.9483, 1, 3}  // Vehicle 38
};

function:CheckInactiveVehicles()
{
    for (new i = 0; i < MAX_FACTION_VEHICLES; i++)
    {
        if (FactionVehicle[i][E_FACVEHICLE_SPAWNED])
        {
            if (gettime() - FactionVehicle[i][E_FACVEHICLE_LASTUSED] > 1800)
            {
                DestroyVehicle(FactionVehicle[i][E_FACVEHICLE_VEH]);
                FactionVehicle[i][E_FACVEHICLE_SPAWNED] = false;
                FactionVehicle[i][E_FACVEHICLE_VEH] = 0;
            }
        }
    }
    return 1;
}

CMD:spawn(playerid, params[])
{
    if(ReturnFactionType(playerid) != FACTION_TYPE_POLICE && ReturnFactionType(playerid) != FACTION_TYPE_MEDICAL)
        return SendErrorMessage(playerid, "You aren't apart of police departement");

    if(IsPlayerInRangeOfPoint(playerid, 3.0, 1568.7626,-1695.0494,5.8906))
    {
        for (new i = 0; i < 27; i++)
        {
            new str[5034];
            if (FactionVehicle[i][E_FACVEHICLE_SPAWNED])
            {
                format(str, sizeof(str), "%s%s\tNot Available\n", str, FactionVehicle[i][E_FACVEHICLE_PLATES]);
            }
            else
            {
                format(str, sizeof(str), "%s%s\tAvailable\n", str, FactionVehicle[i][E_FACVEHICLE_PLATES]);
            }
            Dialog_ShowPages(playerid, FactionVehicles, DIALOG_STYLE_TABLIST, "Faction Vehicles", str, "Select", "Close");
        }
    }
    return 1;
}

Dialog:FactionVehicles(playerid, response, listitem, inputtext[])
{
    if(response)
    {
        if(FactionVehicle[listitem][E_FACVEHICLE_SPAWNED])
            return SendErrorMessage(playerid, "This vehicle is already spawned and not available.");

        new modelid = FactionVehicle[listitem][E_FACVEHICLE_MODEL];
        new color1 = FactionVehicle[listitem][E_FACVEHICLE_COLOR1];
        new color2 = FactionVehicle[listitem][E_FACVEHICLE_COLOR2];
        new Float:x = FactionVehicle[listitem][E_FACVEHICLE_POSX];
        new Float:y = FactionVehicle[listitem][E_FACVEHICLE_POSY];
        new Float:z = FactionVehicle[listitem][E_FACVEHICLE_POSZ];
        new Float:rot = FactionVehicle[listitem][E_FACVEHICLE_ROT];

        FactionVehicle[listitem][E_FACVEHICLE_LASTUSED] = gettime();

        FactionVehicle[listitem][E_FACVEHICLE_VEH] = AddStaticVehicleEx(modelid, x, y, z, rot, color1, color2, 1800, 1);
        VehicleInfo[FactionVehicle[listitem][E_FACVEHICLE_VEH]][E_VEHICLE_HEALTH] = 2000.0;
		VehicleInfo[FactionVehicle[listitem][E_FACVEHICLE_VEH]][E_VEHICLE_FUEL] = 100;
		VehicleInfo[FactionVehicle[listitem][E_FACVEHICLE_VEH]][E_VEHICLE_MILES] = 0; 
		SetVehicleHealth(FactionVehicle[listitem][E_FACVEHICLE_VEH], VehicleInfo[FactionVehicle[listitem][E_FACVEHICLE_VEH]][E_VEHICLE_HEALTH]);
        SetVehicleNumberPlate(FactionVehicle[listitem][E_FACVEHICLE_VEH], FactionVehicle[FactionVehicle[listitem][E_FACVEHICLE_VEH]][E_FACVEHICLE_PLATES]);
        FactionVehicle[listitem][E_FACVEHICLE_SPAWNED] = true;

        SendServerMessage(playerid, "[Faction] {DEDEDE} Faction Vehicles spawned successfully.");
    }
    return 1;
}