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
	SendClientMessageEx(playerb, COLOR_GRAD2, "Name : %s", ReturnName(playerid)); 
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
		
	for(new i = 0; i < sizeof DMV_Vehicles; i++)
	{
		if(vehicleid == DMV_Vehicles[i])
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

CMD:licenseexam(playerid, params[])
{
	new vehicleid = IsPlayerInAnyVehicle(playerid);
	new Cents = floatround(100 * 100, floatround_round);
	
	if(Cents > PlayerInfo[playerid][E_CHARACTER_MONEY])
		return SendErrorMessage(playerid, "You can't afford a license exam");

	if(IsPlayerInDMVVehicle(playerid))
    {
        if(PlayerTakingLicense[playerid])
            return SendErrorMessage(playerid, "You're already in middle of a test.");

        PlayerTakingLicense[playerid] = true; 
        PlayerLicenseTime[playerid] = 60;
        
        PlayersLicenseVehicle[playerid] = vehicleid;
        PlayerLicensePoint[playerid] = 0; 
        
        ToggleVehicleEngine(vehicleid, true); 
        VehicleInfo[vehicleid][E_VEHICLE_ENGINE] = true;
        
        SendClientMessage(playerid, COLOR_GREY, "License instructor says: Follow the checkpoints and the rules of the road.");
        GPS_SetPlayerRaceCheckPoint(playerid, 1, LicensetestInfo[0][E_CHECKPOINTX], LicensetestInfo[1][E_CHECKPOINTY], LicensetestInfo[2][E_CHECKPOINTZ], 0.0, 0.0, 0.0, GPS_DMV); 
    }
	return 1;
}