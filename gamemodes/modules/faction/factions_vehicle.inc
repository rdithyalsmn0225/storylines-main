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
        new str[512];
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
        Dialog_Show(playerid, DialogPoliceVehicles, DIALOG_STYLE_TABLIST, "Faction Vehicles", str, "Select", "Close");
    }
    else if(IsPlayerInRangeOfPoint(playerid, 3.0, 1124.1577,-1324.4509,13.6212) && ReturnFactionType(playerid) == FACTION_TYPE_MEDICAL)
    {
        new str[512];
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
        Dialog_Show(playerid, DialogMedicVehicles, DIALOG_STYLE_TABLIST, "Faction Vehicles", str, "Select", "Close");
    }
    else SendErrorMessage(playerid, "You aren't near faction vehicle spawn point");
    return 1;
}

CMD:despawn(playerid, params[])
{
    if (ReturnFactionType(playerid) == FACTION_TYPE_POLICE || ReturnFactionType(playerid) == FACTION_TYPE_MEDICAL)
    {
        if(IsPlayerInRangeOfPoint(playerid, 3.0, 1124.1577,-1324.4509,13.6212) || IsPlayerInRangeOfPoint(playerid, 3.0, 1568.7626,-1695.0494,5.8906))
        {
            new vehicleid = GetPlayerVehicleID(playerid);

            if(!IsPlayerInAnyVehicle(playerid))
                return SendErrorMessage(playerid, "You aren't in any vehicles.");
                
            // Loop through faction vehicles to find a match
            for (new i = 0; i < sizeof(FactionVehicle); i++)
            {
                if (FactionVehicle[i][E_FACVEHICLE_VEH] == vehicleid)
                {
                    if ((ReturnFactionType(playerid) == FACTION_TYPE_POLICE && i < 27) ||
                        (ReturnFactionType(playerid) == FACTION_TYPE_MEDICAL && i >= 27 && i < 38))
                    {
                        DestroyVehicle(vehicleid);
                        FactionVehicle[i][E_FACVEHICLE_SPAWNED] = false;
                        FactionVehicle[i][E_FACVEHICLE_VEH] = INVALID_VEHICLE_ID;

                        SendInfoMessage(playerid, "[FACTION] Faction Vehicle despawned successfully.");
                        return 1;
                    }
                    else
                    {
                        return SendErrorMessage(playerid, "You can only despawn vehicles from your faction.");
                    }
                }
            }

            SendErrorMessage(playerid, "This vehicle is not registered as a faction vehicle.");
        }
    }
    else
    {
        SendErrorMessage(playerid, "You are not authorized to use this command.");
    }
    return 1;
}