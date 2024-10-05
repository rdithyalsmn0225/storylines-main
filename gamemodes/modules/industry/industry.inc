enum
{
    INDUSTRY_PRODUCTS,
    INDUSTRY_CRATES,
    INDUSTRY_FOODS,
    INDUSTRY_CLOTHES,
    INDUSTRY_TOOLS
};

stock IndustryRefresh(id)
{
    new str[512], str1[512];
	if(IsValidDynamic3DTextLabel(ServerInfo[id][E_SERVER_3DTEXT]))
    	DestroyDynamic3DTextLabel(ServerInfo[id][E_SERVER_3DTEXT]);

    format(str, sizeof(str), "%s\n{ffffff}Available stock: %d", IndustryInfo[0][Name], ServerInfo[id][E_SERVER_PRODUCTS]);
    format(str1, sizeof(str1), "%s\n{ffffff}Available stock: %d", IndustryInfo[1][Name], ServerInfo[id][E_SERVER_PRODUCTS]);

	ServerInfo[id][E_SERVER_3DTEXT] = CreateDynamic3DTextLabel(str, COLOR_POINT, IndustryInfo[0][Posx], IndustryInfo[0][Posy], IndustryInfo[0][Posz], 5.0);
	ServerInfo[id][E_SERVER_3DTEXT] = CreateDynamic3DTextLabel(str1, COLOR_POINT, IndustryInfo[1][Posx], IndustryInfo[1][Posy], IndustryInfo[1][Posz], 5.0);  
	return 1;
}

function:Query_ServerDataLoad()
{
    static
	    rows,
	    fields;

	cache_get_row_count(rows);
	cache_get_field_count(fields);

	for (new i = 0; i < rows; i ++) if (i < MAX_SERVERDATA)
	{
	    cache_get_value_name_int(i, "id", ServerInfo[i][E_SERVER_DBID]);
        cache_get_value_name_int(i, "products", ServerInfo[i][E_SERVER_PRODUCTS]);
		
        IndustryRefresh(i);
	}
	return 1;
}

stock ServerData_Plus(type, plus)
{
	for(new i = 0; i < MAX_SERVERDATA; i++)
	{
        IndustryRefresh(i);
    }
	for(new i = 0; i < MAX_SERVERDATA; i++)
	{
		switch(type)
		{
			case INDUSTRY_PRODUCTS:
			{
				ServerInfo[i][E_SERVER_PRODUCTS]+= plus;
			}
		}
	}
    
	SaveServerData();
	return 1;
}

stock ServerData_Minus(type, minus)
{
	for(new i = 0; i < MAX_SERVERDATA; i++)
	{
        IndustryRefresh(i);
    }
	for(new i = 0; i < MAX_SERVERDATA; i++)
	{
		switch(type)
		{
			case INDUSTRY_PRODUCTS:
			{
				ServerInfo[i][E_SERVER_PRODUCTS]-= minus;
			}
		}
	}
    
	SaveServerData();
	return 1;
}

stock ShowIndustry(playerid)
{
	new str[456];
	forex(i, sizeof(IndustryInfo))
	{
		format(str, sizeof(str), "%s%s\n", str, IndustryInfo[i][Name]);
	}
	ShowPlayerDialog(playerid, DIALOG_INDUSTRYLOC, DIALOG_STYLE_TABLIST, "Truck PDA - Industrial:", str, "Select", "Close");
	return 1;
}

stock ShowShipments(playerid)
{
    static
	    string[512],
		type[24];

	string[0] = 0;

	for (new i = 0; i < MAX_BUSINESS; i ++) if (BusinessInfo[i][E_BUSINESS_EXISTS] && BusinessInfo[i][E_BUSINESS_STOCK] < 100)
	{
	    switch (BusinessInfo[i][E_BUSINESS_TYPE]) {
	        case 1: type = "Restaurant";
	        case 2: type = "Bar";
	        case 3: type = "Jewelry";
	        case 4: type = "Ammunations";
			case 6: type = "Club";
			case 7: type = "Bank";
			case 8: type = "Pawnstore";
			case 9: type = "Clothes";
			case 10: type = "Dealership";
			case 11: type = "DMV";
			case 12: type = "Barbershop";
			case 13: type = "Furniture";
			case 14: type = "Gym";
		}
	    format(string, sizeof(string), "%s%d: %s (%s)\n", string, i, BusinessInfo[i][E_BUSINESS_NAME], type);
	}
	if (!strlen(string)) {
	    SendErrorMessage(playerid, "There are no shipments.");
	}
	else ShowPlayerDialog(playerid, DIALOG_DEFAULT, DIALOG_STYLE_LIST, "Shipments:", string, "Close", "");
	return 1;
}

function:IndustryTimer()
{
	for(new i = 0; i < MAX_SERVERDATA; i++)
	{
        IndustryRefresh(i);
    }
	for(new i = 0; i < MAX_SERVERDATA; i++)
	{
		ServerInfo[i][E_SERVER_PRODUCTS] = 100;
	}
	return 1;
}