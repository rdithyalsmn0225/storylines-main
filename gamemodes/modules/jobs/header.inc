//Function
stock StartMainJobs(playerid, type)
{
    new vehicleid = GetPlayerVehicleID(playerid);
    switch(type)
    {
        case 1: //Dockworker
        {
            if(PlayerInfo[playerid][E_CHARACTER_JOBS] != JOB_DOCKSWORKER)
                return SendErrorMessage(playerid, "You aren't docksworker.");

            if(GetPlayerState(playerid) == PLAYER_STATE_DRIVER)
            {
                if(PlayerInfo[playerid][E_CHARACTER_INJOBS] == false) //Start
                {
                    if(GetVehicleModel(vehicleid) == 530)
                    {
                        if(PlayerInfo[playerid][E_CHARACTER_JOBS] != JOB_DOCKSWORKER)
                            return SendErrorMessage(playerid, "You aren't in docksworker jobs");

                        PlayerInfo[playerid][E_CHARACTER_INJOBS] = true;
                        PlayerDockworkerCollect[playerid] = random(sizeof(Dockworker_Collect));
                        GPS_SetPlayerRaceCheckPoint(playerid, 1, Dockworker_Collect[PlayerDockworkerCollect[playerid]][0], Dockworker_Collect[PlayerDockworkerCollect[playerid]][1], Dockworker_Collect[PlayerDockworkerCollect[playerid]][2], 0.0, 0.0, 0.0);

                        ShowBoxMessage(playerid, "~w~Dock Worker job started. Take the package in oceandocks import warehouse and deliver it to export warehouse", 5, 2);
                    }                
                     
                }
                else if(PlayerInfo[playerid][E_CHARACTER_INJOBS] == true) //Stop
                {
                    if(GetVehicleModel(vehicleid) == 530)
                    {
                        if(PlayerInfo[playerid][E_CHARACTER_JOBS] != JOB_DOCKSWORKER)
                            return SendErrorMessage(playerid, "You aren't in docksworker jobs");

                        PlayerInfo[playerid][E_CHARACTER_INJOBS] = false;
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
                if(PlayerInfo[playerid][E_CHARACTER_INJOBS] == false) //Start
                {
                    if(GetVehicleModel(GetPlayerVehicleID(playerid)) == 408)
                    {
                        if(PlayerInfo[playerid][E_CHARACTER_JOBS] != JOB_TRASHMASTER)
                            return SendErrorMessage(playerid, "You aren't in trashmaster jobs");

                        PlayerInfo[playerid][E_CHARACTER_INJOBS] = true;
                        PlayerInfo[playerid][E_CHARACTER_JOBSVEHICLE] = GetPlayerVehicleID(playerid);
                        Trashmaster_FetchNewPoint(playerid);

                        PlayerTrashmaster[playerid] = random(sizeof(GarbageLocations));
                        GPS_SetPlayerRaceCheckPoint(playerid, 1, GarbageLocations[PlayerTrashmaster[playerid]][0], GarbageLocations[PlayerTrashmaster[playerid]][1], GarbageLocations[PlayerTrashmaster[playerid]][2], 0.0, 0.0, 0.0);
                        
                        SendServerMessage(playerid, "To start trashmaster jobs press ALT nearest the trashcan pickup.");
                        ShowBoxMessage(playerid, "~w~Trashmaster job started. Colect trash in garbage around los santos", 5, 2);
                    }
                }
                else if(PlayerInfo[playerid][E_CHARACTER_INJOBS] == true) //Stop
                {
                    if(GetVehicleModel(GetPlayerVehicleID(playerid)) == 408)
                    {
                        if(PlayerInfo[playerid][E_CHARACTER_JOBS] != JOB_TRASHMASTER)
                            return SendErrorMessage(playerid, "You aren't in trashmaster jobs");

                        SetVehicleToRespawnEx(PlayerInfo[playerid][E_CHARACTER_JOBSVEHICLE]);
                        
                        PlayerInfo[playerid][E_CHARACTER_INJOBS] = false;
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
        case 3: //Burglary
        {
            if(GetPlayerState(playerid) == PLAYER_STATE_DRIVER)
            {
                if(GetVehicleModel(vehicleid) == 498)
                {
                    if(PlayerInfo[playerid][E_CHARACTER_LEVEL] != 5)
                        return SendErrorMessage(playerid, "You must level 5 to start missions burglary.");

                    if(PlayerInfo[playerid][E_CHARACTER_ROBBERYCD] > 0)
                        return SendErrorMessage(playerid, "You cannot be stolen goods at this time.");

                    if(PlayerInfo[playerid][E_CHARACTER_STARTBURGLARY] == true) return SendErrorMessage(playerid, "You're currently in a mission. Please finish it to start another missions.");

                    PlayerInfo[playerid][E_CHARACTER_STARTBURGLARY] = true;
                    PlayerInfo[playerid][E_CHARACTER_BURGLARYVEHICLE] = vehicleid;
                    ShowBoxMessage(playerid, "~w~Burglary started. Find NPC properties destination to start stolen goods!", 5, 2);
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
        CreateDynamicPickup(1239, 1, JobsInfo[i][E_JOBSPOSX], JobsInfo[i][E_JOBSPOSY], JobsInfo[i][E_JOBSPOSZ], -1, -1, -1, 50.0);
        CreateDynamic3DTextLabel("[Jobs Point]\nAvailable commands: /takejob /quitjob", COLOR_POINT, JobsInfo[i][E_JOBSPOSX], JobsInfo[i][E_JOBSPOSY], JobsInfo[i][E_JOBSPOSZ], 50.0);
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
        case JOB_DOCKSWORKER:
		{
            if(PlayerInfo[playerid][E_CHARACTER_LEVEL] >= 5)
                format(name, 32, "Professional Docks");
            else if(PlayerInfo[playerid][E_CHARACTER_LEVEL] >= 0)
                format(name, 32, "Docks Trainee");
        }
        case JOB_TRASHMASTER:
		{
            if(PlayerInfo[playerid][E_CHARACTER_LEVEL] >= 10)
                format(name, 32, "Professional Garbageman");
            else if(PlayerInfo[playerid][E_CHARACTER_LEVEL] >= 8)
                format(name, 32, "Garbageman Trainee");
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
        case JOB_DOCKSWORKER:
		{
			format(name, 32, "Docksworker");
	    }
        case JOB_TRASHMASTER:
		{
			format(name, 32, "Trashmaster");
	    }
	    default: format(name, 32, "Unemployed");
	}

	return name;
}

CMD:takejob(playerid, params[])
{
    if(IsPlayerInRangeOfPoint(playerid, 3.0, JobsInfo[1][E_JOBSPOSX], JobsInfo[1][E_JOBSPOSY], JobsInfo[1][E_JOBSPOSZ]))
    {
        if(PlayerInfo[playerid][E_CHARACTER_JOBS] != JOB_NONE)
            return SendErrorMessage(playerid, "You already have jobs.");

        PlayerInfo[playerid][E_CHARACTER_JOBS] = JOB_TRUCKER;
        SendServerMessage(playerid, "You are now a truckers use /help to see jobs commands.");
        SaveCharacter(playerid);
    }
    else if(IsPlayerInRangeOfPoint(playerid, 3.0, JobsInfo[2][E_JOBSPOSX], JobsInfo[2][E_JOBSPOSY], JobsInfo[2][E_JOBSPOSZ]))
    {
        if(PlayerInfo[playerid][E_CHARACTER_JOBS] != JOB_NONE)
            return SendErrorMessage(playerid, "You already have jobs.");

        PlayerInfo[playerid][E_CHARACTER_JOBS] = JOB_DOCKSWORKER;
        SendServerMessage(playerid, "You are now a docksworkers use /help to see jobs commands.");
        SaveCharacter(playerid);
    }
    else if(IsPlayerInRangeOfPoint(playerid, 3.0, JobsInfo[3][E_JOBSPOSX], JobsInfo[3][E_JOBSPOSY], JobsInfo[3][E_JOBSPOSZ]))
    {
        if(PlayerInfo[playerid][E_CHARACTER_JOBS] != JOB_NONE)
            return SendErrorMessage(playerid, "You already have jobs.");

        PlayerInfo[playerid][E_CHARACTER_JOBS] = JOB_TRASHMASTER;
        SendServerMessage(playerid, "You are now a trashmaster use /help to see jobs commands.");
        SaveCharacter(playerid);
    }
    else return SendErrorMessage(playerid, "You aren't near jobs point");
    return 1;
}

CMD:quitjob(playerid, params[])
{
    if(PlayerInfo[playerid][E_CHARACTER_JOBS] != JOB_NONE)
    {
        PlayerInfo[playerid][E_CHARACTER_JOBS] = JOB_NONE;
        SendServerMessage(playerid, "You are now exit the jobs.");
        SaveCharacter(playerid);
    }
    return 1;
}