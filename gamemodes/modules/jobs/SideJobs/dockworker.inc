InsertDocksWorkers()
{
    for(new i; i < sizeof(Dockworker_Store); i++)
    {
        CreateDynamic3DTextLabel("[Docksworker Point]\n{ffffff}Available commands: /storecargo", COLOR_3DTEXT, Dockworker_Store[i][E_DOCKWORK_POS][0],Dockworker_Store[i][E_DOCKWORK_POS][1], Dockworker_Store[i][E_DOCKWORK_POS][2], 5.0);
    }
    for(new i; i < sizeof(Dockworker_Collect); i++)
    {
        CreateDynamic3DTextLabel("[Docksworker Point]\n{ffffff}Available commands: /takecargo", COLOR_3DTEXT, Dockworker_Collect[i][E_DOCKWORK_POS][0],Dockworker_Collect[i][E_DOCKWORK_POS][1], Dockworker_Collect[i][E_DOCKWORK_POS][2], 5.0);
    }
    return 1;
}
function:DockWorkers(playerid, type)
{
    new text[256];
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

                    GPS_SetPlayerRaceCheckPoint(playerid, 1, Dockworker_Store[PlayerDockworkerStore[playerid]][E_DOCKWORK_POS][0],Dockworker_Store[PlayerDockworkerStore[playerid]][E_DOCKWORK_POS][1], Dockworker_Store[PlayerDockworkerStore[playerid]][E_DOCKWORK_POS][2], 0.0, 0.0, 0.0);
                    TogglePlayerControllable(playerid, true);
                    
                    PlayerInfo[playerid][E_CHARACTER_LOADING] = false;
                    PlayerInfo[playerid][E_CHARACTER_LOADINGCOUNT] = 0;

                    Delete3DTextLabel(PlayerInfo[playerid][E_CHARACTER_LOADINGDISPLAY]); 
                    KillTimer(PlayerInfo[playerid][E_CHARACTER_LOADINGTIMER]);

                    SetPlayerNeeds(playerid, -0.1, -0.2);

                    CrateObject[PlayerInfo[playerid][E_CHARACTER_JOBSVEHICLE]] = CreateDynamicObject(1221,0.0,0.0,-1000.0,0.0,0.0,0.0,-1,-1,-1,300.0,300.0);
                    AttachDynamicObjectToVehicle(CrateObject[PlayerInfo[playerid][E_CHARACTER_JOBSVEHICLE]], PlayerInfo[playerid][E_CHARACTER_JOBSVEHICLE], 0.000, 0.630, 0.360, 0.000, 0.000, 0.000);
                    VehicleInfo[PlayerInfo[playerid][E_CHARACTER_JOBSVEHICLE]][E_VEHICLE_CRATES] = 1;
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
                    GPS_SetPlayerRaceCheckPoint(playerid, 1, Dockworker_Collect[PlayerDockworkerCollect[playerid]][E_DOCKWORK_POS][0], Dockworker_Collect[PlayerDockworkerCollect[playerid]][E_DOCKWORK_POS][1], Dockworker_Collect[PlayerDockworkerCollect[playerid]][E_DOCKWORK_POS][2], 0.0, 0.0, 0.0);

                    TogglePlayerControllable(playerid, true);
                    
                    PlayerInfo[playerid][E_CHARACTER_LOADING] = false;
                    PlayerInfo[playerid][E_CHARACTER_LOADINGCOUNT] = 0;

                    Delete3DTextLabel(PlayerInfo[playerid][E_CHARACTER_LOADINGDISPLAY]); 
                    KillTimer(PlayerInfo[playerid][E_CHARACTER_LOADINGTIMER]);

                    DestroyDynamicObject(CrateObject[PlayerInfo[playerid][E_CHARACTER_JOBSVEHICLE]]);
                    SendJobsMessage(playerid, "[Dockworker] {DEDEDE}Next task: fetch some %s from the %s and store it in the next warehouse.", Dockworker_Collect[PlayerDockworkerCollect[playerid]][E_DOCKWORK_DESCRIPTION], Dockworker_Store[PlayerDockworkerCollect[playerid]][E_DOCKWORK_DESCRIPTION]);
                    
                    new rand = randomEx(8, 10);
                    new Cents = floatround(rand * 100, floatround_round);

	                GiveMoney(playerid, Cents);

                    SetPlayerNeeds(playerid, -0.1, -0.2);
                    PlayerDockworkerLimit[playerid]++;
                    if(PlayerDockworkerLimit[playerid] > 10)
                    {
                        PlayerDockworkerLimit[playerid] = 0;
                        PlayerInfo[playerid][E_CHARACTER_DOCKWORKERCD] = 10;
                    }
                    VehicleInfo[PlayerInfo[playerid][E_CHARACTER_JOBSVEHICLE]][E_VEHICLE_CRATES] = 0;
                }
            }
        }
    }
    Update3DTextLabelText(PlayerInfo[playerid][E_CHARACTER_LOADINGDISPLAY], COLOR_3DTEXT, text); 
}

CMD:takecargo(playerid, params[])
{
    new vehicleid = GetPlayerVehicleID(playerid);

    if(GetVehicleModel(vehicleid) != 530)
    	return SendErrorMessage(playerid, "You need to be inside dockworker vehicle.");

    if(!IsPlayerInRangeOfPoint(playerid, 3.0, Dockworker_Collect[PlayerDockworkerCollect[playerid]][E_DOCKWORK_POS][0], Dockworker_Collect[PlayerDockworkerCollect[playerid]][E_DOCKWORK_POS][1], Dockworker_Collect[PlayerDockworkerCollect[playerid]][E_DOCKWORK_POS][2]))
        return SendErrorMessage(playerid, "You aren't near the dockworker collect checkpoint.");

    if(PlayerInfo[playerid][E_CHARACTER_LOADING] == true)
		return SendErrorMessage(playerid, "You can't use this right now"); 

    if(PlayerInfo[playerid][E_CHARACTER_HUNGRY] < 20 || PlayerInfo[playerid][E_CHARACTER_THIRSTY] < 20)
		return SendErrorMessage(playerid, "You're hungry or thirsty right now.");

    if(GetPlayerState(playerid) == PLAYER_STATE_DRIVER)
    {
        if(PlayerInfo[playerid][E_CHARACTER_DOCKSWORK] == true && VehicleInfo[vehicleid][E_VEHICLE_CRATES] == 0)
        {
            new Float:x, Float:y, Float:z;
            GetPlayerPos(playerid, x, y, z);

            PlayerInfo[playerid][E_CHARACTER_LOADING] = true;
	        PlayerInfo[playerid][E_CHARACTER_LOADINGCOUNT] = 1;
	        PlayerInfo[playerid][E_CHARACTER_LOADINGDISPLAY] = Create3DTextLabel("Loading take cargo process\n(( |------ ))", COLOR_3DTEXT, x, y, z, 25.0, 0, 1);
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

    if(!IsPlayerInRangeOfPoint(playerid, 3.0, Dockworker_Store[PlayerDockworkerStore[playerid]][E_DOCKWORK_POS][0],Dockworker_Store[PlayerDockworkerStore[playerid]][E_DOCKWORK_POS][1], Dockworker_Store[PlayerDockworkerStore[playerid]][E_DOCKWORK_POS][2]))
        return SendErrorMessage(playerid, "You aren't near the dockworker collect checkpoint.");
        
    if(PlayerInfo[playerid][E_CHARACTER_LOADING] == true)
		return SendErrorMessage(playerid, "You can't use this right now"); 

    if(PlayerInfo[playerid][E_CHARACTER_HUNGRY] < 20 || PlayerInfo[playerid][E_CHARACTER_THIRSTY] < 20)
		return SendErrorMessage(playerid, "You're hungry or thirsty right now.");

    if(GetPlayerState(playerid) == PLAYER_STATE_DRIVER)
    {
        if(PlayerInfo[playerid][E_CHARACTER_DOCKSWORK] == true && VehicleInfo[vehicleid][E_VEHICLE_CRATES] == 1)
        {
            new Float:x, Float:y, Float:z;
            GetPlayerPos(playerid, x, y, z);

            PlayerInfo[playerid][E_CHARACTER_LOADING] = true;
	        PlayerInfo[playerid][E_CHARACTER_LOADINGCOUNT] = 1;
	        PlayerInfo[playerid][E_CHARACTER_LOADINGDISPLAY] = Create3DTextLabel("Loading take cargo process\n(( |------ ))", COLOR_3DTEXT, x, y, z, 25.0, 0, 1);
	        PlayerInfo[playerid][E_CHARACTER_LOADINGTIMER] = SetTimerEx("DockWorkers", 500, true, "ii", playerid, 1);
	        TogglePlayerControllable(playerid, false);
        }
    }
    return 1;
}