public OnPlayerPickUpDynamicPickup(playerid, pickupid)
{
    new str[1024];
    for(new i = 1; i < MAX_BUSINESS; i++)
	{
        if(pickupid == BusinessInfo[i][E_BUSINESS_PICKUP])
        {
            if(!BusinessInfo[i][E_BUSINESS_DBID])
				continue;

			if(!BusinessInfo[i][E_BUSINESS_OWNERDBID])
			{
				if(BusinessInfo[i][E_BUSINESS_TYPE] == BUSINESS_TYPE_DMV)
					format(str, sizeof(str), "~b~%s~n~~w~enter the vehicle to start drivetest.", BusinessInfo[i][E_BUSINESS_NAME], BusinessInfo[i][E_BUSINESS_ENTRANCEFEE]); 
				else if(BusinessInfo[i][E_BUSINESS_TYPE] == BUSINESS_TYPE_HAIRCUT || BusinessInfo[i][E_BUSINESS_TYPE] == BUSINESS_TYPE_GUNSTORE || BusinessInfo[i][E_BUSINESS_TYPE] == BUSINESS_TYPE_ACID)
					format(str, sizeof(str), "~b~%s~n~~w~Owned By: NPC~n~~y~Entrance Fee: $%s.~n~~w~Press '~y~RETURN~w~' to enter.", BusinessInfo[i][E_BUSINESS_NAME], BusinessInfo[i][E_BUSINESS_ENTRANCEFEE]); 
				else if(BusinessInfo[i][E_BUSINESS_TYPE] == BUSINESS_TYPE_BANK)
					format(str, sizeof(str), "~b~%s~n~~w~Owned By: Goverments~n~~y~Entrance Fee: $%s.~n~~w~Press '~y~RETURN~w~' to enter.", BusinessInfo[i][E_BUSINESS_NAME], BusinessInfo[i][E_BUSINESS_ENTRANCEFEE]); 
				else if(BusinessInfo[i][E_BUSINESS_TYPE] == BUSINESS_TYPE_RENT)
					format(str, sizeof(str), "~b~%s~n~~w~Owned By: Goverments~n~~w~Type '/rentcars' to rent vehicle.", BusinessInfo[i][E_BUSINESS_NAME]); 
						
				else format(str, sizeof(str), "~b~%s~n~~y~This business is for sale price: $%s.~n~~w~Press '~y~RETURN~w~' to enter.", BusinessInfo[i][E_BUSINESS_NAME], FormatMoney(BusinessInfo[i][E_BUSINESS_PRICE]), BusinessInfo[i][E_BUSINESS_LEVEL]); 
			}
			else format(str, sizeof(str), "~b~%s~n~~w~Owned By: %s~n~~y~Entrance Fee: $%s.~n~~w~Press '~y~RETURN~w~' to enter.", BusinessInfo[i][E_BUSINESS_NAME], ReturnDBIDName(BusinessInfo[i][E_BUSINESS_OWNERDBID]), FormatMoney(BusinessInfo[i][E_BUSINESS_ENTRANCEFEE])); 
			
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
                format(str, sizeof(str), "~b~%s, %s~n~~y~This property is for sale price: $%s~n~~w~Press '~y~RETURN~w~' to enter.", PropertyInfo[i][E_PROPERTY_ADDRESS], ReturnLocation(playerid), FormatMoney(PropertyInfo[i][E_PROPERTY_PRICE]));
                ShowBoxMessage(playerid, str, 5);
            }
            else
            {
                format(str, sizeof(str), "~b~%s, %s~n~~w~You're standing on %s's porch~n~~w~Press '~y~RETURN~w~' to enter.", PropertyInfo[i][E_PROPERTY_ADDRESS], ReturnLocation(playerid),  ReturnDBIDName(PropertyInfo[i][E_PROPERTY_OWNERDBID]));
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

			format(str, sizeof(str), "~b~Entrance Point~n~~w~Press '~y~RETURN~w~' to enter."); 
			ShowBoxMessage(playerid, str, 5); 	
            return 1;	
        }
    }

    for(new i = 0; i < 5; i++)
    {
        if(pickupid == GeneralStorePickup[i])
        {
            format(str, sizeof(str), "~b~General Store~n~~w~Press '~y~N~w~' to grab an items."); 
			ShowBoxMessage(playerid, str, 5); 	
            return 1;	
        }
    }

    for(new i = 0; i < 3; i++)
    {
        if(pickupid == FactionLockerPickup[i])
        {
            format(str, sizeof(str), "~b~Faction Locker~n~~w~Type '~y~/flocker~w~' to open locker menu."); 
			ShowBoxMessage(playerid, str, 5); 	
            return 1;	
        }
    }
    
    if(pickupid == SideJobsPickup[0])
    {
        format(str, sizeof(str), "~b~Garbageman~n~~w~Type '~y~/jobduty~w~' start garbageman~n~~w~Type '~y~/collectgarbage~w~' collect trash~n~~w~Type '~y~/dumpgarbage~w~' unload trash into HQ."); 
        ShowBoxMessage(playerid, str, 5); 	
        return 1;	
    }

    if(pickupid == SideJobsPickup[1])
    {
        format(str, sizeof(str), "~b~Docksworker~n~~w~Type '~y~/jobduty~w~' start dockworkers~n~~w~Type '~y~/takecargo~w~' load cargo~n~~w~Type '~y~/storecargo~w~' unload cargo into warehouse."); 
        ShowBoxMessage(playerid, str, 5); 	
        return 1;	
    }

    if(pickupid == SideJobsPickup[2])
    {
        format(str, sizeof(str), "~b~Street Cleaner~n~~w~Type '~y~/jobduty~w~' start sweepers~n~~w~Clean trash around the street."); 
        ShowBoxMessage(playerid, str, 5); 	
        return 1;	
    }

    if(pickupid == SideJobsPickup[3])
    {
        format(str, sizeof(str), "~b~Bus Driver~n~~w~Type '~y~/jobduty~w~' start bus driver~n~~w~drive around the road and get passengers at bus stops."); 
        ShowBoxMessage(playerid, str, 5); 	
        return 1;	
    }

    for(new i = 0; i < sizeof(JobsInfo); i++)
    {
        if(pickupid == JobsPickup[i])
        {
            format(str, sizeof(str), "~b~Jobs Point~n~~w~Type '~y~/joinjob~w~' to join jobs~n~~w~Type '~y~/quitjob~w~' to quit jobs."); 
            ShowBoxMessage(playerid, str, 5); 
            return 1;	
        }
    }

    if(pickupid == ChainsawPickup)
    {
        format(str, sizeof(str), "~b~Leafy Hollow Barn~n~~w~Type '~y~/buysaw~w~' to buy chainsaw."); 
        ShowBoxMessage(playerid, str, 5); 
        return 1;	
    }

    if(pickupid == DropInjuredPickup)
    {
        format(str, sizeof(str), "~b~Hospital~n~~w~Type '~y~/dropinjured~w~' to drop player injured."); 
        ShowBoxMessage(playerid, str, 5); 
        return 1;	
    }

    if(pickupid == VehicleScrapPickup)
    {
        format(str, sizeof(str), "~b~Vehicle Scrapyard~n~~w~Type '~y~/carscrap~w~' to scrap vehicles."); 
        ShowBoxMessage(playerid, str, 5); 
        return 1;	
    }

    if(pickupid == HairCutPickup)
    {
        format(str, sizeof(str), "~b~Haircuts~n~~w~Type '~y~/haircut~w~' to cut hairs."); 
        ShowBoxMessage(playerid, str, 5); 
        return 1;	
    }

    if(pickupid == TicketPickup)
    {
        format(str, sizeof(str), "~b~Tikcets~n~~w~Type '~y~/tickets~w~' to pay your ticket."); 
        ShowBoxMessage(playerid, str, 5); 
        return 1;	
    }

    if(pickupid == FishFactoryPickup)
    {
        format(str, sizeof(str), "~b~Fish Factory~n~~w~Type '~y~/buybait~w~' to buy fish bait~n~~w~Type '~y~/sellfish~w~' to sell fish."); 
        ShowBoxMessage(playerid, str, 5); 
        return 1;	
    }

    for(new i; i < sizeof(BusStop_Index); i++)
	{
        if(pickupid == BusStopPickup[i])
        {
            format(str, sizeof(str), "~b~Bus Station (Start of Service) Bus Stop~n~~w~Type '~y~/viewroute~w~' to show bus route stop."); 
            ShowBoxMessage(playerid, str, 5); 
            return 1;	
        }
    }

    if(pickupid == DealershipPickup[0])
    {
        format(str, sizeof(str), "~b~Bikes Dealership~n~~w~Type '~y~/dealership~w~' to see dealership menu."); 
        ShowBoxMessage(playerid, str, 5); 
        return 1;	
    }

    if(pickupid == DealershipPickup[1])
    {
        format(str, sizeof(str), "~b~Two Door Dealership~n~~w~Type '~y~/dealership~w~' to see dealership menu."); 
        ShowBoxMessage(playerid, str, 5); 
        return 1;	
    }

    if(pickupid == DealershipPickup[2])
    {
        format(str, sizeof(str), "~b~Four Door Dealership~n~~w~Type '~y~/dealership~w~' to see dealership menu."); 
        ShowBoxMessage(playerid, str, 5); 
        return 1;	
    }

    if(pickupid == DealershipPickup[3])
    {
        format(str, sizeof(str), "~b~Industry Dealership~n~~w~Type '~y~/dealership~w~' to see dealership menu."); 
        ShowBoxMessage(playerid, str, 5); 
        return 1;	
    }

    if(pickupid == DealershipPickup[4])
    {
        format(str, sizeof(str), "~b~Taxi Dealership~n~~w~Type '~y~/dealership~w~' to see dealership menu."); 
        ShowBoxMessage(playerid, str, 5); 
        return 1;	
    }

    if(pickupid == PrisonPickup)
    {
        format(str, sizeof(str), "~b~Los Santos Correctional Facility~n~~w~Type '~y~/charge~w~' to put player into prison~n~~w~Type '~y~/opencell or /closecell~w~' to open/close cell."); 
        ShowBoxMessage(playerid, str, 5); 
        return 1;	
    }

    if(pickupid == LotteryPickup)
    {
        format(str, sizeof(str), "~b~Los Santos Correctional Facility~n~~w~Type '~y~/charge~w~' to put player into prison~n~~w~Type '~y~/opencell or /closecell~w~' to open/close cell."); 
        ShowBoxMessage(playerid, str, 5); 
        return 1;	
    }
    
    return 1;
}