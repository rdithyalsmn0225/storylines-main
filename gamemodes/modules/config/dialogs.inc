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
			format(str, sizeof(str), "Welcome to {297183}Storylines RPG{DEDEDE}, {FFFFFF}%s!\n\n{DEDEDE}Failure to authenticate three times will result in a {E03232}kick{DEDEDE}.\nYou have a total of {EEC650}five minutes{DEDEDE} to authenticate.\n\nIn order to proceed, enter a {EEC650}password{DEDEDE} below to authenticate (or register).", ReturnSettingsName(playerid, playerid));
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
		case DIALOG_SPAWNS:
		{
			if (!response)
			{
				SendErrorMessage(playerid, "You were kicked for not selection spawn."); 
				return KickEx(playerid);
			}
			switch(listitem)
			{
				case 0:
				{
					PlayerInfo[playerid][E_CHARACTER_SPAWNPOINT] = 0; 
					LoadCharacter(playerid);
				}
				case 1:
				{
					PlayerInfo[playerid][E_CHARACTER_SPAWNPOINT] = 1; 
					LoadCharacter(playerid);
				}
				case 2:
				{
					if(PlayerInfo[playerid][E_CHARACTER_FACTION] == 0)
						return ShowPlayerDialog(playerid, DIALOG_SPAWNS, DIALOG_STYLE_TABLIST, "Spawn Option:", "1\tHoodrats Spawn\t(Public)\n2\tLast Position\t(Public)\n3\tFaction Spawn\t(Faction)", "Select", "Close");

					PlayerInfo[playerid][E_CHARACTER_SPAWNPOINT] = 2;
					LoadCharacter(playerid);
				}
			}
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
				SendClientMessage(playerid, -1, "Please begin by typing your characters first and last name. i.e: {8E5B94}George_Jefferson");
				SendClientMessage(playerid, -1, "Your characters name must be in Firstname_Lastname format with no numbers or special characters.");
				SendClientMessage(playerid, -1, "Press {8E5B94}'T'{ffffff} to inputtext for character creation.");
				
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
				
				format(string, sizeof(string), "You selected the character {8E5B94}%s{FFFFFF}.", characterLister[playerid][listitem]);
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
						ShowPlayerDialog(playerid, DIALOG_GPSPOI, DIALOG_STYLE_LIST, "GPS: Point of Interest", "Public Locations\nJobs Locations\nBusiness Locations", "Select", "Cancel");
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
				}
			}
		}
		case DIALOG_GPS_PUBLIC:
		{
			if (response)
			{
				GPS_SetPlayerRaceCheckPoint(playerid, 1, PublicPoint[listitem][0], PublicPoint[listitem][1], PublicPoint[listitem][2], 0.0, 0.0, 0.0);
			}
		}
		case DIALOG_GPS_JOBS:
		{
			if (response)
			{
				GPS_SetPlayerRaceCheckPoint(playerid, 1, JobPoint[listitem][0], JobPoint[listitem][1], JobPoint[listitem][2], 0.0, 0.0, 0.0);
			}
		}
		case DIALOG_GPS_BUSINESS:
		{
			if (response)
			{
				GPS_SetPlayerRaceCheckPoint(playerid, 1, BusinessInfo[listitem+1][E_BUSINESS_ENTRANCEPOS][0], BusinessInfo[listitem+1][E_BUSINESS_ENTRANCEPOS][1], BusinessInfo[listitem+1][E_BUSINESS_ENTRANCEPOS][2], 0.0, 0.0, 0.0);
			}
		}
		case DIALOG_POLICE_SKINS:
		{
			if(response)
			{
				switch(listitem)
				{
					case 0: SetPlayerSkin(playerid, 280);
					case 1: SetPlayerSkin(playerid, 300);
					case 2: SetPlayerSkin(playerid, 281);
					case 3: SetPlayerSkin(playerid, 301);
					case 4: SetPlayerSkin(playerid, 306);
					case 5: SetPlayerSkin(playerid, 307);
					case 6: SetPlayerSkin(playerid, 265);
					case 7: SetPlayerSkin(playerid, 267);
					case 8: SetPlayerSkin(playerid, 266);
					case 9: SetPlayerSkin(playerid, 284);
					case 10: SetPlayerSkin(playerid, 61);
					case 11: SetPlayerSkin(playerid, 93);
				}
			}
			return 1;
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
					
						SendClientMessageEx(playerid, COLOR_STORE, "[Store]:{d7d7d7} You bought a cellphone for $500.");

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
					
						SendClientMessageEx(playerid, COLOR_STORE, "[Store]:{d7d7d7} You bought a radio for $2,500.");
 
						
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
						
						SendClientMessageEx(playerid, COLOR_STORE, "[Store]:{d7d7d7} You bought a gasoline can for $250.");
						//GiveMoney(playerid, -250);
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
						
						SendClientMessageEx(playerid, COLOR_STORE, "[Store]:{d7d7d7} You bought a repairkit for $250.");
						//GiveMoney(playerid, -250);
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
					
						SendClientMessageEx(playerid, COLOR_STORE, "[Store]:{d7d7d7} You bought a spikebat for $350.");
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
					
						SendClientMessageEx(playerid, COLOR_STORE, "[Store]:{d7d7d7} You bought a wooden for $500.");
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
					
						SendClientMessageEx(playerid, COLOR_STORE, "[Store]:{d7d7d7} You bought a nailbat for $350.");
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
					
						SendClientMessageEx(playerid, COLOR_STORE, "[Store]:{d7d7d7} You bought a raw meat for $50.");
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
					
						SendClientMessageEx(playerid, COLOR_STORE, "[Store]:{d7d7d7} You bought a parsley for $250.");

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
					
						SendClientMessageEx(playerid, COLOR_STORE, "[Store]:{d7d7d7} You bought a mint for $50.");

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
					
						SendClientMessageEx(playerid, COLOR_STORE, "[Store]:{d7d7d7} You bought a oregano for $250.");

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
					
						SendClientMessageEx(playerid, COLOR_STORE, "[Store]:{d7d7d7} You bought a baking soda for $100.");

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
					
						SendClientMessageEx(playerid, COLOR_STORE, "[Store]:{d7d7d7} You bought a spraycan for $250.");

						PlayerInfo[playerid][E_CHARACTER_PURCHASE] += 250; 
						BusinessInfo[IsPlayerInBusiness(playerid)][E_BUSINESS_STOCK]--;
						Inventory_Add(playerid, "Spraycan", 365, 1);

						ApplyAnimation(playerid, "MISC", "GRAB_R", 4.1, 0, 0, 0, 0, 0, 0);
					}
					case 1:
					{
						if(Inventory_Count(playerid, "Crowbar") >= 1)		
							return SendErrorMessage(playerid, "You may only hold up to 1 crowbar.");
					
						if(1000 > PlayerInfo[playerid][E_CHARACTER_MONEY])
							return SendErrorMessage(playerid, "You can't afford a crowbar.");
					
						SendClientMessageEx(playerid, COLOR_STORE, "[Store]:{d7d7d7} You bought a crowbar for $1.000.");

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
					
						SendClientMessageEx(playerid, COLOR_STORE, "[Store]:{d7d7d7} You bought a sprunk for $2.");

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
					
						SendClientMessageEx(playerid, COLOR_STORE, "[Store]:{d7d7d7} You bought a budweiser beer for $100.");
						GiveMoney(playerid, -250); 
						
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
					
						SendClientMessageEx(playerid, COLOR_STORE, "[Store]:{d7d7d7} You bought a corona extra beer for $150.");
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
					
						SendClientMessageEx(playerid, COLOR_STORE, "[Store]:{d7d7d7} You bought a peroni beer for $200.");
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

						SendClientMessageEx(playerid, COLOR_STORE, "[Store]:{d7d7d7} You bought American classic burger's and eat it");
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
					
						SendClientMessageEx(playerid, COLOR_STORE, "[Store]:{d7d7d7} You bought American classic donut's and eat it");
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
					
						SendClientMessageEx(playerid, COLOR_STORE, "[Store]:{d7d7d7} You bought American classic pizza's and eat it");
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
					
						SendClientMessageEx(playerid, COLOR_STORE, "[Store]:{d7d7d7} You bought Coca cola large's and eat it");
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
							ShowBoxMessage(playerid, "Accessory attached", 3);

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
							ShowBoxMessage(playerid, "Accessory deattached", 3);

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
						ShowBoxMessage(playerid, "Accessory removed!", 3);
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
				SendClientMessageEx(playerid, 	COLOR_STORE, "[Clothing]{FFFFFF}  Accessories bone position now is %s", Bone_Name[listitem + 1]);
			}
		}
		case DIALOG_CLOTHESMENU:
		{
			if(response)
			{
				switch(listitem)
				{
					case 0:
					{
						SetPlayerPos(playerid, 217.5163,-98.4308,1005.2578);
						SetPlayerFacingAngle(playerid, 94.6310);

						SetPlayerCameraPos(playerid, 214.387527, -99.966537, 1005.545410);
						SetPlayerCameraLookAt(playerid, 217.848388, -97.962821, 1005.458129, 1);
						ShowModelSelectionMenu(playerid, "Skin_List", MODEL_SELECTION_BUYSKIN, g_aHoodRatsSkins, sizeof(g_aHoodRatsSkins), -16.0, 0.0, -55.0);
					}
					case 1:
					{
						SetPlayerPos(playerid, 217.5163,-98.4308,1005.2578);
						SetPlayerFacingAngle(playerid, 94.6310);

						SetPlayerCameraPos(playerid, 214.387527, -99.966537, 1005.545410);
						SetPlayerCameraLookAt(playerid, 217.848388, -97.962821, 1005.458129, 1);
						ShowModelSelectionMenu(playerid, "Clothing_List", MODEL_SELECTION_CLOTHING1, g_aClothingCustom, sizeof(g_aClothingCustom), -16.0, 0.0, -55.0);
					}
				}
			}
			return 1;
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
						SendClientMessageEx(playerid, COLOR_STORE, "[Gym]:{d7d7d7} You learn a fightstyle boxing for $1,000.");
						GiveMoney(playerid, -1000);
					}	
					case 1:
					{
						SetPlayerFightingStyle(playerid, 7);
						PlayerInfo[playerid][E_CHARACTER_FIGHTSTYLE] = 7;
						SendClientMessageEx(playerid, COLOR_STORE, "[Gym]:{d7d7d7} You learn a fightstyle KneeHead for $2,500.");
						GiveMoney(playerid, -2500);
					}
					case 2:
					{
						SetPlayerFightingStyle(playerid, 15);
						PlayerInfo[playerid][E_CHARACTER_FIGHTSTYLE] = 15;
						SendClientMessageEx(playerid, COLOR_STORE, "[Gym]:{d7d7d7} You learn a fightstyle GrabKick for $3,000.");
						GiveMoney(playerid, -3000);
					}
					case 3:
					{
						SetPlayerFightingStyle(playerid, 4);
						PlayerInfo[playerid][E_CHARACTER_FIGHTSTYLE] = 4;
						SendClientMessageEx(playerid, COLOR_STORE, "[Gym]:{d7d7d7} You reset a fightstyle for $500.");
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
		case DIALOG_DEALERSHIP_SELECT:
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
				PutPlayerInVehicle(playerid, DealershipPlayerCar[playerid], 0); 
				
				ShowPlayerDialog(playerid, DIALOG_DEALERSHIP_APPEND, DIALOG_STYLE_LIST, caption, str, "Append", "<<");
			}
			return 1;
		}
		case DIALOG_DEALERSHIP_APPEND:
		{
			new
				caption[60],
				str[400]; 
			
			format(caption, 60, "%s - {5B9460}%s:", g_aDealershipData[SubDealershipHolder[playerid]][E_DEALERSHIP_MODEL], FormatMoney(DealershipTotalCost[playerid])); 
			
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
						
						ShowPlayerDialog(playerid, DIALOG_DEALERSHIP_APPEND_CMENU, DIALOG_STYLE_LIST, caption, str, "Select", "<<"); 
					}
					case 1: //Purchase
					{
						new dstr[128], vehicleid = GetPlayerVehicleID(playerid);
						
						format(dstr, sizeof(dstr), "Models:\t%s\n", ReturnVehicleName(vehicleid));
						strcat(str, dstr);
						format(dstr, sizeof(dstr), "Value:\t{FFFFFF}$%s\n", FormatMoney(g_aDealershipData[SubDealershipHolder[playerid]][E_DEALERSHIP_PRICE]));
						strcat(str, dstr);
						format(dstr, sizeof(dstr), "Max Speed:\t{FFFFFF}%.1f\n", GetVehicleTopSpeed(DealershipPlayerCar[playerid])); 
						strcat(str, dstr); 
						ShowPlayerDialog(playerid, DIALOG_DEALERSHIP_PURCHASE, DIALOG_STYLE_MSGBOX, caption, str, "Edit", "Checkout"); 
						return 1;
					}
				}
			}
			else ConfirmDialog(playerid, "Confirmation", "Are you sure you want to exit?", "OnPlayerExitDealership"); 
			return 1;
		}
		case DIALOG_DEALERSHIP_PURCHASE:
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
				
				randset[0] = random(sizeof(possiblE_VEHICLE_PLATES)); 
				randset[1] = random(sizeof(possiblE_VEHICLE_PLATES)); 
				randset[2] = random(sizeof(possiblE_VEHICLE_PLATES)); 
				
				format(plates, 32, "%d%s%s%s%d%d%d", random(9), possiblE_VEHICLE_PLATES[randset[0]], possiblE_VEHICLE_PLATES[randset[1]], possiblE_VEHICLE_PLATES[randset[2]], random(9), random(9)); 
				GiveMoney(playerid, -DealershipTotalCost[playerid]);
				
				SendClientMessage(playerid, COLOR_VEHICLE, "[Vehicle]:{d7d7d7} Your vehicles being setup.");
				ShowPlayerPlates(playerid, plates); 
				
				mysql_format(ourConnection, insert, sizeof(insert), "INSERT INTO vehicles (VehicleOwnerDBID, VehicleModel, VehicleParkPosX, VehicleParkPosY, VehicleParkPosZ, VehicleParkPosA) VALUES(%i, %i, %f, %f, %f, %f)",
					PlayerInfo[playerid][E_CHARACTER_DBID], g_aDealershipData[SubDealershipHolder[playerid]][E_DEALERSHIP_MODELID], x, y, z, a); 
					
				mysql_pquery(ourConnection, insert, "OnPlayerVehiclePurchase", "iisffff", playerid, idx, plates, x, y, z, a);
				
				PlayerPurchasingVehicle[playerid] = true; 
				TogglePlayerControllable(playerid, true);
			}
			return 1;
		}
		case DIALOG_DEALERSHIP_APPEND_CMENU:
		{
			new
				str[128],
				caption[60]
			; 
			
			format(caption, 60, "%s - {5B9460}%s:", g_aDealershipData[SubDealershipHolder[playerid]][E_DEALERSHIP_MODEL], FormatMoney(DealershipTotalCost[playerid])); 
		
			if(response)
			{
				switch(listitem)
				{
					case 0:
					{
						format(str, sizeof(str), "{FFFFFF}You're selecting your vehicles first color. ({%06x}%d{FFFFFF})\n Please select a Color ID. (0-255)", VehicleColoursTableRGBA[DealershipCarColors[playerid][0]] >>> 8, DealershipCarColors[playerid][0]); 
						ShowPlayerDialog(playerid, DIALOG_DEALERSHIP_APPEND_COLOR1, DIALOG_STYLE_INPUT, caption, str, "Select", "<<");  
					}
					case 1:
					{
						format(str, sizeof(str), "{FFFFFF}You're selecting your vehicles second color. ({%06x}%d{FFFFFF})\n Please select a Color ID. (0-255)", VehicleColoursTableRGBA[DealershipCarColors[playerid][1]] >>> 8, DealershipCarColors[playerid][1]); 
						ShowPlayerDialog(playerid, DIALOG_DEALERSHIP_APPEND_COLOR2, DIALOG_STYLE_INPUT, caption, str, "Select", "<<"); 
					}
				}
			}
			else return ShowDealerAppend(playerid);
			return 1;
		}
		case DIALOG_DEALERSHIP_APPEND_COLOR1:
		{
			new
				caption[60],
				str[128],
				color1
			;
			
			format(caption, 60, "%s - {5B9460}%s:", g_aDealershipData[SubDealershipHolder[playerid]][E_DEALERSHIP_MODEL], FormatMoney(DealershipTotalCost[playerid])); 
			
			if(response)
			{
				if(!IsNumeric(inputtext))
				{
					format(str, sizeof(str), "{FFFFFF}You're selecting your vehicles first color. ({%06x}%d{FFFFFF})\n Please select a Color ID. (0-255)", VehicleColoursTableRGBA[DealershipCarColors[playerid][0]] >>> 8, DealershipCarColors[playerid][0]); 
					return ShowPlayerDialog(playerid, DIALOG_DEALERSHIP_APPEND_COLOR1, DIALOG_STYLE_INPUT, caption, str, "Select", "<<");  
				}
			
				color1 = strval(inputtext);
				
				if(color1 > 255 || color1 < 0)
				{
					format(str, sizeof(str), "{FFFFFF}You're selecting your vehicles first color. ({%06x}%d{FFFFFF})\n Please select a Color ID. (0-255)", VehicleColoursTableRGBA[DealershipCarColors[playerid][0]] >>> 8, DealershipCarColors[playerid][0]); 
					return ShowPlayerDialog(playerid, DIALOG_DEALERSHIP_APPEND_COLOR1, DIALOG_STYLE_INPUT, caption, str, "Select", "<<");  
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
						
				ShowPlayerDialog(playerid, DIALOG_DEALERSHIP_APPEND_CMENU, DIALOG_STYLE_LIST, caption, str, "Select", "<<"); 
			}
			return 1;
		}
		case DIALOG_DEALERSHIP_APPEND_COLOR2:
		{
			new
				caption[60],
				str[128],
				color2
			;
			
			format(caption, 60, "%s - {5B9460}%s:", g_aDealershipData[SubDealershipHolder[playerid]][E_DEALERSHIP_MODEL], FormatMoney(DealershipTotalCost[playerid])); 
			
			if(response)
			{
				if(!IsNumeric(inputtext))
				{
					format(str, sizeof(str), "{FFFFFF}You're selecting your vehicles second color. ({%06x}%d{FFFFFF})\n Please select a Color ID. (0-255)", VehicleColoursTableRGBA[DealershipCarColors[playerid][1]] >>> 8, DealershipCarColors[playerid][1]); 
					return ShowPlayerDialog(playerid, DIALOG_DEALERSHIP_APPEND_COLOR1, DIALOG_STYLE_INPUT, caption, str, "Select", "<<");  
				}
			
				color2 = strval(inputtext);
				
				if(color2 > 255 || color2 < 0)
				{
					format(str, sizeof(str), "{FFFFFF}You're selecting your vehicles second color. ({%06x}%d{FFFFFF})\n Please select a Color ID. (0-255)", VehicleColoursTableRGBA[DealershipCarColors[playerid][1]] >>> 8, DealershipCarColors[playerid][1]); 
					return ShowPlayerDialog(playerid, DIALOG_DEALERSHIP_APPEND_COLOR1, DIALOG_STYLE_INPUT, caption, str, "Select", "<<");  
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
						
				ShowPlayerDialog(playerid, DIALOG_DEALERSHIP_APPEND_CMENU, DIALOG_STYLE_LIST, caption, str, "Select", "<<"); 
			}
			return 1;
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
					format(str, sizeof(str), "Welcome to {297183}Storylines RPG{DEDEDE}, {FFFFFF}%s!\n\n{DEDEDE}Failure to authenticate three times will result in a {E03232}kick{DEDEDE}.\nYou have a total of {EEC650}five minutes{DEDEDE} to authenticate.\n\nIn order to proceed, enter a {EEC650}password{DEDEDE} below to authenticate (or register).", ReturnSettingsName(playerid, playerid));
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
						if ((id = GetNearestVehicle(playerid)) != -1 && !VehicleInfo[id][E_VEHICLE_LOCKED])
						{
							if(GetVehicleModel(id) == 459 || GetVehicleModel(id) == 482 || GetVehicleModel(id) == 440 || GetVehicleModel(id) == 413)
							{
								if (id == -1) {
									return SendErrorMessage(playerid, "You don't have anymore of this item to store!");
								}
								else if (InventoryInfo[playerid][listitem][E_INVENTORY_QUANTITY] == 1)
								{
									if(!strcmp(name, "Products Cargo") && VS_Count(id, "Products Cargo") >= 3 || !strcmp(name, "Woods Cargo") && VS_Count(id, "Woods Cargo") >= 3 || !strcmp(name, "Tools Cargo") && VS_Count(id, "Tools Cargo") >= 3 || !strcmp(name, "Clothes Cargo") && VS_Count(id, "Clothes Cargo") >= 3)
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
									if(!strcmp(name, "Products Cargo") && VS_Count(id, "Products Cargo") >= 5 || !strcmp(name, "Woods Cargo") && VS_Count(id, "Woods Cargo") >= 5 || !strcmp(name, "Tools Cargo") && VS_Count(id, "Tools Cargo") >= 5 || !strcmp(name, "Clothes Cargo") && VS_Count(id, "Clothes Cargo") >= 5)
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
									if(!strcmp(name, "Products Cargo") && VS_Count(id, "Products Cargo") >= 8 || !strcmp(name, "Woods Cargo") && VS_Count(id, "Woods Cargo") >= 8 || !strcmp(name, "Tools Cargo") && VS_Count(id, "Tools Cargo") >= 8 || !strcmp(name, "Clothes Cargo") && VS_Count(id, "Clothes Cargo") >= 8)
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
									if(!strcmp(name, "Products Cargo") && VS_Count(id, "Products Cargo") >= 10 || !strcmp(name, "Woods Cargo") && VS_Count(id, "Woods Cargo") >= 10 || !strcmp(name, "Tools Cargo") && VS_Count(id, "Tools Cargo") >= 10 || !strcmp(name, "Clothes Cargo") && VS_Count(id, "Clothes Cargo") >= 10)
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
				    SendServerMessage(userid, "%s has given you \"%s\" (added to inventory).", ReturnSettingsName(playerid, playerid), string);

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
			    SendServerMessage(userid, "%s has given you \"%s\" (added to inventory).", ReturnSettingsName(playerid, playerid), string);

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
						format(string, sizeof(string), "~g~%s~w~ added to inventory!", DroppedInfo[id][E_DROPPED_ITEM]);
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
			        	new str[1024];
			        	strcat(str, "/stats\tSee your character's stats\n/admins\tSee list administrator on/off duty\n/report\tReport something to admin\n/o(oc)\tOut of character global chat\n/pay\tPay to another players\n/isafk\tSee who is afk\n/time\tSee the time\n/levelup\tLevel up your character\n");
						strcat(str, "/enter\tEnter building\n/exit\tExit building\n/mask\tWear your mask\n/setchannel\tSet your channel radio\n/setslot\tSet your slot radio\n/radio\tTalk to radio\n/licenseexam\tDriving test in dmv\n/unimpound\tUnimpound your vehicle\n/rcp\tShow checkpoint if u loss\n/inventory(y)\tSee your inventory\n");
						strcat(str, "/jobs\tSee list available jobs\n/damages\tSee your damages from your body\n/acceptdeath\tAccepted your wounded bound situation\n/fixr\tFix your radio\n/respawnme\tWake up from injured\n/setspawn\tSet your setspawn\n/settings\tSettings your gameplay.\n/approve\tapprove from other player offer\n");
			    		strcat(str, "/coin\tFlips your coin\n/dice\tRolls a dice\n/gascan\tRefilling your vehicle fuel\n/repairkits\tRepairing your vehicle engine\n/cursor\tEnable/disable your cursorn");
			    		ShowPlayerDialog(playerid, DIALOG_DEFAULT, DIALOG_STYLE_TABLIST, "General Commands:", str, "Select", "Close");
					}
					case 1:
					{
						new str[1024];
						strcat(str, "/me\tDo an emote with your character\n/do\tDo an emote to another entity than your own character\n/ame\tDo an emote that shown above your character\n/my\tDo an emote in possesive pronoun\n/amy\tDo an emote in possesive pronoun above your character\n/shout\tShout with your character\n");
						strcat(str, "/low\tTalk in low chat\n/b\tWrite in local OOC chat\n/pm\tsend private messages another players\n/deposit\tDeposit your money to bank\n/withdraw\tWithdraw your money\n/balance\tSee your balance in bank\n/license\tShow your licenses\n/animhelp\tSee all available animations\n/handshake\tshake your hand to other player\n/frisk\tinspect other player inventory\n/voicelines\tVoicelines character in gta");
						ShowPlayerDialog(playerid, DIALOG_DEFAULT, DIALOG_STYLE_TABLIST, "Roleplay Commands:", str, "Select", "Close");
					}
					case 2:
					{
						new str[512];
						strcat(str, "/buyproperty\tBuy properties availables\n/lock\tLocked or Unlock your properties\n/setstation\tSet boombox music in your properties\n/property\tSee your properties list");
						ShowPlayerDialog(playerid, DIALOG_DEFAULT, DIALOG_STYLE_TABLIST, "Property Commands:", str, "Select", "Close");
					}
					case 3:
					{
						new str[512];
						strcat(str, "/buybiz\tBuy business in server\n/bizinfo\tSee information business\n/bizfee\tSet your business fee\n/bizcash\tOpen your business cash\n/sellbiz\tSell your business to server\n");
						ShowPlayerDialog(playerid, DIALOG_DEFAULT, DIALOG_STYLE_TABLIST, "Business Commands:", str, "Select", "Close");
					}
					case 4:
					{
						new str[512];
						strcat(str, "/factionhelp\tSee faction commands\n/factions\tSee faction list in server\n/(f)action\tTalk in faction chat\n/togfam\tToggle your faction chat\n/factionon\tSee faction member online\n/accept\tAccept invitation faction");
						ShowPlayerDialog(playerid, DIALOG_DEFAULT, DIALOG_STYLE_TABLIST, "Faction Commands:", str, "Select", "Close");
					}
					case 5:
					{
						new str[1024];
						strcat(str, "/carlist\tList/Spawn your own vehicles\n/carlock\t(Un)lock your own vehicles\ncardespawn\tDespawn your own vehicles\n/carkey\tShare your vehicles keys to another players\n/carscrap\tDestroy your vehicles into Vehicle Scrapyard\n");
						strcat(str, "/carfind\tFind your vehicles in map\n/carhood\tOpen the hood vehicles\n/cartrunk\tOpen the trunks vehicles\n/carlights\tTurn on/off your vehicles lights\n");
						strcat(str, "/engine\tTurn on/off engine on your vehicle\n/check\tCheck your vehicle in trunk\n/place\tPlace your weapon to your vehicle\n/refill\tRefill your vehicle fuel");
						ShowPlayerDialog(playerid, DIALOG_DEFAULT, DIALOG_STYLE_TABLIST, "Vehicle Commands:", str, "Select", "Close");
					}
					case 6:
					{
						new str[512];
						strcat(str, "/court\tStart playin' basketball in court\n/resetcourt\tif the ball lost/fall into ground will reset to default position.\nPress 'LMB'\tTo shoot the ball from a distance.\nPress 'LMB'\tClose to the hoop to dunk basketball.\nPress 'LMB'\tWill nearest player to steal the ball.\n");
						strcat(str, "Press 'LMB'\tTo pass the ball to nearest player.\nHold 'LALT'\tTo stay/idle will you have a ball.\nHold 'LALT'\tBlocking their ball from nearest distance.");
						ShowPlayerDialog(playerid, DIALOG_DEFAULT, DIALOG_STYLE_TABLIST, "Minigames Commands:", str, "Select", "Close");
					}
					case 7:
					{
						new str[1024];
						strcat(str, "CMD\tDescription\tType\n");
						strcat(str, "/takejobs\tStart join the jobs\tTake Jobs\nPress '2'\tStart the jobs missions\tDocksworker & Garbageman\nPress 'ALT'\tPickup trash nearest trashcan pickup\tGarbageman\n/takecargo\tLoad the cargo package from oceandocks import warehouse\tDocksworker\n/storecargo\tUnload the cargo package into oceandocks export warehouse\tDocksworker\n");
						strcat(str, "/tpda\tSee the industry list\tTruckers\n/cargobuy\tBuy products cargo from oceandocks ships\tTruckers\n/cargosell\tSell products cargo to business\tTruckers\n/cargodrop\tDropped/Remove products cargo in your inventory\tTruckers\n");
						strcat(str, "/fish\tStart fishing jobs\tActivity\n");
						ShowPlayerDialog(playerid, DIALOG_DEFAULT, DIALOG_STYLE_TABLIST_HEADERS, "Jobs Commands:", str, "Select", "Close");
					}
					case 8:
					{
						new str[512];
						strcat(str, "Press 'ALT'\tStolen goods in NPC House\nHold 'RMB'\tHold aim into actor/npc to start robbery in business\nPress 'LMB'\tBeat'em into actor/npc to start extortion in business\n");
						strcat(str, "/extort\tStart extortion in business\n/extortions\tSee the list of business you have relations with them\n/drugsdeal\tSelling Drugs to NPC\n");
						ShowPlayerDialog(playerid, DIALOG_DEFAULT, DIALOG_STYLE_TABLIST, "Crime Professions Commands:", str, "Select", "Close");
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
				SendClientMessageEx(playerid, COLOR_WHITE, "Fishing: You have sold all the fish and earn %s.", FormatMoney(total));
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
							SendClientMessage(playerid, COLOR_WHITE, "Settings: Streets TextDraws has been Enable.");
						}
						else
						{
							PlayerInfo[playerid][E_CHARACTER_TOGHUD] = true;
							SendClientMessage(playerid, COLOR_WHITE, "Settings: Streets TextDraws has been Disable.");
						}
					}
					case 1:
					{
						if(PlayerInfo[playerid][E_CHARACTER_TOGJOIN])
						{
							PlayerInfo[playerid][E_CHARACTER_TOGJOIN] = false;
							SendClientMessage(playerid, COLOR_WHITE, "Settings: Joined Logs has been Enable.");
						}
						else
						{
							PlayerInfo[playerid][E_CHARACTER_TOGJOIN] = true;
							SendClientMessage(playerid, COLOR_WHITE, "Settings: Joined Logs has been Disable.");
						}
					}
					case 2:
					{
						if(PlayerInfo[playerid][E_CHARACTER_TOGADMIN])
						{
							PlayerInfo[playerid][E_CHARACTER_TOGADMIN] = false;
							SendClientMessage(playerid, COLOR_WHITE, "Settings: Admin Messages has been Enable.");
						}
						else
						{
							PlayerInfo[playerid][E_CHARACTER_TOGADMIN] = true;
							SendClientMessage(playerid, COLOR_WHITE, "Settings: Admin Messages has been Disable.");
						}
					}
					case 3:
					{
						if(PlayerInfo[playerid][E_CHARACTER_TOGFMS])
						{
							PlayerInfo[playerid][E_CHARACTER_TOGFMS] = false;
							SendClientMessage(playerid, COLOR_WHITE, "Settings: Faction Messages has been Enable.");
						}
						else
						{
							PlayerInfo[playerid][E_CHARACTER_TOGFMS] = true;
							SendClientMessage(playerid, COLOR_WHITE, "Settings: Faction Messages has been Disable.");
						}
					}
					case 4:
					{
						if(PlayerInfo[playerid][E_CHARACTER_TOGPMS])
						{
							PlayerInfo[playerid][E_CHARACTER_TOGPMS] = false;
							SendClientMessage(playerid, COLOR_WHITE, "Settings: Private Messages has been Enable.");
						}
						else
						{
							PlayerInfo[playerid][E_CHARACTER_TOGPMS] = true;
							SendClientMessage(playerid, COLOR_WHITE, "Settings: Private Messages has been Disable.");
						}
					}
					case 5:
					{
						if(PlayerInfo[playerid][E_CHARACTER_TOGDMS])
						{
							PlayerInfo[playerid][E_CHARACTER_TOGDMS] = false;
							SendClientMessage(playerid, COLOR_WHITE, "Settings: Damages Messages has been Enable.");
						}
						else
						{
							PlayerInfo[playerid][E_CHARACTER_TOGDMS] = true;
							SendClientMessage(playerid, COLOR_WHITE, "Settings: Damages Messages has been Disable.");
						}
					}
					case 6:
					{
						if(PlayerInfo[playerid][E_CHARACTER_TOGNAMESTYLE])
						{
							PlayerInfo[playerid][E_CHARACTER_TOGNAMESTYLE] = false;
							UpdateTabListForPlayer(playerid);
							SendClientMessage(playerid, COLOR_WHITE, "Settings: switched your namestyle to streetnames tags.");
						}
						else
						{
							PlayerInfo[playerid][E_CHARACTER_TOGNAMESTYLE] = true;
							UpdateTabListForPlayer(playerid);
							SendClientMessage(playerid, COLOR_WHITE, "Settings: switched your namestyle to Firstname_Lastname.");
						}
					}
					case 7:
					{
						if(PlayerInfo[playerid][E_CHARACTER_TOGDD])
						{
							PlayerInfo[playerid][E_CHARACTER_TOGDD] = false;
							SendClientMessage(playerid, COLOR_WHITE, "Settings: Draw Distance has been set to Low.");
							Streamer_SetVisibleItems(STREAMER_TYPE_OBJECT, 5000, playerid);
						}
						else
						{
							PlayerInfo[playerid][E_CHARACTER_TOGDD] = true;
							SendClientMessage(playerid, COLOR_WHITE, "Settings: Draw Distance has been set to High.");
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
						SendClientMessageEx(playerid, COLOR_JOBS, "[Drug Dealer]:{d7d7d7} You've opened drugs corner at %s, it will run for 15 minutes.", ReturnLocationStreet(playerid));
					}
					case 1: //Heroin
					{
						new type = 3;
						if(!PlayerInfo[playerid][E_CHARACTER_FACTION])
							return SendErrorMessage(playerid, "You are not apart a gang members");

						if(FactionInfo[PlayerInfo[playerid][E_CHARACTER_FACTION]][E_FACTION_TYPE] != FACTION_TYPE_ILLEGAL)
							return SendErrorMessage(playerid, "You can't buy because you are not apart in a gang."); 

						SetTimerEx("DrugsDealing", 15000, false, "iiffff", playerid, type, x, y, z ,a);
						SendClientMessageEx(playerid, COLOR_JOBS, "[Drug Dealer]:{d7d7d7} You've opened drugs corner at %s, it will run for 15 minutes.", ReturnLocationStreet(playerid));
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
						SendClientMessageEx(playerid, COLOR_JOBS, "[Drug Dealer]:{d7d7d7} You've opened drugs corner at %s, it will run for 15 minutes.", ReturnLocationStreet(playerid));
					}
					case 1: //PCP
					{
						new type = 4;
						if(!PlayerInfo[playerid][E_CHARACTER_FACTION])
							return SendErrorMessage(playerid, "You are not apart a gang members");

						if(FactionInfo[PlayerInfo[playerid][E_CHARACTER_FACTION]][E_FACTION_TYPE] != FACTION_TYPE_ILLEGAL)
							return SendErrorMessage(playerid, "You can't buy because you are not apart in a gang."); 

						SetTimerEx("DrugsDealing", 15000, false, "iiffff", playerid, type, x, y, z ,a);
						SendClientMessageEx(playerid, COLOR_JOBS, "[Drug Dealer]:{d7d7d7} You've opened drugs corner at %s, it will run for 15 minutes.", ReturnLocationStreet(playerid));
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
						SendClientMessageEx(playerid, COLOR_JOBS, "[Drug Dealer]:{d7d7d7} You've received $%d from selling crack.", cost);

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
						SendClientMessageEx(playerid, COLOR_JOBS, "[Drug Dealer]:{d7d7d7} You've received $%d from selling marijuana.", cost);

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
						SendClientMessageEx(playerid, COLOR_JOBS, "[Drug Dealer]:{d7d7d7} You've received $%d from selling heroin.", cost);

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
						SendClientMessageEx(playerid, COLOR_JOBS, "[Drug Dealer]:{d7d7d7} You've received $%d from selling pcp.", cost);

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
		case DIALOG_SPRAYMENU:
		{
			if(response)
			{
				switch(listitem)
				{
					case 0: ShowPlayerDialog(playerid, DIALOG_SPRAYSTATIC, DIALOG_STYLE_MSGBOX, "Spraytags:", "You are now selecting static type spraytags\nYour spraytags will replace the spraytags from 'GTA Classic Locations' or 'Another spraytags'\nPress 'Select' to continue", "Select", "Cancel");
					case 1: ShowPlayerDialog(playerid, DIALOG_SPRAYFONT, DIALOG_STYLE_INPUT, "Spraytags:", "You are now selecting custom static type spraytags\nYour spraytags will replace the spraytags with custom font.\nThe font you input will only be visible to visual players that only have that font\nPlease input the font below:", "Input", "Cancel");
					case 2: ShowPlayerDialog(playerid, DIALOG_SPRAYCREATE, DIALOG_STYLE_MSGBOX, "Spraytags:", "You are now making spraytags, use the spraycan to start spraying on the wall\nPress 'Select' to continue", "Select", "Cancel");
				}
			}
		}
		case DIALOG_SPRAYCOLOR:
		{
			if(response)
			{
				switch(listitem)
				{
					case 0:
					{
						new iColor = HexToInt("0xFF2C6B2F");
						PlayerInfo[playerid][E_CHARACTER_OBJECTCOLOR] = iColor;
						ShowPlayerDialog(playerid, DIALOG_SPRAYSTATIC2, DIALOG_STYLE_INPUT, "Spraytags Texts:", "You are now selecting custom static type spraytags\nYour spraytags will replace the spraytags with custom font.\nAllowed letter is A - Z and ( ) - = / ? \nTo break the letter use \"|\"\nPlease input the letter below:", "Input", "Cancel");
					}
					case 1:
					{
						new iColor = HexToInt("0xFF9EC9A0");
						PlayerInfo[playerid][E_CHARACTER_OBJECTCOLOR] = iColor;
						ShowPlayerDialog(playerid, DIALOG_SPRAYSTATIC2, DIALOG_STYLE_INPUT, "Spraytags Texts:", "You are now selecting custom static type spraytags\nYour spraytags will replace the spraytags with custom font.\nAllowed letter is A - Z and ( ) - = / ? \nTo break the letter use \"|\"\nPlease input the letter below:", "Input", "Cancel");
					}
					case 2:
					{
						new iColor = HexToInt("0xFF6D9D6F");
						PlayerInfo[playerid][E_CHARACTER_OBJECTCOLOR] = iColor;
						ShowPlayerDialog(playerid, DIALOG_SPRAYSTATIC2, DIALOG_STYLE_INPUT, "Spraytags Texts:", "You are now selecting custom static type spraytags\nYour spraytags will replace the spraytags with custom font.\nAllowed letter is A - Z and ( ) - = / ? \nTo break the letter use \"|\"\nPlease input the letter below:", "Input", "Cancel");
					}
					case 3:
					{
						new iColor = HexToInt("0xFF6C1D8A");
						PlayerInfo[playerid][E_CHARACTER_OBJECTCOLOR] = iColor;
						ShowPlayerDialog(playerid, DIALOG_SPRAYSTATIC2, DIALOG_STYLE_INPUT, "Spraytags Texts:", "You are now selecting custom static type spraytags\nYour spraytags will replace the spraytags with custom font.\nAllowed letter is A - Z and ( ) - = / ? \nTo break the letter use \"|\"\nPlease input the letter below:", "Input", "Cancel");
					}
					case 4:
					{
						new iColor = HexToInt("0xFF9B4F8F");
						PlayerInfo[playerid][E_CHARACTER_OBJECTCOLOR] = iColor;
						ShowPlayerDialog(playerid, DIALOG_SPRAYSTATIC2, DIALOG_STYLE_INPUT, "Spraytags Texts:", "You are now selecting custom static type spraytags\nYour spraytags will replace the spraytags with custom font.\nAllowed letter is A - Z and ( ) - = / ? \nTo break the letter use \"|\"\nPlease input the letter below:", "Input", "Cancel");
					}
					case 5:
					{
						new iColor = HexToInt("0xFF8A2C7C");
						PlayerInfo[playerid][E_CHARACTER_OBJECTCOLOR] = iColor;
						ShowPlayerDialog(playerid, DIALOG_SPRAYSTATIC2, DIALOG_STYLE_INPUT, "Spraytags Texts:", "You are now selecting custom static type spraytags\nYour spraytags will replace the spraytags with custom font.\nAllowed letter is A - Z and ( ) - = / ? \nTo break the letter use \"|\"\nPlease input the letter below:", "Input", "Cancel");
					}
					case 6:
					{
						new iColor = HexToInt("0xFFAC09C7");
						PlayerInfo[playerid][E_CHARACTER_OBJECTCOLOR] = iColor;
						ShowPlayerDialog(playerid, DIALOG_SPRAYSTATIC2, DIALOG_STYLE_INPUT, "Spraytags Texts:", "You are now selecting custom static type spraytags\nYour spraytags will replace the spraytags with custom font.\nAllowed letter is A - Z and ( ) - = / ? \nTo break the letter use \"|\"\nPlease input the letter below:", "Input", "Cancel");
					}
					case 7:
					{
						new iColor = HexToInt("0xFF7BEDff");
						PlayerInfo[playerid][E_CHARACTER_OBJECTCOLOR] = iColor;
						ShowPlayerDialog(playerid, DIALOG_SPRAYSTATIC2, DIALOG_STYLE_INPUT, "Spraytags Texts:", "You are now selecting custom static type spraytags\nYour spraytags will replace the spraytags with custom font.\nAllowed letter is A - Z and ( ) - = / ? \nTo break the letter use \"|\"\nPlease input the letter below:", "Input", "Cancel");
					}
					case 8:
					{
						new iColor = HexToInt("0xFFFFDF7B");
						PlayerInfo[playerid][E_CHARACTER_OBJECTCOLOR] = iColor;
						ShowPlayerDialog(playerid, DIALOG_SPRAYSTATIC2, DIALOG_STYLE_INPUT, "Spraytags Texts:", "You are now selecting custom static type spraytags\nYour spraytags will replace the spraytags with custom font.\nAllowed letter is A - Z and ( ) - = / ? \nTo break the letter use \"|\"\nPlease input the letter below:", "Input", "Cancel");
					}
					case 9:
					{
						new iColor = HexToInt("0xFFD7A542");
						PlayerInfo[playerid][E_CHARACTER_OBJECTCOLOR] = iColor;
						ShowPlayerDialog(playerid, DIALOG_SPRAYSTATIC2, DIALOG_STYLE_INPUT, "Spraytags Texts:", "You are now selecting custom static type spraytags\nYour spraytags will replace the spraytags with custom font.\nAllowed letter is A - Z and ( ) - = / ? \nTo break the letter use \"|\"\nPlease input the letter below:", "Input", "Cancel");
					}
				}
			}
		}
		case DIALOG_SPRAYFONT:
		{
			if(response)
			{
				if (isnull(inputtext) || !FilterInputFont(inputtext) || strlen(inputtext) < 5)
					return ShowPlayerDialog(playerid, DIALOG_SPRAYFONT, DIALOG_STYLE_INPUT, "Spraytags Fonts:", "You are now selecting custom static type spraytags\nYour spraytags will replace the spraytags with custom font.\nThe font you input will only be visible to visual players that only have that font\nPlease input the font below:", "Input", "Cancel");

				format(PlayerInfo[playerid][E_CHARACTER_OBJECTFONT], 512, inputtext);

				new str[256];
				strcat(str, "{2C6B2F}Green\n");
				strcat(str, "{9EC9A0}Light Green\n");
				strcat(str, "{6D9D6F}Dark Green\n");
				strcat(str, "{6C1D8A}Purple\n");
				strcat(str, "{9B4F8F}Light Purple\n");
				strcat(str, "{8A2C7C}Medium Purple\n");
				strcat(str, "{AC09C7}Dark Purple\n");
				strcat(str, "{7BEDff}Cyan\n");
				strcat(str, "{FFDF7B}Yellow\n");
				strcat(str, "{D7A542}Orange");
				ShowPlayerDialog(playerid, DIALOG_SPRAYCOLOR, DIALOG_STYLE_LIST, "Spraytags Colors:", str, "Select", "Cancel");
			}
		}
		case DIALOG_SPRAYSTATIC:
		{
			if(response)
			{
				new id = Spraytags_Nearest(playerid);

				if(id != -1)
				{
					new str[32];
					format(str, sizeof(str), "Static");
					SetTimerEx("SprayingTags", 10000, false, "isiffffff", playerid, str, 1, SpraytagsInfo[id][E_SPRAYTAGS_POS][0], SpraytagsInfo[id][E_SPRAYTAGS_POS][1], SpraytagsInfo[id][E_SPRAYTAGS_POS][2], SpraytagsInfo[id][E_SPRAYTAGS_POS][3], SpraytagsInfo[id][E_SPRAYTAGS_POS][4], SpraytagsInfo[id][E_SPRAYTAGS_POS][5]);
							
					ApplyAnimation(playerid, "GRAFFITI", "null", 4.0, 0, 0, 0, 0, 0, 0);
					ApplyAnimation(playerid, "GRAFFITI", "spraycan_fire", 4.0, 1, 0, 0, 0, 0, 1);
					ApplyAnimation(playerid, "GRAFFITI", "spraycan_fire", 4.0, 1, 0, 0, 0, 0, 1);
					SetPlayerAttachedObject(playerid, ATTACH_HAND, 365, 6, 0.0000, 0.0000, 0.0360, 0.0000, 0.0000, 0.0000, 1.0000, 1.0000, 1.0000, 0xFFFFFFFF, 0xFFFFFFFF); // spraycan
					SetPlayerAttachedObject(playerid, ATTACH_HAND2, 18729, 6, 0.0460, 1.6179, 0.1640, 92.2999, 0.0000, -78.4000, 1.0000, 1.0000, 1.0000, 0xFFFFFFFF, 0xFFFFFFFF); //spraycan	
				}	
			}
		}
		case DIALOG_SPRAYSTATIC2:
		{
			if (response) 
			{
				if (isnull(inputtext) || strlen(inputtext) < 5 || strlen(inputtext) > 32)
					return ShowPlayerDialog(playerid, DIALOG_SPRAYSTATIC2, DIALOG_STYLE_INPUT, "Spraytags Texts:", "You are now selecting custom static type spraytags\nYour spraytags will replace the spraytags with custom font.\nAllowed letter is A - Z and * = / ? !\nTo break the letter use \"|\"\nPlease input the letter below:", "Input", "Cancel");

				new id = Spraytags_Nearest(playerid);

				if(id != -1)
				{
					new formattedText[512];
					format(formattedText, sizeof(formattedText), "%s", inputtext);

					for (new i = 0; i < strlen(formattedText); i++)
					{
						if (formattedText[i] == '|')
						{
							formattedText[i] = '\n'; 
						}
					}

					format(PlayerInfo[playerid][E_CHARACTER_OBJECTSTRING], 128, formattedText);

					SetTimerEx("SprayingTags", 10000, false, "isiffffff", playerid, formattedText, 2, SpraytagsInfo[id][E_SPRAYTAGS_POS][0], SpraytagsInfo[id][E_SPRAYTAGS_POS][1], SpraytagsInfo[id][E_SPRAYTAGS_POS][2], SpraytagsInfo[id][E_SPRAYTAGS_POS][3], SpraytagsInfo[id][E_SPRAYTAGS_POS][4], SpraytagsInfo[id][E_SPRAYTAGS_POS][5]);
							
					ApplyAnimation(playerid, "GRAFFITI", "null", 4.0, 0, 0, 0, 0, 0, 0);
					ApplyAnimation(playerid, "GRAFFITI", "spraycan_fire", 4.0, 1, 0, 0, 0, 0, 1);
					ApplyAnimation(playerid, "GRAFFITI", "spraycan_fire", 4.0, 1, 0, 0, 0, 0, 1);
					SetPlayerAttachedObject(playerid, ATTACH_HAND, 365, 6, 0.0000, 0.0000, 0.0360, 0.0000, 0.0000, 0.0000, 1.0000, 1.0000, 1.0000, 0xFFFFFFFF, 0xFFFFFFFF); // spraycan
					SetPlayerAttachedObject(playerid, ATTACH_HAND2, 18729, 6, 0.0460, 1.6179, 0.1640, 92.2999, 0.0000, -78.4000, 1.0000, 1.0000, 1.0000, 0xFFFFFFFF, 0xFFFFFFFF); //spraycan	
				}	
			}
		}
		case DIALOG_SPRAYCREATE:
		{
			if(response)
			{
				if(IsPlayerAdmins(playerid) > 2)
				{
					new Float:x, Float:y, Float:z; 
					GetPlayerPos(playerid, x, y, z); 
					PlayerInfo[playerid][E_CHARACTER_ADDOBJECT] = CreateDynamicObject(PlayerInfo[playerid][E_CHARACTER_OBJECTID], x, y, z, 0.0, 0.0, 0.0, GetPlayerVirtualWorld(playerid), GetPlayerInterior(playerid)); 
					EditDynamicObject(playerid, PlayerInfo[playerid][E_CHARACTER_ADDOBJECT]); 
					PlayerInfo[playerid][E_CHARACTER_EDITINGOBJECT] = 1;
				}
				else return SendUnauthMessage(playerid);
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
				if (response)
				{
					if (isnull(inputtext))
					{
						return ShowPlayerDialog(playerid, DIALOG_SMSTEXT, DIALOG_STYLE_INPUT, "Text Message:", "Please enter a message to send.\n\nPlease enter the message to send to:", "Send", "Back");
					}
					new targetid = PlayerInfo[playerid][E_CHARACTER_CONTACT];

					if (!IsPlayerConnected(targetid) || !PlayerInfo[targetid][E_CHARACTER_PHONE])
						return SendErrorMessage(playerid, "The specified phone number went offline.");

					SendClientMessage(playerid, COLOR_GREY, "[ ! ] Your text message is being sent.");

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
						
					playerText[playerid] = SetTimerEx("OnPhoneSMS", 1500, false, "iiis", playerid, 3, targetid, inputtext); 
				}
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

						SendClientMessageEx(playerid, COLOR_PHONE, "[Phone]:{d7d7d7} You have added \"%s\" to your contacts.", name);
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

						SendClientMessageEx(playerid, COLOR_PHONE, "[Phone]:{d7d7d7} You have deleted \"%s\" from your contacts.", ContactInfo[playerid][id][E_CONTACT_NAME]);

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
							SendClientMessageEx(playerid, COLOR_RELATIONS, "[Business]:{d7d7d7} You've got money $%d from take cash money on cashiers.", rand);
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

			if ((carid = GetNearestVehicle(playerid)) != -1 && !VehicleInfo[carid][E_VEHICLE_LOCKED])
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
					SendClientMessageEx(playerid, COLOR_VEHICLE, "[Vehicle]:{d7d7d7} You have closed the trunk.");
				}
			}
		}
		case DIALOG_VOPTIONS:
		{
			static
				carid = -1,
				itemid = -1,
				string[32];

			if ((carid = GetNearestVehicle(playerid)) != -1 && !VehicleInfo[carid][E_VEHICLE_LOCKED])
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
								if(!strcmp(string, "Products Cargo") && Inventory_Count(playerid, "Products Cargo") == 1 || !strcmp(string, "Woods Cargo") && Inventory_Count(playerid, "Woods Cargo") == 1 || !strcmp(string, "Tools Cargo") && Inventory_Count(playerid, "Tools Cargo") == 1 || !strcmp(string, "Clothes Cargo") && Inventory_Count(playerid, "Clothes Cargo") == 1)
									return SendErrorMessage(playerid, "You can't take cargo from your vehicle trunk");

								new id = Inventory_Add(playerid, string, VstorageInfo[carid][itemid][E_VEHICLE_TRUNKMODEL], 1);

								if (id == -1)
									return SendErrorMessage(playerid, "You don't have any storage slots left.");

								VS_RemoveItem(carid, string);
				
								ShowVehicleStorage(playerid, carid);
							}
							else
							{
								if(!strcmp(string, "Products Cargo") && Inventory_Count(playerid, "Products Cargo") == 1 || !strcmp(string, "Woods Cargo") && Inventory_Count(playerid, "Woods Cargo") == 1 || !strcmp(string, "Tools Cargo") && Inventory_Count(playerid, "Tools Cargo") == 1 || !strcmp(string, "Clothes Cargo") && Inventory_Count(playerid, "Clothes Cargo") == 1)
									return SendErrorMessage(playerid, "You can't take cargo from your vehicle trunk");

								if(!strcmp(string, "Products Cargo") && VS_Count(carid, "Products Cargo") > 1 || !strcmp(string, "Woods Cargo") && VS_Count(carid, "Woods Cargo") > 1 || !strcmp(string, "Tools Cargo") && VS_Count(carid, "Tools Cargo") > 1 || !strcmp(string, "Clothes Cargo") && VS_Count(carid, "Clothes Cargo") > 1)
								{
									new id = Inventory_Add(playerid, string, VstorageInfo[carid][itemid][E_VEHICLE_TRUNKMODEL], 1);

									if (id == -1)
										return SendErrorMessage(playerid, "You don't have any storage slots left.");

									VS_RemoveItem(carid, string);
						
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
									if(!strcmp(string, "Products Cargo") && VS_Count(carid, "Products Cargo") >= 3 || !strcmp(string, "Woods Cargo") && VS_Count(carid, "Woods Cargo") >= 3 || !strcmp(string, "Tools Cargo") && VS_Count(carid, "Tools Cargo") >= 3 || !strcmp(string, "Clothes Cargo") && VS_Count(carid, "Clothes Cargo") >= 3)
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
									if(!strcmp(string, "Products Cargo") && VS_Count(carid, "Products Cargo") >= 5 || !strcmp(string, "Woods Cargo") && VS_Count(carid, "Woods Cargo") >= 5 || !strcmp(string, "Tools Cargo") && VS_Count(carid, "Tools Cargo") >= 5 || !strcmp(string, "Clothes Cargo") && VS_Count(carid, "Clothes Cargo") >= 5)
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
									if(!strcmp(string, "Products Cargo") && VS_Count(carid, "Products Cargo") >= 8 || !strcmp(string, "Woods Cargo") && VS_Count(carid, "Woods Cargo") >= 8 || !strcmp(string, "Tools Cargo") && VS_Count(carid, "Tools Cargo") >= 8 || !strcmp(string, "Clothes Cargo") && VS_Count(carid, "Clothes Cargo") >= 8)
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
									if(!strcmp(string, "Products Cargo") && VS_Count(carid, "Products Cargo") >= 10 || !strcmp(string, "Woods Cargo") && VS_Count(carid, "Woods Cargo") >= 10 || !strcmp(string, "Tools Cargo") && VS_Count(carid, "Tools Cargo") >= 10 || !strcmp(string, "Clothes Cargo") && VS_Count(carid, "Clothes Cargo") >= 10)
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
			if ((carid = GetNearestVehicle(playerid)) != -1 && !VehicleInfo[carid][E_VEHICLE_LOCKED])
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

			if ((carid = GetNearestVehicle(playerid)) != -1 && !VehicleInfo[carid][E_VEHICLE_LOCKED])
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
		case DIALOG_INDUSTRY:
		{
			if(response)
			{
				switch(listitem)
				{
					case 0:
					{
						new str[512];
						strcat(str, "Welcome to The Ship!\n\nThe ship is currently restocked product every one hour(s).\n\nYou can buy cargo products if stock is still available on the ship.");
						ShowPlayerDialog(playerid, DIALOG_DEFAULT, DIALOG_STYLE_MSGBOX, "Oceandocks Information", str, "Confirm", "");
					}
					case 1:
					{
						ShowIndustry(playerid);
					}
					case 2:
					{
						ShowShipments(playerid);
					}
				}
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
