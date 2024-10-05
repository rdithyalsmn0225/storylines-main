//Dealership:
InsertDealership()
{
    CreateDynamicPickup(1239, 1, 684.6581,-1570.5861,14.2422, -1, -1, -1, 10.0); //Bikes
    CreateDynamicPickup(1239, 1, 2132.0190,-1149.9902,24.2088, -1, -1, -1, 10.0); //2door
    CreateDynamicPickup(1239, 1, 1629.6158,-1903.5123,13.5530, -1, -1, -1, 10.0); //4door
    CreateDynamicPickup(1239, 1, 2684.1277,-2515.6733,13.1552, -1, -1, -1, 10.0); //Vans
}

CMD:carbuy(playerid, params[])
{
    if(PlayerInfo[playerid][E_CHARACTER_VEHICLESPAWNED])
		return SendErrorMessage(playerid, "You have a vehicle spawned."); 
			
	new idx;
			
	for(new i = 1; i < MAX_PLAYER_VEHICLES; i++)
	{
		if(!PlayerInfo[playerid][E_CHARACTER_OWNEDVEHICLE][i])
		{
			idx = i;
			break;
		}
	}
				
	if(!idx)
	{
		SendErrorMessage(playerid, "You own the maximum amount of vehicles."); 
		return 1;
	}
			
	if(IsPlayerInRangeOfPoint(playerid, 3.0, 684.6581,-1570.5861,14.2422))
	{		
		new larstr[512],
			counter = 0;

        CatDealershipHolder[playerid] = DEALERSHIP_CATEGORY_BIKES; 

		for(new i = 0; i < sizeof(g_aDealershipData); i++)
	    {
			if(DEALERSHIP_CATEGORY_BIKES == g_aDealershipData[i][E_DEALERSHIP_CATEGORY])
			{
				format(larstr, sizeof(larstr), "%s%s\t{0D7304}$%s{ffffff}\n", larstr, g_aDealershipData[i][E_DEALERSHIP_MODEL], FormatMoney(g_aDealershipData[i][E_DEALERSHIP_PRICE]));
						
				SubDealershipHolderArr[playerid][counter] = i; 
				counter++; 
			}
		}
				
		ShowPlayerDialog(playerid, DIALOG_DEALERSHIP_SELECT, DIALOG_STYLE_TABLIST, "Available Models:", larstr, "Select", "Close"); 			
	}
    else if(IsPlayerInRangeOfPoint(playerid, 3.0, 2132.0190,-1149.9902,24.2088))
	{		
		new larstr[512],
			counter = 0;

        CatDealershipHolder[playerid] = DEALERSHIP_CATEGORY_TWODOOR; 

		for(new i = 0; i < sizeof(g_aDealershipData); i++)
	    {
			if(DEALERSHIP_CATEGORY_TWODOOR == g_aDealershipData[i][E_DEALERSHIP_CATEGORY])
			{
				format(larstr, sizeof(larstr), "%s%s\t{0D7304}$%s{ffffff}\n", larstr, g_aDealershipData[i][E_DEALERSHIP_MODEL], FormatMoney(g_aDealershipData[i][E_DEALERSHIP_PRICE]));
						
				SubDealershipHolderArr[playerid][counter] = i; 
				counter++; 
			}
		}
				
		ShowPlayerDialog(playerid, DIALOG_DEALERSHIP_SELECT, DIALOG_STYLE_TABLIST, "Available Models:", larstr, "Select", "Close"); 			
	}
    else if(IsPlayerInRangeOfPoint(playerid, 3.0, 1629.6158,-1903.5123,13.5530))
	{		
		new larstr[512],
			counter = 0;

        CatDealershipHolder[playerid] = DEALERSHIP_CATEGORY_FOURDOOR; 

		for(new i = 0; i < sizeof(g_aDealershipData); i++)
	    {
			if(DEALERSHIP_CATEGORY_FOURDOOR == g_aDealershipData[i][E_DEALERSHIP_CATEGORY])
			{
				format(larstr, sizeof(larstr), "%s%s\t{0D7304}$%s{ffffff}\n", larstr, g_aDealershipData[i][E_DEALERSHIP_MODEL], FormatMoney(g_aDealershipData[i][E_DEALERSHIP_PRICE]));
						
				SubDealershipHolderArr[playerid][counter] = i; 
				counter++; 
			}
		}
				
		ShowPlayerDialog(playerid, DIALOG_DEALERSHIP_SELECT, DIALOG_STYLE_TABLIST, "Available Models:", larstr, "Select", "Close"); 			
	}
    else if(IsPlayerInRangeOfPoint(playerid, 3.0, 2684.1277,-2515.6733,13.1552))
	{		
		new larstr[512],
			counter = 0;

        CatDealershipHolder[playerid] = DEALERSHIP_CATEGORY_VANS; 

		for(new i = 0; i < sizeof(g_aDealershipData); i++)
	    {
			if(DEALERSHIP_CATEGORY_VANS == g_aDealershipData[i][E_DEALERSHIP_CATEGORY])
			{
				format(larstr, sizeof(larstr), "%s%s\t{0D7304}$%s{ffffff}\n", larstr, g_aDealershipData[i][E_DEALERSHIP_MODEL], FormatMoney(g_aDealershipData[i][E_DEALERSHIP_PRICE]));
						
				SubDealershipHolderArr[playerid][counter] = i; 
				counter++; 
			}
		}
				
		ShowPlayerDialog(playerid, DIALOG_DEALERSHIP_SELECT, DIALOG_STYLE_TABLIST, "Available Models:", larstr, "Select", "Close"); 			
	}
    return 1;
}