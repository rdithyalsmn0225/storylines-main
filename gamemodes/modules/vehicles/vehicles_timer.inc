function:OnVehicleFuelUpdate()
{
	for (new i = 1; i != MAX_VEHICLES; i ++) if (IsEngineVehicle(i) && GetVehicleEngineStatus(i))
	{
		if(VehicleInfo[i][E_VEHICLE_ADMIN]) //kalo kendaraan admin ga bisa ngurang.
			return 0;

		VehicleInfo[i][E_VEHICLE_MILES]++;

	    if(VehicleInfo[i][E_VEHICLE_FUEL] > 1.0)
		{
		    VehicleInfo[i][E_VEHICLE_FUEL] -= 0.5;

			if (VehicleInfo[i][E_VEHICLE_FUEL] >= 1.0 && VehicleInfo[i][E_VEHICLE_FUEL] <= 5.0)
			{
			    SendServerMessage(GetVehicleDriver(i), "[Vehicle] {cdd0d1}This vehicle is low on fuel.");
			}
            SaveVehicle(i);
		}
		if (VehicleInfo[i][E_VEHICLE_FUEL] <= 0)
		{
		    VehicleInfo[i][E_VEHICLE_FUEL] = 0;
		    ToggleVehicleEngine(i, false);
            SaveVehicle(i);
		}
	}
	return 1;
}

function:OnVehicleRental()
{
	for (new i = 1; i != MAX_VEHICLES; i ++)
	{
		foreach(new playerid : Player)
		{
			if(VehicleInfo[i][E_VEHICLE_RENTAL])
			{
				VehicleInfo[i][E_VEHICLE_RENTTIMER]--;
				if (VehicleInfo[i][E_VEHICLE_RENTTIMER] <= 0)
				{
					new delQuery[128];
					new dbid = VehicleInfo[i][E_VEHICLE_DBID];
				
					mysql_format(ourConnection, delQuery, sizeof(delQuery), "DELETE FROM vehicles WHERE VehicleDBID = %i", dbid);
					mysql_pquery(ourConnection, delQuery); 
					
					SendServerMessage(playerid, "[Vehicle] {cdd0d1}Your rental vehicle {d7d292}%s{cdd0d1} has been permanently deleted.", ReturnVehicleName(i)); 
					
					ResetVehicleVars(i); 
					VS_RemoveAllItems(i);
					DestroyVehicle(i); 
					
					PlayerInfo[playerid][E_CHARACTER_VEHICLESPAWNED] = false;
					PlayerInfo[playerid][E_CHARACTER_VEHICLESPAWN] = 0;
					
					for(new b = 1; b < MAX_PLAYER_VEHICLES; b++)
					{
						if(PlayerInfo[playerid][E_CHARACTER_OWNEDVEHICLE][b] == dbid)
						{
							PlayerInfo[playerid][E_CHARACTER_OWNEDVEHICLE][b] = 0;
						}
					}
				}
			}
		}
	}
}

stock TotalledCheck()
{
	static
	    Float:fHealth;

	for (new i = 1; i != MAX_VEHICLES; i ++) if (IsValidVehicle(i) && GetVehicleHealth(i, fHealth) && fHealth < 400.0) {
	    SetVehicleHealthEx(i, 400.0);
	    ToggleVehicleEngine(i, false);
	}
	return 1;
}

function:OnVehicleUpdate()
{
	new
		Float:vehicle_health;

	new Float:x, Float:y, Float:z, Float:a;

	for(new i = 1, j = GetVehiclePoolSize(); i <= j; i++)
    {
		if(VehicleInfo[i][E_VEHICLE_ADMIN]) //kalo kendaraan admin ga bisa ngurang.
			return 0;
			
		GetVehicleHealth(i, vehicle_health); 
		GetVehiclePos(i, x, y, z);
		GetVehicleZAngle(i, a);

		new panels, doors, lights, tires;
		GetVehicleDamageStatus(i, panels, doors, lights, tires);
		UpdateVehicleDamageStatus(i, panels, doors, lights, tires);
		VehicleInfo[i][E_VEHICLE_BODY] = panels;
		VehicleInfo[i][E_VEHICLE_TIRE] = tires;

		VehicleInfo[i][E_VEHICLE_POS][0] = x;
		VehicleInfo[i][E_VEHICLE_POS][1] = y;
		VehicleInfo[i][E_VEHICLE_POS][2] = z;
		VehicleInfo[i][E_VEHICLE_POS][3] = a;
		VehicleInfo[i][E_VEHICLE_HEALTH] = vehicle_health;
		SaveVehicle(i);
		
		TotalledCheck();
	}
	return 1;
}