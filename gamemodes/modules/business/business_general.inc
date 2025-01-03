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
				format(str, sizeof(str), "%s:", BusinessInfo[IsPlayerInBusiness(playerid)][E_BUSINESS_NAME]);
				format(str2, sizeof(str2), "Product\tPrice\n");
				format(str2, sizeof(str2), "%sSpraycan\t$%s\n", str2, FormatMoney(BusinessInfo[businessid][E_BUSINESS_PRODUCTS][1]));
				format(str2, sizeof(str2), "%sGascan\t$%s\n", str2, FormatMoney(BusinessInfo[businessid][E_BUSINESS_PRODUCTS][2]));
				format(str2, sizeof(str2), "%sRepairkit\t$%s\n", str2, FormatMoney(BusinessInfo[businessid][E_BUSINESS_PRODUCTS][3]));
				format(str2, sizeof(str2), "%sScrewdriver\t$%s\n", str2, FormatMoney(BusinessInfo[businessid][E_BUSINESS_PRODUCTS][4]));
				Dialog_Show(playerid, DialogGeneral4, DIALOG_STYLE_TABLIST_HEADERS, str, str2, "Select", "Cancel"); 
			}
		}
		case 2: //Cellphone & Radio
		{
			if(IsPlayerInBusiness(playerid))
			{	
				format(str, sizeof(str), "%s:", BusinessInfo[IsPlayerInBusiness(playerid)][E_BUSINESS_NAME]);
				format(str2, sizeof(str2), "Product\tPrice\n");
				format(str2, sizeof(str2), "%sCellphone\t$%s\n", str2, FormatMoney(BusinessInfo[businessid][E_BUSINESS_PRODUCTS][1]));
				format(str2, sizeof(str2), "%sRadio\t$%s\n", str2, FormatMoney(BusinessInfo[businessid][E_BUSINESS_PRODUCTS][2]));
				format(str2, sizeof(str2), "%sBoombox\t$%s\n", str2, FormatMoney(BusinessInfo[businessid][E_BUSINESS_PRODUCTS][3]));
				Dialog_Show(playerid, DialogGeneral1, DIALOG_STYLE_TABLIST_HEADERS, str, str2, "Select", "Cancel"); 
			}
		}
		case 3: //Baseball
		{
			if(IsPlayerInBusiness(playerid))
			{	
				format(str, sizeof(str), "%s:", BusinessInfo[IsPlayerInBusiness(playerid)][E_BUSINESS_NAME]);
				format(str2, sizeof(str2), "Product\tPrice\n");
				format(str2, sizeof(str2), "%sSpike Bat\t$%s\n", str2, FormatMoney(BusinessInfo[businessid][E_BUSINESS_PRODUCTS][1]));
				format(str2, sizeof(str2), "%sWooden\t$%s\n", str2, FormatMoney(BusinessInfo[businessid][E_BUSINESS_PRODUCTS][2]));
				format(str2, sizeof(str2), "%sBaseball Bat\t$%s\n", str2, FormatMoney(BusinessInfo[businessid][E_BUSINESS_PRODUCTS][3]));
				Dialog_Show(playerid, DialogGeneral2, DIALOG_STYLE_TABLIST_HEADERS, str, str2, "Select", "Cancel"); 
			}
		}
		case 4: //Raw Meat
		{
			if(IsPlayerInBusiness(playerid))
			{	
				format(str, sizeof(str), "%s:", BusinessInfo[IsPlayerInBusiness(playerid)][E_BUSINESS_NAME]);
				format(str2, sizeof(str2), "Product\tPrice\n");
				format(str2, sizeof(str2), "%sRaw Meat\t$%s\n", str2, FormatMoney(BusinessInfo[businessid][E_BUSINESS_PRODUCTS][1]));
				format(str2, sizeof(str2), "%sParsley\t$%s\n", str2, FormatMoney(BusinessInfo[businessid][E_BUSINESS_PRODUCTS][2]));
				format(str2, sizeof(str2), "%sMint\t$%s\n", str2, FormatMoney(BusinessInfo[businessid][E_BUSINESS_PRODUCTS][3]));
				format(str2, sizeof(str2), "%sOregano\t$%s\n", str2, FormatMoney(BusinessInfo[businessid][E_BUSINESS_PRODUCTS][4]));
				format(str2, sizeof(str2), "%sBaking Soda\t$%s\n", str2, FormatMoney(BusinessInfo[businessid][E_BUSINESS_PRODUCTS][5]));
				Dialog_Show(playerid, DialogGeneral3, DIALOG_STYLE_TABLIST_HEADERS, str, str2, "Select", "Cancel"); 
			}
		}
		case 5: //Sprunk
		{
			if(IsPlayerInBusiness(playerid))
			{	
				format(str, sizeof(str), "%s:", BusinessInfo[IsPlayerInBusiness(playerid)][E_BUSINESS_NAME]);
				Dialog_Show(playerid, DialogGeneral5, DIALOG_STYLE_TABLIST_HEADERS, str, "Product\tPrice\nSprunk\t$2.00\nPisswasher\t$5.00", "Select", "Cancel"); 
			}
		}
		case 6: //Knife
		{
			if(IsPlayerInBusiness(playerid))
			{	
				format(str, sizeof(str), "%s:", BusinessInfo[IsPlayerInBusiness(playerid)][E_BUSINESS_NAME]);
				format(str2, sizeof(str2), "Product\tPrice\n");
				format(str2, sizeof(str2), "%sKnife\t$%s\n", str2, FormatMoney(BusinessInfo[businessid][E_BUSINESS_PRODUCTS][1]));
				format(str2, sizeof(str2), "%sMarcos Knife\t$%s\n", str2, FormatMoney(BusinessInfo[businessid][E_BUSINESS_PRODUCTS][2]));
				format(str2, sizeof(str2), "%sHammer\t$%s\n", str2, FormatMoney(BusinessInfo[businessid][E_BUSINESS_PRODUCTS][3]));
				format(str2, sizeof(str2), "%sWrench\t$%s\n", str2, FormatMoney(BusinessInfo[businessid][E_BUSINESS_PRODUCTS][4]));
				format(str2, sizeof(str2), "%sBroom\t$%s\n", str2, FormatMoney(BusinessInfo[businessid][E_BUSINESS_PRODUCTS][5]));
				Dialog_Show(playerid, DialogGeneral6, DIALOG_STYLE_TABLIST_HEADERS, str, str2, "Select", "Cancel"); 
			}
		}
		case 7: //Glove
		{
			if(IsPlayerInBusiness(playerid))
			{	
				format(str, sizeof(str), "%s:", BusinessInfo[IsPlayerInBusiness(playerid)][E_BUSINESS_NAME]);
				format(str2, sizeof(str2), "Product\tPrice\n");
				format(str2, sizeof(str2), "%sGlove\t$%s\n", str2, FormatMoney(BusinessInfo[businessid][E_BUSINESS_PRODUCTS][1]));
				Dialog_Show(playerid, DialogGeneral7, DIALOG_STYLE_TABLIST_HEADERS, str, str2, "Select", "Cancel"); 
			}
		}
	}
	return 1;
}