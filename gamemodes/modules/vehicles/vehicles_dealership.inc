//Dealership:
InsertDealership()
{
    CreateDynamicPickup(1239, 1, 684.6581,-1570.5861,14.2422, -1, -1, -1, 5.0); //Bikes
    CreateDynamicPickup(1239, 1, 2132.0190,-1149.9902,24.2088, -1, -1, -1, 5.0); //2door
    CreateDynamicPickup(1239, 1, 1629.6158,-1903.5123,13.5530, -1, -1, -1, 5.0); //4door
    CreateDynamicPickup(1239, 1, 2684.1277,-2515.6733,13.1552, -1, -1, -1, 5.0); //Vans
	CreateDynamicPickup(1239, 1, 666.1486,-1419.0734,14.0272, -1, -1, -1, 5.0);

	CreateDynamic3DTextLabel("[Bikes Dealership]\n{ffffff}Available Commands: '/carbuy' to purchase vehicle", COLOR_POINT, 684.6581,-1570.5861,14.2422, 5.0);
	CreateDynamic3DTextLabel("[Two Door Dealership]\n{ffffff}Available Commands: '/carbuy' to purchase vehicle", COLOR_POINT, 2132.0190,-1149.9902,24.2088, 5.0);
	CreateDynamic3DTextLabel("[Four Door Dealership]\n{ffffff}Available Commands: '/carbuy' to purchase vehicle", COLOR_POINT, 1629.6158,-1903.5123,13.5530, 5.0);
	CreateDynamic3DTextLabel("[Industry Dealership]\n{ffffff}Available Commands: '/carbuy' to purchase vehicle", COLOR_POINT, 2684.1277,-2515.6733,13.1552, 5.0);
	CreateDynamic3DTextLabel("[Taxi Dealership]\n{ffffff}Available Commands: '/carbuy' to purchase vehicle", COLOR_POINT, 666.1486,-1419.0734,14.0272, 5.0);
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
				format(larstr, sizeof(larstr), "%s%d\t~g~$%s~w~\n", larstr, g_aDealershipData[i][E_DEALERSHIP_MODELID], FormatMoney(g_aDealershipData[i][E_DEALERSHIP_PRICE]));
						
				SubDealershipHolderArr[playerid][counter] = i; 
				counter++; 
			}
		}
				
		Dialog_Show(playerid, DealershipSelect, DIALOG_STYLE_PREVIEW_MODEL, "Available Models:", larstr, "Select", "Close"); 			
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
				format(larstr, sizeof(larstr), "%s%d\t~g~$%s~w~\n", larstr, g_aDealershipData[i][E_DEALERSHIP_MODELID], FormatMoney(g_aDealershipData[i][E_DEALERSHIP_PRICE]));
						
				SubDealershipHolderArr[playerid][counter] = i; 
				counter++; 
			}
		}
				
		Dialog_Show(playerid, DealershipSelect, DIALOG_STYLE_PREVIEW_MODEL, "Available Models:", larstr, "Select", "Close"); 			
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
				format(larstr, sizeof(larstr), "%s%d\t~g~$%s~w~\n", larstr, g_aDealershipData[i][E_DEALERSHIP_MODELID], FormatMoney(g_aDealershipData[i][E_DEALERSHIP_PRICE]));
						
				SubDealershipHolderArr[playerid][counter] = i; 
				counter++; 
			}
		}
				
		Dialog_Show(playerid, DealershipSelect, DIALOG_STYLE_PREVIEW_MODEL, "Available Models:", larstr, "Select", "Close"); 			
	}
    else if(IsPlayerInRangeOfPoint(playerid, 3.0, 2684.1277,-2515.6733,13.1552))
	{		
		new larstr[512],
			counter = 0;

        CatDealershipHolder[playerid] = DEALERSHIP_CATEGORY_INDUSTRIAL; 

		for(new i = 0; i < sizeof(g_aDealershipData); i++)
	    {
			if(DEALERSHIP_CATEGORY_INDUSTRIAL == g_aDealershipData[i][E_DEALERSHIP_CATEGORY])
			{
				format(larstr, sizeof(larstr), "%s%d\t~g~$%s~w~\n", larstr, g_aDealershipData[i][E_DEALERSHIP_MODELID], FormatMoney(g_aDealershipData[i][E_DEALERSHIP_PRICE]));
						
				SubDealershipHolderArr[playerid][counter] = i; 
				counter++; 
			}
		}
				
		Dialog_Show(playerid, DealershipSelect, DIALOG_STYLE_PREVIEW_MODEL, "Available Models:", larstr, "Select", "Close"); 			
	}
	else if(IsPlayerInRangeOfPoint(playerid, 3.0, 666.1486,-1419.0734,14.0272))
	{		
		new larstr[512],
			counter = 0;

        CatDealershipHolder[playerid] = DEALERSHIP_CATEGORY_TAXI; 

		for(new i = 0; i < sizeof(g_aDealershipData); i++)
	    {
			if(DEALERSHIP_CATEGORY_TAXI == g_aDealershipData[i][E_DEALERSHIP_CATEGORY])
			{
				format(larstr, sizeof(larstr), "%s%d\t~g~$%s~w~\n", larstr, g_aDealershipData[i][E_DEALERSHIP_MODELID], FormatMoney(g_aDealershipData[i][E_DEALERSHIP_PRICE]));
						
				SubDealershipHolderArr[playerid][counter] = i; 
				counter++; 
			}
		}
				
		Dialog_Show(playerid, DealershipSelect, DIALOG_STYLE_PREVIEW_MODEL, "Available Models:", larstr, "Select", "Close"); 			
	}
    return 1;
}

Dialog:DealershipSelect(playerid, response, listitem, inputtext)
{
	if(response)
	{
		SubDealershipHolder[playerid] = SubDealershipHolderArr[playerid][listitem]; 
		
		new
			i,
			str[128],
			caption[60]; 
			
		i = SubDealershipHolder[playerid];
		
		if(g_aDealershipData[i][E_DEALERSHIP_PRICE] > PlayerInfo[playerid][E_CHARACTER_MONEY])
			return SendErrorMessage(playerid, "You need $%s to buy this. (Total: $%s)", FormatMoney(g_aDealershipData[i][E_DEALERSHIP_PRICE]), FormatMoney(PlayerInfo[playerid][E_CHARACTER_MONEY])); 
			
		DealershipTotalCost[playerid] = g_aDealershipData[i][E_DEALERSHIP_PRICE];
		
		format(caption, 60, "%s - {5B9460}%s:", g_aDealershipData[i][E_DEALERSHIP_MODEL], FormatMoney(DealershipTotalCost[playerid])); 
		strcat(str, "Colors\n");
		strcat(str, "{FFFF00}Purchase Vehicle\n"); 
		
		TogglePlayerControllable(playerid, false); 
		
		DealershipPlayerCar[playerid] = CreateVehicle(g_aDealershipData[i][E_DEALERSHIP_MODELID], g_aDealershipData[i][E_DEALERSHIP_SPAWNX], g_aDealershipData[i][E_DEALERSHIP_SPAWNY], g_aDealershipData[i][E_DEALERSHIP_SPAWNZ], g_aDealershipData[i][E_DEALERSHIP_SPAWNA], 0, 0, -1);
		PlayerPutIntoVehicle(playerid, DealershipPlayerCar[playerid], 0); 
		
		ShowPlayerDialog(playerid, DIALOG_DEALERSHIP_APPEND, DIALOG_STYLE_LIST, caption, str, "Append", "<<");
	}
	return 1;
}