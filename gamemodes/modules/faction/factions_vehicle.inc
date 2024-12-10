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
    if(IsPlayerInRangeOfPoint(playerid, 3.0, 1568.7626,-1695.0494,5.8906) && ReturnFactionType(playerid) == FACTION_TYPE_POLICE)
    {
        new str[1024];
        for (new i = 0; i < 27; i++)
        {
            if (FactionVehicle[i][E_FACVEHICLE_SPAWNED])
            {
                format(str, sizeof(str), "%s%s\t{FF6347}Unvailable{ffffff}\n", str, FactionVehicle[i][E_FACVEHICLE_PLATES]);
            }
            else
            {
                format(str, sizeof(str), "%s%s\t{33AA33}Available{ffffff}\n", str, FactionVehicle[i][E_FACVEHICLE_PLATES]);
            }
            
        }
        Dialog_Show(playerid, LSPDFactionVehicles, DIALOG_STYLE_TABLIST, "Faction Vehicles", str, "Select", "Close");
    }
    
    if(IsPlayerInRangeOfPoint(playerid, 3.0, 1124.1577,-1324.4509,13.6212) && ReturnFactionType(playerid) == FACTION_TYPE_MEDICAL)
    {
        new str[1024];
        for (new i = 27; i < 38; i++)
        {
            if (FactionVehicle[i][E_FACVEHICLE_SPAWNED])
            {
                format(str, sizeof(str), "%s%s\t{FF6347}Unvailable{ffffff}\n", str, FactionVehicle[i][E_FACVEHICLE_PLATES]);
            }
            else
            {
                format(str, sizeof(str), "%s%s\t{33AA33}Available{ffffff}\n", str, FactionVehicle[i][E_FACVEHICLE_PLATES]);
            }
            
        }
        Dialog_Show(playerid, LSMDFactionVehicles, DIALOG_STYLE_TABLIST, "Faction Vehicles", str, "Select", "Close");
    }
    else SendErrorMessage(playerid, "You aren't near faction vehicle spawn point");
    return 1;
}

Dialog:LSMDFactionVehicles(playerid, response, listitem, inputtext[])
{
    if (response)
    {
        new index = listitem + 27; // Menyesuaikan indeks agar sesuai dengan Medical (27-37)

        if (FactionVehicle[index][E_FACVEHICLE_SPAWNED])
            return SendErrorMessage(playerid, "This vehicle is already spawned and not available.");

        new modelid = FactionVehicle[index][E_FACVEHICLE_MODEL];
        new color1 = FactionVehicle[index][E_FACVEHICLE_COLOR1];
        new color2 = FactionVehicle[index][E_FACVEHICLE_COLOR2];
        new Float:x = FactionVehicle[index][E_FACVEHICLE_POSX];
        new Float:y = FactionVehicle[index][E_FACVEHICLE_POSY];
        new Float:z = FactionVehicle[index][E_FACVEHICLE_POSZ];
        new Float:rot = FactionVehicle[index][E_FACVEHICLE_ROT];

        FactionVehicle[index][E_FACVEHICLE_LASTUSED] = gettime();

        FactionVehicle[index][E_FACVEHICLE_VEH] = AddStaticVehicleEx(modelid, x, y, z, rot, color1, color2, 1800, 1);
        VehicleInfo[FactionVehicle[index][E_FACVEHICLE_VEH]][E_VEHICLE_HEALTH] = 2000.0;
        VehicleInfo[FactionVehicle[index][E_FACVEHICLE_VEH]][E_VEHICLE_FUEL] = 100;
        VehicleInfo[FactionVehicle[index][E_FACVEHICLE_VEH]][E_VEHICLE_MILES] = 0;

        SetVehicleHealth(FactionVehicle[index][E_FACVEHICLE_VEH], VehicleInfo[FactionVehicle[index][E_FACVEHICLE_VEH]][E_VEHICLE_HEALTH]);
        SetVehicleNumberPlate(FactionVehicle[index][E_FACVEHICLE_VEH], FactionVehicle[index][E_FACVEHICLE_PLATES]);

        FactionVehicle[index][E_FACVEHICLE_SPAWNED] = true;

        SendServerMessage(playerid, "[Faction] {DEDEDE} Faction Vehicle spawned successfully.");
    }
    return 1;
}

Dialog:LSPDFactionVehicles(playerid, response, listitem, inputtext[])
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