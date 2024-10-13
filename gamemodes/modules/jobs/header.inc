//Function
stock StartMainJobs(playerid, type)
{
    new vehicleid = GetPlayerVehicleID(playerid);
    switch(type)
    {
        case 1: //Dockworker
        {
            if(GetPlayerState(playerid) == PLAYER_STATE_DRIVER)
            {
                if(PlayerInfo[playerid][E_CHARACTER_DOCKSWORK] == false) //Start
                {
                    if(GetVehicleModel(vehicleid) == 530)
                    {
                        PlayerInfo[playerid][E_CHARACTER_DOCKSWORK] = true;
                        PlayerDockworkerCollect[playerid] = random(sizeof(Dockworker_Collect));
                        GPS_SetPlayerRaceCheckPoint(playerid, 1, Dockworker_Collect[PlayerDockworkerCollect[playerid]][0], Dockworker_Collect[PlayerDockworkerCollect[playerid]][1], Dockworker_Collect[PlayerDockworkerCollect[playerid]][2], 0.0, 0.0, 0.0);

                        ShowBoxMessage(playerid, "~w~Dock Worker job started. Take the package in oceandocks import warehouse and deliver it to export warehouse", 5, 2);
                    }                
                     
                }
                else if(PlayerInfo[playerid][E_CHARACTER_DOCKSWORK] == true) //Stop
                {
                    if(GetVehicleModel(vehicleid) == 530)
                    {
                        PlayerInfo[playerid][E_CHARACTER_DOCKSWORK] = false;
                        PlayerDockworkerCollect[playerid] = 0;
                        PlayerDockworkerStore[playerid] = 0;
                        GPS_DisablePlayerRaceCheckPoint(playerid);
                        ShowBoxMessage(playerid, "~w~Dock Worker job stopped.", 5, 2); 
                    }
                    
                }
            }
            return 1;
        }
        case 2: //Trashmaster
        {
            if(GetPlayerState(playerid) == PLAYER_STATE_DRIVER)
            {
                if(PlayerInfo[playerid][E_CHARACTER_GARBAGEMAN] == false) //Start
                {
                    if(GetVehicleModel(GetPlayerVehicleID(playerid)) == 408)
                    {
                        PlayerInfo[playerid][E_CHARACTER_GARBAGEMAN] = true;
                        PlayerInfo[playerid][E_CHARACTER_JOBSVEHICLE] = GetPlayerVehicleID(playerid);
                        Trashmaster_FetchNewPoint(playerid);

                        PlayerTrashmaster[playerid] = random(sizeof(GarbageLocations));
                        GPS_SetPlayerRaceCheckPoint(playerid, 1, GarbageLocations[PlayerTrashmaster[playerid]][0], GarbageLocations[PlayerTrashmaster[playerid]][1], GarbageLocations[PlayerTrashmaster[playerid]][2], 0.0, 0.0, 0.0);
                        
                        SendTipMessage(playerid, "To start trashmaster jobs press 'ALT' nearest the trashcan pickup.");
                        ShowBoxMessage(playerid, "~w~Trashmaster job started. Colect trash in garbage around los santos", 5, 2);
                    }
                }
                else if(PlayerInfo[playerid][E_CHARACTER_GARBAGEMAN] == true) //Stop
                {
                    if(GetVehicleModel(GetPlayerVehicleID(playerid)) == 408)
                    {
                        SetVehicleToRespawnEx(PlayerInfo[playerid][E_CHARACTER_JOBSVEHICLE]);
                        
                        PlayerInfo[playerid][E_CHARACTER_GARBAGEMAN] = false;
                        PlayerInfo[playerid][E_CHARACTER_JOBSTIME] = 0;
                        PlayerInfo[playerid][E_CHARACTER_JOBSVEHICLE] = -1;
                        RemovePlayerFromVehicle(playerid);
                        GPS_DisablePlayerRaceCheckPoint(playerid);
                        RemovePlayerAttachedObject(playerid, ATTACH_HAND);
                        ShowBoxMessage(playerid, "~w~Trashmaster job stopped.", 5, 2); 
                    }
                }
            }
            return 1;
        }
    }
    return 1;
}

stock InsertJobsPoint()
{
    for(new i = 0; i < sizeof(JobsInfo); i++)
    {
        CreateDynamicPickup(1239, 1, JobsInfo[i][E_JOBSPOSX], JobsInfo[i][E_JOBSPOSY], JobsInfo[i][E_JOBSPOSZ], -1, -1, -1, 5.0);
        CreateDynamic3DTextLabel("[Jobs Point]\n{ffffff}Available commands: /takejobs /quitjobs", COLOR_DARKGREEN, JobsInfo[i][E_JOBSPOSX], JobsInfo[i][E_JOBSPOSY], JobsInfo[i][E_JOBSPOSZ], 5.0);
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
            SendServerMessage(playerid, "You are now a %s use /help to see jobs commands.", JobsInfo[i][E_JOBSNAMES]);
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
        SendServerMessage(playerid, "You are now exit the jobs.");
        SaveCharacter(playerid);
    }
    return 1;
}