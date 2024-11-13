// STATIC VEHICLES
new g_Vehicle[100];
new JOBS_Vehicles[20];
new SAPD_Vehicles[30];
new SAMD_Vehicles[8];
new DMV_Vehicles[4]; 

InsertStaticVehicles()
{
	// DMV
	DMV_Vehicles[0] = AddStaticVehicle(405, 1273.0470, -1557.0576, 13.5405, -91.0000, 1, 1); SetVehicleNumberPlate(DMV_Vehicles[0], "DMV");
	DMV_Vehicles[1] = AddStaticVehicle(405, 1273.0470, -1549.9562, 13.5405, -91.0000, 1, 1); SetVehicleNumberPlate(DMV_Vehicles[1], "DMV");
	DMV_Vehicles[2] = AddStaticVehicle(405, 1273.0470, -1542.8961, 13.5405, -91.0000, 1, 1); SetVehicleNumberPlate(DMV_Vehicles[2], "DMV");
	DMV_Vehicles[3] = AddStaticVehicle(405, 1273.0470, -1536.0962, 13.5405, -91.0000, 1, 1); SetVehicleNumberPlate(DMV_Vehicles[3], "DMV");

	//DockWrorker
	JOBS_Vehicles[7] = CreateVehicle(530, 2744.6150,-2444.0518,13.4080, 268.9370, 11, 0, -1); SetVehicleNumberPlate(JOBS_Vehicles[7], "DOCK");
	JOBS_Vehicles[8] = CreateVehicle(530, 2746.6934,-2467.3901,13.4124, 91.9786, 11, 0, -1); SetVehicleNumberPlate(JOBS_Vehicles[8], "DOCK");
	JOBS_Vehicles[9] = CreateVehicle(530, 2672.1262,-2421.1860,13.3976, 1.2609, 11, 0, -1); SetVehicleNumberPlate(JOBS_Vehicles[9], "DOCK");
	JOBS_Vehicles[10] = CreateVehicle(530, 2640.8159,-2389.7834,13.3978,85.6932, 11, 0, -1); SetVehicleNumberPlate(JOBS_Vehicles[10], "DOCK");
	JOBS_Vehicles[11] = CreateVehicle(530, 2446.9351,-2431.2043,13.3915,225.1755, 11, 0, -1); SetVehicleNumberPlate(JOBS_Vehicles[11], "DOCK");

	//Police
	SAPD_Vehicles[0] = AddStaticVehicleEx(596,1585.8813,-1667.5236,5.5589,268.9741,36,1, 60000); // Cruiser HC
	SAPD_Vehicles[1] = AddStaticVehicleEx(596,1585.6987,-1671.8832,5.5520,271.2573,15,1, 60000); // Cruiser Command Team
	SAPD_Vehicles[2] = AddStaticVehicleEx(596,1585.7786,-1675.9716,5.5531,270.9127,108,1, 60000); // Cruiser Supervisor 1
	SAPD_Vehicles[3] = AddStaticVehicleEx(596,1585.8177,-1679.6355,5.5674,270.8011,108,1, 60000); // Cruiser Supervisor 2
	SAPD_Vehicles[4] = AddStaticVehicleEx(596,1602.5104,-1684.0599,5.5721,91.0629,0,1, 60000); // Cruiser
	SAPD_Vehicles[5] = AddStaticVehicleEx(596,1602.5287,-1688.0629,5.5712,88.9105,0,1, 60000); // Cruiser
	SAPD_Vehicles[6] = AddStaticVehicleEx(596,1602.4117,-1692.0302,5.5735,88.5088,0,1, 60000); // Cruiser
	SAPD_Vehicles[7] = AddStaticVehicleEx(596,1602.4979,-1696.1620,5.5303,92.1094,0,1, 60000); // Cruiser
	SAPD_Vehicles[8] = AddStaticVehicleEx(596,1602.3427,-1700.1394,5.5328,89.7606,0,1, 60000); // Cruiser
	SAPD_Vehicles[9] = AddStaticVehicleEx(596,1602.3191,-1704.4431,5.5304,88.5293,0,1, 60000); // Cruiser
	SAPD_Vehicles[10] = AddStaticVehicleEx(599,1595.4366,-1711.3505,5.9677,0.7363,0,1, 60000); // Bear 1
	SAPD_Vehicles[11] = AddStaticVehicleEx(599,1591.4089,-1711.5291,5.9700,359.3976,0,1, 60000); // Bear 2
	SAPD_Vehicles[12] = AddStaticVehicleEx(468,1566.6353,-1708.4395,5.5598,359.7773,0,0, 60000, 1); // Marry 1
	SAPD_Vehicles[13] = AddStaticVehicleEx(468,1566.9927,-1711.9053,5.5516,359.1170,0,0, 60000, 1); // Marry 2
	SAPD_Vehicles[14] = AddStaticVehicleEx(490,1545.6080,-1676.0394,6.0064,89.7384,0,1, 60000); // DAVID 3
	SAPD_Vehicles[15] = AddStaticVehicleEx(426,1528.6735,-1684.0107,5.6811,269.4669,198,198, 60000, 1); // TEU Premier 1
	SAPD_Vehicles[16] = AddStaticVehicleEx(426,1528.6068,-1687.9893,5.6737,271.4348,1,1, 60000, 1); // TEU Premier 2
	SAPD_Vehicles[17] = AddStaticVehicleEx(497,1566.6866,-1696.0535,28.6456,269.6936,0,1, 60000, 1);

	SAMD_Vehicles[0] = AddStaticVehicle(416, 1116.0294, -1296.6489, 13.6160, 179.4438, 1, 3);
	SAMD_Vehicles[1] = AddStaticVehicle(416, 1125.8785, -1296.2780, 13.6160, 179.4438, 1, 3);
	SAMD_Vehicles[2] = AddStaticVehicle(416, 1121.1556, -1296.4138, 13.6160, 179.4438, 1, 3);
	SAMD_Vehicles[3] = AddStaticVehicle(442, 1111.1719, -1296.7606, 13.4886, 185.0000, 0, 1);
	SAMD_Vehicles[4] = AddStaticVehicle(426, 1136.0360, -1341.2158, 13.3050, 0.0000, 0, 1);
	SAMD_Vehicles[5] = AddStaticVehicle(586, 1130.7795, -1330.4045, 13.3639, 0.0000, 0, 1);
	SAMD_Vehicles[6] = AddStaticVehicle(563, 1162.9077, -1313.8203, 32.1891, 270.6980, -1, 3);
	SAMD_Vehicles[7] = AddStaticVehicle(487, 1163.0469, -1297.5098, 31.5550, 269.6279, -1, 3);

	for (new i = 0; i < 18; i ++) if (IsValidVehicle(SAPD_Vehicles[i])) 
	{
		VehicleInfo[SAPD_Vehicles[i]][E_VEHICLE_HEALTH] = 1000.0;
		VehicleInfo[SAPD_Vehicles[i]][E_VEHICLE_FUEL] = 100;
		format(VehicleInfo[SAPD_Vehicles[i]][E_VEHICLE_PLATES], 32, "SAPD");
		SetVehicleNumberPlate(SAPD_Vehicles[i], VehicleInfo[SAPD_Vehicles[i]][E_VEHICLE_PLATES]);
	}

	for (new i = 0; i < 8; i ++) if (IsValidVehicle(SAMD_Vehicles[i])) 
	{
		VehicleInfo[SAMD_Vehicles[i]][E_VEHICLE_HEALTH] = 1000.0;
		VehicleInfo[SAMD_Vehicles[i]][E_VEHICLE_FUEL] = 100;
		format(VehicleInfo[SAMD_Vehicles[i]][E_VEHICLE_PLATES], 32, "SAMD");
		SetVehicleNumberPlate(SAMD_Vehicles[i], VehicleInfo[SAMD_Vehicles[i]][E_VEHICLE_PLATES]);
	}

	for (new i = 0; i < 38; i ++) if (IsValidVehicle(g_Vehicle[i])) 
	{
		VehicleInfo[g_Vehicle[i]][E_VEHICLE_HEALTH] = 1000.0;
		VehicleInfo[g_Vehicle[i]][E_VEHICLE_FUEL] = 99999;
		format(VehicleInfo[g_Vehicle[i]][E_VEHICLE_PLATES], 32, "STATIC");
		SetVehicleNumberPlate(g_Vehicle[i], VehicleInfo[g_Vehicle[i]][E_VEHICLE_PLATES]);
	}

	for (new i = 0; i < 15; i ++) if (IsValidVehicle(JOBS_Vehicles[i])) 
	{
		VehicleInfo[JOBS_Vehicles[i]][E_VEHICLE_HEALTH] = 1000.0;
		VehicleInfo[JOBS_Vehicles[i]][E_VEHICLE_FUEL] = 99999;
		VehicleInfo[JOBS_Vehicles[i]][E_VEHICLE_CRATES] = 0;
		VehicleInfo[JOBS_Vehicles[i]][E_VEHICLE_TRASHMASTER] = 0;
		format(VehicleInfo[JOBS_Vehicles[i]][E_VEHICLE_PLATES], 32, "JOBS");
		SetVehicleNumberPlate(JOBS_Vehicles[i], VehicleInfo[JOBS_Vehicles[i]][E_VEHICLE_PLATES]);
	}

	for (new i = 0; i < 4; i ++) if (IsValidVehicle(DMV_Vehicles[i])) 
	{
		VehicleInfo[DMV_Vehicles[i]][E_VEHICLE_HEALTH] = 1000.0;
		VehicleInfo[DMV_Vehicles[i]][E_VEHICLE_FUEL] = 99999;
		format(VehicleInfo[DMV_Vehicles[i]][E_VEHICLE_PLATES], 32, "DMV");
		SetVehicleNumberPlate(DMV_Vehicles[i], VehicleInfo[DMV_Vehicles[i]][E_VEHICLE_PLATES]);
	}
}