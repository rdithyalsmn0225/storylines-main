CountVehicleSlot(vehicleid)
{
	return VS_Count(vehicleid, "Products Cargo") || VS_Count(vehicleid, "Foods Cargo") || VS_Count(vehicleid, "Tools Cargo") || VS_Count(vehicleid, "Clothes Cargo");
}

stock UpdateVehicleObject(vehicleid)
{
	new model = GetVehicleModel(vehicleid), count;

	switch(model)
	{
	    case 422:
		{
	        count = CountVehicleSlot(vehicleid);

			for(new i = 0; i != 3; ++i)
			{
			    if(IsValidDynamicObject(VehicleInfo[vehicleid][E_VEHICLE_OBJECTS][i]))
				{
			    	DestroyDynamicObject(VehicleInfo[vehicleid][E_VEHICLE_OBJECTS][i]);
				}

				if(i < count)
				{
					VehicleInfo[vehicleid][E_VEHICLE_OBJECTS][i] = CreateDynamicObject(2912, 0.0, 0.0, -20.0, 0.0, 0.0, 0.0);

					switch(i)
					{
						case 0: AttachDynamicObjectToVehicle(VehicleInfo[vehicleid][E_VEHICLE_OBJECTS][i], vehicleid, -0.344999, -0.769999, -0.294999, 0.000000, 0.000000, 0.000000); //Object Model: 2912 | CRATE
						case 1: AttachDynamicObjectToVehicle(VehicleInfo[vehicleid][E_VEHICLE_OBJECTS][i], vehicleid, 0.364999, -0.769999, -0.299999, 0.000000, 0.000000, 0.000000); //Object Model: 2912 | CRATE
						case 2: AttachDynamicObjectToVehicle(VehicleInfo[vehicleid][E_VEHICLE_OBJECTS][i], vehicleid, 0.159999, -1.839998, -0.299999, 0.000000, 0.000000, 0.000000); //Object Model: 2912 | CRATE
					}
				}

			}
	    }
	    case 543, 605:
		{
	        count =CountVehicleSlot(vehicleid);

			for(new i = 0; i != 2; ++i)
			{
			    if(IsValidDynamicObject(VehicleInfo[vehicleid][E_VEHICLE_OBJECTS][i]))
				{
			    	DestroyDynamicObject(VehicleInfo[vehicleid][E_VEHICLE_OBJECTS][i]);
				}

				if(i < count)
				{
					VehicleInfo[vehicleid][E_VEHICLE_OBJECTS][i] = CreateDynamicObject(2912, 0.0, 0.0, -20.0, 0.0, 0.0, 0.0);

					switch(i)
					{
						case 0: AttachDynamicObjectToVehicle(VehicleInfo[vehicleid][E_VEHICLE_OBJECTS][i], vehicleid, -0.344999, -0.769999, -0.294999, 0.000000, 0.000000, 0.000000); //Object Model: 2912 | CRATE
						case 1: AttachDynamicObjectToVehicle(VehicleInfo[vehicleid][E_VEHICLE_OBJECTS][i], vehicleid, -0.344999, -0.769999, -0.294999, 0.000000, 0.000000, 0.000000); //Object Model: 2912 | CRATE
					}

				}
			}
	    }
        case 554:
		{
	      	count =CountVehicleSlot(vehicleid);

			for(new i = 0; i != 4; ++i)
			{
			    if(IsValidDynamicObject(VehicleInfo[vehicleid][E_VEHICLE_OBJECTS][i]))
				{
			    	DestroyDynamicObject(VehicleInfo[vehicleid][E_VEHICLE_OBJECTS][i]);
				}

				if(i < count)
				{
					VehicleInfo[vehicleid][E_VEHICLE_OBJECTS][i] = CreateDynamicObject(2912, 0.0, 0.0, -20.0, 0.0, 0.0, 0.0);

					switch(i)
					{
						case 0: AttachDynamicObjectToVehicle(VehicleInfo[vehicleid][E_VEHICLE_OBJECTS][i], vehicleid, 0.294999, -0.989999, -0.239999, 0.000000, 0.000000, 0.000000); //Object Model: 2912 |
						case 1: AttachDynamicObjectToVehicle(VehicleInfo[vehicleid][E_VEHICLE_OBJECTS][i], vehicleid, -0.409999, -1.694998, -0.239999, 0.000000, 0.000000, 0.000000); //Object Model: 2912 |
						case 2: AttachDynamicObjectToVehicle(VehicleInfo[vehicleid][E_VEHICLE_OBJECTS][i], vehicleid, 0.295000, -1.694998, -0.239999, 0.000000, 0.000000, 0.000000); //Object Model: 2912 |
						case 3: AttachDynamicObjectToVehicle(VehicleInfo[vehicleid][E_VEHICLE_OBJECTS][i], vehicleid, -0.414999, -2.405007, -0.239999, 0.000000, 0.000000, 0.000000); //Object Model: 2912 |
						case 4: AttachDynamicObjectToVehicle(VehicleInfo[vehicleid][E_VEHICLE_OBJECTS][i], vehicleid, 0.295000, -2.410007, -0.239999, 0.000000, 0.000000, 0.000000); //Object Model: 2912 |
					}

				}
			}
		}
		case 600:
		{
		    count =CountVehicleSlot(vehicleid);

			for(new i = 0; i != 2; ++i)
			{
			    if(IsValidDynamicObject(VehicleInfo[vehicleid][E_VEHICLE_OBJECTS][i]))
				{
			    	DestroyDynamicObject(VehicleInfo[vehicleid][E_VEHICLE_OBJECTS][i]);
				}

				if(i < count)
				{
					VehicleInfo[vehicleid][E_VEHICLE_OBJECTS][i] = CreateDynamicObject(2912, 0.0, 0.0, -20.0, 0.0, 0.0, 0.0);

					switch(i)
					{
						case 0: AttachDynamicObjectToVehicle(VehicleInfo[vehicleid][E_VEHICLE_OBJECTS][i], vehicleid, -0.344999, -0.92, -0.294999, 0.000000, 0.000000, 0.000000); //Object Model: 2912 | CRATE
						case 1: AttachDynamicObjectToVehicle(VehicleInfo[vehicleid][E_VEHICLE_OBJECTS][i], vehicleid, 0.364999, -0.92, -0.299999, 0.000000, 0.000000, 0.000000); //Object Model: 2912 | CRATE
					}
				}

			}
		}
		case 478:
		{
			count =CountVehicleSlot(vehicleid);

			for(new i = 0; i != 4; ++i)
			{
			    if(IsValidDynamicObject(VehicleInfo[vehicleid][E_VEHICLE_OBJECTS][i]))
				{
			    	DestroyDynamicObject(VehicleInfo[vehicleid][E_VEHICLE_OBJECTS][i]);
				}

				if(i < count)
				{
					VehicleInfo[vehicleid][E_VEHICLE_OBJECTS][i] = CreateDynamicObject(2912, 0.0, 0.0, -20.0, 0.0, 0.0, 0.0);

					switch(i)
					{
						case 0: AttachDynamicObjectToVehicle(VehicleInfo[vehicleid][E_VEHICLE_OBJECTS][i], vehicleid, -0.354999, -0.949999, 0.000000, 0.000000, 0.000000, 0.000000); //Object Model: 2912 |
						case 1: AttachDynamicObjectToVehicle(VehicleInfo[vehicleid][E_VEHICLE_OBJECTS][i], vehicleid, 0.354999, -0.949999, 0.000000, 0.000000, 0.000000, 0.000000); //Object Model: 2912 |
						case 2: AttachDynamicObjectToVehicle(VehicleInfo[vehicleid][E_VEHICLE_OBJECTS][i], vehicleid, -0.354999, -1.664998, 0.000000, 0.000000, 0.000000, 0.000000); //Object Model: 2912 |
						case 3: AttachDynamicObjectToVehicle(VehicleInfo[vehicleid][E_VEHICLE_OBJECTS][i], vehicleid, 0.354999, -1.664998, 0.000000, 0.000000, 0.000000, 0.000000); //Object Model: 2912 |
					}
				}
			}
		}
	}
    return 1;
}

CMD:cargo(playerid, params[])
{
    new oneString[30], id;
	
	if(sscanf(params, "s[30]", oneString))
	{
		SendUsageMessage(playerid, "/cargo [action]"); 
		SendClientMessage(playerid, COLOR_RED, "[Type]:{d7d7d7} buy, sell"); 
		return 1;
	}

	if(PlayerInfo[playerid][E_CHARACTER_JOBS] != JOB_TRUCKER)
        return SendErrorMessage(playerid, "You aren't truckers.");

    if(!strcmp(oneString, "buy"))
	{
        if(IsPlayerInRangeOfPoint(playerid, 3.0, IndustryInfo[0][Posx], IndustryInfo[0][Posy], IndustryInfo[0][Posz]) || IsPlayerInRangeOfPoint(playerid, 3.0, IndustryInfo[1][Posx], IndustryInfo[1][Posy], IndustryInfo[1][Posz])) //products
        {
            if(Inventory_Count(playerid, "Foods Cargo") || Inventory_Count(playerid, "Tools Cargo") || Inventory_Count(playerid, "Clothes Cargo") || Inventory_Count(playerid, "Products Cargo"))
                return SendErrorMessage(playerid, "You are already carrying your cargo.");

			for(new i = 0; i < MAX_SERVERDATA; i++)
			{
				if(ServerInfo[i][E_SERVER_PRODUCTS] < 1)
					return SendErrorMessage(playerid, "This warehouse is out of stock.");
			}

            Inventory_Add(playerid, "Products Cargo", 2912, 1);
            SetPlayerSpecialAction(playerid, SPECIAL_ACTION_CARRY);
		    SetPlayerAttachedObject(playerid, ATTACH_CARGO, 2912, 1, -0.019, 0.713999, -0.076, 0, 87.1, -9.4, 1.0000, 1.0000, 1.0000);
            GiveMoney(playerid, -PRICE_PRODUCTS);

            ServerData_Minus(INDUSTRY_PRODUCTS, 1);

            SendClientMessageEx(playerid, COLOR_JOBS, "[Jobs]:{d7d7d7} You has purchase products cargo for %s.", FormatMoney(PRICE_PRODUCTS));
        }
    }

    else if(!strcmp(oneString, "sell"))
	{
        if((id = IsPlayerInBusiness(playerid)) != 0) //Products
        {
            if(!Inventory_Count(playerid, "Products Cargo"))
                return SendErrorMessage(playerid, "You are not carrying your cargo.");

            if(BusinessInfo[id][E_BUSINESS_STOCK] > 100)
                return SendErrorMessage(playerid, "This business aren't requesting business or full of products");

            Inventory_Remove(playerid, "Products Cargo", 1);
            SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
		    RemovePlayerAttachedObject(playerid, 7);
            GiveMoney(playerid, PRICE_PRODUCTS*5);

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
            SendClientMessageEx(playerid, COLOR_JOBS, "[Jobs]:{d7d7d7} You has sell products cargo for %s into business.", FormatMoney(PRICE_PRODUCTS*5));
        }
    }

    return 1;
}

CMD:tpda(playerid, params[])
{
    if(PlayerInfo[playerid][E_CHARACTER_JOBS] != JOB_TRUCKER)
        return SendErrorMessage(playerid, "You aren't truckers.");

    ShowPlayerDialog(playerid, DIALOG_INDUSTRY, DIALOG_STYLE_LIST, "Truck PDA:", "Show Oceandocks Information\nShow All Industry\nShow Business Request Shipments", "Select", "Cancel");
    return 1;
}