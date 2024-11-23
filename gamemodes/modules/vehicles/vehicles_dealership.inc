//Dealership:
InsertDealership()
{
    DealershipPickup[0] = CreateDynamicPickup(1239, 1, 684.6581,-1570.5861,14.2422, -1, -1, -1, 5.0); //Bikes
    DealershipPickup[1] = CreateDynamicPickup(1239, 1, 2132.0190,-1149.9902,24.2088, -1, -1, -1, 5.0); //2door
    DealershipPickup[2] =  CreateDynamicPickup(1239, 1, 1629.6158,-1903.5123,13.5530, -1, -1, -1, 5.0); //4door
    DealershipPickup[3] = CreateDynamicPickup(1239, 1, 2684.1277,-2515.6733,13.1552, -1, -1, -1, 5.0); //Vans
	DealershipPickup[4] = CreateDynamicPickup(1239, 1, 666.1486,-1419.0734,14.0272, -1, -1, -1, 5.0); //Taxi

	CreateDynamic3DTextLabel("[Bikes Dealership]", COLOR_3DTEXT, 684.6581,-1570.5861,14.2422, 5.0);
	CreateDynamic3DTextLabel("[Two Door Dealership]", COLOR_3DTEXT, 2132.0190,-1149.9902,24.2088, 5.0);
	CreateDynamic3DTextLabel("[Four Door Dealership]", COLOR_3DTEXT, 1629.6158,-1903.5123,13.5530, 5.0);
	CreateDynamic3DTextLabel("[Industry Dealership]", COLOR_3DTEXT, 2684.1277,-2515.6733,13.1552, 5.0);
	CreateDynamic3DTextLabel("[Taxi Dealership]", COLOR_3DTEXT, 666.1486,-1419.0734,14.0272, 5.0);

	CreateDynamicMapIcon(684.6581,-1570.5861,14.2422, 55, 0, -1, -1, -1, 999999.0);
	CreateDynamicMapIcon(2132.0190,-1149.9902,24.2088, 55, 0, -1, -1, -1, 999999.0);
	CreateDynamicMapIcon(1629.6158,-1903.5123,13.5530, 55, 0, -1, -1, -1, 999999.0);
	CreateDynamicMapIcon(2684.1277,-2515.6733,13.1552, 55, 0, -1, -1, -1, 999999.0);
	CreateDynamicMapIcon(666.1486,-1419.0734,14.0272, 55, 0, -1, -1, -1, 999999.0);
}

CMD:dealership(playerid, params[])
{		
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
		new larstr[1024],
			counter = 0;

        CatDealershipHolder[playerid] = DEALERSHIP_CATEGORY_BIKES; 

		for(new i = 0; i < sizeof(g_aDealershipData); i++)
	    {
			new Cents = floatround(g_aDealershipData[i][E_DEALERSHIP_PRICE] * 100, floatround_round);
			if(DEALERSHIP_CATEGORY_BIKES == g_aDealershipData[i][E_DEALERSHIP_CATEGORY])
			{
				format(larstr, sizeof(larstr), "%s%d\t~g~$%s~w~\n", larstr, g_aDealershipData[i][E_DEALERSHIP_MODELID], FormatMoney(Cents));
						
				SubDealershipHolderArr[playerid][counter] = i; 
				counter++; 
			}
		}
				
		Dialog_Show(playerid, DealershipSelect, DIALOG_STYLE_PREVIEW_MODEL, "Available Models:", larstr, "Select", "Close"); 			
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
				format(larstr, sizeof(larstr), "%s%d\t~g~$%s~w~\n", larstr, g_aDealershipData[i][E_DEALERSHIP_MODELID], FormatMoney(Cents));
						
				SubDealershipHolderArr[playerid][counter] = i; 
				counter++; 
			}
		}
				
		Dialog_Show(playerid, DealershipSelect, DIALOG_STYLE_PREVIEW_MODEL, "Available Models:", larstr, "Select", "Close"); 			
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
				format(larstr, sizeof(larstr), "%s%d\t~g~$%s~w~\n", larstr, g_aDealershipData[i][E_DEALERSHIP_MODELID], FormatMoney(Cents));
						
				SubDealershipHolderArr[playerid][counter] = i; 
				counter++; 
			}
		}
				
		Dialog_Show(playerid, DealershipSelect, DIALOG_STYLE_PREVIEW_MODEL, "Available Models:", larstr, "Select", "Close"); 			
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
				format(larstr, sizeof(larstr), "%s%d\t~g~$%s~w~\n", larstr, g_aDealershipData[i][E_DEALERSHIP_MODELID], FormatMoney(Cents));
						
				SubDealershipHolderArr[playerid][counter] = i; 
				counter++; 
			}
		}
				
		Dialog_Show(playerid, DealershipSelect, DIALOG_STYLE_PREVIEW_MODEL, "Available Models:", larstr, "Select", "Close"); 			
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
				format(larstr, sizeof(larstr), "%s%d\t~g~$%s~w~\n", larstr, g_aDealershipData[i][E_DEALERSHIP_MODELID], FormatMoney(Cents));
						
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
		
		new Cents = floatround(g_aDealershipData[i][E_DEALERSHIP_PRICE] * 100, floatround_round);

		if(Cents > PlayerInfo[playerid][E_CHARACTER_MONEY])
			return SendErrorMessage(playerid, "You need $%s to buy this. (Total: $%s)", FormatMoney(Cents), FormatMoney(PlayerInfo[playerid][E_CHARACTER_MONEY])); 
			
		DealershipTotalCost[playerid] = Cents;
		
		format(caption, 60, "%s - {93C47D}%s:", g_aDealershipData[i][E_DEALERSHIP_MODEL], FormatMoney(DealershipTotalCost[playerid])); 
		strcat(str, "Colors\n");
		strcat(str, "{FFFF00}Purchase Vehicle\n"); 
		
		TogglePlayerControllable(playerid, false); 
		
		DealershipPlayerCar[playerid] = CreateVehicle(g_aDealershipData[i][E_DEALERSHIP_MODELID], g_aDealershipData[i][E_DEALERSHIP_SPAWNX], g_aDealershipData[i][E_DEALERSHIP_SPAWNY], g_aDealershipData[i][E_DEALERSHIP_SPAWNZ], g_aDealershipData[i][E_DEALERSHIP_SPAWNA], 0, 0, -1);
		PlayerPutIntoVehicle(playerid, DealershipPlayerCar[playerid], 0); 
		
		Dialog_Show(playerid, DealershipAppend, DIALOG_STYLE_LIST, caption, str, "Append", "<<");
	}
	return 1;
}

Dialog:DealershipAppend(playerid, response, listitem, inputtext[])
{
	new
		caption[60],
		str[400]; 
	
	format(caption, 60, "%s - {93C47D}%s:", g_aDealershipData[SubDealershipHolder[playerid]][E_DEALERSHIP_MODEL], FormatMoney(DealershipTotalCost[playerid])); 
	
	if(response)
	{
		switch(listitem)
		{
			case 0: //Colors
			{
				new 
					dstr[128];
			
				format(dstr, sizeof(dstr), "Color 1 ({%06x}%d{FFFFFF})\n", VehicleColoursTableRGBA[DealershipCarColors[playerid][0]] >>> 8, DealershipCarColors[playerid][0]);
				strcat(str, dstr);
				
				format(dstr, sizeof(dstr), "Color 2 ({%06x}%d{FFFFFF})\n", VehicleColoursTableRGBA[DealershipCarColors[playerid][1]] >>> 8, DealershipCarColors[playerid][1]);
				strcat(str, dstr);
				
				Dialog_Show(playerid, DealershipAppendCMenu, DIALOG_STYLE_LIST, caption, str, "Select", "<<"); 
			}
			case 1: //Purchase
			{
				new dstr[128], vehicleid = GetPlayerVehicleID(playerid);
				
				format(dstr, sizeof(dstr), "Models:\t%s\n", ReturnVehicleName(vehicleid));
				strcat(str, dstr);
				format(dstr, sizeof(dstr), "Price:\t{FFFFFF}{93C47D}$%s{ffffff}\n", FormatMoney(g_aDealershipData[SubDealershipHolder[playerid]][E_DEALERSHIP_PRICE]));
				strcat(str, dstr);
				format(dstr, sizeof(dstr), "Max Speed:\t{FFFFFF}%.1f\n", GetVehicleTopSpeed(DealershipPlayerCar[playerid])); 
				strcat(str, dstr); 
				Dialog_Show(playerid, DealershipPurchase, DIALOG_STYLE_MSGBOX, caption, str, "Edit", "Checkout"); 
				return 1;
			}
		}
	}
	else ConfirmDialog(playerid, "Confirmation", "Are you sure you want to exit?", "OnPlayerExitDealership"); 
	return 1;
}

Dialog:DealershipAppendCMenu(playerid, response, listitem, inputtext[])
{
	new
		str[128],
		caption[60]
	; 
	
	format(caption, 60, "%s - {93C47D}%s:", g_aDealershipData[SubDealershipHolder[playerid]][E_DEALERSHIP_MODEL], FormatMoney(DealershipTotalCost[playerid])); 

	if(response)
	{
		switch(listitem)
		{
			case 0:
			{
				format(str, sizeof(str), "{FFFFFF}You're selecting your vehicles first color. ({%06x}%d{FFFFFF})\n Please select a Color ID. (0-255)", VehicleColoursTableRGBA[DealershipCarColors[playerid][0]] >>> 8, DealershipCarColors[playerid][0]); 
				Dialog_Show(playerid, DealershipAppendColor1, DIALOG_STYLE_INPUT, caption, str, "Select", "<<");  
			}
			case 1:
			{
				format(str, sizeof(str), "{FFFFFF}You're selecting your vehicles second color. ({%06x}%d{FFFFFF})\n Please select a Color ID. (0-255)", VehicleColoursTableRGBA[DealershipCarColors[playerid][1]] >>> 8, DealershipCarColors[playerid][1]); 
				Dialog_Show(playerid, DealershipAppendColor2, DIALOG_STYLE_INPUT, caption, str, "Select", "<<"); 
			}
		}
	}
	else return ShowDealerAppend(playerid);
	return 1;
}

Dialog:DealershipAppendColor1(playerid, response, listitem, inputtext[])
{
	new
		caption[60],
		str[128],
		color1
	;
	
	format(caption, 60, "%s - {93C47D}%s:", g_aDealershipData[SubDealershipHolder[playerid]][E_DEALERSHIP_MODEL], FormatMoney(DealershipTotalCost[playerid])); 
	
	if(response)
	{
		if(!IsNumeric(inputtext))
		{
			format(str, sizeof(str), "{FFFFFF}You're selecting your vehicles first color. ({%06x}%d{FFFFFF})\n Please select a Color ID. (0-255)", VehicleColoursTableRGBA[DealershipCarColors[playerid][0]] >>> 8, DealershipCarColors[playerid][0]); 
			return Dialog_Show(playerid, DealershipAppendColor1, DIALOG_STYLE_INPUT, caption, str, "Select", "<<");  
		}
	
		color1 = strval(inputtext);
		
		if(color1 > 255 || color1 < 0)
		{
			format(str, sizeof(str), "{FFFFFF}You're selecting your vehicles first color. ({%06x}%d{FFFFFF})\n Please select a Color ID. (0-255)", VehicleColoursTableRGBA[DealershipCarColors[playerid][0]] >>> 8, DealershipCarColors[playerid][0]); 
			return Dialog_Show(playerid, DealershipAppendColor1, DIALOG_STYLE_INPUT, caption, str, "Select", "<<");  
		}
		
		ChangeVehicleColor(DealershipPlayerCar[playerid], color1, DealershipCarColors[playerid][1]); 
		
		DealershipCarColors[playerid][0] = color1;
		return ShowDealerAppend(playerid); 
	}
	else
	{
		new 
			dstr[128]
		;
			
		format(dstr, sizeof(dstr), "{FFFFFF}Color 1 ({%06x}%d{FFFFFF})\n", VehicleColoursTableRGBA[DealershipCarColors[playerid][0]] >>> 8, DealershipCarColors[playerid][0]);
		strcat(str, dstr);
				
		format(dstr, sizeof(dstr), "{FFFFFF}Color 2 ({%06x}%d{FFFFFF})\n", VehicleColoursTableRGBA[DealershipCarColors[playerid][1]] >>> 8, DealershipCarColors[playerid][1]);
		strcat(str, dstr);
				
		Dialog_Show(playerid, DealershipAppendCMenu, DIALOG_STYLE_LIST, caption, str, "Select", "<<"); 
	}
	return 1;
}

Dialog:DealershipAppendColor2(playerid, response, listitem, inputtext[])
{
	new
		caption[60],
		str[128],
		color2
	;
	
	format(caption, 60, "%s - {93C47D}%s:", g_aDealershipData[SubDealershipHolder[playerid]][E_DEALERSHIP_MODEL], FormatMoney(DealershipTotalCost[playerid])); 
	
	if(response)
	{
		if(!IsNumeric(inputtext))
		{
			format(str, sizeof(str), "{FFFFFF}You're selecting your vehicles second color. ({%06x}%d{FFFFFF})\n Please select a Color ID. (0-255)", VehicleColoursTableRGBA[DealershipCarColors[playerid][1]] >>> 8, DealershipCarColors[playerid][1]); 
			return Dialog_Show(playerid, DealershipAppendColor2, DIALOG_STYLE_INPUT, caption, str, "Select", "<<");  
		}
	
		color2 = strval(inputtext);
		
		if(color2 > 255 || color2 < 0)
		{
			format(str, sizeof(str), "{FFFFFF}You're selecting your vehicles second color. ({%06x}%d{FFFFFF})\n Please select a Color ID. (0-255)", VehicleColoursTableRGBA[DealershipCarColors[playerid][1]] >>> 8, DealershipCarColors[playerid][1]); 
			return Dialog_Show(playerid, DealershipAppendColor2, DIALOG_STYLE_INPUT, caption, str, "Select", "<<");  
		}
		
		ChangeVehicleColor(DealershipPlayerCar[playerid], DealershipCarColors[playerid][0], color2); 
		
		DealershipCarColors[playerid][1] = color2;
		return ShowDealerAppend(playerid); 
	}
	else
	{
		new 
			dstr[128]
		;
			
		format(dstr, sizeof(dstr), "{FFFFFF}Color 1 ({%06x}%d{FFFFFF})\n", VehicleColoursTableRGBA[DealershipCarColors[playerid][0]] >>> 8, DealershipCarColors[playerid][0]);
		strcat(str, dstr);
				
		format(dstr, sizeof(dstr), "{FFFFFF}Color 2 ({%06x}%d{FFFFFF})\n", VehicleColoursTableRGBA[DealershipCarColors[playerid][1]] >>> 8, DealershipCarColors[playerid][1]);
		strcat(str, dstr);
				
		Dialog_Show(playerid, DealershipAppendCMenu, DIALOG_STYLE_LIST, caption, str, "Select", "<<"); 
	}
	return 1;
}

Dialog:DealershipPurchase(playerid, response, listitem, inputtext[])
{
	if(response)
	{
		return ShowDealerAppend(playerid);
	}
	else
	{
		if(DealershipTotalCost[playerid] > PlayerInfo[playerid][E_CHARACTER_MONEY])
		{
			SendErrorMessage(playerid, "You can't afford the total price. (Price: $%s, Total:$%s)", FormatMoney(DealershipTotalCost[playerid]), FormatMoney(PlayerInfo[playerid][E_CHARACTER_MONEY]));
			
			DestroyVehicle(DealershipPlayerCar[playerid]);
			TogglePlayerControllable(playerid, true);
			return ResetDealershipVars(playerid);
		}
		
		new
			idx, 
			plates[32],
			randset[3],
			insert[256],
			Float:x,
			Float:y,
			Float:z,
			Float:a;
		
		for(new i = 1; i < MAX_PLAYER_VEHICLES; i++)
		{
			if(!PlayerInfo[playerid][E_CHARACTER_OWNEDVEHICLE][i])
			{
				idx = i;
				break;
			}
		}
		
		GetVehiclePos(DealershipPlayerCar[playerid], x, y, z);
		GetVehicleZAngle(DealershipPlayerCar[playerid], a);
		
		randset[0] = random(sizeof(possible_vehicle_plates)); 
		randset[1] = random(sizeof(possible_vehicle_plates)); 
		randset[2] = random(sizeof(possible_vehicle_plates)); 
		
		format(plates, 32, "%d%s%s%s%d%d%d", random(9), possible_vehicle_plates[randset[0]], possible_vehicle_plates[randset[1]], possible_vehicle_plates[randset[2]], random(9), random(9)); 
		GiveMoney(playerid, -DealershipTotalCost[playerid]);
		
		ShowPlayerPlates(playerid, plates); 
		
		mysql_format(ourConnection, insert, sizeof(insert), "INSERT INTO vehicles (VehicleOwnerDBID, VehicleModel, VehicleParkPosX, VehicleParkPosY, VehicleParkPosZ, VehicleParkPosA) VALUES(%i, %i, %f, %f, %f, %f)",
			PlayerInfo[playerid][E_CHARACTER_DBID], g_aDealershipData[SubDealershipHolder[playerid]][E_DEALERSHIP_MODELID], x, y, z, a); 
			
		mysql_pquery(ourConnection, insert, "OnPlayerVehiclePurchase", "iisffff", playerid, idx, plates, x, y, z, a);
		
		PlayerPurchasingVehicle[playerid] = true; 
		TogglePlayerControllable(playerid, true);
	}
	return 1;
}