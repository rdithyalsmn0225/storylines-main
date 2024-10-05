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

			format(str, sizeof(str), "%s", (!characterLister[playerid][0][0]) ? ("Empty_Slot") : (characterLister[playerid][0]));
			format(str1, sizeof(str1), "%s", ReturnFactionNameEx(characterFaction[playerid][0]));


			PlayerTextDrawSetString(playerid, SelectFactionName[playerid], str1);
			PlayerTextDrawSetString(playerid, SelectFactionLocation[playerid], str);
			PlayerTextDrawColor(playerid,SelectFactionName[playerid], FactionInfo[characterFaction[playerid][0]][E_FACTION_COLORHEX]);
		}
		else if(PlayerInfo[playerid][E_CHARACTER_SELECTCHAR] == 1) 
		{
			InterpolateCameraPos(playerid, 2185.926269, -1268.906616, 41.573722, 2245.688720, -1260.544433, 24.907897, 5000, 1);
			InterpolateCameraLookAt(playerid, 2189.362548, -1267.340942, 40.254177, 2249.600341, -1260.573974, 24.072427, 5000, 1);

			format(str, sizeof(str), "%s", (!characterLister[playerid][1][0]) ? ("Empty_Slot") : (characterLister[playerid][1]));
			format(str1, sizeof(str1), "%s", ReturnFactionNameEx(characterFaction[playerid][1]));

			PlayerTextDrawSetString(playerid, SelectFactionName[playerid], str1);
			PlayerTextDrawSetString(playerid, SelectFactionLocation[playerid], str);
			PlayerTextDrawColor(playerid,SelectFactionName[playerid], FactionInfo[characterFaction[playerid][1]][E_FACTION_COLORHEX]);
		}
		else if(PlayerInfo[playerid][E_CHARACTER_SELECTCHAR] == 2) 
		{
			InterpolateCameraPos(playerid, 2500.692871, -1674.725708, 21.212182, 2528.266601, -1667.606933, 16.029075, 5000, 1);
			InterpolateCameraLookAt(playerid, 2504.393310, -1673.521484, 20.286582, 2532.240478, -1667.483764, 15.588704, 5000, 1);

			format(str, sizeof(str), "%s", (!characterLister[playerid][2][0]) ? ("Empty_Slot") : (characterLister[playerid][2]));
			format(str1, sizeof(str1), "%s", ReturnFactionNameEx(characterFaction[playerid][2]));


			PlayerTextDrawSetString(playerid, SelectFactionName[playerid], str1);
			PlayerTextDrawSetString(playerid, SelectFactionLocation[playerid], str);
			PlayerTextDrawColor(playerid,SelectFactionName[playerid], FactionInfo[characterFaction[playerid][2]][E_FACTION_COLORHEX]);
		}
		else if(PlayerInfo[playerid][E_CHARACTER_SELECTCHAR] == 3) 
		{
			InterpolateCameraPos(playerid, 917.880371, -1074.410278, 29.465572, 903.424865, -1070.598022, 25.597146, 3000, 1);
			InterpolateCameraLookAt(playerid, 914.184448, -1074.500610, 27.938461, 901.119445, -1073.822387, 25.060024, 3000, 1);

			format(str, sizeof(str), "%s", (!characterLister[playerid][3][0]) ? ("Empty_Slot") : (characterLister[playerid][3]));
			format(str1, sizeof(str1), "%s", ReturnFactionNameEx(characterFaction[playerid][3]));

			PlayerTextDrawSetString(playerid, SelectFactionName[playerid], str1);
			PlayerTextDrawSetString(playerid, SelectFactionLocation[playerid], str);
			PlayerTextDrawColor(playerid,SelectFactionName[playerid], FactionInfo[characterFaction[playerid][3]][E_FACTION_COLORHEX]);
		}
	}

	/*=====[FACTION SELECTION]======*/
	if(playerCharacterStep[playerid] == 6)
	{
		if(PlayerInfo[playerid][E_CHARACTER_SELECTCHAR] == -1) {
			PlayerInfo[playerid][E_CHARACTER_SELECTCHAR] = SELECT_HOODRATS;
		}
		
		if(PlayerInfo[playerid][E_CHARACTER_SELECTCHAR] == SELECT_HOODRATS) {
			SetPlayerInterior(playerid,0);
			InterpolateCameraPos(playerid, 2223.004394, -1261.156982, 24.698129, 2238.075439, -1260.909179, 24.844661, 3000, 1);
			InterpolateCameraLookAt(playerid, 2226.993896, -1261.235473, 24.418256, 2242.063232, -1260.991943, 24.544891, 3000, 1);

			PlayerTextDrawSetString(playerid, SelectFactionName[playerid], "Hoodrats");
			PlayerTextDrawSetString(playerid, SelectFactionLocation[playerid], "ELS");
			PlayerTextDrawColor(playerid,SelectFactionName[playerid], COLOR_GREY);
		}
		else if(PlayerInfo[playerid][E_CHARACTER_SELECTCHAR] == SELECT_POLICE) {
			SetPlayerInterior(playerid,6);
			InterpolateCameraPos(playerid, 235.439743, 70.881576, 1006.824462, 235.504196, 73.025299, 1006.495483, 3000, 1);
			InterpolateCameraLookAt(playerid, 235.519836, 74.791122, 1005.982421, 235.569183, 76.949172, 1005.721557, 3000, 1);	
			
			PlayerTextDrawSetString(playerid, SelectFactionName[playerid], "Los_Santos_Police_Departement");
			PlayerTextDrawSetString(playerid, SelectFactionLocation[playerid], "Coference_Center");
			PlayerTextDrawColor(playerid,SelectFactionName[playerid], COLOR_COP);
		}
		else if(PlayerInfo[playerid][E_CHARACTER_SELECTCHAR] == SELECT_GSF) {
			SetPlayerInterior(playerid, 0);
			InterpolateCameraPos(playerid, 2283.245117, -1788.274658, 14.121856, 2283.024658, -1792.657470, 14.073786, 3000, 1);
			InterpolateCameraLookAt(playerid, 2283.131835, -1792.271850, 14.021317, 2282.951416, -1796.640625, 13.714371, 3000, 1);
			
			
			PlayerTextDrawSetString(playerid, SelectFactionName[playerid], "Grove_Street_Famillies");
			PlayerTextDrawSetString(playerid, SelectFactionLocation[playerid], "Ganton");
			PlayerTextDrawColor(playerid,SelectFactionName[playerid], COLOR_GSF);
		}
		else if(PlayerInfo[playerid][E_CHARACTER_SELECTCHAR] == SELECT_KTB) {
			SetPlayerInterior(playerid,0);
			InterpolateCameraPos(playerid, 2040.372802, -1295.134033, 22.667469, 2048.909912, -1295.137939, 21.981952, 3000, 1);
			InterpolateCameraLookAt(playerid, 2044.323120, -1295.187866, 22.041101, 2052.877441, -1295.148193, 21.474071, 3000, 1);


			
			PlayerTextDrawSetString(playerid, SelectFactionName[playerid], "Kilo_Tray_Ballas");
			PlayerTextDrawSetString(playerid, SelectFactionLocation[playerid], "Bahamas");
			PlayerTextDrawColor(playerid,SelectFactionName[playerid], COLOR_KTB);
		}
		else if(PlayerInfo[playerid][E_CHARACTER_SELECTCHAR] == SELECT_RHB) {
			SetPlayerInterior(playerid,0);
			InterpolateCameraPos(playerid, 2231.554443, -1429.878417, 28.386594, 2232.753417, -1429.869018, 28.145399, 3000, 1);
			InterpolateCameraLookAt(playerid, 2235.451904, -1429.754516, 27.495582, 2236.676025, -1429.748535, 27.371461, 3000, 1);

			
			PlayerTextDrawSetString(playerid, SelectFactionName[playerid], "Rollin'_Height_Ballas");
			PlayerTextDrawSetString(playerid, SelectFactionLocation[playerid], "Crenshaw");
			PlayerTextDrawColor(playerid,SelectFactionName[playerid], COLOR_JB);
		}
		else if(PlayerInfo[playerid][E_CHARACTER_SELECTCHAR] == SELECT_SBF) {
			SetPlayerInterior(playerid,0);
			InterpolateCameraPos(playerid, 2738.134765, -1967.499755, 17.795400, 2739.684814, -1967.437500, 17.631998, 3000, 1);
			InterpolateCameraLookAt(playerid, 2739.130859, -1967.445312, 17.725433, 2743.659667, -1967.277832, 17.213018, 3000, 1);

			
			PlayerTextDrawSetString(playerid, SelectFactionName[playerid], "Seville_BLVD_Famillies");
			PlayerTextDrawSetString(playerid, SelectFactionLocation[playerid], "Playa_Del_Seville");
			PlayerTextDrawColor(playerid,SelectFactionName[playerid], COLOR_SBF);
		}
		else if(PlayerInfo[playerid][E_CHARACTER_SELECTCHAR] == SELECT_VLA) {
			SetPlayerInterior(playerid,0);
			InterpolateCameraPos(playerid, 1976.289428, -2099.277832, 21.832500, 1976.516723, -2098.046875, 21.778263, 3000, 1);
			InterpolateCameraLookAt(playerid, 1976.329833, -2098.279052, 21.862220, 1976.590087, -2094.048828, 21.677722, 3000, 1);

			PlayerTextDrawSetString(playerid, SelectFactionName[playerid], "Varrios_Los_Aztecas");
			PlayerTextDrawSetString(playerid, SelectFactionLocation[playerid], "El_Corona");
			PlayerTextDrawColor(playerid,SelectFactionName[playerid], COLOR_VLA);
		}
		else if(PlayerInfo[playerid][E_CHARACTER_SELECTCHAR] == SELECT_ELSV) {
			SetPlayerInterior(playerid,0);
			InterpolateCameraPos(playerid, 2555.181640, -1405.602050, 41.682781, 2554.544433, -1402.863281, 41.471443, 3000, 1);
			InterpolateCameraLookAt(playerid, 2554.342285, -1401.734008, 41.105453, 2553.883300, -1398.983642, 40.756309, 3000, 1);

			PlayerTextDrawSetString(playerid, SelectFactionName[playerid], "Los_Santos_Vagos");
			PlayerTextDrawSetString(playerid, SelectFactionLocation[playerid], "East_Los_Santos");
			PlayerTextDrawColor(playerid,SelectFactionName[playerid], COLOR_ELSV);
		}
		else if(PlayerInfo[playerid][E_CHARACTER_SELECTCHAR] == SELECT_FYB) {
			SetPlayerInterior(playerid,0);
			InterpolateCameraPos(playerid, 1880.481079, -1584.717163, 14.674718, 1881.177734, -1584.388305, 14.644520, 3000, 1);
			InterpolateCameraLookAt(playerid, 1884.444091, -1585.218017, 14.883565, 1885.038085, -1585.412475, 14.424382, 3000, 1);

			PlayerTextDrawSetString(playerid, SelectFactionName[playerid], "Front_Yard_Ballas");
			PlayerTextDrawSetString(playerid, SelectFactionLocation[playerid], "Arbor_Vitae_Street");
			PlayerTextDrawColor(playerid,SelectFactionName[playerid], COLOR_FYB);
		}
		else if(PlayerInfo[playerid][E_CHARACTER_SELECTCHAR] == SELECT_TDF) {
			SetPlayerInterior(playerid,0);
			InterpolateCameraPos(playerid, 1141.767211, -1016.997497, 38.380058, 1139.114990, -1014.970336, 37.624214, 3000, 1);
			InterpolateCameraLookAt(playerid, 1138.687744, -1014.605224, 37.489048, 1135.903076, -1012.775085, 36.694351, 3000, 1);

			PlayerTextDrawSetString(playerid, SelectFactionName[playerid], "Temple_Drive_Famillies");
			PlayerTextDrawSetString(playerid, SelectFactionLocation[playerid], "Crystall_Hill");
			PlayerTextDrawColor(playerid,SelectFactionName[playerid], COLOR_TDF);
		}
		else if(PlayerInfo[playerid][E_CHARACTER_SELECTCHAR] == SELECT_TDB) {
			SetPlayerInterior(playerid,0);
			InterpolateCameraPos(playerid, 1183.787109, -1228.550903, 22.545907, 1183.698120, -1230.320068, 22.690839, 3000, 1);
			InterpolateCameraLookAt(playerid, 1183.522705, -1232.542114, 22.565057, 1183.593994, -1234.285034, 22.172798, 3000, 1);

			
			PlayerTextDrawSetString(playerid, SelectFactionName[playerid], "Temple_Drive_Ballas");
			PlayerTextDrawSetString(playerid, SelectFactionLocation[playerid], "Market_Street");
			PlayerTextDrawColor(playerid,SelectFactionName[playerid], COLOR_TDB);
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