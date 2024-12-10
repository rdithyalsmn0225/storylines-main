stock ShowGeneralList(playerid, type)
{
    new businessid = IsPlayerInBusiness(playerid);
	if(BusinessInfo[businessid][E_BUSINESS_STOCK] < 1)
		return SendErrorMessage(playerid, "This business is out of stock"); 

	new str[128], str2[128];

	switch(type)
	{
		case 0:
		{
			//unused
		}
		case 1: //Spraycan & Crowbar
		{
			if(IsPlayerInBusiness(playerid))
			{	
				if(IsPlayerInRangeOfPoint(playerid, 2.0, -48.1108,5.5907,203.2633))
				{
					format(str, sizeof(str), "%s:", BusinessInfo[IsPlayerInBusiness(playerid)][E_BUSINESS_NAME]);
                    format(str2, sizeof(str2), "Product\tPrice\n");
                    format(str2, sizeof(str2), "%sSpraycan\t$%s\n", str2, FormatMoney(BusinessInfo[businessid][E_BUSINESS_PRODUCTS][1]));
                    format(str2, sizeof(str2), "%sCrowbar\t$%s\n", str2, FormatMoney(BusinessInfo[businessid][E_BUSINESS_PRODUCTS][2]));
					Dialog_Show(playerid, GeneralStore4, DIALOG_STYLE_TABLIST_HEADERS, str, str2, "Select", "Cancel"); 
				}
			}
		}
		case 2: //Cellphone & Portable Radio
		{
			if(IsPlayerInBusiness(playerid))
			{	
				if(IsPlayerInRangeOfPoint(playerid, 2.0, -51.4530,5.4811,203.2633))
				{
					format(str, sizeof(str), "%s:", BusinessInfo[IsPlayerInBusiness(playerid)][E_BUSINESS_NAME]);
                    format(str2, sizeof(str2), "Product\tPrice\n");
                    format(str2, sizeof(str2), "%sCellphone\t$%s\n", str2, FormatMoney(BusinessInfo[businessid][E_BUSINESS_PRODUCTS][1]));
                    format(str2, sizeof(str2), "%sPortable Radio\t$%s\n", str2, FormatMoney(BusinessInfo[businessid][E_BUSINESS_PRODUCTS][2]));
                    format(str2, sizeof(str2), "%sGascan\t$%s\n", str2, FormatMoney(BusinessInfo[businessid][E_BUSINESS_PRODUCTS][3]));
                    format(str2, sizeof(str2), "%sRepairkit\t$%s\n", str2, FormatMoney(BusinessInfo[businessid][E_BUSINESS_PRODUCTS][1]));
					Dialog_Show(playerid, GeneralStore1, DIALOG_STYLE_TABLIST_HEADERS, str, str2, "Select", "Cancel"); 
				}
			}
		}
		case 3: //Baseball
		{
			if(IsPlayerInBusiness(playerid))
			{	
				if(IsPlayerInRangeOfPoint(playerid, 2.0, -53.7646,5.2118,203.2633))
				{
					format(str, sizeof(str), "%s:", BusinessInfo[IsPlayerInBusiness(playerid)][E_BUSINESS_NAME]);
                    format(str2, sizeof(str2), "Product\tPrice\n");
                    format(str2, sizeof(str2), "%sSpike Bat\t$%s\n", str2, FormatMoney(BusinessInfo[businessid][E_BUSINESS_PRODUCTS][1]));
                    format(str2, sizeof(str2), "%sWooden\t$%s\n", str2, FormatMoney(BusinessInfo[businessid][E_BUSINESS_PRODUCTS][2]));
                    format(str2, sizeof(str2), "%sBaseball Bat\t$%s\n", str2, FormatMoney(BusinessInfo[businessid][E_BUSINESS_PRODUCTS][3]));
					Dialog_Show(playerid, GeneralStore2, DIALOG_STYLE_TABLIST_HEADERS, str, str2, "Select", "Cancel"); 
				}
			}
		}
		case 4: //Raw Meat
		{
			if(IsPlayerInBusiness(playerid))
			{	
				if(IsPlayerInRangeOfPoint(playerid, 2.0, -48.4748,-1.1597,203.2633))
				{
					format(str, sizeof(str), "%s:", BusinessInfo[IsPlayerInBusiness(playerid)][E_BUSINESS_NAME]);
                    format(str2, sizeof(str2), "Product\tPrice\n");
                    format(str2, sizeof(str2), "%sRaw Meat\t$%s\n", str2, FormatMoney(BusinessInfo[businessid][E_BUSINESS_PRODUCTS][1]));
                    format(str2, sizeof(str2), "%sParsley\t$%s\n", str2, FormatMoney(BusinessInfo[businessid][E_BUSINESS_PRODUCTS][2]));
                    format(str2, sizeof(str2), "%sMint\t$%s\n", str2, FormatMoney(BusinessInfo[businessid][E_BUSINESS_PRODUCTS][3]));
                    format(str2, sizeof(str2), "%sOregano\t$%s\n", str2, FormatMoney(BusinessInfo[businessid][E_BUSINESS_PRODUCTS][1]));
                    format(str2, sizeof(str2), "%sBaking Soda\t$%s\n", str2, FormatMoney(BusinessInfo[businessid][E_BUSINESS_PRODUCTS][2]));
					Dialog_Show(playerid, GeneralStore3, DIALOG_STYLE_TABLIST_HEADERS, str, str2, "Select", "Cancel"); 
				}
			}
		}
		case 5: //Sprunk
		{
			if(IsPlayerInBusiness(playerid))
			{	
				if(IsPlayerInRangeOfPoint(playerid, 2.0, -53.7980,2.8393,203.2633))
				{
					format(str, sizeof(str), "%s:", BusinessInfo[IsPlayerInBusiness(playerid)][E_BUSINESS_NAME]);
					Dialog_Show(playerid, GeneralStore5, DIALOG_STYLE_TABLIST_HEADERS, str, "Product\tPrice\nSprunk\t$2", "Select", "Cancel"); 
				}
			}
		}
	}
	return 1;
}

Dialog:GeneralStore1(playerid, response, listitem, inputtext[])
{
    if(response)
    {
        new businessid = IsPlayerInBusiness(playerid);
        switch(listitem)
        {
            case 0:
            {
                if(Inventory_Count(playerid, "Cellphone"))
                    return SendErrorMessage(playerid, "You already own a cellphone.");
            
                if(BusinessInfo[businessid][E_BUSINESS_PRODUCTS][1] > PlayerInfo[playerid][E_CHARACTER_MONEY])
                    return SendErrorMessage(playerid, "You can't afford a cellphone.");
            
                SendPropertyMessage(playerid, "[Business] {DEDEDE}You bought a cellphone for $%s.", FormatMoney(BusinessInfo[businessid][E_BUSINESS_PRODUCTS][1]));

                PlayerInfo[playerid][E_CHARACTER_PURCHASE] += BusinessInfo[businessid][E_BUSINESS_PRODUCTS][1];
                BusinessInfo[businessid][E_BUSINESS_STOCK]--;
                Inventory_Add(playerid, "Cellphone", 18867, 1);

                ApplyAnimation(playerid, "MISC", "GRAB_R", 4.1, 0, 0, 0, 0, 0, 0);
            }
            case 1:
            {
                if(Inventory_Count(playerid, "Portable Radio"))
                    return SendErrorMessage(playerid, "You already own a radio.");
            
                if(BusinessInfo[businessid][E_BUSINESS_PRODUCTS][2] > PlayerInfo[playerid][E_CHARACTER_MONEY])
                    return SendErrorMessage(playerid, "You can't afford a radio.");
            
                SendPropertyMessage(playerid, "[Business] {DEDEDE}You bought a radio for $%s.", FormatMoney(BusinessInfo[businessid][E_BUSINESS_PRODUCTS][2]));

                PlayerInfo[playerid][E_CHARACTER_PURCHASE] += BusinessInfo[businessid][E_BUSINESS_PRODUCTS][2];
                BusinessInfo[businessid][E_BUSINESS_STOCK]--;
                Inventory_Add(playerid, "Portable Radio", 19942, 1);

                ApplyAnimation(playerid, "MISC", "GRAB_R", 4.1, 0, 0, 0, 0, 0, 0);
            }
            case 2:
            {
                if(Inventory_Count(playerid, "Gascan") >= 5)
                    return SendErrorMessage(playerid, "You may only hold up to 5 gasoline cans.");
                    
                if(BusinessInfo[businessid][E_BUSINESS_PRODUCTS][3] > PlayerInfo[playerid][E_CHARACTER_MONEY])
                    return SendErrorMessage(playerid, "You can't afford a gasoline.");
            
                SendPropertyMessage(playerid, "[Business] {DEDEDE}You bought a gasoline for $%s.", FormatMoney(BusinessInfo[businessid][E_BUSINESS_PRODUCTS][3]));

                PlayerInfo[playerid][E_CHARACTER_PURCHASE] += BusinessInfo[businessid][E_BUSINESS_PRODUCTS][3];
                BusinessInfo[businessid][E_BUSINESS_STOCK]--;
                Inventory_Add(playerid, "Gascan", 1650, 1);

                ApplyAnimation(playerid, "MISC", "GRAB_R", 4.1, 0, 0, 0, 0, 0, 0);
            }
            case 3:
            {
                if(Inventory_Count(playerid, "Repair Kits"))
                    return SendErrorMessage(playerid, "You already own a repairkit.");
                    
                if(BusinessInfo[businessid][E_BUSINESS_PRODUCTS][1] > PlayerInfo[playerid][E_CHARACTER_MONEY])
                    return SendErrorMessage(playerid, "You can't afford a repairkit.");
            
                SendPropertyMessage(playerid, "[Business] {DEDEDE}You bought a repairkit for $%s.", FormatMoney(BusinessInfo[businessid][E_BUSINESS_PRODUCTS][1]));

                PlayerInfo[playerid][E_CHARACTER_PURCHASE] += BusinessInfo[businessid][E_BUSINESS_PRODUCTS][1];
                BusinessInfo[businessid][E_BUSINESS_STOCK]--;
                Inventory_Add(playerid, "Repair Kits", 1650, 1);

                ApplyAnimation(playerid, "MISC", "GRAB_R", 4.1, 0, 0, 0, 0, 0, 0);
            }
        }
    }
    return 1;
}

Dialog:GeneralStore2(playerid, response, listitem, inputtext[])
{
    if(response)
    {
        new businessid = IsPlayerInBusiness(playerid);
        switch(listitem)
        {
            case 0:
            {
                if(Inventory_Count(playerid, "Spike Bat"))
                    return SendErrorMessage(playerid, "You already own a spikebat.");
            
                if(BusinessInfo[businessid][E_BUSINESS_PRODUCTS][1] > PlayerInfo[playerid][E_CHARACTER_MONEY])
                    return SendErrorMessage(playerid, "You can't afford a spikebat.");
            
                SendPropertyMessage(playerid, "[Business] {DEDEDE}You bought a spikebat for $%s.", FormatMoney(BusinessInfo[businessid][E_BUSINESS_PRODUCTS][1]));

                PlayerInfo[playerid][E_CHARACTER_PURCHASE] += BusinessInfo[businessid][E_BUSINESS_PRODUCTS][1];

                BusinessInfo[businessid][E_BUSINESS_STOCK]--;
                Inventory_Add(playerid, "Spike Bat", -2200, 1);

                ApplyAnimation(playerid, "MISC", "GRAB_R", 4.1, 0, 0, 0, 0, 0, 0);
            }
            case 1:
            {
                if(Inventory_Count(playerid, "Cutscene Bat"))
                    return SendErrorMessage(playerid, "You already own a wooden.");
            
                if(BusinessInfo[businessid][E_BUSINESS_PRODUCTS][2] > PlayerInfo[playerid][E_CHARACTER_MONEY])
                    return SendErrorMessage(playerid, "You can't afford a wooden.");
            
                SendPropertyMessage(playerid, "[Business] {DEDEDE}You bought a wooden for $%s.", FormatMoney(BusinessInfo[businessid][E_BUSINESS_PRODUCTS][2]));

                PlayerInfo[playerid][E_CHARACTER_PURCHASE] += BusinessInfo[businessid][E_BUSINESS_PRODUCTS][2];
                BusinessInfo[businessid][E_BUSINESS_STOCK]--;
                Inventory_Add(playerid, "Cutscene Bat", -2201, 1);

                ApplyAnimation(playerid, "MISC", "GRAB_R", 4.1, 0, 0, 0, 0, 0, 0);
            }
            case 2:
            {
                if(Inventory_Count(playerid, "Baseball Bat"))
                    return SendErrorMessage(playerid, "You already own a nailbat.");
            
                if(BusinessInfo[businessid][E_BUSINESS_PRODUCTS][3] > PlayerInfo[playerid][E_CHARACTER_MONEY])
                    return SendErrorMessage(playerid, "You can't afford a nailbat.");
            
                SendPropertyMessage(playerid, "[Business] {DEDEDE}You bought a nailbat for $%s.", FormatMoney(BusinessInfo[businessid][E_BUSINESS_PRODUCTS][3]));

                PlayerInfo[playerid][E_CHARACTER_PURCHASE] += BusinessInfo[businessid][E_BUSINESS_PRODUCTS][3];
                BusinessInfo[businessid][E_BUSINESS_STOCK]--;
                Inventory_Add(playerid, "Baseball Bat", -2202, 1);

                ApplyAnimation(playerid, "MISC", "GRAB_R", 4.1, 0, 0, 0, 0, 0, 0);
            }
        }
    }
    return 1;
}

Dialog:GeneralStore3(playerid, response, listitem, inputtext[])
{
    if(response)
    {
        new businessid = IsPlayerInBusiness(playerid);
        switch(listitem)
        {
            case 0:
            {
                if(Inventory_Count(playerid, "Raw Meat"))
                    return SendErrorMessage(playerid, "You already own a raw meat.");
            
                if(BusinessInfo[businessid][E_BUSINESS_PRODUCTS][1] > PlayerInfo[playerid][E_CHARACTER_MONEY])
                    return SendErrorMessage(playerid, "You can't afford a raw meat.");
            
                SendPropertyMessage(playerid, "[Business] {DEDEDE}You bought a raw meat for $%s.", FormatMoney(BusinessInfo[businessid][E_BUSINESS_PRODUCTS][1]));

                PlayerInfo[playerid][E_CHARACTER_PURCHASE] += BusinessInfo[businessid][E_BUSINESS_PRODUCTS][1];
                BusinessInfo[businessid][E_BUSINESS_STOCK]--;
                Inventory_Add(playerid, "Raw Meat", 19582, 1);

                ApplyAnimation(playerid, "MISC", "GRAB_R", 4.1, 0, 0, 0, 0, 0, 0);
            }
            case 1:
            {
                if(Inventory_Count(playerid, "Parsley") >= 5)
                    return SendErrorMessage(playerid, "You may only hold up to 5 parsley.");
            
                if(BusinessInfo[businessid][E_BUSINESS_PRODUCTS][2] > PlayerInfo[playerid][E_CHARACTER_MONEY])
                    return SendErrorMessage(playerid, "You can't afford a parsley.");
            
                SendPropertyMessage(playerid, "[Business] {DEDEDE}You bought a parsley for $%s.", FormatMoney(BusinessInfo[businessid][E_BUSINESS_PRODUCTS][2]));

                PlayerInfo[playerid][E_CHARACTER_PURCHASE] += BusinessInfo[businessid][E_BUSINESS_PRODUCTS][2];
                BusinessInfo[businessid][E_BUSINESS_STOCK]--;
                Inventory_Add(playerid, "Parsley", 2244, 1);

                ApplyAnimation(playerid, "MISC", "GRAB_R", 4.1, 0, 0, 0, 0, 0, 0);
            }
            case 2:
            {
                if(Inventory_Count(playerid, "Mint") >= 5)	
                    return SendErrorMessage(playerid, "You may only hold up to 5 mint.");
            
                if(BusinessInfo[businessid][E_BUSINESS_PRODUCTS][3] > PlayerInfo[playerid][E_CHARACTER_MONEY])
                    return SendErrorMessage(playerid, "You can't afford a mint.");
            
                SendPropertyMessage(playerid, "[Business] {DEDEDE}You bought a mint for $%s.", FormatMoney(BusinessInfo[businessid][E_BUSINESS_PRODUCTS][3]));

                PlayerInfo[playerid][E_CHARACTER_PURCHASE] += BusinessInfo[businessid][E_BUSINESS_PRODUCTS][3];
                BusinessInfo[businessid][E_BUSINESS_STOCK]--;
                Inventory_Add(playerid, "Mint", 19570, 1);

                ApplyAnimation(playerid, "MISC", "GRAB_R", 4.1, 0, 0, 0, 0, 0, 0);
            }
            case 3:
            {
                if(Inventory_Count(playerid, "Oregano") >= 5)
                    return SendErrorMessage(playerid, "You may only hold up to 5 oregano.");
            
                if(BusinessInfo[businessid][E_BUSINESS_PRODUCTS][1] > PlayerInfo[playerid][E_CHARACTER_MONEY])
                    return SendErrorMessage(playerid, "You can't afford a oregano.");
            
                SendPropertyMessage(playerid, "[Business] {DEDEDE}You bought a oregano for $%s.", FormatMoney(BusinessInfo[businessid][E_BUSINESS_PRODUCTS][1]));

                PlayerInfo[playerid][E_CHARACTER_PURCHASE] += BusinessInfo[businessid][E_BUSINESS_PRODUCTS][1];
                BusinessInfo[businessid][E_BUSINESS_STOCK]--;
                Inventory_Add(playerid, "Oregano", 19570, 1);

                ApplyAnimation(playerid, "MISC", "GRAB_R", 4.1, 0, 0, 0, 0, 0, 0);
            }
            case 4:
            {
                if(Inventory_Count(playerid, "Baking Soda") >= 5)	
                    return SendErrorMessage(playerid, "You may only hold up to 5 baking soda.");
            
                if(BusinessInfo[businessid][E_BUSINESS_PRODUCTS][2] > PlayerInfo[playerid][E_CHARACTER_MONEY])
                    return SendErrorMessage(playerid, "You can't afford a baking soda.");
            
                SendPropertyMessage(playerid, "[Business] {DEDEDE}You bought a baking soda for $%s.", FormatMoney(BusinessInfo[businessid][E_BUSINESS_PRODUCTS][2]));

                PlayerInfo[playerid][E_CHARACTER_PURCHASE] += BusinessInfo[businessid][E_BUSINESS_PRODUCTS][2];
                BusinessInfo[businessid][E_BUSINESS_STOCK]--;
                
                Inventory_Add(playerid, "Baking Soda", 19570, 1);

                ApplyAnimation(playerid, "MISC", "GRAB_R", 4.1, 0, 0, 0, 0, 0, 0);
            }
        }
    }
    return 1;
}

Dialog:GeneralStore4(playerid, response, listitem, inputtext[])
{
    if(response)
    {
        new businessid = IsPlayerInBusiness(playerid);
        switch(listitem)
        {
            case 0:
            {
                if(Inventory_Count(playerid, "Spraycan") >= 5)	
                    return SendErrorMessage(playerid, "You may only hold up to 5 spraycan.");
            
                if(BusinessInfo[businessid][E_BUSINESS_PRODUCTS][1] > PlayerInfo[playerid][E_CHARACTER_MONEY])
                    return SendErrorMessage(playerid, "You can't afford a spraycan.");
            
                SendPropertyMessage(playerid, "[Business] {DEDEDE}You bought a spraycan for $%s.", FormatMoney(BusinessInfo[businessid][E_BUSINESS_PRODUCTS][1]));

                PlayerInfo[playerid][E_CHARACTER_PURCHASE] += BusinessInfo[businessid][E_BUSINESS_PRODUCTS][1];

                PlayerInfo[playerid][E_CHARACTER_PURCHASE] += 250; 
                BusinessInfo[businessid][E_BUSINESS_STOCK]--;
                Inventory_Add(playerid, "Spraycan", 365, 1);

                ApplyAnimation(playerid, "MISC", "GRAB_R", 4.1, 0, 0, 0, 0, 0, 0);
            }
            case 1:
            {
                if(Inventory_Count(playerid, "Marcos Knife") >= 1)		
                    return SendErrorMessage(playerid, "You may only hold up to 1 crowbar.");
            
                if(BusinessInfo[businessid][E_BUSINESS_PRODUCTS][2] > PlayerInfo[playerid][E_CHARACTER_MONEY])
                    return SendErrorMessage(playerid, "You can't afford a crowbar.");
            
                SendPropertyMessage(playerid, "[Business] {DEDEDE}You bought a crowbar for $%s.", FormatMoney(BusinessInfo[businessid][E_BUSINESS_PRODUCTS][2]));

                PlayerInfo[playerid][E_CHARACTER_PURCHASE] += BusinessInfo[businessid][E_BUSINESS_PRODUCTS][2];
                BusinessInfo[businessid][E_BUSINESS_STOCK]--;
                Inventory_Add(playerid, "Marcos Knife", 18634, 1);

                ApplyAnimation(playerid, "MISC", "GRAB_R", 4.1, 0, 0, 0, 0, 0, 0);
            }
        }
    }
    return 1;
}

Dialog:GeneralStore5(playerid, response, listitem, inputtext[])
{
    if(response)
    {
        new businessid = IsPlayerInBusiness(playerid);
        switch(listitem)
        {
            case 0:
            {
                if(Inventory_Count(playerid, "Spraycan") >= 5)	
                    return SendErrorMessage(playerid, "You may only hold up to 5 sprunk.");
            
                if(2 > PlayerInfo[playerid][E_CHARACTER_MONEY])
                    return SendErrorMessage(playerid, "You can't afford a sprunk.");
            
                SendPropertyMessage(playerid, "[Business] {DEDEDE}You bought a sprunk for $2.");

                PlayerInfo[playerid][E_CHARACTER_PURCHASE] += 5; 
                BusinessInfo[businessid][E_BUSINESS_STOCK]--;
                Inventory_Add(playerid, "Sprunk", 2601, 1);

                ApplyAnimation(playerid, "MISC", "GRAB_R", 4.1, 0, 0, 0, 0, 0, 0);
            }
        }
    }
    return 1;
}