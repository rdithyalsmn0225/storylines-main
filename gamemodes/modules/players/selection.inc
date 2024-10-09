SetupCharacterSelection(playerid)
{
	new str[512], str1[512];

	/*=====[CHARACTERS SELECTION]======*/
	if(characterSelection[playerid])
	{
		if(PlayerInfo[playerid][E_CHARACTER_SELECTCHAR] == -1) 
		{
			PlayerInfo[playerid][E_CHARACTER_SELECTCHAR] = 0;
		}
		
		if(PlayerInfo[playerid][E_CHARACTER_SELECTCHAR] == 0) 
		{
			InterpolateCameraPos(playerid, 2390.306640, -1425.533081, 32.989219, 2404.556640, -1384.927124, 25.295658, 5000, 1);
			InterpolateCameraLookAt(playerid, 2391.055175, -1421.735839, 31.978948, 2408.435791, -1384.241455, 24.601261, 5000, 1);

			format(str, sizeof(str), "%s", (characterLister[playerid][0][0] == EOS) ? ("Empty_Slot") : (characterLister[playerid][0]));
			format(str1, sizeof(str1), "%s", ReturnFactionNameEx(characterFaction[playerid][0]));

			PlayerTextDrawSetString(playerid, SelectFactionName[playerid], str1);
			PlayerTextDrawSetString(playerid, SelectFactionLocation[playerid], str);
			PlayerTextDrawColor(playerid,SelectFactionName[playerid], FactionInfo[characterFaction[playerid][0]][E_FACTION_COLORHEX]);
		}
		else if(PlayerInfo[playerid][E_CHARACTER_SELECTCHAR] == 1) 
		{
			InterpolateCameraPos(playerid, 2185.926269, -1268.906616, 41.573722, 2245.688720, -1260.544433, 24.907897, 5000, 1);
			InterpolateCameraLookAt(playerid, 2189.362548, -1267.340942, 40.254177, 2249.600341, -1260.573974, 24.072427, 5000, 1);

			format(str, sizeof(str), "%s", (characterLister[playerid][1][0] == EOS) ? ("Empty_Slot") : (characterLister[playerid][1]));
			format(str1, sizeof(str1), "%s", ReturnFactionNameEx(characterFaction[playerid][1]));

			PlayerTextDrawSetString(playerid, SelectFactionName[playerid], str1);
			PlayerTextDrawSetString(playerid, SelectFactionLocation[playerid], str);
			PlayerTextDrawColor(playerid,SelectFactionName[playerid], FactionInfo[characterFaction[playerid][1]][E_FACTION_COLORHEX]);
		}
		else if(PlayerInfo[playerid][E_CHARACTER_SELECTCHAR] == 2) 
		{
			InterpolateCameraPos(playerid, 2500.692871, -1674.725708, 21.212182, 2528.266601, -1667.606933, 16.029075, 5000, 1);
			InterpolateCameraLookAt(playerid, 2504.393310, -1673.521484, 20.286582, 2532.240478, -1667.483764, 15.588704, 5000, 1);

			format(str, sizeof(str), "%s", (characterLister[playerid][2][0] == EOS) ? ("Empty_Slot") : (characterLister[playerid][2]));
			format(str1, sizeof(str1), "%s", ReturnFactionNameEx(characterFaction[playerid][2]));


			PlayerTextDrawSetString(playerid, SelectFactionName[playerid], str1);
			PlayerTextDrawSetString(playerid, SelectFactionLocation[playerid], str);
			PlayerTextDrawColor(playerid,SelectFactionName[playerid], FactionInfo[characterFaction[playerid][2]][E_FACTION_COLORHEX]);
		}
		else if(PlayerInfo[playerid][E_CHARACTER_SELECTCHAR] == 3) 
		{
			InterpolateCameraPos(playerid, 917.880371, -1074.410278, 29.465572, 903.424865, -1070.598022, 25.597146, 3000, 1);
			InterpolateCameraLookAt(playerid, 914.184448, -1074.500610, 27.938461, 901.119445, -1073.822387, 25.060024, 3000, 1);

			format(str, sizeof(str), "%s", (characterLister[playerid][3][0] == EOS) ? ("Empty_Slot") : (characterLister[playerid][3]));
			format(str1, sizeof(str1), "%s", ReturnFactionNameEx(characterFaction[playerid][3]));

			PlayerTextDrawSetString(playerid, SelectFactionName[playerid], str1);
			PlayerTextDrawSetString(playerid, SelectFactionLocation[playerid], str);
			PlayerTextDrawColor(playerid, SelectFactionName[playerid], FactionInfo[characterFaction[playerid][3]][E_FACTION_COLORHEX]);
		}
	}

	PlayerTextDrawShow(playerid, SelectFaction[0][playerid]);
	PlayerTextDrawShow(playerid, SelectFaction[1][playerid]);
	PlayerTextDrawShow(playerid, SelectFactionName[playerid]);
	PlayerTextDrawShow(playerid, SelectFactionLocation[playerid]);
	PlayerTextDrawShow(playerid, SelectFactionClick[0][playerid]);
	PlayerTextDrawShow(playerid, SelectFactionClick[1][playerid]);
	PlayerTextDrawShow(playerid, SelectFactionClick[2][playerid]);
	return 1;
}

//----------------------------------------------------------

SwitchNextCharacterSelection(playerid)
{
	if(characterSelection[playerid])
	{
		PlayerInfo[playerid][E_CHARACTER_SELECTCHAR]++;
		if(PlayerInfo[playerid][E_CHARACTER_SELECTCHAR] > 3) {
			PlayerInfo[playerid][E_CHARACTER_SELECTCHAR] = 0;
		}
		PlayerPlaySound(playerid,1052,0.0,0.0,0.0);
		SetupCharacterSelection(playerid);
	}
	if(playerCharacterStep[playerid] == 6)
	{
		PlayerInfo[playerid][E_CHARACTER_SELECTCHAR]++;
		if(PlayerInfo[playerid][E_CHARACTER_SELECTCHAR] > SELECT_TDB) {
			PlayerInfo[playerid][E_CHARACTER_SELECTCHAR] = SELECT_HOODRATS;
		}
		PlayerPlaySound(playerid,1052,0.0,0.0,0.0);
		SetupCharacterSelection(playerid);
	}
}

//----------------------------------------------------------

SwitchPrevCharacterSelection(playerid)
{
	if(characterSelection[playerid])
	{
		PlayerInfo[playerid][E_CHARACTER_SELECTCHAR]--;
		if(PlayerInfo[playerid][E_CHARACTER_SELECTCHAR] < 0) {
			PlayerInfo[playerid][E_CHARACTER_SELECTCHAR] = 3;
		}
		PlayerPlaySound(playerid,1053,0.0,0.0,0.0);
		SetupCharacterSelection(playerid);
	}
	if(playerCharacterStep[playerid] == 6)
	{
		PlayerInfo[playerid][E_CHARACTER_SELECTCHAR]--;
		if(PlayerInfo[playerid][E_CHARACTER_SELECTCHAR] < SELECT_HOODRATS) {
			PlayerInfo[playerid][E_CHARACTER_SELECTCHAR] = SELECT_TDB;
		}
		PlayerPlaySound(playerid,1053,0.0,0.0,0.0);
		SetupCharacterSelection(playerid);
	}
}

//----------------------------------------------------------

ShowCharacterSelection(playerid)
{
	characterSelection[playerid] = true;
	playerMakingCharacter[playerid] = false;
	playerCharacterStep[playerid] = 0; 

	if(PlayerInfo[playerid][E_CHARACTER_SELECTCHAR] == -1) 
	{
		PlayerInfo[playerid][E_CHARACTER_SELECTCHAR] = 0;
	}

	for(new i = 0; i < 3; i ++) {PlayerTextDrawHide(playerid, loginscreen[i][playerid]);}

	SetupCharacterSelection(playerid);
	if(characterSelection[playerid])
	{
		PlayerTextDrawShow(playerid, SelectFaction[0][playerid]);
		PlayerTextDrawShow(playerid, SelectFaction[1][playerid]);
		PlayerTextDrawShow(playerid, SelectFactionName[playerid]);
		PlayerTextDrawShow(playerid, SelectFactionLocation[playerid]);
		PlayerTextDrawShow(playerid, SelectFactionClick[0][playerid]);
		PlayerTextDrawShow(playerid, SelectFactionClick[1][playerid]);
		PlayerTextDrawShow(playerid, SelectFactionClick[2][playerid]);

		SelectTextDraw(playerid, COLOR_YELLOW);
	}
	if(playerCharacterStep[playerid] == 6)
	{
		PlayerTextDrawShow(playerid, SelectFaction[0][playerid]);
		PlayerTextDrawShow(playerid, SelectFaction[1][playerid]);
		PlayerTextDrawShow(playerid, SelectFactionName[playerid]);
		PlayerTextDrawShow(playerid, SelectFactionLocation[playerid]);
		PlayerTextDrawShow(playerid, SelectFactionClick[0][playerid]);
		PlayerTextDrawShow(playerid, SelectFactionClick[1][playerid]);
		PlayerTextDrawShow(playerid, SelectFactionClick[2][playerid]);

		SelectTextDraw(playerid, COLOR_YELLOW);
	}
	return 1;
}

SelectCharacter(playerid, id)
{
	PlayerInfo[playerid][E_CHARACTER_SELECTCHAR] = id;
	AccountInfo[playerid][E_MASTERS_LOGGED] = true;
	
	if (!characterLister[playerid][id][0])
	{
		for(new i =0 ; i < 10; i++){ SendClientMessage(playerid, -1, " "); }
		SendClientMessage(playerid, COLOR_WHITE, "You selected an empty character slot!");

		SetPlayerVirtualWorld(playerid, 99);			
		SendClientMessage(playerid, -1, "This process will guide you through creating your character.");
		SendClientMessage(playerid, -1, "Please begin by typing your characters first and last name. i.e: {8E5B94}George_Jefferson");
		SendClientMessage(playerid, -1, "Your characters name must be in Firstname_Lastname format with no numbers or special characters.");
		SendClientMessage(playerid, -1, "Press {8E5B94}'T'{ffffff} to inputtext for character creation.");

		playerMakingCharacter[playerid] = true;
		playerCharacterStep[playerid] = 1; 
		characterSelection[playerid] = false;

		PlayerTextDrawHide(playerid, SelectFaction[0][playerid]);
		PlayerTextDrawHide(playerid, SelectFaction[1][playerid]);
		PlayerTextDrawHide(playerid, SelectFactionName[playerid]);
		PlayerTextDrawHide(playerid, SelectFactionLocation[playerid]);
		PlayerTextDrawHide(playerid, SelectFactionClick[0][playerid]);
		PlayerTextDrawHide(playerid, SelectFactionClick[1][playerid]);
		PlayerTextDrawHide(playerid, SelectFactionClick[2][playerid]);

		CancelSelectTextDraw(playerid);
		DestroyPlayerActor(playerid);
	}
	    
	else
	{
		new string[128], thread[128];

		for(new i = 0; i < 3; i ++) {PlayerTextDrawHide(playerid, loginscreen[i][playerid]);}
		characterPickTime[playerid] = 0;
					
		playerMakingCharacter[playerid] = false;
		playerCharacterStep[playerid] = 0; 
		characterSelection[playerid] = false;
					
		format(string, sizeof(string), "You selected the character {8E5B94}%s{FFFFFF}.", characterLister[playerid][id]);
		SendClientMessage(playerid, -1, string);

		new str[256];
		format(str, sizeof(str), "%s", characterLister[playerid][id]);
		SetPlayerName(playerid, str); 
					
		mysql_format(ourConnection, thread, sizeof(thread), "SELECT * FROM characters WHERE char_name = '%e' LIMIT 1", characterLister[playerid][id]);
		mysql_pquery(ourConnection, thread, "Query_SelectCharacter", "i", playerid); 

		PlayerTextDrawHide(playerid, SelectFaction[0][playerid]);
		PlayerTextDrawHide(playerid, SelectFaction[1][playerid]);
		PlayerTextDrawHide(playerid, SelectFactionName[playerid]);
		PlayerTextDrawHide(playerid, SelectFactionLocation[playerid]);
		PlayerTextDrawHide(playerid, SelectFactionClick[0][playerid]);
		PlayerTextDrawHide(playerid, SelectFactionClick[1][playerid]);
		PlayerTextDrawHide(playerid, SelectFactionClick[2][playerid]);

		CancelSelectTextDraw(playerid);
		DestroyPlayerActor(playerid);
	}
	return 1;
}