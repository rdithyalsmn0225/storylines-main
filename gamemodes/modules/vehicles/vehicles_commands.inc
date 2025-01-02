//car commands:
CMD:carsell(playerid, params[])
{
	new vehicleid = GetPlayerVehicleID(playerid);

	if(!IsPlayerInAnyVehicle(playerid))
		return SendErrorMessage(playerid, "You aren't in any vehicle.");

	if(VehicleInfo[vehicleid][E_VEHICLE_OWNERDBID] != PlayerInfo[playerid][E_CHARACTER_DBID])
		return SendErrorMessage(playerid, "You don't own this vehicle."); 

	new userid = INVALID_PLAYER_ID, price;

	if(sscanf(params, "uf", userid, price))
		return SendUsageMessage(playerid, "/carsell [playerid OR name] [price]"); 

	if(userid == INVALID_PLAYER_ID)
		return SendErrorMessage(playerid, "This player is not connected.");

	if(userid == playerid)
		return SendErrorMessage(playerid, "You can't sell it to yourself.");

	if(!IsPlayerNearPlayer(playerid, userid, 5.0))
		return SendErrorMessage(playerid, "You aren't near that player.");

	new idx;
	new Cents = floatround(price * 100, floatround_round);
			
	for(new i = 1; i < MAX_PLAYER_VEHICLES; i++)
	{
		if(!PlayerInfo[userid][E_CHARACTER_OWNEDVEHICLE][i])
		{
			idx = i;
			break;
		}
	}
				
	if(!idx)
	{
		SendErrorMessage(playerid, "This player own the maximum amount of vehicles."); 
		return 1;
	}

	if(price < 0)
		return SendErrorMessage(playerid, "Invalid price!");

	PlayerInfo[userid][E_CHARACTER_PRICEOFFER] = Cents;
	PlayerInfo[userid][E_CHARACTER_SELLOFFER] = playerid;
	PlayerInfo[userid][E_CHARACTER_SELLVOFFER] = vehicleid;

	SendTipMessage(userid, "%s has offered sell their vehicle %s for $%s, type /approve vehicle to approve.", ReturnName(playerid), ReturnVehicleModelName(vehicleid), FormatMoney(Cents));
	SendVehicleMessage(playerid, "[VEHICLE] You have offered sell your %s for $%s.", ReturnName(userid, playerid), ReturnVehicleModelName(vehicleid), FormatMoney(Cents));
	return 1;
}

CMD:carkey(playerid, params[])
{
    if(!IsPlayerInAnyVehicle(playerid))
		return SendErrorMessage(playerid, "You aren't in any vehicle.");
			
	if(PlayerInfo[playerid][E_CHARACTER_VEHICLESPAWNED] == false) return SendErrorMessage(playerid, "You don't have a vehicle spawned.");
			
	new playerb, vehicleid = GetPlayerVehicleID(playerid);
			
	if(VehicleInfo[vehicleid][E_VEHICLE_OWNERDBID] != PlayerInfo[playerid][E_CHARACTER_DBID])
		return SendErrorMessage(playerid, "You don't own this vehicle."); 
			
	if(sscanf(params, "u", playerb))
		return SendUsageMessage(playerid, "/carkey [playerid OR name]"); 
			
	if(playerb == playerid)return SendErrorMessage(playerid, "You can't give yourself a duplicate key.");
			
	if(!IsPlayerConnected(playerb))
		return SendErrorMessage(playerid, "The player you specified isn't connected.");
			
	if(AccountInfo[playerb][E_MASTERS_LOGGED] == false)
		return SendErrorMessage(playerid, "The player you specified isn't logged in.");
			
	if(!IsPlayerNearPlayer(playerid, playerb, 5.0))
		return SendErrorMessage(playerid, "You aren't near that player."); 
			
	SendNearbyMessage(playerid, 20.0, COLOR_EMOTE, "* %s gives %s a key to their vehicle.", ReturnName(playerid), ReturnName(playerb));
	SendVehicleMessage(playerb, "[VEHICLE] %s gave you a key their vehicle.", ReturnName(playerid));
		
	SendVehicleMessage(playerid, "[VEHICLE] You gave %s a duplicatekey.", ReturnName(playerb));
		
	PlayerInfo[playerb][E_CHARACTER_DUPLICATEKEY] = vehicleid;
    return 1;
}

CMD:cardespawn(playerid, params[])
{
    if(!IsPlayerInAnyVehicle(playerid))
		return SendErrorMessage(playerid, "You aren't in any vehicle.");
			
	if(GetPlayerState(playerid) != PLAYER_STATE_DRIVER) return SendErrorMessage(playerid, "You need to be driving your vehicle.");

	new 
		vehicleid = GetPlayerVehicleID(playerid);
			
	if(VehicleInfo[vehicleid][E_VEHICLE_OWNERDBID] != PlayerInfo[playerid][E_CHARACTER_DBID])
		return SendErrorMessage(playerid, "You don't own this vehicle."); 
		
	if(!IsPlayerInRangeOfPoint(playerid, 5.0, VehicleInfo[vehicleid][E_VEHICLE_POS][0], VehicleInfo[vehicleid][E_VEHICLE_POS][1], VehicleInfo[vehicleid][E_VEHICLE_POS][2]))
	{
		SendVehicleMessage(playerid, "[VEHICLE] You have to be at your vehicle's parking place.");
		SendTipMessage(playerid, "Follow the marker to your parking.");
		
		GPS_SetPlayerRaceCheckPoint(playerid, 1, VehicleInfo[vehicleid][E_VEHICLE_POS][0], VehicleInfo[vehicleid][E_VEHICLE_POS][1], VehicleInfo[vehicleid][E_VEHICLE_POS][2], 0.0, 0.0, 0.0);
		return 1;
	}
		
	PlayerInfo[playerid][E_CHARACTER_VEHICLESPAWNED] = false; 
	PlayerInfo[playerid][E_CHARACTER_VEHICLESPAWN] = INVALID_VEHICLE_ID;

	new
		Float:vehicle_health;

	new Float:x, Float:y, Float:z, Float:a;

	GetVehicleHealth(vehicleid, vehicle_health); 
	GetVehiclePos(vehicleid, x, y, z);
	GetVehicleZAngle(vehicleid, a);

	VehicleInfo[vehicleid][E_VEHICLE_POS][0] = x;
	VehicleInfo[vehicleid][E_VEHICLE_POS][1] = y;
	VehicleInfo[vehicleid][E_VEHICLE_POS][2] = z;
	VehicleInfo[vehicleid][E_VEHICLE_POS][3] = a;
	VehicleInfo[vehicleid][E_VEHICLE_HEALTH] = vehicle_health;
	
	SendVehicleMessage(playerid, "[VEHICLE] You parked your %s.", ReturnVehicleName(vehicleid));
	SaveCharacter(playerid);
	ResetVehicleVars(vehicleid);
	DestroyVehicle(vehicleid); 
    return 1;
}

CMD:carscrap(playerid, params[])
{
    if(!IsPlayerInAnyVehicle(playerid))
		return SendErrorMessage(playerid, "You aren't in any vehicle.");

	if(!IsPlayerInRangeOfPoint(playerid, 5.0, 2412.9312,-1425.4226,23.9835)) return SendErrorMessage(playerid, "You aren't near vehicle scrapyard");
			
	if(GetPlayerState(playerid) != PLAYER_STATE_DRIVER) return SendErrorMessage(playerid, "You need to be driving your vehicle.");
			
	if(PlayerInfo[playerid][E_CHARACTER_VEHICLESPAWNED] == false) return SendErrorMessage(playerid, "You don't have a vehicle spawned.");
			
	new 
		str[160], 
		vehicleid = GetPlayerVehicleID(playerid),
		cash_back;
			
	if(VehicleInfo[vehicleid][E_VEHICLE_RENTAL])
		return SendErrorMessage(playerid, "You don't own this vehicle (rented)."); 

	if(VehicleInfo[vehicleid][E_VEHICLE_OWNERDBID] != PlayerInfo[playerid][E_CHARACTER_DBID])
		return SendErrorMessage(playerid, "You don't own this vehicle."); 
			
	for(new i = 0; i < sizeof(g_aDealershipData); i++)
	{
		if(g_aDealershipData[i][E_DEALERSHIP_MODELID] == VehicleInfo[vehicleid][E_VEHICLE_MODEL])
		{
			cash_back = g_aDealershipData[i][E_DEALERSHIP_PRICE] / 2; 
		}
	}
			
	format(str, sizeof(str), "Are you sure you want to scrap your %s?\nYou'll receive a cashback of: {33AA33}$%s{ffffff}\n\n{FF6347}This action is permanent and cannot be undone.", ReturnVehicleName(vehicleid), FormatMoney(cash_back)); 
	ConfirmDialog(playerid, "Confirmation", str, "OnVehicleScrap", VehicleInfo[vehicleid][E_VEHICLE_DBID], cash_back);
    return 1;
}

CMD:carlock(playerid, params[])
{
    new bool:foundCar = false, vehicleid, Float:fetchPos[3];
		
	for (new i = 0; i < MAX_VEHICLES; i++)
	{
		GetVehiclePos(i, fetchPos[0], fetchPos[1], fetchPos[2]);
		if(IsPlayerInRangeOfPoint(playerid, 4.0, fetchPos[0], fetchPos[1], fetchPos[2]))
		{
			foundCar = true;
			vehicleid = i; 
			break; 
		}
	}
		
	if(foundCar == true)
	{
		if(VehicleInfo[vehicleid][E_VEHICLE_OWNERDBID] != PlayerInfo[playerid][E_CHARACTER_DBID] && PlayerInfo[playerid][E_CHARACTER_DUPLICATEKEY] != vehicleid)
			return SendErrorMessage(playerid, "You don't have the keys to this vehicle."); 

		if(VehicleInfo[vehicleid][E_VEHICLE_IMPOUND])
			return SendErrorMessage(playerid, "Your vehicle is impounded.");

		new statusString[90], str[90]; 
		new engine, lights, alarm, doors, bonnet, boot, objective; 
	
		GetVehicleParamsEx(vehicleid, engine, lights, alarm, doors, bonnet, boot, objective);
			
		if(VehicleInfo[vehicleid][E_VEHICLE_LOCKED])
		{
			format(statusString, sizeof(statusString), "~g~%s Unlocked", ReturnVehicleName(vehicleid));
			SendClientMessageEx(playerid, COLOR_WHITE, "> %s {33AA33}Unlocked", ReturnVehicleName(vehicleid));
			SetVehicleParamsEx(vehicleid, engine, lights, alarm, false, bonnet, boot, objective);
			VehicleInfo[vehicleid][E_VEHICLE_LOCKED] = false;
			format(str, sizeof(str), "unlocks the %s", ReturnVehicleName(vehicleid));
			cmd_me(playerid, str);
		}
		else 
		{
			format(statusString, sizeof(statusString), "~r~%s Locked", ReturnVehicleName(vehicleid));	
			SendClientMessageEx(playerid, COLOR_WHITE, "> %s {FF6347}Locked", ReturnVehicleName(vehicleid));	
			SetVehicleParamsEx(vehicleid, engine, lights, alarm, true, bonnet, boot, objective);
			VehicleInfo[vehicleid][E_VEHICLE_LOCKED] = true;
			format(str, sizeof(str), "locks the %s", ReturnVehicleName(vehicleid));
			cmd_me(playerid, str);
		}

		ShowBoxMessage(playerid, statusString, 5);
	}
	else SendErrorMessage(playerid, "You aren't near a vehicle OR the vehicle isn't synced.");
    return 1;
}

CMD:lights(playerid, params[]) return cmd_carlights(playerid, params);
CMD:carlights(playerid, params[])
{
    new vehicleid = GetPlayerVehicleID(playerid);
		
	if(!IsPlayerInAnyVehicle(playerid))
		return SendErrorMessage(playerid, "You aren't in any vehicle.");
			
	if(GetPlayerState(playerid) != PLAYER_STATE_DRIVER) return SendErrorMessage(playerid, "You aren't driving a vehicle.");
		
	if(VehicleInfo[vehicleid][E_VEHICLE_LIGHTS] == false)
		ToggleVehicleLights(vehicleid, true);
			
	else ToggleVehicleLights(vehicleid, false);
    return 1;
}

CMD:cws(playerid, params[]) return cmd_carwindow(playerid, params);
CMD:window(playerid, params[]) return cmd_carwindow(playerid, params);
CMD:windows(playerid, params[]) return cmd_carwindow(playerid, params);
CMD:rollwindow(playerid, params[]) return cmd_carwindow(playerid, params);
CMD:rollwindows(playerid, params[]) return cmd_carwindow(playerid, params);
CMD:carwindows(playerid, params[]) return cmd_carwindow(playerid, params);
CMD:carwindow(playerid, params[])
{
    if(!IsPlayerInAnyVehicle(playerid))
		return SendErrorMessage(playerid, "You aren't in any vehicle.");

    new vehicleid = GetPlayerVehicleID(playerid);

    if (!IsWindowedVehicle(vehicleid))
        return SendErrorMessage(playerid, "You are not in any vehicle with windows.");

    if (sscanf(params, "d", params[0]))
    {
        SendUsageMessage(playerid, "/(car/roll)window(s) [0, 1-2-3-4]");
        SendTipMessage(playerid, "0 - All | 1 - Driver window | 2 - Passenger window | 3 - Rear-left window | 4 - Rear-right window");
        return 1;
    }

    if (params[0] > 4 || params[0] < 0)
        return SendClientMessage(playerid, -1, "0 - All | 1 - Driver window | 2 - Passenger window | 3 - Rear-left window | 4 - Rear-right window");

    new driver, passenger, backleft, backright;
    GetVehicleParamsCarWindows(vehicleid, driver, passenger, backleft, backright);

    switch (params[0])
    {
        case 0:
        {
            if (VehicleInfo[vehicleid][E_VEHICLE_WINDOWS])
            {
                VehicleInfo[vehicleid][E_VEHICLE_WINDOWS] = false;
                driver = 0;
                passenger = 0;
                backleft = 0;
                backright = 0;
            }
            else
            {
                driver = 1;
                passenger = 1;
                backleft = 1;
                backright = 1;
                VehicleInfo[vehicleid][E_VEHICLE_WINDOWS] = true;
            }
            return 1;
        }

        case 1: driver = !driver;
        case 2: passenger = !passenger;
        case 3: backleft = !backleft;
        case 4: backright = !backright;
    }

    switch (params[0])
    {
        case 0:
        {
            if (VehicleInfo[vehicleid][E_VEHICLE_WINDOWS])
            {
				new str[128];
				format(str, sizeof(str), "rolls up the windows of the %s.", ReturnVehicleName(vehicleid));
                cmd_me(playerid, str);
            }
            else
            {
                new str[128];
				format(str, sizeof(str), "rolls downs the windows of the %s.", ReturnVehicleName(vehicleid));
                cmd_me(playerid, str);
            }
        }

        case 1:
        {
			new str[128];
			format(str, sizeof(str), "rolls %s the front-left window of the %s.", driver ? "up" : "down", ReturnVehicleName(vehicleid));
            cmd_me(playerid, str);
        }

        case 2:
        {
            new str[128];
			format(str, sizeof(str), "rolls %s the front-right window of the %s.", driver ? "up" : "down", ReturnVehicleName(vehicleid));
            cmd_me(playerid, str);
        }

        case 3:
        {
            new str[128];
			format(str, sizeof(str), "rolls %s the rear-left window of the %s.", driver ? "up" : "down", ReturnVehicleName(vehicleid));
            cmd_me(playerid, str);
        }

        case 4:
        {
            new str[128];
			format(str, sizeof(str), "rolls %s the front-right window of the %s.", driver ? "up" : "down", ReturnVehicleName(vehicleid));
            cmd_me(playerid, str);
        }
    }

    if (driver == 0 || passenger == 0 || backleft == 0 || backright == 0)
    {
        VehicleInfo[vehicleid][E_VEHICLE_WINDOWS] = false;
    }
    else if (driver == 1 && passenger == 1 && backleft == 1 && backright == 1)
    {
        VehicleInfo[vehicleid][E_VEHICLE_WINDOWS] = true;
    }

    SetVehicleParamsCarWindows(vehicleid, driver, passenger, backleft, backright);
    return 1;
}

CMD:cartrunk(playerid, params[])
{
    new
		Float:x,
		Float:y,
		Float:z;
		
	new engine, lights, alarm, doors, bonnet, boot, objective;
	
	if(!IsPlayerInAnyVehicle(playerid) && IsPlayerNearVehicle(playerid) != INVALID_VEHICLE_ID)
	{
		GetVehicleBoot(IsPlayerNearVehicle(playerid), x, y, z); 
			
		new 
			vehicleid = IsPlayerNearVehicle(playerid);
				
		if(VehicleInfo[vehicleid][E_VEHICLE_LOCKED])
			return SendErrorMessage(playerid, "This vehicle is locked."); 
			
		if(!IsPlayerInRangeOfPoint(playerid, 2.5, x, y, z))
			return SendErrorMessage(playerid, "You aren't near the vehicles trunk.");
			
		GetVehicleParamsEx(vehicleid, engine, lights, alarm, doors, bonnet, boot, objective);
			
		if(!boot)
		{
			SetVehicleParamsEx(vehicleid, engine, lights, alarm, doors, bonnet, 1, objective);
				
			SendClientMessageEx(playerid, COLOR_WHITE, "> Trunk {33AA33}Opened");	
			ShowVehicleStorage(playerid, IsPlayerNearVehicle(playerid));
		}
		else
		{
			SetVehicleParamsEx(vehicleid, engine, lights, alarm, doors, bonnet, 0, objective);	
			SendClientMessageEx(playerid, COLOR_WHITE, "> Trunk {FF6347}Closed");	
		}
	}
	else if(IsPlayerInAnyVehicle(playerid))
	{
		new
			vehicleid = GetPlayerVehicleID(playerid);
			
		if(GetPlayerState(playerid) != PLAYER_STATE_DRIVER)
			return SendErrorMessage(playerid, "You aren't in the driver's seat.");
			
		if(PlayerInfo[playerid][E_CHARACTER_DBID] != VehicleInfo[vehicleid][E_VEHICLE_OWNERDBID] && PlayerInfo[playerid][E_CHARACTER_DUPLICATEKEY] != vehicleid)
			return SendErrorMessage(playerid, "You don't have the keys to this vehicle."); 
				
		GetVehicleParamsEx(vehicleid, engine, lights, alarm, doors, bonnet, boot, objective);
			
		if(!boot)
		{
			SetVehicleParamsEx(vehicleid, engine, lights, alarm, doors, bonnet, 1, objective);	
			SendClientMessageEx(playerid, COLOR_WHITE, "> Trunk {33AA33}Opened");	
		}
		else
		{
			SetVehicleParamsEx(vehicleid, engine, lights, alarm, doors, bonnet, 0, objective);
			SendClientMessageEx(playerid, COLOR_WHITE, "> Trunk {FF6347}Closed");	
		}
	}
    return 1;
}

CMD:carhood(playerid, params[])
{
    new
		Float:x,
		Float:y,
		Float:z;
		
	new engine, lights, alarm, doors, bonnet, boot, objective;
	
	if(!IsPlayerInAnyVehicle(playerid) && IsPlayerNearVehicle(playerid) != INVALID_VEHICLE_ID)
	{
		GetVehicleHood(IsPlayerNearVehicle(playerid), x, y, z); 
			
		new 
			vehicleid = IsPlayerNearVehicle(playerid);
				
		if(VehicleInfo[vehicleid][E_VEHICLE_LOCKED])
			return SendErrorMessage(playerid, "This vehicle is locked."); 
			
		if(!IsPlayerInRangeOfPoint(playerid, 2.5, x, y, z))
			return SendErrorMessage(playerid, "You aren't near the vehicles hood.");
			
		GetVehicleParamsEx(vehicleid, engine, lights, alarm, doors, bonnet, boot, objective);
			
		if(!bonnet)
		{
			SetVehicleParamsEx(vehicleid, engine, lights, alarm, doors, 1, boot, objective);
			SendClientMessageEx(playerid, COLOR_WHITE, "> Hood {33AA33}Opened");	
		}
		else
		{
			SetVehicleParamsEx(vehicleid, engine, lights, alarm, doors, 0, boot, objective);
			SendClientMessageEx(playerid, COLOR_WHITE, "> Hood {FF6347}Closed");
		}
	}
	else if(IsPlayerInAnyVehicle(playerid))
	{
		new
			vehicleid = GetPlayerVehicleID(playerid);
			
		if(PlayerInfo[playerid][E_CHARACTER_DBID] != VehicleInfo[vehicleid][E_VEHICLE_OWNERDBID] && PlayerInfo[playerid][E_CHARACTER_DUPLICATEKEY] != vehicleid)
			return SendErrorMessage(playerid, "You don't have the keys to this vehicle."); 
				
		if(GetPlayerState(playerid) != PLAYER_STATE_DRIVER)
			return SendErrorMessage(playerid, "You aren't in the driver's seat.");
				
		GetVehicleParamsEx(vehicleid, engine, lights, alarm, doors, bonnet, boot, objective);
			
		if(!bonnet)
		{
			SetVehicleParamsEx(vehicleid, engine, lights, alarm, doors, 1, boot, objective);
			SendClientMessageEx(playerid, COLOR_WHITE, "> Hood {33AA33}Opened");	
		}
		else
		{
			SetVehicleParamsEx(vehicleid, engine, lights, alarm, doors, 0, boot, objective);
			SendClientMessageEx(playerid, COLOR_WHITE, "> Hood {FF6347}Closed");
		}
	}
	else return SendErrorMessage(playerid, "You aren't in or near a vehicle.");
    return 1;
}

CMD:mv(playerid, params[]) return cmd_mycars(playerid, params);
CMD:mycars(playerid, params[])
{
    if(!CountPlayerVehicles(playerid))
		return SendErrorMessage(playerid, "You don't own any vehicles.");
			
	ShowVehicleList(playerid); 
	return 1;
}

CMD:carradio(playerid, params[])
{
    if(!IsPlayerInAnyVehicle(playerid))
		return SendErrorMessage(playerid, "You are not in any vehicle.");

	if (!IsEngineVehicle(GetPlayerVehicleID(playerid)))
		return SendErrorMessage(playerid, "You are not in any vehicle.");
		
	Dialog_Show(playerid, DialogRadio, DIALOG_STYLE_LIST, "Radio:", "Add URL\nTurn Off", "Select", "Close");
    return 1;
}

CMD:en(playerid, params[]) return cmd_engine(playerid, params);
CMD:carengine(playerid, params[]) return cmd_engine(playerid, params);
CMD:engine(playerid, params[])
{
	if(GetPlayerState(playerid) != PLAYER_STATE_DRIVER)
		return SendErrorMessage(playerid, "You aren't in the driver's seat of a vehicle."); 
		
	new vehicleid = GetPlayerVehicleID(playerid), str[90];
	
	if (!IsEngineVehicle(vehicleid))
		return SendErrorMessage(playerid, "You are not in any vehicle.");

	if(VehicleInfo[vehicleid][E_VEHICLE_IMPOUND])
		return SendErrorMessage(playerid, "Your vehicle is impounded.");

	if(IsPlayerAdmins(playerid) < ADMINS_HELPERS)
	{
		if(VehicleInfo[vehicleid][E_VEHICLE_TYPE] == VEHICLE_TYPE_PLAYER)
		{
			if(VehicleInfo[vehicleid][E_VEHICLE_OWNERDBID] != PlayerInfo[playerid][E_CHARACTER_DBID] && VehicleInfo[vehicleid][E_VEHICLE_OWNERDBID] != PlayerInfo[playerid][E_CHARACTER_DUPLICATEKEY])
				return SendErrorMessage(playerid, "You don't own this vehicles.");	

			if(PlayerEngineTimer[playerid])
				return ShowBoxMessage(playerid, "Please wait....", 5);

			if (ReturnVehicleHealth(vehicleid) > 400)
			{
				if(VehicleInfo[vehicleid][E_VEHICLE_FUEL] < 1 && !VehicleInfo[vehicleid][E_VEHICLE_ADMIN])
					return SendClientMessage(playerid, COLOR_RED, "Vehicle is out of fuel!"); 
				
				if(!VehicleInfo[vehicleid][E_VEHICLE_ENGINE])
				{	ShowBoxMessage(playerid, "~g~Turn on engine.", 5);
					PlayerEngineValue[playerid] = 0;
					PlayerEngineTimer[playerid] = SetTimerEx("TurnEngine", 500, true, "dd", playerid, vehicleid);
					format(str, sizeof(str), "twists the key turning the engine of the %s on", ReturnVehicleName(vehicleid));
					cmd_me(playerid, str);
				}
				else
				{
					SendClientMessageEx(playerid, COLOR_WHITE, "> Engine {FF6347}Stopped");	
					ToggleVehicleEngine(vehicleid, false); VehicleInfo[vehicleid][E_VEHICLE_ENGINE] = false;
					format(str, sizeof(str), "twists the key turning the engine of the %s off", ReturnVehicleName(vehicleid));
					cmd_me(playerid, str);
				}
			}
			else ShowBoxMessage(playerid, "This vehicle is ~r~totalled~w~ and needs repairing.", 3);
		}
		else if(VehicleInfo[vehicleid][E_VEHICLE_TYPE] == VEHICLE_TYPE_JOBS)
		{
			if(PlayerEngineTimer[playerid])
				return ShowBoxMessage(playerid, "Please wait....", 5);

			if (ReturnVehicleHealth(vehicleid) > 400)
			{
				if(VehicleInfo[vehicleid][E_VEHICLE_FUEL] < 1 && !VehicleInfo[vehicleid][E_VEHICLE_ADMIN])
					return SendClientMessage(playerid, COLOR_RED, "Vehicle is out of fuel!"); 
				
				if(!VehicleInfo[vehicleid][E_VEHICLE_ENGINE])
				{	ShowBoxMessage(playerid, "~g~Turn on engine.", 5);
					PlayerEngineValue[playerid] = 0;
					PlayerEngineTimer[playerid] = SetTimerEx("TurnEngine", 500, true, "dd", playerid, vehicleid);
					format(str, sizeof(str), "twists the key turning the engine of the %s on", ReturnVehicleName(vehicleid));
					cmd_me(playerid, str);
				}
				else
				{
					SendClientMessageEx(playerid, COLOR_WHITE, "> Engine {FF6347}Stopped");	
					ToggleVehicleEngine(vehicleid, false); VehicleInfo[vehicleid][E_VEHICLE_ENGINE] = false;
					format(str, sizeof(str), "twists the key turning the engine of the %s off", ReturnVehicleName(vehicleid));
					cmd_me(playerid, str);
				}
			}
			else ShowBoxMessage(playerid, "This vehicle is ~r~totalled~w~ and needs repairing.", 3);
		}
		else
		{
			if(PlayerEngineTimer[playerid])
				return ShowBoxMessage(playerid, "Please wait....", 5);

			if (ReturnVehicleHealth(vehicleid) > 400)
			{
				if(VehicleInfo[vehicleid][E_VEHICLE_FUEL] < 1 && !VehicleInfo[vehicleid][E_VEHICLE_ADMIN])
					return SendClientMessage(playerid, COLOR_RED, "Vehicle is out of fuel!"); 
				
				if(!VehicleInfo[vehicleid][E_VEHICLE_ENGINE])
				{	ShowBoxMessage(playerid, "~g~Turn on engine.", 5);
					PlayerEngineValue[playerid] = 0;
					PlayerEngineTimer[playerid] = SetTimerEx("TurnEngine", 500, true, "dd", playerid, vehicleid);
					format(str, sizeof(str), "twists the key turning the engine of the %s on", ReturnVehicleName(vehicleid));
					cmd_me(playerid, str);
				}
				else
				{
					SendClientMessageEx(playerid, COLOR_WHITE, "> Engine {FF6347}Stopped");	
					ToggleVehicleEngine(vehicleid, false); VehicleInfo[vehicleid][E_VEHICLE_ENGINE] = false;
					format(str, sizeof(str), "twists the key turning the engine of the %s off", ReturnVehicleName(vehicleid));
					cmd_me(playerid, str);
				}
			}
			else ShowBoxMessage(playerid, "This vehicle is ~r~totalled~w~ and needs repairing.", 3);
		}
	}
	else
	{
		if(PlayerEngineTimer[playerid])
			return ShowBoxMessage(playerid, "Please wait....", 5);

		if (ReturnVehicleHealth(vehicleid) > 400)
		{
			if(VehicleInfo[vehicleid][E_VEHICLE_FUEL] < 1 && !VehicleInfo[vehicleid][E_VEHICLE_ADMIN])
				return SendClientMessage(playerid, COLOR_RED, "Vehicle is out of fuel!"); 
			
			if(!VehicleInfo[vehicleid][E_VEHICLE_ENGINE])
			{	ShowBoxMessage(playerid, "~g~Turn on engine.", 5);
				PlayerEngineValue[playerid] = 0;
				PlayerEngineTimer[playerid] = SetTimerEx("TurnEngine", 500, true, "dd", playerid, vehicleid);
				format(str, sizeof(str), "twists the key turning the engine of the %s on", ReturnVehicleName(vehicleid));
				cmd_me(playerid, str);
			}
			else
			{
				SendClientMessageEx(playerid, COLOR_WHITE, "> Engine {FF6347}Stopped");	
				ToggleVehicleEngine(vehicleid, false); VehicleInfo[vehicleid][E_VEHICLE_ENGINE] = false;
				format(str, sizeof(str), "twists the key turning the engine of the %s off", ReturnVehicleName(vehicleid));
				cmd_me(playerid, str);
			}
		}
		else ShowBoxMessage(playerid, "This vehicle is ~r~totalled~w~ and needs repairing.", 3);
	}
	return 1;
}

function:TurnEngine(playerid, vehicleid)
{
	new message[32];
	PlayerEngineValue[playerid]++;
	switch(PlayerEngineValue[playerid])
	{
		case 1: format(message, sizeof(message), "~g~Turn on engine.");
		case 2: format(message, sizeof(message), "~g~Turn on engine..");
		case 3: format(message, sizeof(message), "~g~Turn on engine...");
		case 4: format(message, sizeof(message), "~g~Turn on engine....");
		case 5:
		{
			SendClientMessageEx(playerid, COLOR_WHITE, "> Engine {33AA33}Started");
			ToggleVehicleEngine(vehicleid, true); VehicleInfo[vehicleid][E_VEHICLE_ENGINE] = true;
			KillTimer(PlayerEngineTimer[playerid]);
			PlayerEngineTimer[playerid] = 0;
			PlayerEngineValue[playerid] = 0;
		}
	}

	ShowBoxMessage(playerid, message, 5);
	return 1;
}

CMD:gascan(playerid, params[])
{
	if(PlayerInfo[playerid][E_CHARACTER_EQUIPITEMS] != GASCAN)
		return SendErrorMessage(playerid, "You must hold the gascan in your hands.");

	if(!Inventory_Count(playerid, "Gascan"))
		return SendErrorMessage(playerid, "You don't have any gascan in your inventory."); 

	if(IsPlayerInAnyVehicle(playerid))
		return SendErrorMessage(playerid, "You can't be in a vehicle.");
			
	if(IsPlayerNearVehicle(playerid) == INVALID_VEHICLE_ID)
		return SendErrorMessage(playerid, "You aren't near a vehicle."); 
			
	if(playerRefillingVehicle[playerid])
		return SendErrorMessage(playerid, "You're already refilling a vehicle."); 
			
	new vehicleid = IsPlayerNearVehicle(playerid), Float:vx, Float:vy, Float:vz;

		
	GetVehicleModelInfo(GetVehicleModel(vehicleid), VEHICLE_MODEL_INFO_PETROLCAP, vx, vy, vz); 
	GetVehiclePos(vehicleid, vx, vy, vz);
		
	GetPlayerPos(playerid, PlayerInfo[playerid][E_CHARACTER_LASTPOS][0], PlayerInfo[playerid][E_CHARACTER_LASTPOS][1], PlayerInfo[playerid][E_CHARACTER_LASTPOS][2]); 
				
	if(!IsPlayerInRangeOfPoint(playerid, 5.0, vx, vy, vz))
		return SendErrorMessage(playerid, "You aren't near the vehicles gas cap.");
			
	if(VehicleInfo[vehicleid][E_VEHICLE_FUEL] > 50)
		return SendErrorMessage(playerid, "This vehicle doesn't need fuel."); 
			
	SendServerMessage(playerid, "You're starting to refill the vehicle.");
	SendServerMessage(playerid, "If you, or the vehicle moves then this process will be interrupted."); 
		
	VehicleInfo[vehicleid][E_VEHICLE_REFILLDISPLAY] = Create3DTextLabel("Loading refilling fuel process\n(( |------ ))", COLOR_3DTEXT, vx, vy, vz, 25.0, 0, 1);
	Attach3DTextLabelToVehicle(VehicleInfo[vehicleid][E_VEHICLE_REFILLDISPLAY], vehicleid, -0.0, -0.0, -0.0); 

	VehicleInfo[vehicleid][E_VEHICLE_REFILLCOUNT] = 1;
		
	playerRefillingVehicle[playerid] = true; 
	playerRefillTimer[playerid] = SetTimerEx("OnGascanRefill", 1000, true, "iifff", playerid, vehicleid, vx, vy, vz);
	return 1;
}

CMD:refill(playerid, params[]) return cmd_refuel(playerid, params);
CMD:refuel(playerid, params[])
{
	new vehicleid = IsPlayerNearVehicle(playerid), Float:vx, Float:vy, Float:vz;

	if(IsPlayerInAnyVehicle(playerid))
		return SendErrorMessage(playerid, "You aren't near any vehicle.");

	if(VehicleInfo[vehicleid][E_VEHICLE_ENGINE])
		return SendErrorMessage(playerid, "You must turn off vehicle engine.");

	GetVehicleModelInfo(GetVehicleModel(vehicleid), VEHICLE_MODEL_INFO_PETROLCAP, vx, vy, vz); 
	GetVehiclePos(vehicleid, vx, vy, vz);
		
	GetPlayerPos(playerid, PlayerInfo[playerid][E_CHARACTER_LASTPOS][0], PlayerInfo[playerid][E_CHARACTER_LASTPOS][1], PlayerInfo[playerid][E_CHARACTER_LASTPOS][2]); 
				
	if(!IsPlayerInRangeOfPoint(playerid, 3.0, vx, vy, vz) && !IsPlayerNearGasStation(playerid))
		return SendErrorMessage(playerid, "You aren't near the vehicles gas cap or gas station.");
			
	if(VehicleInfo[vehicleid][E_VEHICLE_FUEL] > 90)
		return SendErrorMessage(playerid, "This vehicle doesn't need fuel."); 
			
	for(new i; i < 23; i++)
	{
		PlayerTextDrawShow(playerid, fuel[i][playerid]);
	}
	TogglePlayerControllable(playerid, false);
	SelectTextDraw(playerid, COLOR_YELLOW);
	return 1;
}

CMD:speedlimit(playerid, params[]) return cmd_limitspeed(playerid, params);
CMD:carlimit(playerid, params[]) return cmd_limitspeed(playerid, params);
CMD:limitspeed(playerid, params[])
{
	new limit;
	if (sscanf(params, "d", limit))
		return SendUsageMessage(playerid, "/limitspeed [speed]");

	if (limit < 20 || limit > 200)
		return SendErrorMessage(playerid, "You vehicle speed limit cannot be less than 20 or more than 200.");

	PlayerSpeedLimit[playerid] = limit;

	SendVehicleMessage(playerid, "[VEHICLE] You has set your vehicle speedlimit to %d/MPH.", limit);
	return 1;
}