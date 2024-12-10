// STATIC 3DTEXT

InsertDynamicPickup()
{
    SideJobsPickup[0] = CreateDynamicPickup(1210, 1, 1529.5608,-1849.4032,13.5469, -1, -1, -1, 5.0);
    SideJobsPickup[1] = CreateDynamicPickup(1210, 1, 2748.7725,-2451.0012,13.6484, -1, -1, -1, 5.0);
	SideJobsPickup[2] = CreateDynamicPickup(1210, 1, 860.7480,-1372.0948,13.5469, -1, -1, -1, 5.0);
	SideJobsPickup[3] = CreateDynamicPickup(1210, 1, 1696.8093,-1527.8206,13.4835, -1, -1, -1, 5.0);
	ChainsawPickup = CreateDynamicPickup(1239, 1, -1448.7738,-1530.5585,101.7578, -1, -1, -1, 5.0);
	DropInjuredPickup = CreateDynamicPickup(1240, 1, 2035.0732,-1414.0488,16.9922, -1, -1, -1, 5.0);
	VehicleScrapPickup = CreateDynamicPickup(1254, 1, 2412.9312,-1425.4226,23.9835, -1, -1, -1, 5.0);
	PrisonPickup = CreateDynamicPickup(1247, 1, 1256.9117,890.3147,1161.0986, -1, -1, -1, 5.0);
	HairCutPickup = CreateDynamicPickup(2752, 1, 2064.5574,-1794.9839,13.4599, -1, -1, -1, 5.0);
	TicketPickup = CreateDynamicPickup(1239, 1, 249.1299,67.8123,1003.6406, -1, -1, -1, 5.0);
	LotteryPickup = CreateDynamicPickup(1239, 1, 1098.1724,-1495.9231,15.7969, -1, -1, -1, 5.0);
	FishFactoryPickup = CreateDynamicPickup(1239, 1, 2610.7708,-2441.7927,13.6310, -1, -1, -1, 5.0);
	SAPDPickup = CreateDynamicPickup(1239, 1, 1568.7626,-1695.0494,5.8906, -1, -1, -1, 5.0);
	SAMDPickup = CreateDynamicPickup(1239, 1, 1124.1577,-1324.4509,13.6212, -1, -1, -1, 5.0);
	GeneralStorePickup[0] = CreateDynamicPickup(1274, 1, -48.4748,-1.1597,203.2633, -1, -1, -1, 5.0);
	GeneralStorePickup[1] = CreateDynamicPickup(1274, 1, -53.7980,2.8393,203.2633, -1, -1, -1, 5.0);
	GeneralStorePickup[2] = CreateDynamicPickup(1274, 1, -51.4530,5.4811,203.2633, -1, -1, -1, 5.0);
	GeneralStorePickup[3] = CreateDynamicPickup(1274, 1, -48.1108,5.5907,203.2633, -1, -1, -1, 5.0);
	GeneralStorePickup[4] = CreateDynamicPickup(1274, 1, -53.7646,5.2118,203.2633, -1, -1, -1, 5.0);

	for(new i; i < sizeof(BusStop_Index); i++)
	{
		BusStopPickup[i] = CreateDynamicPickup(1239, 1, BusStop_Index[i][0], BusStop_Index[i][1], BusStop_Index[i][2], -1, -1, -1, 5.0);
	}
}

Insert3DTextLabel()
{
    new str1[256], str2[256]; 
    
    format(str1, sizeof(str1), "[Gunstore Materials]\n{ffffff}Available stock: %d / 1000\nMaterials Price $5 / gram", ServerInfo[0][E_SERVER_MATERIALS]);
    CreateDynamic3DTextLabel(str1, COLOR_3DTEXT, -576.3427,-505.8364,25.5234, 5.0);

    format(str2, sizeof(str2), "[Drugs Labs]\n{ffffff}Available stock: %d / 100\nMarijuana Price $3000 / 25 gram\nCocaine Price $5000 / 30 gram\nHeroin Price $5000 / 30 gram", ServerInfo[0][E_SERVER_DRUGS]);
    CreateDynamic3DTextLabel(str2, COLOR_3DTEXT, 122.0707,-319.1785,1.5781, 5.0);

	fittingRoomDoor = CreateDynamicObject(2877, 216.760360, -97.310455, 1005.337768, 0.0, 0.0, 360.0, .interiorid = 15);
}