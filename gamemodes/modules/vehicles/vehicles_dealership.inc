//Dealership:
InsertDealership()
{
    DealershipPickup[0] = CreateDynamicPickup(1239, 1, 684.6581,-1570.5861,14.2422, -1, -1, -1, 5.0); //Bikes
    DealershipPickup[1] = CreateDynamicPickup(1239, 1, 2132.0190,-1149.9902,24.2088, -1, -1, -1, 5.0); //2door
    DealershipPickup[2] =  CreateDynamicPickup(1239, 1, 1629.6158,-1903.5123,13.5530, -1, -1, -1, 5.0); //4door
    DealershipPickup[3] = CreateDynamicPickup(1239, 1, 2684.1277,-2515.6733,13.1552, -1, -1, -1, 5.0); //Vans
	DealershipPickup[4] = CreateDynamicPickup(1239, 1, 666.1486,-1419.0734,14.0272, -1, -1, -1, 5.0); //Taxi
	DealershipPickup[5] = CreateDynamicPickup(1239, 1, 2639.1436,-2470.5903,3.0000, -1, -1, -1, 5.0); //Boat

	CreateDynamic3DTextLabel("[Bikes Dealership]", COLOR_3DTEXT, 684.6581,-1570.5861,14.2422, 5.0);
	CreateDynamic3DTextLabel("[Two Door Dealership]", COLOR_3DTEXT, 2132.0190,-1149.9902,24.2088, 5.0);
	CreateDynamic3DTextLabel("[Four Door Dealership]", COLOR_3DTEXT, 1629.6158,-1903.5123,13.5530, 5.0);
	CreateDynamic3DTextLabel("[Industry Dealership]", COLOR_3DTEXT, 2684.1277,-2515.6733,13.1552, 5.0);
	CreateDynamic3DTextLabel("[Taxi Dealership]", COLOR_3DTEXT, 666.1486,-1419.0734,14.0272, 5.0);
	CreateDynamic3DTextLabel("[Boat Dealership]", COLOR_3DTEXT, 2639.1436,-2470.5903,3.0000, 5.0);
}


stock ShowDealerAppend(playerid)
{
	new
		caption[60],
		str[255];

	format(caption, 60, "%s - {33AA33}%s:", g_aDealershipData[SubDealershipHolder[playerid]][E_DEALERSHIP_MODEL], FormatMoney(DealershipTotalCost[playerid])); 
	strcat(str, "Colors\n");
	strcat(str, "{FFFF00}Purchase Vehicle\n"); 
			
	Dialog_Show(playerid, DialogDealerAppend, DIALOG_STYLE_LIST, caption, str, "Append", "<<"); 
	return 1; 
}

CMD:dealership(playerid, params[])
{		
	new idx;

	new maxVehicles = AccountInfo[playerid][E_MASTERS_VIP] ? 4 : 2;

	for(new i = 1; i < MAX_PLAYER_VEHICLES; i++)
	{
		if(!PlayerInfo[playerid][E_CHARACTER_OWNEDVEHICLE][i])
		{
			if(i <= maxVehicles)
			{
				idx = i;
				break;
			}
		}
	}

	if(!idx)
	{
		SendErrorMessage(playerid, "You own the maximum amount of vehicles."); 
		return 1;
	}
			
	if(IsPlayerInRangeOfPoint(playerid, 3.0, 684.6581,-1570.5861,14.2422))
	{		
		new larstr[1024],
			counter = 0;

        CatDealershipHolder[playerid] = DEALERSHIP_CATEGORY_BIKES; 

		for(new i = 0; i < sizeof(g_aDealershipData); i++)
	    {
			new Cents = floatround(g_aDealershipData[i][E_DEALERSHIP_PRICE] * 100, floatround_round);
			if(DEALERSHIP_CATEGORY_BIKES == g_aDealershipData[i][E_DEALERSHIP_CATEGORY])
			{
				format(larstr, sizeof(larstr), "%s%d\t$%s\n", larstr, g_aDealershipData[i][E_DEALERSHIP_MODELID], FormatMoney(Cents));
						
				SubDealershipHolderArr[playerid][counter] = i; 
				counter++; 
			}
		}
				
		Dialog_Show(playerid, DialogDealership, DIALOG_STYLE_TABLIST, "Available Models:", larstr, "Select", "Close"); 			
	}
    else if(IsPlayerInRangeOfPoint(playerid, 3.0, 2132.0190,-1149.9902,24.2088))
	{		
		new larstr[1024],
			counter = 0;

        CatDealershipHolder[playerid] = DEALERSHIP_CATEGORY_TWODOOR; 

		for(new i = 0; i < sizeof(g_aDealershipData); i++)
	    {
			new Cents = floatround(g_aDealershipData[i][E_DEALERSHIP_PRICE] * 100, floatround_round);
			if(DEALERSHIP_CATEGORY_TWODOOR == g_aDealershipData[i][E_DEALERSHIP_CATEGORY])
			{
				format(larstr, sizeof(larstr), "%s%d\t$%s\n", larstr, g_aDealershipData[i][E_DEALERSHIP_MODELID], FormatMoney(Cents));
						
				SubDealershipHolderArr[playerid][counter] = i; 
				counter++; 
			}
		}
				
		Dialog_Show(playerid, DialogDealership, DIALOG_STYLE_TABLIST, "Available Models:", larstr, "Select", "Close"); 			
	}
    else if(IsPlayerInRangeOfPoint(playerid, 3.0, 1629.6158,-1903.5123,13.5530))
	{		
		new larstr[1024],
			counter = 0;

        CatDealershipHolder[playerid] = DEALERSHIP_CATEGORY_FOURDOOR; 

		for(new i = 0; i < sizeof(g_aDealershipData); i++)
	    {
			new Cents = floatround(g_aDealershipData[i][E_DEALERSHIP_PRICE] * 100, floatround_round);
			if(DEALERSHIP_CATEGORY_FOURDOOR == g_aDealershipData[i][E_DEALERSHIP_CATEGORY])
			{
				format(larstr, sizeof(larstr), "%s%d\t$%s\n", larstr, g_aDealershipData[i][E_DEALERSHIP_MODELID], FormatMoney(Cents));
						
				SubDealershipHolderArr[playerid][counter] = i; 
				counter++; 
			}
		}
				
		Dialog_Show(playerid, DialogDealership, DIALOG_STYLE_TABLIST, "Available Models:", larstr, "Select", "Close"); 			
	}
    else if(IsPlayerInRangeOfPoint(playerid, 3.0, 2684.1277,-2515.6733,13.1552))
	{		
		new larstr[1024],
			counter = 0;

        CatDealershipHolder[playerid] = DEALERSHIP_CATEGORY_INDUSTRIAL; 

		for(new i = 0; i < sizeof(g_aDealershipData); i++)
	    {
			new Cents = floatround(g_aDealershipData[i][E_DEALERSHIP_PRICE] * 100, floatround_round);
			if(DEALERSHIP_CATEGORY_INDUSTRIAL == g_aDealershipData[i][E_DEALERSHIP_CATEGORY])
			{
				format(larstr, sizeof(larstr), "%s%d\t$%s\n", larstr, g_aDealershipData[i][E_DEALERSHIP_MODELID], FormatMoney(Cents));
						
				SubDealershipHolderArr[playerid][counter] = i; 
				counter++; 
			}
		}
				
		Dialog_Show(playerid, DialogDealership, DIALOG_STYLE_TABLIST, "Available Models:", larstr, "Select", "Close"); 			
	}
	else if(IsPlayerInRangeOfPoint(playerid, 3.0, 666.1486,-1419.0734,14.0272))
	{		
		new larstr[1024],
			counter = 0;

        CatDealershipHolder[playerid] = DEALERSHIP_CATEGORY_TAXI; 

		for(new i = 0; i < sizeof(g_aDealershipData); i++)
	    {
			new Cents = floatround(g_aDealershipData[i][E_DEALERSHIP_PRICE] * 100, floatround_round);
			if(DEALERSHIP_CATEGORY_TAXI == g_aDealershipData[i][E_DEALERSHIP_CATEGORY])
			{
				format(larstr, sizeof(larstr), "%s%d\t$%s\n", larstr, g_aDealershipData[i][E_DEALERSHIP_MODELID], FormatMoney(Cents));
						
				SubDealershipHolderArr[playerid][counter] = i; 
				counter++; 
			}
		}		
		Dialog_Show(playerid, DialogDealership, DIALOG_STYLE_TABLIST, "Available Models:", larstr, "Select", "Close"); 			
	}
	else if(IsPlayerInRangeOfPoint(playerid, 3.0, 666.1486,-1419.0734,14.0272))
	{		
		new larstr[1024],
			counter = 0;

        CatDealershipHolder[playerid] = DEALERSHIP_CATEGORY_BOAT; 

		for(new i = 0; i < sizeof(g_aDealershipData); i++)
	    {
			new Cents = floatround(g_aDealershipData[i][E_DEALERSHIP_PRICE] * 100, floatround_round);
			if(DEALERSHIP_CATEGORY_BOAT == g_aDealershipData[i][E_DEALERSHIP_CATEGORY])
			{
				format(larstr, sizeof(larstr), "%s%d\t$%s\n", larstr, g_aDealershipData[i][E_DEALERSHIP_MODELID], FormatMoney(Cents));
						
				SubDealershipHolderArr[playerid][counter] = i; 
				counter++; 
			}
		}
		Dialog_Show(playerid, DialogDealership, DIALOG_STYLE_TABLIST, "Available Models:", larstr, "Select", "Close"); 			
	}
    return 1;
}