new tmpobjid;

//Static
new GSF_Vehicles[8];
new KTB_Vehicles[5];
new JB_Vehicles[7];
new SBF_Vehicles[8];
new VLA_Vehicles[6];
new ELSV_Vehicles[6];
new FYB_Vehicles[7];
new TDB_Vehicles[6];
new TDF_Vehicles[6];
new g_Vehicle[100];
new Jobs_vehicles[20];
new LSPDVehicles[30];
new dmv_vehicles[4]; 

new PlayerActor[MAX_PLAYERS];

CreatePlayerActor(playerid, skin)
{
	new vwid = AccountInfo[playerid][E_MASTERS_DBID];

	if(IsValidDynamicActor(PlayerActor[playerid]))
		DestroyDynamicActor(PlayerActor[playerid]);

	PlayerActor[playerid] = CreateDynamicActor(skin, 1673.8185,-2325.6941,-2.6797,271.9806); //hood
	ApplyDynamicActorAnimation(PlayerActor[playerid], "DEALER", "DEALER_IDLE", 4.1, 1, 0, 0, 0, 0);
	SetDynamicActorVirtualWorld(PlayerActor[playerid], vwid);
	return 1;
}

DestroyPlayerActor(playerid)
{
	DestroyDynamicActor(PlayerActor[playerid]);
	return 1;
}
//Static

InsertSideJobs()
{
    CreateDynamicPickup(1210, 1, 1529.5608,-1849.4032,13.5469, -1, -1, -1, 5.0);
    CreateDynamic3DTextLabel("[Garbageman]\n{ffffff}Available commands: /jobduty, /collectgarbage, /dumpgarbage", COLOR_DARKGREEN, 1529.5608,-1849.4032,13.5469, 5.0);
    CreateDynamicPickup(1210, 1, 2748.7725,-2451.0012,13.6484, -1, -1, -1, 5.0);
    CreateDynamic3DTextLabel("[Dockworker]\n{ffffff}Available commands: /jobduty, /takecargo, /storecargo", COLOR_DARKGREEN, 2748.7725,-2451.0012,13.6484, 5.0);
}
Insert3DTextLabel()
{
    new str1[512], str2[512]; 
    
    format(str1, sizeof(str1), "[Gunstore Materials]\n{ffffff}Available stock: %d / 1000\nMaterials Price $5 / gram", ServerInfo[0][E_SERVER_MATERIALS]);
    CreateDynamic3DTextLabel(str1, COLOR_DARKGREEN, -576.3427,-505.8364,25.5234, 5.0);

    format(str2, sizeof(str2), "[Drugs Labs]\n{ffffff}Available stock: %d / 100\nMarijuana Price $3000 / 25 gram\nCocaine Price $5000 / 30 gram\nHeroin Price $5000 / 30 gram", ServerInfo[0][E_SERVER_DRUGS]);
    CreateDynamic3DTextLabel(str2, COLOR_DARKGREEN, 122.0707,-319.1785,1.5781, 5.0);

	fittingRoomDoor = CreateDynamicObject(2877, 216.760360, -97.310455, 1005.337768, 0.0, 0.0, 360.0, .interiorid = 15);

	CreateDynamic3DTextLabel("[Leafy Hollow Barn]\n{ffffff}Available Commands: '/buyaxe'", COLOR_DARKGREEN, -1448.7738,-1530.5585,101.7578, 5.0);

	CreateDynamic3DTextLabel("[Drop Injured]\n{ffffff}Available Commands: '/dropinjured'", COLOR_DARKGREEN, 2035.0732,-1414.0488,16.9922, 5.0);

	CreateDynamic3DTextLabel("[Vehicle Graveyard & Scrapyard]\n{ffffff}Available Commands: '/carscrap'", COLOR_DARKGREEN, 2412.9312,-1425.4226,23.9835, 5.0);

	CreateDynamic3DTextLabel("[Clothes store]\n{ffffff}Available Commands: '/clothes'", COLOR_DARKGREEN, 217.5163,-98.4308,1005.2578, 5.0);

	CreateDynamic3DTextLabel("[Los Santos Prison]\n{ffffff}Available Commands: '/charge'", COLOR_DARKGREEN, 252.9687,90.9530,1002.4453, 5.0);

	CreateDynamic3DTextLabel("[General Store]\n{ffffff}Press 'N' to grab an items.", COLOR_DARKGREEN, -48.4748,-1.1597,203.2633, 5.0);
	CreateDynamic3DTextLabel("[General Store]\n{ffffff}Press 'N' to grab an items.", COLOR_DARKGREEN, -53.7980,2.8393,203.2633, 5.0);
	CreateDynamic3DTextLabel("[General Store]\n{ffffff}Press 'N' to grab an items.", COLOR_DARKGREEN, -51.4530,5.4811,203.2633, 5.0);
	CreateDynamic3DTextLabel("[General Store]\n{ffffff}Press 'N' to grab an items.", COLOR_DARKGREEN, -48.1108,5.5907,203.2633, 5.0);
	CreateDynamic3DTextLabel("[General Store]\n{ffffff}Press 'N' to grab an items.", COLOR_DARKGREEN, -53.7646,5.2118,203.2633, 5.0);

	CreateDynamic3DTextLabel("[Furniture Store]\n{ffffff}Press 'N' to grab an items.", COLOR_DARKGREEN, 1359.4304,1703.7946,434.9792, 5.0);
	CreateDynamic3DTextLabel("[Furniture Store]\n{ffffff}Press 'N' to grab an items.", COLOR_DARKGREEN, 1359.4393,1710.9224,434.9792, 5.0);
	CreateDynamic3DTextLabel("[Furniture Store]\n{ffffff}Press 'N' to grab an items.", COLOR_DARKGREEN, 1362.5713,1711.0144,434.9792, 5.0);

	CreateDynamic3DTextLabel("[Haircut]\n{ffffff}Available Commands: '/haircut'", COLOR_DARKGREEN, 2064.5574,-1794.9839,13.4599, 5.0);

	CreateDynamic3DTextLabel("[Fish Factory]\n{ffffff}Available Commands: '/buybait'\n{ffffff}Available Commands: '/sellfish'", COLOR_DARKGREEN, 2895.6743,-2135.5847,3.6525, 5.0);
}

InsertStaticVehicles()
{
	dmv_vehicles[0] = AddStaticVehicle(405, 1273.0470, -1557.0576, 13.5405, -91.0000, 1, 1); SetVehicleNumberPlate(dmv_vehicles[0], "DMV");
	dmv_vehicles[1] = AddStaticVehicle(405, 1273.0470, -1549.9562, 13.5405, -91.0000, 1, 1); SetVehicleNumberPlate(dmv_vehicles[1], "DMV");
	dmv_vehicles[2] = AddStaticVehicle(405, 1273.0470, -1542.8961, 13.5405, -91.0000, 1, 1); SetVehicleNumberPlate(dmv_vehicles[2], "DMV");
	dmv_vehicles[3] = AddStaticVehicle(405, 1273.0470, -1536.0962, 13.5405, -91.0000, 1, 1); SetVehicleNumberPlate(dmv_vehicles[3], "DMV");

	for (new i = 0; i < 4; i ++) if (IsValidVehicle(dmv_vehicles[i])) 
	{
		VehicleInfo[dmv_vehicles[i]][E_VEHICLE_HEALTH] = 1000.0;
		VehicleInfo[dmv_vehicles[i]][E_VEHICLE_FUEL] = 99999;
	}

	//DockWrorker
	Jobs_vehicles[7] = CreateVehicle(530, 2744.6150,-2444.0518,13.4080, 268.9370, 11, 0, -1); SetVehicleNumberPlate(Jobs_vehicles[7], "DOCK");
	Jobs_vehicles[8] = CreateVehicle(530, 2746.6934,-2467.3901,13.4124, 91.9786, 11, 0, -1); SetVehicleNumberPlate(Jobs_vehicles[8], "DOCK");
	Jobs_vehicles[9] = CreateVehicle(530, 2672.1262,-2421.1860,13.3976, 1.2609, 11, 0, -1); SetVehicleNumberPlate(Jobs_vehicles[9], "DOCK");
	Jobs_vehicles[10] = CreateVehicle(530, 2640.8159,-2389.7834,13.3978,85.6932, 11, 0, -1); SetVehicleNumberPlate(Jobs_vehicles[10], "DOCK");
	Jobs_vehicles[11] = CreateVehicle(530, 2446.9351,-2431.2043,13.3915,225.1755, 11, 0, -1); SetVehicleNumberPlate(Jobs_vehicles[11], "DOCK");

	for (new i = 0; i < 15; i ++) if (IsValidVehicle(Jobs_vehicles[i])) 
	{
		VehicleInfo[Jobs_vehicles[i]][E_VEHICLE_HEALTH] = 1000.0;
		VehicleInfo[Jobs_vehicles[i]][E_VEHICLE_FUEL] = 99999;
		VehicleInfo[Jobs_vehicles[i]][E_VEHICLE_CRATES] = 0;
		VehicleInfo[Jobs_vehicles[i]][E_VEHICLE_TRASHMASTER] = 0;

	}

	for (new i = 0; i < 38; i ++) if (IsValidVehicle(g_Vehicle[i])) 
	{
		VehicleInfo[g_Vehicle[i]][E_VEHICLE_HEALTH] = 1000.0;
		VehicleInfo[g_Vehicle[i]][E_VEHICLE_FUEL] = 99999;
	}

	//Police
	LSPDVehicles[0] = AddStaticVehicleEx(596,1585.8813,-1667.5236,5.5589,268.9741,36,1, 60000); // Cruiser HC
	LSPDVehicles[1] = AddStaticVehicleEx(596,1585.6987,-1671.8832,5.5520,271.2573,15,1, 60000); // Cruiser Command Team
	LSPDVehicles[2] = AddStaticVehicleEx(596,1585.7786,-1675.9716,5.5531,270.9127,108,1, 60000); // Cruiser Supervisor 1
	LSPDVehicles[3] = AddStaticVehicleEx(596,1585.8177,-1679.6355,5.5674,270.8011,108,1, 60000); // Cruiser Supervisor 2
	LSPDVehicles[4] = AddStaticVehicleEx(596,1602.5104,-1684.0599,5.5721,91.0629,0,1, 60000); // Cruiser
	LSPDVehicles[5] = AddStaticVehicleEx(596,1602.5287,-1688.0629,5.5712,88.9105,0,1, 60000); // Cruiser
	LSPDVehicles[6] = AddStaticVehicleEx(596,1602.4117,-1692.0302,5.5735,88.5088,0,1, 60000); // Cruiser
	LSPDVehicles[7] = AddStaticVehicleEx(596,1602.4979,-1696.1620,5.5303,92.1094,0,1, 60000); // Cruiser
	LSPDVehicles[8] = AddStaticVehicleEx(596,1602.3427,-1700.1394,5.5328,89.7606,0,1, 60000); // Cruiser
	LSPDVehicles[9] = AddStaticVehicleEx(596,1602.3191,-1704.4431,5.5304,88.5293,0,1, 60000); // Cruiser
	LSPDVehicles[10] = AddStaticVehicleEx(599,1595.4366,-1711.3505,5.9677,0.7363,0,1, 60000); // Bear 1
	LSPDVehicles[11] = AddStaticVehicleEx(599,1591.4089,-1711.5291,5.9700,359.3976,0,1, 60000); // Bear 2
	LSPDVehicles[12] = AddStaticVehicleEx(468,1566.6353,-1708.4395,5.5598,359.7773,0,0, 60000, 1); // Marry 1
	LSPDVehicles[13] = AddStaticVehicleEx(468,1566.9927,-1711.9053,5.5516,359.1170,0,0, 60000, 1); // Marry 2
	LSPDVehicles[14] = AddStaticVehicleEx(490,1545.6080,-1676.0394,6.0064,89.7384,0,1, 60000); // DAVID 3
	LSPDVehicles[15] = AddStaticVehicleEx(426,1528.6735,-1684.0107,5.6811,269.4669,198,198, 60000, 1); // TEU Premier 1
	LSPDVehicles[16] = AddStaticVehicleEx(426,1528.6068,-1687.9893,5.6737,271.4348,1,1, 60000, 1); // TEU Premier 2
	LSPDVehicles[17] = AddStaticVehicleEx(497,1566.6866,-1696.0535,28.6456,269.6936,0,1, 60000, 1);

	for (new i = 0; i < 18; i ++) if (IsValidVehicle(LSPDVehicles[i])) 
	{
		VehicleInfo[LSPDVehicles[i]][E_VEHICLE_HEALTH] = 1000.0;
		VehicleInfo[LSPDVehicles[i]][E_VEHICLE_FUEL] = 100;
	}
}
RemoveObjects(playerid)
{
    //Industrial
    RemoveBuildingForPlayer(playerid, 3776, 902.335, -1191.140, 25.039, 0.250);
    RemoveBuildingForPlayer(playerid, 3777, 902.335, -1191.140, 25.039, 0.250);
    RemoveBuildingForPlayer(playerid, 3776, 868.132, -1191.140, 25.039, 0.250);
    RemoveBuildingForPlayer(playerid, 3777, 868.132, -1191.140, 25.039, 0.250);
    RemoveBuildingForPlayer(playerid, 5864, 849.914, -1196.689, 19.406, 0.250);
    RemoveBuildingForPlayer(playerid, 5982, 849.914, -1196.689, 19.406, 0.250);
    RemoveBuildingForPlayer(playerid, 3776, 831.960, -1191.140, 25.039, 0.250);
    RemoveBuildingForPlayer(playerid, 3777, 831.960, -1191.140, 25.039, 0.250);
    RemoveBuildingForPlayer(playerid, 3623, 2618.860, -2429.300, 17.070, 0.250);
    RemoveBuildingForPlayer(playerid, 3709, 2618.860, -2429.300, 17.070, 0.250);
    RemoveBuildingForPlayer(playerid, 3623, 2639.550, -2429.300, 17.070, 0.250);
    RemoveBuildingForPlayer(playerid, 3709, 2639.550, -2429.300, 17.070, 0.250);

    //Garage
    RemoveBuildingForPlayer(playerid, 5340, 2644.859375, -2039.234375, 14.039100, 1.000000);
    RemoveBuildingForPlayer(playerid, 5779, 1041.351562, -1025.929688, 32.671902, 1.000000);
    RemoveBuildingForPlayer(playerid, 10575, -2716.351562, 217.476593, 5.382800, 1.000000);
    RemoveBuildingForPlayer(playerid, 11313, -1935.859375, 239.531296, 35.351601, 1.000000);
    RemoveBuildingForPlayer(playerid, 9093, 2386.656250, 1043.601562, 11.593800, 1.000000);
    RemoveBuildingForPlayer(playerid, 5422, 2071.476562, -1831.421875, 14.562500, 1.000000);
    RemoveBuildingForPlayer(playerid, 5856, 1024.984375, -1029.351562, 33.195301, 1.000000);
    RemoveBuildingForPlayer(playerid, 6400, 488.281311, -1734.695312, 12.390600, 1.000000);
    RemoveBuildingForPlayer(playerid, 11319, -1904.531250, 277.898407, 42.953098, 1.000000);
    RemoveBuildingForPlayer(playerid, 9625, -2425.726562, 1027.992188, 52.281300, 1.000000);
    RemoveBuildingForPlayer(playerid, 7891, 1968.742188, 2162.492188, 12.093800, 1.000000);
    RemoveBuildingForPlayer(playerid, 13028, 720.015625, -462.523407, 16.859400, 1.000000);
    RemoveBuildingForPlayer(playerid, 3294, -1420.546875, 2591.156250, 57.742199, 1.000000);
    RemoveBuildingForPlayer(playerid, 3294, -100.000000, 1111.414062, 21.640600, 1.000000);
    RemoveBuildingForPlayer(playerid, 5043, 1843.367188, -1856.320312, 13.875000, 1.000000);
    RemoveBuildingForPlayer(playerid, 7707, 2006.000000, 2317.601562, 11.312500, 1.000000);

	//Docksworker
	RemoveBuildingForPlayer(playerid, 3624, 2788.159, -2455.879, 16.726, 0.250);
	RemoveBuildingForPlayer(playerid, 3710, 2788.159, -2455.879, 16.726, 0.250);
	RemoveBuildingForPlayer(playerid, 3624, 2788.159, -2417.790, 16.726, 0.250);
	RemoveBuildingForPlayer(playerid, 3710, 2788.159, -2417.790, 16.726, 0.250);
	RemoveBuildingForPlayer(playerid, 3624, 2788.159, -2493.979, 16.726, 0.250);
	RemoveBuildingForPlayer(playerid, 3710, 2788.159, -2493.979, 16.726, 0.250);
	RemoveBuildingForPlayer(playerid, 3761, 2783.780, -2463.820, 14.632, 0.250);
	RemoveBuildingForPlayer(playerid, 3761, 2797.520, -2448.340, 14.632, 0.250);
	RemoveBuildingForPlayer(playerid, 3761, 2791.949, -2463.820, 14.632, 0.250);
	RemoveBuildingForPlayer(playerid, 3761, 2791.949, -2448.479, 14.632, 0.250);
	RemoveBuildingForPlayer(playerid, 3761, 2783.780, -2448.479, 14.632, 0.250);
	RemoveBuildingForPlayer(playerid, 3761, 2783.780, -2425.350, 14.632, 0.250);
	RemoveBuildingForPlayer(playerid, 3761, 2783.780, -2410.209, 14.671, 0.250);
	RemoveBuildingForPlayer(playerid, 3761, 2791.949, -2410.209, 14.656, 0.250);
	RemoveBuildingForPlayer(playerid, 3761, 2791.949, -2425.350, 14.671, 0.250);
	RemoveBuildingForPlayer(playerid, 3761, 2797.520, -2410.080, 14.632, 0.250);
	RemoveBuildingForPlayer(playerid, 3761, 2783.780, -2486.959, 14.656, 0.250);
	RemoveBuildingForPlayer(playerid, 3761, 2791.949, -2486.959, 14.632, 0.250);
	RemoveBuildingForPlayer(playerid, 3761, 2797.520, -2486.830, 14.632, 0.250);
	RemoveBuildingForPlayer(playerid, 3761, 2791.949, -2501.840, 14.632, 0.250);
	RemoveBuildingForPlayer(playerid, 3761, 2783.780, -2501.840, 14.695, 0.250);

	//All Spray Tag
	RemoveBuildingForPlayer(playerid, 1490, 2046.41, -1635.84, 13.5859, 0.25);
	RemoveBuildingForPlayer(playerid, 1490, 2066.43, -1652.48, 14.2812, 0.25);
	RemoveBuildingForPlayer(playerid, 1490, 2102.20, -1648.76, 13.5859, 0.25);
	RemoveBuildingForPlayer(playerid, 1490, 2399.41, -1552.03, 28.7500, 0.25);
	RemoveBuildingForPlayer(playerid, 1490, 2353.54, -1508.21, 24.7500, 0.25);
	RemoveBuildingForPlayer(playerid, 1490, 2394.10, -1468.37, 24.7812, 0.25);

	RemoveBuildingForPlayer(playerid, 1531, 1724.73, -1741.50, 14.1016, 0.25);
	RemoveBuildingForPlayer(playerid, 1531, 1767.21, -1617.54, 15.0391, 0.25);
	RemoveBuildingForPlayer(playerid, 1531, 1799.13, -1708.77, 14.1016, 0.25);
	RemoveBuildingForPlayer(playerid, 1531, 1746.75, -1359.77, 16.2109, 0.25);
	RemoveBuildingForPlayer(playerid, 1531, 1850.01, -1876.84, 14.3594, 0.25);
	RemoveBuildingForPlayer(playerid, 1531, 1889.24, -1982.51, 15.7578, 0.25);
	RemoveBuildingForPlayer(playerid, 1531, 1950.62, -2034.40, 14.0938, 0.25);
	RemoveBuildingForPlayer(playerid, 1531, 1936.88, -2134.91, 14.2188, 0.25);
	RemoveBuildingForPlayer(playerid, 1531, 1808.34, -2092.27, 14.2188, 0.25);
	RemoveBuildingForPlayer(playerid, 1531, 2273.90, -2265.80, 14.5625, 0.25);
	RemoveBuildingForPlayer(playerid, 1531, 2173.59, -2165.19, 15.3047, 0.25);

	RemoveBuildingForPlayer(playerid, 1530, 2281.46, -1118.96, 27.0078, 0.25);
	RemoveBuildingForPlayer(playerid, 1530, 2239.78, -999.75, 59.7578, 0.25);
	RemoveBuildingForPlayer(playerid, 1530, 2122.69, -1060.90, 25.3906, 0.25);
	RemoveBuildingForPlayer(playerid, 1530, 2062.72, -996.46, 48.2656, 0.25);
	RemoveBuildingForPlayer(playerid, 1530, 2076.73, -1071.13, 27.6094, 0.25);
	RemoveBuildingForPlayer(playerid, 1530, 2841.37, -1312.96, 18.8203, 0.25);
	RemoveBuildingForPlayer(playerid, 1530, 2820.34, -1190.98, 25.6719, 0.25);
	RemoveBuildingForPlayer(playerid, 1530, 2766.09, -1197.14, 69.0703, 0.25);
	RemoveBuildingForPlayer(playerid, 1530, 2756.01, -1388.12, 39.4609, 0.25);
	RemoveBuildingForPlayer(playerid, 1530, 2821.23, -1465.09, 16.5391, 0.25);
	RemoveBuildingForPlayer(playerid, 1530, 2767.78, -1621.19, 11.2344, 0.25);
	RemoveBuildingForPlayer(playerid, 1530, 2767.76, -1819.95, 12.2266, 0.25);
	RemoveBuildingForPlayer(playerid, 1530, 2667.89, -1469.13, 31.6797, 0.25);
	RemoveBuildingForPlayer(playerid, 1530, 2612.93, -1390.77, 35.4297, 0.25);
	RemoveBuildingForPlayer(playerid, 1530, 2536.22, -1352.77, 31.0859, 0.25);
	RemoveBuildingForPlayer(playerid, 1530, 2580.95, -1274.09, 46.5938, 0.25);
	RemoveBuildingForPlayer(playerid, 1530, 2603.16, -1197.81, 60.9922, 0.25);
	RemoveBuildingForPlayer(playerid, 1530, 2576.82, -1143.27, 48.2031, 0.25);
	RemoveBuildingForPlayer(playerid, 1530, 2621.51, -1092.20, 69.7969, 0.25);
	RemoveBuildingForPlayer(playerid, 1530, 2797.92, -1097.70, 31.0625, 0.25);
	RemoveBuildingForPlayer(playerid, 1530, 1332.13, -1722.30, 14.1875, 0.25);
	RemoveBuildingForPlayer(playerid, 1530, 1732.73, -963.08, 41.4375, 0.25);
	RemoveBuildingForPlayer(playerid, 1530, 1118.91, -2008.24, 75.0234, 0.25);
	RemoveBuildingForPlayer(playerid, 1530, 2273.20, -2529.12, 8.5156, 0.25);
	RemoveBuildingForPlayer(playerid, 1530, 2704.23, -2144.30, 11.8203, 0.25);

	RemoveBuildingForPlayer(playerid, 1529, 2379.32, -2166.22, 24.9453, 0.25);
	RemoveBuildingForPlayer(playerid, 1529, 810.57, -1797.57, 13.6172, 0.25);
	RemoveBuildingForPlayer(playerid, 1529, 730.45, -1482.01, 2.2500, 0.25);
	RemoveBuildingForPlayer(playerid, 1529, 947.48, -1466.72, 17.2422, 0.25);
	RemoveBuildingForPlayer(playerid, 1529, 399.01, -2066.88, 11.2344, 0.25);
	RemoveBuildingForPlayer(playerid, 1529, 466.98, -1283.02, 16.3203, 0.25);
	RemoveBuildingForPlayer(playerid, 1529, 583.46, -1502.11, 16.0000, 0.25);
	RemoveBuildingForPlayer(playerid, 1529, 944.27, -985.82, 39.2969, 0.25);
	RemoveBuildingForPlayer(playerid, 1529, 1072.91, -1012.80, 35.5156, 0.25);
	RemoveBuildingForPlayer(playerid, 1529, 1206.25, -1162.00, 23.8750, 0.25);
	RemoveBuildingForPlayer(playerid, 1529, 1098.81, -1292.55, 17.1406, 0.25);

	RemoveBuildingForPlayer(playerid, 1528, 2763.00, -2012.11, 14.1328, 0.25);
	RemoveBuildingForPlayer(playerid, 1528, 2794.53, -1906.81, 14.6719, 0.25);
	RemoveBuildingForPlayer(playerid, 1528, 2812.94, -1942.07, 11.0625, 0.25);
	RemoveBuildingForPlayer(playerid, 1528, 2874.50, -1909.38, 8.3906, 0.25);

	RemoveBuildingForPlayer(playerid, 1527, 2182.23, -1467.90, 25.5547, 0.25);
	RemoveBuildingForPlayer(playerid, 1527, 2132.23, -1258.09, 24.0547, 0.25);
	RemoveBuildingForPlayer(playerid, 1527, 2233.95, -1367.62, 24.5312, 0.25);
	RemoveBuildingForPlayer(playerid, 1527, 2224.77, -1193.06, 25.8359, 0.25);
	RemoveBuildingForPlayer(playerid, 1527, 2119.20, -1196.62, 24.6328, 0.25);
	RemoveBuildingForPlayer(playerid, 1527, 2522.46, -1478.74, 24.1641, 0.25);
	RemoveBuildingForPlayer(playerid, 1527, 2322.45, -1254.41, 22.9219, 0.25);
	RemoveBuildingForPlayer(playerid, 1527, 1448.23, -1755.90, 14.5234, 0.25);
	RemoveBuildingForPlayer(playerid, 1527, 1574.71, -2691.88, 13.6016, 0.25);
	RemoveBuildingForPlayer(playerid, 1527, 1071.14, -1863.79, 14.0938, 0.25);
	RemoveBuildingForPlayer(playerid, 1527, 2392.36, -1914.57, 14.7422, 0.25);
	RemoveBuildingForPlayer(playerid, 1527, 2430.33, -1997.91, 14.7422, 0.25);
	RemoveBuildingForPlayer(playerid, 1527, 2587.32, -2063.52, 4.6094, 0.25);

	RemoveBuildingForPlayer(playerid, 1525, 1974.09, -1351.16, 24.5625, 0.25);
	RemoveBuildingForPlayer(playerid, 1525, 2093.76, -1413.45, 24.1172, 0.25);
	RemoveBuildingForPlayer(playerid, 1525, 1969.59, -1289.70, 24.5625, 0.25);
	RemoveBuildingForPlayer(playerid, 1525, 1966.95, -1174.73, 20.0391, 0.25);
	RemoveBuildingForPlayer(playerid, 1525, 1911.87, -1064.40, 25.1875, 0.25);
	RemoveBuildingForPlayer(playerid, 1525, 2462.27, -1541.41, 25.4219, 0.25);
	RemoveBuildingForPlayer(playerid, 1525, 2346.52, -1350.78, 24.2812, 0.25);
	RemoveBuildingForPlayer(playerid, 1525, 2273.02, -1687.43, 14.9688, 0.25);
	RemoveBuildingForPlayer(playerid, 1525, 2422.91, -1682.30, 13.9922, 0.25);
	RemoveBuildingForPlayer(playerid, 1525, 1549.89, -1714.52, 15.1016, 0.25);
	RemoveBuildingForPlayer(playerid, 1525, 1498.63, -1207.35, 24.6797, 0.25);
	RemoveBuildingForPlayer(playerid, 1525, 1519.42, -1010.95, 24.6094, 0.25);
	RemoveBuildingForPlayer(playerid, 1525, 1687.23, -1239.12, 15.8125, 0.25);
	RemoveBuildingForPlayer(playerid, 1525, 1783.97, -2156.54, 14.3125, 0.25);
	RemoveBuildingForPlayer(playerid, 1525, 1624.62, -2296.24, 14.3125, 0.25);
	RemoveBuildingForPlayer(playerid, 1525, 2065.44, -1897.23, 13.6094, 0.25);
	RemoveBuildingForPlayer(playerid, 1525, 2134.33, -2011.20, 10.5156, 0.25);
	RemoveBuildingForPlayer(playerid, 1525, 1271.48, -1662.32, 20.2500, 0.25);

	RemoveBuildingForPlayer(playerid, 1524, 2162.78, -1786.07, 14.1875, 0.25);
	RemoveBuildingForPlayer(playerid, 1524, 2034.40, -1801.67, 14.5469, 0.25);
	RemoveBuildingForPlayer(playerid, 1524, 1910.16, -1779.66, 18.7500, 0.25);
	RemoveBuildingForPlayer(playerid, 1524, 1837.20, -1814.19, 4.3359, 0.25);
	RemoveBuildingForPlayer(playerid, 1524, 1837.66, -1640.38, 13.7578, 0.25);
	RemoveBuildingForPlayer(playerid, 1524, 1959.40, -1577.76, 13.7578, 0.25);
	RemoveBuildingForPlayer(playerid, 1524, 2074.18, -1579.15, 14.0312, 0.25);
	RemoveBuildingForPlayer(playerid, 1524, 2542.95, -1363.24, 31.7656, 0.25);
	RemoveBuildingForPlayer(playerid, 1524, 2704.20, -1966.69, 13.7578, 0.25);
	RemoveBuildingForPlayer(playerid, 1524, 2489.24, -1959.07, 13.7578, 0.25);
	RemoveBuildingForPlayer(playerid, 1524, 1295.18, -1465.22, 10.2812, 0.25);
	RemoveBuildingForPlayer(playerid, 1524, 482.63, -1761.59, 5.9141, 0.25);

	//PaynSpray
	RemoveBuildingForPlayer(playerid, 3574, 2313.050, -2008.540, 15.023, 0.250);
	RemoveBuildingForPlayer(playerid, 3744, 2313.050, -2008.540, 15.023, 0.250);
	RemoveBuildingForPlayer(playerid, 3574, 2331.379, -2001.670, 15.023, 0.250);
	RemoveBuildingForPlayer(playerid, 3744, 2331.379, -2001.670, 15.023, 0.250);
	RemoveBuildingForPlayer(playerid, 1260, 2336.909, -1987.630, 21.828, 0.250);
	RemoveBuildingForPlayer(playerid, 1266, 2336.909, -1987.630, 21.828, 0.250);

    //House Interior
	RemoveBuildingForPlayer(playerid, 2520, 234.602, 1109.380, 1079.949, 0.250);
	RemoveBuildingForPlayer(playerid, 2522, 235.602, 1112.239, 1079.969, 0.250);
	RemoveBuildingForPlayer(playerid, 2523, 232.656, 1108.829, 1079.989, 0.250);
	RemoveBuildingForPlayer(playerid, 2528, 232.632, 1110.589, 1079.979, 0.250);
	RemoveBuildingForPlayer(playerid, 1567, 2231.300, -1111.459, 1049.859, 0.250);
	RemoveBuildingForPlayer(playerid, 15039, 2232.340, -1106.739, 1049.750, 0.250);
	RemoveBuildingForPlayer(playerid, 15038, 2235.290, -1108.130, 1051.270, 0.250);
	RemoveBuildingForPlayer(playerid, 1741, 248.483, 306.125, 998.140, 0.250);
	RemoveBuildingForPlayer(playerid, 2088, 248.492, 304.351, 998.226, 0.250);
	RemoveBuildingForPlayer(playerid, 14863, 246.983, 303.578, 998.750, 0.250);
	RemoveBuildingForPlayer(playerid, 1741, 248.867, 301.960, 998.140, 0.250);
	RemoveBuildingForPlayer(playerid, 14861, 245.757, 302.234, 998.546, 0.250);
	RemoveBuildingForPlayer(playerid, 14862, 245.554, 300.859, 998.835, 0.250);
	RemoveBuildingForPlayer(playerid, 14860, 246.516, 301.585, 1000.000, 0.250);
	RemoveBuildingForPlayer(playerid, 2103, 248.406, 300.562, 999.304, 0.250);
	RemoveBuildingForPlayer(playerid, 1744, 250.102, 301.960, 999.453, 0.250);
	RemoveBuildingForPlayer(playerid, 1744, 250.102, 301.960, 1000.159, 0.250);
	RemoveBuildingForPlayer(playerid, 1740, 243.882, 301.976, 998.234, 0.250);
	RemoveBuildingForPlayer(playerid, 14864, 246.188, 303.109, 998.265, 0.250);
	RemoveBuildingForPlayer(playerid, 2091, 2819.800, -1165.660, 1028.160, 0.250);
	RemoveBuildingForPlayer(playerid, 2157, 2818.709, -1173.949, 1024.569, 0.250);
	RemoveBuildingForPlayer(playerid, 2046, 2819.449, -1174.000, 1026.359, 0.250);
	RemoveBuildingForPlayer(playerid, 2059, 2814.840, -1173.479, 1025.359, 0.250);
	RemoveBuildingForPlayer(playerid, 2047, 2817.310, -1170.969, 1031.170, 0.250);
	RemoveBuildingForPlayer(playerid, 2300, 2818.649, -1166.510, 1028.170, 0.250);
	RemoveBuildingForPlayer(playerid, 2069, 2806.389, -1166.819, 1024.630, 0.250);
	RemoveBuildingForPlayer(playerid, 2100, 2805.510, -1165.560, 1024.569, 0.250);
	RemoveBuildingForPlayer(playerid, 2068, 2809.199, -1169.369, 1027.530, 0.250);
	RemoveBuildingForPlayer(playerid, 2156, 2813.649, -1167.000, 1024.569, 0.250);
	RemoveBuildingForPlayer(playerid, 2160, 2815.899, -1164.910, 1024.560, 0.250);
	RemoveBuildingForPlayer(playerid, 2159, 2817.270, -1164.910, 1024.560, 0.250);
	RemoveBuildingForPlayer(playerid, 2157, 2818.639, -1164.910, 1024.560, 0.250);
	RemoveBuildingForPlayer(playerid, 2157, 2820.629, -1167.310, 1024.569, 0.250);
	RemoveBuildingForPlayer(playerid, 2116, 2814.300, -1173.420, 1024.550, 0.250);
	RemoveBuildingForPlayer(playerid, 2121, 2815.379, -1172.479, 1025.089, 0.250);
	RemoveBuildingForPlayer(playerid, 2121, 2813.949, -1172.459, 1025.089, 0.250);
	RemoveBuildingForPlayer(playerid, 1765, 2811.479, -1168.410, 1024.560, 0.250);
	RemoveBuildingForPlayer(playerid, 2053, 2810.610, -1167.579, 1024.630, 0.250);
	RemoveBuildingForPlayer(playerid, 2297, 2811.020, -1165.060, 1024.560, 0.250);
	RemoveBuildingForPlayer(playerid, 2058, 2809.639, -1165.339, 1024.579, 0.250);
	RemoveBuildingForPlayer(playerid, 1821, 2810.590, -1167.619, 1024.560, 0.250);
	RemoveBuildingForPlayer(playerid, 1764, 2808.659, -1166.949, 1024.569, 0.250);
	RemoveBuildingForPlayer(playerid, 2276, 2809.209, -1165.270, 1026.689, 0.250);
	RemoveBuildingForPlayer(playerid, 2272, 2811.340, -1165.270, 1026.790, 0.250);
	RemoveBuildingForPlayer(playerid, 2275, 2812.610, -1168.109, 1026.449, 0.250);
	RemoveBuildingForPlayer(playerid, 2060, 2810.020, -1171.229, 1024.699, 0.250);
	RemoveBuildingForPlayer(playerid, 1736, 2812.830, -1172.300, 1027.050, 0.250);
	RemoveBuildingForPlayer(playerid, 2051, 2813.129, -1171.290, 1026.339, 0.250);
	RemoveBuildingForPlayer(playerid, 2050, 2813.129, -1173.339, 1026.339, 0.250);
	RemoveBuildingForPlayer(playerid, 2064, 2810.840, -1171.900, 1025.199, 0.250);
	RemoveBuildingForPlayer(playerid, 2060, 2811.600, -1172.849, 1025.209, 0.250);
	RemoveBuildingForPlayer(playerid, 2060, 2811.600, -1172.849, 1025.050, 0.250);
	RemoveBuildingForPlayer(playerid, 2060, 2811.600, -1172.849, 1024.699, 0.250);
	RemoveBuildingForPlayer(playerid, 2060, 2811.600, -1172.849, 1024.880, 0.250);
	RemoveBuildingForPlayer(playerid, 2060, 2810.300, -1172.849, 1025.209, 0.250);
	RemoveBuildingForPlayer(playerid, 2060, 2810.300, -1172.849, 1025.050, 0.250);
	RemoveBuildingForPlayer(playerid, 2060, 2810.300, -1172.849, 1024.880, 0.250);
	RemoveBuildingForPlayer(playerid, 2060, 2810.300, -1172.849, 1024.699, 0.250);
	RemoveBuildingForPlayer(playerid, 2046, 2806.229, -1174.569, 1026.359, 0.250);
	RemoveBuildingForPlayer(playerid, 2049, 2805.209, -1173.489, 1026.520, 0.250);
	RemoveBuildingForPlayer(playerid, 2241, 2805.689, -1173.520, 1025.069, 0.250);
	RemoveBuildingForPlayer(playerid, 2048, 2805.209, -1172.050, 1026.890, 0.250);
	RemoveBuildingForPlayer(playerid, 2055, 2805.199, -1170.540, 1026.510, 0.250);
	RemoveBuildingForPlayer(playerid, 2255, 2814.570, -1169.290, 1029.910, 0.250);
	RemoveBuildingForPlayer(playerid, 1755, 2325.270, -1025.060, 1049.140, 0.250);
	RemoveBuildingForPlayer(playerid, 2112, 2322.659, -1026.420, 1049.589, 0.250);
	RemoveBuildingForPlayer(playerid, 2241, 2322.449, -1026.449, 1050.500, 0.250);
	RemoveBuildingForPlayer(playerid, 2105, 2323.020, -1026.859, 1050.449, 0.250);
	RemoveBuildingForPlayer(playerid, 1760, 2327.800, -1021.030, 1049.199, 0.250);
	RemoveBuildingForPlayer(playerid, 2117, 2329.699, -1022.590, 1049.199, 0.250);
	RemoveBuildingForPlayer(playerid, 1739, 2329.050, -1022.700, 1050.109, 0.250);
	RemoveBuildingForPlayer(playerid, 1739, 2328.840, -1023.599, 1050.109, 0.250);
	RemoveBuildingForPlayer(playerid, 2868, 2329.770, -1023.020, 1050.000, 0.250);
	RemoveBuildingForPlayer(playerid, 2829, 2329.469, -1023.630, 1050.010, 0.250);
	RemoveBuildingForPlayer(playerid, 1739, 2330.370, -1022.690, 1050.109, 0.250);
	RemoveBuildingForPlayer(playerid, 1739, 2330.370, -1023.520, 1050.109, 0.250);
	RemoveBuildingForPlayer(playerid, 2243, 2329.300, -1018.030, 1049.400, 0.250);
	RemoveBuildingForPlayer(playerid, 2295, 2328.790, -1015.830, 1049.199, 0.250);
	RemoveBuildingForPlayer(playerid, 2229, 2329.070, -1017.280, 1049.199, 0.250);
	RemoveBuildingForPlayer(playerid, 2104, 2327.169, -1017.210, 1049.209, 0.250);
	RemoveBuildingForPlayer(playerid, 2229, 2325.639, -1017.280, 1049.199, 0.250);
	RemoveBuildingForPlayer(playerid, 2224, 2322.699, -1019.090, 1049.199, 0.250);
	RemoveBuildingForPlayer(playerid, 2242, 2321.459, -1019.750, 1049.369, 0.250);
	RemoveBuildingForPlayer(playerid, 2244, 2322.360, -1019.890, 1049.479, 0.250);
	RemoveBuildingForPlayer(playerid, 2078, 2318.260, -1017.599, 1049.199, 0.250);
	RemoveBuildingForPlayer(playerid, 2291, 2323.790, -1009.590, 1049.209, 0.250);
	RemoveBuildingForPlayer(playerid, 2291, 2324.780, -1009.590, 1049.209, 0.250);
	RemoveBuildingForPlayer(playerid, 2291, 2325.780, -1009.590, 1049.209, 0.250);
	RemoveBuildingForPlayer(playerid, 2291, 2326.770, -1009.590, 1049.209, 0.250);
	RemoveBuildingForPlayer(playerid, 2291, 2327.760, -1009.590, 1049.209, 0.250);
	RemoveBuildingForPlayer(playerid, 2291, 2329.189, -1010.020, 1049.209, 0.250);
	RemoveBuildingForPlayer(playerid, 2291, 2329.189, -1011.010, 1049.209, 0.250);
	RemoveBuildingForPlayer(playerid, 2291, 2329.189, -1011.989, 1049.209, 0.250);
	RemoveBuildingForPlayer(playerid, 1822, 2326.629, -1012.219, 1049.209, 0.250);
	RemoveBuildingForPlayer(playerid, 1822, 2324.340, -1012.219, 1049.209, 0.250);
	RemoveBuildingForPlayer(playerid, 2107, 2326.070, -1016.669, 1050.660, 0.250);
	RemoveBuildingForPlayer(playerid, 2261, 2322.459, -1015.429, 1051.160, 0.250);
	RemoveBuildingForPlayer(playerid, 2281, 2324.310, -1017.799, 1051.229, 0.250);
	RemoveBuildingForPlayer(playerid, 2285, 2328.979, -1007.640, 1051.229, 0.250);
	RemoveBuildingForPlayer(playerid, 1735, 2318.800, -1007.969, 1049.199, 0.250);
	RemoveBuildingForPlayer(playerid, 2139, 2317.340, -1009.590, 1049.199, 0.250);
	RemoveBuildingForPlayer(playerid, 2139, 2317.340, -1007.609, 1049.199, 0.250);
	RemoveBuildingForPlayer(playerid, 2139, 2317.340, -1008.599, 1049.199, 0.250);
	RemoveBuildingForPlayer(playerid, 2305, 2312.370, -1007.630, 1049.199, 0.250);
	RemoveBuildingForPlayer(playerid, 2135, 2313.340, -1007.630, 1049.199, 0.250);
	RemoveBuildingForPlayer(playerid, 2138, 2314.330, -1007.630, 1049.199, 0.250);
	RemoveBuildingForPlayer(playerid, 2138, 2312.370, -1008.609, 1049.199, 0.250);
	RemoveBuildingForPlayer(playerid, 2831, 2312.189, -1010.659, 1050.270, 0.250);
	RemoveBuildingForPlayer(playerid, 2136, 2312.360, -1010.609, 1049.199, 0.250);
	RemoveBuildingForPlayer(playerid, 2830, 2312.139, -1013.669, 1050.260, 0.250);
	RemoveBuildingForPlayer(playerid, 2203, 2312.159, -1014.549, 1050.420, 0.250);
	RemoveBuildingForPlayer(playerid, 2139, 2312.379, -1014.549, 1049.199, 0.250);
	RemoveBuildingForPlayer(playerid, 2139, 2312.379, -1013.559, 1049.199, 0.250);
	RemoveBuildingForPlayer(playerid, 2139, 2312.379, -1012.570, 1049.199, 0.250);
	RemoveBuildingForPlayer(playerid, 2303, 2312.360, -1011.590, 1049.199, 0.250);
	RemoveBuildingForPlayer(playerid, 2079, 2313.889, -1011.580, 1049.839, 0.250);
	RemoveBuildingForPlayer(playerid, 2079, 2313.889, -1010.539, 1049.839, 0.250);
	RemoveBuildingForPlayer(playerid, 2832, 2315.050, -1011.280, 1050.000, 0.250);
	RemoveBuildingForPlayer(playerid, 2079, 2314.979, -1009.299, 1049.839, 0.250);
	RemoveBuildingForPlayer(playerid, 2079, 2315.929, -1010.549, 1049.839, 0.250);
	RemoveBuildingForPlayer(playerid, 2079, 2315.929, -1011.590, 1049.839, 0.250);
	RemoveBuildingForPlayer(playerid, 2115, 2314.989, -1011.409, 1049.199, 0.250);
	RemoveBuildingForPlayer(playerid, 2079, 2314.979, -1012.679, 1049.839, 0.250);
	RemoveBuildingForPlayer(playerid, 2165, 2323.379, -1015.900, 1053.699, 0.250);
	RemoveBuildingForPlayer(playerid, 1714, 2323.750, -1014.859, 1053.709, 0.250);
	RemoveBuildingForPlayer(playerid, 2088, 2325.530, -1015.090, 1053.699, 0.250);
	RemoveBuildingForPlayer(playerid, 2088, 2327.479, -1015.090, 1053.699, 0.250);
	RemoveBuildingForPlayer(playerid, 2295, 2329.260, -1015.830, 1053.790, 0.250);
	RemoveBuildingForPlayer(playerid, 2096, 2330.229, -1012.969, 1053.709, 0.250);
	RemoveBuildingForPlayer(playerid, 2240, 2330.739, -1010.780, 1054.260, 0.250);
	RemoveBuildingForPlayer(playerid, 2096, 2330.229, -1009.190, 1053.709, 0.250);
	RemoveBuildingForPlayer(playerid, 2106, 2327.729, -1006.950, 1054.229, 0.250);
	RemoveBuildingForPlayer(playerid, 2106, 2325.040, -1006.950, 1054.229, 0.250);
	RemoveBuildingForPlayer(playerid, 2298, 2325.060, -1010.719, 1053.699, 0.250);
	RemoveBuildingForPlayer(playerid, 2331, 2323.449, -1009.280, 1053.949, 0.250);
	RemoveBuildingForPlayer(playerid, 2333, 2323.489, -1009.729, 1053.699, 0.250);
	RemoveBuildingForPlayer(playerid, 1502, 2317.050, -1006.700, 1053.699, 0.250);
	RemoveBuildingForPlayer(playerid, 2194, 2322.360, -1008.450, 1054.949, 0.250);
	RemoveBuildingForPlayer(playerid, 2526, 2318.379, -1003.070, 1053.739, 0.250);
	RemoveBuildingForPlayer(playerid, 2523, 2322.250, -1003.070, 1053.719, 0.250);
	RemoveBuildingForPlayer(playerid, 2528, 2321.270, -1006.030, 1053.729, 0.250);
	RemoveBuildingForPlayer(playerid, 2249, 2323.020, -1005.880, 1054.400, 0.250);
	RemoveBuildingForPlayer(playerid, 1567, 2315.760, -1011.520, 1053.709, 0.250);

}

stock InsertObjects()
{
    //Garbageman
    tmpobjid = CreateDynamicObject(1411, 1536.800292, -1842.484375, 14.106877, 0.000000, 0.000000, 180.000000, -1, -1, -1, 800.00, 800.00); 
    tmpobjid = CreateDynamicObject(1411, 1531.619018, -1842.484375, 14.106877, 0.000000, 0.000000, 180.000000, -1, -1, -1, 800.00, 800.00); 
    tmpobjid = CreateDynamicObject(1411, 1522.150146, -1842.484375, 14.106877, 0.000000, 0.000000, 180.000000, -1, -1, -1, 800.00, 800.00); 
    tmpobjid = CreateDynamicObject(1411, 1516.910644, -1842.484375, 14.106877, 0.000000, 0.000000, 180.000000, -1, -1, -1, 800.00, 800.00); 
    tmpobjid = CreateDynamicObject(1411, 1511.710693, -1842.484375, 14.106877, 0.000000, 0.000000, 180.000000, -1, -1, -1, 800.00, 800.00); 
    tmpobjid = CreateDynamicObject(1411, 1506.510986, -1842.484375, 14.106877, 0.000000, 0.000000, 180.000000, -1, -1, -1, 800.00, 800.00); 
    tmpobjid = CreateDynamicObject(1411, 1503.030517, -1847.925903, 14.106877, 0.000000, 0.000000, 270.000000, -1, -1, -1, 800.00, 800.00); 
    //Industrial
    tmpobjid = CreateDynamicObject(19482, 2610.919921, -2443.353027, 16.571224, 0.000000, 0.000000, 90.000000, -1, -1, -1, 800.00, 800.00); 
    SetDynamicObjectMaterialText(tmpobjid, 0, "{000000}F&M FACTORIES", 120, "Ariel", 40, 1, 0x00000000, 0x00000000, 1);
    tmpobjid = CreateDynamicObject(19482, 924.989379, -1222.038208, 24.325054, 0.000000, 0.000000, 0.199999, -1, -1, -1, 800.00, 800.00); 
    SetDynamicObjectMaterialText(tmpobjid, 0, "{000000}Waterford Industries", 120, "Ariel", 60, 1, 0x00000000, 0x00000000, 1);
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    tmpobjid = CreateDynamicObject(17012, 871.871276, -1181.831298, 21.023527, 0.000000, 0.000000, 810.000000, -1, -1, -1, 800.00, 800.00); 
    tmpobjid = CreateDynamicObject(5864, 849.914001, -1196.689941, 19.406299, 0.000000, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
    tmpobjid = CreateDynamicObject(996, 874.250671, -1210.277954, 16.656602, 0.000000, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
    tmpobjid = CreateDynamicObject(996, 859.509521, -1210.277954, 16.656602, 0.000000, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
    tmpobjid = CreateDynamicObject(1215, 895.288696, -1210.301635, 16.476573, 0.000000, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
    tmpobjid = CreateDynamicObject(1215, 893.597290, -1210.301635, 16.476573, 0.000000, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
    tmpobjid = CreateDynamicObject(1215, 891.636657, -1210.301635, 16.476573, 0.000000, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
    tmpobjid = CreateDynamicObject(1215, 885.998168, -1210.301635, 16.476573, 0.000000, 0.000014, 0.000000, -1, -1, -1, 800.00, 800.00); 
    tmpobjid = CreateDynamicObject(1215, 884.306762, -1210.301635, 16.476573, 0.000000, 0.000014, 0.000000, -1, -1, -1, 800.00, 800.00); 
    tmpobjid = CreateDynamicObject(1215, 882.346130, -1210.301635, 16.476573, 0.000000, 0.000014, 0.000000, -1, -1, -1, 800.00, 800.00); 
    tmpobjid = CreateDynamicObject(1215, 858.064025, -1210.301635, 16.476573, 0.000000, 0.000022, 0.000000, -1, -1, -1, 800.00, 800.00); 
    tmpobjid = CreateDynamicObject(1215, 856.372619, -1210.301635, 16.476573, 0.000000, 0.000022, 0.000000, -1, -1, -1, 800.00, 800.00); 
    tmpobjid = CreateDynamicObject(1215, 854.411987, -1210.301635, 16.476573, 0.000000, 0.000022, 0.000000, -1, -1, -1, 800.00, 800.00); 
    tmpobjid = CreateDynamicObject(996, 832.713623, -613.108459, 16.035934, 0.000000, 0.000000, 90.000000, -1, -1, -1, 800.00, 800.00); 
    tmpobjid = CreateDynamicObject(996, 827.493469, -612.959106, 16.035934, 0.000000, 0.000000, 90.000000, -1, -1, -1, 800.00, 800.00); 
    tmpobjid = CreateDynamicObject(1215, 832.386657, -605.669921, 15.855940, 0.000000, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
    tmpobjid = CreateDynamicObject(1215, 827.725891, -605.669921, 15.855940, 0.000000, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
    tmpobjid = CreateDynamicObject(1215, 829.986450, -605.669921, 15.855940, 0.000000, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
    tmpobjid = CreateDynamicObject(996, 822.762695, -612.959106, 16.035934, 0.000000, 0.000000, 90.000000, -1, -1, -1, 800.00, 800.00); 
    tmpobjid = CreateDynamicObject(996, 817.552062, -612.959106, 16.035934, 0.000000, 0.000000, 90.000000, -1, -1, -1, 800.00, 800.00); 
    tmpobjid = CreateDynamicObject(1215, 822.494506, -605.669921, 15.855940, 0.000000, 0.000007, 0.000000, -1, -1, -1, 800.00, 800.00); 
    tmpobjid = CreateDynamicObject(1215, 817.833740, -605.669921, 15.855940, 0.000000, 0.000007, 0.000000, -1, -1, -1, 800.00, 800.00); 
    tmpobjid = CreateDynamicObject(1215, 820.094299, -605.669921, 15.855940, 0.000000, 0.000007, 0.000000, -1, -1, -1, 800.00, 800.00); 
    tmpobjid = CreateDynamicObject(10843, 2627.738281, -2433.696289, 20.462427, 0.000000, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
    tmpobjid = CreateDynamicObject(1508, 2610.644287, -2443.351318, 14.271495, 0.000000, 0.000000, 90.000000, -1, -1, -1, 800.00, 800.00); 
    tmpobjid = CreateDynamicObject(994, 2607.096923, -2443.376220, 12.631551, 0.000000, 0.000000, 90.000000, -1, -1, -1, 800.00, 800.00); 
    tmpobjid = CreateDynamicObject(994, 2607.096923, -2435.392822, 12.631551, 0.000000, 0.000000, 90.000000, -1, -1, -1, 800.00, 800.00); 
    tmpobjid = CreateDynamicObject(3576, 2612.677001, -2424.440429, 14.100787, 0.000000, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
    tmpobjid = CreateDynamicObject(3576, 2609.904296, -2419.040527, 14.100787, 0.000000, 0.000000, -45.300006, -1, -1, -1, 800.00, 800.00); 

	//DockWorker
	tmpobjid = CreateDynamicObject(19357, 2209.845458, -2217.223388, 12.466873, 0.000000, 90.000000, -44.200000, -1, -1, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 10778, "airportcpark_sfse", "ws_carpark3", 0x00000000);
	tmpobjid = CreateDynamicObject(19357, 2217.137207, -2210.417480, 12.466873, 0.000000, 90.000000, -44.200000, -1, -1, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 10778, "airportcpark_sfse", "ws_carpark3", 0x00000000);
	tmpobjid = CreateDynamicObject(19357, 2202.768554, -2224.772949, 12.466873, 0.000000, 90.000000, -44.200000, -1, -1, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 10778, "airportcpark_sfse", "ws_carpark3", 0x00000000);
	tmpobjid = CreateDynamicObject(19379, 2815.981445, -2436.867187, 11.755403, 0.000000, 98.600051, 0.000000, -1, -1, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 9583, "bigshap_sfw", "shipceiling_sfw", 0x00000000);
	tmpobjid = CreateDynamicObject(19379, 2815.981445, -2388.335449, 11.755403, 0.000000, 98.600051, 0.000000, -1, -1, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 9583, "bigshap_sfw", "shipceiling_sfw", 0x00000000);
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	tmpobjid = CreateDynamicObject(5126, 2790.643798, -2434.140869, 27.649303, 0.000000, 0.000000, 90.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(5126, 2790.643798, -2495.600097, 27.649303, 0.000000, 0.000000, 270.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(8339, 2786.590332, -2463.179931, 16.605548, 0.000000, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(8075, 2789.653808, -2410.711181, 16.560054, 0.000000, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(3574, 2788.802246, -2525.272216, 15.322412, 0.000000, 0.000000, 270.000000, -1, -1, -1, 800.00, 800.00); 

	//Furniturestore
	tmpobjid = CreateDynamicObject(19379, 1359.067871, 1707.377685, 433.893280, 0.000000, 90.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 3980, "cityhall_lan", "man_cellarfloor128", 0x00000000);
	tmpobjid = CreateDynamicObject(19379, 1354.499023, 1707.377685, 433.343017, 0.000000, 180.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 10053, "slapart01sfe", "sl_hiriseredconc", 0x00000000);
	tmpobjid = CreateDynamicObject(19379, 1364.207885, 1707.377685, 433.343017, 0.000000, 180.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 10053, "slapart01sfe", "sl_hiriseredconc", 0x00000000);
	tmpobjid = CreateDynamicObject(19379, 1359.338623, 1712.117187, 433.343017, 0.000000, 180.000000, 270.000000, -1, -1, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 10053, "slapart01sfe", "sl_hiriseredconc", 0x00000000);
	tmpobjid = CreateDynamicObject(19379, 1359.338623, 1702.635986, 433.343017, 0.000000, 180.000000, 270.000000, -1, -1, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 10053, "slapart01sfe", "sl_hiriseredconc", 0x00000000);
	tmpobjid = CreateDynamicObject(19379, 1359.067871, 1707.377685, 438.402923, 0.000000, 90.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 3980, "cityhall_lan", "man_cellarfloor128", 0x00000000);
	tmpobjid = CreateDynamicObject(3032, 1364.101684, 1704.744873, 435.629119, 0.000007, 0.000000, 89.999977, -1, -1, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 12946, "ce_bankalley1", "newindow13", 0x00000000);
	tmpobjid = CreateDynamicObject(3032, 1364.101684, 1710.065795, 435.629119, 0.000007, 0.000000, 89.999977, -1, -1, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 12946, "ce_bankalley1", "newindow13", 0x00000000);
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	tmpobjid = CreateDynamicObject(1893, 1361.363769, 1709.803833, 438.859100, 0.000000, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(1893, 1356.709350, 1709.803833, 438.859100, 0.000000, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(1893, 1356.709350, 1705.000366, 438.859100, 0.000000, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(1893, 1361.330810, 1704.980346, 438.859100, 0.000000, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(1522, 1364.175170, 1708.172729, 433.979217, 0.000000, 0.000000, 270.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(2626, 1356.104736, 1703.703247, 434.509216, 0.000000, 0.000000, 90.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(1550, 1356.025634, 1703.004516, 434.289154, 0.000000, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(362, 1356.163696, 1703.170776, 434.049316, 0.000000, 0.000000, 90.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(1793, 1354.637939, 1708.266723, 435.350677, 0.000000, 79.799995, 0.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(2121, 1356.326049, 1711.674316, 434.459442, 0.000000, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(2121, 1356.326049, 1711.315673, 434.631195, 42.899978, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(1433, 1356.524047, 1709.901000, 434.149139, 0.000000, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(912, 1360.109863, 1711.630126, 434.529113, 0.000000, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(19831, 1363.060791, 1711.669189, 433.979217, 0.000000, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(19831, 1362.129882, 1711.669189, 433.979217, 0.000000, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(912, 1358.688842, 1711.630126, 434.529113, 0.000000, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(2694, 1360.505004, 1711.546875, 434.809204, 0.000000, 0.000000, 270.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(2694, 1359.754394, 1711.546875, 434.809204, 0.000000, 0.000000, 270.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(2694, 1359.083618, 1711.546875, 434.809204, -0.000007, -0.000000, -89.999977, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(2694, 1358.333007, 1711.546875, 434.809204, -0.000007, -0.000000, -89.999977, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(2694, 1360.505004, 1711.546875, 434.469085, -0.000007, -0.000000, -89.999977, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(2694, 1359.754394, 1711.546875, 434.469085, -0.000007, -0.000000, -89.999977, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(2694, 1359.083618, 1711.546875, 434.469085, -0.000015, 0.000000, -89.999954, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(2694, 1358.333007, 1711.546875, 434.469085, -0.000015, 0.000000, -89.999954, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(2694, 1360.505004, 1711.546875, 434.098907, -0.000015, 0.000000, -89.999954, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(2694, 1359.754394, 1711.546875, 434.098907, -0.000015, 0.000000, -89.999954, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(2694, 1359.083618, 1711.546875, 434.098907, -0.000022, 0.000000, -89.999931, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(2694, 1358.333007, 1711.546875, 434.098907, -0.000022, 0.000000, -89.999931, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(2654, 1358.717773, 1711.579101, 435.289062, 0.000000, 0.000000, 450.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(2654, 1360.148681, 1711.579101, 435.289062, 0.000000, 0.000000, 450.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(2631, 1362.840454, 1704.662231, 433.979217, 0.000000, 0.000000, 90.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(912, 1360.149902, 1703.089477, 434.529113, 0.000000, 0.000000, 180.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(1985, 1362.804687, 1703.988159, 438.402191, 0.000000, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(2916, 1363.205688, 1703.943969, 434.133056, 0.000000, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(2916, 1362.434936, 1703.943969, 434.133056, 0.000000, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(912, 1358.748535, 1703.089477, 434.529113, 0.000000, 0.000000, 180.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(2103, 1360.079589, 1703.209838, 435.099273, 0.000000, 0.000000, 180.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(2103, 1358.698242, 1703.209838, 435.099273, 0.000000, 0.000000, 180.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(19555, 1360.449707, 1703.119384, 434.749053, 90.000000, 360.000000, 360.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(19556, 1360.008666, 1703.149169, 434.759307, 90.000000, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(19555, 1358.918212, 1703.119384, 434.749053, 89.999992, 450.000000, -89.999992, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(19556, 1358.477172, 1703.149169, 434.759307, 89.999992, 89.999992, -89.999992, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(19585, 1358.737304, 1703.360961, 434.529357, 0.000000, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(19585, 1360.207275, 1703.360961, 434.529357, 0.000000, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(19585, 1359.786865, 1703.360961, 434.209228, 0.000000, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(19585, 1359.146240, 1703.360961, 434.209228, 0.000000, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 

	//Generalstore
	tmpobjid = CreateDynamicObject(19379, -49.815429, 2.279375, 202.177368, 0.000000, 90.000007, 0.000000, -1, -1, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 14709, "lamidint2", "mp_apt1_bathfloor1", 0x00000000);
	tmpobjid = CreateDynamicObject(19379, -55.065471, 2.279375, 201.287368, 0.000000, 180.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 12855, "cunte_cop", "sw_brick05", 0x00000000);
	tmpobjid = CreateDynamicObject(19379, -45.385490, 2.279375, 201.287368, 0.000000, 180.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 12855, "cunte_cop", "sw_brick05", 0x00000000);
	tmpobjid = CreateDynamicObject(19379, -50.235412, 6.969374, 201.287368, 0.000007, 180.000000, 89.999977, -1, -1, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 12855, "cunte_cop", "sw_brick05", 0x00000000);
	tmpobjid = CreateDynamicObject(19379, -49.815429, 2.279375, 206.467239, 0.000000, 270.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 3895, "inditaly", "tenwhitebrick64", 0x00000000);
	tmpobjid = CreateDynamicObject(19379, -50.235412, -2.610626, 201.287368, 0.000007, 180.000000, 89.999977, -1, -1, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 12855, "cunte_cop", "sw_brick05", 0x00000000);
	tmpobjid = CreateDynamicObject(19482, -50.017234, -2.499486, 203.583389, 0.000000, 0.000000, 90.000000, -1, -1, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 4227, "graffiti_lan01", "cleargraf01_LA", 0x00000000);
	tmpobjid = CreateDynamicObject(19482, -51.497234, 6.860522, 203.653396, 0.000000, 0.000000, 270.000000, -1, -1, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 4981, "wiresetc2_las", "ganggraf03_LA", 0x00000000);
	tmpobjid = CreateDynamicObject(3034, -45.481777, -0.496737, 203.863327, 0.000000, 0.000000, 270.000000, -1, -1, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 12946, "ce_bankalley1", "newindow13", 0x00000000);
	tmpobjid = CreateDynamicObject(3034, -45.481777, 5.023260, 203.863327, 0.000000, 0.000000, 270.000000, -1, -1, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 12946, "ce_bankalley1", "newindow13", 0x00000000);
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	tmpobjid = CreateDynamicObject(1893, -47.715503, 4.682677, 206.903854, 0.000000, 0.000007, 0.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(1893, -53.595478, 4.682677, 206.903854, 0.000000, 0.000007, 0.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(1893, -47.715503, 0.022679, 206.903854, 0.000000, 0.000015, 0.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(1893, -53.595478, 0.022679, 206.903854, 0.000000, 0.000015, 0.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(1522, -45.423656, 3.062862, 202.263305, 0.000000, 0.000000, 270.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(19640, -48.038055, 6.365225, 202.263305, 0.000000, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(19640, -51.498085, 6.365225, 202.263305, 0.000000, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(1984, -53.656913, -0.049523, 202.263305, 0.000000, 0.000000, 270.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(1843, -48.609718, -2.028584, 202.263305, 0.000000, 0.000000, 180.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(336, -53.823436, 6.306971, 202.776947, 0.000000, 67.999992, 0.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(1338, -53.837821, 6.157994, 202.263305, 0.000000, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(336, -53.823436, 6.046966, 202.776947, 0.000000, 67.999992, 0.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(336, -53.823436, 6.046966, 202.776947, 0.000000, -77.199996, 0.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(336, -54.035209, 5.998799, 202.819335, -24.899991, -78.299980, 43.199996, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(2045, -54.031200, 6.210261, 202.733230, 0.000000, 0.000000, -26.599988, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(2045, -53.637767, 6.013250, 202.733230, 0.000000, 0.000000, -60.100002, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(18868, -52.299747, 6.452274, 203.703292, 0.000000, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(18868, -52.089771, 6.452274, 203.703292, 0.000000, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(18868, -51.899791, 6.452274, 203.703292, 0.000000, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(19942, -51.657810, 6.464463, 203.722427, -94.300018, 6.400001, 0.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(19942, -51.450153, 6.521510, 203.718063, -94.300018, 6.400001, 2.499999, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(19942, -51.270584, 6.509322, 203.719482, -94.300018, 6.400001, 2.499999, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(19942, -51.108230, 6.538283, 203.717773, -94.300018, 6.400001, 2.499999, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(19942, -50.858814, 6.521357, 203.719818, -94.300018, 6.400001, 2.499999, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(19942, -50.679233, 6.509170, 203.721282, -94.300018, 6.400001, 2.499999, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(1650, -52.265495, 6.807435, 203.213226, 0.000000, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(1650, -51.785537, 6.807435, 203.213226, 0.000000, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(19921, -51.156517, 6.358495, 202.983123, 0.000000, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(365, -48.848133, 6.590269, 203.843200, 0.000000, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(365, -48.568168, 6.590269, 203.843231, 0.000000, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(365, -48.298164, 6.590269, 203.843353, 0.000000, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(365, -47.988132, 6.590269, 203.843200, 0.000000, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(365, -47.698150, 6.590269, 203.843200, 0.000000, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(365, -47.368156, 6.590269, 203.843200, 0.000000, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(18634, -47.629402, 6.585095, 203.021972, 123.400016, 0.000000, 180.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(18634, -48.049369, 6.585095, 203.021972, 123.400016, 0.000000, 180.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(18634, -48.499336, 6.585095, 203.021972, 123.400016, 0.000000, 180.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(2443, -54.634571, 2.880167, 202.243286, 0.000000, 0.000000, 90.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(2674, -50.789505, -1.002036, 202.283264, 0.000000, 0.000000, 35.800006, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(2675, -47.150119, 4.006287, 202.323272, 0.000000, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(2673, -53.143981, 4.302063, 202.363265, 0.000000, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
	
	//Admin Jail
	tmpobjid = CreateDynamicObject(2395, -8.718139, 2338.405761, 22.930620, 0.000000, 0.000000, 270.000000, 999, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 3314, "ce_burbhouse", "black_128", 0x00000000);
	tmpobjid = CreateDynamicObject(2395, -8.728139, 2338.405761, 23.030622, 0.000000, 0.000000, 270.000000, 999, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 3314, "ce_burbhouse", "black_128", 0x00000000);
	SetDynamicObjectMaterialText(tmpobjid, 0, "{FFFFFF}Read the rules first, FOO!", 120, "Ariel", 40, 1, 0x00000000, 0x00000000, 1);

	//Basket (ELS)
	tmpobjid = CreateDynamicObject(19447, 2311.059814, -1543.008422, 25.987787, 0.000000, 0.000000, 90.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 13659, "8bars", "Upt_Fence_Mesh", 0x00000000);
	tmpobjid = CreateDynamicObject(19447, 2320.694824, -1543.008422, 25.987787, 0.000000, 0.000000, 90.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 13659, "8bars", "Upt_Fence_Mesh", 0x00000000);
	tmpobjid = CreateDynamicObject(19447, 2322.376464, -1543.008422, 25.987787, 0.000000, 0.000000, 90.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 13659, "8bars", "Upt_Fence_Mesh", 0x00000000);
	tmpobjid = CreateDynamicObject(19447, 2327.121093, -1538.138061, 25.987787, 0.000000, 0.000000, 180.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 13659, "8bars", "Upt_Fence_Mesh", 0x00000000);
	tmpobjid = CreateDynamicObject(19447, 2327.121093, -1517.774536, 25.987787, 0.000000, 0.000000, 180.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 13659, "8bars", "Upt_Fence_Mesh", 0x00000000);
	tmpobjid = CreateDynamicObject(19447, 2322.399169, -1512.862060, 25.987787, 0.000000, 0.000000, 270.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 13659, "8bars", "Upt_Fence_Mesh", 0x00000000);
	tmpobjid = CreateDynamicObject(19447, 2312.778320, -1512.862060, 25.987787, 0.000000, 0.000000, 270.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 13659, "8bars", "Upt_Fence_Mesh", 0x00000000);
	tmpobjid = CreateDynamicObject(19447, 2311.166748, -1512.862060, 25.987787, 0.000000, 0.000000, 270.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 13659, "8bars", "Upt_Fence_Mesh", 0x00000000);
	tmpobjid = CreateDynamicObject(19447, 2295.952148, -1512.862182, 27.567823, 0.000000, 0.000000, -89.999969, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 13659, "8bars", "Upt_Fence_Mesh", 0x00000000);
	tmpobjid = CreateDynamicObject(19447, 2286.317138, -1512.862182, 27.567823, 0.000000, 0.000000, -89.999969, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 13659, "8bars", "Upt_Fence_Mesh", 0x00000000);
	tmpobjid = CreateDynamicObject(19447, 2284.635498, -1512.862182, 27.567823, 0.000000, 0.000000, -89.999969, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 13659, "8bars", "Upt_Fence_Mesh", 0x00000000);
	tmpobjid = CreateDynamicObject(19447, 2279.890869, -1517.732543, 27.567823, -0.000000, 0.000000, -0.000015, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 13659, "8bars", "Upt_Fence_Mesh", 0x00000000);
	tmpobjid = CreateDynamicObject(19447, 2279.890869, -1538.096069, 27.567823, -0.000000, 0.000000, -0.000015, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 13659, "8bars", "Upt_Fence_Mesh", 0x00000000);
	tmpobjid = CreateDynamicObject(19447, 2284.612792, -1543.008544, 27.567823, 0.000000, 0.000000, 89.999938, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 13659, "8bars", "Upt_Fence_Mesh", 0x00000000);
	tmpobjid = CreateDynamicObject(19447, 2294.233642, -1543.008544, 27.567823, 0.000000, 0.000000, 89.999938, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 13659, "8bars", "Upt_Fence_Mesh", 0x00000000);
	tmpobjid = CreateDynamicObject(19447, 2295.845214, -1543.008544, 27.567823, 0.000000, 0.000000, 89.999938, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 13659, "8bars", "Upt_Fence_Mesh", 0x00000000);

	//PaynSpray
	tmpobjid = CreateDynamicObject(5532, 2324.035400, -1990.516723, 20.629161, 0.000000, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(5422, 2340.383544, -1991.440063, 16.334711, 0.000000, -80.499977, 0.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(5422, 2071.600585, -1831.421508, 14.506878, 0.000000, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(5532, 1821.698608, -1397.265747, 20.449699, 0.000000, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(5422, 1837.795043, -1398.199218, 16.259263, 0.000000, -82.099998, 0.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(5532, 1618.660278, -1896.942138, 20.602912, 0.000000, 0.000000, 90.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(5422, 1619.607910, -1880.587768, 16.530103, 0.000000, -87.099990, 90.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(1267, 1614.511840, -1891.618896, 20.044927, 0.000000, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(1267, 2329.088623, -1986.141601, 20.024196, 0.000000, 0.000000, 270.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(1267, 1826.941650, -1392.895263, 19.840042, 0.000000, 0.000000, 270.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(4988, 1827.652832, -1394.716186, 25.863389, 0.000000, 0.000000, -161.800003, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(5779, 1041.345947, -1026.011596, 32.651184, 0.000000, 0.000000, 90.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(5856, 1025.018066, -1029.541503, 33.079601, 0.000000, 0.000000, 90.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(6400, 488.233428, -1734.756103, 12.301477, 0.000000, 0.000000, 80.199859, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(5043, 1843.289550, -1856.313964, 13.764872, 0.000000, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 

	//pier
	tmpobjid = CreateDynamicObject(3250, 2891.978027, -2136.329833, 2.152460, 0.000000, 0.000000, 90.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(12990, 2920.069335, -2144.075927, 0.414515, 0.000000, -1.600000, 81.900001, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(17068, 140.618560, -1803.330200, 0.327998, 0.000000, 0.000000, 270.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(17068, 140.618560, -1822.819580, 0.327998, 0.000000, 0.000000, 270.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(1344, 2893.492187, -2131.497314, 3.047862, 0.000000, 0.000000, 180.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(2673, 2893.107421, -2130.260009, 2.437118, 0.000000, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(1338, 2898.340332, -2138.911621, 3.000403, 0.000000, 0.499999, 0.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(2968, 2898.157958, -2138.212890, 2.529225, 0.000000, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 

	//Beach
	CreateDynamicObject(16003, 309.64999390, -1836.00000000, 4.11999989, 0.00000000, 0.00000000, 180.00000000, 0, 0, -1, 400.0); //
	CreateDynamicObject(16003, 309.62554932, -1846.19995117, 3.80119991, 0.00000000, 0.00000000, 179.99450684, 0, 0, -1, 400.0); //
	CreateDynamicObject(2405, 310.60000610, -1847.69995117, 3.62999988, 0.00000000, 0.00000000, 0.00000000, 0, 0, -1, 400.0); //
	CreateDynamicObject(2404, 308.39999390, -1837.46997070, 3.90000010, 0.00000000, 0.00000000, 0.00000000, 0, 0, -1, 400.0); //
	CreateDynamicObject(2404, 309.16000366, -1837.46997070, 3.90000010, 0.00000000, 0.00000000, 0.00000000, 0, 0, -1, 400.0); //
	CreateDynamicObject(1461, 327.20001221, -1879.19995117, 2.20000005, 0.00000000, 0.00000000, 0.00000000, 0, 0, -1, 400.0); //
	CreateDynamicObject(1461, 255.39999390, -1873.59997559, 1.89999998, 0.00000000, 0.00000000, 0.00000000, 0, 0, -1, 400.0); //
	CreateDynamicObject(1461, 183.69999695, -1872.69995117, 2.50000000, 0.00000000, 0.00000000, 0.00000000, 0, 0, -1, 400.0); //
	CreateDynamicObject(1598, 203.19921875, -1848.50000000, 2.70000005, 0.00000000, 0.00000000, 0.00000000, 0, 0, -1, 400.0); //
	CreateDynamicObject(1255, 333.79998779, -1847.90002441, 2.97008395, 0.00000000, 0.00000000, 299.99816895, 0, 0, -1, 400.0); //
	CreateDynamicObject(2406, 310.69921875, -1844.72949219, 3.70000005, 0.00000000, 0.00000000, 179.99450684, 0, 0, -1, 400.0); //
	CreateDynamicObject(2405, 309.09960938, -1844.72949219, 3.70000005, 0.00000000, 0.00000000, 179.99450684, 0, 0, -1, 400.0); //
	CreateDynamicObject(1255, 335.89999390, -1847.90002441, 2.97008395, 0.00000000, 0.00000000, 239.99633789, 0, 0, -1, 400.0); //
	CreateDynamicObject(1642, 265.79980469, -1853.39941406, 2.16700006, 1.00000000, 0.00000000, 0.00000000, 0, 0, -1, 400.0); //
	CreateDynamicObject(1641, 267.50000000, -1853.39941406, 2.17900014, 1.00000000, 0.00000000, 0.00000000, 0, 0, -1, 400.0); //
	CreateDynamicObject(1280, 303.19921875, -1823.19921875, 3.41000009, 358.00000000, 0.00000000, 179.99450684, 0, 0, -1, 400.0); //
	CreateDynamicObject(1280, 303.09960938, -1841.39941406, 2.90555549, 358.40002441, 0.00000000, 179.99450684, 0, 0, -1, 400.0); //
	CreateDynamicObject(1280, 303.19921875, -1837.39941406, 3.02999997, 358.00000000, 0.00000000, 179.99450684, 0, 0, -1, 400.0); //
	CreateDynamicObject(1280, 308.79980469, -1856.19921875, 2.53999996, 2.00000000, 0.00000000, 0.00000000, 0, 0, -1, 400.0); //
	CreateDynamicObject(1281, 233.59960938, -1842.29980469, 3.25000000, 0.00000000, 0.00000000, 0.00000000, 0, 0, -1, 400.0); //
	CreateDynamicObject(2406, 308.89999390, -1834.52050781, 4.00000000, 0.00000000, 0.00000000, 179.99450684, 0, 0, -1, 400.0); //
	CreateDynamicObject(1598, 309.79998779, -1834.59997559, 3.05999994, 0.00000000, 0.00000000, 0.00000000, 0, 0, -1, 400.0); //
	CreateDynamicObject(1598, 311.60000610, -1847.30004883, 2.70000005, 0.00000000, 0.00000000, 0.00000000, 0, 0, -1, 400.0); //
	CreateDynamicObject(1328, 303.19921875, -1839.39941406, 3.09999990, 0.00000000, 0.00000000, 0.00000000, 0, 0, -1, 400.0); //
	CreateDynamicObject(1280, 308.59960938, -1828.59960938, 3.31555629, 2.00000000, 0.00000000, 0.00000000, 0, 0, -1, 400.0); //
	CreateDynamicObject(642, 334.89999390, -1847.09997559, 3.75000000, 0.00000000, 0.00000000, 0.00000000, 0, 0, -1, 400.0); //
	CreateDynamicObject(1255, 278.70001221, -1837.69995117, 3.20000005, 0.00000000, 0.00000000, 270.00000000, 0, 0, -1, 400.0); //
	CreateDynamicObject(1255, 276.10000610, -1837.59997559, 3.20000005, 0.00000000, 0.00000000, 270.00000000, 0, 0, -1, 400.0); //
	CreateDynamicObject(1255, 277.39999390, -1837.59997559, 3.20000005, 0.00000000, 0.00000000, 270.00000000, 0, 0, -1, 400.0); //
	CreateDynamicObject(642, 344.29998779, -1847.80004883, 3.77999997, 0.00000000, 0.00000000, 0.00000000, 0, 0, -1, 400.0); //
	CreateDynamicObject(1255, 345.39999390, -1848.90002441, 3.03700829, 0.00000000, 0.00000000, 239.99633789, 0, 0, -1, 400.0); //
	CreateDynamicObject(1255, 342.70001221, -1848.40002441, 3.03700829, 0.00000000, 0.00000000, 299.99816895, 0, 0, -1, 400.0); //
	CreateDynamicObject(1646, 350.00000000, -1862.80004883, 2.65000010, 0.00000000, 0.00000000, 0.00000000, 0, 0, -1, 400.0); //
	CreateDynamicObject(1646, 347.79998779, -1862.80004883, 2.65000010, 0.00000000, 0.00000000, 0.00000000, 0, 0, -1, 400.0); //
	CreateDynamicObject(1647, 348.89999390, -1862.80004883, 2.50000000, 0.00000000, 0.00000000, 0.00000000, 0, 0, -1, 400.0); //
	CreateDynamicObject(1281, 180.80000305, -1816.30004883, 4.11999989, 0.00000000, 0.00000000, 0.00000000, 0, 0, -1, 400.0); //
	CreateDynamicObject(1645, 218.89999390, -1863.59997559, 2.20099998, 0.00000000, 0.00000000, 0.00000000, 0, 0, -1, 400.0); //
	CreateDynamicObject(1646, 220.19999695, -1863.59997559, 2.20099998, 0.00000000, 0.00000000, 0.00000000, 0, 0, -1, 400.0); //
	CreateDynamicObject(1645, 173.10000610, -1856.09997559, 2.60000014, 0.00000000, 0.00000000, 0.00000000, 0, 0, -1, 400.0); //
	CreateDynamicObject(1646, 175.39999390, -1856.09997559, 2.60000014, 0.00000000, 0.00000000, 0.00000000, 0, 0, -1, 400.0); //
	CreateDynamicObject(1647, 174.19999695, -1856.00000000, 2.50000000, 0.00000000, 0.00000000, 0.00000000, 0, 0, -1, 400.0); //
	CreateDynamicObject(1255, 194.00000000, -1874.19946289, 2.08100009, 0.00000000, 5.00000000, 300.00000000, 0, 0, -1, 400.0); //
	CreateDynamicObject(1255, 196.10000610, -1874.30004883, 2.00100017, 0.00000000, 5.00000000, 240.00000000, 0, 0, -1, 400.0); //
	CreateDynamicObject(2817, 224.39999390, -1856.90002441, 2.14099979, 0.00000000, 358.59997559, 90.00000000, 0, 0, -1, 400.0); //
	CreateDynamicObject(2818, 225.60000610, -1856.90002441, 2.09999990, 0.00000000, 358.50000000, 90.00000000, 0, 0, -1, 400.0); //
	CreateDynamicObject(1598, 255.10000610, -1868.59997559, 1.79999995, 0.00000000, 0.00000000, 0.00000000, 0, 0, -1, 400.0); //
	CreateDynamicObject(1598, 338.89999390, -1887.90002441, 1.20000005, 0.00000000, 0.00000000, 0.00000000, 0, 0, -1, 400.0); //
	CreateDynamicObject(1598, 169.19999695, -1880.19995117, 1.39999998, 0.00000000, 0.00000000, 0.00000000, 0, 0, -1, 400.0); //
	CreateDynamicObject(1645, 313.79980469, -1871.79980469, 1.93999994, 2.00000000, 0.00000000, 0.00000000, 0, 0, -1, 400.0); //
	CreateDynamicObject(1646, 314.79980469, -1871.79980469, 1.93999994, 2.00000000, 0.00000000, 0.00000000, 0, 0, -1, 400.0); //
	CreateDynamicObject(1645, 315.89941406, -1871.79980469, 1.93999994, 2.00000000, 0.00000000, 0.00000000, 0, 0, -1, 400.0); //
	CreateDynamicObject(1646, 291.20001221, -1844.69995117, 2.73000002, 2.99926758, 0.00000000, 340.00000000, 0, 0, -1, 400.0); //
	CreateDynamicObject(1646, 290.10000610, -1844.40002441, 2.73000002, 2.99926758, 0.00000000, 339.99938965, 0, 0, -1, 400.0); //
	CreateDynamicObject(1645, 245.30000305, -1845.69995117, 2.58999991, 1.50000000, 0.00000000, 0.00000000, 0, 0, -1, 400.0); //
	CreateDynamicObject(1646, 246.60000610, -1845.69995117, 2.58999991, 1.50000000, 0.00000000, 0.00000000, 0, 0, -1, 400.0); //
}

InsertDonatorStars() // Do not remove this under any circumstances, people paid for this...
{ 
	new g_DynamicObject[68];
	g_DynamicObject[0] = CreateDynamicObject(19483, 1020.3718, -1133.6745, 22.8472, 180.0000, 90.0000, 180.0000, -1, -1, -1, 250.0, 250.0); // Plane009
	SetDynamicObjectMaterialText(g_DynamicObject[0], 0, "Radeetz", 90, "Arial", 24, 1, 0xFF745217, 0x0, 1);
	g_DynamicObject[1] = CreateDynamicObject(19483, 974.8618, -1133.6745, 22.8472, 180.0000, 90.0000, 180.0000, -1, -1, -1, 250.0, 250.0); // Plane009
	SetDynamicObjectMaterialText(g_DynamicObject[1], 0, "BigSmoke", 90, "Arial", 24, 1, 0xFF745217, 0x0, 1);
	g_DynamicObject[2] = CreateDynamicObject(19483, 979.3926, -1133.5844, 22.8472, 180.0000, 90.0000, 180.0000, -1, -1, -1, 250.0, 250.0); // Plane009
	SetDynamicObjectMaterialText(g_DynamicObject[2], 0, "MarV", 90, "Arial", 24, 1, 0xFF745217, 0x0, 1);
	g_DynamicObject[3] = CreateDynamicObject(19483, 983.9432, -1133.5344, 22.8472, 180.0000, 90.0000, 180.0000, -1, -1, -1, 250.0, 250.0); // Plane009
	SetDynamicObjectMaterialText(g_DynamicObject[3], 0, "Boris", 90, "Arial", 24, 1, 0xFF745217, 0x0, 1);
	g_DynamicObject[4] = CreateDynamicObject(19483, 988.4937, -1133.5844, 22.8472, 180.0000, 90.0000, 180.0000, -1, -1, -1, 250.0, 250.0); // Plane009
	SetDynamicObjectMaterialText(g_DynamicObject[4], 0, "Nhces", 90, "Arial", 24, 1, 0xFF745217, 0x0, 1);
	g_DynamicObject[5] = CreateDynamicObject(19483, 993.0543, -1133.5844, 22.8472, 180.0000, 90.0000, 180.0000, -1, -1, -1, 250.0, 250.0); // Plane009
	SetDynamicObjectMaterialText(g_DynamicObject[5], 0, "Kodok", 90, "Arial", 24, 1, 0xFF745217, 0x0, 1);
	g_DynamicObject[6] = CreateDynamicObject(19483, 997.6054, -1133.5844, 22.8472, 180.0000, 90.0000, 180.0000, -1, -1, -1, 250.0, 250.0); // Plane009
	SetDynamicObjectMaterialText(g_DynamicObject[6], 0, "None", 90, "Arial", 24, 1, 0xFF745217, 0x0, 1);
	g_DynamicObject[7] = CreateDynamicObject(19483, 1002.1675, -1133.5844, 22.8472, 180.0000, 90.0000, 180.0000, -1, -1, -1, 250.0, 250.0); // Plane009
	SetDynamicObjectMaterialText(g_DynamicObject[7], 0, "None", 90, "Arial", 24, 1, 0xFF745217, 0x0, 1);
	g_DynamicObject[8] = CreateDynamicObject(19483, 1006.6901, -1133.5844, 22.8472, 180.0000, 90.0000, 180.0000, -1, -1, -1, 250.0, 250.0); // Plane009
	SetDynamicObjectMaterialText(g_DynamicObject[8], 0, "None", 90, "Arial", 24, 1, 0xFF745217, 0x0, 1);
	g_DynamicObject[9] = CreateDynamicObject(19483, 1011.2512, -1133.5844, 22.8472, 180.0000, 90.0000, 180.0000, -1, -1, -1, 250.0, 250.0); // Plane009
	SetDynamicObjectMaterialText(g_DynamicObject[9], 0, "None", 90, "Arial", 24, 1, 0xFF745217, 0x0, 1);
	g_DynamicObject[10] = CreateDynamicObject(19483, 1015.7910, -1133.6545, 22.8472, 180.0000, 90.0000, 180.0000, -1, -1, -1, 250.0, 250.0); // Plane009
	SetDynamicObjectMaterialText(g_DynamicObject[10], 0, "None", 90, "Arial", 24, 1, 0xFF745217, 0x0, 1);
	g_DynamicObject[11] = CreateDynamicObject(19483, 997.8256, -1133.5844, 22.8472, 180.0000, 90.0000, 180.0000, -1, -1, -1, 250.0, 250.0); // Plane009
	SetDynamicObjectMaterialText(g_DynamicObject[11], 0, "None", 130, "Arial", 24, 1, 0xFF840410, 0x0, 1);
	g_DynamicObject[12] = CreateDynamicObject(19483, 984.2057, -1133.5444, 22.8472, 180.0000, 90.0000, 180.0000, -1, -1, -1, 250.0, 250.0); // Plane009
	SetDynamicObjectMaterialText(g_DynamicObject[12], 0, "None", 130, "Arial", 20, 1, 0xFF840410, 0x0, 1);
	g_DynamicObject[13] = CreateDynamicObject(19483, 1011.4364, -1133.5944, 22.8372, 180.0000, 90.0000, 180.0000, -1, -1, -1, 250.0, 250.0); // Plane009
	SetDynamicObjectMaterialText(g_DynamicObject[13], 0, "None", 130, "Arial", 20, 1, 0xFF840410, 0x0, 1);
	g_DynamicObject[14] = CreateDynamicObject(19483, 1025.4821, -1133.6745, 22.8472, 180.0000, 90.0000, 180.0000, -1, -1, -1, 250.0, 250.0); // Plane009
	SetDynamicObjectMaterialText(g_DynamicObject[14], 0, "None", 90, "Arial", 20, 1, 0xFF745217, 0x0, 1);
	g_DynamicObject[15] = CreateDynamicObject(19483, 1029.9742, -1133.6745, 22.8572, 180.0000, 90.0000, 180.0000, -1, -1, -1, 250.0, 250.0); // Plane009
	SetDynamicObjectMaterialText(g_DynamicObject[15], 0, "None", 90, "Arial", 20, 1, 0xFF745217, 0x0, 1);
	g_DynamicObject[16] = CreateDynamicObject(19483, 1034.4479, -1133.6745, 22.8572, 180.0000, 90.0000, 180.0000, -1, -1, -1, 250.0, 250.0); // Plane009
	SetDynamicObjectMaterialText(g_DynamicObject[16], 0, "None", 90, "Arial", 20, 1, 0xFF745217, 0x0, 1);
	g_DynamicObject[17] = CreateDynamicObject(19483, 1038.9393, -1133.6745, 22.8371, 180.0000, 90.0000, 180.0000, -1, -1, -1, 250.0, 250.0); // Plane009
	SetDynamicObjectMaterialText(g_DynamicObject[17], 0, "None", 90, "Arial", 20, 1, 0xFF745217, 0x0, 1);
	g_DynamicObject[18] = CreateDynamicObject(19483, 1043.4500, -1133.6745, 22.8371, 180.0000, 90.0000, 180.0000, -1, -1, -1, 250.0, 250.0); // Plane009
	SetDynamicObjectMaterialText(g_DynamicObject[18], 0, "None", 90, "Arial", 20, 1, 0xFF745217, 0x0, 1);
	g_DynamicObject[19] = CreateDynamicObject(19483, 1047.9607, -1133.6745, 22.8371, 180.0000, 90.0000, 180.0000, -1, -1, -1, 250.0, 250.0); // Plane009
	SetDynamicObjectMaterialText(g_DynamicObject[19], 0, "None", 90, "Arial", 20, 1, 0xFF745217, 0x0, 1);
	g_DynamicObject[20] = CreateDynamicObject(19483, 1052.4714, -1133.6745, 22.8371, 180.0000, 90.0000, 180.0000, -1, -1, -1, 250.0, 250.0); // Plane009
	SetDynamicObjectMaterialText(g_DynamicObject[20], 0, "None", 90, "Arial", 20, 1, 0xFF745217, 0x0, 1);
	g_DynamicObject[21] = CreateDynamicObject(19483, 1052.6014, -1133.6844, 22.8472, 180.0000, 90.0000, 180.0000, -1, -1, -1, 250.0, 250.0); // Plane009
	SetDynamicObjectMaterialText(g_DynamicObject[21], 0, "None", 130, "Arial", 20, 1, 0xFF840410, 0x0, 1);
	g_DynamicObject[22] = CreateDynamicObject(19483, 1056.9714, -1133.6745, 22.8371, 180.0000, 90.0000, 180.0000, -1, -1, -1, 250.0, 250.0); // Plane009
	SetDynamicObjectMaterialText(g_DynamicObject[22], 0, "None", 90, "Arial", 20, 1, 0xFF745217, 0x0, 1);
	g_DynamicObject[23] = CreateDynamicObject(19483, 1057.0800, -1133.6844, 22.8472, 180.0000, 90.0000, 180.0000, -1, -1, -1, 250.0, 250.0); // Plane009
	SetDynamicObjectMaterialText(g_DynamicObject[23], 0, "None", 130, "Arial", 20, 1, 0xFF840410, 0x0, 1);
	g_DynamicObject[24] = CreateDynamicObject(19483, 1061.4021, -1133.6745, 22.8371, 180.0000, 90.0000, 180.0000, -1, -1, -1, 250.0, 250.0); // Plane009
	SetDynamicObjectMaterialText(g_DynamicObject[24], 0, "None", 90, "Arial", 20, 1, 0xFF745217, 0x0, 1);
	g_DynamicObject[25] = CreateDynamicObject(19483, 1061.5321, -1133.6844, 22.8472, 180.0000, 90.0000, 180.0000, -1, -1, -1, 250.0, 250.0); // Plane009
	SetDynamicObjectMaterialText(g_DynamicObject[25], 0, "None", 130, "Arial", 20, 1, 0xFF840410, 0x0, 1);
	g_DynamicObject[26] = CreateDynamicObject(19483, 1065.9021, -1133.6745, 22.8371, 180.0000, 90.0000, 180.0000, -1, -1, -1, 250.0, 250.0); // Plane009
	SetDynamicObjectMaterialText(g_DynamicObject[26], 0, "None ", 90, "Arial", 20, 1, 0xFF745217, 0x0, 1);
	g_DynamicObject[27] = CreateDynamicObject(19483, 1066.0321, -1133.6844, 22.8472, 180.0000, 90.0000, 180.0000, -1, -1, -1, 250.0, 250.0); // Plane009
	SetDynamicObjectMaterialText(g_DynamicObject[27], 0, "None", 130, "Arial", 20, 1, 0xFF840410, 0x0, 1);
	g_DynamicObject[28] = CreateDynamicObject(19483, 1070.4021, -1133.6745, 22.8371, 180.0000, 90.0000, 180.0000, -1, -1, -1, 250.0, 250.0); // Plane009
	SetDynamicObjectMaterialText(g_DynamicObject[28], 0, "None ", 90, "Arial", 20, 1, 0xFF745217, 0x0, 1);
	g_DynamicObject[29] = CreateDynamicObject(19483, 1070.5321, -1133.6844, 22.8472, 180.0000, 90.0000, 180.0000, -1, -1, -1, 250.0, 250.0); // Plane009
	SetDynamicObjectMaterialText(g_DynamicObject[29], 0, "None", 130, "Arial", 20, 1, 0xFF840410, 0x0, 1);
	g_DynamicObject[30] = CreateDynamicObject(19483, 1094.7280, -1133.6745, 22.8371, 180.0000, 90.0000, 180.0000, -1, -1, -1, 250.0, 250.0); // Plane009
	SetDynamicObjectMaterialText(g_DynamicObject[30], 0, "None ", 90, "Arial", 20, 1, 0xFF745217, 0x0, 1);
	g_DynamicObject[31] = CreateDynamicObject(19483, 1094.8580, -1133.6844, 22.8472, 180.0000, 90.0000, 180.0000, -1, -1, -1, 250.0, 250.0); // Plane009
	SetDynamicObjectMaterialText(g_DynamicObject[31], 0, "None", 130, "Arial", 20, 1, 0xFF840410, 0x0, 1);
	g_DynamicObject[32] = CreateDynamicObject(19483, 1099.0387, -1133.6745, 22.8371, 180.0000, 90.0000, 180.0000, -1, -1, -1, 250.0, 250.0); // Plane009
	SetDynamicObjectMaterialText(g_DynamicObject[32], 0, "None ", 90, "Arial", 20, 1, 0xFF745217, 0x0, 1);
	g_DynamicObject[33] = CreateDynamicObject(19483, 1099.1687, -1133.6844, 22.8472, 180.0000, 90.0000, 180.0000, -1, -1, -1, 250.0, 250.0); // Plane009
	SetDynamicObjectMaterialText(g_DynamicObject[33], 0, "None", 130, "Arial", 20, 1, 0xFF840410, 0x0, 1);
	g_DynamicObject[34] = CreateDynamicObject(19483, 1103.3494, -1133.6745, 22.8371, 180.0000, 90.0000, 180.0000, -1, -1, -1, 250.0, 250.0); // Plane009
	SetDynamicObjectMaterialText(g_DynamicObject[34], 0, "None ", 90, "Arial", 20, 1, 0xFF745217, 0x0, 1);
	g_DynamicObject[35] = CreateDynamicObject(19483, 1103.4794, -1133.6844, 22.8472, 180.0000, 90.0000, 180.0000, -1, -1, -1, 250.0, 250.0); // Plane009
	SetDynamicObjectMaterialText(g_DynamicObject[35], 0, "None", 130, "Arial", 20, 1, 0xFF840410, 0x0, 1);
	g_DynamicObject[36] = CreateDynamicObject(19483, 1107.6511, -1133.6745, 22.8371, 180.0000, 90.0000, 180.0000, -1, -1, -1, 250.0, 250.0); // Plane009
	SetDynamicObjectMaterialText(g_DynamicObject[36], 0, "None ", 90, "Arial", 20, 1, 0xFF745217, 0x0, 1);
	g_DynamicObject[37] = CreateDynamicObject(19483, 1107.7811, -1133.6844, 22.8472, 180.0000, 90.0000, 180.0000, -1, -1, -1, 250.0, 250.0); // Plane009
	SetDynamicObjectMaterialText(g_DynamicObject[37], 0, "None", 130, "Arial", 20, 1, 0xFF840410, 0x0, 1);
	g_DynamicObject[38] = CreateDynamicObject(19483, 1111.9228, -1133.6745, 22.8371, 180.0000, 90.0000, 180.0000, -1, -1, -1, 250.0, 250.0); // Plane009
	SetDynamicObjectMaterialText(g_DynamicObject[38], 0, "None ", 90, "Arial", 20, 1, 0xFF745217, 0x0, 1);
	g_DynamicObject[39] = CreateDynamicObject(19483, 1112.0528, -1133.6844, 22.8472, 180.0000, 90.0000, 180.0000, -1, -1, -1, 250.0, 250.0); // Plane009
	SetDynamicObjectMaterialText(g_DynamicObject[39], 0, "None", 130, "Arial", 20, 1, 0xFF840410, 0x0, 1);
	g_DynamicObject[40] = CreateDynamicObject(19483, 1116.1945, -1133.6745, 22.8371, 180.0000, 90.0000, 180.0000, -1, -1, -1, 250.0, 250.0); // Plane009
	SetDynamicObjectMaterialText(g_DynamicObject[40], 0, "None ", 90, "Arial", 20, 1, 0xFF745217, 0x0, 1);
	g_DynamicObject[41] = CreateDynamicObject(19483, 1116.3245, -1133.6844, 22.8472, 180.0000, 90.0000, 180.0000, -1, -1, -1, 250.0, 250.0); // Plane009
	SetDynamicObjectMaterialText(g_DynamicObject[41], 0, "None", 130, "Arial", 20, 1, 0xFF840410, 0x0, 1);
	g_DynamicObject[42] = CreateDynamicObject(19483, 1120.4662, -1133.6745, 22.8371, 180.0000, 90.0000, 180.0000, -1, -1, -1, 250.0, 250.0); // Plane009
	SetDynamicObjectMaterialText(g_DynamicObject[42], 0, "None ", 90, "Arial", 20, 1, 0xFF745217, 0x0, 1);
	g_DynamicObject[43] = CreateDynamicObject(19483, 1120.5962, -1133.6844, 22.8472, 180.0000, 90.0000, 180.0000, -1, -1, -1, 250.0, 250.0); // Plane009
	SetDynamicObjectMaterialText(g_DynamicObject[43], 0, "None", 130, "Arial", 20, 1, 0xFF840410, 0x0, 1);
	g_DynamicObject[44] = CreateDynamicObject(19483, 1124.7679, -1133.6745, 22.8371, 180.0000, 90.0000, 180.0000, -1, -1, -1, 250.0, 250.0); // Plane009
	SetDynamicObjectMaterialText(g_DynamicObject[44], 0, "None ", 90, "Arial", 20, 1, 0xFF745217, 0x0, 1);
	g_DynamicObject[45] = CreateDynamicObject(19483, 1124.8979, -1133.6844, 22.8472, 180.0000, 90.0000, 180.0000, -1, -1, -1, 250.0, 250.0); // Plane009
	SetDynamicObjectMaterialText(g_DynamicObject[45], 0, "None", 130, "Arial", 20, 1, 0xFF840410, 0x0, 1);
	g_DynamicObject[46] = CreateDynamicObject(19483, 1129.0696, -1133.6745, 22.8371, 180.0000, 90.0000, 180.0000, -1, -1, -1, 250.0, 250.0); // Plane009
	SetDynamicObjectMaterialText(g_DynamicObject[46], 0, "None", 90, "Arial", 20, 1, 0xFF745217, 0x0, 1);
	g_DynamicObject[47] = CreateDynamicObject(19483, 1133.3713, -1133.6745, 22.8371, 180.0000, 90.0000, 180.0000, -1, -1, -1, 250.0, 250.0); // Plane009
	SetDynamicObjectMaterialText(g_DynamicObject[47], 0, "None", 90, "Arial", 20, 1, 0xFF745217, 0x0, 1);
	g_DynamicObject[48] = CreateDynamicObject(19483, 1137.673, -1133.6745, 22.8371, 180.0000, 90.0000, 180.0000, -1, -1, -1, 250.0, 250.0); // Plane009
	SetDynamicObjectMaterialText(g_DynamicObject[48], 0, "None", 90, "Arial", 20, 1, 0xFF745217, 0x0, 1);
	g_DynamicObject[49] = CreateDynamicObject(19483, 1141.9747, -1133.6745, 22.8371, 180.0000, 90.0000, 180.0000, -1, -1, -1, 250.0, 250.0); // Plane009
	SetDynamicObjectMaterialText(g_DynamicObject[49], 0, "None", 90, "Arial", 20, 1, 0xFF745217, 0x0, 1);
	g_DynamicObject[50] = CreateDynamicObject(19483, 1146.2764, -1133.6745, 22.8371, 180.0000, 90.0000, 180.0000, -1, -1, -1, 250.0, 250.0); // Plane009
	SetDynamicObjectMaterialText(g_DynamicObject[50], 0, "None", 90, "Arial", 20, 1, 0xFF745217, 0x0, 1);
	g_DynamicObject[51] = CreateDynamicObject(19483, 1150.5781, -1133.6745, 22.8371, 180.0000, 90.0000, 180.0000, -1, -1, -1, 250.0, 250.0); // Plane009
	SetDynamicObjectMaterialText(g_DynamicObject[51], 0, "None", 90, "Arial", 20, 1, 0xFF745217, 0x0, 1);
	g_DynamicObject[52] = CreateDynamicObject(19483, 1175.3240, -1133.7745, 22.8871, 180.0000, 90.0000, 0.0000, -1, -1, -1, 250.0, 250.0); // Plane009
	SetDynamicObjectMaterialText(g_DynamicObject[52], 0, "None ", 90, "Arial", 20, 1, 0xFF745217, 0x0, 1);
	g_DynamicObject[53] = CreateDynamicObject(19483, 1175.2000, -1133.7844, 22.8972, 180.0000, 90.0000, 0.0000, -1, -1, -1, 250.0, 250.0); // Plane009
	SetDynamicObjectMaterialText(g_DynamicObject[53], 0, "None", 130, "Arial", 20, 1, 0xFF840410, 0x0, 1);
	g_DynamicObject[54] = CreateDynamicObject(19483, 1180.4257, -1133.7745, 22.8871, 180.0000, 90.0000, 0.0000, -1, -1, -1, 250.0, 250.0); // Plane009
	SetDynamicObjectMaterialText(g_DynamicObject[54], 0, "None ", 90, "Arial", 20, 1, 0xFF745217, 0x0, 1);
	g_DynamicObject[55] = CreateDynamicObject(19483, 1185.5274, -1133.7745, 22.8871, 180.0000, 90.0000, 0.0000, -1, -1, -1, 250.0, 250.0); // Plane009
	SetDynamicObjectMaterialText(g_DynamicObject[55], 0, "None ", 90, "Arial", 20, 1, 0xFF745217, 0x0, 1);
	g_DynamicObject[56] = CreateDynamicObject(19483, 1185.4034, -1133.7844, 22.8972, 180.0000, 90.0000, 0.0000, -1, -1, -1, 250.0, 250.0); // Plane009
	SetDynamicObjectMaterialText(g_DynamicObject[56], 0, "None", 130, "Arial", 20, 1, 0xFF840410, 0x0, 1);
	g_DynamicObject[57] = CreateDynamicObject(19483, 1190.8691, -1133.7745, 22.9871, 180.0000, 90.0000, 0.0000, -1, -1, -1, 250.0, 250.0); // Plane009
	SetDynamicObjectMaterialText(g_DynamicObject[57], 0, "None ", 90, "Arial", 20, 1, 0xFF745217, 0x0, 1);
	g_DynamicObject[58] = CreateDynamicObject(19483, 1196.0000, -1133.6745, 22.9871, 180.0000, 90.0000, 0.0000, -1, -1, -1, 250.0, 250.0); // Plane009
	SetDynamicObjectMaterialText(g_DynamicObject[58], 0, "None ", 90, "Arial", 20, 1, 0xFF745217, 0x0, 1);
	g_DynamicObject[59] = CreateDynamicObject(19483, 1201.4325, -1133.6745, 22.9871, 180.0000, 90.0000, 0.0000, -1, -1, -1, 250.0, 250.0); // Plane009
	SetDynamicObjectMaterialText(g_DynamicObject[59], 0, "None ", 90, "Arial", 20, 1, 0xFF745217, 0x0, 1);
	g_DynamicObject[60] = CreateDynamicObject(19483, 1201.3100, -1133.6844, 22.9972, 180.0000, 90.0000, 0.0000, -1, -1, -1, 250.0, 250.0); // Plane009
	SetDynamicObjectMaterialText(g_DynamicObject[60], 0, "None", 130, "Arial", 20, 1, 0xFF840410, 0x0, 1);
	g_DynamicObject[61] = CreateDynamicObject(19483, 1206.8634, -1133.6745, 22.9871, 180.0000, 90.0000, 0.0000, -1, -1, -1, 250.0, 250.0); // Plane009
	SetDynamicObjectMaterialText(g_DynamicObject[61], 0, "None ", 90, "Arial", 20, 1, 0xFF745217, 0x0, 1);
	g_DynamicObject[62] = CreateDynamicObject(19483, 1212.2943, -1133.6745, 22.9871, 180.0000, 90.0000, 0.0000, -1, -1, -1, 250.0, 250.0); // Plane009
	SetDynamicObjectMaterialText(g_DynamicObject[62], 0, "None ", 90, "Arial", 20, 1, 0xFF745217, 0x0, 1);
	g_DynamicObject[63] = CreateDynamicObject(19483, 1217.6252, -1133.6745, 22.9871, 180.0000, 90.0000, 0.0000, -1, -1, -1, 250.0, 250.0); // Plane009
	SetDynamicObjectMaterialText(g_DynamicObject[63], 0, "None ", 90, "Arial", 20, 1, 0xFF745217, 0x0, 1);
	g_DynamicObject[64] = CreateDynamicObject(19483, 1223.0561, -1133.4745, 22.9871, 180.0000, 90.0000, 0.0000, -1, -1, -1, 250.0, 250.0); // Plane009
	SetDynamicObjectMaterialText(g_DynamicObject[64], 0, "None ", 90, "Arial", 20, 1, 0xFF745217, 0x0, 1);
	g_DynamicObject[65] = CreateDynamicObject(19483, 1228.4570, -1133.4445, 22.9871, 180.0000, 90.0000, 0.0000, -1, -1, -1, 250.0, 250.0); // Plane009
	SetDynamicObjectMaterialText(g_DynamicObject[65], 0, "None ", 90, "Arial", 20, 1, 0xFF745217, 0x0, 1);
	g_DynamicObject[66] = CreateDynamicObject(19483, 1233.8879, -1133.4445, 22.8871, 180.0000, 90.0000, 0.0000, -1, -1, -1, 250.0, 250.0); // Plane009
	SetDynamicObjectMaterialText(g_DynamicObject[66], 0, "None ", 90, "Arial", 20, 1, 0xFF745217, 0x0, 1);
	g_DynamicObject[67] = CreateDynamicObject(19483, 1233.6879, -1133.4445, 22.8972, 180.0000, 90.0000, 0.0000, -1, -1, -1, 250.0, 250.0); // Plane009
	SetDynamicObjectMaterialText(g_DynamicObject[67], 0, "None", 130, "Arial", 20, 1, 0xFF840410, 0x0, 1);
}

InsertAcidGunLabs(){
	tmpobjid = CreateDynamicObject(19379, 1439.623901, 1576.735717, 107.291091, 0.000000, 90.000000, 0.000000, -1, 11, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 19853, "mihouse1", "tileblue1", 0x00000000);
	tmpobjid = CreateDynamicObject(19379, 1439.623901, 1567.115356, 107.291091, 0.000000, 270.000000, 180.000000, -1, 11, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 19853, "mihouse1", "tileblue1", 0x00000000);
	tmpobjid = CreateDynamicObject(19379, 1434.442993, 1567.115356, 105.640968, 0.000000, 360.000000, 0.000000, -1, 11, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 4835, "airoads_las", "ws_carparkwall1", 0x00000000);
	tmpobjid = CreateDynamicObject(19379, 1434.442993, 1576.736206, 105.640968, 0.000000, 360.000000, 0.000000, -1, 11, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 4835, "airoads_las", "ws_carparkwall1", 0x00000000);
	tmpobjid = CreateDynamicObject(19379, 1444.177978, 1567.115356, 105.640968, 0.000000, 360.000000, 0.000000, -1, 11, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 4835, "airoads_las", "ws_carparkwall1", 0x00000000);
	tmpobjid = CreateDynamicObject(19379, 1444.177978, 1576.736206, 105.640968, 0.000000, 360.000000, 0.000000, -1, 11, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 4835, "airoads_las", "ws_carparkwall1", 0x00000000);
	tmpobjid = CreateDynamicObject(19379, 1439.307373, 1581.436645, 105.640968, 0.000000, 360.000000, 90.000000, -1, 11, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 4835, "airoads_las", "ws_carparkwall1", 0x00000000);
	tmpobjid = CreateDynamicObject(19379, 1439.307373, 1562.527832, 105.640968, 0.000000, 360.000000, 90.000000, -1, 11, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 4835, "airoads_las", "ws_carparkwall1", 0x00000000);
	tmpobjid = CreateDynamicObject(19379, 1439.623901, 1576.735717, 110.921104, 0.000000, 90.000007, 0.000000, -1, 11, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 3615, "beachhut", "sw_flatroof01", 0x00000000);
	tmpobjid = CreateDynamicObject(19379, 1439.623901, 1567.115356, 110.921104, 0.000000, 90.000007, 0.000000, -1, 11, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 3615, "beachhut", "sw_flatroof01", 0x00000000);
	tmpobjid = CreateDynamicObject(3761, 1435.289550, 1576.623413, 108.757034, 0.000000, 0.000000, 0.000000, -1, 11, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 3, 13659, "8bars", "Upt_Fence_Mesh", 0x00000000);
	tmpobjid = CreateDynamicObject(937, 1440.322631, 1577.585327, 107.826980, 0.000000, 0.000000, 90.000000, -1, 11, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 1560, "7_11_door", "cj_sheetmetal2", 0x00000000);
	SetDynamicObjectMaterial(tmpobjid, 1, 1560, "7_11_door", "cj_sheetmetal2", 0x00000000);
	tmpobjid = CreateDynamicObject(937, 1440.322631, 1575.724487, 107.826980, 0.000000, 0.000000, 90.000000, -1, 11, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 1560, "7_11_door", "cj_sheetmetal2", 0x00000000);
	SetDynamicObjectMaterial(tmpobjid, 1, 1560, "7_11_door", "cj_sheetmetal2", 0x00000000);
	tmpobjid = CreateDynamicObject(937, 1440.322631, 1573.853759, 107.826980, 0.000000, 0.000000, 90.000000, -1, 11, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 1560, "7_11_door", "cj_sheetmetal2", 0x00000000);
	SetDynamicObjectMaterial(tmpobjid, 1, 1560, "7_11_door", "cj_sheetmetal2", 0x00000000);
	tmpobjid = CreateDynamicObject(19899, 1443.640747, 1565.170654, 107.367027, 0.000000, 0.000000, 180.000000, -1, 11, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 1560, "7_11_door", "cj_sheetmetal2", 0x00000000);
	tmpobjid = CreateDynamicObject(1650, 1435.814331, 1576.156494, 107.896995, 0.000000, 0.000000, 0.000000, -1, 11, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 16293, "a51_undergrnd", "Was_scrpyd_door_in_hngr", 0x00000000);
	tmpobjid = CreateDynamicObject(1650, 1435.814331, 1575.976318, 107.896995, 0.000000, 0.000000, 0.000000, -1, 11, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 16293, "a51_undergrnd", "Was_scrpyd_door_in_hngr", 0x00000000);
	tmpobjid = CreateDynamicObject(1650, 1435.814331, 1575.505859, 107.896995, 0.000000, 0.000000, 0.000000, -1, 11, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 16293, "a51_undergrnd", "Was_scrpyd_door_in_hngr", 0x00000000);
	tmpobjid = CreateDynamicObject(1650, 1435.814331, 1577.985107, 107.896995, 0.000000, 0.000000, -22.699996, -1, 11, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 16293, "a51_undergrnd", "Was_scrpyd_door_in_hngr", 0x00000000);
	tmpobjid = CreateDynamicObject(1650, 1435.742553, 1578.590576, 107.896995, 0.000000, 0.000000, 6.700006, -1, 11, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 16293, "a51_undergrnd", "Was_scrpyd_door_in_hngr", 0x00000000);
	tmpobjid = CreateDynamicObject(1650, 1435.672241, 1579.176879, 107.667167, 87.599967, 0.000000, 6.700006, -1, 11, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 16293, "a51_undergrnd", "Was_scrpyd_door_in_hngr", 0x00000000);
	tmpobjid = CreateDynamicObject(365, 1434.935424, 1570.623168, 108.486976, 0.000000, 0.000000, 0.000000, -1, 11, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 2543, "cj_ss_3", "CJ_DOOG_FOOD", 0x00000000);
	tmpobjid = CreateDynamicObject(365, 1435.420288, 1570.783325, 108.499633, 0.000000, 80.199974, 0.000000, -1, 11, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 2543, "cj_ss_3", "CJ_DOOG_FOOD", 0x00000000);
	tmpobjid = CreateDynamicObject(365, 1434.857299, 1570.382934, 108.412513, -1.399999, 80.199974, -30.299997, -1, 11, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 2543, "cj_ss_3", "CJ_DOOG_FOOD", 0x00000000);
	tmpobjid = CreateDynamicObject(2002, 1435.123168, 1568.760986, 107.067016, 0.000000, 0.000000, 0.000000, -1, 11, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 1419, "break_fence3", "CJ_FRAME_Glass", 0x00000000);
	tmpobjid = CreateDynamicObject(19830, 1435.086059, 1568.385131, 108.316864, 0.000000, 0.000000, 90.000000, -1, 11, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 1419, "break_fence3", "CJ_FRAME_Glass", 0x00000000);
	SetDynamicObjectMaterial(tmpobjid, 1, 1419, "break_fence3", "CJ_FRAME_Glass", 0x00000000);
	SetDynamicObjectMaterial(tmpobjid, 3, 1419, "break_fence3", "CJ_FRAME_Glass", 0x00000000);
	tmpobjid = CreateDynamicObject(19570, 1435.133422, 1569.489868, 108.317031, 0.000000, 0.000000, 0.000000, -1, 11, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 18646, "matcolours", "grey-40-percent", 0x00000000);
	tmpobjid = CreateDynamicObject(19570, 1435.143432, 1569.870239, 108.317031, 0.000000, 0.000000, 0.000000, -1, 11, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 18646, "matcolours", "grey-40-percent", 0x00000000);
	tmpobjid = CreateDynamicObject(3027, 1435.136718, 1568.401367, 108.637031, 0.000000, 0.000000, 0.000000, -1, 11, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 19267, "mapmarkers", "red-2", 0x00000000);
	tmpobjid = CreateDynamicObject(3027, 1435.136718, 1568.401367, 108.747039, -17.200002, 0.000000, 0.000000, -1, 11, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 19267, "mapmarkers", "red-2", 0x00000000);
	tmpobjid = CreateDynamicObject(3027, 1435.136718, 1568.429687, 108.846054, -44.899997, 0.000000, 0.000000, -1, 11, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 19267, "mapmarkers", "red-2", 0x00000000);
	tmpobjid = CreateDynamicObject(3027, 1435.136718, 1568.509399, 108.927215, -82.499977, 0.000000, 0.000000, -1, 11, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 19267, "mapmarkers", "red-2", 0x00000000);
	tmpobjid = CreateDynamicObject(3027, 1435.136718, 1568.608398, 108.940261, -82.499977, 0.000000, 0.000000, -1, 11, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 19267, "mapmarkers", "red-2", 0x00000000);
	tmpobjid = CreateDynamicObject(3027, 1435.136718, 1568.707519, 108.953308, -106.699974, 0.000000, 0.000000, -1, 11, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 19267, "mapmarkers", "red-2", 0x00000000);
	tmpobjid = CreateDynamicObject(3027, 1435.136718, 1568.802978, 108.924560, -106.699974, 0.000000, 0.000000, -1, 11, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 19267, "mapmarkers", "red-2", 0x00000000);
	tmpobjid = CreateDynamicObject(3027, 1435.136718, 1568.898071, 108.895790, -121.099975, 0.000000, 0.000000, -1, 11, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 19267, "mapmarkers", "red-2", 0x00000000);
	tmpobjid = CreateDynamicObject(3027, 1435.136718, 1568.983520, 108.844139, -121.099975, 0.000000, 0.000000, -1, 11, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 19267, "mapmarkers", "red-2", 0x00000000);
	tmpobjid = CreateDynamicObject(3027, 1435.136718, 1569.211669, 108.364143, -56.199985, 0.000000, 0.000000, -1, 11, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 5168, "lashops6_las2", "yellow2_128", 0x00000000);
	tmpobjid = CreateDynamicObject(3027, 1435.136718, 1569.299682, 108.418968, -25.300012, 0.000000, 0.000000, -1, 11, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 5168, "lashops6_las2", "yellow2_128", 0x00000000);
	tmpobjid = CreateDynamicObject(3027, 1435.136718, 1569.342407, 108.509376, -25.300012, 0.000000, 0.000000, -1, 11, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 5168, "lashops6_las2", "yellow2_128", 0x00000000);
	tmpobjid = CreateDynamicObject(3027, 1435.136718, 1569.385620, 108.602752, -68.200111, 0.000000, 0.000000, -1, 11, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 5168, "lashops6_las2", "yellow2_128", 0x00000000);
	tmpobjid = CreateDynamicObject(3027, 1435.136718, 1569.496948, 108.647338, -87.300132, 0.000000, 0.000000, -1, 11, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 5168, "lashops6_las2", "yellow2_128", 0x00000000);
	tmpobjid = CreateDynamicObject(3027, 1435.136718, 1569.597045, 108.652038, -87.300132, 0.000000, 0.000000, -1, 11, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 5168, "lashops6_las2", "yellow2_128", 0x00000000);
	tmpobjid = CreateDynamicObject(3027, 1435.136718, 1569.697021, 108.656730, -97.600173, 0.000000, 0.000000, -1, 11, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 5168, "lashops6_las2", "yellow2_128", 0x00000000);
	tmpobjid = CreateDynamicObject(3027, 1435.136718, 1569.776123, 108.646141, -97.600173, 0.000000, 0.000000, -1, 11, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 5168, "lashops6_las2", "yellow2_128", 0x00000000);
	tmpobjid = CreateDynamicObject(19993, 1435.164184, 1570.174316, 108.317024, 0.000000, 0.000000, 0.000000, -1, 11, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 1560, "7_11_door", "cj_sheetmetal2", 0x00000000);
	tmpobjid = CreateDynamicObject(3027, 1435.136718, 1569.884887, 108.631607, -97.600173, 0.000000, 0.000000, -1, 11, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 5168, "lashops6_las2", "yellow2_128", 0x00000000);
	tmpobjid = CreateDynamicObject(3027, 1435.136718, 1569.993652, 108.617080, -115.300224, 0.000000, 0.000000, -1, 11, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 5168, "lashops6_las2", "yellow2_128", 0x00000000);
	tmpobjid = CreateDynamicObject(3027, 1435.136718, 1570.083984, 108.574356, -129.900253, 0.000000, 0.000000, -1, 11, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 5168, "lashops6_las2", "yellow2_128", 0x00000000);
	tmpobjid = CreateDynamicObject(3027, 1435.136718, 1570.154296, 108.527770, -151.600265, 0.000000, 0.000000, -1, 11, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 5168, "lashops6_las2", "yellow2_128", 0x00000000);
	tmpobjid = CreateDynamicObject(11744, 1435.061645, 1568.386718, 108.627067, 0.000000, 0.000000, 0.000000, -1, 11, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 19267, "mapmarkers", "red-2", 0x00000000);
	tmpobjid = CreateDynamicObject(2002, 1440.337036, 1574.234375, 107.057014, 0.000000, 0.000007, 0.000000, -1, 11, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 1419, "break_fence3", "CJ_FRAME_Glass", 0x00000000);
	tmpobjid = CreateDynamicObject(19830, 1440.299926, 1573.858520, 108.306861, 0.000007, 0.000000, 89.999977, -1, 11, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 1419, "break_fence3", "CJ_FRAME_Glass", 0x00000000);
	SetDynamicObjectMaterial(tmpobjid, 1, 1419, "break_fence3", "CJ_FRAME_Glass", 0x00000000);
	SetDynamicObjectMaterial(tmpobjid, 3, 1419, "break_fence3", "CJ_FRAME_Glass", 0x00000000);
	tmpobjid = CreateDynamicObject(19570, 1440.347290, 1574.963256, 108.307029, 0.000000, 0.000007, 0.000000, -1, 11, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 18646, "matcolours", "grey-40-percent", 0x00000000);
	tmpobjid = CreateDynamicObject(19570, 1440.357299, 1575.343627, 108.307029, 0.000000, 0.000007, 0.000000, -1, 11, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 18646, "matcolours", "grey-40-percent", 0x00000000);
	tmpobjid = CreateDynamicObject(3027, 1440.350585, 1573.874755, 108.627029, 0.000000, 0.000007, 0.000000, -1, 11, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 19267, "mapmarkers", "red-2", 0x00000000);
	tmpobjid = CreateDynamicObject(3027, 1440.350585, 1573.874755, 108.737037, -17.200000, 0.000007, 0.000002, -1, 11, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 19267, "mapmarkers", "red-2", 0x00000000);
	tmpobjid = CreateDynamicObject(3027, 1440.350585, 1573.903076, 108.836051, -44.899993, 0.000010, 0.000007, -1, 11, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 19267, "mapmarkers", "red-2", 0x00000000);
	tmpobjid = CreateDynamicObject(3027, 1440.350585, 1573.982788, 108.917213, -82.499977, 0.000058, 0.000057, -1, 11, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 19267, "mapmarkers", "red-2", 0x00000000);
	tmpobjid = CreateDynamicObject(3027, 1440.350585, 1574.081787, 108.930259, -82.499977, 0.000058, 0.000057, -1, 11, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 19267, "mapmarkers", "red-2", 0x00000000);
	tmpobjid = CreateDynamicObject(3027, 1440.350585, 1574.180908, 108.943305, -73.300018, 179.999969, 179.999969, -1, 11, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 19267, "mapmarkers", "red-2", 0x00000000);
	tmpobjid = CreateDynamicObject(3027, 1440.350585, 1574.276367, 108.914558, -73.300018, 179.999969, 179.999969, -1, 11, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 19267, "mapmarkers", "red-2", 0x00000000);
	tmpobjid = CreateDynamicObject(3027, 1440.350585, 1574.371459, 108.885787, -58.900024, 179.999969, 179.999984, -1, 11, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 19267, "mapmarkers", "red-2", 0x00000000);
	tmpobjid = CreateDynamicObject(3027, 1440.350585, 1574.456909, 108.834136, -58.900024, 179.999969, 179.999984, -1, 11, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 19267, "mapmarkers", "red-2", 0x00000000);
	tmpobjid = CreateDynamicObject(3027, 1440.350585, 1574.685058, 108.354141, -56.199985, 0.000013, 0.000011, -1, 11, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 5168, "lashops6_las2", "yellow2_128", 0x00000000);
	tmpobjid = CreateDynamicObject(3027, 1440.350585, 1574.773071, 108.408966, -25.300010, 0.000008, 0.000003, -1, 11, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 5168, "lashops6_las2", "yellow2_128", 0x00000000);
	tmpobjid = CreateDynamicObject(3027, 1440.350585, 1574.815795, 108.499374, -25.300010, 0.000008, 0.000003, -1, 11, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 5168, "lashops6_las2", "yellow2_128", 0x00000000);
	tmpobjid = CreateDynamicObject(3027, 1440.350585, 1574.859008, 108.592750, -68.200103, 0.000020, 0.000019, -1, 11, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 5168, "lashops6_las2", "yellow2_128", 0x00000000);
	tmpobjid = CreateDynamicObject(3027, 1440.350585, 1574.970336, 108.637336, -87.300125, 0.000161, 0.000161, -1, 11, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 5168, "lashops6_las2", "yellow2_128", 0x00000000);
	tmpobjid = CreateDynamicObject(3027, 1440.350585, 1575.070434, 108.642036, -87.300125, 0.000161, 0.000161, -1, 11, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 5168, "lashops6_las2", "yellow2_128", 0x00000000);
	tmpobjid = CreateDynamicObject(3027, 1440.350585, 1575.170410, 108.646728, -82.399810, 179.999938, 179.999938, -1, 11, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 5168, "lashops6_las2", "yellow2_128", 0x00000000);
	tmpobjid = CreateDynamicObject(3027, 1440.350585, 1575.249511, 108.636138, -82.399810, 179.999938, 179.999938, -1, 11, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 5168, "lashops6_las2", "yellow2_128", 0x00000000);
	tmpobjid = CreateDynamicObject(19993, 1440.378051, 1575.647705, 108.307022, 0.000000, 0.000007, 0.000000, -1, 11, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 1560, "7_11_door", "cj_sheetmetal2", 0x00000000);
	tmpobjid = CreateDynamicObject(3027, 1440.350585, 1575.358276, 108.621604, -82.399810, 179.999938, 179.999938, -1, 11, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 5168, "lashops6_las2", "yellow2_128", 0x00000000);
	tmpobjid = CreateDynamicObject(3027, 1440.350585, 1575.467041, 108.607078, -64.699768, 179.999969, 179.999969, -1, 11, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 5168, "lashops6_las2", "yellow2_128", 0x00000000);
	tmpobjid = CreateDynamicObject(3027, 1440.350585, 1575.557373, 108.564353, -50.099742, 179.999984, 179.999984, -1, 11, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 5168, "lashops6_las2", "yellow2_128", 0x00000000);
	tmpobjid = CreateDynamicObject(3027, 1440.350585, 1575.627685, 108.517768, -28.399732, 179.999984, 179.999984, -1, 11, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 5168, "lashops6_las2", "yellow2_128", 0x00000000);
	tmpobjid = CreateDynamicObject(11744, 1440.275512, 1573.860107, 108.617065, 0.000000, 0.000007, 0.000000, -1, 11, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 19267, "mapmarkers", "red-2", 0x00000000);
	tmpobjid = CreateDynamicObject(2002, 1440.316528, 1577.772460, 107.057014, 0.000000, 0.000022, 179.999938, -1, 11, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 1419, "break_fence3", "CJ_FRAME_Glass", 0x00000000);
	tmpobjid = CreateDynamicObject(19830, 1440.353637, 1578.148315, 108.306861, 0.000022, 0.000000, -90.000038, -1, 11, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 1419, "break_fence3", "CJ_FRAME_Glass", 0x00000000);
	SetDynamicObjectMaterial(tmpobjid, 1, 1419, "break_fence3", "CJ_FRAME_Glass", 0x00000000);
	SetDynamicObjectMaterial(tmpobjid, 3, 1419, "break_fence3", "CJ_FRAME_Glass", 0x00000000);
	tmpobjid = CreateDynamicObject(19570, 1440.306274, 1577.043579, 108.307029, 0.000000, 0.000022, 179.999938, -1, 11, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 18646, "matcolours", "grey-40-percent", 0x00000000);
	tmpobjid = CreateDynamicObject(19570, 1440.296264, 1576.663208, 108.307029, 0.000000, 0.000022, 179.999938, -1, 11, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 18646, "matcolours", "grey-40-percent", 0x00000000);
	tmpobjid = CreateDynamicObject(3027, 1440.302978, 1578.132080, 108.627029, 0.000000, 0.000022, 179.999938, -1, 11, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 19267, "mapmarkers", "red-2", 0x00000000);
	tmpobjid = CreateDynamicObject(3027, 1440.302978, 1578.132080, 108.737037, -17.199996, 0.000023, 179.999969, -1, 11, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 19267, "mapmarkers", "red-2", 0x00000000);
	tmpobjid = CreateDynamicObject(3027, 1440.302978, 1578.103759, 108.836051, -44.899993, 0.000032, 179.999969, -1, 11, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 19267, "mapmarkers", "red-2", 0x00000000);
	tmpobjid = CreateDynamicObject(3027, 1440.302978, 1578.024047, 108.917213, -82.499977, 0.000175, -179.999816, -1, 11, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 19267, "mapmarkers", "red-2", 0x00000000);
	tmpobjid = CreateDynamicObject(3027, 1440.302978, 1577.925048, 108.930259, -82.499977, 0.000175, -179.999816, -1, 11, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 19267, "mapmarkers", "red-2", 0x00000000);
	tmpobjid = CreateDynamicObject(3027, 1440.302978, 1577.825927, 108.943305, -73.300010, 179.999908, -0.000132, -1, 11, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 19267, "mapmarkers", "red-2", 0x00000000);
	tmpobjid = CreateDynamicObject(3027, 1440.302978, 1577.730468, 108.914558, -73.300010, 179.999908, -0.000132, -1, 11, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 19267, "mapmarkers", "red-2", 0x00000000);
	tmpobjid = CreateDynamicObject(3027, 1440.302978, 1577.635375, 108.885787, -58.900024, 179.999938, -0.000088, -1, 11, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 19267, "mapmarkers", "red-2", 0x00000000);
	tmpobjid = CreateDynamicObject(3027, 1440.302978, 1577.549926, 108.834136, -58.900024, 179.999938, -0.000088, -1, 11, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 19267, "mapmarkers", "red-2", 0x00000000);
	tmpobjid = CreateDynamicObject(3027, 1440.302978, 1577.321777, 108.354141, -56.199985, 0.000041, -179.999954, -1, 11, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 5168, "lashops6_las2", "yellow2_128", 0x00000000);
	tmpobjid = CreateDynamicObject(3027, 1440.302978, 1577.233764, 108.408966, -25.300006, 0.000025, 179.999969, -1, 11, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 5168, "lashops6_las2", "yellow2_128", 0x00000000);
	tmpobjid = CreateDynamicObject(3027, 1440.302978, 1577.191040, 108.499374, -25.300006, 0.000025, 179.999969, -1, 11, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 5168, "lashops6_las2", "yellow2_128", 0x00000000);
	tmpobjid = CreateDynamicObject(3027, 1440.302978, 1577.147827, 108.592750, -68.200103, 0.000061, -179.999923, -1, 11, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 5168, "lashops6_las2", "yellow2_128", 0x00000000);
	tmpobjid = CreateDynamicObject(3027, 1440.302978, 1577.036499, 108.637336, -87.300125, 0.000485, -179.999496, -1, 11, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 5168, "lashops6_las2", "yellow2_128", 0x00000000);
	tmpobjid = CreateDynamicObject(3027, 1440.302978, 1576.936401, 108.642036, -87.300125, 0.000485, -179.999496, -1, 11, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 5168, "lashops6_las2", "yellow2_128", 0x00000000);
	tmpobjid = CreateDynamicObject(3027, 1440.302978, 1576.836425, 108.646728, -82.399810, 179.999816, -0.000225, -1, 11, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 5168, "lashops6_las2", "yellow2_128", 0x00000000);
	tmpobjid = CreateDynamicObject(3027, 1440.302978, 1576.757324, 108.636138, -82.399810, 179.999816, -0.000225, -1, 11, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 5168, "lashops6_las2", "yellow2_128", 0x00000000);
	tmpobjid = CreateDynamicObject(19993, 1440.275512, 1576.359130, 108.307022, 0.000000, 0.000022, 179.999938, -1, 11, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 1560, "7_11_door", "cj_sheetmetal2", 0x00000000);
	tmpobjid = CreateDynamicObject(3027, 1440.302978, 1576.648559, 108.621604, -82.399810, 179.999816, -0.000225, -1, 11, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 5168, "lashops6_las2", "yellow2_128", 0x00000000);
	tmpobjid = CreateDynamicObject(3027, 1440.302978, 1576.539794, 108.607078, -64.699752, 179.999938, -0.000122, -1, 11, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 5168, "lashops6_las2", "yellow2_128", 0x00000000);
	tmpobjid = CreateDynamicObject(3027, 1440.302978, 1576.449462, 108.564353, -50.099735, 179.999954, -0.000085, -1, 11, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 5168, "lashops6_las2", "yellow2_128", 0x00000000);
	tmpobjid = CreateDynamicObject(3027, 1440.302978, 1576.379150, 108.517768, -28.399728, 179.999954, -0.000080, -1, 11, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 5168, "lashops6_las2", "yellow2_128", 0x00000000);
	tmpobjid = CreateDynamicObject(11744, 1440.378051, 1578.146728, 108.617065, 0.000000, 0.000022, 179.999938, -1, 11, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 19267, "mapmarkers", "red-2", 0x00000000);
	tmpobjid = CreateDynamicObject(1650, 1440.656005, 1570.204833, 108.646972, 0.000000, 0.000000, 41.299999, -1, 11, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 16293, "a51_undergrnd", "Was_scrpyd_door_in_hngr", 0x00000000);
	tmpobjid = CreateDynamicObject(19379, 1470.164672, 1567.115356, 107.291091, 0.000000, 270.000000, 179.999954, -1, 11, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 19853, "mihouse1", "tileblue1", 0x00000000);
	tmpobjid = CreateDynamicObject(19379, 1466.635009, 1567.115356, 105.640968, 0.000000, 360.000000, 0.000000, -1, 11, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 4835, "airoads_las", "ws_carparkwall1", 0x00000000);
	tmpobjid = CreateDynamicObject(19379, 1474.718750, 1567.115356, 105.640968, 0.000000, 360.000000, 0.000000, -1, 11, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 4835, "airoads_las", "ws_carparkwall1", 0x00000000);
	tmpobjid = CreateDynamicObject(19379, 1469.848144, 1571.877563, 105.640968, 0.000007, 360.000000, 89.999977, -1, 11, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 4835, "airoads_las", "ws_carparkwall1", 0x00000000);
	tmpobjid = CreateDynamicObject(19379, 1469.848144, 1562.527832, 105.640968, 0.000007, 360.000000, 89.999977, -1, 11, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 4835, "airoads_las", "ws_carparkwall1", 0x00000000);
	tmpobjid = CreateDynamicObject(19379, 1470.164672, 1567.115356, 110.921104, 0.000000, 90.000015, 0.000000, -1, 11, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 3615, "beachhut", "sw_flatroof01", 0x00000000);
	tmpobjid = CreateDynamicObject(937, 1474.083618, 1563.946044, 107.837051, 0.000000, 0.000000, 90.000000, -1, 11, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 1, 1560, "7_11_door", "cj_sheetmetal2", 0x00000000);
	tmpobjid = CreateDynamicObject(19900, 1472.187133, 1562.935913, 107.377029, 0.000000, 0.000000, 0.000000, -1, 11, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 1560, "7_11_door", "cj_sheetmetal2", 0x00000000);
	tmpobjid = CreateDynamicObject(937, 1474.083618, 1567.976928, 107.837051, 0.000000, 0.000000, 90.000000, -1, 11, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 1, 1560, "7_11_door", "cj_sheetmetal2", 0x00000000);
	tmpobjid = CreateDynamicObject(937, 1474.083618, 1570.858520, 107.837051, 0.000000, 0.000000, 90.000000, -1, 11, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 1, 1560, "7_11_door", "cj_sheetmetal2", 0x00000000);
	tmpobjid = CreateDynamicObject(1522, 1471.295410, 1565.549560, 107.377029, 0.000000, 0.000000, 67.900039, -1, 11, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 3819, "baseball_sfsx", "helipad_mesh_t", 0x00000000);
	tmpobjid = CreateDynamicObject(2974, 1466.501098, 1568.757568, 107.377029, 0.000000, 0.000000, 0.000000, -1, 11, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 16293, "a51_undergrnd", "Was_scrpyd_door_in_hngr", 0x00000000);
	tmpobjid = CreateDynamicObject(19899, 1468.024291, 1566.128540, 107.377029, 0.000000, 0.000000, 90.000000, -1, 11, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 1560, "7_11_door", "cj_sheetmetal2", 0x00000000);
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	tmpobjid = CreateDynamicObject(1893, 1437.607666, 1574.722900, 111.406997, 0.000007, 0.000000, 89.999977, -1, 11, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(1893, 1436.286376, 1574.722900, 111.406997, 0.000007, 0.000000, 89.999977, -1, 11, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(1893, 1436.286376, 1568.118896, 111.406997, 0.000000, 0.000000, 90.000000, -1, 11, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(1893, 1437.607666, 1568.099365, 111.406997, 0.000000, 0.000000, 90.000000, -1, 11, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(1893, 1436.286376, 1564.317626, 111.406997, 0.000007, 0.000000, 89.999977, -1, 11, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(1893, 1437.607666, 1564.298095, 111.406997, 0.000007, 0.000000, 89.999977, -1, 11, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(1893, 1437.607666, 1578.503540, 111.406997, 0.000015, 0.000000, 89.999954, -1, 11, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(1893, 1436.286376, 1578.503540, 111.406997, 0.000015, 0.000000, 89.999954, -1, 11, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(1893, 1443.052856, 1574.722900, 111.406997, 0.000022, 0.000000, 89.999931, -1, 11, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(1893, 1441.731567, 1574.722900, 111.406997, 0.000022, 0.000000, 89.999931, -1, 11, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(1893, 1440.690551, 1568.118896, 111.406997, 0.000007, 0.000000, 89.999977, -1, 11, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(1893, 1442.011840, 1568.099365, 111.406997, 0.000007, 0.000000, 89.999977, -1, 11, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(1893, 1440.690551, 1564.317626, 111.406997, 0.000015, 0.000000, 89.999954, -1, 11, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(1893, 1442.011840, 1564.298095, 111.406997, 0.000015, 0.000000, 89.999954, -1, 11, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(1893, 1443.052856, 1579.124145, 111.406997, 0.000030, 0.000000, 89.999908, -1, 11, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(1893, 1441.731567, 1579.104125, 111.406997, 0.000030, 0.000000, 89.999908, -1, 11, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(14578, 1442.165039, 1574.688476, 110.966880, 0.000000, 0.000000, 90.000000, -1, 11, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(14882, 1446.379638, 1561.488525, 109.236976, 0.000000, 0.000000, 0.000000, -1, 11, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(14882, 1446.379638, 1568.497314, 109.236976, 0.000000, 0.000000, 0.000000, -1, 11, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(14578, 1439.143676, 1580.129882, 110.966880, 0.000000, 0.000000, 270.000000, -1, 11, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(14578, 1438.453979, 1563.849853, 110.956832, 0.000000, 0.000000, 450.000000, -1, 11, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(5340, 1439.370239, 1562.538696, 108.846977, 0.000000, 0.000000, 270.000000, -1, 11, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(19869, 1441.524414, 1571.889038, 107.347023, 0.000000, 0.000000, 0.000000, -1, 11, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(14882, 1436.965820, 1566.300659, 109.316986, 0.000000, 0.000000, 0.000000, -1, 11, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(14882, 1436.965820, 1560.552001, 109.316986, 0.000000, 0.000000, 0.000000, -1, 11, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(944, 1442.607421, 1580.622070, 108.236991, 0.000000, 0.000000, 0.000000, -1, 11, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(1348, 1443.659301, 1575.938964, 108.096961, 0.000000, 0.000000, 90.000000, -1, 11, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(2007, 1443.582519, 1570.819824, 107.377029, 0.000000, 0.000000, 270.000000, -1, 11, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(2007, 1443.582519, 1569.859130, 107.377029, 0.000000, 0.000000, 270.000000, -1, 11, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(2007, 1443.582519, 1570.819824, 108.777000, -0.000007, -0.000000, -89.999977, -1, 11, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(2007, 1443.582519, 1569.859130, 108.777000, -0.000007, -0.000000, -89.999977, -1, 11, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(2418, 1435.098999, 1569.707397, 107.377029, 0.000000, 0.000000, 90.000000, -1, 11, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(2418, 1435.098999, 1567.837280, 107.377029, 0.000000, 0.000000, 90.000000, -1, 11, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(2418, 1439.942016, 1569.916748, 107.377029, 0.000000, 0.000000, 270.000000, -1, 11, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(2418, 1441.143188, 1569.005981, 107.367027, 0.000000, 0.000000, 450.000000, -1, 11, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(2958, 1435.898315, 1578.866333, 108.467025, 0.000000, 0.000000, 0.000000, -1, 11, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(2958, 1435.898315, 1579.246704, 108.467025, 0.000000, 0.000000, 0.000000, -1, 11, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(2958, 1435.267700, 1579.136596, 108.467025, 0.000000, 0.000000, 0.000000, -1, 11, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(2958, 1435.507934, 1579.456909, 108.467025, 0.000000, 0.000000, 86.200050, -1, 11, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(2958, 1435.898315, 1578.126953, 108.467025, 0.000000, 0.000015, 0.000000, -1, 11, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(2958, 1435.898315, 1578.507324, 108.467025, 0.000000, 0.000015, 0.000000, -1, 11, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(2958, 1435.267700, 1578.397216, 108.467025, 0.000000, 0.000015, 0.000000, -1, 11, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(2958, 1435.507934, 1578.717529, 108.467025, 0.000015, 0.000001, 86.200004, -1, 11, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(2958, 1435.487915, 1578.197021, 108.467025, 0.000000, 0.000022, 0.000000, -1, 11, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(2958, 1435.487915, 1578.577392, 108.467025, 0.000000, 0.000022, 0.000000, -1, 11, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(2958, 1434.857299, 1578.467285, 108.467025, 0.000000, 0.000022, 0.000000, -1, 11, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(2958, 1435.097534, 1578.787597, 108.467025, 0.000022, 0.000001, 86.199981, -1, 11, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(928, 1435.397705, 1577.455444, 108.636955, 0.000000, 0.000000, 0.000000, -1, 11, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(928, 1435.397705, 1576.594970, 108.636955, 0.000000, 0.000000, 55.900005, -1, 11, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(1575, 1435.570068, 1575.824951, 108.377037, 0.000000, 0.000000, 47.999996, -1, 11, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(1575, 1435.485717, 1574.353149, 108.377037, 0.000000, 0.000000, -65.299995, -1, 11, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(1575, 1435.652954, 1574.424194, 108.442527, 0.000000, 27.200010, 23.100000, -1, 11, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(1578, 1435.442993, 1574.394409, 109.157005, 0.000000, 0.000000, -44.200000, -1, 11, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(1578, 1435.426757, 1577.088867, 109.157005, 0.000000, 0.000000, -44.200000, -1, 11, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(1578, 1435.415039, 1577.894287, 109.157005, 0.000000, 0.000000, 29.299995, -1, 11, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(19585, 1435.071777, 1568.594970, 108.727020, 0.000000, 0.000000, 0.000000, -1, 11, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(19585, 1440.285644, 1574.068359, 108.717018, 0.000000, 0.000007, 0.000000, -1, 11, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(19585, 1440.367919, 1577.938476, 108.717018, 0.000000, 0.000022, 179.999938, -1, 11, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(1575, 1439.968505, 1569.893676, 108.256988, 0.000000, 0.000000, -36.299999, -1, 11, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(1575, 1439.995239, 1568.883178, 108.256988, 0.000000, 0.000000, 55.000000, -1, 11, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(19585, 1440.929199, 1569.144042, 108.506965, 0.000000, 0.000000, 0.000000, -1, 11, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(19585, 1441.299560, 1569.144042, 108.506965, 0.000000, 0.000000, 0.000000, -1, 11, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(1893, 1440.109497, 1577.182250, 110.907035, 0.000000, 0.000000, 0.000000, -1, 11, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(1893, 1440.109497, 1574.610839, 110.907035, 0.000000, 0.000000, 0.000000, -1, 11, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(1893, 1468.148437, 1563.969726, 111.406997, 0.000015, 0.000000, 89.999954, -1, 11, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(1893, 1473.563720, 1563.969726, 111.406997, 0.000030, 0.000000, 89.999908, -1, 11, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(1893, 1473.563720, 1569.462524, 111.406997, 0.000030, 0.000000, 89.999908, -1, 11, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(19869, 1473.884887, 1565.609375, 107.377029, 0.000000, 0.000007, 0.000000, -1, 11, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(1893, 1468.148437, 1569.462524, 111.406997, 0.000015, 0.000000, 89.999954, -1, 11, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(19869, 1467.485351, 1565.609375, 107.377029, 0.000000, 0.000007, 0.000000, -1, 11, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(19869, 1467.485351, 1565.609375, 109.806976, 0.000000, 0.000007, 0.000000, -1, 11, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(19869, 1473.884887, 1565.609375, 109.797012, 0.000000, 0.000007, 0.000000, -1, 11, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(19869, 1470.702026, 1565.609375, 109.797012, 0.000000, 0.000007, 0.000000, -1, 11, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(2924, 1471.296386, 1562.562622, 108.586975, 0.000000, 0.000000, 360.000000, -1, 11, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(1224, 1467.353393, 1563.255859, 107.977027, 0.000000, 0.000000, 0.000000, -1, 11, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(1224, 1467.353393, 1563.255859, 109.136932, 0.000000, 0.000000, 450.000000, -1, 11, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(1221, 1467.460937, 1564.697998, 107.817024, 0.000000, 0.000000, -35.800003, -1, 11, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(3052, 1473.942871, 1563.287475, 108.446968, 0.000000, 0.000000, 0.000000, -1, 11, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(356, 1473.747924, 1563.951293, 108.386955, 90.000000, -108.800003, 90.000000, -1, 11, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(352, 1473.912475, 1564.497314, 108.297019, 90.000000, -49.999996, 0.000000, -1, 11, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(2359, 1474.465942, 1564.343505, 108.507019, 0.000000, 0.000000, 270.000000, -1, 11, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(2041, 1474.440307, 1567.321289, 108.527023, 0.000000, 0.000000, 0.000000, -1, 11, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(2041, 1474.099975, 1567.321289, 108.527023, 0.000000, 0.000000, -37.699989, -1, 11, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(2041, 1474.305786, 1568.651611, 108.527023, 0.000000, 0.000000, -134.000000, -1, 11, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(352, 1473.847778, 1567.979614, 108.317008, 90.000000, 29.699998, 0.000000, -1, 11, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(3384, 1473.821044, 1566.330932, 108.786987, 0.000000, 0.000000, 0.000000, -1, 11, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(2615, 1474.569213, 1567.978759, 109.176979, 0.000000, 0.000000, 270.000000, -1, 11, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(1431, 1471.037719, 1571.437866, 107.886962, 0.000000, 0.000000, 180.000000, -1, 11, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(923, 1467.621582, 1571.315917, 108.246948, 0.000000, 0.000000, 0.000000, -1, 11, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(3014, 1474.196044, 1570.281372, 108.517044, 0.000000, 0.000000, 0.000000, -1, 11, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(3014, 1473.765625, 1571.391601, 108.517044, 0.000000, 0.000000, 0.000000, -1, 11, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(2969, 1467.733154, 1566.127807, 108.716995, 0.000000, 0.000000, 0.000000, -1, 11, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(2969, 1468.833374, 1566.127807, 109.536987, 0.000000, 0.000000, 0.000000, -1, 11, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(2068, 1470.539672, 1567.722412, 110.886863, 0.000000, 0.000000, 0.000000, -1, 11, -1, 800.00, 800.00); 

}
InsertEmmetMaps() {
    
    // Families Emmet (pull original mapping)
    new g_Object[151];
    g_Object[0] = CreateDynamicObject(1448, 2440.3666, -1967.6428, 12.6197, 0.0000, 0.0000, 0.0000); //DYN_CRATE_1
    g_Object[1] = CreateDynamicObject(2968, 2440.1203, -1967.8758, 12.9933, 0.0000, 0.0000, 0.0000); //cm_box
    g_Object[2] = CreateDynamicObject(928, 2440.6364, -1967.4493, 12.9525, 0.0000, 0.0000, 0.0000); //RUBBISH_BOX1
    g_Object[3] = CreateDynamicObject(964, 2440.1801, -1966.3198, 12.5731, 0.0000, 0.0000, 90.0000); //CJ_METAL_CRATE
    SetDynamicObjectMaterial(g_Object[3], 0, 10839, "aircarpkbarier_sfse", "cratetop128", 0xFFFFFFFF);
    SetDynamicObjectMaterial(g_Object[3], 1, 3066, "ammotrx", "ammotrn92crate64", 0xFFFFFFFF);
    SetDynamicObjectMaterial(g_Object[3], 2, 10839, "aircarpkbarier_sfse", "cratetop128", 0xFFFFFFFF);
    g_Object[4] = CreateDynamicObject(1431, 2440.0378, -1964.1656, 13.1028, 0.0000, 0.0000, 86.9999); //DYN_BOX_PILE
    SetDynamicObjectMaterial(g_Object[4], 0, 12821, "alleystuff", "Gen_Crate", 0xFFFFFFFF);
    g_Object[5] = CreateDynamicObject(1449, 2441.0214, -1962.5495, 13.1049, 0.0000, 0.0000, 0.0000); //DYN_CRATE_2
    SetDynamicObjectMaterial(g_Object[5], 0, 3063, "col_wall1x", "ab_wood1", 0xFFFFFFFF);
    g_Object[6] = CreateDynamicObject(941, 2443.0495, -1962.6407, 13.0080, 0.0000, 0.0000, 0.0000); //CJ_DF_WORKTOP_3
    SetDynamicObjectMaterial(g_Object[6], 0, 10839, "aircarpkbarier_sfse", "cratetop128", 0xFFFFFFFF);
    SetDynamicObjectMaterial(g_Object[6], 1, 3066, "ammotrx", "ammotrn92crate64", 0xFFFFFFFF);
    g_Object[7] = CreateDynamicObject(1450, 2445.1274, -1962.6312, 13.1105, 0.0000, 0.0000, 0.0000); //DYN_CRATE_3
    g_Object[8] = CreateDynamicObject(924, 2444.1213, -1962.6595, 13.6716, 0.0000, 0.0000, -90.0000); //FRUITCRATE3
    g_Object[9] = CreateDynamicObject(917, 2442.5366, -1962.3260, 13.6218, 0.0000, 0.0000, 0.0000); //FRUITCRATE1
    g_Object[10] = CreateDynamicObject(2749, 2442.7336, -1962.1982, 13.4820, 0.0000, 0.0000, 0.0000); //CJ_hairspray
    SetDynamicObjectMaterial(g_Object[10], 0, 6869, "vegastemp1", "vgnbarbtex1_256", 0xFFFFFFFF);
    g_Object[11] = CreateDynamicObject(2749, 2442.7336, -1962.3784, 13.4820, 0.0000, 0.0000, 0.0000); //CJ_hairspray
    SetDynamicObjectMaterial(g_Object[11], 0, 19344, "egg_texts", "easter_egg01", 0xFFFFFFFF);
    g_Object[12] = CreateDynamicObject(2749, 2442.3791, -1962.3614, 13.5621, 0.0000, 90.0000, 27.6000); //CJ_hairspray
    SetDynamicObjectMaterial(g_Object[12], 0, 18835, "mickytextures", "metal013", 0xFFFFFFFF);
    g_Object[13] = CreateDynamicObject(19914, 2442.3395, -1962.9560, 13.5165, 0.0000, 0.0000, 26.7999); //CutsceneBat1
    SetDynamicObjectMaterial(g_Object[13], 0, 18028, "cj_bar2", "CJ_nastybar_D3", 0xFFFFFFFF);
    g_Object[14] = CreateDynamicObject(2676, 2443.5129, -1963.4809, 12.6801, 0.0000, 0.0000, 0.0000); //PROC_RUBBISH_8
    g_Object[15] = CreateDynamicObject(2853, 2443.1823, -1962.6400, 13.4729, 0.0000, 0.0000, -22.2000); //gb_bedmags03
    SetDynamicObjectMaterial(g_Object[15], 0, 19297, "matlights", "invisible", 0xFFFFFFFF);
    SetDynamicObjectMaterial(g_Object[15], 1, 19297, "matlights", "invisible", 0xFFFFFFFF);
    SetDynamicObjectMaterial(g_Object[15], 2, 19297, "matlights", "invisible", 0xFFFFFFFF);
    SetDynamicObjectMaterial(g_Object[15], 3, 19297, "matlights", "invisible", 0xFFFFFFFF);
    SetDynamicObjectMaterial(g_Object[15], 6, 19297, "matlights", "invisible", 0xFFFFFFFF);
    SetDynamicObjectMaterial(g_Object[15], 7, 19297, "matlights", "invisible", 0xFFFFFFFF);
    SetDynamicObjectMaterial(g_Object[15], 8, 19297, "matlights", "invisible", 0xFFFFFFFF);
    SetDynamicObjectMaterial(g_Object[15], 9, 19297, "matlights", "invisible", 0xFFFFFFFF);
    g_Object[16] = CreateDynamicObject(960, 2442.8374, -1962.5334, 12.8899, 0.0000, 0.0000, 0.0000); //CJ_ARM_CRATE
    g_Object[17] = CreateDynamicObject(3015, 2445.6723, -1965.8929, 12.6878, 0.0000, 0.0000, -147.3999); //cr_cratestack
    SetDynamicObjectMaterial(g_Object[17], 0, 5132, "imstuff_las2", "sjmlawarshcrategen", 0xFFFFFFFF);
    SetDynamicObjectMaterial(g_Object[17], 1, 5132, "imstuff_las2", "sjmlawarshcrategen", 0xFFFFFFFF);
    g_Object[18] = CreateDynamicObject(2040, 2444.1262, -1966.3917, 13.1351, 0.0000, 0.0000, 35.3997); //AMMO_BOX_M1
    g_Object[19] = CreateDynamicObject(2586, 2444.1928, -1966.3205, 13.0354, 0.0000, 0.0000, 14.3999); //CJ_SEX_COUNTER2
    SetDynamicObjectMaterial(g_Object[19], 0, 19297, "matlights", "invisible", 0xFFFFFFFF);
    SetDynamicObjectMaterial(g_Object[19], 2, 15040, "cuntcuts", "csnewspaper02", 0xFFFFFFFF);
    SetDynamicObjectMaterial(g_Object[19], 3, 19297, "matlights", "invisible", 0xFFFFFFFF);
    SetDynamicObjectMaterial(g_Object[19], 4, 19297, "matlights", "invisible", 0xFFFFFFFF);
    SetDynamicObjectMaterial(g_Object[19], 5, 18064, "ab_sfammuunits", "gun_targetc", 0xFFFFFFFF);
    SetDynamicObjectMaterial(g_Object[19], 7, 16387, "des_gunclub", "woodenpanels256", 0xFFFFFFFF);
    SetDynamicObjectMaterial(g_Object[19], 8, 19297, "matlights", "invisible", 0xFFFFFFFF);
    SetDynamicObjectMaterial(g_Object[19], 9, 19297, "matlights", "invisible", 0xFFFFFFFF);
    SetDynamicObjectMaterial(g_Object[19], 10, 19297, "matlights", "invisible", 0xFFFFFFFF);
    SetDynamicObjectMaterial(g_Object[19], 11, 19297, "matlights", "invisible", 0xFFFFFFFF);
    g_Object[20] = CreateDynamicObject(2042, 2444.4499, -1966.3508, 12.8634, 0.0000, 0.0000, -14.0000); //AMMO_BOX_M3
    g_Object[21] = CreateDynamicObject(2043, 2444.8005, -1966.0992, 13.1267, 0.0000, 0.0000, -36.7999); //AMMO_BOX_M4
    g_Object[22] = CreateDynamicObject(2358, 2443.5849, -1966.5322, 12.8697, 0.0000, 0.0000, -165.1999); //AMMO_BOX_c2

    // Weapons
    CreateDynamicObject(337, 2170.47144, -1505.10559, 24.00065,   0.00000, 90.00000, 90.00000); // Shovel
    CreateDynamicObject(336, 2169.82715, -1504.59607, 24.00070,   0.00000, 90.00000, -79.08002); // Bat
    CreateDynamicObject(346, 2169.09839, -1504.90320, 23.91879,   85.74005, 92.33997, -45.00000); // Colt
    CreateDynamicObject(352, 2168.07275, -1505.27966, 23.91880,   90.00000, 90.00000, -72.66008); // Uzi
    CreateDynamicObject(372, 2166.94263, -1506.31592, 23.91880,   90.00000, 90.00000, -26.57990); // Tec
    CreateDynamicObject(349, 2166.26147, -1507.68811, 23.85945,   97.01997, 93.36000, -49.50007); // Shotgun
    CreateDynamicObject(355, 2166.29810, -1508.62866, 23.85940,   97.02000, 93.36000, -51.59982); // AK
}

InsertASGHMaps()
{
	//= SAMD INTERIOR
	tmpobjid = CreateDynamicObject(19378, 1835.652465, -1074.273193, 40.567787, 0.000000, 90.000000, 90.000000, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 19597, "lsbeachside", "ceilingtiles4-128x128", 0x00000000);
    tmpobjid = CreateDynamicObject(19378, 1845.281738, -1074.273193, 40.567787, 0.000000, 90.000000, 90.000000, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 19597, "lsbeachside", "ceilingtiles4-128x128", 0x00000000);
    tmpobjid = CreateDynamicObject(19378, 1854.912353, -1074.273193, 40.567787, 0.000000, 90.000000, 90.000000, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 19597, "lsbeachside", "ceilingtiles4-128x128", 0x00000000);
    tmpobjid = CreateDynamicObject(19378, 1835.652465, -1084.751342, 40.567787, 0.000007, 90.000000, 89.999977, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 19597, "lsbeachside", "ceilingtiles4-128x128", 0x00000000);
    tmpobjid = CreateDynamicObject(19378, 1845.281738, -1084.751342, 40.567787, 0.000007, 90.000000, 89.999977, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 19597, "lsbeachside", "ceilingtiles4-128x128", 0x00000000);
    tmpobjid = CreateDynamicObject(19378, 1854.912353, -1084.751342, 40.567787, 0.000007, 90.000000, 89.999977, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 19597, "lsbeachside", "ceilingtiles4-128x128", 0x00000000);
    tmpobjid = CreateDynamicObject(19378, 1835.652465, -1095.251220, 40.567787, 0.000014, 90.000000, 89.999954, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 19597, "lsbeachside", "ceilingtiles4-128x128", 0x00000000);
    tmpobjid = CreateDynamicObject(19378, 1845.281738, -1095.251220, 40.567787, 0.000014, 90.000000, 89.999954, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 19597, "lsbeachside", "ceilingtiles4-128x128", 0x00000000);
    tmpobjid = CreateDynamicObject(19378, 1854.912353, -1095.251220, 40.567787, 0.000014, 90.000000, 89.999954, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 19597, "lsbeachside", "ceilingtiles4-128x128", 0x00000000);
    tmpobjid = CreateDynamicObject(19378, 1835.652465, -1105.721435, 40.567787, 0.000022, 90.000000, 89.999931, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 19597, "lsbeachside", "ceilingtiles4-128x128", 0x00000000);
    tmpobjid = CreateDynamicObject(19378, 1845.281738, -1105.721435, 40.567787, 0.000022, 90.000000, 89.999931, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 19597, "lsbeachside", "ceilingtiles4-128x128", 0x00000000);
    tmpobjid = CreateDynamicObject(19378, 1854.912353, -1105.721435, 40.567787, 0.000022, 90.000000, 89.999931, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 19597, "lsbeachside", "ceilingtiles4-128x128", 0x00000000);
    tmpobjid = CreateDynamicObject(19448, 1835.696655, -1069.121826, 42.413753, 0.000000, 0.000000, 90.000000, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    tmpobjid = CreateDynamicObject(19448, 1835.696655, -1069.131835, 39.733760, 0.000000, 0.000000, 90.000000, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1833.141479, -1069.241699, 41.653774, 0.000000, 450.000000, 179.999984, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1830.880126, -1069.241699, 41.653774, 0.000000, 450.000000, 179.999984, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19448, 1835.696655, -1069.131835, 45.803749, 0.000000, 0.000000, 90.000000, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 10765, "airportgnd_sfse", "black64", 0x00000000);
    tmpobjid = CreateDynamicObject(19378, 1835.652465, -1074.273193, 44.257804, 0.000000, 90.000000, 90.000000, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 3922, "bistro", "Marble2", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1833.141479, -1069.241699, 41.713783, 0.000000, 450.000000, 179.999938, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1830.880126, -1069.241699, 41.713783, 0.000000, 450.000000, 179.999938, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19448, 1845.315673, -1069.121826, 42.413753, 0.000007, 0.000000, 89.999977, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    tmpobjid = CreateDynamicObject(19448, 1845.315673, -1069.131835, 39.733760, 0.000007, 0.000000, 89.999977, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1842.760498, -1069.241699, 41.653774, 0.000000, 450.000000, 179.999938, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1840.499145, -1069.241699, 41.653774, 0.000000, 450.000000, 179.999938, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19448, 1845.315673, -1069.131835, 45.803749, 0.000007, 0.000000, 89.999977, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 10765, "airportgnd_sfse", "black64", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1842.760498, -1069.241699, 41.713783, 0.000000, 450.000000, 179.999893, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1840.499145, -1069.241699, 41.713783, 0.000000, 450.000000, 179.999893, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19448, 1850.156738, -1072.090454, 42.413753, 0.000014, 0.000000, -0.000091, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    tmpobjid = CreateDynamicObject(19448, 1850.146728, -1072.090454, 39.733760, 0.000014, 0.000000, -0.000091, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1850.036865, -1069.535278, 41.653774, 0.000000, 450.000000, 89.999893, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1850.036865, -1067.273925, 41.653774, 0.000000, 450.000000, 89.999893, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19448, 1850.146728, -1072.090454, 45.803749, 0.000014, 0.000000, -0.000091, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 10765, "airportgnd_sfse", "black64", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1850.036865, -1069.535278, 41.713783, 0.000000, 450.000000, 89.999847, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1850.036865, -1067.273925, 41.713783, 0.000000, 450.000000, 89.999847, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19448, 1854.874755, -1076.831420, 42.413753, 0.000022, 0.000007, 89.999855, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    tmpobjid = CreateDynamicObject(19448, 1854.874755, -1076.841430, 39.733760, 0.000022, 0.000007, 89.999855, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1852.319580, -1076.951293, 41.653774, 0.000007, 450.000000, 179.999801, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1850.058227, -1076.951293, 41.653774, 0.000007, 450.000000, 179.999801, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19448, 1854.874755, -1076.841430, 45.803749, 0.000022, 0.000007, 89.999855, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 10765, "airportgnd_sfse", "black64", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1852.319580, -1076.951293, 41.713783, 0.000007, 450.000000, 179.999755, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1850.058227, -1076.951293, 41.713783, 0.000007, 450.000000, 179.999755, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19448, 1859.016479, -1081.629150, 42.413753, 0.000029, 0.000014, -0.000136, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    tmpobjid = CreateDynamicObject(19448, 1859.006469, -1081.629150, 39.733760, 0.000029, 0.000014, -0.000136, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1858.896606, -1079.073974, 41.653774, 0.000014, 450.000000, 89.999763, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1858.896606, -1076.812622, 41.653774, 0.000014, 450.000000, 89.999763, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19448, 1859.006469, -1081.629150, 45.803749, 0.000029, 0.000014, -0.000136, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 10765, "airportgnd_sfse", "black64", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1858.896606, -1079.073974, 41.713783, 0.000014, 450.000000, 89.999717, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1858.896606, -1076.812622, 41.713783, 0.000014, 450.000000, 89.999717, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19448, 1859.016479, -1091.248046, 42.413753, 0.000029, 0.000022, -0.000136, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    tmpobjid = CreateDynamicObject(19448, 1859.006469, -1091.248046, 39.733760, 0.000029, 0.000022, -0.000136, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1858.896606, -1088.692871, 41.653774, 0.000022, 450.000000, 89.999740, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1858.896606, -1086.431518, 41.653774, 0.000022, 450.000000, 89.999740, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19448, 1859.006469, -1091.248046, 45.803749, 0.000029, 0.000022, -0.000136, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 10765, "airportgnd_sfse", "black64", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1858.896606, -1088.692871, 41.713783, 0.000022, 450.000000, 89.999694, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1858.896606, -1086.431518, 41.713783, 0.000022, 450.000000, 89.999694, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19448, 1859.016479, -1100.877197, 42.413753, 0.000029, 0.000029, -0.000136, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    tmpobjid = CreateDynamicObject(19448, 1859.006469, -1100.877197, 39.733760, 0.000029, 0.000029, -0.000136, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1858.896606, -1098.322021, 41.653774, 0.000029, 450.000000, 89.999717, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1858.896606, -1096.060668, 41.653774, 0.000029, 450.000000, 89.999717, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19448, 1859.006469, -1100.877197, 45.803749, 0.000029, 0.000029, -0.000136, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 10765, "airportgnd_sfse", "black64", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1858.896606, -1098.322021, 41.713783, 0.000029, 450.000000, 89.999671, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1858.896606, -1096.060668, 41.713783, 0.000029, 450.000000, 89.999671, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19448, 1850.867919, -1105.708374, 42.413753, 0.000022, 0.000037, -90.000114, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    tmpobjid = CreateDynamicObject(19448, 1850.867919, -1105.698364, 39.733760, 0.000022, 0.000037, -90.000114, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1853.423095, -1105.588500, 41.653774, 0.000037, 450.000000, -0.000349, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1855.684448, -1105.588500, 41.653774, 0.000037, 450.000000, -0.000349, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19448, 1850.867919, -1105.698364, 45.803749, 0.000022, 0.000037, -90.000114, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 10765, "airportgnd_sfse", "black64", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1853.423095, -1105.588500, 41.713783, 0.000037, 450.000000, -0.000395, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1855.684448, -1105.588500, 41.713783, 0.000037, 450.000000, -0.000395, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19448, 1841.269775, -1105.708374, 42.413753, 0.000014, 0.000037, -90.000091, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    tmpobjid = CreateDynamicObject(19448, 1841.269775, -1105.698364, 39.733760, 0.000014, 0.000037, -90.000091, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1843.824951, -1105.588500, 41.653774, 0.000037, 450.000000, -0.000349, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1846.086303, -1105.588500, 41.653774, 0.000037, 450.000000, -0.000349, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19448, 1841.269775, -1105.698364, 45.803749, 0.000014, 0.000037, -90.000091, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 10765, "airportgnd_sfse", "black64", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1843.824951, -1105.588500, 41.713783, 0.000037, 450.000000, -0.000395, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1846.086303, -1105.588500, 41.713783, 0.000037, 450.000000, -0.000395, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19448, 1831.639526, -1105.708374, 42.413753, 0.000007, 0.000037, -90.000068, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    tmpobjid = CreateDynamicObject(19448, 1831.639526, -1105.698364, 39.733760, 0.000007, 0.000037, -90.000068, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1834.194702, -1105.588500, 41.653774, 0.000037, 450.000000, -0.000349, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1836.456054, -1105.588500, 41.653774, 0.000037, 450.000000, -0.000349, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19448, 1831.639526, -1105.698364, 45.803749, 0.000007, 0.000037, -90.000068, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 10765, "airportgnd_sfse", "black64", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1834.194702, -1105.588500, 41.713783, 0.000037, 450.000000, -0.000395, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1836.456054, -1105.588500, 41.713783, 0.000037, 450.000000, -0.000395, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19448, 1831.577880, -1100.890991, 42.413753, 0.000007, 0.000037, 179.999801, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    tmpobjid = CreateDynamicObject(19448, 1831.587890, -1100.890991, 39.733760, 0.000007, 0.000037, 179.999801, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1831.697753, -1103.446166, 41.653774, 0.000037, 450.000000, -90.000350, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1831.697753, -1105.707519, 41.653774, 0.000037, 450.000000, -90.000350, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19448, 1831.587890, -1100.890991, 45.803749, 0.000007, 0.000037, 179.999801, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 10765, "airportgnd_sfse", "black64", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1831.697753, -1103.446166, 41.713783, 0.000037, 450.000000, -90.000396, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1831.697753, -1105.707519, 41.713783, 0.000037, 450.000000, -90.000396, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19448, 1831.577880, -1091.351196, 42.413753, 0.000007, 0.000029, 179.999755, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    tmpobjid = CreateDynamicObject(19448, 1831.587890, -1091.351196, 39.733760, 0.000007, 0.000029, 179.999755, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1831.697753, -1093.906372, 41.653774, 0.000029, 450.000000, -90.000328, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1831.697753, -1096.167724, 41.653774, 0.000029, 450.000000, -90.000328, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19448, 1831.587890, -1091.351196, 45.803749, 0.000007, 0.000029, 179.999755, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 10765, "airportgnd_sfse", "black64", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1831.697753, -1093.906372, 41.713783, 0.000029, 450.000000, -90.000373, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1831.697753, -1096.167724, 41.713783, 0.000029, 450.000000, -90.000373, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19448, 1831.577880, -1081.760742, 42.413753, 0.000007, 0.000022, 179.999710, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    tmpobjid = CreateDynamicObject(19448, 1831.587890, -1081.760742, 39.733760, 0.000007, 0.000022, 179.999710, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1831.697753, -1084.315917, 41.653774, 0.000022, 450.000000, -90.000305, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1831.697753, -1086.577270, 41.653774, 0.000022, 450.000000, -90.000305, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19448, 1831.587890, -1081.760742, 45.803749, 0.000007, 0.000022, 179.999710, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 10765, "airportgnd_sfse", "black64", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1831.697753, -1084.315917, 41.713783, 0.000022, 450.000000, -90.000350, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1831.697753, -1086.577270, 41.713783, 0.000022, 450.000000, -90.000350, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19448, 1831.577880, -1072.430786, 42.413753, 0.000007, 0.000014, 179.999664, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    tmpobjid = CreateDynamicObject(19448, 1831.587890, -1072.430786, 39.733760, 0.000007, 0.000014, 179.999664, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1831.697753, -1074.985961, 41.653774, 0.000014, 450.000000, -90.000282, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1831.697753, -1077.247314, 41.653774, 0.000014, 450.000000, -90.000282, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19448, 1831.587890, -1072.430786, 45.803749, 0.000007, 0.000014, 179.999664, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 10765, "airportgnd_sfse", "black64", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1831.697753, -1074.985961, 41.713783, 0.000014, 450.000000, -90.000328, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1831.697753, -1077.247314, 41.713783, 0.000014, 450.000000, -90.000328, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19378, 1845.272460, -1074.273193, 44.257804, 0.000000, 90.000000, 90.000000, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 3922, "bistro", "Marble2", 0x00000000);
    tmpobjid = CreateDynamicObject(19378, 1854.891967, -1074.273193, 44.257804, 0.000000, 90.000000, 90.000000, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 3922, "bistro", "Marble2", 0x00000000);
    tmpobjid = CreateDynamicObject(19378, 1835.652465, -1084.773071, 44.257804, 0.000007, 90.000000, 89.999977, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 3922, "bistro", "Marble2", 0x00000000);
    tmpobjid = CreateDynamicObject(19378, 1845.272460, -1084.773071, 44.257804, 0.000007, 90.000000, 89.999977, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 3922, "bistro", "Marble2", 0x00000000);
    tmpobjid = CreateDynamicObject(19378, 1854.891967, -1084.773071, 44.257804, 0.000007, 90.000000, 89.999977, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 3922, "bistro", "Marble2", 0x00000000);
    tmpobjid = CreateDynamicObject(19378, 1835.652465, -1095.263793, 44.257804, 0.000014, 90.000000, 89.999954, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 3922, "bistro", "Marble2", 0x00000000);
    tmpobjid = CreateDynamicObject(19378, 1845.272460, -1095.263793, 44.257804, 0.000014, 90.000000, 89.999954, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 3922, "bistro", "Marble2", 0x00000000);
    tmpobjid = CreateDynamicObject(19378, 1854.891967, -1095.263793, 44.257804, 0.000014, 90.000000, 89.999954, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 3922, "bistro", "Marble2", 0x00000000);
    tmpobjid = CreateDynamicObject(19378, 1835.833007, -1105.743408, 44.257804, 0.000037, 90.000000, 89.999885, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 3922, "bistro", "Marble2", 0x00000000);
    tmpobjid = CreateDynamicObject(19378, 1845.453002, -1105.743408, 44.257804, 0.000037, 90.000000, 89.999885, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 3922, "bistro", "Marble2", 0x00000000);
    tmpobjid = CreateDynamicObject(19378, 1855.072509, -1105.743408, 44.257804, 0.000037, 90.000000, 89.999885, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 3922, "bistro", "Marble2", 0x00000000);
    tmpobjid = CreateDynamicObject(19448, 1845.328735, -1082.972167, 42.413753, 0.000014, 0.000000, 89.999954, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    tmpobjid = CreateDynamicObject(19448, 1845.328735, -1082.982177, 39.733760, 0.000014, 0.000000, 89.999954, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1842.773559, -1083.092041, 41.653774, 0.000000, 450.000000, 179.999893, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1840.512207, -1083.092041, 41.653774, 0.000000, 450.000000, 179.999893, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19448, 1845.328735, -1082.982177, 45.803749, 0.000014, 0.000000, 89.999954, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 10765, "airportgnd_sfse", "black64", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1842.773559, -1083.092041, 41.713783, 0.000000, 450.000000, 179.999847, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1840.512207, -1083.092041, 41.713783, 0.000000, 450.000000, 179.999847, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19448, 1845.328735, -1082.932128, 39.733760, 0.000014, 0.000000, 89.999954, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1842.773559, -1082.871826, 41.653774, 0.000000, 450.000000, 179.999847, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1840.512207, -1082.871826, 41.653774, 0.000000, 450.000000, 179.999847, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1842.773559, -1082.871826, 41.713783, 0.000000, 450.000000, 179.999801, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1840.512207, -1082.871826, 41.713783, 0.000000, 450.000000, 179.999801, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19448, 1845.328735, -1082.952148, 45.803749, 0.000014, 0.000000, 89.999954, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 10765, "airportgnd_sfse", "black64", 0x00000000);
    tmpobjid = CreateDynamicObject(19448, 1835.728881, -1082.972167, 42.413753, 0.000022, 0.000000, 89.999931, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    tmpobjid = CreateDynamicObject(19448, 1835.728881, -1082.982177, 39.733760, 0.000022, 0.000000, 89.999931, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1833.173706, -1083.092041, 41.653774, 0.000000, 450.000000, 179.999847, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1830.912353, -1083.092041, 41.653774, 0.000000, 450.000000, 179.999847, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19448, 1835.728881, -1082.982177, 45.803749, 0.000022, 0.000000, 89.999931, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 10765, "airportgnd_sfse", "black64", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1833.173706, -1083.092041, 41.713783, 0.000000, 450.000000, 179.999801, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1830.912353, -1083.092041, 41.713783, 0.000000, 450.000000, 179.999801, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19448, 1835.728881, -1082.932128, 39.733760, 0.000022, 0.000000, 89.999931, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1833.173706, -1082.871826, 41.653774, 0.000000, 450.000000, 179.999801, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1830.912353, -1082.871826, 41.653774, 0.000000, 450.000000, 179.999801, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1833.173706, -1082.871826, 41.713783, 0.000000, 450.000000, 179.999755, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1830.912353, -1082.871826, 41.713783, 0.000000, 450.000000, 179.999755, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19448, 1835.728881, -1082.952148, 45.803749, 0.000022, 0.000000, 89.999931, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 10765, "airportgnd_sfse", "black64", 0x00000000);
    tmpobjid = CreateDynamicObject(19448, 1836.360473, -1078.097045, 42.413753, 0.000029, -0.000014, 179.999786, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    tmpobjid = CreateDynamicObject(19448, 1836.370483, -1078.097045, 39.733760, 0.000029, -0.000014, 179.999786, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1836.480346, -1080.652221, 41.653774, -0.000014, 450.000000, -90.000091, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1836.480346, -1082.913574, 41.653774, -0.000014, 450.000000, -90.000091, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19448, 1836.370483, -1078.097045, 45.803749, 0.000029, -0.000014, 179.999786, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 10765, "airportgnd_sfse", "black64", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1836.480346, -1080.652221, 41.713783, -0.000014, 450.000000, -90.000137, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1836.480346, -1082.913574, 41.713783, -0.000014, 450.000000, -90.000137, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19448, 1836.340454, -1078.097045, 39.733760, 0.000029, -0.000014, 179.999786, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1836.260131, -1080.652221, 41.653774, -0.000014, 450.000000, -90.000137, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1836.260131, -1082.913574, 41.653774, -0.000014, 450.000000, -90.000137, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1836.260131, -1080.652221, 41.713783, -0.000014, 450.000000, -90.000183, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1836.260131, -1082.913574, 41.713783, -0.000014, 450.000000, -90.000183, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19448, 1836.340454, -1078.097045, 45.803749, 0.000029, -0.000014, 179.999786, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 10765, "airportgnd_sfse", "black64", 0x00000000);
    tmpobjid = CreateDynamicObject(19398, 1836.360473, -1071.677001, 42.423759, 0.000029, -0.000014, 179.999786, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19398, 1836.400512, -1071.697021, 40.023757, 180.000030, -0.000014, 179.999786, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    tmpobjid = CreateDynamicObject(19398, 1836.330444, -1071.697021, 40.023757, 180.000030, -0.000014, 179.999786, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    tmpobjid = CreateDynamicObject(19448, 1836.360473, -1065.298339, 42.413753, 0.000029, -0.000022, 179.999740, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    tmpobjid = CreateDynamicObject(19448, 1836.370483, -1065.298339, 39.733760, 0.000029, -0.000022, 179.999740, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1836.480346, -1067.853515, 41.653774, -0.000022, 450.000000, -90.000068, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1836.480346, -1070.114868, 41.653774, -0.000022, 450.000000, -90.000068, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19448, 1836.370483, -1065.298339, 45.803749, 0.000029, -0.000022, 179.999740, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 10765, "airportgnd_sfse", "black64", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1836.480346, -1067.853515, 41.713783, -0.000022, 450.000000, -90.000114, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1836.480346, -1070.114868, 41.713783, -0.000022, 450.000000, -90.000114, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1836.260131, -1067.853515, 41.653774, -0.000022, 450.000000, -90.000114, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1836.260131, -1070.114868, 41.653774, -0.000022, 450.000000, -90.000114, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1836.260131, -1067.853515, 41.713783, -0.000022, 450.000000, -90.000160, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1836.260131, -1070.114868, 41.713783, -0.000022, 450.000000, -90.000160, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19448, 1836.340454, -1065.298339, 45.803749, 0.000029, -0.000022, 179.999740, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 10765, "airportgnd_sfse", "black64", 0x00000000);
    tmpobjid = CreateDynamicObject(18766, 1840.982177, -1078.061157, 39.253711, 0.000000, 0.000000, 90.000000, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 14526, "sweetsmain", "ah_whitpanelceil", 0x00000000);
    tmpobjid = CreateDynamicObject(3431, 1841.796997, -1074.017456, 41.143707, 0.000000, 0.000000, 180.000000, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 6871, "vegascourtbld", "courthse2_256", 0x00000000);
    tmpobjid = CreateDynamicObject(3431, 1841.796997, -1075.928222, 41.143707, 0.000000, 0.000000, 180.000000, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 6871, "vegascourtbld", "courthse2_256", 0x00000000);
    tmpobjid = CreateDynamicObject(3431, 1841.796997, -1077.838378, 41.143707, 0.000000, 0.000000, 180.000000, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 6871, "vegascourtbld", "courthse2_256", 0x00000000);
    tmpobjid = CreateDynamicObject(3431, 1841.796997, -1079.748291, 41.143707, 0.000000, 0.000000, 180.000000, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 6871, "vegascourtbld", "courthse2_256", 0x00000000);
    tmpobjid = CreateDynamicObject(3431, 1841.796997, -1081.648437, 41.143707, 0.000000, 0.000000, 180.000000, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 6871, "vegascourtbld", "courthse2_256", 0x00000000);
    tmpobjid = CreateDynamicObject(19448, 1849.980957, -1087.726196, 39.953788, 0.000014, -0.000022, -0.000228, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    tmpobjid = CreateDynamicObject(19448, 1849.970947, -1087.726196, 39.733760, 0.000014, -0.000022, -0.000228, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1849.861083, -1085.171020, 41.653774, -0.000022, 450.000000, 89.999870, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1849.861083, -1082.909667, 41.653774, -0.000022, 450.000000, 89.999870, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19448, 1849.970947, -1087.726196, 45.803749, 0.000014, -0.000022, -0.000228, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 10765, "airportgnd_sfse", "black64", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1849.861083, -1085.171020, 41.713783, -0.000022, 450.000000, 89.999824, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1849.861083, -1082.909667, 41.713783, -0.000022, 450.000000, 89.999824, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1850.081298, -1085.171020, 41.653774, -0.000022, 450.000000, 89.999824, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1850.081298, -1082.909667, 41.653774, -0.000022, 450.000000, 89.999824, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1850.081298, -1085.171020, 41.713783, -0.000022, 450.000000, 89.999778, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1850.081298, -1082.909667, 41.713783, -0.000022, 450.000000, 89.999778, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19448, 1850.000976, -1087.726196, 45.803749, 0.000014, -0.000022, -0.000228, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 10765, "airportgnd_sfse", "black64", 0x00000000);
    tmpobjid = CreateDynamicObject(19448, 1850.000976, -1087.726196, 39.733760, 0.000014, -0.000022, -0.000228, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19448, 1849.980957, -1100.927734, 39.953788, 0.000014, -0.000014, -0.000228, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    tmpobjid = CreateDynamicObject(19448, 1849.970947, -1100.927734, 39.733760, 0.000014, -0.000014, -0.000228, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1849.861083, -1098.372558, 41.653774, -0.000014, 450.000000, 89.999847, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1849.861083, -1096.111206, 41.653774, -0.000014, 450.000000, 89.999847, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19448, 1849.970947, -1100.927734, 45.803749, 0.000014, -0.000014, -0.000228, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 10765, "airportgnd_sfse", "black64", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1849.861083, -1098.372558, 41.713783, -0.000014, 450.000000, 89.999801, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1849.861083, -1096.111206, 41.713783, -0.000014, 450.000000, 89.999801, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1850.081298, -1098.372558, 41.653774, -0.000014, 450.000000, 89.999801, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1850.081298, -1096.111206, 41.653774, -0.000014, 450.000000, 89.999801, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1850.081298, -1098.372558, 41.713783, -0.000014, 450.000000, 89.999755, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1850.081298, -1096.111206, 41.713783, -0.000014, 450.000000, 89.999755, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19448, 1850.000976, -1100.927734, 45.803749, 0.000014, -0.000014, -0.000228, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 10765, "airportgnd_sfse", "black64", 0x00000000);
    tmpobjid = CreateDynamicObject(19448, 1849.990966, -1100.927734, 39.733760, 0.000014, -0.000014, -0.000228, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(18762, 1849.601806, -1092.071899, 43.093738, 0.000000, 0.000000, 0.000000, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(18762, 1849.601806, -1096.582397, 43.093738, 0.000000, 0.000000, 0.000000, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19398, 1847.510620, -1091.696655, 42.423759, 0.000029, -0.000014, 269.999786, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19398, 1847.510620, -1091.676635, 40.043788, 180.000030, -0.000014, 269.999786, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    tmpobjid = CreateDynamicObject(19398, 1847.510620, -1091.776733, 40.043788, 180.000030, -0.000014, 269.999786, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    tmpobjid = CreateDynamicObject(19448, 1841.159545, -1091.668945, 39.953788, 0.000022, -0.000007, 89.999717, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    tmpobjid = CreateDynamicObject(19448, 1841.159545, -1091.678955, 39.733760, 0.000022, -0.000007, 89.999717, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1838.604370, -1091.788818, 41.653774, -0.000007, 450.000000, 179.999755, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1836.343017, -1091.788818, 41.653774, -0.000007, 450.000000, 179.999755, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19448, 1841.159545, -1091.678955, 45.803749, 0.000022, -0.000007, 89.999717, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 10765, "airportgnd_sfse", "black64", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1838.604370, -1091.788818, 41.713783, -0.000007, 450.000000, 179.999710, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1836.343017, -1091.788818, 41.713783, -0.000007, 450.000000, 179.999710, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1838.604370, -1091.568603, 41.653774, -0.000007, 450.000000, 179.999710, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1836.343017, -1091.568603, 41.653774, -0.000007, 450.000000, 179.999710, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1838.604370, -1091.568603, 41.713783, -0.000007, 450.000000, 179.999664, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1836.343017, -1091.568603, 41.713783, -0.000007, 450.000000, 179.999664, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19448, 1841.159545, -1091.648925, 45.803749, 0.000022, -0.000007, 89.999717, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 10765, "airportgnd_sfse", "black64", 0x00000000);
    tmpobjid = CreateDynamicObject(19448, 1841.159545, -1091.658935, 39.733760, 0.000022, -0.000007, 89.999717, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19448, 1831.568969, -1091.668945, 39.953788, 0.000029, -0.000007, 89.999694, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    tmpobjid = CreateDynamicObject(19448, 1831.568969, -1091.678955, 39.733760, 0.000029, -0.000007, 89.999694, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1829.013793, -1091.788818, 41.653774, -0.000007, 450.000000, 179.999710, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1826.752441, -1091.788818, 41.653774, -0.000007, 450.000000, 179.999710, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19448, 1831.568969, -1091.678955, 45.803749, 0.000029, -0.000007, 89.999694, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 10765, "airportgnd_sfse", "black64", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1829.013793, -1091.788818, 41.713783, -0.000007, 450.000000, 179.999664, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1826.752441, -1091.788818, 41.713783, -0.000007, 450.000000, 179.999664, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1829.013793, -1091.568603, 41.653774, -0.000007, 450.000000, 179.999664, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1826.752441, -1091.568603, 41.653774, -0.000007, 450.000000, 179.999664, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1829.013793, -1091.568603, 41.713783, -0.000007, 450.000000, 179.999618, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1826.752441, -1091.568603, 41.713783, -0.000007, 450.000000, 179.999618, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19448, 1831.568969, -1091.648925, 45.803749, 0.000029, -0.000007, 89.999694, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 10765, "airportgnd_sfse", "black64", 0x00000000);
    tmpobjid = CreateDynamicObject(19448, 1831.568969, -1091.658935, 39.733760, 0.000029, -0.000007, 89.999694, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19398, 1847.510620, -1096.946899, 42.423759, 0.000029, -0.000014, 269.999786, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19398, 1847.510620, -1096.927246, 40.043788, 180.000030, -0.000014, 269.999786, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    tmpobjid = CreateDynamicObject(19398, 1847.510620, -1096.967285, 40.043788, 180.000030, -0.000014, 269.999786, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    tmpobjid = CreateDynamicObject(19448, 1841.101074, -1096.930175, 39.953788, 0.000037, -0.000007, 89.999671, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    tmpobjid = CreateDynamicObject(19448, 1841.101074, -1096.940185, 39.733760, 0.000037, -0.000007, 89.999671, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1838.545898, -1097.050048, 41.653774, -0.000007, 450.000000, 179.999664, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1836.284545, -1097.050048, 41.653774, -0.000007, 450.000000, 179.999664, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19448, 1841.101074, -1096.940185, 45.803749, 0.000037, -0.000007, 89.999671, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 10765, "airportgnd_sfse", "black64", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1838.545898, -1097.050048, 41.713783, -0.000007, 450.000000, 179.999618, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1836.284545, -1097.050048, 41.713783, -0.000007, 450.000000, 179.999618, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1838.545898, -1096.829833, 41.653774, -0.000007, 450.000000, 179.999618, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1836.284545, -1096.829833, 41.653774, -0.000007, 450.000000, 179.999618, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1838.545898, -1096.829833, 41.713783, -0.000007, 450.000000, 179.999572, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1836.284545, -1096.829833, 41.713783, -0.000007, 450.000000, 179.999572, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19448, 1841.101074, -1096.910156, 45.803749, 0.000037, -0.000007, 89.999671, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 10765, "airportgnd_sfse", "black64", 0x00000000);
    tmpobjid = CreateDynamicObject(19448, 1841.101074, -1096.920166, 39.733760, 0.000037, -0.000007, 89.999671, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19448, 1831.551269, -1096.930175, 39.953788, 0.000045, -0.000007, 89.999649, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    tmpobjid = CreateDynamicObject(19448, 1831.551269, -1096.940185, 39.733760, 0.000045, -0.000007, 89.999649, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1828.996093, -1097.050048, 41.653774, -0.000007, 450.000000, 179.999618, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1826.734741, -1097.050048, 41.653774, -0.000007, 450.000000, 179.999618, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19448, 1831.551269, -1096.940185, 45.803749, 0.000045, -0.000007, 89.999649, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 10765, "airportgnd_sfse", "black64", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1828.996093, -1097.050048, 41.713783, -0.000007, 450.000000, 179.999572, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1826.734741, -1097.050048, 41.713783, -0.000007, 450.000000, 179.999572, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1828.996093, -1096.829833, 41.653774, -0.000007, 450.000000, 179.999572, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1826.734741, -1096.829833, 41.653774, -0.000007, 450.000000, 179.999572, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1828.996093, -1096.829833, 41.713783, -0.000007, 450.000000, 179.999526, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1826.734741, -1096.829833, 41.713783, -0.000007, 450.000000, 179.999526, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19448, 1831.551269, -1096.910156, 45.803749, 0.000045, -0.000007, 89.999649, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 10765, "airportgnd_sfse", "black64", 0x00000000);
    tmpobjid = CreateDynamicObject(19448, 1831.551269, -1096.920166, 39.733760, 0.000045, -0.000007, 89.999649, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(18762, 1850.242309, -1082.812011, 43.093738, 0.000000, 0.000000, 0.000000, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(18762, 1850.242309, -1076.791137, 43.093738, 0.000000, 0.000000, 0.000000, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19398, 1841.390625, -1071.436889, 42.423759, 0.000029, -0.000014, 179.999786, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19398, 1841.491210, -1071.456787, 40.023757, 180.000030, -0.000014, 179.999786, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    tmpobjid = CreateDynamicObject(19398, 1841.361083, -1071.456787, 40.023757, 180.000030, -0.000014, 179.999786, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    tmpobjid = CreateDynamicObject(19435, 1841.381347, -1069.076538, 42.383712, 0.000000, 0.000000, 0.000000, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(974, 1841.383666, -1079.671630, 45.993701, 180.000000, 0.000000, 90.000000, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 1, 19278, "skydiveplatforms", "chromegrill8", 0x00000000);
    tmpobjid = CreateDynamicObject(974, 1841.383666, -1073.001098, 45.993701, 180.000000, 0.000000, 90.000000, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 1, 19278, "skydiveplatforms", "chromegrill8", 0x00000000);
    tmpobjid = CreateDynamicObject(19369, 1836.490234, -1103.731933, 41.533718, 0.000000, 0.000000, 0.000000, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15040, "cuntcuts", "AH_pinkcurtain", 0x00000000);
    tmpobjid = CreateDynamicObject(19369, 1842.132324, -1103.731933, 41.533718, 0.000000, 0.000007, 0.000000, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15040, "cuntcuts", "AH_pinkcurtain", 0x00000000);
    tmpobjid = CreateDynamicObject(19369, 1847.703369, -1103.731933, 41.533718, 0.000000, 0.000014, 0.000000, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15040, "cuntcuts", "AH_pinkcurtain", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1839.296142, -1096.884521, 44.193721, 0.000000, 0.000000, 0.000000, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 10765, "airportgnd_sfse", "black64", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1832.645019, -1096.884521, 44.193721, 0.000000, 0.000000, 0.000000, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 10765, "airportgnd_sfse", "black64", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1839.296142, -1091.723999, 44.193721, 0.000000, 0.000000, 0.000000, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 10765, "airportgnd_sfse", "black64", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1832.645019, -1091.723144, 44.193721, 0.000000, 0.000000, 0.000000, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 10765, "airportgnd_sfse", "black64", 0x00000000);
    tmpobjid = CreateDynamicObject(19369, 1849.276855, -1084.961181, 41.533718, 0.000000, 0.000007, 179.999847, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15040, "cuntcuts", "AH_pinkcurtain", 0x00000000);
    tmpobjid = CreateDynamicObject(19369, 1843.616088, -1084.961181, 41.533718, 0.000000, 0.000000, 179.999801, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15040, "cuntcuts", "AH_pinkcurtain", 0x00000000);
    tmpobjid = CreateDynamicObject(19369, 1837.205566, -1084.961181, 41.533718, 0.000000, -0.000007, 179.999755, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15040, "cuntcuts", "AH_pinkcurtain", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1849.945556, -1098.964965, 44.513710, 0.000000, 0.000000, 0.000000, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 10765, "airportgnd_sfse", "black64", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1849.945556, -1102.785278, 44.513710, 0.000000, 0.000000, 0.000000, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 10765, "airportgnd_sfse", "black64", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1849.945556, -1089.674804, 44.513710, 0.000000, 0.000000, 0.000000, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 10765, "airportgnd_sfse", "black64", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1849.945556, -1085.904052, 44.513710, 0.000000, 0.000000, 0.000000, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 10765, "airportgnd_sfse", "black64", 0x00000000);
    tmpobjid = CreateDynamicObject(19378, 1854.912353, -1116.191284, 40.567787, 0.000022, 90.000000, 89.999931, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 19597, "lsbeachside", "ceilingtiles4-128x128", 0x00000000);
    tmpobjid = CreateDynamicObject(19378, 1845.281738, -1116.211791, 40.567787, 0.000022, 90.000000, 89.999931, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 19597, "lsbeachside", "ceilingtiles4-128x128", 0x00000000);
    tmpobjid = CreateDynamicObject(19378, 1835.651733, -1116.211791, 40.567787, 0.000022, 90.000000, 89.999931, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 19597, "lsbeachside", "ceilingtiles4-128x128", 0x00000000);
    tmpobjid = CreateDynamicObject(19448, 1859.005615, -1110.454589, 42.418754, 0.000000, 0.000000, -0.000037, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    tmpobjid = CreateDynamicObject(19448, 1858.995605, -1110.454589, 39.738761, 0.000000, 0.000000, -0.000037, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1858.885742, -1107.899414, 41.658775, 0.000000, 450.000000, 89.999938, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1858.885742, -1105.638061, 41.658775, 0.000000, 450.000000, 89.999938, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19448, 1858.995605, -1110.454589, 45.808750, 0.000000, 0.000000, -0.000037, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 10765, "airportgnd_sfse", "black64", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1858.885742, -1107.899414, 41.718784, 0.000000, 450.000000, 89.999893, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1858.885742, -1105.638061, 41.718784, 0.000000, 450.000000, 89.999893, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19448, 1859.005615, -1120.073852, 42.418754, 0.000000, 0.000007, -0.000037, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    tmpobjid = CreateDynamicObject(19448, 1858.995605, -1120.073852, 39.738761, 0.000000, 0.000007, -0.000037, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1858.885742, -1117.518676, 41.658775, 0.000007, 450.000000, 89.999916, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1858.885742, -1115.257324, 41.658775, 0.000007, 450.000000, 89.999916, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19448, 1858.995605, -1120.073852, 45.808750, 0.000000, 0.000007, -0.000037, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 10765, "airportgnd_sfse", "black64", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1858.885742, -1117.518676, 41.718784, 0.000007, 450.000000, 89.999870, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1858.885742, -1115.257324, 41.718784, 0.000007, 450.000000, 89.999870, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19448, 1854.137451, -1119.835815, 42.418754, -0.000007, 0.000014, -89.999916, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    tmpobjid = CreateDynamicObject(19448, 1854.137451, -1119.825805, 39.738761, -0.000007, 0.000014, -89.999916, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1856.692626, -1119.715942, 41.658775, 0.000014, 450.000000, -0.000080, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1858.953979, -1119.715942, 41.658775, 0.000014, 450.000000, -0.000080, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19448, 1854.137451, -1119.825805, 45.808750, -0.000007, 0.000014, -89.999916, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 10765, "airportgnd_sfse", "black64", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1856.692626, -1119.715942, 41.718784, 0.000014, 450.000000, -0.000127, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1858.953979, -1119.715942, 41.718784, 0.000014, 450.000000, -0.000127, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19448, 1844.538208, -1119.835815, 42.418754, -0.000014, 0.000014, -89.999893, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    tmpobjid = CreateDynamicObject(19448, 1844.538208, -1119.825805, 39.738761, -0.000014, 0.000014, -89.999893, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1847.093383, -1119.715942, 41.658775, 0.000014, 450.000000, -0.000080, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1849.354736, -1119.715942, 41.658775, 0.000014, 450.000000, -0.000080, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19448, 1844.538208, -1119.825805, 45.808750, -0.000014, 0.000014, -89.999893, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 10765, "airportgnd_sfse", "black64", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1847.093383, -1119.715942, 41.718784, 0.000014, 450.000000, -0.000127, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1849.354736, -1119.715942, 41.718784, 0.000014, 450.000000, -0.000127, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19448, 1834.978881, -1119.835815, 42.418754, -0.000022, 0.000014, -89.999870, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    tmpobjid = CreateDynamicObject(19448, 1834.978881, -1119.825805, 39.738761, -0.000022, 0.000014, -89.999870, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1837.534057, -1119.715942, 41.658775, 0.000014, 450.000000, -0.000080, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1839.795410, -1119.715942, 41.658775, 0.000014, 450.000000, -0.000080, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19448, 1834.978881, -1119.825805, 45.808750, -0.000022, 0.000014, -89.999870, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 10765, "airportgnd_sfse", "black64", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1837.534057, -1119.715942, 41.718784, 0.000014, 450.000000, -0.000127, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1839.795410, -1119.715942, 41.718784, 0.000014, 450.000000, -0.000127, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19448, 1831.477783, -1110.546142, 42.418754, -0.000029, 0.000007, -179.999771, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    tmpobjid = CreateDynamicObject(19448, 1831.487792, -1110.546142, 39.738761, -0.000029, 0.000007, -179.999771, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1831.597656, -1113.101318, 41.658775, 0.000007, 450.000000, -90.000030, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1831.597656, -1115.362670, 41.658775, 0.000007, 450.000000, -90.000030, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19448, 1831.487792, -1110.546142, 45.808750, -0.000029, 0.000007, -179.999771, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 10765, "airportgnd_sfse", "black64", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1831.597656, -1113.101318, 41.718784, 0.000007, 450.000000, -90.000076, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1831.597656, -1115.362670, 41.718784, 0.000007, 450.000000, -90.000076, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19448, 1831.477783, -1120.167114, 42.418754, -0.000029, 0.000000, -179.999725, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    tmpobjid = CreateDynamicObject(19448, 1831.487792, -1120.167114, 39.738761, -0.000029, 0.000000, -179.999725, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1831.597656, -1122.722290, 41.658775, 0.000000, 450.000000, -90.000007, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1831.597656, -1124.983642, 41.658775, 0.000000, 450.000000, -90.000007, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19448, 1831.487792, -1120.167114, 45.808750, -0.000029, 0.000000, -179.999725, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 10765, "airportgnd_sfse", "black64", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1831.597656, -1122.722290, 41.718784, 0.000000, 450.000000, -90.000053, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1831.597656, -1124.983642, 41.718784, 0.000000, 450.000000, -90.000053, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19378, 1855.072509, -1116.243530, 44.257804, 0.000037, 90.000000, 89.999885, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 3922, "bistro", "Marble2", 0x00000000);
    tmpobjid = CreateDynamicObject(19378, 1845.463134, -1116.243530, 44.257804, 0.000037, 90.000000, 89.999885, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 3922, "bistro", "Marble2", 0x00000000);
    tmpobjid = CreateDynamicObject(19378, 1835.833374, -1116.243530, 44.257804, 0.000037, 90.000000, 89.999885, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 3922, "bistro", "Marble2", 0x00000000);
    tmpobjid = CreateDynamicObject(19448, 1850.872436, -1105.729370, 39.738761, -0.000037, 0.000000, 90.000205, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1848.317260, -1105.839233, 41.658775, 0.000000, 450.000000, 179.999862, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1846.055908, -1105.839233, 41.658775, 0.000000, 450.000000, 179.999862, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19448, 1850.872436, -1105.729370, 45.808750, -0.000037, 0.000000, 90.000205, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 10765, "airportgnd_sfse", "black64", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1848.317260, -1105.839233, 41.718784, 0.000000, 450.000000, 179.999816, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1846.055908, -1105.839233, 41.718784, 0.000000, 450.000000, 179.999816, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19448, 1841.242187, -1105.729370, 39.738761, -0.000029, 0.000000, 90.000183, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1838.687011, -1105.839233, 41.658775, 0.000000, 450.000000, 179.999816, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1836.425659, -1105.839233, 41.658775, 0.000000, 450.000000, 179.999816, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19448, 1841.242187, -1105.729370, 45.808750, -0.000029, 0.000000, 90.000183, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 10765, "airportgnd_sfse", "black64", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1838.687011, -1105.839233, 41.718784, 0.000000, 450.000000, 179.999771, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1836.425659, -1105.839233, 41.718784, 0.000000, 450.000000, 179.999771, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19448, 1831.643432, -1105.729370, 39.738761, -0.000022, 0.000000, 90.000160, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1829.088256, -1105.839233, 41.658775, 0.000000, 450.000000, 179.999771, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1826.826904, -1105.839233, 41.658775, 0.000000, 450.000000, 179.999771, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19448, 1831.643432, -1105.729370, 45.808750, -0.000022, 0.000000, 90.000160, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 10765, "airportgnd_sfse", "black64", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1829.088256, -1105.839233, 41.718784, 0.000000, 450.000000, 179.999725, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1826.826904, -1105.839233, 41.718784, 0.000000, 450.000000, 179.999725, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(18762, 1855.222167, -1105.753784, 43.093738, 0.000000, 0.000000, 0.000000, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19448, 1840.400146, -1115.004760, 39.738761, -0.000014, -0.000007, -179.999755, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1840.510009, -1117.559936, 41.658775, -0.000007, 450.000000, -90.000190, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1840.510009, -1119.821289, 41.658775, -0.000007, 450.000000, -90.000190, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19448, 1840.400146, -1115.004760, 45.808750, -0.000014, -0.000007, -179.999755, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 10765, "airportgnd_sfse", "black64", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1840.510009, -1117.559936, 41.718784, -0.000007, 450.000000, -90.000236, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1840.510009, -1119.821289, 41.718784, -0.000007, 450.000000, -90.000236, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19448, 1840.399536, -1115.013671, 42.418754, -0.000022, 0.000014, 0.000127, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    tmpobjid = CreateDynamicObject(19448, 1840.389892, -1115.161865, 39.738761, -0.000014, -0.000007, 0.000228, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1840.280029, -1112.606689, 41.658775, -0.000007, 450.000000, 89.999748, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1840.280029, -1110.345336, 41.658775, -0.000007, 450.000000, 89.999748, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19448, 1840.389892, -1115.161865, 45.808750, -0.000014, -0.000007, 0.000228, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 10765, "airportgnd_sfse", "black64", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1840.280029, -1112.606689, 41.718784, -0.000007, 450.000000, 89.999702, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1840.280029, -1110.345336, 41.718784, -0.000007, 450.000000, 89.999702, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(18762, 1840.332031, -1110.234863, 43.093738, 0.000000, 0.000000, 0.000000, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(18762, 1840.332031, -1106.265136, 43.093738, 0.000000, 0.000000, 0.000000, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19448, 1845.230834, -1111.927856, 39.738761, -0.000014, 0.000000, -89.999771, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1847.786010, -1111.817993, 41.658775, 0.000000, 450.000000, -0.000319, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1850.047363, -1111.817993, 41.658775, 0.000000, 450.000000, -0.000319, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19448, 1845.230834, -1111.927856, 45.808750, -0.000014, 0.000000, -89.999771, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 10765, "airportgnd_sfse", "black64", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1847.786010, -1111.817993, 41.718784, 0.000000, 450.000000, -0.000365, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1850.047363, -1111.817993, 41.718784, 0.000000, 450.000000, -0.000365, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19448, 1857.331420, -1111.927856, 39.738761, -0.000022, 0.000000, -89.999748, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1859.886596, -1111.817993, 41.658775, 0.000000, 450.000000, -0.000319, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1862.147949, -1111.817993, 41.658775, 0.000000, 450.000000, -0.000319, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19448, 1857.331420, -1111.927856, 45.808750, -0.000022, 0.000000, -89.999748, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 10765, "airportgnd_sfse", "black64", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1859.886596, -1111.817993, 41.718784, 0.000000, 450.000000, -0.000365, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1862.147949, -1111.817993, 41.718784, 0.000000, 450.000000, -0.000365, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19448, 1845.222045, -1111.932983, 39.998764, -0.000022, 0.000014, 90.000129, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    tmpobjid = CreateDynamicObject(19448, 1857.332153, -1111.932983, 39.998764, -0.000022, 0.000014, 90.000129, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    tmpobjid = CreateDynamicObject(19448, 1857.337280, -1111.978149, 39.738761, -0.000022, 0.000000, 90.000190, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1854.782104, -1112.088012, 41.658775, 0.000000, 450.000000, 179.999572, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1852.520751, -1112.088012, 41.658775, 0.000000, 450.000000, 179.999572, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19448, 1857.337280, -1111.978149, 45.808750, -0.000022, 0.000000, 90.000190, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 10765, "airportgnd_sfse", "black64", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1854.782104, -1112.088012, 41.718784, 0.000000, 450.000000, 179.999526, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1852.520751, -1112.088012, 41.718784, 0.000000, 450.000000, 179.999526, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19448, 1845.197387, -1111.978149, 39.738761, -0.000014, 0.000000, 90.000167, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1842.642211, -1112.088012, 41.658775, 0.000000, 450.000000, 179.999526, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1840.380859, -1112.088012, 41.658775, 0.000000, 450.000000, 179.999526, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19448, 1845.197387, -1111.978149, 45.808750, -0.000014, 0.000000, 90.000167, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 10765, "airportgnd_sfse", "black64", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1842.642211, -1112.088012, 41.718784, 0.000000, 450.000000, 179.999481, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1840.380859, -1112.088012, 41.718784, 0.000000, 450.000000, 179.999481, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19398, 1851.330688, -1111.917724, 42.423759, 0.000029, -0.000014, 269.999786, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15041, "bigsfsave", "ah_greencarp", 0x00000000);
    tmpobjid = CreateDynamicObject(19398, 1851.330688, -1111.897705, 39.983757, 180.000030, -0.000014, 269.999786, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    tmpobjid = CreateDynamicObject(19398, 1851.330688, -1111.937744, 39.983757, 180.000030, -0.000014, 269.999786, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    tmpobjid = CreateDynamicObject(1499, 1846.762084, -1096.984252, 40.653724, 0.000000, 0.000000, 360.000000, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 18641, "flashlight1", "metalblack1-2", 0x00000000);
    SetDynamicObjectMaterial(tmpobjid, 1, 18889, "forcefields", "glass1", 0x00000000);
    tmpobjid = CreateDynamicObject(1499, 1846.772094, -1091.714111, 40.653724, 0.000000, 0.000000, 360.000000, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 18641, "flashlight1", "metalblack1-2", 0x00000000);
    SetDynamicObjectMaterial(tmpobjid, 1, 18889, "forcefields", "glass1", 0x00000000);
    tmpobjid = CreateDynamicObject(1499, 1836.410522, -1072.453369, 40.653724, 0.000000, 0.000000, 450.000000, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 18641, "flashlight1", "metalblack1-2", 0x00000000);
    SetDynamicObjectMaterial(tmpobjid, 1, 18889, "forcefields", "glass1", 0x00000000);
    tmpobjid = CreateDynamicObject(19369, 1845.391601, -1117.843627, 41.533718, 0.000000, 0.000007, 0.000000, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15040, "cuntcuts", "AH_pinkcurtain", 0x00000000);
    tmpobjid = CreateDynamicObject(19369, 1850.692871, -1117.843627, 41.533718, 0.000000, 0.000014, 0.000000, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15040, "cuntcuts", "AH_pinkcurtain", 0x00000000);
    tmpobjid = CreateDynamicObject(19369, 1856.292602, -1117.843627, 41.533718, 0.000000, 0.000022, 0.000000, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15040, "cuntcuts", "AH_pinkcurtain", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1847.075561, -1111.957397, 44.453723, 0.000000, 0.000000, 0.000000, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 10765, "airportgnd_sfse", "black64", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1843.375122, -1111.957397, 44.453723, 0.000000, 0.000000, 0.000000, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 10765, "airportgnd_sfse", "black64", 0x00000000);
    tmpobjid = CreateDynamicObject(19089, 1856.027587, -1111.957397, 44.453723, 0.000000, 0.000000, 0.000000, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 10765, "airportgnd_sfse", "black64", 0x00000000);
    tmpobjid = CreateDynamicObject(19369, 1833.740478, -1115.326293, 41.573719, 0.000007, 0.000029, 89.999946, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15040, "cuntcuts", "AH_pinkcurtain", 0x00000000);
    tmpobjid = CreateDynamicObject(19369, 1838.510742, -1115.326293, 41.573719, 0.000014, 0.000029, 89.999923, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15040, "cuntcuts", "AH_pinkcurtain", 0x00000000);
    tmpobjid = CreateDynamicObject(19369, 1833.740478, -1110.624145, 41.573719, 0.000014, 0.000029, 89.999923, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15040, "cuntcuts", "AH_pinkcurtain", 0x00000000);
    tmpobjid = CreateDynamicObject(19369, 1838.510742, -1110.624145, 41.573719, 0.000022, 0.000029, 89.999900, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 15040, "cuntcuts", "AH_pinkcurtain", 0x00000000);
    tmpobjid = CreateDynamicObject(3657, 1843.109008, -1111.387084, 41.163707, 0.000000, 0.000000, 180.000000, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 1, 1968, "dinerseat2", "donut_seat1", 0x00000000);
    tmpobjid = CreateDynamicObject(3657, 1847.949096, -1111.387084, 41.163707, 0.000000, 0.000000, 180.000000, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 1, 1968, "dinerseat2", "donut_seat1", 0x00000000);
    tmpobjid = CreateDynamicObject(3657, 1850.501098, -1101.875732, 41.163707, 0.000000, -0.000007, 449.999938, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 1, 1968, "dinerseat2", "donut_seat1", 0x00000000);
    tmpobjid = CreateDynamicObject(3657, 1852.620605, -1105.046508, 41.163707, 0.000000, -0.000007, 179.999954, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 1, 1968, "dinerseat2", "donut_seat1", 0x00000000);
    tmpobjid = CreateDynamicObject(3657, 1852.620605, -1098.666015, 41.163707, 0.000000, -0.000007, 359.999938, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 1, 1968, "dinerseat2", "donut_seat1", 0x00000000);
    tmpobjid = CreateDynamicObject(3657, 1850.501098, -1087.384887, 41.163707, 0.000007, -0.000007, 89.999916, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 1, 1968, "dinerseat2", "donut_seat1", 0x00000000);
    tmpobjid = CreateDynamicObject(3657, 1852.620605, -1090.555664, 41.163707, 0.000000, -0.000014, 179.999908, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 1, 1968, "dinerseat2", "donut_seat1", 0x00000000);
    tmpobjid = CreateDynamicObject(3657, 1852.620605, -1084.175170, 41.163707, 0.000000, 0.000000, -0.000059, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 1, 1968, "dinerseat2", "donut_seat1", 0x00000000);
    tmpobjid = CreateDynamicObject(3657, 1843.560058, -1096.437133, 41.163707, 0.000000, -0.000007, 179.999954, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 1, 1968, "dinerseat2", "donut_seat1", 0x00000000);
    tmpobjid = CreateDynamicObject(3657, 1836.679321, -1096.437133, 41.163707, 0.000000, -0.000007, 179.999954, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 1, 1968, "dinerseat2", "donut_seat1", 0x00000000);
    tmpobjid = CreateDynamicObject(3657, 1836.679199, -1092.156494, 41.163707, 0.000000, -0.000007, -0.000059, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 1, 1968, "dinerseat2", "donut_seat1", 0x00000000);
    tmpobjid = CreateDynamicObject(3657, 1843.559936, -1092.156494, 41.163707, 0.000000, -0.000007, -0.000059, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 1, 1968, "dinerseat2", "donut_seat1", 0x00000000);
    tmpobjid = CreateDynamicObject(19372, 1850.081176, -1071.675415, 42.353721, 0.000000, 0.000000, 0.000000, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 7009, "vgndwntwn1", "vgnbankbld6_256", 0x00000000);
    tmpobjid = CreateDynamicObject(19372, 1850.081176, -1074.875854, 42.353721, 0.000000, 0.000000, 0.000000, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 7009, "vgndwntwn1", "vgnbankbld5_256", 0x00000000);
    tmpobjid = CreateDynamicObject(19372, 1850.081176, -1068.456909, 42.353721, 0.000000, 0.000000, 0.000000, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 7009, "vgndwntwn1", "vgnbankbld5_256", 0x00000000);
    tmpobjid = CreateDynamicObject(2257, 1858.907958, -1080.085937, 42.913707, 0.000000, 0.000000, 270.000000, -1, 1, -1, 300.00, 100.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 3899, "hospital2", "hospitalboard_128a", 0x00000000);
    SetDynamicObjectMaterial(tmpobjid, 1, 3899, "hospital2", "hospitalboard_128a", 0x00000000);
    tmpobjid = CreateDynamicObject(19325, 1849.943237, -1099.444824, 42.503711, 0.000000, 0.000000, 0.000000, -1, 1, -1, 300.00, 100.00); 
    tmpobjid = CreateDynamicObject(19325, 1849.943237, -1102.273559, 42.503711, 0.000000, 0.000000, 0.000000, -1, 1, -1, 300.00, 100.00); 
    tmpobjid = CreateDynamicObject(19325, 1849.943237, -1086.364257, 42.503711, 0.000000, 0.000000, 0.000000, -1, 1, -1, 300.00, 100.00); 
    tmpobjid = CreateDynamicObject(19325, 1849.943237, -1089.234741, 42.503711, 0.000000, 0.000000, 0.000000, -1, 1, -1, 300.00, 100.00); 
    tmpobjid = CreateDynamicObject(19325, 1842.595214, -1091.722167, 42.943714, 0.000000, 0.000000, 90.000000, -1, 1, -1, 300.00, 100.00); 
    tmpobjid = CreateDynamicObject(19325, 1835.974853, -1091.722167, 42.943714, 0.000000, 0.000000, 90.000000, -1, 1, -1, 300.00, 100.00); 
    tmpobjid = CreateDynamicObject(19325, 1829.334350, -1091.722167, 42.943714, 0.000000, 0.000000, 90.000000, -1, 1, -1, 300.00, 100.00); 
    tmpobjid = CreateDynamicObject(19325, 1842.595214, -1096.881347, 42.943714, 0.000000, 0.000000, 90.000000, -1, 1, -1, 300.00, 100.00); 
    tmpobjid = CreateDynamicObject(19325, 1835.965454, -1096.881347, 42.943714, 0.000000, 0.000000, 90.000000, -1, 1, -1, 300.00, 100.00); 
    tmpobjid = CreateDynamicObject(19325, 1829.325195, -1096.881347, 42.943714, 0.000000, 0.000000, 90.000000, -1, 1, -1, 300.00, 100.00); 
    tmpobjid = CreateDynamicObject(2566, 1835.181396, -1103.081176, 41.143718, 0.000000, 0.000000, 180.000000, -1, 1, -1, 300.00, 100.00); 
    tmpobjid = CreateDynamicObject(2372, 1836.743774, -1103.767944, 44.203723, 180.000000, 0.000000, 0.000000, -1, 1, -1, 300.00, 100.00); 
    tmpobjid = CreateDynamicObject(2372, 1836.743774, -1102.467041, 44.203723, 180.000000, 0.000000, 0.000000, -1, 1, -1, 300.00, 100.00); 
    tmpobjid = CreateDynamicObject(2566, 1840.823486, -1103.081176, 41.143718, 0.000000, -0.000007, 179.999954, -1, 1, -1, 300.00, 100.00); 
    tmpobjid = CreateDynamicObject(2372, 1842.385864, -1103.767944, 44.203723, 0.000000, 179.999984, -179.999984, -1, 1, -1, 300.00, 100.00); 
    tmpobjid = CreateDynamicObject(2372, 1842.385864, -1102.467041, 44.203723, 0.000000, 179.999984, -179.999984, -1, 1, -1, 300.00, 100.00); 
    tmpobjid = CreateDynamicObject(2566, 1846.394531, -1103.081176, 41.143718, 0.000000, -0.000014, 179.999908, -1, 1, -1, 300.00, 100.00); 
    tmpobjid = CreateDynamicObject(2372, 1847.956909, -1103.767944, 44.203723, 0.000000, 179.999984, -179.999938, -1, 1, -1, 300.00, 100.00); 
    tmpobjid = CreateDynamicObject(2372, 1847.956909, -1102.467041, 44.203723, 0.000000, 179.999984, -179.999938, -1, 1, -1, 300.00, 100.00); 
    tmpobjid = CreateDynamicObject(2566, 1844.925292, -1085.611938, 41.143718, 0.000000, -0.000014, -0.000103, -1, 1, -1, 300.00, 100.00); 
    tmpobjid = CreateDynamicObject(2372, 1849.023315, -1084.925170, 44.203723, 0.000000, 179.999984, 0.000045, -1, 1, -1, 300.00, 100.00); 
    tmpobjid = CreateDynamicObject(2372, 1849.023315, -1086.226074, 44.203723, 0.000000, 179.999984, 0.000045, -1, 1, -1, 300.00, 100.00); 
    tmpobjid = CreateDynamicObject(2566, 1839.264526, -1085.611938, 41.143718, 0.000000, -0.000007, -0.000103, -1, 1, -1, 300.00, 100.00); 
    tmpobjid = CreateDynamicObject(2372, 1843.362548, -1084.925170, 44.203723, 0.000000, 179.999984, 0.000045, -1, 1, -1, 300.00, 100.00); 
    tmpobjid = CreateDynamicObject(2372, 1843.362548, -1086.226074, 44.203723, 0.000000, 179.999984, 0.000045, -1, 1, -1, 300.00, 100.00); 
    tmpobjid = CreateDynamicObject(2566, 1832.854003, -1085.611938, 41.143718, 0.000000, 0.000000, -0.000103, -1, 1, -1, 300.00, 100.00); 
    tmpobjid = CreateDynamicObject(2372, 1836.952026, -1084.925170, 44.203723, 0.000000, 179.999984, 0.000045, -1, 1, -1, 300.00, 100.00); 
    tmpobjid = CreateDynamicObject(2372, 1836.952026, -1086.226074, 44.203723, 0.000000, 179.999984, 0.000045, -1, 1, -1, 300.00, 100.00); 
    tmpobjid = CreateDynamicObject(19325, 1840.472534, -1109.960815, 45.213726, 0.000000, 0.000000, 0.000000, -1, 1, -1, 300.00, 100.00); 
    tmpobjid = CreateDynamicObject(1897, 1840.480957, -1107.076538, 43.473720, 90.000000, 0.000000, 180.000000, -1, 1, -1, 300.00, 100.00); 
    tmpobjid = CreateDynamicObject(1897, 1840.480957, -1109.296630, 43.473720, 90.000000, 0.000000, 180.000000, -1, 1, -1, 300.00, 100.00); 
    tmpobjid = CreateDynamicObject(1897, 1840.480957, -1109.296630, 43.733722, 90.000000, 0.000000, 180.000000, -1, 1, -1, 300.00, 100.00); 
    tmpobjid = CreateDynamicObject(1897, 1840.480957, -1107.086669, 43.733722, 90.000000, 0.000000, 180.000000, -1, 1, -1, 300.00, 100.00); 
    tmpobjid = CreateDynamicObject(1897, 1840.480957, -1107.086669, 44.043724, 90.000000, 0.000000, 180.000000, -1, 1, -1, 300.00, 100.00); 
    tmpobjid = CreateDynamicObject(1897, 1840.480957, -1109.306274, 44.043724, 90.000000, 0.000000, 180.000000, -1, 1, -1, 300.00, 100.00); 
    tmpobjid = CreateDynamicObject(1897, 1840.480957, -1108.116088, 44.273715, 360.000000, 0.000000, 540.000000, -1, 1, -1, 300.00, 100.00); 
    tmpobjid = CreateDynamicObject(19325, 1843.753051, -1111.954223, 42.673725, 0.000000, 0.000000, 90.000000, -1, 1, -1, 300.00, 100.00); 
    tmpobjid = CreateDynamicObject(19325, 1846.703735, -1111.954223, 42.673725, 0.000000, 0.000000, 90.000000, -1, 1, -1, 300.00, 100.00); 
    tmpobjid = CreateDynamicObject(19325, 1855.843383, -1111.954223, 42.673725, 0.000000, 0.000000, 90.000000, -1, 1, -1, 300.00, 100.00); 
    tmpobjid = CreateDynamicObject(2566, 1844.082763, -1117.192871, 41.143718, 0.000000, -0.000007, 179.999954, -1, 1, -1, 300.00, 100.00); 
    tmpobjid = CreateDynamicObject(2372, 1845.645141, -1117.879638, 44.203723, 0.000000, 179.999984, -179.999984, -1, 1, -1, 300.00, 100.00); 
    tmpobjid = CreateDynamicObject(2372, 1845.645141, -1116.578735, 44.203723, 0.000000, 179.999984, -179.999984, -1, 1, -1, 300.00, 100.00); 
    tmpobjid = CreateDynamicObject(2566, 1849.384033, -1117.192871, 41.143718, 0.000000, -0.000014, 179.999908, -1, 1, -1, 300.00, 100.00); 
    tmpobjid = CreateDynamicObject(2372, 1850.946411, -1117.879638, 44.203723, 0.000000, 179.999984, -179.999938, -1, 1, -1, 300.00, 100.00); 
    tmpobjid = CreateDynamicObject(2372, 1850.946411, -1116.578735, 44.203723, 0.000000, 179.999984, -179.999938, -1, 1, -1, 300.00, 100.00); 
    tmpobjid = CreateDynamicObject(2566, 1854.983764, -1117.192871, 41.143718, 0.000000, -0.000022, 179.999862, -1, 1, -1, 300.00, 100.00); 
    tmpobjid = CreateDynamicObject(2372, 1856.546142, -1117.879638, 44.203723, 0.000000, 179.999984, -179.999893, -1, 1, -1, 300.00, 100.00); 
    tmpobjid = CreateDynamicObject(2372, 1856.546142, -1116.578735, 44.203723, 0.000000, 179.999984, -179.999893, -1, 1, -1, 300.00, 100.00); 
    tmpobjid = CreateDynamicObject(1997, 1833.648071, -1116.616943, 40.653724, 0.000000, 0.000000, 90.000000, -1, 1, -1, 300.00, 100.00); 
    tmpobjid = CreateDynamicObject(2372, 1838.546752, -1115.072753, 44.243724, -0.000014, 179.999984, -89.999832, -1, 1, -1, 300.00, 100.00); 
    tmpobjid = CreateDynamicObject(2372, 1833.776489, -1115.072753, 44.243724, -0.000007, 179.999984, -89.999855, -1, 1, -1, 300.00, 100.00); 
    tmpobjid = CreateDynamicObject(2372, 1832.475585, -1115.072753, 44.243724, -0.000007, 179.999984, -89.999855, -1, 1, -1, 300.00, 100.00); 
    tmpobjid = CreateDynamicObject(2372, 1837.245849, -1115.072753, 44.243724, -0.000014, 179.999984, -89.999832, -1, 1, -1, 300.00, 100.00); 
    tmpobjid = CreateDynamicObject(3396, 1839.518432, -1117.578735, 40.653724, 0.000000, 0.000000, 0.000000, -1, 1, -1, 300.00, 100.00); 
    tmpobjid = CreateDynamicObject(3386, 1832.951293, -1119.336059, 40.653724, 0.000000, 0.000000, 270.000000, -1, 1, -1, 300.00, 100.00); 
    tmpobjid = CreateDynamicObject(3388, 1833.962280, -1119.349365, 40.653724, 0.000000, 0.000000, 270.000000, -1, 1, -1, 300.00, 100.00); 
    tmpobjid = CreateDynamicObject(1744, 1831.425048, -1118.280639, 41.473731, 0.000000, 0.000000, 450.000000, -1, 1, -1, 300.00, 100.00); 
    tmpobjid = CreateDynamicObject(11738, 1831.784179, -1118.503662, 41.833721, 0.000000, 0.000000, 0.000000, -1, 1, -1, 300.00, 100.00); 
    tmpobjid = CreateDynamicObject(11738, 1831.784179, -1118.313598, 41.833721, 0.000000, 0.000000, 0.000000, -1, 1, -1, 300.00, 100.00); 
    tmpobjid = CreateDynamicObject(1997, 1833.648071, -1111.914794, 40.653724, 0.000007, 0.000000, 89.999977, -1, 1, -1, 300.00, 100.00); 
    tmpobjid = CreateDynamicObject(2372, 1838.546752, -1110.370605, 44.243724, -0.000022, 179.999984, -89.999809, -1, 1, -1, 300.00, 100.00); 
    tmpobjid = CreateDynamicObject(2372, 1833.776489, -1110.370605, 44.243724, -0.000014, 179.999984, -89.999832, -1, 1, -1, 300.00, 100.00); 
    tmpobjid = CreateDynamicObject(2372, 1832.475585, -1110.370605, 44.243724, -0.000014, 179.999984, -89.999832, -1, 1, -1, 300.00, 100.00); 
    tmpobjid = CreateDynamicObject(2372, 1837.245849, -1110.370605, 44.243724, -0.000022, 179.999984, -89.999809, -1, 1, -1, 300.00, 100.00); 
    tmpobjid = CreateDynamicObject(3396, 1839.518432, -1112.876586, 40.653724, 0.000000, 0.000007, 0.000000, -1, 1, -1, 300.00, 100.00); 
    tmpobjid = CreateDynamicObject(3386, 1832.951293, -1114.633911, 40.653724, -0.000007, 0.000000, -89.999977, -1, 1, -1, 300.00, 100.00); 
    tmpobjid = CreateDynamicObject(3388, 1833.962280, -1114.647216, 40.653724, -0.000007, 0.000000, -89.999977, -1, 1, -1, 300.00, 100.00); 
    tmpobjid = CreateDynamicObject(1744, 1831.425048, -1113.578491, 41.473731, 0.000007, 0.000000, 89.999977, -1, 1, -1, 300.00, 100.00); 
    tmpobjid = CreateDynamicObject(11738, 1831.784179, -1113.801513, 41.833721, 0.000000, 0.000007, 0.000000, -1, 1, -1, 300.00, 100.00); 
    tmpobjid = CreateDynamicObject(11738, 1831.784179, -1113.611450, 41.833721, 0.000000, 0.000007, 0.000000, -1, 1, -1, 300.00, 100.00); 
    tmpobjid = CreateDynamicObject(1703, 1834.998168, -1097.600219, 40.653724, 0.000000, 0.000000, 0.000000, -1, 1, -1, 300.00, 100.00); 
    tmpobjid = CreateDynamicObject(1433, 1838.441772, -1097.714233, 40.823715, 0.000000, 0.000000, 0.000000, -1, 1, -1, 300.00, 100.00); 
    tmpobjid = CreateDynamicObject(1703, 1834.998168, -1097.600219, 40.653724, 0.000000, 0.000000, 0.000000, -1, 1, -1, 300.00, 100.00); 
    tmpobjid = CreateDynamicObject(1703, 1839.858764, -1097.600219, 40.653724, 0.000000, 0.000000, 0.000000, -1, 1, -1, 300.00, 100.00); 
    tmpobjid = CreateDynamicObject(1433, 1839.255859, -1090.810180, 40.823715, 0.000000, 0.000000, 179.999893, -1, 1, -1, 300.00, 100.00); 
    tmpobjid = CreateDynamicObject(1703, 1842.699462, -1090.924194, 40.653724, 0.000000, 0.000000, 179.999893, -1, 1, -1, 300.00, 100.00); 
    tmpobjid = CreateDynamicObject(1703, 1837.838867, -1090.924194, 40.653724, 0.000000, 0.000000, 179.999893, -1, 1, -1, 300.00, 100.00); 
    tmpobjid = CreateDynamicObject(1433, 1845.651855, -1112.965698, 40.878738, 0.000000, 0.000000, -0.000119, -1, 1, -1, 300.00, 100.00); 
    tmpobjid = CreateDynamicObject(1703, 1842.208251, -1112.851684, 40.708747, 0.000000, 0.000000, -0.000119, -1, 1, -1, 300.00, 100.00); 
    tmpobjid = CreateDynamicObject(1703, 1847.068847, -1112.851684, 40.708747, 0.000000, 0.000000, -0.000119, -1, 1, -1, 300.00, 100.00); 
    tmpobjid = CreateDynamicObject(2311, 1852.873291, -1102.748779, 40.653724, 0.000000, 0.000000, 90.000000, -1, 1, -1, 300.00, 100.00); 
    tmpobjid = CreateDynamicObject(2311, 1852.873291, -1088.257934, 40.653724, 0.000007, 0.000000, 89.999977, -1, 1, -1, 300.00, 100.00); 
    tmpobjid = CreateDynamicObject(1997, 1844.364379, -1106.516235, 40.653724, 0.000000, 0.000000, 90.000000, -1, 1, -1, 300.00, 100.00); 
    tmpobjid = CreateDynamicObject(1997, 1847.594360, -1106.516235, 40.653724, 0.000000, 0.000000, 90.000000, -1, 1, -1, 300.00, 100.00); 
    tmpobjid = CreateDynamicObject(1997, 1850.804687, -1106.516235, 40.653724, 0.000000, 0.000000, 90.000000, -1, 1, -1, 300.00, 100.00); 
    tmpobjid = CreateDynamicObject(1997, 1857.665893, -1077.790405, 40.653724, 0.000000, 0.000000, 255.000000, -1, 1, -1, 300.00, 100.00); 
    tmpobjid = CreateDynamicObject(1997, 1857.665893, -1079.480957, 40.653724, 0.000000, 0.000000, 255.000000, -1, 1, -1, 300.00, 100.00); 
    tmpobjid = CreateDynamicObject(1997, 1857.665893, -1081.200805, 40.653724, -0.000007, 0.000000, -104.999977, -1, 1, -1, 300.00, 100.00); 
    tmpobjid = CreateDynamicObject(2008, 1841.043823, -1077.560791, 40.913730, 0.000000, 0.000000, 270.000000, -1, 1, -1, 300.00, 100.00); 
    tmpobjid = CreateDynamicObject(2008, 1841.043823, -1081.031372, 40.913730, 0.000000, 0.000000, 270.000000, -1, 1, -1, 300.00, 100.00); 
    tmpobjid = CreateDynamicObject(2008, 1841.043823, -1074.771362, 40.913730, 0.000000, 0.000000, 270.000000, -1, 1, -1, 300.00, 100.00); 
    tmpobjid = CreateDynamicObject(1714, 1839.074707, -1075.564697, 40.653724, 0.000000, 0.000000, 90.000000, -1, 1, -1, 300.00, 100.00); 
    tmpobjid = CreateDynamicObject(1714, 1839.074707, -1078.515502, 40.653724, 0.000000, 0.000000, 90.000000, -1, 1, -1, 300.00, 100.00); 
    tmpobjid = CreateDynamicObject(1714, 1839.074707, -1081.616577, 40.653724, 0.000000, 0.000000, 90.000000, -1, 1, -1, 300.00, 100.00); 
    tmpobjid = CreateDynamicObject(638, 1849.706909, -1074.909667, 41.311717, 0.000000, 0.000000, 0.000000, -1, 1, -1, 300.00, 100.00); 
    tmpobjid = CreateDynamicObject(638, 1849.706909, -1069.399414, 41.311717, 0.000000, 0.000000, 0.000000, -1, 1, -1, 300.00, 100.00); 
    tmpobjid = CreateDynamicObject(1721, 1845.696166, -1081.844848, 40.653724, 0.000000, 0.000000, 90.000000, -1, 1, -1, 300.00, 100.00); 
    tmpobjid = CreateDynamicObject(1721, 1845.696166, -1080.974243, 40.653724, 0.000000, 0.000000, 90.000000, -1, 1, -1, 300.00, 100.00); 
    tmpobjid = CreateDynamicObject(1721, 1845.696166, -1080.073486, 40.653724, 0.000000, 0.000000, 90.000000, -1, 1, -1, 300.00, 100.00); 
    tmpobjid = CreateDynamicObject(1721, 1845.696166, -1079.253051, 40.653724, 0.000000, 0.000000, 90.000000, -1, 1, -1, 300.00, 100.00); 
    tmpobjid = CreateDynamicObject(1721, 1846.796508, -1081.844848, 40.653724, 0.000007, 0.000000, 89.999977, -1, 1, -1, 300.00, 100.00); 
    tmpobjid = CreateDynamicObject(1721, 1846.796508, -1080.974243, 40.653724, 0.000007, 0.000000, 89.999977, -1, 1, -1, 300.00, 100.00); 
    tmpobjid = CreateDynamicObject(1721, 1846.796508, -1080.073486, 40.653724, 0.000007, 0.000000, 89.999977, -1, 1, -1, 300.00, 100.00); 
    tmpobjid = CreateDynamicObject(1721, 1846.796508, -1079.253051, 40.653724, 0.000007, 0.000000, 89.999977, -1, 1, -1, 300.00, 100.00); 
    tmpobjid = CreateDynamicObject(1721, 1848.057861, -1081.844848, 40.653724, 0.000014, 0.000000, 89.999954, -1, 1, -1, 300.00, 100.00); 
    tmpobjid = CreateDynamicObject(1721, 1848.057861, -1080.974243, 40.653724, 0.000014, 0.000000, 89.999954, -1, 1, -1, 300.00, 100.00); 
    tmpobjid = CreateDynamicObject(1721, 1848.057861, -1080.073486, 40.653724, 0.000014, 0.000000, 89.999954, -1, 1, -1, 300.00, 100.00); 
    tmpobjid = CreateDynamicObject(1721, 1848.057861, -1079.253051, 40.653724, 0.000014, 0.000000, 89.999954, -1, 1, -1, 300.00, 100.00); 
    tmpobjid = CreateDynamicObject(1888, 1831.826416, -1075.017211, 40.653724, 0.000000, 0.000000, 90.000000, -1, 1, -1, 300.00, 100.00); 
    tmpobjid = CreateDynamicObject(1888, 1831.826416, -1078.027343, 40.653724, 0.000000, 0.000000, 90.000000, -1, 1, -1, 300.00, 100.00); 
    tmpobjid = CreateDynamicObject(2611, 1836.189208, -1076.354858, 42.973728, 0.000000, 0.000000, -90.000000, -1, 1, -1, 300.00, 100.00); 
    tmpobjid = CreateDynamicObject(2612, 1836.189208, -1078.084594, 42.973728, 0.000000, 0.000000, -90.000000, -1, 1, -1, 300.00, 100.00); 
    tmpobjid = CreateDynamicObject(1506, 1834.043579, -1082.872314, 40.653724, 0.000000, 0.000000, 0.000000, -1, 1, -1, 300.00, 100.00); 
}

InsertSelectionMaps()
{
	tmpobjid = CreateDynamicObject(19482, 227.162307, 67.416839, 1005.249206, 0.000000, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 10765, "airportgnd_sfse", "white", 0x00000000);
	SetDynamicObjectMaterialText(tmpobjid, 0, "{000000}_____", 130, "Ariel", 20, 1, 0x00000000, 0x00000000, 1);
	tmpobjid = CreateDynamicObject(2691, 227.174942, 67.007293, 1005.739013, 0.000000, 0.000000, 90.000000, -1, -1, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 10765, "airportgnd_sfse", "white", 0x00000000);
	tmpobjid = CreateDynamicObject(19482, 227.162307, 67.416839, 1005.018981, 0.000000, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 10765, "airportgnd_sfse", "white", 0x00000000);
	SetDynamicObjectMaterialText(tmpobjid, 0, "{000000}________", 130, "Ariel", 20, 1, 0x00000000, 0x00000000, 1);
	tmpobjid = CreateDynamicObject(19482, 227.162307, 67.416839, 1005.459411, 0.000000, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 10765, "airportgnd_sfse", "white", 0x00000000);
	SetDynamicObjectMaterialText(tmpobjid, 0, "{000000}________", 130, "Ariel", 20, 1, 0x00000000, 0x00000000, 1);
	tmpobjid = CreateDynamicObject(19482, 227.162307, 67.416839, 1005.689636, 0.000000, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 10765, "airportgnd_sfse", "white", 0x00000000);
	SetDynamicObjectMaterialText(tmpobjid, 0, "{000000}_____", 130, "Ariel", 20, 1, 0x00000000, 0x00000000, 1);
	tmpobjid = CreateDynamicObject(19482, 227.162307, 67.416839, 1005.939880, 0.000000, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 10765, "airportgnd_sfse", "white", 0x00000000);
	SetDynamicObjectMaterialText(tmpobjid, 0, "{000000}________", 130, "Ariel", 20, 1, 0x00000000, 0x00000000, 1);
	tmpobjid = CreateDynamicObject(19482, 227.162307, 67.416839, 1006.170043, 0.000000, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 10765, "airportgnd_sfse", "white", 0x00000000);
	SetDynamicObjectMaterialText(tmpobjid, 0, "{000000}_____", 130, "Ariel", 20, 1, 0x00000000, 0x00000000, 1);
	tmpobjid = CreateDynamicObject(19482, 227.162307, 67.416839, 1006.450378, 0.000000, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 10765, "airportgnd_sfse", "white", 0x00000000);
	SetDynamicObjectMaterialText(tmpobjid, 0, "{000000}________", 130, "Ariel", 20, 1, 0x00000000, 0x00000000, 1);
	tmpobjid = CreateDynamicObject(19482, 227.162307, 67.966857, 1004.948913, 0.000000, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 10765, "airportgnd_sfse", "white", 0x00000000);
	SetDynamicObjectMaterialText(tmpobjid, 0, "{ff0000}3'", 130, "courier", 10, 1, 0x00000000, 0x00000000, 1);
	tmpobjid = CreateDynamicObject(19482, 227.162307, 67.966857, 1005.389343, 0.000000, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 10765, "airportgnd_sfse", "white", 0x00000000);
	SetDynamicObjectMaterialText(tmpobjid, 0, "{ff0000}4'", 130, "courier", 10, 1, 0x00000000, 0x00000000, 1);
	tmpobjid = CreateDynamicObject(19482, 227.162307, 67.966857, 1005.879821, 0.000000, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 10765, "airportgnd_sfse", "white", 0x00000000);
	SetDynamicObjectMaterialText(tmpobjid, 0, "{ff0000}5'", 130, "courier", 10, 1, 0x00000000, 0x00000000, 1);
	tmpobjid = CreateDynamicObject(19482, 227.162307, 67.966857, 1006.390319, 0.000000, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 10765, "airportgnd_sfse", "white", 0x00000000);
	SetDynamicObjectMaterialText(tmpobjid, 0, "{ff0000}6'", 130, "courier", 10, 1, 0x00000000, 0x00000000, 1);
}