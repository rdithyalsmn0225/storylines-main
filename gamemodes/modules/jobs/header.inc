//Function
stock StartMainJobs(playerid, type)
{
    new vehicleid = GetPlayerVehicleID(playerid);
    new Float:x, Float:y, Float:z;
    GetPlayerPos(playerid, x, y, z);

    switch(type)
    {
        case 1: //Dockworker
        {
            
            if(PlayerInfo[playerid][E_CHARACTER_DOCKSWORK] == false) //Start
            {
                PlayerInfo[playerid][E_CHARACTER_JOBSVEHICLE] = CreateVehicle(530, x, y, z, 0.0, 1, 1, 5000, 0);
                VehicleInfo[PlayerInfo[playerid][E_CHARACTER_JOBSVEHICLE]][E_VEHICLE_HEALTH] = 1000.0;
                VehicleInfo[PlayerInfo[playerid][E_CHARACTER_JOBSVEHICLE]][E_VEHICLE_FUEL] = 1000;

                PlayerPutIntoVehicle(playerid, PlayerInfo[playerid][E_CHARACTER_JOBSVEHICLE], 0);
                PlayerInfo[playerid][E_CHARACTER_DOCKSWORK] = true;
                PlayerDockworkerCollect[playerid] = random(sizeof(Dockworker_Collect));
                GPS_SetPlayerRaceCheckPoint(playerid, 1, Dockworker_Collect[PlayerDockworkerCollect[playerid]][E_DOCKWORK_POS][0], Dockworker_Collect[PlayerDockworkerCollect[playerid]][E_DOCKWORK_POS][1], Dockworker_Collect[PlayerDockworkerCollect[playerid]][E_DOCKWORK_POS][2], 0.0, 0.0, 0.0);

                SendJobsMessage(playerid, "[Dockworker] {DEDEDE}To start dockworker jobs, guide will randomly marked in your map to collect and store warehouse.");
                SendJobsMessage(playerid, "[Dockworker] {DEDEDE}To collect cargo '/takecargo' nearest the warehouse checkpoint.");
                SendJobsMessage(playerid, "[Dockworker] {DEDEDE}To store cargo '/storecargo' nearest the warehouse checkpoint.");
                SendJobsMessage(playerid, "[Dockworker] {DEDEDE}Next task: fetch some %s from the %s and store it in the next warehouse.", Dockworker_Collect[PlayerDockworkerCollect[playerid]][E_DOCKWORK_DESCRIPTION], Dockworker_Store[PlayerDockworkerCollect[playerid]][E_DOCKWORK_DESCRIPTION]);

            }
            else if(PlayerInfo[playerid][E_CHARACTER_DOCKSWORK] == true) //Stop
            {
                if(GetVehicleModel(vehicleid) == 530)
                {
                    PlayerInfo[playerid][E_CHARACTER_DOCKSWORK] = false;
                    PlayerDockworkerCollect[playerid] = 0;
                    PlayerDockworkerStore[playerid] = 0;
                    GPS_DisablePlayerRaceCheckPoint(playerid);
                    ShowBoxMessage(playerid, "~r~Dockworker job stopped.", 5); 
		            DestroyVehicle(PlayerInfo[playerid][E_CHARACTER_JOBSVEHICLE]);
                }
                
            }
            return 1;
        }
        case 2: //Trashmaster
        {
            if(IsPlayerInRangeOfPoint(playerid, 3.0, 1529.5608,-1849.4032,13.5469))
            {
                if(PlayerInfo[playerid][E_CHARACTER_GARBAGEMAN] == false) //Start
                {
                    if(PlayerInfo[playerid][E_CHARACTER_GARBAGECD])
                        return SendErrorMessage(playerid, "You cannot use this commands right now.");

                    PlayerInfo[playerid][E_CHARACTER_GARBAGEMAN] = true;
                    SetPlayerSkin(playerid, 16);

                    SendTipMessage(playerid, "To start garbageman jobs press 'ALT' or '/collectgarbage' nearest the trash objects.");
                    SendTipMessage(playerid, "To find the rubbish '/garbage' will show in your map.");
                    SendTipMessage(playerid, "To empty your garbage bag '/dumpgarbage' in HQ");
                }
                else if(PlayerInfo[playerid][E_CHARACTER_GARBAGEMAN] == true) //Stop
                {
                    SetPlayerSkin(playerid, PlayerInfo[playerid][E_CHARACTER_LASTSKIN]);
                    PlayerInfo[playerid][E_CHARACTER_GARBAGEMAN] = false;
                    ShowBoxMessage(playerid, "~r~Garbageman job stopped.", 5); 
                }
            }
            return 1;
        }
        case 3: //Sweeper
        {
            if(PlayerInfo[playerid][E_CHARACTER_SWEEPER] == false) //Start
            {
                if(PlayerInfo[playerid][E_CHARACTER_SWEEPERCD])
                    return SendErrorMessage(playerid, "You cannot use this commands right now.");

                PlayerInfo[playerid][E_CHARACTER_JOBSVEHICLE] = CreateVehicle(574, x, y, z, 0.0, 1, 1, 5000, 0);
                VehicleInfo[PlayerInfo[playerid][E_CHARACTER_JOBSVEHICLE]][E_VEHICLE_HEALTH] = 1000.0;
                VehicleInfo[PlayerInfo[playerid][E_CHARACTER_JOBSVEHICLE]][E_VEHICLE_FUEL] = 1000;
                
                PlayerPutIntoVehicle(playerid, PlayerInfo[playerid][E_CHARACTER_JOBSVEHICLE], 0);
                PlayerInfo[playerid][E_CHARACTER_SWEEPER] = true;
                PlayerSweeperIndex[playerid] = 1;
                
                GPS_SetPlayerRaceCheckPoint(playerid, 1, Sweeper_Index[0][0], Sweeper_Index[0][1], Sweeper_Index[0][2], 0.0, 0.0, 0.0, GPS_SWEEPER); // SweepCheckPoint1

                SendTipMessage(playerid, "To Street Claner jobs drive around the street to clean the street.");
                SendTipMessage(playerid, "Follow the checkpoint in your maps.");
                ShowBoxMessage(playerid, "~w~Street Claner job started. Clean trash around the street.", 5);

            }
            else if(PlayerInfo[playerid][E_CHARACTER_SWEEPER] == true) //Stop
            {
                if(GetVehicleModel(vehicleid) == 574)
                {
                    PlayerInfo[playerid][E_CHARACTER_SWEEPER] = false;
                    
                    GPS_DisablePlayerRaceCheckPoint(playerid);
                    ShowBoxMessage(playerid, "~r~Street Cleaner job stopped.", 5); 
		            DestroyVehicle(PlayerInfo[playerid][E_CHARACTER_JOBSVEHICLE]);
                }
            }
            return 1;
        }
        case 4: //Bus Driver
        {
            if(PlayerInfo[playerid][E_CHARACTER_BUSDRIVER] == false) //Start
            {
                if(PlayerInfo[playerid][E_CHARACTER_BUSDRIVERCD])
                    return SendErrorMessage(playerid, "You cannot use this commands right now.");

                PlayerInfo[playerid][E_CHARACTER_JOBSVEHICLE] = CreateVehicle(431, 1696.8093,-1527.8206,13.4835, 359.0005, 1, 1, 5000, 0);
                VehicleInfo[PlayerInfo[playerid][E_CHARACTER_JOBSVEHICLE]][E_VEHICLE_HEALTH] = 1000.0;
                VehicleInfo[PlayerInfo[playerid][E_CHARACTER_JOBSVEHICLE]][E_VEHICLE_FUEL] = 1000;
                
                PlayerPutIntoVehicle(playerid, PlayerInfo[playerid][E_CHARACTER_JOBSVEHICLE], 0);
                PlayerInfo[playerid][E_CHARACTER_BUSDRIVER] = true;
                PlayerBusDriverIndex[playerid] = 0;

                GPS_SetPlayerRaceCheckPoint(playerid, 1, BusDriver_Index[PlayerBusDriverIndex[playerid]][0],BusDriver_Index[PlayerBusDriverIndex[playerid]][1], BusDriver_Index[PlayerBusDriverIndex[playerid]][2], 0.0, 0.0, 0.0, GPS_BUSDRIVER);
                
                SendTipMessage(playerid, "To Bus Driver jobs drive around the street and get passengers at bus stops.");
                SendTipMessage(playerid, "Follow the checkpoint in your maps.");
                ShowBoxMessage(playerid, "~w~Bus Driver job started. Drive around the street and get passengers at bus stops.", 5);

            }
            else if(PlayerInfo[playerid][E_CHARACTER_BUSDRIVER] == true) //Stop
            {
                if(GetVehicleModel(vehicleid) == 431)
                {
                    PlayerInfo[playerid][E_CHARACTER_BUSDRIVER] = false;
                    
                    GPS_DisablePlayerRaceCheckPoint(playerid);
                    ShowBoxMessage(playerid, "~r~Bus Driver job stopped.", 5); 
		            DestroyVehicle(PlayerInfo[playerid][E_CHARACTER_JOBSVEHICLE]);
                }
            }
            return 1;
        }
    }
    return 1;
}

function:OnPlayerJobsUpdate()
{
    foreach(new i : Player)
    {
        if(PlayerInfo[i][E_CHARACTER_JOBSCD])
        {
            PlayerInfo[i][E_CHARACTER_JOBSCD]--;
            if(PlayerInfo[i][E_CHARACTER_JOBSCD] < 0)
            {
                PlayerInfo[i][E_CHARACTER_JOBSCD] = 0;
                SendServerMessage(i, "[Jobs] {DEDEDE}You can start {d7d292}Main Jobs{DEDEDE} rightnow.");
            }
        }

        if(PlayerInfo[i][E_CHARACTER_SWEEPERCD])
        {
            PlayerInfo[i][E_CHARACTER_SWEEPERCD]--;
            if(PlayerInfo[i][E_CHARACTER_SWEEPERCD] < 0)
            {
                PlayerInfo[i][E_CHARACTER_SWEEPERCD] = 0;
                SendServerMessage(i, "[Jobs] {DEDEDE}You can start {d7d292}Street Cleaner{DEDEDE} SideJobs rightnow.");
            }
        }

        if(PlayerInfo[i][E_CHARACTER_GARBAGECD])
        {
            PlayerInfo[i][E_CHARACTER_GARBAGECD]--;
            if(PlayerInfo[i][E_CHARACTER_GARBAGECD] < 0)
            {
                PlayerInfo[i][E_CHARACTER_GARBAGECD] = 0;
                SendServerMessage(i, "[Jobs] {DEDEDE}You can start {d7d292}Garbageman{DEDEDE} SideJobs rightnow.");
            }
        }

        if(PlayerInfo[i][E_CHARACTER_BUSDRIVERCD])
        {
            PlayerInfo[i][E_CHARACTER_BUSDRIVERCD]--;
            if(PlayerInfo[i][E_CHARACTER_BUSDRIVERCD] < 0)
            {
                PlayerInfo[i][E_CHARACTER_BUSDRIVERCD] = 0;
                SendServerMessage(i, "[Jobs] {DEDEDE}You can start {d7d292}Bus Driver{DEDEDE} SideJobs rightnow.");
            }
        }
    }
    return 1;
}
stock InsertJobsPoint()
{
    for(new i = 0; i < sizeof(JobsInfo); i++)
    {
        new str[512];
        JobsPickup[i] = CreateDynamicPickup(1210, 1, JobsInfo[i][E_JOBSPOSX], JobsInfo[i][E_JOBSPOSY], JobsInfo[i][E_JOBSPOSZ], -1, -1, -1, 5.0);
        format(str, sizeof(str), "[%s]", JobsInfo[i][E_JOBSNAMES]);
        CreateDynamic3DTextLabel(str, COLOR_3DTEXT, JobsInfo[i][E_JOBSPOSX], JobsInfo[i][E_JOBSPOSY], JobsInfo[i][E_JOBSPOSZ], 5.0);


        CreateDynamicMapIcon(JobsInfo[1][E_JOBSPOSX], JobsInfo[1][E_JOBSPOSY], JobsInfo[1][E_JOBSPOSZ], 51, 0, -1, -1, -1, 999999.0);
        CreateDynamicMapIcon(JobsInfo[2][E_JOBSPOSX], JobsInfo[2][E_JOBSPOSY], JobsInfo[2][E_JOBSPOSZ], 11, 0, -1, -1, -1, 999999.0);
        CreateDynamicMapIcon(JobsInfo[3][E_JOBSPOSX], JobsInfo[3][E_JOBSPOSY], JobsInfo[3][E_JOBSPOSZ], 42, 0, -1, -1, -1, 999999.0);
        CreateDynamicMapIcon(JobsInfo[4][E_JOBSPOSX], JobsInfo[4][E_JOBSPOSY], JobsInfo[4][E_JOBSPOSZ], 27, 0, -1, -1, -1, 999999.0);
    }
    return 1;
}

ReturnJobSkill(playerid, jobid)
{
	new name[32];

	switch(jobid)
	{
	    case JOB_TRUCKER:
		{
			if(PlayerInfo[playerid][E_CHARACTER_LEVEL] >= 10)
                format(name, 32, "Professional Trucker");
            else if(PlayerInfo[playerid][E_CHARACTER_LEVEL] >= 8)
                format(name, 32, "Trucker");
            else if(PlayerInfo[playerid][E_CHARACTER_LEVEL] >= 6)
                format(name, 32, "Trucker Trainee");
            else if(PlayerInfo[playerid][E_CHARACTER_LEVEL] >= 4)
                format(name, 32, "Professional Courier");
            else if(PlayerInfo[playerid][E_CHARACTER_LEVEL] >= 2)
                format(name, 32, "Courier");
            else if(PlayerInfo[playerid][E_CHARACTER_LEVEL] >= 0)
                format(name, 32, "Courier Trainee");
	    }
        case JOB_LUMBERJACK:
		{
			if(PlayerInfo[playerid][E_CHARACTER_LEVEL] >= 10)
                format(name, 32, "Professional Lumberjack");
            else if(PlayerInfo[playerid][E_CHARACTER_LEVEL] >= 8)
                format(name, 32, "Lumberjack");
            else if(PlayerInfo[playerid][E_CHARACTER_LEVEL] >= 6)
                format(name, 32, "Lumberjack Trainee");
            else if(PlayerInfo[playerid][E_CHARACTER_LEVEL] >= 4)
                format(name, 32, "Professional Timberjack");
            else if(PlayerInfo[playerid][E_CHARACTER_LEVEL] >= 2)
                format(name, 32, "Timberjack");
            else if(PlayerInfo[playerid][E_CHARACTER_LEVEL] >= 0)
                format(name, 32, "Timberjack Trainee");
	    }
        case JOB_TAXI:
		{
			if(PlayerInfo[playerid][E_CHARACTER_LEVEL] >= 10)
                format(name, 32, "Professional Taxi Driver");
            else if(PlayerInfo[playerid][E_CHARACTER_LEVEL] >= 8)
                format(name, 32, "Taxi Driver");
            else if(PlayerInfo[playerid][E_CHARACTER_LEVEL] >= 6)
                format(name, 32, "Taxi Driver Trainee");
            else if(PlayerInfo[playerid][E_CHARACTER_LEVEL] >= 4)
                format(name, 32, "Professional Driver");
            else if(PlayerInfo[playerid][E_CHARACTER_LEVEL] >= 2)
                format(name, 32, "Driver");
            else if(PlayerInfo[playerid][E_CHARACTER_LEVEL] >= 0)
                format(name, 32, "Driver Trainee");
	    }
        case JOB_MECHANIC:
		{
			if(PlayerInfo[playerid][E_CHARACTER_LEVEL] >= 10)
                format(name, 32, "Professional Mechanic Technician");
            else if(PlayerInfo[playerid][E_CHARACTER_LEVEL] >= 8)
                format(name, 32, "Mechanic Technician");
            else if(PlayerInfo[playerid][E_CHARACTER_LEVEL] >= 6)
                format(name, 32, "Mechanic Technician Trainee");
            else if(PlayerInfo[playerid][E_CHARACTER_LEVEL] >= 4)
                format(name, 32, "Professional Mechanic");
            else if(PlayerInfo[playerid][E_CHARACTER_LEVEL] >= 2)
                format(name, 32, "Mechanic");
            else if(PlayerInfo[playerid][E_CHARACTER_LEVEL] >= 0)
                format(name, 32, "Mechanic Trainee");
	    }
        case JOB_SMUGGLER:
		{
			if(PlayerInfo[playerid][E_CHARACTER_LEVEL] >= 10)
                format(name, 32, "Professional Smuggler");
            else if(PlayerInfo[playerid][E_CHARACTER_LEVEL] >= 5)
                format(name, 32, "Smuggler");
            else if(PlayerInfo[playerid][E_CHARACTER_LEVEL] >= 3)
                format(name, 32, "Smuggler Trainee");
	    }
	    default: format(name, 32, "Unemployed");
	}
	return name;
}

ReturnJobName(jobid)
{
	new name[32];

	switch(jobid)
	{
	    case JOB_TRUCKER:
		{
			format(name, 32, "Truckers");
	    }
        case JOB_LUMBERJACK:
        {
            format(name, 32, "Lumberjack");
        }
        case JOB_TAXI:
        {
            format(name, 32, "Taxi Driver");
        }
        case JOB_MECHANIC:
        {
            format(name, 32, "Mechanic");
        }
        case JOB_SMUGGLER:
        {
            format(name, 32, "Smugglers");
        }
	    default: format(name, 32, "Unemployed");
	}

	return name;
}

CMD:takejobs(playerid, params[])
{
    for(new i = 0; i != sizeof(JobsInfo); i++)
    {
        if(IsPlayerInRangeOfPoint(playerid, 3.0, JobsInfo[i][E_JOBSPOSX], JobsInfo[i][E_JOBSPOSY], JobsInfo[i][E_JOBSPOSZ]))
        {
            if(PlayerInfo[playerid][E_CHARACTER_JOBS] != JOB_NONE)
                return SendErrorMessage(playerid, "You already have jobs.");

            PlayerInfo[playerid][E_CHARACTER_JOBS] = i;
            SendServerMessage(playerid, "[Jobs] {DEDEDE}You are now a %s use /help to see jobs commands.", JobsInfo[i][E_JOBSNAMES]);
            SaveCharacter(playerid);
        }
    }
    return 1;
}

CMD:quitjobs(playerid, params[])
{
    if(PlayerInfo[playerid][E_CHARACTER_JOBS] != JOB_NONE)
    {
        PlayerInfo[playerid][E_CHARACTER_JOBS] = JOB_NONE;
        SendServerMessage(playerid, "[Jobs] {DEDEDE}You are now exit the jobs.");
        SaveCharacter(playerid);
    }
    return 1;
}

CMD:jobduty(playerid, params[])
{
    if(GetPlayerState(playerid) == PLAYER_STATE_ONFOOT)
    {
        if(IsPlayerInRangeOfPoint(playerid, 3.0, 1529.5608,-1849.4032,13.5469))
        {
            StartMainJobs(playerid, 2);
        }
        if(IsPlayerInRangeOfPoint(playerid, 3.0, 2748.7725,-2451.0012,13.6484))
        {
            StartMainJobs(playerid, 1);
        }
        if(IsPlayerInRangeOfPoint(playerid, 3.0, 860.7480,-1372.0948,13.5469))
        {
            StartMainJobs(playerid, 3);
        }
        if(IsPlayerInRangeOfPoint(playerid, 3.0, 1696.8093,-1527.8206,13.4835))
        {
            StartMainJobs(playerid, 4);
        }
        return 1;
    }
    
    if(GetPlayerState(playerid) == PLAYER_STATE_DRIVER && IsPlayerInAnyVehicle(playerid))
    {
        new vehicleid = GetPlayerVehicleID(playerid);
        if(GetVehicleModel(vehicleid) == 420 || GetVehicleModel(vehicleid) == 438)
        {
            if (PlayerInfo[playerid][E_CHARACTER_JOBS] != JOB_TAXI)
                return SendErrorMessage(playerid, "You aren't taxi driver.");

            if (PlayerInfo[playerid][E_CHARACTER_TAXIDUTY])
            {
                foreach (new i : Player) if (PlayerInfo[i][E_CHARACTER_TAXIPLAYER] == playerid && IsPlayerInVehicle(i, GetPlayerVehicleID(playerid))) {
                    LeaveTaxi(i, playerid);
                }
                
                PlayerInfo[playerid][E_CHARACTER_TAXIDUTY] = false;
                SendJobsMessage(playerid, "[Taxi] {DEDEDE}You are no longer on taxi duty!");
            }
            else
            {
                PlayerInfo[playerid][E_CHARACTER_TAXIDUTY] = true;
                SendClientMessageToAllEx(COLOR_TAXI, "[Taxi Duty]: %s is now on taxi duty. Type \"/call 111\" to call a taxi!", ReturnName(playerid));
            }
        }
        else if(GetVehicleModel(vehicleid) == 525)
        {
            if (PlayerInfo[playerid][E_CHARACTER_JOBS] != JOB_MECHANIC)
                return SendErrorMessage(playerid, "You aren't mechanic.");

            if (PlayerInfo[playerid][E_CHARACTER_MECHDUTY])
            {
                PlayerInfo[playerid][E_CHARACTER_MECHDUTY] = false;
                SendJobsMessage(playerid, "[Mechanic] {DEDEDE}You are no longer on mechanic duty!");
            }
            else
            {
                PlayerInfo[playerid][E_CHARACTER_MECHDUTY] = true;
                SendJobsMessage(playerid, "[Mechanic] {DEDEDE}You are now mechanic duty!");
            }
        }
        return 1;
    }
    return 1;
}