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

new PlayerActor[MAX_PLAYERS][4];

CreatePlayerActor(playerid)
{
	new vwid = AccountInfo[playerid][E_MASTERS_DBID];

	PlayerActor[playerid][0] = CreateDynamicActor(characterSkin[playerid][0],2408.3296,-1384.2576,24.3245,104.8779); //hood
	PlayerActor[playerid][1] = CreateDynamicActor(characterSkin[playerid][1],2248.5664,-1260.5315,23.9566,89.2008); //hood
	PlayerActor[playerid][3] = CreateDynamicActor(characterSkin[playerid][2],2531.9561,-1667.5062,15.1688,88.3198); //hood
	PlayerActor[playerid][3] = CreateDynamicActor(characterSkin[playerid][3],899.3932,-1073.4900,24.3234,178.2752); //hood
	
	ApplyDynamicActorAnimation(PlayerActor[playerid][0], "DEALER", "DEALER_IDLE", 4.1, 1, 0, 0, 0, 0);
	ApplyDynamicActorAnimation(PlayerActor[playerid][1], "DEALER", "DEALER_IDLE", 4.1, 1, 0, 0, 0, 0);
	ApplyDynamicActorAnimation(PlayerActor[playerid][2], "DEALER", "DEALER_IDLE", 4.1, 1, 0, 0, 0, 0);
	ApplyDynamicActorAnimation(PlayerActor[playerid][3], "GRAVEYARD", "mrnF_loop", 4.1, 1, 0, 0, 0, 0);
	
	SetDynamicActorVirtualWorld(PlayerActor[playerid][0], vwid);
	SetDynamicActorVirtualWorld(PlayerActor[playerid][1], vwid);
	SetDynamicActorVirtualWorld(PlayerActor[playerid][2], vwid);
	SetDynamicActorVirtualWorld(PlayerActor[playerid][3], vwid);
	return 1;
}

DestroyPlayerActor(playerid)
{
	for (new a = 0; a < 4; a ++)
	{
		DestroyDynamicActor(PlayerActor[playerid][a]);
	}
	return 1;
}
//Static
InsertStaticActors()
{
	fittingRoomDoor = CreateDynamicObject(2877, 216.760360, -97.310455, 1005.337768, 0.0, 0.0, 360.0, .interiorid = 15);

	CreateDynamic3DTextLabel("[Vehicle Graveyard & Scrapyard]\n{ffffff}Available Commands: '/carscrap'", COLOR_POINT, 2412.9312,-1425.4226,23.9835, 2.0);

	CreateDynamic3DTextLabel("[Clothes store]\n{ffffff}Available Commands: '/clothes'", COLOR_POINT, 217.5163,-98.4308,1005.2578, 2.0);

	CreateDynamic3DTextLabel("[Los Santos Prison]\n{ffffff}Available Commands: '/charge'", COLOR_POINT, 252.9687,90.9530,1002.4453, 2.0);

	CreateDynamic3DTextLabel("[Food & Drinks Menu]\n{ffffff}Available Commands: '/menu'", COLOR_POINT, 2106.5166,-1797.5454,13.5625, 2.0);
	CreateDynamic3DTextLabel("[Food & Drinks Menu]\n{ffffff}Available Commands: '/menu'", COLOR_POINT, 2414.0591,-1504.1791,24.0031, 2.0);
	CreateDynamic3DTextLabel("[Food & Drinks Menu]\n{ffffff}Available Commands: '/menu'", COLOR_POINT, 2392.0125,-1905.1108,13.5234, 2.0);
	CreateDynamic3DTextLabel("[Food & Drinks Menu]\n{ffffff}Available Commands: '/menu'", COLOR_POINT, 1859.9919,-1670.8585,13.3731, 2.0);
	CreateDynamic3DTextLabel("[Food & Drinks Menu]\n{ffffff}Available Commands: '/menu'", COLOR_POINT, 1705.7178,-1650.0876,13.5276, 2.0);
	CreateDynamic3DTextLabel("[Food & Drinks Menu]\n{ffffff}Available Commands: '/menu'", COLOR_POINT, 1035.1194,-1346.8387,13.7469, 2.0);

	CreateDynamic3DTextLabel("[Liquor]\n{ffffff}Available Commands: '/buybeer'", COLOR_POINT, 2130.7271,-1769.0083,13.5510, 2.0);
	CreateDynamic3DTextLabel("[Liquor]\n{ffffff}Available Commands: '/buybeer'", COLOR_POINT, 2139.9614,-1769.1486,13.5510, 2.0);

	CreateDynamic3DTextLabel("[General Store]\n{ffffff}Press 'N' to grab an items.", COLOR_POINT, -48.4748,-1.1597,203.2633, 2.0);
	CreateDynamic3DTextLabel("[General Store]\n{ffffff}Press 'N' to grab an items.", COLOR_POINT, -53.7980,2.8393,203.2633, 2.0);
	CreateDynamic3DTextLabel("[General Store]\n{ffffff}Press 'N' to grab an items.", COLOR_POINT, -51.4530,5.4811,203.2633, 2.0);
	CreateDynamic3DTextLabel("[General Store]\n{ffffff}Press 'N' to grab an items.", COLOR_POINT, -48.1108,5.5907,203.2633, 2.0);
	CreateDynamic3DTextLabel("[General Store]\n{ffffff}Press 'N' to grab an items.", COLOR_POINT, -53.7646,5.2118,203.2633, 2.0);

	CreateDynamic3DTextLabel("[Furniture Store]\n{ffffff}Press 'N' to grab an items.", COLOR_POINT, 1359.4304,1703.7946,434.9792, 2.0);
	CreateDynamic3DTextLabel("[Furniture Store]\n{ffffff}Press 'N' to grab an items.", COLOR_POINT, 1359.4393,1710.9224,434.9792, 2.0);
	CreateDynamic3DTextLabel("[Furniture Store]\n{ffffff}Press 'N' to grab an items.", COLOR_POINT, 1362.5713,1711.0144,434.9792, 2.0);

	CreateDynamic3DTextLabel("[Haircut]\n{ffffff}Available Commands: '/haircut'", COLOR_POINT, 2064.5574,-1794.9839,13.4599, 2.0);

	CreateDynamic3DTextLabel("Fish Factory\n{ffffff}Available Commands: '/buybait'\n{ffffff}Available Commands: '/sellfish'", COLOR_POINT, 2895.6743,-2135.5847,3.6525, 2.0);
}

InsertStaticVehicles()
{
	ModShop[0] = CreateDynamicCP(2332.0183,-1991.8457,13.5586, 5.0, -1, -1, -1, 3.0);
	ModShop[1] = CreateDynamicCP(1829.3051,-1398.4575,13.4297, 5.0, -1, -1, -1, 3.0);
	ModShop[2] = CreateDynamicCP(1621.7565,-1887.4757,13.5550, 5.0, -1, -1, -1, 3.0);

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

	//Garbage
	Jobs_vehicles[12] = CreateVehicle(408,2189.7869,-1995.8069,14.0930,88.8796,6, 6, -1); SetVehicleNumberPlate(Jobs_vehicles[12], "GARBAGE");
	Jobs_vehicles[13] = CreateVehicle(408,2190.3909,-1990.3845,14.0929,88.0486,6, 6, -1); SetVehicleNumberPlate(Jobs_vehicles[13], "GARBAGE");
	Jobs_vehicles[14] = CreateVehicle(408,2190.0566,-1985.0049,14.0975,90.3632,6, 6, -1); SetVehicleNumberPlate(Jobs_vehicles[14], "GARBAGE");
	
	for (new i = 0; i < 15; i ++) if (IsValidVehicle(Jobs_vehicles[i])) 
	{
		VehicleInfo[Jobs_vehicles[i]][E_VEHICLE_HEALTH] = 1000.0;
		VehicleInfo[Jobs_vehicles[i]][E_VEHICLE_FUEL] = 99999;
		VehicleInfo[Jobs_vehicles[i]][E_VEHICLE_CRATES] = 0;
		VehicleInfo[Jobs_vehicles[i]][E_VEHICLE_BURGLARY] = 0;
		VehicleInfo[Jobs_vehicles[i]][E_VEHICLE_TRASHMASTER] = 0;

	}

	//Static
	g_Vehicle[0] = CreateVehicle(591, 2062.8889, -1940.2619, 13.9858, 89.9758, 1, 0, -1); //Trailer C
	g_Vehicle[1] = CreateVehicle(591, 2028.6773, -1940.3161, 13.9363, 89.1962, 1, 0, -1); //Trailer C

	g_Vehicle[2] = CreateVehicle(481, 2233.7578, -1673.7036, 14.4241, 164.1705, 0, 0, -1); //BMX
	g_Vehicle[3] = CreateVehicle(481, 2232.0830, -1691.7159, 13.4066, 83.9132, 0, 0, -1); //BMX
	g_Vehicle[4] = CreateVehicle(481, 1954.5018, -1145.2349, 25.3644, 79.2205, 0, 0, -1); //BMX
	g_Vehicle[5] = CreateVehicle(481, 1949.7686, -1145.3051, 25.2439, 96.6447, 0, 0, -1); //BMX
	g_Vehicle[6] = CreateVehicle(481, 2763.4172, -2006.7130, 13.0710, 0.0000, 0, 0, -1); //BMX
	g_Vehicle[7] = CreateVehicle(481, 2672.4475, -1922.8100, 13.0612, 268.3999, 0, 0, -1); //BMX
	g_Vehicle[8] = CreateVehicle(481, 2723.7163, -2007.7385, 13.0690, 178.1805, 0, 0, -1); //BMX
	g_Vehicle[9] = CreateVehicle(481, 1813.4281, -2041.3507, 13.0699, 0.9607, 0, 0, -1); //BMX
	g_Vehicle[10] = CreateVehicle(481, 1813.4915, -2031.5114, 13.0724, 0.0474, 0, 0, -1); //BMX
	g_Vehicle[11] = CreateVehicle(481, 1813.6887, -2052.5441, 13.0613, 359.2406, 0, 0, -1); //BMX
	g_Vehicle[12] = CreateVehicle(481, 2463.6838, -1353.9309, 24.2022, 89.1558, 0, 0, -1); //BMX
	g_Vehicle[13] = CreateVehicle(481, 2460.6013, -1365.0794, 23.4984, 0.0250, 0, 0, -1); //BMX
	g_Vehicle[14] = CreateVehicle(481, 2204.8662, -1313.1074, 23.4989, 0.0000, 0, 0, -1); //BMX
	g_Vehicle[15] = CreateVehicle(481, 2242.1848, -1263.0550, 23.4598, 267.4012, 0, 0, -1); //BMX

	g_Vehicle[16] = CreateVehicle(481, 1948.2949, -2073.0600, 13.0614, 88.1823, 0, 0, -1); //BMX
	g_Vehicle[17] = CreateVehicle(481, 2416.6606, -1470.2977, 23.4979, 272.1199, 0, 0, -1); //BMX
	g_Vehicle[18] = CreateVehicle(481, 2383.5585, -1508.3507, 23.5146, 359.9949, 0, 0, -1); //BMX
	g_Vehicle[19] = CreateVehicle(481, 2353.0952, -1467.0678, 23.5146, 0.0000, 0, 0, -1); //BMX
	g_Vehicle[20] = CreateVehicle(481, 2519.4697, -1947.7603, 13.1962, 0.2285, 0, 0, -1); //BMX
	g_Vehicle[21] = CreateVehicle(481, 2228.0476, -1867.3701, 13.0614, 0.0000, 0, 0, -1); //BMX
	g_Vehicle[22] = CreateVehicle(481, 1836.3259, -1888.8200, 12.9363, 88.7467, 0, 0, -1); //BMX
	g_Vehicle[23] = CreateVehicle(481, 1979.4620, -2050.7692, 13.0599, 88.0991, 0, 0, -1); //BMX
	g_Vehicle[24] = CreateVehicle(481, 1939.4611, -1982.0015, 13.0612, 84.6999, 0, 0, -1); //BMX
	g_Vehicle[25] = CreateVehicle(481, 1952.7302, -1907.4423, 13.0614, 0.0000, 0, 0, -1); //BMX
	g_Vehicle[26] = CreateVehicle(481, 2358.5290, -1289.1805, 23.5259, 266.2498, 0, 0, -1); //BMX
	g_Vehicle[27] = CreateVehicle(481, 2324.7565, -1374.8699, 23.5311, 263.4043, 0, 0, -1); //BMX
	g_Vehicle[28] = CreateVehicle(481, 2212.8432, -1365.5156, 23.5032, 0.0028, 0, 0, -1); //BMX

	g_Vehicle[29] = CreateVehicle(473,2937.6396,-2103.8728,-0.2721,259.0053,0, 0, -1); // boat
	g_Vehicle[30] = CreateVehicle(453,2932.1443,-2115.2156,-0.3427,270.0765,0, 0, -1); // boat
	g_Vehicle[31] = CreateVehicle(452,2937.7739,-2058.9788,-0.2453,267.4742,0, 0, -1); // boat
	g_Vehicle[32] = CreateVehicle(473,2899.9417,-1835.0874,-0.2598,0.2502,0, 0, -1); // boat
	g_Vehicle[33] = CreateVehicle(473,129.5652,-1803.0558,-0.2381,359.8999,0, 0, -1); // boat
	g_Vehicle[34] = CreateVehicle(454,129.1682,-1940.8101,0.0906,0.1088,0, 0, -1); // boat
	g_Vehicle[35] = CreateVehicle(453,170.2965,-1919.6825,-0.3462,359.9013,0, 0, -1); // boat
	g_Vehicle[36] = CreateVehicle(484,2718.6948,-2306.7476,0.2115,0.2194,0, 0, -1); // boat
	g_Vehicle[37] = CreateVehicle(453,2492.3928,-2277.1829,-0.4793,359.8600,0, 0, -1); // boat

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
	
	//Burglary
	RemoveBuildingForPlayer(playerid, 2103, 2360.830, -1130.140, 1051.020, 0.250);
	RemoveBuildingForPlayer(playerid, 2077, 2357.550, -1131.520, 1050.689, 0.250);
	RemoveBuildingForPlayer(playerid, 2077, 2357.550, -1134.189, 1050.699, 0.250);
	RemoveBuildingForPlayer(playerid, 2811, 2372.699, -1128.910, 1049.819, 0.250);
	RemoveBuildingForPlayer(playerid, 2331, 2367.370, -1123.160, 1050.119, 0.250);
	RemoveBuildingForPlayer(playerid, 2868, 2374.979, -1125.229, 1049.869, 0.250);
	RemoveBuildingForPlayer(playerid, 2225, 2369.179, -1125.800, 1049.869, 0.250);

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

	//Bahamas
	//RemoveBuildingForPlayer(playerid, 5461, 2011.469, -1300.900, 28.695, 0.250);
	//RemoveBuildingForPlayer(playerid, 5597, 2011.469, -1300.900, 28.695, 0.250);

	//Cluckin Bell
	RemoveBuildingForPlayer(playerid, 17534, 2402.310, -1503.589, 28.992, 0.250);
	RemoveBuildingForPlayer(playerid, 17754, 2402.310, -1503.589, 28.992, 0.250);
	RemoveBuildingForPlayer(playerid, 1533, 2419.300, -1510.479, 22.992, 0.250);
	RemoveBuildingForPlayer(playerid, 1537, 2419.300, -1507.469, 22.992, 0.250);
	RemoveBuildingForPlayer(playerid, 5168, 2385.189, -1906.520, 18.445, 0.250);
	RemoveBuildingForPlayer(playerid, 5224, 2385.189, -1906.520, 18.445, 0.250);
	RemoveBuildingForPlayer(playerid, 1522, 2396.300, -1899.619, 12.539, 0.250);
	RemoveBuildingForPlayer(playerid, 1522, 2399.330, -1899.619, 12.539, 0.250);

	//Crenshaw
	RemoveBuildingForPlayer(playerid, 3562, 2232.398, -1464.796, 25.648, 0.250);
	RemoveBuildingForPlayer(playerid, 3562, 2247.531, -1464.796, 25.546, 0.250);
	RemoveBuildingForPlayer(playerid, 3562, 2263.718, -1464.796, 25.437, 0.250);
	RemoveBuildingForPlayer(playerid, 3562, 2243.710, -1401.781, 25.640, 0.250);
	RemoveBuildingForPlayer(playerid, 3562, 2230.609, -1401.781, 25.640, 0.250);
	RemoveBuildingForPlayer(playerid, 3562, 2256.664, -1401.781, 25.640, 0.250);
	RemoveBuildingForPlayer(playerid, 5649, 2252.000, -1434.140, 23.257, 0.250);
	RemoveBuildingForPlayer(playerid, 713, 2275.390, -1438.664, 22.554, 0.250);
	RemoveBuildingForPlayer(playerid, 673, 2229.023, -1411.640, 22.960, 0.250);
	RemoveBuildingForPlayer(playerid, 673, 2265.617, -1410.335, 21.773, 0.250);
	RemoveBuildingForPlayer(playerid, 1221, 2226.851, -1404.742, 23.632, 0.250);
	RemoveBuildingForPlayer(playerid, 3582, 2230.609, -1401.781, 25.640, 0.250);
	RemoveBuildingForPlayer(playerid, 1224, 2225.984, -1396.679, 23.531, 0.250);
	RemoveBuildingForPlayer(playerid, 1221, 2227.953, -1396.851, 23.375, 0.250);
	RemoveBuildingForPlayer(playerid, 3582, 2243.710, -1401.781, 25.640, 0.250);
	RemoveBuildingForPlayer(playerid, 645, 2237.531, -1395.484, 23.039, 0.250);
	RemoveBuildingForPlayer(playerid, 3582, 2256.664, -1401.781, 25.640, 0.250);
	RemoveBuildingForPlayer(playerid, 620, 2274.578, -1398.492, 22.507, 0.250);
	RemoveBuildingForPlayer(playerid, 1224, 2225.679, -1468.617, 23.429, 0.250);
	RemoveBuildingForPlayer(playerid, 1221, 2225.851, -1466.648, 23.273, 0.250);
	RemoveBuildingForPlayer(playerid, 645, 2239.570, -1468.804, 22.687, 0.250);
	RemoveBuildingForPlayer(playerid, 3582, 2232.398, -1464.796, 25.648, 0.250);
	RemoveBuildingForPlayer(playerid, 673, 2241.890, -1458.929, 22.960, 0.250);
	RemoveBuildingForPlayer(playerid, 3582, 2247.531, -1464.796, 25.546, 0.250);
	RemoveBuildingForPlayer(playerid, 620, 2267.468, -1470.195, 21.718, 0.250);
	RemoveBuildingForPlayer(playerid, 3582, 2263.718, -1464.796, 25.437, 0.250);
	RemoveBuildingForPlayer(playerid, 1221, 2251.289, -1461.828, 23.632, 0.250);
	RemoveBuildingForPlayer(playerid, 1220, 2256.656, -1456.898, 22.859, 0.250);
	RemoveBuildingForPlayer(playerid, 1230, 2255.984, -1457.906, 22.859, 0.250);
	RemoveBuildingForPlayer(playerid, 673, 2227.203, -1444.500, 22.960, 0.250);
	RemoveBuildingForPlayer(playerid, 5428, 2252.000, -1434.140, 23.257, 0.250);
	RemoveBuildingForPlayer(playerid, 5682, 2241.429, -1433.671, 31.281, 0.250);
	RemoveBuildingForPlayer(playerid, 700, 2226.515, -1426.765, 23.117, 0.250);
	RemoveBuildingForPlayer(playerid, 673, 2243.570, -1423.609, 22.960, 0.250);
	RemoveBuildingForPlayer(playerid, 620, 2256.406, -1444.507, 23.101, 0.250);
	RemoveBuildingForPlayer(playerid, 3593, 2261.773, -1441.101, 23.500, 0.250);
	RemoveBuildingForPlayer(playerid, 3593, 2265.078, -1424.476, 23.500, 0.250);
	RemoveBuildingForPlayer(playerid, 1307, 2225.419, -1456.390, 23.117, 0.250);
	RemoveBuildingForPlayer(playerid, 1308, 2224.419, -1473.040, 22.804, 0.250);
	RemoveBuildingForPlayer(playerid, 1308, 2223.090, -1410.119, 23.312, 0.250);
	RemoveBuildingForPlayer(playerid, 1308, 2227.870, -1394.410, 23.054, 0.250);
	RemoveBuildingForPlayer(playerid, 1308, 2252.590, -1394.410, 23.054, 0.250);
	RemoveBuildingForPlayer(playerid, 1308, 2280.469, -1395.760, 23.054, 0.250);
	RemoveBuildingForPlayer(playerid, 1307, 2272.679, -1459.189, 22.054, 0.250);

	//Donut
	RemoveBuildingForPlayer(playerid, 5732, 1014.020, -1361.459, 20.351, 0.250);
	RemoveBuildingForPlayer(playerid, 5975, 1014.020, -1361.459, 20.351, 0.250);
	RemoveBuildingForPlayer(playerid, 1522, 1038.949, -1341.150, 12.718, 0.250);

	//Elcorona Flat
	RemoveBuildingForPlayer(playerid, 5189, 1983.530, -2085.120, 18.078, 0.250);
	RemoveBuildingForPlayer(playerid, 5198, 1983.530, -2085.120, 18.078, 0.250);
	RemoveBuildingForPlayer(playerid, 1308, 1971.150, -2082.530, 12.609, 0.250);

	//Alhambra
	/*RemoveBuildingForPlayer(playerid, 5504, 2046.0000, -1613.0000, 12.0000, 0.25);
    RemoveBuildingForPlayer(playerid, 5515, 1931.6484, -1577.5703, 12.3594, 0.25);
    RemoveBuildingForPlayer(playerid, 5516, 1977.8359, -1569.0469, 19.0703, 0.25);
    RemoveBuildingForPlayer(playerid, 5534, 1927.7031, -1754.3125, 12.4609, 0.25);
    RemoveBuildingForPlayer(playerid, 5536, 1866.3281, -1789.7813, 20.9453, 0.25);
    RemoveBuildingForPlayer(playerid, 5541, 1822.8906, -1725.2578, 12.4688, 0.25);
    RemoveBuildingForPlayer(playerid, 5542, 1884.6641, -1613.4219, 12.4609, 0.25);
    RemoveBuildingForPlayer(playerid, 5543, 1941.6563, -1682.5703, 12.4766, 0.25);
    RemoveBuildingForPlayer(playerid, 5544, 1873.7422, -1682.4766, 34.7969, 0.25);
    RemoveBuildingForPlayer(playerid, 5545, 1971.6563, -1682.3125, 13.7422, 0.25);
    RemoveBuildingForPlayer(playerid, 5548, 2046.0000, -1613.0000, 12.0000, 0.25);
    RemoveBuildingForPlayer(playerid, 5633, 2089.3594, -1643.9297, 18.2188, 0.25);
    RemoveBuildingForPlayer(playerid, 5634, 1931.3125, -1574.8438, 16.4609, 0.25);
    RemoveBuildingForPlayer(playerid, 1524, 1837.6641, -1640.3828, 13.7578, 0.25);
    RemoveBuildingForPlayer(playerid, 1524, 1959.3984, -1577.7578, 13.7578, 0.25);
    RemoveBuildingForPlayer(playerid, 3772, 1975.5078, -1719.0391, 19.3281, 0.25);
    RemoveBuildingForPlayer(playerid, 3773, 1971.2734, -1701.7734, 17.8828, 0.25);
    RemoveBuildingForPlayer(playerid, 3774, 1974.9453, -1667.4844, 17.6563, 0.25);
    RemoveBuildingForPlayer(playerid, 3772, 1976.1250, -1682.9609, 19.3516, 0.25);
    RemoveBuildingForPlayer(playerid, 3773, 1971.3516, -1651.2969, 17.9063, 0.25);
    RemoveBuildingForPlayer(playerid, 3774, 1972.3906, -1630.0000, 17.6797, 0.25);
    RemoveBuildingForPlayer(playerid, 5397, 1866.3281, -1789.7813, 20.9453, 0.25);
    RemoveBuildingForPlayer(playerid, 5503, 1927.7031, -1754.3125, 12.4609, 0.25);
    RemoveBuildingForPlayer(playerid, 1226, 1867.5547, -1748.2031, 16.3594, 0.25);
    RemoveBuildingForPlayer(playerid, 620, 1855.7188, -1741.5391, 10.8047, 0.25);
    RemoveBuildingForPlayer(playerid, 620, 1879.5078, -1741.4844, 10.8047, 0.25);
    RemoveBuildingForPlayer(playerid, 620, 1908.2188, -1741.4844, 10.8047, 0.25);
    RemoveBuildingForPlayer(playerid, 5502, 1822.8906, -1725.2578, 12.4688, 0.25);
    RemoveBuildingForPlayer(playerid, 712, 1929.5781, -1736.9063, 21.3906, 0.25);
    RemoveBuildingForPlayer(playerid, 620, 1931.0391, -1726.3281, 10.8047, 0.25);
    RemoveBuildingForPlayer(playerid, 1226, 1945.7656, -1716.3594, 16.3906, 0.25);
    RemoveBuildingForPlayer(playerid, 620, 1958.3672, -1736.5547, 14.4844, 0.25);
    RemoveBuildingForPlayer(playerid, 1226, 1825.9297, -1697.5625, 16.3438, 0.25);
    RemoveBuildingForPlayer(playerid, 620, 1832.3828, -1694.3125, 9.7188, 0.25);
    RemoveBuildingForPlayer(playerid, 1537, 1837.4375, -1683.9688, 12.3047, 0.25);
    RemoveBuildingForPlayer(playerid, 1533, 1837.4375, -1683.9531, 12.3047, 0.25);
    RemoveBuildingForPlayer(playerid, 1537, 1837.4375, -1686.9844, 12.3125, 0.25);
    RemoveBuildingForPlayer(playerid, 1226, 1825.8516, -1667.0781, 16.3438, 0.25);
    RemoveBuildingForPlayer(playerid, 620, 1832.8984, -1670.7656, 9.7188, 0.25);
    RemoveBuildingForPlayer(playerid, 1533, 1837.4375, -1677.9219, 12.2969, 0.25);
    RemoveBuildingForPlayer(playerid, 1537, 1837.4375, -1680.9531, 12.2969, 0.25);
    RemoveBuildingForPlayer(playerid, 1533, 1837.4375, -1680.9375, 12.2969, 0.25);
    RemoveBuildingForPlayer(playerid, 5408, 1873.7422, -1682.4766, 34.7969, 0.25);
    RemoveBuildingForPlayer(playerid, 620, 1931.0391, -1702.2891, 10.8047, 0.25);
    RemoveBuildingForPlayer(playerid, 712, 1929.5781, -1694.4609, 21.3906, 0.25);
    RemoveBuildingForPlayer(playerid, 620, 1931.0391, -1667.0313, 10.8047, 0.25);
    RemoveBuildingForPlayer(playerid, 1226, 1937.5547, -1669.8906, 16.3906, 0.25);
    RemoveBuildingForPlayer(playerid, 5441, 1941.6563, -1682.5703, 12.4766, 0.25);
    RemoveBuildingForPlayer(playerid, 1226, 1979.4219, -1748.1641, 16.3984, 0.25);
    //RemoveBuildingForPlayer(playerid, 1308, 1978.8594, -1742.5703, 12.7031, 0.25);
    RemoveBuildingForPlayer(playerid, 3580, 1975.5078, -1719.0391, 19.3281, 0.25);
    RemoveBuildingForPlayer(playerid, 673, 1988.7656, -1702.0469, 15.0156, 0.25);
    RemoveBuildingForPlayer(playerid, 3616, 1971.2734, -1701.7734, 17.8828, 0.25);
    RemoveBuildingForPlayer(playerid, 3580, 1976.1250, -1682.9609, 19.3516, 0.25);
    RemoveBuildingForPlayer(playerid, 5412, 1971.6563, -1682.3125, 13.7422, 0.25);
    RemoveBuildingForPlayer(playerid, 3617, 1974.9453, -1667.4844, 17.6563, 0.25);
    RemoveBuildingForPlayer(playerid, 620, 1931.0391, -1637.8984, 10.8047, 0.25);
    RemoveBuildingForPlayer(playerid, 1226, 1945.7656, -1635.7734, 16.3906, 0.25);
    RemoveBuildingForPlayer(playerid, 620, 1855.7188, -1623.2813, 10.8047, 0.25);
    RemoveBuildingForPlayer(playerid, 620, 1879.5078, -1623.1016, 10.8047, 0.25);
    RemoveBuildingForPlayer(playerid, 1308, 1891.9688, -1622.0000, 12.7813, 0.25);
    RemoveBuildingForPlayer(playerid, 620, 1908.2188, -1622.9844, 10.8047, 0.25);
    RemoveBuildingForPlayer(playerid, 712, 1929.5781, -1627.6250, 21.3906, 0.25);
    RemoveBuildingForPlayer(playerid, 1226, 1883.8203, -1616.4297, 16.3906, 0.25);
    RemoveBuildingForPlayer(playerid, 5501, 1884.6641, -1613.4219, 12.4609, 0.25);
    RemoveBuildingForPlayer(playerid, 1226, 1908.2813, -1608.1172, 16.3906, 0.25);
    RemoveBuildingForPlayer(playerid, 1308, 1943.8672, -1602.8047, 12.7813, 0.25);
    RemoveBuildingForPlayer(playerid, 5474, 1931.6484, -1577.5703, 12.3594, 0.25);
    RemoveBuildingForPlayer(playerid, 5630, 1928.4922, -1575.9688, 20.5547, 0.25);
    RemoveBuildingForPlayer(playerid, 673, 1955.3047, -1649.8828, 15.0625, 0.25);
    RemoveBuildingForPlayer(playerid, 673, 1986.5938, -1650.9219, 14.6641, 0.25);
    RemoveBuildingForPlayer(playerid, 3616, 1971.3516, -1651.2969, 17.9063, 0.25);
    RemoveBuildingForPlayer(playerid, 673, 1955.0156, -1632.9219, 14.9688, 0.25);
    RemoveBuildingForPlayer(playerid, 3617, 1972.3906, -1630.0000, 17.6797, 0.25);
    RemoveBuildingForPlayer(playerid, 1308, 1951.5391, -1616.5078, 12.7813, 0.25);
    RemoveBuildingForPlayer(playerid, 620, 1954.3594, -1603.6406, 12.5000, 0.25);
    RemoveBuildingForPlayer(playerid, 645, 1976.1719, -1600.1797, 12.1953, 0.25);
    RemoveBuildingForPlayer(playerid, 5475, 1977.8359, -1569.0469, 19.0703, 0.25);
    RemoveBuildingForPlayer(playerid, 1308, 1979.7734, -1614.9375, 12.7813, 0.25);
    RemoveBuildingForPlayer(playerid, 620, 1987.1172, -1618.2578, 12.5000, 0.25);
    RemoveBuildingForPlayer(playerid, 5517, 1883.5234, -1576.4453, 20.1953, 0.25);
    RemoveBuildingForPlayer(playerid, 740, 1887.1953, -1565.8984, 9.7813, 0.25);
    RemoveBuildingForPlayer(playerid, 740, 1863.3125, -1568.6484, 11.7734, 0.25);
    RemoveBuildingForPlayer(playerid, 714, 2007.6094, -1556.6563, 12.5938, 0.25);
    RemoveBuildingForPlayer(playerid, 5476, 1883.5234, -1576.4453, 20.1953, 0.25);
    RemoveBuildingForPlayer(playerid, 1307, 1931.7422, -1569.8828, 12.6641, 0.25);
    RemoveBuildingForPlayer(playerid, 700, 1942.5625, -1599.2969, 12.9922, 0.25);
    RemoveBuildingForPlayer(playerid, 1307, 1983.3359, -1557.6797, 12.6641, 0.25);
    RemoveBuildingForPlayer(playerid, 700, 2021.3359, -1599.2969, 12.9922, 0.25);*/

	//FrontYard
	//RemoveBuildingForPlayer(playerid, 5476, 1883.520, -1576.449, 20.195, 0.250);
	//RemoveBuildingForPlayer(playerid, 5517, 1883.520, -1576.449, 20.195, 0.250);

	//JeffersonMotel
	RemoveBuildingForPlayer(playerid, 5413, 2222.989, -1162.599, 30.039, 0.250);
	RemoveBuildingForPlayer(playerid, 5612, 2222.989, -1162.599, 30.039, 0.250);
	RemoveBuildingForPlayer(playerid, 1493, 2192.330, -1150.839, 32.781, 0.250);
	RemoveBuildingForPlayer(playerid, 1493, 2233.719, -1160.550, 24.867, 0.250);
	RemoveBuildingForPlayer(playerid, 700, 2252.300, -1178.280, 25.132, 0.250);
	RemoveBuildingForPlayer(playerid, 700, 2255.510, -1170.449, 25.132, 0.250);
	RemoveBuildingForPlayer(playerid, 673, 2256.379, -1178.199, 24.734, 0.250);
	RemoveBuildingForPlayer(playerid, 5638, 2184.500, -1179.329, 36.406, 0.250);

	//Lsv
	RemoveBuildingForPlayer(playerid, 17943, 2540.879, -1350.800, 42.601, 0.250);
	RemoveBuildingForPlayer(playerid, 17679, 2540.830, -1350.589, 40.898, 0.250);
	RemoveBuildingForPlayer(playerid, 17729, 2540.830, -1350.589, 40.898, 0.250);
	RemoveBuildingForPlayer(playerid, 17954, 2577.229, -1350.400, 56.539, 0.250);
	RemoveBuildingForPlayer(playerid, 17591, 2606.379, -1341.839, 47.546, 0.250);

	//Ganton24
	RemoveBuildingForPlayer(playerid, 17757, 2450.8750, -1757.3984, 16.0000, 0.25);
    RemoveBuildingForPlayer(playerid, 17519, 2450.8750, -1757.3984, 16.0000, 0.25);

	//Pizzastack
	RemoveBuildingForPlayer(playerid, 5418, 2112.939, -1797.089, 19.335, 0.250);
	RemoveBuildingForPlayer(playerid, 5530, 2112.939, -1797.089, 19.335, 0.250);
	RemoveBuildingForPlayer(playerid, 1522, 2105.919, -1807.250, 12.515, 0.250);
	RemoveBuildingForPlayer(playerid, 1408, 2099.850, -1813.910, 13.101, 0.250);
	RemoveBuildingForPlayer(playerid, 1408, 2099.860, -1819.359, 13.101, 0.250);
	RemoveBuildingForPlayer(playerid, 1408, 2102.600, -1822.079, 13.117, 0.250);
	RemoveBuildingForPlayer(playerid, 1408, 2099.860, -1799.420, 13.101, 0.250);
	RemoveBuildingForPlayer(playerid, 1408, 2099.850, -1793.979, 13.101, 0.250);
	RemoveBuildingForPlayer(playerid, 1408, 2102.659, -1791.329, 13.101, 0.250);
	RemoveBuildingForPlayer(playerid, 1432, 2102.060, -1793.140, 12.671, 0.250);
	RemoveBuildingForPlayer(playerid, 1432, 2101.629, -1798.170, 12.671, 0.250);
	RemoveBuildingForPlayer(playerid, 1432, 2103.689, -1795.910, 12.671, 0.250);
	RemoveBuildingForPlayer(playerid, 1432, 2103.959, -1800.560, 12.671, 0.250);
	RemoveBuildingForPlayer(playerid, 1226, 2114.719, -1785.180, 16.398, 0.250);
	RemoveBuildingForPlayer(playerid, 1432, 2104.020, -1812.420, 12.671, 0.250);
	RemoveBuildingForPlayer(playerid, 1432, 2101.989, -1814.709, 12.570, 0.250);
	RemoveBuildingForPlayer(playerid, 1432, 2103.409, -1817.300, 12.671, 0.250);
	RemoveBuildingForPlayer(playerid, 1432, 2102.129, -1819.949, 12.671, 0.250);

	//Seville
	//RemoveBuildingForPlayer(playerid, 3697, 2744.070, -1965.119, 16.843, 0.250);
	//RemoveBuildingForPlayer(playerid, 3696, 2744.070, -1965.119, 16.843, 0.250);

	//TDB
	/*RemoveBuildingForPlayer(playerid, 3684, 1183.630, -1230.229, 20.570, 0.250);
	RemoveBuildingForPlayer(playerid, 3685, 1183.630, -1230.229, 20.570, 0.250);
	RemoveBuildingForPlayer(playerid, 3684, 1183.630, -1257.880, 17.328, 0.250);
	RemoveBuildingForPlayer(playerid, 3685, 1183.630, -1257.880, 17.328, 0.250);
	RemoveBuildingForPlayer(playerid, 6006, 1183.699, -1241.359, 16.273, 0.250);
	RemoveBuildingForPlayer(playerid, 6009, 1183.699, -1241.359, 16.273, 0.250);*/

	//TDF
	//RemoveBuildingForPlayer(playerid, 5891, 1123.150, -1020.750, 37.304, 0.250);
	//RemoveBuildingForPlayer(playerid, 5890, 1123.150, -1020.750, 37.304, 0.250);

	//Westmont
	RemoveBuildingForPlayer(playerid, 5205, 2111.6563, -1873.3672, 16.3984, 0.25);
    RemoveBuildingForPlayer(playerid, 5206, 2163.6719, -1873.6172, 15.8203, 0.25);
    RemoveBuildingForPlayer(playerid, 5207, 2167.0391, -1925.2031, 15.8281, 0.25);
    RemoveBuildingForPlayer(playerid, 5208, 2115.0000, -1921.5234, 15.3906, 0.25);
    RemoveBuildingForPlayer(playerid, 3744, 2159.8281, -1930.6328, 15.0781, 0.25);
    RemoveBuildingForPlayer(playerid, 3567, 2142.9141, -1947.4219, 13.2656, 0.25);
    RemoveBuildingForPlayer(playerid, 1226, 2118.2891, -1939.3984, 16.3906, 0.25);
    RemoveBuildingForPlayer(playerid, 620, 2114.5547, -1928.1875, 5.0313, 0.25);
    RemoveBuildingForPlayer(playerid, 620, 2113.3984, -1925.0391, 10.8047, 0.25);
    RemoveBuildingForPlayer(playerid, 620, 2115.6719, -1922.7656, 10.8047, 0.25);
    RemoveBuildingForPlayer(playerid, 620, 2123.3594, -1928.0703, 6.8438, 0.25);
    RemoveBuildingForPlayer(playerid, 3574, 2159.8281, -1930.6328, 15.0781, 0.25);
    RemoveBuildingForPlayer(playerid, 5181, 2167.0391, -1925.2031, 15.8281, 0.25);
    RemoveBuildingForPlayer(playerid, 5182, 2115.0000, -1921.5234, 15.3906, 0.25);
    RemoveBuildingForPlayer(playerid, 620, 2122.6563, -1916.7891, 10.8047, 0.25);
    RemoveBuildingForPlayer(playerid, 620, 2116.9297, -1916.0781, 10.8047, 0.25);
    RemoveBuildingForPlayer(playerid, 620, 2121.5078, -1909.5313, 10.8047, 0.25);
    RemoveBuildingForPlayer(playerid, 620, 2110.2734, -1906.5859, 5.0313, 0.25);
    RemoveBuildingForPlayer(playerid, 5183, 2111.6563, -1873.3672, 16.3984, 0.25);
    RemoveBuildingForPlayer(playerid, 5180, 2163.6719, -1873.6172, 15.8203, 0.25);
    RemoveBuildingForPlayer(playerid, 5374, 2085.2666, -1909.7165, 22.9930, 0.50 );

	//Seville
    RemoveBuildingForPlayer(playerid, 3244, 2632.3906, -1954.8203, 12.7578, 0.25);
    RemoveBuildingForPlayer(playerid, 5151, 2674.1016, -1990.7891, 15.1875, 0.25);
    RemoveBuildingForPlayer(playerid, 5241, 2674.1016, -1990.7891, 15.1875, 0.25);
    RemoveBuildingForPlayer(playerid, 3638, 2644.6172, -1955.7031, 15.7344, 0.25);
    RemoveBuildingForPlayer(playerid, 3638, 2666.4375, -1955.7031, 15.7344, 0.25);
    RemoveBuildingForPlayer(playerid, 3638, 2687.1250, -1955.7031, 15.7344, 0.25);

	//Idlewood Liquor
	RemoveBuildingForPlayer(playerid, 5430, 2148.949, -1791.839, 19.101, 0.250);
	RemoveBuildingForPlayer(playerid, 5531, 2148.949, -1791.839, 19.101, 0.250);
	RemoveBuildingForPlayer(playerid, 1259, 2128.229, -1780.709, 23.875, 0.250);
	RemoveBuildingForPlayer(playerid, 1268, 2128.229, -1780.709, 23.875, 0.250);

	//PaynSpray
	RemoveBuildingForPlayer(playerid, 3574, 2313.050, -2008.540, 15.023, 0.250);
	RemoveBuildingForPlayer(playerid, 3744, 2313.050, -2008.540, 15.023, 0.250);
	RemoveBuildingForPlayer(playerid, 3574, 2331.379, -2001.670, 15.023, 0.250);
	RemoveBuildingForPlayer(playerid, 3744, 2331.379, -2001.670, 15.023, 0.250);
	RemoveBuildingForPlayer(playerid, 1260, 2336.909, -1987.630, 21.828, 0.250);
	RemoveBuildingForPlayer(playerid, 1266, 2336.909, -1987.630, 21.828, 0.250);
}

stock InsertObjects()
{
	//Alhambra
	/*new Alhambara_Object[31];

    Alhambara_Object[0] = CreateObject(-25610, 1941.6600, -1682.5710, 12.4770, 0.0000, 0.0000, 0.0000, 5000.0000); //gtac/alhambra/alhambra_roads.dff
    Alhambara_Object[1] = CreateObject(-25611, 1851.4637, -1663.6250, 13.8887, 0.0000, 0.0000, 0.0000, 1000.0000); //gtac/alhambra/alhambra_1.dff
    Alhambara_Object[2] = CreateObject(-25612, 1901.0300, -1629.1778, 14.2440, 0.0000, 0.0000, 0.0000, 1000.0000); //gtac/alhambra/alhambra_2.dff
    Alhambara_Object[3] = CreateObject(-25613, 1851.1568, -1719.3070, 16.5079, 0.0000, 0.0000, 0.0000, 1000.0000); //gtac/alhambra/alhambra_3.dff
    Alhambara_Object[4] = CreateObject(-25614, 1910.5898, -1705.7480, 21.3080, 0.0000, 0.0000, 0.0000, 1000.0000); //gtac/alhambra/alhambra_4.dff
    Alhambara_Object[5] = CreateObject(-25615, 1867.8590, -1781.7889, 15.7700, 0.0000, 0.0000, 0.0000, 1000.0000); //gtac/alhambra/alhambra_sm.dff
    Alhambara_Object[6] = CreateObject(-25616, 1932.3487, -1562.3658, 12.6660, 0.0000, 0.0000, 0.0000, 1000.0000); //gtac/alhambra/alhambra_projects.dff
    Alhambara_Object[7] = CreateObject(-25617, 1968.4709, -1678.2910, 12.8450, 0.0000, 0.0000, 0.0000, 1000.0000); //gtac/alhambra/alhambra_houses.dff
    Alhambara_Object[8] = CreateObject(-25618, 1933.8120, -1724.3010, 21.6560, 0.0000, 0.0000, 0.0000, 1000.0000); //gtac/alhambra/alhambra_bits.dff
    Alhambara_Object[9] = CreateObject(-25619, 1930.4720, -1657.1280, 24.4920, 0.0000, 0.0000, 0.0000, 1000.0000); //gtac/alhambra/alhambra_alphas.dff

    Alhambara_Object[10] = CreateObject(1280, 1870.0743, -1628.4344, 12.8898, 0.0000, 0.0000, 0.0000, 150.0000); //parkbench1
    Alhambara_Object[11] = CreateObject(1280, 1870.0743, -1637.1756, 12.8898, 0.0000, 0.0000, 0.0000, 150.0000); //parkbench1

    Alhambara_Object[12] = CreateObject(-25620, 1868.6689, -1645.6555, 13.3957, 0.0000, 0.0000, 0.0000, 500.0000); //reyo/alley_bits.dff

    Alhambara_Object[13] = CreateObject(647, 1849.2856, -1626.8664, 13.4863, 0.0000, 0.0000, 0.0000, 500.0000); //new_bushsm
    Alhambara_Object[14] = CreateObject(1283, 1882.3863, -1623.1634, 15.6148, 0.0000, 0.0000, 0.0000, 500.0000); //MTraffic1
    Alhambara_Object[15] = CreateObject(1283, 1893.1092, -1657.8066, 15.6148, 0.0000, 0.0000, 90.0000, 500.0000); //MTraffic1
    Alhambara_Object[16] = CreateObject(647, 1859.6466, -1626.1661, 13.4863, 0.0000, 0.0000, -42.7999, 500.0000); //new_bushsm
    Alhambara_Object[17] = CreateObject(1226, 1888.5771, -1671.2119, 16.3145, 0.0000, 0.0000, 0.0000, 500.0000); //lamppost3
    Alhambara_Object[18] = CreateObject(1226, 1888.5771, -1638.9525, 16.3145, 0.0000, 0.0000, 0.0000, 500.0000); //lamppost3
    Alhambara_Object[19] = CreateObject(1226, 1872.7170, -1666.4436, 16.3145, 0.0000, 0.0000, 180.0000, 500.0000); //lamppost3
    Alhambara_Object[20] = CreateObject(1226, 1858.4173, -1691.4211, 16.3145, 0.0000, 0.0000, -90.0000, 500.0000); //lamppost3
    Alhambara_Object[21] = CreateObject(19450, 1628.7058, -1200.2943, 35.9883, 0.0000, 90.0000, 89.1996, 200.0000); //wall090
    SetObjectMaterial(Alhambara_Object[21], 0, 19297, "matlights", "invisible", 0xFFFFFFFF);
    Alhambara_Object[22] = CreateObject(2736, 1631.4825, -1200.1517, 23.9304, 0.0000, 0.0000, 0.0000, 300.0000); //CJ_ZIP_POST_05
    SetObjectMaterial(Alhambara_Object[22], 0, 10864, "bridgeland_sfse", "prolaps02", 0xFFFFFFFF);
    Alhambara_Object[23] = CreateObject(1522, 1625.7716, -1199.5548, 35.9444, 0.0000, 0.0000, 0.0000, 200.0000); //Gen_doorSHOP3
    SetObjectMaterial(Alhambara_Object[23], 0, 18246, "cw_junkyard2cs_t", "Was_scrpyd_door_dbl_grey", 0xFFFFFFFF);
    Alhambara_Object[24] = CreateObject(1522, 1630.7021, -1199.5648, 35.9444, 0.0000, 0.0000, 0.0000, 200.0000); //Gen_doorSHOP3
    SetObjectMaterial(Alhambara_Object[24], 0, 18246, "cw_junkyard2cs_t", "Was_scrpyd_door_dbl_grey", 0xFFFFFFFF);
    Alhambara_Object[25] = CreateObject(4227, 1811.5620, -1788.9355, 14.3879, 0.0000, 0.0000, 90.1996, 300.0000); //graffiti_lan01
    Alhambara_Object[26] = CreateObject(1256, 1729.8254, -1772.7823, 13.1225, 0.0000, 0.0000, 0.0000, 100.0000); //Stonebench1
    Alhambara_Object[27] = CreateObject(1256, 1729.8254, -1785.4228, 13.1225, 0.0000, 0.0000, 0.0000, 100.0000); //Stonebench1
    Alhambara_Object[28] = CreateObject(1256, 1706.6650, -1785.4228, 13.1920, 0.0000, 0.0000, 180.0000, 100.0000); //Stonebench1
    Alhambara_Object[29] = CreateObject(1256, 1706.6650, -1769.9033, 13.1724, 0.0000, 0.0000, 180.0000, 100.0000); //Stonebench1
	*/
	
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

	//Idlewood Liquor
	tmpobjid = CreateDynamicObject(19482, 2131.473144, -1778.100830, 14.590969, 0.000000, 0.000000, 90.000000, -1, -1, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 5998, "sunstr_lawn", "ganggraf02_LA", 0x00000000);
	tmpobjid = CreateDynamicObject(19482, 2138.483154, -1778.100830, 15.460397, -10.800001, 0.000000, 90.000000, -1, -1, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 4981, "wiresetc2_las", "ganggraf03_LA", 0x00000000);
	tmpobjid = CreateDynamicObject(19482, 2128.670410, -1771.259521, 15.130972, 0.000000, 0.000000, 360.000000, -1, -1, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 5390, "glenpark7_lae", "ganggraf01_LA", 0x00000000);
	tmpobjid = CreateDynamicObject(19482, 2141.724609, -1771.259521, 15.800987, -7.799997, 0.000000, 540.000000, -1, -1, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 5114, "beach_las2", "ganggraf04_LA", 0x00000000);
	tmpobjid = CreateDynamicObject(19572, 2141.397216, -1763.974731, 14.160981, 0.000000, 0.000000, 90.000000, -1, -1, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 12848, "cunte_town1", "sprunk_temp", 0x00000000);
	tmpobjid = CreateDynamicObject(19572, 2141.437255, -1763.974731, 13.310977, 0.000000, 0.000000, 90.000000, -1, -1, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 1488, "dyn_objects", "CJ_bottle3", 0x00000000);
	tmpobjid = CreateDynamicObject(19572, 2141.397216, -1764.735473, 14.160981, 0.000007, 0.000000, 89.999977, -1, -1, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 12848, "cunte_town1", "sprunk_temp", 0x00000000);
	tmpobjid = CreateDynamicObject(19572, 2141.437255, -1764.735473, 13.310977, 0.000007, 0.000000, 89.999977, -1, -1, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 1488, "dyn_objects", "CJ_bottle3", 0x00000000);
	tmpobjid = CreateDynamicObject(19572, 2141.397216, -1765.565917, 14.160981, 0.000015, 0.000000, 89.999954, -1, -1, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 12848, "cunte_town1", "sprunk_temp", 0x00000000);
	tmpobjid = CreateDynamicObject(19572, 2141.437255, -1765.565917, 13.310977, 0.000015, 0.000000, 89.999954, -1, -1, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 1488, "dyn_objects", "CJ_bottle3", 0x00000000);
	tmpobjid = CreateDynamicObject(19572, 2141.397216, -1766.456542, 14.160981, 0.000022, 0.000000, 89.999931, -1, -1, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 12848, "cunte_town1", "sprunk_temp", 0x00000000);
	tmpobjid = CreateDynamicObject(19572, 2141.437255, -1766.456542, 13.310977, 0.000022, 0.000000, 89.999931, -1, -1, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 1488, "dyn_objects", "CJ_bottle3", 0x00000000);
	tmpobjid = CreateDynamicObject(19572, 2141.397216, -1767.307250, 14.160981, 0.000030, 0.000000, 89.999908, -1, -1, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 12848, "cunte_town1", "sprunk_temp", 0x00000000);
	tmpobjid = CreateDynamicObject(19572, 2141.437255, -1767.307250, 13.310977, 0.000030, 0.000000, 89.999908, -1, -1, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 1488, "dyn_objects", "CJ_bottle3", 0x00000000);
	tmpobjid = CreateDynamicObject(19572, 2141.397216, -1768.228027, 14.160981, 0.000038, 0.000000, 89.999885, -1, -1, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 12848, "cunte_town1", "sprunk_temp", 0x00000000);
	tmpobjid = CreateDynamicObject(19572, 2141.437255, -1768.228027, 13.310977, 0.000038, 0.000000, 89.999885, -1, -1, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 1488, "dyn_objects", "CJ_bottle3", 0x00000000);
	tmpobjid = CreateDynamicObject(19572, 2141.397216, -1770.208251, 14.160981, 0.000045, 0.000000, 89.999862, -1, -1, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 12848, "cunte_town1", "sprunk_temp", 0x00000000);
	tmpobjid = CreateDynamicObject(19572, 2141.437255, -1770.208251, 13.310977, 0.000045, 0.000000, 89.999862, -1, -1, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 1488, "dyn_objects", "CJ_bottle3", 0x00000000);
	tmpobjid = CreateDynamicObject(19572, 2141.397216, -1770.848754, 14.160981, 0.000053, 0.000000, 89.999839, -1, -1, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 12848, "cunte_town1", "sprunk_temp", 0x00000000);
	tmpobjid = CreateDynamicObject(19572, 2141.437255, -1770.848754, 13.310977, 0.000053, 0.000000, 89.999839, -1, -1, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 1488, "dyn_objects", "CJ_bottle3", 0x00000000);
	tmpobjid = CreateDynamicObject(19572, 2141.397216, -1771.599365, 14.160981, 0.000061, 0.000000, 89.999816, -1, -1, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 12848, "cunte_town1", "sprunk_temp", 0x00000000);
	tmpobjid = CreateDynamicObject(19572, 2141.437255, -1771.599365, 13.310977, 0.000061, 0.000000, 89.999816, -1, -1, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 1488, "dyn_objects", "CJ_bottle3", 0x00000000);
	tmpobjid = CreateDynamicObject(19572, 2141.397216, -1772.479614, 14.160981, 0.000068, 0.000000, 89.999794, -1, -1, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 12848, "cunte_town1", "sprunk_temp", 0x00000000);
	tmpobjid = CreateDynamicObject(19572, 2141.437255, -1772.479614, 13.310977, 0.000068, 0.000000, 89.999794, -1, -1, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 1488, "dyn_objects", "CJ_bottle3", 0x00000000);
	tmpobjid = CreateDynamicObject(19572, 2141.397216, -1773.229614, 14.160981, 0.000076, 0.000000, 89.999771, -1, -1, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 12848, "cunte_town1", "sprunk_temp", 0x00000000);
	tmpobjid = CreateDynamicObject(19572, 2141.437255, -1773.229614, 13.310977, 0.000076, 0.000000, 89.999771, -1, -1, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 1488, "dyn_objects", "CJ_bottle3", 0x00000000);
	tmpobjid = CreateDynamicObject(19572, 2141.397216, -1774.010009, 14.160981, 0.000083, 0.000000, 89.999748, -1, -1, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 12848, "cunte_town1", "sprunk_temp", 0x00000000);
	tmpobjid = CreateDynamicObject(19572, 2141.437255, -1774.010009, 13.310977, 0.000083, 0.000000, 89.999748, -1, -1, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 1488, "dyn_objects", "CJ_bottle3", 0x00000000);
	tmpobjid = CreateDynamicObject(19572, 2141.397216, -1774.640502, 14.160981, 0.000091, 0.000000, 89.999725, -1, -1, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 12848, "cunte_town1", "sprunk_temp", 0x00000000);
	tmpobjid = CreateDynamicObject(19572, 2141.437255, -1774.640502, 13.310977, 0.000091, 0.000000, 89.999725, -1, -1, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 1488, "dyn_objects", "CJ_bottle3", 0x00000000);
	tmpobjid = CreateDynamicObject(2541, 2129.127441, -1770.694702, 12.640960, 0.000000, 0.000000, 90.000000, -1, -1, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 1419, "break_fence3", "CJ_FRAME_Glass", 0x00000000);
	SetDynamicObjectMaterial(tmpobjid, 6, 1419, "break_fence3", "CJ_FRAME_Glass", 0x00000000);
	SetDynamicObjectMaterial(tmpobjid, 8, 1419, "break_fence3", "CJ_FRAME_Glass", 0x00000000);
	tmpobjid = CreateDynamicObject(2541, 2129.117431, -1772.215454, 12.640960, 0.000000, 0.000000, 90.000000, -1, -1, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 1419, "break_fence3", "CJ_FRAME_Glass", 0x00000000);
	SetDynamicObjectMaterial(tmpobjid, 6, 1419, "break_fence3", "CJ_FRAME_Glass", 0x00000000);
	SetDynamicObjectMaterial(tmpobjid, 8, 1419, "break_fence3", "CJ_FRAME_Glass", 0x00000000);
	tmpobjid = CreateDynamicObject(2541, 2129.127441, -1774.086914, 12.640960, 0.000000, 0.000000, 90.000000, -1, -1, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 1419, "break_fence3", "CJ_FRAME_Glass", 0x00000000);
	SetDynamicObjectMaterial(tmpobjid, 6, 1419, "break_fence3", "CJ_FRAME_Glass", 0x00000000);
	SetDynamicObjectMaterial(tmpobjid, 8, 1419, "break_fence3", "CJ_FRAME_Glass", 0x00000000);
	tmpobjid = CreateDynamicObject(2541, 2129.127441, -1767.896118, 12.640960, 0.000000, 0.000000, 90.000000, -1, -1, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 1419, "break_fence3", "CJ_FRAME_Glass", 0x00000000);
	SetDynamicObjectMaterial(tmpobjid, 6, 1419, "break_fence3", "CJ_FRAME_Glass", 0x00000000);
	SetDynamicObjectMaterial(tmpobjid, 8, 1419, "break_fence3", "CJ_FRAME_Glass", 0x00000000);
	tmpobjid = CreateDynamicObject(2541, 2129.127441, -1764.286010, 12.640960, 0.000000, 0.000000, 90.000000, -1, -1, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 1419, "break_fence3", "CJ_FRAME_Glass", 0x00000000);
	SetDynamicObjectMaterial(tmpobjid, 6, 1419, "break_fence3", "CJ_FRAME_Glass", 0x00000000);
	SetDynamicObjectMaterial(tmpobjid, 8, 1419, "break_fence3", "CJ_FRAME_Glass", 0x00000000);
	tmpobjid = CreateDynamicObject(2541, 2129.127441, -1766.126464, 12.640960, 0.000000, 0.000000, 90.000000, -1, -1, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 1419, "break_fence3", "CJ_FRAME_Glass", 0x00000000);
	SetDynamicObjectMaterial(tmpobjid, 6, 1419, "break_fence3", "CJ_FRAME_Glass", 0x00000000);
	SetDynamicObjectMaterial(tmpobjid, 8, 1419, "break_fence3", "CJ_FRAME_Glass", 0x00000000);
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	tmpobjid = CreateDynamicObject(-25601, 2148.893554, -1791.782470, 19.097839, 0.000000, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(1522, 2128.548095, -1762.298339, 12.522499, 0.000000, 0.000000, 48.099987, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(1522, 2131.016601, -1761.839965, 12.574217, 9.299998, 0.000000, -1.600039, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(1984, 2139.112060, -1777.671508, 12.550964, 0.000000, 0.000000, 90.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(1849, 2141.381835, -1772.377685, 12.550964, 0.000000, 0.000000, -90.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(1849, 2141.381835, -1766.057861, 12.550964, 0.000000, 0.000000, -90.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(1848, 2135.794433, -1766.071166, 12.550964, 0.000000, 0.000000, 90.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(955, 2132.279785, -1762.783447, 12.930971, 0.000000, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(1984, 2130.840820, -1775.650878, 12.550964, 0.000000, 0.000000, 270.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(1848, 2135.780517, -1772.361206, 12.550964, 0.000000, 0.000000, 90.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(1848, 2134.783447, -1766.071166, 12.550964, 0.000000, 0.000000, 270.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(1848, 2134.783447, -1772.353637, 12.550964, 0.000000, 0.000000, 270.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(1849, 2129.020019, -1766.057861, 12.550964, 0.000000, 0.000000, 90.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(1849, 2129.051269, -1772.377685, 12.550964, 0.000000, 0.000000, 90.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(2541, 2129.147460, -1769.193237, 13.060970, 0.000000, 0.000000, 90.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(2541, 2141.294433, -1769.193237, 13.060970, 0.000000, 0.000000, 270.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(19572, 2141.267089, -1763.974731, 12.860968, 0.000000, 0.000000, 90.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(19572, 2141.267089, -1764.735473, 12.860968, 0.000007, 0.000000, 89.999977, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(19572, 2141.267089, -1765.565917, 12.860968, 0.000015, 0.000000, 89.999954, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(19572, 2141.267089, -1766.456542, 12.860968, 0.000022, 0.000000, 89.999931, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(19572, 2141.267089, -1767.307250, 12.860968, 0.000030, 0.000000, 89.999908, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(19572, 2141.267089, -1768.228027, 12.860968, 0.000038, 0.000000, 89.999885, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(19572, 2141.267089, -1770.208251, 12.860968, 0.000045, 0.000000, 89.999862, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(19572, 2141.267089, -1770.848754, 12.860968, 0.000053, 0.000000, 89.999839, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(19572, 2141.267089, -1771.599365, 12.860968, 0.000061, 0.000000, 89.999816, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(19572, 2141.267089, -1772.479614, 12.860968, 0.000068, 0.000000, 89.999794, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(19572, 2141.267089, -1773.229614, 12.860968, 0.000076, 0.000000, 89.999771, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(19572, 2141.267089, -1774.010009, 12.860968, 0.000083, 0.000000, 89.999748, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(19572, 2141.267089, -1774.640502, 12.860968, 0.000091, 0.000000, 89.999725, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(2443, 2135.231445, -1777.756958, 12.550964, 0.000000, 0.000000, 180.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(2673, 2131.644775, -1770.202270, 12.550964, 0.000000, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(2673, 2139.676269, -1767.868041, 12.550964, 0.000000, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(2673, 2138.189697, -1763.745605, 12.550964, 0.000000, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(2673, 2137.900390, -1776.517333, 12.550964, 0.000000, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(2673, 2132.000488, -1776.439331, 12.550964, 0.000000, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(2673, 2132.328125, -1765.398437, 12.550964, 0.000000, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(2674, 2138.959472, -1772.815429, 12.550964, 0.000000, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(2674, 2132.219238, -1776.266357, 12.550964, 0.000000, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(2674, 2130.681152, -1767.076049, 12.550964, 0.000000, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(2673, 2133.868408, -1760.532958, 12.557804, 0.000000, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(2673, 2143.019287, -1759.506469, 12.550988, 0.000000, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(2673, 2126.554931, -1759.599243, 12.562500, 0.000000, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(2673, 2127.134033, -1766.460571, 12.568567, 0.000000, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 

	//Westmont
	tmpobjid = CreateDynamicObject(-25606, 2141.8728, -1884.4298, 12.6302, 0.0000, 0.0000, 0.0000, -1, -1, -1, 800.00, 800.00); 
    tmpobjid = CreateDynamicObject(-25604, 2163.6718, -1873.6169, 15.8203, 0.0000, 0.0000, 0.0000, -1, -1, -1, 800.00, 800.00); 
    tmpobjid = CreateDynamicObject(-25609, 2167.0390, -1925.2031, 15.8281, 0.0000, 0.0000, 0.0000, -1, -1, -1, 800.00, 800.00); 
    tmpobjid = CreateDynamicObject(-25605, 2100.7656, -1870.1402, 13.7693, 0.0000, 0.0000, 90.0000, -1, -1, -1, 800.00, 800.00); 
    tmpobjid = CreateDynamicObject(-25608, 2115.0000, -1921.5234, 15.3900, 0.0000, 0.0000, 0.0000, -1, -1, -1, 800.00, 800.00); 
    tmpobjid = CreateDynamicObject(-25607, 2115.0000, -1921.5234, 15.3906, 0.0000, 0.0000, 0.0000, -1, -1, -1, 800.00, 800.00); 

	//TDF
	//tmpobjid = CreateDynamicObject(-25565, 1123.164550, -1020.754577, 37.301929, 0.000000, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
	//tmpobjid = CreateDynamicObject(-25566, 1123.167602, -1020.787780, 37.288917, 0.000000, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 

	//TDB
	/*tmpobjid = CreateDynamicObject(3697, 1183.781860, -1256.995605, 18.599679, 0.000000, 0.000000, 540.000000, -1, -1, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 14603, "bikeskool", "motel_wall3", 0x00000000);
	tmpobjid = CreateDynamicObject(19355, 1172.729492, -1235.792114, 17.477184, 0.000000, 90.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 17539, "landlae2c", "conc_slab_256", 0x00000000);
	tmpobjid = CreateDynamicObject(19355, 1172.729492, -1238.991699, 17.477184, 0.000000, 90.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 17539, "landlae2c", "conc_slab_256", 0x00000000);
	tmpobjid = CreateDynamicObject(19355, 1172.729492, -1239.471313, 17.478183, 0.000000, 90.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 17539, "landlae2c", "conc_slab_256", 0x00000000);
	tmpobjid = CreateDynamicObject(19355, 1176.220703, -1239.471313, 17.478183, 0.000000, 90.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 17539, "landlae2c", "conc_slab_256", 0x00000000);
	tmpobjid = CreateDynamicObject(19355, 1177.711181, -1239.471313, 17.477184, 0.000000, 90.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 17539, "landlae2c", "conc_slab_256", 0x00000000);
	tmpobjid = CreateDynamicObject(19355, 1196.332031, -1252.292602, 14.097164, 0.000000, 90.000015, 179.999893, -1, -1, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 17539, "landlae2c", "conc_slab_256", 0x00000000);
	tmpobjid = CreateDynamicObject(19355, 1196.332031, -1249.093017, 14.097164, 0.000000, 90.000015, 179.999893, -1, -1, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 17539, "landlae2c", "conc_slab_256", 0x00000000);
	tmpobjid = CreateDynamicObject(19355, 1196.332031, -1248.613403, 14.098163, 0.000000, 90.000015, 179.999893, -1, -1, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 17539, "landlae2c", "conc_slab_256", 0x00000000);
	tmpobjid = CreateDynamicObject(19355, 1192.840820, -1248.613403, 14.098163, 0.000000, 90.000015, 179.999893, -1, -1, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 17539, "landlae2c", "conc_slab_256", 0x00000000);
	tmpobjid = CreateDynamicObject(19355, 1189.900512, -1248.613403, 14.097164, 0.000000, 90.000015, 179.999893, -1, -1, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 17539, "landlae2c", "conc_slab_256", 0x00000000);
	tmpobjid = CreateDynamicObject(6006, 1183.699951, -1241.359985, 16.273399, 0.000000, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 17539, "landlae2c", "conc_slab_256", 0x00000000);
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	tmpobjid = CreateDynamicObject(-25593, 1185.282104, -1227.275390, 21.834644, 0.000000, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(1498, 1202.100097, -1228.869995, 20.764579, 0.000000, 0.000000, 90.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(1498, 1201.533081, -1225.952026, 20.817321, -8.199997, 0.000000, -86.300048, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(1498, 1190.718383, -1221.209838, 20.938884, -15.099996, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(1498, 1193.188598, -1220.411743, 20.663772, -0.699999, 0.000000, -138.299987, -1, -1, -1, 800.00, 800.00); 
	*/

	//Seville
	/*tmpobjid = CreateDynamicObject(1569, 2750.715576, -1972.407592, 15.926919, 0.000000, 0.000000, 450.000000, -1, -1, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 6284, "bev_law2", "comptdoor2", 0x00000000);
	tmpobjid = CreateDynamicObject(1569, 2750.715576, -1972.387573, 15.926919, 0.000000, 0.000000, 630.000000, -1, -1, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 6284, "bev_law2", "comptdoor2", 0x00000000);
	tmpobjid = CreateDynamicObject(1569, 2743.669433, -1982.350341, 15.926919, 0.000007, -0.000007, 179.999908, -1, -1, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 3584, "comedprj1_la", "whiwind1", 0x00000000);
	tmpobjid = CreateDynamicObject(1569, 2743.649414, -1982.350341, 15.926919, -0.000007, 0.000007, -0.000007, -1, -1, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 3584, "comedprj1_la", "whiwind1", 0x00000000);
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	tmpobjid = CreateDynamicObject(-25558, 2743.845947, -1965.431152, 16.993759, 0.000000, 0.000000, 270.000000, -1, -1, -1, 800.00, 800.00); 
	*/

	//Pizzastack
	tmpobjid = CreateDynamicObject(19482, 2092.236083, -1799.514892, 12.402797, 0.000000, 270.000000, 176.900009, -1, -1, -1, 800.00, 800.00); 
	SetDynamicObjectMaterialText(tmpobjid, 0, "{ffffff}EMPLOYEE ONLY", 130, "Ariel", 50, 1, 0x00000000, 0x00000000, 1);
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	tmpobjid = CreateDynamicObject(-25596, 2112.908447, -1797.091186, 19.340522, 0.000000, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(1226, 2122.922363, -1783.489379, 16.398399, 0.000000, 0.000000, -360.000061, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(19325, 2101.520751, -1798.456665, 13.592661, 0.000000, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(19325, 2101.520751, -1805.094482, 13.592661, 0.000000, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(19325, 2105.974853, -1790.293090, 14.007279, 0.000000, 0.000000, 90.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(19325, 2116.326171, -1795.785522, 13.592661, 0.000000, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(1522, 2101.631835, -1794.023315, 12.516330, 0.000000, 0.000000, -163.100021, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(1522, 2101.605957, -1792.552978, 12.516330, 0.000000, 0.000000, 810.999877, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(19325, 2105.974853, -1808.354370, 14.007279, 0.000000, 0.000000, 90.000000, -1, -1, -1, 800.00, 800.00); 


	//LSV
	tmpobjid = CreateDynamicObject(17954, 2577.229980, -1350.400024, 56.539100, 0.000000, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(-25581, 2540.833007, -1350.622192, 40.908519, 0.000000, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(-25582, 2549.581054, -1411.054321, 34.504783, 0.000000, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(-25583, 2548.661865, -1413.742675, 37.666473, 0.000000, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(-25584, 2561.020996, -1409.838500, 33.696670, 0.000000, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(-25585, 2556.306396, -1407.427124, 40.898323, 0.000000, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(-25586, 2553.969238, -1402.046630, 34.418621, 0.000000, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(-25587, 2548.122802, -1410.583862, 33.560352, 0.000000, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(-25588, 2548.389160, -1411.691894, 37.189205, 0.000000, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 

	//JeffersonMotel
	tmpobjid = CreateDynamicObject(-25553, 2222.952636, -1162.518798, 30.016845, 0.000000, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(-25554, 2184.455078, -1179.234008, 36.457843, 0.000000, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(1493, 2192.330078, -1151.340454, 33.791294, -12.199994, 0.000000, -0.000009, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(1493, 2233.599853, -1158.688232, 24.867200, 0.000000, 0.000000, -142.500076, -1, -1, -1, 800.00, 800.00); 

	//Ganton
	/*tmpobjid = CreateDynamicObject(19362, 2286.148925, -1798.073852, 14.186350, 0.000000, 0.000000, 90.000000, -1, -1, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 4833, "airprtrunway_las", "dockwall1", 0x00000000);
	tmpobjid = CreateDynamicObject(19482, 2284.632324, -1797.963500, 14.039594, 0.000000, 0.000000, 90.000000, -1, -1, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 5114, "beach_las2", "ganggraf04_LA", 0x00000000);
	tmpobjid = CreateDynamicObject(14414, 2285.494140, -1811.618896, 13.102623, 0.000000, 0.000000, 270.000000, -1, -1, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 3452, "bballvgnint", "Bow_Abattoir_Conc2", 0x00000000);
	SetDynamicObjectMaterial(tmpobjid, 1, 3452, "bballvgnint", "Bow_Abattoir_Conc2", 0x00000000);
	tmpobjid = CreateDynamicObject(19377, 2283.967041, -1809.661987, 10.696382, 0.000000, 0.000000, 90.000000, -1, -1, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 4833, "airprtrunway_las", "dockwall1", 0x00000000);
	tmpobjid = CreateDynamicObject(19377, 2283.967041, -1811.373657, 10.696382, 0.000000, 0.000000, 90.000000, -1, -1, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 4833, "airprtrunway_las", "dockwall1", 0x00000000);
	tmpobjid = CreateDynamicObject(19427, 2288.696289, -1810.510620, 14.159627, 0.000000, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 4833, "airprtrunway_las", "dockwall1", 0x00000000);
	tmpobjid = CreateDynamicObject(1498, 2281.980712, -1805.572021, 16.293272, 0.000000, 0.000000, 270.000000, -1, -1, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 17933, "carter_mainmap", "mp_apt1_brokedoor", 0x00000000);
	tmpobjid = CreateDynamicObject(1498, 2287.581298, -1775.045410, 16.285486, 0.000000, 0.000000, 180.000000, -1, -1, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 17933, "carter_mainmap", "mp_apt1_brokedoor", 0x00000000);
	tmpobjid = CreateDynamicObject(1498, 2283.874023, -1771.350463, 16.285486, 0.000000, 0.000000, 360.000000, -1, -1, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 17933, "carter_mainmap", "mp_apt1_brokedoor", 0x00000000);
	tmpobjid = CreateDynamicObject(1498, 2281.567138, -1797.842163, 16.283588, -8.299997, 0.000000, 270.000000, -1, -1, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 17933, "carter_mainmap", "mp_apt1_brokedoor", 0x00000000);
	tmpobjid = CreateDynamicObject(1498, 2281.567138, -1790.609863, 16.283588, -8.299997, 0.000000, 270.000000, -1, -1, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 17933, "carter_mainmap", "mp_apt1_brokedoor", 0x00000000);
	tmpobjid = CreateDynamicObject(19482, 2286.085693, -1799.777221, 16.303585, 0.000000, 90.000000, 90.000000, -1, -1, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 14415, "carter_block_2", "mp_motel_carpet1", 0x00000000);
	tmpobjid = CreateDynamicObject(2263, 2287.215820, -1798.108276, 17.924972, 0.000000, 12.699998, 0.000000, -1, -1, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 14489, "carlspics", "AH_picture2", 0x00000000);
	tmpobjid = CreateDynamicObject(2263, 2285.399658, -1798.108276, 17.923894, 0.000000, 0.600000, 0.000000, -1, -1, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 14489, "carlspics", "AH_picture3", 0x00000000);
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	tmpobjid = CreateDynamicObject(-25594, 2283.248779, -1790.520874, 16.999298, 0.000000, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(-25595, 2283.163085, -1790.650268, 16.176084, 0.000000, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(615, 668.531005, -1083.199951, 46.757801, 0.000000, 0.000000, -89.999992, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(17887, 2343.610107, -1784.510009, 20.312500, 0.000000, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(1498, 2284.636718, -1806.747802, 12.556343, 0.000000, 0.000000, 92.099937, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(2121, 2285.156250, -1798.682983, 13.036587, 0.000000, 0.000000, 58.700008, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(2121, 2284.952636, -1800.218750, 13.036587, 0.000000, 0.000000, 98.500053, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(1728, 2287.872802, -1809.127929, 12.574940, 0.000000, 0.000000, 180.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(1670, 2286.042724, -1809.088989, 13.089611, 0.000000, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(2674, 2286.140136, -1802.159057, 12.576128, 0.000000, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(2675, 2287.835205, -1807.680908, 12.576108, 0.000000, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(2675, 2283.443359, -1793.335937, 12.576343, 0.000000, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(2673, 2285.179443, -1782.209472, 12.569610, 0.000000, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(2675, 2278.925048, -1781.270751, 12.569610, 0.000000, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(2674, 2281.343017, -1777.814819, 12.589611, 0.000000, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(1728, 2283.934570, -1796.452392, 12.576343, 0.000000, 0.000000, 180.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(2121, 2282.165283, -1789.962280, 13.076352, 0.000000, 0.000000, 69.000022, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(2121, 2282.889160, -1788.076416, 13.066352, 0.000000, 0.000000, 33.500022, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(2674, 2282.442871, -1788.606933, 12.569610, 0.000000, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(1728, 2282.962402, -1786.222534, 12.539609, 0.000000, 0.000000, 180.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(2675, 2285.052001, -1776.513916, 12.639612, 0.000000, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(2121, 2277.394287, -1779.788574, 13.019614, 0.000000, 0.000000, 38.499992, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(2121, 2279.132568, -1778.900024, 13.019614, 0.000000, 0.000000, -5.900000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(19572, 2280.210205, -1786.176513, 12.569610, 0.000000, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(2311, 2281.848388, -1793.744628, 12.576343, 0.000000, 0.000000, 90.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(19572, 2281.770996, -1792.095458, 13.086346, 0.000000, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(19572, 2281.770996, -1792.535888, 13.086346, 0.000000, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(2860, 2281.896972, -1793.385498, 13.086352, 0.000000, 0.000000, 85.799972, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(19820, 2281.730468, -1793.999633, 13.066344, 0.000000, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(1893, 2284.287109, -1792.211181, 16.526367, 0.000000, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(1893, 2284.287109, -1782.009643, 16.526367, 0.000000, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(1728, 2287.583007, -1798.092529, 16.268848, 0.000000, 0.000000, -13.100000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(1728, 2283.560302, -1798.141601, 16.268848, 0.000000, 0.000000, 0.700001, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(2315, 2285.345703, -1799.366333, 16.272495, 0.000000, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(19820, 2285.155517, -1799.262084, 16.771720, 0.000000, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(1670, 2285.794921, -1799.241699, 16.780605, 0.000000, 0.000000, 40.699996, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(1728, 2288.714843, -1801.279907, 16.268848, 0.000000, 0.000000, 180.699996, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(1728, 2285.034179, -1801.324829, 16.268848, 0.000000, 0.000000, 172.100006, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(19572, 2286.653564, -1799.572875, 16.752761, 0.000000, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(19572, 2286.893798, -1799.152465, 16.752761, 0.000000, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(1728, 2287.751464, -1788.444458, 16.268848, 0.000000, 0.000000, -43.599990, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(1743, 2288.027343, -1790.569702, 16.189691, 0.000000, 0.000000, 180.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(1429, 2287.558349, -1791.539428, 17.415109, 0.000000, 0.000000, 180.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(1788, 2286.787109, -1791.595458, 17.508474, 0.000000, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(2845, 2282.451416, -1791.995239, 16.315139, 0.000000, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(2315, 2284.206054, -1791.641601, 16.306526, 0.000000, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(2844, 2284.313964, -1792.093261, 16.802680, 0.000000, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(1711, 2284.144287, -1788.556152, 16.234617, 0.000000, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(2674, 2286.813720, -1789.932373, 16.302560, 0.000000, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(913, 2277.936523, -1805.567993, 16.285486, 0.000000, 0.000000, 180.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(1440, 2277.289550, -1794.589965, 16.753280, 0.000000, 0.000000, 90.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(1432, 2278.159179, -1790.111694, 16.385488, 0.000000, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(1670, 2278.065917, -1790.049316, 17.015499, 0.000000, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(2675, 2280.608398, -1795.580566, 16.293272, 0.000000, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(2675, 2280.259277, -1807.259765, 16.293272, 0.000000, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(2675, 2279.622802, -1812.229003, 16.297935, 0.000000, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(11730, 2277.246582, -1813.397949, 16.287935, 0.000000, 0.000000, 180.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(11730, 2277.907226, -1813.397949, 16.287935, 0.000000, 0.000000, 180.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(1369, 2277.749511, -1806.889770, 16.883285, 0.000000, 0.000000, 16.300001, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(2675, 2279.423339, -1779.222900, 16.363273, 0.000000, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(2675, 2280.629638, -1773.351684, 16.293272, 0.000000, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(2675, 2286.920898, -1772.455200, 16.285486, 0.000000, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(1462, 2281.156982, -1786.658447, 16.313272, 0.000000, 0.000000, 270.000000, -1, -1, -1, 800.00, 800.00); 
	*/
	
	//Frontyard
	//tmpobjid = CreateDynamicObject(-25559, 1883.505004, -1577.937622, 20.196878, 0.000000, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 

	//Elcorona Flat
	tmpobjid = CreateDynamicObject(-25573, 1983.819580, -2085.158447, 18.627683, 0.000000, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(-25574, 1981.547119, -2085.314208, 18.269657, 0.000000, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(-25575, 1983.810668, -2085.142578, 18.637987, 0.000000, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(-25576, 1976.681396, -2076.517822, 20.152694, 0.000000, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(-25577, 1988.843627, -2073.108154, 20.362567, 0.000000, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(-25578, 1976.391967, -2096.613281, 20.362234, 0.000000, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(-25579, 1988.391967, -2078.225585, 16.693155, 0.000000, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(-25580, 1988.367309, -2078.217773, 16.688690, 0.000000, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(17951, 1997.515869, -2095.718994, 15.589147, 0.000000, -83.399963, 0.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(1495, 1983.652343, -2075.852294, 12.510087, 0.000000, 0.000000, -71.199966, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(1495, 1983.664428, -2070.176269, 12.595181, 0.000000, 0.000000, -60.799968, -1, -1, -1, 800.00, 800.00); 

	//donut
	tmpobjid = CreateDynamicObject(-25599, 1014.592285, -1361.461669, 20.356273, 0.000000, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(1522, 1037.809204, -1341.150024, 12.718794, 0.000000, 0.000000, 56.499969, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(-25600, 1037.139404, -1349.018188, 14.642861, 0.000000, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 

	//Crenshaw
	tmpobjid = CreateDynamicObject(-25569, 2249.500000, -1433.358886, 22.929998, 0.000000, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(-25571, 2229.528320, -1433.852172, 24.917284, 0.000000, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(-25567, 2235.613037, -1429.360229, 26.244188, 0.000000, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(-25568, 2224.755371, -1432.185791, 24.267032, 0.000000, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(-25570, 2241.486083, -1433.453491, 31.266567, 0.000000, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 

	//Cluckin Bell
	tmpobjid = CreateDynamicObject(-25598, 2402.264404, -1503.656127, 29.024990, 0.000000, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(1533, 2419.300048, -1510.479980, 22.992200, 0.000000, 0.000000, 16.400003, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(1537, 2419.300048, -1507.469970, 22.992200, 0.000000, 0.000000, 89.999992, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(19325, 2419.115234, -1503.082031, 25.078271, 0.000000, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(19325, 2419.115234, -1496.439941, 25.078271, 0.000000, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(19325, 2415.784667, -1493.232177, 25.078271, 0.000000, 0.000000, 90.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(-25597, 2385.200683, -1906.543945, 18.446716, 0.000000, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(1522, 2395.269287, -1899.483276, 12.539095, 0.000009, 0.000000, 87.199996, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(1522, 2398.339111, -1899.379760, 12.539095, -0.000009, 0.000000, 179.999984, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(19325, 2384.567138, -1899.527099, 14.173914, 0.000000, 0.000000, 90.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(19325, 2391.201660, -1899.527099, 14.173914, 0.000000, 0.000000, 90.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(19325, 2381.039306, -1903.447265, 14.173914, 0.000000, 0.000000, 180.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(19325, 2398.985351, -1903.447265, 14.173914, 0.000000, 0.000000, 180.000000, -1, -1, -1, 800.00, 800.00); 

	/*//Bahamas
	tmpobjid = CreateDynamicObject(19482, 2038.023437, -1315.047729, 34.002094, 0.000000, 0.000000, 270.000000, -1, -1, -1, 800.00, 800.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 10101, "2notherbuildsfe", "Bow_Abpave_Gen", 0x00000000);
	SetDynamicObjectMaterialText(tmpobjid, 0, "{000000}CJ SAID FUCK U", 130, "Ariel", 30, 1, 0x00000000, 0x00000000, 1);
	tmpobjid = CreateDynamicObject(-25560, 2011.462768, -1300.896850, 28.695602, 0.000000, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(1498, 2036.777954, -1313.624755, 24.116359, 0.000000, 0.000000, 36.699981, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(1498, 2038.504394, -1310.592407, 24.139087, -15.299972, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(2674, 2041.967041, -1316.954711, 24.116359, 0.000000, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(2674, 2042.840332, -1315.244995, 27.070602, 0.000000, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(2675, 2042.832397, -1320.706665, 27.070602, 0.000000, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(2514, 2043.058105, -1281.581665, 27.086227, 0.000000, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(2522, 2041.715087, -1284.097534, 27.086227, 0.000000, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(2132, 2043.053466, -1285.246704, 27.070602, 0.000000, 0.000000, 270.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(2141, 2040.972900, -1287.145385, 27.030603, 0.000000, 0.000000, 180.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(1728, 2042.583251, -1291.008789, 27.070602, 0.000000, 0.000000, 180.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(2674, 2038.173583, -1288.619018, 27.080602, 0.000000, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(2675, 2040.055786, -1296.048461, 27.015914, 0.000000, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(2675, 2039.002075, -1283.511596, 27.070602, 0.000000, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(2121, 2037.310058, -1281.396362, 27.550613, 0.000000, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(2121, 2037.310058, -1283.877319, 27.550613, 0.000000, 0.000000, 78.100006, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(931, 2042.686889, -1293.033569, 28.075920, 0.000000, 0.000000, 90.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(2674, 2044.927734, -1296.898925, 27.070602, 0.000000, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(2673, 2044.876342, -1305.739746, 27.070602, 0.000000, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(2673, 2044.824462, -1314.132568, 27.070602, 0.000000, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(2673, 2044.835205, -1288.627929, 27.070602, 0.000000, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(2673, 2044.923828, -1283.163574, 27.070602, 0.000000, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(2674, 2045.009643, -1282.318725, 27.070602, 0.000000, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(2674, 2040.688232, -1313.032592, 30.059352, 0.000000, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(2675, 2042.887451, -1319.159301, 30.039352, 0.000000, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(2675, 2045.137451, -1308.523315, 30.039352, 0.000000, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(2673, 2044.834960, -1293.782470, 30.039352, 0.000000, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(2673, 2044.902099, -1286.488281, 30.039352, 0.000000, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(1812, 2043.084594, -1282.467529, 30.047164, 0.000000, 0.000000, 180.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(1740, 2041.055297, -1283.446044, 30.047164, 0.000000, 0.000000, 180.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(2674, 2041.790039, -1281.930908, 30.077165, 0.000000, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(1432, 2038.096801, -1290.661743, 30.047164, 0.000000, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(2674, 2038.556274, -1290.479492, 30.067165, 0.000000, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(2674, 2042.169189, -1291.192016, 30.077165, 0.000000, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(2673, 2041.898803, -1293.922729, 30.047164, 0.000000, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(2514, 2039.266235, -1292.223999, 30.062789, 0.000000, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(2522, 2038.248657, -1294.434082, 30.062789, 0.000000, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(2673, 2038.757080, -1283.710937, 30.047164, 0.000000, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(2675, 2039.680053, -1282.880126, 30.047164, 0.000000, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(2675, 2039.459350, -1287.384887, 30.047164, 0.000000, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(2675, 2044.980102, -1284.070312, 30.039352, 0.000000, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(2673, 2045.324584, -1321.541015, 30.039352, 0.000000, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(2121, 2037.775146, -1311.240234, 27.570610, 0.000000, 0.000000, 54.199996, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(2121, 2037.459594, -1312.924316, 27.570610, 0.000000, 0.000000, 100.299995, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(2121, 2037.392211, -1298.116577, 27.485925, 0.000000, 0.000000, 149.200012, -1, -1, -1, 800.00, 800.00); 
	tmpobjid = CreateDynamicObject(2121, 2037.214233, -1296.115600, 27.485925, 0.000000, 0.000000, 72.200027, -1, -1, -1, 800.00, 800.00); 
	*/

	//Ganton24
	tmpobjid = CreateDynamicObject(-25602, 2450.767333, -1757.388916, 16, 0.000000, 0.000000, 0.000000, -1, -1, -1, 800.00, 800.00);
    tmpobjid = CreateDynamicObject(-25603, 2428.597900, -1747.966674, 12.646861, 0.000000, 0.000000, -90.0, -1, 0, -1, 800.00, 800.00); 

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

	//Record Labels
	tmpobjid = CreateDynamicObject(19379, 1397.698486, -1689.474975, 40.502990, 0.000000, 90.000000, 0.000000, -1, 5, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 17081, "cuntwlandcent", "ws_traingravel", 0x00000000);
	tmpobjid = CreateDynamicObject(19379, 1397.698486, -1679.855102, 40.502990, 0.000000, 90.000000, 0.000000, -1, 5, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 17081, "cuntwlandcent", "ws_traingravel", 0x00000000);
	tmpobjid = CreateDynamicObject(19379, 1392.417358, -1689.474975, 39.103042, 0.000000, 180.000000, 0.000000, -1, 5, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 14668, "711c", "cj_white_wall2", 0x00000000);
	tmpobjid = CreateDynamicObject(19379, 1392.417358, -1679.844970, 39.103042, 0.000000, 180.000000, 0.000000, -1, 5, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 14668, "711c", "cj_white_wall2", 0x00000000);
	tmpobjid = CreateDynamicObject(19379, 1402.987670, -1689.474975, 39.103042, 0.000000, 180.000000, 0.000000, -1, 5, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 14668, "711c", "cj_white_wall2", 0x00000000);
	tmpobjid = CreateDynamicObject(19379, 1402.987670, -1679.844970, 39.103042, 0.000000, 180.000000, 0.000000, -1, 5, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 14668, "711c", "cj_white_wall2", 0x00000000);
	tmpobjid = CreateDynamicObject(19379, 1397.698486, -1678.196655, 39.553039, 90.000000, 90.000000, 0.000000, -1, 5, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 14668, "711c", "cj_white_wall2", 0x00000000);
	tmpobjid = CreateDynamicObject(19379, 1397.698486, -1694.216064, 39.553039, 90.000000, 90.000000, 0.000000, -1, 5, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 14668, "711c", "cj_white_wall2", 0x00000000);
	tmpobjid = CreateDynamicObject(19379, 1397.698486, -1689.474975, 44.023056, 0.000000, 90.000015, 0.000000, -1, 5, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 16640, "a51", "ws_stationfloor", 0x00000000);
	tmpobjid = CreateDynamicObject(19379, 1397.698486, -1679.855102, 44.023056, 0.000000, 90.000015, 0.000000, -1, 5, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 16640, "a51", "ws_stationfloor", 0x00000000);
	tmpobjid = CreateDynamicObject(19389, 1397.273437, -1689.499877, 42.238941, 0.000000, 0.000007, 0.000000, -1, 5, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 14668, "711c", "cj_white_wall2", 0x00000000);
	tmpobjid = CreateDynamicObject(19359, 1397.283203, -1692.512329, 42.238899, 0.000000, 0.000000, 0.000000, -1, 5, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 14668, "711c", "cj_white_wall2", 0x00000000);
	tmpobjid = CreateDynamicObject(19359, 1395.742065, -1692.512329, 42.238899, 0.000000, 0.000000, 270.000000, -1, 5, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 14668, "711c", "cj_white_wall2", 0x00000000);
	tmpobjid = CreateDynamicObject(19405, 1401.393432, -1687.975708, 42.228916, 0.000000, 0.000000, 90.000000, -1, 5, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 14668, "711c", "cj_white_wall2", 0x00000000);
	tmpobjid = CreateDynamicObject(19405, 1398.905517, -1687.965698, 42.228916, 0.000000, 0.000000, 90.000000, -1, 5, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 14668, "711c", "cj_white_wall2", 0x00000000);
	tmpobjid = CreateDynamicObject(1492, 1397.269775, -1688.700561, 40.588928, 0.000000, 0.000000, 270.000000, -1, 5, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 1, 1569, "adam_v_doort", "ws_guardhousedoor", 0x00000000);
	tmpobjid = CreateDynamicObject(19359, 1395.722045, -1690.320434, 42.238899, 0.000000, 0.000000, 270.000000, -1, 5, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 14668, "711c", "cj_white_wall2", 0x00000000);
	tmpobjid = CreateDynamicObject(19359, 1392.731201, -1690.320434, 42.238899, 0.000000, 0.000000, 270.000000, -1, 5, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 14668, "711c", "cj_white_wall2", 0x00000000);
	tmpobjid = CreateDynamicObject(2395, 1402.841186, -1688.548095, 41.238880, 0.000000, 0.000000, 270.000000, -1, 5, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 3967, "cj_airprt", "CJ_BLACK_RUB2", 0x00000000);
	tmpobjid = CreateDynamicObject(2395, 1402.841186, -1692.218505, 41.238880, 0.000000, 0.000000, 270.000000, -1, 5, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 3967, "cj_airprt", "CJ_BLACK_RUB2", 0x00000000);
	tmpobjid = CreateDynamicObject(2395, 1402.430786, -1694.080078, 41.238880, 0.000000, 0.000000, 540.000000, -1, 5, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 3967, "cj_airprt", "CJ_BLACK_RUB2", 0x00000000);
	tmpobjid = CreateDynamicObject(2395, 1398.720336, -1694.080078, 41.238880, 0.000000, 0.000000, 540.000000, -1, 5, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 3967, "cj_airprt", "CJ_BLACK_RUB2", 0x00000000);
	tmpobjid = CreateDynamicObject(2395, 1397.419677, -1693.629638, 41.238880, 0.000000, 0.000000, 810.000000, -1, 5, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 3967, "cj_airprt", "CJ_BLACK_RUB2", 0x00000000);
	tmpobjid = CreateDynamicObject(19482, 1402.866943, -1691.257812, 43.068927, 0.000000, 0.000000, 180.000000, -1, 5, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 10101, "2notherbuildsfe", "Bow_Abpave_Gen", 0x00000000);
	SetDynamicObjectMaterialText(tmpobjid, 0, "{ff0000}R{ffffff}ecord Label{00ff00}S", 130, "Ariel", 30, 1, 0x00000000, 0x00000000, 1);
	tmpobjid = CreateDynamicObject(2395, 1392.598999, -1681.493652, 41.218875, 0.000000, 0.000000, 810.000000, -1, 5, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 3967, "cj_airprt", "CJ_BLACK_RUB2", 0x00000000);
	tmpobjid = CreateDynamicObject(2395, 1392.598999, -1685.203979, 41.218875, 0.000000, 0.000000, 810.000000, -1, 5, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 3967, "cj_airprt", "CJ_BLACK_RUB2", 0x00000000);
	tmpobjid = CreateDynamicObject(2395, 1392.598999, -1688.923828, 41.218875, 0.000000, 0.000000, 810.000000, -1, 5, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 3967, "cj_airprt", "CJ_BLACK_RUB2", 0x00000000);
	tmpobjid = CreateDynamicObject(2395, 1392.598999, -1692.654418, 41.218875, 0.000000, 0.000000, 810.000000, -1, 5, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 3967, "cj_airprt", "CJ_BLACK_RUB2", 0x00000000);
	tmpobjid = CreateDynamicObject(19482, 1392.644409, -1682.880004, 43.068927, -0.000000, 0.000000, -0.000015, -1, 5, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 10101, "2notherbuildsfe", "Bow_Abpave_Gen", 0x00000000);
	SetDynamicObjectMaterialText(tmpobjid, 0, "{ff0000}R{ffffff}ecord Label{00ff00}S", 130, "Ariel", 30, 1, 0x00000000, 0x00000000, 1);
	tmpobjid = CreateDynamicObject(2395, 1396.741943, -1690.184814, 41.218875, 0.000000, 0.000000, 900.000000, -1, 5, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 3967, "cj_airprt", "CJ_BLACK_RUB2", 0x00000000);
	tmpobjid = CreateDynamicObject(2395, 1393.021118, -1690.184814, 41.218875, 0.000000, 0.000000, 900.000000, -1, 5, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 3967, "cj_airprt", "CJ_BLACK_RUB2", 0x00000000);
	tmpobjid = CreateDynamicObject(2395, 1402.843017, -1684.674804, 41.218875, 0.000000, 0.000000, 990.000000, -1, 5, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 3967, "cj_airprt", "CJ_BLACK_RUB2", 0x00000000);
	tmpobjid = CreateDynamicObject(2395, 1402.843017, -1680.964843, 41.218875, 0.000000, 0.000000, 990.000000, -1, 5, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 3967, "cj_airprt", "CJ_BLACK_RUB2", 0x00000000);
	tmpobjid = CreateDynamicObject(2395, 1402.843017, -1677.262573, 41.218875, 0.000000, 0.000000, 990.000000, -1, 5, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 3967, "cj_airprt", "CJ_BLACK_RUB2", 0x00000000);
	tmpobjid = CreateDynamicObject(2395, 1399.661621, -1678.333618, 41.218875, 0.000000, 0.000000, 1080.000000, -1, 5, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 3967, "cj_airprt", "CJ_BLACK_RUB2", 0x00000000);
	tmpobjid = CreateDynamicObject(2395, 1395.941772, -1678.333618, 41.218875, 0.000000, 0.000000, 1080.000000, -1, 5, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 3967, "cj_airprt", "CJ_BLACK_RUB2", 0x00000000);
	tmpobjid = CreateDynamicObject(2395, 1392.513183, -1678.333618, 41.218875, 0.000000, 0.000000, 1080.000000, -1, 5, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 3967, "cj_airprt", "CJ_BLACK_RUB2", 0x00000000);
	tmpobjid = CreateDynamicObject(955, 1401.332031, -1678.752075, 40.968921, 0.000000, 0.000000, 0.000000, -1, 5, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 2221, "donut_tray", "rustycoffeerap_rb", 0x00000000);
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	tmpobjid = CreateDynamicObject(1536, 1399.194702, -1678.225830, 40.588928, 0.000000, 0.000000, 180.000000, -1, 5, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(1536, 1396.204589, -1678.265869, 40.588928, 0.000000, 0.000000, 360.000000, -1, 5, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(1649, 1400.159057, -1687.962158, 41.788951, 0.000000, 0.000000, 180.000000, -1, 5, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(1649, 1400.159057, -1687.962158, 41.788951, 0.000000, 0.000000, 360.000000, -1, 5, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(14391, 1393.452148, -1683.101318, 41.478946, 0.000000, 0.000000, 0.000000, -1, 5, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(19616, 1397.583862, -1687.687988, 40.588928, 0.000000, 0.000000, 180.000000, -1, 5, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(19317, 1398.264282, -1687.695800, 41.287067, -20.100000, 0.000000, 180.000000, -1, 5, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(2357, 1400.467529, -1683.883789, 40.978916, 0.000000, 0.000000, 90.000000, -1, 5, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(1715, 1402.090942, -1682.843505, 40.588928, 0.000000, 0.000000, 270.000000, -1, 5, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(1715, 1402.090942, -1684.794921, 40.588928, 0.000000, 0.000000, -115.999977, -1, 5, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(1715, 1400.804931, -1686.770019, 40.588928, 0.000000, 0.000000, -132.799942, -1, 5, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(1715, 1398.779907, -1684.894775, 40.588928, 0.000000, 0.000000, 114.600051, -1, 5, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(1715, 1398.763549, -1683.313720, 40.588928, 0.000000, 0.000000, 66.900039, -1, 5, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(19999, 1395.215209, -1683.159423, 40.588928, 0.000000, 0.000000, -29.899961, -1, 5, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(19611, 1400.054809, -1681.158447, 40.588928, 0.000000, 0.000000, 0.000000, -1, 5, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(19617, 1402.917846, -1681.629150, 42.678913, 0.000000, 0.000000, 270.000000, -1, 5, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(19617, 1402.917846, -1679.969238, 42.678913, 0.000000, 4.499999, 270.000000, -1, 5, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(2894, 1400.453125, -1682.300292, 41.388916, 0.000000, 0.000000, 60.499992, -1, 5, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(1669, 1400.696899, -1685.549560, 41.548931, 0.000000, 0.000000, 0.000000, -1, 5, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(1669, 1400.196411, -1684.748779, 41.548931, 0.000000, 0.000000, 0.000000, -1, 5, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(19897, 1400.100097, -1685.349243, 41.408901, 0.000000, 0.000000, -17.800001, -1, 5, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(19897, 1400.661987, -1685.266845, 41.408901, 0.000000, 0.000000, -17.800001, -1, 5, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(11737, 1397.682861, -1678.749633, 40.588928, 0.000000, 0.000000, 0.000000, -1, 5, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(2842, 1400.941650, -1685.470092, 41.366928, 0.000000, 0.000000, 90.000000, -1, 5, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(1665, 1400.546264, -1684.485107, 41.404899, 0.000000, 0.000000, 0.000000, -1, 5, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(2059, 1400.321166, -1682.979248, 41.398906, 0.000000, 0.000000, 0.000000, -1, 5, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(2002, 1392.839111, -1689.761474, 40.588928, 0.000000, 0.000000, 180.000000, -1, 5, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(19617, 1397.345581, -1692.347167, 42.778896, 0.000000, 0.000000, 90.000000, -1, 5, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(1708, 1397.866455, -1693.845825, 40.478939, 0.000000, 0.000000, 90.000000, -1, 5, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(1708, 1397.866455, -1691.935180, 40.478939, 0.000000, 0.000000, 90.000000, -1, 5, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(19611, 1400.335693, -1692.440063, 40.578945, 0.000000, 0.000000, -49.499984, -1, 5, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(19610, 1400.327026, -1692.441528, 42.208923, 0.000000, 0.000000, 112.100105, -1, 5, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(19613, 1399.787475, -1693.784790, 40.588947, 0.000000, 0.000000, 540.000000, -1, 5, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(19317, 1400.560546, -1693.931274, 41.309635, -15.999998, 0.000000, 174.999984, -1, 5, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(19786, 1403.017700, -1691.242431, 43.018898, 0.000000, 0.000000, 270.000000, -1, 5, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(14391, 1402.135375, -1691.320922, 41.478946, 0.000000, 0.000000, 180.000000, -1, 5, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(19786, 1392.493652, -1682.895385, 43.018898, 0.000000, 0.000000, 89.999938, -1, 5, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(2002, 1393.559814, -1689.761474, 40.588928, 0.000000, 0.000000, 180.000000, -1, 5, -1, 300.00, 300.00); 
	
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

	//Seville
	tmpobjid = CreateDynamicObject(-25562, 2674.1015, -1990.7889, 15.1875, 0.0000, 0.0000, 0.0000, -1, -1, -1, 800.00, 800.00);  //gtac/seville/sbf_vp.dff
    tmpobjid = CreateDynamicObject(-25563, 2651.4736, -2034.9664, 15.5515, 0.0000, 0.0000, 0.0000, -1, -1, -1, 800.00, 800.00);  //gtac/seville/sbf4_vp.dff

	CreateDynamicObject(3646, 2676.8830, -1953.7281, 14.8739, 0.0000, 0.0000, -90.0000, -1, 0, -1, 2000.00, 2000.00);  //ganghous05_LAx
    CreateDynamicObject(3648, 2640.6843, -1954.1063, 15.2740, 0.0000, 0.0000, -90.0000, -1, 0, -1, 2000.00, 2000.00);  //ganghous02_LAx
    CreateDynamicObject(3589, 2660.1662, -1951.4543, 15.2536, 0.0000, 0.0000, 0.0000, -1, 0, -1, 2000.00, 2000.00);  //compfukhouse3
    CreateDynamicObject(1419, 2658.0886, -1945.0477, 13.3992, 0.0000, 0.0000, 180.0000, -1, 0, -1, 200.00, 200.00);  //DYN_F_IRON_1
    CreateDynamicObject(1446, 2697.1005, -1942.3430, 13.3472, 0.0000, 0.0000, 180.0000, -1, 0, -1, 200.00, 200.00);  //DYN_F_R_WOOD_4
    CreateDynamicObject(1446, 2704.0036, -1948.2635, 13.3472, 0.0000, 0.0000, 90.0000, -1, 0, -1, 200.00, 200.00);  //DYN_F_R_WOOD_4
    CreateDynamicObject(1446, 2703.9836, -1944.6838, 13.3472, 0.0000, 0.0000, 90.0000, -1, 0, -1, 200.00, 200.00);  //DYN_F_R_WOOD_4
    CreateDynamicObject(1418, 2683.9208, -1942.3885, 13.2809, 0.0000, 0.0000, 0.0000, -1, 0, -1, 200.00, 200.00);  //DYN_F_WOOD_3
    CreateDynamicObject(1460, 2670.4216, -1942.3503, 13.3142, 0.0000, 0.0000, 180.0000, -1, 0, -1, 200.00, 200.00);  //DYN_F_R_WOOD_3
    CreateDynamicObject(1460, 2679.9216, -1942.3503, 13.3142, 0.0000, 0.0000, 180.0000, -1, 0, -1, 200.00, 200.00);  //DYN_F_R_WOOD_3
    CreateDynamicObject(1418, 2686.2006, -1944.0852, 13.2809, 0.0000, 0.0000, 106.8000, -1, 0, -1, 200.00, 200.00);  //DYN_F_WOOD_3
    CreateDynamicObject(1418, 2686.7011, -1947.5078, 13.2809, 0.0000, 0.0000, 90.0000, -1, 0, -1, 200.00, 200.00);  //DYN_F_WOOD_3
    CreateDynamicObject(1446, 2701.7416, -1942.3430, 13.3472, 0.0000, 0.0000, 180.0000, -1, 0, -1, 200.00, 200.00);  //DYN_F_R_WOOD_4
    CreateDynamicObject(1468, 2668.0236, -1944.9626, 13.7690, 0.0000, 0.0000, 90.0000, -1, 0, -1, 200.00, 200.00);  //DYN_MESH_05
    CreateDynamicObject(1468, 2665.3815, -1942.4012, 13.7690, 0.0000, 0.0000, 0.0000, -1, 0, -1, 200.00, 200.00);  //DYN_MESH_05
    tmpobjid = CreateDynamicObject(19325, 2670.8103, -1965.6656, 12.4905, 0.0000, 0.0000, 90.0000, -1, 0, -1, 200.00, 200.00);  //lsmall_window01
    SetDynamicObjectMaterial(tmpobjid, 0, 4981, "wiresetc2_las", "ganggraf03_LA", 0xFFFFFFFF);
    CreateDynamicObject(994, 2627.5957, -2043.0937, 12.5572, 0.0000, 0.0000, 0.0000, -1, 0, -1, 200.00, 200.00);  //lhouse_barrier2
    CreateDynamicObject(994, 2627.6552, -2049.4140, 12.5572, 0.0000, 0.0000, 90.0000, -1, 0, -1, 200.00, 200.00);  //lhouse_barrier2
    CreateDynamicObject(3557, 2695.8549, -1957.7043, 14.9870, 0.0000, 0.0000, 0.0000, -1, 0, -1, 800.00, 2000.00);  //compmedhos4_LAe
    tmpobjid = CreateDynamicObject(2256, 2750.8720, -1979.3092, 15.0747, 0.0000, -5.1999, 90.0000, -1, 0, -1, 200.00, 200.00);  //Frame_Clip_3
    SetDynamicObjectMaterial(tmpobjid, 0, 14801, "lee_bdupsmain", "Bdup_graf3", 0xFF000000);
    SetDynamicObjectMaterial(tmpobjid, 1, 19297, "matlights", "invisible", 0xFFFFFFFF);

	//TDF
	new Tdf_Object[364];
    Tdf_Object[0] = CreateObject(1362, 1269.6391, -893.6914, 42.4706, 0.0000, 0.0000, 5.7999, 200.0000); //CJ_FIREBIN_(L0)
    SetObjectMaterial(Tdf_Object[0], 0, 1328, "labins01_la", "cj_bin2", 0xFFFFFFFF);
    SetObjectMaterial(Tdf_Object[0], 1, 1574, "dyn_trash", "trash", 0xFFFFFFFF);
    SetObjectMaterial(Tdf_Object[0], 2, 19297, "matlights", "invisible", 0xFFFFFFFF);
    Tdf_Object[1] = CreateObject(3496, 1276.2032, -881.0482, 41.5651, 0.0000, 0.0000, -174.5997, 200.0000); //vgsxrefbballnet
    SetObjectMaterial(Tdf_Object[1], 0, 14785, "gen_offtrackint", "otb_mural4", 0xFFFFFFFF);
    SetObjectMaterial(Tdf_Object[1], 1, 16640, "a51", "banding9_64HV", 0xFFFFFFFF);
    SetObjectMaterial(Tdf_Object[1], 2, 2917, "a51_crane", "banding5_64HV", 0xFFFFFFFF);
    SetObjectMaterial(Tdf_Object[1], 3, 14785, "gen_offtrackint", "otb_mural1", 0xFFFFFFFF);
    SetObjectMaterial(Tdf_Object[1], 5, 16640, "a51", "scratchedmetal", 0xFFFFFFFF);
    Tdf_Object[2] = CreateObject(8674, 1265.3446, -897.1065, 43.3208, 0.0000, 0.0000, -84.4000, 250.0000); //csrsfence02_lvs
    Tdf_Object[3] = CreateObject(1437, 1304.0495, -895.8950, 46.2304, -20.4999, -0.1999, 96.0000, 200.0000); //DYN_LADDER_2
    SetObjectMaterial(Tdf_Object[3], 0, 3629, "arprtxxref_las", "metaldoor_128", 0xFFFFFFFF);
    Tdf_Object[4] = CreateObject(3035, 1269.7397, -895.2581, 42.6557, 0.0000, 0.0000, 96.1996, 200.0000); //tmp_bin
    Tdf_Object[5] = CreateObject(1208, 1269.6612, -891.7799, 42.1566, 90.0000, 0.0000, 4.9998, 200.0000); //washer
    Tdf_Object[6] = CreateObject(19995, 1269.5770, -893.7940, 42.5690, 16.7999, 90.0000, 0.0000, 75.0000); //CutsceneAmmoClip1
    Tdf_Object[7] = CreateObject(19995, 1269.5775, -893.6065, 42.6072, -1.2000, 101.9999, 90.4000, 75.0000); //CutsceneAmmoClip1
    Tdf_Object[8] = CreateObject(19874, 1269.6881, -893.7130, 42.5861, -3.3998, 9.9996, -55.0000, 75.0000); //SoapBar1
    SetObjectMaterial(Tdf_Object[8], 0, 1279, "craigpackage", "drugs", 0xFFFFFFFF);
    Tdf_Object[9] = CreateObject(8674, 1271.2253, -903.1801, 43.2807, 0.0000, 0.0000, -84.4000, 250.0000); //csrsfence02_lvs
    Tdf_Object[10] = CreateObject(8674, 1270.5688, -896.6945, 43.2807, 0.0000, 0.0000, -84.4000, 250.0000); //csrsfence02_lvs
    Tdf_Object[11] = CreateObject(639, 1265.4012, -897.2219, 42.7728, 0.0000, 0.0000, -175.4001, 250.0000); //veg_ivy_balcny_kb3
    SetObjectMaterial(Tdf_Object[11], 0, 17851, "cinemart_alpha", "kb_ivy2_256", 0xFFFFFFFF);
    Tdf_Object[13] = CreateObject(1712, 1303.1245, -883.5087, 41.8501, 0.0000, 0.0000, -91.3999, 130.0000); //kb_couch05
    Tdf_Object[14] = CreateObject(924, 1269.5704, -894.4766, 43.5527, 0.0000, 0.0000, 4.5998, 200.0000); //FRUITCRATE3
    SetObjectMaterial(Tdf_Object[14], 0, 2567, "ab", "Box_Texturepage", 0xFFFFFFFF);
    Tdf_Object[15] = CreateObject(2677, 1268.9099, -894.0197, 42.1543, 0.0000, 0.0000, 23.9999, 75.0000); //PROC_RUBBISH_7
    SetObjectMaterial(Tdf_Object[15], 0, 2765, "cj_cb_sign", "CJ_CB_POST1", 0xFFFFFFFF);
    SetObjectMaterial(Tdf_Object[15], 1, 2765, "cj_cb_sign", "CJ_CB_POST1", 0xFFFFFFFF);
    SetObjectMaterial(Tdf_Object[15], 2, 13363, "cephotoblockcs_t", "lampost_16clr", 0xFFFFFFFF);
    SetObjectMaterial(Tdf_Object[15], 3, 14690, "7_11_posters", "cokopops_1", 0xFFFFFFFF);
    SetObjectMaterial(Tdf_Object[15], 4, 2059, "cj_ammo2", "cj_don_post_1", 0xFFFFFFFF);
    SetObjectMaterial(Tdf_Object[15], 5, 14742, "mp3", "GB_rapposter05", 0xFF9CA1A3);
    Tdf_Object[16] = CreateObject(1265, 1266.1555, -899.9033, 42.1771, 0.0000, 0.0000, 127.5998, 200.0000); //BlackBag2
    Tdf_Object[17] = CreateObject(1439, 1266.2331, -901.2155, 42.0018, 0.0000, 0.0000, 95.5998, 250.0000); //DYN_DUMPSTER_1
    SetObjectMaterial(Tdf_Object[17], 1, 13059, "ce_fact03", "Ind_PKabin", 0xFFFFFFFF);
    Tdf_Object[18] = CreateObject(10252, 1270.4486, -907.8272, 43.5022, 0.0000, 0.0000, 7.1999, 250.0000); //china_town_gateb
    Tdf_Object[19] = CreateObject(10252, 1263.1793, -908.6798, 43.5022, 0.0000, 0.0000, 6.1999, 250.0000); //china_town_gateb
    Tdf_Object[20] = CreateObject(1710, 1276.8740, -890.2683, 41.8745, 0.0000, 0.0000, -173.7998, 200.0000); //kb_couch07
    Tdf_Object[21] = CreateObject(1670, 1300.8414, -884.6505, 42.6870, 0.0000, 0.0000, -87.7994, 100.0000); //propcollecttable
    SetObjectMaterial(Tdf_Object[21], 0, 1488, "dyn_objects", "CJ_bottle3", 0xFFFFFFFF);
    SetObjectMaterial(Tdf_Object[21], 6, 1486, "break_bar", "CJ_bottle", 0xFFFFFFFF);
    Tdf_Object[22] = CreateObject(2112, 1300.7950, -884.8643, 42.2605, 0.0000, 0.0000, 0.0000, 200.0000); //MED_DINNING_4
    SetObjectMaterial(Tdf_Object[22], 0, 13003, "ce_racestart", "CJ_TARTAN", 0xFFFFFFFF);
    Tdf_Object[23] = CreateObject(2112, 1300.7950, -883.4846, 42.2605, 0.0000, 0.0000, 0.0000, 200.0000); //MED_DINNING_4
    SetObjectMaterial(Tdf_Object[23], 0, 13003, "ce_racestart", "CJ_TARTAN", 0xFFFFFFFF);
    Tdf_Object[24] = CreateObject(1670, 1300.9465, -883.3350, 42.6870, 0.0000, 0.0000, -30.6000, 100.0000); //propcollecttable
    SetObjectMaterial(Tdf_Object[24], 0, 1488, "dyn_objects", "CJ_bottle3", 0xFFFFFFFF);
    SetObjectMaterial(Tdf_Object[24], 6, 1486, "break_bar", "CJ_bottle2", 0xFFFFFFFF);
    Tdf_Object[25] = CreateObject(2852, 1300.6955, -883.9495, 42.6487, 0.0000, 0.0000, -57.9999, 100.0000); //gb_bedmags02
    Tdf_Object[26] = CreateObject(1946, 1276.3916, -881.6079, 42.0312, 0.0000, 0.0000, 97.1996, 100.0000); //baskt_ball_hi
    Tdf_Object[27] = CreateObject(19325, 1304.3502, -884.3391, 42.2065, 1.1999, 0.0000, 0.0000, 200.0000); //lsmall_window01
    SetObjectMaterial(Tdf_Object[27], 0, 1530, "tags_lavagos", "vagos", 0xFF000000);
    Tdf_Object[28] = CreateObject(1707, 1247.7032, -906.6519, 45.4766, 0.0000, 0.0000, 98.5998, 250.0000); //kb_couch01
    Tdf_Object[29] = CreateObject(1933, 1287.2600, -900.8903, 46.0494, 0.0000, 0.0000, 0.0000, 100.0000); //chip_stack16
    Tdf_Object[30] = CreateObject(1827, 1287.4526, -900.3378, 45.6174, 0.0000, 0.0000, 0.0000, 200.0000); //man_sdr_tables
    SetObjectMaterial(Tdf_Object[30], 0, 18058, "mp_diner2", "mp_diner_table", 0xFFFFFFFF);
    SetObjectMaterial(Tdf_Object[30], 1, 18058, "mp_diner2", "mp_diner_table", 0xFFFFFFFF);
    Tdf_Object[31] = CreateObject(1933, 1288.0664, -900.4860, 46.0494, 0.0000, 0.0000, 6.8000, 100.0000); //chip_stack16
    SetObjectMaterial(Tdf_Object[31], 0, 1859, "chips2", "indx_chip432", 0xFFFFFFFF);
    Tdf_Object[32] = CreateObject(1933, 1287.9807, -900.5701, 46.0494, 0.0000, 0.0000, -45.4000, 100.0000); //chip_stack16
    SetObjectMaterial(Tdf_Object[32], 0, 1859, "chips2", "chip_stck6", 0xFFFFFFFF);
    Tdf_Object[33] = CreateObject(1933, 1287.3259, -899.8502, 46.0494, 0.0000, 0.0000, 6.8000, 100.0000); //chip_stack16
    SetObjectMaterial(Tdf_Object[33], 0, 1859, "chips2", "indx_chip432", 0xFFFFFFFF);
    Tdf_Object[34] = CreateObject(1933, 1287.4055, -899.8405, 46.0494, 0.0000, 0.0000, 65.9999, 100.0000); //chip_stack16
    SetObjectMaterial(Tdf_Object[34], 0, 1859, "chips2", "chip_stck3", 0xFFFFFFFF);
    Tdf_Object[35] = CreateObject(1933, 1287.0266, -900.0009, 46.0494, 0.0000, 0.0000, 65.9999, 100.0000); //chip_stack16
    SetObjectMaterial(Tdf_Object[35], 0, 1859, "chips2", "indx_chip164", 0xFFFFFFFF);
    Tdf_Object[36] = CreateObject(2660, 1287.5002, -900.3275, 46.0796, -90.0000, 0.0000, 28.3999, 100.0000); //CJ_BANNER06
    SetObjectMaterial(Tdf_Object[36], 0, 1827, "kbmiscfrn2", "man_mny1", 0xFFFFFFFF);
    Tdf_Object[37] = CreateObject(19825, 1285.1695, -900.8145, 47.9308, 0.0000, 0.0000, 96.3999, 100.0000); //SprunkClock1
    Tdf_Object[38] = CreateObject(8674, 1275.1966, -891.0114, 43.2807, 0.0000, 0.0000, 6.7999, 250.0000); //csrsfence02_lvs
    Tdf_Object[39] = CreateObject(2660, 1290.0233, -898.7976, 47.2573, 0.0000, 0.0000, -81.7994, 100.0000); //CJ_BANNER06
    SetObjectMaterial(Tdf_Object[39], 0, 10148, "bombshop_sfe", "calendar01", 0xFFFFFFFF);
    Tdf_Object[40] = CreateObject(2612, 1290.0716, -899.2653, 47.1977, 0.0000, 0.0000, -82.4000, 200.0000); //POLICE_NB2
    SetObjectMaterial(Tdf_Object[40], 0, 19297, "matlights", "invisible", 0xFFFFFFFF);
    SetObjectMaterial(Tdf_Object[40], 1, 19297, "matlights", "invisible", 0xFFFFFFFF);
    SetObjectMaterial(Tdf_Object[40], 3, 15054, "savesfmid", "cspornmag", 0xFFFFFFFF);
    Tdf_Object[41] = CreateObject(8674, 1259.7104, -892.5354, 43.3208, 0.0000, 0.0000, 6.3997, 250.0000); //csrsfence02_lvs
    Tdf_Object[42] = CreateObject(14826, 1266.1373, -873.2985, 42.5601, 0.0000, 0.0000, 96.7994, 250.0000); //int_kbsgarage2
    Tdf_Object[43] = CreateObject(18762, 1269.6584, -914.2133, 41.2172, 24.3999, 90.0000, 9.3999, 200.0000); //Concrete1mx1mx5m
    SetObjectMaterial(Tdf_Object[43], 0, 19297, "matlights", "invisible", 0xFFFFFFFF);
    Tdf_Object[44] = CreateObject(1704, 23.9458, -1.1094, 0.7487, 0.0000, 0.0000, 0.0000, 25.0000); //kb_chair03
    Tdf_Object[45] = CreateObject(19790, 1035.6936, -1001.0360, 32.8558, 0.0000, 0.0000, 90.0000, 75.0000); //Cube5mx5m
    SetObjectMaterial(Tdf_Object[45], 0, 5149, "lasground2_las2", "driveway4_128", 0xFFFFFFFF);
    Tdf_Object[46] = CreateObject(1522, 2073.4011, -2048.3034, 180.0000, 0.0000, 0.0000, 0.0000, 75.0000); //Gen_doorSHOP3
    Tdf_Object[47] = CreateObject(19393, 1036.6739, -1003.6173, 39.5167, 0.0000, 0.0000, 90.0000, 75.0000); //wall041
    SetObjectMaterial(Tdf_Object[47], 0, 5444, "chicano10_lae", "comptwall15", 0xFFFFFFFF);
    Tdf_Object[48] = CreateObject(19357, 1034.6556, -1003.6074, 37.2680, 0.0000, 0.0000, 90.0000, 250.0000); //wall005
    SetObjectMaterial(Tdf_Object[48], 0, 3193, "cxref_desert", "sw_woodslat01", 0xFFFFFFFF);
    Tdf_Object[49] = CreateObject(19357, 1033.1352, -1002.1370, 37.2680, 0.0000, 0.0000, 0.0000, 75.0000); //wall005
    SetObjectMaterial(Tdf_Object[49], 0, 3193, "cxref_desert", "sw_woodslat01", 0xFFFFFFFF);
    Tdf_Object[50] = CreateObject(8658, 1185.7977, -1305.8039, 13.4926, 0.0000, 0.0000, 180.0000, 300.0000); //shabbyhouse11_lvs
    SetObjectMaterial(Tdf_Object[50], 0, 9524, "blokmodb", "Bow_Grimebrick", 0xFFFFFFFF);
    Tdf_Object[51] = CreateObject(8661, 1165.8039, -1300.5937, 12.5289, 0.0000, 0.0000, 0.0000, 500.0000); //gnhtelgrnd_lvs
    SetObjectMaterial(Tdf_Object[51], 0, 4833, "airprtrunway_las", "greyground256", 0xFFFFFFFF);
    Tdf_Object[52] = CreateObject(10252, 1205.8204, -1118.4748, 24.5111, 0.0000, 0.0000, 180.0000, 120.0000); //china_town_gateb
    Tdf_Object[53] = CreateObject(10252, 1203.3601, -1118.4748, 24.5111, 0.0000, 0.0000, 180.0000, 120.0000); //china_town_gateb
    Tdf_Object[54] = CreateObject(19790, 1035.4355, -996.2567, 32.8460, 0.0000, 0.0000, 90.0000, 75.0000); //Cube5mx5m
    SetObjectMaterial(Tdf_Object[54], 0, 5149, "lasground2_las2", "driveway4_128", 0xFFFFFFFF);
    Tdf_Object[55] = CreateObject(19940, 1208.2380, -1117.8437, 23.3610, 0.0000, -10.6997, 90.0000, 75.0000); //MKShelf3
    SetObjectMaterial(Tdf_Object[55], 0, 3314, "ce_burbhouse", "ventc64", 0xFFFFFFFF);
    Tdf_Object[56] = CreateObject(19940, 1206.2480, -1117.8437, 23.3610, 0.0000, -10.6997, 90.0000, 75.0000); //MKShelf3
    SetObjectMaterial(Tdf_Object[56], 0, 3314, "ce_burbhouse", "ventc64", 0xFFFFFFFF);
    Tdf_Object[57] = CreateObject(2930, 1204.6197, -1117.7900, 26.1347, 0.0000, 0.0000, 161.6999, 75.0000); //chinaTgate
    SetObjectMaterial(Tdf_Object[57], 0, 4829, "airport_las", "fencekb_64h", 0xFF000000);
    SetObjectMaterial(Tdf_Object[57], 1, 11100, "bendytunnel_sfse", "blackmetal", 0xFFFFFFFF);
    Tdf_Object[58] = CreateObject(2930, 1206.9665, -1117.6914, 26.1347, 0.0000, 0.0000, 161.8999, 120.0000); //chinaTgate
    SetObjectMaterial(Tdf_Object[58], 0, 4829, "airport_las", "fencekb_64h", 0xFF000000);
    SetObjectMaterial(Tdf_Object[58], 1, 11100, "bendytunnel_sfse", "blackmetal", 0xFFFFFFFF);
    Tdf_Object[59] = CreateObject(19940, 1204.2578, -1117.8437, 23.3610, 0.0000, -10.6997, 90.0000, 75.0000); //MKShelf3
    SetObjectMaterial(Tdf_Object[59], 0, 3314, "ce_burbhouse", "ventc64", 0xFFFFFFFF);
    Tdf_Object[60] = CreateObject(19940, 1202.2578, -1117.8437, 23.3610, 0.0000, -10.6997, 90.0000, 100.0000); //MKShelf3
    SetObjectMaterial(Tdf_Object[60], 0, 3314, "ce_burbhouse", "ventc64", 0xFFFFFFFF);
    Tdf_Object[61] = CreateObject(19940, 1200.2473, -1117.8437, 23.3610, 0.0000, -10.6997, 90.0000, 100.0000); //MKShelf3
    SetObjectMaterial(Tdf_Object[61], 0, 3314, "ce_burbhouse", "ventc64", 0xFFFFFFFF);
    Tdf_Object[62] = CreateObject(19325, 1193.9305, -1159.5749, 24.5783, 0.0000, 0.0000, 90.0000, 250.0000); //lsmall_window01
    SetObjectMaterial(Tdf_Object[62], 0, 6404, "beafron1_law2", "shutter02LA", 0xFFFFFFFF);
    Tdf_Object[63] = CreateObject(19325, 1200.5522, -1159.5749, 24.5783, 0.0000, 0.0000, 90.0000, 250.0000); //lsmall_window01
    SetObjectMaterial(Tdf_Object[63], 0, 6404, "beafron1_law2", "shutter04LA", 0xFFFFFFFF);
    Tdf_Object[64] = CreateObject(19325, 1187.3098, -1159.5749, 24.5783, 0.0000, 0.0000, 90.0000, 250.0000); //lsmall_window01
    SetObjectMaterial(Tdf_Object[64], 0, 6404, "beafron1_law2", "shutter02LA", 0xFFFFFFFF);
    Tdf_Object[65] = CreateObject(19325, 1180.6888, -1159.5749, 24.5783, 0.0000, 0.0000, 90.0000, 250.0000); //lsmall_window01
    SetObjectMaterial(Tdf_Object[65], 0, 6404, "beafron1_law2", "shutter04LA", 0xFFFFFFFF);
    Tdf_Object[66] = CreateObject(19325, 1167.4206, -1159.5749, 24.5783, 0.0000, 0.0000, 90.0000, 250.0000); //lsmall_window01
    SetObjectMaterial(Tdf_Object[66], 0, 5461, "glenpark6d_lae", "shutter01LA", 0xFFFFFFFF);
    Tdf_Object[67] = CreateObject(19325, 1174.0400, -1159.5749, 24.5783, 0.0000, 0.0000, 90.0000, 250.0000); //lsmall_window01
    SetObjectMaterial(Tdf_Object[67], 0, 5461, "glenpark6d_lae", "shutter01LA", 0xFFFFFFFF);
    Tdf_Object[68] = CreateObject(19325, 1160.7912, -1159.5749, 24.5783, 0.0000, 0.0000, 90.0000, 250.0000); //lsmall_window01
    SetObjectMaterial(Tdf_Object[68], 0, 6404, "beafron1_law2", "shutter04LA", 0xFFFFFFFF);
    Tdf_Object[69] = CreateObject(19325, 1180.6888, -1159.5749, 29.3183, 0.0000, 0.0000, -90.0000, 250.0000); //lsmall_window01
    SetObjectMaterial(Tdf_Object[69], 0, 6282, "beafron2_law2", "hollysign02_LAw", 0xFFFFFFFF);
    Tdf_Object[70] = CreateObject(19325, 1200.4791, -1159.5749, 29.3183, 0.0000, 0.0000, -90.0000, 250.0000); //lsmall_window01
    SetObjectMaterial(Tdf_Object[70], 0, 17526, "eastls1_lae2", "comptsign3_LAe", 0xFFFFFFFF);
    Tdf_Object[71] = CreateObject(19325, 1161.0572, -1159.5749, 29.3183, 0.0000, 0.0000, -90.0000, 250.0000); //lsmall_window01
    SetObjectMaterial(Tdf_Object[71], 0, 17508, "barrio1_lae2", "gangsign4_LAe", 0xFFFFFFFF);
    Tdf_Object[72] = CreateObject(19368, 1210.7679, -1131.1800, 23.9022, 0.0000, 0.0000, 90.0000, 250.0000); //wall016
    SetObjectMaterial(Tdf_Object[72], 0, 13699, "cunte2_lahills", "laposhfence3", 0xFFFFFFFF);
    Tdf_Object[73] = CreateObject(1256, 1179.4433, -1159.1164, 23.5076, 0.0000, 0.0000, -90.0000, 250.0000); //Stonebench1
    Tdf_Object[74] = CreateObject(1256, 1159.2832, -1159.1164, 23.5076, 0.0000, 0.0000, -90.0000, 250.0000); //Stonebench1
    Tdf_Object[75] = CreateObject(19790, 1186.7170, -1120.4366, 18.3558, 0.0000, 0.0000, 90.0000, 120.0000); //Cube5mx5m
    SetObjectMaterial(Tdf_Object[75], 0, 5149, "lasground2_las2", "driveway4_128", 0xFFFFFFFF);
    Tdf_Object[76] = CreateObject(19790, 1181.7374, -1120.4366, 18.3558, 0.0000, 0.0000, 90.0000, 75.0000); //Cube5mx5m
    SetObjectMaterial(Tdf_Object[76], 0, 5149, "lasground2_las2", "driveway4_128", 0xFFFFFFFF);
    Tdf_Object[77] = CreateObject(2957, 1189.3260, -1127.4614, 24.5701, 0.0000, 0.0000, 90.6996, 120.0000); //chinaTgarageDoor
    SetObjectMaterial(Tdf_Object[77], 0, 3816, "bighangarsfxr", "ws_hangardoor", 0xFFFFFFFF);
    Tdf_Object[78] = CreateObject(19325, 1209.8913, -1126.6739, 25.1784, 0.0000, 0.0000, -179.3999, 250.0000); //lsmall_window01
    SetObjectMaterial(Tdf_Object[78], 0, 18024, "intclotheshiphop", "mp_cloth_sub", 0xFF072407);
    Tdf_Object[79] = CreateObject(2612, 1211.0100, -1131.3054, 24.4244, 0.0000, 0.0000, 0.0000, 250.0000); //POLICE_NB2
    SetObjectMaterial(Tdf_Object[79], 0, 19297, "matlights", "invisible", 0xFFFFFFFF);
    SetObjectMaterial(Tdf_Object[79], 1, 19297, "matlights", "invisible", 0xFFFFFFFF);
    SetObjectMaterial(Tdf_Object[79], 2, 15040, "cuntcuts", "newspaper1", 0xFFFFFFFF);
    SetObjectMaterial(Tdf_Object[79], 3, 15040, "cuntcuts", "csnewspaper", 0xFFFFFFFF);
    Tdf_Object[80] = CreateObject(1569, 1181.8426, -1121.4377, 23.3085, 0.0000, 0.0000, 90.0000, 120.0000); //ADAM_V_DOOR
    SetObjectMaterial(Tdf_Object[80], 0, 12805, "ce_loadbay", "sw_waredoor", 0xFFFFFFFF);
    Tdf_Object[81] = CreateObject(1236, 1198.5144, -1118.5423, 24.0513, 0.0000, 0.0000, 0.0000, 75.0000); //rcyclbank01
    Tdf_Object[82] = CreateObject(1339, 1182.3425, -1118.7325, 23.9848, 0.0000, 0.0000, 39.7000, 75.0000); //BinNt09_LA
    SetObjectMaterial(Tdf_Object[82], 0, 1328, "labins01_la", "bins4_LAe2", 0xFFFFFFFF);
    Tdf_Object[83] = CreateObject(1339, 1183.2812, -1118.6103, 23.9848, 0.0000, 0.0000, 0.6998, 75.0000); //BinNt09_LA
    SetObjectMaterial(Tdf_Object[83], 0, 1328, "labins01_la", "bins7_LAe2", 0xFFFFFFFF);
    Tdf_Object[84] = CreateObject(1236, 1213.6949, -1121.5826, 23.9113, 0.0000, 0.0000, 90.0000, 250.0000); //rcyclbank01
    Tdf_Object[85] = CreateObject(1236, 1214.3856, -1129.0633, 23.6914, 0.0000, 0.0000, 94.5998, 250.0000); //rcyclbank01
    Tdf_Object[86] = CreateObject(11714, 1214.8729, -1125.6711, 24.3631, 0.0000, 0.0000, 5.0998, 250.0000); //MaintenanceDoors1
    SetObjectMaterial(Tdf_Object[86], 0, 18246, "cw_junkyard2cs_t", "Was_scrpyd_door_dbl_grey", 0xFFFFFFFF);
    Tdf_Object[87] = CreateObject(11714, 1203.3835, -1122.5058, 24.4230, 0.0000, 0.0000, 90.0998, 250.0000); //MaintenanceDoors1
    SetObjectMaterial(Tdf_Object[87], 0, 18246, "cw_junkyard2cs_t", "Was_scrpyd_door_dbl_grey", 0xFFFFFFFF);
    Tdf_Object[88] = CreateObject(19325, 1181.9499, -1128.5655, 24.6583, 0.0000, 0.0000, 0.0000, 130.0000); //lsmall_window01
    SetObjectMaterial(Tdf_Object[88], 0, 18028, "cj_bar2", "CJ_nastybar_D3", 0x99FFFFFF);
    Tdf_Object[89] = CreateObject(19325, 1192.7110, -1122.3822, 24.7182, 0.0000, 0.0000, -91.0998, 250.0000); //lsmall_window01
    SetObjectMaterial(Tdf_Object[89], 0, 18028, "cj_bar2", "CJ_nastybar_D2", 0x99FFFFFF);
    Tdf_Object[90] = CreateObject(19325, 1199.8708, -1122.4742, 24.7182, 0.0000, 0.0000, -90.5000, 250.0000); //lsmall_window01
    SetObjectMaterial(Tdf_Object[90], 0, 18028, "cj_bar2", "CJ_nastybar_D6", 0x99FFFFFF);
    Tdf_Object[91] = CreateObject(19325, 1206.5128, -1122.4853, 24.7182, 0.0000, 0.0000, -89.8000, 250.0000); //lsmall_window01
    SetObjectMaterial(Tdf_Object[91], 0, 18028, "cj_bar2", "CJ_nastybar_D", 0x99FFFFFF);
    Tdf_Object[92] = CreateObject(9131, 1189.5969, -1122.6986, 23.3586, 0.0000, 0.0000, 0.0000, 120.0000); //shbbyhswall13_lvs
    SetObjectMaterial(Tdf_Object[92], 0, 18028, "cj_bar2", "GB_nastybar08", 0x99FFFFFF);
    Tdf_Object[93] = CreateObject(9131, 1189.5969, -1122.6986, 25.6284, 0.0000, 0.0000, 0.0000, 120.0000); //shbbyhswall13_lvs
    SetObjectMaterial(Tdf_Object[93], 0, 18028, "cj_bar2", "GB_nastybar08", 0x99FFFFFF);
    Tdf_Object[94] = CreateObject(1256, 1217.8824, -1131.4272, 23.6228, 0.0000, 0.0000, 90.0000, 250.0000); //Stonebench1
    Tdf_Object[95] = CreateObject(1256, 1237.0428, -1131.2572, 23.6228, 0.0000, 0.0000, 90.0000, 250.0000); //Stonebench1
    Tdf_Object[96] = CreateObject(1257, 1191.8443, -1134.4510, 24.1714, 0.0000, 0.0000, 90.0000, 75.0000); //bustopm
    Tdf_Object[97] = CreateObject(1440, 1210.6152, -1130.3863, 23.5037, 0.0000, 0.0000, 180.0000, 75.0000); //DYN_BOX_PILE_3
    SetObjectMaterial(Tdf_Object[97], 0, 9583, "bigshap_sfw", "freight_crate7", 0xFFFFFFFF);
    Tdf_Object[98] = CreateObject(1287, 1163.9466, -1155.0078, 23.3929, 0.0000, 0.0000, 0.0000, 250.0000); //newstandnew3
    Tdf_Object[99] = CreateObject(1285, 1164.7617, -1154.9945, 23.3512, 0.0000, 0.0000, 0.0000, 250.0000); //newstandnew5
    Tdf_Object[100] = CreateObject(1300, 1176.7860, -1159.1218, 23.2255, 0.0000, 0.0000, 0.0000, 250.0000); //bin1
    Tdf_Object[101] = CreateObject(1300, 1156.7856, -1159.1218, 23.2255, 0.0000, 0.0000, 0.0000, 250.0000); //bin1
    Tdf_Object[102] = CreateObject(2671, 1183.2574, -1119.6317, 23.3684, 0.0000, 0.0000, 0.0000, 100.0000); //PROC_RUBBISH_3
    SetObjectMaterial(Tdf_Object[102], 0, 10101, "2notherbuildsfe", "sl_vicbrikwall01", 0xFFFFFFFF);
    Tdf_Object[103] = CreateObject(2673, 1214.5766, -1128.6379, 24.4447, 0.0000, 0.0000, 0.0000, 75.0000); //PROC_RUBBISH_5
    Tdf_Object[104] = CreateObject(1230, 1199.9737, -1118.3801, 23.7938, 0.0000, 0.0000, 0.0000, 75.0000); //cardboardbox
    Tdf_Object[105] = CreateObject(1220, 1197.8872, -1118.5892, 25.0501, 0.0000, 0.0000, -46.0998, 75.0000); //cardboardbox2
    Tdf_Object[106] = CreateObject(1220, 1197.6933, -1121.6899, 23.5503, 0.0000, 0.0000, 40.2999, 75.0000); //cardboardbox2
    Tdf_Object[107] = CreateObject(1635, 1198.9051, -1121.9831, 26.4841, 0.0000, 0.0000, -90.6996, 75.0000); //nt_aircon1dbl
    Tdf_Object[108] = CreateObject(19325, 1152.6655, -1121.3509, 23.4479, -2.4999, 0.0000, 180.0000, 150.0000); //lsmall_window01
    SetObjectMaterial(Tdf_Object[108], 0, 1529, "tags_latemple", "temple", 0xFF177517);
    Tdf_Object[109] = CreateObject(19466, 1152.3662, -1114.2679, 24.8171, 0.0000, 0.0000, 180.0000, 120.0000); //window001
    SetObjectMaterial(Tdf_Object[109], 0, 14801, "lee_bdupsmain", "Bdup_graf3", 0xFF177517);
    Tdf_Object[110] = CreateObject(19393, 1036.2425, -994.6887, 39.5768, 0.0000, 0.0000, 90.0000, 250.0000); //wall041
    SetObjectMaterial(Tdf_Object[110], 0, 5444, "chicano10_lae", "comptwall15", 0xFFFFFFFF);
    Tdf_Object[111] = CreateObject(19790, 1033.4432, -1009.1569, 31.2660, 0.0000, 0.0000, 90.0000, 250.0000); //Cube5mx5m
    SetObjectMaterial(Tdf_Object[111], 0, 5149, "lasground2_las2", "driveway4_128", 0xFFFFFFFF);
    Tdf_Object[112] = CreateObject(19790, 1033.3935, -1004.1770, 31.2660, 0.0000, 0.0000, 90.0000, 250.0000); //Cube5mx5m
    SetObjectMaterial(Tdf_Object[112], 0, 5149, "lasground2_las2", "driveway4_128", 0xFFFFFFFF);
    Tdf_Object[113] = CreateObject(19405, 1033.1246, -1002.1378, 39.5213, 0.0000, 0.0000, 0.0000, 250.0000); //wall053
    SetObjectMaterial(Tdf_Object[113], 0, 5444, "chicano10_lae", "comptwall15", 0xFFFFFFFF);
    Tdf_Object[114] = CreateObject(19405, 1034.6561, -1003.6768, 39.5811, 0.0000, 0.0000, 90.0000, 250.0000); //wall053
    SetObjectMaterial(Tdf_Object[114], 0, 5444, "chicano10_lae", "comptwall15", 0xFFFFFFFF);
    Tdf_Object[115] = CreateObject(19357, 1034.5456, -999.7669, 39.5680, 0.0000, 0.0000, 0.0000, 75.0000); //wall005
    SetObjectMaterial(Tdf_Object[115], 0, 10434, "hashblock2b_sfs", "ws_apartmentgrn2", 0xFFFFFFFF);
    Tdf_Object[116] = CreateObject(19405, 1035.9764, -1005.3582, 39.5213, 0.0000, 0.0000, 0.0000, 250.0000); //wall053
    SetObjectMaterial(Tdf_Object[116], 0, 5444, "chicano10_lae", "comptwall15", 0xFFFFFFFF);
    Tdf_Object[117] = CreateObject(19357, 1037.9265, -999.4271, 39.5680, 0.0000, 0.0000, 0.0000, 75.0000); //wall005
    SetObjectMaterial(Tdf_Object[117], 0, 10434, "hashblock2b_sfs", "ws_apartmentgrn2", 0xFFFFFFFF);
    Tdf_Object[118] = CreateObject(19357, 1037.9365, -1002.1472, 39.5680, 0.0000, 0.0000, 0.0000, 75.0000); //wall005
    SetObjectMaterial(Tdf_Object[118], 0, 5444, "chicano10_lae", "comptwall15", 0xFFFFFFFF);
    Tdf_Object[119] = CreateObject(19357, 1034.5456, -996.5570, 39.5680, 0.0000, 0.0000, 0.0000, 75.0000); //wall005
    SetObjectMaterial(Tdf_Object[119], 0, 10434, "hashblock2b_sfs", "ws_apartmentgrn2", 0xFFFFFFFF);
    Tdf_Object[120] = CreateObject(19434, 1035.2541, -1001.2899, 39.5806, 0.0000, 0.0000, 90.0000, 75.0000); //wall074
    SetObjectMaterial(Tdf_Object[120], 0, 5444, "chicano10_lae", "comptwall15", 0xFFFFFFFF);
    Tdf_Object[121] = CreateObject(19434, 1033.8133, -1001.2800, 39.5806, 0.0000, 0.0000, 90.0000, 75.0000); //wall074
    SetObjectMaterial(Tdf_Object[121], 0, 5444, "chicano10_lae", "comptwall15", 0xFFFFFFFF);
    Tdf_Object[122] = CreateObject(2612, 1037.7873, -996.1751, 39.6888, 0.0000, 0.0000, -90.0000, 75.0000); //POLICE_NB2
    SetObjectMaterial(Tdf_Object[122], 0, 10439, "hashblock3_sfs", "dt_road_to_alley", 0xFFFFFFFF);
    SetObjectMaterial(Tdf_Object[122], 1, 10439, "hashblock3_sfs", "ws_hs_awning", 0xFFFFFFFF);
    SetObjectMaterial(Tdf_Object[122], 2, 14654, "ab_trukstpe", "bbar_sports1", 0xFFFFFFFF);
    SetObjectMaterial(Tdf_Object[122], 3, 13598, "destructo", "knifeAfterDark", 0xFFFFFFFF);
    Tdf_Object[123] = CreateObject(19357, 1036.3363, -996.2263, 41.3582, 0.0000, 90.0000, 0.0000, 250.0000); //wall005
    SetObjectMaterial(Tdf_Object[123], 0, 3555, "comedhos1_la", "comptroof3", 0xFFFFFFFF);
    Tdf_Object[124] = CreateObject(19357, 1036.3363, -999.4362, 41.3582, 0.0000, 90.0000, 0.0000, 250.0000); //wall005
    SetObjectMaterial(Tdf_Object[124], 0, 3555, "comedhos1_la", "comptroof3", 0xFFFFFFFF);
    Tdf_Object[125] = CreateObject(19434, 1036.3745, -1002.9710, 41.3507, 0.0000, 90.0000, 0.0000, 250.0000); //wall074
    SetObjectMaterial(Tdf_Object[125], 0, 3555, "comedhos1_la", "comptroof3", 0xFFFFFFFF);
    Tdf_Object[126] = CreateObject(19434, 1036.3745, -1001.3698, 41.3507, 0.0000, 90.0000, 0.0000, 250.0000); //wall074
    SetObjectMaterial(Tdf_Object[126], 0, 3555, "comedhos1_la", "comptroof3", 0xFFFFFFFF);
    Tdf_Object[127] = CreateObject(19434, 1033.8352, -1002.0203, 41.3507, 0.0000, 90.0000, 90.0000, 250.0000); //wall074
    SetObjectMaterial(Tdf_Object[127], 0, 3555, "comedhos1_la", "comptroof3", 0xFFFFFFFF);
    Tdf_Object[128] = CreateObject(1491, 1034.3553, -1009.1392, 36.0984, 0.0000, 0.0000, 90.0000, 75.0000); //Gen_doorINT01
    SetObjectMaterial(Tdf_Object[128], 0, 17933, "carter_mainmap", "mp_apt1_brokedoor", 0xFFFFFFFF);
    Tdf_Object[129] = CreateObject(1491, 1035.4648, -994.7089, 37.8483, 0.0000, 0.0000, 0.0000, 75.0000); //Gen_doorINT01
    SetObjectMaterial(Tdf_Object[129], 0, 17933, "carter_mainmap", "mp_apt1_brokedoor", 0xFFFFFFFF);
    Tdf_Object[130] = CreateObject(19357, 1035.9659, -1005.3582, 36.0181, 0.0000, 0.0000, 0.0000, 75.0000); //wall005
    SetObjectMaterial(Tdf_Object[130], 0, 5444, "chicano10_lae", "comptwall15", 0xFFFFFFFF);
    Tdf_Object[131] = CreateObject(19434, 1038.2546, -1011.5208, 37.9509, 0.0000, 0.0000, 90.0000, 75.0000); //wall074
    SetObjectMaterial(Tdf_Object[131], 0, 5444, "chicano10_lae", "comptwall15", 0xFFFFFFFF);
    Tdf_Object[132] = CreateObject(19434, 1035.2523, -1006.8809, 37.8208, 0.0000, 0.0000, 90.0000, 250.0000); //wall074
    SetObjectMaterial(Tdf_Object[132], 0, 5444, "chicano10_lae", "comptwall15", 0xFFFFFFFF);
    Tdf_Object[133] = CreateObject(19790, 1038.4361, -1004.1362, 31.2458, 0.0000, 0.0000, 90.0000, 75.0000); //Cube5mx5m
    SetObjectMaterial(Tdf_Object[133], 0, 5149, "lasground2_las2", "driveway4_128", 0xFFFFFFFF);
    Tdf_Object[134] = CreateObject(19790, 1036.9448, -1009.1162, 31.2458, 0.0000, 0.0000, 90.0000, 75.0000); //Cube5mx5m
    SetObjectMaterial(Tdf_Object[134], 0, 5149, "lasground2_las2", "driveway4_128", 0xFFFFFFFF);
    Tdf_Object[135] = CreateObject(19405, 1036.0478, -1011.5172, 37.9513, 0.0000, 0.0000, 90.0000, 250.0000); //wall053
    SetObjectMaterial(Tdf_Object[135], 0, 5444, "chicano10_lae", "comptwall15", 0xFFFFFFFF);
    Tdf_Object[136] = CreateObject(19393, 1034.3840, -1008.3980, 37.8269, 0.0000, 0.0000, 0.0000, 250.0000); //wall041
    SetObjectMaterial(Tdf_Object[136], 0, 5444, "chicano10_lae", "comptwall15", 0xFFFFFFFF);
    Tdf_Object[137] = CreateObject(19434, 1034.4144, -1010.7905, 37.8008, 0.0000, 0.0000, 0.0000, 250.0000); //wall074
    SetObjectMaterial(Tdf_Object[137], 0, 5444, "chicano10_lae", "comptwall15", 0xFFFFFFFF);
    Tdf_Object[138] = CreateObject(14877, 1037.3962, -1005.1942, 35.7453, 0.0000, 0.0000, 90.0000, 75.0000); //michelle-stairs
    Tdf_Object[139] = CreateObject(19434, 1037.4956, -1005.2078, 41.2621, 0.0000, 87.5000, 90.0000, 75.0000); //wall074
    SetObjectMaterial(Tdf_Object[139], 0, 3555, "comedhos1_la", "comptroof3", 0xFFFFFFFF);
    Tdf_Object[140] = CreateObject(19434, 1036.6960, -1005.2083, 41.2719, 0.0000, 87.5000, 90.0000, 250.0000); //wall074
    SetObjectMaterial(Tdf_Object[140], 0, 3555, "comedhos1_la", "comptroof3", 0xFFFFFFFF);
    Tdf_Object[141] = CreateObject(19357, 1036.1158, -1008.3953, 39.5881, 0.0000, 90.0000, 0.0000, 250.0000); //wall005
    SetObjectMaterial(Tdf_Object[141], 0, 3555, "comedhos1_la", "comptroof3", 0xFFFFFFFF);
    Tdf_Object[142] = CreateObject(19434, 1036.1175, -1010.7894, 39.6142, 0.0000, 90.0000, 0.0000, 250.0000); //wall074
    SetObjectMaterial(Tdf_Object[142], 0, 3555, "comedhos1_la", "comptroof3", 0xFFFFFFFF);
    Tdf_Object[143] = CreateObject(2559, 1034.1540, -1004.0878, 39.0996, 0.0000, 0.0000, 0.0000, 75.0000); //CURTAIN_1_OPEN
    SetObjectMaterial(Tdf_Object[143], 0, 3653, "beachapts_lax", "comptcowind1", 0xFFFFFFFF);
    SetObjectMaterial(Tdf_Object[143], 1, 14383, "burg_1", "curtain_sink2", 0xFFFFFFFF);
    Tdf_Object[144] = CreateObject(19790, 1029.9311, -1005.8054, 30.8162, -15.0000, 0.0000, 90.0000, 250.0000); //Cube5mx5m
    SetObjectMaterial(Tdf_Object[144], 0, 5149, "lasground2_las2", "driveway4_128", 0xFFFFFFFF);
    Tdf_Object[145] = CreateObject(1464, 1031.6241, -1002.7655, 37.3320, 0.0000, 0.0000, 0.0000, 250.0000); //DYN_SCAFFOLD_3
    SetObjectMaterial(Tdf_Object[145], 0, 18081, "cj_barb", "ab_panel_woodgrime", 0xFFFFFFFF);
    Tdf_Object[146] = CreateObject(1819, 1035.1307, -999.6104, 37.8431, 0.0000, 0.0000, 41.0998, 75.0000); //COFFEE_SWANK_4
    SetObjectMaterial(Tdf_Object[146], 0, 18058, "mp_diner2", "mp_diner_table", 0xFFFFFFFF);
    SetObjectMaterial(Tdf_Object[146], 1, 11100, "bendytunnel_sfse", "blackmetal", 0xFFFFFFFF);
    Tdf_Object[147] = CreateObject(2559, 1035.1051, -1003.3472, 39.0996, 0.0000, 0.0000, 180.0000, 75.0000); //CURTAIN_1_OPEN
    SetObjectMaterial(Tdf_Object[147], 0, 3653, "beachapts_lax", "comptcowind1", 0xFFFFFFFF);
    SetObjectMaterial(Tdf_Object[147], 1, 14383, "burg_1", "curtain_sink2", 0xFFFFFFFF);
    Tdf_Object[148] = CreateObject(2558, 1033.4447, -1001.8654, 39.0410, 0.0000, 0.0000, 90.0000, 75.0000); //CURTAIN_1_CLOSED
    SetObjectMaterial(Tdf_Object[148], 0, 14581, "ab_mafiasuitea", "ab_wood01", 0xFFFFFFFF);
    SetObjectMaterial(Tdf_Object[148], 1, 14383, "burg_1", "curtain_sink2", 0xFFFFFFFF);
    Tdf_Object[149] = CreateObject(2558, 1032.7137, -1000.8449, 39.0410, 0.0000, 0.0000, -90.0000, 75.0000); //CURTAIN_1_CLOSED
    SetObjectMaterial(Tdf_Object[149], 0, 14581, "ab_mafiasuitea", "ab_wood01", 0xFFFFFFFF);
    SetObjectMaterial(Tdf_Object[149], 1, 14383, "burg_1", "curtain_sink2", 0xFFFFFFFF);
    Tdf_Object[150] = CreateObject(2558, 1035.5643, -1004.8347, 39.0410, 0.0000, 0.0000, -90.0000, 75.0000); //CURTAIN_1_CLOSED
    SetObjectMaterial(Tdf_Object[150], 0, 14581, "ab_mafiasuitea", "ab_wood01", 0xFFFFFFFF);
    SetObjectMaterial(Tdf_Object[150], 1, 14383, "burg_1", "curtain_sink2", 0xFFFFFFFF);
    Tdf_Object[151] = CreateObject(2558, 1036.3050, -1005.9456, 39.0410, 0.0000, 0.0000, 90.0000, 75.0000); //CURTAIN_1_CLOSED
    SetObjectMaterial(Tdf_Object[151], 0, 14581, "ab_mafiasuitea", "ab_wood01", 0xFFFFFFFF);
    SetObjectMaterial(Tdf_Object[151], 1, 14383, "burg_1", "curtain_sink2", 0xFFFFFFFF);
    Tdf_Object[152] = CreateObject(2558, 1036.6053, -1011.1259, 37.4710, 0.0000, 0.0000, 180.0000, 75.0000); //CURTAIN_1_CLOSED
    SetObjectMaterial(Tdf_Object[152], 0, 14581, "ab_mafiasuitea", "ab_wood01", 0xFFFFFFFF);
    SetObjectMaterial(Tdf_Object[152], 1, 14383, "burg_1", "curtain_sink2", 0xFFFFFFFF);
    Tdf_Object[153] = CreateObject(2558, 1035.5748, -1011.8662, 37.4710, 0.0000, 0.0000, 0.0000, 75.0000); //CURTAIN_1_CLOSED
    SetObjectMaterial(Tdf_Object[153], 0, 14581, "ab_mafiasuitea", "ab_wood01", 0xFFFFFFFF);
    SetObjectMaterial(Tdf_Object[153], 1, 14383, "burg_1", "curtain_sink2", 0xFFFFFFFF);
    Tdf_Object[154] = CreateObject(19357, 1037.9365, -1005.3568, 39.5680, 0.0000, 0.0000, 0.0000, 75.0000); //wall005
    SetObjectMaterial(Tdf_Object[154], 0, 5444, "chicano10_lae", "comptwall15", 0xFFFFFFFF);
    Tdf_Object[155] = CreateObject(19357, 1037.9365, -1005.3568, 36.0680, 0.0000, 0.0000, 0.0000, 75.0000); //wall005
    SetObjectMaterial(Tdf_Object[155], 0, 5444, "chicano10_lae", "comptwall15", 0xFFFFFFFF);
    Tdf_Object[156] = CreateObject(19357, 1037.9365, -1008.5667, 37.9882, 0.0000, 0.0000, 0.0000, 75.0000); //wall005
    SetObjectMaterial(Tdf_Object[156], 0, 5444, "chicano10_lae", "comptwall15", 0xFFFFFFFF);
    Tdf_Object[157] = CreateObject(19434, 1037.9343, -1010.8104, 37.9509, 0.0000, 0.0000, 0.0000, 75.0000); //wall074
    SetObjectMaterial(Tdf_Object[157], 0, 5444, "chicano10_lae", "comptwall15", 0xFFFFFFFF);
    Tdf_Object[158] = CreateObject(1795, 1034.4504, -1010.1550, 36.2672, 0.0000, 0.0000, -90.0000, 75.0000); //SWANK_BED_2
    SetObjectMaterial(Tdf_Object[158], 0, 2988, "kcomp_gx", "kmwood_gate", 0xFFFFFFFF);
    SetObjectMaterial(Tdf_Object[158], 1, 1738, "cjtemp", "CJ_bed1", 0xFFFFFFFF);
    Tdf_Object[159] = CreateObject(2833, 1035.6042, -1009.3585, 36.2723, 0.0000, 0.5999, -0.7997, 75.0000); //gb_livingrug02
    Tdf_Object[160] = CreateObject(2060, 1037.6540, -1010.6881, 36.7947, -151.1000, 0.0000, -95.2994, 75.0000); //CJ_SANDBAG
    SetObjectMaterial(Tdf_Object[160], 0, 14802, "lee_bdupsflat", "Bdup_Pillow", 0xFFFFFFFF);
    Tdf_Object[161] = CreateObject(2096, 1035.5648, -1007.8552, 36.1697, 2.9000, 0.0000, -156.5000, 75.0000); //CJ_RockingChair
    SetObjectMaterial(Tdf_Object[161], 0, 1407, "break_f_w", "CJ_GREENWOOD", 0xFFFFFFFF);
    Tdf_Object[162] = CreateObject(2158, 1037.3955, -1008.8720, 35.3399, 0.0000, 0.0000, -90.0000, 75.0000); //CJ_KITCH1_L
    SetObjectMaterial(Tdf_Object[162], 0, 5042, "bombshop_las", "shutterclosed_law", 0xFFFFFFFF);
    SetObjectMaterial(Tdf_Object[162], 1, 3374, "ce_farmxref", "sw_barndoor1", 0xFFFFFFFF);
    Tdf_Object[163] = CreateObject(2607, 1035.4786, -1007.3806, 36.6421, 0.0000, 0.0000, 180.0000, 75.0000); //POLCE_DESK2
    SetObjectMaterial(Tdf_Object[163], 0, 642, "canopy", "wood02", 0xFFFFFFFF);
    SetObjectMaterial(Tdf_Object[163], 2, 642, "canopy", "wood02", 0xFFFFFFFF);
    SetObjectMaterial(Tdf_Object[163], 3, 642, "canopy", "wood02", 0xFFFFFFFF);
    SetObjectMaterial(Tdf_Object[163], 4, 6282, "beafron2_law2", "boardwalk2_la", 0xFFFFFFFF);
    Tdf_Object[164] = CreateObject(2611, 1035.3066, -1007.0197, 37.7262, 0.0000, 0.0000, 0.0000, 75.0000); //POLICE_NB1
    SetObjectMaterial(Tdf_Object[164], 0, 16640, "a51", "Metalox64", 0xFFFFFFFF);
    SetObjectMaterial(Tdf_Object[164], 2, 1355, "break_s_bins", "CJ_WOOD_DARK", 0xFFFFFFFF);
    SetObjectMaterial(Tdf_Object[164], 3, 10713, "gayclub_sfs", "CJ_GEN_GLASS2", 0xFFFFFFFF);
    Tdf_Object[165] = CreateObject(1744, 1038.0145, -1009.9359, 37.4281, 0.0000, 0.0000, -90.0000, 75.0000); //MED_SHELF
    SetObjectMaterial(Tdf_Object[165], 0, 1453, "break_farm", "CJ_DarkWood", 0xFFFFFFFF);
    Tdf_Object[166] = CreateObject(3431, 1035.6800, -1005.8499, 38.3498, 0.0000, 0.0000, 0.0000, 250.0000); //vgsclubox01
    SetObjectMaterial(Tdf_Object[166], 0, 5444, "chicano10_lae", "comptwall15", 0xFFFFFFFF);
    Tdf_Object[167] = CreateObject(3431, 1032.8354, -1002.3095, 38.3534, 0.0000, 0.0000, 0.0000, 250.0000); //vgsclubox01
    SetObjectMaterial(Tdf_Object[167], 0, 5444, "chicano10_lae", "comptwall15", 0xFFFFFFFF);
    Tdf_Object[168] = CreateObject(19790, 1033.4432, -1014.1168, 31.2660, 0.0000, 0.0000, 90.0000, 250.0000); //Cube5mx5m
    SetObjectMaterial(Tdf_Object[168], 0, 5149, "lasground2_las2", "driveway4_128", 0xFFFFFFFF);
    Tdf_Object[169] = CreateObject(3431, 1035.6855, -1004.5695, 38.3534, 0.0000, 0.0000, 0.0000, 250.0000); //vgsclubox01
    SetObjectMaterial(Tdf_Object[169], 0, 5444, "chicano10_lae", "comptwall15", 0xFFFFFFFF);
    Tdf_Object[170] = CreateObject(19790, 1038.4134, -1014.1168, 31.2660, 0.0000, 0.0000, 90.0000, 250.0000); //Cube5mx5m
    SetObjectMaterial(Tdf_Object[170], 0, 5149, "lasground2_las2", "driveway4_128", 0xFFFFFFFF);
    Tdf_Object[171] = CreateObject(2558, 1037.4165, -1006.4174, 39.9309, 0.0000, 0.0000, 180.0000, 75.0000); //CURTAIN_1_CLOSED
    SetObjectMaterial(Tdf_Object[171], 0, 14581, "ab_mafiasuitea", "ab_wood01", 0xFFFFFFFF);
    SetObjectMaterial(Tdf_Object[171], 1, 14383, "burg_1", "curtain_sink2", 0xFFFFFFFF);
    Tdf_Object[172] = CreateObject(2558, 1036.4853, -1007.3178, 39.9309, 0.0000, 0.0000, 0.0000, 75.0000); //CURTAIN_1_CLOSED
    SetObjectMaterial(Tdf_Object[172], 0, 14581, "ab_mafiasuitea", "ab_wood01", 0xFFFFFFFF);
    SetObjectMaterial(Tdf_Object[172], 1, 14383, "burg_1", "curtain_sink2", 0xFFFFFFFF);
    Tdf_Object[173] = CreateObject(2120, 1034.1977, -1001.7019, 38.5097, 0.0000, 0.0000, 176.8997, 75.0000); //MED_DIN_CHAIR_4
    SetObjectMaterial(Tdf_Object[173], 0, 1738, "cjtemp", "cj_Mattress5", 0xFFFFFFFF);
    SetObjectMaterial(Tdf_Object[173], 1, 18081, "cj_barb", "ab_panel_woodgrime", 0xFFFFFFFF);
    Tdf_Object[174] = CreateObject(2120, 1036.4110, -1001.6281, 38.5097, 0.0000, 0.0000, 33.9995, 75.0000); //MED_DIN_CHAIR_4
    SetObjectMaterial(Tdf_Object[174], 0, 1738, "cjtemp", "cj_Mattress2", 0xFFFFFFFF);
    SetObjectMaterial(Tdf_Object[174], 1, 18081, "cj_barb", "ab_panel_woodgrime", 0xFFFFFFFF);
    Tdf_Object[175] = CreateObject(19325, 1034.6394, -998.0371, 39.2140, 0.0000, 0.0000, 0.0000, 75.0000); //lsmall_window01
    SetObjectMaterial(Tdf_Object[175], 0, 18028, "cj_bar2", "CJ_nastybar_D3", 0x99FFFFFF);
    Tdf_Object[176] = CreateObject(19357, 1034.6551, -1001.2968, 37.2680, 0.0000, 0.0000, 90.0000, 75.0000); //wall005
    SetObjectMaterial(Tdf_Object[176], 0, 3193, "cxref_desert", "sw_woodslat01", 0xFFFFFFFF);
    Tdf_Object[177] = CreateObject(19434, 1034.5439, -995.4191, 39.5606, 0.0000, 0.0000, 0.0000, 75.0000); //wall074
    SetObjectMaterial(Tdf_Object[177], 0, 10434, "hashblock2b_sfs", "ws_haight2top", 0xFFFFFFFF);
    Tdf_Object[178] = CreateObject(2160, 1034.1075, -1003.2899, 37.8263, 0.0000, 0.0000, 180.0000, 75.0000); //CJ_K6_LOW_UNIT3
    Tdf_Object[179] = CreateObject(2157, 1035.4664, -1003.2910, 37.8297, 0.0000, 0.0000, 180.0000, 75.0000); //CJ_K6_LOW_UNIT2
    Tdf_Object[180] = CreateObject(19916, 1037.7003, -1003.1510, 37.7933, 0.0000, 0.0000, -114.1996, 75.0000); //CutsceneFridge1
    SetObjectMaterial(Tdf_Object[180], 0, 14495, "sweetshall", "mp_cooker1", 0xFFFFFFFF);
    Tdf_Object[181] = CreateObject(2631, 1035.9458, -998.5111, 37.8314, 0.0000, 0.0000, -91.0998, 75.0000); //gym_mat1
    SetObjectMaterial(Tdf_Object[181], 0, 14801, "lee_bdupsmain", "ahomcarpet", 0xFFFFFFFF);
    Tdf_Object[182] = CreateObject(19915, 1033.5356, -1001.6848, 37.8353, 0.0000, 0.0000, 0.0000, 75.0000); //CutsceneCooker1
    SetObjectMaterial(Tdf_Object[182], 3, 14495, "sweetshall", "mp_cooker1", 0xFFFFFFFF);
    Tdf_Object[183] = CreateObject(1744, 1035.7738, -1001.2036, 39.0153, 180.0000, 0.0000, 180.0000, 75.0000); //MED_SHELF
    SetObjectMaterial(Tdf_Object[183], 0, 3063, "col_wall1x", "ab_wood1", 0xFFFFFFFF);
    Tdf_Object[184] = CreateObject(2833, 1034.4090, -1002.5427, 37.8451, 0.0000, 0.5999, -5.2999, 75.0000); //gb_livingrug02
    SetObjectMaterial(Tdf_Object[184], 0, 15048, "labigsave", "AH_carpet4kb", 0xFFFFFFFF);
    Tdf_Object[185] = CreateObject(1761, 1037.3454, -997.4655, 37.8361, 0.0000, 0.0000, -90.0000, 75.0000); //SWANK_COUCH_2
    SetObjectMaterial(Tdf_Object[185], 0, 8534, "tikimotel", "sa_wood04_128", 0xFFBDBEC6);
    SetObjectMaterial(Tdf_Object[185], 1, 14533, "pleas_dome", "ab_carpethexi", 0xFF8E8C46);
    Tdf_Object[186] = CreateObject(1762, 1035.1136, -997.4212, 37.8577, 0.0000, 0.0000, 50.5998, 75.0000); //SWANK_SINGLE_2
    SetObjectMaterial(Tdf_Object[186], 0, 8534, "tikimotel", "sa_wood04_128", 0xFFBDBEC6);
    SetObjectMaterial(Tdf_Object[186], 1, 14533, "pleas_dome", "ab_carpethexi", 0xFF8E8C46);
    Tdf_Object[187] = CreateObject(1786, 1034.7209, -999.0181, 38.3348, 0.0000, 0.0000, 90.0000, 75.0000); //SWANK_TV_4
    SetObjectMaterial(Tdf_Object[187], 1, 15042, "svsfsm", "chin_carp2", 0xFF788222);
    Tdf_Object[188] = CreateObject(2047, 1034.6529, -998.5916, 39.9771, 0.0000, 0.0000, 90.0000, 75.0000); //CJ_FLAG1
    SetObjectMaterial(Tdf_Object[188], 0, 10355, "haight1_sfs", "ws_hashbanner", 0xFFFFFFFF);
    Tdf_Object[189] = CreateObject(19393, 1036.2425, -994.7086, 39.5699, 0.0000, 0.0000, 90.0000, 75.0000); //wall041
    SetObjectMaterial(Tdf_Object[189], 0, 10434, "hashblock2b_sfs", "ws_apartmentgrn2", 0xFFFFFFFF);
    Tdf_Object[190] = CreateObject(19357, 1037.9265, -996.2269, 39.5680, 0.0000, 0.0000, 0.0000, 75.0000); //wall005
    SetObjectMaterial(Tdf_Object[190], 0, 10434, "hashblock2b_sfs", "ws_apartmentgrn2", 0xFFFFFFFF);
    Tdf_Object[191] = CreateObject(19393, 1037.0443, -1001.0855, 39.5666, 0.0000, 0.0000, 90.0000, 75.0000); //wall041
    SetObjectMaterial(Tdf_Object[191], 0, 10434, "hashblock2b_sfs", "ws_apartmentgrn2", 0xFFFFFFFF);
    Tdf_Object[192] = CreateObject(19434, 1035.4742, -1001.0797, 39.5405, 0.0000, 0.0000, 90.0000, 75.0000); //wall074
    SetObjectMaterial(Tdf_Object[192], 0, 10434, "hashblock2b_sfs", "ws_apartmentgrn2", 0xFFFFFFFF);
    Tdf_Object[193] = CreateObject(19393, 1037.0443, -1001.2758, 39.5666, 0.0000, 0.0000, 90.0000, 75.0000); //wall041
    SetObjectMaterial(Tdf_Object[193], 0, 5444, "chicano10_lae", "comptwall15", 0xFFFFFFFF);
    Tdf_Object[194] = CreateObject(2238, 1037.1512, -996.9602, 38.2667, 0.0000, 0.0000, 0.0000, 75.0000); //CJ_LAVA_LAMP
    Tdf_Object[195] = CreateObject(19327, 1037.7832, -999.7551, 39.8652, 0.0000, 4.9998, -90.0000, 75.0000); //7_11_sign02
    SetObjectMaterial(Tdf_Object[195], 0, 4833, "airprtrunway_las", "homies_1", 0xFFFFFFFF);
    Tdf_Object[196] = CreateObject(2329, 1036.5378, -999.6964, 37.8175, 0.0000, 0.0000, 146.8000, 75.0000); //LOW_CABINET_1_L
    SetObjectMaterial(Tdf_Object[196], 0, 19598, "sfbuilding1", "darkwood1", 0xFFFFFFFF);
    Tdf_Object[197] = CreateObject(2102, 1035.1496, -999.8297, 40.1029, 0.0000, 0.0000, 157.6999, 75.0000); //LOW_HI_FI_2
    Tdf_Object[198] = CreateObject(948, 1035.2130, -1000.0197, 38.5726, 0.0000, 0.0000, -175.1999, 75.0000); //Plant_Pot_10
    SetObjectMaterial(Tdf_Object[198], 2, 3261, "grasshouse", "veg_marijuana", 0xFFFFFFFF);
    SetObjectMaterial(Tdf_Object[198], 3, 3922, "bistro", "StainedGlass", 0xFFFFFFFF);
    Tdf_Object[199] = CreateObject(19621, 1035.5655, -1000.1112, 38.7821, 0.0000, 0.0000, 79.6996, 75.0000); //OilCan1
    SetObjectMaterial(Tdf_Object[199], 0, 13060, "ce_fact01", "glassblock_law", 0xFFFFFFFF);
    Tdf_Object[200] = CreateObject(1623, 1035.4211, -994.7858, 40.9855, 0.0000, 0.0000, -90.0000, 250.0000); //nt_aircon3_01
    Tdf_Object[201] = CreateObject(914, 1036.6385, -1006.8527, 40.4522, 0.0000, 0.0000, 0.0000, 75.0000); //GRILL
    Tdf_Object[202] = CreateObject(914, 1037.2292, -1006.8527, 40.4522, 0.0000, 0.0000, 0.0000, 75.0000); //GRILL
    Tdf_Object[203] = CreateObject(19790, 1023.8684, -1005.8054, 30.0361, 0.0000, 0.0000, 90.0000, 250.0000); //Cube5mx5m
    SetObjectMaterial(Tdf_Object[203], 0, 5149, "lasground2_las2", "driveway4_128", 0xFFFFFFFF);
    Tdf_Object[204] = CreateObject(638, 1278.4460, -886.2221, 42.5689, 0.0000, 0.0000, 96.0000, 250.0000); //kb_planter+bush
    SetObjectMaterial(Tdf_Object[204], 0, 3455, "vgnhseblk1", "vnghse1_256", 0xFFFFFFFF);
    SetObjectMaterial(Tdf_Object[204], 1, 4992, "airportdetail", "sm_Agave_1", 0xFFFFFFFF);
    Tdf_Object[205] = CreateObject(8645, 1229.3929, -891.1118, 43.6599, 0.0000, 0.0000, -80.5998, 250.0000); //shbbyhswall01_lvs
    SetObjectMaterial(Tdf_Object[205], 0, 3455, "vgnhseblk1", "vnghse1_256", 0xFFFFFFFF);
    SetObjectMaterial(Tdf_Object[205], 1, 3455, "vgnhseblk1", "vnghse1_256", 0xFFFFFFFF);
    Tdf_Object[206] = CreateObject(10444, 1001.8233, -1010.4235, 41.3521, 0.0000, 0.0000, 0.0000, 100.0000); //poolwater_SFS
    Tdf_Object[207] = CreateObject(8658, 1149.9575, -1305.8039, 13.4926, 0.0000, 0.0000, 180.0000, 300.0000); //shabbyhouse11_lvs
    SetObjectMaterial(Tdf_Object[207], 0, 9524, "blokmodb", "Bow_Grimebrick", 0xFFFFFFFF);
    Tdf_Object[208] = CreateObject(996, 1162.4388, -1290.9465, 13.2454, 0.0000, 0.0000, 0.7997, 250.0000); //lhouse_barrier1
    SetObjectMaterial(Tdf_Object[208], 0, 17547, "eastbeach4a_lae2", "bluestucco1", 0xFFFFFFFF);
    Tdf_Object[209] = CreateObject(8658, 1164.9176, -1384.9654, 13.4926, 0.0000, 0.0000, 90.0000, 300.0000); //shabbyhouse11_lvs
    SetObjectMaterial(Tdf_Object[209], 0, 12944, "ce_bankalley2", "sw_brick04", 0xFFFFFFFF);
    Tdf_Object[210] = CreateObject(19449, 989.6657, -1264.1379, 14.2038, 0.0000, 0.0000, 0.0000, 100.0000); //wall089
    SetObjectMaterial(Tdf_Object[210], 0, 5461, "glenpark6d_lae", "shutter01LA", 0xAAFFFFFF);
    Tdf_Object[211] = CreateObject(19449, 989.6657, -1254.5383, 14.2038, 0.0000, 0.0000, 0.0000, 100.0000); //wall089
    SetObjectMaterial(Tdf_Object[211], 0, 6282, "beafron2_law2", "shutter03LA", 0xAAFFFFFF);
    Tdf_Object[212] = CreateObject(19449, 989.4660, -1262.6577, 15.4039, 0.0000, 0.0000, 0.0000, 100.0000); //wall089
    SetObjectMaterial(Tdf_Object[212], 0, 10838, "airwelcomesign_sfse", "sl_rustyrailing", 0xFFFFFFFF);
    Tdf_Object[213] = CreateObject(19449, 989.4660, -1253.0377, 15.4039, 0.0000, 0.0000, 0.0000, 100.0000); //wall089
    SetObjectMaterial(Tdf_Object[213], 0, 10838, "airwelcomesign_sfse", "sl_rustyrailing", 0xFFFFFFFF);
    Tdf_Object[214] = CreateObject(19479, 976.2166, -1250.9759, 20.7896, 0.0000, 0.0000, -90.0000, 150.0000); //Plane005
    SetObjectMaterial(Tdf_Object[214], 0, 17526, "eastls1_lae2", "comptsign1_LAe", 0xFFFFFFFF);
    Tdf_Object[215] = CreateObject(2991, 992.9954, -1255.1894, 14.0472, 0.0000, 0.0000, 91.3999, 75.0000); //imy_bbox
    SetObjectMaterial(Tdf_Object[215], 1, 17526, "eastls1_lae2", "comptsign3_LAe", 0xFFFFFFFF);
    Tdf_Object[216] = CreateObject(1339, 990.1375, -1268.5415, 14.6646, 0.0000, 0.0000, 0.6998, 75.0000); //BinNt09_LA
    SetObjectMaterial(Tdf_Object[216], 0, 1328, "labins01_la", "bins7_LAe2", 0xFFFFFFFF);
    Tdf_Object[217] = CreateObject(18262, 992.9671, -1254.4366, 14.7214, -2.2000, 0.0000, 0.0000, 120.0000); //cw2_phroofstuf
    SetObjectMaterial(Tdf_Object[217], 0, 3080, "adjumpx", "planks64", 0xFF9F9D94);
    SetObjectMaterial(Tdf_Object[217], 1, 1245, "newramp", "craneblnk_128", 0xFFFFFFFF);
    Tdf_Object[218] = CreateObject(19325, 992.9348, -1248.8835, 16.7070, 0.0000, 0.0000, -90.0000, 100.0000); //lsmall_window01
    SetObjectMaterial(Tdf_Object[218], 0, 5785, "melrosetr1_lawn", "blob1_LAwN", 0xFF9EA4AB);
    Tdf_Object[219] = CreateObject(1709, 997.9243, -1262.8967, 14.0115, 0.0000, 0.0000, -90.0000, 75.0000); //kb_couch08
    Tdf_Object[220] = CreateObject(2405, 989.8745, -1258.1816, 15.2123, -8.3999, 0.0000, 90.0000, 75.0000); //CJ_SURF_BOARD2
    SetObjectMaterial(Tdf_Object[220], 0, 1453, "break_farm", "CJ_DarkWood", 0xFFFFFFFF);
    SetObjectMaterial(Tdf_Object[220], 1, 18028, "cj_bar2", "CJ_nastybar_D", 0xFFFFFFFF);
    Tdf_Object[221] = CreateObject(2405, 989.8745, -1259.3830, 15.2123, -8.3999, 0.0000, 86.4000, 75.0000); //CJ_SURF_BOARD2
    SetObjectMaterial(Tdf_Object[221], 0, 1453, "break_farm", "CJ_DarkWood", 0xFFFFFFFF);
    SetObjectMaterial(Tdf_Object[221], 1, 18028, "cj_bar2", "CJ_nastybar_D4", 0xFFFFFFFF);
    Tdf_Object[222] = CreateObject(19878, 993.3079, -1252.2390, 14.8315, 0.0000, 0.0000, 100.3999, 75.0000); //Skateboard1
    SetObjectMaterial(Tdf_Object[222], 0, 18028, "cj_bar2", "CJ_nastybar_D3", 0xFFFFFFFF);
    Tdf_Object[223] = CreateObject(19878, 992.6898, -1256.6252, 14.8315, 0.0000, 0.0000, 33.0000, 75.0000); //Skateboard1
    SetObjectMaterial(Tdf_Object[223], 0, 18028, "cj_bar2", "CJ_nastybar_D2", 0xFFFFFFFF);
    Tdf_Object[224] = CreateObject(2032, 983.9835, -1276.8060, 14.1077, 0.0000, 0.0000, 0.0000, 75.0000); //MED_DINNING_2
    SetObjectMaterial(Tdf_Object[224], 0, 14825, "genintint2_gym", "plywood3_gym", 0xFFFFFFFF);
    SetObjectMaterial(Tdf_Object[224], 1, 2343, "cb_bar_bits", "CJ_POLISHED", 0xFF989586);
    Tdf_Object[225] = CreateObject(1811, 983.0258, -1276.8927, 14.7206, 0.0000, 0.0000, -90.0000, 75.0000); //MED_DIN_CHAIR_5
    SetObjectMaterial(Tdf_Object[225], 0, 3586, "la_props1", "shutters2", 0xFFFFFFFF);
    SetObjectMaterial(Tdf_Object[225], 1, 6282, "beafron2_law2", "shutter03LA", 0xFFFFFFFF);
    Tdf_Object[226] = CreateObject(1811, 986.0767, -1276.8509, 14.7206, 0.0000, 0.0000, -65.3999, 75.0000); //MED_DIN_CHAIR_5
    SetObjectMaterial(Tdf_Object[226], 0, 3586, "la_props1", "shutters2", 0xFFFFFFFF);
    SetObjectMaterial(Tdf_Object[226], 1, 6282, "beafron2_law2", "shutter03LA", 0xFFFFFFFF);
    Tdf_Object[228] = CreateObject(19479, 991.3792, -1277.3103, 14.1723, 0.0000, 0.0000, 90.0000, 100.0000); //Plane005
    SetObjectMaterial(Tdf_Object[228], 0, 5390, "glenpark7_lae", "ganggraf01_LA", 0xFFFFFFFF);
    Tdf_Object[229] = CreateObject(365, 1020.2321, -1245.0351, 14.2706, 0.0000, 90.0000, 0.0000, 40.0000); //spraycan
    Tdf_Object[230] = CreateObject(1216, 1017.1400, -1310.5239, 13.1843, 0.0000, 0.0000, 0.0000, 100.0000); //phonebooth1
    Tdf_Object[232] = CreateObject(19339, 885.8590, -1077.4266, 22.4689, 0.0000, 0.0000, 180.0000, 75.0000); //coffin01
    Tdf_Object[233] = CreateObject(2790, 931.7614, -1095.2445, 25.3659, 0.0000, 0.0000, 0.0000, 100.0000); //CJ_ARRIVE_BOARD
    SetObjectMaterial(Tdf_Object[233], 1, 10442, "graveyard_sfs", "ws_memorial", 0xFFFFFFFF);
    SetObjectMaterial(Tdf_Object[233], 2, 914, "industrialext", "CJ_VENT1", 0xFFFFFFFF);
    Tdf_Object[234] = CreateObject(5777, 888.3134, -1077.3940, 23.8567, 0.0000, 0.0000, 0.0000, 100.0000); //tombston01_LAwN
    Tdf_Object[235] = CreateObject(2660, 885.8848, -1077.4886, 22.8603, -90.0000, 0.0000, -39.0000, 75.0000); //CJ_BANNER06
    SetObjectMaterial(Tdf_Object[235], 0, 14387, "dr_gsnew", "mp_flowerbush", 0xFFFFFFFF);
    Tdf_Object[236] = CreateObject(10985, 888.3333, -1076.7197, 21.5876, 0.0000, 4.7999, 0.0000, 75.0000); //rubbled02_SFS
    SetObjectMaterial(Tdf_Object[236], 0, 10368, "cathedral_sfs", "dirt64b2", 0xFFFFFFFF);
    Tdf_Object[237] = CreateObject(2739, 929.1920, -1094.8608, 23.9710, 180.0000, 0.0000, 0.0000, 75.0000); //CJ_B_SINK1
    SetObjectMaterial(Tdf_Object[237], 0, 3440, "airportpillar", "metalic_64", 0xFFFFFFFF);
    Tdf_Object[238] = CreateObject(2739, 933.3123, -1094.8608, 23.9710, 180.0000, 0.0000, 0.0000, 75.0000); //CJ_B_SINK1
    SetObjectMaterial(Tdf_Object[238], 0, 3440, "airportpillar", "metalic_64", 0xFFFFFFFF);
    Tdf_Object[239] = CreateObject(869, 928.7935, -1095.9477, 23.6217, 0.0000, 0.0000, 0.0000, 100.0000); //veg_Pflowerswee
    Tdf_Object[240] = CreateObject(869, 933.7932, -1095.5876, 23.6217, 0.0000, 0.0000, 26.6000, 100.0000); //veg_Pflowerswee
    Tdf_Object[241] = CreateObject(3630, 1156.5959, -1304.0605, 13.9848, 0.0000, 0.0000, 90.0000, 300.0000); //crdboxes2_LAs
    SetObjectMaterial(Tdf_Object[241], 0, 12821, "alleystuff", "cratec", 0xFFFFFFFF);
    Tdf_Object[242] = CreateObject(996, 1177.8586, -1290.7839, 13.2454, 0.0000, 0.0000, 0.5999, 250.0000); //lhouse_barrier1
    SetObjectMaterial(Tdf_Object[242], 0, 17547, "eastbeach4a_lae2", "bluestucco1", 0xFFFFFFFF);
    Tdf_Object[243] = CreateObject(1845, 1839.6175, -1847.6728, 180.0000, 0.0000, 0.0000, 0.0000, 100.0000); //shop_shelf10
    Tdf_Object[244] = CreateObject(2807, 1031.9643, -1344.7082, 13.2391, 0.0000, 0.0000, 126.0000, 75.0000); //CJ_BURG_CHAIR_NA
    SetObjectMaterial(Tdf_Object[244], 1, 19517, "noncolored", "bowlerwhite", 0xFFFFFFFF);
    Tdf_Object[245] = CreateObject(2449, 1034.1123, -1340.6096, 12.6660, 0.0000, 0.0000, 180.0000, 75.0000); //CJ_FF_CONTER_5e
    Tdf_Object[246] = CreateObject(2448, 1034.1191, -1343.8828, 12.6778, 0.0000, 0.0000, -90.0000, 75.0000); //CJ_FF_CONTER_5d
    Tdf_Object[247] = CreateObject(2446, 1031.9593, -1343.6490, 12.6913, 0.0000, 0.0000, 0.0000, 75.0000); //CJ_FF_CONTER_5
    Tdf_Object[248] = CreateObject(2447, 1033.9077, -1346.3319, 12.6976, 0.0000, 0.0000, 90.0000, 75.0000); //CJ_FF_CONTER_5c
    Tdf_Object[249] = CreateObject(2457, 1034.0069, -1350.5820, 12.7137, 0.0000, 0.0000, 90.0000, 75.0000); //CJ_FF_CONTER_8c
    SetObjectMaterial(Tdf_Object[249], 4, 2772, "airp_prop", "CJ_red_COUNTER", 0xFFFFFFFF);
    Tdf_Object[250] = CreateObject(2586, 1034.0251, -1347.9803, 13.2156, 0.0000, 0.0000, 90.0000, 75.0000); //CJ_SEX_COUNTER2
    SetObjectMaterial(Tdf_Object[250], 1, 2772, "airp_prop", "CJ_red_COUNTER", 0xFFFFFFFF);
    SetObjectMaterial(Tdf_Object[250], 2, 2432, "cj_don_sign", "cj_don_post_2", 0xFFFFFFFF);
    SetObjectMaterial(Tdf_Object[250], 7, 1560, "7_11_door", "cj_sheetmetal2", 0xFFFFFFFF);
    Tdf_Object[251] = CreateObject(2665, 1031.0433, -1351.7329, 15.2875, 0.0000, 0.0000, 90.0000, 75.0000); //CJ_FF_LIST04
    SetObjectMaterial(Tdf_Object[251], 0, 2221, "donut_tray", "rustycoffeerap_rb", 0xFFFFFFFF);
    SetObjectMaterial(Tdf_Object[251], 1, 2059, "cj_ammo2", "cj_don_post_1", 0xFFFFFFFF);
    SetObjectMaterial(Tdf_Object[251], 2, 2432, "cj_don_sign", "cj_don_post_2", 0xFFFFFFFF);
    SetObjectMaterial(Tdf_Object[251], 3, 2432, "cj_don_sign", "cj_don_post_3", 0xFFFFFFFF);
    Tdf_Object[252] = CreateObject(2586, 1034.0251, -1352.2419, 13.2156, 0.0000, 0.0000, 90.0000, 75.0000); //CJ_SEX_COUNTER2
    SetObjectMaterial(Tdf_Object[252], 1, 2772, "airp_prop", "CJ_red_COUNTER", 0xFFFFFFFF);
    SetObjectMaterial(Tdf_Object[252], 2, 19297, "matlights", "invisible", 0xFFFFFFFF);
    SetObjectMaterial(Tdf_Object[252], 5, 19297, "matlights", "invisible", 0xFFFFFFFF);
    SetObjectMaterial(Tdf_Object[252], 7, 1560, "7_11_door", "cj_sheetmetal2", 0xFFFFFFFF);
    Tdf_Object[253] = CreateObject(2682, 1033.9885, -1347.0152, 13.8922, 0.0000, 0.0000, 0.0000, 45.0000); //PIZZA_MENU
    SetObjectMaterial(Tdf_Object[253], 0, 2432, "cj_don_sign", "cj_don_post_2", 0xFFFFFFFF);
    Tdf_Object[254] = CreateObject(2665, 1031.0433, -1348.1728, 15.2875, 0.0000, 0.0000, 90.0000, 75.0000); //CJ_FF_LIST04
    SetObjectMaterial(Tdf_Object[254], 0, 18021, "genintintfastd", "CJ_DON_WIN", 0xFFFFFFFF);
    SetObjectMaterial(Tdf_Object[254], 1, 2059, "cj_ammo2", "cj_don_post_1", 0xFFFFFFFF);
    SetObjectMaterial(Tdf_Object[254], 2, 2432, "cj_don_sign", "cj_don_post_2", 0xFFFFFFFF);
    SetObjectMaterial(Tdf_Object[254], 3, 2432, "cj_don_sign", "cj_don_post_3", 0xFFFFFFFF);
    Tdf_Object[255] = CreateObject(2753, 1034.0395, -1348.7237, 13.9209, 0.0000, 0.0000, 90.0000, 45.0000); //CJ_FF_TILL_que
    Tdf_Object[256] = CreateObject(2222, 1033.9884, -1350.2967, 13.6842, 0.0000, 0.0000, -1.3997, 45.0000); //rustyhigh
    SetObjectMaterial(Tdf_Object[256], 0, 19297, "matlights", "invisible", 0xFFFFFFFF);
    SetObjectMaterial(Tdf_Object[256], 1, 2221, "donut_tray", "bagel_rb", 0xFFFFFFFF);
    SetObjectMaterial(Tdf_Object[256], 2, 2221, "donut_tray", "bagel_rb", 0xFFFFFFFF);
    SetObjectMaterial(Tdf_Object[256], 3, 19297, "matlights", "invisible", 0xFFFFFFFF);
    SetObjectMaterial(Tdf_Object[256], 4, 19297, "matlights", "invisible", 0xFFFFFFFF);
    SetObjectMaterial(Tdf_Object[256], 5, 19297, "matlights", "invisible", 0xFFFFFFFF);
    SetObjectMaterial(Tdf_Object[256], 6, 19297, "matlights", "invisible", 0xFFFFFFFF);
    SetObjectMaterial(Tdf_Object[256], 7, 19297, "matlights", "invisible", 0xFFFFFFFF);
    SetObjectMaterial(Tdf_Object[256], 8, 19297, "matlights", "invisible", 0xFFFFFFFF);
    Tdf_Object[257] = CreateObject(2222, 1034.0052, -1349.5964, 13.6842, 0.0000, 0.0000, -1.3997, 45.0000); //rustyhigh
    SetObjectMaterial(Tdf_Object[257], 0, 19297, "matlights", "invisible", 0xFFFFFFFF);
    SetObjectMaterial(Tdf_Object[257], 3, 19297, "matlights", "invisible", 0xFFFFFFFF);
    SetObjectMaterial(Tdf_Object[257], 4, 19297, "matlights", "invisible", 0xFFFFFFFF);
    SetObjectMaterial(Tdf_Object[257], 5, 19297, "matlights", "invisible", 0xFFFFFFFF);
    SetObjectMaterial(Tdf_Object[257], 6, 19297, "matlights", "invisible", 0xFFFFFFFF);
    SetObjectMaterial(Tdf_Object[257], 7, 19297, "matlights", "invisible", 0xFFFFFFFF);
    SetObjectMaterial(Tdf_Object[257], 8, 19297, "matlights", "invisible", 0xFFFFFFFF);
    Tdf_Object[258] = CreateObject(2222, 1033.9967, -1349.9564, 13.6842, 0.0000, 0.0000, -1.3997, 45.0000); //rustyhigh
    SetObjectMaterial(Tdf_Object[258], 0, 19297, "matlights", "invisible", 0xFFFFFFFF);
    SetObjectMaterial(Tdf_Object[258], 1, 19883, "breadslice1", "cj_bread_2", 0xFFFFFFFF);
    SetObjectMaterial(Tdf_Object[258], 2, 2702, "pick_up", "CJ_BREAD", 0xFFFFFFFF);
    SetObjectMaterial(Tdf_Object[258], 3, 19297, "matlights", "invisible", 0xFFFFFFFF);
    SetObjectMaterial(Tdf_Object[258], 4, 19297, "matlights", "invisible", 0xFFFFFFFF);
    SetObjectMaterial(Tdf_Object[258], 5, 19297, "matlights", "invisible", 0xFFFFFFFF);
    SetObjectMaterial(Tdf_Object[258], 6, 19297, "matlights", "invisible", 0xFFFFFFFF);
    SetObjectMaterial(Tdf_Object[258], 7, 19297, "matlights", "invisible", 0xFFFFFFFF);
    SetObjectMaterial(Tdf_Object[258], 8, 19297, "matlights", "invisible", 0xFFFFFFFF);
    Tdf_Object[259] = CreateObject(11741, 1034.0571, -1345.2319, 13.9594, 0.0000, 0.0000, 0.0000, 45.0000); //MCake3
    Tdf_Object[260] = CreateObject(11741, 1034.0571, -1345.2325, 13.6590, 0.0000, 0.0000, 0.0000, 45.0000); //MCake3
    SetObjectMaterial(Tdf_Object[260], 0, 19525, "weddingcake1", "weddingcake1", 0xFFFFFFFF);
    Tdf_Object[261] = CreateObject(11741, 1034.0571, -1344.7320, 13.6590, 0.0000, 0.0000, 0.0000, 45.0000); //MCake3
    SetObjectMaterial(Tdf_Object[261], 0, 19525, "weddingcake1", "bngdecoration1", 0xFFFFFFFF);
    Tdf_Object[262] = CreateObject(11741, 1034.0571, -1344.0915, 13.6590, 0.0000, 0.0000, 0.0000, 45.0000); //MCake3
    SetObjectMaterial(Tdf_Object[262], 0, 14660, "inttattoobits", "tat_spray1", 0xFFFFFFFF);
    Tdf_Object[263] = CreateObject(11739, 1034.0367, -1344.7270, 13.9504, 0.0000, 0.0000, 0.0000, 45.0000); //MCake1
    Tdf_Object[264] = CreateObject(2223, 1034.0345, -1346.3287, 14.0410, 0.0000, 0.0000, 0.0000, 45.0000); //rustymed
    Tdf_Object[265] = CreateObject(11739, 1034.0367, -1344.1064, 13.9504, 0.0000, 0.0000, 0.0000, 45.0000); //MCake1
    SetObjectMaterial(Tdf_Object[265], 0, 19517, "noncolored", "wmoice", 0xFFFFFFFF);
    Tdf_Object[266] = CreateObject(2223, 1034.0355, -1346.2884, 13.7412, 0.0000, 0.0000, -1.3997, 45.0000); //rustymed
    Tdf_Object[267] = CreateObject(2027, 1037.7762, -1346.0592, 13.2810, 0.0000, 0.0000, 90.0000, 75.0000); //dinerseat_4
    SetObjectMaterial(Tdf_Object[267], 1, 19297, "matlights", "invisible", 0xFFFFFFFF);
    SetObjectMaterial(Tdf_Object[267], 2, 19297, "matlights", "invisible", 0xFFFFFFFF);
    SetObjectMaterial(Tdf_Object[267], 3, 19297, "matlights", "invisible", 0xFFFFFFFF);
    SetObjectMaterial(Tdf_Object[267], 4, 14652, "ab_trukstpa", "CJ_CORD", 0xFFFFFFFF);
    SetObjectMaterial(Tdf_Object[267], 5, 14652, "ab_trukstpa", "CJ_WOOD6", 0xFFFFFFFF);
    Tdf_Object[268] = CreateObject(19939, 1036.7724, -1353.3430, 13.5635, 0.0000, 0.0000, 0.0000, 45.0000); //MKShelf2
    SetObjectMaterial(Tdf_Object[268], 0, 18021, "genintintfastd", "tile_test3red", 0xFFFFFFFF);
    Tdf_Object[269] = CreateObject(19939, 1036.7724, -1350.9012, 13.5635, 0.0000, 0.0000, 0.0000, 45.0000); //MKShelf2
    SetObjectMaterial(Tdf_Object[269], 0, 18021, "genintintfastd", "tile_test3red", 0xFFFFFFFF);
    Tdf_Object[270] = CreateObject(2027, 1037.7762, -1353.3818, 13.2810, 0.0000, 0.0000, 90.0000, 75.0000); //dinerseat_4
    SetObjectMaterial(Tdf_Object[270], 1, 19297, "matlights", "invisible", 0xFFFFFFFF);
    SetObjectMaterial(Tdf_Object[270], 2, 19297, "matlights", "invisible", 0xFFFFFFFF);
    SetObjectMaterial(Tdf_Object[270], 3, 19297, "matlights", "invisible", 0xFFFFFFFF);
    SetObjectMaterial(Tdf_Object[270], 4, 14652, "ab_trukstpa", "CJ_CORD", 0xFFFFFFFF);
    SetObjectMaterial(Tdf_Object[270], 5, 14652, "ab_trukstpa", "CJ_WOOD6", 0xFFFFFFFF);
    Tdf_Object[271] = CreateObject(2027, 1037.7762, -1350.9404, 13.2810, 0.0000, 0.0000, 90.0000, 75.0000); //dinerseat_4
    SetObjectMaterial(Tdf_Object[271], 1, 19297, "matlights", "invisible", 0xFFFFFFFF);
    SetObjectMaterial(Tdf_Object[271], 2, 19297, "matlights", "invisible", 0xFFFFFFFF);
    SetObjectMaterial(Tdf_Object[271], 3, 19297, "matlights", "invisible", 0xFFFFFFFF);
    SetObjectMaterial(Tdf_Object[271], 4, 14652, "ab_trukstpa", "CJ_CORD", 0xFFFFFFFF);
    SetObjectMaterial(Tdf_Object[271], 5, 14652, "ab_trukstpa", "CJ_WOOD6", 0xFFFFFFFF);
    Tdf_Object[272] = CreateObject(2027, 1037.7762, -1348.4996, 13.2810, 0.0000, 0.0000, 90.0000, 75.0000); //dinerseat_4
    SetObjectMaterial(Tdf_Object[272], 1, 19297, "matlights", "invisible", 0xFFFFFFFF);
    SetObjectMaterial(Tdf_Object[272], 2, 19297, "matlights", "invisible", 0xFFFFFFFF);
    SetObjectMaterial(Tdf_Object[272], 3, 19297, "matlights", "invisible", 0xFFFFFFFF);
    SetObjectMaterial(Tdf_Object[272], 4, 14652, "ab_trukstpa", "CJ_CORD", 0xFFFFFFFF);
    SetObjectMaterial(Tdf_Object[272], 5, 14652, "ab_trukstpa", "CJ_WOOD6", 0xFFFFFFFF);
    Tdf_Object[273] = CreateObject(19939, 1036.7724, -1348.4593, 13.5635, 0.0000, 0.0000, 0.0000, 45.0000); //MKShelf2
    SetObjectMaterial(Tdf_Object[273], 0, 18021, "genintintfastd", "tile_test3red", 0xFFFFFFFF);
    Tdf_Object[274] = CreateObject(19939, 1036.7724, -1346.0384, 13.5635, 0.0000, 0.0000, 0.0000, 45.0000); //MKShelf2
    SetObjectMaterial(Tdf_Object[274], 0, 18021, "genintintfastd", "tile_test3red", 0xFFFFFFFF);
    Tdf_Object[275] = CreateObject(1775, 1034.8243, -1355.2248, 13.8118, 0.0000, 0.0000, 90.0000, 75.0000); //CJ_SPRUNK1
    Tdf_Object[276] = CreateObject(1776, 1034.7491, -1356.4172, 13.8135, 0.0000, 0.0000, 90.0000, 75.0000); //CJ_CANDYVENDOR
    Tdf_Object[277] = CreateObject(2027, 1040.7364, -1344.1595, 13.2810, 0.0000, 0.0000, 90.0000, 75.0000); //dinerseat_4
    SetObjectMaterial(Tdf_Object[277], 1, 19297, "matlights", "invisible", 0xFFFFFFFF);
    SetObjectMaterial(Tdf_Object[277], 2, 19297, "matlights", "invisible", 0xFFFFFFFF);
    SetObjectMaterial(Tdf_Object[277], 3, 19297, "matlights", "invisible", 0xFFFFFFFF);
    SetObjectMaterial(Tdf_Object[277], 4, 14652, "ab_trukstpa", "CJ_CORD", 0xFFFFFFFF);
    SetObjectMaterial(Tdf_Object[277], 5, 14652, "ab_trukstpa", "CJ_WOOD6", 0xFFFFFFFF);
    Tdf_Object[278] = CreateObject(2027, 1040.7364, -1347.1411, 13.2810, 0.0000, 0.0000, 90.0000, 75.0000); //dinerseat_4
    SetObjectMaterial(Tdf_Object[278], 1, 19297, "matlights", "invisible", 0xFFFFFFFF);
    SetObjectMaterial(Tdf_Object[278], 2, 19297, "matlights", "invisible", 0xFFFFFFFF);
    SetObjectMaterial(Tdf_Object[278], 3, 19297, "matlights", "invisible", 0xFFFFFFFF);
    SetObjectMaterial(Tdf_Object[278], 4, 14652, "ab_trukstpa", "CJ_CORD", 0xFFFFFFFF);
    SetObjectMaterial(Tdf_Object[278], 5, 14652, "ab_trukstpa", "CJ_WOOD6", 0xFFFFFFFF);
    Tdf_Object[279] = CreateObject(2027, 1040.7364, -1350.1628, 13.2810, 0.0000, 0.0000, 90.0000, 75.0000); //dinerseat_4
    SetObjectMaterial(Tdf_Object[279], 1, 19297, "matlights", "invisible", 0xFFFFFFFF);
    SetObjectMaterial(Tdf_Object[279], 2, 19297, "matlights", "invisible", 0xFFFFFFFF);
    SetObjectMaterial(Tdf_Object[279], 3, 19297, "matlights", "invisible", 0xFFFFFFFF);
    SetObjectMaterial(Tdf_Object[279], 4, 14652, "ab_trukstpa", "CJ_CORD", 0xFFFFFFFF);
    SetObjectMaterial(Tdf_Object[279], 5, 14652, "ab_trukstpa", "CJ_WOOD6", 0xFFFFFFFF);
    Tdf_Object[280] = CreateObject(2027, 1040.7364, -1353.1643, 13.2810, 0.0000, 0.0000, 90.0000, 75.0000); //dinerseat_4
    SetObjectMaterial(Tdf_Object[280], 1, 19297, "matlights", "invisible", 0xFFFFFFFF);
    SetObjectMaterial(Tdf_Object[280], 2, 19297, "matlights", "invisible", 0xFFFFFFFF);
    SetObjectMaterial(Tdf_Object[280], 3, 19297, "matlights", "invisible", 0xFFFFFFFF);
    SetObjectMaterial(Tdf_Object[280], 4, 14652, "ab_trukstpa", "CJ_CORD", 0xFFFFFFFF);
    SetObjectMaterial(Tdf_Object[280], 5, 14652, "ab_trukstpa", "CJ_WOOD6", 0xFFFFFFFF);
    Tdf_Object[281] = CreateObject(19939, 1041.7346, -1353.1428, 13.5635, 0.0000, 0.0000, 0.0000, 45.0000); //MKShelf2
    SetObjectMaterial(Tdf_Object[281], 0, 18021, "genintintfastd", "tile_test3red", 0xFFFFFFFF);
    Tdf_Object[282] = CreateObject(19939, 1041.7346, -1350.1599, 13.5635, 0.0000, 0.0000, 0.0000, 45.0000); //MKShelf2
    SetObjectMaterial(Tdf_Object[282], 0, 18021, "genintintfastd", "tile_test3red", 0xFFFFFFFF);
    Tdf_Object[283] = CreateObject(19939, 1041.7346, -1347.0981, 13.5635, 0.0000, 0.0000, 0.0000, 45.0000); //MKShelf2
    SetObjectMaterial(Tdf_Object[283], 0, 18021, "genintintfastd", "tile_test3red", 0xFFFFFFFF);
    Tdf_Object[284] = CreateObject(19939, 1041.7346, -1344.1368, 13.5635, 0.0000, 0.0000, 0.0000, 45.0000); //MKShelf2
    SetObjectMaterial(Tdf_Object[284], 0, 18021, "genintintfastd", "tile_test3red", 0xFFFFFFFF);
    Tdf_Object[285] = CreateObject(2223, 1033.9746, -1340.5063, 14.0214, 0.0000, 0.0000, 90.0000, 45.0000); //rustymed
    Tdf_Object[286] = CreateObject(2223, 1032.9538, -1340.5063, 14.0214, 0.0000, 0.0000, 90.0000, 45.0000); //rustymed
    Tdf_Object[287] = CreateObject(2420, 1040.5804, -1355.9228, 12.7051, 0.0000, 0.0000, -90.0000, 75.0000); //CJ_FF_BUCKET
    SetObjectMaterial(Tdf_Object[287], 0, 16640, "a51", "ws_metalpanel1", 0xFFFFFFFF);
    SetObjectMaterial(Tdf_Object[287], 1, 2221, "donut_tray", "rustyside_rb", 0xFFFFFFFF);
    SetObjectMaterial(Tdf_Object[287], 2, 3629, "arprtxxref_las", "rustybolts", 0xFFFFFFFF);
    Tdf_Object[288] = CreateObject(2420, 1040.5804, -1355.9228, 12.7051, 0.0000, 0.0000, -90.0000, 75.0000); //CJ_FF_BUCKET
    SetObjectMaterial(Tdf_Object[288], 0, 16640, "a51", "ws_metalpanel1", 0xFFFFFFFF);
    SetObjectMaterial(Tdf_Object[288], 1, 2221, "donut_tray", "rustyside_rb", 0xFFFFFFFF);
    SetObjectMaterial(Tdf_Object[288], 2, 3629, "arprtxxref_las", "rustybolts", 0xFFFFFFFF);
    Tdf_Object[289] = CreateObject(2420, 1040.5804, -1356.8038, 12.7051, 0.0000, 0.0000, -90.0000, 75.0000); //CJ_FF_BUCKET
    SetObjectMaterial(Tdf_Object[289], 0, 16640, "a51", "ws_metalpanel1", 0xFFFFFFFF);
    SetObjectMaterial(Tdf_Object[289], 1, 2432, "cj_don_sign", "cj_don_post_2", 0xFFFFFFFF);
    SetObjectMaterial(Tdf_Object[289], 2, 3629, "arprtxxref_las", "rustybolts", 0xFFFFFFFF);
    Tdf_Object[290] = CreateObject(2417, 1031.4171, -1353.4200, 12.6027, 0.0000, 0.0000, 90.0000, 75.0000); //CJ_FF_COOKER
    Tdf_Object[291] = CreateObject(2419, 1031.6947, -1346.9903, 12.6812, 0.0000, 0.0000, 90.0000, 75.0000); //CJ_FF_WORKTOP_2
    Tdf_Object[292] = CreateObject(2426, 1031.2253, -1346.2943, 13.6400, 0.0000, 0.0000, 90.0000, 45.0000); //CJ_FF_PIZZA_OVEN
    Tdf_Object[293] = CreateObject(2417, 1031.4171, -1348.1778, 12.6027, 0.0000, 0.0000, 90.0000, 75.0000); //CJ_FF_COOKER
    Tdf_Object[294] = CreateObject(2419, 1031.5544, -1352.4541, 12.6812, 0.0000, 0.0000, 90.0000, 75.0000); //CJ_FF_WORKTOP_2
    Tdf_Object[295] = CreateObject(2425, 1031.1052, -1345.9609, 14.0326, 0.0000, 0.0000, 90.0000, 100.0000); //CJ_FF_JUICE
    Tdf_Object[296] = CreateObject(19835, 1031.4022, -1346.5338, 14.1154, 0.0000, 0.0000, 0.0000, 45.0000); //CoffeeCup1
    SetObjectMaterial(Tdf_Object[296], 0, 12847, "sprunkworks", "bigsprunkcan", 0xFFFFFFFF);
    SetObjectMaterial(Tdf_Object[296], 1, 19297, "matlights", "invisible", 0xFFFFFFFF);
    SetObjectMaterial(Tdf_Object[296], 2, 2976, "gloopx", "alien_liquid", 0xFFFFFFFF);
    Tdf_Object[297] = CreateObject(19835, 1031.3044, -1346.6334, 14.1154, 0.0000, 0.0000, -48.7999, 45.0000); //CoffeeCup1
    SetObjectMaterial(Tdf_Object[297], 0, 12847, "sprunkworks", "bigsprunkcan", 0xFFFFFFFF);
    SetObjectMaterial(Tdf_Object[297], 1, 19297, "matlights", "invisible", 0xFFFFFFFF);
    SetObjectMaterial(Tdf_Object[297], 2, 2976, "gloopx", "alien_liquid", 0xFFFFFFFF);
    Tdf_Object[298] = CreateObject(2222, 1031.2135, -1353.2910, 13.6239, 0.0000, 0.0000, -1.3997, 45.0000); //rustyhigh
    SetObjectMaterial(Tdf_Object[298], 0, 19297, "matlights", "invisible", 0xFFFFFFFF);
    SetObjectMaterial(Tdf_Object[298], 1, 2221, "donut_tray", "bagel_rb", 0xFFFFFFFF);
    SetObjectMaterial(Tdf_Object[298], 2, 2221, "donut_tray", "bagel_rb", 0xFFFFFFFF);
    SetObjectMaterial(Tdf_Object[298], 3, 19297, "matlights", "invisible", 0xFFFFFFFF);
    SetObjectMaterial(Tdf_Object[298], 4, 19297, "matlights", "invisible", 0xFFFFFFFF);
    SetObjectMaterial(Tdf_Object[298], 5, 19297, "matlights", "invisible", 0xFFFFFFFF);
    SetObjectMaterial(Tdf_Object[298], 6, 19297, "matlights", "invisible", 0xFFFFFFFF);
    SetObjectMaterial(Tdf_Object[298], 7, 19297, "matlights", "invisible", 0xFFFFFFFF);
    SetObjectMaterial(Tdf_Object[298], 8, 19297, "matlights", "invisible", 0xFFFFFFFF);
    Tdf_Object[299] = CreateObject(2416, 1031.5638, -1350.3702, 12.7040, 0.0000, 0.0000, 90.0000, 75.0000); //CJ_FF_DISP
    SetObjectMaterial(Tdf_Object[299], 0, 2221, "donut_tray", "rustyside_rb", 0xFFFFFFFF);
    SetObjectMaterial(Tdf_Object[299], 1, 2221, "donut_tray", "rustyside_rb", 0xFFFFFFFF);
    SetObjectMaterial(Tdf_Object[299], 2, 2772, "airp_prop", "CJ_red_COUNTER", 0xFFFFFFFF);
    Tdf_Object[300] = CreateObject(2222, 1031.3017, -1353.7159, 13.6639, 0.0000, 0.0000, 62.0000, 45.0000); //rustyhigh
    SetObjectMaterial(Tdf_Object[300], 0, 19297, "matlights", "invisible", 0xFFFFFFFF);
    SetObjectMaterial(Tdf_Object[300], 1, 2221, "donut_tray", "bagel_rb", 0xFFFFFFFF);
    SetObjectMaterial(Tdf_Object[300], 2, 2221, "donut_tray", "bagel_rb", 0xFFFFFFFF);
    SetObjectMaterial(Tdf_Object[300], 3, 19297, "matlights", "invisible", 0xFFFFFFFF);
    SetObjectMaterial(Tdf_Object[300], 4, 19297, "matlights", "invisible", 0xFFFFFFFF);
    SetObjectMaterial(Tdf_Object[300], 5, 19297, "matlights", "invisible", 0xFFFFFFFF);
    SetObjectMaterial(Tdf_Object[300], 6, 19297, "matlights", "invisible", 0xFFFFFFFF);
    SetObjectMaterial(Tdf_Object[300], 7, 19297, "matlights", "invisible", 0xFFFFFFFF);
    SetObjectMaterial(Tdf_Object[300], 8, 19297, "matlights", "invisible", 0xFFFFFFFF);
    Tdf_Object[301] = CreateObject(2222, 1031.4361, -1353.8581, 13.5242, 0.0000, 0.0000, 8.7999, 45.0000); //rustyhigh
    SetObjectMaterial(Tdf_Object[301], 0, 19297, "matlights", "invisible", 0xFFFFFFFF);
    SetObjectMaterial(Tdf_Object[301], 1, 2221, "donut_tray", "bagel_rb", 0xFFFFFFFF);
    SetObjectMaterial(Tdf_Object[301], 2, 19297, "matlights", "invisible", 0xFFFFFFFF);
    SetObjectMaterial(Tdf_Object[301], 3, 19297, "matlights", "invisible", 0xFFFFFFFF);
    SetObjectMaterial(Tdf_Object[301], 4, 19297, "matlights", "invisible", 0xFFFFFFFF);
    SetObjectMaterial(Tdf_Object[301], 5, 19297, "matlights", "invisible", 0xFFFFFFFF);
    SetObjectMaterial(Tdf_Object[301], 6, 19297, "matlights", "invisible", 0xFFFFFFFF);
    SetObjectMaterial(Tdf_Object[301], 7, 19297, "matlights", "invisible", 0xFFFFFFFF);
    SetObjectMaterial(Tdf_Object[301], 8, 19297, "matlights", "invisible", 0xFFFFFFFF);
    Tdf_Object[302] = CreateObject(2222, 1031.4178, -1351.6711, 13.7040, 0.0000, 0.0000, -39.1999, 45.0000); //rustyhigh
    Tdf_Object[303] = CreateObject(11743, 1031.2286, -1347.9670, 13.6133, 0.0000, 0.0000, 90.0000, 45.0000); //MCoffeeMachine1
    Tdf_Object[304] = CreateObject(2715, 1039.0091, -1357.4238, 14.8680, 0.0000, 0.0000, 0.0000, 45.0000); //CJ_DON_POSTER
    Tdf_Object[305] = CreateObject(19835, 1031.3021, -1348.2552, 13.6954, 0.0000, 0.0000, 0.0000, 45.0000); //CoffeeCup1
    Tdf_Object[306] = CreateObject(2665, 1041.7237, -1351.9128, 15.2875, 0.0000, 0.0000, -90.0000, 75.0000); //CJ_FF_LIST04
    SetObjectMaterial(Tdf_Object[306], 0, 2221, "donut_tray", "rustycoffeerap_rb", 0xFFFFFFFF);
    SetObjectMaterial(Tdf_Object[306], 1, 2059, "cj_ammo2", "cj_don_post_1", 0xFFFFFFFF);
    SetObjectMaterial(Tdf_Object[306], 2, 2432, "cj_don_sign", "cj_don_post_2", 0xFFFFFFFF);
    SetObjectMaterial(Tdf_Object[306], 3, 2432, "cj_don_sign", "cj_don_post_3", 0xFFFFFFFF);
    Tdf_Object[307] = CreateObject(2665, 1041.7237, -1345.5909, 15.2875, 0.0000, 0.0000, -90.0000, 75.0000); //CJ_FF_LIST04
    SetObjectMaterial(Tdf_Object[307], 0, 2221, "donut_tray", "rustycoffeerap_rb", 0xFFFFFFFF);
    SetObjectMaterial(Tdf_Object[307], 1, 2059, "cj_ammo2", "cj_don_post_1", 0xFFFFFFFF);
    SetObjectMaterial(Tdf_Object[307], 2, 2432, "cj_don_sign", "cj_don_post_2", 0xFFFFFFFF);
    SetObjectMaterial(Tdf_Object[307], 3, 2432, "cj_don_sign", "cj_don_post_3", 0xFFFFFFFF);
    Tdf_Object[308] = CreateObject(19826, 1031.5062, -1342.9138, 14.4273, 0.0000, 0.0000, 90.0000, 45.0000); //LightSwitch1
    Tdf_Object[309] = CreateObject(2715, 1041.7705, -1348.6628, 15.2679, 0.0000, 0.0000, 90.0000, 45.0000); //CJ_DON_POSTER
    SetObjectMaterial(Tdf_Object[309], 0, 2432, "cj_don_sign", "cj_don_post_3", 0xFFFFFFFF);
    Tdf_Object[310] = CreateObject(1893, 1032.5494, -1344.5141, 17.3309, 0.0000, 0.0000, 0.0000, 75.0000); //shoplight1
    Tdf_Object[311] = CreateObject(1893, 1032.5494, -1350.6761, 17.3309, 0.0000, 0.0000, 0.0000, 75.0000); //shoplight1
    Tdf_Object[312] = CreateObject(1893, 1038.6118, -1350.6761, 17.3309, 0.0000, 0.0000, 0.0000, 75.0000); //shoplight1
    Tdf_Object[313] = CreateObject(1893, 1038.6706, -1344.5141, 17.3309, 0.0000, 0.0000, 0.0000, 75.0000); //shoplight1
    Tdf_Object[314] = CreateObject(2342, 1031.5854, -1353.3996, 13.7263, 0.0000, 0.0000, -98.9999, 45.0000); //donut_disp
    SetObjectMaterial(Tdf_Object[314], 1, 19297, "matlights", "invisible", 0xFFFFFFFF);
    SetObjectMaterial(Tdf_Object[314], 2, 19297, "matlights", "invisible", 0xFFFFFFFF);
    SetObjectMaterial(Tdf_Object[314], 3, 19297, "matlights", "invisible", 0xFFFFFFFF);
    Tdf_Object[315] = CreateObject(2420, 1041.2613, -1340.9012, 12.7051, 0.0000, 0.0000, -90.0000, 75.0000); //CJ_FF_BUCKET
    SetObjectMaterial(Tdf_Object[315], 0, 16640, "a51", "ws_metalpanel1", 0xFFFFFFFF);
    SetObjectMaterial(Tdf_Object[315], 1, 2221, "donut_tray", "rustyside_rb", 0xFFFFFFFF);
    SetObjectMaterial(Tdf_Object[315], 2, 3629, "arprtxxref_las", "rustybolts", 0xFFFFFFFF);
    Tdf_Object[316] = CreateObject(2420, 1041.2613, -1341.9621, 12.7051, 0.0000, 0.0000, -90.0000, 75.0000); //CJ_FF_BUCKET
    SetObjectMaterial(Tdf_Object[316], 0, 16640, "a51", "ws_metalpanel1", 0xFFFFFFFF);
    SetObjectMaterial(Tdf_Object[316], 1, 2059, "cj_ammo2", "cj_don_post_1", 0xFFFFFFFF);
    SetObjectMaterial(Tdf_Object[316], 2, 3629, "arprtxxref_las", "rustybolts", 0xFFFFFFFF);
    Tdf_Object[318] = CreateObject(10985, 912.3532, -1069.6422, 21.2572, 7.7999, -1.7999, 0.0000, 75.0000); //rubbled02_SFS
    SetObjectMaterial(Tdf_Object[318], 0, 10368, "cathedral_sfs", "dirt64b2", 0xFFFFFFFF);
    Tdf_Object[319] = CreateObject(19339, 911.3513, -1069.0655, 22.4489, 0.0000, 0.0000, -87.0000, 75.0000); //coffin01
    Tdf_Object[320] = CreateObject(2660, 911.2797, -1069.0743, 22.8201, -90.0000, 0.0000, 125.1996, 75.0000); //CJ_BANNER06
    SetObjectMaterial(Tdf_Object[320], 0, 14387, "dr_gsnew", "mp_flowerbush", 0xFFFFFFFF);
    Tdf_Object[321] = CreateObject(5777, 911.1931, -1066.6545, 24.0566, 0.0000, 0.0000, -90.0000, 100.0000); //tombston01_LAwN
    Tdf_Object[322] = CreateObject(2042, 1247.6057, -907.3239, 45.6878, 0.0000, 0.0000, 42.2000, 100.0000); //AMMO_BOX_M3
    Tdf_Object[323] = CreateObject(1431, 1267.5605, -876.0546, 42.3395, 0.0000, 0.0000, 97.7994, 200.0000); //DYN_BOX_PILE
    SetObjectMaterial(Tdf_Object[323], 0, 3066, "ammotrx", "ammotrn92tarp128", 0xFFD78E10);
    Tdf_Object[324] = CreateObject(19480, 1267.5710, -878.7000, 45.9827, 0.0000, 0.0000, 99.0000, 250.0000); //Plane006
    SetObjectMaterial(Tdf_Object[324], 0, 17518, "hub_alpha", "clothline1_LAe", 0xFFFFFFFF);
    Tdf_Object[325] = CreateObject(19325, 1282.9072, -895.5219, 43.7700, 0.0000, 180.0000, 6.9998, 200.0000); //lsmall_window01
    SetObjectMaterial(Tdf_Object[325], 0, 1530, "tags_lavagos", "vagos", 0xFF000000);
    Tdf_Object[326] = CreateObject(19325, 1264.1412, -905.9641, 41.2728, -1.5999, 180.0000, 7.3997, 200.0000); //lsmall_window01
    SetObjectMaterial(Tdf_Object[326], 0, 1525, "tags_lakilo", "kilotray", 0xFF000000);
    Tdf_Object[327] = CreateObject(19325, 1260.2580, -876.7677, 40.8675, 1.0000, 180.0000, 7.3997, 200.0000); //lsmall_window01
    SetObjectMaterial(Tdf_Object[327], 0, 1528, "tags_laseville", "seville", 0xFF000000);
    Tdf_Object[330] = CreateObject(640, 1243.4995, -890.3165, 42.5550, 0.0000, 0.0000, 97.1996, 250.0000); //kb_planter+bush2
    SetObjectMaterial(Tdf_Object[330], 0, 3455, "vgnhseblk1", "vnghse1_256", 0xFFFFFFFF);
    Tdf_Object[331] = CreateObject(640, 1261.6180, -888.0288, 42.5550, 0.0000, 0.0000, 97.1996, 250.0000); //kb_planter+bush2
    SetObjectMaterial(Tdf_Object[331], 0, 3455, "vgnhseblk1", "vnghse1_256", 0xFFFFFFFF);
    Tdf_Object[333] = CreateObject(984, 1252.5461, -889.1881, 42.4832, 0.0000, 0.0000, 97.1996, 250.0000); //fenceshit2
    SetObjectMaterial(Tdf_Object[333], 0, 3077, "blkbrdx", "nf_blackbrd", 0xFFFFFFFF);
    SetObjectMaterial(Tdf_Object[333], 1, 3077, "blkbrdx", "nf_blackbrd", 0xFFFFFFFF);
    SetObjectMaterial(Tdf_Object[333], 2, 3077, "blkbrdx", "nf_blackbrd", 0xFFFFFFFF);
    SetObjectMaterial(Tdf_Object[333], 3, 3077, "blkbrdx", "nf_blackbrd", 0xFFFFFFFF);
    SetObjectMaterial(Tdf_Object[333], 4, 3077, "blkbrdx", "nf_blackbrd", 0xFFFFFFFF);
    SetObjectMaterial(Tdf_Object[333], 5, 3077, "blkbrdx", "nf_blackbrd", 0xFFFFFFFF);
    SetObjectMaterial(Tdf_Object[333], 6, 3077, "blkbrdx", "nf_blackbrd", 0xFFFFFFFF);
    SetObjectMaterial(Tdf_Object[333], 7, 3077, "blkbrdx", "nf_blackbrd", 0xFFFFFFFF);
    SetObjectMaterial(Tdf_Object[333], 8, 3077, "blkbrdx", "nf_blackbrd", 0xFFFFFFFF);
    SetObjectMaterial(Tdf_Object[333], 9, 5418, "idlewood3_lae", "lasjmrail1", 0xFFFFFFFF);
    Tdf_Object[334] = CreateObject(2673, 1236.9737, -893.1527, 42.6748, 0.0000, 0.0000, 0.0000, 100.0000); //PROC_RUBBISH_5
    Tdf_Object[335] = CreateObject(1432, 1287.3935, -898.8192, 41.9972, 0.0000, 0.0000, -36.7999, 250.0000); //DYN_TABLE_2
    SetObjectMaterial(Tdf_Object[335], 0, 1426, "break_scaffold", "CJ_BLUE_WOOD", 0xFFFFFFFF);
    SetObjectMaterial(Tdf_Object[335], 1, 16640, "a51", "bluemetal", 0xFFFFFFFF);
    SetObjectMaterial(Tdf_Object[335], 2, 17545, "burnsground", "bluapartwall1_256", 0xFFFFFFFF);
    Tdf_Object[336] = CreateObject(2671, 1235.2165, -891.0689, 41.8991, 0.0000, 0.0000, 46.4000, 100.0000); //PROC_RUBBISH_3
    SetObjectMaterial(Tdf_Object[336], 0, 12871, "ce_ground01", "desgreengrassmix", 0xFFFFFFFF);
    SetObjectMaterial(Tdf_Object[336], 1, 2924, "crash3doorx", "villagreen128256", 0xFFFFFFFF);
    SetObjectMaterial(Tdf_Object[336], 2, 701, "badlands", "newtreeleaves128", 0xFFFFFFFF);
    Tdf_Object[337] = CreateObject(869, 1233.8009, -898.2531, 42.3474, 0.0000, 0.0000, 0.0000, 250.0000); //veg_Pflowerswee
    SetObjectMaterial(Tdf_Object[337], 0, 701, "badlands", "newtreeleaves128", 0xFFFFFFFF);
    Tdf_Object[338] = CreateObject(876, 1231.0882, -882.0189, 42.4700, 0.0000, 0.0000, -22.6000, 250.0000); //veg_Pflowers03
    SetObjectMaterial(Tdf_Object[338], 0, 730, "gtatreeshifir", "cedar2", 0xFFFFFFFF);
    Tdf_Object[339] = CreateObject(638, 1294.4177, -884.2415, 42.5689, 0.0000, 0.0000, 97.5998, 250.0000); //kb_planter+bush
    SetObjectMaterial(Tdf_Object[339], 0, 3455, "vgnhseblk1", "vnghse1_256", 0xFFFFFFFF);
    SetObjectMaterial(Tdf_Object[339], 1, 17848, "eastlstr2_lae2", "deadpalm01", 0xFFFFFFFF);
    Tdf_Object[340] = CreateObject(984, 1286.3758, -885.2578, 42.5433, 0.0000, 0.0000, 97.0000, 250.0000); //fenceshit2
    SetObjectMaterial(Tdf_Object[340], 0, 3077, "blkbrdx", "nf_blackbrd", 0xFFFFFFFF);
    SetObjectMaterial(Tdf_Object[340], 1, 3077, "blkbrdx", "nf_blackbrd", 0xFFFFFFFF);
    SetObjectMaterial(Tdf_Object[340], 2, 3077, "blkbrdx", "nf_blackbrd", 0xFFFFFFFF);
    SetObjectMaterial(Tdf_Object[340], 3, 3077, "blkbrdx", "nf_blackbrd", 0xFFFFFFFF);
    SetObjectMaterial(Tdf_Object[340], 4, 3077, "blkbrdx", "nf_blackbrd", 0xFFFFFFFF);
    SetObjectMaterial(Tdf_Object[340], 5, 3077, "blkbrdx", "nf_blackbrd", 0xFFFFFFFF);
    SetObjectMaterial(Tdf_Object[340], 6, 3077, "blkbrdx", "nf_blackbrd", 0xFFFFFFFF);
    SetObjectMaterial(Tdf_Object[340], 7, 3077, "blkbrdx", "nf_blackbrd", 0xFFFFFFFF);
    SetObjectMaterial(Tdf_Object[340], 8, 3077, "blkbrdx", "nf_blackbrd", 0xFFFFFFFF);
    SetObjectMaterial(Tdf_Object[340], 9, 5418, "idlewood3_lae", "lasjmrail1", 0xFFFFFFFF);
    Tdf_Object[341] = CreateObject(8661, 1165.8039, -1320.5727, 12.5289, 0.0000, 0.0000, 0.0000, 500.0000); //gnhtelgrnd_lvs
    SetObjectMaterial(Tdf_Object[341], 0, 4833, "airprtrunway_las", "greyground256", 0xFFFFFFFF);
    Tdf_Object[342] = CreateObject(8661, 1155.3049, -1338.3702, 12.5689, 0.0000, 0.0000, 90.0000, 500.0000); //gnhtelgrnd_lvs
    SetObjectMaterial(Tdf_Object[342], 0, 4833, "airprtrunway_las", "greyground256", 0xFFFFFFFF);
    Tdf_Object[343] = CreateObject(1503, 1301.0683, -856.3416, 42.9327, 0.0000, 0.0000, -90.1996, 250.0000); //DYN_RAMP
    SetObjectMaterial(Tdf_Object[343], 0, 916, "crates_n_stuffext", "CJ_CABLEWRAP", 0xFFFFFFFF);
    SetObjectMaterial(Tdf_Object[343], 1, 18787, "matramps", "grating3", 0xFFFFFFFF);
    Tdf_Object[344] = CreateObject(1462, 1288.4576, -891.3941, 40.3861, 0.0000, 0.0000, -83.0000, 100.0000); //DYN_woodpile
    SetObjectMaterial(Tdf_Object[344], 0, 14786, "ab_sfgymbeams", "knot_wood128", 0xFFFFFFFF);
    Tdf_Object[345] = CreateObject(19622, 1287.7110, -876.5759, 42.6547, -13.3999, 0.0000, -25.3999, 100.0000); //Broom1
    Tdf_Object[346] = CreateObject(1795, 1288.8072, -877.2780, 41.1016, 81.1996, 0.0000, -83.9999, 250.0000); //SWANK_BED_2
    SetObjectMaterial(Tdf_Object[346], 0, 14534, "ab_wooziea", "CJ_WOODDOOR5", 0xFFFFFFFF);
    SetObjectMaterial(Tdf_Object[346], 1, 1738, "cjtemp", "cj_Mattress5", 0xFFFFFFFF);
    Tdf_Object[347] = CreateObject(1810, 1288.2353, -876.4677, 41.9710, 0.0000, 0.0000, 39.9999, 250.0000); //CJ_FOLDCHAIR
    SetObjectMaterial(Tdf_Object[347], 0, 1355, "break_s_bins", "CJ_TABLE_TOP", 0xFFFFFFFF);
    Tdf_Object[348] = CreateObject(2713, 1288.4493, -878.9420, 42.1100, 0.0000, 0.0000, 23.5998, 100.0000); //cj_bucket

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

	//Rodeo
	CreateDynamicObject(1537, 480.399231, -1466.906372, 17.945024, 0.000000, 3.500001, 67.399956);
	CreateDynamicObject(1537, 479.823914, -1468.287720, 18.036587, 0.000000, 3.500001, 67.399956);
	CreateDynamicObject(1557, 475.210205, -1500.308105, 19.434126, 0.000000, 0.000000, 82.099983);
	CreateDynamicObject(1557, 475.440308, -1497.308105, 19.434126, 0.000000, 0.000000, -90.899994);
	CreateDynamicObject(1537, 473.983521, -1517.379395, 19.399544, 0.000000, 0.000000, 95.000000);
	CreateDynamicObject(19176, 493.431915, -1503.016235, 20.997993, 0.000000, 1.000000, 85.599976);
	CreateDynamicObject(19176, 495.748993, -1486.486938, 20.313019, 0.000000, 1.000001, 76.300003);
	CreateDynamicObject(19176, 477.809052, -1536.783203, 19.868849, 0.000000, -1.100015, 107.300026);
	CreateDynamicObject(19176, 493.499023, -1510.411133, 20.963711, 0.000000, 0.000000, 94.700005);
	CreateDynamicObject(19176, 494.104309, -1517.655518, 20.783705, 0.000000, 0.000000, 94.700005);
	CreateDynamicObject(1346, 493.030670, -1499.498779, 20.768122, 0.000000, 0.000000, -92.399963);
	CreateDynamicObject(3471, 476.934601, -1501.526245, 20.622097, 0.000000, 0.000000, -7.299994);
	CreateDynamicObject(18014, 494.382904, -1490.581665, 19.562868, -3.199998, 0.000000, -12.200003);
	CreateDynamicObject(3749, 505.409821, -1446.285889, 19.831541, 0.000000, 0.000000, -39.600002);
	CreateDynamicObject(1231, 479.309723, -1505.094360, 20.595934, 0.000000, 0.000000, 85.499992);
	CreateDynamicObject(1231, 479.977020, -1493.682617, 20.375929, 0.000000, 0.000000, 85.499992);
	CreateDynamicObject(1231, 476.453400, -1514.367920, 20.475929, 0.000000, 0.000000, 91.500000);
	CreateDynamicObject(1231, 478.422241, -1483.869751, 20.035921, 0.000000, 0.000000, 85.499992);
	CreateDynamicObject(1231, 483.644318, -1462.065674, 18.515913, 0.000000, 0.000000, 62.300014);
	CreateDynamicObject(1231, 496.275543, -1482.797363, 19.705908, 0.000000, 0.000000, 75.900024);
	CreateDynamicObject(3749, 508.858673, -1567.105957, 21.171509, 0.000000, 0.000000, 41.299965);
	CreateDynamicObject(18014, 494.398254, -1521.845215, 19.554516, 3.700001, 0.199999, 14.599996);
	CreateDynamicObject(1231, 495.268463, -1525.488525, 19.965919, 0.000000, 0.000000, 103.799965);
	CreateDynamicObject(1231, 493.498871, -1514.975098, 20.455921, 0.000000, 0.000000, 95.699898);
	CreateDynamicObject(1231, 493.450897, -1498.698242, 20.505922, 0.000000, 0.000000, 87.799904);
	CreateDynamicObject(1257, 513.218628, -1448.806152, 15.242550, 0.000000, 0.000000, -129.199997);
	CreateDynamicObject(1366, 487.810852, -1454.569336, 17.162024, 0.000000, 0.000000, -36.900005);
	CreateDynamicObject(1280, 476.579041, -1488.901855, 19.591982, 1.899999, 0.000000, -171.599884);
	CreateDynamicObject(1280, 475.183441, -1509.124268, 19.946339, 0.700000, 0.000000, 165.099869);
	CreateDynamicObject(3041, 493.492706, -1494.528809, 19.269119, 1.500000, -2.100002, -95.400047);
	CreateDynamicObject(2714, 494.295868, -1492.162720, 21.799555, 0.099999, -18.900001, -102.699905);
	CreateDynamicObject(792, 479.386688, -1527.282837, 19.125481, 3.399999, 0.000000, 15.300003);
	CreateDynamicObject(792, 485.045197, -1543.729858, 17.951363, 5.199999, 0.000000, 26.100002);
	CreateDynamicObject(792, 475.575165, -1506.931396, 19.711905, 0.000000, 0.000000, -14.900004);
	CreateDynamicObject(792, 474.244171, -1511.314819, 19.711905, 0.000000, 0.000000, -21.100010);
	CreateDynamicObject(792, 476.709564, -1491.219727, 19.443443, -2.300001, -0.199999, 7.599990);
	CreateDynamicObject(792, 476.074432, -1486.659424, 19.231682, -2.500001, 2.399998, 104.099937);
	CreateDynamicObject(792, 496.404846, -1538.164062, 17.951363, 5.199999, 0.000000, 23.600004);
	CreateDynamicObject(792, 491.569061, -1523.950073, 19.125481, 3.399999, 0.000000, 13.699996);
	CreateDynamicObject(16760, 473.871460, -1487.875122, 31.047207, 0.000000, 0.000000, 175.699966);
	CreateDynamicObject(18014, 475.632965, -1492.384155, 19.731031, -1.899997, 0.000000, 6.899995);
	CreateDynamicObject(3471, 477.320435, -1496.409668, 20.622097, 0.000000, 0.000000, -0.299996);
	CreateDynamicObject(18014, 474.589752, -1486.236816, 19.523470, -1.899997, 0.000000, 13.099998);
	CreateDynamicObject(1231, 475.331573, -1489.216064, 20.265926, 0.000000, 0.000000, 97.899918);
	CreateDynamicObject(1231, 473.651581, -1508.837646, 20.575928, 0.000000, 0.000000, 73.599930);
	CreateDynamicObject(18014, 474.518402, -1505.755005, 20.026606, -0.099997, 0.000000, -12.800005);
	CreateDynamicObject(18014, 472.735443, -1511.635742, 19.957403, 1.000003, 0.000000, -20.800003);
	CreateDynamicObject(18013, 468.921936, -1499.525879, 22.860556, 0.000000, 0.000000, 81.999992);
	CreateDynamicObject(18013, 469.073639, -1494.921509, 22.860556, 0.000000, 0.000000, 90.000000);
	CreateDynamicObject(1231, 492.770264, -1506.776245, 20.505922, 0.000000, 0.000000, 87.799904);
	CreateDynamicObject(18013, 486.685455, -1532.106079, 24.826889, 0.000000, 0.000000, 11.500003);
	CreateDynamicObject(18013, 492.184509, -1530.793823, 24.826889, 0.000000, 0.000000, 11.500003);
	CreateDynamicObject(3498, 490.955688, -1524.952881, 26.010344, 0.000000, 90.000000, 11.799988);
	CreateDynamicObject(3498, 482.116486, -1526.799561, 26.010344, 0.000000, 90.000000, 11.799988);
	CreateDynamicObject(3498, 473.277557, -1528.645020, 26.010344, 0.000000, 90.000000, 11.799988);
	CreateDynamicObject(3498, 483.188690, -1539.120972, 26.670334, 0.000000, 90.000000, 11.799988);
	CreateDynamicObject(3498, 492.027710, -1537.274902, 26.670334, 0.000000, 90.000000, 11.799988);
	CreateDynamicObject(3498, 500.866852, -1535.428589, 26.670334, 0.000000, 90.000000, 11.799988);
	CreateDynamicObject(18013, 493.023346, -1466.625000, 24.226891, 0.000000, 0.000000, -23.099997);
	CreateDynamicObject(3498, 495.253448, -1474.338257, 26.081476, -17.799999, 90.000000, -23.499998);
	CreateDynamicObject(3498, 486.981506, -1470.741943, 26.081476, -17.799999, 90.000000, -23.499998);
	CreateDynamicObject(3498, 478.700439, -1467.141602, 26.081476, -17.799999, 90.000000, -23.499998);
	CreateDynamicObject(3498, 501.585114, -1463.112061, 25.546774, -17.799999, 90.000000, -23.499998);
	CreateDynamicObject(3498, 493.304108, -1459.511230, 25.546774, -17.799999, 90.000000, -23.499998);
	CreateDynamicObject(3498, 485.032349, -1455.915405, 25.546774, -17.799999, 90.000000, -23.499998);
	CreateDynamicObject(18013, 491.832764, -1465.747559, 24.300758, 4.199998, 0.000000, 156.899979);
	CreateDynamicObject(2895, 497.340820, -1460.849731, 25.595287, -90.599983, 0.000000, -33.300003);
	CreateDynamicObject(2895, 495.894501, -1460.246460, 25.598330, -90.599983, 0.000000, -33.300003);
	CreateDynamicObject(2895, 488.725861, -1471.159424, 25.935083, -90.599983, 0.000000, -33.300003);
	CreateDynamicObject(2895, 492.756866, -1472.946899, 25.927536, -90.599983, 0.000000, -33.300003);
	CreateDynamicObject(1616, 493.263550, -1512.702881, 23.391989, 0.000000, 0.000000, 0.000000);
	CreateDynamicObject(3038, 485.365417, -1526.150757, 25.466019, 0.000000, 0.000000, 103.099998);
	CreateDynamicObject(3038, 488.146362, -1538.101929, 26.096029, 0.000000, 0.000000, 103.099998);
	CreateDynamicObject(3038, 489.981567, -1472.108887, 25.472712, 0.000000, 0.000000, 65.900009);
	CreateDynamicObject(3038, 495.240967, -1460.351318, 24.972706, 0.000000, 0.000000, 65.900009);
	CreateDynamicObject(7655, 489.262909, -1484.099487, 27.926231, 0.000000, 0.000000, 0.000000);
	CreateDynamicObject(7655, 483.412964, -1493.560425, 27.926231, 0.000000, 0.000000, 0.000000);
	CreateDynamicObject(7655, 489.262909, -1504.931396, 27.926231, 0.000000, 0.000000, 0.000000);
	CreateDynamicObject(7655, 489.262909, -1521.589844, 27.926231, 0.000000, 0.000000, 0.000000);
	CreateDynamicObject(1972, 493.617462, -1513.105469, 20.902733, 0.000000, 0.000000, -87.200005);
	SetDynamicObjectMaterial(CreateDynamicObject(19426, 494.929108, -1513.163330, 20.668415, 0.000000, 90.000000, 3.099999), 0, 5134, "wasteland_las2", "ws_sandstone2", 0);
	CreateDynamicObject(19623, 493.442017, -1512.876953, 20.811777, 0.000000, 0.000000, -44.300003);
	CreateDynamicObject(19623, 493.446350, -1513.230347, 20.811777, 0.000000, 0.000000, -44.300003);
	CreateDynamicObject(367, 493.682098, -1513.587646, 20.771786, 0.000000, 0.000000, 142.999985);
	SetDynamicObjectMaterial(CreateDynamicObject(19426, 495.697388, -1520.647827, 20.668415, 0.000000, 90.000000, 14.200004), 0, 5134, "wasteland_las2", "ws_sandstone2", 0);
	CreateDynamicObject(1972, 494.402130, -1520.844849, 20.902733, 0.000000, 0.000000, -75.600037);
	SetDynamicObjectMaterial(CreateDynamicObject(19426, 477.861908, -1540.308350, 19.618410, 0.000000, 90.000000, 27.600004), 0, 5134, "wasteland_las2", "ws_sandstone2", 0);
	CreateDynamicObject(1972, 479.054382, -1539.811401, 19.862734, 0.000000, 0.000000, 117.699997);
	SetDynamicObjectMaterial(CreateDynamicObject(19426, 476.511749, -1475.752930, 19.788412, 0.000000, 90.000000, -11.999998), 0, 5134, "wasteland_las2", "ws_sandstone2", 0);
	CreateDynamicObject(1972, 477.766479, -1476.160889, 20.032730, 0.000000, 0.000000, 77.800003);
	CreateDynamicObject(18950, 479.257507, -1540.071533, 19.752674, -8.199995, -92.600021, -29.199995);
	CreateDynamicObject(18950, 479.106720, -1539.827148, 19.741253, -8.199995, -92.600021, -29.199995);
	CreateDynamicObject(2710, 478.892609, -1539.367920, 19.811083, 0.000000, 0.000000, 85.199997);
	CreateDynamicObject(2050, 497.661072, -1532.879761, 19.908098, 0.000000, 0.000000, -66.100006);
	CreateDynamicObject(2049, 497.652313, -1532.874390, 20.796572, 0.000000, -0.100000, -66.600021);
	CreateDynamicObject(2386, 494.237885, -1520.725464, 20.838236, 0.000000, 0.000000, 0.000000);
	CreateDynamicObject(2384, 494.408020, -1521.315308, 20.848228, 0.000000, 0.000000, 0.000000);
	CreateDynamicObject(14521, 496.155792, -1520.624023, 21.099384, 0.000000, 0.000000, 21.599997);
	CreateDynamicObject(18874, 477.989655, -1475.793213, 19.859676, 0.000000, 0.000000, 30.499996);
	CreateDynamicObject(18874, 478.024872, -1475.656250, 19.859676, 0.000000, 0.000000, 30.499996);
	CreateDynamicObject(18869, 477.979340, -1476.058594, 19.859678, 0.000000, 0.000000, 0.000000);
	CreateDynamicObject(18869, 477.849304, -1476.058594, 19.859678, 0.000000, 0.000000, 0.000000);
	CreateDynamicObject(18866, 477.894836, -1476.448853, 19.859678, 0.000000, 0.000000, 114.999992);
	CreateDynamicObject(18866, 477.893799, -1476.328613, 19.859678, 0.000000, 0.000000, 114.999992);
	CreateDynamicObject(1234, 477.884064, -1475.156250, 19.896099, 0.000000, 0.000000, -13.600000);
	CreateDynamicObject(330, 477.584747, -1476.199707, 20.128231, 0.000000, 0.000000, -100.700027);
	CreateDynamicObject(330, 477.603302, -1476.101318, 20.128231, 0.000000, 0.000000, -100.700027);

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
	//CreateDynamicObject(1646, 268.19921875, -1870.79980469, 1.77999997, 3.00000000, 0.00000000, 0.00000000, 0, 0, -1, 400.0); //
	//CreateDynamicObject(1645, 269.39941406, -1870.79980469, 1.77999997, 3.00000000, 0.00000000, 0.00000000, 0, 0, -1, 400.0); //
	//CreateDynamicObject(1645, 270.59960938, -1870.79980469, 1.77999997, 3.00000000, 0.00000000, 0.00000000, 0, 0, -1, 400.0); //
	//CreateDynamicObject(1646, 271.79980469, -1870.89941406, 1.77999997, 3.00000000, 0.00000000, 0.00000000, 0, 0, -1, 400.0); //
	CreateDynamicObject(1598, 255.10000610, -1868.59997559, 1.79999995, 0.00000000, 0.00000000, 0.00000000, 0, 0, -1, 400.0); //
	CreateDynamicObject(1598, 338.89999390, -1887.90002441, 1.20000005, 0.00000000, 0.00000000, 0.00000000, 0, 0, -1, 400.0); //
	CreateDynamicObject(1598, 169.19999695, -1880.19995117, 1.39999998, 0.00000000, 0.00000000, 0.00000000, 0, 0, -1, 400.0); //
	//CreateDynamicObject(1646, 272.89941406, -1870.89941406, 1.77999997, 3.00000000, 0.00000000, 0.00000000, 0, 0, -1, 400.0); //
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


    // VLA Emmet
    CreateDynamicObject(3577, 1691.07727, -1975.60339, 8.53939,   0.00000, 0.00000, 0.00000);
    CreateDynamicObject(3576, 1688.32947, -1972.35852, 9.30083,   0.00000, 0.00000, 180.00000);
    CreateDynamicObject(3576, 1687.89685, -1976.10913, 9.30080,   0.00000, 0.00000, 90.00000);
    CreateDynamicObject(941, 1694.97595, -1973.16956, 8.23873,   0.00000, 0.00000, 90.36005);
    CreateDynamicObject(936, 1694.61487, -1970.61035, 8.28345,   0.00000, 0.00000, -74.52010);
    CreateDynamicObject(3577, 1694.29370, -1975.81567, 8.53940,   0.00000, 0.00000, 180.00000);
    CreateDynamicObject(3577, 1687.96301, -1969.23523, 8.53940,   0.00000, 0.00000, -90.00000);
    CreateDynamicObject(937, 1692.87610, -1969.34448, 8.28299,   0.00000, 0.00000, 0.00000);
    CreateDynamicObject(941, 1690.48828, -1969.25732, 8.23870,   0.00000, 0.00000, 0.00000);
    CreateDynamicObject(2358, 1690.13464, -1969.29773, 7.92955,   0.00000, 0.00000, 22.02000);
    CreateDynamicObject(2358, 1690.87610, -1969.25159, 7.92955,   0.00000, 0.00000, 178.85921);
    CreateDynamicObject(3014, 1691.38904, -1969.75879, 8.02065,   0.00000, 0.00000, 0.00000);
    CreateDynamicObject(3014, 1694.42542, -1972.29150, 8.02065,   0.00000, 0.00000, 0.00000);
    CreateDynamicObject(3014, 1694.91541, -1973.68152, 8.02065,   0.00000, 0.00000, 0.00000);
    CreateDynamicObject(2358, 1694.63831, -1972.97400, 7.92955,   0.00000, 0.00000, 100.80054);
    CreateDynamicObject(2945, 1687.89868, -1969.81567, 10.54690,   0.00000, 0.00000, 90.00000);
    CreateDynamicObject(2945, 1687.93445, -1973.57031, 10.54690,   0.00000, 0.00000, 90.00000);
    CreateDynamicObject(2945, 1690.01440, -1975.59729, 10.54690,   0.00000, 0.00000, 0.00000);
    CreateDynamicObject(2945, 1693.75916, -1975.57959, 10.54690,   0.00000, 0.00000, 0.00000);
    CreateDynamicObject(2068, 1692.39307, -1972.87085, 12.10386,   0.00000, 0.00000, -4.13999);
    CreateDynamicObject(2058, 1694.61292, -1970.69580, 8.77704,   0.00000, 0.00000, 0.00000);
    CreateDynamicObject(2058, 1690.09436, -1969.21301, 8.71985,   0.00000, 0.00000, 0.00000);
    CreateDynamicObject(2064, 1695.77808, -1969.79456, 8.41505,   0.00000, 0.00000, 63.78013);
    CreateDynamicObject(2047, 1691.90625, -1975.54980, 10.50250,   0.00000, 0.00000, 180.00000);


    // Vagos Emmet
    CreateDynamicObject(3577, 2615.04443, -1390.87744, 34.46767,   0.60000, -5.22000, 181.25914);
    CreateDynamicObject(3576, 2615.11792, -1394.72986, 35.24468,   0.00000, 0.00000, 90.60009);
    CreateDynamicObject(3576, 2609.21655, -1390.27869, 35.28242,   0.00000, 0.00000, -89.76016);
    CreateDynamicObject(2062, 2612.98975, -1391.38354, 34.30603,   0.00000, 0.00000, 0.00000);
    CreateDynamicObject(2062, 2612.70776, -1392.17700, 34.26943,   0.00000, 0.00000, 88.49998);
    CreateDynamicObject(2064, 2611.55811, -1392.03406, 34.31248,   0.00000, 0.00000, 0.00000);
    CreateDynamicObject(941, 2609.93726, -1395.42847, 34.50162,   -1.38000, -1.62000, -37.98002);
    CreateDynamicObject(936, 2608.85864, -1393.61023, 34.31594,   2.52000, 5.40000, 95.76000);
    CreateDynamicObject(937, 2612.52734, -1396.00488, 34.41574,   3.00000, -4.20000, 184.49910);
    CreateDynamicObject(3014, 2609.37378, -1395.38110, 34.24118,   -1.80000, -3.06000, -41.82007);
    CreateDynamicObject(3014, 2611.17456, -1396.56042, 34.33735,   -0.60000, 5.94000, -17.64005);
    CreateDynamicObject(2358, 2610.20581, -1396.14783, 34.20118,   -2.94000, 0.48000, -19.62001);
    CreateDynamicObject(2358, 2612.08569, -1396.27039, 34.27462,   -2.46000, 2.94000, 0.84001);
    CreateDynamicObject(2358, 2612.82983, -1396.14832, 34.62661,   -2.46000, 2.94000, 0.84001);
    CreateDynamicObject(2058, 2610.08838, -1395.58813, 34.99343,   -1.01999, -0.36000, 0.00000);
    CreateDynamicObject(2050, 2609.67188, -1390.81006, 35.93570,   0.00000, 0.00000, 0.00000);
    CreateDynamicObject(2049, 2610.41357, -1390.80920, 36.45600,   0.00000, 0.00000, 0.00000);
    CreateDynamicObject(2051, 2611.15503, -1390.80835, 35.72570,   0.00000, 0.00000, 0.00000);
    CreateDynamicObject(2047, 2616.67725, -1391.86365, 35.82505,   0.00000, 0.00000, -90.00000);
    CreateDynamicObject(2068, 2613.23096, -1390.48145, 34.66608,   0.00000, 90.00000, 87.71992);


    // Ballas Emmet
    CreateDynamicObject(3577, 2169.22485, -1510.74890, 23.66784,   0.00000, 0.00000, 0.00000);
    CreateDynamicObject(3577, 2172.48730, -1510.68274, 23.66780,   0.00000, 0.00000, -90.00000);
    CreateDynamicObject(3576, 2171.87158, -1507.45837, 24.43359,   0.00000, 0.00000, 0.00000);
    CreateDynamicObject(2062, 2167.22388, -1510.64514, 23.47137,   0.00000, 0.00000, 0.00000);
    CreateDynamicObject(2062, 2167.22437, -1511.62476, 23.45225,   0.00000, 0.00000, 0.00000);
    CreateDynamicObject(2062, 2166.30835, -1510.98621, 23.27288,   0.00000, 90.00000, 175.55917);
    CreateDynamicObject(941, 2167.42383, -1505.95703, 23.44052,   0.00000, 0.00000, 40.74009);
    CreateDynamicObject(936, 2169.80127, -1504.89368, 23.44364,   0.00000, 0.00000, 0.00000);
    CreateDynamicObject(3577, 2172.45972, -1505.88196, 23.63123,   0.00000, 0.00000, -90.00000);
    CreateDynamicObject(937, 2166.54517, -1507.98572, 23.40520,   0.00000, 0.00000, 90.00000);
    CreateDynamicObject(2358, 2167.56006, -1505.71045, 23.06591,   0.00000, 0.00000, -140.15967);
    CreateDynamicObject(3014, 2167.94873, -1505.23096, 23.17045,   0.00000, 0.00000, 44.16003);
    CreateDynamicObject(2358, 2167.12109, -1506.23389, 23.06591,   0.00000, 0.00000, -231.35869);
    CreateDynamicObject(2358, 2166.41797, -1507.55273, 23.24356,   0.00000, 0.00000, -90.95975);
    CreateDynamicObject(2358, 2166.42334, -1508.29346, 23.24356,   0.00000, 0.00000, -75.83991);
    CreateDynamicObject(2358, 2166.41895, -1507.83301, 23.60356,   0.00000, 0.00000, -96.17988);
    CreateDynamicObject(2064, 2166.43530, -1509.69617, 23.45910,   0.00000, 0.00000, -69.96008);
    CreateDynamicObject(2058, 2167.48608, -1505.71094, 23.92630,   0.00000, 0.00000, 74.34007);
    CreateDynamicObject(2050, 2172.32520, -1506.22571, 25.00286,   0.00000, 0.00000, -90.00000);
    CreateDynamicObject(2051, 2172.30640, -1505.58997, 25.80780,   0.00000, 0.00000, -90.00000);
    CreateDynamicObject(2049, 2172.31689, -1505.12280, 24.84580,   0.00000, 0.00000, -90.00000);
    CreateDynamicObject(2047, 2173.45679, -1504.04236, 25.93031,   0.00000, 0.00000, 180.00000);

    // Weapons
    CreateDynamicObject(337, 2170.47144, -1505.10559, 24.00065,   0.00000, 90.00000, 90.00000); // Shovel
    CreateDynamicObject(336, 2169.82715, -1504.59607, 24.00070,   0.00000, 90.00000, -79.08002); // Bat
    CreateDynamicObject(346, 2169.09839, -1504.90320, 23.91879,   85.74005, 92.33997, -45.00000); // Colt
    CreateDynamicObject(352, 2168.07275, -1505.27966, 23.91880,   90.00000, 90.00000, -72.66008); // Uzi
    CreateDynamicObject(372, 2166.94263, -1506.31592, 23.91880,   90.00000, 90.00000, -26.57990); // Tec
    CreateDynamicObject(349, 2166.26147, -1507.68811, 23.85945,   97.01997, 93.36000, -49.50007); // Shotgun
    CreateDynamicObject(355, 2166.29810, -1508.62866, 23.85940,   97.02000, 93.36000, -51.59982); // AK
}