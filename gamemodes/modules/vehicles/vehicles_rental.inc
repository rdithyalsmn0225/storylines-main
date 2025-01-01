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

    Dialog_Show(playerid, DialogRentalCars, DIALOG_STYLE_TABLIST, "Rental Cars:", "Faggio\t{33AA33}$50.00/hours{ffffff}\nSentinel\t{33AA33}$120.00/hours{ffffff}", "Select", "Cancel");
    return 1;
}

Dialog:DialogRentalCars(playerid, response, listitem, inputtext[])
{
	if(response)
	{
		switch(listitem)
		{
			case 0:
			{
				new Cents = floatround(50 * 100, floatround_round);

				if(Cents > PlayerInfo[playerid][E_CHARACTER_MONEY])
					return SendErrorMessage(playerid, "You can't afford the total price. (Price: $%s, Total:$%s)", FormatMoney(Cents), FormatMoney(PlayerInfo[playerid][E_CHARACTER_MONEY]));

				new
					idx, 
					plates[32],
					randset[3],
					insert[256],
					Float:x,
					Float:y,
					Float:z,
					Float:a;
				
				for(new i = 1; i < MAX_PLAYER_VEHICLES; i++)
				{
					if(!PlayerInfo[playerid][E_CHARACTER_OWNEDVEHICLE][i])
					{
						idx = i;
						break;
					}
				}

				GetPlayerPos(playerid, x, y, z);
				GetPlayerFacingAngle(playerid, a);

				randset[0] = random(sizeof(possible_vehicle_plates)); 
				randset[1] = random(sizeof(possible_vehicle_plates)); 
				randset[2] = random(sizeof(possible_vehicle_plates)); 
				
				format(plates, 32, "%d%s%s%s%d%d%d", random(9), possible_vehicle_plates[randset[0]], possible_vehicle_plates[randset[1]], possible_vehicle_plates[randset[2]], random(9), random(9)); 

				GiveMoney(playerid, -Cents);
				
				ShowPlayerPlates(playerid, plates); 
				
				mysql_format(ourConnection, insert, sizeof(insert), "INSERT INTO vehicles (VehicleOwnerDBID, VehicleModel, VehicleParkPosX, VehicleParkPosY, VehicleParkPosZ, VehicleParkPosA, VehicleRental, VehicleRentalTimer) VALUES(%i, %i, %f, %f, %f, %f, %i, %i)",
					PlayerInfo[playerid][E_CHARACTER_DBID], 462, x, y, z, a, 1, 60); 
					
				mysql_pquery(ourConnection, insert, "OnPlayerVehicleRental", "iiiisffff", playerid, idx, 462, Cents, plates, x, y, z, a);
			}
			case 1:
			{
				new Cents = floatround(120 * 100, floatround_round);

				if(Cents > PlayerInfo[playerid][E_CHARACTER_MONEY])
					return SendErrorMessage(playerid, "You can't afford the total price. (Price: $%s, Total:$%s)", FormatMoney(Cents), FormatMoney(PlayerInfo[playerid][E_CHARACTER_MONEY]));

				new
					idx, 
					plates[32],
					randset[3],
					insert[256],
					Float:x,
					Float:y,
					Float:z,
					Float:a;
				
				for(new i = 1; i < MAX_PLAYER_VEHICLES; i++)
				{
					if(!PlayerInfo[playerid][E_CHARACTER_OWNEDVEHICLE][i])
					{
						idx = i;
						break;
					}
				}

				GetPlayerPos(playerid, x, y, z);
				GetPlayerFacingAngle(playerid, a);

				randset[0] = random(sizeof(possible_vehicle_plates)); 
				randset[1] = random(sizeof(possible_vehicle_plates)); 
				randset[2] = random(sizeof(possible_vehicle_plates)); 
				
				format(plates, 32, "%d%s%s%s%d%d%d", random(9), possible_vehicle_plates[randset[0]], possible_vehicle_plates[randset[1]], possible_vehicle_plates[randset[2]], random(9), random(9)); 
				
				GiveMoney(playerid, -Cents);
				
				ShowPlayerPlates(playerid, plates); 
				
				mysql_format(ourConnection, insert, sizeof(insert), "INSERT INTO vehicles (VehicleOwnerDBID, VehicleModel, VehicleParkPosX, VehicleParkPosY, VehicleParkPosZ, VehicleParkPosA, VehicleRental, VehicleRentalTimer) VALUES(%i, %i, %f, %f, %f, %f, %i, %i)",
					PlayerInfo[playerid][E_CHARACTER_DBID], 405, x, y, z, a, 1, 60); 
					
				mysql_pquery(ourConnection, insert, "OnPlayerVehicleRental", "iiiisffff", playerid, idx, 405, Cents, plates, x, y, z, a);
			}
		}
	}
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
	
	SendVehicleMessage(playerid, "[VEHICLE] You successfully rent a %s for $%s.", ReturnVehicleName(vehicleid), FormatMoney(cost));
	return 1;
}