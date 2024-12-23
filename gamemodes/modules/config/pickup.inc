public OnPlayerPickUpDynamicPickup(playerid, pickupid)
{
    new str[256];
    for(new i = 1; i < MAX_BUSINESS; i++)
	{
        if(pickupid == BusinessInfo[i][E_BUSINESS_PICKUP])
        {
            if(!BusinessInfo[i][E_BUSINESS_DBID])
				continue;

			if(!BusinessInfo[i][E_BUSINESS_OWNERDBID])
			{
				if(BusinessInfo[i][E_BUSINESS_TYPE] == BUSINESS_TYPE_DMV)
					format(str, sizeof(str), "enter the vehicle to start drivetest~n~~w~%s.", BusinessInfo[i][E_BUSINESS_NAME], BusinessInfo[i][E_BUSINESS_FEE]); 
				else if(BusinessInfo[i][E_BUSINESS_TYPE] == BUSINESS_TYPE_HAIRCUT || BusinessInfo[i][E_BUSINESS_TYPE] == BUSINESS_TYPE_GUNSTORE || BusinessInfo[i][E_BUSINESS_TYPE] == BUSINESS_TYPE_ACID)
					format(str, sizeof(str), "Press 'RETURN' to enter~n~~w~%s~n~~w~Owned By: NPC~n~~w~Entrance Fee: $%s.", BusinessInfo[i][E_BUSINESS_NAME], BusinessInfo[i][E_BUSINESS_FEE]); 
				else if(BusinessInfo[i][E_BUSINESS_TYPE] == BUSINESS_TYPE_BANK)
					format(str, sizeof(str), "Press 'RETURN' to enter~n~~w~%s~n~~w~Owned By: Goverments~n~~w~Entrance Fee: $%s.", BusinessInfo[i][E_BUSINESS_NAME], BusinessInfo[i][E_BUSINESS_FEE]); 
				else if(BusinessInfo[i][E_BUSINESS_TYPE] == BUSINESS_TYPE_RENT)
					format(str, sizeof(str), "Press 'RETURN' to enter~n~~w~%s~n~~w~Owned By: Goverments~n~~w~Type '/rentcars' to rent vehicle.", BusinessInfo[i][E_BUSINESS_NAME]); 
						
				else format(str, sizeof(str), "Press 'RETURN' to enter~n~~w~%s~n~~w~This business is for sale price: $%s.", BusinessInfo[i][E_BUSINESS_NAME], FormatMoney(BusinessInfo[i][E_BUSINESS_PRICE]), BusinessInfo[i][E_BUSINESS_LEVEL]); 
			}
			else format(str, sizeof(str), "Press 'RETURN' to enter~n~~w~%s~n~~w~Owned By: %s~n~~w~Entrance Fee: $%s.", BusinessInfo[i][E_BUSINESS_NAME], ReturnDBIDName(BusinessInfo[i][E_BUSINESS_OWNERDBID]), FormatMoney(BusinessInfo[i][E_BUSINESS_FEE])); 
			
			ShowBoxMessage(playerid, str, 5);
            return 1;	 	
        }
    }
    for(new i = 1; i < MAX_PROPERTY; i++)
	{
        if(pickupid == PropertyInfo[i][E_PROPERTY_PICKUP])
        {
            if(!PropertyInfo[i][E_PROPERTY_DBID])
                continue;
                
            if(GetPlayerInterior(playerid) != PropertyInfo[i][E_PROPERTY_ENTRANCEINTERIOR])
                continue;
                
            if(GetPlayerVirtualWorld(playerid) != PropertyInfo[i][E_PROPERTY_ENTRANCEWORLD])
                continue; 
    
            if(!PropertyInfo[i][E_PROPERTY_OWNERDBID])
            {
                format(str, sizeof(str), "Press 'RETURN' to enter~n~~w~%s, %s~n~This property is for sale price: $%s.", PropertyInfo[i][E_PROPERTY_ADDRESS], ReturnLocation(playerid), FormatMoney(PropertyInfo[i][E_PROPERTY_PRICE]));
                ShowBoxMessage(playerid, str, 5);
            }
            else
            {
                format(str, sizeof(str), "Press 'RETURN' to enter~n~~w~%s, %s~n~You're standing on %s's porch.", PropertyInfo[i][E_PROPERTY_ADDRESS], ReturnLocation(playerid),  ReturnDBIDName(PropertyInfo[i][E_PROPERTY_OWNERDBID]));
                ShowBoxMessage(playerid, str, 5);
            }	
            return 1;	
        }
    }
    for(new i = 1; i < MAX_ENTRANCE; i++)
	{
        if(pickupid == EntranceInfo[i][E_ENTRANCE_PICKUP])
        {
            if(!EntranceInfo[i][E_ENTRANCE_DBID])
				continue;

			format(str, sizeof(str), "Press 'RETURN' to enter~n~~w~Entrance Point."); 
			ShowBoxMessage(playerid, str, 5); 	
            return 1;	
        }
    }

    for(new i = 0; i < sizeof(BusinessPoint); i++)
    {
        if(pickupid == GeneralStorePickup[i])
        {
            format(str, sizeof(str), "General Store~n~~w~Press 'N' to grab an items."); 
			ShowBoxMessage(playerid, str, 5); 	
            return 1;	
        }
    }

    for(new i = 0; i < 3; i++)
    {
        if(pickupid == FactionLockerPickup[i])
        {
            format(str, sizeof(str), "Faction Locker~n~~w~Type '/flocker' to open locker menu."); 
			ShowBoxMessage(playerid, str, 5); 	
            return 1;	
        }
    }
    
    if(pickupid == SideJobsPickup[0])
    {
        format(str, sizeof(str), "Garbageman~n~~w~Type '/jobduty' start garbageman~n~~w~Type '/collectgarbage' collect trash~n~~w~Type '/dumpgarbage' unload trash into HQ."); 
        ShowBoxMessage(playerid, str, 5); 	
        return 1;	
    }

    if(pickupid == SideJobsPickup[1])
    {
        format(str, sizeof(str), "Docksworker~n~~w~Type '/jobduty' start dockworkers~n~~w~Type '/takecargo' load cargo~n~~w~Type '/storecargo' unload cargo into warehouse."); 
        ShowBoxMessage(playerid, str, 5); 	
        return 1;	
    }

    if(pickupid == SideJobsPickup[2])
    {
        format(str, sizeof(str), "Street Cleaner~n~~w~Type '/jobduty' start sweepers~n~~w~Clean trash around the street."); 
        ShowBoxMessage(playerid, str, 5); 	
        return 1;	
    }

    if(pickupid == SideJobsPickup[3])
    {
        format(str, sizeof(str), "Bus Driver~n~~w~Type '/jobduty' start bus driver~n~~w~drive around the road and get passengers at bus stops."); 
        ShowBoxMessage(playerid, str, 5); 	
        return 1;	
    }

    for(new i = 0; i < sizeof(JobsInfo); i++)
    {
        if(pickupid == JobsPickup[i])
        {
            format(str, sizeof(str), "Jobs Point~n~~w~Type '/joinjob' to join jobs~n~~w~Type '/quitjob' to quit jobs."); 
            ShowBoxMessage(playerid, str, 5); 
            return 1;	
        }
    }

    if(pickupid == ChainsawPickup)
    {
        format(str, sizeof(str), "Leafy Hollow Barn~n~~w~Type '/buysaw' to buy chainsaw."); 
        ShowBoxMessage(playerid, str, 5); 
        return 1;	
    }

    if(pickupid == DropInjuredPickup)
    {
        format(str, sizeof(str), "Hospital~n~~w~Type '/dropinjured' to drop player injured."); 
        ShowBoxMessage(playerid, str, 5); 
        return 1;	
    }

    if(pickupid == VehicleScrapPickup)
    {
        format(str, sizeof(str), "Vehicle Scrapyard~n~~w~Type '/carscrap' to scrap vehicles."); 
        ShowBoxMessage(playerid, str, 5); 
        return 1;	
    }

    if(pickupid == HairCutPickup)
    {
        format(str, sizeof(str), "Haircuts~n~~w~Type '/haircut' to cut hairs."); 
        ShowBoxMessage(playerid, str, 5); 
        return 1;	
    }

    if(pickupid == TicketPickup)
    {
        format(str, sizeof(str), "Tikcets~n~~w~Type '/tickets' to pay your ticket."); 
        ShowBoxMessage(playerid, str, 5); 
        return 1;	
    }

    if(pickupid == FishFactoryPickup)
    {
        format(str, sizeof(str), "Fish Factory~n~~w~Type '/buybait' to buy fish bait~n~Type '/buyrod' to buy fishing rod~n~~w~Type '/sellfish' to sell fish."); 
        ShowBoxMessage(playerid, str, 5); 
        return 1;	
    }

    if(pickupid == SAPDPickup)
    {
        format(str, sizeof(str), "Faction Vehicles~n~~w~Type '/spawn' to spawn faction vehicles~n~~w~Type '/despawn' to despawn faction vehicles."); 
        ShowBoxMessage(playerid, str, 5); 
        return 1;	
    }

    if(pickupid == SAMDPickup)
    {
        format(str, sizeof(str), "Faction Vehicles~n~~w~Type '/spawn' to spawn faction vehicles~n~~w~Type '/despawn' to despawn faction vehicles."); 
        ShowBoxMessage(playerid, str, 5); 
        return 1;	
    }

    for(new i; i < sizeof(BusStop_Index); i++)
	{
        if(pickupid == BusStopPickup[i])
        {
            format(str, sizeof(str), "Bus Station (Start of Service) Bus Stop~n~~w~Type '/viewroute' to show bus route stop."); 
            ShowBoxMessage(playerid, str, 5); 
            return 1;	
        }
    }

    if(pickupid == DealershipPickup[0])
    {
        format(str, sizeof(str), "Bikes Dealership~n~~w~Type '/dealership' to see dealership menu."); 
        ShowBoxMessage(playerid, str, 5); 
        return 1;	
    }

    if(pickupid == DealershipPickup[1])
    {
        format(str, sizeof(str), "Two Door Dealership~n~~w~Type '/dealership' to see dealership menu."); 
        ShowBoxMessage(playerid, str, 5); 
        return 1;	
    }

    if(pickupid == DealershipPickup[2])
    {
        format(str, sizeof(str), "Four Door Dealership~n~~w~Type '/dealership' to see dealership menu."); 
        ShowBoxMessage(playerid, str, 5); 
        return 1;	
    }

    if(pickupid == DealershipPickup[3])
    {
        format(str, sizeof(str), "Industry Dealership~n~~w~Type '/dealership' to see dealership menu."); 
        ShowBoxMessage(playerid, str, 5); 
        return 1;	
    }

    if(pickupid == DealershipPickup[4])
    {
        format(str, sizeof(str), "Taxi Dealership~n~~w~Type '/dealership' to see dealership menu."); 
        ShowBoxMessage(playerid, str, 5); 
        return 1;	
    }

    if(pickupid == DealershipPickup[5])
    {
        format(str, sizeof(str), "Boat Dealership~n~~w~Type '/dealership' to see dealership menu."); 
        ShowBoxMessage(playerid, str, 5); 
        return 1;	
    }

    if(pickupid == PrisonPickup)
    {
        format(str, sizeof(str), "Los Santos Police Departement~n~~w~Type '/charge' to put player into prison~n~~w~Type '/opencell or /closecell' to open/close cell."); 
        ShowBoxMessage(playerid, str, 5); 
        return 1;	
    }

    if(pickupid == LotteryPickup)
    {
        format(str, sizeof(str), "Lottery Agent~n~~w~Type '/buylottery' to buy lottery."); 
        ShowBoxMessage(playerid, str, 5); 
        return 1;	
    }
    
    return 1;
}