function:DockWorkers(playerid, type)
{
    new text[256], vehicleid = GetPlayerVehicleID(playerid);
    switch(type)
    {
        case 0:
        {
            PlayerInfo[playerid][E_CHARACTER_LOADINGCOUNT]++;

            switch(PlayerInfo[playerid][E_CHARACTER_LOADINGCOUNT])
            {
                case 2: text = "Loading take cargo process\n(( ||----- ))";
                case 3: text = "Loading take cargo process\n(( |||---- ))";
                case 4: text = "Loading take cargo process\n(( ||||--- ))";
                case 5: text = "Loading take cargo process\n(( |||||-- ))";
                case 6: text = "Loading take cargo process\n(( ||||||- ))";
                case 7: text = "Loading take cargo process\n(( ||||||| ))";
                case 8:
                {
                    PlayerDockworkerStore[playerid] = random(sizeof(Dockworker_Store));

                    GPS_SetPlayerRaceCheckPoint(playerid, 1, Dockworker_Store[PlayerDockworkerStore[playerid]][0],Dockworker_Store[PlayerDockworkerStore[playerid]][1], Dockworker_Store[PlayerDockworkerStore[playerid]][2], 0.0, 0.0, 0.0);
                    TogglePlayerControllable(playerid, true);
                    
                    PlayerInfo[playerid][E_CHARACTER_LOADING] = false;
                    PlayerInfo[playerid][E_CHARACTER_LOADINGCOUNT] = 0;

                    Delete3DTextLabel(PlayerInfo[playerid][E_CHARACTER_LOADINGDISPLAY]); 
                    KillTimer(PlayerInfo[playerid][E_CHARACTER_LOADINGTIMER]);

                    CrateObject[vehicleid] = CreateDynamicObject(1221,0.0,0.0,-1000.0,0.0,0.0,0.0,-1,-1,-1,300.0,300.0);
                    AttachDynamicObjectToVehicle(CrateObject[vehicleid], vehicleid, 0.000, 0.630, 0.360, 0.000, 0.000, 0.000);
                    ShowBoxMessage(playerid, "~w~You've succesfully take the package. Deliver it to warehouse", 5, 2); 
                    VehicleInfo[vehicleid][E_VEHICLE_CRATES] = 1;
                }
            }
        }
        case 1:
        {
            PlayerInfo[playerid][E_CHARACTER_LOADINGCOUNT]++;

            switch(PlayerInfo[playerid][E_CHARACTER_LOADINGCOUNT])
            {
                case 2: text = "Loading store cargo process\n(( ||----- ))";
                case 3: text = "Loading store cargo process\n(( |||---- ))";
                case 4: text = "Loading store cargo process\n(( ||||--- ))";
                case 5: text = "Loading store cargo process\n(( |||||-- ))";
                case 6: text = "Loading store cargo process\n(( ||||||- ))";
                case 7: text = "Loading store cargo process\n(( ||||||| ))";
                case 8:
                {
                    PlayerDockworkerCollect[playerid] = random(sizeof(Dockworker_Collect));
                    GPS_SetPlayerRaceCheckPoint(playerid, 1, Dockworker_Collect[PlayerDockworkerCollect[playerid]][0], Dockworker_Collect[PlayerDockworkerCollect[playerid]][1], Dockworker_Collect[PlayerDockworkerCollect[playerid]][2], 0.0, 0.0, 0.0);

                    TogglePlayerControllable(playerid, true);
                    
                    PlayerInfo[playerid][E_CHARACTER_LOADING] = false;
                    PlayerInfo[playerid][E_CHARACTER_LOADINGCOUNT] = 0;

                    Delete3DTextLabel(PlayerInfo[playerid][E_CHARACTER_LOADINGDISPLAY]); 
                    KillTimer(PlayerInfo[playerid][E_CHARACTER_LOADINGTIMER]);

                    DestroyDynamicObject(CrateObject[vehicleid]);
                    ShowBoxMessage(playerid, "~w~You've succesfully store the package.", 5, 2); 
                    GivePaycheck(playerid, DOCKWORKER_SALARY);

                    PlayerInfo[playerid][E_CHARACTER_RESPECT]++;
                    new str[512];
                    format(str, sizeof(str), "~h~Job Complete~n~~w~$%d~n~Respect +", DOCKWORKER_SALARY);
                    GameTextForPlayer(playerid, str, 3000, 6);
                    VehicleInfo[vehicleid][E_VEHICLE_CRATES] = 0;
                }
            }
        }
    }
    Update3DTextLabelText(PlayerInfo[playerid][E_CHARACTER_LOADINGDISPLAY], COLOR_DARKGREEN, text); 
}

CMD:takecargo(playerid, params[])
{
    new vehicleid = GetPlayerVehicleID(playerid);

    if(GetVehicleModel(vehicleid) != 530)
    	return SendErrorMessage(playerid, "You need to be inside dockworker vehicle.");

    if(!IsPlayerInRangeOfPoint(playerid, 3.0, Dockworker_Collect[PlayerDockworkerCollect[playerid]][0], Dockworker_Collect[PlayerDockworkerCollect[playerid]][1], Dockworker_Collect[PlayerDockworkerCollect[playerid]][2]))
        return SendErrorMessage(playerid, "You aren't near the dockworker collect checkpoint.");

    if(PlayerInfo[playerid][E_CHARACTER_JOBS] != JOB_DOCKSWORKER)
        return SendErrorMessage(playerid, "You aren't docksworker.");

    if(GetPlayerState(playerid) == PLAYER_STATE_DRIVER)
    {
        if(PlayerInfo[playerid][E_CHARACTER_INJOBS] == true && VehicleInfo[vehicleid][E_VEHICLE_CRATES] == 0)
        {
            new Float:x, Float:y, Float:z;
            GetPlayerPos(playerid, x, y, z);

            PlayerInfo[playerid][E_CHARACTER_LOADING] = true;
	        PlayerInfo[playerid][E_CHARACTER_LOADINGCOUNT] = 1;
	        PlayerInfo[playerid][E_CHARACTER_LOADINGDISPLAY] = Create3DTextLabel("Loading take cargo process\n(( |------ ))", COLOR_DARKGREEN, x, y, z, 25.0, 0, 1);
	        PlayerInfo[playerid][E_CHARACTER_LOADINGTIMER] = SetTimerEx("DockWorkers", 500, true, "ii", playerid, 0);
	        TogglePlayerControllable(playerid, false);
        }
    }
    return 1;
}

CMD:storecargo(playerid, params[])
{
    new vehicleid = GetPlayerVehicleID(playerid);

    if(GetVehicleModel(vehicleid) != 530)
    	return SendErrorMessage(playerid, "You need to be inside dockworker vehicle.");

    if(!IsPlayerInRangeOfPoint(playerid, 3.0, Dockworker_Store[PlayerDockworkerStore[playerid]][0],Dockworker_Store[PlayerDockworkerStore[playerid]][1], Dockworker_Store[PlayerDockworkerStore[playerid]][2]))
        return SendErrorMessage(playerid, "You aren't near the dockworker collect checkpoint.");

    if(PlayerInfo[playerid][E_CHARACTER_JOBS] != JOB_DOCKSWORKER)
        return SendErrorMessage(playerid, "You aren't docksworker.");
        
    if(GetPlayerState(playerid) == PLAYER_STATE_DRIVER)
    {
        if(PlayerInfo[playerid][E_CHARACTER_INJOBS] == true && VehicleInfo[vehicleid][E_VEHICLE_CRATES] == 1)
        {
            new Float:x, Float:y, Float:z;
            GetPlayerPos(playerid, x, y, z);

            PlayerInfo[playerid][E_CHARACTER_LOADING] = true;
	        PlayerInfo[playerid][E_CHARACTER_LOADINGCOUNT] = 1;
	        PlayerInfo[playerid][E_CHARACTER_LOADINGDISPLAY] = Create3DTextLabel("Loading take cargo process\n(( |------ ))", COLOR_DARKGREEN, x, y, z, 25.0, 0, 1);
	        PlayerInfo[playerid][E_CHARACTER_LOADINGTIMER] = SetTimerEx("DockWorkers", 500, true, "ii", playerid, 1);
	        TogglePlayerControllable(playerid, false);
        }
    }
    return 1;
}