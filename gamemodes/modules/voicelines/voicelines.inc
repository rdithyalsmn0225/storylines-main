

stock Voiceline_GetDescription(soundid, desc[], len = sizeof (desc)) 
{
	new bool: found = false ;

	for (new i, j = sizeof(VL_Families); i < j ; i ++) {

		if ( VL_Families[i][E_VOICELINE_ID] == soundid) {

			format(desc, len, "%s", VL_Families[i][E_VOICELINE_DESC]);
			found = true;
		}

		else continue ;
	}

	for (new i, j = sizeof(VL_Ballas); i < j ; i ++) {

		if (VL_Ballas[i][E_VOICELINE_ID ] == soundid) {

			format(desc, len, "%s", VL_Ballas[i][E_VOICELINE_DESC ]) ;
			found = true;
		}

		else continue;
	}

	for (new i, j = sizeof (VL_Aztecas); i < j ; i ++) {

		if (VL_Aztecas[i][E_VOICELINE_ID ] == soundid) {

			format(desc, len, "%s", VL_Aztecas[i][E_VOICELINE_DESC]) ;
			found = true;
		}

		else continue ;
	}

	for (new i, j = sizeof (VL_Vagos); i < j ; i ++) {

		if (VL_Vagos[i][E_VOICELINE_ID ] == soundid) {

			format(desc, len, "%s", VL_Vagos[i][E_VOICELINE_DESC]) ;
			found = true;
		}

		else continue;
	}


	for (new i, j = sizeof (VL_LSPD); i < j ; i ++) {

		if (VL_LSPD[i][E_VOICELINE_ID] == soundid) {

			format(desc, len, "%s", VL_LSPD[i][E_VOICELINE_DESC]) ;
			found = true;
		}

		else continue;
	}

	if(!found) {

		format(desc, len, "Invalid");
	}
}

Voiceline_Play(playerid, voiceid) 
{
	if(PlayerInfo[playerid][E_CHARACTER_VOICELINECD] && (gettime() - PlayerInfo[playerid][E_CHARACTER_VOICELINECD]) < 10)
		return SendErrorMessage(playerid, "You must wait before playing another voice line.");

	new text[128];

	Voiceline_GetDescription(voiceid, text, sizeof(text));
	PlayerPlaySoundEx(playerid, voiceid);

	new string[256];

	format(string, sizeof (string), "* %s{C4DD89} says: %s", ReturnMixedName ( playerid ), text ) ;
	SetPlayerChatBubble(playerid, string, 0xC4DD89FF, 15.0, 5000 ) ;

	format (string, sizeof (string), "[VOICELINES] %s{C4DD89} says: %s", ReturnMixedName ( playerid ), text ) ;
	SendClientMessage(playerid, 0xC4DD89FF, string);

	PlayerInfo[playerid][E_CHARACTER_VOICELINECD] = gettime();
	return 1;
}		

CMD:vl(playerid, params[]) return cmd_voicelines(playerid, params);
CMD:voicelines(playerid, params[])
{
	Dialog_Show(playerid, VoicelinesList, DIALOG_STYLE_LIST, "Voicelines Select:", "Famillies Gang Members\nBallas Gang Members\nAztecas Gang Members\nVagos Gang Members\nPolice Officers", "Select", "Close");
	return 1;
}

Dialog:VoicelinesList(playerid, response, listitem, inputtext[]) 
{
	new string[2048];
    if(response)
	{
		switch(listitem)
		{
			case 0:
			{
				strcat(string, "Description\n");
				forex(i, sizeof (VL_Families)) {
					format(string, sizeof(string), "%s%s\n", string, VL_Families[i][E_VOICELINE_DESC]);
				}
				Dialog_ShowPages(playerid, VoicelinesPlay, DIALOG_STYLE_TABLIST_HEADERS, "Voicelines:", string, "Play", "Close");
			}
			case 1:
			{
				strcat(string, "Description\n");
				forex(i, sizeof(VL_Ballas)) {
					format(string, sizeof(string), "%s%s\n", string, VL_Ballas[i][E_VOICELINE_DESC]);
				}
				Dialog_ShowPages(playerid, VoicelinesPlay, DIALOG_STYLE_TABLIST_HEADERS, "Voicelines:", string, "Play", "Close");
			}
			case 2:
			{
				strcat(string, "Description\n");
				forex(i, sizeof(VL_Aztecas)) {
					format(string, sizeof(string), "%s%s\n", string, VL_Aztecas[i][E_VOICELINE_DESC]);
				}
				Dialog_ShowPages(playerid, VoicelinesPlay, DIALOG_STYLE_TABLIST_HEADERS, "Voicelines:", string, "Play", "Close");
			}
			case 3:
			{
				strcat(string, "Description\n");
				forex(i, sizeof(VL_Vagos)) {
					format(string, sizeof(string), "%s%s\n", string, VL_Vagos[i][E_VOICELINE_DESC]);
				}
				Dialog_ShowPages(playerid, VoicelinesPlay, DIALOG_STYLE_TABLIST_HEADERS, "Voicelines:", string, "Play", "Close");
			}
			case 4:
			{
				strcat(string, "Description\n");
				forex(i, sizeof(VL_LSPD)) {
					format(string, sizeof(string), "%s%s\n", string, VL_LSPD[i][E_VOICELINE_DESC]);
				}
				Dialog_ShowPages(playerid, VoicelinesPlay, DIALOG_STYLE_TABLIST_HEADERS, "Voicelines:", string, "Play", "Close");
			}
		}
	}
    return 1;
}

Dialog:VoicelinesPlay(playerid, response, listitem, inputtext[]) 
{
    if(response)
	{
		if(PlayerInfo[playerid][E_CHARACTER_FACTION] == 3 || PlayerInfo[playerid][E_CHARACTER_FACTION] == 6 || PlayerInfo[playerid][E_CHARACTER_FACTION] == 10)
		{
			Voiceline_Play(playerid, VL_Families[listitem][E_VOICELINE_ID]);
		}
		else if(PlayerInfo[playerid][E_CHARACTER_FACTION] == 4 || PlayerInfo[playerid][E_CHARACTER_FACTION] == 5 || PlayerInfo[playerid][E_CHARACTER_FACTION] == 9 || PlayerInfo[playerid][E_CHARACTER_FACTION] == 11)
		{
			Voiceline_Play(playerid, VL_Ballas[listitem][E_VOICELINE_ID]);
		}
		else if(PlayerInfo[playerid][E_CHARACTER_FACTION] == 8)
		{
			Voiceline_Play(playerid, VL_Aztecas[listitem][E_VOICELINE_ID]);
		}
		else if(PlayerInfo[playerid][E_CHARACTER_FACTION] == 7)
		{
			Voiceline_Play(playerid, VL_Vagos[listitem][E_VOICELINE_ID]);
		}
		else if(PlayerInfo[playerid][E_CHARACTER_FACTION] == 1)
		{
			Voiceline_Play(playerid, VL_LSPD[listitem][E_VOICELINE_ID]);
		}
	}
	return 1;
}