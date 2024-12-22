CMD:rentcars(playerid, params[])
{
    new businessid = IsPlayerNearBusiness(playerid);

    if(!IsPlayerNearBusiness(playerid))
        return SendErrorMessage(playerid, "You aren't near any business.");

    if(BusinessInfo[businessid][E_BUSINESS_TYPE] != BUSINESS_TYPE_RENT)
        return SendErrorMessage(playerid, "You aren't near business rental");
	
	new idx;
			
	new maxVehicles = AccountInfo[playerid][E_MASTERS_VIP] ? 4 : 2;

	for(new i = 1; i < MAX_PLAYER_VEHICLES; i++)
	{
		if(!PlayerInfo[playerid][E_CHARACTER_OWNEDVEHICLE][i])
		{
			if(i <= maxVehicles)
			{
				idx = i;
				break;
			}
		}
	}

	if(!idx)
	{
		SendErrorMessage(playerid, "You own the maximum amount of vehicles."); 
		return 1;
	}

    ShowPlayerDialog(playerid, DIALOG_RENTALCARS, DIALOG_STYLE_TABLIST, "Rental Cars:", "Faggio\t{33AA33}$50.00/hours{ffffff}\nSentinel\t{33AA33}$120.00/hours{ffffff}", "Select", "Cancel");
    return 1;
}

function:OnPlayerVehicleRental(playerid, id, modelid, cost, plates[], Float:x, Float:y, Float:z, Float:a)
{
	new vehicleid = INVALID_VEHICLE_ID;
	
	vehicleid = 
		CreateVehicle(modelid, x, y, z, a, 0, 0, -1);  
		
	SetVehicleNumberPlate(vehicleid, plates); 
	SetVehicleToRespawnEx(vehicleid); 
	
	PlayerPutIntoVehicle(playerid, vehicleid, 0); 
	PlayerInfo[playerid][E_CHARACTER_OWNEDVEHICLE][id] = cache_insert_id(); 
	
	if(vehicleid != INVALID_VEHICLE_ID)
	{
		VehicleInfo[vehicleid][E_VEHICLE_DBID] = cache_insert_id();
		VehicleInfo[vehicleid][E_VEHICLE_OWNERDBID] = PlayerInfo[playerid][E_CHARACTER_DBID]; 
		
		VehicleInfo[vehicleid][E_VEHICLE_MODEL] = modelid;
		
		VehicleInfo[vehicleid][E_VEHICLE_COLOR1] = 0;
		VehicleInfo[vehicleid][E_VEHICLE_COLOR2] = 0;
		
        VehicleInfo[vehicleid][E_VEHICLE_RENTAL] = true;
		VehicleInfo[vehicleid][E_VEHICLE_RENTTIMER] = 60;

		VehicleInfo[vehicleid][E_VEHICLE_PAINTJOB] = -1;
		
		VehicleInfo[vehicleid][E_VEHICLE_POS][0] = x;
		VehicleInfo[vehicleid][E_VEHICLE_POS][1] = y;
		VehicleInfo[vehicleid][E_VEHICLE_POS][2] = z;
		VehicleInfo[vehicleid][E_VEHICLE_POS][3] = a;
		
		format(VehicleInfo[vehicleid][E_VEHICLE_PLATES], 32, "%s", plates); 
		
		VehicleInfo[vehicleid][E_VEHICLE_LOCKED] = false;
		VehicleInfo[vehicleid][E_VEHICLE_ENGINE] = false;
		
		VehicleInfo[vehicleid][E_VEHICLE_FUEL] = 50.0; 
        VehicleInfo[vehicleid][E_VEHICLE_MILES] = 0; 
		
		VehicleInfo[vehicleid][E_VEHICLE_HEALTH] = 1000.0; 
		
		VehicleInfo[vehicleid][E_VEHICLE_DESTROYED] = 0;
        VehicleInfo[vehicleid][E_VEHICLE_PLATESSTATUS] = true;
        VehicleInfo[vehicleid][E_VEHICLE_TYPE] = VEHICLE_TYPE_PLAYER;
		
		SaveVehicle(vehicleid);
		
		PlayerInfo[playerid][E_CHARACTER_VEHICLESPAWNED] = true;
		PlayerInfo[playerid][E_CHARACTER_VEHICLESPAWN] = vehicleid;

        if(VehicleInfo[vehicleid][E_VEHICLE_EXISTS] && IsValidVehicle(vehicleid))
		{
            new str[128];
			format(str, sizeof(str), "SELECT * FROM `vstorage` WHERE `ID` = '%d'", VehicleInfo[vehicleid][E_VEHICLE_DBID]);
			mysql_pquery(ourConnection, str, "VehicleStorage_Load", "d", vehicleid);
		}
	}
	
	SendVehicleMessage(playerid, "[Vehicle] You successfully rent a %s for $%s.", ReturnVehicleName(vehicleid), FormatMoney(cost));
	return 1;
}