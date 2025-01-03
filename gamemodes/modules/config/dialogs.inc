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
	
	Dialog_Show(playerid, DialogConfirm, DIALOG_STYLE_MSGBOX, caption, info, "Yes", "No"); // display the dialog message itself
	
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

Dialog:DialogConfirm(playerid, response, listitem, inputtext[])
{
	ConfirmDialog_Response(playerid, response);
	return 1;
}

Dialog:DialogRegister(playerid, response, listitem, inputtext[])
{
	if(!response)
	{
		SendErrorMessage(playerid, "You were kicked for not registering.");
		return KickEx(playerid); 
	}
	
	new str[128];
	format(str, sizeof(str), "You are not registered user! Plase register!");
	new insert[256]; 
	
	if(strlen(inputtext) > 128 || strlen(inputtext) < 3)
		return Dialog_Show(playerid, DialogRegister, DIALOG_STYLE_PASSWORD, "Register:", str, "Confirm", "");
		
	mysql_format(ourConnection, insert, sizeof(insert), "INSERT INTO `masters` (`acc_name`, `acc_pass`, `register_date`, `register_ip`, `forum_name`) VALUES ('%e', sha1('%e'), '%e', '%e', '%e')", ReturnName(playerid, 1), inputtext, ReturnDate(), ReturnIP(playerid), ReturnName(playerid, 1));
	mysql_pquery(ourConnection, insert, "OnPlayerRegister", "i", playerid);
	return 1;
}

Dialog:DialogLogin(playerid, response, listitem, inputtext[])
{
	if (!response)
	{
		SendErrorMessage(playerid, "You were kicked for not logging in."); 
		return KickEx(playerid);
	}
	
	new continueCheck[211]; 
	
	mysql_format(ourConnection, continueCheck, sizeof(continueCheck), "SELECT * FROM masters WHERE acc_name = '%e' AND acc_pass = sha1('%e') LIMIT 1", 
		ReturnName(playerid, 1), inputtext);
		
	mysql_pquery(ourConnection, continueCheck, "LoggingIn", "i", playerid);
	return 1;
}

Dialog:DialogSpawn(playerid, response, listitem, inputtext[])
{
	if (!response)
	{
		SendErrorMessage(playerid, "You were kicked for not selection spawn."); 
		return KickEx(playerid);
	}

	if(listitem == 9)
	{
		PlayerInfo[playerid][E_CHARACTER_SPAWNPOINT] = SPAWN_POINT_LAST; 
		LoadCharacter(playerid);
	}
	else
	{
		PlayerInfo[playerid][E_CHARACTER_SPAWNPOINT] = listitem; 
		LoadCharacter(playerid);
	}
	return 1;
}

Dialog:DialogCharPreview(playerid, response, listitem, inputtext[])
{
	if(!response)
	{
		if (isnull(playerCharactersName[playerid]) || !playerCharactersSex[playerid] || !playerCharactersAge[playerid] ||
		isnull(playerCharactersEthnicity[playerid]) || isnull(playerCharactersHair[playerid]) || isnull(playerCharactersEyes[playerid]) ||
		!playerCharactersHeights[playerid] || isnull(playerCharactersDescription[playerid]))
		{
			ShowCharacterPreview(playerid);
			SendErrorMessage(playerid, "You must complete the character attribute.");
			return 1;
		}
		
		PlayerInfo[playerid][E_CHARACTER_FACTION] = 0;
		characterSelection[playerid] = true;
		playerMakingCharacter[playerid] = false;
		playerCharacterStep[playerid] = 0; 
		PlayerInfo[playerid][E_CHARACTER_SPAWNPOINT] = 0;

		PlayerInfo[playerid][E_CHARACTER_LASTSKIN] = playerCharactersSkins[playerid];
		
		ClearLines(playerid, 17); 
						
		SendServerMessage(playerid, "You successfully created a new character. Please wait while your list is rebuilt.");
						
		new query[512];

		new fid; 
				
		fid = PlayerInfo[playerid][E_CHARACTER_FACTION];
						
		mysql_format(ourConnection, query, sizeof(query), "INSERT INTO characters (`master_dbid`, `char_name`, `char_masters`, `pAge`, `pEthnicity`, `pGender`, `pHair`, `pEyes`, `pHeight`, `pFaction`, `pLastSkin`, `create_date`, `create_ip`, `pPhone`, pSpawnPoint, pLastPosX, pLastPosY, pLastPosZ) \
		VALUES(%i, '%e', '%e', '%d', '%e', '%d', '%e', '%e', '%d', '%d', '%d', '%e', '%e', %d, %d, %f, %f, %f)", AccountInfo[playerid][E_MASTERS_DBID], playerCharactersName[playerid], AccountInfo[playerid][E_MASTERS_ACCNAME], playerCharactersAge[playerid],
		playerCharactersEthnicity[playerid], playerCharactersSex[playerid], playerCharactersHair[playerid], playerCharactersEyes[playerid], playerCharactersHeights[playerid], PlayerInfo[playerid][E_CHARACTER_FACTION], PlayerInfo[playerid][E_CHARACTER_LASTSKIN], ReturnDate(), ReturnIP(playerid), 94000+random(6999), PlayerInfo[playerid][E_CHARACTER_SPAWNPOINT], FactionInfo[fid][E_FACTION_SPAWN][0], FactionInfo[fid][E_FACTION_SPAWN][1], FactionInfo[fid][E_FACTION_SPAWN][2]);				
		mysql_pquery(ourConnection, query); 
						
		SetTimerEx("RefreshCharacters", 1000, false, "i", playerid);
	}

	if(response)
	{
		switch(listitem)
		{
			case 0: // Name:
			{
				Dialog_Show(playerid, DialogCharName, DIALOG_STYLE_INPUT, "Character Name:", "Insert a full name of your character.\n{33AA33}Info:{ffffff} Required in format of Firstname_Lastname", "Confirm", "");	
			}
			case 1: // Sex:
			{
				Dialog_Show(playerid, DialogCharSex, DIALOG_STYLE_LIST, "Character Sex:", "Male\nFemale", "Edit", "Finish");	
			}
			case 2: // Age:
			{
				Dialog_Show(playerid, DialogCharAge, DIALOG_STYLE_INPUT, "Character Age:", "Insert a age of your character.\n{33AA33}{33AA33}Info:{ffffff}{ffffff} Required in format cannot be less than 18 years old", "Confirm", "");	
			}
			case 3: // Ethnicity:
			{
				Dialog_Show(playerid, DialogCharEthnic, DIALOG_STYLE_LIST, "Character Ethnicity:", "White\nBlack\nLatino\nAsian", "Confirm", "");	
			}
			case 4: // Hair:
			{
				Dialog_Show(playerid, DialogCharHair, DIALOG_STYLE_LIST, "Character Hair:", "Bald\nBlack\nBrown\nBlonde\nWhite\nGray\nRed", "Confirm", "");	
			}
			case 5: // Eyes:
			{
				Dialog_Show(playerid, DialogCharEyes, DIALOG_STYLE_LIST, "Character Eyes:", "Amber\nBlack\nBrown\nBlue\nGray\nHazel", "Confirm", "");	
			}
			case 6: // Height:
			{
				Dialog_Show(playerid, DialogCharHeight, DIALOG_STYLE_INPUT, "Character Age:", "Insert a height of your character.\n{33AA33}Info:{ffffff} Required in format cannot be less than 160 cm", "Confirm", "");	
			}
			case 7: //Description
			{
				Dialog_Show(playerid, DialogCharDesc, DIALOG_STYLE_INPUT, "Character Description:", "Insert a description of your character.\n{33AA33}Info:{ffffff} Required for description your characters", "Confirm", "");	
			}
		}
	}
	return 1;
}

Dialog:DialogCharName(playerid, response, listitem, inputtext[])
{
	if(response)
	{
		if(strlen(inputtext) > MAX_PLAYER_NAME + 1 || strlen(inputtext) < 3)
		{
			Dialog_Show(playerid, DialogCharName, DIALOG_STYLE_INPUT, "Character Name:", "Insert a full name of your character.\n{33AA33}Info:{ffffff} Required in format of Firstname_Lastname", "Confirm", "");	
			SendErrorMessage(playerid, "Your characters name must be at least 3 characters and no more than %i characters.", MAX_PLAYER_NAME);
			return 1;
		}
		if(!IsValidRoleplayName(inputtext))
		{
			Dialog_Show(playerid, DialogCharName, DIALOG_STYLE_INPUT, "Character Name:", "Insert a full name of your character.\n{33AA33}Info:{ffffff} Required in format of Firstname_Lastname", "Confirm", "");	
			SendErrorMessage(playerid, "Please follow the Firstname_Lastname format to make your character."); 
			return 1;
		}
		
		foreach (new i : Player)
		{
			if(!strcmp(inputtext, ReturnName(i, playerid)))
			{
				Dialog_Show(playerid, DialogCharName, DIALOG_STYLE_INPUT, "Character Name:", "Insert a full name of your character.\n{33AA33}Info:{ffffff} Required in format of Firstname_Lastname", "Confirm", "");	
				SendErrorMessage(playerid, "That character already exists. Please try again."); 
				return 1;
			}
		}
		
		new
			threadSearch[128]
		;
		
		format(playerCharactersName[playerid], 128, "%s", inputtext); 
		
		mysql_format(ourConnection, threadSearch, sizeof(threadSearch), "SELECT char_dbid FROM characters WHERE char_name = '%e'", inputtext);
		mysql_pquery(ourConnection, threadSearch, "Query_CreateCharacter", "i", playerid);
	}
	return 1;
}

Dialog:DialogCharSex(playerid, response, listitem, inputtext[])
{
	if(response)
	{
		switch(listitem)
		{
			case 0: //male
			{
				playerCharactersSex[playerid] = 1;
				
				new rand = random(sizeof(g_aMaleSkins));
				playerCharactersSkins[playerid] = g_aMaleSkins[rand];
				CreatePlayerActor(playerid, playerCharactersSkins[playerid]);
				ShowCharacterPreview(playerid);
			}
			case 1: //female
			{
				new rand = random(sizeof(g_aFemaleSkins));
				playerCharactersSkins[playerid] = g_aFemaleSkins[rand];
				CreatePlayerActor(playerid, playerCharactersSkins[playerid]);
				playerCharactersSex[playerid] = 2;
				ShowCharacterPreview(playerid);
			}
		}
	}
	return 1;
}

Dialog:DialogCharAge(playerid, response, listitem, inputtext[])
{
	if(response)
	{
		if(strval(inputtext) > 60 || strval(inputtext) < 18 || isnull(inputtext))
		{
			Dialog_Show(playerid, DialogCharAge, DIALOG_STYLE_INPUT, "Character Age:", "Insert a age of your character.\n{33AA33}Info:{ffffff} Required in format cannot be less than 18 years old", "Confirm", "");	
			SendErrorMessage(playerid, "Your characters age must be at least 18 years old and no more than 60 years old.");
			return 1;
		}

		playerCharactersAge[playerid] = strval(inputtext);
		ShowCharacterPreview(playerid);
	}
	return 1;
}

Dialog:DialogCharEthnic(playerid, response, listitem, inputtext[])
{
	if(response)
	{
		format(playerCharactersEthnicity[playerid], 128, "%s", inputtext); 
		ShowCharacterPreview(playerid);
	}
	return 1;
}

Dialog:DialogCharHair(playerid, response, listitem, inputtext[])
{
	if(response)
	{
		format(playerCharactersHair[playerid], 20, "%s", inputtext); 
		ShowCharacterPreview(playerid);
	}
	return 1;
}

Dialog:DialogCharEyes(playerid, response, listitem, inputtext[])
{
	if(response)
	{
		format(playerCharactersEyes[playerid], 20, "%s", inputtext); 
		ShowCharacterPreview(playerid);
	}
	return 1;
}

Dialog:DialogCharHeight(playerid, response, listitem, inputtext[])
{
	if(response)
	{
		if(strval(inputtext) > 190 || strval(inputtext) < 160 || isnull(inputtext) || !IsNumeric(inputtext))
		{
			Dialog_Show(playerid, DialogCharHeight, DIALOG_STYLE_INPUT, "Character Age:", "Insert a height of your character.\n{33AA33}Info:{ffffff} Required in format cannot be less than 160 cm", "Confirm", "");	
			SendErrorMessage(playerid, "Your characters height must be at least 160 cm and no more than 180 cm.");
			return 1;
		}

		playerCharactersHeights[playerid] = strval(inputtext); 
		ShowCharacterPreview(playerid);
	}
	return 1;
}
Dialog:DialogCharDesc(playerid, response, listitem, inputtext[])
{
	if(response)
	{
		if(strlen(inputtext) > 32 || strlen(inputtext) < 12 || isnull(inputtext))
		{
			Dialog_Show(playerid, DialogCharDesc, DIALOG_STYLE_INPUT, "Character Description:", "Insert a description of your character.\n{33AA33}Info:{ffffff} Required for description your characters", "Confirm", "");	
			SendErrorMessage(playerid, "Your characters description must be at least 12 characters and no more than 32 characters.");
			return 1;
		}

		format(playerCharactersDescription[playerid], 20, "%s", inputtext); 
		ShowCharacterPreview(playerid);
	}
	return 1;
}

Dialog:DialogStreetShop(playerid, response, listitem, inputtext[])
{
	if(response)
	{
		switch(listitem)
		{
			case 0:
			{
				if(50 > AccountInfo[playerid][E_MASTERS_STREETCREDITS])
					return SendErrorMessage(playerid, "You can't afford a this items");

				Dialog_Show(playerid, DialogChangePhone, DIALOG_STYLE_INPUT, "Change Phone Number:", "Insert a new phone number below.\n{33AA33}Info:{ffffff} Required in format of number only Ex: 911922", "Select", "Close");
			}
			case 1:
			{
				if(70 > AccountInfo[playerid][E_MASTERS_STREETCREDITS])
					return SendErrorMessage(playerid, "You can't afford a items");
				
				Dialog_Show(playerid, DialogChangeMask, DIALOG_STYLE_INPUT, "Change Mask ID:", "Insert a new mask id below.\n{33AA33}Info:{ffffff} Required in format of number only Ex: 911922", "Select", "Close");
			}
			case 2:
			{
				if(150 > AccountInfo[playerid][E_MASTERS_STREETCREDITS])
					return SendErrorMessage(playerid, "You can't afford a items");

				Dialog_Show(playerid, DialogChangeName, DIALOG_STYLE_INPUT, "Change Name:", "Insert a full name of your character.\n{33AA33}Info:{ffffff} Required in format of number only Ex: 911922", "Select", "Close");
			}
			case 3:
			{
				if(80 > AccountInfo[playerid][E_MASTERS_STREETCREDITS])
					return SendErrorMessage(playerid, "You can't afford a items");

				AccountInfo[playerid][E_MASTERS_STREETCREDITS] -= 80;
				AccountInfo[playerid][E_MASTERS_VIP] = 1;
				AccountInfo[playerid][E_MASTERS_VIPTIMER] = gettime() + (7 * 86400);
				SendServerMessage(playerid, "You has purchase supreme vip level 7 days for 50 street credits.");
			}
			case 4:
			{
				if(120 > AccountInfo[playerid][E_MASTERS_STREETCREDITS])
					return SendErrorMessage(playerid, "You can't afford a items");

				AccountInfo[playerid][E_MASTERS_STREETCREDITS] -= 120;
				AccountInfo[playerid][E_MASTERS_VIP] = 2;
				AccountInfo[playerid][E_MASTERS_VIPTIMER] = gettime() + (7 * 86400);
				SendServerMessage(playerid, "You has purchase legend vip level 7 days for 120 street credits.");
			}
			case 5:
			{
				if(150 > AccountInfo[playerid][E_MASTERS_STREETCREDITS])
					return SendErrorMessage(playerid, "You can't afford a items");

				AccountInfo[playerid][E_MASTERS_STREETCREDITS] -= 150;
				AccountInfo[playerid][E_MASTERS_VIP] = 3;
				AccountInfo[playerid][E_MASTERS_VIPTIMER] = gettime() + (7 * 86400);
				SendServerMessage(playerid, "You has purchase ultimate vip level 7 days for 150 street credits.");
			}
		}
	}
	return 1;
}

Dialog:DialogChangePhone(playerid, response, listitem, inputtext[])
{
	if(response)
	{
		if(isnull(inputtext) || strlen(inputtext) < 1 || strlen(inputtext) > 8)
			return Dialog_Show(playerid, DialogChangePhone, DIALOG_STYLE_INPUT, "Change Phone Number:", "Insert a new phone number below.\n{33AA33}Info:{ffffff} Required in format of number only Ex: 911922", "Select", "Close");

		for(new i = 0; i < strlen(inputtext); i++)
		{
			if(inputtext[i] < '0' || inputtext[i] > '9')
				return SendErrorMessage(playerid, "Input must contain numbers only.");
		}

		AccountInfo[playerid][E_MASTERS_STREETCREDITS] -= 50;
		PlayerInfo[playerid][E_CHARACTER_PHONE] = strval(inputtext);
		SendServerMessage(playerid, "You has change phone number to %d for 50 street credits.", strval(inputtext));

	}
	return 1;
}

Dialog:DialogChangeMask(playerid, response, listitem, inputtext[])
{
	if(response)
	{
		if(isnull(inputtext) || strlen(inputtext) < 1 || strlen(inputtext) > 8)
			return Dialog_Show(playerid, DialogChangeMask, DIALOG_STYLE_INPUT, "Change Mask ID:", "Insert a new mask id below.\n{33AA33}Info:{ffffff} Required in format of number only Ex: 911922", "Select", "Close");

		for(new i = 0; i < strlen(inputtext); i++)
		{
			if(inputtext[i] < '0' || inputtext[i] > '9')
				return SendErrorMessage(playerid, "Input must contain numbers only.");
		}

		PlayerInfo[playerid][E_CHARACTER_MASKID] = strval(inputtext);
		AccountInfo[playerid][E_MASTERS_STREETCREDITS] -= 70;
		SendServerMessage(playerid, "You has change mask id to %d for 70 street credits.", strval(inputtext));

	}
	return 1;
}

Dialog:DialogChangeName(playerid, response, listitem, inputtext[])
{
	if(response)
	{
		if(strlen(inputtext) > MAX_PLAYER_NAME + 1 || strlen(inputtext) < 3)
		{
			Dialog_Show(playerid, DialogChangeName, DIALOG_STYLE_INPUT, "Change Character Name:", "Insert a full name of your character.\n{33AA33}Info:{ffffff} Required in format of Firstname_Lastname", "Confirm", "");	
			SendErrorMessage(playerid, "Your characters name must be at least 3 characters and no more than %i characters.", MAX_PLAYER_NAME);
			return 1;
		}
		if(!IsValidRoleplayName(inputtext))
		{
			Dialog_Show(playerid, DialogChangeName, DIALOG_STYLE_INPUT, "Change Character Name:", "Insert a full name of your character.\n{33AA33}Info:{ffffff} Required in format of Firstname_Lastname", "Confirm", "");	
			SendErrorMessage(playerid, "Please follow the Firstname_Lastname format to make your character."); 
			return 1;
		}
		
		foreach (new i : Player)
		{
			if(!strcmp(inputtext, ReturnName(i, playerid)))
			{
				Dialog_Show(playerid, DialogChangeName, DIALOG_STYLE_INPUT, "Change Character Name:", "Insert a full name of your character.\n{33AA33}Info:{ffffff} Required in format of Firstname_Lastname", "Confirm", "");	
				SendErrorMessage(playerid, "That character already exists. Please try again."); 
				return 1;
			}
		}
		
		new
			threadSearch[128];
		
		format(playerCharactersName[playerid], 128, "%s", inputtext); 
		
		mysql_format(ourConnection, threadSearch, sizeof(threadSearch), "SELECT char_dbid FROM characters WHERE char_name = '%e'", inputtext);
		mysql_pquery(ourConnection, threadSearch, "Query_ChangeCharacter", "i", playerid);
	}
	return 1;
}

Dialog:DialogCompensation(playerid, response, listitem, inputtext[])
{
	if(response)
	{
		for (new i = 0; i < MAX_COMPENSATION; i++) if(CompetationInfo[i][E_COMPETATION_EXISTS])
		{
			if (strcmp(CompetationInfo[i][E_COMPETATION_CODE], inputtext, true) == 0)
			{
				if (gettime() > CompetationInfo[i][E_COMPETATION_EXPIRED])
				{
					new query[256];
					mysql_format(ourConnection, query, sizeof(query), "DELETE FROM compensation_codes WHERE code = '%s'", CompetationInfo[i][E_COMPETATION_CODE]);
					mysql_tquery(ourConnection, query);

					mysql_format(ourConnection, query, sizeof(query), "DELETE FROM compensation_claims WHERE code = '%s'", CompetationInfo[i][E_COMPETATION_CODE]);
					mysql_tquery(ourConnection, query);

					CompetationInfo[i][E_COMPETATION_EXISTS] = false;
					
					return SendErrorMessage(playerid, "This compensation code has expired.");
				}

				if (CompetationInfo[i][E_COMPETATION_USED] >= CompetationInfo[i][E_COMPETATION_PLAYERS])
				{
					new query[256];
					mysql_format(ourConnection, query, sizeof(query), "DELETE FROM compensation_codes WHERE code = '%s'", CompetationInfo[i][E_COMPETATION_CODE]);
					mysql_tquery(ourConnection, query);

					mysql_format(ourConnection, query, sizeof(query), "DELETE FROM compensation_claims WHERE code = '%s'", CompetationInfo[i][E_COMPETATION_CODE]);
					mysql_tquery(ourConnection, query);

					CompetationInfo[i][E_COMPETATION_EXISTS] = false;

					return SendErrorMessage(playerid, "This compensation code has reached its limit.");
				}

				new query[256];
				mysql_format(ourConnection, query, sizeof(query), "SELECT * FROM compensation_claims WHERE player_id = %d AND code = '%s'", PlayerInfo[playerid][E_CHARACTER_DBID], inputtext);
				mysql_pquery(ourConnection, query, "CompensationCallback", "ii", playerid, i);
			}
		}
		else
		{
			SendErrorMessage(playerid, "Invalid or not available compensation code at this time.");
		}
	}
	return 1;
}

Dialog:DialogReport(playerid, response, listitem, inputtext[])
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
	return 1;
}

Dialog:DialogInterior(playerid, response, listitem, inputtext[])
{
	if (response)
	{
		SetPlayerInteriorEx(playerid, g_arrInteriorData[listitem][E_INT_ID]);
		SetPlayerPosEx(playerid, g_arrInteriorData[listitem][E_INT_X], g_arrInteriorData[listitem][E_INT_Y], g_arrInteriorData[listitem][E_INT_Z]);
	}
	return 1;
}

Dialog:DialogFactionLocker(playerid, response, listitem, inputtext[])
{
	if(response)
	{
		switch(listitem)
		{
			case 0:
			{
				if(!IsPlayerFaction(playerid))
					return SendErrorMessage(playerid, "You aren't in any faction.");
					
				if(ReturnFactionType(playerid) != FACTION_TYPE_POLICE && ReturnFactionType(playerid) != FACTION_TYPE_MEDICAL)
					return SendErrorMessage(playerid, "You can't use this command."); 

				if(!PlayerInfo[playerid][E_CHARACTER_FACSKIN])
					return SendErrorMessage(playerid, "You don't have faction skin.");

				if(ReturnFactionType(playerid) == FACTION_TYPE_POLICE)
				{
					if(!PlayerInfo[playerid][E_CHARACTER_POLICEDUTY])
					{
						SendPoliceMessage(COLOR_COP, "** HQ: %s %s is now On Duty! **", IsPlayerFactionRank(playerid), ReturnName(playerid));
						SendTipMessage(playerid, "You can use '/tazer' use an electrical current to temporarily incapacitate a person.");
						SendTipMessage(playerid, "You can use '/tackle' The player you hit will have a message flashed to them indicating that a tackle has been attempted..");

						SetPlayerHealthEx(playerid, 100);
						SetPlayerArmourEx(playerid, 100);
						
						PlayerInfo[playerid][E_CHARACTER_POLICEDUTY] = true; 

						SetPlayerSkin(playerid, PlayerInfo[playerid][E_CHARACTER_FACSKIN]); 
					}
					else
					{
						PlayerInfo[playerid][E_CHARACTER_POLICEDUTY] = false;
	
						ResetPlayerWeaponEx(playerid); 
						
						SendPoliceMessage(COLOR_COP, "** HQ: %s %s is now Off Duty! **", IsPlayerFactionRank(playerid), ReturnName(playerid)); 
						
						SetPlayerArmourEx(playerid, 0);
						SetPlayerHealthEx(playerid, 100); 
						
						SetPlayerSkin(playerid, PlayerInfo[playerid][E_CHARACTER_LASTSKIN]); 
					}
				}
				else if(ReturnFactionType(playerid) == FACTION_TYPE_MEDICAL)
				{
					if(!PlayerInfo[playerid][E_CHARACTER_MEDICDUTY])
					{
						SendMedicMessage(COLOR_MEDIC, "** HQ: %s %s is now On Duty! **", IsPlayerFactionRank(playerid), ReturnName(playerid));
						
						SetPlayerHealthEx(playerid, 100);
						SetPlayerArmourEx(playerid, 100);

						PlayerInfo[playerid][E_CHARACTER_MEDICDUTY] = true; 

						SetPlayerSkin(playerid, PlayerInfo[playerid][E_CHARACTER_FACSKIN]); 
					}
					else
					{
						PlayerInfo[playerid][E_CHARACTER_MEDICDUTY] = false;
	
						ResetPlayerWeaponEx(playerid); 
						
						SendPoliceMessage(COLOR_COP, "** HQ: %s %s is now Off Duty! **", IsPlayerFactionRank(playerid), ReturnName(playerid)); 
						
						SetPlayerArmourEx(playerid, 0);
						SetPlayerHealthEx(playerid, 100); 
						
						SetPlayerSkin(playerid, PlayerInfo[playerid][E_CHARACTER_LASTSKIN]); 
						
						if(Inventory_Count(playerid, "Bandage"))
						{
							Inventory_Set(playerid, "Bandage", 17738, 0);
						}
					}
				}
			}
			case 1:
			{
				if(ReturnFactionType(playerid) == FACTION_TYPE_POLICE)
				{
					if(PlayerInfo[playerid][E_CHARACTER_GENDER] == 1)
					{
						ShowSelectionModel(playerid, SELECT_POLICEMALESKIN);
					}
					else if(PlayerInfo[playerid][E_CHARACTER_GENDER] == 2)
					{
						ShowSelectionModel(playerid, SELECT_POLICEFEMALESKIN);
					}
				}
				
				else if(ReturnFactionType(playerid) == FACTION_TYPE_MEDICAL)
				{
					if(PlayerInfo[playerid][E_CHARACTER_GENDER] == 1)
					{
						ShowSelectionModel(playerid, SELECT_MEDICMALESKIN);
					}
					else if(PlayerInfo[playerid][E_CHARACTER_GENDER] == 2)
					{
						ShowSelectionModel(playerid, SELECT_MEDICFEMALESKIN);
					}
				}
			}
			case 2:
			{
				if(ReturnFactionType(playerid) == FACTION_TYPE_POLICE)
				{
					if(!Inventory_Count(playerid, "Desert Eagle"))
					{
						Inventory_Set(playerid, "Desert Eagle", 348, 1);
					}
					Inventory_Set(playerid, "Regular Ammo", 2040, 50);
				}
				if(ReturnFactionType(playerid) == FACTION_TYPE_MEDICAL)
				{
					Inventory_Set(playerid, "Bandage", 17738, 10);
				}
			}
			case 3:
			{
				if(ReturnFactionType(playerid) == FACTION_TYPE_POLICE)
				{
					if(!Inventory_Count(playerid, "Shotgun"))
					{
						Inventory_Set(playerid, "Shotgun", 348, 1);
					}
					Inventory_Set(playerid, "Regular Ammo", 2040, 50);
				}
				if(ReturnFactionType(playerid) == FACTION_TYPE_MEDICAL)
				{
					Inventory_Set(playerid, "Extinguisher", 366, 1);
				}
			}
			case 4:
			{
				if(ReturnFactionType(playerid) == FACTION_TYPE_POLICE)
				{
					if(!Inventory_Count(playerid, "Regular Ammo"))
					{
						Inventory_Set(playerid, "Regular Ammo", 2040, 50);
					}
					else
					{
						Inventory_Set(playerid, "Regular Ammo", 2040, 0);
					}
				}
				if(ReturnFactionType(playerid) == FACTION_TYPE_MEDICAL)
				{
					Inventory_Set(playerid, "Extinguisher", 366, 1);
				}
			}
			case 5:
			{
				if(ReturnFactionType(playerid) == FACTION_TYPE_POLICE)
				{
					if(!Inventory_Count(playerid, "Surplus Ammo"))
					{
						Inventory_Set(playerid, "Surplus Ammo", 2040, 50);
					}
					else
					{
						Inventory_Set(playerid, "Surplus Ammo", 2040, 0);
					}
				}
				if(ReturnFactionType(playerid) == FACTION_TYPE_MEDICAL)
				{
					Inventory_Set(playerid, "Extinguisher", 366, 1);
				}
			}
			case 6:
			{
				if(ReturnFactionType(playerid) == FACTION_TYPE_POLICE)
				{
					if(!Inventory_Count(playerid, "JHP Ammo"))
					{
						Inventory_Set(playerid, "JHP Ammo", 2040, 50);
					}
					else
					{
						Inventory_Set(playerid, "JHP Ammo", 2040, 0);
					}
				}
				if(ReturnFactionType(playerid) == FACTION_TYPE_MEDICAL)
				{
					Inventory_Set(playerid, "Extinguisher", 366, 1);
				}
			}
			case 7:
			{
				if(ReturnFactionType(playerid) == FACTION_TYPE_POLICE)
				{
					if(!Inventory_Count(playerid, "Rubber Ammo"))
					{
						Inventory_Set(playerid, "Rubber Ammo", 2040, 50);
					}
					else
					{
						Inventory_Set(playerid, "Rubber Ammo", 2040, 0);
					}
				}
				if(ReturnFactionType(playerid) == FACTION_TYPE_MEDICAL)
				{
					Inventory_Set(playerid, "Extinguisher", 366, 1);
				}
			}
		}
	}
	return 1;
}

Dialog:DialogMedicVehicles(playerid, response, listitem, inputtext[])
{
	if (response)
	{
		new index = listitem + 27; // Menyesuaikan indeks agar sesuai dengan Medical (27-37)

		if (FactionVehicle[index][E_FACVEHICLE_SPAWNED])
			return SendErrorMessage(playerid, "This vehicle is already spawned and not available.");

		new modelid = FactionVehicle[index][E_FACVEHICLE_MODEL];
		new color1 = FactionVehicle[index][E_FACVEHICLE_COLOR1];
		new color2 = FactionVehicle[index][E_FACVEHICLE_COLOR2];
		new Float:x = FactionVehicle[index][E_FACVEHICLE_POSX];
		new Float:y = FactionVehicle[index][E_FACVEHICLE_POSY];
		new Float:z = FactionVehicle[index][E_FACVEHICLE_POSZ];
		new Float:rot = FactionVehicle[index][E_FACVEHICLE_ROT];

		FactionVehicle[index][E_FACVEHICLE_LASTUSED] = gettime();

		FactionVehicle[index][E_FACVEHICLE_VEH] = AddStaticVehicleEx(modelid, x, y, z, rot, color1, color2, 1800, 1);
		VehicleInfo[FactionVehicle[index][E_FACVEHICLE_VEH]][E_VEHICLE_HEALTH] = 2000.0;
		VehicleInfo[FactionVehicle[index][E_FACVEHICLE_VEH]][E_VEHICLE_FUEL] = 100;
		VehicleInfo[FactionVehicle[index][E_FACVEHICLE_VEH]][E_VEHICLE_MILES] = 0;

		SetVehicleHealth(FactionVehicle[index][E_FACVEHICLE_VEH], VehicleInfo[FactionVehicle[index][E_FACVEHICLE_VEH]][E_VEHICLE_HEALTH]);
		SetVehicleNumberPlate(FactionVehicle[index][E_FACVEHICLE_VEH], FactionVehicle[index][E_FACVEHICLE_PLATES]);

		FactionVehicle[index][E_FACVEHICLE_SPAWNED] = true;

		SendInfoMessage(playerid, "[FACTION]  Faction Vehicle spawned successfully.");
	}
	return 1;
}

Dialog:DialogPoliceVehicles(playerid, response, listitem, inputtext[])
{
	if(response)
	{
		if(FactionVehicle[listitem][E_FACVEHICLE_SPAWNED])
			return SendErrorMessage(playerid, "This vehicle is already spawned and not available.");

		new modelid = FactionVehicle[listitem][E_FACVEHICLE_MODEL];
		new color1 = FactionVehicle[listitem][E_FACVEHICLE_COLOR1];
		new color2 = FactionVehicle[listitem][E_FACVEHICLE_COLOR2];
		new Float:x = FactionVehicle[listitem][E_FACVEHICLE_POSX];
		new Float:y = FactionVehicle[listitem][E_FACVEHICLE_POSY];
		new Float:z = FactionVehicle[listitem][E_FACVEHICLE_POSZ];
		new Float:rot = FactionVehicle[listitem][E_FACVEHICLE_ROT];

		FactionVehicle[listitem][E_FACVEHICLE_LASTUSED] = gettime();

		FactionVehicle[listitem][E_FACVEHICLE_VEH] = AddStaticVehicleEx(modelid, x, y, z, rot, color1, color2, 1800, 1);
		VehicleInfo[FactionVehicle[listitem][E_FACVEHICLE_VEH]][E_VEHICLE_HEALTH] = 2000.0;
		VehicleInfo[FactionVehicle[listitem][E_FACVEHICLE_VEH]][E_VEHICLE_FUEL] = 100;
		VehicleInfo[FactionVehicle[listitem][E_FACVEHICLE_VEH]][E_VEHICLE_MILES] = 0; 
		SetVehicleHealth(FactionVehicle[listitem][E_FACVEHICLE_VEH], VehicleInfo[FactionVehicle[listitem][E_FACVEHICLE_VEH]][E_VEHICLE_HEALTH]);
		SetVehicleNumberPlate(FactionVehicle[listitem][E_FACVEHICLE_VEH], FactionVehicle[FactionVehicle[listitem][E_FACVEHICLE_VEH]][E_FACVEHICLE_PLATES]);
		FactionVehicle[listitem][E_FACVEHICLE_SPAWNED] = true;

		SendInfoMessage(playerid, "[FACTION]  Faction Vehicles spawned successfully.");
	}
	return 1;
}

Dialog:DialogTreatment(playerid, response, listitem, inputtext[])
{
	if(response)
	{
		new targetid = PlayerInfo[playerid][E_CHARACTER_TARGETID];

		if(!IsPlayerNearPlayer(playerid, targetid, 5.0) || targetid == INVALID_PLAYER_ID)
			return SendErrorMessage(playerid, "You aren't near any player.");

		if(listitem == 0)
		{
			ShowPlayerCondition(playerid, targetid);
		}
		if(listitem == 1)
		{
			if(!PlayerInfo[targetid][E_CHARACTER_INJURED])
				return SendErrorMessage(playerid, "That player is not in injured condition!");

			PlayerInfo[targetid][E_CHARACTER_INJURED] = 0;
			SetPlayerTeam(targetid, PLAYER_STATE_ALIVE);
			SetPlayerHealthEx(targetid, 100.0);

			SendInfoMessage(playerid, "[TREATMENT] You have been reviving %s.", ReturnName(targetid));
			SendInfoMessage(targetid, "[TREATMENT] You have been revived by %s.", ReturnName(playerid));
		}
		if(listitem == 2)
		{
			new Float:hp;
			GetPlayerHealth(targetid, hp);
			if(hp >= 100.0)
				return SendErrorMessage(playerid, "That player already have Max Health!");

			SetPlayerHealthEx(targetid, 100.0);
			SendInfoMessage(playerid, "[TREATMENT] You have healing %s.", ReturnName(targetid));
			SendInfoMessage(targetid, "[TREATMENT] You have been healed by %s.", ReturnName(playerid));
		}
		if(listitem == 3)
		{
			if(PlayerInfo[playerid][E_CHARACTER_LOADING] == true)
				return SendErrorMessage(playerid, "You can't use this right now."); 

			new Float:x, Float:y, Float:z;
			GetPlayerPos(targetid, x, y, z);

			TogglePlayerControllable(playerid, false);
			TogglePlayerControllable(targetid, false);

			PlayerInfo[playerid][E_CHARACTER_LOADINGDISPLAY] = Create3DTextLabel("Loading operate process\n(( |------ ))", COLOR_3DTEXT, x, y, z, 25.0, 0, 1);
			PlayerInfo[playerid][E_CHARACTER_LOADINGCOUNT] = 1;

			PlayerInfo[playerid][E_CHARACTER_LOADING] = true; 
			PlayerInfo[playerid][E_CHARACTER_LOADINGTIMER] = SetTimerEx("Treatments", 5000, true, "ii", playerid, targetid);

			SendInfoMessage(playerid, "[TREATMENT] You need waiting for a minutes to operate %s.", ReturnName(targetid));
		}
	}
	return 1;
}

Dialog:DialogMDCName(playerid, response, listitem, inputtext[])
{
	if (ReturnFactionType(playerid) != FACTION_TYPE_POLICE || !IsPoliceVehicle(GetPlayerVehicleID(playerid)))
		return 0;

	if (response)
	{
		if(strlen(inputtext) < 3 || strlen(inputtext) > 32)
			return Dialog_Show(playerid, DialogMDCName, DIALOG_STYLE_INPUT, "Place Charges:", "Please enter the name of the player:", "Search", "Back"); 
			
		if(!ReturnDBIDFromName(inputtext))
			return Dialog_Show(playerid, DialogMDCName, DIALOG_STYLE_INPUT, "Place Charges:", "Invalid user specified.\nPlease enter the name of the player:", "Search", "Back"); 
		
		format(PlayerInfo[playerid][E_CHARACTER_MDCPLAYER], 32, "%s", inputtext); 

		new str[128];
		format(str, sizeof(str), "Please enter the description of the crime committed by %s:", ReturnName(PlayerInfo[playerid][E_CHARACTER_MDCPLAYER], playerid));
		Dialog_Show(playerid, DialogMDCPlace, DIALOG_STYLE_INPUT, "Given Charge:", str, "Search", "Back");
	}
	return 1;
}

Dialog:DialogMDCPlace(playerid, response, listitem, inputtext[])
{
	if (ReturnFactionType(playerid) != FACTION_TYPE_POLICE || !IsPoliceVehicle(GetPlayerVehicleID(playerid)))
		return 0;

	if (response)
	{
		if (isnull(inputtext))
		{
			new str[128];
			format(str, sizeof(str), "Please enter the name of the player:");
			return Dialog_Show(playerid, DialogMDCPlace, DIALOG_STYLE_INPUT, "Given Charge:", str, "Enter", "Back");
		}
			
		AddWanted(PlayerInfo[playerid][E_CHARACTER_MDCPLAYER], inputtext);

		SendPoliceMessage(COLOR_COP, "** HQ: %s has placed a charge on %s for \"%s\".", ReturnName(playerid, 0), PlayerInfo[playerid][E_CHARACTER_MDCPLAYER], inputtext);
	}
	return 1;
}
Dialog:DialogMDCPlate(playerid, response, listitem, inputtext[])
{
	if(response)
	{
		new query[128];
		if(strlen(inputtext) > 6 || strlen(inputtext) < 3)
			return Dialog_Show(playerid, DialogMDCPlate, DIALOG_STYLE_INPUT, "Plates Search:", "Please enter the vehicle plates:", "Search", "Back"); 
		
		format(PlayerInfo[playerid][E_CHARACTER_MDCPLAYER], 32, "%s", inputtext); 

		mysql_format(ourConnection, query, sizeof(query), "SELECT VehiclePlates FROM vehicles WHERE VehiclePlates LIKE '%%%e%%' LIMIT 5", PlayerInfo[playerid][E_CHARACTER_MDCPLAYER]); 
		mysql_pquery(ourConnection, query, "OnMDCPlate", "i", playerid); 
	}
	return 1;
}

Dialog:DialogMDCPlateList(playerid, response, listitem, inputtext[])
{
	if(response)
	{
		new query[220];
		mysql_format(ourConnection, query, sizeof(query), "SELECT VehicleOwnerDBID, VehicleModel, VehicleImpounded FROM vehicles WHERE VehiclePlates = '%e'", PlayerPlateSaver[playerid][listitem]);
		mysql_pquery(ourConnection, query, "OnPlateSelect", "ii", playerid, listitem); 
	}
	return 1;
}

Dialog:DialogMDCView(playerid, response, listitem, inputtext[])
{
	if (ReturnFactionType(playerid) != FACTION_TYPE_POLICE || !IsPoliceVehicle(GetPlayerVehicleID(playerid)))
		return 0;

	if (response)
	{
		if (isnull(inputtext) || strlen(inputtext) > 24)
			return Dialog_Show(playerid, DialogMDCView, DIALOG_STYLE_INPUT, "Name Search:", "Please enter the name of the player:", "Search", "Back");

		if (IsNumeric(inputtext) && IsPlayerConnected(strval(inputtext))) 
		{
			ViewCharges(playerid, ReturnName(strval(inputtext), playerid));
		}
		else if (!IsNumeric(inputtext)) 
		{
			ViewCharges(playerid, inputtext);
		}
		else 
		{
			Dialog_Show(playerid, DialogMDCView, DIALOG_STYLE_INPUT, "Name Search:", "Invalid user specified.\nPlease enter the name of the player:", "Search", "Back");
		}
	}
	return 1;
}

Dialog:DialogCharge(playerid, response, listitem, inputtext[])
{
	if(response)
	{
		new str[256];
		new Cents = floatround(PenalInfo[listitem][E_PENALCODES_CHARGES] * 100, floatround_round);

		PlayerInfo[playerid][E_CHARACTER_MDCCHARGE] = Cents;
		PlayerInfo[playerid][E_CHARACTER_MDCTIME] = PenalInfo[listitem][E_PENALCODES_JAILTIME];
		format(PlayerInfo[playerid][E_CHARACTER_MDCPLAYER], 32, "%s", PlayerInfo[PlayerInfo[playerid][E_CHARACTER_MDCSELECT]][E_CHARACTER_NAME]);
		format(PlayerInfo[playerid][E_CHARACTER_MDCDESC], 128, "%s", PenalInfo[listitem][E_PENALCODES_TYPE]);

		format(str, sizeof(str), "Suspect: %s\nDescription: (%s) %.150s\nCharges: {33AA33}$%s{ffffff}\nJail Times: %d Month (Minutes)", PlayerInfo[PlayerInfo[playerid][E_CHARACTER_MDCSELECT]][E_CHARACTER_NAME], PenalInfo[listitem][E_PENALCODES_TYPE], PenalInfo[listitem][E_PENALCODES_NAME], FormatMoney(Cents), PenalInfo[listitem][E_PENALCODES_JAILTIME]);
		Dialog_Show(playerid, DialogChargeSelect, DIALOG_STYLE_MSGBOX, "State Penal Code (Arrest Offesenses):", str, "Enter", "Cancel");
	}
	return 1;
}

Dialog:DialogChargeSelect(playerid, response, listitem, inputtext[])
{
	if(response)
	{
		new playerb = PlayerInfo[playerid][E_CHARACTER_MDCSELECT];
		SetPlayerInPrison(playerb);
		SaveCharacter(playerb);
		ResetVarInventory(playerid);
		PlayerInfo[playerb][E_CHARACTER_HANDCUFF] = false;
		SetPlayerSpecialAction(playerb, SPECIAL_ACTION_NONE);

		GiveMoney(playerb, -PlayerInfo[playerid][E_CHARACTER_MDCCHARGE]);
		AddWanted(PlayerInfo[playerid][E_CHARACTER_MDCPLAYER], PlayerInfo[playerid][E_CHARACTER_MDCDESC]);
	}
	return 1;
}

Dialog:DialogClothShow(playerid, response, listitem, inputtext[])
{
	if(response)
	{
		if(pToys[playerid][listitem][E_TOY_MODEL] == 0)
			return SendErrorMessage(playerid, "There is no accessory on selected index!");

		new string[256], str[64];
		toySelect[playerid] = listitem;
		if(pToys[playerid][listitem][E_TOY_TYPE] == ACC_HAIRCUT)
			format(string, sizeof(string), "Place %s", (!toyToggle[playerid][toySelect[playerid]]) ? ("On") : ("Off"));
		else
			format(string, sizeof(string), "Place %s\nChange Bone\nChange Placement\nRemove", (!toyToggle[playerid][toySelect[playerid]]) ? ("On") : ("Off"));

		format(str, sizeof(str), "Accessories %d:", listitem);
		Dialog_Show(playerid, DialogClothEdit, DIALOG_STYLE_LIST, str, string, "Select", "Cancel");
	}
	return 1;
}

Dialog:DialogClothEdit(playerid, response, listitem, inputtext[])
{
	if(response)
	{
		switch(listitem)
		{
			case 0: // toggle attach
			{
				if(!toyToggle[playerid][toySelect[playerid]])
				{
					ShowBoxMessage(playerid, "Accessories attached", 5);

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
					ShowBoxMessage(playerid, "Accessories dettached", 5);

					toyToggle[playerid][toySelect[playerid]] = false;
				}
				SavePlayerToys(playerid);
			}
			case 1: // change bone
			{
				Dialog_Show(playerid, DialogClothBone, DIALOG_STYLE_LIST, "Bone Selection:", "Spine\nHead\nLeft upper arm\nRight upper arm\nLeft hand\nRight hand\nLeft thigh\nRight thigh\nLeft foot\nRight foot\nRight calf\nLeft calf\nLeft forearm\nRight forearm\nLeft shoulder\nRight shoulder\nNeck\nJaw", "Choose", "Cancel");
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
				ShowBoxMessage(playerid, "Accessories delete!", 5);
				SavePlayerToys(playerid);
			}
		}
	}
	return 1;
}

Dialog:DialogClothBone(playerid, response, listitem, inputtext[])
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
		SendInfoMessage(playerid, "[CLOTHING] Accessories bone position now is %s", Bone_Name[listitem + 1]);
	}
	return 1;
}

Dialog:DialogGym(playerid, response, listitem, inputtext[])
{
	if(response)
	{
		new businessid = IsPlayerInBusiness(playerid);
		switch(listitem)
		{
			case 0:
			{
				SetPlayerFightingStyle(playerid, 5);
				PlayerInfo[playerid][E_CHARACTER_FIGHTSTYLE] = 5;
				SendPropertyMessage(playerid, "[BUSINESS] You learn a fightstyle boxing for $150.00.");
				new Cents = floatround(150 * 100, floatround_round);

				GiveMoney(playerid, -Cents);
				BusinessInfo[businessid][E_BUSINESS_CASH] += Cents;
			}	
			case 1:
			{
				SetPlayerFightingStyle(playerid, 7);
				PlayerInfo[playerid][E_CHARACTER_FIGHTSTYLE] = 7;
				SendPropertyMessage(playerid, "[BUSINESS] You learn a fightstyle KneeHead for $200.00.");
				new Cents = floatround(200 * 100, floatround_round);

				GiveMoney(playerid, -Cents);
				BusinessInfo[businessid][E_BUSINESS_CASH] += Cents;
			}
			case 2:
			{
				SetPlayerFightingStyle(playerid, 15);
				PlayerInfo[playerid][E_CHARACTER_FIGHTSTYLE] = 15;
				SendPropertyMessage(playerid, "[BUSINESS] You learn a fightstyle GrabKick for $300.00.");
				new Cents = floatround(300 * 100, floatround_round);

				GiveMoney(playerid, -Cents);
				BusinessInfo[businessid][E_BUSINESS_CASH] += Cents;
			}
			case 3:
			{
				SetPlayerFightingStyle(playerid, 4);
				PlayerInfo[playerid][E_CHARACTER_FIGHTSTYLE] = 4;
				SendPropertyMessage(playerid, "[BUSINESS] You reset a fightstyle for $100.00.");
				new Cents = floatround(100 * 100, floatround_round);

				GiveMoney(playerid, -Cents);
				BusinessInfo[businessid][E_BUSINESS_CASH] += Cents;
			}
			case 4:
			{
				if(BusinessInfo[businessid][E_BUSINESS_STOCK] < 1)
					return SendErrorMessage(playerid, "This business is out of stock"); 

				if(Inventory_Count(playerid, "Sprunk") >= 5)	
					return SendErrorMessage(playerid, "You may only hold up to 5 sprunk.");
			
				if(2 > PlayerInfo[playerid][E_CHARACTER_MONEY])
					return SendErrorMessage(playerid, "You can't afford a sprunk.");
			
				SendPropertyMessage(playerid, "[BUSINESS] You bought a sprunk for $2.");

				new Cents = floatround(2 * 100, floatround_round);
				BusinessInfo[businessid][E_BUSINESS_CASH] += Cents;
				BusinessInfo[businessid][E_BUSINESS_STOCK]--;
				GiveMoney(playerid, -Cents);
				Inventory_Add(playerid, "Sprunk", 2601, 1);

				ApplyAnimation(playerid, "MISC", "GRAB_R", 4.1, 0, 0, 0, 0, 0, 0);
			}
		}
	}
	return 1;
}

Dialog:DialogBuyCloth(playerid, response, listitem, inputtext[])
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
	return 1;
}

Dialog:DialogInvOption(playerid, response, listitem, inputtext[])
{
	if(response)
	{
		new
			itemid = PlayerInfo[playerid][E_CHARACTER_LISTITEM],
			string[128],
			str[128];

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
				SendInventoryMessage(playerid, "You have stored items in your inventory.");
			}
			case 2:
			{
				if(PlayerInfo[playerid][E_CHARACTER_EQUIPITEMS] > INVENTORY_NONE)
					return SendErrorMessage(playerid, "You must store your items in inventory first.");

				if(!strcmp(string, "Cellphone"))
					return SendErrorMessage(playerid, "You can't do that on this item!");

				if(!strcmp(string, "Radio"))
					return SendErrorMessage(playerid, "You can't do that on this item!");

				if(!strcmp(string, "Mask"))
					return SendErrorMessage(playerid, "You can't do that on this item!");

				PlayerInfo[playerid][E_CHARACTER_LISTITEM] = itemid;
				Dialog_Show(playerid, DialogInvGive, DIALOG_STYLE_INPUT, "Give Item:", "Please enter the name or the ID of the player:", "Submit", "Cancel");
			}
			case 3:
			{
				if (IsPlayerInAnyVehicle(playerid))
					return SendErrorMessage(playerid, "You can't drop items right now.");

				if(!strcmp(string, "Cellphone"))
					return SendErrorMessage(playerid, "You can't do that on this item!");

				if(!strcmp(string, "Radio"))
					return SendErrorMessage(playerid, "You can't do that on this item!");

				if(!strcmp(string, "Mask"))
					return SendErrorMessage(playerid, "You can't do that on this item!");

				if(!strcmp(string, "Boombox"))
				{
					DropPlayerItem(playerid, itemid, 1, E_DROPPED_TYPE_BOOMBOX);		
				}
				else if (InventoryInfo[playerid][itemid][E_INVENTORY_QUANTITY] == 1)
				{
					DropPlayerItem(playerid, itemid);						
				}
				else
					format(str, sizeof(str), "Item: %s - Quantity: %d\n\nPlease specify how much of this item you wish to drop:", string, InventoryInfo[playerid][itemid][E_INVENTORY_QUANTITY]),
					Dialog_Show(playerid, DialogDropItem, DIALOG_STYLE_INPUT, "Drop Item:", str, "Drop", "Cancel");
			}
		}
	}
	return 1;
}

Dialog:DialogDropItem(playerid, response, listitem, inputtext[])
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
			{
				format(str, sizeof(str), "Drop Item", "Item: %s - Quantity: %d\n\nPlease specify how much of this item you wish to drop:", string, InventoryInfo[playerid][itemid][E_INVENTORY_QUANTITY]),
				Dialog_Show(playerid, DialogDropItem, DIALOG_STYLE_INPUT, "Drop Item", str, "Drop", "Cancel");
				return 1;
			}

			if (strval(inputtext) < 1 || strval(inputtext) > InventoryInfo[playerid][itemid][E_INVENTORY_QUANTITY])
			{
				format(str, sizeof(str), "ERROR: Insufficient amount specified.\n\nItem: %s - Quantity: %d\n\nPlease specify how much of this item you wish to drop:", string, InventoryInfo[playerid][itemid][E_INVENTORY_QUANTITY]),
				Dialog_Show(playerid, DialogDropItem, DIALOG_STYLE_INPUT, "Drop Item:", str, "Drop", "Cancel");
				return 1;
			}
			
			DropPlayerItem(playerid, itemid, strval(inputtext));
		}
	}
	return 1;
}

Dialog:DialogInvGive(playerid, response, listitem, inputtext[])
{
	if (response)
	{
		static
			userid = -1,
			itemid = -1,
			string[32];

		if (sscanf(inputtext, "u", userid))
			return Dialog_Show(playerid, DialogInvGive, DIALOG_STYLE_INPUT, "Give Item:", "Please enter the name or the ID of the player:", "Submit", "Cancel");

		if (userid == INVALID_PLAYER_ID)
			return Dialog_Show(playerid, DialogInvGive, DIALOG_STYLE_INPUT, "Give Item:", "ERROR: Invalid player specified.\n\nPlease enter the name or the ID of the player:", "Submit", "Cancel");

		if (!IsPlayerNearPlayer(playerid, userid, 6.0))
			return Dialog_Show(playerid, DialogInvGive, DIALOG_STYLE_INPUT, "Give Item:", "ERROR: You are not near that player.\n\nPlease enter the name or the ID of the player:", "Submit", "Cancel");

		if (userid == playerid)
			return Dialog_Show(playerid, DialogInvGive, DIALOG_STYLE_INPUT, "Give Item:", "ERROR: You can't give items to yourself.\n\nPlease enter the name or the ID of the player:", "Submit", "Cancel");

		itemid = PlayerInfo[playerid][E_CHARACTER_LISTITEM];

		if (itemid == -1)
			return 0;

		strunpack(string, InventoryInfo[playerid][itemid][E_INVENTORY_ITEM]);

		if (InventoryInfo[playerid][itemid][E_INVENTORY_QUANTITY] == 1)
		{
			new id = Inventory_Add(userid, string, InventoryInfo[playerid][itemid][E_INVENTORY_MODEL]);

			if (id == -1)
				return SendErrorMessage(playerid, "That player doesn't have anymore inventory slots.");

			SendNearbyMessage(playerid, 30.0, COLOR_EMOTE, "* %s takes out a \"%s\" and gives it to %s.", ReturnName(playerid, 0), string, ReturnName(userid, 0));
			SendServerMessage(userid, "%s has given you %s (added to inventory).", ReturnName(playerid, 0), string);

			Inventory_Remove(playerid, string);
		}
		else
		{
			new str[152];
			format(str, sizeof(str), "Item: %s (Amount: %d)\n\nPlease enter the amount of this item you wish to give %s:", string, InventoryInfo[playerid][itemid][E_INVENTORY_QUANTITY], ReturnName(userid, playerid));
			Dialog_Show(playerid, DialogInvGiveAmount, DIALOG_STYLE_INPUT, "Give Item:", str, "Give", "Cancel");
			PlayerInfo[playerid][E_CHARACTER_TARGET] = userid;
		}
	}
	return 1;
}

Dialog:DialogInvGiveAmount(playerid, response, listitem, inputtext[])
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
			return format(str, sizeof(str), "Item: %s (Amount: %d)\n\nPlease enter the amount of this item you wish to give %s:", string, InventoryInfo[playerid][itemid][E_INVENTORY_QUANTITY], ReturnName(userid, playerid)),
			Dialog_Show(playerid, DialogInvGiveAmount, DIALOG_STYLE_INPUT, "Give Item", str, "Give", "Cancel");

		if (strval(inputtext) < 1 || strval(inputtext) > InventoryInfo[playerid][itemid][E_INVENTORY_QUANTITY])
			return format(str, sizeof(str), "ERROR: You don't have that much.\n\nItem: %s (Amount: %d)\n\nPlease enter the amount of this item you wish to give %s:", string, InventoryInfo[playerid][itemid][E_INVENTORY_QUANTITY], ReturnName(userid, playerid)),
			Dialog_Show(playerid, DialogInvGiveAmount, DIALOG_STYLE_INPUT, "Give Item:", str, "Give", "Cancel");

		new id = Inventory_Add(userid, string, InventoryInfo[playerid][itemid][E_INVENTORY_MODEL], strval(inputtext));

		if (id == -1)
			return SendErrorMessage(playerid, "That player doesn't have anymore inventory slots.");

		SendNearbyMessage(playerid, 30.0, COLOR_EMOTE, "* %s takes out a \"%s\" and gives it to %s.", ReturnName(playerid, 0), string, ReturnName(userid, 0));
		SendServerMessage(userid, "%s has given you %s (added to inventory).", ReturnName(playerid, 0), string);

		Inventory_Remove(playerid, string, strval(inputtext));
	}
	return 1;
}

Dialog:DialogPickup(playerid, response, listitem, inputtext[])
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
	return 1;
}

Dialog:DialogHelp(playerid, response, listitem, inputtext[])
{
	if (response)
	{
		switch (listitem)
		{
			case 0:
			{
				SendClientMessage(playerid, COLOR_DARKGREEN, "|__________ General Commands __________|");
				SendClientMessage(playerid, COLOR_ORANGE, "General Commands: /stats, /admins, /report, /o(oc), /pay, /isafk, /time, /delays, /levelup, /rcp, /inventory");
				SendClientMessage(playerid, COLOR_ORANGE, "General Commands: /enter, /exit, /mask, /setchannel, /setslot, /radio, /licenseexam, /unimpound");
				SendClientMessage(playerid, COLOR_ORANGE, "General Commands: /damages, /health, /acceptdeath, /helpup, /fixr, /respawnme, /setspawn, /settings");
				SendClientMessage(playerid, COLOR_ORANGE, "General Commands: /approve, /deny, /tickets, /coin, /dice, /gascan, /listings, /pc, /spray");
			}
			case 1:
			{
				SendClientMessage(playerid, COLOR_DARKGREEN, "|__________ Roleplay Commands __________|");
				SendClientMessage(playerid, COLOR_ORANGE, "Roleplay Commands: /me, /do, /ame, /my, /amy, /s(hout), /l(ow), /b, /pm, /deposit, /withdraw");
				SendClientMessage(playerid, COLOR_ORANGE, "Roleplay Commands: /balance, /myidcard, /animhelp, /handshake, /frisk");
			}
			case 2:
			{
				SendClientMessage(playerid, COLOR_DARKGREEN, "|__________ Property Commands __________|");
				SendClientMessage(playerid, COLOR_ORANGE, "Property Commands: /buyproperty, /lock, /furniture, /giveproperty, /sellproperty");
				SendClientMessage(playerid, COLOR_ORANGE, "Property Commands: /ringbell, /knock");
			}
			case 3:
			{
				SendClientMessage(playerid, COLOR_DARKGREEN, "|__________ Business Commands __________|");
				SendClientMessage(playerid, COLOR_ORANGE, "Business Commands: /buybiz, /lock, /bizinfo, /bizfee, /bizcash, /bizproduct");
				SendClientMessage(playerid, COLOR_ORANGE, "Business Commands: /givebusiness, /sellbusiness, /ringbell, /knock, /badvert");
			}
			case 4:
			{
				SendClientMessage(playerid, COLOR_DARKGREEN, "|__________ Faction Commands __________|");
				SendClientMessage(playerid, COLOR_ORANGE, "Faction Commands: /factions, /f, /factionon");

				if(ReturnFactionType(playerid) == FACTION_TYPE_POLICE)
				{
					SendClientMessage(playerid, COLOR_ORANGE, "Faction Commands: /fduty, /offduty, /handcuff, /unhandcuff, /badge, /flocker, /m(egaphone), /(dep)artment");
					SendClientMessage(playerid, COLOR_ORANGE, "Faction Commands: /carsign, /remove_carsign, /tazer, /riotgun, /revoke, /givelicense, /impound, /checktrunk");
					SendClientMessage(playerid, COLOR_ORANGE, "Faction Commands: /searchproperty, /mdc, /tackle, /ticket, /charge, /opencell, /closecell, /spike, /roadblock");
				}
				if(ReturnFactionType(playerid) == FACTION_TYPE_MEDICAL)
				{
					SendClientMessage(playerid, COLOR_ORANGE, "Faction Commands: /fduty, /offduty, /flocker, /m(egaphone), /(dep)artment");
					SendClientMessage(playerid, COLOR_ORANGE, "Faction Commands: /dropinjured, /loadinjured, /rescue");
				}
				if(PlayerInfo[playerid][E_CHARACTER_FACTIONRANK] == 4)
				{
					SendClientMessage(playerid, COLOR_ORANGE, "Faction Commands: /finvite, /funinvite, /founinvite, /frank.");
				}
			}
			case 5:
			{
				SendClientMessage(playerid, COLOR_DARKGREEN, "|__________ Vehicle Commands __________|");
				SendClientMessage(playerid, COLOR_ORANGE, "Vehicle Commands: /mycars, /engine, /carlock, /carkey, /carsell, /cardespawn, /cartrunk, /carhood");
				SendClientMessage(playerid, COLOR_ORANGE, "Vehicle Commands: /carlights, /carwindow, /carradio, /carscrap, /carwhisper, /carb");
				SendClientMessage(playerid, COLOR_ORANGE, "Vehicle Commands: /refill, /limitspeed");
				SendTipMessage(playerid, "Press 'ALT' to turn on engine");
				SendTipMessage(playerid, "Press '2' to unlock/lock vehicles");
			}
			case 6:
			{
				SendClientMessage(playerid, COLOR_DARKGREEN, "|__________ Minigames Commands __________|");
				SendClientMessage(playerid, COLOR_ORANGE, "Minigames Commands: /court, /resetcourt, /blackjack, /buylottery, /pool, /poolexit");
			}
			case 7:
			{
				SendClientMessage(playerid, COLOR_DARKGREEN, "|__________ Jobs Commands __________|");
				SendClientMessage(playerid, COLOR_ORANGE, "Jobs Commands: /joinjob, /quitjob, /jobduty, ");
				SendClientMessage(playerid, COLOR_ORANGE, "Docksworker Commands: /loadcargo, /storecargo");
				SendClientMessage(playerid, COLOR_ORANGE, "Fishing Commands: /fish, /sellfish, /buybait, /buyrod");
				if(PlayerInfo[playerid][E_CHARACTER_JOBS] == JOB_TRUCKER)
				{
					SendClientMessage(playerid, COLOR_ORANGE, "Truckers Commands: /tpda, /buycargo, /sellcargo");
					SendTipMessage(playerid, "Type '/cartrunk' to place cargo into truck.");
				}
				if(PlayerInfo[playerid][E_CHARACTER_JOBS] == JOB_LUMBERJACK)
				{
					SendClientMessage(playerid, COLOR_ORANGE, "Lumberjack Commands: /buysaw, /cutwood, /sellwood");
					SendTipMessage(playerid, "Press 'ALT' to cutting tree(s) using chainsaw.");
				}
				if(PlayerInfo[playerid][E_CHARACTER_JOBS] == JOB_TAXI)
				{
					SendClientMessage(playerid, COLOR_ORANGE, "Taxi Commands: /jobduty, /taxicall");
					SendTipMessage(playerid, "Taxi fare will change every 50 meters of distance.");
				}
				if(PlayerInfo[playerid][E_CHARACTER_JOBS] == JOB_MECHANIC)
				{
					SendClientMessage(playerid, COLOR_ORANGE, "Mechanic Commands: /jobduty, /mechmenu(/mm)");
					SendTipMessage(playerid, "Repairing, Repaint vehicles and maintenace road safety.");
				}
				if(PlayerInfo[playerid][E_CHARACTER_JOBS] == JOB_SMUGGLER)
				{
					SendClientMessage(playerid, COLOR_ORANGE, "Smugglers Commands: /findpacket, /storepacket");
					SendTipMessage(playerid, "Press 'ALT' to pickup packet.");
				}
			}
			case 8:
			{
				SendClientMessage(playerid, COLOR_DARKGREEN, "|__________ Crime Profesions Commands __________|");
				SendClientMessage(playerid, COLOR_ORANGE, "Crime Commands: /extort, /extortions, /drugsdeal, /buydrugs, /buymats, /creategun, /production");
				SendTipMessage(playerid, "Hold aim into actor/npc to start robbery business.");
				SendTipMessage(playerid, "Press LMB (punch) into actor/npc to start extortions business.");
			}
			case 9:
			{
				SendClientMessage(playerid, COLOR_DARKGREEN, "|__________ Donatur Commands __________|");
				SendClientMessage(playerid, COLOR_ORANGE, "Donatur Commands: /streetshop");
			}
		}
	}
	return 1;
}

Dialog:DialogSettings(playerid, response, listitem, inputtext[])
{
	if (response)
	{
		switch(listitem)
		{
			case 0:
			{
				if(PlayerInfo[playerid][E_CHARACTER_TOGHUD])
				{
					ShowPlayerNeeds(playerid);
					PlayerTextDrawShow(playerid, servername[playerid]);
					PlayerTextDrawShow(playerid, servername2[playerid]);
					ShowMoneyFormat(playerid);
					TextDrawShowForPlayer(playerid, Times);
					PlayerInfo[playerid][E_CHARACTER_TOGHUD] = false;
					SendInfoMessage(playerid, "[SETTINGS] HUD TextDraws has been Enable.");
				}
				else
				{
					HideClock(playerid);
					HidePlayerNeeds(playerid);
					PlayerTextDrawHide(playerid, servername[playerid]);
					PlayerTextDrawHide(playerid, servername2[playerid]);
					PlayerTextDrawHide(playerid, Street[0][playerid]);
					PlayerTextDrawHide(playerid, Street[1][playerid]);
					HideVehicleSpeedometer(playerid);
					HideMoneyFormat(playerid);
					PlayerInfo[playerid][E_CHARACTER_TOGHUD] = true;
					SendInfoMessage(playerid, "[SETTINGS] HUD TextDraws has been Disable.");
				}
			}
			case 1:
			{
				if(PlayerInfo[playerid][E_CHARACTER_TOGJOIN])
				{
					PlayerInfo[playerid][E_CHARACTER_TOGJOIN] = false;
					SendInfoMessage(playerid, "[SETTINGS] Joined Logs has been Enable.");
				}
				else
				{
					PlayerInfo[playerid][E_CHARACTER_TOGJOIN] = true;
					SendInfoMessage(playerid, "[SETTINGS] Joined Logs has been Disable.");
				}
			}
			case 2:
			{
				if(PlayerInfo[playerid][E_CHARACTER_TOGADMIN])
				{
					PlayerInfo[playerid][E_CHARACTER_TOGADMIN] = false;
					SendInfoMessage(playerid, "[SETTINGS] Admin Messages has been Enable.");
				}
				else
				{
					PlayerInfo[playerid][E_CHARACTER_TOGADMIN] = true;
					SendInfoMessage(playerid, "[SETTINGS] Admin Messages has been Disable.");
				}
			}
			case 3:
			{
				if(PlayerInfo[playerid][E_CHARACTER_TOGFMS])
				{
					PlayerInfo[playerid][E_CHARACTER_TOGFMS] = false;
					SendInfoMessage(playerid, "[SETTINGS] Faction Messages has been Enable.");
				}
				else
				{
					PlayerInfo[playerid][E_CHARACTER_TOGFMS] = true;
					SendInfoMessage(playerid, "[SETTINGS] Faction Messages has been Disable.");
				}
			}
			case 4:
			{
				if(PlayerInfo[playerid][E_CHARACTER_TOGPMS])
				{
					PlayerInfo[playerid][E_CHARACTER_TOGPMS] = false;
					SendInfoMessage(playerid, "[SETTINGS] Private Messages has been Enable.");
				}
				else
				{
					PlayerInfo[playerid][E_CHARACTER_TOGPMS] = true;
					SendInfoMessage(playerid, "[SETTINGS] Private Messages has been Disable.");
				}
			}
			case 5:
			{
				if(PlayerInfo[playerid][E_CHARACTER_TOGDMS])
				{
					PlayerInfo[playerid][E_CHARACTER_TOGDMS] = false;
					SendInfoMessage(playerid, "[SETTINGS] Damages Messages has been Enable.");
				}
				else
				{
					PlayerInfo[playerid][E_CHARACTER_TOGDMS] = true;
					SendInfoMessage(playerid, "[SETTINGS] Damages Messages has been Disable.");
				}
			}
			case 6:
			{
				if(PlayerInfo[playerid][E_CHARACTER_TOGTIPS])
				{
					PlayerInfo[playerid][E_CHARACTER_TOGTIPS] = false;
					SendInfoMessage(playerid, "[SETTINGS] Tips Messages has been Enable.");
				}
				else
				{
					PlayerInfo[playerid][E_CHARACTER_TOGTIPS] = true;
					SendInfoMessage(playerid, "[SETTINGS] Tips Messages has been Disable.");
				}
			}
			case 7:
			{
				if(PlayerInfo[playerid][E_CHARACTER_TOGPHONE])
				{
					PlayerInfo[playerid][E_CHARACTER_TOGPHONE] = false;
					SendInfoMessage(playerid, "[SETTINGS] switched your phonestyle to old school.");
				}
				else
				{
					PlayerInfo[playerid][E_CHARACTER_TOGPHONE] = true;
					SendInfoMessage(playerid, "[SETTINGS] switched your phonestyle to modern.");
				}
			}
			case 8:
			{
				if(PlayerInfo[playerid][E_CHARACTER_TOGALPR])
				{
					PlayerInfo[playerid][E_CHARACTER_TOGALPR] = false;
					SendInfoMessage(playerid, "[SETTINGS] ALPR interface has been Enable.");
				}
				else
				{
					PlayerInfo[playerid][E_CHARACTER_TOGALPR] = true;
					HideHeaderMessage(playerid);
					SendInfoMessage(playerid, "[SETTINGS] ALPR interface has been Disable.");
				}
			}
		}
	}
	return 1;
}

Dialog:DialogRadio(playerid, response, listitem, inputtext[])
{
	if (response)
	{
		switch(listitem)
		{
			case 0:
			{
				Dialog_Show(playerid, DialogAddURL, DIALOG_STYLE_INPUT, "Radio Stations:", "Type a song or radio station URL.\nNote that year we roleplay in 1990.", "Input", "Close");
			}
			case 1:
			{
				StopAudioStreamForPlayer(playerid);
				VehicleInfo[GetPlayerVehicleID(playerid)][E_VEHICLE_RADIO] = false;
			}
		}
	}
	return 1;
}

Dialog:DialogAddURL(playerid, response, listitem, inputtext[])
{
	if(response)
	{
		if (isnull(inputtext))
		{
			Dialog_Show(playerid, DialogAddURL, DIALOG_STYLE_INPUT, "Radio Stations:", "Type a song or radio station URL.\nNote that year we roleplay in 1990.", "Input", "Close");
		}

		format(VehicleInfo[GetPlayerVehicleID(playerid)][E_VEHICLE_RADIOURL], 128, inputtext);
		PlayAudioStreamForPlayer(playerid, inputtext);
		VehicleInfo[GetPlayerVehicleID(playerid)][E_VEHICLE_RADIO] = true;
	}
	return 1;
}

Dialog:DialogDrugsDealType1(playerid, response, listitem, inputtext[])
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

				SetTimerEx("DrugsDealing", 15000, false, "iiffff", playerid, type, x, y, z ,a);
				SendInfoMessage(playerid, "[DRUGS DEALER] You've opened drugs corner at %s, it will run for 15 minutes.", ReturnLocationStreet(playerid));
			}
			case 1: //Heroin
			{
				new type = 3;


				SetTimerEx("DrugsDealing", 15000, false, "iiffff", playerid, type, x, y, z ,a);
				SendInfoMessage(playerid, "[DRUGS DEALER] You've opened drugs corner at %s, it will run for 15 minutes.", ReturnLocationStreet(playerid));
			}
		}
	}
	return 1;
}

Dialog:DialogDrugsDealType2(playerid, response, listitem, inputtext[])
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
				
				SetTimerEx("DrugsDealing", 15000, false, "iiffff", playerid, type, x, y, z ,a);
				SendInfoMessage(playerid, "[DRUGS DEALER] You've opened drugs corner at %s, it will run for 15 minutes.", ReturnLocationStreet(playerid));
			}
			case 1: //PCP
			{
				new type = 4;
				
				SetTimerEx("DrugsDealing", 15000, false, "iiffff", playerid, type, x, y, z ,a);
				SendInfoMessage(playerid, "[DRUGS DEALER] You've opened drugs corner at %s, it will run for 15 minutes.", ReturnLocationStreet(playerid));
			}
		}
	}	
	return 1;
}

Dialog:DialogDrugsDeal(playerid, response, listitem, inputtext[])
{
	if(response)
	{
		if(IsPlayerNearDrugsDealing(playerid))
		{
			if(DrugsDealerType[playerid] == 1)
			{
				new cost = DrugsDealerAmount[playerid] * 50;
				if(!Inventory_Count(playerid, "Cocaine Crack"))
					return SendErrorMessage(playerid, "You don't have any crack in inventory.");

				if(Inventory_Count(playerid, "Cocaine Crack") < DrugsDealerAmount[playerid])
					return SendErrorMessage(playerid, "You need at least %d grams of crack.", DrugsDealerAmount[playerid]);

				Inventory_Remove(playerid, "Cocaine Crack", DrugsDealerAmount[playerid]);
				
				new Cents = floatround(cost * 100, floatround_round);

				GiveMoney(playerid, Cents);
				
				SendInfoMessage(playerid, "[DRUGS DEALER] You've received $%s from selling crack.", FormatMoney(Cents));

				//SetDynamicActorAngleToPlayer(DrugsDealerActor[playerid], playerid);
				ApplyDynamicActorAnimation(DrugsDealerActor[playerid], "DEALER", "DRUGS_BUY", 4.1, 0, 0, 0, 0, 0);
				ApplyAnimation(playerid, "DEALER", "DRUGS_BUY", 4.1, 0, 0, 0, 0, 0, 1);
				SetTimerEx("DrugsDealingRun", 3000, false, "ii", playerid, 0);
			}
			else if(DrugsDealerType[playerid] == 2)
			{
				new cost = DrugsDealerAmount[playerid] * 65;
				if(!Inventory_Count(playerid, "Marijuana"))
					return SendErrorMessage(playerid, "You don't have any marijuana in inventory.");

				if(Inventory_Count(playerid, "Marijuana") < DrugsDealerAmount[playerid])
					return SendErrorMessage(playerid, "You need at least %d grams of marijuana.", DrugsDealerAmount[playerid]);

				Inventory_Remove(playerid, "Marijuana", DrugsDealerAmount[playerid]);

				new Cents = floatround(cost * 100, floatround_round);

				GiveMoney(playerid, Cents);

				SendInfoMessage(playerid, "[DRUGS DEALER] You've received $%s from selling marijuana.", FormatMoney(Cents));

				//SetDynamicActorAngleToPlayer(DrugsDealerActor[playerid], playerid);
				ApplyDynamicActorAnimation(DrugsDealerActor[playerid], "DEALER", "DRUGS_BUY", 4.1, 0, 0, 0, 0, 0);
				ApplyAnimation(playerid, "DEALER", "DRUGS_BUY", 4.1, 0, 0, 0, 0, 0, 1);
				SetTimerEx("DrugsDealingRun", 3000, false, "ii", playerid, 0);
			}
			else if(DrugsDealerType[playerid] == 3)
			{
				new cost = DrugsDealerAmount[playerid] * 80;
				if(!Inventory_Count(playerid, "Heroin"))
					return SendErrorMessage(playerid, "You don't have any heroin in inventory.");

				if(Inventory_Count(playerid, "Heroin") < DrugsDealerAmount[playerid])
					return SendErrorMessage(playerid, "You need at least %d grams of heroin.", DrugsDealerAmount[playerid]);

				Inventory_Remove(playerid, "Heroin", DrugsDealerAmount[playerid]);

				new Cents = floatround(cost * 100, floatround_round);

				GiveMoney(playerid, Cents);
				
				SendInfoMessage(playerid, "[DRUGS DEALER] You've received $%s from selling heroin.", FormatMoney(Cents));

				//SetDynamicActorAngleToPlayer(DrugsDealerActor[playerid], playerid);
				ApplyDynamicActorAnimation(DrugsDealerActor[playerid], "DEALER", "DRUGS_BUY", 4.1, 0, 0, 0, 0, 0);
				ApplyAnimation(playerid, "DEALER", "DRUGS_BUY", 4.1, 0, 0, 0, 0, 0, 1);
				SetTimerEx("DrugsDealingRun", 3000, false, "ii", playerid, 0);
			}
			else if(DrugsDealerType[playerid] == 4)
			{
				new cost = DrugsDealerAmount[playerid] * 80;
				if(!Inventory_Count(playerid, "PCP"))
					return SendErrorMessage(playerid, "You don't have any pcp in inventory.");

				if(Inventory_Count(playerid, "PCP") < DrugsDealerAmount[playerid])
					return SendErrorMessage(playerid, "You need at least %d grams of pcp.", DrugsDealerAmount[playerid]);

				Inventory_Remove(playerid, "PCP", DrugsDealerAmount[playerid]);
				
				new Cents = floatround(cost * 100, floatround_round);

				GiveMoney(playerid, Cents);

				SendInfoMessage(playerid, "[DRUGS DEALER] You've received $%s from selling pcp.", FormatMoney(Cents));

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
	return 1;
}

Dialog:DialogDrugsCombine(playerid, response, listitem, inputtext[])
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

					BusinessInfo[id][E_BUSINESS_LOADINGDISPLAY] = Create3DTextLabel("PCP COOK IN PROCESS\nSupplied Marijuana: 5 gram\nExpected Output: 3-5 gram\nTime Left: ((|------))", COLOR_3DTEXT, BusinessInfo[id][E_BUSINESS_ENTRANCEPOINT][0], BusinessInfo[id][E_BUSINESS_ENTRANCEPOINT][1], BusinessInfo[id][E_BUSINESS_ENTRANCEPOINT][2]+1, 5.0, BusinessInfo[id][E_BUSINESS_INTERIORPOSWORLD], 1);
					BusinessInfo[id][E_BUSINESS_LOADINGCOUNT] = 1;

					BusinessInfo[id][E_BUSINESS_LOADING] = true; 
					BusinessInfo[id][E_BUSINESS_LOADINGTIMER] = SetTimerEx("CookDrugs", 10000, true, "iii", playerid, 1, id);
				}
			}
			case 1:
			{
				new id = IsPlayerInBusiness(playerid);
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

					BusinessInfo[id][E_BUSINESS_LOADINGDISPLAY] = Create3DTextLabel("PCP COOK IN PROCESS\nSupplied Marijuana: 5 gram\nExpected Output: 3-5 gram\nTime Left: ((|------))", COLOR_3DTEXT, BusinessInfo[id][E_BUSINESS_ENTRANCEPOINT][0], BusinessInfo[id][E_BUSINESS_ENTRANCEPOINT][1], BusinessInfo[id][E_BUSINESS_ENTRANCEPOINT][2]+1, 5.0, BusinessInfo[id][E_BUSINESS_INTERIORPOSWORLD], 1);
					BusinessInfo[id][E_BUSINESS_LOADINGCOUNT] = 1;

					BusinessInfo[id][E_BUSINESS_LOADING] = true; 
					BusinessInfo[id][E_BUSINESS_LOADINGTIMER] = SetTimerEx("CookDrugs", 10000, true, "iii", playerid, 2, id);
				}
			}
		}
	}
	return 1;
}

Dialog:DialogPhone(playerid, response, listitem, inputtext[])
{
	if(response)
	{
		switch(listitem)
		{
			case 0:
			{
				if(PlayerInfo[playerid][E_CHARACTER_PHONEOFF])
					return SendErrorMessage(playerid, "Your cellphone is turned off.");

				Dialog_Show(playerid, DialogDialNumber, DIALOG_STYLE_INPUT, "Dial Number:", "Please enter the number that you wish to dial below:", "Submit", "Cancel");
			}
			case 1:
			{
				if(PlayerInfo[playerid][E_CHARACTER_PHONEOFF])
					return SendErrorMessage(playerid, "Your cellphone is turned off.");

				Dialog_Show(playerid, DialogSMS, DIALOG_STYLE_INPUT, "Send Text Message:", "Please enter the number that you wish to send a text message to:", "Submit", "Cancel");
			}
			case 2:
			{
				ShowContacts(playerid);
			}
			case 3:
			{
				if(PlayerInfo[playerid][E_CHARACTER_PHONEOFF])
					return SendErrorMessage(playerid, "Your cellphone is turned off.");

				Dialog_Show(playerid, DialogBackground, DIALOG_STYLE_LIST, "Choose Wallpaper Color:", "(1) Default\n(2) Red\n(3) Yellow\n(4) Blue\n(5) Purple\n(6) Green", "Select", "Cancel");
			}
			case 4:
			{
				if (!PlayerInfo[playerid][E_CHARACTER_PHONEOFF])
				{
					if (PlayerInfo[playerid][E_CHARACTER_PHONELINE] != INVALID_PLAYER_ID) {
						cmd_hangup(playerid, "");
					}
					PlayerInfo[playerid][E_CHARACTER_PHONEOFF] = true;
					SendNearbyMessage(playerid, 20.0, COLOR_EMOTE, "** %s has powered off their cellphone.", ReturnName(playerid, 0));
				}
				else
				{
					PlayerInfo[playerid][E_CHARACTER_PHONEOFF] = false;
					SendNearbyMessage(playerid, 20.0, COLOR_EMOTE, "** %s has powered on their cellphone.", ReturnName(playerid, 0));
				}
			}
		}
	}
	return 1;
}

Dialog:DialogBackground(playerid, response, listitem, inputtext[])
{
	if(response)
	{
		switch(listitem)
		{
			case 0:
			{
				PlayerTextDrawBoxColor(playerid, Phone[1][playerid], 1703312639);
				PlayerTextDrawShow(playerid, Phone[1][playerid]);
			}
			case 1:
			{
				PlayerTextDrawBoxColor(playerid, Phone[1][playerid], 0x866565FF);
				PlayerTextDrawShow(playerid, Phone[1][playerid]);
			}
			case 2:
			{
				PlayerTextDrawBoxColor(playerid, Phone[1][playerid], 0x828665FF);
				PlayerTextDrawShow(playerid, Phone[1][playerid]);
			}
			case 3:
			{
				PlayerTextDrawBoxColor(playerid, Phone[1][playerid], 0x656E86FF);
				PlayerTextDrawShow(playerid, Phone[1][playerid]);
			}
			case 4:
			{
				PlayerTextDrawBoxColor(playerid, Phone[1][playerid], 0x776586FF);
				PlayerTextDrawShow(playerid, Phone[1][playerid]);
			}
			case 5:
			{
				PlayerTextDrawBoxColor(playerid, Phone[1][playerid], 0x658666FF);
				PlayerTextDrawShow(playerid, Phone[1][playerid]);
			}
		}
	}
	return 1;
}

Dialog:DialogDialNumber(playerid, response, listitem, inputtext[])
{
	if (response)
	{
		new
			string[16];

		if (isnull(inputtext) || !IsNumeric(inputtext))
			return Dialog_Show(playerid, DialogDialNumber, DIALOG_STYLE_INPUT, "Dial Number:", "Please enter the number that you wish to dial below:", "Submit", "Cancel");

		format(string, 16, "%d", strval(inputtext));
		cmd_call(playerid, string);
	}
	return 1;
}

Dialog:DialogSMS(playerid, response, listitem, inputtext[])
{
	if (response)
	{
		new number = strval(inputtext);

		if (isnull(inputtext) || !IsNumeric(inputtext))
			return Dialog_Show(playerid, DialogSMS, DIALOG_STYLE_INPUT, "Send Text Message:", "Please enter the number that you wish to send a text message to:", "Dial", "Back");

		if (GetNumberOwner(number) == INVALID_PLAYER_ID)
			return Dialog_Show(playerid, DialogSMS, DIALOG_STYLE_INPUT, "Send Text Message:", "Error: That number is not online right now.\nPlease enter the number that you wish to send a text message to:", "Dial", "Back");

		PlayerInfo[playerid][E_CHARACTER_CONTACT] = GetNumberOwner(number);

		new str[128];
		format(str, sizeof(str), "Please enter the message to send to %s:", ReturnName(PlayerInfo[playerid][E_CHARACTER_CONTACT], playerid));
		Dialog_Show(playerid, DialogSMSText, DIALOG_STYLE_INPUT, "Text Message:", str, "Send", "Back");
	}
	return 1;
}

Dialog:DialogSMSText(playerid, response, listitem, inputtext[])
{
	if (response)
	{
		if (isnull(inputtext))
		{
			return Dialog_Show(playerid, DialogSMSText, DIALOG_STYLE_INPUT, "Text Message:", "Please enter a message to send.\n\nPlease enter the message to send to:", "Send", "Back");
		}
		new targetid = PlayerInfo[playerid][E_CHARACTER_CONTACT];

		if (!IsPlayerConnected(targetid) || !PlayerInfo[targetid][E_CHARACTER_PHONE])
			return SendErrorMessage(playerid, "The specified phone number went offline.");

		SendErrorMessage(playerid, "Your text message is being sent.");

		new str[128];
		format(str, sizeof(str), "* %s takes out their cellphone.", ReturnName(playerid, 0));
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
		format(playerSMS[playerid], 128, inputtext);
		playerText[playerid] = SetTimerEx("OnPhoneSMS", 1500, false, "iii", playerid, 3, targetid); 
	}
	return 1;
}

Dialog:DialogContact(playerid, response, listitem, inputtext[])
{
	if (response)
	{
		if (!listitem) {
			Dialog_Show(playerid, DialogContactNew, DIALOG_STYLE_INPUT, "New Contact:", "Please enter the name of the contact below:", "Submit", "Back");
		}
		else {
			PlayerInfo[playerid][E_CHARACTER_CONTACT] = ListedContacts[playerid][listitem - 1];

			Dialog_Show(playerid, DialogContactInfo, DIALOG_STYLE_LIST, ContactInfo[playerid][PlayerInfo[playerid][E_CHARACTER_CONTACT]][E_CONTACT_NAME], "Call Contact\nDelete Contact", "Select", "Back");
		}
	}
	return 1;
}

Dialog:DialogContactNew(playerid, response, listitem, inputtext[])
{
	if (response)
	{
		if (isnull(inputtext))
			return Dialog_Show(playerid, DialogContactNew, DIALOG_STYLE_INPUT, "New Contact:", "Please enter a contact name.\nPlease enter the name of the contact below:", "Submit", "Back");

		if (strlen(inputtext) > 32)
			return Dialog_Show(playerid, DialogContactNew, DIALOG_STYLE_INPUT, "New Contact:", "The contact name can't exceed 32 characters.\nPlease enter the name of the contact below:", "Submit", "Back");

		strpack(PlayerInfo[playerid][E_CHARACTER_EDITINGITEM], inputtext, 32);

		new str[128];
		format(str, sizeof(str), "Contact Name: %s\nPlease enter the phone number for this contact:");
		Dialog_Show(playerid, DialogContactNumber, DIALOG_STYLE_INPUT, "Contact Number:", str, "Submit", "Back");
	}
	return 1;
}

Dialog:DialogContactNumber(playerid, response, listitem, inputtext[])
{
	if (response)
	{
		static name[32], string[128];

		strunpack(name, PlayerInfo[playerid][E_CHARACTER_EDITINGITEM]);

		if (isnull(inputtext) || !IsNumeric(inputtext))
		{
			new str[128];
			format(str, sizeof(str),  "Contact Name: %s\nPlease enter the phone number for this contact:");
			Dialog_Show(playerid, DialogContactNumber, DIALOG_STYLE_INPUT, "Contact Number:", str, "Submit", "Back");
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

				SendInfoMessage(playerid, "[PHONE] You have added %s to your contacts.", name);
				return 1;
			}
		}
		SendErrorMessage(playerid, "There is no slot left for anymore contacts.");
	}
	return 1;
}

Dialog:DialogContactInfo(playerid, response, listitem, inputtext[])
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

				SendInfoMessage(playerid, "[PHONE] You have deleted %s from your contacts.", ContactInfo[playerid][id][E_CONTACT_NAME]);

				ContactInfo[playerid][id][E_CONTACT_EXISTS] = false;
				ContactInfo[playerid][id][E_CONTACT_NUMBER] = 0;
				ContactInfo[playerid][id][E_CONTACT_DBID] = 0;

				ShowContacts(playerid);
			}
		}
	}
	return 1;
}

Dialog:DialogGPS(playerid, response, listitem, inputtext[])
{
	if(response)
	{
		switch(listitem)
		{
			case 0: //Point Of Interest
				Dialog_Show(playerid, DialogGPSPOI, DIALOG_STYLE_LIST, "GPS: Point of Interest", "Public Locations\nJobs Locations\nBusiness Locations\nTree Locations", "Select", "Cancel");
			case 1:
				Dialog_Show(playerid, DialogGPSPROP, DIALOG_STYLE_INPUT, "GPS: Properties", "Please enter the address of the properties below:", "Submit", "Cancel");
			case 2: //ENEX
				ShowENEXLocation(playerid);
			case 3: //Disable CP
				GPS_DisablePlayerRaceCheckPoint(playerid);
		}
	}
	return 1;
}

Dialog:DialogGPSPROP(playerid, response, listitem, inputtext[])
{
	if (response)
	{
		if (isnull(inputtext) || strlen(inputtext) > 32)
			return Dialog_Show(playerid, DialogGPSPROP, DIALOG_STYLE_INPUT, "GPS: Properties", "Please enter the address of the properties below:", "Submit", "Cancel");

		for (new i = 1; i != MAX_PROPERTY; i ++)
		{
			if (PropertyInfo[i][E_PROPERTY_DBID] && !strcmp(PropertyInfo[i][E_PROPERTY_ADDRESS], inputtext, true))
			{
				GPS_SetPlayerRaceCheckPoint(playerid, 1, PropertyInfo[i][E_PROPERTY_ENTRANCEPOS][0], PropertyInfo[i][E_PROPERTY_ENTRANCEPOS][1], PropertyInfo[i][E_PROPERTY_ENTRANCEPOS][2], 0.0, 0.0, 0.0);
			}
		}
		Dialog_Show(playerid, DialogGPSPROP, DIALOG_STYLE_INPUT, "GPS: Properties", "No results found for.\nPlease enter the address of the properties below:", "Submit", "Cancel");
	}
	return 1;
}

Dialog:DialogGPSPOI(playerid, response, listitem, inputtext[])
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
	return 1;
}

Dialog:DialogGPSPublic(playerid, response, listitem, inputtext[])
{
	if (response)
	{
		GPS_SetPlayerRaceCheckPoint(playerid, 1, PublicPoint[listitem][0], PublicPoint[listitem][1], PublicPoint[listitem][2], 0.0, 0.0, 0.0);
	}
	return 1;
}

Dialog:DialogGPSBiz(playerid, response, listitem, inputtext[])
{
	if (response)
	{
		GPS_SetPlayerRaceCheckPoint(playerid, 1, BusinessInfo[listitem+3][E_BUSINESS_ENTRANCEPOS][0], BusinessInfo[listitem+3][E_BUSINESS_ENTRANCEPOS][1], BusinessInfo[listitem+3][E_BUSINESS_ENTRANCEPOS][2], 0.0, 0.0, 0.0);
	}
	return 1;
}

Dialog:DialogGPSTree(playerid, response, listitem, inputtext[])
{
	if (response)
	{
		GPS_SetPlayerRaceCheckPoint(playerid, 1, TreeInfo[listitem][E_TREE_POS][0], TreeInfo[listitem][E_TREE_POS][1], TreeInfo[listitem][E_TREE_POS][2], 0.0, 0.0, 0.0);
	}
	return 1;
}

Dialog:DialogGPSEnex(playerid, response, listitem, inputtext[])
{
	if (response)
	{
		GPS_SetPlayerRaceCheckPoint(playerid, 1, ENEXPoint[listitem][0], ENEXPoint[listitem][1], ENEXPoint[listitem][2], 0.0, 0.0, 0.0);
	}
	return 1;
}

Dialog:DialogGPSJobs(playerid, response, listitem, inputtext[])
{
	if (response)
	{
		GPS_SetPlayerRaceCheckPoint(playerid, 1, JobPoint[listitem][0], JobPoint[listitem][1], JobPoint[listitem][2], 0.0, 0.0, 0.0);
	}
	return 1;
}

Dialog:DialogInventory(playerid, response, listitem, inputtext[])
{
	if(response)
	{
		new
			name[128], id = -1;

		strunpack(name, InventoryInfo[playerid][listitem][E_INVENTORY_ITEM]);
		PlayerInfo[playerid][E_CHARACTER_LISTITEM] = listitem;

		if(InventoryInfo[playerid][listitem][E_INVENTORY_QUANTITY] < 1)
			return SendErrorMessage(playerid, "There is no item on selected slot!");

		switch (PlayerInfo[playerid][E_CHARACTER_STORAGESELECT])
		{
			case 0:
			{
				format(name, sizeof(name), "%s (%d):", name, InventoryInfo[playerid][listitem][E_INVENTORY_QUANTITY]);
				Dialog_Show(playerid, DialogInvOption, DIALOG_STYLE_LIST, name, "Equip Item\nUnequip Item\nGive Item\nDrop Item", "Select", "Cancel");
			}
			case 1:
			{
				if ((id = IsPlayerNearVehicle(playerid)) != -1 && !VehicleInfo[id][E_VEHICLE_LOCKED])
				{
					if(GetVehicleModel(id) == 459 || GetVehicleModel(id) == 482 || GetVehicleModel(id) == 440 || GetVehicleModel(id) == 413)
					{
						if(!strcmp(name, "Fabric Cargo") && VS_Count(id, "Fabric Cargo") >= 3 || !strcmp(name, "Steel Cargo") && VS_Count(id, "Steel Cargo") >= 3
						|| !strcmp(name, "Woods Cargo") && VS_Count(id, "Woods Cargo") >= 3 || !strcmp(name, "Foods Cargo") && VS_Count(id, "Foods Cargo") >= 3
						|| !strcmp(name, "Clothes Cargo") && VS_Count(id, "Clothes Cargo") >= 3 || !strcmp(name, "Appliances Cargo") && VS_Count(id, "Appliances Cargo") >= 3
						|| !strcmp(name, "Fish Cargo") && VS_Count(id, "Fish Cargo") >= 3)
							return SendErrorMessage(playerid, "You can't place cargo into your vehicle trunk is full.");

						if (InventoryInfo[playerid][listitem][E_INVENTORY_QUANTITY] == 1)
						{

							VS_AddItem(id, name, InventoryInfo[playerid][listitem][E_INVENTORY_MODEL], 1);
							Inventory_Remove(playerid, name);

							ShowVehicleStorage(playerid, id);
						}
						else
						{
							new str[128];
							format(str, sizeof(str), "Item: %s (Quantity: %d)\n\nPlease enter the quantity that you wish to store for this item:", name, InventoryInfo[playerid][PlayerInfo[playerid][E_CHARACTER_LISTITEM]][E_INVENTORY_QUANTITY]);
							Dialog_Show(playerid, DIalogVPlace, DIALOG_STYLE_INPUT, "Vehicle Place:", str, "Store", "Back");
						}
					}
					else if(GetVehicleModel(id) == 499 || GetVehicleModel(id) == 414)
					{
						if(!strcmp(name, "Fabric Cargo") && VS_Count(id, "Fabric Cargo") >= 5 || !strcmp(name, "Steel Cargo") && VS_Count(id, "Steel Cargo") >= 5
						|| !strcmp(name, "Woods Cargo") && VS_Count(id, "Woods Cargo") >= 5 || !strcmp(name, "Foods Cargo") && VS_Count(id, "Foods Cargo") >= 5
						|| !strcmp(name, "Clothes Cargo") && VS_Count(id, "Clothes Cargo") >= 5 || !strcmp(name, "Appliances Cargo") && VS_Count(id, "Appliances Cargo") >= 5
						|| !strcmp(name, "Fish Cargo") && VS_Count(id, "Fish Cargo") >= 5)
							return SendErrorMessage(playerid, "You can't place cargo into your vehicle trunk is full.");

						if (InventoryInfo[playerid][listitem][E_INVENTORY_QUANTITY] == 1)
						{
							VS_AddItem(id, name, InventoryInfo[playerid][listitem][E_INVENTORY_MODEL], 1);
							Inventory_Remove(playerid, name);
		
							ShowVehicleStorage(playerid, id);
						}
						else
						{
							new str[128];
							format(str, sizeof(str), "Item: %s (Quantity: %d)\n\nPlease enter the quantity that you wish to store for this item:", name, InventoryInfo[playerid][PlayerInfo[playerid][E_CHARACTER_LISTITEM]][E_INVENTORY_QUANTITY]);
							Dialog_Show(playerid, DIalogVPlace, DIALOG_STYLE_INPUT, "Vehicle Place:", str, "Store", "Back");
						}
					}
					else if(GetVehicleModel(id) == 456)
					{
						if(!strcmp(name, "Fabric Cargo") && VS_Count(id, "Fabric Cargo") >= 8 || !strcmp(name, "Steel Cargo") && VS_Count(id, "Steel Cargo") >= 8
						|| !strcmp(name, "Woods Cargo") && VS_Count(id, "Woods Cargo") >= 8 || !strcmp(name, "Foods Cargo") && VS_Count(id, "Foods Cargo") >= 8
						|| !strcmp(name, "Clothes Cargo") && VS_Count(id, "Clothes Cargo") >= 8 || !strcmp(name, "Appliances Cargo") && VS_Count(id, "Appliances Cargo") >= 8
						|| !strcmp(name, "Fish Cargo") && VS_Count(id, "Fish Cargo") >= 8)
							return SendErrorMessage(playerid, "You can't place cargo into your vehicle trunk is full.");

						if (InventoryInfo[playerid][listitem][E_INVENTORY_QUANTITY] == 1)
						{
							VS_AddItem(id, name, InventoryInfo[playerid][listitem][E_INVENTORY_MODEL], 1);
							Inventory_Remove(playerid, name);
			
							ShowVehicleStorage(playerid, id);
						}
						else
						{
							new str[128];
							format(str, sizeof(str), "Item: %s (Quantity: %d)\n\nPlease enter the quantity that you wish to store for this item:", name, InventoryInfo[playerid][PlayerInfo[playerid][E_CHARACTER_LISTITEM]][E_INVENTORY_QUANTITY]);
							Dialog_Show(playerid, DIalogVPlace, DIALOG_STYLE_INPUT, "Vehicle Place:", str, "Store", "Back");
						}
					}
					else if(GetVehicleModel(id) == 455)
					{
						if(!strcmp(name, "Fabric Cargo") && VS_Count(id, "Fabric Cargo") >= 10 || !strcmp(name, "Steel Cargo") && VS_Count(id, "Steel Cargo") >= 10
						|| !strcmp(name, "Woods Cargo") && VS_Count(id, "Woods Cargo") >= 10 || !strcmp(name, "Foods Cargo") && VS_Count(id, "Foods Cargo") >= 10
						|| !strcmp(name, "Clothes Cargo") && VS_Count(id, "Clothes Cargo") >= 10 || !strcmp(name, "Appliances Cargo") && VS_Count(id, "Appliances Cargo") >= 10
						|| !strcmp(name, "Fish Cargo") && VS_Count(id, "Fish Cargo") >= 10)
							return SendErrorMessage(playerid, "You can't place cargo into your vehicle trunk is full.");

						if (InventoryInfo[playerid][listitem][E_INVENTORY_QUANTITY] == 1)
						{
							VS_AddItem(id, name, InventoryInfo[playerid][listitem][E_INVENTORY_MODEL], 1);
							Inventory_Remove(playerid, name);
			
							ShowVehicleStorage(playerid, id);
						}
						else
						{
							new str[128];
							format(str, sizeof(str), "Item: %s (Quantity: %d)\n\nPlease enter the quantity that you wish to store for this item:", name, InventoryInfo[playerid][PlayerInfo[playerid][E_CHARACTER_LISTITEM]][E_INVENTORY_QUANTITY]);
							Dialog_Show(playerid, DIalogVPlace, DIALOG_STYLE_INPUT, "Vehicle Place:", str, "Store", "Back");
						}
					}
					//Lumberjack
					else if(GetVehicleModel(id) == 422 || GetVehicleModel(id) == 478 || GetVehicleModel(id) == 554 || GetVehicleModel(id) == 543)
					{
						if(!strcmp(name, "Woods") && VS_Count(id, "Woods") >= 3)
							return SendErrorMessage(playerid, "You can't place woods into your vehicle trunk is full.");

						if (InventoryInfo[playerid][listitem][E_INVENTORY_QUANTITY] == 1)
						{
							VS_AddItem(id, name, InventoryInfo[playerid][listitem][E_INVENTORY_MODEL], 1);
							Inventory_Remove(playerid, name);
							VehicleObjectUpdates(id);
							ShowVehicleStorage(playerid, id);
						}
						else
						{
							new str[128];
							format(str, sizeof(str), "Item: %s (Quantity: %d)\n\nPlease enter the quantity that you wish to store for this item:", name, InventoryInfo[playerid][PlayerInfo[playerid][E_CHARACTER_LISTITEM]][E_INVENTORY_QUANTITY]);
							Dialog_Show(playerid, DIalogVPlace, DIALOG_STYLE_INPUT, "Vehicle Place:", str, "Store", "Back");
						}
					}
					else
					{
						if (!strcmp(name, "Woods"))
						{
							if (GetVehicleModel(id) != 422 && GetVehicleModel(id) != 478 && GetVehicleModel(id) != 554 && GetVehicleModel(id) != 543)
							{
								return SendErrorMessage(playerid, "Woods can only be placed in specific vehicles.");
							}
						}
						else if (!strcmp(name, "Fabric Cargo") && !strcmp(name, "Steel Cargo") && !strcmp(name, "Woods Cargo") && !strcmp(name, "Foods Cargo")
						&& !strcmp(name, "Clothes Cargo") && !strcmp(name, "Appliances Cargo") && !strcmp(name, "Fish Cargo"))
						{
							if (GetVehicleModel(id) != 422 && GetVehicleModel(id) != 478 && GetVehicleModel(id) != 554 && GetVehicleModel(id) != 543 && 
								GetVehicleModel(id) != 459 && GetVehicleModel(id) != 482 && GetVehicleModel(id) != 440 && GetVehicleModel(id) != 413 && 
								GetVehicleModel(id) != 499 && GetVehicleModel(id) != 414 && GetVehicleModel(id) != 456 && GetVehicleModel(id) != 455)
							{
								SendErrorMessage(playerid, "Cargo can only be placed in specific vehicles.");
							}
						}

						if (InventoryInfo[playerid][listitem][E_INVENTORY_QUANTITY] == 1)
						{
							VS_AddItem(id, name, InventoryInfo[playerid][listitem][E_INVENTORY_MODEL], 1);
							Inventory_Remove(playerid, name);
							ShowVehicleStorage(playerid, id);
						}
						else 
						{
							new str[128];
							format(str, sizeof(str), "Item: %s (Quantity: %d)\n\nPlease enter the quantity that you wish to store for this item:", name, InventoryInfo[playerid][PlayerInfo[playerid][E_CHARACTER_LISTITEM]][E_INVENTORY_QUANTITY]);
							Dialog_Show(playerid, DIalogVPlace, DIALOG_STYLE_INPUT, "Vehicle Place:", str, "Store", "Back");
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
						new str[128];
						format(str, sizeof(str), "Item: %s (Quantity: %d)\n\nPlease enter the quantity that you wish to store for this item:", name, InventoryInfo[playerid][PlayerInfo[playerid][E_CHARACTER_LISTITEM]][E_INVENTORY_QUANTITY]);
						Dialog_Show(playerid, DialogPropertyDeposit, DIALOG_STYLE_INPUT, "Property Safe Place:", str, "Store", "Back");
					}
				}
				PlayerInfo[playerid][E_CHARACTER_STORAGESELECT] = 0;
			}
		}
	}
	else
	{
		cmd_cartrunk(playerid, "");
	}
	return 1;
}

Dialog:DialogDropitems(playerid, response, listitem, inputtext[])
{
	if(!response)
	{
		new
			Float:x,
			Float:y,
			Float:z;

		GetPlayerPos(playerid, x, y, z);

		PlayerInfo[playerid][E_CHARACTER_ADDOBJECT] = CreateDynamicObject(PlayerInfo[playerid][E_CHARACTER_OBJECTID], x+2, y, z, 0.0, 0.0, 0.0, GetPlayerVirtualWorld(playerid), GetPlayerInterior(playerid)); 
		EditDynamicObject(playerid, PlayerInfo[playerid][E_CHARACTER_ADDOBJECT]); 
		PlayerInfo[playerid][E_CHARACTER_EDITINGOBJECT] = 5;
	}
	else
	{
		new
			Float:x,
			Float:y,
			Float:z,
			Float:angle;

		GetPlayerPos(playerid, x, y, z);
		GetPlayerFacingAngle(playerid, angle);

		DropItem(PlayerInfo[playerid][E_CHARACTER_OBJECTSTRING], ReturnName(playerid), PlayerInfo[playerid][E_CHARACTER_OBJECTID], PlayerInfo[playerid][E_CHARACTER_OBJECTQUANTITY], x, y, z - 0.9, 0.0, 0.0, 0.0, GetPlayerInterior(playerid), GetPlayerVirtualWorld(playerid), PlayerInfo[playerid][E_CHARACTER_OBJECTTYPE]);
		Inventory_Remove(playerid, PlayerInfo[playerid][E_CHARACTER_OBJECTSTRING], PlayerInfo[playerid][E_CHARACTER_OBJECTQUANTITY]);
		ApplyAnimation(playerid, "GRENADE", "WEAPON_throwu", 4.1, 0, 0, 0, 0, 0, 1);

		PlayerInfo[playerid][E_CHARACTER_EDITINGOBJECT] = 0; 
		PlayerInfo[playerid][E_CHARACTER_OBJECTID] = 0;
		PlayerInfo[playerid][E_CHARACTER_OBJECTTYPE] = 0;
		PlayerInfo[playerid][E_CHARACTER_OBJECTQUANTITY] = 0;
		PlayerInfo[playerid][E_CHARACTER_OBJECTOWN] = 0;
		format(PlayerInfo[playerid][E_CHARACTER_OBJECTSTRING], 512, "");
		DestroyDynamicObject(PlayerInfo[playerid][E_CHARACTER_ADDOBJECT]);
		SendServerMessage(playerid, "You're moved dropped items."); 

		if(PlayerInfo[playerid][E_CHARACTER_EQUIPITEMS] > INVENTORY_NONE)
		{
			ResetVarInventory(playerid);
		}
	}
	return 1;
}

Dialog:DialogVStorage(playerid, response, listitem, inputtext[])
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
				Dialog_Show(playerid, DialogVOption, DIALOG_STYLE_LIST, string, "Take Item\nStore Item", "Select", "Back");
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
	return 1;
}

Dialog:DialogVOption(playerid, response, listitem, inputtext[])
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
							new str[256];
							format(str, sizeof(str), "Item: %s (Quantity: %d)\n\nPlease enter the quantity that you wish to take for this item:", string, VstorageInfo[carid][itemid][E_VEHICLE_TRUNKQUANTITY]);
							Dialog_Show(playerid, DialogVtake, DIALOG_STYLE_INPUT, "Vehicle Take:", str, "Take", "Back");
						}
					}
				}
				case 1: //store
				{
					new id = Inventory_GetItemID(playerid, string);

					if(GetVehicleModel(carid) == 459 || GetVehicleModel(carid) == 482 || GetVehicleModel(carid) == 440 || GetVehicleModel(carid) == 413)
					{
						if(!strcmp(string, "Fabric Cargo") && VS_Count(carid, "Fabric Cargo") >= 3 || !strcmp(string, "Steel Cargo") && VS_Count(carid, "Steel Cargo") >= 3 \
						|| !strcmp(string, "Woods Cargo") && VS_Count(carid, "Woods Cargo") >= 3 || !strcmp(string, "Foods Cargo") && VS_Count(carid, "Foods Cargo") >= 3
						|| !strcmp(string, "Clothes Cargo") && VS_Count(carid, "Clothes Cargo") >= 3 || !strcmp(string, "Appliances Cargo") && VS_Count(carid, "Appliances Cargo") >= 3
						|| !strcmp(string, "Fish Cargo") && VS_Count(carid, "Fish Cargo") >= 3)
							return SendErrorMessage(playerid, "You can't place cargo into your vehicle trunk is full.");

						if (id == -1) {
							return SendErrorMessage(playerid, "You don't have anymore of this item to store!");
						}
						else if (InventoryInfo[playerid][id][E_INVENTORY_QUANTITY] == 1)
						{
							VS_AddItem(carid, string, InventoryInfo[playerid][id][E_INVENTORY_MODEL], 1);
							Inventory_Remove(playerid, string);
				
							ShowVehicleStorage(playerid, carid);
						}
						else
						{
							PlayerInfo[playerid][E_CHARACTER_LISTITEM] = id;

							new str[128];
							format(str, sizeof(str), "Item: %s (Quantity: %d)\n\nPlease enter the quantity that you wish to store for this item:", string, InventoryInfo[playerid][PlayerInfo[playerid][E_CHARACTER_LISTITEM]][E_INVENTORY_QUANTITY]);
							Dialog_Show(playerid, DIalogVPlace, DIALOG_STYLE_INPUT, "Vehicle Place:", str, "Store", "Back");
						}
					}
					else if(GetVehicleModel(carid) == 499 || GetVehicleModel(carid) == 414)
					{
						if(!strcmp(string, "Fabric Cargo") && VS_Count(carid, "Fabric Cargo") >= 5 || !strcmp(string, "Steel Cargo") && VS_Count(carid, "Steel Cargo") >= 5
						|| !strcmp(string, "Woods Cargo") && VS_Count(carid, "Woods Cargo") >= 5 || !strcmp(string, "Foods Cargo") && VS_Count(carid, "Foods Cargo") >= 5
						|| !strcmp(string, "Clothes Cargo") && VS_Count(carid, "Clothes Cargo") >= 5 || !strcmp(string, "Appliances Cargo") && VS_Count(carid, "Appliances Cargo") >= 5
						|| !strcmp(string, "Fish Cargo") && VS_Count(carid, "Fish Cargo") >= 5)
							return SendErrorMessage(playerid, "You can't place cargo into your vehicle trunk is full.");


						if (id == -1) {
							return SendErrorMessage(playerid, "You don't have anymore of this item to store!");
						}
						else if (InventoryInfo[playerid][id][E_INVENTORY_QUANTITY] == 1)
						{
							VS_AddItem(carid, string, InventoryInfo[playerid][id][E_INVENTORY_MODEL], 1);
							Inventory_Remove(playerid, string);
		
							ShowVehicleStorage(playerid, carid);
						}
						else
						{
							PlayerInfo[playerid][E_CHARACTER_LISTITEM] = id;

							new str[128];
							format(str, sizeof(str), "Item: %s (Quantity: %d)\n\nPlease enter the quantity that you wish to store for this item:", string, InventoryInfo[playerid][PlayerInfo[playerid][E_CHARACTER_LISTITEM]][E_INVENTORY_QUANTITY]);
							Dialog_Show(playerid, DIalogVPlace, DIALOG_STYLE_INPUT, "Vehicle Place:", str, "Store", "Back");
						}
					}
					else if(GetVehicleModel(carid) == 456)
					{
						if(!strcmp(string, "Fabric Cargo") && VS_Count(carid, "Fabric Cargo") >= 8 || !strcmp(string, "Steel Cargo") && VS_Count(carid, "Steel Cargo") >= 8
						|| !strcmp(string, "Woods Cargo") && VS_Count(carid, "Woods Cargo") >= 8 || !strcmp(string, "Foods Cargo") && VS_Count(carid, "Foods Cargo") >= 8
						|| !strcmp(string, "Clothes Cargo") && VS_Count(carid, "Clothes Cargo") >= 8 || !strcmp(string, "Appliances Cargo") && VS_Count(carid, "Appliances Cargo") >= 8
						|| !strcmp(string, "Fish Cargo") && VS_Count(carid, "Fish Cargo") >= 8)
							return SendErrorMessage(playerid, "You can't place cargo into your vehicle trunk is full.");


						if (id == -1) {
							return SendErrorMessage(playerid, "You don't have anymore of this item to store!");
						}
						else if (InventoryInfo[playerid][id][E_INVENTORY_QUANTITY] == 1)
						{
							VS_AddItem(carid, string, InventoryInfo[playerid][id][E_INVENTORY_MODEL], 1);
							Inventory_Remove(playerid, string);
				
							ShowVehicleStorage(playerid, carid);
						}
						else
						{
							PlayerInfo[playerid][E_CHARACTER_LISTITEM] = id;

							new str[128];
							format(str, sizeof(str), "Item: %s (Quantity: %d)\n\nPlease enter the quantity that you wish to store for this item:", string, InventoryInfo[playerid][PlayerInfo[playerid][E_CHARACTER_LISTITEM]][E_INVENTORY_QUANTITY]);
							Dialog_Show(playerid, DIalogVPlace, DIALOG_STYLE_INPUT, "Vehicle Place:", str, "Store", "Back");
						}
					}
					else if(GetVehicleModel(carid) == 455)
					{
						if(!strcmp(string, "Fabric Cargo") && VS_Count(carid, "Fabric Cargo") >= 10 || !strcmp(string, "Steel Cargo") && VS_Count(carid, "Steel Cargo") >= 10
						|| !strcmp(string, "Woods Cargo") && VS_Count(carid, "Woods Cargo") >= 10 || !strcmp(string, "Foods Cargo") && VS_Count(carid, "Foods Cargo") >= 10
						|| !strcmp(string, "Clothes Cargo") && VS_Count(carid, "Clothes Cargo") >= 10 || !strcmp(string, "Appliances Cargo") && VS_Count(carid, "Appliances Cargo") >= 10
						|| !strcmp(string, "Fish Cargo") && VS_Count(carid, "Fish Cargo") >= 10)
							return SendErrorMessage(playerid, "You can't place cargo into your vehicle trunk is full.");


						if (id == -1) {
							return SendErrorMessage(playerid, "You don't have anymore of this item to store!");
						}
						else if (InventoryInfo[playerid][id][E_INVENTORY_QUANTITY] == 1)
						{
							VS_AddItem(carid, string, InventoryInfo[playerid][id][E_INVENTORY_MODEL], 1);
							Inventory_Remove(playerid, string);
				
							ShowVehicleStorage(playerid, carid);
						}
						else
						{
							PlayerInfo[playerid][E_CHARACTER_LISTITEM] = id;

							new str[128];
							format(str, sizeof(str), "Item: %s (Quantity: %d)\n\nPlease enter the quantity that you wish to store for this item:", string, InventoryInfo[playerid][PlayerInfo[playerid][E_CHARACTER_LISTITEM]][E_INVENTORY_QUANTITY]);
							Dialog_Show(playerid, DIalogVPlace, DIALOG_STYLE_INPUT, "Vehicle Place:", str, "Store", "Back");
						}
					}
					else if(GetVehicleModel(carid) == 422 || GetVehicleModel(carid) == 478 || GetVehicleModel(carid) == 554 || GetVehicleModel(carid) == 543)
					{
						if(!strcmp(string, "Woods") && VS_Count(carid, "Woods") >= 3)
							return SendErrorMessage(playerid, "You can't place woods into your vehicle trunk is full.");

						if (id == -1) {
							return SendErrorMessage(playerid, "You don't have anymore of this item to store!");
						}
						else if (InventoryInfo[playerid][id][E_INVENTORY_QUANTITY] == 1)
						{
							VS_AddItem(carid, string, InventoryInfo[playerid][id][E_INVENTORY_MODEL], 1);
							Inventory_Remove(playerid, string);
							VehicleObjectUpdates(carid);
							ShowVehicleStorage(playerid, carid);
						}
						else
						{
							PlayerInfo[playerid][E_CHARACTER_LISTITEM] = id;

							new str[128];
							format(str, sizeof(str), "Item: %s (Quantity: %d)\n\nPlease enter the quantity that you wish to store for this item:", string, InventoryInfo[playerid][PlayerInfo[playerid][E_CHARACTER_LISTITEM]][E_INVENTORY_QUANTITY]);
							Dialog_Show(playerid, DIalogVPlace, DIALOG_STYLE_INPUT, "Vehicle Place:", str, "Store", "Back");
						}
					}
					else
					{
						if (!strcmp(string, "Woods"))
						{
							if (GetVehicleModel(carid) != 422 && GetVehicleModel(carid) != 478 && GetVehicleModel(carid) != 554 && GetVehicleModel(carid) != 543)
							{
								return SendErrorMessage(playerid, "Woods can only be placed in specific vehicles.");
							}
						}
						else if (!strcmp(string, "Fabric Cargo") && !strcmp(string, "Steel Cargo") && !strcmp(string, "Woods Cargo") && !strcmp(string, "Foods Cargo")
						&& !strcmp(string, "Clothes Cargo") && !strcmp(string, "Appliances Cargo") && !strcmp(string, "Fish Cargo"))
						{
							if (GetVehicleModel(carid) != 422 && GetVehicleModel(carid) != 478 && GetVehicleModel(carid) != 554 && GetVehicleModel(carid) != 543 && 
								GetVehicleModel(carid) != 459 && GetVehicleModel(carid) != 482 && GetVehicleModel(carid) != 440 && GetVehicleModel(carid) != 413 && 
								GetVehicleModel(carid) != 499 && GetVehicleModel(carid) != 414 && GetVehicleModel(carid) != 456 && GetVehicleModel(carid) != 455)
							{
								SendErrorMessage(playerid, "Cargo can only be placed in specific vehicles.");
							}
						}

						if (id == -1) {
							return SendErrorMessage(playerid, "You don't have anymore of this item to store!");
						}
						else if (InventoryInfo[playerid][id][E_INVENTORY_QUANTITY] == 1)
						{

							VS_AddItem(carid, string, InventoryInfo[playerid][id][E_INVENTORY_MODEL], 1);
							Inventory_Remove(playerid, string);
							
							ShowVehicleStorage(playerid, carid);
						}
						else 
						{
							PlayerInfo[playerid][E_CHARACTER_LISTITEM] = id;

							new str[128];
							format(str, sizeof(str), "Item: %s (Quantity: %d)\n\nPlease enter the quantity that you wish to store for this item:", string, InventoryInfo[playerid][PlayerInfo[playerid][E_CHARACTER_LISTITEM]][E_INVENTORY_QUANTITY]);
							Dialog_Show(playerid, DIalogVPlace, DIALOG_STYLE_INPUT, "Vehicle Place:", str, "Store", "Back");
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
	return 1;
}

Dialog:DialogVPlace(playerid, response, listitem, inputtext[])
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

			// Cek apakah item adalah Woods atau Cargo
			if (!strcmp(string, "Woods") || !strcmp(string, "Fabric Cargo") || !strcmp(string, "Steel Cargo") || 
				!strcmp(string, "Woods Cargo") || !strcmp(string, "Foods Cargo") || !strcmp(string, "Clothes Cargo") || 
				!strcmp(string, "Appliances Cargo") || !strcmp(string, "Fish Cargo"))
			{
				amount = 1; // Batasi hanya bisa 1
			}

			if (amount < 1 || amount > InventoryInfo[playerid][PlayerInfo[playerid][E_CHARACTER_LISTITEM]][E_INVENTORY_QUANTITY])
			{
				new str[128];
				format(str, sizeof(str), "Item: %s (Quantity: %d)\n\nPlease enter the quantity that you wish to store for this item:", string, InventoryInfo[playerid][PlayerInfo[playerid][E_CHARACTER_LISTITEM]][E_INVENTORY_QUANTITY]);
				return Dialog_Show(playerid, DialogVPlace, DIALOG_STYLE_INPUT, "Vehicle Place:", str, "Store", "Back");
			}

			VS_AddItem(carid, string, InventoryInfo[playerid][PlayerInfo[playerid][E_CHARACTER_LISTITEM]][E_INVENTORY_MODEL], amount);
			Inventory_Remove(playerid, string, amount);
			VehicleObjectUpdates(carid);
			ShowVehicleStorage(playerid, carid);
		}
		else ShowVehicleStorage(playerid, carid);
	}
	return 1;
}

Dialog:DialogVTake(playerid, response, listitem, inputtext[])
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

			// Cek apakah item adalah Woods atau Cargo
			if (!strcmp(string, "Woods") || !strcmp(string, "Fabric Cargo") || !strcmp(string, "Steel Cargo") || 
				!strcmp(string, "Woods Cargo") || !strcmp(string, "Foods Cargo") || !strcmp(string, "Clothes Cargo") || 
				!strcmp(string, "Appliances Cargo") || !strcmp(string, "Fish Cargo"))
			{
				amount = 1; // Batasi hanya bisa 1
			}

			if (amount < 1 || amount > VstorageInfo[carid][PlayerInfo[playerid][E_CHARACTER_STORAGEITEM]][E_VEHICLE_TRUNKQUANTITY])
			{
				new str[128];
				format(str, sizeof(str), "Item: %s (Quantity: %d)\n\nPlease enter the quantity that you wish to take for this item:", string, VstorageInfo[carid][PlayerInfo[playerid][E_CHARACTER_LISTITEM]][E_VEHICLE_TRUNKQUANTITY]);
				return Dialog_Show(playerid, DialogVTake, DIALOG_STYLE_INPUT, "Vehicle Take:", str, "Take", "Back");
			}

			new id = Inventory_Add(playerid, string, VstorageInfo[carid][PlayerInfo[playerid][E_CHARACTER_STORAGEITEM]][E_VEHICLE_TRUNKMODEL], amount);

			if (id == -1)
				return SendErrorMessage(playerid, "You don't have any inventory slots left.");

			VS_RemoveItem(carid, string, amount);
			VehicleObjectUpdates(carid);
			ShowVehicleStorage(playerid, carid);
		}
		else ShowVehicleStorage(playerid, carid);
	}
	return 1;
}

Dialog:DialogPropertyItem(playerid, response, listitem, inputtext[])
{
	static
		houseid = -1,
		string[64];

	if ((houseid = IsPlayerInProperty(playerid)) != -1 && (PropertyInfo[houseid][E_PROPERTY_OWNERDBID] == PlayerInfo[playerid][E_CHARACTER_DBID]) || ReturnFactionType(playerid) == FACTION_TYPE_POLICE)
	{
		if (response)
		{
			if (PropertyStorage[houseid][listitem][E_PSTORAGE_EXISTS])
			{
				PlayerInfo[playerid][E_CHARACTER_STORAGEITEM] = listitem;

				strunpack(string, PropertyStorage[houseid][listitem][E_PSTORAGE_NAME]);

				format(string, sizeof(string), "%s (Quantity: %d)", string, PropertyStorage[houseid][listitem][E_PSTORAGE_QUANTITY]);
				Dialog_Show(playerid, DialogPropertyStorage, DIALOG_STYLE_LIST, string, "Take Item\nStore Item", "Select", "Back");
			}
			else 
			{
				OpenInventory(playerid);
				PlayerInfo[playerid][E_CHARACTER_STORAGESELECT] = 2;
			}
		}
	}
	return 1;
}

Dialog:DialogPropertyStorage(playerid, response, listitem, inputtext[])
{
	static
		houseid = -1,
		itemid = -1,
		string[32];

	if ((houseid = IsPlayerInProperty(playerid)) != -1 && (PropertyInfo[houseid][E_PROPERTY_OWNERDBID] == PlayerInfo[playerid][E_CHARACTER_DBID]) || ReturnFactionType(playerid) == FACTION_TYPE_POLICE)
	{
		itemid = PlayerInfo[playerid][E_CHARACTER_STORAGEITEM];

		strunpack(string, PropertyStorage[houseid][itemid][E_PSTORAGE_NAME]);

		if (response)
		{
			switch (listitem)
			{
				case 0:
				{
					if (PropertyStorage[houseid][itemid][E_PSTORAGE_QUANTITY] == 1)
					{
						new id = Inventory_Add(playerid, string, PropertyStorage[houseid][itemid][E_PSTORAGE_MODEL], 1);

						if (id == -1)
							return SendErrorMessage(playerid, "You don't have any inventory slots left.");

						Property_RemoveItem(houseid, string);

						Property_ShowItems(playerid, houseid);
					}
					else
					{
						new str[512];
						format(str, sizeof(str), "Item: %s (Quantity: %d)\n\nPlease enter the quantity that you wish to take for this item:", string, PropertyStorage[houseid][itemid][E_PSTORAGE_QUANTITY]);
						Dialog_Show(playerid, DialogPropertyTake, DIALOG_STYLE_INPUT, "Property Safe Take:", str, "Take", "Back");
					}
				}
				case 1:
				{
					new id = Inventory_GetItemID(playerid, string);

					if (id == -1) {
						Property_ShowItems(playerid, houseid);

						return SendErrorMessage(playerid, "You don't have anymore of this item to store!");
					}
					else if (InventoryInfo[playerid][id][E_INVENTORY_QUANTITY] == 1)
					{
						Property_AddItem(houseid, string, InventoryInfo[playerid][id][E_INVENTORY_MODEL]);
						Inventory_Remove(playerid, string);

						Property_ShowItems(playerid, houseid);
					}
					else if (InventoryInfo[playerid][id][E_INVENTORY_QUANTITY] > 1) {
						PlayerInfo[playerid][E_CHARACTER_LISTITEM] = id;

						new str[512];
						format(str, sizeof(str), "Item: %s (Quantity: %d)\n\nPlease enter the quantity that you wish to store for this item:", string, InventoryInfo[playerid][id][E_INVENTORY_QUANTITY]);
						Dialog_Show(playerid, DialogPropertyDeposit, DIALOG_STYLE_INPUT, "Property Safe Place:", str, "Place", "Back");
					}
				}
			}
		}
		else
		{
			Property_ShowItems(playerid, houseid);
		}
	}
	return 1;
}

Dialog:DialogPropertyDeposit(playerid, response, listitem, inputtext[])
{
	static
		houseid = -1,
		string[32];

	if ((houseid = IsPlayerInProperty(playerid)) != -1 && (PropertyInfo[houseid][E_PROPERTY_OWNERDBID] == PlayerInfo[playerid][E_CHARACTER_DBID]) || ReturnFactionType(playerid) == FACTION_TYPE_POLICE)
	{
		strunpack(string, InventoryInfo[playerid][PlayerInfo[playerid][E_CHARACTER_LISTITEM]][E_INVENTORY_ITEM]);

		if (response)
		{
			new amount = strval(inputtext);

			if (amount < 1 || amount > InventoryInfo[playerid][PlayerInfo[playerid][E_CHARACTER_LISTITEM]][E_INVENTORY_QUANTITY])
			{
				new str[512];
				format(str, sizeof(str), "Item: %s (Quantity: %d)\n\nPlease enter the quantity that you wish to store for this item:", string, InventoryInfo[playerid][PlayerInfo[playerid][E_CHARACTER_LISTITEM]][E_INVENTORY_QUANTITY]);
				return Dialog_Show(playerid, DialogPropertyDeposit, DIALOG_STYLE_INPUT, "Property Safe Place:", str, "Place", "Back");
			}

			Property_AddItem(houseid, string, InventoryInfo[playerid][PlayerInfo[playerid][E_CHARACTER_LISTITEM]][E_INVENTORY_MODEL], amount);
			Inventory_Remove(playerid, string, amount);

			Property_ShowItems(playerid, houseid);
		}
	}
	return 1;
}

Dialog:DialogPropertyTake(playerid, response, listitem, inputtext[])
{
	static
		houseid = -1,
		string[32];

	if ((houseid = IsPlayerInProperty(playerid)) != -1 && (PropertyInfo[houseid][E_PROPERTY_OWNERDBID] == PlayerInfo[playerid][E_CHARACTER_DBID]) || ReturnFactionType(playerid) == FACTION_TYPE_POLICE)
	{
		strunpack(string, PropertyStorage[houseid][PlayerInfo[playerid][E_CHARACTER_STORAGEITEM]][E_PSTORAGE_NAME]);

		if (response)
		{
			new amount = strval(inputtext);

			if (amount < 1 || amount > PropertyStorage[houseid][PlayerInfo[playerid][E_CHARACTER_STORAGEITEM]][E_PSTORAGE_QUANTITY])
			{
				new str[512];
				format(str, sizeof(str), "Item: %s (Quantity: %d)\n\nPlease enter the quantity that you wish to take for this item:", string, PropertyStorage[houseid][PlayerInfo[playerid][E_CHARACTER_LISTITEM]][E_PSTORAGE_QUANTITY]);
				return Dialog_Show(playerid, DialogPropertyTake, DIALOG_STYLE_INPUT, "Property Safe Take:", str, "Take", "Back");
			}

			new id = Inventory_Add(playerid, string, PropertyStorage[houseid][PlayerInfo[playerid][E_CHARACTER_STORAGEITEM]][E_PSTORAGE_MODEL], amount);

			if (id == -1)
				return SendErrorMessage(playerid, "You don't have any inventory slots left.");

			Property_RemoveItem(houseid, string, amount);
			
			Property_ShowItems(playerid, houseid);
		}
	}
	return 1;
}

Dialog:DialogShop(playerid, response, listitem, inputtext[])
{
	if(response)
	{
		switch(listitem)
		{
			case 0:
			{
				cmd_inventory(playerid, "");
			}
			case 1:
			{
				if(IsPlayerInRangeOfPoint(playerid, 2.0, BusinessPoint[0][E_BUSINESS_POINT_POS][0], BusinessPoint[0][E_BUSINESS_POINT_POS][1], BusinessPoint[0][E_BUSINESS_POINT_POS][2]) \
				|| IsPlayerInRangeOfPoint(playerid, 2.0, BusinessPoint[1][E_BUSINESS_POINT_POS][0], BusinessPoint[1][E_BUSINESS_POINT_POS][1], BusinessPoint[1][E_BUSINESS_POINT_POS][2])) //spraycan
				{
					ShowGeneralList(playerid, 1);
				}
				else if(IsPlayerInRangeOfPoint(playerid, 2.0, BusinessPoint[2][E_BUSINESS_POINT_POS][0], BusinessPoint[2][E_BUSINESS_POINT_POS][1], BusinessPoint[2][E_BUSINESS_POINT_POS][2]) \
				|| IsPlayerInRangeOfPoint(playerid, 2.0, BusinessPoint[3][E_BUSINESS_POINT_POS][0], BusinessPoint[3][E_BUSINESS_POINT_POS][1], BusinessPoint[3][E_BUSINESS_POINT_POS][2])) //cellphone
				{
					ShowGeneralList(playerid, 2);
				}
				else if(IsPlayerInRangeOfPoint(playerid, 2.0, BusinessPoint[6][E_BUSINESS_POINT_POS][0], BusinessPoint[6][E_BUSINESS_POINT_POS][1], BusinessPoint[6][E_BUSINESS_POINT_POS][2]) \
				|| IsPlayerInRangeOfPoint(playerid, 2.0, BusinessPoint[7][E_BUSINESS_POINT_POS][0], BusinessPoint[7][E_BUSINESS_POINT_POS][1], BusinessPoint[7][E_BUSINESS_POINT_POS][2])) //baseball
				{
					ShowGeneralList(playerid, 3);
				}
				else if(IsPlayerInRangeOfPoint(playerid, 2.0, BusinessPoint[4][E_BUSINESS_POINT_POS][0], BusinessPoint[4][E_BUSINESS_POINT_POS][1], BusinessPoint[4][E_BUSINESS_POINT_POS][2]) \
				|| IsPlayerInRangeOfPoint(playerid, 2.0, BusinessPoint[5][E_BUSINESS_POINT_POS][0], BusinessPoint[5][E_BUSINESS_POINT_POS][1], BusinessPoint[5][E_BUSINESS_POINT_POS][2])) // raw meat
				{
					ShowGeneralList(playerid, 4);
				}
				else if(IsPlayerInRangeOfPoint(playerid, 2.0, BusinessPoint[10][E_BUSINESS_POINT_POS][0], BusinessPoint[10][E_BUSINESS_POINT_POS][1], BusinessPoint[10][E_BUSINESS_POINT_POS][2]) \
				|| IsPlayerInRangeOfPoint(playerid, 2.0, BusinessPoint[11][E_BUSINESS_POINT_POS][0], BusinessPoint[11][E_BUSINESS_POINT_POS][1], BusinessPoint[11][E_BUSINESS_POINT_POS][2]) \
				|| IsPlayerInRangeOfPoint(playerid, 2.0, BusinessPoint[12][E_BUSINESS_POINT_POS][0], BusinessPoint[12][E_BUSINESS_POINT_POS][1], BusinessPoint[12][E_BUSINESS_POINT_POS][2]) \
				|| IsPlayerInRangeOfPoint(playerid, 2.0, BusinessPoint[13][E_BUSINESS_POINT_POS][0], BusinessPoint[13][E_BUSINESS_POINT_POS][1], BusinessPoint[13][E_BUSINESS_POINT_POS][2]) \ 
				|| IsPlayerInRangeOfPoint(playerid, 2.0, BusinessPoint[14][E_BUSINESS_POINT_POS][0], BusinessPoint[14][E_BUSINESS_POINT_POS][1], BusinessPoint[14][E_BUSINESS_POINT_POS][2]) \
				|| IsPlayerInRangeOfPoint(playerid, 2.0, BusinessPoint[15][E_BUSINESS_POINT_POS][0], BusinessPoint[15][E_BUSINESS_POINT_POS][1], BusinessPoint[15][E_BUSINESS_POINT_POS][2]) \
				|| IsPlayerInRangeOfPoint(playerid, 2.0, BusinessPoint[16][E_BUSINESS_POINT_POS][0], BusinessPoint[16][E_BUSINESS_POINT_POS][1], BusinessPoint[16][E_BUSINESS_POINT_POS][2])) //sprunk
				{
					ShowGeneralList(playerid, 5);
				}
				else if(IsPlayerInRangeOfPoint(playerid, 2.0, BusinessPoint[8][E_BUSINESS_POINT_POS][0], BusinessPoint[8][E_BUSINESS_POINT_POS][1], BusinessPoint[8][E_BUSINESS_POINT_POS][2])) //Knife
				{
					ShowGeneralList(playerid, 6);
				}
				else if(IsPlayerInRangeOfPoint(playerid, 2.0, BusinessPoint[9][E_BUSINESS_POINT_POS][0], BusinessPoint[9][E_BUSINESS_POINT_POS][1], BusinessPoint[9][E_BUSINESS_POINT_POS][2])) //Glove
				{
					ShowGeneralList(playerid, 7);
				}
			}
		}
	}
	return 1;
}

Dialog:DialogClerk(playerid, response, listitem, inputtext[])
{
	if(response)
	{
		switch(listitem)
		{
			case 0:
			{
				cmd_inventory(playerid, "");
			}
			case 1:
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
			case 2:
			{
				if(BusinessInfo[IsPlayerInBusiness(playerid)][E_BUSINESS_ROBBERYCASH] == true && BusinessInfo[IsPlayerInBusiness(playerid)][E_BUSINESS_CASH] >= 500)
				{
					new rand = random(100);
					new Cents = floatround(rand * 100, floatround_round);

					GiveMoney(playerid, Cents);
					BusinessInfo[IsPlayerInBusiness(playerid)][E_BUSINESS_CASH] -= rand;
					BusinessInfo[IsPlayerInBusiness(playerid)][E_BUSINESS_ROBBERYCASH] = false;
					BusinessRefresh(IsPlayerInBusiness(playerid));
					SendPropertyMessage(playerid, "[BUSINESS] You've got money $%s from take cash money on cashiers.", FormatMoney(Cents));
				}
			}
		}
	}
	return 1;
}
Dialog:DialogGeneral1(playerid, response, listitem, inputtext[])
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
			
				SendInventoryMessage(playerid, "You bought a cellphone for $%s don't forget to pay at the clerk.", FormatMoney(BusinessInfo[businessid][E_BUSINESS_PRODUCTS][1]));

				PlayerInfo[playerid][E_CHARACTER_PURCHASE] += BusinessInfo[businessid][E_BUSINESS_PRODUCTS][1];
				BusinessInfo[businessid][E_BUSINESS_STOCK]--;
				Inventory_Add(playerid, "Cellphone", 18867, 1);

				ApplyAnimation(playerid, "MISC", "GRAB_R", 4.1, 0, 0, 0, 0, 0, 0);
			}
			case 1:
			{
				if(Inventory_Count(playerid, "Radio"))
					return SendErrorMessage(playerid, "You already own a radio.");
			
				if(BusinessInfo[businessid][E_BUSINESS_PRODUCTS][2] > PlayerInfo[playerid][E_CHARACTER_MONEY])
					return SendErrorMessage(playerid, "You can't afford a radio.");
			
				SendInventoryMessage(playerid, "You bought a radio for $%s don't forget to pay at the clerk.", FormatMoney(BusinessInfo[businessid][E_BUSINESS_PRODUCTS][2]));

				PlayerInfo[playerid][E_CHARACTER_PURCHASE] += BusinessInfo[businessid][E_BUSINESS_PRODUCTS][2];
				BusinessInfo[businessid][E_BUSINESS_STOCK]--;
				Inventory_Add(playerid, "Radio", 19942, 1);

				ApplyAnimation(playerid, "MISC", "GRAB_R", 4.1, 0, 0, 0, 0, 0, 0);
			}
		}
	}
	return 1;
}

Dialog:DialogGeneral2(playerid, response, listitem, inputtext[])
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
			
				SendInventoryMessage(playerid, "You bought a spikebat for $%s don't forget to pay at the clerk.", FormatMoney(BusinessInfo[businessid][E_BUSINESS_PRODUCTS][1]));

				PlayerInfo[playerid][E_CHARACTER_PURCHASE] += BusinessInfo[businessid][E_BUSINESS_PRODUCTS][1];

				BusinessInfo[businessid][E_BUSINESS_STOCK]--;
				Inventory_Add(playerid, "Spike Bat", 2045, 1);

				ApplyAnimation(playerid, "MISC", "GRAB_R", 4.1, 0, 0, 0, 0, 0, 0);
			}
			case 1:
			{
				if(Inventory_Count(playerid, "Cutscene Bat"))
					return SendErrorMessage(playerid, "You already own a wooden.");
			
				if(BusinessInfo[businessid][E_BUSINESS_PRODUCTS][2] > PlayerInfo[playerid][E_CHARACTER_MONEY])
					return SendErrorMessage(playerid, "You can't afford a wooden.");
			
				SendInventoryMessage(playerid, "You bought a wooden for $%s don't forget to pay at the clerk.", FormatMoney(BusinessInfo[businessid][E_BUSINESS_PRODUCTS][2]));

				PlayerInfo[playerid][E_CHARACTER_PURCHASE] += BusinessInfo[businessid][E_BUSINESS_PRODUCTS][2];
				BusinessInfo[businessid][E_BUSINESS_STOCK]--;
				Inventory_Add(playerid, "Cutscene Bat", 19914, 1);

				ApplyAnimation(playerid, "MISC", "GRAB_R", 4.1, 0, 0, 0, 0, 0, 0);
			}
			case 2:
			{
				if(Inventory_Count(playerid, "Baseball Bat"))
					return SendErrorMessage(playerid, "You already own a nailbat.");
			
				if(BusinessInfo[businessid][E_BUSINESS_PRODUCTS][3] > PlayerInfo[playerid][E_CHARACTER_MONEY])
					return SendErrorMessage(playerid, "You can't afford a nailbat.");
			
				SendInventoryMessage(playerid, "You bought a nailbat for $%s don't forget to pay at the clerk.", FormatMoney(BusinessInfo[businessid][E_BUSINESS_PRODUCTS][3]));

				PlayerInfo[playerid][E_CHARACTER_PURCHASE] += BusinessInfo[businessid][E_BUSINESS_PRODUCTS][3];
				BusinessInfo[businessid][E_BUSINESS_STOCK]--;
				Inventory_Add(playerid, "Baseball Bat", 336, 1);

				ApplyAnimation(playerid, "MISC", "GRAB_R", 4.1, 0, 0, 0, 0, 0, 0);
			}
		}
	}
	return 1;
}

Dialog:DialogGeneral3(playerid, response, listitem, inputtext[])
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
			
				SendInventoryMessage(playerid, "You bought a raw meat for $%s don't forget to pay at the clerk.", FormatMoney(BusinessInfo[businessid][E_BUSINESS_PRODUCTS][1]));

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
			
				SendInventoryMessage(playerid, "You bought a parsley for $%s don't forget to pay at the clerk.", FormatMoney(BusinessInfo[businessid][E_BUSINESS_PRODUCTS][2]));

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
			
				SendInventoryMessage(playerid, "You bought a mint for $%s don't forget to pay at the clerk.", FormatMoney(BusinessInfo[businessid][E_BUSINESS_PRODUCTS][3]));

				PlayerInfo[playerid][E_CHARACTER_PURCHASE] += BusinessInfo[businessid][E_BUSINESS_PRODUCTS][3];
				BusinessInfo[businessid][E_BUSINESS_STOCK]--;
				Inventory_Add(playerid, "Mint", 19570, 1);

				ApplyAnimation(playerid, "MISC", "GRAB_R", 4.1, 0, 0, 0, 0, 0, 0);
			}
			case 3:
			{
				if(Inventory_Count(playerid, "Oregano") >= 5)
					return SendErrorMessage(playerid, "You may only hold up to 5 oregano.");
			
				if(BusinessInfo[businessid][E_BUSINESS_PRODUCTS][4] > PlayerInfo[playerid][E_CHARACTER_MONEY])
					return SendErrorMessage(playerid, "You can't afford a oregano.");
			
				SendInventoryMessage(playerid, "You bought a oregano for $%s don't forget to pay at the clerk.", FormatMoney(BusinessInfo[businessid][E_BUSINESS_PRODUCTS][4]));

				PlayerInfo[playerid][E_CHARACTER_PURCHASE] += BusinessInfo[businessid][E_BUSINESS_PRODUCTS][4];
				BusinessInfo[businessid][E_BUSINESS_STOCK]--;
				Inventory_Add(playerid, "Oregano", 19570, 1);

				ApplyAnimation(playerid, "MISC", "GRAB_R", 4.1, 0, 0, 0, 0, 0, 0);
			}
			case 4:
			{
				if(Inventory_Count(playerid, "Baking Soda") >= 5)	
					return SendErrorMessage(playerid, "You may only hold up to 5 baking soda.");
			
				if(BusinessInfo[businessid][E_BUSINESS_PRODUCTS][5] > PlayerInfo[playerid][E_CHARACTER_MONEY])
					return SendErrorMessage(playerid, "You can't afford a baking soda.");
			
				SendInventoryMessage(playerid, "You bought a baking soda for $%s don't forget to pay at the clerk.", FormatMoney(BusinessInfo[businessid][E_BUSINESS_PRODUCTS][5]));

				PlayerInfo[playerid][E_CHARACTER_PURCHASE] += BusinessInfo[businessid][E_BUSINESS_PRODUCTS][5];
				BusinessInfo[businessid][E_BUSINESS_STOCK]--;
				
				Inventory_Add(playerid, "Baking Soda", 19570, 1);

				ApplyAnimation(playerid, "MISC", "GRAB_R", 4.1, 0, 0, 0, 0, 0, 0);
			}
		}
	}
	return 1;
}

Dialog:DialogGeneral4(playerid, response, listitem, inputtext[])
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
			
				SendInventoryMessage(playerid, "You bought a spraycan for $%s don't forget to pay at the clerk.", FormatMoney(BusinessInfo[businessid][E_BUSINESS_PRODUCTS][1]));

				PlayerInfo[playerid][E_CHARACTER_PURCHASE] += BusinessInfo[businessid][E_BUSINESS_PRODUCTS][1];

				BusinessInfo[businessid][E_BUSINESS_STOCK]--;
				Inventory_Add(playerid, "Spraycan", 365, 1);

				ApplyAnimation(playerid, "MISC", "GRAB_R", 4.1, 0, 0, 0, 0, 0, 0);
			}
			case 1:
			{
				if(Inventory_Count(playerid, "Gascan") >= 5)
					return SendErrorMessage(playerid, "You may only hold up to 5 gasoline cans.");
					
				if(BusinessInfo[businessid][E_BUSINESS_PRODUCTS][3] > PlayerInfo[playerid][E_CHARACTER_MONEY])
					return SendErrorMessage(playerid, "You can't afford a gasoline.");
			
				SendInventoryMessage(playerid, "You bought a gasoline for $%s don't forget to pay at the clerk.", FormatMoney(BusinessInfo[businessid][E_BUSINESS_PRODUCTS][2]));

				PlayerInfo[playerid][E_CHARACTER_PURCHASE] += BusinessInfo[businessid][E_BUSINESS_PRODUCTS][2];
				BusinessInfo[businessid][E_BUSINESS_STOCK]--;
				Inventory_Add(playerid, "Gascan", 1650, 1);

				ApplyAnimation(playerid, "MISC", "GRAB_R", 4.1, 0, 0, 0, 0, 0, 0);
			}
			case 2:
			{
				if(Inventory_Count(playerid, "Repair Kits"))
					return SendErrorMessage(playerid, "You already own a repairkit.");
					
				if(BusinessInfo[businessid][E_BUSINESS_PRODUCTS][4] > PlayerInfo[playerid][E_CHARACTER_MONEY])
					return SendErrorMessage(playerid, "You can't afford a repairkit.");
			
				SendInventoryMessage(playerid, "You bought a repairkit for $%s don't forget to pay at the clerk.", FormatMoney(BusinessInfo[businessid][E_BUSINESS_PRODUCTS][3]));

				PlayerInfo[playerid][E_CHARACTER_PURCHASE] += BusinessInfo[businessid][E_BUSINESS_PRODUCTS][4];
				BusinessInfo[businessid][E_BUSINESS_STOCK]--;
				Inventory_Add(playerid, "Repair Kits", 1650, 1);

				ApplyAnimation(playerid, "MISC", "GRAB_R", 4.1, 0, 0, 0, 0, 0, 0);
			}
			case 3:
			{
				if(Inventory_Count(playerid, "Screwdriver"))
					return SendErrorMessage(playerid, "You already own a Screwdriver.");
					
				if(BusinessInfo[businessid][E_BUSINESS_PRODUCTS][1] > PlayerInfo[playerid][E_CHARACTER_MONEY])
					return SendErrorMessage(playerid, "You can't afford a Screwdriver.");
			
				SendInventoryMessage(playerid, "You bought a Screwdriver for $%s don't forget to pay at the clerk.", FormatMoney(BusinessInfo[businessid][E_BUSINESS_PRODUCTS][1]));

				PlayerInfo[playerid][E_CHARACTER_PURCHASE] += BusinessInfo[businessid][E_BUSINESS_PRODUCTS][1];
				BusinessInfo[businessid][E_BUSINESS_STOCK]--;
				Inventory_Add(playerid, "Screwdriver", 18644, 1);

				ApplyAnimation(playerid, "MISC", "GRAB_R", 4.1, 0, 0, 0, 0, 0, 0);
			}
		}
	}
	return 1;
}

Dialog:DialogGeneral5(playerid, response, listitem, inputtext[])
{
	if(response)
	{
		new businessid = IsPlayerInBusiness(playerid);
		switch(listitem)
		{
			case 0:
			{
				if(Inventory_Count(playerid, "Sprunk") >= 5)	
					return SendErrorMessage(playerid, "You may only hold up to 5 sprunk.");
			
				if(200 > PlayerInfo[playerid][E_CHARACTER_MONEY])
					return SendErrorMessage(playerid, "You can't afford a sprunk.");
			
				SendInventoryMessage(playerid, "You bought a sprunk for $2.");

				PlayerInfo[playerid][E_CHARACTER_PURCHASE] += 200; 
				BusinessInfo[businessid][E_BUSINESS_STOCK]--;
				Inventory_Add(playerid, "Sprunk", 2601, 1);

				ApplyAnimation(playerid, "MISC", "GRAB_R", 4.1, 0, 0, 0, 0, 0, 0);
			}
			case 1:
			{
				if(Inventory_Count(playerid, "Pisswasher") >= 5)	
					return SendErrorMessage(playerid, "You may only hold up to 5 sprunk.");
			
				if(500 > PlayerInfo[playerid][E_CHARACTER_MONEY])
					return SendErrorMessage(playerid, "You can't afford a sprunk.");
			
				SendInventoryMessage(playerid, "You bought a sprunk for $2.");

				PlayerInfo[playerid][E_CHARACTER_PURCHASE] += 500; 
				BusinessInfo[businessid][E_BUSINESS_STOCK]--;
				Inventory_Add(playerid, "Pisswasher", 1484, 1);

				ApplyAnimation(playerid, "MISC", "GRAB_R", 4.1, 0, 0, 0, 0, 0, 0);
			}
		}
	}
	return 1;
}

Dialog:DialogGeneral6(playerid, response, listitem, inputtext[])
{
	if(response)
	{
		new businessid = IsPlayerInBusiness(playerid);
		switch(listitem)
		{
			case 0:
			{
				if(Inventory_Count(playerid, "Knife"))
					return SendErrorMessage(playerid, "You already own a Knife.");
			
				if(BusinessInfo[businessid][E_BUSINESS_PRODUCTS][1] > PlayerInfo[playerid][E_CHARACTER_MONEY])
					return SendErrorMessage(playerid, "You can't afford a Knife.");
			
				SendInventoryMessage(playerid, "You bought a Knife for $%s don't forget to pay at the clerk.", FormatMoney(BusinessInfo[businessid][E_BUSINESS_PRODUCTS][1]));

				PlayerInfo[playerid][E_CHARACTER_PURCHASE] += BusinessInfo[businessid][E_BUSINESS_PRODUCTS][1];

				BusinessInfo[businessid][E_BUSINESS_STOCK]--;
				Inventory_Add(playerid, "Knife", 335, 1);

				ApplyAnimation(playerid, "MISC", "GRAB_R", 4.1, 0, 0, 0, 0, 0, 0);
			}
			case 1:
			{
				if(Inventory_Count(playerid, "Marcos Knife"))
					return SendErrorMessage(playerid, "You already own a Marcos Knife.");
			
				if(BusinessInfo[businessid][E_BUSINESS_PRODUCTS][2] > PlayerInfo[playerid][E_CHARACTER_MONEY])
					return SendErrorMessage(playerid, "You can't afford a Marcos Knife.");
			
				SendInventoryMessage(playerid, "You bought a Marcos Knife for $%s don't forget to pay at the clerk.", FormatMoney(BusinessInfo[businessid][E_BUSINESS_PRODUCTS][2]));

				PlayerInfo[playerid][E_CHARACTER_PURCHASE] += BusinessInfo[businessid][E_BUSINESS_PRODUCTS][2];
				BusinessInfo[businessid][E_BUSINESS_STOCK]--;
				Inventory_Add(playerid, "Marcos Knife", 19583, 1);

				ApplyAnimation(playerid, "MISC", "GRAB_R", 4.1, 0, 0, 0, 0, 0, 0);
			}
			case 2:
			{
				if(Inventory_Count(playerid, "Hammer"))
					return SendErrorMessage(playerid, "You already own a Hammer.");
			
				if(BusinessInfo[businessid][E_BUSINESS_PRODUCTS][3] > PlayerInfo[playerid][E_CHARACTER_MONEY])
					return SendErrorMessage(playerid, "You can't afford a Hammer.");
			
				SendInventoryMessage(playerid, "You bought a Hammer for $%s don't forget to pay at the clerk.", FormatMoney(BusinessInfo[businessid][E_BUSINESS_PRODUCTS][3]));

				PlayerInfo[playerid][E_CHARACTER_PURCHASE] += BusinessInfo[businessid][E_BUSINESS_PRODUCTS][3];
				BusinessInfo[businessid][E_BUSINESS_STOCK]--;
				Inventory_Add(playerid, "Hammer", 18635, 1);

				ApplyAnimation(playerid, "MISC", "GRAB_R", 4.1, 0, 0, 0, 0, 0, 0);
			}
			case 3:
			{
				if(Inventory_Count(playerid, "Wrench"))
					return SendErrorMessage(playerid, "You already own a Wrench.");
			
				if(BusinessInfo[businessid][E_BUSINESS_PRODUCTS][4] > PlayerInfo[playerid][E_CHARACTER_MONEY])
					return SendErrorMessage(playerid, "You can't afford a Wrench.");
			
				SendInventoryMessage(playerid, "You bought a Wrench for $%s don't forget to pay at the clerk.", FormatMoney(BusinessInfo[businessid][E_BUSINESS_PRODUCTS][4]));

				PlayerInfo[playerid][E_CHARACTER_PURCHASE] += BusinessInfo[businessid][E_BUSINESS_PRODUCTS][4];
				BusinessInfo[businessid][E_BUSINESS_STOCK]--;
				Inventory_Add(playerid, "Wrench", 18633, 1);

				ApplyAnimation(playerid, "MISC", "GRAB_R", 4.1, 0, 0, 0, 0, 0, 0);
			}
			case 4:
			{
				if(Inventory_Count(playerid, "Broom"))
					return SendErrorMessage(playerid, "You already own a Broom.");
			
				if(BusinessInfo[businessid][E_BUSINESS_PRODUCTS][5] > PlayerInfo[playerid][E_CHARACTER_MONEY])
					return SendErrorMessage(playerid, "You can't afford a Broom.");
			
				SendInventoryMessage(playerid, "You bought a Broom for $%s don't forget to pay at the clerk.", FormatMoney(BusinessInfo[businessid][E_BUSINESS_PRODUCTS][5]));

				PlayerInfo[playerid][E_CHARACTER_PURCHASE] += BusinessInfo[businessid][E_BUSINESS_PRODUCTS][5];
				BusinessInfo[businessid][E_BUSINESS_STOCK]--;
				Inventory_Add(playerid, "Broom", 19622, 1);

				ApplyAnimation(playerid, "MISC", "GRAB_R", 4.1, 0, 0, 0, 0, 0, 0);
			}
		}
	}
	return 1;
}

Dialog:DialogGeneral7(playerid, response, listitem, inputtext[])
{
	if(response)
	{
		new businessid = IsPlayerInBusiness(playerid);
		switch(listitem)
		{
			case 0:
			{
				if(Inventory_Count(playerid, "Glove"))
					return SendErrorMessage(playerid, "You already own a Glove.");
			
				if(BusinessInfo[businessid][E_BUSINESS_PRODUCTS][1] > PlayerInfo[playerid][E_CHARACTER_MONEY])
					return SendErrorMessage(playerid, "You can't afford a Glove.");
			
				SendInventoryMessage(playerid, "You bought a Glove for $%s don't forget to pay at the clerk.", FormatMoney(BusinessInfo[businessid][E_BUSINESS_PRODUCTS][1]));

				PlayerInfo[playerid][E_CHARACTER_PURCHASE] += BusinessInfo[businessid][E_BUSINESS_PRODUCTS][1];

				BusinessInfo[businessid][E_BUSINESS_STOCK]--;
				Inventory_Add(playerid, "Glove", 19556, 1);

				ApplyAnimation(playerid, "MISC", "GRAB_R", 4.1, 0, 0, 0, 0, 0, 0);
			}
		}
	}
	return 1;
}

Dialog:DialogBarstore(playerid, response, listitem, inputtext[])
{
	if(response)
	{
		new businessid = IsPlayerInBusiness(playerid);
		switch(listitem)
		{
			case 0:
			{
				if(Inventory_Count(playerid, "Pisswasher") >= 5)
					return SendErrorMessage(playerid, "You may only hold up to 5 Pisswasher.");
			
				if(BusinessInfo[businessid][E_BUSINESS_PRODUCTS][1] > PlayerInfo[playerid][E_CHARACTER_MONEY])
					return SendErrorMessage(playerid, "You can't afford a Pisswasher.");
			
				SendPropertyMessage(playerid, "[BUSINESS] You bought a Pisswasher for $%s.", FormatMoney(BusinessInfo[businessid][E_BUSINESS_PRODUCTS][1]));
				GiveMoney(playerid, BusinessInfo[businessid][E_BUSINESS_PRODUCTS][1]); 
				
				BusinessInfo[businessid][E_BUSINESS_STOCK]--;
				BusinessInfo[businessid][E_BUSINESS_CASH] += BusinessInfo[businessid][E_BUSINESS_PRODUCTS][1];
				Inventory_Add(playerid, "Pisswasher", 1486, 1);
			}
			case 1:
			{
				if(Inventory_Count(playerid, "Pisswasher") >= 5)
					return SendErrorMessage(playerid, "You may only hold up to 5 Pisswasher.");
			
				if(BusinessInfo[businessid][E_BUSINESS_PRODUCTS][2] > PlayerInfo[playerid][E_CHARACTER_MONEY])
					return SendErrorMessage(playerid, "You can't afford a Pisswasher.");

			
				SendPropertyMessage(playerid, "[BUSINESS] You bought a Pisswasher for $%s.", FormatMoney(BusinessInfo[businessid][E_BUSINESS_PRODUCTS][2]));
				GiveMoney(playerid, -BusinessInfo[businessid][E_BUSINESS_PRODUCTS][2]); 
				
				BusinessInfo[businessid][E_BUSINESS_STOCK]--;
				BusinessInfo[businessid][E_BUSINESS_CASH] += BusinessInfo[businessid][E_BUSINESS_PRODUCTS][2];
				Inventory_Add(playerid, "Pisswasher", 1486, 1);
			}
			case 2:
			{
				if(Inventory_Count(playerid, "Pisswasher") >= 5)
					return SendErrorMessage(playerid, "You may only hold up to 5 Pisswasher.");
			
				if(BusinessInfo[businessid][E_BUSINESS_PRODUCTS][3] > PlayerInfo[playerid][E_CHARACTER_MONEY])
					return SendErrorMessage(playerid, "You can't afford a Pisswasher.");
			
				SendPropertyMessage(playerid, "[BUSINESS] You bought a Pisswasher for $%s.", FormatMoney(BusinessInfo[businessid][E_BUSINESS_PRODUCTS][3]));
				GiveMoney(playerid, -BusinessInfo[businessid][E_BUSINESS_PRODUCTS][3]); 
				
				BusinessInfo[businessid][E_BUSINESS_STOCK]--;
				BusinessInfo[businessid][E_BUSINESS_CASH] += BusinessInfo[businessid][E_BUSINESS_PRODUCTS][3];
				Inventory_Add(playerid, "Pisswasher", 1486, 1);
			}
		}
	}
	return 1;
}

Dialog:DialogBarberstore(playerid, response, listitem, inputtext[])
{
	if(response)
	{
		if(250 > PlayerInfo[playerid][E_CHARACTER_MONEY])
		{
			ApplyDynamicActorAnimation(BusinessInfo[IsPlayerInBusiness(playerid)][E_BUSINESS_ACTOR], "HAIRCUTS", "BRB_Cut_Out", 4.1, 0, 0, 0, 0, 0);
			ApplyAnimation(playerid, "HAIRCUTS", "BRB_Sit_Out", 4.1, 0, 0, 0, 0, 0, 0);
			SetTimerEx("ExitHairCut", 1000, false, "i", playerid);
			return SendErrorMessage(playerid, "You can't afford a clothes.");
		}

		if(BusinessInfo[IsPlayerInBusiness(playerid)][E_BUSINESS_STOCK] < 1)
		{
			ApplyDynamicActorAnimation(BusinessInfo[IsPlayerInBusiness(playerid)][E_BUSINESS_ACTOR], "HAIRCUTS", "BRB_Cut_Out", 4.1, 0, 0, 0, 0, 0);
			ApplyAnimation(playerid, "HAIRCUTS", "BRB_Sit_Out", 4.1, 0, 0, 0, 0, 0, 0);
			SetTimerEx("ExitHairCut", 1000, false, "i", playerid);
			return SendErrorMessage(playerid, "This business is out of stock");
		}

		if(GetPlayerFreeToySlot(playerid) == -1)
		{
			ApplyDynamicActorAnimation(BusinessInfo[IsPlayerInBusiness(playerid)][E_BUSINESS_ACTOR], "HAIRCUTS", "BRB_Cut_Out", 4.1, 0, 0, 0, 0, 0);
			ApplyAnimation(playerid, "HAIRCUTS", "BRB_Sit_Out", 4.1, 0, 0, 0, 0, 0, 0);
			SetTimerEx("ExitHairCut", 1000, false, "i", playerid);
			return SendErrorMessage(playerid, "You already have full slot of Accessory!");
		}

		SetTimerEx("StartHairCut", 500, false, "ii", playerid, g_aHaircut[listitem]);
	}
	else
	{
		SetCameraBehindPlayer(playerid);
		TogglePlayerControllable(playerid, true);
	}
	return 1;
}

Dialog:DialogBuyskin(playerid, response, listitem, inputtext[])
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

				if(PlayerInfo[playerid][E_CHARACTER_GENDER] == 1)
				{
					ShowSelectionModel(playerid, SELECT_MALESKIN);
				}
				else if(PlayerInfo[playerid][E_CHARACTER_GENDER] == 2)
				{
					ShowSelectionModel(playerid, SELECT_FEMALESKIN);
				}
			}
			case 1:
			{
				ShowSelectionModel(playerid, SELECT_ACCESSORIES);
			}
		}
	}
	return 1;
}

Dialog:DialogDealership(playerid, response, listitem, inputtext[])
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
		
		format(caption, 60, "%s - {33AA33}%s:", g_aDealershipData[i][E_DEALERSHIP_MODEL], FormatMoney(DealershipTotalCost[playerid])); 
		strcat(str, "Colors\n");
		strcat(str, "{FFFF00}Purchase Vehicle\n"); 
		
		PauseAC(playerid);
		TogglePlayerControllable(playerid, false); 
		
		DealershipPlayerCar[playerid] = CreateVehicle(g_aDealershipData[i][E_DEALERSHIP_MODELID], g_aDealershipData[i][E_DEALERSHIP_SPAWNX], g_aDealershipData[i][E_DEALERSHIP_SPAWNY], g_aDealershipData[i][E_DEALERSHIP_SPAWNZ], g_aDealershipData[i][E_DEALERSHIP_SPAWNA], 0, 0, -1);
		PlayerPutIntoVehicle(playerid, DealershipPlayerCar[playerid], 0); 
		
		Dialog_Show(playerid, DialogDealerAppend, DIALOG_STYLE_LIST, caption, str, "Append", "<<");
	}
	return 1;
}

Dialog:DialogDealerAppend(playerid, response, listitem, inputtext[])
{
	new
		caption[60],
		str[400]; 
	
	format(caption, 60, "%s - {33AA33}%s:", g_aDealershipData[SubDealershipHolder[playerid]][E_DEALERSHIP_MODEL], FormatMoney(DealershipTotalCost[playerid])); 
	
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
				
				Dialog_Show(playerid, DialogDealerMenu, DIALOG_STYLE_LIST, caption, str, "Select", "<<"); 
			}
			case 1: //Purchase
			{
				new dstr[128], vehicleid = GetPlayerVehicleID(playerid);
				
				format(dstr, sizeof(dstr), "Models:\t%s\n", ReturnVehicleName(vehicleid));
				strcat(str, dstr);
				format(dstr, sizeof(dstr), "Price:\t{FFFFFF}{33AA33}$%s{ffffff}\n", FormatMoney(floatround(g_aDealershipData[SubDealershipHolder[playerid]][E_DEALERSHIP_PRICE] * 100, floatround_round)));
				strcat(str, dstr);
				format(dstr, sizeof(dstr), "Max Speed:\t{FFFFFF}%.1f\n", GetVehicleTopSpeed(DealershipPlayerCar[playerid])); 
				strcat(str, dstr); 
				Dialog_Show(playerid, DialogDealerConfirm, DIALOG_STYLE_MSGBOX, caption, str, "Edit", "Checkout"); 
				return 1;
			}
		}
	}
	else ConfirmDialog(playerid, "Confirmation", "Are you sure you want to exit?", "OnPlayerExitDealership"); 
	return 1;
}

Dialog:DialogDealerMenu(playerid, response, listitem, inputtext[])
{
	new
		caption[60],
		str[3200];
	
	format(caption, 60, "%s - {33AA33}%s:", g_aDealershipData[SubDealershipHolder[playerid]][E_DEALERSHIP_MODEL], FormatMoney(DealershipTotalCost[playerid])); 

	if(response)
	{
		switch(listitem)
		{
			case 0:
			{
				
				for (new colorid; colorid != sizeof g_VehicleColors; colorid++)
				{
					format(str, sizeof str, "%s{%06x}%03d%s", str, g_VehicleColors[colorid] >>> 8, colorid, !((colorid + 1) % 16) ? ("\n") : (" "));
				}
				Dialog_Show(playerid, DialogDealerColor1, DIALOG_STYLE_INPUT, caption, str, "Select", "<<");  
			}
			case 1:
			{
				for (new colorid; colorid != sizeof g_VehicleColors; colorid++)
				{
					format(str, sizeof str, "%s{%06x}%03d%s", str, g_VehicleColors[colorid] >>> 8, colorid, !((colorid + 1) % 16) ? ("\n") : (" "));
				}
				Dialog_Show(playerid, DialogDealerColor2, DIALOG_STYLE_INPUT, caption, str, "Select", "<<"); 
			}
		}
	}
	else return ShowDealerAppend(playerid);
	return 1;
}

Dialog:DialogDealerColor1(playerid, response, listitem, inputtext[])
{
	new
		caption[60],
		str[3200],
		color1;
	
	format(caption, 60, "%s - {33AA33}%s:", g_aDealershipData[SubDealershipHolder[playerid]][E_DEALERSHIP_MODEL], FormatMoney(DealershipTotalCost[playerid])); 
	
	if(response)
	{
		if(!IsNumeric(inputtext))
		{
			for (new colorid; colorid != sizeof g_VehicleColors; colorid++)
			{
				format(str, sizeof str, "%s{%06x}%03d%s", str, g_VehicleColors[colorid] >>> 8, colorid, !((colorid + 1) % 16) ? ("\n") : (" "));
			}
			return Dialog_Show(playerid, DialogDealerColor1, DIALOG_STYLE_INPUT, caption, str, "Select", "<<");  
		}
	
		color1 = strval(inputtext);
		
		if(color1 > 255 || color1 < 0)
		{
			for (new colorid; colorid != sizeof g_VehicleColors; colorid++)
			{
				format(str, sizeof str, "%s{%06x}%03d%s", str, g_VehicleColors[colorid] >>> 8, colorid, !((colorid + 1) % 16) ? ("\n") : (" "));
			}
			return Dialog_Show(playerid, DialogDealerColor1, DIALOG_STYLE_INPUT, caption, str, "Select", "<<");  
		}
		
		PauseAC(playerid);
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
				
		Dialog_Show(playerid, DialogDealerMenu, DIALOG_STYLE_LIST, caption, str, "Select", "<<"); 
	}
	return 1;
}

Dialog:DialogDealerColor2(playerid, response, listitem, inputtext[])
{
	new
		caption[60],
		str[3200],
		color2
	;
	
	format(caption, 60, "%s - {33AA33}%s:", g_aDealershipData[SubDealershipHolder[playerid]][E_DEALERSHIP_MODEL], FormatMoney(DealershipTotalCost[playerid])); 
	
	if(response)
	{
		if(!IsNumeric(inputtext))
		{
			for (new colorid; colorid != sizeof g_VehicleColors; colorid++)
			{
				format(str, sizeof str, "%s{%06x}%03d%s", str, g_VehicleColors[colorid] >>> 8, colorid, !((colorid + 1) % 16) ? ("\n") : (" "));
			}
			return Dialog_Show(playerid, DialogDealerColor2, DIALOG_STYLE_INPUT, caption, str, "Select", "<<");  
		}
	
		color2 = strval(inputtext);
		
		if(color2 > 255 || color2 < 0)
		{
			for (new colorid; colorid != sizeof g_VehicleColors; colorid++)
			{
				format(str, sizeof str, "%s{%06x}%03d%s", str, g_VehicleColors[colorid] >>> 8, colorid, !((colorid + 1) % 16) ? ("\n") : (" "));
			}
			return Dialog_Show(playerid, DialogDealerColor2, DIALOG_STYLE_INPUT, caption, str, "Select", "<<");  
		}
		
		PauseAC(playerid);
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
				
		Dialog_Show(playerid, DialogDealerMenu, DIALOG_STYLE_LIST, caption, str, "Select", "<<"); 
	}
	return 1;
}

Dialog:DialogDealerConfirm(playerid, response, listitem, inputtext[])
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
		
		PauseAC(playerid);
		GetVehiclePos(DealershipPlayerCar[playerid], x, y, z);
		GetVehicleZAngle(DealershipPlayerCar[playerid], a);
		
		randset[0] = random(sizeof(possible_vehicle_plates)); 
		randset[1] = random(sizeof(possible_vehicle_plates)); 
		randset[2] = random(sizeof(possible_vehicle_plates)); 
		
		format(plates, 32, "%d%s%s%s%d%d%d", random(9), possible_vehicle_plates[randset[0]], possible_vehicle_plates[randset[1]], possible_vehicle_plates[randset[2]], random(9), random(9)); 
		GiveMoney(playerid, -DealershipTotalCost[playerid]);
		
		ShowPlayerPlates(playerid, plates); 
		
		mysql_format(ourConnection, insert, sizeof(insert), "INSERT INTO vehicles (VehicleOwnerDBID, VehicleModel, VehicleParkPosX, VehicleParkPosY, VehicleParkPosZ, VehicleParkPosA, VehicleColor1, VehicleColor2) VALUES(%i, %i, %f, %f, %f, %f, %i, %i)",
			PlayerInfo[playerid][E_CHARACTER_DBID], g_aDealershipData[SubDealershipHolder[playerid]][E_DEALERSHIP_MODELID], x, y, z, a, DealershipCarColors[playerid][0], DealershipCarColors[playerid][1]); 
			
		mysql_pquery(ourConnection, insert, "OnPlayerVehiclePurchase", "iisffff", playerid, idx, plates, x, y, z, a);
		
		PlayerPurchasingVehicle[playerid] = true; 
		TogglePlayerControllable(playerid, true);
	}
	return 1;
}

Dialog:DialogPaySpray(playerid, response, listitem, inputtext[])
{
	if(response)
	{
		new vehicleid = IsPlayerNearVehicle(playerid);
		new Float:x, Float:y, Float:z;
		GetPlayerPos(playerid, x, y, z);
		TogglePlayerControllable(playerid, false);
		ApplyAnimation(playerid, "BOMBER", "BOM_Plant", 4.1, 1, 0, 0, 0, 0, 1);

		PlayerInfo[playerid][E_CHARACTER_LOADINGDISPLAY] = Create3DTextLabel("Loading modifications process\n(( |------ ))", COLOR_3DTEXT, x, y, z, 25.0, 0, 1);
		PlayerInfo[playerid][E_CHARACTER_LOADINGCOUNT] = 1;

		PlayerInfo[playerid][E_CHARACTER_LOADING] = true; 
		PlayerInfo[playerid][E_CHARACTER_LOADINGTIMER] = SetTimerEx("modifications", 2500, true, "iii", playerid, vehicleid, SubVehicleComponentArr[playerid][listitem]);
	}
	return 1;
}