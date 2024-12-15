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
					ShowPlayerDialog(playerid, DIALOG_GENERALSTORE4, DIALOG_STYLE_TABLIST_HEADERS, str, str2, "Select", "Cancel"); 
				}
			}
		}
		case 2: //Cellphone & Radio
		{
			if(IsPlayerInBusiness(playerid))
			{	
				if(IsPlayerInRangeOfPoint(playerid, 2.0, -51.4530,5.4811,203.2633))
				{
					format(str, sizeof(str), "%s:", BusinessInfo[IsPlayerInBusiness(playerid)][E_BUSINESS_NAME]);
                    format(str2, sizeof(str2), "Product\tPrice\n");
                    format(str2, sizeof(str2), "%sCellphone\t$%s\n", str2, FormatMoney(BusinessInfo[businessid][E_BUSINESS_PRODUCTS][1]));
                    format(str2, sizeof(str2), "%sRadio\t$%s\n", str2, FormatMoney(BusinessInfo[businessid][E_BUSINESS_PRODUCTS][2]));
                    format(str2, sizeof(str2), "%sGascan\t$%s\n", str2, FormatMoney(BusinessInfo[businessid][E_BUSINESS_PRODUCTS][3]));
                    format(str2, sizeof(str2), "%sRepairkit\t$%s\n", str2, FormatMoney(BusinessInfo[businessid][E_BUSINESS_PRODUCTS][1]));
					ShowPlayerDialog(playerid, DIALOG_GENERALSTORE1, DIALOG_STYLE_TABLIST_HEADERS, str, str2, "Select", "Cancel"); 
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
					ShowPlayerDialog(playerid, DIALOG_GENERALSTORE2, DIALOG_STYLE_TABLIST_HEADERS, str, str2, "Select", "Cancel"); 
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
					ShowPlayerDialog(playerid, DIALOG_GENERALSTORE3, DIALOG_STYLE_TABLIST_HEADERS, str, str2, "Select", "Cancel"); 
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
					ShowPlayerDialog(playerid, DIALOG_GENERALSTORE5, DIALOG_STYLE_TABLIST_HEADERS, str, "Product\tPrice\nSprunk\t$2", "Select", "Cancel"); 
				}
			}
		}
	}
	return 1;
}