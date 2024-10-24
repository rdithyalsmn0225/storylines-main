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

                        ShowBoxMessage(playerid, "~w~Dock Worker job started. Take the package in oceandocks import warehouse and deliver it to export warehouse", 5);
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
                        ShowBoxMessage(playerid, "~r~Dock Worker job stopped.", 5); 
                    }
                    
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
    }
    return 1;
}

stock InsertJobsPoint()
{
    for(new i = 0; i < sizeof(JobsInfo); i++)
    {
        CreateDynamicPickup(1210, 1, JobsInfo[i][E_JOBSPOSX], JobsInfo[i][E_JOBSPOSY], JobsInfo[i][E_JOBSPOSZ], -1, -1, -1, 5.0);
        CreateDynamic3DTextLabel("[Jobs Point]\n{ffffff}Available commands: /takejobs /quitjobs", COLOR_POINT, JobsInfo[i][E_JOBSPOSX], JobsInfo[i][E_JOBSPOSY], JobsInfo[i][E_JOBSPOSZ], 5.0);
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
            SendServerMessage(playerid, "[Jobs] {cdd0d1}You are now a %s use /help to see jobs commands.", JobsInfo[i][E_JOBSNAMES]);
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
        SendServerMessage(playerid, "[Jobs] {cdd0d1}You are now exit the jobs.");
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
    }
    else if(GetPlayerState(playerid) == PLAYER_STATE_DRIVER && IsPlayerInAnyVehicle(playerid))
    {
        new vehicleid = GetPlayerVehicleID(playerid);
        if(GetVehicleModel(vehicleid) == 530)
        {
            StartMainJobs(playerid, 1);
        } 
        else if(GetVehicleModel(vehicleid) == 420 || GetVehicleModel(vehicleid) == 438)
        {
            if (PlayerInfo[playerid][E_CHARACTER_JOBS] != JOB_TAXI)
                return SendErrorMessage(playerid, "You aren't taxi driver.");

            if (PlayerInfo[playerid][E_CHARACTER_TAXIDUTY])
            {
                foreach (new i : Player) if (PlayerInfo[i][E_CHARACTER_TAXIPLAYER] == playerid && IsPlayerInVehicle(i, GetPlayerVehicleID(playerid))) {
                    LeaveTaxi(i, playerid);
                }
                
                PlayerInfo[playerid][E_CHARACTER_TAXIDUTY] = false;
                SendServerMessage(playerid, "[Taxi] {cdd0d1}You are no longer on taxi duty!");
            }
            else
            {
                PlayerInfo[playerid][E_CHARACTER_TAXIDUTY] = true;
                SendClientMessageToAllEx(COLOR_TAXI, "[Taxi Duty]: %s is now on taxi duty. Type \"/call 111\" to call a taxi!", ReturnSettingsName(playerid, playerid));
            }
        }
        else if(GetVehicleModel(vehicleid) == 525)
        {
            if (PlayerInfo[playerid][E_CHARACTER_JOBS] != JOB_MECHANIC)
                return SendErrorMessage(playerid, "You aren't mechanic.");

            if (PlayerInfo[playerid][E_CHARACTER_MECHDUTY])
            {
                PlayerInfo[playerid][E_CHARACTER_MECHDUTY] = false;
                SendServerMessage(playerid, "[Mechanic] {cdd0d1}You are no longer on mechanic duty!");
            }
            else
            {
                PlayerInfo[playerid][E_CHARACTER_MECHDUTY] = true;
                SendServerMessage(playerid, "[Mechanic] {cdd0d1}You are now mechanic duty!");
            }
        }
    }
    return 1;
}