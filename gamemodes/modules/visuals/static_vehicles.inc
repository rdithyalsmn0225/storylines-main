// STATIC VEHICLES
new g_Vehicle[100];
new JOBS_Vehicles[20];
new SAPD_Vehicles[39];
new SAMD_Vehicles[8];
new DMV_Vehicles[4]; 

InsertStaticVehicles()
{
	// DMV
	DMV_Vehicles[0] = AddStaticVehicle(405, 1273.0470, -1557.0576, 13.5405, -91.0000, 1, 1); SetVehicleNumberPlate(DMV_Vehicles[0], "DMV");
	DMV_Vehicles[1] = AddStaticVehicle(405, 1273.0470, -1549.9562, 13.5405, -91.0000, 1, 1); SetVehicleNumberPlate(DMV_Vehicles[1], "DMV");
	DMV_Vehicles[2] = AddStaticVehicle(405, 1273.0470, -1542.8961, 13.5405, -91.0000, 1, 1); SetVehicleNumberPlate(DMV_Vehicles[2], "DMV");
	DMV_Vehicles[3] = AddStaticVehicle(405, 1273.0470, -1536.0962, 13.5405, -91.0000, 1, 1); SetVehicleNumberPlate(DMV_Vehicles[3], "DMV");

	//SAPD
	SAPD_Vehicles[30] = AddStaticVehicle(596,1602.3312,-1684.0071,5.6185,91.2188,3,1); // Cruiser
	SetVehicleNumberPlate(SAPD_Vehicles[30], "LINCON-1");
	SAPD_Vehicles[31] = AddStaticVehicle(596,1602.5184,-1687.9525,5.6098,89.0430,3,1); // Cruiser
	SetVehicleNumberPlate(SAPD_Vehicles[31], "LINCON-2");
	SAPD_Vehicles[32] = AddStaticVehicle(596,1602.3141,-1692.2067,5.6149,89.1927,3,1); // Cruiser
	SetVehicleNumberPlate(SAPD_Vehicles[32], "LINCON-3");
	SAPD_Vehicles[33] = AddStaticVehicle(596,1602.2833,-1696.3682,5.6286,90.2932,3,1); // Cruiser
	SetVehicleNumberPlate(SAPD_Vehicles[33], "LINCON-4");
	SAPD_Vehicles[34] = AddStaticVehicle(596,1602.1863,-1700.2629,5.6161,88.2802,3,1); // Cruiser
	SetVehicleNumberPlate(SAPD_Vehicles[34], "LINCON-5");

	SAPD_Vehicles[35] = AddStaticVehicle(596,1595.1029,-1711.1693,5.6132,358.1242,0,0); // Cruiser
	SetVehicleNumberPlate(SAPD_Vehicles[35], "LINCON-6");
	SAPD_Vehicles[36] = AddStaticVehicle(596,1591.2061,-1711.1152,5.6060,357.9518,0,0); // Cruiser
	SetVehicleNumberPlate(SAPD_Vehicles[36], "LINCON-7");
	SAPD_Vehicles[37] = AddStaticVehicle(596,1587.8042,-1711.0640,5.6139,0.4377,0,0); // Cruiser
	SetVehicleNumberPlate(SAPD_Vehicles[37], "LINCON-8");
	SAPD_Vehicles[38] = AddStaticVehicle(596,1583.5166,-1710.9095,5.6262,357.2809,0,0); // Cruiser
	SetVehicleNumberPlate(SAPD_Vehicles[38], "LINCON-9");

	SAPD_Vehicles[9] = AddStaticVehicle(601,1526.5850,-1644.1801,5.6494,180.3210,1,1); // Splashy
	SetVehicleNumberPlate(SAPD_Vehicles[9], "KING-3");
	SAPD_Vehicles[10] = AddStaticVehicle(601,1530.7244,-1644.2538,5.6494,179.6148,1,1); // Splashy
	SetVehicleNumberPlate(SAPD_Vehicles[10], "KING-4");
	SAPD_Vehicles[11] = AddStaticVehicle(427,1534.8553,-1644.8682,6.0226,180.7921,0,0); // Enforcer
	SetVehicleNumberPlate(SAPD_Vehicles[11], "KING-5");
	SAPD_Vehicles[12] = AddStaticVehicle(427,1538.9325,-1644.9508,6.0226,179.5991,0,0); // Enforcer
	SetVehicleNumberPlate(SAPD_Vehicles[12], "KING-6");

	SAPD_Vehicles[18] = AddStaticVehicle(497,1565.0839,-1643.2800,28.5921,89.4944,0,1); // Maverick
	SetVehicleNumberPlate(SAPD_Vehicles[18], "CHOPPER-1");
	SAPD_Vehicles[19] = AddStaticVehicle(497,1564.4895,-1703.4138,28.5848,87.6184,0,1); // Maverick
	SetVehicleNumberPlate(SAPD_Vehicles[19], "CHOPPER-2");

	SAPD_Vehicles[8] = AddStaticVehicle(490,1545.7213,-1655.0195,6.0814,90.4218,0,0); // Rancher
	SetVehicleNumberPlate(SAPD_Vehicles[8], "KING-1");
	SAPD_Vehicles[9] = AddStaticVehicle(490,1545.8069,-1651.1516,6.0790,88.2897,0,0); // Rancher
	SetVehicleNumberPlate(SAPD_Vehicles[9], "KING-2");

	SAPD_Vehicles[20] = AddStaticVehicle(525,1528.3439,-1684.0914,5.7702,269.9949,1,0); // Towtruck
	SetVehicleNumberPlate(SAPD_Vehicles[20], "ZEUS-1");
	SAPD_Vehicles[21] = AddStaticVehicle(525,1528.6476,-1688.2294,5.7698,269.9370,1,0); // Towtruck
	SetVehicleNumberPlate(SAPD_Vehicles[21], "ZEUS-2");

	SAPD_Vehicles[22] = AddStaticVehicle(468,1544.0415,-1708.5723,5.5538,156.7939,0,0); // Cruiser (Front)
	SetVehicleNumberPlate(SAPD_Vehicles[22], "TEU-1");
	SAPD_Vehicles[23] = AddStaticVehicle(468,1542.7850,-1707.5076,5.5622,158.1278,0,0); // Tow Truck
	SetVehicleNumberPlate(SAPD_Vehicles[23], "TEU-2");
	SAPD_Vehicles[24] = AddStaticVehicle(468,1542.0917,-1707.0608,5.5511,154.1654,0,0); // Tow Truck
	SetVehicleNumberPlate(SAPD_Vehicles[24], "TEU-3");
	SAPD_Vehicles[25] = AddStaticVehicle(522,1540.4431,-1705.9148,5.4508,156.6729,0,0); // Maverick
	SetVehicleNumberPlate(SAPD_Vehicles[25], "TEU-4");
	SAPD_Vehicles[26] = AddStaticVehicle(522,1539.9655,-1705.2487,5.4344,156.1196,0,0); // Maverick
	SetVehicleNumberPlate(SAPD_Vehicles[26], "TEU-5");
	SAPD_Vehicles[27] = AddStaticVehicle(522,1539.1798,-1704.4395,5.4616,154.4021,0,0); // Maverick
	SetVehicleNumberPlate(SAPD_Vehicles[27], "TEU-6");

	//SULTAN CHIEF SAPD
    SAPD_Vehicles[28] = AddStaticVehicle(560,1546.3962,-1668.0127,5.5955,89.4513,0,0); // Rancher
	SetVehicleNumberPlate(SAPD_Vehicles[28], "Chief SAPD");
	SAPD_Vehicles[29] = AddStaticVehicle(560,1546.2767,-1663.0496,5.5966,90.1683,0,0); // Rancher
	SetVehicleNumberPlate(SAPD_Vehicles[29], "Deputy SAPD");

	SAMD_Vehicles[0] = AddStaticVehicle(416, 1116.0294, -1296.6489, 13.6160, 179.4438, 1, 3);
	SAMD_Vehicles[1] = AddStaticVehicle(416, 1125.8785, -1296.2780, 13.6160, 179.4438, 1, 3);
	SAMD_Vehicles[2] = AddStaticVehicle(416, 1121.1556, -1296.4138, 13.6160, 179.4438, 1, 3);
	SAMD_Vehicles[3] = AddStaticVehicle(442, 1111.1719, -1296.7606, 13.4886, 185.0000, 0, 1);
	SAMD_Vehicles[4] = AddStaticVehicle(426, 1136.0360, -1341.2158, 13.3050, 0.0000, 0, 1);
	SAMD_Vehicles[5] = AddStaticVehicle(586, 1130.7795, -1330.4045, 13.3639, 0.0000, 0, 1);
	SAMD_Vehicles[6] = AddStaticVehicle(563, 1162.9077, -1313.8203, 32.1891, 270.6980, -1, 3);
	SAMD_Vehicles[7] = AddStaticVehicle(487, 1163.0469, -1297.5098, 31.5550, 269.6279, -1, 3);

	for (new i = 0; i < 39; i ++) if (IsValidVehicle(SAPD_Vehicles[i])) 
	{
		VehicleInfo[SAPD_Vehicles[i]][E_VEHICLE_HEALTH] = 2000.0;
		VehicleInfo[SAPD_Vehicles[i]][E_VEHICLE_FUEL] = 100;
		VehicleInfo[SAPD_Vehicles[i]][E_VEHICLE_MILES] = 0; 
	}

	for (new i = 0; i < 8; i ++) if (IsValidVehicle(SAMD_Vehicles[i])) 
	{
		VehicleInfo[SAMD_Vehicles[i]][E_VEHICLE_HEALTH] = 2000.0;
		VehicleInfo[SAMD_Vehicles[i]][E_VEHICLE_FUEL] = 100;
		VehicleInfo[SAMD_Vehicles[i]][E_VEHICLE_MILES] = 0;
		format(VehicleInfo[SAMD_Vehicles[i]][E_VEHICLE_PLATES], 32, "SAMD");
		SetVehicleNumberPlate(SAMD_Vehicles[i], VehicleInfo[SAMD_Vehicles[i]][E_VEHICLE_PLATES]);
	}

	for (new i = 0; i < 38; i ++) if (IsValidVehicle(g_Vehicle[i])) 
	{
		VehicleInfo[g_Vehicle[i]][E_VEHICLE_HEALTH] = 1000.0;
		VehicleInfo[g_Vehicle[i]][E_VEHICLE_FUEL] = 99999;
		VehicleInfo[g_Vehicle[i]][E_VEHICLE_MILES] = 0;
		format(VehicleInfo[g_Vehicle[i]][E_VEHICLE_PLATES], 32, "STATIC");
		SetVehicleNumberPlate(g_Vehicle[i], VehicleInfo[g_Vehicle[i]][E_VEHICLE_PLATES]);
	}

	for (new i = 0; i < 15; i ++) if (IsValidVehicle(JOBS_Vehicles[i])) 
	{
		VehicleInfo[JOBS_Vehicles[i]][E_VEHICLE_HEALTH] = 1000.0;
		VehicleInfo[JOBS_Vehicles[i]][E_VEHICLE_FUEL] = 99999;
		VehicleInfo[JOBS_Vehicles[i]][E_VEHICLE_MILES] = 0;
		VehicleInfo[JOBS_Vehicles[i]][E_VEHICLE_CRATES] = 0;
		VehicleInfo[JOBS_Vehicles[i]][E_VEHICLE_TRASHMASTER] = 0;
		format(VehicleInfo[JOBS_Vehicles[i]][E_VEHICLE_PLATES], 32, "JOBS");
		SetVehicleNumberPlate(JOBS_Vehicles[i], VehicleInfo[JOBS_Vehicles[i]][E_VEHICLE_PLATES]);
	}

	for (new i = 0; i < 4; i ++) if (IsValidVehicle(DMV_Vehicles[i])) 
	{
		VehicleInfo[DMV_Vehicles[i]][E_VEHICLE_HEALTH] = 1000.0;
		VehicleInfo[DMV_Vehicles[i]][E_VEHICLE_FUEL] = 99999;
		VehicleInfo[DMV_Vehicles[i]][E_VEHICLE_MILES] = 0;
		format(VehicleInfo[DMV_Vehicles[i]][E_VEHICLE_PLATES], 32, "DMV");
		SetVehicleNumberPlate(DMV_Vehicles[i], VehicleInfo[DMV_Vehicles[i]][E_VEHICLE_PLATES]);
	}
}