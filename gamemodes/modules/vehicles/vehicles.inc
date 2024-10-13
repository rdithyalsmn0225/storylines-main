static const s_TopSpeed[212] = {
    157, 147, 186, 110, 133, 164, 110, 148, 100, 158, 129, 221, 168, 110, 105, 192, 154, 270,
    115, 149, 145, 154, 140, 99, 135, 270, 173, 165, 157, 201, 190, 130, 94, 110, 167, 0, 149,
    158, 142, 168, 136, 145, 139, 126, 110, 164, 270, 270, 111, 0, 0, 193, 270, 60, 135, 157,
    106, 95, 157, 136, 270, 160, 111, 142, 145, 145, 147, 140, 144, 270, 157, 110, 190, 190,
    149, 173, 270, 186, 117, 140, 184, 73, 156, 122, 190, 99, 64, 270, 270, 139, 157, 149, 140,
    270, 214, 176, 162, 270, 108, 123, 140, 145, 216, 216, 173, 140, 179, 166, 108, 79, 101, 270,
    270, 270, 120, 142, 157, 157, 164, 270, 270, 160, 176, 151, 130, 160, 158, 149, 176, 149, 60,
    70, 110, 167, 168, 158, 173, 0, 0, 270, 149, 203, 164, 151, 150, 147, 149, 142, 270, 153, 145,
    157, 121, 270, 144, 158, 113, 113, 156, 178, 169, 154, 178, 270, 145, 165, 160, 173, 146, 0, 0,
    93, 60, 110, 60, 158, 158, 270, 130, 158, 153, 151, 136, 85, 0, 153, 142, 165, 108, 162, 0, 0,
    270, 270, 130, 190, 175, 175, 175, 158, 151, 110, 169, 171, 148, 152, 0, 0, 0, 108, 0, 0
};

GetAvailableSeat(vehicleid, start = 1)
{
    new seats = GetVehicleMaxSeats(vehicleid);

    for (new i = start; i < seats; i ++) if(!IsVehicleSeatUsed(vehicleid, i)) {
        return i;
    }
    return -1;
}

IsVehicleSeatUsed(vehicleid, seat)
{
    foreach (new i : Player) if(IsPlayerInVehicle(i, vehicleid) && GetPlayerVehicleSeat(i) == seat) {
        return 1;
    }
    return 0;
}

GetVehicleMaxSeats(vehicleid)
{
    static const g_arrMaxSeats[] = {
        4, 2, 2, 2, 4, 4, 1, 2, 2, 4, 2, 2, 2, 4, 2, 2, 4, 2, 4, 2, 4, 4, 2, 2, 2, 1, 4, 4, 4, 2,
        1, 7, 1, 2, 2, 0, 2, 7, 4, 2, 4, 1, 2, 2, 2, 4, 1, 2, 1, 0, 0, 2, 1, 1, 1, 2, 2, 2, 4, 4,
        2, 2, 2, 2, 1, 1, 4, 4, 2, 2, 4, 2, 1, 1, 2, 2, 1, 2, 2, 4, 2, 1, 4, 3, 1, 1, 1, 4, 2, 2,
        4, 2, 4, 1, 2, 2, 2, 4, 4, 2, 2, 1, 2, 2, 2, 2, 2, 4, 2, 1, 1, 2, 1, 1, 2, 2, 4, 2, 2, 1,
        1, 2, 2, 2, 2, 2, 2, 2, 2, 4, 1, 1, 1, 2, 2, 2, 2, 7, 7, 1, 4, 2, 2, 2, 2, 2, 4, 4, 2, 2,
        4, 4, 2, 1, 2, 2, 2, 2, 2, 2, 4, 4, 2, 2, 1, 2, 4, 4, 1, 0, 0, 1, 1, 2, 1, 2, 2, 1, 2, 4,
        4, 2, 4, 1, 0, 4, 2, 2, 2, 2, 0, 0, 7, 2, 2, 1, 4, 4, 4, 2, 2, 2, 2, 2, 4, 2, 0, 0, 0, 4,
        0, 0
    };
    new
        model = GetVehicleModel(vehicleid);

    if(400 <= model <= 611)
        return g_arrMaxSeats[model - 400];

    return 0;
}

IsWindowedVehicle(vehicleid)
{
	static const g_aWindowStatus[] = {
	    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
	    1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1,
	    1, 0, 1, 1, 1, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 0, 1, 1,
	    1, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1,
	    1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1,
	    1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1,
	    1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 1, 0, 1, 1, 0, 0, 0, 0,
	    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
	    1, 1, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 1, 1,
		1, 0, 1, 1, 0, 1, 0, 1, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 1,
		1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 0, 0
	};
	new modelid = GetVehicleModel(vehicleid);

    if (modelid < 400 || modelid > 611)
        return 0;

    return (g_aWindowStatus[modelid - 400]);
}

stock GetVehicleEngineStatus(vehicleid)
{
	static
	    engine,
	    lights,
	    alarm,
	    doors,
	    bonnet,
	    boot,
	    objective;

	GetVehicleParamsEx(vehicleid, engine, lights, alarm, doors, bonnet, boot, objective);

	if (engine != 1)
		return 0;

	return 1;
}

stock IsEngineVehicle(vehicleid)
{
	static const g_aEngineStatus[] = {
	    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
	    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1,
	    1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1,
	    1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
	    1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
	    1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1,
	    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1,
	    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
	    1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1,
	    1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 1, 1, 1, 1, 1,
	    1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 0, 0
	};
    new modelid = GetVehicleModel(vehicleid);

    if (modelid < 400 || modelid > 611)
        return 0;

    return (g_aEngineStatus[modelid - 400]);
}

IsABike(vehicleid)
{
    switch (GetVehicleModel(vehicleid)) {
        case 448, 461..463, 468, 521..523, 581, 586, 481, 509, 510: return 1;
    }
    return 0;
}

function:OnVehicleScrap(playerid, response, dbid, cash_back)
{
	if(response)
	{
		if(!IsPlayerInAnyVehicle(playerid))
			return SendErrorMessage(playerid, "You're no longer in a vehicle. This was aborted.");
			
		new delQuery[128];
		
		mysql_format(ourConnection, delQuery, sizeof(delQuery), "DELETE FROM vehicles WHERE VehicleDBID = %i", dbid);
		mysql_pquery(ourConnection, delQuery); 
		
		SendServerMessage(playerid, "Your %s has been permanently deleted.", ReturnVehicleName(GetPlayerVehicleID(playerid))); 
		SendServerMessage(playerid, "You earned $%s from scrapping it.", FormatMoney(cash_back));
		
		GiveMoney(playerid, cash_back); 
		
		ResetVehicleVars(GetPlayerVehicleID(playerid)); 
		VS_RemoveAllItems(GetPlayerVehicleID(playerid));
		DestroyVehicle(GetPlayerVehicleID(playerid)); 
		
		PlayerInfo[playerid][E_CHARACTER_VEHICLESPAWNED] = false;
		PlayerInfo[playerid][E_CHARACTER_VEHICLESPAWN] = 0;
		
		for(new i = 1; i < MAX_PLAYER_VEHICLES; i++)
		{
			if(PlayerInfo[playerid][E_CHARACTER_OWNEDVEHICLE][i] == dbid)
			{
				PlayerInfo[playerid][E_CHARACTER_OWNEDVEHICLE][i] = 0;
			}
		}
	}
	
	else return SendServerMessage(playerid, "This action was aborted.");
	return 1;
}

function:OnVehicleTow(playerid)
{
	new vehicleid = PlayerInfo[playerid][E_CHARACTER_VEHICLESPAWN], newDisplay[128]; 
	
	if(IsVehicleOccupied(vehicleid))
	{
		KillTimer(playerTowTimer[playerid]);
		SendServerMessage(playerid, "Your vehicle tow was interrupted."); 
		
		playerTowingVehicle[playerid] = false;	
		Delete3DTextLabel(VehicleInfo[vehicleid][E_VEHICLE_TOW]);
		
		VehicleInfo[vehicleid][E_VEHICLE_TOWCOUNT] = 0;
		return 1;
	}
	
	VehicleInfo[vehicleid][E_VEHICLE_TOWCOUNT]++;
	
	if(VehicleInfo[vehicleid][E_VEHICLE_TOWCOUNT] == 1) newDisplay = "(( || ))\nTOWING VEHICLE"; 
	if(VehicleInfo[vehicleid][E_VEHICLE_TOWCOUNT] == 2) newDisplay = "(( ||| ))\nTOWING VEHICLE"; 
	if(VehicleInfo[vehicleid][E_VEHICLE_TOWCOUNT] == 3) newDisplay = "(( |||| ))\nTOWING VEHICLE"; 
	if(VehicleInfo[vehicleid][E_VEHICLE_TOWCOUNT] == 4) newDisplay = "(( ||||| ))\nTOWING VEHICLE"; 
	if(VehicleInfo[vehicleid][E_VEHICLE_TOWCOUNT] == 5) newDisplay = "(( |||||| ))\nTOWING VEHICLE"; 
	if(VehicleInfo[vehicleid][E_VEHICLE_TOWCOUNT] == 6) newDisplay = "(( ||||||| ))\nTOWING VEHICLE"; 
	if(VehicleInfo[vehicleid][E_VEHICLE_TOWCOUNT] == 7) newDisplay = "(( |||||||| ))\nTOWING VEHICLE"; 
	if(VehicleInfo[vehicleid][E_VEHICLE_TOWCOUNT] == 8) newDisplay = "(( |||||||| ))\nTOWING VEHICLE"; 
	
	Update3DTextLabelText(VehicleInfo[vehicleid][E_VEHICLE_TOW], COLOR_DARKGREEN, newDisplay);
	
	if(VehicleInfo[vehicleid][E_VEHICLE_TOWCOUNT] == 9)
	{
		SendServerMessage(playerid, "Your vehicle has been towed.");
		GiveMoney(playerid, -2000);
		
		playerTowingVehicle[playerid] = false;	
		SetVehicleToRespawnEx(vehicleid); 
		
		Delete3DTextLabel(VehicleInfo[vehicleid][E_VEHICLE_TOW]);
		KillTimer(playerTowTimer[playerid]);
		
		VehicleInfo[vehicleid][E_VEHICLE_TOWCOUNT] = 0; 
		return 1;
	}
	
	return 1;
}

function:OnGascanRefill(playerid, vehicleid, x, y, z)
{
	new 
		text[128]
	;
	/*if(GetVehicleDistanceFromPoint(vehicleid, x, y, z) > 5)
	{
		SendErrorMessage(playerid, "The vehicle you were refilling moved and canceled."); 
		
		KillTimer(playerRefillTimer[playerid]);
		playerRefillingVehicle[playerid] = false; 
		
		Delete3DTextLabel(VehicleInfo[vehicleid][E_VEHICLE_REFILLDISPLAY]); 
		VehicleInfo[vehicleid][E_VEHICLE_REFILLCOUNT] = 0; 
		return 1;
	}*/
	
	if(!IsPlayerInRangeOfPoint(playerid, 1.0, PlayerInfo[playerid][E_CHARACTER_LASTPOS][0], PlayerInfo[playerid][E_CHARACTER_LASTPOS][1], PlayerInfo[playerid][E_CHARACTER_LASTPOS][2]))
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
			
			SendServerMessage(playerid, "You refilled the %s to 50 percent fuel.", ReturnVehicleName(vehicleid)); 
			return 1;
		}
	}
	
	Update3DTextLabelText(VehicleInfo[vehicleid][E_VEHICLE_REFILLDISPLAY], COLOR_DARKGREEN, text); 
	return 1;
}

function:OnPlayerVehiclePurchase(playerid, id, plates[], Float:x, Float:y, Float:z, Float:a)
{
	new
		vehicleid = INVALID_VEHICLE_ID
	;
	
	DestroyVehicle(DealershipPlayerCar[playerid]);
	
	vehicleid = 
		CreateVehicle(g_aDealershipData[SubDealershipHolder[playerid]][E_DEALERSHIP_MODELID], x, y, z, a, DealershipCarColors[playerid][0], DealershipCarColors[playerid][1], -1);  
		
	SetVehicleNumberPlate(vehicleid, plates); 
	SetVehicleToRespawnEx(vehicleid); 
	
	PutPlayerInVehicle(playerid, vehicleid, 0); 
	PlayerInfo[playerid][E_CHARACTER_OWNEDVEHICLE][id] = cache_insert_id(); 
	
	if(vehicleid != INVALID_VEHICLE_ID)
	{
		VehicleInfo[vehicleid][E_VEHICLE_DBID] = cache_insert_id();
		VehicleInfo[vehicleid][E_VEHICLE_OWNERDBID] = PlayerInfo[playerid][E_CHARACTER_DBID]; 
		
		VehicleInfo[vehicleid][E_VEHICLE_MODEL] = g_aDealershipData[SubDealershipHolder[playerid]][E_DEALERSHIP_MODELID];
		
		VehicleInfo[vehicleid][E_VEHICLE_COLOR1] = DealershipCarColors[playerid][0];
		VehicleInfo[vehicleid][E_VEHICLE_COLOR2] = DealershipCarColors[playerid][1];
		
		VehicleInfo[vehicleid][E_VEHICLE_PAINTJOB] = -1;
		
		VehicleInfo[vehicleid][E_VEHICLE_POS][0] = x;
		VehicleInfo[vehicleid][E_VEHICLE_POS][1] = y;
		VehicleInfo[vehicleid][E_VEHICLE_POS][2] = z;
		VehicleInfo[vehicleid][E_VEHICLE_POS][3] = a;
		
		format(VehicleInfo[vehicleid][E_VEHICLE_PLATES], 32, "%s", plates); 
		
		VehicleInfo[vehicleid][E_VEHICLE_LOCKED] = false;
		VehicleInfo[vehicleid][E_VEHICLE_ENGINE] = false;
		
		VehicleInfo[vehicleid][E_VEHICLE_FUEL] = 50.0; 
		
		VehicleInfo[vehicleid][E_VEHICLE_HEALTH] = 1000.0; 
		
		VehicleInfo[vehicleid][E_VEHICLE_DESTROYED] = 0;
		
		SaveVehicle(vehicleid);
		
		PlayerInfo[playerid][E_CHARACTER_VEHICLESPAWNED] = true;
		PlayerInfo[playerid][E_CHARACTER_VEHICLESPAWN] = vehicleid;
	}
	
	SendServerMessage(playerid, "You successfully bought a %s for $%s.", ReturnVehicleName(vehicleid), FormatMoney(DealershipTotalCost[playerid]));
	
	PlayerPurchasingVehicle[playerid] = false;
	ResetDealershipVars(playerid); 
	return 1;
}

function:Query_LoadPrivateVehicle(playerid)
{
	if(!cache_num_rows())
		return SendErrorMessage(playerid, "An error occurred while loading your vehicle."); 
		
	new rows, fields; 
	cache_get_row_count(rows);
	cache_get_field_count(fields);
	new str[512], vehicleid = INVALID_VEHICLE_ID, Float:x, Float:y, Float:z, Float:a, c1, c2, model; 
	
	for (new i = 0; i < rows && i < MAX_VEHICLES; i++)
	{
		cache_get_value_name_int(i, "VehicleModel", model);
		cache_get_value_name_float(i, "VehicleParkPosX", x);
		cache_get_value_name_float(i, "VehicleParkPosY", y);
		cache_get_value_name_float(i, "VehicleParkPosZ", z);
		cache_get_value_name_float(i, "VehicleParkPosA", a);
		cache_get_value_name_int(i, "VehicleColor1", c1);
		cache_get_value_name_int(i, "VehicleColor2", c2);

		vehicleid = CreateVehicle(model, x, y, z, a, c1, c2, -1, 0);
			
		if(vehicleid != INVALID_VEHICLE_ID)
		{
			VehicleInfo[vehicleid][E_VEHICLE_EXISTS] = true; 
			cache_get_value_name_int(i, "VehicleDBID", VehicleInfo[vehicleid][E_VEHICLE_DBID]); 
			cache_get_value_name_int(i, "VehicleOwnerDBID", VehicleInfo[vehicleid][E_VEHICLE_OWNERDBID]);
			cache_get_value_name_int(i, "VehicleModel", VehicleInfo[vehicleid][E_VEHICLE_MODEL]);
			cache_get_value_name_int(i, "VehicleColor1", VehicleInfo[vehicleid][E_VEHICLE_COLOR1]);
			cache_get_value_name_int(i, "VehicleColor2", VehicleInfo[vehicleid][E_VEHICLE_COLOR2]);
			cache_get_value_name_float(i, "VehicleParkPosX", VehicleInfo[vehicleid][E_VEHICLE_POS][0]);
			cache_get_value_name_float(i, "VehicleParkPosY", VehicleInfo[vehicleid][E_VEHICLE_POS][1]);
			cache_get_value_name_float(i, "VehicleParkPosZ", VehicleInfo[vehicleid][E_VEHICLE_POS][2]);
			cache_get_value_name_float(i, "VehicleParkPosA", VehicleInfo[vehicleid][E_VEHICLE_POS][3]);
			cache_get_value_name_int(i, "VehicleParkInterior", VehicleInfo[vehicleid][E_VEHICLE_INT]);
			cache_get_value_name_int(i, "VehicleParkWorld", VehicleInfo[vehicleid][E_VEHICLE_WORLD]);
			cache_get_value_name(i, "VehiclePlates", VehicleInfo[vehicleid][E_VEHICLE_PLATES], 32);
			cache_get_value_name_bool(i, "VehicleLocked", VehicleInfo[vehicleid][E_VEHICLE_LOCKED]);
			cache_get_value_name_bool(i, "VehicleImpounded", VehicleInfo[vehicleid][E_VEHICLE_IMPOUND]);
			cache_get_value_name_float(i, "VehicleImpoundPosX", VehicleInfo[vehicleid][E_VEHICLE_IMPOUNDPOS][0]);
			cache_get_value_name_float(i, "VehicleImpoundPosY", VehicleInfo[vehicleid][E_VEHICLE_IMPOUNDPOS][1]);
			cache_get_value_name_float(i, "VehicleImpoundPosZ", VehicleInfo[vehicleid][E_VEHICLE_IMPOUNDPOS][2]);
			cache_get_value_name_float(i, "VehicleImpoundPosA", VehicleInfo[vehicleid][E_VEHICLE_IMPOUNDPOS][3]);
			cache_get_value_name_float(i, "VehicleFuel", VehicleInfo[vehicleid][E_VEHICLE_FUEL]); 
			cache_get_value_name_int(i, "VehicleSirens", VehicleInfo[vehicleid][E_VEHICLE_SIRENS]);
			cache_get_value_name_int(i, "VehicleTimesDestroyed", VehicleInfo[vehicleid][E_VEHICLE_DESTROYED]);		
			cache_get_value_name_float(i, "VehicleHealth", VehicleInfo[vehicleid][E_VEHICLE_HEALTH]);
			for(new d = 1; d < 5; d++)
			{
				format(str, sizeof(str), "VehicleLastDrivers%d", d);
				cache_get_value_name_int(i, str, VehicleInfo[vehicleid][E_VEHICLE_LASTDRIVER][d]);
				
				format(str, sizeof(str), "VehicleLastPassengers%d", d);
				cache_get_value_name_int(i, str, VehicleInfo[vehicleid][E_VEHICLE_LASTPASSENGERS][d]);
			}

			for(new m = 0; m < 13; m++)
			{
				format(str, sizeof(str), "VehicleMods%d", m);
				cache_get_value_name_int(i, str, VehicleInfo[vehicleid][E_VEHICLE_MODS][m]);

				if(VehicleInfo[vehicleid][E_VEHICLE_MODS][m] && IsVehicleUpgradeCompatible(VehicleInfo[vehicleid][E_VEHICLE_MODEL], VehicleInfo[vehicleid][E_VEHICLE_MODS][m])) AddVehicleComponent(vehicleid, VehicleInfo[vehicleid][E_VEHICLE_MODS][m]);
			}
			cache_get_value_name_int(i, "VehicleWheels", VehicleInfo[vehicleid][E_VEHICLE_WHEELS]);
			cache_get_value_name_int(i, "VehicleHydraulics", VehicleInfo[vehicleid][E_VEHICLE_HYDRAULICS]);
			cache_get_value_name_int(i, "VehiclePaintjob", VehicleInfo[vehicleid][E_VEHICLE_PAINTJOB]);
			
			format(str, sizeof(str), "SELECT * FROM `vstorage` WHERE `ID` = '%d'", VehicleInfo[vehicleid][E_VEHICLE_DBID]);
			mysql_pquery(ourConnection, str, "VehicleStorage_Load", "d", vehicleid);

			if(VehicleInfo[vehicleid][E_VEHICLE_INT] != 0)
			{
				LinkVehicleToInterior(vehicleid, VehicleInfo[vehicleid][E_VEHICLE_INT]); 
				SetVehicleVirtualWorld(vehicleid, VehicleInfo[vehicleid][E_VEHICLE_WORLD]);
			}
			
			if(!isnull(VehicleInfo[vehicleid][E_VEHICLE_PLATES]))
			{
				SetVehicleNumberPlate(vehicleid, VehicleInfo[vehicleid][E_VEHICLE_PLATES]);
				SetVehicleToRespawnEx(vehicleid); 
			}
			
			if(VehicleInfo[vehicleid][E_VEHICLE_IMPOUND] == true)
			{
				SetVehiclePos(vehicleid, VehicleInfo[vehicleid][E_VEHICLE_IMPOUNDPOS][0], VehicleInfo[vehicleid][E_VEHICLE_IMPOUNDPOS][1], VehicleInfo[vehicleid][E_VEHICLE_IMPOUNDPOS][2]);
				SetVehicleZAngle(vehicleid, VehicleInfo[vehicleid][E_VEHICLE_IMPOUNDPOS][3]); 
			}
			ChangeVehiclePaintjob(vehicleid, VehicleInfo[vehicleid][E_VEHICLE_PAINTJOB]);
			ChangeVehicleColor(vehicleid, VehicleInfo[vehicleid][E_VEHICLE_COLOR1], VehicleInfo[vehicleid][E_VEHICLE_COLOR2]);
			SetVehicleHealthEx(vehicleid, VehicleInfo[vehicleid][E_VEHICLE_HEALTH]);
			AddVehicleComponent(vehicleid, VehicleInfo[vehicleid][E_VEHICLE_HYDRAULICS]);
			AddVehicleComponent(vehicleid, VehicleInfo[vehicleid][E_VEHICLE_WHEELS]);
			
			if(VehicleInfo[vehicleid][E_VEHICLE_LOCKED] == false)
				SetVehicleParamsEx(vehicleid, 0, 0, 0, 0, 0, 0, 0);
				
			else SetVehicleParamsEx(vehicleid, 0, 0, 0, 1, 0, 0, 0);
			
			VehicleInfo[vehicleid][E_VEHICLE_ADMIN] = false;
			
			if(!IsEngineVehicle(vehicleid))
				ToggleVehicleEngine(vehicleid, true); 
		}
	}

	VehicleInfo[vehicleid][E_VEHICLE_CRATES] = 0;

	VehicleInfo[vehicleid][E_VEHICLE_VCTIMER] = 0;
	
	PlayerInfo[playerid][E_CHARACTER_VEHICLESPAWNED] = true;
	PlayerInfo[playerid][E_CHARACTER_VEHICLESPAWN] = vehicleid; 
	
	SendServerMessage(playerid, "%s has been spawned at its parking place.", ReturnVehicleName(vehicleid));
	if(VehicleInfo[vehicleid][E_VEHICLE_IMPOUND]) SendClientMessage(playerid, COLOR_RED, "Your vehicle is impounded.");
	GPS_SetPlayerRaceCheckPoint(playerid, 1, VehicleInfo[vehicleid][E_VEHICLE_POS][0], VehicleInfo[vehicleid][E_VEHICLE_POS][1], VehicleInfo[vehicleid][E_VEHICLE_POS][2], 0.0, 0.0, 0.0);
	return 1;
}

function:Query_AddPlayerVehicle(playerid, playerb)
{
	PlayerInfo[playerb][E_CHARACTER_OWNEDVEHICLE][playerInsertID[playerb]] = cache_insert_id(); 
	
	SendServerMessage(playerb, "You received a vehicle from %s in slot %i.", ReturnSettingsName(playerid, playerid), playerInsertID[playerb]);
	SendServerMessage(playerid, "You issued %s a new vehicle.", ReturnSettingsName(playerb, playerid));
	
	playerInsertID[playerb] = 0;
	SaveCharacter(playerb);
	return 1;
}

function:OnVehicleAlarm(vehicleid)
{
	return ToggleVehicleAlarms(vehicleid, false);
}
function:Query_ShowVehicleList(playerid, idx)
{
	new rows, fields; 
	cache_get_row_count(rows);
	cache_get_field_count(fields);
	
	new 
		vehicleDBID,
		vehicleModel,
		vehiclePlates[32],
		bool:isSpawned = false,
		color[512]
	;
	
	for(new i = 0; i < rows; i++)
	{
		cache_get_value_name_int(0, "VehicleDBID", vehicleDBID);
		cache_get_value_name_int(0, "VehicleModel", vehicleModel);
		cache_get_value_name(0, "VehiclePlates", vehiclePlates, 32); 
	}
	
	for(new id = 0; id < MAX_VEHICLES; id++)
	{
		if(VehicleInfo[id][E_VEHICLE_DBID] == vehicleDBID)
		{
			isSpawned = true;
		}
	}
	
	if(isSpawned)
		format(color, sizeof(color), "Spawned");
	
	else format(color, sizeof(color), "Despawn");
	
	PlayerTextDrawShow(playerid, VehicleBox[playerid]);
	PlayerTextDrawShow(playerid, VehicleHeader[playerid]);
	PlayerTextDrawShow(playerid, VehicleClose[playerid]);

	new str[128], str2[128];

	if(idx == 1)
	{
		PlayerTextDrawSetPreviewModel(playerid, VehicleModels[0][playerid], vehicleModel);
		format(str, sizeof(str), "%s", color);
		format(str2, sizeof(str2), "%s", vehiclePlates);

		PlayerTextDrawShow(playerid, VehicleModels[0][playerid]);
		PlayerTextDrawShow(playerid, VehiclePlate[0][playerid]);
		PlayerTextDrawShow(playerid, VehicleClick[0][playerid]);
		PlayerTextDrawSetString(playerid, VehicleClick[0][playerid], str);
		PlayerTextDrawSetString(playerid, VehiclePlate[0][playerid], str2);
	}
	else if(idx == 2)
	{
		PlayerTextDrawSetPreviewModel(playerid, VehicleModels[1][playerid], vehicleModel);
		format(str, sizeof(str), "%s", color);
		format(str2, sizeof(str2), "%s", vehiclePlates);

		PlayerTextDrawShow(playerid, VehicleModels[1][playerid]);
		PlayerTextDrawShow(playerid, VehiclePlate[1][playerid]);
		PlayerTextDrawShow(playerid, VehicleClick[1][playerid]);
		PlayerTextDrawSetString(playerid, VehicleClick[1][playerid], str);
		PlayerTextDrawSetString(playerid, VehiclePlate[1][playerid], str2);
	}
	else if(idx == 3)
	{
		PlayerTextDrawSetPreviewModel(playerid, VehicleModels[2][playerid], vehicleModel);
		format(str, sizeof(str), "%s", color);
		format(str2, sizeof(str2), "%s", vehiclePlates);

		PlayerTextDrawShow(playerid, VehicleModels[2][playerid]);
		PlayerTextDrawShow(playerid, VehiclePlate[2][playerid]);
		PlayerTextDrawShow(playerid, VehicleClick[2][playerid]);
		PlayerTextDrawSetString(playerid, VehicleClick[2][playerid], str);
		PlayerTextDrawSetString(playerid, VehiclePlate[2][playerid], str2);
	}
	SelectTextDraw(playerid, COLOR_YELLOW);
	return 1;
}

function:Float:GetVehicleSpeed(vehicleid)
{
	new
	    Float:x,
	    Float:y,
	    Float:z;

	if(GetVehicleVelocity(vehicleid, x, y, z))
	{
		return floatsqroot((x * x) + (y * y) + (z * z)) * 181.5;
	}

	return 0.0;
}
function:Float:GetVehicleTopSpeed(vehicleid)
{
    new model = GetVehicleModel(vehicleid);
 
    if (model)
    {
        return float(s_TopSpeed[(model - 400)]);
    }
    return 0.0;
}

stock IsVehicleOccupied(vehicleid)
{
	foreach(new i : Player){
		if(IsPlayerInVehicle(i, vehicleid))return true; 
	}
	return false;
}

stock SetVehicleHealthEx(vehicleid, Float:VehicleHealth)
{
	PauseVehicleAC(vehicleid);

	VehicleInfo[vehicleid][E_VEHICLE_HEALTH] = VehicleHealth;
	SetVehicleHealth(vehicleid, VehicleHealth);
	SaveVehicle(vehicleid);
	return true;
}

stock NotifyVehicleOwner(vehicleid)
{
	new playerid = INVALID_PLAYER_ID;

	foreach(new i : Player)
	{
		if(!strcmp(ReturnSettingsName(i, i), ReturnDBIDName(VehicleInfo[vehicleid][E_VEHICLE_OWNERDBID])))
		{
			playerid = i;
		}
	}
	if(playerid != INVALID_PLAYER_ID)
	{
		SendServerMessage(playerid, "SMS: Your vehicle alarm has been set off, Sender: Vehicle Alarm (Unknown)");
	}
	else return 1;
	return 1;
}

GetVehicleDriver(vehicleid) {
	foreach (new i : Player) {
		if (GetPlayerState(i) == PLAYER_STATE_DRIVER && GetPlayerVehicleID(i) == vehicleid) return i;
	}
	return INVALID_PLAYER_ID;
}

stock GetNearestVehicle(playerid)
{
 	new
	 	Float:fX,
	 	Float:fY,
	 	Float:fZ,
	 	Float:fSX,
	    Float:fSY,
		Float:fSZ,
		Float:fRadius;

	for (new i = 1, j = GetVehiclePoolSize(); i <= j; i ++)
	{
	    if (!IsVehicleStreamedIn(i, playerid))
		{
			continue;
	    }
	    else
	    {
			GetVehiclePos(i, fX, fY, fZ);

			GetVehicleModelInfo(GetVehicleModel(i), VEHICLE_MODEL_INFO_SIZE, fSX, fSY, fSZ);

			fRadius = floatsqroot((fSX + fSX) + (fSY + fSY));

			if (IsPlayerInRangeOfPoint(playerid, fRadius, fX, fY, fZ) && GetPlayerVirtualWorld(playerid) == GetVehicleVirtualWorld(i))
			{
				return i;
			}
		}
	}
	return INVALID_VEHICLE_ID;
}

stock GetVehicleBoot(vehicleid, &Float:x, &Float:y, &Float:z) 
{ 
    if (!GetVehicleModel(vehicleid) || vehicleid == INVALID_VEHICLE_ID) 
        return (x = 0.0, y = 0.0, z = 0.0), 0; 

    static 
        Float:pos[7] 
    ; 
    GetVehicleModelInfo(GetVehicleModel(vehicleid), VEHICLE_MODEL_INFO_SIZE, pos[0], pos[1], pos[2]); 
    GetVehiclePos(vehicleid, pos[3], pos[4], pos[5]); 
    GetVehicleZAngle(vehicleid, pos[6]); 

    x = pos[3] - (floatsqroot(pos[1] + pos[1]) * floatsin(-pos[6], degrees)); 
    y = pos[4] - (floatsqroot(pos[1] + pos[1]) * floatcos(-pos[6], degrees)); 
    z = pos[5]; 

    return 1; 
} 

stock GetVehicleHood(vehicleid, &Float:x, &Float:y, &Float:z) 
{ 
    if (!GetVehicleModel(vehicleid) || vehicleid == INVALID_VEHICLE_ID) 
        return (x = 0.0, y = 0.0, z = 0.0), 0; 

    static 
        Float:pos[7] 
    ; 
    GetVehicleModelInfo(GetVehicleModel(vehicleid), VEHICLE_MODEL_INFO_SIZE, pos[0], pos[1], pos[2]); 
    GetVehiclePos(vehicleid, pos[3], pos[4], pos[5]); 
    GetVehicleZAngle(vehicleid, pos[6]); 

    x = pos[3] + (floatsqroot(pos[1] + pos[1]) * floatsin(-pos[6], degrees)); 
    y = pos[4] + (floatsqroot(pos[1] + pos[1]) * floatcos(-pos[6], degrees)); 
    z = pos[5]; 

    return 1; 
}  

stock CountPlayerVehicles(playerid)
{
	new
		count = 0
	;
	
	for(new i = 1; i < 3; i++)
	{
		if(PlayerInfo[playerid][E_CHARACTER_OWNEDVEHICLE][i])
		{
			count++;
		}
	}
	return count;
}

stock ShowVehicleList(playerid)
{
	new thread[128]; 
	for(new i = 1; i < 3; i++)
	{
		if(PlayerInfo[playerid][E_CHARACTER_OWNEDVEHICLE][i])
		{
			mysql_format(ourConnection, thread, sizeof(thread), "SELECT * FROM vehicles WHERE VehicleDBID = %i", PlayerInfo[playerid][E_CHARACTER_OWNEDVEHICLE][i]); 
			mysql_pquery(ourConnection, thread, "Query_ShowVehicleList", "ii", playerid, i);
		}
	}

	return 1;
}

stock ResetDealershipVars(playerid)
{
	DealershipPlayerCar[playerid] = INVALID_VEHICLE_ID; 
	DealershipTotalCost[playerid] = 0;

	DealershipAlarmLevel[playerid] = 0;
	DealershipImmobLevel[playerid] = 1;
	
	DealershipLockLevel[playerid] = 0;
	
	for(new i = 0; i <2 ;i++) { DealershipCarColors[playerid][i] = 0; }
	return 1;
}

stock ShowDealerAppend(playerid)
{
	new
		caption[60],
		str[255]
	;

	format(caption, 60, "%s - {33AA33}%s:", g_aDealershipData[SubDealershipHolder[playerid]][E_DEALERSHIP_MODEL], FormatMoney(DealershipTotalCost[playerid])); 
	strcat(str, "Colors\n");
	strcat(str, "{FFFF00}Purchase Vehicle\n"); 
			
	ShowPlayerDialog(playerid, DIALOG_DEALERSHIP_APPEND, DIALOG_STYLE_LIST, caption, str, "Append", "<<"); 
	return 1; 
}

stock HasNoEngine(vehicleid)
{
	switch(GetVehicleModel(vehicleid))
	{
		case 481, 509, 510: return 1;
	}
	return 0;
}

stock IsABoat(vehicleid)
{
	switch (GetVehicleModel(vehicleid)) {
		case 430, 446, 452, 453, 454, 472, 473, 484, 493, 595: return 1;
	}
	return 0;
}

stock IsATrucker(vehicleid)
{
	switch (GetVehicleModel(vehicleid)) {
		case 600, 543, 605, 443, 422, 478, 554: return 1;
	}
	return 0;
}

stock SetVehicleToRespawnEx(vehicleid)
{
	VehicleInfo[vehicleid][E_VEHICLE_HEALTH] = 1000.0;
	SetVehicleToRespawn(vehicleid);
	return true;
}

function:StartThief(playerid, vehicleid)
{		
	new statusString[90]; 
	new engine, lights, alarm, doors, bonnet, boot, objective; 
	
	GetVehicleParamsEx(vehicleid, engine, lights, alarm, doors, bonnet, boot, objective);
			
	if(VehicleInfo[vehicleid][E_VEHICLE_LOCKED])
	{
		format(statusString, sizeof(statusString), "~g~%s UNLOCKED", ReturnVehicleName(vehicleid));
			
		SetVehicleParamsEx(vehicleid, engine, lights, alarm, false, bonnet, boot, objective);
		VehicleInfo[vehicleid][E_VEHICLE_LOCKED] = false;
	}
	GameTextForPlayer(playerid, statusString, 3000, 3);
	TogglePlayerControllable(playerid, true);
	RemovePlayerAttachedObject(playerid, 4);
	return 1;
}

function:TurnEngine(vehicleid)
{
	ToggleVehicleEngine(vehicleid, true); VehicleInfo[vehicleid][E_VEHICLE_ENGINE] = true;
	return 1;
}

stock IsVehicleUpgradeCompatible(model, componentid) // by AirKite
{
	switch(model)
	{
		case 400:
		{
			switch(componentid)
			{
				case 1008: return true;
				case 1009: return true;
				case 1010: return true;
				case 1013: return true;
				case 1018: return true;
				case 1019: return true;
				case 1020: return true;
				case 1021: return true;
				case 1024: return true;
				case 1025: return true;
				case 1073: return true;
				case 1074: return true;
				case 1075: return true;
				case 1076: return true;
				case 1077: return true;
				case 1078: return true;
				case 1079: return true;
				case 1080: return true;
				case 1081: return true;
				case 1082: return true;
				case 1083: return true;
				case 1084: return true;
				case 1085: return true;
				case 1087: return true;
				case 1096: return true;
				case 1097: return true;
				case 1098: return true;
			}
		}
		case 401:
		{
			switch(componentid)
			{
				case 1001: return true;
				case 1003: return true;
				case 1004: return true;
				case 1005: return true;
				case 1006: return true;
				case 1007: return true;
				case 1008: return true;
				case 1009: return true;
				case 1010: return true;
				case 1013: return true;
				case 1017: return true;
				case 1019: return true;
				case 1020: return true;
				case 1025: return true;
				case 1073: return true;
				case 1074: return true;
				case 1075: return true;
				case 1076: return true;
				case 1077: return true;
				case 1078: return true;
				case 1079: return true;
				case 1080: return true;
				case 1081: return true;
				case 1082: return true;
				case 1083: return true;
				case 1084: return true;
				case 1085: return true;
				case 1087: return true;
				case 1096: return true;
				case 1097: return true;
				case 1098: return true;
				case 1142: return true;
				case 1143: return true;
				case 1144: return true;
			}
		}
		case 404:
		{
			switch(componentid)
			{
				case 1000: return true;
				case 1002: return true;
				case 1007: return true;
				case 1008: return true;
				case 1009: return true;
				case 1010: return true;
				case 1013: return true;
				case 1016: return true;
				case 1017: return true;
				case 1019: return true;
				case 1020: return true;
				case 1021: return true;
				case 1025: return true;
				case 1073: return true;
				case 1074: return true;
				case 1075: return true;
				case 1076: return true;
				case 1077: return true;
				case 1078: return true;
				case 1079: return true;
				case 1080: return true;
				case 1081: return true;
				case 1082: return true;
				case 1083: return true;
				case 1084: return true;
				case 1085: return true;
				case 1087: return true;
				case 1096: return true;
				case 1097: return true;
				case 1098: return true;
			}
		}
		case 405:
		{
			switch(componentid)
			{
				case 1000: return true;
				case 1001: return true;
				case 1008: return true;
				case 1009: return true;
				case 1010: return true;
				case 1014: return true;
				case 1018: return true;
				case 1019: return true;
				case 1020: return true;
				case 1021: return true;
				case 1023: return true;
				case 1025: return true;
				case 1073: return true;
				case 1074: return true;
				case 1075: return true;
				case 1076: return true;
				case 1077: return true;
				case 1078: return true;
				case 1079: return true;
				case 1080: return true;
				case 1081: return true;
				case 1082: return true;
				case 1083: return true;
				case 1084: return true;
				case 1085: return true;
				case 1087: return true;
				case 1096: return true;
				case 1097: return true;
				case 1098: return true;
			}
		}
		case 410:
		{
			switch(componentid)
			{
				case 1001: return true;
				case 1003: return true;
				case 1007: return true;
				case 1008: return true;
				case 1009: return true;
				case 1010: return true;
				case 1013: return true;
				case 1017: return true;
				case 1019: return true;
				case 1020: return true;
				case 1021: return true;
				case 1023: return true;
				case 1024: return true;
				case 1025: return true;
				case 1073: return true;
				case 1074: return true;
				case 1075: return true;
				case 1076: return true;
				case 1077: return true;
				case 1078: return true;
				case 1079: return true;
				case 1080: return true;
				case 1081: return true;
				case 1082: return true;
				case 1083: return true;
				case 1084: return true;
				case 1085: return true;
				case 1087: return true;
				case 1096: return true;
				case 1097: return true;
				case 1098: return true;
			}
		}
		case 415:
		{
			switch(componentid)
			{
				case 1001: return true;
				case 1003: return true;
				case 1007: return true;
				case 1008: return true;
				case 1009: return true;
				case 1010: return true;
				case 1017: return true;
				case 1018: return true;
				case 1019: return true;
				case 1023: return true;
				case 1025: return true;
				case 1073: return true;
				case 1074: return true;
				case 1075: return true;
				case 1076: return true;
				case 1077: return true;
				case 1078: return true;
				case 1079: return true;
				case 1080: return true;
				case 1081: return true;
				case 1082: return true;
				case 1083: return true;
				case 1084: return true;
				case 1085: return true;
				case 1087: return true;
				case 1096: return true;
				case 1097: return true;
				case 1098: return true;
			}
		}
		case 418:
		{
			switch(componentid)
			{
				case 1002: return true;
				case 1006: return true;
				case 1008: return true;
				case 1009: return true;
				case 1010: return true;
				case 1016: return true;
				case 1020: return true;
				case 1021: return true;
				case 1025: return true;
				case 1073: return true;
				case 1074: return true;
				case 1075: return true;
				case 1076: return true;
				case 1077: return true;
				case 1078: return true;
				case 1079: return true;
				case 1080: return true;
				case 1081: return true;
				case 1082: return true;
				case 1083: return true;
				case 1084: return true;
				case 1085: return true;
				case 1087: return true;
				case 1096: return true;
				case 1097: return true;
				case 1098: return true;
			}
		}
		case 420:
		{
			switch(componentid)
			{
				case 1001: return true;
				case 1003: return true;
				case 1004: return true;
				case 1005: return true;
				case 1008: return true;
				case 1009: return true;
				case 1010: return true;
				case 1019: return true;
				case 1021: return true;
				case 1025: return true;
				case 1073: return true;
				case 1074: return true;
				case 1075: return true;
				case 1076: return true;
				case 1077: return true;
				case 1078: return true;
				case 1079: return true;
				case 1080: return true;
				case 1081: return true;
				case 1082: return true;
				case 1083: return true;
				case 1084: return true;
				case 1085: return true;
				case 1087: return true;
				case 1096: return true;
				case 1097: return true;
				case 1098: return true;
			}
		}
		case 421:
		{
			switch(componentid)
			{
				case 1000: return true;
				case 1008: return true;
				case 1009: return true;
				case 1010: return true;
				case 1014: return true;
				case 1016: return true;
				case 1018: return true;
				case 1019: return true;
				case 1020: return true;
				case 1021: return true;
				case 1023: return true;
				case 1025: return true;
				case 1073: return true;
				case 1074: return true;
				case 1075: return true;
				case 1076: return true;
				case 1077: return true;
				case 1078: return true;
				case 1079: return true;
				case 1080: return true;
				case 1081: return true;
				case 1082: return true;
				case 1083: return true;
				case 1084: return true;
				case 1085: return true;
				case 1087: return true;
				case 1096: return true;
				case 1097: return true;
				case 1098: return true;
			}
		}
		case 422:
		{
			switch(componentid)
			{
				case 1007: return true;
				case 1008: return true;
				case 1009: return true;
				case 1010: return true;
				case 1013: return true;
				case 1017: return true;
				case 1019: return true;
				case 1020: return true;
				case 1021: return true;
				case 1025: return true;
				case 1073: return true;
				case 1074: return true;
				case 1075: return true;
				case 1076: return true;
				case 1077: return true;
				case 1078: return true;
				case 1079: return true;
				case 1080: return true;
				case 1081: return true;
				case 1082: return true;
				case 1083: return true;
				case 1084: return true;
				case 1085: return true;
				case 1087: return true;
				case 1096: return true;
				case 1097: return true;
				case 1098: return true;
			}
		}
		case 426:
		{
			switch(componentid)
			{
				case 1001: return true;
				case 1003: return true;
				case 1004: return true;
				case 1005: return true;
				case 1006: return true;
				case 1008: return true;
				case 1009: return true;
				case 1010: return true;
				case 1019: return true;
				case 1021: return true;
				case 1025: return true;
				case 1073: return true;
				case 1074: return true;
				case 1075: return true;
				case 1076: return true;
				case 1077: return true;
				case 1078: return true;
				case 1079: return true;
				case 1080: return true;
				case 1081: return true;
				case 1082: return true;
				case 1083: return true;
				case 1084: return true;
				case 1085: return true;
				case 1087: return true;
				case 1096: return true;
				case 1097: return true;
				case 1098: return true;
			}
		}
		case 436:
		{
			switch(componentid)
			{
				case 1001: return true;
				case 1003: return true;
				case 1006: return true;
				case 1007: return true;
				case 1008: return true;
				case 1009: return true;
				case 1010: return true;
				case 1013: return true;
				case 1017: return true;
				case 1019: return true;
				case 1020: return true;
				case 1021: return true;
				case 1022: return true;
				case 1025: return true;
				case 1073: return true;
				case 1074: return true;
				case 1075: return true;
				case 1076: return true;
				case 1077: return true;
				case 1078: return true;
				case 1079: return true;
				case 1080: return true;
				case 1081: return true;
				case 1082: return true;
				case 1083: return true;
				case 1084: return true;
				case 1085: return true;
				case 1087: return true;
				case 1096: return true;
				case 1097: return true;
				case 1098: return true;
			}
		}
		case 439:
		{
			switch(componentid)
			{
				case 1001: return true;
				case 1003: return true;
				case 1007: return true;
				case 1008: return true;
				case 1009: return true;
				case 1010: return true;
				case 1013: return true;
				case 1017: return true;
				case 1023: return true;
				case 1025: return true;
				case 1073: return true;
				case 1074: return true;
				case 1075: return true;
				case 1076: return true;
				case 1077: return true;
				case 1078: return true;
				case 1079: return true;
				case 1080: return true;
				case 1081: return true;
				case 1082: return true;
				case 1083: return true;
				case 1084: return true;
				case 1085: return true;
				case 1087: return true;
				case 1096: return true;
				case 1097: return true;
				case 1098: return true;
				case 1142: return true;
				case 1143: return true;
				case 1144: return true;
				case 1145: return true;
			}
		}
		case 477:
		{
			switch(componentid)
			{
				case 1006: return true;
				case 1007: return true;
				case 1008: return true;
				case 1009: return true;
				case 1010: return true;
				case 1017: return true;
				case 1018: return true;
				case 1019: return true;
				case 1020: return true;
				case 1021: return true;
				case 1025: return true;
				case 1073: return true;
				case 1074: return true;
				case 1075: return true;
				case 1076: return true;
				case 1077: return true;
				case 1078: return true;
				case 1079: return true;
				case 1080: return true;
				case 1081: return true;
				case 1082: return true;
				case 1083: return true;
				case 1084: return true;
				case 1085: return true;
				case 1087: return true;
				case 1096: return true;
				case 1097: return true;
				case 1098: return true;
			}
		}
		case 478:
		{
			switch(componentid)
			{
				case 1004: return true;
				case 1005: return true;
				case 1008: return true;
				case 1009: return true;
				case 1010: return true;
				case 1012: return true;
				case 1013: return true;
				case 1020: return true;
				case 1021: return true;
				case 1022: return true;
				case 1024: return true;
				case 1025: return true;
				case 1073: return true;
				case 1074: return true;
				case 1075: return true;
				case 1076: return true;
				case 1077: return true;
				case 1078: return true;
				case 1079: return true;
				case 1080: return true;
				case 1081: return true;
				case 1082: return true;
				case 1083: return true;
				case 1084: return true;
				case 1085: return true;
				case 1087: return true;
				case 1096: return true;
				case 1097: return true;
				case 1098: return true;
			}
		}
		case 489:
		{
			switch(componentid)
			{
				case 1000: return true;
				case 1002: return true;
				case 1004: return true;
				case 1005: return true;
				case 1006: return true;
				case 1008: return true;
				case 1009: return true;
				case 1010: return true;
				case 1013: return true;
				case 1016: return true;
				case 1018: return true;
				case 1019: return true;
				case 1020: return true;
				case 1024: return true;
				case 1025: return true;
				case 1073: return true;
				case 1074: return true;
				case 1075: return true;
				case 1076: return true;
				case 1077: return true;
				case 1078: return true;
				case 1079: return true;
				case 1080: return true;
				case 1081: return true;
				case 1082: return true;
				case 1083: return true;
				case 1084: return true;
				case 1085: return true;
				case 1087: return true;
				case 1096: return true;
				case 1097: return true;
				case 1098: return true;
			}
		}
		case 491:
		{
			switch(componentid)
			{
				case 1003: return true;
				case 1007: return true;
				case 1008: return true;
				case 1009: return true;
				case 1010: return true;
				case 1014: return true;
				case 1017: return true;
				case 1018: return true;
				case 1019: return true;
				case 1020: return true;
				case 1021: return true;
				case 1023: return true;
				case 1025: return true;
				case 1073: return true;
				case 1074: return true;
				case 1075: return true;
				case 1076: return true;
				case 1077: return true;
				case 1078: return true;
				case 1079: return true;
				case 1080: return true;
				case 1081: return true;
				case 1082: return true;
				case 1083: return true;
				case 1084: return true;
				case 1085: return true;
				case 1087: return true;
				case 1096: return true;
				case 1097: return true;
				case 1098: return true;
				case 1142: return true;
				case 1143: return true;
				case 1144: return true;
				case 1145: return true;
			}
		}
		case 492:
		{
			switch(componentid)
			{
				case 1000: return true;
				case 1004: return true;
				case 1005: return true;
				case 1006: return true;
				case 1008: return true;
				case 1009: return true;
				case 1010: return true;
				case 1016: return true;
				case 1025: return true;
				case 1073: return true;
				case 1074: return true;
				case 1075: return true;
				case 1076: return true;
				case 1077: return true;
				case 1078: return true;
				case 1079: return true;
				case 1080: return true;
				case 1081: return true;
				case 1082: return true;
				case 1083: return true;
				case 1084: return true;
				case 1085: return true;
				case 1087: return true;
				case 1096: return true;
				case 1097: return true;
				case 1098: return true;
			}
		}
		case 496:
		{
			switch(componentid)
			{
				case 1001: return true;
				case 1002: return true;
				case 1003: return true;
				case 1006: return true;
				case 1007: return true;
				case 1008: return true;
				case 1009: return true;
				case 1010: return true;
				case 1011: return true;
				case 1017: return true;
				case 1019: return true;
				case 1020: return true;
				case 1023: return true;
				case 1025: return true;
				case 1073: return true;
				case 1074: return true;
				case 1075: return true;
				case 1076: return true;
				case 1077: return true;
				case 1078: return true;
				case 1079: return true;
				case 1080: return true;
				case 1081: return true;
				case 1082: return true;
				case 1083: return true;
				case 1084: return true;
				case 1085: return true;
				case 1087: return true;
				case 1096: return true;
				case 1097: return true;
				case 1098: return true;
				case 1142: return true;
				case 1143: return true;
			}
		}
		case 500:
		{
			switch(componentid)
			{
				case 1008: return true;
				case 1009: return true;
				case 1010: return true;
				case 1013: return true;
				case 1019: return true;
				case 1020: return true;
				case 1021: return true;
				case 1024: return true;
				case 1025: return true;
				case 1073: return true;
				case 1074: return true;
				case 1075: return true;
				case 1076: return true;
				case 1077: return true;
				case 1078: return true;
				case 1079: return true;
				case 1080: return true;
				case 1081: return true;
				case 1082: return true;
				case 1083: return true;
				case 1084: return true;
				case 1085: return true;
				case 1087: return true;
				case 1096: return true;
				case 1097: return true;
				case 1098: return true;
			}
		}
		case 516:
		{
			switch(componentid)
			{
				case 1000: return true;
				case 1002: return true;
				case 1004: return true;
				case 1007: return true;
				case 1008: return true;
				case 1009: return true;
				case 1010: return true;
				case 1015: return true;
				case 1016: return true;
				case 1017: return true;
				case 1018: return true;
				case 1019: return true;
				case 1020: return true;
				case 1021: return true;
				case 1025: return true;
				case 1073: return true;
				case 1074: return true;
				case 1075: return true;
				case 1076: return true;
				case 1077: return true;
				case 1078: return true;
				case 1079: return true;
				case 1080: return true;
				case 1081: return true;
				case 1082: return true;
				case 1083: return true;
				case 1084: return true;
				case 1085: return true;
				case 1087: return true;
				case 1096: return true;
				case 1097: return true;
				case 1098: return true;
			}
		}
		case 517:
		{
			switch(componentid)
			{
				case 1002: return true;
				case 1003: return true;
				case 1007: return true;
				case 1008: return true;
				case 1009: return true;
				case 1010: return true;
				case 1016: return true;
				case 1017: return true;
				case 1018: return true;
				case 1019: return true;
				case 1020: return true;
				case 1023: return true;
				case 1025: return true;
				case 1073: return true;
				case 1074: return true;
				case 1075: return true;
				case 1076: return true;
				case 1077: return true;
				case 1078: return true;
				case 1079: return true;
				case 1080: return true;
				case 1081: return true;
				case 1082: return true;
				case 1083: return true;
				case 1084: return true;
				case 1085: return true;
				case 1087: return true;
				case 1096: return true;
				case 1097: return true;
				case 1098: return true;
				case 1142: return true;
				case 1143: return true;
				case 1144: return true;
				case 1145: return true;
			}
		}
		case 518:
		{
			switch(componentid)
			{
				case 1001: return true;
				case 1003: return true;
				case 1005: return true;
				case 1006: return true;
				case 1007: return true;
				case 1008: return true;
				case 1009: return true;
				case 1010: return true;
				case 1013: return true;
				case 1017: return true;
				case 1018: return true;
				case 1020: return true;
				case 1023: return true;
				case 1025: return true;
				case 1073: return true;
				case 1074: return true;
				case 1075: return true;
				case 1076: return true;
				case 1077: return true;
				case 1078: return true;
				case 1079: return true;
				case 1080: return true;
				case 1081: return true;
				case 1082: return true;
				case 1083: return true;
				case 1084: return true;
				case 1085: return true;
				case 1087: return true;
				case 1096: return true;
				case 1097: return true;
				case 1098: return true;
				case 1142: return true;
				case 1143: return true;
				case 1144: return true;
				case 1145: return true;
			}
		}
		case 527:
		{
			switch(componentid)
			{
				case 1001: return true;
				case 1007: return true;
				case 1008: return true;
				case 1009: return true;
				case 1010: return true;
				case 1014: return true;
				case 1015: return true;
				case 1017: return true;
				case 1018: return true;
				case 1020: return true;
				case 1021: return true;
				case 1025: return true;
				case 1073: return true;
				case 1074: return true;
				case 1075: return true;
				case 1076: return true;
				case 1077: return true;
				case 1078: return true;
				case 1079: return true;
				case 1080: return true;
				case 1081: return true;
				case 1082: return true;
				case 1083: return true;
				case 1084: return true;
				case 1085: return true;
				case 1087: return true;
				case 1096: return true;
				case 1097: return true;
				case 1098: return true;
			}
		}
		case 529:
		{
			switch(componentid)
			{
				case 1001: return true;
				case 1003: return true;
				case 1006: return true;
				case 1007: return true;
				case 1008: return true;
				case 1009: return true;
				case 1010: return true;
				case 1011: return true;
				case 1012: return true;
				case 1017: return true;
				case 1018: return true;
				case 1019: return true;
				case 1020: return true;
				case 1023: return true;
				case 1025: return true;
				case 1073: return true;
				case 1074: return true;
				case 1075: return true;
				case 1076: return true;
				case 1077: return true;
				case 1078: return true;
				case 1079: return true;
				case 1080: return true;
				case 1081: return true;
				case 1082: return true;
				case 1083: return true;
				case 1084: return true;
				case 1085: return true;
				case 1087: return true;
				case 1096: return true;
				case 1097: return true;
				case 1098: return true;
			}
		}
		case 534:
		{
			switch(componentid)
			{
				case 1008: return true;
				case 1009: return true;
				case 1010: return true;
				case 1025: return true;
				case 1073: return true;
				case 1074: return true;
				case 1075: return true;
				case 1076: return true;
				case 1077: return true;
				case 1078: return true;
				case 1079: return true;
				case 1080: return true;
				case 1081: return true;
				case 1082: return true;
				case 1083: return true;
				case 1084: return true;
				case 1085: return true;
				case 1087: return true;
				case 1096: return true;
				case 1097: return true;
				case 1098: return true;
				case 1100: return true;
				case 1101: return true;
				case 1106: return true;
				case 1122: return true;
				case 1123: return true;
				case 1124: return true;
				case 1125: return true;
				case 1126: return true;
				case 1127: return true;
				case 1178: return true;
				case 1179: return true;
				case 1180: return true;
				case 1185: return true;
			}
		}
		case 535:
		{
			switch(componentid)
			{
				case 1008: return true;
				case 1009: return true;
				case 1010: return true;
				case 1025: return true;
				case 1073: return true;
				case 1074: return true;
				case 1075: return true;
				case 1076: return true;
				case 1077: return true;
				case 1078: return true;
				case 1079: return true;
				case 1080: return true;
				case 1081: return true;
				case 1082: return true;
				case 1083: return true;
				case 1084: return true;
				case 1085: return true;
				case 1087: return true;
				case 1096: return true;
				case 1097: return true;
				case 1098: return true;
				case 1109: return true;
				case 1110: return true;
				case 1113: return true;
				case 1114: return true;
				case 1115: return true;
				case 1116: return true;
				case 1117: return true;
				case 1118: return true;
				case 1119: return true;
				case 1120: return true;
				case 1121: return true;
			}
		}
		case 536:
		{
			switch(componentid)
			{
				case 1008: return true;
				case 1009: return true;
				case 1010: return true;
				case 1025: return true;
				case 1073: return true;
				case 1074: return true;
				case 1075: return true;
				case 1076: return true;
				case 1077: return true;
				case 1078: return true;
				case 1079: return true;
				case 1080: return true;
				case 1081: return true;
				case 1082: return true;
				case 1083: return true;
				case 1084: return true;
				case 1085: return true;
				case 1087: return true;
				case 1096: return true;
				case 1097: return true;
				case 1098: return true;
				case 1103: return true;
				case 1104: return true;
				case 1105: return true;
				case 1107: return true;
				case 1108: return true;
				case 1128: return true;
				case 1181: return true;
				case 1182: return true;
				case 1183: return true;
				case 1184: return true;
			}
		}
		case 540:
		{
			switch(componentid)
			{
				case 1001: return true;
				case 1004: return true;
				case 1006: return true;
				case 1007: return true;
				case 1008: return true;
				case 1009: return true;
				case 1010: return true;
				case 1017: return true;
				case 1018: return true;
				case 1019: return true;
				case 1020: return true;
				case 1023: return true;
				case 1024: return true;
				case 1025: return true;
				case 1073: return true;
				case 1074: return true;
				case 1075: return true;
				case 1076: return true;
				case 1077: return true;
				case 1078: return true;
				case 1079: return true;
				case 1080: return true;
				case 1081: return true;
				case 1082: return true;
				case 1083: return true;
				case 1084: return true;
				case 1085: return true;
				case 1087: return true;
				case 1096: return true;
				case 1097: return true;
				case 1098: return true;
				case 1142: return true;
				case 1143: return true;
				case 1144: return true;
				case 1145: return true;
			}
		}
		case 542:
		{
			switch(componentid)
			{
				case 1008: return true;
				case 1009: return true;
				case 1010: return true;
				case 1014: return true;
				case 1015: return true;
				case 1018: return true;
				case 1019: return true;
				case 1020: return true;
				case 1021: return true;
				case 1025: return true;
				case 1073: return true;
				case 1074: return true;
				case 1075: return true;
				case 1076: return true;
				case 1077: return true;
				case 1078: return true;
				case 1079: return true;
				case 1080: return true;
				case 1081: return true;
				case 1082: return true;
				case 1083: return true;
				case 1084: return true;
				case 1085: return true;
				case 1087: return true;
				case 1096: return true;
				case 1097: return true;
				case 1098: return true;
				case 1144: return true;
				case 1145: return true;
			}
		}
		case 546:
		{
			switch(componentid)
			{
				case 1001: return true;
				case 1002: return true;
				case 1004: return true;
				case 1006: return true;
				case 1007: return true;
				case 1008: return true;
				case 1009: return true;
				case 1010: return true;
				case 1017: return true;
				case 1018: return true;
				case 1019: return true;
				case 1023: return true;
				case 1024: return true;
				case 1025: return true;
				case 1073: return true;
				case 1074: return true;
				case 1075: return true;
				case 1076: return true;
				case 1077: return true;
				case 1078: return true;
				case 1079: return true;
				case 1080: return true;
				case 1081: return true;
				case 1082: return true;
				case 1083: return true;
				case 1084: return true;
				case 1085: return true;
				case 1087: return true;
				case 1096: return true;
				case 1097: return true;
				case 1098: return true;
				case 1142: return true;
				case 1143: return true;
				case 1144: return true;
				case 1145: return true;
			}
		}
		case 547:
		{
			switch(componentid)
			{
				case 1000: return true;
				case 1003: return true;
				case 1008: return true;
				case 1009: return true;
				case 1010: return true;
				case 1016: return true;
				case 1018: return true;
				case 1019: return true;
				case 1020: return true;
				case 1021: return true;
				case 1025: return true;
				case 1073: return true;
				case 1074: return true;
				case 1075: return true;
				case 1076: return true;
				case 1077: return true;
				case 1078: return true;
				case 1079: return true;
				case 1080: return true;
				case 1081: return true;
				case 1082: return true;
				case 1083: return true;
				case 1084: return true;
				case 1085: return true;
				case 1087: return true;
				case 1096: return true;
				case 1097: return true;
				case 1098: return true;
				case 1142: return true;
				case 1143: return true;
			}
		}
		case 549:
		{
			switch(componentid)
			{
				case 1001: return true;
				case 1003: return true;
				case 1007: return true;
				case 1008: return true;
				case 1009: return true;
				case 1010: return true;
				case 1011: return true;
				case 1012: return true;
				case 1017: return true;
				case 1018: return true;
				case 1019: return true;
				case 1020: return true;
				case 1023: return true;
				case 1025: return true;
				case 1073: return true;
				case 1074: return true;
				case 1075: return true;
				case 1076: return true;
				case 1077: return true;
				case 1078: return true;
				case 1079: return true;
				case 1080: return true;
				case 1081: return true;
				case 1082: return true;
				case 1083: return true;
				case 1084: return true;
				case 1085: return true;
				case 1087: return true;
				case 1096: return true;
				case 1097: return true;
				case 1098: return true;
				case 1142: return true;
				case 1143: return true;
				case 1144: return true;
				case 1145: return true;
			}
		}
		case 550:
		{
			switch(componentid)
			{
				case 1001: return true;
				case 1003: return true;
				case 1004: return true;
				case 1005: return true;
				case 1006: return true;
				case 1008: return true;
				case 1009: return true;
				case 1010: return true;
				case 1018: return true;
				case 1019: return true;
				case 1020: return true;
				case 1023: return true;
				case 1025: return true;
				case 1073: return true;
				case 1074: return true;
				case 1075: return true;
				case 1076: return true;
				case 1077: return true;
				case 1078: return true;
				case 1079: return true;
				case 1080: return true;
				case 1081: return true;
				case 1082: return true;
				case 1083: return true;
				case 1084: return true;
				case 1085: return true;
				case 1087: return true;
				case 1096: return true;
				case 1097: return true;
				case 1098: return true;
				case 1142: return true;
				case 1143: return true;
				case 1144: return true;
				case 1145: return true;
			}
		}
		case 551:
		{
			switch(componentid)
			{
				case 1002: return true;
				case 1003: return true;
				case 1005: return true;
				case 1006: return true;
				case 1008: return true;
				case 1009: return true;
				case 1010: return true;
				case 1016: return true;
				case 1018: return true;
				case 1019: return true;
				case 1020: return true;
				case 1021: return true;
				case 1023: return true;
				case 1025: return true;
				case 1073: return true;
				case 1074: return true;
				case 1075: return true;
				case 1076: return true;
				case 1077: return true;
				case 1078: return true;
				case 1079: return true;
				case 1080: return true;
				case 1081: return true;
				case 1082: return true;
				case 1083: return true;
				case 1084: return true;
				case 1085: return true;
				case 1087: return true;
				case 1096: return true;
				case 1097: return true;
				case 1098: return true;
			}
		}
		case 558:
		{
			switch(componentid)
			{
				case 1008: return true;
				case 1009: return true;
				case 1010: return true;
				case 1025: return true;
				case 1073: return true;
				case 1074: return true;
				case 1075: return true;
				case 1076: return true;
				case 1077: return true;
				case 1078: return true;
				case 1079: return true;
				case 1080: return true;
				case 1081: return true;
				case 1082: return true;
				case 1083: return true;
				case 1084: return true;
				case 1085: return true;
				case 1087: return true;
				case 1088: return true;
				case 1089: return true;
				case 1090: return true;
				case 1091: return true;
				case 1092: return true;
				case 1093: return true;
				case 1094: return true;
				case 1095: return true;
				case 1096: return true;
				case 1097: return true;
				case 1098: return true;
				case 1163: return true;
				case 1164: return true;
				case 1165: return true;
				case 1166: return true;
				case 1167: return true;
				case 1168: return true;
			}
		}
		case 559:
		{
			switch(componentid)
			{
				case 1008: return true;
				case 1009: return true;
				case 1010: return true;
				case 1025: return true;
				case 1065: return true;
				case 1066: return true;
				case 1067: return true;
				case 1068: return true;
				case 1069: return true;
				case 1070: return true;
				case 1071: return true;
				case 1072: return true;
				case 1073: return true;
				case 1074: return true;
				case 1075: return true;
				case 1076: return true;
				case 1077: return true;
				case 1078: return true;
				case 1079: return true;
				case 1080: return true;
				case 1081: return true;
				case 1082: return true;
				case 1083: return true;
				case 1084: return true;
				case 1085: return true;
				case 1087: return true;
				case 1096: return true;
				case 1097: return true;
				case 1098: return true;
				case 1158: return true;
				case 1159: return true;
				case 1160: return true;
				case 1161: return true;
				case 1162: return true;
				case 1173: return true;
			}
		}
		case 560:
		{
			switch(componentid)
			{
				case 1008: return true;
				case 1009: return true;
				case 1010: return true;
				case 1025: return true;
				case 1026: return true;
				case 1027: return true;
				case 1028: return true;
				case 1029: return true;
				case 1030: return true;
				case 1031: return true;
				case 1032: return true;
				case 1033: return true;
				case 1073: return true;
				case 1074: return true;
				case 1075: return true;
				case 1076: return true;
				case 1077: return true;
				case 1078: return true;
				case 1079: return true;
				case 1080: return true;
				case 1081: return true;
				case 1082: return true;
				case 1083: return true;
				case 1084: return true;
				case 1085: return true;
				case 1087: return true;
				case 1096: return true;
				case 1097: return true;
				case 1098: return true;
				case 1138: return true;
				case 1139: return true;
				case 1140: return true;
				case 1141: return true;
				case 1169: return true;
				case 1170: return true;
			}
		}
		case 561:
		{
			switch(componentid)
			{
				case 1008: return true;
				case 1009: return true;
				case 1010: return true;
				case 1025: return true;
				case 1055: return true;
				case 1056: return true;
				case 1057: return true;
				case 1058: return true;
				case 1059: return true;
				case 1060: return true;
				case 1061: return true;
				case 1062: return true;
				case 1063: return true;
				case 1064: return true;
				case 1073: return true;
				case 1074: return true;
				case 1075: return true;
				case 1076: return true;
				case 1077: return true;
				case 1078: return true;
				case 1079: return true;
				case 1080: return true;
				case 1081: return true;
				case 1082: return true;
				case 1083: return true;
				case 1084: return true;
				case 1085: return true;
				case 1087: return true;
				case 1096: return true;
				case 1097: return true;
				case 1098: return true;
				case 1154: return true;
				case 1155: return true;
				case 1156: return true;
				case 1157: return true;
			}
		}
		case 562:
		{
			switch(componentid)
			{
				case 1008: return true;
				case 1009: return true;
				case 1010: return true;
				case 1025: return true;
				case 1034: return true;
				case 1035: return true;
				case 1036: return true;
				case 1037: return true;
				case 1038: return true;
				case 1039: return true;
				case 1040: return true;
				case 1041: return true;
				case 1073: return true;
				case 1074: return true;
				case 1075: return true;
				case 1076: return true;
				case 1077: return true;
				case 1078: return true;
				case 1079: return true;
				case 1080: return true;
				case 1081: return true;
				case 1082: return true;
				case 1083: return true;
				case 1084: return true;
				case 1085: return true;
				case 1087: return true;
				case 1096: return true;
				case 1097: return true;
				case 1098: return true;
				case 1146: return true;
				case 1147: return true;
				case 1148: return true;
				case 1149: return true;
				case 1171: return true;
				case 1172: return true;
			}
		}
		case 565:
		{
			switch(componentid)
			{
				case 1008: return true;
				case 1009: return true;
				case 1010: return true;
				case 1025: return true;
				case 1045: return true;
				case 1046: return true;
				case 1047: return true;
				case 1048: return true;
				case 1049: return true;
				case 1050: return true;
				case 1051: return true;
				case 1052: return true;
				case 1053: return true;
				case 1054: return true;
				case 1073: return true;
				case 1074: return true;
				case 1075: return true;
				case 1076: return true;
				case 1077: return true;
				case 1078: return true;
				case 1079: return true;
				case 1080: return true;
				case 1081: return true;
				case 1082: return true;
				case 1083: return true;
				case 1084: return true;
				case 1085: return true;
				case 1087: return true;
				case 1096: return true;
				case 1097: return true;
				case 1098: return true;
				case 1150: return true;
				case 1151: return true;
				case 1152: return true;
				case 1153: return true;
			}
		}
		case 567:
		{
			switch(componentid)
			{
				case 1008: return true;
				case 1009: return true;
				case 1010: return true;
				case 1025: return true;
				case 1073: return true;
				case 1074: return true;
				case 1075: return true;
				case 1076: return true;
				case 1077: return true;
				case 1078: return true;
				case 1079: return true;
				case 1080: return true;
				case 1081: return true;
				case 1082: return true;
				case 1083: return true;
				case 1084: return true;
				case 1085: return true;
				case 1087: return true;
				case 1096: return true;
				case 1097: return true;
				case 1098: return true;
				case 1102: return true;
				case 1129: return true;
				case 1130: return true;
				case 1131: return true;
				case 1132: return true;
				case 1133: return true;
				case 1186: return true;
				case 1187: return true;
				case 1188: return true;
				case 1189: return true;
			}
		}
		case 575:
		{
			switch(componentid)
			{
				case 1008: return true;
				case 1009: return true;
				case 1010: return true;
				case 1025: return true;
				case 1042: return true;
				case 1043: return true;
				case 1044: return true;
				case 1073: return true;
				case 1074: return true;
				case 1075: return true;
				case 1076: return true;
				case 1077: return true;
				case 1078: return true;
				case 1079: return true;
				case 1080: return true;
				case 1081: return true;
				case 1082: return true;
				case 1083: return true;
				case 1084: return true;
				case 1085: return true;
				case 1087: return true;
				case 1096: return true;
				case 1097: return true;
				case 1098: return true;
				case 1099: return true;
				case 1174: return true;
				case 1175: return true;
				case 1176: return true;
				case 1177: return true;
			}
		}
		case 576:
		{
			switch(componentid)
			{
				case 1008: return true;
				case 1009: return true;
				case 1010: return true;
				case 1025: return true;
				case 1073: return true;
				case 1074: return true;
				case 1075: return true;
				case 1076: return true;
				case 1077: return true;
				case 1078: return true;
				case 1079: return true;
				case 1080: return true;
				case 1081: return true;
				case 1082: return true;
				case 1083: return true;
				case 1084: return true;
				case 1085: return true;
				case 1087: return true;
				case 1096: return true;
				case 1097: return true;
				case 1098: return true;
				case 1134: return true;
				case 1135: return true;
				case 1136: return true;
				case 1137: return true;
				case 1190: return true;
				case 1191: return true;
				case 1192: return true;
				case 1193: return true;
			}
		}
		case 580:
		{
			switch(componentid)
			{
				case 1001: return true;
				case 1006: return true;
				case 1007: return true;
				case 1008: return true;
				case 1009: return true;
				case 1010: return true;
				case 1017: return true;
				case 1018: return true;
				case 1020: return true;
				case 1023: return true;
				case 1025: return true;
				case 1073: return true;
				case 1074: return true;
				case 1075: return true;
				case 1076: return true;
				case 1077: return true;
				case 1078: return true;
				case 1079: return true;
				case 1080: return true;
				case 1081: return true;
				case 1082: return true;
				case 1083: return true;
				case 1084: return true;
				case 1085: return true;
				case 1087: return true;
				case 1096: return true;
				case 1097: return true;
				case 1098: return true;
			}
		}
		case 585:
		{
			switch(componentid)
			{
				case 1001: return true;
				case 1003: return true;
				case 1006: return true;
				case 1007: return true;
				case 1008: return true;
				case 1009: return true;
				case 1010: return true;
				case 1013: return true;
				case 1017: return true;
				case 1018: return true;
				case 1019: return true;
				case 1020: return true;
				case 1023: return true;
				case 1025: return true;
				case 1073: return true;
				case 1074: return true;
				case 1075: return true;
				case 1076: return true;
				case 1077: return true;
				case 1078: return true;
				case 1079: return true;
				case 1080: return true;
				case 1081: return true;
				case 1082: return true;
				case 1083: return true;
				case 1084: return true;
				case 1085: return true;
				case 1087: return true;
				case 1096: return true;
				case 1097: return true;
				case 1098: return true;
				case 1142: return true;
				case 1143: return true;
				case 1144: return true;
				case 1145: return true;
			}
		}
		case 589:
		{
			switch(componentid)
			{
				case 1000: return true;
				case 1004: return true;
				case 1005: return true;
				case 1006: return true;
				case 1007: return true;
				case 1008: return true;
				case 1009: return true;
				case 1010: return true;
				case 1013: return true;
				case 1016: return true;
				case 1017: return true;
				case 1018: return true;
				case 1020: return true;
				case 1024: return true;
				case 1025: return true;
				case 1073: return true;
				case 1074: return true;
				case 1075: return true;
				case 1076: return true;
				case 1077: return true;
				case 1078: return true;
				case 1079: return true;
				case 1080: return true;
				case 1081: return true;
				case 1082: return true;
				case 1083: return true;
				case 1084: return true;
				case 1085: return true;
				case 1087: return true;
				case 1096: return true;
				case 1097: return true;
				case 1098: return true;
				case 1144: return true;
				case 1145: return true;
			}
		}
		case 600:
		{
			switch(componentid)
			{
				case 1004: return true;
				case 1005: return true;
				case 1006: return true;
				case 1007: return true;
				case 1008: return true;
				case 1009: return true;
				case 1010: return true;
				case 1013: return true;
				case 1017: return true;
				case 1018: return true;
				case 1020: return true;
				case 1022: return true;
				case 1025: return true;
				case 1073: return true;
				case 1074: return true;
				case 1075: return true;
				case 1076: return true;
				case 1077: return true;
				case 1078: return true;
				case 1079: return true;
				case 1080: return true;
				case 1081: return true;
				case 1082: return true;
				case 1083: return true;
				case 1084: return true;
				case 1085: return true;
				case 1087: return true;
				case 1096: return true;
				case 1097: return true;
				case 1098: return true;
			}
		}
		case 603:
		{
			switch(componentid)
			{
				case 1001: return true;
				case 1006: return true;
				case 1007: return true;
				case 1008: return true;
				case 1009: return true;
				case 1010: return true;
				case 1017: return true;
				case 1018: return true;
				case 1019: return true;
				case 1020: return true;
				case 1023: return true;
				case 1024: return true;
				case 1025: return true;
				case 1073: return true;
				case 1074: return true;
				case 1075: return true;
				case 1076: return true;
				case 1077: return true;
				case 1078: return true;
				case 1079: return true;
				case 1080: return true;
				case 1081: return true;
				case 1082: return true;
				case 1083: return true;
				case 1084: return true;
				case 1085: return true;
				case 1087: return true;
				case 1096: return true;
				case 1097: return true;
				case 1098: return true;
				case 1142: return true;
				case 1143: return true;
				case 1144: return true;
				case 1145: return true;
			}
		}
		case 402,403,406..409,411..414,416,419,423,424,427..429,431..435,437,438,440..445,448,450,451,455..459,461..463,466..468,470,471,474,475,479..486,490,494,495,498,499,502..510,514,515,521..526,528,530..533,541,552,543..545,554..557,566,568,578,571..574,579,581..584,586..588,591,594,596..599,601,602,604..611:
		{
			switch(componentid)
			{
				case 1008: return true;
				case 1009: return true;
				case 1010: return true;
				case 1025: return true;
				case 1073: return true;
				case 1074: return true;
				case 1075: return true;
				case 1076: return true;
				case 1077: return true;
				case 1078: return true;
				case 1079: return true;
				case 1080: return true;
				case 1081: return true;
				case 1082: return true;
				case 1083: return true;
				case 1084: return true;
				case 1085: return true;
				case 1087: return true;
				case 1096: return true;
				case 1097: return true;
				case 1098: return true;
			}
		}
	}
	return 0;
}

stock IsActualVehicleMod(componentid)
{
	switch(componentid)
	{
		case 1008: return false;
		case 1009: return false;
		case 1010: return false;
		case 1025: return false;
		case 1073: return false;
		case 1074: return false;
		case 1075: return false;
		case 1076: return false;
		case 1077: return false;
		case 1078: return false;
		case 1079: return false;
		case 1080: return false;
		case 1081: return false;
		case 1082: return false;
		case 1083: return false;
		case 1084: return false;
		case 1085: return false;
		case 1087: return false;
		case 1096: return false;
		case 1097: return false;
		case 1098: return false;
	}
	return true;
}

stock GetVehicleModName(componentid)
{
	static ModName[32];

	enum RCRP_ModInfo
	{
		ModComponentID,
		ModFullName[64 char]
	};
	static const RCRP_Mods[][RCRP_ModInfo] =
	{
		{1000, !"Pro Spoiler"},
		{1001, !"Win Spoiler"},
		{1002, !"Drag Spoiler"},
		{1003, !"Alpha Spoiler"},
		{1004, !"Champ Scoop"},
		{1005, !"Fury Scoop"},
		{1006, !"Roof Scoop"},
		{1007, !"Right Sideskirt"},
		{1008, !"Nitrous x5"},
		{1009, !"Nitrous x2"},
		{1010, !"Nitrous x10"},
		{1011, !"Race Scoop"},
		{1012, !"Worx Scoop"},
		{1013, !"Round Fog Lights"},
		{1014, !"Champ Spoiler"},
		{1015, !"Race Spoiler"},
		{1016, !"Worx Spoiler"},
		{1017, !"Left Sideskirt"},
		{1018, !"Upswept Exhaust"},
		{1019, !"Twin Exhaust"},
		{1020, !"Large Exhaust"},
		{1021, !"Medium Exhaust"},
		{1022, !"Small Exhaust"},
		{1023, !"Fury Spoiler"},
		{1024, !"Square Fog Lights"},
		{1025, !"Offroad Wheels"},
		{1026, !"Right Alien Sideskirt"},
		{1027, !"Left Alien Sideskirt"},
		{1028, !"Alien Exhaust"},
		{1029, !"X-Flow Exhaust"},
		{1030, !"Right X-Flow Sideskirt"},
		{1031, !"Left X-Flow Sideskirt"},
		{1032, !"Alien Roof Vent"},
		{1033, !"X-Flow Roof Vent"},
		{1034, !"Alien Exhaust"},
		{1035, !"X-Flow Roof Vent"},
		{1036, !"Right Alien Sideskirt"},
		{1037, !"X-Flow Exhaust"},
		{1038, !"Alien Roof Vent"},
		{1039, !"Right X-Flow Sideskirt"},
		{1040, !"Left Alien Sideskirt"},
		{1041, !"Left X-Flow Sideskirt"},
		{1042, !"Right Chrome Sideskirt"},
		{1043, !"Slamin Exhaust"},
		{1044, !"Chrome Exhaust"},
		{1045, !"X-Flow Exhaust"},
		{1046, !"Alien Exhaust"},
		{1047, !"Right Alien Sideskirt"},
		{1048, !"Right X-Flow Sideskirt"},
		{1049, !"Alien Spoiler"},
		{1050, !"X-Flow Spoiler"},
		{1051, !"Left Alien Sideskirt"},
		{1052, !"Left X-Flow Sideskirt"},
		{1053, !"X-Flow Roof Vent"},
		{1054, !"Alien Roof Vent"},
		{1055, !"Alien Roof Vent"},
		{1056, !"Right Alien Sideskirt"},
		{1057, !"Right X-Flow Sideskirt"},
		{1058, !"X-Flow Spoiler"},
		{1059, !"X-Flow Exhaust"},
		{1060, !"Alien Spoiler"},
		{1061, !"X-Flow Roof Vent"},
		{1062, !"Left Alien Sideskirt"},
		{1063, !"Left X-Flow Sideskirt"},
		{1064, !"Alien Exhaust"},
		{1065, !"Alien Exhaust"},
		{1066, !"X-Flow Exhaust"},
		{1067, !"Alien Roof Vent"},
		{1068, !"X-Flow Roof Vent"},
		{1069, !"Right Alien Sideskirt"},
		{1070, !"Right X-Flow Sideskirt"},
		{1071, !"Left Alien Sideskirt"},
		{1072, !"Left X-Flow Sideskirt"},
		{1073, !"Shadow Wheels"},
		{1074, !"Mega Wheels"},
		{1075, !"Rimshine Wheels"},
		{1076, !"Wires Wheels"},
		{1077, !"Classic Wheels"},
		{1078, !"Twist Wheels"},
		{1079, !"Cutter Wheels"},
		{1080, !"Stitch Wheels"},
		{1081, !"Grove Wheels"},
		{1082, !"Import Wheels"},
		{1083, !"Dollar Wheels"},
		{1084, !"Trance Wheels"},
		{1085, !"Atomic Wheels"},
		{1086, !"Stereo"},
		{1087, !"Hydraulics"},
		{1088, !"Alien Roof Vent"},
		{1089, !"X-Flow Exhaust"},
		{1090, !"Right Alien Sideskirt"},
		{1091, !"X-Flow Roof Vent"},
		{1092, !"Alien Exhaust"},
		{1093, !"Left X-Flow Sideskirt"},
		{1094, !"Left Alien Sideskirt"},
		{1095, !"Right X-Flow Sideskirt"},
		{1096, !"Ahab Wheels"},
		{1097, !"Virtual Wheels"},
		{1098, !"Access Wheels"},
		{1099, !"Left Chrome Sideskirt"},
		{1100, !"Chrome Grill"},
		{1101, !"Left Chrome Flames Sideskirt"},
		{1102, !"Left Chrome Strip Sideskirt"},
		{1103, !"Convertible Roof"},
		{1104, !"Chrome Exhaust"},
		{1105, !"Slamin Exhaust"},
		{1106, !"Left Chrome Arches Sideskirt"},
		{1107, !"Left Chrome Strip Sideskirt"},
		{1108, !"Right Chrome Strip Sideskirt"},
		{1109, !"Chrome Rear Bullbars"},
		{1110, !"Slamin Rear Bullbars"},
		{1111, !"Front Sign"},
		{1112, !"Front Sign"},
		{1113, !"Chrome Exhaust"},
		{1114, !"Slamin Exhaust"},
		{1115, !"Chrome Front Bullbars"},
		{1116, !"Slamin Front Bullbars"},
		{1117, !"Chrome Front Bumper"},
		{1118, !"Right Chrome Trim Sideskirt"},
		{1119, !"Right Wheelcovers Sideskirt"},
		{1120, !"Left Chrome Trim Sideskirt"},
		{1121, !"Left Wheelcovers Sideskirt"},
		{1122, !"Right Chrome Flames Sideskirt"},
		{1123, !"Bullbar Chrome Bars"},
		{1124, !"Left Chrome Arches Sideskirt"},
		{1125, !"Bullbar Chrome Lights"},
		{1126, !"Chrome Exhaust"},
		{1127, !"Slamin Exhaust"},
		{1128, !"Vinyl Hardtop Roof"},
		{1129, !"Chrome Exhaust"},
		{1130, !"Hardtop Roof"},
		{1131, !"Softtop Roof"},
		{1132, !"Slamin Exhaust"},
		{1133, !"Right Chrome Strip Sideskirt"},
		{1134, !"Right Chrome Strip Sideskirt"},
		{1135, !"Slamin Exhaust"},
		{1136, !"Chrome Exhaust"},
		{1138, !"Alien Spoiler"},
		{1139, !"X-Flow Spoiler"},
		{1140, !"X-Flow Rear Bumper"},
		{1141, !"Alien Rear Bumper"},
		{1142, !"Left Oval Vents"},
		{1143, !"Right Oval Vents"},
		{1144, !"Left Square Vents"},
		{1145, !"Right Square Vents"},
		{1146, !"X-Flow Spoiler"},
		{1147, !"Alien Spoiler"},
		{1148, !"X-Flow Rear Bumper"},
		{1149, !"Alien Rear Bumper"},
		{1150, !"Alien Rear Bumper"},
		{1151, !"X-Flow Rear Bumper"},
		{1152, !"X-Flow Front Bumper"},
		{1153, !"Alien Front Bumper"},
		{1154, !"Alien Rear Bumper"},
		{1155, !"Alien Front Bumper"},
		{1156, !"X-Flow Rear Bumper"},
		{1157, !"X-Flow Front Bumper"},
		{1158, !"X-Flow Spoiler"},
		{1159, !"Alien Rear Bumper"},
		{1160, !"Alien Front Bumper"},
		{1161, !"X-Flow Rear Bumper"},
		{1162, !"Alien Spoiler"},
		{1163, !"X-Flow Spoiler"},
		{1164, !"Alien Spoiler"},
		{1165, !"X-Flow Front Bumper"},
		{1166, !"Alien Front Bumper"},
		{1167, !"X-Flow Rear Bumper"},
		{1168, !"Alien Rear Bumper"},
		{1169, !"Alien Front Bumper"},
		{1170, !"X-Flow Front Bumper"},
		{1171, !"Alien Front Bumper"},
		{1172, !"X-Flow Front Bumper"},
		{1173, !"X-Flow Front Bumper"},
		{1174, !"Chrome Front Bumper"},
		{1175, !"Slamin Front Bumper"},
		{1176, !"Chrome Rear Bumper"},
		{1177, !"Slamin Rear Bumper"},
		{1178, !"Slamin Rear Bumper"},
		{1179, !"Chrome Front Bumper"},
		{1180, !"Chrome Rear Bumper"},
		{1181, !"Slamin Front Bumper"},
		{1182, !"Chrome Front Bumper"},
		{1183, !"Slamin Rear Bumper"},
		{1184, !"Chrome Rear Bumper"},
		{1185, !"Slamin Front Bumper"},
		{1186, !"Slamin Rear Bumper"},
		{1187, !"Chrome Rear Bumper"},
		{1188, !"Slamin Front Bumper"},
		{1189, !"Chrome Front Bumper"},
		{1190, !"Slamin Front Bumper"},
		{1191, !"Chrome Front Bumper"},
		{1192, !"Chrome Rear Bumper"},
		{1193, !"Slamin Rear Bumper"}
	};

	for(new i = 0; i < sizeof(RCRP_Mods); i++)
	{
		if(RCRP_Mods[i][ModComponentID] == componentid)
		{
			strunpack(ModName, RCRP_Mods[i][ModFullName]);
			return ModName;
		}
	}

	strunpack(ModName, !"Unknown");
	return ModName;
}

stock IsSuitablePaintjobCar(vehicleid)
{
	new model = GetVehicleModel(vehicleid);

	if(model == 483) return true; //camper
	if(model == 534) return true; //remington
	if(model == 535) return true; //slamvan
	if(model == 536) return true; //blade
	if(model == 558) return true; //uranus
	if(model == 559) return true; //jester
	if(model == 560) return true; //sultan
	if(model == 561) return true; //stratum
	if(model == 562) return true; //elegy
	if(model == 565) return true; //flash
	if(model == 567) return true; //savanna
	if(model == 575) return true; //broadway
	if(model == 576) return true; //tornado
	return false;
}