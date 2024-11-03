// STATIC 3DTEXT

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

	CreateDynamic3DTextLabel("[Los Santos Correctional Facility]\n{ffffff}Available Commands: '/charge'\n{ffffff}Available Commands: '/opencell'\n{ffffff}Available Commands: '/closecell'", COLOR_DARKGREEN, 1256.9117,890.3147,1161.0986, 5.0);

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