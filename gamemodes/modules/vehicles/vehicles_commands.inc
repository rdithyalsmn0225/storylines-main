//car commands:
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
			
	SendNearbyMessage(playerid, 20.0, COLOR_EMOTE, "* %s gives %s a key to their vehicle.", ReturnSettingsName(playerid, playerid), ReturnSettingsName(playerb, playerid));
	SendServerMessage(playerb, "%s gave you a key to their vehicle.", ReturnSettingsName(playerid, playerid));
		
	GiveMoney(playerid, -500);
	SendClientMessageEx(playerid, COLOR_VEHICLE, "[Vehicle]:{d7d7d7} You gave %s a duplicatekey for $500.", ReturnSettingsName(playerb, playerid));
		
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
		SendServerMessage(playerid, "You have to be at your vehicle's parking place.");
		SendClientMessage(playerid, COLOR_WHITE, "Follow the marker to your parking.");
		
		GPS_SetPlayerRaceCheckPoint(playerid, 1, VehicleInfo[vehicleid][E_VEHICLE_POS][0], VehicleInfo[vehicleid][E_VEHICLE_POS][1], VehicleInfo[vehicleid][E_VEHICLE_POS][2], 0.0, 0.0, 0.0);
		return 1;
	}
		
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
	SaveVehicle(vehicleid);

	PlayerInfo[playerid][E_CHARACTER_VEHICLESPAWNED] = false; 
	PlayerInfo[playerid][E_CHARACTER_VEHICLESPAWN] = INVALID_VEHICLE_ID;
		
	SendClientMessageEx(playerid, COLOR_VEHICLE, "[Vehicle]:{d7d7d7} You parked your %s.", ReturnVehicleName(vehicleid));
		
	SaveVehicle(vehicleid);
		
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
			
	if(VehicleInfo[vehicleid][E_VEHICLE_OWNERDBID] != PlayerInfo[playerid][E_CHARACTER_DBID])
		return SendErrorMessage(playerid, "You don't own this vehicle."); 
			
	for(new i = 0; i < sizeof(g_aDealershipData); i++)
	{
		if(g_aDealershipData[i][E_DEALERSHIP_MODELID] == VehicleInfo[vehicleid][E_VEHICLE_MODEL])
		{
			cash_back = g_aDealershipData[i][E_DEALERSHIP_PRICE] / 2; 
		}
	}
			
	format(str, sizeof(str), "Are you sure you want to scrap your %s?\nYou'll receive a cashback of: $%s\n\n{FF6347}This action is permanent and cannot be undone.", ReturnVehicleName(vehicleid), FormatMoney(cash_back)); 
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

		new statusString[90]; 
		new engine, lights, alarm, doors, bonnet, boot, objective; 
	
		GetVehicleParamsEx(vehicleid, engine, lights, alarm, doors, bonnet, boot, objective);
			
		if(VehicleInfo[vehicleid][E_VEHICLE_LOCKED])
		{
			format(statusString, sizeof(statusString), "~g~%s UNLOCKED", ReturnVehicleName(vehicleid));
			
			SetVehicleParamsEx(vehicleid, engine, lights, alarm, false, bonnet, boot, objective);
			VehicleInfo[vehicleid][E_VEHICLE_LOCKED] = false;
		}
		else 
		{
			format(statusString, sizeof(statusString), "~r~%s LOCKED", ReturnVehicleName(vehicleid));		
			SetVehicleParamsEx(vehicleid, engine, lights, alarm, true, bonnet, boot, objective);
			VehicleInfo[vehicleid][E_VEHICLE_LOCKED] = true;
		}
		GameTextForPlayer(playerid, statusString, 3000, 3);
	}
	else SendErrorMessage(playerid, "You aren't near a vehicle OR the vehicle isn't synced.");
    return 1;
}

CMD:carlights(playerid, params[])
{
    new vehicleid = GetPlayerVehicleID(playerid);
		
	if(!IsPlayerInAnyVehicle(playerid))
		return SendErrorMessage(playerid, "You aren't in any vehicle.");
			
	if(GetPlayerState(playerid) != PLAYER_STATE_DRIVER) return SendErrorMessage(playerid, "You aren't driving a vehicle.");
		
	if(VehicleInfo[vehicleid][E_VEHICLE_LIGHTS] == false)
		TogglE_VEHICLE_LIGHTS(vehicleid, true);
			
	else TogglE_VEHICLE_LIGHTS(vehicleid, false);
    return 1;
}

CMD:carfind(playerid, params[])
{
    if(PlayerInfo[playerid][E_CHARACTER_VEHICLESPAWNED] == false) 
		return SendErrorMessage(playerid, "You don't have a vehicle spawned.");
			
	if(IsVehicleOccupied(PlayerInfo[playerid][E_CHARACTER_VEHICLESPAWN]))
		return SendErrorMessage(playerid, "Your vehicle is in use / stolen.");
			
	new 
		Float:fetchPos[3];
		
	GetVehiclePos(PlayerInfo[playerid][E_CHARACTER_VEHICLESPAWN], fetchPos[0], fetchPos[1], fetchPos[2]);
	GPS_SetPlayerRaceCheckPoint(playerid, 1, fetchPos[0], fetchPos[1], fetchPos[2], 0.0, 0.0, 0.0);
    return 1;
}

CMD:cartrunk(playerid, params[])
{
    new
		Float:x,
		Float:y,
		Float:z;
		
	new engine, lights, alarm, doors, bonnet, boot, objective;
	
	if(!IsPlayerInAnyVehicle(playerid) && GetNearestVehicle(playerid) != INVALID_VEHICLE_ID)
	{
		GetVehicleBoot(GetNearestVehicle(playerid), x, y, z); 
			
		new 
			vehicleid = GetNearestVehicle(playerid);
				
		if(VehicleInfo[vehicleid][E_VEHICLE_LOCKED])
			return SendErrorMessage(playerid, "This vehicle is locked."); 
			
		if(!IsPlayerInRangeOfPoint(playerid, 2.5, x, y, z))
			return SendErrorMessage(playerid, "You aren't near the vehicles trunk.");
			
		GetVehicleParamsEx(vehicleid, engine, lights, alarm, doors, bonnet, boot, objective);
			
		if(!boot)
		{
			SetVehicleParamsEx(vehicleid, engine, lights, alarm, doors, bonnet, 1, objective);
				
			SendClientMessageEx(playerid, COLOR_VEHICLE, "[Vehicle]:{d7d7d7} You have opened the trunk.");
			ShowVehicleStorage(playerid, GetNearestVehicle(playerid));
		}
		else
		{
				SetVehicleParamsEx(vehicleid, engine, lights, alarm, doors, bonnet, 0, objective);	
				SendClientMessageEx(playerid, COLOR_VEHICLE, "[Vehicle]:{d7d7d7} You have closed the trunk.");
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
			SendClientMessageEx(playerid, COLOR_VEHICLE, "[Vehicle]:{d7d7d7} You have opened the trunk.");
		}
		else
		{
			SetVehicleParamsEx(vehicleid, engine, lights, alarm, doors, bonnet, 0, objective);
			SendClientMessageEx(playerid, COLOR_VEHICLE, "[Vehicle]:{d7d7d7} You have closed the trunk.");
		}
	}
	else return SendErrorMessage(playerid, "You aren't in or near a vehicle.");
    return 1;
}

CMD:carhood(playerid, params[])
{
    new
		Float:x,
		Float:y,
		Float:z;
		
	new engine, lights, alarm, doors, bonnet, boot, objective;
	
	if(!IsPlayerInAnyVehicle(playerid) && GetNearestVehicle(playerid) != INVALID_VEHICLE_ID)
	{
		GetVehicleHood(GetNearestVehicle(playerid), x, y, z); 
			
		new 
			vehicleid = GetNearestVehicle(playerid);
				
		if(VehicleInfo[vehicleid][E_VEHICLE_LOCKED])
			return SendErrorMessage(playerid, "This vehicle is locked."); 
			
		if(!IsPlayerInRangeOfPoint(playerid, 2.5, x, y, z))
			return SendErrorMessage(playerid, "You aren't near the vehicles hood.");
			
		GetVehicleParamsEx(vehicleid, engine, lights, alarm, doors, bonnet, boot, objective);
			
		if(!bonnet)
		{
			SetVehicleParamsEx(vehicleid, engine, lights, alarm, doors, 1, boot, objective);
			SendClientMessageEx(playerid, COLOR_VEHICLE, "[Vehicle]:{d7d7d7} You have opened the hood.");
		}
		else
		{
			SetVehicleParamsEx(vehicleid, engine, lights, alarm, doors, 0, boot, objective);
			SendClientMessageEx(playerid, COLOR_VEHICLE, "[Vehicle]:{d7d7d7} You have closed the hood.");
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
			SendClientMessageEx(playerid, COLOR_VEHICLE, "[Vehicle]:{d7d7d7} You have opened the hood.");
		}
		else
		{
			SetVehicleParamsEx(vehicleid, engine, lights, alarm, doors, 0, boot, objective);
			SendClientMessageEx(playerid, COLOR_VEHICLE, "[Vehicle]:{d7d7d7} You have closed the hood.");
		}
	}
	else return SendErrorMessage(playerid, "You aren't in or near a vehicle.");
    return 1;
}

CMD:carlist(playerid, params[])
{
    if(CountPlayerVehicles(playerid) == 0)
		return SendErrorMessage(playerid, "You don't own any vehicles.");
			
	return ShowVehicleList(playerid); 
}

CMD:carradio(playerid, params[])
{
    if(!IsPlayerInAnyVehicle(playerid))
		return SendErrorMessage(playerid, "You are not in any vehicle.");

	if (!IsEngineVehicle(GetPlayerVehicleID(playerid)))
		return SendErrorMessage(playerid, "You are not in any vehicle.");
		
	ShowPlayerDialog(playerid, DIALOG_RADIO, DIALOG_STYLE_LIST, "Radio:", "Add URL\nTurn Off", "Select", "Close");
    return 1;
}

CMD:engine(playerid, params[])
{
	if(GetPlayerState(playerid) != PLAYER_STATE_DRIVER)
		return SendErrorMessage(playerid, "You aren't in the driver's seat of a vehicle."); 
		
	new vehicleid = GetPlayerVehicleID(playerid);
	
	if (!IsEngineVehicle(vehicleid))
		return SendErrorMessage(playerid, "You are not in any vehicle.");

	if(VehicleInfo[vehicleid][E_VEHICLE_IMPOUND])
		return SendErrorMessage(playerid, "Your vehicle is impounded.");

	if (ReturnVehicleHealth(vehicleid) > 400)
	{
		if(VehicleInfo[vehicleid][E_VEHICLE_FUEL] < 1 && !VehicleInfo[vehicleid][E_VEHICLE_ADMIN])
			return SendClientMessage(playerid, COLOR_RED, "Vehicle is out of fuel!"); 
		
		if(!VehicleInfo[vehicleid][E_VEHICLE_ENGINE])
		{
			SendNearbyMessage(playerid, 20.0, COLOR_EMOTE, "* %s started the engine of the %s.", ReturnSettingsName(playerid, playerid), ReturnVehicleName(vehicleid)); 
			SetTimerEx("TurnEngine", 2000, false, "d", vehicleid);
		}
		else
		{
			SendNearbyMessage(playerid, 20.0, COLOR_EMOTE, "* %s stopped the engine of the %s.", ReturnSettingsName(playerid, playerid), ReturnVehicleName(vehicleid)); 
			ToggleVehicleEngine(vehicleid, false); VehicleInfo[vehicleid][E_VEHICLE_ENGINE] = false;
		}
	}
	else ShowBoxMessage(playerid, "This vehicle is ~r~totalled~w~ and needs repairing.", 3);
	return 1;
}