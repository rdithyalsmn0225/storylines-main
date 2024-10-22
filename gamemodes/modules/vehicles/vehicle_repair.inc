CMD:repairkits(playerid, params[])
{
	if(PlayerInfo[playerid][E_CHARACTER_EQUIPITEMS] != REPAIR_KITS)
		return SendErrorMessage(playerid, "You must hold the repair kits in your hands.");

	if(!Inventory_Count(playerid, "Repair Kits"))
		return SendErrorMessage(playerid, "You don't have any repair kits in your inventory."); 

	new vehicleid = IsPlayerNearVehicle(playerid), Float:vx, Float:vy, Float:vz;
	GetVehicleHood(vehicleid, vx, vy, vz);  
	GetVehiclePos(vehicleid, vx, vy, vz);

	if(!IsPlayerInRangeOfPoint(playerid, 5.0, vx, vy, vz))
		return SendErrorMessage(playerid, "You aren't near the vehicles hood.");

	if(IsPlayerInAnyVehicle(playerid))
		return SendErrorMessage(playerid, "You can't be in a vehicle.");
				
	if(IsPlayerNearVehicle(playerid) == INVALID_VEHICLE_ID)
		return SendErrorMessage(playerid, "You aren't near a vehicle.");

	if(PlayerInfo[playerid][E_CHARACTER_LOADING] == true)
		return SendErrorMessage(playerid, "You're can't use this right now."); 

	new Float:x, Float:y, Float:z;
	GetPlayerPos(playerid, x, y, z);
	TogglePlayerControllable(playerid, false);
	ApplyAnimation(playerid, "CAR", "Fixn_Car_Loop", 4.1, 1, 0, 0, 0, 0, 1);
	PlayerInfo[playerid][E_CHARACTER_LOADINGDISPLAY] = Create3DTextLabel("Loading repairing process\n(( |------ ))", COLOR_POINT, x, y, z, 25.0, 0, 1);
	PlayerInfo[playerid][E_CHARACTER_LOADINGCOUNT] = 1;

	PlayerInfo[playerid][E_CHARACTER_LOADING] = true; 
	PlayerInfo[playerid][E_CHARACTER_LOADINGTIMER] = SetTimerEx("repairkits", 4500, true, "ii", playerid, vehicleid);
	return 1;
}

function:repairkits(playerid, vehicleid)
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

            Delete3DTextLabel(PlayerInfo[playerid][E_CHARACTER_LOADINGDISPLAY]); 
            KillTimer(PlayerInfo[playerid][E_CHARACTER_LOADINGTIMER]);

            Inventory_Remove(playerid, "Repair Kits", 1);
            SetVehicleHealthEx(vehicleid, 1000.0);
            new panels, doors, lights, tires;
			GetVehicleDamageStatus(vehicleid, panels, doors, lights, tires);
			UpdateVehicleDamageStatus(vehicleid, 0, 0, 0, tires);

			PlayerPlaySound(playerid,1133,0.0,0.0,0.0);
			SaveVehicle(vehicleid);

		    SendServerMessage(playerid, "VEHICLE: {ffffff}You've repaired the %s engine.", ReturnVehicleName(vehicleid));
		    RemovePlayerAttachedObject(playerid, 4);
		}
    }
    Update3DTextLabelText(PlayerInfo[playerid][E_CHARACTER_LOADINGDISPLAY], COLOR_DARKGREEN, text); 
}