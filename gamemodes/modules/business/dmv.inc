stock ReturnLicenses(playerid, playerb)
{
	new
		driver_str[60],
		wep_str[60]
	;
	
	if(!PlayerInfo[playerid][E_CHARACTER_DRIVELICENSE])
		driver_str = "{FF6346}Driving License : No";
		
	else driver_str = "{E2FFFF}Driving License : Yes";
	
	if(!PlayerInfo[playerid][E_CHARACTER_WEAPLICENSE])
		wep_str = "{FF6346}Weapons License : No";
	
	else wep_str = "{E2FFFF}Weapons License : Yes";
	
	SendClientMessage(playerb, COLOR_DARKGREEN, "______Identification_______");
	SendClientMessageEx(playerb, COLOR_GRAD2, "Name : %s", ReturnSettingsName(playerid, playerid)); 
	SendClientMessageEx(playerb, COLOR_GRAD2, "%s", driver_str);
	SendClientMessageEx(playerb, COLOR_GRAD2, "%s", wep_str); 
	SendClientMessage(playerb, COLOR_DARKGREEN, "___________________________"); 
	return 1;
}

stock IsPlayerInDMVVehicle(playerid)
{
	new
		vehicleid = GetPlayerVehicleID(playerid);
	
	if(!vehicleid)
		return 0; 
		
	for(new i = 0; i < sizeof dmv_vehicles; i++)
	{
		if(vehicleid == dmv_vehicles[i])
			return 1;
	}
		
	return 0;
}

stock StopDriverstest(playerid)
{
	SetVehicleToRespawnEx(PlayersLicenseVehicle[playerid]);
	ToggleVehicleEngine(PlayersLicenseVehicle[playerid], false); 
	VehicleInfo[PlayersLicenseVehicle[playerid]][E_VEHICLE_ENGINE] = false;
	
	PlayersLicenseVehicle[playerid] = INVALID_VEHICLE_ID; 
	
	PlayerLicensePoint[playerid] = 0;
	PlayerTakingLicense[playerid] = false;
	
	GPS_DisablePlayerRaceCheckPoint(playerid);
	return 1;
}