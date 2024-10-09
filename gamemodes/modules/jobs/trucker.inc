CMD:cargobuy(playerid, params[])
{
	if(PlayerInfo[playerid][E_CHARACTER_JOBS] != JOB_TRUCKER)
        return SendErrorMessage(playerid, "You aren't truckers.");

	if(IsPlayerInRangeOfPoint(playerid, 3.0, IndustryInfo[0][Posx], IndustryInfo[0][Posy], IndustryInfo[0][Posz]) || IsPlayerInRangeOfPoint(playerid, 3.0, IndustryInfo[1][Posx], IndustryInfo[1][Posy], IndustryInfo[1][Posz])) //products
	{
		if(Inventory_Count(playerid, "Woods Cargo") || Inventory_Count(playerid, "Tools Cargo") || Inventory_Count(playerid, "Clothes Cargo") || Inventory_Count(playerid, "Products Cargo"))
			return SendErrorMessage(playerid, "You are already carrying your cargo.");

		if(!ServerInfo[0][E_SERVER_PRODUCTS])
			return SendErrorMessage(playerid, "This cargo storage is out of stock.");

		Inventory_Add(playerid, "Products Cargo", 2912, 1);
		SetPlayerSpecialAction(playerid, SPECIAL_ACTION_CARRY);
		SetPlayerAttachedObject(playerid, ATTACH_CARGO, 2912, 1, -0.019, 0.713999, -0.076, 0, 87.1, -9.4, 1.0000, 1.0000, 1.0000);
		GiveMoney(playerid, -PRICE_PRODUCTS);

		ServerData_Minus(INDUSTRY_PRODUCTS, 1);

		SendClientMessageEx(playerid, COLOR_JOBS, "[Jobs]:{d7d7d7} You has purchase products cargo for %s.", FormatMoney(PRICE_PRODUCTS));
	}
	if(IsPlayerInRangeOfPoint(playerid, 3.0, IndustryInfo[2][Posx], IndustryInfo[2][Posy], IndustryInfo[2][Posz])) //woods
	{
		if(Inventory_Count(playerid, "Woods Cargo") || Inventory_Count(playerid, "Tools Cargo") || Inventory_Count(playerid, "Clothes Cargo") || Inventory_Count(playerid, "Products Cargo"))
			return SendErrorMessage(playerid, "You are already carrying your cargo.");

		if(!ServerInfo[0][E_SERVER_WOODS])
			return SendErrorMessage(playerid, "This cargo storage is out of stock.");

		Inventory_Add(playerid, "Woods Cargo", 2912, 1);
		SetPlayerSpecialAction(playerid, SPECIAL_ACTION_CARRY);
		SetPlayerAttachedObject(playerid, ATTACH_CARGO, 2912, 1, -0.019, 0.713999, -0.076, 0, 87.1, -9.4, 1.0000, 1.0000, 1.0000);
		GiveMoney(playerid, -PRICE_WOODS);

		ServerData_Minus(INDUSTRY_WOODS, 1);

		SendClientMessageEx(playerid, COLOR_JOBS, "[Jobs]:{d7d7d7} You has purchase products cargo for %s.", FormatMoney(PRICE_WOODS));
	}
	return 1;
}

CMD:cargosell(playerid, params[])
{
	new id;
	if(PlayerInfo[playerid][E_CHARACTER_JOBS] != JOB_TRUCKER)
        return SendErrorMessage(playerid, "You aren't truckers.");

	if((id = IsPlayerNearBusiness(playerid)) != 0) //Products
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

	else if(IsPlayerInRangeOfPoint(playerid, 3.0, IndustryInfo[0][Posx], IndustryInfo[0][Posy], IndustryInfo[0][Posz]) || IsPlayerInRangeOfPoint(playerid, 3.0, IndustryInfo[1][Posx], IndustryInfo[1][Posy], IndustryInfo[1][Posz])) //products
	{
		if(!Inventory_Count(playerid, "Woods Cargo"))
			return SendErrorMessage(playerid, "You are not carrying your cargo.");

		if(!ServerInfo[0][E_SERVER_PRODUCTS] >= 100)
			return SendErrorMessage(playerid, "This cargo storage is full of stock.");

		Inventory_Remove(playerid, "Woods Cargo", 1);
		SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
		RemovePlayerAttachedObject(playerid, 7);
		GiveMoney(playerid, PRICE_WOODS*5);

		ServerData_Plus(INDUSTRY_PRODUCTS, 1);
		
		SendClientMessageEx(playerid, COLOR_JOBS, "[Jobs]:{d7d7d7} You has sell woods cargo for %s into oceandocks ships.", FormatMoney(PRICE_WOODS*5));
	}
	return 1;
}

CMD:cargodrop(playerid, params[])
{
	if(PlayerInfo[playerid][E_CHARACTER_JOBS] != JOB_TRUCKER)
        return SendErrorMessage(playerid, "You aren't truckers.");

	if(!Inventory_Count(playerid, "Products Cargo"))
		return SendErrorMessage(playerid, "You are not carrying your cargo.");

	Inventory_Remove(playerid, "Products Cargo", 1);
	SendClientMessageEx(playerid, COLOR_JOBS, "[Jobs]:{d7d7d7} You has dropped products cargo in your inventory.");
	return 1;
}

CMD:tpda(playerid, params[])
{
    if(PlayerInfo[playerid][E_CHARACTER_JOBS] != JOB_TRUCKER)
        return SendErrorMessage(playerid, "You aren't truckers.");

    ShowPlayerDialog(playerid, DIALOG_INDUSTRY, DIALOG_STYLE_LIST, "Truck PDA:", "Show Oceandocks Information\nShow All Industry\nShow Business Request Shipments", "Select", "Cancel");
    return 1;
}