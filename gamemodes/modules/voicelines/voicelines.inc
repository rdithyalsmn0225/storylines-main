

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

CMD:voicelines(playerid, params[])
{
	ShowPlayerDialog(playerid, DIALOG_VOICELINES, DIALOG_STYLE_LIST, "Voicelines Select:", "Famillies Gang Members\nBallas Gang Members\nAztecas Gang Members\nVagos Gang Members\nPolice Officers", "Select", "Close");
	return 1;
}