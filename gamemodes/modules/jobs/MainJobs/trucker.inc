CMD:cargobuy(playerid, params[])
{
	if(PlayerInfo[playerid][E_CHARACTER_JOBS] != JOB_TRUCKER)
        return SendErrorMessage(playerid, "You aren't truckers.");

	if(PlayerInfo[playerid][E_CHARACTER_HUNGRY] < 20 || PlayerInfo[playerid][E_CHARACTER_THIRSTY] < 20)
		return SendErrorMessage(playerid, "You're hungry or thirsty right now.");

	// Primary:
	if(IsPlayerInRangeOfPoint(playerid, 3.0, IndustryInfo[0][Posx], IndustryInfo[0][Posy], IndustryInfo[0][Posz]))
	{
		if(Inventory_Count(playerid, "Fabric Cargo") || Inventory_Count(playerid, "Steel Cargo") || Inventory_Count(playerid, "Woods Cargo") || Inventory_Count(playerid, "Foods Cargo")
		|| Inventory_Count(playerid, "Clothes Cargo") || Inventory_Count(playerid, "Appliances Cargo") || Inventory_Count(playerid, "Fish Cargo"))
			return SendErrorMessage(playerid, "You are already carrying your cargo.");

		if(!ServerInfo[0][E_SERVER_FABRIC])
			return SendErrorMessage(playerid, "This cargo storage is out of stock.");

		Inventory_Add(playerid, "Fabric Cargo", 2912, 1);
		SetPlayerSpecialAction(playerid, SPECIAL_ACTION_CARRY);
		SetPlayerAttachedObject(playerid, ATTACH_CARGO, 2912, 1, -0.019, 0.713999, -0.076, 0, 87.1, -9.4, 1.0000, 1.0000, 1.0000);
		new Cents = floatround(IndustryInfo[0][Price] * 100, floatround_round);

		SetPlayerNeeds(playerid, -0.3, -0.2);
		
	    GiveMoney(playerid, -Cents);

		ServerData_Minus(INDUSTRY_FABRIC, 1);

		SendJobsMessage(playerid, "[Trucker] {DEDEDE}You has purchase cargo for $%s.", FormatMoney(Cents));
		SendTipMessage(playerid, "You can place cargo by type /cartrunk and sell into industries or business by type /tpda.");
	}
	if(IsPlayerInRangeOfPoint(playerid, 3.0, IndustryInfo[1][Posx], IndustryInfo[1][Posy], IndustryInfo[1][Posz]))
	{
		if(Inventory_Count(playerid, "Fabric Cargo") || Inventory_Count(playerid, "Steel Cargo") || Inventory_Count(playerid, "Woods Cargo") || Inventory_Count(playerid, "Foods Cargo")
		|| Inventory_Count(playerid, "Clothes Cargo") || Inventory_Count(playerid, "Appliances Cargo") || Inventory_Count(playerid, "Fish Cargo"))
			return SendErrorMessage(playerid, "You are already carrying your cargo.");

		if(!ServerInfo[0][E_SERVER_STEEL])
			return SendErrorMessage(playerid, "This cargo storage is out of stock.");

		Inventory_Add(playerid, "Steel Cargo", 2912, 1);
		SetPlayerSpecialAction(playerid, SPECIAL_ACTION_CARRY);
		SetPlayerAttachedObject(playerid, ATTACH_CARGO, 2912, 1, -0.019, 0.713999, -0.076, 0, 87.1, -9.4, 1.0000, 1.0000, 1.0000);
		new Cents = floatround(IndustryInfo[1][Price] * 100, floatround_round);

		SetPlayerNeeds(playerid, -0.3, -0.2);

	    GiveMoney(playerid, -Cents);

		ServerData_Minus(INDUSTRY_STEEL, 1);

		SendJobsMessage(playerid, "[Trucker] {DEDEDE}You has purchase cargo for $%s.", FormatMoney(Cents));
		SendTipMessage(playerid, "You can place cargo by type /cartrunk and sell into industries or business by type /tpda.");
	}
	if(IsPlayerInRangeOfPoint(playerid, 3.0, IndustryInfo[2][Posx], IndustryInfo[2][Posy], IndustryInfo[2][Posz])) //woods
	{
		if(Inventory_Count(playerid, "Fabric Cargo") || Inventory_Count(playerid, "Steel Cargo") || Inventory_Count(playerid, "Woods Cargo") || Inventory_Count(playerid, "Foods Cargo")
		|| Inventory_Count(playerid, "Clothes Cargo") || Inventory_Count(playerid, "Appliances Cargo") || Inventory_Count(playerid, "Fish Cargo"))
			return SendErrorMessage(playerid, "You are already carrying your cargo.");

		if(!ServerInfo[0][E_SERVER_WOODS])
			return SendErrorMessage(playerid, "This cargo storage is out of stock.");

		Inventory_Add(playerid, "Woods Cargo", 2912, 1);
		SetPlayerSpecialAction(playerid, SPECIAL_ACTION_CARRY);
		SetPlayerAttachedObject(playerid, ATTACH_CARGO, 2912, 1, -0.019, 0.713999, -0.076, 0, 87.1, -9.4, 1.0000, 1.0000, 1.0000);
		new Cents = floatround(IndustryInfo[2][Price] * 100, floatround_round);

		SetPlayerNeeds(playerid, -0.3, -0.2);

	    GiveMoney(playerid, -Cents);

		ServerData_Minus(INDUSTRY_WOODS, 1);

		SendJobsMessage(playerid, "[Trucker] {DEDEDE}You has purchase cargo for $%s.", FormatMoney(Cents));
		SendTipMessage(playerid, "You can place cargo by type /cartrunk and sell into industries or business by type /tpda.");
	} 
	if(IsPlayerInRangeOfPoint(playerid, 3.0, IndustryInfo[3][Posx], IndustryInfo[3][Posy], IndustryInfo[3][Posz])) //woods
	{
		if(Inventory_Count(playerid, "Fabric Cargo") || Inventory_Count(playerid, "Steel Cargo") || Inventory_Count(playerid, "Woods Cargo") || Inventory_Count(playerid, "Foods Cargo")
		|| Inventory_Count(playerid, "Clothes Cargo") || Inventory_Count(playerid, "Appliances Cargo") || Inventory_Count(playerid, "Fish Cargo"))
			return SendErrorMessage(playerid, "You are already carrying your cargo.");

		if(!ServerInfo[0][E_SERVER_FISH])
			return SendErrorMessage(playerid, "This cargo storage is out of stock.");

		Inventory_Add(playerid, "Fish Cargo", 2912, 1);
		SetPlayerSpecialAction(playerid, SPECIAL_ACTION_CARRY);
		SetPlayerAttachedObject(playerid, ATTACH_CARGO, 2912, 1, -0.019, 0.713999, -0.076, 0, 87.1, -9.4, 1.0000, 1.0000, 1.0000);
		new Cents = floatround(IndustryInfo[3][Price] * 100, floatround_round);

		SetPlayerNeeds(playerid, -0.3, -0.2);

	    GiveMoney(playerid, -Cents);

		ServerData_Minus(INDUSTRY_FISH, 1);

		SendJobsMessage(playerid, "[Trucker] {DEDEDE}You has purchase cargo for $%s.", FormatMoney(Cents));
		SendTipMessage(playerid, "You can place cargo by type /cartrunk and sell into industries or business by type /tpda.");
	} 

	// Secondary:
	if(IsPlayerInRangeOfPoint(playerid, 3.0, IndustryInfo[4][Posx], IndustryInfo[4][Posy], IndustryInfo[4][Posz]))
	{
		if(Inventory_Count(playerid, "Fabric Cargo") || Inventory_Count(playerid, "Steel Cargo") || Inventory_Count(playerid, "Woods Cargo") || Inventory_Count(playerid, "Foods Cargo")
		|| Inventory_Count(playerid, "Clothes Cargo") || Inventory_Count(playerid, "Appliances Cargo") || Inventory_Count(playerid, "Fish Cargo"))
			return SendErrorMessage(playerid, "You are already carrying your cargo.");

		if(!ServerInfo[0][E_SERVER_FOODS])
			return SendErrorMessage(playerid, "This cargo storage is out of stock.");

		Inventory_Add(playerid, "Foods Cargo", 2912, 1);
		SetPlayerSpecialAction(playerid, SPECIAL_ACTION_CARRY);
		SetPlayerAttachedObject(playerid, ATTACH_CARGO, 2912, 1, -0.019, 0.713999, -0.076, 0, 87.1, -9.4, 1.0000, 1.0000, 1.0000);
		new Cents = floatround(IndustryInfo[4][Price] * 100, floatround_round);

		SetPlayerNeeds(playerid, -0.3, -0.2);

	    GiveMoney(playerid, -Cents);

		ServerData_Minus(INDUSTRY_FOODS, 1);

		SendJobsMessage(playerid, "[Trucker] {DEDEDE}You has purchase cargo for $%s.", FormatMoney(Cents));
		SendTipMessage(playerid, "You can place cargo by type /cartrunk and sell into industries or business by type /tpda.");
	}
	if(IsPlayerInRangeOfPoint(playerid, 3.0, IndustryInfo[5][Posx], IndustryInfo[5][Posy], IndustryInfo[5][Posz]))
	{
		if(Inventory_Count(playerid, "Fabric Cargo") || Inventory_Count(playerid, "Steel Cargo") || Inventory_Count(playerid, "Woods Cargo") || Inventory_Count(playerid, "Foods Cargo")
		|| Inventory_Count(playerid, "Clothes Cargo") || Inventory_Count(playerid, "Appliances Cargo") || Inventory_Count(playerid, "Fish Cargo"))
			return SendErrorMessage(playerid, "You are already carrying your cargo.");

		if(!ServerInfo[0][E_SERVER_CLOTHES])
			return SendErrorMessage(playerid, "This cargo storage is out of stock.");

		Inventory_Add(playerid, "Clothes Cargo", 2912, 1);
		SetPlayerSpecialAction(playerid, SPECIAL_ACTION_CARRY);
		SetPlayerAttachedObject(playerid, ATTACH_CARGO, 2912, 1, -0.019, 0.713999, -0.076, 0, 87.1, -9.4, 1.0000, 1.0000, 1.0000);
		new Cents = floatround(IndustryInfo[5][Price] * 100, floatround_round);

		SetPlayerNeeds(playerid, -0.3, -0.2);

	    GiveMoney(playerid, -Cents);

		ServerData_Minus(INDUSTRY_CLOTHES, 1);

		SendJobsMessage(playerid, "[Trucker] {DEDEDE}You has purchase cargo for $%s.", FormatMoney(Cents));
		SendTipMessage(playerid, "You can place cargo by type /cartrunk and sell into industries or business by type /tpda.");
	}
	if(IsPlayerInRangeOfPoint(playerid, 3.0, IndustryInfo[6][Posx], IndustryInfo[6][Posy], IndustryInfo[6][Posz]))
	{
		if(Inventory_Count(playerid, "Fabric Cargo") || Inventory_Count(playerid, "Steel Cargo") || Inventory_Count(playerid, "Woods Cargo") || Inventory_Count(playerid, "Foods Cargo")
		|| Inventory_Count(playerid, "Clothes Cargo") || Inventory_Count(playerid, "Appliances Cargo") || Inventory_Count(playerid, "Fish Cargo"))
			return SendErrorMessage(playerid, "You are already carrying your cargo.");

		if(!ServerInfo[0][E_SERVER_APPLIANCES])
			return SendErrorMessage(playerid, "This cargo storage is out of stock.");

		Inventory_Add(playerid, "Appliances Cargo", 2912, 1);
		SetPlayerSpecialAction(playerid, SPECIAL_ACTION_CARRY);
		SetPlayerAttachedObject(playerid, ATTACH_CARGO, 2912, 1, -0.019, 0.713999, -0.076, 0, 87.1, -9.4, 1.0000, 1.0000, 1.0000);
		new Cents = floatround(IndustryInfo[6][Price] * 100, floatround_round);

		SetPlayerNeeds(playerid, -0.3, -0.2);

	    GiveMoney(playerid, -Cents);

		ServerData_Minus(INDUSTRY_APPLIANCES, 1);

		SendJobsMessage(playerid, "[Trucker] {DEDEDE}You has purchase cargo for $%s.", FormatMoney(Cents));
		SendTipMessage(playerid, "You can place cargo by type /cartrunk and sell into industries or business by type /tpda.");
	}
	return 1;
}

CMD:cargosell(playerid, params[])
{
	new id;
	if(PlayerInfo[playerid][E_CHARACTER_JOBS] != JOB_TRUCKER)
        return SendErrorMessage(playerid, "You aren't truckers.");

	if(PlayerInfo[playerid][E_CHARACTER_HUNGRY] < 20 || PlayerInfo[playerid][E_CHARACTER_THIRSTY] < 20)
		return SendErrorMessage(playerid, "You're hungry or thirsty right now.");

	// Primary Sell
	if(IsPlayerInRangeOfPoint(playerid, 3.0, IndustryInfo[4][Posx], IndustryInfo[4][Posy], IndustryInfo[4][Posz]))
	{
		if(!Inventory_Count(playerid, "Fish Cargo"))
			return SendErrorMessage(playerid, "You are not carrying your cargo.");

		if(!ServerInfo[0][E_SERVER_FISH] >= 100)
			return SendErrorMessage(playerid, "This cargo storage is full of stock.");

		Inventory_Remove(playerid, "Fish Cargo", 1);
		SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
		RemovePlayerAttachedObject(playerid, ATTACH_CARGO);
		new Cents = floatround(IndustryInfo[3][Price] * 2 * 100, floatround_round);

		SetPlayerNeeds(playerid, -0.3, -0.2);

	    GiveMoney(playerid, Cents);

		ServerData_Plus(INDUSTRY_FISH, 1);
		
		SendJobsMessage(playerid, "[Trucker] {DEDEDE}You has sell cargo for $%s.", FormatMoney(Cents));
	}
	if(IsPlayerInRangeOfPoint(playerid, 3.0, IndustryInfo[5][Posx], IndustryInfo[5][Posy], IndustryInfo[5][Posz]))
	{
		if(!Inventory_Count(playerid, "Fabric Cargo"))
			return SendErrorMessage(playerid, "You are not carrying your cargo.");

		if(!ServerInfo[0][E_SERVER_CLOTHES] >= 100)
			return SendErrorMessage(playerid, "This cargo storage is full of stock.");

		Inventory_Remove(playerid, "Fabric Cargo", 1);
		SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
		RemovePlayerAttachedObject(playerid, ATTACH_CARGO);
		new Cents = floatround(IndustryInfo[0][Price] * 2 * 100, floatround_round);

		SetPlayerNeeds(playerid, -0.3, -0.2);

	    GiveMoney(playerid, Cents);

		ServerData_Plus(INDUSTRY_CLOTHES, 1);
		
		SendJobsMessage(playerid, "[Trucker] {DEDEDE}You has sell cargo for $%s.", FormatMoney(Cents));
	}
	if(IsPlayerInRangeOfPoint(playerid, 3.0, IndustryInfo[6][Posx], IndustryInfo[6][Posy], IndustryInfo[6][Posz]))
	{
		if(Inventory_Count(playerid, "Steel Cargo"))
		{
			if(!ServerInfo[0][E_SERVER_APPLIANCES] >= 100)
				return SendErrorMessage(playerid, "This cargo storage is full of stock.");

			Inventory_Remove(playerid, "Steel Cargo", 1);
			SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
			RemovePlayerAttachedObject(playerid, ATTACH_CARGO);
			new Cents = floatround(IndustryInfo[1][Price] * 2 * 100, floatround_round);

			GiveMoney(playerid, Cents);

			ServerData_Plus(INDUSTRY_APPLIANCES, 1);
			
			SendJobsMessage(playerid, "[Trucker] {DEDEDE}You has sell cargo for $%s.", FormatMoney(Cents));
		}
		else if(Inventory_Count(playerid, "Woods Cargo"))
		{
			if(!ServerInfo[0][E_SERVER_APPLIANCES] >= 100)
				return SendErrorMessage(playerid, "This cargo storage is full of stock.");

			Inventory_Remove(playerid, "Woods Cargo", 1);
			SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
			RemovePlayerAttachedObject(playerid, ATTACH_CARGO);
			new Cents = floatround(IndustryInfo[2][Price] * 2 * 100, floatround_round);

			SetPlayerNeeds(playerid, -0.3, -0.2);

			GiveMoney(playerid, Cents);

			ServerData_Plus(INDUSTRY_APPLIANCES, 1);
			
			SendJobsMessage(playerid, "[Trucker] {DEDEDE}You has sell cargo for $%s.", FormatMoney(Cents));
		}
		else SendErrorMessage(playerid, "You are not carrying your cargo.");
	}

	// Secondary Sell:
	if((id = IsPlayerNearBusiness(playerid)) != 0)
	{
		if(!Inventory_Count(playerid, "Appliances Cargo"))
			return SendErrorMessage(playerid, "You are not carrying your cargo.");

		if(BusinessInfo[id][E_BUSINESS_TYPE] != BUSINESS_TYPE_GENERAL)
			return SendErrorMessage(playerid, "This business aren't requesting business or full of products");

		if(BusinessInfo[id][E_BUSINESS_STOCK] > 100)
			return SendErrorMessage(playerid, "This business aren't requesting business or full of products");

		Inventory_Remove(playerid, "Appliances Cargo", 1);
		SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
		RemovePlayerAttachedObject(playerid, ATTACH_CARGO);
		new Cents = floatround(IndustryInfo[6][Price] * 2 * 100, floatround_round);

		SetPlayerNeeds(playerid, -0.3, -0.2);

	    GiveMoney(playerid, Cents);

		if(BusinessInfo[id][E_BUSINESS_STOCK] > 100)
		{
			BusinessInfo[id][E_BUSINESS_STOCK] = 100;
			BusinessInfo[id][E_BUSINESS_SHIPMENTS] = 0;
		}
		else
		{
			BusinessInfo[id][E_BUSINESS_STOCK]++;
			BusinessInfo[id][E_BUSINESS_CASH] -= 10;
		}
		SendJobsMessage(playerid, "[Trucker] {DEDEDE}You has sell cargo for $%s.", FormatMoney(Cents));
	}
	if((id = IsPlayerNearBusiness(playerid)) != 0)
	{
		if(!Inventory_Count(playerid, "Clothes Cargo"))
			return SendErrorMessage(playerid, "You are not carrying your cargo.");

		if(BusinessInfo[id][E_BUSINESS_TYPE] != BUSINESS_TYPE_CLOTHES)
			return SendErrorMessage(playerid, "This business aren't requesting business or full of products");

		if(BusinessInfo[id][E_BUSINESS_STOCK] > 100 || BusinessInfo[id][E_BUSINESS_CASH] < 10)
			return SendErrorMessage(playerid, "This business aren't requesting business or full of products");

		Inventory_Remove(playerid, "Clothes Cargo", 1);
		SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
		RemovePlayerAttachedObject(playerid, ATTACH_CARGO);
		new Cents = floatround(IndustryInfo[5][Price] *2 * 100, floatround_round);

	    GiveMoney(playerid, Cents);

		if(BusinessInfo[id][E_BUSINESS_STOCK] > 100)
		{
			BusinessInfo[id][E_BUSINESS_STOCK] = 100;
			BusinessInfo[id][E_BUSINESS_SHIPMENTS] = 0;
		}
		else
		{
			BusinessInfo[id][E_BUSINESS_STOCK]++;
			BusinessInfo[id][E_BUSINESS_CASH] -= 10;
		}
		SendJobsMessage(playerid, "[Trucker] {DEDEDE}You has sell cargo for $%s.", FormatMoney(Cents));
	}
	if((id = IsPlayerNearBusiness(playerid)) != 0)
	{
		if(!Inventory_Count(playerid, "Foods Cargo"))
			return SendErrorMessage(playerid, "You are not carrying your cargo.");

		if(BusinessInfo[id][E_BUSINESS_TYPE] != BUSINESS_TYPE_DINNER && BusinessInfo[id][E_BUSINESS_TYPE] != BUSINESS_TYPE_BAR && BusinessInfo[id][E_BUSINESS_TYPE] != BUSINESS_TYPE_CLUB)
			return SendErrorMessage(playerid, "This business aren't requesting business or full of products");

		if(BusinessInfo[id][E_BUSINESS_STOCK] > 100 || BusinessInfo[id][E_BUSINESS_CASH] < 10)
			return SendErrorMessage(playerid, "This business aren't requesting business or full of products");

		Inventory_Remove(playerid, "Foods Cargo", 1);
		SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
		RemovePlayerAttachedObject(playerid, ATTACH_CARGO);
		new Cents = floatround(IndustryInfo[4][Price] * 2 * 100, floatround_round);

		SetPlayerNeeds(playerid, -0.3, -0.2);

	    GiveMoney(playerid, Cents);

		if(BusinessInfo[id][E_BUSINESS_STOCK] > 100)
		{
			BusinessInfo[id][E_BUSINESS_STOCK] = 100;
			BusinessInfo[id][E_BUSINESS_SHIPMENTS] = 0;
		}
		else
		{
			BusinessInfo[id][E_BUSINESS_STOCK]++;
			BusinessInfo[id][E_BUSINESS_CASH] -= 10;
		}
		SendJobsMessage(playerid, "[Trucker] {DEDEDE}You has sell cargo for $%s.", FormatMoney(Cents));
	}
	return 1;
}

CMD:tpda(playerid, params[])
{
    if(PlayerInfo[playerid][E_CHARACTER_JOBS] != JOB_TRUCKER)
        return SendErrorMessage(playerid, "You aren't truckers.");

    Dialog_Show(playerid, Industry, DIALOG_STYLE_LIST, "Truck PDA:", "Show Oceandocks Information\nShow Freight Industry\nShow Cargo Industry\nShow Business Request Shipments", "Select", "Cancel");
    return 1;
}

Dialog:Industry(playerid, response, listitem, inputtext[])
{
	if(response)
	{
		switch(listitem)
		{
			case 0:
			{
				new str[256];
				strcat(str, "Welcome to los santos economy!\n\nThe ship & warehouses is currently restocked product every 30 minute(s).\n\nYou can buy cargo products if stock is still available on the ship or warehouses.");
				ShowPlayerDialog(playerid, DIALOG_DEFAULT, DIALOG_STYLE_MSGBOX, "Information:", str, "Confirm", "");
			}
			case 1:
			{
				if(GetVehicleModel(GetPlayerVehicleID(playerid)) != 515 && GetVehicleModel(GetPlayerVehicleID(playerid)) != 514 && GetVehicleModel(GetPlayerVehicleID(playerid)) != 403)
					return SendErrorMessage(playerid, "You aren't in heavy truck.");

				if(PlayerInfo[playerid][E_CHARACTER_LEVEL] < 5)
					return SendErrorMessage(playerid, "Your level (5) is minimum to access this jobs."); 

				if(PlayerInfo[playerid][E_CHARACTER_HUNGRY] < 20 || PlayerInfo[playerid][E_CHARACTER_THIRSTY] < 20)
					return SendErrorMessage(playerid, "You're hungry or thirsty right now.");

				ShowFreight(playerid);
			}
			case 2:
			{
				ShowIndustry(playerid);
			}
			case 3:
			{
				ShowShipments(playerid);
			}
		}
	}
	return 1;
}

stock AttachVehicleFreight(playerid, vehicleid)
{
	new Float:x, Float:y, Float:z;
	GetPlayerPos(playerid, x, y, z);

	switch(PlayerTruckIndex[playerid])
	{
		case 1: // Fabric
		{
			PlayerTruckAttach[playerid] = CreateVehicle(591, x, y, z, 0.0, 1, -1, -1, 0);
			SetTimerEx("AttachVehicleFreightEx", 1500, false, "ddd", playerid, PlayerTruckAttach[playerid], vehicleid);
			SendJobsMessage(playerid, "[Trucker] {DEDEDE}You has attached trailer into your truck, go to checkpoint to deliver the trailer at %s.", GetZoneName(FreightInfo[0][Endx], FreightInfo[0][Endy], FreightInfo[0][Endz]));
			GPS_SetPlayerRaceCheckPoint(playerid, 1, FreightInfo[0][Endx], FreightInfo[0][Endy], FreightInfo[0][Endz], 0.0, 0.0, 0.0, GPS_TRUCKERSFINISH);
		}
		case 2: // Steel
		{
			PlayerTruckAttach[playerid] = CreateVehicle(450, x, y, z, 0.0, 1, -1, -1, 0);
			SetTimerEx("AttachVehicleFreightEx", 1500, false, "ddd", playerid, PlayerTruckAttach[playerid], vehicleid);
			SendJobsMessage(playerid, "[Trucker] {DEDEDE}You has attached trailer into your truck, go to checkpoint to deliver the trailer at %s.", GetZoneName(FreightInfo[1][Endx], FreightInfo[1][Endy], FreightInfo[1][Endz]));
			GPS_SetPlayerRaceCheckPoint(playerid, 1, FreightInfo[1][Endx], FreightInfo[1][Endy], FreightInfo[1][Endz], 0.0, 0.0, 0.0, GPS_TRUCKERSFINISH);
		}
		case 3: // Wood
		{
			PlayerTruckAttach[playerid] = CreateVehicle(450, x, y, z, 0.0, 1, -1, -1, 0);
			SetTimerEx("AttachVehicleFreightEx", 1500, false, "ddd", playerid, PlayerTruckAttach[playerid], vehicleid);
			SendJobsMessage(playerid, "[Trucker] {DEDEDE}You has attached trailer into your truck, go to checkpoint to deliver the trailer at %s.", GetZoneName(FreightInfo[2][Endx], FreightInfo[2][Endy], FreightInfo[2][Endz]));
			GPS_SetPlayerRaceCheckPoint(playerid, 1, FreightInfo[2][Endx], FreightInfo[2][Endy], FreightInfo[2][Endz], 0.0, 0.0, 0.0, GPS_TRUCKERSFINISH);
		}
		case 4: // Fish
		{
			PlayerTruckAttach[playerid] = CreateVehicle(591, x, y, z, 0.0, 1, -1, -1, 0);
			SetTimerEx("AttachVehicleFreightEx", 1500, false, "ddd", playerid, PlayerTruckAttach[playerid], vehicleid);
			SendJobsMessage(playerid, "[Trucker] {DEDEDE}You has attached trailer into your truck, go to checkpoint to deliver the trailer at %s.", GetZoneName(FreightInfo[3][Endx], FreightInfo[3][Endy], FreightInfo[3][Endz]));
			GPS_SetPlayerRaceCheckPoint(playerid, 1, FreightInfo[3][Endx], FreightInfo[3][Endy], FreightInfo[3][Endz], 0.0, 0.0, 0.0, GPS_TRUCKERSFINISH);
		}
		case 5: // Sprunk
		{
			PlayerTruckAttach[playerid] = CreateVehicle(591, x, y, z, 0.0, 16, -1, -1, 0);

			PlayerTruckObject[playerid] = CreateDynamicObject(19482,0.0,0.0,-1000.0,0.0,0.0,0.0,-1,-1,-1,300.0,300.0);
			SetDynamicObjectMaterial(PlayerTruckObject[playerid], 0, 10101, "2notherbuildsfe", "Bow_Abpave_Gen", 0);
			SetDynamicObjectMaterialText(PlayerTruckObject[playerid], 0, "{ffffff}SPRUNK", 120, "Engravers MT", 100, 1, 0, 0, 1);
			AttachDynamicObjectToVehicle(PlayerTruckObject[playerid], PlayerTruckAttach[playerid], -1.390, 0.933, 1.048, 2.600, 0.000, 180.000);
			PlayerTruckObject[playerid] = CreateDynamicObject(19482,0.0,0.0,-1000.0,0.0,0.0,0.0,-1,-1,-1,300.0,300.0);
			SetDynamicObjectMaterial(PlayerTruckObject[playerid], 0, 10101, "2notherbuildsfe", "Bow_Abpave_Gen", 0);
			SetDynamicObjectMaterialText(PlayerTruckObject[playerid], 0, "{ffffff}SPRUNK", 120, "Engravers MT", 100, 1, 0, 0, 1);
			AttachDynamicObjectToVehicle(PlayerTruckObject[playerid], PlayerTruckAttach[playerid], 1.340, 0.933, 1.048, 2.500, 0.000, 0.000);

			SetTimerEx("AttachVehicleFreightEx", 1500, false, "ddd", playerid, PlayerTruckAttach[playerid], vehicleid);
			SendJobsMessage(playerid, "[Trucker] {DEDEDE}You has attached trailer into your truck, go to checkpoint to deliver the trailer at %s.", GetZoneName(FreightInfo[4][Endx], FreightInfo[4][Endy], FreightInfo[4][Endz]));
			GPS_SetPlayerRaceCheckPoint(playerid, 1, FreightInfo[4][Endx], FreightInfo[4][Endy], FreightInfo[4][Endz], 0.0, 0.0, 0.0, GPS_TRUCKERSFINISH);
		}
		case 6: // Cocacola
		{
			PlayerTruckAttach[playerid] = CreateVehicle(591, x, y, z, 0.0, 3, -1, -1, 0);

			PlayerTruckObject[playerid] = CreateDynamicObject(19482,0.0,0.0,-1000.0,0.0,0.0,0.0,-1,-1,-1,300.0,300.0);
			SetDynamicObjectMaterial(PlayerTruckObject[playerid], 0, 10101, "2notherbuildsfe", "Bow_Abpave_Gen", 0);
			SetDynamicObjectMaterialText(PlayerTruckObject[playerid], 0, "{ffffff}CocaCola", 120, "Engravers MT", 100, 1, 0, 0, 1);
			AttachDynamicObjectToVehicle(PlayerTruckObject[playerid], PlayerTruckAttach[playerid], -1.355, 0.801, 1.040, 0.000, 0.000, -179.900);
			PlayerTruckObject[playerid] = CreateDynamicObject(19482,0.0,0.0,-1000.0,0.0,0.0,0.0,-1,-1,-1,300.0,300.0);
			SetDynamicObjectMaterial(PlayerTruckObject[playerid], 0, 10101, "2notherbuildsfe", "Bow_Abpave_Gen", 0);
			SetDynamicObjectMaterialText(PlayerTruckObject[playerid], 0, "{ffffff}CocaCola", 120, "Engravers MT", 100, 1, 0, 0, 1);
			AttachDynamicObjectToVehicle(PlayerTruckObject[playerid], PlayerTruckAttach[playerid], 1.339, 0.889, 1.160, 0.000, 0.000, 0.000);

			SetTimerEx("AttachVehicleFreightEx", 1500, false, "ddd", playerid, PlayerTruckAttach[playerid], vehicleid);
			SendJobsMessage(playerid, "[Trucker] {DEDEDE}You has attached trailer into your truck, go to checkpoint to deliver the trailer at %s.", GetZoneName(FreightInfo[5][Endx], FreightInfo[5][Endy], FreightInfo[5][Endz]));
			GPS_SetPlayerRaceCheckPoint(playerid, 1, FreightInfo[5][Endx], FreightInfo[5][Endy], FreightInfo[5][Endz], 0.0, 0.0, 0.0, GPS_TRUCKERSFINISH);
		}
		case 7: // Big Goods
		{
			PlayerTruckAttach[playerid] = CreateVehicle(591, x, y, z, 0.0, 1, -1, -1, 0);

			PlayerTruckObject[playerid] = CreateDynamicObject(19482,0.0,0.0,-1000.0,0.0,0.0,0.0,-1,-1,-1,300.0,300.0);
			SetDynamicObjectMaterial(PlayerTruckObject[playerid], 0, 10101, "2notherbuildsfe", "Bow_Abpave_Gen", 0);
			SetDynamicObjectMaterialText(PlayerTruckObject[playerid], 0, "{ff0000}G", 120, "Engravers MT", 100, 1, 0, 0, 1);
			AttachDynamicObjectToVehicle(PlayerTruckObject[playerid], PlayerTruckAttach[playerid], 1.340, 1.220, 1.030, 0.000, 0.000, 0.000);
			PlayerTruckObject[playerid] = CreateDynamicObject(19482,0.0,0.0,-1000.0,0.0,0.0,0.0,-1,-1,-1,300.0,300.0);
			SetDynamicObjectMaterial(PlayerTruckObject[playerid], 0, 10101, "2notherbuildsfe", "Bow_Abpave_Gen", 0);
			SetDynamicObjectMaterialText(PlayerTruckObject[playerid], 0, "{ff0000}--------", 120, "Engravers MT", 100, 1, 0, 0, 1);
			AttachDynamicObjectToVehicle(PlayerTruckObject[playerid], PlayerTruckAttach[playerid], 1.330, 2.850, 1.150, 0.000, 0.000, 720.000);
			PlayerTruckObject[playerid] = CreateDynamicObject(19482,0.0,0.0,-1000.0,0.0,0.0,0.0,-1,-1,-1,300.0,300.0);
			SetDynamicObjectMaterial(PlayerTruckObject[playerid], 0, 10101, "2notherbuildsfe", "Bow_Abpave_Gen", 0);
			SetDynamicObjectMaterialText(PlayerTruckObject[playerid], 0, "{ff0000}------", 120, "Engravers MT", 100, 1, 0, 0, 1);
			AttachDynamicObjectToVehicle(PlayerTruckObject[playerid], PlayerTruckAttach[playerid], 1.340, -0.129, 1.150, 0.000, 0.000, 0.000);
			PlayerTruckObject[playerid] = CreateDynamicObject(19482,0.0,0.0,-1000.0,0.0,0.0,0.0,-1,-1,-1,300.0,300.0);
			SetDynamicObjectMaterial(PlayerTruckObject[playerid], 0, 10101, "2notherbuildsfe", "Bow_Abpave_Gen", 0);
			SetDynamicObjectMaterialText(PlayerTruckObject[playerid], 0, "{000000}BIG", 120, "Engravers MT", 60, 1, 0, 0, 1);
			AttachDynamicObjectToVehicle(PlayerTruckObject[playerid], PlayerTruckAttach[playerid], 1.340, -0.129, 1.560, 0.000, 0.000, 0.000);
			PlayerTruckObject[playerid] = CreateDynamicObject(19482,0.0,0.0,-1000.0,0.0,0.0,0.0,-1,-1,-1,300.0,300.0);
			SetDynamicObjectMaterial(PlayerTruckObject[playerid], 0, 10101, "2notherbuildsfe", "Bow_Abpave_Gen", 0);
			SetDynamicObjectMaterialText(PlayerTruckObject[playerid], 0, "{000000}GOODS", 120, "Engravers MT", 60, 1, 0, 0, 1);
			AttachDynamicObjectToVehicle(PlayerTruckObject[playerid], PlayerTruckAttach[playerid], 1.340, 3.000, 1.560, 0.000, 0.000, 0.000);
			PlayerTruckObject[playerid] = CreateDynamicObject(19482,0.0,0.0,-1000.0,0.0,0.0,0.0,-1,-1,-1,300.0,300.0);
			SetDynamicObjectMaterial(PlayerTruckObject[playerid], 0, 10101, "2notherbuildsfe", "Bow_Abpave_Gen", 0);
			SetDynamicObjectMaterialText(PlayerTruckObject[playerid], 0, "{ff0000}G", 120, "Engravers MT", 100, 1, 0, 0, 1);
			AttachDynamicObjectToVehicle(PlayerTruckObject[playerid], PlayerTruckAttach[playerid], -1.300, 1.220, 1.030, 0.000, 0.000, 180.000);
			PlayerTruckObject[playerid] = CreateDynamicObject(19482,0.0,0.0,-1000.0,0.0,0.0,0.0,-1,-1,-1,300.0,300.0);
			SetDynamicObjectMaterial(PlayerTruckObject[playerid], 0, 10101, "2notherbuildsfe", "Bow_Abpave_Gen", 0);
			SetDynamicObjectMaterialText(PlayerTruckObject[playerid], 0, "{ff0000}--------", 120, "Engravers MT", 100, 1, 0, 0, 1);
			AttachDynamicObjectToVehicle(PlayerTruckObject[playerid], PlayerTruckAttach[playerid], -1.330, -0.409, 1.150, 0.000, 0.000, 0.000);
			PlayerTruckObject[playerid] = CreateDynamicObject(19482,0.0,0.0,-1000.0,0.0,0.0,0.0,-1,-1,-1,300.0,300.0);
			SetDynamicObjectMaterial(PlayerTruckObject[playerid], 0, 10101, "2notherbuildsfe", "Bow_Abpave_Gen", 0);
			SetDynamicObjectMaterialText(PlayerTruckObject[playerid], 0, "{ff0000}------", 120, "Engravers MT", 100, 1, 0, 0, 1);
			AttachDynamicObjectToVehicle(PlayerTruckObject[playerid], PlayerTruckAttach[playerid], -1.360, 2.540, 1.150, 0.000, 0.000, 0.000);
			PlayerTruckObject[playerid] = CreateDynamicObject(19482,0.0,0.0,-1000.0,0.0,0.0,0.0,-1,-1,-1,300.0,300.0);
			SetDynamicObjectMaterial(PlayerTruckObject[playerid], 0, 10101, "2notherbuildsfe", "Bow_Abpave_Gen", 0);
			SetDynamicObjectMaterialText(PlayerTruckObject[playerid], 0, "{000000}GOODS", 120, "Engravers MT", 60, 1, 0, 0, 1);
			AttachDynamicObjectToVehicle(PlayerTruckObject[playerid], PlayerTruckAttach[playerid], -1.349, -0.269, 1.560, 0.000, 0.000, 180.000);
			PlayerTruckObject[playerid] = CreateDynamicObject(19482,0.0,0.0,-1000.0,0.0,0.0,0.0,-1,-1,-1,300.0,300.0);
			SetDynamicObjectMaterial(PlayerTruckObject[playerid], 0, 10101, "2notherbuildsfe", "Bow_Abpave_Gen", 0);
			SetDynamicObjectMaterialText(PlayerTruckObject[playerid], 0, "{000000}BIG", 120, "Engravers MT", 60, 1, 0, 0, 1);
			AttachDynamicObjectToVehicle(PlayerTruckObject[playerid], PlayerTruckAttach[playerid], -1.330, 2.690, 1.560, 0.000, 0.000, 180.000);

			SetTimerEx("AttachVehicleFreightEx", 1500, false, "ddd", playerid, PlayerTruckAttach[playerid], vehicleid);
			SendJobsMessage(playerid, "[Trucker] {DEDEDE}You has attached trailer into your truck, go to checkpoint to deliver the trailer at %s.", GetZoneName(FreightInfo[6][Endx], FreightInfo[6][Endy], FreightInfo[6][Endz]));
			GPS_SetPlayerRaceCheckPoint(playerid, 1, FreightInfo[6][Endx], FreightInfo[6][Endy], FreightInfo[6][Endz], 0.0, 0.0, 0.0, GPS_TRUCKERSFINISH);
		}
	}
	return 1;
}

DettachVehicleFreight(playerid, vehicleid)
{
	new rand = randomEx(100, 200);
	new total = rand + 50;
	new Cents = floatround(total * 100, floatround_round);

	if(IsValidDynamicObject(PlayerTruckObject[playerid]))
		DestroyDynamicObject(PlayerTruckObject[playerid]);

	DestroyVehicle(PlayerTruckAttach[playerid]);
	DetachTrailerFromVehicle(vehicleid);

	SetPlayerNeeds(playerid, -5.0, -10.0);

	GivePaycheck(playerid, Cents);
	SendJobsMessage(playerid, "[Trucker] {DEDEDE}You has deliver trailer into destination and earn into your paycheck $%s.", FormatMoney(Cents));
	GPS_DisablePlayerRaceCheckPoint(playerid);
	return 1;
}

function:AttachVehicleFreightEx(playerid, trailerid, vehicleid)
{
	if(IsVehicleStreamedIn(trailerid, playerid))
	{
		AttachTrailerToVehicle(trailerid, vehicleid);
	}
	return 1;
}