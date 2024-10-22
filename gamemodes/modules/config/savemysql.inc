stock SaveFactions()
{
	for (new i = 1; i < MAX_FACTIONS; i ++)
	{
		if(FactionInfo[i][E_FACTION_DBID])
		{
			SaveFaction(i);
		}
	}
	return 1;
}

stock SaveProperties()
{
	for(new i = 1; i < MAX_PROPERTY; i++)
	{
		if(!PropertyInfo[i][E_PROPERTY_DBID])
			continue;
			
		SaveProperty(i); 
	}
	return 1;
}

stock SaveBusinesses()
{
	for(new i = 1; i < MAX_BUSINESS; i++)
	{
		if(!BusinessInfo[i][E_BUSINESS_DBID])
			continue;
			
		SaveBusiness(i);
	}
	return 1;
}

stock SaveFaction(id)
{
	new threadSave[1024];
	
	mysql_format(ourConnection, threadSave, sizeof(threadSave), "UPDATE factions SET FactionName = '%e', FactionAbbrev = '%e', FactionJoinRank = %i, FactionAlterRank = %i, FactionChatRank = %i, FactionTowRank = %i, FactionType = %i, FactionChatColor = %i WHERE DBID = %i",
		FactionInfo[id][E_FACTION_NAME],
		FactionInfo[id][E_FACTION_ABBREV],
		FactionInfo[id][E_FACTION_LOCALRANK],
		FactionInfo[id][E_FACTION_OFFICIALRANK],
		FactionInfo[id][E_FACTION_HIGHRANK],
		FactionInfo[id][E_FACTION_LEADERRANK],
		FactionInfo[id][E_FACTION_TYPE],
		FactionInfo[id][E_FACTION_COLORHEX],
		FactionInfo[id][E_FACTION_DBID]);
	mysql_pquery(ourConnection, threadSave);
	
	mysql_format(ourConnection, threadSave, sizeof(threadSave), "UPDATE factions SET FactionSpawnX = %f, FactionSpawnY = %f, FactionSpawnZ = %f, FactionInterior = %i, FactionWorld = %i, FactionDrugs = %i WHERE DBID = %i",
		FactionInfo[id][E_FACTION_SPAWN][0],
		FactionInfo[id][E_FACTION_SPAWN][1],
		FactionInfo[id][E_FACTION_SPAWN][2],
		FactionInfo[id][E_FACTION_SPAWNINT],
		FactionInfo[id][E_FACTION_SPAWNWORLD],
		FactionInfo[id][E_FACTION_STORAGE],
		FactionInfo[id][E_FACTION_DBID]);
	mysql_pquery(ourConnection, threadSave);
	return 1;
}

stock SaveFactionRanks(id)
{
	if(!FactionInfo[id][E_FACTION_DBID])
		return 0;
		
	new threadSave[256];
	
	for(new i = 1; i < MAX_FACTION_RANKS; i++)
	{
		mysql_format(ourConnection, threadSave, sizeof(threadSave), "UPDATE faction_ranks SET FactionRank%i = %i WHERE factionid = %i", i, FactionRanks[id][i], FactionInfo[id][E_FACTION_DBID]); 
		mysql_pquery(ourConnection, threadSave);
	}
	
	return 1;
}

stock SaveVehicle(vehicleid)
{
	new query[2048];
	
	mysql_format(ourConnection, query, sizeof(query), "UPDATE vehicles SET VehicleOwnerDBID = %i, VehicleColor1 = %i, VehicleColor2 = %i, VehiclePaintjob = %i, VehiclePlates = '%e', VehicleLocked = %i, VehicleSirens = %i, VehicleFuel = %f WHERE VehicleDBID = %i",
		VehicleInfo[vehicleid][E_VEHICLE_OWNERDBID], 
		
		VehicleInfo[vehicleid][E_VEHICLE_COLOR1],
		VehicleInfo[vehicleid][E_VEHICLE_COLOR2],
		VehicleInfo[vehicleid][E_VEHICLE_PAINTJOB],
		VehicleInfo[vehicleid][E_VEHICLE_PLATES],
		VehicleInfo[vehicleid][E_VEHICLE_LOCKED],
		VehicleInfo[vehicleid][E_VEHICLE_SIRENS],
		VehicleInfo[vehicleid][E_VEHICLE_FUEL],
		VehicleInfo[vehicleid][E_VEHICLE_DBID]);
	mysql_pquery(ourConnection, query);
	
	mysql_format(ourConnection, query, sizeof(query), "UPDATE vehicles SET VehicleHealth = %f, VehicleBody = %i, VehicleTire = %i, VehicleTimesDestroyed = %i WHERE VehicleDBID = %i",
		VehicleInfo[vehicleid][E_VEHICLE_HEALTH],
		VehicleInfo[vehicleid][E_VEHICLE_BODY],
		VehicleInfo[vehicleid][E_VEHICLE_TIRE],
		VehicleInfo[vehicleid][E_VEHICLE_DESTROYED],
		VehicleInfo[vehicleid][E_VEHICLE_DBID]);
	mysql_pquery(ourConnection, query);
	
	mysql_format(ourConnection, query, sizeof(query), "UPDATE vehicles SET VehicleParkPosX = %f, VehicleParkPosY = %f, VehicleParkPosZ = %f, VehicleParkPosA = %f, VehicleParkInterior = %i, VehicleParkWorld = %i WHERE VehicleDBID = %i",
		VehicleInfo[vehicleid][E_VEHICLE_POS][0],
		VehicleInfo[vehicleid][E_VEHICLE_POS][1], 
		VehicleInfo[vehicleid][E_VEHICLE_POS][2],
		VehicleInfo[vehicleid][E_VEHICLE_POS][3],
		VehicleInfo[vehicleid][E_VEHICLE_INT],
		VehicleInfo[vehicleid][E_VEHICLE_WORLD],
		VehicleInfo[vehicleid][E_VEHICLE_DBID]);
	mysql_pquery(ourConnection, query);
	
	mysql_format(ourConnection, query, sizeof(query), "UPDATE vehicles SET VehicleImpounded = %i, VehicleImpoundPosX = %f, VehicleImpoundPosY = %f, VehicleImpoundPosZ = %f, VehicleImpoundPosA = %f WHERE VehicleDBID = %i",
		VehicleInfo[vehicleid][E_VEHICLE_IMPOUND],
		VehicleInfo[vehicleid][E_VEHICLE_IMPOUNDPOS][0],
		VehicleInfo[vehicleid][E_VEHICLE_IMPOUNDPOS][1],
		VehicleInfo[vehicleid][E_VEHICLE_IMPOUNDPOS][2],
		VehicleInfo[vehicleid][E_VEHICLE_IMPOUNDPOS][3],
		VehicleInfo[vehicleid][E_VEHICLE_DBID]);
	mysql_pquery(ourConnection, query);
	
	for(new j = 1; j < 5; j++)
	{
		mysql_format(ourConnection, query, sizeof(query), "UPDATE vehicles SET VehicleLastDrivers%d = %i, VehicleLastPassengers%d = %i WHERE VehicleDBID = %i",
			j,
			VehicleInfo[vehicleid][E_VEHICLE_LASTDRIVER][j],
			j,
			VehicleInfo[vehicleid][E_VEHICLE_LASTPASSENGERS][j],
			VehicleInfo[vehicleid][E_VEHICLE_DBID]);
		mysql_pquery(ourConnection, query);	
	}
	for(new m = 0; m < 13; m++)
	{
		mysql_format(ourConnection, query, sizeof(query), "UPDATE vehicles SET VehicleMods%d = %i, VehicleWheels = %i, VehicleHydraulics = %i WHERE VehicleDBID = %i",
			m,
			VehicleInfo[vehicleid][E_VEHICLE_MODS][m],
			VehicleInfo[vehicleid][E_VEHICLE_WHEELS],
			VehicleInfo[vehicleid][E_VEHICLE_HYDRAULICS],
			VehicleInfo[vehicleid][E_VEHICLE_DBID]);
		mysql_pquery(ourConnection, query);
			
	}
	return 1;
}

stock SaveProperty(id)
{
	new query[512]; 
	
	mysql_format(ourConnection, query, sizeof(query), "UPDATE properties SET PropertyOwnerDBID = %i, PropertyType = %i, PropertyFaction = %i, PropertyLocked = %i, PropertyCashbox = %i, PropertyLevel = %i, PropertyMarketPrice = %i WHERE PropertyDBID = %i",
		PropertyInfo[id][E_PROPERTY_OWNERDBID], 
		PropertyInfo[id][E_PROPERTY_TYPE],
		PropertyInfo[id][E_PROPERTY_FACTION],
		PropertyInfo[id][E_PROPERTY_LOCKED],
		PropertyInfo[id][E_PROPERTY_CASH],
		PropertyInfo[id][E_PROPERTY_LEVEL],
		PropertyInfo[id][E_PROPERTY_PRICE],
		PropertyInfo[id][E_PROPERTY_DBID]);
	mysql_pquery(ourConnection, query); 
	
	mysql_format(ourConnection, query, sizeof(query), "UPDATE properties SET PropertyEntranceX = %f, PropertyEntranceY = %f, PropertyEntranceZ = %f, PropertyEntranceInterior = %i, PropertyEntranceWorld = %i WHERE PropertyDBID = %i",
		PropertyInfo[id][E_PROPERTY_ENTRANCEPOS][0],
		PropertyInfo[id][E_PROPERTY_ENTRANCEPOS][1],
		PropertyInfo[id][E_PROPERTY_ENTRANCEPOS][2],
		PropertyInfo[id][E_PROPERTY_ENTRANCEINTERIOR],
		PropertyInfo[id][E_PROPERTY_ENTRANCEWORLD],
		PropertyInfo[id][E_PROPERTY_DBID]);
	mysql_pquery(ourConnection, query);
	 
	mysql_format(ourConnection, query, sizeof(query), "UPDATE properties SET PropertyInteriorX = %f, PropertyInteriorY = %f, PropertyInteriorZ = %f, PropertyInteriorIntID = %i, PropertyInteriorWorld = %i, PropertyAddress = '%e' WHERE PropertyDBID = %i",
		PropertyInfo[id][E_PROPERTY_INTERIORPOS][0],
		PropertyInfo[id][E_PROPERTY_INTERIORPOS][1],
		PropertyInfo[id][E_PROPERTY_INTERIORPOS][2],
		PropertyInfo[id][E_PROPERTY_INTERIORINTERIOR],
		PropertyInfo[id][E_PROPERTY_INTERIORWORLD],
		PropertyInfo[id][E_PROPERTY_ADDRESS],
		PropertyInfo[id][E_PROPERTY_DBID]);
	mysql_pquery(ourConnection, query);

	return 1;
}

stock SaveEntrance(id)
{
	new query[512]; 
	
	mysql_format(ourConnection, query, sizeof(query), "UPDATE entrance SET posx = %f, posy = %f, posz = %f, icon = %i WHERE ID = %i",
		EntranceInfo[id][E_ENTRANCE_POS][0],
		EntranceInfo[id][E_ENTRANCE_POS][1],
		EntranceInfo[id][E_ENTRANCE_POS][2],
		EntranceInfo[id][E_ENTRANCE_ICON],
		EntranceInfo[id][E_PROPERTY_DBID]);
	mysql_pquery(ourConnection, query);
	 
	mysql_format(ourConnection, query, sizeof(query), "UPDATE entrance SET intx = %f, inty = %f, intz = %f, interior = %i, world = %i, garage = %i WHERE ID = %i",
		EntranceInfo[id][E_ENTRANCE_INT][0],
		EntranceInfo[id][E_ENTRANCE_INT][1],
		EntranceInfo[id][E_ENTRANCE_INT][2],
		EntranceInfo[id][E_ENTRANCE_INTERIOR],
		EntranceInfo[id][E_ENTRANCE_WORLD],
		EntranceInfo[id][E_ENTRANCE_GARAGE],
		EntranceInfo[id][E_PROPERTY_DBID]);
	mysql_pquery(ourConnection, query);

	return 1;
}

stock SaveBusiness(id)
{
	new query[512];
	
	mysql_format(ourConnection, query, sizeof(query), "UPDATE businesses SET BusinessOwnerDBID = %i, BusinessName = '%e', BusinessType = %i, BusinessLocked = %i, BusinessEntranceFee = %i, BusinessLevel = %i, BusinessCashbox = %i, BusinessProducts = %i, BusinessMarketPrice = %i, BusinessRobberyTime = %i, BusinessShipments = %i WHERE BusinessDBID = %i",
		BusinessInfo[id][E_BUSINESS_OWNERDBID],
		BusinessInfo[id][E_BUSINESS_NAME],
		BusinessInfo[id][E_BUSINESS_TYPE],
		BusinessInfo[id][E_BUSINESS_LOCKED], 
		BusinessInfo[id][E_BUSINESS_ENTRANCEFEE],
		BusinessInfo[id][E_BUSINESS_LEVEL],
		BusinessInfo[id][E_BUSINESS_CASH],
		BusinessInfo[id][E_BUSINESS_STOCK],
		BusinessInfo[id][E_BUSINESS_PRICE],
		BusinessInfo[id][E_BUSINESS_ROBBERYTIME],
		BusinessInfo[id][E_BUSINESS_SHIPMENTS],
		BusinessInfo[id][E_BUSINESS_DBID]);
	mysql_pquery(ourConnection, query);
	
	mysql_format(ourConnection, query, sizeof(query), "UPDATE businesses SET BusinessInteriorX = %f, BusinessInteriorY = %f, BusinessInteriorZ = %f, BusinessInteriorWorld = %i, BusinessInteriorIntID = %i WHERE BusinessDBID = %i",
		BusinessInfo[id][E_BUSINESS_INTERIORPOS][0],
		BusinessInfo[id][E_BUSINESS_INTERIORPOS][1],
		BusinessInfo[id][E_BUSINESS_INTERIORPOS][2],
		BusinessInfo[id][E_BUSINESS_INTERIORPOSWORLD],
		BusinessInfo[id][E_BUSINESS_INTERIORPOSINTERIOR],
		BusinessInfo[id][E_BUSINESS_DBID]);
	mysql_pquery(ourConnection, query);
	
	mysql_format(ourConnection, query, sizeof(query), "UPDATE businesses SET BusinessEntranceX = %f, BusinessEntranceY = %f, BusinessEntranceZ = %f, BusinessPointX = %f, BusinessPointY = %f, BusinessPointZ = %f WHERE BusinessDBID = %i",
		BusinessInfo[id][E_BUSINESS_ENTRANCEPOS][0],
		BusinessInfo[id][E_BUSINESS_ENTRANCEPOS][1],
		BusinessInfo[id][E_BUSINESS_ENTRANCEPOS][2],
		BusinessInfo[id][E_BUSINESS_ENTRANCEPOINT][0],
		BusinessInfo[id][E_BUSINESS_ENTRANCEPOINT][1],
		BusinessInfo[id][E_BUSINESS_ENTRANCEPOINT][2],
		BusinessInfo[id][E_BUSINESS_DBID]);
	mysql_pquery(ourConnection, query);
	return 1;
}

stock SaveServerDatas(id)
{
	new query[400];
	
	mysql_format(ourConnection, query, sizeof(query), "UPDATE server_data SET fabric = %i, steel = %i, woods = %i, foods = %i, clothes = %i, appliances = %i, materials = %i, drugs = %i WHERE id = %i",
		ServerInfo[id][E_SERVER_FABRIC],
		ServerInfo[id][E_SERVER_STEEL],
		ServerInfo[id][E_SERVER_WOODS],
		ServerInfo[id][E_SERVER_FOODS],
		ServerInfo[id][E_SERVER_CLOTHES],
		ServerInfo[id][E_SERVER_APPLIANCES],
		ServerInfo[id][E_SERVER_MATERIALS],
		ServerInfo[id][E_SERVER_DRUGS],
		ServerInfo[id][E_SERVER_DBID]);
	mysql_pquery(ourConnection, query);
	return 1;
}

stock Tree_Save(id)
{
	new query[400];
	
	mysql_format(ourConnection, query, sizeof(query), "UPDATE tree SET posx = %f, posy = %f, posz = %f, posrx = %f, posry = %f, posrz = %f, time = %i WHERE id = %i",
		TreeInfo[id][E_TREE_POS][0],
		TreeInfo[id][E_TREE_POS][1],
		TreeInfo[id][E_TREE_POS][2],
		TreeInfo[id][E_TREE_POS][3],
		TreeInfo[id][E_TREE_POS][4],
		TreeInfo[id][E_TREE_POS][5],
		TreeInfo[id][E_TREE_TIMER],
		TreeInfo[id][E_TREE_DBID]);
	mysql_pquery(ourConnection, query);
	return 1;
}

stock Court_Save(cid)
{
	new query[512];

	mysql_format(ourConnection,query, sizeof(query), "UPDATE court SET ballx = %f, bally = %f, ballz = %f WHERE ID = %i",
		CourtInfo[cid][E_BALL_POS][0],
	    CourtInfo[cid][E_BALL_POS][1],
	    CourtInfo[cid][E_BALL_POS][2],
	    CourtInfo[cid][E_COURT_DBID]
	);
	mysql_pquery(ourConnection, query);

	mysql_format(ourConnection,query, sizeof(query), "UPDATE court SET bluex = %f, bluey = %f, bluez = %f, bluebx = %f, blueby = %f, bluebz = %f WHERE ID = %i",
		CourtInfo[cid][E_BLUE_POS][0],
	    CourtInfo[cid][E_BLUE_POS][1],
	    CourtInfo[cid][E_BLUE_POS][2],
		CourtInfo[cid][E_BLUE_BALL][0],
	    CourtInfo[cid][E_BLUE_BALL][1],
	    CourtInfo[cid][E_BLUE_BALL][2],
	    CourtInfo[cid][E_COURT_DBID]
	);
	mysql_pquery(ourConnection, query);

	mysql_format(ourConnection,query, sizeof(query), "UPDATE court SET redx = %f, redy = %f, redz = %f, redbx = %f, redby = %f, redbz = %f WHERE ID = %i",
		CourtInfo[cid][E_RED_POS][0],
	    CourtInfo[cid][E_RED_POS][1],
	    CourtInfo[cid][E_RED_POS][2],
		CourtInfo[cid][E_RED_BALL][0],
	    CourtInfo[cid][E_RED_BALL][1],
	    CourtInfo[cid][E_RED_BALL][2],
	    CourtInfo[cid][E_COURT_DBID]
	);
	mysql_pquery(ourConnection, query);
	return 1;
}