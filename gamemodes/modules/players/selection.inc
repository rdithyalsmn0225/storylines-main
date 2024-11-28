SetupCharacterSelection(playerid)
{
	new str[512], str1[512];

	// CHARACTERS SELECTION]======*/
	if(characterSelection[playerid])
	{
		if(PlayerInfo[playerid][E_CHARACTER_SELECTCHAR] == -1) 
		{
			PlayerInfo[playerid][E_CHARACTER_SELECTCHAR] = 0;
		}
		
		if(PlayerInfo[playerid][E_CHARACTER_SELECTCHAR] == 0) 
		{
			InterpolateCameraPos(playerid, 1342.239868, 907.062683, 132.776443, 1340.489257, 895.953430, 131.934539, 8000, 1);
			InterpolateCameraLookAt(playerid, 1342.029663, 903.076232, 132.523345, 1340.611816, 891.964660, 131.660949, 8000, 1);

			format(str, sizeof(str), "%s", (characterLister[playerid][0][0] == EOS) ? ("Empty_Slot") : (characterLister[playerid][0]));
			format(str1, sizeof(str1), "%s", ReturnFactionNameEx(characterFaction[playerid][0]));

			PlayerTextDrawSetString(playerid, SelectFactionName[playerid], str1);
			PlayerTextDrawSetString(playerid, SelectFactionLocation[playerid], str);
			
			CreatePlayerActor(playerid, characterSkin[playerid][0]);
		}
		else if(PlayerInfo[playerid][E_CHARACTER_SELECTCHAR] == 1) 
		{
			InterpolateCameraPos(playerid, 1342.239868, 907.062683, 132.776443, 1340.489257, 895.953430, 131.934539, 8000, 1);
			InterpolateCameraLookAt(playerid, 1342.029663, 903.076232, 132.523345, 1340.611816, 891.964660, 131.660949, 8000, 1);

			format(str, sizeof(str), "%s", (characterLister[playerid][1][0] == EOS) ? ("Empty_Slot") : (characterLister[playerid][1]));
			format(str1, sizeof(str1), "%s", ReturnFactionNameEx(characterFaction[playerid][1]));

			PlayerTextDrawSetString(playerid, SelectFactionName[playerid], str1);
			PlayerTextDrawSetString(playerid, SelectFactionLocation[playerid], str);
			
			CreatePlayerActor(playerid, characterSkin[playerid][1]);
		}
		else if(PlayerInfo[playerid][E_CHARACTER_SELECTCHAR] == 2) 
		{
			InterpolateCameraPos(playerid, 1342.239868, 907.062683, 132.776443, 1340.489257, 895.953430, 131.934539, 8000, 1);
			InterpolateCameraLookAt(playerid, 1342.029663, 903.076232, 132.523345, 1340.611816, 891.964660, 131.660949, 8000, 1);

			format(str, sizeof(str), "%s", (characterLister[playerid][2][0] == EOS) ? ("Empty_Slot") : (characterLister[playerid][2]));
			format(str1, sizeof(str1), "%s", ReturnFactionNameEx(characterFaction[playerid][2]));


			PlayerTextDrawSetString(playerid, SelectFactionName[playerid], str1);
			PlayerTextDrawSetString(playerid, SelectFactionLocation[playerid], str);
			
			CreatePlayerActor(playerid, characterSkin[playerid][2]);
		}
		else if(PlayerInfo[playerid][E_CHARACTER_SELECTCHAR] == 3) 
		{
			InterpolateCameraPos(playerid, 1342.239868, 907.062683, 132.776443, 1340.489257, 895.953430, 131.934539, 8000, 1);
			InterpolateCameraLookAt(playerid, 1342.029663, 903.076232, 132.523345, 1340.611816, 891.964660, 131.660949, 8000, 1);

			format(str, sizeof(str), "%s", (characterLister[playerid][3][0] == EOS) ? ("Empty_Slot") : (characterLister[playerid][3]));
			format(str1, sizeof(str1), "%s", ReturnFactionNameEx(characterFaction[playerid][3]));

			PlayerTextDrawSetString(playerid, SelectFactionName[playerid], str1);
			PlayerTextDrawSetString(playerid, SelectFactionLocation[playerid], str);
			
			CreatePlayerActor(playerid, characterSkin[playerid][3]);
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

	for(new i = 0; i < 4; i ++) {PlayerTextDrawHide(playerid, LoginScreen[i][playerid]);}

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

	foreach (new x : Player)
	{
		if(playerid == x) continue;

		if(AccountInfo[playerid][E_MASTERS_DBID] == AccountInfo[x][E_MASTERS_DBID])
		{
			SendErrorMessage(playerid, "Login unsuccessful (character already logged in?)");
			return 1;
		}
	}

	if (!characterLister[playerid][id][0])
	{
		for(new i =0 ; i < 10; i++){ SendClientMessage(playerid, -1, " "); }
		SendClientMessage(playerid, COLOR_WHITE, "You selected an empty character slot!");

		ShowCharacterPreview(playerid);
		
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
	}   
	else
	{
		new string[128], thread[128];

		for(new i = 0; i < 4; i ++) {PlayerTextDrawHide(playerid, LoginScreen[i][playerid]);}
		characterPickTime[playerid] = 0;
					
		playerMakingCharacter[playerid] = false;
		playerCharacterStep[playerid] = 0; 
		characterSelection[playerid] = false;
					
		format(string, sizeof(string), "You selected the character {93C47D}%s{FFFFFF}.", characterLister[playerid][id]);
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