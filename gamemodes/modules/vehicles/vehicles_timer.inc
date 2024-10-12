function:OnVehicleFuelUpdate()
{
	for (new i = 1; i != MAX_VEHICLES; i ++) if (IsEngineVehicle(i) && GetVehicleEngineStatus(i))
	{
	    if(VehicleInfo[i][E_VEHICLE_FUEL] > 1.0)
		{
		    VehicleInfo[i][E_VEHICLE_FUEL] -= 0.5;

			if (VehicleInfo[i][E_VEHICLE_FUEL] >= 1.0 && VehicleInfo[i][E_VEHICLE_FUEL] <= 5.0)
			{
			    SendServerMessage(GetVehicleDriver(i), "This vehicle is low on fuel.");
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
		if(VehicleInfo[i][E_VEHICLE_ADMIN])
			continue;
			
		GetVehicleHealth(i, vehicle_health); 
		GetVehiclePos(i, x, y, z);
		GetVehicleZAngle(i, a);

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