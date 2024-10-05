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

		    SendClientMessageEx(playerid, COLOR_VEHICLE, "[Vehicle]: You've repaired the %s engine.", ReturnVehicleName(vehicleid));
		    RemovePlayerAttachedObject(playerid, 4);
		}
    }
    Update3DTextLabelText(PlayerInfo[playerid][E_CHARACTER_LOADINGDISPLAY], COLOR_DARKGREEN, text); 
}