CMD:untow(playerid, params[])
{
	if (GetVehicleModel(GetPlayerVehicleID(playerid)) != 525)
	    return SendErrorMessage(playerid, "You are not driving a tow truck.");

	if (GetPlayerState(playerid) != PLAYER_STATE_DRIVER)
	    return SendErrorMessage(playerid, "You are not the driver.");

	new
	    trailerid = GetVehicleTrailer(GetPlayerVehicleID(playerid));

    if (!trailerid)
	    return SendErrorMessage(playerid, "There is no vehicle hooked onto the truck.");

	DetachTrailerFromVehicle(GetPlayerVehicleID(playerid));
	SendNearbyMessage(playerid, 20.0, COLOR_EMOTE, "* %s has unhooked the %s from the tow truck.", ReturnName(playerid), ReturnVehicleModelName(GetVehicleModel(trailerid)));

	return 1;
}

CMD:tow(playerid, params[])
{
	if (GetVehicleModel(GetPlayerVehicleID(playerid)) != 525)
	    return SendErrorMessage(playerid, "You are not driving a tow truck.");

	if (GetPlayerState(playerid) != PLAYER_STATE_DRIVER)
	    return SendErrorMessage(playerid, "You are not the driver.");

	new vehicleid = GetVehicleFromBehind(GetPlayerVehicleID(playerid));

	if (vehicleid == INVALID_VEHICLE_ID)
	    return SendErrorMessage(playerid, "There is no vehicle in range.");

	if (!IsDoorVehicle(vehicleid))
	    return SendErrorMessage(playerid, "You can't tow this vehicle.");

	AttachTrailerToVehicle(vehicleid, GetPlayerVehicleID(playerid));
	SendNearbyMessage(playerid, 20.0, COLOR_EMOTE, "* %s has hooked a %s onto their tow truck.", ReturnName(playerid), ReturnVehicleModelName(GetVehicleModel(vehicleid)));
	return 1;
}

CMD:mechmenu(playerid, params[])
{
    if (PlayerInfo[playerid][E_CHARACTER_JOBS] != JOB_MECHANIC)
	    return SendErrorMessage(playerid, "You aren't mechanic.");

	if (!PlayerInfo[playerid][E_CHARACTER_MECHDUTY])
	    return SendErrorMessage(playerid, "You must be on mechanic duty to access mechanic menu.");

    if(PlayerInfo[playerid][E_CHARACTER_HUNGRY] < 20 || PlayerInfo[playerid][E_CHARACTER_THIRSTY] < 20)
		return SendErrorMessage(playerid, "You're hungry or thirsty right now.");
        
    if(IsPlayerInAnyVehicle(playerid))
		return SendErrorMessage(playerid, "You can't be in a vehicle.");
			
	if(IsPlayerNearVehicle(playerid) == INVALID_VEHICLE_ID)
		return SendErrorMessage(playerid, "You aren't near a vehicle."); 

    new str[1524];
    strcat(str, "Option\tRequire\tTime\n");
    strcat(str, "Repair Engine\t(1 Repair Kits)\t25 seconds\n");
    strcat(str, "Repair Bodykit\t(1 Repair Kits)\t30 seconds\n");
    strcat(str, "Repair Tire\t(1 Repair Kits)\t20 seconds\n");
    strcat(str, "Repaint Exterior\t(1 Spraycan)\t35 seconds\n");
    strcat(str, "Repaint Interior\t(1 Spraycan)\t35 seconds\n");
    strcat(str, "Repaint Paintjob type 1\t(2 Spraycan)\t40 seconds\n");
    strcat(str, "Repaint Paintjob type 2\t(2 Spraycan)\t40 seconds\n");
    strcat(str, "Repaint Paintjob type 3\t(2 Spraycan)\t40 seconds\n");
    strcat(str, "Manipulation Plates\t(2 Spraycan)\t35 seconds\n");
    ShowPlayerDialog(playerid, DIALOG_MECHMENU, DIALOG_STYLE_TABLIST_HEADERS, "Mechanic Menu", str, "Select", "Close");
    return 1;
}

function:repairengine(playerid, vehicleid)
{
	new text[256];
    PlayerInfo[playerid][E_CHARACTER_LOADINGCOUNT]++;

    switch(PlayerInfo[playerid][E_CHARACTER_LOADINGCOUNT])
    {
        case 2: text = "Loading repairing process\n(( ||----- ))";
        case 3: text = "Loading repairing process\n(( |||---- ))";
        case 4: text = "Loading repairing process\n(( ||||--- ))";
        case 5: text = "Loading repairing process\n(( |||||-- ))";
        case 6: text = "Loading repairing process\n(( ||||||- ))";
        case 7: text = "Loading repairing process\n(( ||||||| ))";
        case 8:
        {
		    TogglePlayerControllable(playerid, true);
            PlayerInfo[playerid][E_CHARACTER_LOADING] = false; 
            Delete3DTextLabel(PlayerInfo[playerid][E_CHARACTER_LOADINGDISPLAY]); 
            KillTimer(PlayerInfo[playerid][E_CHARACTER_LOADINGTIMER]);

            Inventory_Remove(playerid, "Repair Kits", 1);
            SetVehicleHealthEx(vehicleid, 1000.0);
            
            new panels, doors, lights, tires;
			GetVehicleDamageStatus(vehicleid, panels, doors, lights, tires);
			UpdateVehicleDamageStatus(vehicleid, 0, 0, 0, tires);

			PlayerPlaySound(playerid,1133,0.0,0.0,0.0);
			SaveVehicle(vehicleid);

            SetPlayerNeeds(playerid, -0.8, -0.5);

            if(PlayerInfo[playerid][E_CHARACTER_EQUIPITEMS] > INVENTORY_NONE)
			{
				ResetVarInventory(playerid);
			}

		    SendVehicleMessage(playerid, "[VEHICLE] You've repaired the %s engine.", ReturnVehicleName(vehicleid));
		    RemovePlayerAttachedObject(playerid, ATTACH_HAND);
		}
    }
    Update3DTextLabelText(PlayerInfo[playerid][E_CHARACTER_LOADINGDISPLAY], COLOR_3DTEXT, text); 
}

function:repairbody(playerid, vehicleid)
{
	new text[256];
    PlayerInfo[playerid][E_CHARACTER_LOADINGCOUNT]++;

    switch(PlayerInfo[playerid][E_CHARACTER_LOADINGCOUNT])
    {
        case 2: text = "Loading repairing process\n(( ||----- ))";
        case 3: text = "Loading repairing process\n(( |||---- ))";
        case 4: text = "Loading repairing process\n(( ||||--- ))";
        case 5: text = "Loading repairing process\n(( |||||-- ))";
        case 6: text = "Loading repairing process\n(( ||||||- ))";
        case 7: text = "Loading repairing process\n(( ||||||| ))";
        case 8:
        {
		    TogglePlayerControllable(playerid, true);
            PlayerInfo[playerid][E_CHARACTER_LOADING] = false; 
            Delete3DTextLabel(PlayerInfo[playerid][E_CHARACTER_LOADINGDISPLAY]); 
            KillTimer(PlayerInfo[playerid][E_CHARACTER_LOADINGTIMER]);

            Inventory_Remove(playerid, "Repair Kits", 1);
           
            new panels, doors, lights, tires;
			GetVehicleDamageStatus(vehicleid, panels, doors, lights, tires);
			UpdateVehicleDamageStatus(vehicleid, 0, 0, 0, tires);
            VehicleInfo[vehicleid][E_VEHICLE_BODY] = 0;
		    VehicleInfo[vehicleid][E_VEHICLE_TIRE] = tires;

			PlayerPlaySound(playerid,1133,0.0,0.0,0.0);
			SaveVehicle(vehicleid);

            SetPlayerNeeds(playerid, -0.8, -0.5);

            if(PlayerInfo[playerid][E_CHARACTER_EQUIPITEMS] > INVENTORY_NONE)
			{
				ResetVarInventory(playerid);
			}

		    SendVehicleMessage(playerid, "[VEHICLE] You've repaired the %s bodykits.", ReturnVehicleName(vehicleid));
		    RemovePlayerAttachedObject(playerid, ATTACH_HAND);
		}
    }
    Update3DTextLabelText(PlayerInfo[playerid][E_CHARACTER_LOADINGDISPLAY], COLOR_3DTEXT, text); 
}

function:repairtire(playerid, vehicleid)
{
	new text[256];
    PlayerInfo[playerid][E_CHARACTER_LOADINGCOUNT]++;

    switch(PlayerInfo[playerid][E_CHARACTER_LOADINGCOUNT])
    {
        case 2: text = "Loading repairing process\n(( ||----- ))";
        case 3: text = "Loading repairing process\n(( |||---- ))";
        case 4: text = "Loading repairing process\n(( ||||--- ))";
        case 5: text = "Loading repairing process\n(( |||||-- ))";
        case 6: text = "Loading repairing process\n(( ||||||- ))";
        case 7: text = "Loading repairing process\n(( ||||||| ))";
        case 8:
        {
		    TogglePlayerControllable(playerid, true);
            PlayerInfo[playerid][E_CHARACTER_LOADING] = false; 
            Delete3DTextLabel(PlayerInfo[playerid][E_CHARACTER_LOADINGDISPLAY]); 
            KillTimer(PlayerInfo[playerid][E_CHARACTER_LOADINGTIMER]);

            Inventory_Remove(playerid, "Repair Kits", 1);
           
            new panels, doors, lights, tires;
			GetVehicleDamageStatus(vehicleid, panels, doors, lights, tires);
			UpdateVehicleDamageStatus(vehicleid, panels, doors, lights, 0);
            VehicleInfo[vehicleid][E_VEHICLE_BODY] = panels;
		    VehicleInfo[vehicleid][E_VEHICLE_TIRE] = 0;

			PlayerPlaySound(playerid,1133,0.0,0.0,0.0);
			SaveVehicle(vehicleid);

            SetPlayerNeeds(playerid, -0.8, -0.5);

            if(PlayerInfo[playerid][E_CHARACTER_EQUIPITEMS] > INVENTORY_NONE)
			{
				ResetVarInventory(playerid);
			}

		    SendVehicleMessage(playerid, "[VEHICLE] You've repaired the %s tires.", ReturnVehicleName(vehicleid));
		    RemovePlayerAttachedObject(playerid, ATTACH_HAND);
		}
    }
    Update3DTextLabelText(PlayerInfo[playerid][E_CHARACTER_LOADINGDISPLAY], COLOR_3DTEXT, text); 
}

function:repaintexterior(playerid, vehicleid, modelid)
{
	new text[256];
    PlayerInfo[playerid][E_CHARACTER_LOADINGCOUNT]++;

    switch(PlayerInfo[playerid][E_CHARACTER_LOADINGCOUNT])
    {
        case 2: text = "Loading repaint process\n(( ||----- ))";
        case 3: text = "Loading repaint process\n(( |||---- ))";
        case 4: text = "Loading repaint process\n(( ||||--- ))";
        case 5: text = "Loading repaint process\n(( |||||-- ))";
        case 6: text = "Loading repaint process\n(( ||||||- ))";
        case 7: text = "Loading repaint process\n(( ||||||| ))";
        case 8:
        {
            PauseAC(playerid);
		    TogglePlayerControllable(playerid, true);
            PlayerInfo[playerid][E_CHARACTER_LOADING] = false; 
            Delete3DTextLabel(PlayerInfo[playerid][E_CHARACTER_LOADINGDISPLAY]); 
            KillTimer(PlayerInfo[playerid][E_CHARACTER_LOADINGTIMER]);

            Inventory_Remove(playerid, "Spraycan", 1);

            PlayerPlaySound(playerid, 1134, 0, 0, 0);
            new color = VehicleInfo[vehicleid][E_VEHICLE_COLOR2];
            ChangeVehicleColor(vehicleid, modelid, color);
            VehicleInfo[vehicleid][E_VEHICLE_COLOR1] = modelid;
            VehicleInfo[vehicleid][E_VEHICLE_COLOR2] = color;
            SaveVehicle(vehicleid);
            
			PlayerPlaySound(playerid,1133,0.0,0.0,0.0);
			SaveVehicle(vehicleid);

            SetPlayerNeeds(playerid, -0.8, -0.5);

            if(PlayerInfo[playerid][E_CHARACTER_EQUIPITEMS] > INVENTORY_NONE)
			{
				ResetVarInventory(playerid);
			}

		    SendVehicleMessage(playerid, "[VEHICLE] You've repaint the %s bodykits.", ReturnVehicleName(vehicleid));
		    RemovePlayerAttachedObject(playerid, ATTACH_HAND);
		}
    }
    Update3DTextLabelText(PlayerInfo[playerid][E_CHARACTER_LOADINGDISPLAY], COLOR_3DTEXT, text); 
}

function:repaintinterior(playerid, vehicleid, modelid)
{
	new text[256];
    PlayerInfo[playerid][E_CHARACTER_LOADINGCOUNT]++;

    switch(PlayerInfo[playerid][E_CHARACTER_LOADINGCOUNT])
    {
        case 2: text = "Loading repaint process\n(( ||----- ))";
        case 3: text = "Loading repaint process\n(( |||---- ))";
        case 4: text = "Loading repaint process\n(( ||||--- ))";
        case 5: text = "Loading repaint process\n(( |||||-- ))";
        case 6: text = "Loading repaint process\n(( ||||||- ))";
        case 7: text = "Loading repaint process\n(( ||||||| ))";
        case 8:
        {
            PauseAC(playerid);
		    TogglePlayerControllable(playerid, true);
            PlayerInfo[playerid][E_CHARACTER_LOADING] = false; 
            Delete3DTextLabel(PlayerInfo[playerid][E_CHARACTER_LOADINGDISPLAY]); 
            KillTimer(PlayerInfo[playerid][E_CHARACTER_LOADINGTIMER]);

            Inventory_Remove(playerid, "Spraycan", 1);
           
            PlayerPlaySound(playerid, 1134, 0, 0, 0);
            new color = VehicleInfo[vehicleid][E_VEHICLE_COLOR1];
            ChangeVehicleColor(vehicleid, color, modelid);
            VehicleInfo[vehicleid][E_VEHICLE_COLOR1] = color;
            VehicleInfo[vehicleid][E_VEHICLE_COLOR2] = modelid;
            SaveVehicle(vehicleid);
            

            SetPlayerNeeds(playerid, -0.8, -0.5);

            if(PlayerInfo[playerid][E_CHARACTER_EQUIPITEMS] > INVENTORY_NONE)
			{
				ResetVarInventory(playerid);
			}

		    SendVehicleMessage(playerid, "[VEHICLE] You've repaint the %s bodykits.", ReturnVehicleName(vehicleid));
		    RemovePlayerAttachedObject(playerid, ATTACH_HAND);
		}
    }
    Update3DTextLabelText(PlayerInfo[playerid][E_CHARACTER_LOADINGDISPLAY], COLOR_3DTEXT, text); 
}

function:repaintpaintjob1(playerid, vehicleid)
{
	new text[256];
    PlayerInfo[playerid][E_CHARACTER_LOADINGCOUNT]++;

    switch(PlayerInfo[playerid][E_CHARACTER_LOADINGCOUNT])
    {
        case 2: text = "Loading repaint process\n(( ||----- ))";
        case 3: text = "Loading repaint process\n(( |||---- ))";
        case 4: text = "Loading repaint process\n(( ||||--- ))";
        case 5: text = "Loading repaint process\n(( |||||-- ))";
        case 6: text = "Loading repaint process\n(( ||||||- ))";
        case 7: text = "Loading repaint process\n(( ||||||| ))";
        case 8:
        {
            PauseAC(playerid);
		    TogglePlayerControllable(playerid, true);
            PlayerInfo[playerid][E_CHARACTER_LOADING] = false; 
            Delete3DTextLabel(PlayerInfo[playerid][E_CHARACTER_LOADINGDISPLAY]); 
            KillTimer(PlayerInfo[playerid][E_CHARACTER_LOADINGTIMER]);

            Inventory_Remove(playerid, "Spraycan", 1);
           
            ChangeVehiclePaintjob(vehicleid, 0);
            VehicleInfo[vehicleid][E_VEHICLE_PAINTJOB] = 0;
            SaveVehicle(vehicleid);

            SetPlayerNeeds(playerid, -0.8, -0.5);

            PlayerPlaySound(playerid, 1134, 0.0, 0.0, 0.0);

            if(PlayerInfo[playerid][E_CHARACTER_EQUIPITEMS] > INVENTORY_NONE)
			{
				ResetVarInventory(playerid);
			}

		    SendVehicleMessage(playerid, "[VEHICLE] You've repaintjob the %s bodykits.", ReturnVehicleName(vehicleid));
		    RemovePlayerAttachedObject(playerid, ATTACH_HAND);
		}
    }
    Update3DTextLabelText(PlayerInfo[playerid][E_CHARACTER_LOADINGDISPLAY], COLOR_3DTEXT, text); 
}

function:repaintpaintjob2(playerid, vehicleid)
{
	new text[256];
    PlayerInfo[playerid][E_CHARACTER_LOADINGCOUNT]++;

    switch(PlayerInfo[playerid][E_CHARACTER_LOADINGCOUNT])
    {
        case 2: text = "Loading repaint process\n(( ||----- ))";
        case 3: text = "Loading repaint process\n(( |||---- ))";
        case 4: text = "Loading repaint process\n(( ||||--- ))";
        case 5: text = "Loading repaint process\n(( |||||-- ))";
        case 6: text = "Loading repaint process\n(( ||||||- ))";
        case 7: text = "Loading repaint process\n(( ||||||| ))";
        case 8:
        {
            PauseAC(playerid);
		    TogglePlayerControllable(playerid, true);
            PlayerInfo[playerid][E_CHARACTER_LOADING] = false; 
            Delete3DTextLabel(PlayerInfo[playerid][E_CHARACTER_LOADINGDISPLAY]); 
            KillTimer(PlayerInfo[playerid][E_CHARACTER_LOADINGTIMER]);

            Inventory_Remove(playerid, "Spraycan", 2);
           
            ChangeVehiclePaintjob(vehicleid, 1);
            VehicleInfo[vehicleid][E_VEHICLE_PAINTJOB] = 1;
            SaveVehicle(vehicleid);

            SetPlayerNeeds(playerid, -0.8, -0.5);

            PlayerPlaySound(playerid, 1134, 0.0, 0.0, 0.0);

            if(PlayerInfo[playerid][E_CHARACTER_EQUIPITEMS] > INVENTORY_NONE)
			{
				ResetVarInventory(playerid);
			}

		    SendVehicleMessage(playerid, "[VEHICLE] You've repaintjob the %s bodykits.", ReturnVehicleName(vehicleid));
		    RemovePlayerAttachedObject(playerid, ATTACH_HAND);
		}
    }
    Update3DTextLabelText(PlayerInfo[playerid][E_CHARACTER_LOADINGDISPLAY], COLOR_3DTEXT, text); 
}

function:repaintpaintjob3(playerid, vehicleid)
{
	new text[256];
    PlayerInfo[playerid][E_CHARACTER_LOADINGCOUNT]++;

    switch(PlayerInfo[playerid][E_CHARACTER_LOADINGCOUNT])
    {
        case 2: text = "Loading repaint process\n(( ||----- ))";
        case 3: text = "Loading repaint process\n(( |||---- ))";
        case 4: text = "Loading repaint process\n(( ||||--- ))";
        case 5: text = "Loading repaint process\n(( |||||-- ))";
        case 6: text = "Loading repaint process\n(( ||||||- ))";
        case 7: text = "Loading repaint process\n(( ||||||| ))";
        case 8:
        {
            PauseAC(playerid);
		    TogglePlayerControllable(playerid, true);
            PlayerInfo[playerid][E_CHARACTER_LOADING] = false; 
            Delete3DTextLabel(PlayerInfo[playerid][E_CHARACTER_LOADINGDISPLAY]); 
            KillTimer(PlayerInfo[playerid][E_CHARACTER_LOADINGTIMER]);

            Inventory_Remove(playerid, "Spraycan", 2);
           
            ChangeVehiclePaintjob(vehicleid, 2);
            VehicleInfo[vehicleid][E_VEHICLE_PAINTJOB] = 2;
            SaveVehicle(vehicleid);

            SetPlayerNeeds(playerid, -0.8, -0.5);

            PlayerPlaySound(playerid, 1134, 0.0, 0.0, 0.0);

            if(PlayerInfo[playerid][E_CHARACTER_EQUIPITEMS] > INVENTORY_NONE)
			{
				ResetVarInventory(playerid);
			}

		    SendVehicleMessage(playerid, "[VEHICLE] You've repaintjob %s bodykits.", ReturnVehicleName(vehicleid));
		    RemovePlayerAttachedObject(playerid, ATTACH_HAND);
		}
    }
    Update3DTextLabelText(PlayerInfo[playerid][E_CHARACTER_LOADINGDISPLAY], COLOR_3DTEXT, text); 
}

function:repaintplates(playerid, vehicleid)
{
	new text[256];
    PlayerInfo[playerid][E_CHARACTER_LOADINGCOUNT]++;

    switch(PlayerInfo[playerid][E_CHARACTER_LOADINGCOUNT])
    {
        case 2: text = "Loading repaint plates process\n(( ||----- ))";
        case 3: text = "Loading repaint plates process\n(( |||---- ))";
        case 4: text = "Loading repaint plates process\n(( ||||--- ))";
        case 5: text = "Loading repaint plates process\n(( |||||-- ))";
        case 6: text = "Loading repaint plates process\n(( ||||||- ))";
        case 7: text = "Loading repaint plates process\n(( ||||||| ))";
        case 8:
        {
            PauseAC(playerid);
		    TogglePlayerControllable(playerid, true);
            PlayerInfo[playerid][E_CHARACTER_LOADING] = false; 
            Delete3DTextLabel(PlayerInfo[playerid][E_CHARACTER_LOADINGDISPLAY]); 
            KillTimer(PlayerInfo[playerid][E_CHARACTER_LOADINGTIMER]);

            Inventory_Remove(playerid, "Spraycan", 2);

            new
                plates[32],
			    randset[3];

            randset[0] = random(sizeof(possible_vehicle_plates)); 
            randset[1] = random(sizeof(possible_vehicle_plates)); 
            randset[2] = random(sizeof(possible_vehicle_plates)); 

            format(plates, 32, "%d%s%s%s%d%d%d", random(9), possible_vehicle_plates[randset[0]], possible_vehicle_plates[randset[1]], possible_vehicle_plates[randset[2]], random(9), random(9)); 
            format(VehicleInfo[vehicleid][E_VEHICLE_FAKEPLATES], 32, plates);

            SetVehicleNumberPlate(vehicleid, plates);
            SetVehicleToRespawnEx(vehicleid); 
            VehicleInfo[vehicleid][E_VEHICLE_PLATESFAKE] = true;
            VehicleInfo[vehicleid][E_VEHICLE_PLATESSTATUS] = false;

            SaveVehicle(vehicleid);

            SetPlayerNeeds(playerid, -0.8, -0.5);
            
            PlayerPlaySound(playerid, 1134, 0.0, 0.0, 0.0);

            if(PlayerInfo[playerid][E_CHARACTER_EQUIPITEMS] > INVENTORY_NONE)
			{
				ResetVarInventory(playerid);
			}

		    SendVehicleMessage(playerid, "[VEHICLE] You've repaint %s plates.", ReturnVehicleName(vehicleid));
		    RemovePlayerAttachedObject(playerid, ATTACH_HAND);
		}
    }
    Update3DTextLabelText(PlayerInfo[playerid][E_CHARACTER_LOADINGDISPLAY], COLOR_3DTEXT, text); 
}