//Dialogs:
stock ConfirmDialog(playerid, caption[], info[], callback[], {Float,_}:...)
{
	new n = numargs(), 		// number of arguments, static + optional
		szParamHash[256];	// variable where the passed arguments will be stored
	for(new arg = 4; arg < n; arg++){	// loop all additional arguments
		format(szParamHash, sizeof(szParamHash), "%s%d|", szParamHash, getarg(arg)); // store them in szParamHash
	}
	SetPVarInt(playerid, "confDialogArgs", n -4);			// store the amount of additional arguments
	SetPVarString(playerid, "confDialCallback", callback);	// store the callback that needs to be called after response
	SetPVarString(playerid, "confDialog_arg", szParamHash);	// store the additional arguments
	
	ShowPlayerDialog(playerid, DIALOG_CONFIRM_SYS, DIALOG_STYLE_MSGBOX, caption, info, "Yes", "No"); // display the dialog message itself
	
	return;
}

stock ConfirmDialog_Response(playerid, response)
{
	new szCallback[33],		// variable to fetch our callback to
		szParamHash[64], 	// variable to check raw compressed argument string
		n,					// variable to fetch the amount of additional arguments
		szForm[12];			// variable to generate the CallLocalFunction() "format" argument
		
	n = GetPVarInt(playerid, "confDialogArgs");	// Fetch the amount of additional arguments
	GetPVarString(playerid, "confDialCallback", szCallback, sizeof(szCallback));	// fetch the callback
	GetPVarString(playerid, "confDialog_arg", szParamHash, sizeof(szParamHash));	// fetch the raw compressed additional arguments
	
	new hashDecoded[12];	// variable to store extracted additional arguments from the ConfirmDialog() generated string
	
	sscanf(szParamHash, "p<|>A<d>(0)[12]", hashDecoded);	// extraction of the additional arguments
	
	new args, 	// amount of cells passed to CallLocalFunction
		addr, 	// pointer address variable for later use
		i;		// i
		
	format(szForm, sizeof(szForm), "dd");	// static parameters for the callback, "playerid" and "response"
	
	#emit ADDR.pri hashDecoded	// get pointer address of the extracted additional arguments
	#emit STOR.S.pri addr		// store the pointer address in variable 'addr'
	if(n){	// if there's any additional arguments
		for(i = addr + ((n-1) * 4); i >= addr; i-=4){ // loops all additional arguments by their addresses
			format(szForm, sizeof(szForm), "%sd", szForm); // adds an aditional specifier to the "format" parameter of CallLocalFunction
			#emit load.s.pri i	// load the argument at the current address
			#emit push.pri		// push it to the CallLocalFunction argument list
			args+=4;			// increase used cell number by 4
		}
	}
	
	
	args+=16;	// preserve 4 more arguments for CallLocalFunction (16 cause 4 args by 4 cells (4*4))
	
	#emit ADDR.pri response				// fetch "response" pointer address to the primary buffer
	#emit push.pri						// push it to the argument list
	
	#emit ADDR.pri playerid				// fetch "playerid" pointer address to the primary buffer
	#emit push.pri						// push it to the argument list
	
	#emit push.adr szForm				// push the szForm ("format") to the argument list by its referenced address
	#emit push.adr szCallback			// push the szCallback (custom callback) to the argument list by its referenced address
	#emit push.s args					// push the amount of arguments
	#emit sysreq.c CallLocalFunction	// call the function
	
	// Clear used data
	#emit LCTRL 4
	#emit LOAD.S.ALT args
	#emit ADD.C 4
	#emit ADD
	#emit SCTRL 4
	
	// Clear used PVars
	DeletePVar(playerid, "confDialCallback");
	DeletePVar(playerid, "confDialog_arg");
	DeletePVar(playerid, "confDialogArgs");
	
	return;
}

public OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
	switch (dialogid)
	{
		case DIALOG_CONFIRM_SYS:
		{
			ConfirmDialog_Response(playerid, response);
			return 1;
		}
		case DIALOG_REGISTER:
		{
			if(!response)
			{
				SendErrorMessage(playerid, "You were kicked for not registering.");
				return KickEx(playerid); 
			}
			
			new str[1024];
			format(str, sizeof(str), "{ffffff}Welcome to {297183}Storylines{DEDEDE}, {FFFFFF}%s!\n\n{DEDEDE}Failure to authenticate three times will result in a {E03232}kick{DEDEDE}.\nYou have a total of {EEC650}five minutes{DEDEDE} to authenticate.\n\nIn order to proceed, enter a {EEC650}password{DEDEDE} below to authenticate (or register).", ReturnSettingsName(playerid, playerid));
			new insert[256]; 
			
			if(strlen(inputtext) > 128 || strlen(inputtext) < 3)
				return ShowPlayerDialog(playerid, DIALOG_REGISTER, DIALOG_STYLE_PASSWORD, "Register:", str, "Confirm", "");
				
			mysql_format(ourConnection, insert, sizeof(insert), "INSERT INTO `masters` (`acc_name`, `acc_pass`, `register_date`, `register_ip`, `forum_name`) VALUES ('%e', sha1('%e'), '%e', '%e', '%e')", ReturnSettingsName(playerid, playerid), inputtext, ReturnDate(), ReturnIP(playerid), ReturnSettingsName(playerid, playerid));
    		mysql_pquery(ourConnection, insert, "OnPlayerRegister", "i", playerid);
		}
		case DIALOG_LOGIN:
		{
			if (!response)
			{
				SendErrorMessage(playerid, "You were kicked for not logging in."); 
				return KickEx(playerid);
			}
			
			new continueCheck[211]; 
			
			mysql_format(ourConnection, continueCheck, sizeof(continueCheck), "SELECT acc_dbid, forum_name, secret_word, active_ip FROM masters WHERE acc_name = '%e' AND acc_pass = sha1('%e') LIMIT 1", 
				ReturnSettingsName(playerid, playerid), inputtext);
				
			mysql_pquery(ourConnection, continueCheck, "LoggingIn", "i", playerid);
			return 1;
		}
		case DIALOG_CHARS:
		{
			if (!response)
			{
				SendErrorMessage(playerid, "You were kicked for not selecting a character.");
				return KickEx(playerid); 
			}
			
			for(new i = 0; i < 3; i ++) {PlayerTextDrawHide(playerid, loginscreen[i][playerid]);}

			SetPlayerVirtualWorld(playerid, 99);
			InterpolateCameraPos(playerid, 2223.004394, -1261.156982, 24.698129, 2238.075439, -1260.909179, 24.844661, 3000, 1);
			InterpolateCameraLookAt(playerid, 2226.993896, -1261.235473, 24.418256, 2242.063232, -1260.991943, 24.544891, 3000, 1);

			if(strfind(characterLister[playerid][listitem], "[", false) != -1)
			{
				for(new i =0 ; i < 10; i++){ SendClientMessage(playerid, -1, " "); }
				SendClientMessage(playerid, COLOR_WHITE, "You selected an empty character slot!");
				
				SendClientMessage(playerid, -1, "This process will guide you through creating your character.");
				SendClientMessage(playerid, -1, "Please begin by typing your characters first and last name. i.e: {B3C99E}George_Jefferson");
				SendClientMessage(playerid, -1, "Your characters name must be in Firstname_Lastname format with no numbers or special characters.");
				SendClientMessage(playerid, -1, "Press {B3C99E}'T'{ffffff} to inputtext for character creation.");
				
				playerMakingCharacter[playerid] = true;
				playerCharacterStep[playerid] = 1; 
				return 1;
			}
			else
			{
				new 
					string[128], thread[128]
				;
				for(new i = 0; i < 3; i ++) {PlayerTextDrawHide(playerid, loginscreen[i][playerid]);}
				characterPickTime[playerid] = 0;
				
				playerMakingCharacter[playerid] = false;
				playerCharacterStep[playerid] = 0; 
				
				format(string, sizeof(string), "You selected the character {B3C99E}%s{FFFFFF}.", characterLister[playerid][listitem]);
				SendClientMessage(playerid, -1, string);

				UpdateTabListForOthers(playerid);
				UpdateTabListForPlayer(playerid);
				
				mysql_format(ourConnection, thread, sizeof(thread), "SELECT * FROM characters WHERE char_name = '%e' LIMIT 1", characterLister[playerid][listitem]);
				mysql_pquery(ourConnection, thread, "Query_SelectCharacter", "i", playerid); 
			}
			return 1;
		}
		case DIALOG_REPORT:
		{
			if (!response)
			{
				return SendErrorMessage(playerid, "You cancelled your report.");
			}
			
			new idx;
	
			for (new i = 1; i < sizeof(ReportInfo); i ++)
			{
				if (ReportInfo[i][E_REPORT_EXISTS] == false)
				{
					idx = i;
					break; 
				}
			}
			
			OnPlayerReport(playerid, idx, playerReport[playerid]); 
		}
		case DIALOG_GPSPROP:
		{
			if (response)
			{
				if (isnull(inputtext) || strlen(inputtext) > 32)
					return ShowPlayerDialog(playerid, DIALOG_GPSPROP, DIALOG_STYLE_INPUT, "GPS: Properties", "Please enter the address of the properties below:", "Submit", "Cancel");

				for (new i = 1; i != MAX_PROPERTY; i ++)
				{
					if (PropertyInfo[i][E_PROPERTY_DBID] && !strcmp(PropertyInfo[i][E_PROPERTY_ADDRESS], inputtext, true))
					{
						GPS_SetPlayerRaceCheckPoint(playerid, 1, PropertyInfo[i][E_PROPERTY_ENTRANCEPOS][0], PropertyInfo[i][E_PROPERTY_ENTRANCEPOS][1], PropertyInfo[i][E_PROPERTY_ENTRANCEPOS][2], 0.0, 0.0, 0.0);
					}
				}
				ShowPlayerDialog(playerid, DIALOG_GPSPROP, DIALOG_STYLE_INPUT, "GPS: Properties", "No results found for.\nPlease enter the address of the properties below:", "Submit", "Cancel");
			}
		}
		case DIALOG_GPS:
		{
			if(response)
			{
				switch(listitem)
				{
					case 0: //Point Of Interest
						ShowPlayerDialog(playerid, DIALOG_GPSPOI, DIALOG_STYLE_LIST, "GPS: Point of Interest", "Public Locations\nJobs Locations\nBusiness Locations\nTree Locations", "Select", "Cancel");
					case 1:
						ShowPlayerDialog(playerid, DIALOG_GPSPROP, DIALOG_STYLE_INPUT, "GPS: Properties", "Please enter the address of the properties below:", "Submit", "Cancel");
					case 2: //ENEX
						ShowENEXLocation(playerid);
					case 3: //Disable CP
						GPS_DisablePlayerRaceCheckPoint(playerid);
				}
			}
		}
		case DIALOG_GPSPOI:
		{
			if (response)
			{
			    switch (listitem)
			    {
			        case 0: //Public
			        {
			        	ShowPublicLocation(playerid);
			        }
					case 1: //Jobs
					{
						ShowJobLocation(playerid);
					}  
					case 2: //Business
					{
						ShowBusinessLocation(playerid);
					} 
					case 3: //Tree
					{
						ShowTreeLocation(playerid);
					}
				}
			}
		}
		case DIALOG_INTERIOR:
		{
			if (response)
			{
			    SetPlayerInterior(playerid, g_arrInteriorData[listitem][E_INT_ID]);
			    SetPlayerPosEx(playerid, g_arrInteriorData[listitem][E_INT_X], g_arrInteriorData[listitem][E_INT_Y], g_arrInteriorData[listitem][E_INT_Z]);
			}
		}
		case DIALOG_GENERALSTORE1:
		{
			if(response)
			{
				switch(listitem)
				{
					case 0:
					{
						if(Inventory_Count(playerid, "Cellphone"))
							return SendErrorMessage(playerid, "You already own a cellphone.");
					
						if(500 > PlayerInfo[playerid][E_CHARACTER_MONEY])
							return SendErrorMessage(playerid, "You can't afford a cellphone.");
					
						SendServerMessage(playerid, "[Business] {cdd0d1}You bought a cellphone for {B3C99E}$500{cdd0d1}.");

						PlayerInfo[playerid][E_CHARACTER_PURCHASE] += 500;
						BusinessInfo[IsPlayerInBusiness(playerid)][E_BUSINESS_STOCK]--;
						Inventory_Add(playerid, "Cellphone", 18867, 1);

						ApplyAnimation(playerid, "MISC", "GRAB_R", 4.1, 0, 0, 0, 0, 0, 0);
					}
					case 1:
					{
						if(Inventory_Count(playerid, "Portable Radio"))
							return SendErrorMessage(playerid, "You already own a radio.");
					
						if(500 > PlayerInfo[playerid][E_CHARACTER_MONEY])
							return SendErrorMessage(playerid, "You can't afford a radio.");
					
						SendServerMessage(playerid, "[Business] {cdd0d1}You bought a radio for {B3C99E}$500{cdd0d1}.");
 
						
						PlayerInfo[playerid][E_CHARACTER_PURCHASE] += 500;
						BusinessInfo[IsPlayerInBusiness(playerid)][E_BUSINESS_STOCK]--;
						Inventory_Add(playerid, "Portable Radio", 19942, 1);

						ApplyAnimation(playerid, "MISC", "GRAB_R", 4.1, 0, 0, 0, 0, 0, 0);
					}
					case 2:
					{
						if(250 > PlayerInfo[playerid][E_CHARACTER_MONEY])
							return SendErrorMessage(playerid, "You can't afford a gasoline can.");
						
						if(Inventory_Count(playerid, "Gascan") >= 5)
							return SendErrorMessage(playerid, "You may only hold up to 5 gasoline cans.");
						
						SendServerMessage(playerid, "[Business] {cdd0d1}You bought a gasoline can for {B3C99E}$250{cdd0d1}.");
	
						PlayerInfo[playerid][E_CHARACTER_PURCHASE] += 250; 
						BusinessInfo[IsPlayerInBusiness(playerid)][E_BUSINESS_STOCK]--;
						Inventory_Add(playerid, "Gascan", 1650, 1);

						ApplyAnimation(playerid, "MISC", "GRAB_R", 4.1, 0, 0, 0, 0, 0, 0);
					}
					case 3:
					{
						if(500 > PlayerInfo[playerid][E_CHARACTER_MONEY])
							return SendErrorMessage(playerid, "You can't afford a repairkit.");
						
						if(Inventory_Count(playerid, "Repair Kits"))
							return SendErrorMessage(playerid, "You already own a repairkit.");
						
						SendServerMessage(playerid, "[Business] {cdd0d1}You bought a repairkit for {B3C99E}$250{cdd0d1}.");
						
						PlayerInfo[playerid][E_CHARACTER_PURCHASE] += 500; 
						BusinessInfo[IsPlayerInBusiness(playerid)][E_BUSINESS_STOCK]--;
						Inventory_Add(playerid, "Repair Kits", 1650, 1);

						ApplyAnimation(playerid, "MISC", "GRAB_R", 4.1, 0, 0, 0, 0, 0, 0);
					}
				}
			}
		}
		case DIALOG_GENERALSTORE2:
		{
			if(response)
			{
				switch(listitem)
				{
					case 0:
					{
						if(Inventory_Count(playerid, "Spike Bat"))
							return SendErrorMessage(playerid, "You already own a spikebat.");
					
						if(350 > PlayerInfo[playerid][E_CHARACTER_MONEY])
							return SendErrorMessage(playerid, "You can't afford a spikebat.");
					
						SendServerMessage(playerid, "[Business] {cdd0d1}You bought a spikebat for $350.");
						PlayerInfo[playerid][E_CHARACTER_PURCHASE] += 350;
						BusinessInfo[IsPlayerInBusiness(playerid)][E_BUSINESS_STOCK]--;
						Inventory_Add(playerid, "Spike Bat", -2200, 1);

						ApplyAnimation(playerid, "MISC", "GRAB_R", 4.1, 0, 0, 0, 0, 0, 0);
					}
					case 1:
					{
						if(Inventory_Count(playerid, "Wooden"))
							return SendErrorMessage(playerid, "You already own a wooden.");
					
						if(500 > PlayerInfo[playerid][E_CHARACTER_MONEY])
							return SendErrorMessage(playerid, "You can't afford a wooded.");
					
						SendServerMessage(playerid, "[Business] {cdd0d1}You bought a wooden for {B3C99E}$250{cdd0d1}.");
						PlayerInfo[playerid][E_CHARACTER_PURCHASE] += 500;
						BusinessInfo[IsPlayerInBusiness(playerid)][E_BUSINESS_STOCK]--;
						Inventory_Add(playerid, "Wooden", -2201, 1);

						ApplyAnimation(playerid, "MISC", "GRAB_R", 4.1, 0, 0, 0, 0, 0, 0);
					}
					case 2:
					{
						if(Inventory_Count(playerid, "Nail Bat"))
							return SendErrorMessage(playerid, "You already own a nailbat.");
					
						if(350 > PlayerInfo[playerid][E_CHARACTER_MONEY])
							return SendErrorMessage(playerid, "You can't afford a nailbat.");
					
						SendServerMessage(playerid, "[Business] {cdd0d1}You bought a nailbat for {B3C99E}$350{cdd0d1}.");
						PlayerInfo[playerid][E_CHARACTER_PURCHASE] += 350;
						BusinessInfo[IsPlayerInBusiness(playerid)][E_BUSINESS_STOCK]--;
						Inventory_Add(playerid, "Nail Bat", -2202, 1);

						ApplyAnimation(playerid, "MISC", "GRAB_R", 4.1, 0, 0, 0, 0, 0, 0);
					}
				}
			}
		}
		case DIALOG_GENERALSTORE3:
		{
			if(response)
			{
				switch(listitem)
				{
					case 0:
					{
						if(Inventory_Count(playerid, "Raw Meat"))
							return SendErrorMessage(playerid, "You already own a raw meat.");
					
						if(50 > PlayerInfo[playerid][E_CHARACTER_MONEY])
							return SendErrorMessage(playerid, "You can't afford a raw meat.");
					
						SendServerMessage(playerid, "[Business] {cdd0d1}You bought a raw meat for {B3C99E}$50{cdd0d1}.");
						PlayerInfo[playerid][E_CHARACTER_PURCHASE] += 50;
						BusinessInfo[IsPlayerInBusiness(playerid)][E_BUSINESS_STOCK]--;
						Inventory_Add(playerid, "Raw Meat", 19582, 1);

						ApplyAnimation(playerid, "MISC", "GRAB_R", 4.1, 0, 0, 0, 0, 0, 0);
					}
					case 1:
					{
						if(Inventory_Count(playerid, "Parsley") >= 5)
							return SendErrorMessage(playerid, "You may only hold up to 5 parsley.");
					
						if(100 > PlayerInfo[playerid][E_CHARACTER_MONEY])
							return SendErrorMessage(playerid, "You can't afford a parsley.");
					
						SendServerMessage(playerid, "[Business] {cdd0d1}You bought a parsley for {B3C99E}$250{cdd0d1}.");

						PlayerInfo[playerid][E_CHARACTER_PURCHASE] += 100; 
						BusinessInfo[IsPlayerInBusiness(playerid)][E_BUSINESS_STOCK]--;
						Inventory_Add(playerid, "Parsley", 2244, 1);

						ApplyAnimation(playerid, "MISC", "GRAB_R", 4.1, 0, 0, 0, 0, 0, 0);
					}
					case 2:
					{
						if(Inventory_Count(playerid, "Mint") >= 5)	
							return SendErrorMessage(playerid, "You may only hold up to 5 mint.");
					
						if(150 > PlayerInfo[playerid][E_CHARACTER_MONEY])
							return SendErrorMessage(playerid, "You can't afford a mint.");
					
						SendServerMessage(playerid, "[Business] {cdd0d1}You bought a mint for {B3C99E}$50{cdd0d1}.");

						PlayerInfo[playerid][E_CHARACTER_PURCHASE] += 50; 
						BusinessInfo[IsPlayerInBusiness(playerid)][E_BUSINESS_STOCK]--;
						Inventory_Add(playerid, "Mint", 19570, 1);

						ApplyAnimation(playerid, "MISC", "GRAB_R", 4.1, 0, 0, 0, 0, 0, 0);
					}
					case 3:
					{
						if(Inventory_Count(playerid, "Oregano") >= 5)
							return SendErrorMessage(playerid, "You may only hold up to 5 oregano.");
					
						if(250 > PlayerInfo[playerid][E_CHARACTER_MONEY])
							return SendErrorMessage(playerid, "You can't afford a oregano.");
					
						SendServerMessage(playerid, "[Business] {cdd0d1}You bought a oregano for {B3C99E}$250{cdd0d1}.");

						PlayerInfo[playerid][E_CHARACTER_PURCHASE] += 250; 
						BusinessInfo[IsPlayerInBusiness(playerid)][E_BUSINESS_STOCK]--;
						Inventory_Add(playerid, "Oregano", 19570, 1);

						ApplyAnimation(playerid, "MISC", "GRAB_R", 4.1, 0, 0, 0, 0, 0, 0);
					}
					case 4:
					{
						if(Inventory_Count(playerid, "Baking Soda") >= 5)	
							return SendErrorMessage(playerid, "You may only hold up to 5 baking soda.");
					
						if(100 > PlayerInfo[playerid][E_CHARACTER_MONEY])
							return SendErrorMessage(playerid, "You can't afford a baking soda.");
					
						SendServerMessage(playerid, "[Business] {cdd0d1}You bought a baking soda for {B3C99E}$100{cdd0d1}.");

						PlayerInfo[playerid][E_CHARACTER_PURCHASE] += 100; 
						BusinessInfo[IsPlayerInBusiness(playerid)][E_BUSINESS_STOCK]--;
						
						Inventory_Add(playerid, "Baking Soda", 19570, 1);

						ApplyAnimation(playerid, "MISC", "GRAB_R", 4.1, 0, 0, 0, 0, 0, 0);
					}
				}
			}
		}
		case DIALOG_GENERALSTORE4:
		{
			if(response)
			{
				switch(listitem)
				{
					case 0:
					{
						if(Inventory_Count(playerid, "Spraycan") >= 5)	
							return SendErrorMessage(playerid, "You may only hold up to 5 spraycan.");
					
						if(250 > PlayerInfo[playerid][E_CHARACTER_MONEY])
							return SendErrorMessage(playerid, "You can't afford a spraycan.");
					
						SendServerMessage(playerid, "[Business] {cdd0d1}You bought a spraycan for {B3C99E}$250{cdd0d1}.");

						PlayerInfo[playerid][E_CHARACTER_PURCHASE] += 250; 
						BusinessInfo[IsPlayerInBusiness(playerid)][E_BUSINESS_STOCK]--;
						Inventory_Add(playerid, "Spraycan", 365, 1);

						ApplyAnimation(playerid, "MISC", "GRAB_R", 4.1, 0, 0, 0, 0, 0, 0);
					}
					case 1:
					{
						if(Inventory_Count(playerid, "Crowbar") >= 1)		
							return SendErrorMessage(playerid, "You may only hold up to 1 crowbar.");
					
						if(500 > PlayerInfo[playerid][E_CHARACTER_MONEY])
							return SendErrorMessage(playerid, "You can't afford a crowbar.");
					
						SendServerMessage(playerid, "[Business] {cdd0d1}You bought a crowbar for {B3C99E}$500{cdd0d1}.");

						PlayerInfo[playerid][E_CHARACTER_PURCHASE] += 500;
						BusinessInfo[IsPlayerInBusiness(playerid)][E_BUSINESS_STOCK]--;
						Inventory_Add(playerid, "Crowbar", 18634, 1);

						ApplyAnimation(playerid, "MISC", "GRAB_R", 4.1, 0, 0, 0, 0, 0, 0);
					}
				}
			}
		}
		case DIALOG_GENERALSTORE5:
		{
			if(response)
			{
				switch(listitem)
				{
					case 0:
					{
						if(Inventory_Count(playerid, "Spraycan") >= 5)	
							return SendErrorMessage(playerid, "You may only hold up to 5 sprunk.");
					
						if(2 > PlayerInfo[playerid][E_CHARACTER_MONEY])
							return SendErrorMessage(playerid, "You can't afford a sprunk.");
					
						SendServerMessage(playerid, "[Business] {cdd0d1}You bought a sprunk for {B3C99E}$2{cdd0d1}.");

						PlayerInfo[playerid][E_CHARACTER_PURCHASE] += 5; 
						BusinessInfo[IsPlayerInBusiness(playerid)][E_BUSINESS_STOCK]--;
						Inventory_Add(playerid, "Sprunk", 2601, 1);

						ApplyAnimation(playerid, "MISC", "GRAB_R", 4.1, 0, 0, 0, 0, 0, 0);
					}
				}
			}
		}
		case DIALOG_BAR:
		{
			if(response)
			{
				switch(listitem)
				{
					case 0:
					{
						if(Inventory_Count(playerid, "Beer") >= 5)
							return SendErrorMessage(playerid, "You may only hold up to 5 beer.");
					
						if(100 > PlayerInfo[playerid][E_CHARACTER_MONEY])
							return SendErrorMessage(playerid, "You can't afford a beer.");
					
						SendServerMessage(playerid, "[Business] {cdd0d1}You bought a budweiser beer for {B3C99E}$100{cdd0d1}.");
						GiveMoney(playerid, -100); 
						
						BusinessInfo[IsPlayerInBusiness(playerid)][E_BUSINESS_STOCK]--;
						Inventory_Add(playerid, "Beer", 1486, 1);
						ShowBeerlist(playerid);
					}
					case 1:
					{
						if(Inventory_Count(playerid, "Beer") >= 5)
						{
							SendErrorMessage(playerid, "You may only hold up to 5 beer.");
							ShowBeerlist(playerid);
							return ShowBeerlist(playerid);
						}
					
						if(150 > PlayerInfo[playerid][E_CHARACTER_MONEY])
						{
							SendErrorMessage(playerid, "You can't afford a beer.");
							return ShowBeerlist(playerid);
						}
					
						SendServerMessage(playerid, "[Business] {cdd0d1}You bought a corona extra beer for {B3C99E}$150{cdd0d1}.");
						GiveMoney(playerid, -150); 
						
						BusinessInfo[IsPlayerInBusiness(playerid)][E_BUSINESS_STOCK]--;
						Inventory_Add(playerid, "Beer", 1486, 1);
						ShowBeerlist(playerid);
					}
					case 2:
					{
						if(Inventory_Count(playerid, "Beer") >= 5)
						{
							SendErrorMessage(playerid, "You may only hold up to 5 beer.");
							return ShowBeerlist(playerid);
						}
					
						if(200 > PlayerInfo[playerid][E_CHARACTER_MONEY])
						{
							SendErrorMessage(playerid, "You can't afford a beer.");
							return ShowBeerlist(playerid);
						}
					
						SendServerMessage(playerid, "[Business] {cdd0d1}You bought a peroni beer for {B3C99E}$200{cdd0d1}.");
						GiveMoney(playerid, -200); 
						
						BusinessInfo[IsPlayerInBusiness(playerid)][E_BUSINESS_STOCK]--;
						Inventory_Add(playerid, "Beer", 1486, 1);
						ShowBeerlist(playerid);
					}
				}
			}
			return 1;
		}
		case DIALOG_DINNER:
		{
			if(response)
			{
				switch(listitem)
				{
					case 0:
					{
						if(50 > PlayerInfo[playerid][E_CHARACTER_MONEY])
						{
							SendErrorMessage(playerid, "You can't afford a American Classic Burger's.");
							return ShowFoodMenu(playerid); 
						}

						SendServerMessage(playerid, "[Business] {cdd0d1}You bought American classic burger's and eat it");
						GiveMoney(playerid, -50); 

						new Float:health;
						GetPlayerHealth(playerid, health);
						SetPlayerHealthEx(playerid, health+20.0);
						BusinessInfo[IsPlayerInBusiness(playerid)][E_BUSINESS_STOCK]--;
						ShowFoodMenu(playerid);
					}
					case 1:
					{
						if(50 > PlayerInfo[playerid][E_CHARACTER_MONEY])
						{
							SendErrorMessage(playerid, "You can't afford a American Classic donut's.");
							return ShowFoodMenu(playerid);
						}
					
						SendServerMessage(playerid, "[Business] {cdd0d1}You bought American classic donut's and eat it");
						GiveMoney(playerid, -50); 
						new Float:health;
						GetPlayerHealth(playerid, health);
						SetPlayerHealthEx(playerid, health+30.0);
						BusinessInfo[IsPlayerInBusiness(playerid)][E_BUSINESS_STOCK]--;
						ShowFoodMenu(playerid);
					}
					case 2:
					{
						if(80 > PlayerInfo[playerid][E_CHARACTER_MONEY])
						{
							SendErrorMessage(playerid, "You can't afford a American Classic pizza's.");
							return ShowFoodMenu(playerid);
						}
					
						SendServerMessage(playerid, "[Business] {cdd0d1}You bought American classic pizza's and eat it");
						GiveMoney(playerid, -80); 
						
						new Float:health;
						GetPlayerHealth(playerid, health);
						SetPlayerHealthEx(playerid, health+35.0);
						BusinessInfo[IsPlayerInBusiness(playerid)][E_BUSINESS_STOCK]--;
						ShowFoodMenu(playerid);
					}
					case 3:
					{
						if(25 > PlayerInfo[playerid][E_CHARACTER_MONEY])
						{
							SendErrorMessage(playerid, "You can't afford a Coca cola large's.");
							return ShowFoodMenu(playerid); 
						}
					
						SendServerMessage(playerid, "[Business] {cdd0d1}You bought Coca cola large's and eat it");
						GiveMoney(playerid, -25); 
						
						new Float:health;
						GetPlayerHealth(playerid, health);
						SetPlayerHealthEx(playerid, health+20.0);
						BusinessInfo[IsPlayerInBusiness(playerid)][E_BUSINESS_STOCK]--;
						ShowFoodMenu(playerid);
					}
				}
			}
			return 1;
		}
		case DIALOG_CLOTHSHOW:
		{
			if(response)
			{
				if(pToys[playerid][listitem][E_TOY_MODEL] == 0)
					return SendErrorMessage(playerid, "There is no accessory on selected index!");

				new string[512];
				toySelect[playerid] = listitem;
				if(pToys[playerid][listitem][E_TOY_TYPE] == ACC_HAIRCUT)
					format(string, sizeof(string), "Place %s", (!toyToggle[playerid][toySelect[playerid]]) ? ("On") : ("Off"));
				else
					format(string, sizeof(string), "Place %s\nChange Bone\nChange Placement\nRemove", (!toyToggle[playerid][toySelect[playerid]]) ? ("On") : ("Off"));

				ShowPlayerDialog(playerid, DIALOG_CLOTHEDIT, DIALOG_STYLE_LIST, sprintf("Accessories %d:", listitem), string, "Select", "Cancel");
			}
		}
		case DIALOG_CLOTHEDIT:
		{
			if(response)
			{
				switch(listitem)
				{
					case 0: // toggle attach
					{
						if(!toyToggle[playerid][toySelect[playerid]])
						{
							ShowBoxMessage(playerid, "Accessory attached", 5);

							SetPlayerAttachedObject(playerid,
							toySelect[playerid],
							pToys[playerid][toySelect[playerid]][E_TOY_MODEL],
							pToys[playerid][toySelect[playerid]][E_TOY_BONE],
							pToys[playerid][toySelect[playerid]][E_TOY_X],
							pToys[playerid][toySelect[playerid]][E_TOY_Y],
							pToys[playerid][toySelect[playerid]][E_TOY_Z],
							pToys[playerid][toySelect[playerid]][E_TOY_RX],
							pToys[playerid][toySelect[playerid]][E_TOY_RY],
							pToys[playerid][toySelect[playerid]][E_TOY_RZ],
							pToys[playerid][toySelect[playerid]][E_TOY_SX],
							pToys[playerid][toySelect[playerid]][E_TOY_SY],
							pToys[playerid][toySelect[playerid]][E_TOY_SZ]);

							toyToggle[playerid][toySelect[playerid]] = true;
						}
						else
						{
							RemovePlayerAttachedObject(playerid, toySelect[playerid]);
							ShowBoxMessage(playerid, "Accessory deattached", 5);

							toyToggle[playerid][toySelect[playerid]] = false;
						}
						SavePlayerToys(playerid);
					}
					case 1: // change bone
					{
					    ShowPlayerDialog(playerid, DIALOG_CLOTHBONE, DIALOG_STYLE_LIST, "Bone Selection:", "Spine\nHead\nLeft upper arm\nRight upper arm\nLeft hand\nRight hand\nLeft thigh\nRight thigh\nLeft foot\nRight foot\nRight calf\nLeft calf\nLeft forearm\nRight forearm\nLeft shoulder\nRight shoulder\nNeck\nJaw", "Choose", "Cancel");
					}
					case 2: // change placement
					{

						EditAttachedObject(playerid, toySelect[playerid]);

					}
					case 3:	//remove from list
					{
						if(IsPlayerAttachedObjectSlotUsed(playerid, toySelect[playerid]))
						{
							RemovePlayerAttachedObject(playerid, toySelect[playerid]);
						}
						pToys[playerid][toySelect[playerid]][E_TOY_MODEL] = 0;
						ShowBoxMessage(playerid, "Accessory removed!", 5);
						SavePlayerToys(playerid);
					}
				}
			}
		}
		case DIALOG_CLOTHBONE:
		{
			if(response)
			{
				pToys[playerid][toySelect[playerid]][E_TOY_BONE] = listitem + 1;
				if(toyToggle[playerid][toySelect[playerid]])
				{
					RemovePlayerAttachedObject(playerid, toySelect[playerid]);
				}
				SetPlayerAttachedObject(playerid,
						toySelect[playerid],
						pToys[playerid][toySelect[playerid]][E_TOY_MODEL],
						pToys[playerid][toySelect[playerid]][E_TOY_BONE],
						pToys[playerid][toySelect[playerid]][E_TOY_X],
						pToys[playerid][toySelect[playerid]][E_TOY_Y],
						pToys[playerid][toySelect[playerid]][E_TOY_Z],
						pToys[playerid][toySelect[playerid]][E_TOY_RX],
						pToys[playerid][toySelect[playerid]][E_TOY_RY],
						pToys[playerid][toySelect[playerid]][E_TOY_RZ],
						pToys[playerid][toySelect[playerid]][E_TOY_SX],
						pToys[playerid][toySelect[playerid]][E_TOY_SY],
						pToys[playerid][toySelect[playerid]][E_TOY_SZ]);
				SendServerMessage(playerid, "[Clothing] {cdd0d1}Accessories bone position now is {d7d292}%s{cdd0d1}", Bone_Name[listitem + 1]);
			}
		}
		case DIALOG_FIGHTSTYLE:
		{
			if(response)
			{
				switch(listitem)
				{
					case 0:
					{
						SetPlayerFightingStyle(playerid, 5);
						PlayerInfo[playerid][E_CHARACTER_FIGHTSTYLE] = 5;
						SendServerMessage(playerid, "[Business] {cdd0d1}You learn a fightstyle boxing for {B3C99E}$1,000{cdd0d1}.");
						GiveMoney(playerid, -1000);
					}	
					case 1:
					{
						SetPlayerFightingStyle(playerid, 7);
						PlayerInfo[playerid][E_CHARACTER_FIGHTSTYLE] = 7;
						SendServerMessage(playerid, "[Business] {cdd0d1}You learn a fightstyle KneeHead for {B3C99E}$2,500{cdd0d1}.");
						GiveMoney(playerid, -2500);
					}
					case 2:
					{
						SetPlayerFightingStyle(playerid, 15);
						PlayerInfo[playerid][E_CHARACTER_FIGHTSTYLE] = 15;
						SendServerMessage(playerid, "[Business] {cdd0d1}You learn a fightstyle GrabKick for {B3C99E}$3,000{cdd0d1}.");
						GiveMoney(playerid, -3000);
					}
					case 3:
					{
						SetPlayerFightingStyle(playerid, 4);
						PlayerInfo[playerid][E_CHARACTER_FIGHTSTYLE] = 4;
						SendServerMessage(playerid, "[Business] {cdd0d1}You reset a fightstyle for {B3C99E}$500{cdd0d1}.");
						GiveMoney(playerid, -500);
					}
				}
			}
			return 1;
		}
		case DIALOG_BUYCLOTHING:
		{
			if(response)
			{
				new slot = GetPlayerFreeToySlot(playerid);
				pToys[playerid][slot][E_TOY_MODEL] = PlayerInfo[playerid][E_CHARACTER_TEMPMODEL];
				pToys[playerid][slot][E_TOY_BONE] = listitem + 1;
				toyToggle[playerid][slot] = true;
				SetPlayerAttachedObject(playerid, slot, pToys[playerid][slot][E_TOY_MODEL], listitem + 1);
				SetCameraBehindPlayer(playerid);
			}
		}
		case DIALOG_MDC:
		{
			if (ReturnFactionType(playerid) != FACTION_TYPE_POLICE || !IsPoliceVehicle(GetPlayerVehicleID(playerid)))
				return 0;

			if (response)
			{
				switch (listitem)
				{
					case 0:
					{
						ShowPlayerDialog(playerid, DIALOG_MDC_NAMECH, DIALOG_STYLE_INPUT, "Place Charges:", "Please enter the name of the player:", "Search", "Back");
					}
					case 1:
					{
						ShowPlayerDialog(playerid, DIALOG_MDC_VIEW, DIALOG_STYLE_INPUT, "View Charges:", "Please enter the name of the player:", "Search", "Back");
					}
					case 2:
					{
						ShowPlayerDialog(playerid, DIALOG_MDC_PLATE, DIALOG_STYLE_INPUT, "View Plates:", "Please enter the vehicle plates:", "Search", "Back"); 
					}
				}
			}
		}
		case DIALOG_MDC_PLATE:
		{
			if(response)
			{
				new query[512];
				if(strlen(inputtext) > 6 || strlen(inputtext) < 3)
					return ShowPlayerDialog(playerid, DIALOG_MDC_PLATE, DIALOG_STYLE_INPUT, "View Plates:", "Please enter the vehicle plates:", "Search", "Back"); 
				
				format(PlayerInfo[playerid][E_CHARACTER_MDCPLAYER], 32, "%s", inputtext); 

				mysql_format(ourConnection, query, sizeof(query), "SELECT VehiclePlates FROM vehicles WHERE VehiclePlates LIKE '%%%e%%' LIMIT 5", PlayerInfo[playerid][E_CHARACTER_MDCPLAYER]); 
				mysql_pquery(ourConnection, query, "OnMDCPlate", "i", playerid); 
			}
		}
		case DIALOG_MDC_PLATELIST:
		{
			if(response)
			{
				new query[220];
				mysql_format(ourConnection, query, sizeof(query), "SELECT VehicleOwnerDBID, VehicleModel, VehicleImpounded FROM vehicles WHERE VehiclePlates = '%e'", PlayerPlateSaver[playerid][listitem]);
				mysql_pquery(ourConnection, query, "OnPlateSelect", "ii", playerid, listitem); 
			}
		}
		case DIALOG_MDC_NAMECH:
		{
			if (ReturnFactionType(playerid) != FACTION_TYPE_POLICE || !IsPoliceVehicle(GetPlayerVehicleID(playerid)))
				return 0;

			if (response)
			{
				if(strlen(inputtext) < 3 || strlen(inputtext) > 32)
					return ShowPlayerDialog(playerid, DIALOG_MDC_NAMECH, DIALOG_STYLE_INPUT, "Place Charges:", "Please enter the name of the player:", "Search", "Back"); 
					
				if(!ReturnDBIDFromName(inputtext))
					return ShowPlayerDialog(playerid, DIALOG_MDC_NAMECH, DIALOG_STYLE_INPUT, "Place Charges:", "Invalid user specified.\nPlease enter the name of the player:", "Search", "Back"); 
				
				format(PlayerInfo[playerid][E_CHARACTER_MDCPLAYER], 32, "%s", inputtext); 

				new str[512];
				format(str, sizeof(str), "Please enter the description of the crime committed by %s:", ReturnSettingsName(PlayerInfo[playerid][E_CHARACTER_MDCPLAYER], playerid));
				ShowPlayerDialog(playerid, DIALOG_MDC_PLACECH, DIALOG_STYLE_INPUT, "Place Charge:", str, "Search", "Back");
			}
			else
				ShowPlayerDialog(playerid, DIALOG_MDC, DIALOG_STYLE_LIST, "Mobile Data Computer:", "Place Charges\nView Chargers\nView Plates", "Select", "Cancel");

		}
		case DIALOG_MDC_PLACECH:
		{
			if (ReturnFactionType(playerid) != FACTION_TYPE_POLICE || !IsPoliceVehicle(GetPlayerVehicleID(playerid)))
				return 0;

			if (response)
			{
				if (isnull(inputtext))
				{
					new str[512];
					format(str, sizeof(str), "Please enter the description of the crime committed by %s:", ReturnSettingsName(PlayerInfo[playerid][E_CHARACTER_MDCPLAYER], playerid));
					return ShowPlayerDialog(playerid, DIALOG_MDC_PLACECH, DIALOG_STYLE_INPUT, "Place Charge:", str, "Enter", "Back");
				}
					
				AddWanted(PlayerInfo[playerid][E_CHARACTER_MDCPLAYER], inputtext);

				SendFactionMessage(playerid, "%s has placed a charge on %s for \"%s\".", ReturnSettingsName(playerid, playerid), PlayerInfo[playerid][E_CHARACTER_MDCPLAYER], inputtext);
				ShowPlayerDialog(playerid, DIALOG_MDC, DIALOG_STYLE_LIST, "Mobile Data Computer:", "Place Charges\nView Chargers\nView Plates", "Select", "Cancel");
			}
			else
			{
				ShowPlayerDialog(playerid, DIALOG_MDC, DIALOG_STYLE_LIST, "Mobile Data Computer:", "Place Charges\nView Chargers\nView Plates", "Select", "Cancel");
			}
		}
		case DIALOG_MDC_VIEW:
		{
			if (ReturnFactionType(playerid) != FACTION_TYPE_POLICE || !IsPoliceVehicle(GetPlayerVehicleID(playerid)))
				return 0;

			if (response)
			{
				if (isnull(inputtext) || strlen(inputtext) > 24)
					return ShowPlayerDialog(playerid, DIALOG_MDC_VIEW, DIALOG_STYLE_INPUT, "View Charges:", "Please enter the name of the player:", "Search", "Back");

				if (IsNumeric(inputtext) && IsPlayerConnected(strval(inputtext))) {
					ViewCharges(playerid, ReturnSettingsName(strval(inputtext), playerid));
				}
				else if (!IsNumeric(inputtext)) {
					ViewCharges(playerid, inputtext);
				}
				else {
					ShowPlayerDialog(playerid, DIALOG_MDC_VIEW, DIALOG_STYLE_INPUT, "View Charges:", "Invalid user specified.\nPlease enter the name of the player:", "Search", "Back");
				}
			}
		}

		case DIALOG_SECRETWORD_INPUT:
		{
			if(response)
			{
				if(AccountInfo[playerid][E_MASTERS_CODE] == strval(inputtext))
				{
					for(new i = 0; i < 20; i ++) { SendClientMessage(playerid, -1, " "); }	
					registerTime[playerid] = 1;	
					
					new str[1024];
					format(str, sizeof(str), "{ffffff}Welcome to {297183}Storylines{DEDEDE}, {FFFFFF}%s!\n\n{DEDEDE}Failure to authenticate three times will result in a {E03232}kick{DEDEDE}.\nYou have a total of {EEC650}five minutes{DEDEDE} to authenticate.\n\nIn order to proceed, enter a {EEC650}password{DEDEDE} below to authenticate (or register).", ReturnSettingsName(playerid, playerid));
					ShowPlayerDialog(playerid, DIALOG_REGISTER, DIALOG_STYLE_PASSWORD, "Register:", str, "Confirm", "");
				}
				else
				{
					return SendClientMessage(playerid, COLOR_RED, "[ACCESS DENIED]:{C8C8C8} You entered a bad security word. This was logged for security reasons.");
					//KickEx(playerid);
				}
			}
			else
			{
				return KickEx(playerid);
			}
		}
		case DIALOG_INVENTORY:
		{
			if(response)
	        {
			    new
			        name[512], id = -1;

	            strunpack(name, InventoryInfo[playerid][listitem][E_INVENTORY_ITEM]);
	            PlayerInfo[playerid][E_CHARACTER_LISTITEM] = listitem;

	            if(InventoryInfo[playerid][listitem][E_INVENTORY_QUANTITY] < 1)
	            	return SendErrorMessage(playerid, "There is no item on selected slot!");

				switch (PlayerInfo[playerid][E_CHARACTER_STORAGESELECT])
				{
				    case 0:
				    {
			            format(name, sizeof(name), "%s (%d):", name, InventoryInfo[playerid][listitem][E_INVENTORY_QUANTITY]);
			            ShowPlayerDialog(playerid, DIALOG_INVACTION, DIALOG_STYLE_LIST, name, "Equip Item\nUnequip Item\nGive Item\nDrop Item", "Select", "Cancel");
					}
					case 1:
					{
						if ((id = IsPlayerNearVehicle(playerid)) != -1 && !VehicleInfo[id][E_VEHICLE_LOCKED])
						{
							if(GetVehicleModel(id) == 459 || GetVehicleModel(id) == 482 || GetVehicleModel(id) == 440 || GetVehicleModel(id) == 413)
							{
								if (id == -1) {
									return SendErrorMessage(playerid, "You don't have anymore of this item to store!");
								}
								else if (InventoryInfo[playerid][listitem][E_INVENTORY_QUANTITY] == 1)
								{
									if(!strcmp(name, "Fabric Cargo") && VS_Count(id, "Fabric Cargo") >= 3 || !strcmp(name, "Steel Cargo") && VS_Count(id, "Steel Cargo") >= 3
									|| !strcmp(name, "Woods Cargo") && VS_Count(id, "Woods Cargo") >= 3 || !strcmp(name, "Foods Cargo") && VS_Count(id, "Foods Cargo") >= 3
									|| !strcmp(name, "Clothes Cargo") && VS_Count(id, "Clothes Cargo") >= 3 || !strcmp(name, "Appliances Cargo") && VS_Count(id, "Appliances Cargo") >= 3
									|| !strcmp(name, "Fish Cargo") && VS_Count(id, "Fish Cargo") >= 3)
										return SendErrorMessage(playerid, "You can't place cargo into your vehicle trunk is full.");

									VS_AddItem(id, name, InventoryInfo[playerid][listitem][E_INVENTORY_MODEL], 1);
									Inventory_Remove(playerid, name);
		
									ShowVehicleStorage(playerid, id);
								}
								else if (InventoryInfo[playerid][listitem][E_INVENTORY_QUANTITY] > 1) 
								{
									PlayerInfo[playerid][E_CHARACTER_LISTITEM] = id;

									new str[512];
									format(str, sizeof(str), "Item: %s (Quantity: %d)\n\nPlease enter the quantity that you wish to store for this item:", name, InventoryInfo[playerid][PlayerInfo[playerid][E_CHARACTER_LISTITEM]][E_INVENTORY_QUANTITY]);
									ShowPlayerDialog(playerid, DIALOG_VPLACE, DIALOG_STYLE_INPUT, "Vehicle Place:", str, "Store", "Back");
								}
							}
							else if(GetVehicleModel(id) == 499 || GetVehicleModel(id) == 414)
							{
								if (id == -1) {
									return SendErrorMessage(playerid, "You don't have anymore of this item to store!");
								}
								else if (InventoryInfo[playerid][listitem][E_INVENTORY_QUANTITY] == 1)
								{
									if(!strcmp(name, "Fabric Cargo") && VS_Count(id, "Fabric Cargo") >= 5 || !strcmp(name, "Steel Cargo") && VS_Count(id, "Steel Cargo") >= 5
									|| !strcmp(name, "Woods Cargo") && VS_Count(id, "Woods Cargo") >= 5 || !strcmp(name, "Foods Cargo") && VS_Count(id, "Foods Cargo") >= 5
									|| !strcmp(name, "Clothes Cargo") && VS_Count(id, "Clothes Cargo") >= 5 || !strcmp(name, "Appliances Cargo") && VS_Count(id, "Appliances Cargo") >= 5
									|| !strcmp(name, "Fish Cargo") && VS_Count(id, "Fish Cargo") >= 5)
										return SendErrorMessage(playerid, "You can't place cargo into your vehicle trunk is full.");

									VS_AddItem(id, name, InventoryInfo[playerid][listitem][E_INVENTORY_MODEL], 1);
									Inventory_Remove(playerid, name);
				
									ShowVehicleStorage(playerid, id);
								}
								else if (InventoryInfo[playerid][listitem][E_INVENTORY_QUANTITY] > 1) 
								{
									PlayerInfo[playerid][E_CHARACTER_LISTITEM] = id;

									new str[512];
									format(str, sizeof(str), "Item: %s (Quantity: %d)\n\nPlease enter the quantity that you wish to store for this item:", name, InventoryInfo[playerid][PlayerInfo[playerid][E_CHARACTER_LISTITEM]][E_INVENTORY_QUANTITY]);
									ShowPlayerDialog(playerid, DIALOG_VPLACE, DIALOG_STYLE_INPUT, "Vehicle Place:", str, "Store", "Back");
								}
							}
							else if(GetVehicleModel(id) == 456)
							{
								if (id == -1) {
									return SendErrorMessage(playerid, "You don't have anymore of this item to store!");
								}
								else if (InventoryInfo[playerid][listitem][E_INVENTORY_QUANTITY] == 1)
								{
									if(!strcmp(name, "Fabric Cargo") && VS_Count(id, "Fabric Cargo") >= 8 || !strcmp(name, "Steel Cargo") && VS_Count(id, "Steel Cargo") >= 8
									|| !strcmp(name, "Woods Cargo") && VS_Count(id, "Woods Cargo") >= 8 || !strcmp(name, "Foods Cargo") && VS_Count(id, "Foods Cargo") >= 8
									|| !strcmp(name, "Clothes Cargo") && VS_Count(id, "Clothes Cargo") >= 8 || !strcmp(name, "Appliances Cargo") && VS_Count(id, "Appliances Cargo") >= 8
									|| !strcmp(name, "Fish Cargo") && VS_Count(id, "Fish Cargo") >= 8)
										return SendErrorMessage(playerid, "You can't place cargo into your vehicle trunk is full.");

									VS_AddItem(id, name, InventoryInfo[playerid][listitem][E_INVENTORY_MODEL], 1);
									Inventory_Remove(playerid, name);
					
									ShowVehicleStorage(playerid, id);
								}
								else if (InventoryInfo[playerid][listitem][E_INVENTORY_QUANTITY] > 1) 
								{
									PlayerInfo[playerid][E_CHARACTER_LISTITEM] = id;

									new str[512];
									format(str, sizeof(str), "Item: %s (Quantity: %d)\n\nPlease enter the quantity that you wish to store for this item:", name, InventoryInfo[playerid][PlayerInfo[playerid][E_CHARACTER_LISTITEM]][E_INVENTORY_QUANTITY]);
									ShowPlayerDialog(playerid, DIALOG_VPLACE, DIALOG_STYLE_INPUT, "Vehicle Place:", str, "Store", "Back");
								}
							}
							else if(GetVehicleModel(id) == 455)
							{
								if (id == -1) {
									return SendErrorMessage(playerid, "You don't have anymore of this item to store!");
								}
								else if (InventoryInfo[playerid][listitem][E_INVENTORY_QUANTITY] == 1)
								{
									if(!strcmp(name, "Fabric Cargo") && VS_Count(id, "Fabric Cargo") >= 10 || !strcmp(name, "Steel Cargo") && VS_Count(id, "Steel Cargo") >= 10
									|| !strcmp(name, "Woods Cargo") && VS_Count(id, "Woods Cargo") >= 10 || !strcmp(name, "Foods Cargo") && VS_Count(id, "Foods Cargo") >= 10
									|| !strcmp(name, "Clothes Cargo") && VS_Count(id, "Clothes Cargo") >= 10 || !strcmp(name, "Appliances Cargo") && VS_Count(id, "Appliances Cargo") >= 10
									|| !strcmp(name, "Fish Cargo") && VS_Count(id, "Fish Cargo") >= 10)
										return SendErrorMessage(playerid, "You can't place cargo into your vehicle trunk is full.");

									VS_AddItem(id, name, InventoryInfo[playerid][listitem][E_INVENTORY_MODEL], 1);
									Inventory_Remove(playerid, name);
					
									ShowVehicleStorage(playerid, id);
								}
								else if (InventoryInfo[playerid][listitem][E_INVENTORY_QUANTITY] > 1) 
								{
									PlayerInfo[playerid][E_CHARACTER_LISTITEM] = id;

									new str[512];
									format(str, sizeof(str), "Item: %s (Quantity: %d)\n\nPlease enter the quantity that you wish to store for this item:", name, InventoryInfo[playerid][PlayerInfo[playerid][E_CHARACTER_LISTITEM]][E_INVENTORY_QUANTITY]);
									ShowPlayerDialog(playerid, DIALOG_VPLACE, DIALOG_STYLE_INPUT, "Vehicle Place:", str, "Store", "Back");
								}
							}
							//Lumberjack
							else if(GetVehicleModel(id) == 422 || GetVehicleModel(id) == 478 || GetVehicleModel(id) == 554 || GetVehicleModel(id) == 543)
							{
								if (id == -1) {
									return SendErrorMessage(playerid, "You don't have anymore of this item to store!");
								}
								else if (InventoryInfo[playerid][listitem][E_INVENTORY_QUANTITY] == 1)
								{
									if(!strcmp(name, "Woods") && VS_Count(id, "Woods") >= 3)
										return SendErrorMessage(playerid, "You can't place woods into your vehicle trunk is full.");

									VS_AddItem(id, name, InventoryInfo[playerid][listitem][E_INVENTORY_MODEL], 1);
									Inventory_Remove(playerid, name);
									VehicleObjectUpdates(id);
									ShowVehicleStorage(playerid, id);
								}
								else if (InventoryInfo[playerid][listitem][E_INVENTORY_QUANTITY] > 1) 
								{
									PlayerInfo[playerid][E_CHARACTER_LISTITEM] = id;

									new str[512];
									format(str, sizeof(str), "Item: %s (Quantity: %d)\n\nPlease enter the quantity that you wish to store for this item:", name, InventoryInfo[playerid][PlayerInfo[playerid][E_CHARACTER_LISTITEM]][E_INVENTORY_QUANTITY]);
									ShowPlayerDialog(playerid, DIALOG_VPLACE, DIALOG_STYLE_INPUT, "Vehicle Place:", str, "Store", "Back");
								}
							}
							else
							{
								if (InventoryInfo[playerid][listitem][E_INVENTORY_QUANTITY] == 1)
								{
									VS_AddItem(id, name, InventoryInfo[playerid][listitem][E_INVENTORY_MODEL], 1);
									Inventory_Remove(playerid, name);
									ShowVehicleStorage(playerid, id);
								}
								else 
								{
									new str[512];
									format(str, sizeof(str), "Item: %s (Quantity: %d)\n\nPlease enter the quantity that you wish to store for this item:", name, InventoryInfo[playerid][PlayerInfo[playerid][E_CHARACTER_LISTITEM]][E_INVENTORY_QUANTITY]);
									ShowPlayerDialog(playerid, DIALOG_VPLACE, DIALOG_STYLE_INPUT, "Vehicle Place:", str, "Store", "Back");
								}
							}
						}
						PlayerInfo[playerid][E_CHARACTER_STORAGESELECT] = 0;
					}
					case 2:
					{
						if ((id = IsPlayerInProperty(playerid)) != -1 && (PropertyInfo[id][E_PROPERTY_OWNERDBID] == PlayerInfo[playerid][E_CHARACTER_DBID]))
						{
							if (InventoryInfo[playerid][listitem][E_INVENTORY_QUANTITY] == 1)
							{
								Property_AddItem(id, name, InventoryInfo[playerid][listitem][E_INVENTORY_MODEL], 1);
								Inventory_Remove(playerid, name);

								Property_ShowItems(playerid, id);
							}
							else 
							{
								new str[512];
								format(str, sizeof(str), "Item: %s (Quantity: %d)\n\nPlease enter the quantity that you wish to store for this item:", name, InventoryInfo[playerid][PlayerInfo[playerid][E_CHARACTER_LISTITEM]][E_INVENTORY_QUANTITY]);
								Dialog_Show(playerid, PropertyDeposit, DIALOG_STYLE_INPUT, "Property Safe Place:", str, "Store", "Back");
							}
						}
						PlayerInfo[playerid][E_CHARACTER_STORAGESELECT] = 0;
					}
				}
			}
		}
		case DIALOG_INVACTION:
		{
			if(response)
		    {
			    new
					itemid = PlayerInfo[playerid][E_CHARACTER_LISTITEM],
					string[1024],
					str[1024];

			    strunpack(string, InventoryInfo[playerid][itemid][E_INVENTORY_ITEM]);

			    switch (listitem)
			    {
			        case 0:
			        {
			            CallLocalFunction("OnPlayerUseItem", "dds", playerid, itemid, string);
			        }
					case 1:
					{
						ResetVarInventory(playerid);
					}
			        case 2:
			        {
						if(PlayerInfo[playerid][E_CHARACTER_EQUIPITEMS] > INVENTORY_NONE)
							return SendErrorMessage(playerid, "You must store your items in inventory first.");

					    if(!strcmp(string, "Cellphone"))
					        return SendErrorMessage(playerid, "You can't do that on this item!");

					    if(!strcmp(string, "Portable Radio"))
					        return SendErrorMessage(playerid, "You can't do that on this item!");

					    if(!strcmp(string, "Mask"))
					        return SendErrorMessage(playerid, "You can't do that on this item!");

						PlayerInfo[playerid][E_CHARACTER_LISTITEM] = itemid;
						ShowPlayerDialog(playerid, DIALOG_INVGIVE, DIALOG_STYLE_INPUT, "Give Item:", "Please enter the name or the ID of the player:", "Submit", "Cancel");
			        }
			        case 3:
			        {
			            if (IsPlayerInAnyVehicle(playerid))
			                return SendErrorMessage(playerid, "You can't drop items right now.");

					    if(!strcmp(string, "Cellphone"))
					        return SendErrorMessage(playerid, "You can't do that on this item!");

					    if(!strcmp(string, "Portable Radio"))
					        return SendErrorMessage(playerid, "You can't do that on this item!");

					    if(!strcmp(string, "Mask"))
					        return SendErrorMessage(playerid, "You can't do that on this item!");
					    
						else if (InventoryInfo[playerid][itemid][E_INVENTORY_QUANTITY] == 1)
						{
							DropPlayerItem(playerid, itemid);						
						}
						else
							format(str, sizeof(str), "Item: %s - Quantity: %d\n\nPlease specify how much of this item you wish to drop:", string, InventoryInfo[playerid][itemid][E_INVENTORY_QUANTITY]),
							ShowPlayerDialog(playerid, DIALOG_DROPITEM, DIALOG_STYLE_INPUT, "Drop Item:", str, "Drop", "Cancel");
					}
				}
			}
		}
		case DIALOG_INVGIVE:
		{
			if (response)
			{
			    static
			        userid = -1,
					itemid = -1,
					string[32];

				if (sscanf(inputtext, "u", userid))
				    return ShowPlayerDialog(playerid, DIALOG_INVGIVE, DIALOG_STYLE_INPUT, "Give Item:", "Please enter the name or the ID of the player:", "Submit", "Cancel");

				if (userid == INVALID_PLAYER_ID)
				    return ShowPlayerDialog(playerid, DIALOG_INVGIVE, DIALOG_STYLE_INPUT, "Give Item:", "ERROR: Invalid player specified.\n\nPlease enter the name or the ID of the player:", "Submit", "Cancel");

			    if (!IsPlayerNearPlayer(playerid, userid, 6.0))
					return ShowPlayerDialog(playerid, DIALOG_INVGIVE, DIALOG_STYLE_INPUT, "Give Item:", "ERROR: You are not near that player.\n\nPlease enter the name or the ID of the player:", "Submit", "Cancel");

			    if (userid == playerid)
					return ShowPlayerDialog(playerid, DIALOG_INVGIVE, DIALOG_STYLE_INPUT, "Give Item:", "ERROR: You can't give items to yourself.\n\nPlease enter the name or the ID of the player:", "Submit", "Cancel");

				itemid = PlayerInfo[playerid][E_CHARACTER_LISTITEM];

				if (itemid == -1)
				    return 0;

				strunpack(string, InventoryInfo[playerid][itemid][E_INVENTORY_ITEM]);

				if (InventoryInfo[playerid][itemid][E_INVENTORY_QUANTITY] == 1)
				{
				    new id = Inventory_Add(userid, string, InventoryInfo[playerid][itemid][E_INVENTORY_MODEL]);

				    if (id == -1)
						return SendErrorMessage(playerid, "That player doesn't have anymore inventory slots.");

				    SendNearbyMessage(playerid, 30.0, COLOR_EMOTE, "* %s takes out a \"%s\" and gives it to %s.", ReturnSettingsName(playerid, playerid), string, ReturnSettingsName(userid, playerid));
				    SendInfoMessage(userid, "{d7d292}%s{cdd0d1} has given you {d7d292}%s{cdd0d1} (added to inventory).", ReturnSettingsName(playerid, playerid), string);

					Inventory_Remove(playerid, string);
		  		}
				else
				{
					new str[152];
					format(str, sizeof(str), "Item: %s (Amount: %d)\n\nPlease enter the amount of this item you wish to give %s:", string, InventoryInfo[playerid][itemid][E_INVENTORY_QUANTITY], ReturnSettingsName(userid, playerid));
				    ShowPlayerDialog(playerid, DIALOG_INVGIVEAMOUNT, DIALOG_STYLE_INPUT, "Give Item:", str, "Give", "Cancel");
				    PlayerInfo[playerid][E_CHARACTER_TARGET] = userid;
				}
			}
		}
		case DIALOG_DROPITEM:
		{
			if(response)
		    {
				new
				    itemid = PlayerInfo[playerid][E_CHARACTER_LISTITEM],
				    string[32],
					str[356];

				strunpack(string, InventoryInfo[playerid][itemid][E_INVENTORY_ITEM]);

				if (response)
				{
				    if (isnull(inputtext))
				    	return format(str, sizeof(str), "Drop Item", "Item: %s - Quantity: %d\n\nPlease specify how much of this item you wish to drop:", string, InventoryInfo[playerid][itemid][E_INVENTORY_QUANTITY]),
						ShowPlayerDialog(playerid, DIALOG_DROPITEM, DIALOG_STYLE_INPUT, "Drop Item", str, "Drop", "Cancel");

					if (strval(inputtext) < 1 || strval(inputtext) > InventoryInfo[playerid][itemid][E_INVENTORY_QUANTITY])
					    return format(str, sizeof(str), "ERROR: Insufficient amount specified.\n\nItem: %s - Quantity: %d\n\nPlease specify how much of this item you wish to drop:", string, InventoryInfo[playerid][itemid][E_INVENTORY_QUANTITY]),
						ShowPlayerDialog(playerid, DIALOG_DROPITEM, DIALOG_STYLE_INPUT, "Drop Item:", str, "Drop", "Cancel");

					
					DropPlayerItem(playerid, itemid, strval(inputtext));
				}
			}
		}
		case DIALOG_INVGIVEAMOUNT:
		{
			if (response && PlayerInfo[playerid][E_CHARACTER_TARGET] != INVALID_PLAYER_ID)
			{
			    new
			        userid = PlayerInfo[playerid][E_CHARACTER_TARGET],
			        itemid = PlayerInfo[playerid][E_CHARACTER_LISTITEM],
					string[32],
					str[352];

				strunpack(string, InventoryInfo[playerid][itemid][E_INVENTORY_ITEM]);

				if (isnull(inputtext))
					return format(str, sizeof(str), "Item: %s (Amount: %d)\n\nPlease enter the amount of this item you wish to give %s:", string, InventoryInfo[playerid][itemid][E_INVENTORY_QUANTITY], ReturnSettingsName(userid, playerid)),
					ShowPlayerDialog(playerid, DIALOG_INVGIVEAMOUNT, DIALOG_STYLE_INPUT, "Give Item", str, "Give", "Cancel");

				if (strval(inputtext) < 1 || strval(inputtext) > InventoryInfo[playerid][itemid][E_INVENTORY_QUANTITY])
				    return format(str, sizeof(str), "ERROR: You don't have that much.\n\nItem: %s (Amount: %d)\n\nPlease enter the amount of this item you wish to give %s:", string, InventoryInfo[playerid][itemid][E_INVENTORY_QUANTITY], ReturnSettingsName(userid, playerid)),
					ShowPlayerDialog(playerid, DIALOG_INVGIVEAMOUNT, DIALOG_STYLE_INPUT, "Give Item:", str, "Give", "Cancel");

		        new id = Inventory_Add(userid, string, InventoryInfo[playerid][itemid][E_INVENTORY_MODEL], strval(inputtext));

			    if (id == -1)
					return SendErrorMessage(playerid, "That player doesn't have anymore inventory slots.");

			    SendNearbyMessage(playerid, 30.0, COLOR_EMOTE, "* %s takes out a \"%s\" and gives it to %s.", ReturnSettingsName(playerid, playerid), string, ReturnSettingsName(userid, playerid));
			    SendInfoMessage(userid, "{d7d292}%s{cdd0d1} has given you {d7d292}%s{cdd0d1} (added to inventory).", ReturnSettingsName(playerid, playerid), string);

				Inventory_Remove(playerid, string, strval(inputtext));
			}
		}
		case DIALOG_PICKUPITEM:
		{
			new
		    string[64];

			if (response)
			{
			    new id = NearestItems[playerid][listitem];

				if (id != -1 && DroppedInfo[id][E_DROPPED_MODEL])
				{
					if (PickupItem(playerid, id))
					{
						format(string, sizeof(string), "%s added to inventory!", DroppedInfo[id][E_DROPPED_ITEM]);
		 				ShowBoxMessage(playerid, string, 5);
					}
					else
						SendErrorMessage(playerid, "You don't have any room in your inventory.");
				}
				else SendErrorMessage(playerid, "This item was already picked up.");
			}
		}
		case DIALOG_HELP:
		{
			if (response)
			{
			    switch (listitem)
			    {
			        case 0:
			        {
						SendClientMessage(playerid, COLOR_DARKGREEN, "|__________ General Commands __________|");
						SendClientMessage(playerid, COLOR_ORANGE, "/stats, /admins, /report, /o(oc), /pay, /isafk, /time, /levelup, /rcp, /inventory");
						SendClientMessage(playerid, COLOR_ORANGE, "/enter, /exit, /mask, /setchannel, /setslot, /radio, /licenseexam, /unimpound");
						SendClientMessage(playerid, COLOR_ORANGE, "/damages, /acceptdeath, /helpup, /fixr, /respawnme, /setspawn, /settings, /approve");
			        	SendClientMessage(playerid, COLOR_ORANGE, "/coin, /dice, /gascan, /repairkits, /cursor");
					}
					case 1:
					{
						SendClientMessage(playerid, COLOR_DARKGREEN, "|__________ Roleplay Commands __________|");
						SendClientMessage(playerid, COLOR_ORANGE, "/me, /do, /ame, /my, /amy, /s(hout), /l(ow), /b, /pm, /deposit, /withdraw");
						SendClientMessage(playerid, COLOR_ORANGE, "/balance, /license, /animhelp, /handshake, /frisk");
					}
					case 2:
					{
						SendClientMessage(playerid, COLOR_DARKGREEN, "|__________ Property Commands __________|");
						SendClientMessage(playerid, COLOR_ORANGE, "/buyproperty, /lock, /property");
					}
					case 3:
					{
						SendClientMessage(playerid, COLOR_DARKGREEN, "|__________ Business Commands __________|");
						SendClientMessage(playerid, COLOR_ORANGE, "/buybiz, /lock, /bizinfo, /bizfee, /bizcash, /sellbiz");
					}
					case 4:
					{
						SendClientMessage(playerid, COLOR_DARKGREEN, "|__________ Faction Commands __________|");
						SendClientMessage(playerid, COLOR_ORANGE, "/factionhelp, /factions, /f, /factionon");

						if(ReturnFactionType(playerid) == FACTION_TYPE_POLICE)
						{
							SendClientMessage(playerid, COLOR_ORANGE, "/fduty, /offduty, /handcuff, /unhandcuff, /badge, /flocker, /m(egaphone), /(dep)artment,");
							SendClientMessage(playerid, COLOR_ORANGE, "/carsign, /remove_carsign, /tazer, /take, /givelicense, /impound, /checkvehicle, /mdc");
						}
						if(ReturnFactionType(playerid) == FACTION_TYPE_MEDICAL)
						{
							SendClientMessage(playerid, COLOR_ORANGE, "/fduty, /offduty, /flocker, /m(egaphone), /(dep)artment,");
							SendClientMessage(playerid, COLOR_ORANGE, "/dropinjured, /loadinjured, /rescue");
						}
						if(PlayerInfo[playerid][E_CHARACTER_FACTIONRANK] == 4)
						{
							SendClientMessage(playerid, COLOR_ORANGE, "/finvite, /funinvite, /founinvite, /frank.");
						}
					}
					case 5:
					{
						SendClientMessage(playerid, COLOR_DARKGREEN, "|__________ Vehicle Commands __________|");
						SendClientMessage(playerid, COLOR_ORANGE, "/mycars, /engine, /carlock, /carkey, /carsell, /cardespawn, /cartrunk, /carhood");
						SendClientMessage(playerid, COLOR_ORANGE, "/carlights, /carfind, /carradio, /carscrap, /carwhisper, /carb, /refill");
					}
					case 6:
					{
						SendClientMessage(playerid, COLOR_DARKGREEN, "|__________ Minigames Commands __________|");
						SendClientMessage(playerid, COLOR_ORANGE, "/court, /resetcourt");
					}
					case 7:
					{
						SendClientMessage(playerid, COLOR_DARKGREEN, "|__________ Jobs Commands __________|");
						SendClientMessage(playerid, COLOR_ORANGE, "/takejobs, /quitjobs, /jobduty, /loadcargo, /storecargo");
						SendClientMessage(playerid, COLOR_ORANGE, "/collectgarbage, /dumpgarbage");
						SendClientMessage(playerid, COLOR_ORANGE, "/fish, /sellfish, /buybait");
						SendClientMessage(playerid, COLOR_ORANGE, "Press 'ALT' collect garbage");
						if(PlayerInfo[playerid][E_CHARACTER_JOBS] == JOB_TRUCKER)
						{
							SendClientMessage(playerid, COLOR_ORANGE, "/tpda, /cargobuy, /cargosell, /cargodrop");
							SendTipMessage(playerid, "Type '/cartrunk' to place cargo into truck.");
						}
						if(PlayerInfo[playerid][E_CHARACTER_JOBS] == JOB_LUMBERJACK)
						{
							SendClientMessage(playerid, COLOR_ORANGE, "/buyaxe, /timbercut, /timbersell");
							SendTipMessage(playerid, "Press 'ALT' to cutting tree(s) using axe.");
						}
						if(PlayerInfo[playerid][E_CHARACTER_JOBS] == JOB_TAXI)
						{
							SendClientMessage(playerid, COLOR_ORANGE, "/jobduty, /taxicall");
							SendTipMessage(playerid, "Taxi fare will change every 50 meters of distance.");
						}
						if(PlayerInfo[playerid][E_CHARACTER_JOBS] == JOB_MECHANIC)
						{
							SendClientMessage(playerid, COLOR_ORANGE, "/jobduty, /mechmenu");
							SendTipMessage(playerid, "Repairing, Repaint vehicles and maintenace road safety.");
						}
						if(PlayerInfo[playerid][E_CHARACTER_JOBS] == JOB_SMUGGLER)
						{
							SendClientMessage(playerid, COLOR_ORANGE, "/findpacket, /storepacket");
							SendTipMessage(playerid, "Press 'ALT' to pickup packet.");
						}
					}
					case 8:
					{
						SendClientMessage(playerid, COLOR_DARKGREEN, "|__________ Crime Profesions Commands __________|");
						SendClientMessage(playerid, COLOR_ORANGE, "/extort, /extortions, /drugsdeal, /buydrugs, /buymats, /creategun, /production");
						SendTipMessage(playerid, "Hold aim into actor/npc to start robbery business.");
						SendTipMessage(playerid, "Press LMB (punch) into actor/npc to start extortions business.");
					}
			    }
			}
		}
		case DIALOG_SELLFISH:
		{
			if(response)
		    {
		        new total = 0;
		        if(Inventory_Count(playerid, "Fish") != 0)
		        {
		            total += FISHING_SALARY * floatround(Inventory_Count(playerid, "Fish"), floatround_round);

					Inventory_Set(playerid, "Fish", 19630, 0);
				}
				GiveMoney(playerid, total);
				SendServerMessage(playerid, "[Fishing] {cdd0d1}You have sold all the fish and earn {B3C99E}$%s{cdd0d1}.", FormatMoney(total));
			}
		}
		case DIALOG_SETTINGS:
		{
			if (response)
			{
				switch(listitem)
				{
					case 0:
					{
						if(PlayerInfo[playerid][E_CHARACTER_TOGHUD])
						{
							PlayerInfo[playerid][E_CHARACTER_TOGHUD] = false;
							SendServerMessage(playerid, "[Settings] {cdd0d1}Streets TextDraws has been Enable.");
						}
						else
						{
							PlayerInfo[playerid][E_CHARACTER_TOGHUD] = true;
							SendServerMessage(playerid, "[Fishing] {cdd0d1}Streets TextDraws has been Disable.");
						}
					}
					case 1:
					{
						if(PlayerInfo[playerid][E_CHARACTER_TOGJOIN])
						{
							PlayerInfo[playerid][E_CHARACTER_TOGJOIN] = false;
							SendServerMessage(playerid, "[Settings] {cdd0d1}Joined Logs has been Enable.");
						}
						else
						{
							PlayerInfo[playerid][E_CHARACTER_TOGJOIN] = true;
							SendServerMessage(playerid, "[Settings] {cdd0d1}Joined Logs has been Disable.");
						}
					}
					case 2:
					{
						if(PlayerInfo[playerid][E_CHARACTER_TOGADMIN])
						{
							PlayerInfo[playerid][E_CHARACTER_TOGADMIN] = false;
							SendServerMessage(playerid, "[Settings] {cdd0d1}Admin Messages has been Enable.");
						}
						else
						{
							PlayerInfo[playerid][E_CHARACTER_TOGADMIN] = true;
							SendServerMessage(playerid, "[Settings] {cdd0d1}Admin Messages has been Disable.");
						}
					}
					case 3:
					{
						if(PlayerInfo[playerid][E_CHARACTER_TOGFMS])
						{
							PlayerInfo[playerid][E_CHARACTER_TOGFMS] = false;
							SendServerMessage(playerid, "[Settings] {cdd0d1}Faction Messages has been Enable.");
						}
						else
						{
							PlayerInfo[playerid][E_CHARACTER_TOGFMS] = true;
							SendServerMessage(playerid, "[Settings] {cdd0d1}Faction Messages has been Disable.");
						}
					}
					case 4:
					{
						if(PlayerInfo[playerid][E_CHARACTER_TOGPMS])
						{
							PlayerInfo[playerid][E_CHARACTER_TOGPMS] = false;
							SendServerMessage(playerid, "[Settings] {cdd0d1}Private Messages has been Enable.");
						}
						else
						{
							PlayerInfo[playerid][E_CHARACTER_TOGPMS] = true;
							SendServerMessage(playerid, "[Settings] {cdd0d1}Private Messages has been Disable.");
						}
					}
					case 5:
					{
						if(PlayerInfo[playerid][E_CHARACTER_TOGDMS])
						{
							PlayerInfo[playerid][E_CHARACTER_TOGDMS] = false;
							SendServerMessage(playerid, "[Settings] {cdd0d1}Damages Messages has been Enable.");
						}
						else
						{
							PlayerInfo[playerid][E_CHARACTER_TOGDMS] = true;
							SendServerMessage(playerid, "[Settings] {cdd0d1}Damages Messages has been Disable.");
						}
					}
					case 6:
					{
						if(PlayerInfo[playerid][E_CHARACTER_TOGNAMESTYLE])
						{
							PlayerInfo[playerid][E_CHARACTER_TOGNAMESTYLE] = false;
							UpdateTabListForPlayer(playerid);
							SendServerMessage(playerid, "[Settings] {cdd0d1}switched your namestyle to streetnames tags.");
						}
						else
						{
							PlayerInfo[playerid][E_CHARACTER_TOGNAMESTYLE] = true;
							UpdateTabListForPlayer(playerid);
							SendServerMessage(playerid, "[Settings] {cdd0d1}switched your namestyle to Firstname_Lastname.");
						}
					}
					case 7:
					{
						if(PlayerInfo[playerid][E_CHARACTER_TOGDD])
						{
							PlayerInfo[playerid][E_CHARACTER_TOGDD] = false;
							SendServerMessage(playerid, "[Settings] {cdd0d1}Draw Distance has been set to Low.");
							Streamer_SetVisibleItems(STREAMER_TYPE_OBJECT, 5000, playerid);
						}
						else
						{
							PlayerInfo[playerid][E_CHARACTER_TOGDD] = true;
							SendServerMessage(playerid, "[Settings] {cdd0d1}Draw Distance has been set to High.");
							Streamer_SetVisibleItems(STREAMER_TYPE_OBJECT, 10000, playerid);
						}
					}
				}
			}
		}
		case DIALOG_RADIO:
		{
			if (response)
			{
				switch(listitem)
				{
					case 0:
					{
						ShowPlayerDialog(playerid, DIALOG_ADDURL, DIALOG_STYLE_INPUT, "Radio Stations:", "Type a song or radio station URL.\nNote that year we roleplay in 1990.", "Input", "Close");
					}
					case 2:
					{
						StopAudioStreamForPlayer(playerid);
						VehicleInfo[GetPlayerVehicleID(playerid)][E_VEHICLE_RADIO] = false;
					}
				}
			}
		}
		case DIALOG_ADDURL:
		{
			if(response)
			{
				if (isnull(inputtext))
				{
					ShowPlayerDialog(playerid, DIALOG_ADDURL, DIALOG_STYLE_INPUT, "Radio Stations:", "Type a song or radio station URL.\nNote that year we roleplay in 1990.", "Input", "Close");
				}

				format(VehicleInfo[GetPlayerVehicleID(playerid)][E_VEHICLE_RADIOURL], 128, inputtext);
				PlayAudioStreamForPlayer(playerid, inputtext);
				VehicleInfo[GetPlayerVehicleID(playerid)][E_VEHICLE_RADIO] = true;
			}
		}

		//Drugs Deal
		case DIALOG_DRUGSDEALTYPE1: //Hispanic Gangs
		{
			if(response)
			{
				new Float:x, Float:y, Float:z, Float:a;
				GetPlayerPos(playerid, x, y, z);
				GetPlayerFacingAngle(playerid, a);

				switch(listitem)
				{
					case 0: //Crack, Marijuana
					{
						new type = randomEx(1,2);
						if(!PlayerInfo[playerid][E_CHARACTER_FACTION])
							return SendErrorMessage(playerid, "You are not apart a gang members");

						if(FactionInfo[PlayerInfo[playerid][E_CHARACTER_FACTION]][E_FACTION_TYPE] != FACTION_TYPE_ILLEGAL)
							return SendErrorMessage(playerid, "You can't buy because you are not apart in a gang."); 

						SetTimerEx("DrugsDealing", 15000, false, "iiffff", playerid, type, x, y, z ,a);
						SendServerMessage(playerid, "[Drugs Dealer] {cdd0d1}You've opened drugs corner at %s, it will run for 15 minutes.", ReturnLocationStreet(playerid));
					}
					case 1: //Heroin
					{
						new type = 3;
						if(!PlayerInfo[playerid][E_CHARACTER_FACTION])
							return SendErrorMessage(playerid, "You are not apart a gang members");

						if(FactionInfo[PlayerInfo[playerid][E_CHARACTER_FACTION]][E_FACTION_TYPE] != FACTION_TYPE_ILLEGAL)
							return SendErrorMessage(playerid, "You can't buy because you are not apart in a gang."); 

						SetTimerEx("DrugsDealing", 15000, false, "iiffff", playerid, type, x, y, z ,a);
						SendServerMessage(playerid, "[Drugs Dealer] {cdd0d1}You've opened drugs corner at {d7d292}%s{cdd0d1}, it will run for 15 minutes.", ReturnLocationStreet(playerid));
					}
				}
			}
		}
		case DIALOG_DRUGSDEALTYPE2: //Black Gangs
		{
			if(response)
			{
				new Float:x, Float:y, Float:z, Float:a;
				GetPlayerPos(playerid, x, y, z);
				GetPlayerFacingAngle(playerid, a);
				switch(listitem)
				{
					case 0: //Crack, Marijuana
					{
						new type = randomEx(1,2);
						if(!PlayerInfo[playerid][E_CHARACTER_FACTION])
							return SendErrorMessage(playerid, "You are not apart a gang members");

						if(FactionInfo[PlayerInfo[playerid][E_CHARACTER_FACTION]][E_FACTION_TYPE] != FACTION_TYPE_ILLEGAL)
							return SendErrorMessage(playerid, "You can't buy because you are not apart in a gang."); 

						SetTimerEx("DrugsDealing", 15000, false, "iiffff", playerid, type, x, y, z ,a);
						SendServerMessage(playerid, "[Drugs Dealer] {cdd0d1}You've opened drugs corner at {d7d292}%s{cdd0d1}, it will run for 15 minutes.", ReturnLocationStreet(playerid));
					}
					case 1: //PCP
					{
						new type = 4;
						if(!PlayerInfo[playerid][E_CHARACTER_FACTION])
							return SendErrorMessage(playerid, "You are not apart a gang members");

						if(FactionInfo[PlayerInfo[playerid][E_CHARACTER_FACTION]][E_FACTION_TYPE] != FACTION_TYPE_ILLEGAL)
							return SendErrorMessage(playerid, "You can't buy because you are not apart in a gang."); 

						SetTimerEx("DrugsDealing", 15000, false, "iiffff", playerid, type, x, y, z ,a);
						SendServerMessage(playerid, "[Drugs Dealer] {cdd0d1}You've opened drugs corner at {d7d292}%s{cdd0d1}, it will run for 15 minutes.", ReturnLocationStreet(playerid));
					}
				}
			}	
		}
		case DIALOG_DRUGSDEAL:
		{
			if(response)
			{
				if(IsPlayerNearDrugsDealing(playerid))
				{
					if(DrugsDealerType[playerid] == 1)
					{
						new cost = DrugsDealerAmount[playerid] * 350;
						if(!Inventory_Count(playerid, "Cocaine Crack"))
							return SendErrorMessage(playerid, "You don't have any crack in inventory.");

						if(Inventory_Count(playerid, "Cocaine Crack") < DrugsDealerAmount[playerid])
							return SendErrorMessage(playerid, "You need at least %d grams of crack.", DrugsDealerAmount[playerid]);

						Inventory_Remove(playerid, "Cocaine Crack", DrugsDealerAmount[playerid]);
						GiveMoney(playerid, cost);
						SendServerMessage(playerid, "[Drugs Dealer] {cdd0d1}You've received {B3C99E}$%d{cdd0d1} from selling crack.", cost);

						//SetDynamicActorAngleToPlayer(DrugsDealerActor[playerid], playerid);
						ApplyDynamicActorAnimation(DrugsDealerActor[playerid], "DEALER", "DRUGS_BUY", 4.1, 0, 0, 0, 0, 0);
						ApplyAnimation(playerid, "DEALER", "DRUGS_BUY", 4.1, 0, 0, 0, 0, 0, 1);
						SetTimerEx("DrugsDealingRun", 3000, false, "ii", playerid, 0);
					}
					else if(DrugsDealerType[playerid] == 2)
					{
						new cost = DrugsDealerAmount[playerid] * 200;
						if(!Inventory_Count(playerid, "Marijuana"))
							return SendErrorMessage(playerid, "You don't have any marijuana in inventory.");

						if(Inventory_Count(playerid, "Marijuana") < DrugsDealerAmount[playerid])
							return SendErrorMessage(playerid, "You need at least %d grams of marijuana.", DrugsDealerAmount[playerid]);

						Inventory_Remove(playerid, "Marijuana", DrugsDealerAmount[playerid]);
						GiveMoney(playerid, cost);
						SendServerMessage(playerid, "[Drugs Dealer] {cdd0d1}You've received {B3C99E}$%d{cdd0d1} from selling marijuana.", cost);

						//SetDynamicActorAngleToPlayer(DrugsDealerActor[playerid], playerid);
						ApplyDynamicActorAnimation(DrugsDealerActor[playerid], "DEALER", "DRUGS_BUY", 4.1, 0, 0, 0, 0, 0);
						ApplyAnimation(playerid, "DEALER", "DRUGS_BUY", 4.1, 0, 0, 0, 0, 0, 1);
						SetTimerEx("DrugsDealingRun", 3000, false, "ii", playerid, 0);
					}
					else if(DrugsDealerType[playerid] == 3)
					{
						new cost = DrugsDealerAmount[playerid] * 200;
						if(!Inventory_Count(playerid, "Heroin"))
							return SendErrorMessage(playerid, "You don't have any heroin in inventory.");

						if(Inventory_Count(playerid, "Heroin") < DrugsDealerAmount[playerid])
							return SendErrorMessage(playerid, "You need at least %d grams of heroin.", DrugsDealerAmount[playerid]);

						Inventory_Remove(playerid, "Heroin", DrugsDealerAmount[playerid]);
						GiveMoney(playerid, cost);
						SendServerMessage(playerid, "[Drugs Dealer] {cdd0d1}You've received {B3C99E}$%d{cdd0d1} from selling heroin.", cost);

						//SetDynamicActorAngleToPlayer(DrugsDealerActor[playerid], playerid);
						ApplyDynamicActorAnimation(DrugsDealerActor[playerid], "DEALER", "DRUGS_BUY", 4.1, 0, 0, 0, 0, 0);
						ApplyAnimation(playerid, "DEALER", "DRUGS_BUY", 4.1, 0, 0, 0, 0, 0, 1);
						SetTimerEx("DrugsDealingRun", 3000, false, "ii", playerid, 0);
					}
					else if(DrugsDealerType[playerid] == 4)
					{
						new cost = DrugsDealerAmount[playerid] * 150;
						if(!Inventory_Count(playerid, "PCP"))
							return SendErrorMessage(playerid, "You don't have any pcp in inventory.");

						if(Inventory_Count(playerid, "PCP") < DrugsDealerAmount[playerid])
							return SendErrorMessage(playerid, "You need at least %d grams of pcp.", DrugsDealerAmount[playerid]);

						Inventory_Remove(playerid, "PCP", DrugsDealerAmount[playerid]);
						GiveMoney(playerid, cost);
						SendServerMessage(playerid, "[Drugs Dealer] {cdd0d1}You've received {B3C99E}$%d{cdd0d1} from selling pcp.", cost);

						//SetDynamicActorAngleToPlayer(DrugsDealerActor[playerid], playerid);
						ApplyDynamicActorAnimation(DrugsDealerActor[playerid], "DEALER", "DRUGS_BUY", 4.1, 0, 0, 0, 0, 0);
						ApplyAnimation(playerid, "DEALER", "DRUGS_BUY", 4.1, 0, 0, 0, 0, 0, 1);
						SetTimerEx("DrugsDealingRun", 3000, false, "ii", playerid, 0);
					}
				}
			}
			else
			{
				if(IsPlayerNearDrugsDealing(playerid))
				{
					//SetDynamicActorAngleToPlayer(DrugsDealerActor[playerid], playerid);
					ApplyDynamicActorAnimation(DrugsDealerActor[playerid], "PED", "fucku", 4.1, 0, 0, 0, 0, 0);
					SetTimerEx("DrugsDealingRun", 3000, false, "ii", playerid, 1);
				}
			}
		}
		case DIALOG_DRUGSCOMBINE:
		{
			if(response)
			{
				switch(listitem)
				{
					case 0:
					{
						new id = IsPlayerInBusiness(playerid);
						if(id != -1)
						{
							if(BusinessInfo[id][E_BUSINESS_LOADING] == true)
								return SendErrorMessage(playerid, "You can't start drugs combine right now.");

							if(BusinessInfo[id][E_BUSINESS_TYPE] != BUSINESS_TYPE_ACID)
								return SendErrorMessage(playerid, "You aren't near a pot of water.");

							if(!Inventory_Count(playerid, "Cocaine"))
								return SendErrorMessage(playerid, "You don't have any cocaine in inventory.");

							if(Inventory_Count(playerid, "Cocaine") < 2)
								return SendErrorMessage(playerid, "You need at least 5 grams of cocaine.");

							if(Inventory_Count(playerid, "Baking Soda") < 2)
								return SendErrorMessage(playerid, "You need at least 5 pack of baking soda.");

							BusinessInfo[id][E_BUSINESS_LOADINGDISPLAY] = Create3DTextLabel("PCP COOK IN PROCESS\nSupplied Marijuana: 5 gram\nExpected Output: 3-5 gram\nTime Left: ((|------))", COLOR_DARKGREEN, BusinessInfo[id][E_BUSINESS_ENTRANCEPOINT][0], BusinessInfo[id][E_BUSINESS_ENTRANCEPOINT][1], BusinessInfo[id][E_BUSINESS_ENTRANCEPOINT][2]+1, 5.0, BusinessInfo[id][E_BUSINESS_INTERIORPOSWORLD], 1);
							BusinessInfo[id][E_BUSINESS_LOADINGCOUNT] = 1;

							BusinessInfo[id][E_BUSINESS_LOADING] = true; 
							BusinessInfo[id][E_BUSINESS_LOADINGTIMER] = SetTimerEx("CookDrugs", 10000, true, "iii", playerid, 1, id);
						}
					}
					case 1:
					{
						new id = Item_Nearest(playerid);
						if(id != -1)
						{
							if(BusinessInfo[id][E_BUSINESS_LOADING] == true)
								return SendErrorMessage(playerid, "You can't start drugs combine right now.");

							if(BusinessInfo[id][E_BUSINESS_TYPE] != BUSINESS_TYPE_ACID)
								return SendErrorMessage(playerid, "You aren't near a pot of water.");

							if(!Inventory_Count(playerid, "Marijuana"))
								return SendErrorMessage(playerid, "You don't have any marijuana in inventory.");

							if(Inventory_Count(playerid, "Marijuana") < 2)
								return SendErrorMessage(playerid, "You need at least 2 grams of marijuana.");

							if(Inventory_Count(playerid, "Parsley") < 2)
								return SendErrorMessage(playerid, "You need at least 2 grams of parsley.");

							if(Inventory_Count(playerid, "Mint") < 1)
								return SendErrorMessage(playerid, "You need at least 1 grams of mint.");

							if(Inventory_Count(playerid, "Baking Soda") < 5)
								return SendErrorMessage(playerid, "You need at least 1 pack of baking soda.");

							BusinessInfo[id][E_BUSINESS_LOADINGDISPLAY] = Create3DTextLabel("PCP COOK IN PROCESS\nSupplied Marijuana: 5 gram\nExpected Output: 3-5 gram\nTime Left: ((|------))", COLOR_DARKGREEN, BusinessInfo[id][E_BUSINESS_ENTRANCEPOINT][0], BusinessInfo[id][E_BUSINESS_ENTRANCEPOINT][1], BusinessInfo[id][E_BUSINESS_ENTRANCEPOINT][2]+1, 5.0, BusinessInfo[id][E_BUSINESS_INTERIORPOSWORLD], 1);
							BusinessInfo[id][E_BUSINESS_LOADINGCOUNT] = 1;

							BusinessInfo[id][E_BUSINESS_LOADING] = true; 
							BusinessInfo[id][E_BUSINESS_LOADINGTIMER] = SetTimerEx("CookDrugs", 10000, true, "iii", playerid, 2, id);
						}
					}
				}
			}
		}
		case DIALOG_PHONE:
		{
			if(response)
			{
				switch(listitem)
				{
					case 0:
					{
						if(PlayerInfo[playerid][E_CHARACTER_PHONEOFF])
							return SendErrorMessage(playerid, "Your cellphone is turned off.");

						ShowPlayerDialog(playerid, DIALOG_DIALNUMBER, DIALOG_STYLE_INPUT, "Dial Number:", "Please enter the number that you wish to dial below:", "Submit", "Cancel");
					}
					case 1:
					{
						if(PlayerInfo[playerid][E_CHARACTER_PHONEOFF])
							return SendErrorMessage(playerid, "Your cellphone is turned off.");

						ShowPlayerDialog(playerid, DIALOG_SMS, DIALOG_STYLE_INPUT, "Send Text Message:", "Please enter the number that you wish to send a text message to:", "Submit", "Cancel");
					}
					case 2:
					{
						if(PlayerInfo[playerid][E_CHARACTER_PHONEOFF])
							return SendErrorMessage(playerid, "Your cellphone is turned off.");

						ShowPlayerDialog(playerid, DIALOG_BACKGROUND, DIALOG_STYLE_LIST, "Choose your wallpaper:", "(1) Sanchez Riders\n(2) Let me Bounce\n(3) East Los Santos\n(4) Narcotics\n(5) Armed Weapons\n(6) Ghetto Bird", "Submit", "Cancel");
					}
					case 3:
					{
						ShowContacts(playerid);
					}
					case 4:
					{
						if (!PlayerInfo[playerid][E_CHARACTER_PHONEOFF])
						{
							if (PlayerInfo[playerid][E_CHARACTER_PHONELINE] != INVALID_PLAYER_ID) {
								cmd_hangup(playerid, "");
							}
							PlayerInfo[playerid][E_CHARACTER_PHONEOFF] = true;
							SendNearbyMessage(playerid, 20.0, COLOR_EMOTE, "** %s has powered off their cellphone.", ReturnSettingsName(playerid, playerid));
						}
						else
						{
							PlayerInfo[playerid][E_CHARACTER_PHONEOFF] = false;
							SendNearbyMessage(playerid, 20.0, COLOR_EMOTE, "** %s has powered on their cellphone.", ReturnSettingsName(playerid, playerid));
						}
					}
				}
			}
		}
		case DIALOG_BACKGROUND:
		{
			if(response)
			{
				switch(listitem)
				{
					case 0:
					{
						PlayerTextDrawSetString(playerid, phone[1][playerid], "mdl-2001:bg_1");
					}
					case 1:
					{
						PlayerTextDrawSetString(playerid, phone[1][playerid], "mdl-2001:bg_2");
					}
					case 2:
					{
						PlayerTextDrawSetString(playerid, phone[1][playerid], "mdl-2001:bg_3");
					}
					case 3:
					{
						PlayerTextDrawSetString(playerid, phone[1][playerid], "mdl-2001:bg_4");
					}
					case 4:
					{
						PlayerTextDrawSetString(playerid, phone[1][playerid], "mdl-2001:bg_5");
					}
					case 5:
					{
						PlayerTextDrawSetString(playerid, phone[1][playerid], "mdl-2001:bg_6");
					}
				}
			}
		}
		case DIALOG_DIALNUMBER:
		{
			if (response)
			{
				new
					string[16];

				if (isnull(inputtext) || !IsNumeric(inputtext))
					return ShowPlayerDialog(playerid, DIALOG_DIALNUMBER, DIALOG_STYLE_INPUT, "Dial Number:", "Please enter the number that you wish to dial below:", "Submit", "Cancel");

				format(string, 16, "%d", strval(inputtext));
				cmd_call(playerid, string);
			}
		}
		case DIALOG_SMS:
		{
			if (response)
			{
				new number = strval(inputtext);

				if (isnull(inputtext) || !IsNumeric(inputtext))
					return ShowPlayerDialog(playerid, DIALOG_SMS, DIALOG_STYLE_INPUT, "Send Text Message:", "Please enter the number that you wish to send a text message to:", "Dial", "Back");

				if (GetNumberOwner(number) == INVALID_PLAYER_ID)
					return ShowPlayerDialog(playerid, DIALOG_SMS, DIALOG_STYLE_INPUT, "Send Text Message:", "Error: That number is not online right now.\nPlease enter the number that you wish to send a text message to:", "Dial", "Back");

				PlayerInfo[playerid][E_CHARACTER_CONTACT] = GetNumberOwner(number);

				new str[512];
				format(str, sizeof(str), "Please enter the message to send to %s:", ReturnSettingsName(PlayerInfo[playerid][E_CHARACTER_CONTACT], playerid));
				ShowPlayerDialog(playerid, DIALOG_SMSTEXT, DIALOG_STYLE_INPUT, "Text Message:", str, "Send", "Back");
			}
		}
		case DIALOG_SMSTEXT:
		{
			if (response)
			{
				if (isnull(inputtext))
				{
					return ShowPlayerDialog(playerid, DIALOG_SMSTEXT, DIALOG_STYLE_INPUT, "Text Message:", "Please enter a message to send.\n\nPlease enter the message to send to:", "Send", "Back");
				}
				new targetid = PlayerInfo[playerid][E_CHARACTER_CONTACT];

				if (!IsPlayerConnected(targetid) || !PlayerInfo[targetid][E_CHARACTER_PHONE])
					return SendErrorMessage(playerid, "The specified phone number went offline.");

				SendErrorMessage(playerid, "Your text message is being sent.");

				new str[512];
				format(str, sizeof(str), "* %s takes out their cellphone.", ReturnSettingsName(playerid, playerid));
				SetPlayerChatBubble(playerid, str, COLOR_EMOTE, 20.0, 3000); 
				
				if(targetid == INVALID_PLAYER_ID)
				{
					playerText[playerid] = SetTimerEx("OnPhoneSMS", 3000, false, "ii", playerid, 1); 
					return 1;
				}
				
				if(PlayerInfo[targetid][E_CHARACTER_PHONEOFF])
				{
					playerText[playerid] = SetTimerEx("OnPhoneSMS", 3000, false, "ii", playerid, 2);
					return 1;
				}
					
				playerText[playerid] = SetTimerEx("OnPhoneSMS", 1500, false, "iiis[128]", playerid, 3, targetid, inputtext); 
			}
		}
		case DIALOG_CONTACTS:
		{
			if (response)
			{
				if (!listitem) {
					ShowPlayerDialog(playerid, DIALOG_NEWNUMBER, DIALOG_STYLE_INPUT, "New Contact:", "Please enter the name of the contact below:", "Submit", "Back");
				}
				else {
					PlayerInfo[playerid][E_CHARACTER_CONTACT] = ListedContacts[playerid][listitem - 1];

					ShowPlayerDialog(playerid, DIALOG_CONTACTINFO, DIALOG_STYLE_LIST, ContactInfo[playerid][PlayerInfo[playerid][E_CHARACTER_CONTACT]][E_CONTACT_NAME], "Call Contact\nDelete Contact", "Select", "Back");
				}
			}
		}
		case DIALOG_NEWNUMBER:
		{
			if (response)
			{
				if (isnull(inputtext))
					return ShowPlayerDialog(playerid, DIALOG_NEWNUMBER, DIALOG_STYLE_INPUT, "New Contact:", "Please enter a contact name.\nPlease enter the name of the contact below:", "Submit", "Back");

				if (strlen(inputtext) > 32)
					return ShowPlayerDialog(playerid, DIALOG_NEWNUMBER, DIALOG_STYLE_INPUT, "New Contact:", "The contact name can't exceed 32 characters.\nPlease enter the name of the contact below:", "Submit", "Back");

				strpack(PlayerInfo[playerid][E_CHARACTER_EDITINGITEM], inputtext, 32);

				new str[512];
				format(str, sizeof(str), "Contact Name: %s\nPlease enter the phone number for this contact:");
				ShowPlayerDialog(playerid, DIALOG_ENTERNUMBER, DIALOG_STYLE_INPUT, "Contact Number:", str, "Submit", "Back");
			}
		}
		case DIALOG_ENTERNUMBER:
		{
			if (response)
			{
				static name[32], string[128];

				strunpack(name, PlayerInfo[playerid][E_CHARACTER_EDITINGITEM]);

				if (isnull(inputtext) || !IsNumeric(inputtext))
				{
					new str[512];
					format(str, sizeof(str),  "Contact Name: %s\nPlease enter the phone number for this contact:");
					ShowPlayerDialog(playerid, DIALOG_ENTERNUMBER, DIALOG_STYLE_INPUT, "Contact Number:", str, "Submit", "Back");
				}
				for (new i = 0; i != MAX_CONTACTS; i ++)
				{
					if (!ContactInfo[playerid][i][E_CONTACT_EXISTS])
					{
						ContactInfo[playerid][i][E_CONTACT_EXISTS] = true;
						ContactInfo[playerid][i][E_CONTACT_NUMBER] = strval(inputtext);

						format(ContactInfo[playerid][i][E_CONTACT_NAME], 32, name);

						format(string, sizeof(string), "INSERT INTO `contacts` (`ID`, `E_CONTACT_NAME`, `E_CONTACT_NUMBER`) VALUES('%d', '%s', '%d')", PlayerInfo[playerid][E_CHARACTER_DBID], name, ContactInfo[playerid][i][E_CONTACT_NUMBER]);
						mysql_pquery(ourConnection, string, "OnContactAdd", "dd", playerid, i);

						SendServerMessage(playerid, "[Contact] {cdd0d1}You have added {d7d292}%s{cdd0d1} to your contacts.", name);
						return 1;
					}
				}
				SendErrorMessage(playerid, "There is no slot left for anymore contacts.");
			}
		}
		case DIALOG_CONTACTINFO:
		{
			if (response)
			{
				new
					id = PlayerInfo[playerid][E_CHARACTER_CONTACT],
					string[72];

				switch (listitem)
				{
					case 0:
					{
						format(string, 16, "%d", ContactInfo[playerid][id][E_CONTACT_NUMBER]);
						cmd_call(playerid, string);
					}
					case 1:
					{
						format(string, sizeof(string), "DELETE FROM `contacts` WHERE `ID` = '%d' AND `E_CONTACT_DBID` = '%d'", PlayerInfo[playerid][E_CHARACTER_DBID], ContactInfo[playerid][id][E_CONTACT_DBID]);
						mysql_pquery(ourConnection, string);

						SendServerMessage(playerid, "[Contact] {cdd0d1}You have deleted {d7d292}%s{cdd0d1} from your contacts.", ContactInfo[playerid][id][E_CONTACT_NAME]);

						ContactInfo[playerid][id][E_CONTACT_EXISTS] = false;
						ContactInfo[playerid][id][E_CONTACT_NUMBER] = 0;
						ContactInfo[playerid][id][E_CONTACT_DBID] = 0;

						ShowContacts(playerid);
					}
				}
			}
		}
		case DIALOG_CLERK:
		{
			if(response)
			{
				switch(listitem)
				{
					case 0:
					{
						if(PlayerInfo[playerid][E_CHARACTER_PURCHASE] == 0)
							return SendErrorMessage(playerid, "You don't have a bill to pay to the clerk.");

						if(PlayerInfo[playerid][E_CHARACTER_PURCHASE] > PlayerInfo[playerid][E_CHARACTER_MONEY])
						{
							return SendErrorMessage(playerid, "You can't afford a bills.");
						}
						GiveMoney(playerid, -PlayerInfo[playerid][E_CHARACTER_PURCHASE]);
						PlayerInfo[playerid][E_CHARACTER_PURCHASE] = 0;

						Relations_Add(playerid, BusinessInfo[IsPlayerInBusiness(playerid)][E_BUSINESS_NAME]);
					}
					case 1:
					{
						if(BusinessInfo[IsPlayerInBusiness(playerid)][E_BUSINESS_ROBBERYCASH] == true && BusinessInfo[IsPlayerInBusiness(playerid)][E_BUSINESS_CASH] >= 500)
						{
							new rand = random(600);
							GiveMoney(playerid, rand);
							BusinessInfo[IsPlayerInBusiness(playerid)][E_BUSINESS_CASH] -= rand;
							BusinessInfo[IsPlayerInBusiness(playerid)][E_BUSINESS_ROBBERYCASH] = false;
							BusinessRefresh(IsPlayerInBusiness(playerid));
							SendServerMessage(playerid, "[Business] {cdd0d1}You've got money {B3C99E}$%d{cdd0d1} from take cash money on cashiers.", rand);
						}
					}
				}
			}
		}
		case DIALOG_VSTORAGE:
		{
			static
				carid = -1,
				string[64];

			if ((carid = IsPlayerNearVehicle(playerid)) != -1 && !VehicleInfo[carid][E_VEHICLE_LOCKED])
			{
				if (response)
				{
					if (VstorageInfo[carid][listitem][E_VEHICLE_TRUNKEXISTS])
					{
						PlayerInfo[playerid][E_CHARACTER_STORAGEITEM] = listitem;

						strunpack(string, VstorageInfo[carid][listitem][E_VEHICLE_TRUNKNAME]);

						format(string, sizeof(string), "%s (Quantity: %d):", string, VstorageInfo[carid][listitem][E_VEHICLE_TRUNKQUANTITY]);
						ShowPlayerDialog(playerid, DIALOG_VOPTIONS, DIALOG_STYLE_LIST, string, "Take Item\nStore Item", "Select", "Back");
					}
					else 
					{
						OpenInventory(playerid);
						PlayerInfo[playerid][E_CHARACTER_STORAGESELECT] = 1;
					}
				}
				else
				{
					new engine, lights, alarm, doors, bonnet, objective;
	
					SetVehicleParamsEx(carid, engine, lights, alarm, doors, bonnet, 0, objective);
					SendClientMessageEx(playerid, COLOR_WHITE, "> Trunk {FF6347}Closed");
				}
			}
		}
		case DIALOG_VOPTIONS:
		{
			static
				carid = -1,
				itemid = -1,
				string[32];

			if ((carid = IsPlayerNearVehicle(playerid)) != -1 && !VehicleInfo[carid][E_VEHICLE_LOCKED])
			{
				itemid = PlayerInfo[playerid][E_CHARACTER_STORAGEITEM];

				strunpack(string, VstorageInfo[carid][itemid][E_VEHICLE_TRUNKNAME]);

				if (response)
				{
					switch (listitem)
					{
						case 0: //take
						{
							if (VstorageInfo[carid][itemid][E_VEHICLE_TRUNKQUANTITY] == 1)
							{
								if(!strcmp(string, "Fabric Cargo") && Inventory_Count(playerid, "Fabric Cargo") == 1 || !strcmp(string, "Steel Cargo") && Inventory_Count(playerid, "Steel Cargo") == 1 
								|| !strcmp(string, "Woods Cargo") && Inventory_Count(playerid, "Woods Cargo") == 1 || !strcmp(string, "Foods Cargo") && Inventory_Count(playerid, "Foods Cargo") == 1
								|| !strcmp(string, "Clothes Cargo") && Inventory_Count(playerid, "Clothes Cargo") == 1 || !strcmp(string, "Appliances Cargo") && Inventory_Count(playerid, "Appliances Cargo") == 1
								|| !strcmp(string, "Fish Cargo") && Inventory_Count(playerid, "Fish Cargo") == 1 || !strcmp(string, "Woods") && Inventory_Count(playerid, "Woods") == 1)
									return SendErrorMessage(playerid, "You already carying cargo/woods.");

								new id = Inventory_Add(playerid, string, VstorageInfo[carid][itemid][E_VEHICLE_TRUNKMODEL], 1);

								if (id == -1)
									return SendErrorMessage(playerid, "You don't have any storage slots left.");

								VS_RemoveItem(carid, string);
								VehicleObjectUpdates(carid);
				
								ShowVehicleStorage(playerid, carid);
							}
							else
							{
								if(!strcmp(string, "Fabric Cargo") && Inventory_Count(playerid, "Fabric Cargo") == 1 || !strcmp(string, "Steel Cargo") && Inventory_Count(playerid, "Steel Cargo") == 1 
								|| !strcmp(string, "Woods Cargo") && Inventory_Count(playerid, "Woods Cargo") == 1 || !strcmp(string, "Foods Cargo") && Inventory_Count(playerid, "Foods Cargo") == 1
								|| !strcmp(string, "Clothes Cargo") && Inventory_Count(playerid, "Clothes Cargo") == 1 || !strcmp(string, "Appliances Cargo") && Inventory_Count(playerid, "Appliances Cargo") == 1
								|| !strcmp(string, "Fish Cargo") && Inventory_Count(playerid, "Fish Cargo") == 1 || !strcmp(string, "Woods") && Inventory_Count(playerid, "Woods") == 1)
									return SendErrorMessage(playerid, "You already carying cargo/woods.");

								if(!strcmp(string, "Fabric Cargo") && VS_Count(carid, "Fabric Cargo") > 1 || !strcmp(string, "Steel Cargo") && VS_Count(carid, "Steel Cargo") > 1
									|| !strcmp(string, "Woods Cargo") && VS_Count(carid, "Woods Cargo") > 1 || !strcmp(string, "Foods Cargo") && VS_Count(carid, "Foods Cargo") > 1
									|| !strcmp(string, "Clothes Cargo") && VS_Count(carid, "Clothes Cargo") > 1 || !strcmp(string, "Appliances Cargo") && VS_Count(carid, "Appliances Cargo") > 1
									|| !strcmp(string, "Fish Cargo") && VS_Count(carid, "Fish Cargo") > 1)
								{
									new id = Inventory_Add(playerid, string, VstorageInfo[carid][itemid][E_VEHICLE_TRUNKMODEL], 1);

									if (id == -1)
										return SendErrorMessage(playerid, "You don't have any storage slots left.");

									VS_RemoveItem(carid, string);
									VehicleObjectUpdates(carid);
						
									ShowVehicleStorage(playerid, carid);
								}
								else
								{
									new str[512];
									format(str, sizeof(str), "Item: %s (Quantity: %d)\n\nPlease enter the quantity that you wish to take for this item:", string, VstorageInfo[carid][itemid][E_VEHICLE_TRUNKQUANTITY]);
									ShowPlayerDialog(playerid, DIALOG_VTAKE, DIALOG_STYLE_INPUT, "Vehicle Take:", str, "Take", "Back");
								}
								
							}
						}
						case 1: //store
						{
							new id = Inventory_GetItemID(playerid, string);

							if(GetVehicleModel(carid) == 459 || GetVehicleModel(carid) == 482 || GetVehicleModel(carid) == 440 || GetVehicleModel(carid) == 413)
							{
								if (id == -1) {
									return SendErrorMessage(playerid, "You don't have anymore of this item to store!");
								}
								else if (InventoryInfo[playerid][id][E_INVENTORY_QUANTITY] == 1)
								{
									if(!strcmp(string, "Fabric Cargo") && VS_Count(carid, "Fabric Cargo") >= 3 || !strcmp(string, "Steel Cargo") && VS_Count(carid, "Steel Cargo") >= 3 \
									|| !strcmp(string, "Woods Cargo") && VS_Count(carid, "Woods Cargo") >= 3 || !strcmp(string, "Foods Cargo") && VS_Count(carid, "Foods Cargo") >= 3
									|| !strcmp(string, "Clothes Cargo") && VS_Count(carid, "Clothes Cargo") >= 3 || !strcmp(string, "Appliances Cargo") && VS_Count(carid, "Appliances Cargo") >= 3
									|| !strcmp(string, "Fish Cargo") && VS_Count(carid, "Fish Cargo") >= 3)
										return SendErrorMessage(playerid, "You can't place cargo into your vehicle trunk is full.");

									VS_AddItem(carid, string, InventoryInfo[playerid][id][E_INVENTORY_MODEL], 1);
									Inventory_Remove(playerid, string);
						
									ShowVehicleStorage(playerid, carid);
								}
								else if (InventoryInfo[playerid][id][E_INVENTORY_QUANTITY] > 1) 
								{
									PlayerInfo[playerid][E_CHARACTER_LISTITEM] = id;

									new str[512];
									format(str, sizeof(str), "Item: %s (Quantity: %d)\n\nPlease enter the quantity that you wish to store for this item:", string, InventoryInfo[playerid][PlayerInfo[playerid][E_CHARACTER_LISTITEM]][E_INVENTORY_QUANTITY]);
									ShowPlayerDialog(playerid, DIALOG_VPLACE, DIALOG_STYLE_INPUT, "Vehicle Place:", str, "Store", "Back");
								}
							}
							else if(GetVehicleModel(carid) == 499 || GetVehicleModel(carid) == 414)
							{
								if (id == -1) {
									return SendErrorMessage(playerid, "You don't have anymore of this item to store!");
								}
								else if (InventoryInfo[playerid][id][E_INVENTORY_QUANTITY] == 1)
								{
									if(!strcmp(string, "Fabric Cargo") && VS_Count(carid, "Fabric Cargo") >= 5 || !strcmp(string, "Steel Cargo") && VS_Count(carid, "Steel Cargo") >= 5
									|| !strcmp(string, "Woods Cargo") && VS_Count(carid, "Woods Cargo") >= 5 || !strcmp(string, "Foods Cargo") && VS_Count(carid, "Foods Cargo") >= 5
									|| !strcmp(string, "Clothes Cargo") && VS_Count(carid, "Clothes Cargo") >= 5 || !strcmp(string, "Appliances Cargo") && VS_Count(carid, "Appliances Cargo") >= 5
									|| !strcmp(string, "Fish Cargo") && VS_Count(carid, "Fish Cargo") >= 5)
										return SendErrorMessage(playerid, "You can't place cargo into your vehicle trunk is full.");

									VS_AddItem(carid, string, InventoryInfo[playerid][id][E_INVENTORY_MODEL], 1);
									Inventory_Remove(playerid, string);
				
									ShowVehicleStorage(playerid, carid);
								}
								else if (InventoryInfo[playerid][id][E_INVENTORY_QUANTITY] > 1) 
								{
									PlayerInfo[playerid][E_CHARACTER_LISTITEM] = id;

									new str[512];
									format(str, sizeof(str), "Item: %s (Quantity: %d)\n\nPlease enter the quantity that you wish to store for this item:", string, InventoryInfo[playerid][PlayerInfo[playerid][E_CHARACTER_LISTITEM]][E_INVENTORY_QUANTITY]);
									ShowPlayerDialog(playerid, DIALOG_VPLACE, DIALOG_STYLE_INPUT, "Vehicle Place:", str, "Store", "Back");
								}
							}
							else if(GetVehicleModel(carid) == 456)
							{
								if (id == -1) {
									return SendErrorMessage(playerid, "You don't have anymore of this item to store!");
								}
								else if (InventoryInfo[playerid][id][E_INVENTORY_QUANTITY] == 1)
								{
									if(!strcmp(string, "Fabric Cargo") && VS_Count(carid, "Fabric Cargo") >= 8 || !strcmp(string, "Steel Cargo") && VS_Count(carid, "Steel Cargo") >= 8
									|| !strcmp(string, "Woods Cargo") && VS_Count(carid, "Woods Cargo") >= 8 || !strcmp(string, "Foods Cargo") && VS_Count(carid, "Foods Cargo") >= 8
									|| !strcmp(string, "Clothes Cargo") && VS_Count(carid, "Clothes Cargo") >= 8 || !strcmp(string, "Appliances Cargo") && VS_Count(carid, "Appliances Cargo") >= 8
									|| !strcmp(string, "Fish Cargo") && VS_Count(carid, "Fish Cargo") >= 8)
										return SendErrorMessage(playerid, "You can't place cargo into your vehicle trunk is full.");

									VS_AddItem(carid, string, InventoryInfo[playerid][id][E_INVENTORY_MODEL], 1);
									Inventory_Remove(playerid, string);
						
									ShowVehicleStorage(playerid, carid);
								}
								else if (InventoryInfo[playerid][id][E_INVENTORY_QUANTITY] > 1) 
								{
									PlayerInfo[playerid][E_CHARACTER_LISTITEM] = id;

									new str[512];
									format(str, sizeof(str), "Item: %s (Quantity: %d)\n\nPlease enter the quantity that you wish to store for this item:", string, InventoryInfo[playerid][PlayerInfo[playerid][E_CHARACTER_LISTITEM]][E_INVENTORY_QUANTITY]);
									ShowPlayerDialog(playerid, DIALOG_VPLACE, DIALOG_STYLE_INPUT, "Vehicle Place:", str, "Store", "Back");
								}
							}
							else if(GetVehicleModel(carid) == 455)
							{
								if (id == -1) {
									return SendErrorMessage(playerid, "You don't have anymore of this item to store!");
								}
								else if (InventoryInfo[playerid][id][E_INVENTORY_QUANTITY] == 1)
								{
									if(!strcmp(string, "Fabric Cargo") && VS_Count(carid, "Fabric Cargo") >= 10 || !strcmp(string, "Steel Cargo") && VS_Count(carid, "Steel Cargo") >= 10
									|| !strcmp(string, "Woods Cargo") && VS_Count(carid, "Woods Cargo") >= 10 || !strcmp(string, "Foods Cargo") && VS_Count(carid, "Foods Cargo") >= 10
									|| !strcmp(string, "Clothes Cargo") && VS_Count(carid, "Clothes Cargo") >= 10 || !strcmp(string, "Appliances Cargo") && VS_Count(carid, "Appliances Cargo") >= 10
									|| !strcmp(string, "Fish Cargo") && VS_Count(carid, "Fish Cargo") >= 10)
										return SendErrorMessage(playerid, "You can't place cargo into your vehicle trunk is full.");

									VS_AddItem(carid, string, InventoryInfo[playerid][id][E_INVENTORY_MODEL], 1);
									Inventory_Remove(playerid, string);
						
									ShowVehicleStorage(playerid, carid);
								}
								else if (InventoryInfo[playerid][id][E_INVENTORY_QUANTITY] > 1) 
								{
									PlayerInfo[playerid][E_CHARACTER_LISTITEM] = id;

									new str[512];
									format(str, sizeof(str), "Item: %s (Quantity: %d)\n\nPlease enter the quantity that you wish to store for this item:", string, InventoryInfo[playerid][PlayerInfo[playerid][E_CHARACTER_LISTITEM]][E_INVENTORY_QUANTITY]);
									ShowPlayerDialog(playerid, DIALOG_VPLACE, DIALOG_STYLE_INPUT, "Vehicle Place:", str, "Store", "Back");
								}
							}
							else if(GetVehicleModel(carid) == 422 || GetVehicleModel(carid) == 478 || GetVehicleModel(carid) == 554 || GetVehicleModel(carid) == 543)
							{
								if (id == -1) {
									return SendErrorMessage(playerid, "You don't have anymore of this item to store!");
								}
								else if (InventoryInfo[playerid][id][E_INVENTORY_QUANTITY] == 1)
								{
									if(!strcmp(string, "Woods") && VS_Count(carid, "Woods") >= 3)
										return SendErrorMessage(playerid, "You can't place woods into your vehicle trunk is full.");

									VS_AddItem(carid, string, InventoryInfo[playerid][id][E_INVENTORY_MODEL], 1);
									Inventory_Remove(playerid, string);
									VehicleObjectUpdates(carid);
									ShowVehicleStorage(playerid, carid);
								}
								else if (InventoryInfo[playerid][id][E_INVENTORY_QUANTITY] > 1) 
								{
									PlayerInfo[playerid][E_CHARACTER_LISTITEM] = id;

									new str[512];
									format(str, sizeof(str), "Item: %s (Quantity: %d)\n\nPlease enter the quantity that you wish to store for this item:", string, InventoryInfo[playerid][PlayerInfo[playerid][E_CHARACTER_LISTITEM]][E_INVENTORY_QUANTITY]);
									ShowPlayerDialog(playerid, DIALOG_VPLACE, DIALOG_STYLE_INPUT, "Vehicle Place:", str, "Store", "Back");
								}
							}
							else
							{
								if (id == -1) {
									return SendErrorMessage(playerid, "You don't have anymore of this item to store!");
								}
								else if (InventoryInfo[playerid][id][E_INVENTORY_QUANTITY] == 1)
								{

									VS_AddItem(carid, string, InventoryInfo[playerid][id][E_INVENTORY_MODEL], 1);
									Inventory_Remove(playerid, string);
									
									ShowVehicleStorage(playerid, carid);
								}
								else if (InventoryInfo[playerid][id][E_INVENTORY_QUANTITY] > 1) 
								{
									PlayerInfo[playerid][E_CHARACTER_LISTITEM] = id;

									new str[512];
									format(str, sizeof(str), "Item: %s (Quantity: %d)\n\nPlease enter the quantity that you wish to store for this item:", string, InventoryInfo[playerid][PlayerInfo[playerid][E_CHARACTER_LISTITEM]][E_INVENTORY_QUANTITY]);
									ShowPlayerDialog(playerid, DIALOG_VPLACE, DIALOG_STYLE_INPUT, "Vehicle Place:", str, "Store", "Back");
								}
							}
						}
					}
				}
				else
				{
					ShowVehicleStorage(playerid, carid);
				}
			}
		}
		case DIALOG_VPLACE:
		{
			static
				carid = -1,
				string[32];

			carid = GetPlayerVehicleID(playerid);
			if ((carid = IsPlayerNearVehicle(playerid)) != -1 && !VehicleInfo[carid][E_VEHICLE_LOCKED])
			{
				strunpack(string, InventoryInfo[playerid][PlayerInfo[playerid][E_CHARACTER_LISTITEM]][E_INVENTORY_ITEM]);

				if (response)
				{
					new amount = strval(inputtext);

					if (amount < 1 || amount > InventoryInfo[playerid][PlayerInfo[playerid][E_CHARACTER_LISTITEM]][E_INVENTORY_QUANTITY])
					{
						new str[512];
						format(str, sizeof(str), "Item: %s (Quantity: %d)\n\nPlease enter the quantity that you wish to store for this item:", string, InventoryInfo[playerid][PlayerInfo[playerid][E_CHARACTER_LISTITEM]][E_INVENTORY_QUANTITY]);
						return ShowPlayerDialog(playerid, DIALOG_VPLACE, DIALOG_STYLE_INPUT, "Vehicle Place:", str, "Store", "Back");
					}
					
					VS_AddItem(carid, string, InventoryInfo[playerid][PlayerInfo[playerid][E_CHARACTER_LISTITEM]][E_INVENTORY_MODEL], amount);
					Inventory_Remove(playerid, string, amount);

					ShowVehicleStorage(playerid, carid);
				}
				else ShowVehicleStorage(playerid, carid);
			}
		}
		case DIALOG_VTAKE:
		{
			static
				carid = -1,
				string[32];

			if ((carid = IsPlayerNearVehicle(playerid)) != -1 && !VehicleInfo[carid][E_VEHICLE_LOCKED])
			{
				strunpack(string, VstorageInfo[carid][PlayerInfo[playerid][E_CHARACTER_STORAGEITEM]][E_VEHICLE_TRUNKNAME]);

				if (response)
				{
					new amount = strval(inputtext);
					
					if (amount < 1 || amount > VstorageInfo[carid][PlayerInfo[playerid][E_CHARACTER_STORAGEITEM]][E_VEHICLE_TRUNKQUANTITY])
					{
						new str[512];
						format(str, sizeof(str), "Item: %s (Quantity: %d)\n\nPlease enter the quantity that you wish to take for this item:", string, VstorageInfo[carid][PlayerInfo[playerid][E_CHARACTER_LISTITEM]][E_VEHICLE_TRUNKQUANTITY]);
						return ShowPlayerDialog(playerid, DIALOG_VTAKE, DIALOG_STYLE_INPUT, "Vehicle Take:", str, "Take", "Back");
					}

					new id = Inventory_Add(playerid, string, VstorageInfo[carid][PlayerInfo[playerid][E_CHARACTER_STORAGEITEM]][E_VEHICLE_TRUNKMODEL], amount);

					if (id == -1)
						return SendErrorMessage(playerid, "You don't have any inventory slots left.");

					VS_RemoveItem(carid, string, amount);

					ShowVehicleStorage(playerid, carid);
				}
				else ShowVehicleStorage(playerid, carid);
			}
		}
		case DIALOG_INDUSTRYLOC:
		{
			if(response)
			{
				GPS_SetPlayerRaceCheckPoint(playerid, 1, IndustryInfo[listitem][Posx], IndustryInfo[listitem][Posy], IndustryInfo[listitem][Posz], 0.0, 0.0, 0.0);
			}
		}
	}
	//PlayerPlaySound(playerid, 1054, 0.0, 0.0, 0.0);
	return 0;
}