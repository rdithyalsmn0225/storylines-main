enum
{
	INDUSTRY_FISH,
	INDUSTRY_FABRIC,
	INDUSTRY_STEEL,
	INDUSTRY_WOODS,
	INDUSTRY_FOODS,
	INDUSTRY_CLOTHES,
    INDUSTRY_APPLIANCES,
	INDUSTRY_MATERIALS,
	INDUSTRY_DRUGS
};

stock IndustryRefresh(id)
{
    new str[512], str1[512], str2[512], str3[512], str4[512], str5[512], str6[512];

	for(new i; i < 6; i++)
	{
		if(IsValidDynamic3DTextLabel(ServerInfo[id][E_SERVER_3DTEXT][i]))
    		DestroyDynamic3DTextLabel(ServerInfo[id][E_SERVER_3DTEXT][i]);
	}
	

    format(str, sizeof(str), "[%s]\n{ffffff}Available stock: %d / 100\nCargo Price: {93C47D}{93C47D}$%d{ffffff}{ffffff} / unit", IndustryInfo[0][Cargo], ServerInfo[id][E_SERVER_FABRIC], IndustryInfo[0][Price]);
    
	format(str1, sizeof(str1), "[%s]\n{ffffff}Available stock: %d / 100\nCargo Price {93C47D}$%d{ffffff} / unit", IndustryInfo[1][Cargo], ServerInfo[id][E_SERVER_STEEL], IndustryInfo[1][Price]);

	format(str2, sizeof(str2), "[%s]\n{ffffff}Available stock: %d / 100\nCargo Price {93C47D}$%d{ffffff} / unit", IndustryInfo[2][Cargo], ServerInfo[id][E_SERVER_WOODS], IndustryInfo[2][Price]);

	format(str3, sizeof(str3), "[%s]\n{ffffff}Available stock: %d / 100\nCargo Price {93C47D}$%d{ffffff} / unit", IndustryInfo[3][Cargo], ServerInfo[id][E_SERVER_FISH], IndustryInfo[3][Price]);

	format(str4, sizeof(str4), "[%s]\n{ffffff}Available stock: %d / 100\nCargo Price {93C47D}$%d{ffffff} / unit", IndustryInfo[4][Cargo], ServerInfo[id][E_SERVER_FOODS], IndustryInfo[4][Price]);

	format(str5, sizeof(str5), "[%s]\n{ffffff}Available stock: %d / 100\nCargo Price {93C47D}$%d{ffffff} / unit", IndustryInfo[5][Cargo], ServerInfo[id][E_SERVER_CLOTHES], IndustryInfo[5][Price]);

	format(str6, sizeof(str6), "[%s]\n{ffffff}Available stock: %d / 100\nCargo Price {93C47D}$%d{ffffff} / unit", IndustryInfo[6][Cargo], ServerInfo[id][E_SERVER_APPLIANCES], IndustryInfo[6][Price]);


	ServerInfo[id][E_SERVER_3DTEXT][0] = CreateDynamic3DTextLabel(str, COLOR_DARKGREEN, IndustryInfo[0][Posx], IndustryInfo[0][Posy], IndustryInfo[0][Posz], 5.0);
	ServerInfo[id][E_SERVER_3DTEXT][1] = CreateDynamic3DTextLabel(str1, COLOR_DARKGREEN, IndustryInfo[1][Posx], IndustryInfo[1][Posy], IndustryInfo[1][Posz], 5.0);  
	ServerInfo[id][E_SERVER_3DTEXT][2] = CreateDynamic3DTextLabel(str2, COLOR_DARKGREEN, IndustryInfo[2][Posx], IndustryInfo[2][Posy], IndustryInfo[2][Posz], 5.0);
	ServerInfo[id][E_SERVER_3DTEXT][3] = CreateDynamic3DTextLabel(str3, COLOR_DARKGREEN, IndustryInfo[3][Posx], IndustryInfo[3][Posy], IndustryInfo[3][Posz], 5.0);  
	ServerInfo[id][E_SERVER_3DTEXT][4] = CreateDynamic3DTextLabel(str4, COLOR_DARKGREEN, IndustryInfo[4][Posx], IndustryInfo[4][Posy], IndustryInfo[4][Posz], 5.0);  
	ServerInfo[id][E_SERVER_3DTEXT][5] = CreateDynamic3DTextLabel(str5, COLOR_DARKGREEN, IndustryInfo[5][Posx], IndustryInfo[5][Posy], IndustryInfo[5][Posz], 5.0);     
	ServerInfo[id][E_SERVER_3DTEXT][6] = CreateDynamic3DTextLabel(str6, COLOR_DARKGREEN, IndustryInfo[6][Posx], IndustryInfo[6][Posy], IndustryInfo[6][Posz], 5.0);   
	return 1;
}

function:Query_ServerDataLoad()
{
    static
	    rows,
	    fields;

	cache_get_row_count(rows);
	cache_get_field_count(fields);

	if(rows)
	{
		cache_get_value_name_int(0, "id", ServerInfo[0][E_SERVER_DBID]);
		cache_get_value_name_int(0, "fish", ServerInfo[0][E_SERVER_FISH]);
		cache_get_value_name_int(0, "fabric", ServerInfo[0][E_SERVER_FABRIC]);
		cache_get_value_name_int(0, "steel", ServerInfo[0][E_SERVER_STEEL]);
		cache_get_value_name_int(0, "woods", ServerInfo[0][E_SERVER_WOODS]);
		cache_get_value_name_int(0, "foods", ServerInfo[0][E_SERVER_FOODS]);
		cache_get_value_name_int(0, "clothes", ServerInfo[0][E_SERVER_CLOTHES]);
		cache_get_value_name_int(0, "appliances", ServerInfo[0][E_SERVER_APPLIANCES]);
		cache_get_value_name_int(0, "materials", ServerInfo[0][E_SERVER_MATERIALS]);
		cache_get_value_name_int(0, "drugs", ServerInfo[0][E_SERVER_DRUGS]);
	}	
    IndustryRefresh(0);
	return 1;
}

stock ServerData_Plus(type, plus)
{
	switch(type)
	{
		case INDUSTRY_FABRIC:
		{
			ServerInfo[0][E_SERVER_FABRIC]+= plus;
		}
		case INDUSTRY_STEEL:
		{
			ServerInfo[0][E_SERVER_STEEL]+= plus;
		}
		case INDUSTRY_WOODS:
		{
			ServerInfo[0][E_SERVER_WOODS]+= plus;
		}
		case INDUSTRY_FOODS:
		{
			ServerInfo[0][E_SERVER_FOODS]+= plus;
		}
		case INDUSTRY_CLOTHES:
		{
			ServerInfo[0][E_SERVER_CLOTHES]+= plus;
		}
		case INDUSTRY_APPLIANCES:
		{
			ServerInfo[0][E_SERVER_APPLIANCES]+= plus;
		}
		case INDUSTRY_MATERIALS:
		{
			ServerInfo[0][E_SERVER_MATERIALS]+= plus;
		}
		case INDUSTRY_DRUGS:
		{
			ServerInfo[0][E_SERVER_DRUGS]+= plus;
		}
	}
    IndustryRefresh(0);
	SaveServerDatas(0);
	return 1;
}

stock ServerData_Minus(type, minus)
{
	switch(type)
	{
		case INDUSTRY_FABRIC:
		{
			ServerInfo[0][E_SERVER_FABRIC]-= minus;
		}
		case INDUSTRY_STEEL:
		{
			ServerInfo[0][E_SERVER_STEEL]-= minus;
		}
		case INDUSTRY_WOODS:
		{
			ServerInfo[0][E_SERVER_WOODS]-= minus;
		}
		case INDUSTRY_FOODS:
		{
			ServerInfo[0][E_SERVER_FOODS]-= minus;
		}
		case INDUSTRY_CLOTHES:
		{
			ServerInfo[0][E_SERVER_CLOTHES]-= minus;
		}
		case INDUSTRY_APPLIANCES:
		{
			ServerInfo[0][E_SERVER_APPLIANCES]-= minus;
		}
		case INDUSTRY_MATERIALS:
		{
			ServerInfo[0][E_SERVER_MATERIALS]-= minus;
		}
		case INDUSTRY_DRUGS:
		{
			ServerInfo[0][E_SERVER_DRUGS]-= minus;
		}
	}

    IndustryRefresh(0);
	SaveServerDatas(0);
	return 1;
}

stock ShowIndustry(playerid)
{
	new str[456];
	strcat(str, "Industries\tCargo\tType\n");
	forex(i, sizeof(IndustryInfo))
	{
		format(str, sizeof(str), "%s%s\t{93C47D}%s{ffffff}\t%s\n", str, IndustryInfo[i][Name], IndustryInfo[i][Cargo], IndustryInfo[i][Type]);
	}
	ShowPlayerDialog(playerid, DIALOG_INDUSTRYLOC, DIALOG_STYLE_TABLIST_HEADERS, "Truck PDA - Industrial:", str, "Select", "Close");
	return 1;
}

stock ShowShipments(playerid)
{
    static
	    string[512],
		type[24];

	string[0] = 0;

	for (new i = 0; i < MAX_BUSINESS; i ++) if (BusinessInfo[i][E_BUSINESS_EXISTS] && BusinessInfo[i][E_BUSINESS_STOCK] < 100 && BusinessInfo[i][E_BUSINESS_TYPE] != 3 && BusinessInfo[i][E_BUSINESS_TYPE] != 4)
	{
	    switch (BusinessInfo[i][E_BUSINESS_TYPE]) {
	        case 1: type = "Restaurant";
	        case 2: type = "Bar";
	        case 3: type = "Acid Labs";
	        case 4: type = "Gunstore";
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
	    SendErrorMessage(playerid, "There is no shipments available.");
	}
	else ShowPlayerDialog(playerid, DIALOG_DEFAULT, DIALOG_STYLE_LIST, "Shipments:", string, "Close", "");
	return 1;
}

function:IndustryTimer()
{
	if(ServerInfo[0][E_SERVER_FABRIC] <= 100)
		ServerInfo[0][E_SERVER_FABRIC] += 10;
	if(ServerInfo[0][E_SERVER_FABRIC] >= 100)
		ServerInfo[0][E_SERVER_FABRIC] = 100;

	if(ServerInfo[0][E_SERVER_STEEL] <= 100)
		ServerInfo[0][E_SERVER_STEEL] += 10;
	if(ServerInfo[0][E_SERVER_STEEL] >= 100)
		ServerInfo[0][E_SERVER_STEEL] = 100;
		
	if(ServerInfo[0][E_SERVER_WOODS] <= 100)
		ServerInfo[0][E_SERVER_WOODS] += 10;
	if(ServerInfo[0][E_SERVER_WOODS] >= 100)
		ServerInfo[0][E_SERVER_WOODS] = 100;

	if(ServerInfo[0][E_SERVER_FISH] <= 100)
		ServerInfo[0][E_SERVER_FISH] += 10;
	if(ServerInfo[0][E_SERVER_FISH] >= 100)
		ServerInfo[0][E_SERVER_FISH] = 100;

	if(ServerInfo[0][E_SERVER_FOODS] <= 100)
		ServerInfo[0][E_SERVER_FOODS] += 10;
	if(ServerInfo[0][E_SERVER_FOODS] >= 100)
		ServerInfo[0][E_SERVER_FOODS] = 100;

	if(ServerInfo[0][E_SERVER_CLOTHES] <= 100)
		ServerInfo[0][E_SERVER_CLOTHES] += 10;
	if(ServerInfo[0][E_SERVER_CLOTHES] >= 100)
		ServerInfo[0][E_SERVER_CLOTHES] = 100;
		
	if(ServerInfo[0][E_SERVER_APPLIANCES] <= 100)
		ServerInfo[0][E_SERVER_APPLIANCES] += 10;
	if(ServerInfo[0][E_SERVER_APPLIANCES] >= 100)
		ServerInfo[0][E_SERVER_APPLIANCES] = 100;

	if(ServerInfo[0][E_SERVER_DRUGS] <= 100)
		ServerInfo[0][E_SERVER_DRUGS] += 10;
	if(ServerInfo[0][E_SERVER_DRUGS] >= 100)
		ServerInfo[0][E_SERVER_DRUGS] = 100;

	IndustryRefresh(0);
	return 1;
}