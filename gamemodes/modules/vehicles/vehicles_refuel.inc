function:OnGascanRefill(playerid, vehicleid, x, y, z)
{
	new 
		text[128]
	;
	if(GetVehicleDistanceFromPoint(vehicleid, x, y, z) > 5)
	{
		SendErrorMessage(playerid, "The vehicle you were refilling moved and canceled."); 
		
		KillTimer(playerRefillTimer[playerid]);
		playerRefillingVehicle[playerid] = false; 
		
		Delete3DTextLabel(VehicleInfo[vehicleid][E_VEHICLE_REFILLDISPLAY]); 
		VehicleInfo[vehicleid][E_VEHICLE_REFILLCOUNT] = 0; 
		return 1;
	}
	
	if(!IsPlayerInRangeOfPoint(playerid, 2.0, PlayerInfo[playerid][E_CHARACTER_LASTPOS][0], PlayerInfo[playerid][E_CHARACTER_LASTPOS][1], PlayerInfo[playerid][E_CHARACTER_LASTPOS][2]))
	{
		SendErrorMessage(playerid, "You moved and stopped refilling the vehicle."); 
		
		KillTimer(playerRefillTimer[playerid]);
		playerRefillingVehicle[playerid] = false; 
		
		Delete3DTextLabel(VehicleInfo[vehicleid][E_VEHICLE_REFILLDISPLAY]); 
		VehicleInfo[vehicleid][E_VEHICLE_REFILLCOUNT] = 0; 
		return 1;
	}
	VehicleInfo[vehicleid][E_VEHICLE_REFILLCOUNT] ++;
	
	switch(VehicleInfo[vehicleid][E_VEHICLE_REFILLCOUNT])
	{
		case 2: text = "Loading refilling fuel process\n(( ||----- ))";
		case 3: text = "Loading refilling fuel process\n(( |||---- ))";
		case 4: text = "Loading refilling fuel process\n(( ||||--- ))";
		case 5: text = "Loading refilling fuel process\n(( |||||-- ))";
		case 6: text = "Loading refilling fuel process\n(( ||||||- ))";
		case 7: text = "Loading refilling fuel process\n(( ||||||| ))";
		case 8:
		{
			KillTimer(playerRefillTimer[playerid]);
			playerRefillingVehicle[playerid] = false; 
			
			Delete3DTextLabel(VehicleInfo[vehicleid][E_VEHICLE_REFILLDISPLAY]); 
			VehicleInfo[vehicleid][E_VEHICLE_REFILLCOUNT] = 0; 
			
			VehicleInfo[vehicleid][E_VEHICLE_FUEL] += 50.0;
			Inventory_Remove(playerid, "Gascan", 1);
			
			SendVehicleMessage(playerid, "[VEHICLE] You refilled the %s to 50 percent fuel.", ReturnVehicleName(vehicleid)); 
			return 1;
		}
	}
	
	Update3DTextLabelText(VehicleInfo[vehicleid][E_VEHICLE_REFILLDISPLAY], COLOR_3DTEXT, text); 
	return 1;
}

function:OnGasStationRefill(playerid, vehicleid, price, Float:fuels, x, y, z)
{
	new 
		text[128];
	
	VehicleInfo[vehicleid][E_VEHICLE_REFILLCOUNT] ++;
	
	switch(VehicleInfo[vehicleid][E_VEHICLE_REFILLCOUNT])
	{
		case 2: text = "Loading refilling fuel process\n(( ||----- ))";
		case 3: text = "Loading refilling fuel process\n(( |||---- ))";
		case 4: text = "Loading refilling fuel process\n(( ||||--- ))";
		case 5: text = "Loading refilling fuel process\n(( |||||-- ))";
		case 6: text = "Loading refilling fuel process\n(( ||||||- ))";
		case 7: text = "Loading refilling fuel process\n(( ||||||| ))";
		case 8:
		{
			KillTimer(playerRefillTimer[playerid]);
			playerRefillingVehicle[playerid] = false; 
			
			Delete3DTextLabel(VehicleInfo[vehicleid][E_VEHICLE_REFILLDISPLAY]); 
			VehicleInfo[vehicleid][E_VEHICLE_REFILLCOUNT] = 0; 
			
			VehicleInfo[vehicleid][E_VEHICLE_FUEL] += fuels;
            SaveVehicle(vehicleid);
			GiveMoney(playerid, -price);
			
            TogglePlayerControllable(playerid, true);
			SendVehicleMessage(playerid, "[VEHICLE] You refilled the %s to %.2f percent fuel for $%s.", ReturnVehicleName(vehicleid), fuels, FormatMoney(price)); 
			return 1;
		}
	}
	
	Update3DTextLabelText(VehicleInfo[vehicleid][E_VEHICLE_REFILLDISPLAY], COLOR_3DTEXT, text); 
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
			
	if(VehicleInfo[vehicleid][E_VEHICLE_FUEL] > 90)
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
			
	Dialog_Show(playerid, DialogRefuel, DIALOG_STYLE_INPUT, "Gas Station:", "Insert a refuel your vehicles $1.50/Liters.\n{33AA33}Info:{ffffff} The minimum is 1 liter of petrol and the maximum is 100 liters of petrol.", "Submit", "Close");
	return 1;
}

Dialog:DialogRefuel(playerid, response, listitem, inputtext[])
{
    if(response)
    {
        new total = strval(inputtext);
        if(total != 30 && total != 50 && total != 100 || isnull(inputtext))
            return Dialog_Show(playerid, DialogRefuel, DIALOG_STYLE_INPUT, "Gas Station:", "Insert a refuel your vehicles.\n{33AA33}Info:{ffffff} The minimum is 1 liter of petrol and the maximum is 100 liters of petrol.", "Submit", "Close");

        new vehicleid = IsPlayerNearVehicle(playerid), Float:vx, Float:vy, Float:vz;
		GetVehiclePos(vehicleid, vx, vy, vz);
		GetVehicleModelInfo(GetVehicleModel(vehicleid), VEHICLE_MODEL_INFO_PETROLCAP, vx, vy, vz); 

		if(playerRefillingVehicle[playerid])
			return SendErrorMessage(playerid, "You cannot use this right now");

		SendServerMessage(playerid, "You're starting to refill the vehicle.");
		SendServerMessage(playerid, "If you, or the vehicle moves then this process will be interrupted."); 
			
		VehicleInfo[vehicleid][E_VEHICLE_REFILLDISPLAY] = Create3DTextLabel("Loading refilling fuel process\n(( |------ ))", COLOR_3DTEXT, vx, vy, vz, 25.0, 0, 1);
		Attach3DTextLabelToVehicle(VehicleInfo[vehicleid][E_VEHICLE_REFILLDISPLAY], vehicleid, -0.0, -0.0, -0.0); 

		VehicleInfo[vehicleid][E_VEHICLE_REFILLCOUNT] = 1;
			
		playerRefillingVehicle[playerid] = true; 
		TogglePlayerControllable(playerid, false);

        if(total == 30)
        {
            if(1500 > PlayerInfo[playerid][E_CHARACTER_MONEY])
                return SendErrorMessage(playerid, "You can't afford gasoline.");

		    playerRefillTimer[playerid] = SetTimerEx("OnGasStationRefill", 2000, true, "iiiffff", playerid, vehicleid, 1500, 30.0, vx, vy, vz);
        }
        if(total == 50)
        {
            if(3500 > PlayerInfo[playerid][E_CHARACTER_MONEY])
                return SendErrorMessage(playerid, "You can't afford gasoline.");

		    playerRefillTimer[playerid] = SetTimerEx("OnGasStationRefill", 2500, true, "iiiffff", playerid, vehicleid, 3500, 50.0, vx, vy, vz);
        }
        if(total == 100)
        {
            if(5000 > PlayerInfo[playerid][E_CHARACTER_MONEY])
                return SendErrorMessage(playerid, "You can't afford gasoline.");

		    playerRefillTimer[playerid] = SetTimerEx("OnGasStationRefill", 3000, true, "iiiffff", playerid, vehicleid, 5000, 100.0, vx, vy, vz);
        }
    }
    return 1;
}