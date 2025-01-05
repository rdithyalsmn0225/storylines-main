//Textdraws
new Text:Times;
new PlayerText:servername[MAX_PLAYERS];
new PlayerText:LoginScreen[4][MAX_PLAYERS];
new PlayerText:HeaderTD[2][MAX_PLAYERS];
new PlayerText:Street[2][MAX_PLAYERS];
new PlayerText:Footers[MAX_PLAYERS];
new PlayerText:Subtittles[MAX_PLAYERS];
new PlayerText:Messages[MAX_PLAYERS];
new PlayerText:speedo[15][MAX_PLAYERS];
new PlayerText:Phone[14][MAX_PLAYERS];
new PlayerText:MDC[14][MAX_PLAYERS];
new PlayerText:pool[5][MAX_PLAYERS];
new PlayerText:blackjack[15][MAX_PLAYERS];
new PlayerText:VehicleSelection[19][MAX_PLAYERS];
new PlayerText:HotwireTD[MAX_PLAYERS][8];
new PlayerText:HotwireTDB[MAX_PLAYERS][8];
new PlayerText:HotwireCable[MAX_PLAYERS][8];
new PlayerText:HE[2][MAX_PLAYERS];
new PlayerBar:HEBAR[1][MAX_PLAYERS];
new PlayerText:money[MAX_PLAYERS];
new PlayerText:MoneyFormat[MAX_PLAYERS];

new PlayerText:SelectFactionLocation[MAX_PLAYERS];
new PlayerText:SelectFactionName[MAX_PLAYERS];
new PlayerText:SelectFaction[2][MAX_PLAYERS];
new PlayerText:SelectFactionClick[3][MAX_PLAYERS];

new PlayerText:ALPR[4][MAX_PLAYERS];
new PlayerText:FoodOrder[10][MAX_PLAYERS];

new PlayerText:WeaponType[MAX_PLAYERS];
new PlayerText:GameBar[3][MAX_PLAYERS];

new PlayerText:tutorialtext[MAX_PLAYERS];
new PlayerText:tutorialbox[MAX_PLAYERS];
new PlayerText:tutorialheader[MAX_PLAYERS];
new PlayerText:tutorialclick[MAX_PLAYERS];
new PlayerText:tutorialskip[MAX_PLAYERS];

new PlayerText:gui_spec_label[MAX_PLAYERS][5];

new PlayerBar:HeaderBar[MAX_PLAYERS];

new Text:UpdateIn;

//Textdraws

stock CreateTextdraws(playerid)
{

	UpdateIn = TextDrawCreate(321.000000, 436.000000, "Maintenance");
	TextDrawFont(UpdateIn, 1);
	TextDrawLetterSize(UpdateIn, 0.212491, 1.199998);
	TextDrawTextSize(UpdateIn, 400.000000, 259.000000);
	TextDrawSetOutline(UpdateIn, 1);
	TextDrawSetShadow(UpdateIn, 0);
	TextDrawAlignment(UpdateIn, 2);
	TextDrawColor(UpdateIn, -1);
	TextDrawBackgroundColor(UpdateIn, 255);
	TextDrawBoxColor(UpdateIn, 50);
	TextDrawUseBox(UpdateIn, 0);
	TextDrawSetProportional(UpdateIn, 1);
	TextDrawSetSelectable(UpdateIn, 0);


	servername[playerid] = CreatePlayerTextDraw(playerid, 584.000000, 416.000000, "~r~F~w~ear and ~b~R~w~espect~n~~b~S~w~tory and ~r~R~w~oleplay");
	PlayerTextDrawFont(playerid, servername[playerid], 0);
	PlayerTextDrawLetterSize(playerid, servername[playerid], 0.420832, 1.500000);
	PlayerTextDrawTextSize(playerid, servername[playerid], 400.000000, 158.000000);
	PlayerTextDrawSetOutline(playerid, servername[playerid], 1);
	PlayerTextDrawSetShadow(playerid, servername[playerid], 0);
	PlayerTextDrawAlignment(playerid, servername[playerid], 2);
	PlayerTextDrawColor(playerid, servername[playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, servername[playerid], 255);
	PlayerTextDrawBoxColor(playerid, servername[playerid], 50);
	PlayerTextDrawUseBox(playerid, servername[playerid], 0);
	PlayerTextDrawSetProportional(playerid, servername[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, servername[playerid], 0);

	LoginScreen[0][playerid] = CreatePlayerTextDraw(playerid, 319.000000, 123.000000, "_");
	PlayerTextDrawFont(playerid, LoginScreen[0][playerid], 1);
	PlayerTextDrawLetterSize(playerid, LoginScreen[0][playerid], 0.600000, 20.849996);
	PlayerTextDrawTextSize(playerid, LoginScreen[0][playerid], 298.500000, 159.500000);
	PlayerTextDrawSetOutline(playerid, LoginScreen[0][playerid], 1);
	PlayerTextDrawSetShadow(playerid, LoginScreen[0][playerid], 0);
	PlayerTextDrawAlignment(playerid, LoginScreen[0][playerid], 2);
	PlayerTextDrawColor(playerid, LoginScreen[0][playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, LoginScreen[0][playerid], 255);
	PlayerTextDrawBoxColor(playerid, LoginScreen[0][playerid], 230);
	PlayerTextDrawUseBox(playerid, LoginScreen[0][playerid], 1);
	PlayerTextDrawSetProportional(playerid, LoginScreen[0][playerid], 1);
	PlayerTextDrawSetSelectable(playerid, LoginScreen[0][playerid], 0);

	LoginScreen[1][playerid] = CreatePlayerTextDraw(playerid, 318.000000, 110.000000, "GTA");
	PlayerTextDrawFont(playerid, LoginScreen[1][playerid], 3);
	PlayerTextDrawLetterSize(playerid, LoginScreen[1][playerid], 0.787500, 2.749996);
	PlayerTextDrawTextSize(playerid, LoginScreen[1][playerid], 400.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, LoginScreen[1][playerid], 2);
	PlayerTextDrawSetShadow(playerid, LoginScreen[1][playerid], 0);
	PlayerTextDrawAlignment(playerid, LoginScreen[1][playerid], 2);
	PlayerTextDrawColor(playerid, LoginScreen[1][playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, LoginScreen[1][playerid], 255);
	PlayerTextDrawBoxColor(playerid, LoginScreen[1][playerid], 50);
	PlayerTextDrawUseBox(playerid, LoginScreen[1][playerid], 0);
	PlayerTextDrawSetProportional(playerid, LoginScreen[1][playerid], 1);
	PlayerTextDrawSetSelectable(playerid, LoginScreen[1][playerid], 0);

	LoginScreen[2][playerid] = CreatePlayerTextDraw(playerid, 325.000000, 125.000000, "Storylines");
	PlayerTextDrawFont(playerid, LoginScreen[2][playerid], 0);
	PlayerTextDrawLetterSize(playerid, LoginScreen[2][playerid], 0.433333, 1.899996);
	PlayerTextDrawTextSize(playerid, LoginScreen[2][playerid], 400.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, LoginScreen[2][playerid], 1);
	PlayerTextDrawSetShadow(playerid, LoginScreen[2][playerid], 0);
	PlayerTextDrawAlignment(playerid, LoginScreen[2][playerid], 2);
	PlayerTextDrawColor(playerid, LoginScreen[2][playerid], 1097458175);
	PlayerTextDrawBackgroundColor(playerid, LoginScreen[2][playerid], 255);
	PlayerTextDrawBoxColor(playerid, LoginScreen[2][playerid], 50);
	PlayerTextDrawUseBox(playerid, LoginScreen[2][playerid], 0);
	PlayerTextDrawSetProportional(playerid, LoginScreen[2][playerid], 1);
	PlayerTextDrawSetSelectable(playerid, LoginScreen[2][playerid], 0);

	LoginScreen[3][playerid] = CreatePlayerTextDraw(playerid, 320.000000, 290.000000, "GTA storylines is an immersive roleplay server based for San Andreas Multiplayer since 2024 by Radeetz");
	PlayerTextDrawFont(playerid, LoginScreen[3][playerid], 1);
	PlayerTextDrawLetterSize(playerid, LoginScreen[3][playerid], 0.133333, 0.799997);
	PlayerTextDrawTextSize(playerid, LoginScreen[3][playerid], 396.500000, 172.000000);
	PlayerTextDrawSetOutline(playerid, LoginScreen[3][playerid], 0);
	PlayerTextDrawSetShadow(playerid, LoginScreen[3][playerid], 0);
	PlayerTextDrawAlignment(playerid, LoginScreen[3][playerid], 2);
	PlayerTextDrawColor(playerid, LoginScreen[3][playerid], -1061109505);
	PlayerTextDrawBackgroundColor(playerid, LoginScreen[3][playerid], 255);
	PlayerTextDrawBoxColor(playerid, LoginScreen[3][playerid], 50);
	PlayerTextDrawUseBox(playerid, LoginScreen[3][playerid], 0);
	PlayerTextDrawSetProportional(playerid, LoginScreen[3][playerid], 1);
	PlayerTextDrawSetSelectable(playerid, LoginScreen[3][playerid], 0);
}

CreateHETextDraws(playerid)
{
	HE[0][playerid] = CreatePlayerTextDraw(playerid, 554.000000, 109.000000, "_");
	PlayerTextDrawFont(playerid, HE[0][playerid], 1);
	PlayerTextDrawLetterSize(playerid, HE[0][playerid], 0.600000, 0.949998);
	PlayerTextDrawTextSize(playerid, HE[0][playerid], 298.000000, 108.000000);
	PlayerTextDrawSetOutline(playerid, HE[0][playerid], 1);
	PlayerTextDrawSetShadow(playerid, HE[0][playerid], 0);
	PlayerTextDrawAlignment(playerid, HE[0][playerid], 2);
	PlayerTextDrawColor(playerid, HE[0][playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, HE[0][playerid], 255);
	PlayerTextDrawBoxColor(playerid, HE[0][playerid], 255);
	PlayerTextDrawUseBox(playerid, HE[0][playerid], 1);
	PlayerTextDrawSetProportional(playerid, HE[0][playerid], 1);
	PlayerTextDrawSetSelectable(playerid, HE[0][playerid], 0);

	HE[1][playerid] = CreatePlayerTextDraw(playerid, 498.000000, 100.000000, "Energy");
	PlayerTextDrawFont(playerid, HE[1][playerid], 0);
	PlayerTextDrawLetterSize(playerid, HE[1][playerid], 0.324997, 0.999997);
	PlayerTextDrawTextSize(playerid, HE[1][playerid], 605.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, HE[1][playerid], 1);
	PlayerTextDrawSetShadow(playerid, HE[1][playerid], 0);
	PlayerTextDrawAlignment(playerid, HE[1][playerid], 1);
	PlayerTextDrawColor(playerid, HE[1][playerid], -1379670017);
	PlayerTextDrawBackgroundColor(playerid, HE[1][playerid], 255);
	PlayerTextDrawBoxColor(playerid, HE[1][playerid], 200);
	PlayerTextDrawUseBox(playerid, HE[1][playerid], 0);
	PlayerTextDrawSetProportional(playerid, HE[1][playerid], 1);
	PlayerTextDrawSetSelectable(playerid, HE[1][playerid], 0);

	HEBAR[0][playerid] = CreatePlayerProgressBar(playerid, 502.000000, 111.000000, 108.500000, 4.500000, -1, 100.0, 0);
}

CreatePhoneTextDraws(playerid)
{
	Phone[0][playerid] = CreatePlayerTextDraw(playerid, 524.000000, 326.000000, "_");
	PlayerTextDrawFont(playerid, Phone[0][playerid], 1);
	PlayerTextDrawLetterSize(playerid, Phone[0][playerid], 0.600000, 14.300004);
	PlayerTextDrawTextSize(playerid, Phone[0][playerid], 298.500000, 68.500000);
	PlayerTextDrawSetOutline(playerid, Phone[0][playerid], 1);
	PlayerTextDrawSetShadow(playerid, Phone[0][playerid], 0);
	PlayerTextDrawAlignment(playerid, Phone[0][playerid], 2);
	PlayerTextDrawColor(playerid, Phone[0][playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, Phone[0][playerid], 255);
	PlayerTextDrawBoxColor(playerid, Phone[0][playerid], 255);
	PlayerTextDrawUseBox(playerid, Phone[0][playerid], 1);
	PlayerTextDrawSetProportional(playerid, Phone[0][playerid], 1);
	PlayerTextDrawSetSelectable(playerid, Phone[0][playerid], 0);

	Phone[1][playerid] = CreatePlayerTextDraw(playerid, 524.000000, 342.000000, "_");
	PlayerTextDrawFont(playerid, Phone[1][playerid], 1);
	PlayerTextDrawLetterSize(playerid, Phone[1][playerid], 0.600000, 9.700001);
	PlayerTextDrawTextSize(playerid, Phone[1][playerid], 298.500000, 58.000000);
	PlayerTextDrawSetOutline(playerid, Phone[1][playerid], 1);
	PlayerTextDrawSetShadow(playerid, Phone[1][playerid], 0);
	PlayerTextDrawAlignment(playerid, Phone[1][playerid], 2);
	PlayerTextDrawColor(playerid, Phone[1][playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, Phone[1][playerid], 1703184127);
	PlayerTextDrawBoxColor(playerid, Phone[1][playerid], 1703312639);
	PlayerTextDrawUseBox(playerid, Phone[1][playerid], 1);
	PlayerTextDrawSetProportional(playerid, Phone[1][playerid], 1);
	PlayerTextDrawSetSelectable(playerid, Phone[1][playerid], 0);

	Phone[2][playerid] = CreatePlayerTextDraw(playerid, 524.000000, 335.000000, "_");
	PlayerTextDrawFont(playerid, Phone[2][playerid], 1);
	PlayerTextDrawLetterSize(playerid, Phone[2][playerid], 0.600000, 0.849999);
	PlayerTextDrawTextSize(playerid, Phone[2][playerid], 298.500000, 58.000000);
	PlayerTextDrawSetOutline(playerid, Phone[2][playerid], 1);
	PlayerTextDrawSetShadow(playerid, Phone[2][playerid], 0);
	PlayerTextDrawAlignment(playerid, Phone[2][playerid], 2);
	PlayerTextDrawColor(playerid, Phone[2][playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, Phone[2][playerid], 255);
	PlayerTextDrawBoxColor(playerid, Phone[2][playerid], 421075455);
	PlayerTextDrawUseBox(playerid, Phone[2][playerid], 1);
	PlayerTextDrawSetProportional(playerid, Phone[2][playerid], 1);
	PlayerTextDrawSetSelectable(playerid, Phone[2][playerid], 0);

	Phone[3][playerid] = CreatePlayerTextDraw(playerid, 496.000000, 352.000000, "Dial Number");
	PlayerTextDrawFont(playerid, Phone[3][playerid], 1);
	PlayerTextDrawLetterSize(playerid, Phone[3][playerid], 0.208333, 0.800000);
	PlayerTextDrawTextSize(playerid, Phone[3][playerid], 552.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, Phone[3][playerid], 0);
	PlayerTextDrawSetShadow(playerid, Phone[3][playerid], 0);
	PlayerTextDrawAlignment(playerid, Phone[3][playerid], 1);
	PlayerTextDrawColor(playerid, Phone[3][playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, Phone[3][playerid], 255);
	PlayerTextDrawBoxColor(playerid, Phone[3][playerid], 421075455);
	PlayerTextDrawUseBox(playerid, Phone[3][playerid], 1);
	PlayerTextDrawSetProportional(playerid, Phone[3][playerid], 1);
	PlayerTextDrawSetSelectable(playerid, Phone[3][playerid], 1);

	Phone[4][playerid] = CreatePlayerTextDraw(playerid, 496.000000, 366.000000, "Send Text");
	PlayerTextDrawFont(playerid, Phone[4][playerid], 1);
	PlayerTextDrawLetterSize(playerid, Phone[4][playerid], 0.208333, 0.800000);
	PlayerTextDrawTextSize(playerid, Phone[4][playerid], 552.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, Phone[4][playerid], 0);
	PlayerTextDrawSetShadow(playerid, Phone[4][playerid], 0);
	PlayerTextDrawAlignment(playerid, Phone[4][playerid], 1);
	PlayerTextDrawColor(playerid, Phone[4][playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, Phone[4][playerid], 255);
	PlayerTextDrawBoxColor(playerid, Phone[4][playerid], 421075455);
	PlayerTextDrawUseBox(playerid, Phone[4][playerid], 1);
	PlayerTextDrawSetProportional(playerid, Phone[4][playerid], 1);
	PlayerTextDrawSetSelectable(playerid, Phone[4][playerid], 1);

	Phone[5][playerid] = CreatePlayerTextDraw(playerid, 496.000000, 380.000000, "My Contacts");
	PlayerTextDrawFont(playerid, Phone[5][playerid], 1);
	PlayerTextDrawLetterSize(playerid, Phone[5][playerid], 0.175000, 0.900000);
	PlayerTextDrawTextSize(playerid, Phone[5][playerid], 552.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, Phone[5][playerid], 0);
	PlayerTextDrawSetShadow(playerid, Phone[5][playerid], 0);
	PlayerTextDrawAlignment(playerid, Phone[5][playerid], 1);
	PlayerTextDrawColor(playerid, Phone[5][playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, Phone[5][playerid], 255);
	PlayerTextDrawBoxColor(playerid, Phone[5][playerid], 421075455);
	PlayerTextDrawUseBox(playerid, Phone[5][playerid], 1);
	PlayerTextDrawSetProportional(playerid, Phone[5][playerid], 1);
	PlayerTextDrawSetSelectable(playerid, Phone[5][playerid], 1);

	Phone[6][playerid] = CreatePlayerTextDraw(playerid, 496.000000, 395.000000, "Settings");
	PlayerTextDrawFont(playerid, Phone[6][playerid], 1);
	PlayerTextDrawLetterSize(playerid, Phone[6][playerid], 0.208333, 0.800000);
	PlayerTextDrawTextSize(playerid, Phone[6][playerid], 552.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, Phone[6][playerid], 0);
	PlayerTextDrawSetShadow(playerid, Phone[6][playerid], 0);
	PlayerTextDrawAlignment(playerid, Phone[6][playerid], 1);
	PlayerTextDrawColor(playerid, Phone[6][playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, Phone[6][playerid], 255);
	PlayerTextDrawBoxColor(playerid, Phone[6][playerid], 421075455);
	PlayerTextDrawUseBox(playerid, Phone[6][playerid], 1);
	PlayerTextDrawSetProportional(playerid, Phone[6][playerid], 1);
	PlayerTextDrawSetSelectable(playerid, Phone[6][playerid], 1);

	Phone[7][playerid] = CreatePlayerTextDraw(playerid, 496.000000, 409.000000, "Turn On/Off");
	PlayerTextDrawFont(playerid, Phone[7][playerid], 1);
	PlayerTextDrawLetterSize(playerid, Phone[7][playerid], 0.208333, 0.800000);
	PlayerTextDrawTextSize(playerid, Phone[7][playerid], 552.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, Phone[7][playerid], 0);
	PlayerTextDrawSetShadow(playerid, Phone[7][playerid], 0);
	PlayerTextDrawAlignment(playerid, Phone[7][playerid], 1);
	PlayerTextDrawColor(playerid, Phone[7][playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, Phone[7][playerid], 255);
	PlayerTextDrawBoxColor(playerid, Phone[7][playerid], 421075455);
	PlayerTextDrawUseBox(playerid, Phone[7][playerid], 1);
	PlayerTextDrawSetProportional(playerid, Phone[7][playerid], 1);
	PlayerTextDrawSetSelectable(playerid, Phone[7][playerid], 1);

	Phone[8][playerid] = CreatePlayerTextDraw(playerid, 553.000000, 335.000000, "20:44");
	PlayerTextDrawFont(playerid, Phone[8][playerid], 1);
	PlayerTextDrawLetterSize(playerid, Phone[8][playerid], 0.208333, 0.800000);
	PlayerTextDrawTextSize(playerid, Phone[8][playerid], 552.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, Phone[8][playerid], 0);
	PlayerTextDrawSetShadow(playerid, Phone[8][playerid], 0);
	PlayerTextDrawAlignment(playerid, Phone[8][playerid], 3);
	PlayerTextDrawColor(playerid, Phone[8][playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, Phone[8][playerid], 255);
	PlayerTextDrawBoxColor(playerid, Phone[8][playerid], 421075455);
	PlayerTextDrawUseBox(playerid, Phone[8][playerid], 0);
	PlayerTextDrawSetProportional(playerid, Phone[8][playerid], 1);
	PlayerTextDrawSetSelectable(playerid, Phone[8][playerid], 1);

	Phone[9][playerid] = CreatePlayerTextDraw(playerid, 553.000000, 422.000000, "~r~Cancel");
	PlayerTextDrawFont(playerid, Phone[9][playerid], 1);
	PlayerTextDrawLetterSize(playerid, Phone[9][playerid], 0.208333, 0.800000);
	PlayerTextDrawTextSize(playerid, Phone[9][playerid], 552.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, Phone[9][playerid], 1);
	PlayerTextDrawSetShadow(playerid, Phone[9][playerid], 0);
	PlayerTextDrawAlignment(playerid, Phone[9][playerid], 3);
	PlayerTextDrawColor(playerid, Phone[9][playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, Phone[9][playerid], 255);
	PlayerTextDrawBoxColor(playerid, Phone[9][playerid], 421075455);
	PlayerTextDrawUseBox(playerid, Phone[9][playerid], 0);
	PlayerTextDrawSetProportional(playerid, Phone[9][playerid], 1);
	PlayerTextDrawSetSelectable(playerid, Phone[9][playerid], 1);

	Phone[10][playerid] = CreatePlayerTextDraw(playerid, 495.000000, 422.000000, "~g~Select");
	PlayerTextDrawFont(playerid, Phone[10][playerid], 1);
	PlayerTextDrawLetterSize(playerid, Phone[10][playerid], 0.208333, 0.800000);
	PlayerTextDrawTextSize(playerid, Phone[10][playerid], 552.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, Phone[10][playerid], 1);
	PlayerTextDrawSetShadow(playerid, Phone[10][playerid], 0);
	PlayerTextDrawAlignment(playerid, Phone[10][playerid], 1);
	PlayerTextDrawColor(playerid, Phone[10][playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, Phone[10][playerid], 255);
	PlayerTextDrawBoxColor(playerid, Phone[10][playerid], 421075455);
	PlayerTextDrawUseBox(playerid, Phone[10][playerid], 0);
	PlayerTextDrawSetProportional(playerid, Phone[10][playerid], 1);
	PlayerTextDrawSetSelectable(playerid, Phone[10][playerid], 1);

	Phone[11][playerid] = CreatePlayerTextDraw(playerid, 513.000000, 334.000000, "[III]");
	PlayerTextDrawFont(playerid, Phone[11][playerid], 1);
	PlayerTextDrawLetterSize(playerid, Phone[11][playerid], 0.208333, 0.900000);
	PlayerTextDrawTextSize(playerid, Phone[11][playerid], 552.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, Phone[11][playerid], 0);
	PlayerTextDrawSetShadow(playerid, Phone[11][playerid], 0);
	PlayerTextDrawAlignment(playerid, Phone[11][playerid], 3);
	PlayerTextDrawColor(playerid, Phone[11][playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, Phone[11][playerid], 255);
	PlayerTextDrawBoxColor(playerid, Phone[11][playerid], 421075455);
	PlayerTextDrawUseBox(playerid, Phone[11][playerid], 0);
	PlayerTextDrawSetProportional(playerid, Phone[11][playerid], 1);
	PlayerTextDrawSetSelectable(playerid, Phone[11][playerid], 1);

	Phone[12][playerid] = CreatePlayerTextDraw(playerid, 524.000000, 437.000000, "_");
	PlayerTextDrawFont(playerid, Phone[12][playerid], 1);
	PlayerTextDrawLetterSize(playerid, Phone[12][playerid], 0.587500, 0.799999);
	PlayerTextDrawTextSize(playerid, Phone[12][playerid], 298.500000, 17.000000);
	PlayerTextDrawSetOutline(playerid, Phone[12][playerid], 1);
	PlayerTextDrawSetShadow(playerid, Phone[12][playerid], 0);
	PlayerTextDrawAlignment(playerid, Phone[12][playerid], 2);
	PlayerTextDrawColor(playerid, Phone[12][playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, Phone[12][playerid], 255);
	PlayerTextDrawBoxColor(playerid, Phone[12][playerid], -1061109505);
	PlayerTextDrawUseBox(playerid, Phone[12][playerid], 1);
	PlayerTextDrawSetProportional(playerid, Phone[12][playerid], 1);
	PlayerTextDrawSetSelectable(playerid, Phone[12][playerid], 0);

	Phone[13][playerid] = CreatePlayerTextDraw(playerid, 524.000000, 438.000000, "_");
	PlayerTextDrawFont(playerid, Phone[13][playerid], 1);
	PlayerTextDrawLetterSize(playerid, Phone[13][playerid], 0.600000, 0.649999);
	PlayerTextDrawTextSize(playerid, Phone[13][playerid], 298.500000, 15.000000);
	PlayerTextDrawSetOutline(playerid, Phone[13][playerid], 1);
	PlayerTextDrawSetShadow(playerid, Phone[13][playerid], 0);
	PlayerTextDrawAlignment(playerid, Phone[13][playerid], 2);
	PlayerTextDrawColor(playerid, Phone[13][playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, Phone[13][playerid], 255);
	PlayerTextDrawBoxColor(playerid, Phone[13][playerid], 421075455);
	PlayerTextDrawUseBox(playerid, Phone[13][playerid], 1);
	PlayerTextDrawSetProportional(playerid, Phone[13][playerid], 1);
	PlayerTextDrawSetSelectable(playerid, Phone[13][playerid], 0);
}

CreateMDCTextDraws(playerid)
{
	MDC[0][playerid] = CreatePlayerTextDraw(playerid, 321.000000, 169.000000, "_");
	PlayerTextDrawFont(playerid, MDC[0][playerid], 1);
	PlayerTextDrawLetterSize(playerid, MDC[0][playerid], 0.600000, 16.050014);
	PlayerTextDrawTextSize(playerid, MDC[0][playerid], 298.500000, 172.500000);
	PlayerTextDrawSetOutline(playerid, MDC[0][playerid], 1);
	PlayerTextDrawSetShadow(playerid, MDC[0][playerid], 0);
	PlayerTextDrawAlignment(playerid, MDC[0][playerid], 2);
	PlayerTextDrawColor(playerid, MDC[0][playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, MDC[0][playerid], 255);
	PlayerTextDrawBoxColor(playerid, MDC[0][playerid], 336860671);
	PlayerTextDrawUseBox(playerid, MDC[0][playerid], 1);
	PlayerTextDrawSetProportional(playerid, MDC[0][playerid], 1);
	PlayerTextDrawSetSelectable(playerid, MDC[0][playerid], 0);

	MDC[1][playerid] = CreatePlayerTextDraw(playerid, 321.000000, 181.000000, "_");
	PlayerTextDrawFont(playerid, MDC[1][playerid], 1);
	PlayerTextDrawLetterSize(playerid, MDC[1][playerid], 0.579164, 12.850003);
	PlayerTextDrawTextSize(playerid, MDC[1][playerid], 298.500000, 154.000000);
	PlayerTextDrawSetOutline(playerid, MDC[1][playerid], 1);
	PlayerTextDrawSetShadow(playerid, MDC[1][playerid], 0);
	PlayerTextDrawAlignment(playerid, MDC[1][playerid], 2);
	PlayerTextDrawColor(playerid, MDC[1][playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, MDC[1][playerid], 255);
	PlayerTextDrawBoxColor(playerid, MDC[1][playerid], 868863);
	PlayerTextDrawUseBox(playerid, MDC[1][playerid], 1);
	PlayerTextDrawSetProportional(playerid, MDC[1][playerid], 1);
	PlayerTextDrawSetSelectable(playerid, MDC[1][playerid], 0);

	MDC[2][playerid] = CreatePlayerTextDraw(playerid, 321.000000, 201.000000, "_");
	PlayerTextDrawFont(playerid, MDC[2][playerid], 1);
	PlayerTextDrawLetterSize(playerid, MDC[2][playerid], 0.579164, -0.299997);
	PlayerTextDrawTextSize(playerid, MDC[2][playerid], 298.500000, 151.500000);
	PlayerTextDrawSetOutline(playerid, MDC[2][playerid], 1);
	PlayerTextDrawSetShadow(playerid, MDC[2][playerid], 0);
	PlayerTextDrawAlignment(playerid, MDC[2][playerid], 2);
	PlayerTextDrawColor(playerid, MDC[2][playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, MDC[2][playerid], 255);
	PlayerTextDrawBoxColor(playerid, MDC[2][playerid], -2686721);
	PlayerTextDrawUseBox(playerid, MDC[2][playerid], 1);
	PlayerTextDrawSetProportional(playerid, MDC[2][playerid], 1);
	PlayerTextDrawSetSelectable(playerid, MDC[2][playerid], 0);

	MDC[3][playerid] = CreatePlayerTextDraw(playerid, 321.000000, 292.000000, "_");
	PlayerTextDrawFont(playerid, MDC[3][playerid], 1);
	PlayerTextDrawLetterSize(playerid, MDC[3][playerid], 0.579164, -0.299997);
	PlayerTextDrawTextSize(playerid, MDC[3][playerid], 298.500000, 152.500000);
	PlayerTextDrawSetOutline(playerid, MDC[3][playerid], 1);
	PlayerTextDrawSetShadow(playerid, MDC[3][playerid], 0);
	PlayerTextDrawAlignment(playerid, MDC[3][playerid], 2);
	PlayerTextDrawColor(playerid, MDC[3][playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, MDC[3][playerid], 255);
	PlayerTextDrawBoxColor(playerid, MDC[3][playerid], -2686721);
	PlayerTextDrawUseBox(playerid, MDC[3][playerid], 1);
	PlayerTextDrawSetProportional(playerid, MDC[3][playerid], 1);
	PlayerTextDrawSetSelectable(playerid, MDC[3][playerid], 0);

	MDC[4][playerid] = CreatePlayerTextDraw(playerid, 286.000000, 179.000000, "SAN ANDREAS POLICE DEPARTEMENT");
	PlayerTextDrawFont(playerid, MDC[4][playerid], 1);
	PlayerTextDrawLetterSize(playerid, MDC[4][playerid], 0.187500, 1.149999);
	PlayerTextDrawTextSize(playerid, MDC[4][playerid], 400.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, MDC[4][playerid], 0);
	PlayerTextDrawSetShadow(playerid, MDC[4][playerid], 0);
	PlayerTextDrawAlignment(playerid, MDC[4][playerid], 1);
	PlayerTextDrawColor(playerid, MDC[4][playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, MDC[4][playerid], 255);
	PlayerTextDrawBoxColor(playerid, MDC[4][playerid], 50);
	PlayerTextDrawUseBox(playerid, MDC[4][playerid], 0);
	PlayerTextDrawSetProportional(playerid, MDC[4][playerid], 1);
	PlayerTextDrawSetSelectable(playerid, MDC[4][playerid], 0);

	MDC[5][playerid] = CreatePlayerTextDraw(playerid, 322.000000, 189.000000, "PROTECTING SAN ANDREAS");
	PlayerTextDrawFont(playerid, MDC[5][playerid], 1);
	PlayerTextDrawLetterSize(playerid, MDC[5][playerid], 0.166666, 0.800000);
	PlayerTextDrawTextSize(playerid, MDC[5][playerid], 400.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, MDC[5][playerid], 0);
	PlayerTextDrawSetShadow(playerid, MDC[5][playerid], 0);
	PlayerTextDrawAlignment(playerid, MDC[5][playerid], 1);
	PlayerTextDrawColor(playerid, MDC[5][playerid], 1097458175);
	PlayerTextDrawBackgroundColor(playerid, MDC[5][playerid], 255);
	PlayerTextDrawBoxColor(playerid, MDC[5][playerid], 50);
	PlayerTextDrawUseBox(playerid, MDC[5][playerid], 0);
	PlayerTextDrawSetProportional(playerid, MDC[5][playerid], 1);
	PlayerTextDrawSetSelectable(playerid, MDC[5][playerid], 0);

	MDC[6][playerid] = CreatePlayerTextDraw(playerid, 261.000000, 172.000000, "_");
	PlayerTextDrawFont(playerid, MDC[6][playerid], 1);
	PlayerTextDrawLetterSize(playerid, MDC[6][playerid], 0.541665, 0.100000);
	PlayerTextDrawTextSize(playerid, MDC[6][playerid], 298.500000, -1.000000);
	PlayerTextDrawSetOutline(playerid, MDC[6][playerid], 0);
	PlayerTextDrawSetShadow(playerid, MDC[6][playerid], 0);
	PlayerTextDrawAlignment(playerid, MDC[6][playerid], 2);
	PlayerTextDrawColor(playerid, MDC[6][playerid], 761337599);
	PlayerTextDrawBackgroundColor(playerid, MDC[6][playerid], 255);
	PlayerTextDrawBoxColor(playerid, MDC[6][playerid], 9109759);
	PlayerTextDrawUseBox(playerid, MDC[6][playerid], 1);
	PlayerTextDrawSetProportional(playerid, MDC[6][playerid], 1);
	PlayerTextDrawSetSelectable(playerid, MDC[6][playerid], 0);

	MDC[7][playerid] = CreatePlayerTextDraw(playerid, 251.000000, 172.000000, "_");
	PlayerTextDrawFont(playerid, MDC[7][playerid], 1);
	PlayerTextDrawLetterSize(playerid, MDC[7][playerid], 0.541665, 0.100000);
	PlayerTextDrawTextSize(playerid, MDC[7][playerid], 298.500000, -1.000000);
	PlayerTextDrawSetOutline(playerid, MDC[7][playerid], 0);
	PlayerTextDrawSetShadow(playerid, MDC[7][playerid], 0);
	PlayerTextDrawAlignment(playerid, MDC[7][playerid], 2);
	PlayerTextDrawColor(playerid, MDC[7][playerid], 761337599);
	PlayerTextDrawBackgroundColor(playerid, MDC[7][playerid], 255);
	PlayerTextDrawBoxColor(playerid, MDC[7][playerid], -1962934017);
	PlayerTextDrawUseBox(playerid, MDC[7][playerid], 1);
	PlayerTextDrawSetProportional(playerid, MDC[7][playerid], 1);
	PlayerTextDrawSetSelectable(playerid, MDC[7][playerid], 0);

	MDC[8][playerid] = CreatePlayerTextDraw(playerid, 256.000000, 172.000000, "_");
	PlayerTextDrawFont(playerid, MDC[8][playerid], 1);
	PlayerTextDrawLetterSize(playerid, MDC[8][playerid], 0.541665, 0.100000);
	PlayerTextDrawTextSize(playerid, MDC[8][playerid], 298.500000, -1.000000);
	PlayerTextDrawSetOutline(playerid, MDC[8][playerid], 2);
	PlayerTextDrawSetShadow(playerid, MDC[8][playerid], 0);
	PlayerTextDrawAlignment(playerid, MDC[8][playerid], 2);
	PlayerTextDrawColor(playerid, MDC[8][playerid], 761337599);
	PlayerTextDrawBackgroundColor(playerid, MDC[8][playerid], 255);
	PlayerTextDrawBoxColor(playerid, MDC[8][playerid], -1962934017);
	PlayerTextDrawUseBox(playerid, MDC[8][playerid], 1);
	PlayerTextDrawSetProportional(playerid, MDC[8][playerid], 1);
	PlayerTextDrawSetSelectable(playerid, MDC[8][playerid], 0);

	MDC[9][playerid] = CreatePlayerTextDraw(playerid, 245.000000, 211.000000, "- Given Charges");
	PlayerTextDrawFont(playerid, MDC[9][playerid], 1);
	PlayerTextDrawLetterSize(playerid, MDC[9][playerid], 0.254166, 1.200000);
	PlayerTextDrawTextSize(playerid, MDC[9][playerid], 397.000000, 18.500000);
	PlayerTextDrawSetOutline(playerid, MDC[9][playerid], 0);
	PlayerTextDrawSetShadow(playerid, MDC[9][playerid], 0);
	PlayerTextDrawAlignment(playerid, MDC[9][playerid], 1);
	PlayerTextDrawColor(playerid, MDC[9][playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, MDC[9][playerid], 255);
	PlayerTextDrawBoxColor(playerid, MDC[9][playerid], 1097457970);
	PlayerTextDrawUseBox(playerid, MDC[9][playerid], 1);
	PlayerTextDrawSetProportional(playerid, MDC[9][playerid], 1);
	PlayerTextDrawSetSelectable(playerid, MDC[9][playerid], 1);

	MDC[10][playerid] = CreatePlayerTextDraw(playerid, 245.000000, 232.000000, "- Name Search");
	PlayerTextDrawFont(playerid, MDC[10][playerid], 1);
	PlayerTextDrawLetterSize(playerid, MDC[10][playerid], 0.254166, 1.200000);
	PlayerTextDrawTextSize(playerid, MDC[10][playerid], 397.000000, 18.500000);
	PlayerTextDrawSetOutline(playerid, MDC[10][playerid], 0);
	PlayerTextDrawSetShadow(playerid, MDC[10][playerid], 0);
	PlayerTextDrawAlignment(playerid, MDC[10][playerid], 1);
	PlayerTextDrawColor(playerid, MDC[10][playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, MDC[10][playerid], 255);
	PlayerTextDrawBoxColor(playerid, MDC[10][playerid], 1097457970);
	PlayerTextDrawUseBox(playerid, MDC[10][playerid], 1);
	PlayerTextDrawSetProportional(playerid, MDC[10][playerid], 1);
	PlayerTextDrawSetSelectable(playerid, MDC[10][playerid], 1);

	MDC[11][playerid] = CreatePlayerTextDraw(playerid, 245.000000, 253.000000, "- Plates Search");
	PlayerTextDrawFont(playerid, MDC[11][playerid], 1);
	PlayerTextDrawLetterSize(playerid, MDC[11][playerid], 0.254166, 1.200000);
	PlayerTextDrawTextSize(playerid, MDC[11][playerid], 397.000000, 18.500000);
	PlayerTextDrawSetOutline(playerid, MDC[11][playerid], 0);
	PlayerTextDrawSetShadow(playerid, MDC[11][playerid], 0);
	PlayerTextDrawAlignment(playerid, MDC[11][playerid], 1);
	PlayerTextDrawColor(playerid, MDC[11][playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, MDC[11][playerid], 255);
	PlayerTextDrawBoxColor(playerid, MDC[11][playerid], 1097457970);
	PlayerTextDrawUseBox(playerid, MDC[11][playerid], 1);
	PlayerTextDrawSetProportional(playerid, MDC[11][playerid], 1);
	PlayerTextDrawSetSelectable(playerid, MDC[11][playerid], 1);

	MDC[12][playerid] = CreatePlayerTextDraw(playerid, 245.000000, 273.000000, "- Police Backup");
	PlayerTextDrawFont(playerid, MDC[12][playerid], 1);
	PlayerTextDrawLetterSize(playerid, MDC[12][playerid], 0.254166, 1.200000);
	PlayerTextDrawTextSize(playerid, MDC[12][playerid], 397.000000, 18.500000);
	PlayerTextDrawSetOutline(playerid, MDC[12][playerid], 0);
	PlayerTextDrawSetShadow(playerid, MDC[12][playerid], 0);
	PlayerTextDrawAlignment(playerid, MDC[12][playerid], 1);
	PlayerTextDrawColor(playerid, MDC[12][playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, MDC[12][playerid], 255);
	PlayerTextDrawBoxColor(playerid, MDC[12][playerid], 1097457970);
	PlayerTextDrawUseBox(playerid, MDC[12][playerid], 1);
	PlayerTextDrawSetProportional(playerid, MDC[12][playerid], 1);
	PlayerTextDrawSetSelectable(playerid, MDC[12][playerid], 1);

	MDC[13][playerid] = CreatePlayerTextDraw(playerid, 321.000000, 304.000000, "_");
	PlayerTextDrawFont(playerid, MDC[13][playerid], 1);
	PlayerTextDrawLetterSize(playerid, MDC[13][playerid], 0.600000, 0.700012);
	PlayerTextDrawTextSize(playerid, MDC[13][playerid], 298.500000, 12.500000);
	PlayerTextDrawSetOutline(playerid, MDC[13][playerid], 1);
	PlayerTextDrawSetShadow(playerid, MDC[13][playerid], 0);
	PlayerTextDrawAlignment(playerid, MDC[13][playerid], 2);
	PlayerTextDrawColor(playerid, MDC[13][playerid], 1296911871);
	PlayerTextDrawBackgroundColor(playerid, MDC[13][playerid], 255);
	PlayerTextDrawBoxColor(playerid, MDC[13][playerid], 1296911871);
	PlayerTextDrawUseBox(playerid, MDC[13][playerid], 1);
	PlayerTextDrawSetProportional(playerid, MDC[13][playerid], 1);
	PlayerTextDrawSetSelectable(playerid, MDC[13][playerid], 1);
}

CreateHotwireTextDraws(playerid)
{
	new indices[8];
    for (new i = 0; i < 8; i++)
    {
        indices[i] = i;
    }

    // Shuffling the indices
    for (new i = 0; i < 8; i++)
    {
        new rnd = random(8);
        new temp = indices[i];
        indices[i] = indices[rnd];
        indices[rnd] = temp;
    }

	for (new i = 0; i < 8; i++)
    {
		new Float:posX = 357.0 + (i % 4) * 50.0;
		new Float:posY = 269.0 + (i / 4) * 80.0;

		new Float:posaX = 361.0 + (i % 4) * 50.0;
		new Float:posaY = 280.0 + (i / 4) * 80.0;

		if (i >= 4)
        {
            posaY -= 25.0;
        }

		HotwireCable[playerid][i] = CreatePlayerTextDraw(playerid, posaX, posaY, "ld_bum:blkdot");
		HotwireTDB[playerid][i] = CreatePlayerTextDraw(playerid, posX, posY, "ld_bum:blkdot");
		HotwireTD[playerid][i] = CreatePlayerTextDraw(playerid, posX, posY, "ld_bum:blkdot");
		
	}
}

CreateNotificationTextDraws(playerid)
{
	Footers[playerid] = CreatePlayerTextDraw(playerid, 321.000000, 384.000000, "Press 'RETURN' to enter~n~~w~Memphis street Liquor store~n~Memphis Street, Playa Del Seville");
	PlayerTextDrawFont(playerid, Footers[playerid], 1);
	PlayerTextDrawLetterSize(playerid, Footers[playerid], 0.329158, 1.049993);
	PlayerTextDrawTextSize(playerid, Footers[playerid], 502.500000, 306.500000);
	PlayerTextDrawSetOutline(playerid, Footers[playerid], 0);
	PlayerTextDrawSetShadow(playerid, Footers[playerid], 1);
	PlayerTextDrawAlignment(playerid, Footers[playerid], 2);
	PlayerTextDrawColor(playerid, Footers[playerid], -65281);
	PlayerTextDrawBackgroundColor(playerid, Footers[playerid], 255);
	PlayerTextDrawBoxColor(playerid, Footers[playerid], 50);
	PlayerTextDrawUseBox(playerid, Footers[playerid], 0);
	PlayerTextDrawSetProportional(playerid, Footers[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, Footers[playerid], 0);

	Subtittles[playerid] = CreatePlayerTextDraw(playerid, 321.000000, 376.000000, "The engine of this vehicle is off.~n~Use /engine to turn it on or /hotwire to hotwire it.");
	PlayerTextDrawFont(playerid, Subtittles[playerid], 1);
	PlayerTextDrawLetterSize(playerid, Subtittles[playerid], 0.291658, 1.149992);
	PlayerTextDrawTextSize(playerid, Subtittles[playerid], 502.500000, 306.500000);
	PlayerTextDrawSetOutline(playerid, Subtittles[playerid], 0);
	PlayerTextDrawSetShadow(playerid, Subtittles[playerid], 1);
	PlayerTextDrawAlignment(playerid, Subtittles[playerid], 2);
	PlayerTextDrawColor(playerid, Subtittles[playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, Subtittles[playerid], 255);
	PlayerTextDrawBoxColor(playerid, Subtittles[playerid], 50);
	PlayerTextDrawUseBox(playerid, Subtittles[playerid], 0);
	PlayerTextDrawSetProportional(playerid, Subtittles[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, Subtittles[playerid], 0);

	Messages[playerid] = CreatePlayerTextDraw(playerid, 5.000000, 254.000000, "The engine of this vehicle is off.~n~Use /engine to turn it on or /hotwire to hotwire it.");
	PlayerTextDrawFont(playerid, Messages[playerid], 1);
	PlayerTextDrawLetterSize(playerid, Messages[playerid], 0.258325, 1.199992);
	PlayerTextDrawTextSize(playerid, Messages[playerid], 144.000000, 323.500000);
	PlayerTextDrawSetOutline(playerid, Messages[playerid], 0);
	PlayerTextDrawSetShadow(playerid, Messages[playerid], 0);
	PlayerTextDrawAlignment(playerid, Messages[playerid], 1);
	PlayerTextDrawColor(playerid, Messages[playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, Messages[playerid], 255);
	PlayerTextDrawBoxColor(playerid, Messages[playerid], 225);
	PlayerTextDrawUseBox(playerid, Messages[playerid], 1);
	PlayerTextDrawSetProportional(playerid, Messages[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, Messages[playerid], 0);

	money[playerid] = CreatePlayerTextDraw(playerid, 607.000000, 97.000000, "~g~+1000");
	PlayerTextDrawFont(playerid, money[playerid], 3);
	PlayerTextDrawLetterSize(playerid, money[playerid], 0.270833, 1.050000);
	PlayerTextDrawTextSize(playerid, money[playerid], 400.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, money[playerid], 1);
	PlayerTextDrawSetShadow(playerid, money[playerid], 0);
	PlayerTextDrawAlignment(playerid, money[playerid], 3);
	PlayerTextDrawColor(playerid, money[playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, money[playerid], 255);
	PlayerTextDrawBoxColor(playerid, money[playerid], 50);
	PlayerTextDrawUseBox(playerid, money[playerid], 0);
	PlayerTextDrawSetProportional(playerid, money[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, money[playerid], 0);

	MoneyFormat[playerid] = CreatePlayerTextDraw(playerid, 586.000000, 79.000000, "~g~,    .");
	PlayerTextDrawFont(playerid, MoneyFormat[playerid], 3);
	PlayerTextDrawLetterSize(playerid, MoneyFormat[playerid], 0.495833, 2.249997);
	PlayerTextDrawTextSize(playerid, MoneyFormat[playerid], 400.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, MoneyFormat[playerid], 1);
	PlayerTextDrawSetShadow(playerid, MoneyFormat[playerid], 0);
	PlayerTextDrawAlignment(playerid, MoneyFormat[playerid], 3);
	PlayerTextDrawColor(playerid, MoneyFormat[playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, MoneyFormat[playerid], 255);
	PlayerTextDrawBoxColor(playerid, MoneyFormat[playerid], 50);
	PlayerTextDrawUseBox(playerid, MoneyFormat[playerid], 0);
	PlayerTextDrawSetProportional(playerid, MoneyFormat[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, MoneyFormat[playerid], 0);
}

CreateHUDTextDraws(playerid)
{
	Street[1][playerid] = CreatePlayerTextDraw(playerid, 147.000000, 387.000000, "Artesia Avenue ~n~Los santos");
	PlayerTextDrawFont(playerid, Street[1][playerid], 1);
	PlayerTextDrawLetterSize(playerid, Street[1][playerid], 0.166667, 1.000000);
	PlayerTextDrawTextSize(playerid, Street[1][playerid], 400.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, Street[1][playerid], 1);
	PlayerTextDrawSetShadow(playerid, Street[1][playerid], 0);
	PlayerTextDrawAlignment(playerid, Street[1][playerid], 1);
	PlayerTextDrawColor(playerid, Street[1][playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, Street[1][playerid], 255);
	PlayerTextDrawBoxColor(playerid, Street[1][playerid], 50);
	PlayerTextDrawUseBox(playerid, Street[1][playerid], 0);
	PlayerTextDrawSetProportional(playerid, Street[1][playerid], 1);
	PlayerTextDrawSetSelectable(playerid, Street[1][playerid], 0);

	Street[0][playerid] = CreatePlayerTextDraw(playerid, 131.000000, 389.000000, "SW");
	PlayerTextDrawFont(playerid, Street[0][playerid], 1);
	PlayerTextDrawLetterSize(playerid, Street[0][playerid], 0.229167, 1.550000);
	PlayerTextDrawTextSize(playerid, Street[0][playerid], 400.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, Street[0][playerid], 1);
	PlayerTextDrawSetShadow(playerid, Street[0][playerid], 0);
	PlayerTextDrawAlignment(playerid, Street[0][playerid], 1);
	PlayerTextDrawColor(playerid, Street[0][playerid], 1097458175);
	PlayerTextDrawBackgroundColor(playerid, Street[0][playerid], 255);
	PlayerTextDrawBoxColor(playerid, Street[0][playerid], 50);
	PlayerTextDrawUseBox(playerid, Street[0][playerid], 0);
	PlayerTextDrawSetProportional(playerid, Street[0][playerid], 1);
	PlayerTextDrawSetSelectable(playerid, Street[0][playerid], 0);

	WeaponType[playerid] = CreatePlayerTextDraw(playerid, 499.000000, 111.000000, "Desert Eagle - 100 Regular");
	PlayerTextDrawFont(playerid, WeaponType[playerid], 1);
	PlayerTextDrawLetterSize(playerid, WeaponType[playerid], 0.170825, 0.899993);
	PlayerTextDrawTextSize(playerid, WeaponType[playerid], 606.000000, 47.500000);
	PlayerTextDrawSetOutline(playerid, WeaponType[playerid], 1);
	PlayerTextDrawSetShadow(playerid, WeaponType[playerid], 0);
	PlayerTextDrawAlignment(playerid, WeaponType[playerid], 1);
	PlayerTextDrawColor(playerid, WeaponType[playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, WeaponType[playerid], 255);
	PlayerTextDrawBoxColor(playerid, WeaponType[playerid], 230);
	PlayerTextDrawUseBox(playerid, WeaponType[playerid], 1);
	PlayerTextDrawSetProportional(playerid, WeaponType[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, WeaponType[playerid], 0);
}

CreateBarInfoTextDraws(playerid)
{
	HeaderTD[0][playerid] = CreatePlayerTextDraw(playerid, 489.000000, 155.000000, "You have started the extorting in Pawnstore Plaza.~n~~n~Hit the store clerk to break them. When the extortion bar is full use /e");
	PlayerTextDrawFont(playerid, HeaderTD[0][playerid], 1);
	PlayerTextDrawLetterSize(playerid, HeaderTD[0][playerid], 0.212497, 0.649996);
	PlayerTextDrawTextSize(playerid, HeaderTD[0][playerid], 615.500000, 19.500000);
	PlayerTextDrawSetOutline(playerid, HeaderTD[0][playerid], 1);
	PlayerTextDrawSetShadow(playerid, HeaderTD[0][playerid], 0);
	PlayerTextDrawAlignment(playerid, HeaderTD[0][playerid], 1);
	PlayerTextDrawColor(playerid, HeaderTD[0][playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, HeaderTD[0][playerid], 255);
	PlayerTextDrawBoxColor(playerid, HeaderTD[0][playerid], 225);
	PlayerTextDrawUseBox(playerid, HeaderTD[0][playerid], 1);
	PlayerTextDrawSetProportional(playerid, HeaderTD[0][playerid], 1);
	PlayerTextDrawSetSelectable(playerid, HeaderTD[0][playerid], 0);

	HeaderTD[1][playerid] = CreatePlayerTextDraw(playerid, 488.000000, 145.000000, "Extortion");
	PlayerTextDrawFont(playerid, HeaderTD[1][playerid], 0);
	PlayerTextDrawLetterSize(playerid, HeaderTD[1][playerid], 0.320831, 1.099997);
	PlayerTextDrawTextSize(playerid, HeaderTD[1][playerid], 605.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, HeaderTD[1][playerid], 1);
	PlayerTextDrawSetShadow(playerid, HeaderTD[1][playerid], 0);
	PlayerTextDrawAlignment(playerid, HeaderTD[1][playerid], 1);
	PlayerTextDrawColor(playerid, HeaderTD[1][playerid], -1379670017);
	PlayerTextDrawBackgroundColor(playerid, HeaderTD[1][playerid], 255);
	PlayerTextDrawBoxColor(playerid, HeaderTD[1][playerid], 200);
	PlayerTextDrawUseBox(playerid, HeaderTD[1][playerid], 0);
	PlayerTextDrawSetProportional(playerid, HeaderTD[1][playerid], 1);
	PlayerTextDrawSetSelectable(playerid, HeaderTD[1][playerid], 0);

	GameBar[2][playerid] = CreatePlayerTextDraw(playerid, 554.000000, 131.000000, "_");
	PlayerTextDrawFont(playerid, GameBar[2][playerid], 1);
	PlayerTextDrawLetterSize(playerid, GameBar[2][playerid], 0.600000, 0.949998);
	PlayerTextDrawTextSize(playerid, GameBar[2][playerid], 298.000000, 108.000000);
	PlayerTextDrawSetOutline(playerid, GameBar[2][playerid], 1);
	PlayerTextDrawSetShadow(playerid, GameBar[2][playerid], 0);
	PlayerTextDrawAlignment(playerid, GameBar[2][playerid], 2);
	PlayerTextDrawColor(playerid, GameBar[2][playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, GameBar[2][playerid], 255);
	PlayerTextDrawBoxColor(playerid, GameBar[2][playerid], 255);
	PlayerTextDrawUseBox(playerid, GameBar[2][playerid], 1);
	PlayerTextDrawSetProportional(playerid, GameBar[2][playerid], 1);
	PlayerTextDrawSetSelectable(playerid, GameBar[2][playerid], 0);

	GameBar[0][playerid] = CreatePlayerTextDraw(playerid, 498.000000, 121.000000, "Extortion");
	PlayerTextDrawFont(playerid, GameBar[0][playerid], 0);
	PlayerTextDrawLetterSize(playerid, GameBar[0][playerid], 0.324997, 0.999997);
	PlayerTextDrawTextSize(playerid, GameBar[0][playerid], 605.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, GameBar[0][playerid], 1);
	PlayerTextDrawSetShadow(playerid, GameBar[0][playerid], 0);
	PlayerTextDrawAlignment(playerid, GameBar[0][playerid], 1);
	PlayerTextDrawColor(playerid, GameBar[0][playerid], -1379670017);
	PlayerTextDrawBackgroundColor(playerid, GameBar[0][playerid], 255);
	PlayerTextDrawBoxColor(playerid, GameBar[0][playerid], 200);
	PlayerTextDrawUseBox(playerid, GameBar[0][playerid], 0);
	PlayerTextDrawSetProportional(playerid, GameBar[0][playerid], 1);
	PlayerTextDrawSetSelectable(playerid, GameBar[0][playerid], 0);

	HeaderBar[playerid] = CreatePlayerProgressBar(playerid, 502.000000, 133.000000, 108.500000, 4.500000, -1, 100.000000, 0);
}

CreateBlackJackTextDraws(playerid)
{
	blackjack[0][playerid] = CreatePlayerTextDraw(playerid, 322.000000, 176.000000, "_");
	PlayerTextDrawFont(playerid, blackjack[0][playerid], 1);
	PlayerTextDrawLetterSize(playerid, blackjack[0][playerid], 0.600000, 14.200002);
	PlayerTextDrawTextSize(playerid, blackjack[0][playerid], 298.500000, 239.500000);
	PlayerTextDrawSetOutline(playerid, blackjack[0][playerid], 1);
	PlayerTextDrawSetShadow(playerid, blackjack[0][playerid], 0);
	PlayerTextDrawAlignment(playerid, blackjack[0][playerid], 2);
	PlayerTextDrawColor(playerid, blackjack[0][playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, blackjack[0][playerid], 255);
	PlayerTextDrawBoxColor(playerid, blackjack[0][playerid], 230);
	PlayerTextDrawUseBox(playerid, blackjack[0][playerid], 1);
	PlayerTextDrawSetProportional(playerid, blackjack[0][playerid], 1);
	PlayerTextDrawSetSelectable(playerid, blackjack[0][playerid], 0);

	blackjack[1][playerid] = CreatePlayerTextDraw(playerid, 205.000000, 238.000000, "Player Cards");
	PlayerTextDrawFont(playerid, blackjack[1][playerid], 1);
	PlayerTextDrawLetterSize(playerid, blackjack[1][playerid], 0.233333, 0.950000);
	PlayerTextDrawTextSize(playerid, blackjack[1][playerid], 400.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, blackjack[1][playerid], 1);
	PlayerTextDrawSetShadow(playerid, blackjack[1][playerid], 0);
	PlayerTextDrawAlignment(playerid, blackjack[1][playerid], 1);
	PlayerTextDrawColor(playerid, blackjack[1][playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, blackjack[1][playerid], 255);
	PlayerTextDrawBoxColor(playerid, blackjack[1][playerid], 50);
	PlayerTextDrawUseBox(playerid, blackjack[1][playerid], 0);
	PlayerTextDrawSetProportional(playerid, blackjack[1][playerid], 1);
	PlayerTextDrawSetSelectable(playerid, blackjack[1][playerid], 0);

	blackjack[2][playerid] = CreatePlayerTextDraw(playerid, 205.000000, 177.000000, "Dealer Cards");
	PlayerTextDrawFont(playerid, blackjack[2][playerid], 1);
	PlayerTextDrawLetterSize(playerid, blackjack[2][playerid], 0.241667, 0.950000);
	PlayerTextDrawTextSize(playerid, blackjack[2][playerid], 400.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, blackjack[2][playerid], 1);
	PlayerTextDrawSetShadow(playerid, blackjack[2][playerid], 0);
	PlayerTextDrawAlignment(playerid, blackjack[2][playerid], 1);
	PlayerTextDrawColor(playerid, blackjack[2][playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, blackjack[2][playerid], 255);
	PlayerTextDrawBoxColor(playerid, blackjack[2][playerid], 50);
	PlayerTextDrawUseBox(playerid, blackjack[2][playerid], 0);
	PlayerTextDrawSetProportional(playerid, blackjack[2][playerid], 1);
	PlayerTextDrawSetSelectable(playerid, blackjack[2][playerid], 0);

	blackjack[3][playerid] = CreatePlayerTextDraw(playerid, 209.000000, 252.000000, "ld_card:cdback");
	PlayerTextDrawFont(playerid, blackjack[3][playerid], 4);
	PlayerTextDrawLetterSize(playerid, blackjack[3][playerid], 0.600000, 2.000000);
	PlayerTextDrawTextSize(playerid, blackjack[3][playerid], 38.000000, 42.500000);
	PlayerTextDrawSetOutline(playerid, blackjack[3][playerid], 1);
	PlayerTextDrawSetShadow(playerid, blackjack[3][playerid], 0);
	PlayerTextDrawAlignment(playerid, blackjack[3][playerid], 1);
	PlayerTextDrawColor(playerid, blackjack[3][playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, blackjack[3][playerid], 255);
	PlayerTextDrawBoxColor(playerid, blackjack[3][playerid], 50);
	PlayerTextDrawUseBox(playerid, blackjack[3][playerid], 1);
	PlayerTextDrawSetProportional(playerid, blackjack[3][playerid], 1);
	PlayerTextDrawSetSelectable(playerid, blackjack[3][playerid], 0);

	blackjack[4][playerid] = CreatePlayerTextDraw(playerid, 255.000000, 252.000000, "ld_card:cdback");
	PlayerTextDrawFont(playerid, blackjack[4][playerid], 4);
	PlayerTextDrawLetterSize(playerid, blackjack[4][playerid], 0.600000, 2.000000);
	PlayerTextDrawTextSize(playerid, blackjack[4][playerid], 38.000000, 42.500000);
	PlayerTextDrawSetOutline(playerid, blackjack[4][playerid], 1);
	PlayerTextDrawSetShadow(playerid, blackjack[4][playerid], 0);
	PlayerTextDrawAlignment(playerid, blackjack[4][playerid], 1);
	PlayerTextDrawColor(playerid, blackjack[4][playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, blackjack[4][playerid], 255);
	PlayerTextDrawBoxColor(playerid, blackjack[4][playerid], 50);
	PlayerTextDrawUseBox(playerid, blackjack[4][playerid], 1);
	PlayerTextDrawSetProportional(playerid, blackjack[4][playerid], 1);
	PlayerTextDrawSetSelectable(playerid, blackjack[4][playerid], 0);

	blackjack[5][playerid] = CreatePlayerTextDraw(playerid, 303.000000, 252.000000, "ld_card:cdback");
	PlayerTextDrawFont(playerid, blackjack[5][playerid], 4);
	PlayerTextDrawLetterSize(playerid, blackjack[5][playerid], 0.600000, 2.000000);
	PlayerTextDrawTextSize(playerid, blackjack[5][playerid], 38.000000, 42.500000);
	PlayerTextDrawSetOutline(playerid, blackjack[5][playerid], 1);
	PlayerTextDrawSetShadow(playerid, blackjack[5][playerid], 0);
	PlayerTextDrawAlignment(playerid, blackjack[5][playerid], 1);
	PlayerTextDrawColor(playerid, blackjack[5][playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, blackjack[5][playerid], 255);
	PlayerTextDrawBoxColor(playerid, blackjack[5][playerid], 50);
	PlayerTextDrawUseBox(playerid, blackjack[5][playerid], 1);
	PlayerTextDrawSetProportional(playerid, blackjack[5][playerid], 1);
	PlayerTextDrawSetSelectable(playerid, blackjack[5][playerid], 0);

	blackjack[6][playerid] = CreatePlayerTextDraw(playerid, 351.000000, 252.000000, "ld_card:cdback");
	PlayerTextDrawFont(playerid, blackjack[6][playerid], 4);
	PlayerTextDrawLetterSize(playerid, blackjack[6][playerid], 0.600000, 2.000000);
	PlayerTextDrawTextSize(playerid, blackjack[6][playerid], 38.000000, 42.500000);
	PlayerTextDrawSetOutline(playerid, blackjack[6][playerid], 1);
	PlayerTextDrawSetShadow(playerid, blackjack[6][playerid], 0);
	PlayerTextDrawAlignment(playerid, blackjack[6][playerid], 1);
	PlayerTextDrawColor(playerid, blackjack[6][playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, blackjack[6][playerid], 255);
	PlayerTextDrawBoxColor(playerid, blackjack[6][playerid], 50);
	PlayerTextDrawUseBox(playerid, blackjack[6][playerid], 1);
	PlayerTextDrawSetProportional(playerid, blackjack[6][playerid], 1);
	PlayerTextDrawSetSelectable(playerid, blackjack[6][playerid], 0);

	blackjack[7][playerid] = CreatePlayerTextDraw(playerid, 400.000000, 252.000000, "ld_card:cdback");
	PlayerTextDrawFont(playerid, blackjack[7][playerid], 4);
	PlayerTextDrawLetterSize(playerid, blackjack[7][playerid], 0.600000, 2.000000);
	PlayerTextDrawTextSize(playerid, blackjack[7][playerid], 38.000000, 42.500000);
	PlayerTextDrawSetOutline(playerid, blackjack[7][playerid], 1);
	PlayerTextDrawSetShadow(playerid, blackjack[7][playerid], 0);
	PlayerTextDrawAlignment(playerid, blackjack[7][playerid], 1);
	PlayerTextDrawColor(playerid, blackjack[7][playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, blackjack[7][playerid], 255);
	PlayerTextDrawBoxColor(playerid, blackjack[7][playerid], 50);
	PlayerTextDrawUseBox(playerid, blackjack[7][playerid], 1);
	PlayerTextDrawSetProportional(playerid, blackjack[7][playerid], 1);
	PlayerTextDrawSetSelectable(playerid, blackjack[7][playerid], 0);

	blackjack[8][playerid] = CreatePlayerTextDraw(playerid, 209.000000, 191.000000, "ld_card:cd10d");
	PlayerTextDrawFont(playerid, blackjack[8][playerid], 4);
	PlayerTextDrawLetterSize(playerid, blackjack[8][playerid], 0.600000, 2.000000);
	PlayerTextDrawTextSize(playerid, blackjack[8][playerid], 38.000000, 42.500000);
	PlayerTextDrawSetOutline(playerid, blackjack[8][playerid], 1);
	PlayerTextDrawSetShadow(playerid, blackjack[8][playerid], 0);
	PlayerTextDrawAlignment(playerid, blackjack[8][playerid], 1);
	PlayerTextDrawColor(playerid, blackjack[8][playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, blackjack[8][playerid], 255);
	PlayerTextDrawBoxColor(playerid, blackjack[8][playerid], 50);
	PlayerTextDrawUseBox(playerid, blackjack[8][playerid], 1);
	PlayerTextDrawSetProportional(playerid, blackjack[8][playerid], 1);
	PlayerTextDrawSetSelectable(playerid, blackjack[8][playerid], 0);

	blackjack[9][playerid] = CreatePlayerTextDraw(playerid, 255.000000, 191.000000, "ld_card:cd10d");
	PlayerTextDrawFont(playerid, blackjack[9][playerid], 4);
	PlayerTextDrawLetterSize(playerid, blackjack[9][playerid], 0.600000, 2.000000);
	PlayerTextDrawTextSize(playerid, blackjack[9][playerid], 38.000000, 42.500000);
	PlayerTextDrawSetOutline(playerid, blackjack[9][playerid], 1);
	PlayerTextDrawSetShadow(playerid, blackjack[9][playerid], 0);
	PlayerTextDrawAlignment(playerid, blackjack[9][playerid], 1);
	PlayerTextDrawColor(playerid, blackjack[9][playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, blackjack[9][playerid], 255);
	PlayerTextDrawBoxColor(playerid, blackjack[9][playerid], 50);
	PlayerTextDrawUseBox(playerid, blackjack[9][playerid], 1);
	PlayerTextDrawSetProportional(playerid, blackjack[9][playerid], 1);
	PlayerTextDrawSetSelectable(playerid, blackjack[9][playerid], 0);

	blackjack[10][playerid] = CreatePlayerTextDraw(playerid, 303.000000, 190.000000, "ld_card:cd10d");
	PlayerTextDrawFont(playerid, blackjack[10][playerid], 4);
	PlayerTextDrawLetterSize(playerid, blackjack[10][playerid], 0.600000, 2.000000);
	PlayerTextDrawTextSize(playerid, blackjack[10][playerid], 38.000000, 42.500000);
	PlayerTextDrawSetOutline(playerid, blackjack[10][playerid], 1);
	PlayerTextDrawSetShadow(playerid, blackjack[10][playerid], 0);
	PlayerTextDrawAlignment(playerid, blackjack[10][playerid], 1);
	PlayerTextDrawColor(playerid, blackjack[10][playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, blackjack[10][playerid], 255);
	PlayerTextDrawBoxColor(playerid, blackjack[10][playerid], 50);
	PlayerTextDrawUseBox(playerid, blackjack[10][playerid], 1);
	PlayerTextDrawSetProportional(playerid, blackjack[10][playerid], 1);
	PlayerTextDrawSetSelectable(playerid, blackjack[10][playerid], 0);

	blackjack[11][playerid] = CreatePlayerTextDraw(playerid, 351.000000, 190.000000, "ld_card:cd10d");
	PlayerTextDrawFont(playerid, blackjack[11][playerid], 4);
	PlayerTextDrawLetterSize(playerid, blackjack[11][playerid], 0.600000, 2.000000);
	PlayerTextDrawTextSize(playerid, blackjack[11][playerid], 38.000000, 42.500000);
	PlayerTextDrawSetOutline(playerid, blackjack[11][playerid], 1);
	PlayerTextDrawSetShadow(playerid, blackjack[11][playerid], 0);
	PlayerTextDrawAlignment(playerid, blackjack[11][playerid], 1);
	PlayerTextDrawColor(playerid, blackjack[11][playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, blackjack[11][playerid], 255);
	PlayerTextDrawBoxColor(playerid, blackjack[11][playerid], 50);
	PlayerTextDrawUseBox(playerid, blackjack[11][playerid], 1);
	PlayerTextDrawSetProportional(playerid, blackjack[11][playerid], 1);
	PlayerTextDrawSetSelectable(playerid, blackjack[11][playerid], 0);

	blackjack[12][playerid] = CreatePlayerTextDraw(playerid, 400.000000, 190.000000, "ld_card:cd10d");
	PlayerTextDrawFont(playerid, blackjack[12][playerid], 4);
	PlayerTextDrawLetterSize(playerid, blackjack[12][playerid], 0.600000, 2.000000);
	PlayerTextDrawTextSize(playerid, blackjack[12][playerid], 38.000000, 42.500000);
	PlayerTextDrawSetOutline(playerid, blackjack[12][playerid], 1);
	PlayerTextDrawSetShadow(playerid, blackjack[12][playerid], 0);
	PlayerTextDrawAlignment(playerid, blackjack[12][playerid], 1);
	PlayerTextDrawColor(playerid, blackjack[12][playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, blackjack[12][playerid], 255);
	PlayerTextDrawBoxColor(playerid, blackjack[12][playerid], 50);
	PlayerTextDrawUseBox(playerid, blackjack[12][playerid], 1);
	PlayerTextDrawSetProportional(playerid, blackjack[12][playerid], 1);
	PlayerTextDrawSetSelectable(playerid, blackjack[12][playerid], 0);

	blackjack[13][playerid] = CreatePlayerTextDraw(playerid, 221.000000, 307.000000, "Hit");
	PlayerTextDrawFont(playerid, blackjack[13][playerid], 3);
	PlayerTextDrawLetterSize(playerid, blackjack[13][playerid], 0.320833, 0.900000);
	PlayerTextDrawTextSize(playerid, blackjack[13][playerid], 400.000000, 37.500000);
	PlayerTextDrawSetOutline(playerid, blackjack[13][playerid], 1);
	PlayerTextDrawSetShadow(playerid, blackjack[13][playerid], 0);
	PlayerTextDrawAlignment(playerid, blackjack[13][playerid], 2);
	PlayerTextDrawColor(playerid, blackjack[13][playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, blackjack[13][playerid], 255);
	PlayerTextDrawBoxColor(playerid, blackjack[13][playerid], 230);
	PlayerTextDrawUseBox(playerid, blackjack[13][playerid], 1);
	PlayerTextDrawSetProportional(playerid, blackjack[13][playerid], 1);
	PlayerTextDrawSetSelectable(playerid, blackjack[13][playerid], 1);

	blackjack[14][playerid] = CreatePlayerTextDraw(playerid, 423.000000, 307.000000, "Stand");
	PlayerTextDrawFont(playerid, blackjack[14][playerid], 3);
	PlayerTextDrawLetterSize(playerid, blackjack[14][playerid], 0.254167, 0.900000);
	PlayerTextDrawTextSize(playerid, blackjack[14][playerid], 400.000000, 37.500000);
	PlayerTextDrawSetOutline(playerid, blackjack[14][playerid], 1);
	PlayerTextDrawSetShadow(playerid, blackjack[14][playerid], 0);
	PlayerTextDrawAlignment(playerid, blackjack[14][playerid], 2);
	PlayerTextDrawColor(playerid, blackjack[14][playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, blackjack[14][playerid], 255);
	PlayerTextDrawBoxColor(playerid, blackjack[14][playerid], 230);
	PlayerTextDrawUseBox(playerid, blackjack[14][playerid], 1);
	PlayerTextDrawSetProportional(playerid, blackjack[14][playerid], 1);
	PlayerTextDrawSetSelectable(playerid, blackjack[14][playerid], 1);
}

CreateVehicleTextDraws(playerid)
{
	speedo[0][playerid] = CreatePlayerTextDraw(playerid, 124.000000, 393.000000, "V");
	PlayerTextDrawFont(playerid, speedo[0][playerid], 1);
	PlayerTextDrawLetterSize(playerid, speedo[0][playerid], 0.362500, 1.299999);
	PlayerTextDrawTextSize(playerid, speedo[0][playerid], 400.000000, 158.000000);
	PlayerTextDrawSetOutline(playerid, speedo[0][playerid], 1);
	PlayerTextDrawSetShadow(playerid, speedo[0][playerid], 0);
	PlayerTextDrawAlignment(playerid, speedo[0][playerid], 2);
	PlayerTextDrawColor(playerid, speedo[0][playerid], 1097458175);
	PlayerTextDrawBackgroundColor(playerid, speedo[0][playerid], 1097458175);
	PlayerTextDrawBoxColor(playerid, speedo[0][playerid], 50);
	PlayerTextDrawUseBox(playerid, speedo[0][playerid], 0);
	PlayerTextDrawSetProportional(playerid, speedo[0][playerid], 1);
	PlayerTextDrawSetSelectable(playerid, speedo[0][playerid], 0);

	speedo[1][playerid] = CreatePlayerTextDraw(playerid, 116.000000, 384.000000, "ld_beat:chit");
	PlayerTextDrawFont(playerid, speedo[1][playerid], 4);
	PlayerTextDrawLetterSize(playerid, speedo[1][playerid], 0.600000, 2.000000);
	PlayerTextDrawTextSize(playerid, speedo[1][playerid], 16.000000, 19.000000);
	PlayerTextDrawSetOutline(playerid, speedo[1][playerid], 1);
	PlayerTextDrawSetShadow(playerid, speedo[1][playerid], 0);
	PlayerTextDrawAlignment(playerid, speedo[1][playerid], 1);
	PlayerTextDrawColor(playerid, speedo[1][playerid], 1097458175);
	PlayerTextDrawBackgroundColor(playerid, speedo[1][playerid], 255);
	PlayerTextDrawBoxColor(playerid, speedo[1][playerid], 50);
	PlayerTextDrawUseBox(playerid, speedo[1][playerid], 1);
	PlayerTextDrawSetProportional(playerid, speedo[1][playerid], 1);
	PlayerTextDrawSetSelectable(playerid, speedo[1][playerid], 0);

	speedo[2][playerid] = CreatePlayerTextDraw(playerid, 119.000000, 388.000000, "ld_beat:chit");
	PlayerTextDrawFont(playerid, speedo[2][playerid], 4);
	PlayerTextDrawLetterSize(playerid, speedo[2][playerid], 0.600000, 2.000000);
	PlayerTextDrawTextSize(playerid, speedo[2][playerid], 10.000000, 11.000000);
	PlayerTextDrawSetOutline(playerid, speedo[2][playerid], 1);
	PlayerTextDrawSetShadow(playerid, speedo[2][playerid], 0);
	PlayerTextDrawAlignment(playerid, speedo[2][playerid], 1);
	PlayerTextDrawColor(playerid, speedo[2][playerid], 255);
	PlayerTextDrawBackgroundColor(playerid, speedo[2][playerid], 255);
	PlayerTextDrawBoxColor(playerid, speedo[2][playerid], 50);
	PlayerTextDrawUseBox(playerid, speedo[2][playerid], 1);
	PlayerTextDrawSetProportional(playerid, speedo[2][playerid], 1);
	PlayerTextDrawSetSelectable(playerid, speedo[2][playerid], 0);

	speedo[3][playerid] = CreatePlayerTextDraw(playerid, 113.000000, 342.000000, "ld_beat:chit");
	PlayerTextDrawFont(playerid, speedo[3][playerid], 4);
	PlayerTextDrawLetterSize(playerid, speedo[3][playerid], 0.600000, 2.000000);
	PlayerTextDrawTextSize(playerid, speedo[3][playerid], 23.000000, 26.000000);
	PlayerTextDrawSetOutline(playerid, speedo[3][playerid], 1);
	PlayerTextDrawSetShadow(playerid, speedo[3][playerid], 0);
	PlayerTextDrawAlignment(playerid, speedo[3][playerid], 1);
	PlayerTextDrawColor(playerid, speedo[3][playerid], -764862721);
	PlayerTextDrawBackgroundColor(playerid, speedo[3][playerid], 255);
	PlayerTextDrawBoxColor(playerid, speedo[3][playerid], 50);
	PlayerTextDrawUseBox(playerid, speedo[3][playerid], 1);
	PlayerTextDrawSetProportional(playerid, speedo[3][playerid], 1);
	PlayerTextDrawSetSelectable(playerid, speedo[3][playerid], 0);

	speedo[4][playerid] = CreatePlayerTextDraw(playerid, 125.000000, 349.000000, "/");
	PlayerTextDrawFont(playerid, speedo[4][playerid], 1);
	PlayerTextDrawLetterSize(playerid, speedo[4][playerid], 0.379166, 0.899999);
	PlayerTextDrawTextSize(playerid, speedo[4][playerid], 400.000000, 158.000000);
	PlayerTextDrawSetOutline(playerid, speedo[4][playerid], 0);
	PlayerTextDrawSetShadow(playerid, speedo[4][playerid], 0);
	PlayerTextDrawAlignment(playerid, speedo[4][playerid], 2);
	PlayerTextDrawColor(playerid, speedo[4][playerid], 255);
	PlayerTextDrawBackgroundColor(playerid, speedo[4][playerid], 1097458175);
	PlayerTextDrawBoxColor(playerid, speedo[4][playerid], 50);
	PlayerTextDrawUseBox(playerid, speedo[4][playerid], 0);
	PlayerTextDrawSetProportional(playerid, speedo[4][playerid], 1);
	PlayerTextDrawSetSelectable(playerid, speedo[4][playerid], 0);

	speedo[5][playerid] = CreatePlayerTextDraw(playerid, 121.000000, 354.000000, "ld_beat:chit");
	PlayerTextDrawFont(playerid, speedo[5][playerid], 4);
	PlayerTextDrawLetterSize(playerid, speedo[5][playerid], 0.600000, 2.000000);
	PlayerTextDrawTextSize(playerid, speedo[5][playerid], 5.500000, 7.000000);
	PlayerTextDrawSetOutline(playerid, speedo[5][playerid], 1);
	PlayerTextDrawSetShadow(playerid, speedo[5][playerid], 0);
	PlayerTextDrawAlignment(playerid, speedo[5][playerid], 1);
	PlayerTextDrawColor(playerid, speedo[5][playerid], 255);
	PlayerTextDrawBackgroundColor(playerid, speedo[5][playerid], 255);
	PlayerTextDrawBoxColor(playerid, speedo[5][playerid], 50);
	PlayerTextDrawUseBox(playerid, speedo[5][playerid], 1);
	PlayerTextDrawSetProportional(playerid, speedo[5][playerid], 1);
	PlayerTextDrawSetSelectable(playerid, speedo[5][playerid], 0);

	speedo[6][playerid] = CreatePlayerTextDraw(playerid, 118.000000, 352.000000, "ld_beat:chit");
	PlayerTextDrawFont(playerid, speedo[6][playerid], 4);
	PlayerTextDrawLetterSize(playerid, speedo[6][playerid], 0.600000, 2.000000);
	PlayerTextDrawTextSize(playerid, speedo[6][playerid], 3.500000, 3.500000);
	PlayerTextDrawSetOutline(playerid, speedo[6][playerid], 1);
	PlayerTextDrawSetShadow(playerid, speedo[6][playerid], 0);
	PlayerTextDrawAlignment(playerid, speedo[6][playerid], 1);
	PlayerTextDrawColor(playerid, speedo[6][playerid], 255);
	PlayerTextDrawBackgroundColor(playerid, speedo[6][playerid], 255);
	PlayerTextDrawBoxColor(playerid, speedo[6][playerid], 50);
	PlayerTextDrawUseBox(playerid, speedo[6][playerid], 1);
	PlayerTextDrawSetProportional(playerid, speedo[6][playerid], 1);
	PlayerTextDrawSetSelectable(playerid, speedo[6][playerid], 0);

	speedo[7][playerid] = CreatePlayerTextDraw(playerid, 121.000000, 348.000000, "ld_beat:chit");
	PlayerTextDrawFont(playerid, speedo[7][playerid], 4);
	PlayerTextDrawLetterSize(playerid, speedo[7][playerid], 0.600000, 2.000000);
	PlayerTextDrawTextSize(playerid, speedo[7][playerid], 3.500000, 3.500000);
	PlayerTextDrawSetOutline(playerid, speedo[7][playerid], 1);
	PlayerTextDrawSetShadow(playerid, speedo[7][playerid], 0);
	PlayerTextDrawAlignment(playerid, speedo[7][playerid], 1);
	PlayerTextDrawColor(playerid, speedo[7][playerid], 255);
	PlayerTextDrawBackgroundColor(playerid, speedo[7][playerid], 255);
	PlayerTextDrawBoxColor(playerid, speedo[7][playerid], 50);
	PlayerTextDrawUseBox(playerid, speedo[7][playerid], 1);
	PlayerTextDrawSetProportional(playerid, speedo[7][playerid], 1);
	PlayerTextDrawSetSelectable(playerid, speedo[7][playerid], 0);

	speedo[8][playerid] = CreatePlayerTextDraw(playerid, 127.000000, 349.000000, "ld_beat:chit");
	PlayerTextDrawFont(playerid, speedo[8][playerid], 4);
	PlayerTextDrawLetterSize(playerid, speedo[8][playerid], 0.600000, 2.000000);
	PlayerTextDrawTextSize(playerid, speedo[8][playerid], 3.500000, 3.500000);
	PlayerTextDrawSetOutline(playerid, speedo[8][playerid], 1);
	PlayerTextDrawSetShadow(playerid, speedo[8][playerid], 0);
	PlayerTextDrawAlignment(playerid, speedo[8][playerid], 1);
	PlayerTextDrawColor(playerid, speedo[8][playerid], 255);
	PlayerTextDrawBackgroundColor(playerid, speedo[8][playerid], 255);
	PlayerTextDrawBoxColor(playerid, speedo[8][playerid], 50);
	PlayerTextDrawUseBox(playerid, speedo[8][playerid], 1);
	PlayerTextDrawSetProportional(playerid, speedo[8][playerid], 1);
	PlayerTextDrawSetSelectable(playerid, speedo[8][playerid], 0);

	speedo[10][playerid] = CreatePlayerTextDraw(playerid, 119.000000, 372.000000, "ld_bum:blkdot");
	PlayerTextDrawFont(playerid, speedo[10][playerid], 4);
	PlayerTextDrawLetterSize(playerid, speedo[10][playerid], 0.600000, 2.000000);
	PlayerTextDrawTextSize(playerid, speedo[10][playerid], 10.000000, 11.000000);
	PlayerTextDrawSetOutline(playerid, speedo[10][playerid], 1);
	PlayerTextDrawSetShadow(playerid, speedo[10][playerid], 0);
	PlayerTextDrawAlignment(playerid, speedo[10][playerid], 1);
	PlayerTextDrawColor(playerid, speedo[10][playerid], -1962934017);
	PlayerTextDrawBackgroundColor(playerid, speedo[10][playerid], 255);
	PlayerTextDrawBoxColor(playerid, speedo[10][playerid], 50);
	PlayerTextDrawUseBox(playerid, speedo[10][playerid], 1);
	PlayerTextDrawSetProportional(playerid, speedo[10][playerid], 1);
	PlayerTextDrawSetSelectable(playerid, speedo[10][playerid], 0);

	speedo[11][playerid] = CreatePlayerTextDraw(playerid, 131.000000, 368.000000, "0");
	PlayerTextDrawFont(playerid, speedo[11][playerid], 0);
	PlayerTextDrawLetterSize(playerid, speedo[11][playerid], 0.174999, 1.849999);
	PlayerTextDrawTextSize(playerid, speedo[11][playerid], 400.000000, 158.000000);
	PlayerTextDrawSetOutline(playerid, speedo[11][playerid], 0);
	PlayerTextDrawSetShadow(playerid, speedo[11][playerid], 0);
	PlayerTextDrawAlignment(playerid, speedo[11][playerid], 2);
	PlayerTextDrawColor(playerid, speedo[11][playerid], -1962934017);
	PlayerTextDrawBackgroundColor(playerid, speedo[11][playerid], 255);
	PlayerTextDrawBoxColor(playerid, speedo[11][playerid], 50);
	PlayerTextDrawUseBox(playerid, speedo[11][playerid], 0);
	PlayerTextDrawSetProportional(playerid, speedo[11][playerid], 1);
	PlayerTextDrawSetSelectable(playerid, speedo[11][playerid], 0);

	speedo[12][playerid] = CreatePlayerTextDraw(playerid, 125.000000, 362.000000, "0");
	PlayerTextDrawFont(playerid, speedo[12][playerid], 2);
	PlayerTextDrawLetterSize(playerid, speedo[12][playerid], 0.466666, 2.299998);
	PlayerTextDrawTextSize(playerid, speedo[12][playerid], 400.000000, 158.000000);
	PlayerTextDrawSetOutline(playerid, speedo[12][playerid], 0);
	PlayerTextDrawSetShadow(playerid, speedo[12][playerid], 0);
	PlayerTextDrawAlignment(playerid, speedo[12][playerid], 2);
	PlayerTextDrawColor(playerid, speedo[12][playerid], -1962934017);
	PlayerTextDrawBackgroundColor(playerid, speedo[12][playerid], 255);
	PlayerTextDrawBoxColor(playerid, speedo[12][playerid], 50);
	PlayerTextDrawUseBox(playerid, speedo[12][playerid], 0);
	PlayerTextDrawSetProportional(playerid, speedo[12][playerid], 1);
	PlayerTextDrawSetSelectable(playerid, speedo[12][playerid], 0);

	speedo[13][playerid] = CreatePlayerTextDraw(playerid, 134.000000, 367.000000, "~g~IIIIIIII");
	PlayerTextDrawFont(playerid, speedo[13][playerid], 2);
	PlayerTextDrawLetterSize(playerid, speedo[13][playerid], 0.316667, 1.550000);
	PlayerTextDrawTextSize(playerid, speedo[13][playerid], 400.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, speedo[13][playerid], 1);
	PlayerTextDrawSetShadow(playerid, speedo[13][playerid], 0);
	PlayerTextDrawAlignment(playerid, speedo[13][playerid], 1);
	PlayerTextDrawColor(playerid, speedo[13][playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, speedo[13][playerid], 255);
	PlayerTextDrawBoxColor(playerid, speedo[13][playerid], 50);
	PlayerTextDrawUseBox(playerid, speedo[13][playerid], 0);
	PlayerTextDrawSetProportional(playerid, speedo[13][playerid], 1);
	PlayerTextDrawSetSelectable(playerid, speedo[13][playerid], 0);

	speedo[14][playerid] = CreatePlayerTextDraw(playerid, 134.000000, 349.000000, "100 Mph");
	PlayerTextDrawFont(playerid, speedo[14][playerid], 1);
	PlayerTextDrawLetterSize(playerid, speedo[14][playerid], 0.220833, 1.100000);
	PlayerTextDrawTextSize(playerid, speedo[14][playerid], 400.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, speedo[14][playerid], 1);
	PlayerTextDrawSetShadow(playerid, speedo[14][playerid], 0);
	PlayerTextDrawAlignment(playerid, speedo[14][playerid], 1);
	PlayerTextDrawColor(playerid, speedo[14][playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, speedo[14][playerid], 255);
	PlayerTextDrawBoxColor(playerid, speedo[14][playerid], 50);
	PlayerTextDrawUseBox(playerid, speedo[14][playerid], 0);
	PlayerTextDrawSetProportional(playerid, speedo[14][playerid], 1);
	PlayerTextDrawSetSelectable(playerid, speedo[14][playerid], 0);

	VehicleSelection[0][playerid] = CreatePlayerTextDraw(playerid, 319.000000, 153.000000, "_");
	PlayerTextDrawFont(playerid, VehicleSelection[0][playerid], 1);
	PlayerTextDrawLetterSize(playerid, VehicleSelection[0][playerid], 0.600000, 14.700004);
	PlayerTextDrawTextSize(playerid, VehicleSelection[0][playerid], 298.500000, 275.000000);
	PlayerTextDrawSetOutline(playerid, VehicleSelection[0][playerid], 1);
	PlayerTextDrawSetShadow(playerid, VehicleSelection[0][playerid], 0);
	PlayerTextDrawAlignment(playerid, VehicleSelection[0][playerid], 2);
	PlayerTextDrawColor(playerid, VehicleSelection[0][playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, VehicleSelection[0][playerid], 255);
	PlayerTextDrawBoxColor(playerid, VehicleSelection[0][playerid], 1296911796);
	PlayerTextDrawUseBox(playerid, VehicleSelection[0][playerid], 1);
	PlayerTextDrawSetProportional(playerid, VehicleSelection[0][playerid], 1);
	PlayerTextDrawSetSelectable(playerid, VehicleSelection[0][playerid], 0);

	VehicleSelection[1][playerid] = CreatePlayerTextDraw(playerid, 319.000000, 153.000000, "My Vehicles");
	PlayerTextDrawFont(playerid, VehicleSelection[1][playerid], 1);
	PlayerTextDrawLetterSize(playerid, VehicleSelection[1][playerid], 0.408333, 1.250000);
	PlayerTextDrawTextSize(playerid, VehicleSelection[1][playerid], 400.000000, 256.000000);
	PlayerTextDrawSetOutline(playerid, VehicleSelection[1][playerid], 1);
	PlayerTextDrawSetShadow(playerid, VehicleSelection[1][playerid], 0);
	PlayerTextDrawAlignment(playerid, VehicleSelection[1][playerid], 2);
	PlayerTextDrawColor(playerid, VehicleSelection[1][playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, VehicleSelection[1][playerid], 255);
	PlayerTextDrawBoxColor(playerid, VehicleSelection[1][playerid], 50);
	PlayerTextDrawUseBox(playerid, VehicleSelection[1][playerid], 0);
	PlayerTextDrawSetProportional(playerid, VehicleSelection[1][playerid], 1);
	PlayerTextDrawSetSelectable(playerid, VehicleSelection[1][playerid], 0);

	VehicleSelection[2][playerid] = CreatePlayerTextDraw(playerid, 183.000000, 185.000000, "Preview_Model");
	PlayerTextDrawFont(playerid, VehicleSelection[2][playerid], 5);
	PlayerTextDrawLetterSize(playerid, VehicleSelection[2][playerid], 0.600000, 2.000000);
	PlayerTextDrawTextSize(playerid, VehicleSelection[2][playerid], 60.500000, 72.000000);
	PlayerTextDrawSetOutline(playerid, VehicleSelection[2][playerid], 0);
	PlayerTextDrawSetShadow(playerid, VehicleSelection[2][playerid], 0);
	PlayerTextDrawAlignment(playerid, VehicleSelection[2][playerid], 1);
	PlayerTextDrawColor(playerid, VehicleSelection[2][playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, VehicleSelection[2][playerid], -741092483);
	PlayerTextDrawBoxColor(playerid, VehicleSelection[2][playerid], 255);
	PlayerTextDrawUseBox(playerid, VehicleSelection[2][playerid], 0);
	PlayerTextDrawSetProportional(playerid, VehicleSelection[2][playerid], 1);
	PlayerTextDrawSetSelectable(playerid, VehicleSelection[2][playerid], 0);
	PlayerTextDrawSetPreviewModel(playerid, VehicleSelection[2][playerid], 420);
	PlayerTextDrawSetPreviewRot(playerid, VehicleSelection[2][playerid], -10.000000, 0.000000, -20.000000, 0.750000);
	PlayerTextDrawSetPreviewVehCol(playerid, VehicleSelection[2][playerid], 1, 1);

	VehicleSelection[3][playerid] = CreatePlayerTextDraw(playerid, 254.000000, 185.000000, "Preview_Model");
	PlayerTextDrawFont(playerid, VehicleSelection[3][playerid], 5);
	PlayerTextDrawLetterSize(playerid, VehicleSelection[3][playerid], 0.600000, 2.000000);
	PlayerTextDrawTextSize(playerid, VehicleSelection[3][playerid], 60.500000, 72.000000);
	PlayerTextDrawSetOutline(playerid, VehicleSelection[3][playerid], 0);
	PlayerTextDrawSetShadow(playerid, VehicleSelection[3][playerid], 0);
	PlayerTextDrawAlignment(playerid, VehicleSelection[3][playerid], 1);
	PlayerTextDrawColor(playerid, VehicleSelection[3][playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, VehicleSelection[3][playerid], -741092483);
	PlayerTextDrawBoxColor(playerid, VehicleSelection[3][playerid], 255);
	PlayerTextDrawUseBox(playerid, VehicleSelection[3][playerid], 0);
	PlayerTextDrawSetProportional(playerid, VehicleSelection[3][playerid], 1);
	PlayerTextDrawSetSelectable(playerid, VehicleSelection[3][playerid], 0);
	PlayerTextDrawSetPreviewModel(playerid, VehicleSelection[3][playerid], 420);
	PlayerTextDrawSetPreviewRot(playerid, VehicleSelection[3][playerid], -10.000000, 0.000000, -20.000000, 0.750000);
	PlayerTextDrawSetPreviewVehCol(playerid, VehicleSelection[3][playerid], 1, 1);

	VehicleSelection[4][playerid] = CreatePlayerTextDraw(playerid, 325.000000, 185.000000, "Preview_Model");
	PlayerTextDrawFont(playerid, VehicleSelection[4][playerid], 5);
	PlayerTextDrawLetterSize(playerid, VehicleSelection[4][playerid], 0.600000, 2.000000);
	PlayerTextDrawTextSize(playerid, VehicleSelection[4][playerid], 60.500000, 72.000000);
	PlayerTextDrawSetOutline(playerid, VehicleSelection[4][playerid], 0);
	PlayerTextDrawSetShadow(playerid, VehicleSelection[4][playerid], 0);
	PlayerTextDrawAlignment(playerid, VehicleSelection[4][playerid], 1);
	PlayerTextDrawColor(playerid, VehicleSelection[4][playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, VehicleSelection[4][playerid], -741092483);
	PlayerTextDrawBoxColor(playerid, VehicleSelection[4][playerid], 255);
	PlayerTextDrawUseBox(playerid, VehicleSelection[4][playerid], 0);
	PlayerTextDrawSetProportional(playerid, VehicleSelection[4][playerid], 1);
	PlayerTextDrawSetSelectable(playerid, VehicleSelection[4][playerid], 0);
	PlayerTextDrawSetPreviewModel(playerid, VehicleSelection[4][playerid], 420);
	PlayerTextDrawSetPreviewRot(playerid, VehicleSelection[4][playerid], -10.000000, 0.000000, -20.000000, 0.750000);
	PlayerTextDrawSetPreviewVehCol(playerid, VehicleSelection[4][playerid], 1, 1);

	VehicleSelection[5][playerid] = CreatePlayerTextDraw(playerid, 395.000000, 185.000000, "Preview_Model");
	PlayerTextDrawFont(playerid, VehicleSelection[5][playerid], 5);
	PlayerTextDrawLetterSize(playerid, VehicleSelection[5][playerid], 0.600000, 2.000000);
	PlayerTextDrawTextSize(playerid, VehicleSelection[5][playerid], 60.500000, 72.000000);
	PlayerTextDrawSetOutline(playerid, VehicleSelection[5][playerid], 0);
	PlayerTextDrawSetShadow(playerid, VehicleSelection[5][playerid], 0);
	PlayerTextDrawAlignment(playerid, VehicleSelection[5][playerid], 1);
	PlayerTextDrawColor(playerid, VehicleSelection[5][playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, VehicleSelection[5][playerid], -741092483);
	PlayerTextDrawBoxColor(playerid, VehicleSelection[5][playerid], 255);
	PlayerTextDrawUseBox(playerid, VehicleSelection[5][playerid], 0);
	PlayerTextDrawSetProportional(playerid, VehicleSelection[5][playerid], 1);
	PlayerTextDrawSetSelectable(playerid, VehicleSelection[5][playerid], 0);
	PlayerTextDrawSetPreviewModel(playerid, VehicleSelection[5][playerid], 420);
	PlayerTextDrawSetPreviewRot(playerid, VehicleSelection[5][playerid], -10.000000, 0.000000, -20.000000, 0.750000);
	PlayerTextDrawSetPreviewVehCol(playerid, VehicleSelection[5][playerid], 1, 1);

	VehicleSelection[6][playerid] = CreatePlayerTextDraw(playerid, 198.000000, 186.000000, "50C010");
	PlayerTextDrawFont(playerid, VehicleSelection[6][playerid], 2);
	PlayerTextDrawLetterSize(playerid, VehicleSelection[6][playerid], 0.166667, 0.650000);
	PlayerTextDrawTextSize(playerid, VehicleSelection[6][playerid], 400.000000, 256.000000);
	PlayerTextDrawSetOutline(playerid, VehicleSelection[6][playerid], 1);
	PlayerTextDrawSetShadow(playerid, VehicleSelection[6][playerid], 0);
	PlayerTextDrawAlignment(playerid, VehicleSelection[6][playerid], 2);
	PlayerTextDrawColor(playerid, VehicleSelection[6][playerid], 852308735);
	PlayerTextDrawBackgroundColor(playerid, VehicleSelection[6][playerid], 255);
	PlayerTextDrawBoxColor(playerid, VehicleSelection[6][playerid], 50);
	PlayerTextDrawUseBox(playerid, VehicleSelection[6][playerid], 0);
	PlayerTextDrawSetProportional(playerid, VehicleSelection[6][playerid], 1);
	PlayerTextDrawSetSelectable(playerid, VehicleSelection[6][playerid], 0);

	VehicleSelection[7][playerid] = CreatePlayerTextDraw(playerid, 270.000000, 186.000000, "50C010");
	PlayerTextDrawFont(playerid, VehicleSelection[7][playerid], 2);
	PlayerTextDrawLetterSize(playerid, VehicleSelection[7][playerid], 0.166667, 0.650000);
	PlayerTextDrawTextSize(playerid, VehicleSelection[7][playerid], 400.000000, 256.000000);
	PlayerTextDrawSetOutline(playerid, VehicleSelection[7][playerid], 1);
	PlayerTextDrawSetShadow(playerid, VehicleSelection[7][playerid], 0);
	PlayerTextDrawAlignment(playerid, VehicleSelection[7][playerid], 2);
	PlayerTextDrawColor(playerid, VehicleSelection[7][playerid], 852308735);
	PlayerTextDrawBackgroundColor(playerid, VehicleSelection[7][playerid], 255);
	PlayerTextDrawBoxColor(playerid, VehicleSelection[7][playerid], 50);
	PlayerTextDrawUseBox(playerid, VehicleSelection[7][playerid], 0);
	PlayerTextDrawSetProportional(playerid, VehicleSelection[7][playerid], 1);
	PlayerTextDrawSetSelectable(playerid, VehicleSelection[7][playerid], 0);

	VehicleSelection[8][playerid] = CreatePlayerTextDraw(playerid, 341.000000, 186.000000, "50C010");
	PlayerTextDrawFont(playerid, VehicleSelection[8][playerid], 2);
	PlayerTextDrawLetterSize(playerid, VehicleSelection[8][playerid], 0.166667, 0.650000);
	PlayerTextDrawTextSize(playerid, VehicleSelection[8][playerid], 400.000000, 256.000000);
	PlayerTextDrawSetOutline(playerid, VehicleSelection[8][playerid], 1);
	PlayerTextDrawSetShadow(playerid, VehicleSelection[8][playerid], 0);
	PlayerTextDrawAlignment(playerid, VehicleSelection[8][playerid], 2);
	PlayerTextDrawColor(playerid, VehicleSelection[8][playerid], 852308735);
	PlayerTextDrawBackgroundColor(playerid, VehicleSelection[8][playerid], 255);
	PlayerTextDrawBoxColor(playerid, VehicleSelection[8][playerid], 50);
	PlayerTextDrawUseBox(playerid, VehicleSelection[8][playerid], 0);
	PlayerTextDrawSetProportional(playerid, VehicleSelection[8][playerid], 1);
	PlayerTextDrawSetSelectable(playerid, VehicleSelection[8][playerid], 0);

	VehicleSelection[9][playerid] = CreatePlayerTextDraw(playerid, 411.000000, 186.000000, "50C010");
	PlayerTextDrawFont(playerid, VehicleSelection[9][playerid], 2);
	PlayerTextDrawLetterSize(playerid, VehicleSelection[9][playerid], 0.166667, 0.650000);
	PlayerTextDrawTextSize(playerid, VehicleSelection[9][playerid], 400.000000, 256.000000);
	PlayerTextDrawSetOutline(playerid, VehicleSelection[9][playerid], 1);
	PlayerTextDrawSetShadow(playerid, VehicleSelection[9][playerid], 0);
	PlayerTextDrawAlignment(playerid, VehicleSelection[9][playerid], 2);
	PlayerTextDrawColor(playerid, VehicleSelection[9][playerid], 852308735);
	PlayerTextDrawBackgroundColor(playerid, VehicleSelection[9][playerid], 255);
	PlayerTextDrawBoxColor(playerid, VehicleSelection[9][playerid], 50);
	PlayerTextDrawUseBox(playerid, VehicleSelection[9][playerid], 0);
	PlayerTextDrawSetProportional(playerid, VehicleSelection[9][playerid], 1);
	PlayerTextDrawSetSelectable(playerid, VehicleSelection[9][playerid], 0);

	VehicleSelection[10][playerid] = CreatePlayerTextDraw(playerid, 213.000000, 250.000000, "Taxi");
	PlayerTextDrawFont(playerid, VehicleSelection[10][playerid], 3);
	PlayerTextDrawLetterSize(playerid, VehicleSelection[10][playerid], 0.166667, 0.650000);
	PlayerTextDrawTextSize(playerid, VehicleSelection[10][playerid], 400.000000, 256.000000);
	PlayerTextDrawSetOutline(playerid, VehicleSelection[10][playerid], 1);
	PlayerTextDrawSetShadow(playerid, VehicleSelection[10][playerid], 0);
	PlayerTextDrawAlignment(playerid, VehicleSelection[10][playerid], 2);
	PlayerTextDrawColor(playerid, VehicleSelection[10][playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, VehicleSelection[10][playerid], 255);
	PlayerTextDrawBoxColor(playerid, VehicleSelection[10][playerid], 50);
	PlayerTextDrawUseBox(playerid, VehicleSelection[10][playerid], 0);
	PlayerTextDrawSetProportional(playerid, VehicleSelection[10][playerid], 1);
	PlayerTextDrawSetSelectable(playerid, VehicleSelection[10][playerid], 0);

	VehicleSelection[11][playerid] = CreatePlayerTextDraw(playerid, 286.000000, 250.000000, "Taxi");
	PlayerTextDrawFont(playerid, VehicleSelection[11][playerid], 3);
	PlayerTextDrawLetterSize(playerid, VehicleSelection[11][playerid], 0.166667, 0.650000);
	PlayerTextDrawTextSize(playerid, VehicleSelection[11][playerid], 400.000000, 256.000000);
	PlayerTextDrawSetOutline(playerid, VehicleSelection[11][playerid], 1);
	PlayerTextDrawSetShadow(playerid, VehicleSelection[11][playerid], 0);
	PlayerTextDrawAlignment(playerid, VehicleSelection[11][playerid], 2);
	PlayerTextDrawColor(playerid, VehicleSelection[11][playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, VehicleSelection[11][playerid], 255);
	PlayerTextDrawBoxColor(playerid, VehicleSelection[11][playerid], 50);
	PlayerTextDrawUseBox(playerid, VehicleSelection[11][playerid], 0);
	PlayerTextDrawSetProportional(playerid, VehicleSelection[11][playerid], 1);
	PlayerTextDrawSetSelectable(playerid, VehicleSelection[11][playerid], 0);

	VehicleSelection[12][playerid] = CreatePlayerTextDraw(playerid, 355.000000, 250.000000, "Taxi");
	PlayerTextDrawFont(playerid, VehicleSelection[12][playerid], 3);
	PlayerTextDrawLetterSize(playerid, VehicleSelection[12][playerid], 0.166667, 0.650000);
	PlayerTextDrawTextSize(playerid, VehicleSelection[12][playerid], 400.000000, 256.000000);
	PlayerTextDrawSetOutline(playerid, VehicleSelection[12][playerid], 1);
	PlayerTextDrawSetShadow(playerid, VehicleSelection[12][playerid], 0);
	PlayerTextDrawAlignment(playerid, VehicleSelection[12][playerid], 2);
	PlayerTextDrawColor(playerid, VehicleSelection[12][playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, VehicleSelection[12][playerid], 255);
	PlayerTextDrawBoxColor(playerid, VehicleSelection[12][playerid], 50);
	PlayerTextDrawUseBox(playerid, VehicleSelection[12][playerid], 0);
	PlayerTextDrawSetProportional(playerid, VehicleSelection[12][playerid], 1);
	PlayerTextDrawSetSelectable(playerid, VehicleSelection[12][playerid], 0);

	VehicleSelection[13][playerid] = CreatePlayerTextDraw(playerid, 427.000000, 250.000000, "Taxi");
	PlayerTextDrawFont(playerid, VehicleSelection[13][playerid], 3);
	PlayerTextDrawLetterSize(playerid, VehicleSelection[13][playerid], 0.166667, 0.650000);
	PlayerTextDrawTextSize(playerid, VehicleSelection[13][playerid], 400.000000, 256.000000);
	PlayerTextDrawSetOutline(playerid, VehicleSelection[13][playerid], 1);
	PlayerTextDrawSetShadow(playerid, VehicleSelection[13][playerid], 0);
	PlayerTextDrawAlignment(playerid, VehicleSelection[13][playerid], 2);
	PlayerTextDrawColor(playerid, VehicleSelection[13][playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, VehicleSelection[13][playerid], 255);
	PlayerTextDrawBoxColor(playerid, VehicleSelection[13][playerid], 50);
	PlayerTextDrawUseBox(playerid, VehicleSelection[13][playerid], 0);
	PlayerTextDrawSetProportional(playerid, VehicleSelection[13][playerid], 1);
	PlayerTextDrawSetSelectable(playerid, VehicleSelection[13][playerid], 0);

	VehicleSelection[14][playerid] = CreatePlayerTextDraw(playerid, 213.000000, 269.000000, "FIND");
	PlayerTextDrawFont(playerid, VehicleSelection[14][playerid], 1);
	PlayerTextDrawLetterSize(playerid, VehicleSelection[14][playerid], 0.216667, 1.000000);
	PlayerTextDrawTextSize(playerid, VehicleSelection[14][playerid], 400.000000, 57.000000);
	PlayerTextDrawSetOutline(playerid, VehicleSelection[14][playerid], 1);
	PlayerTextDrawSetShadow(playerid, VehicleSelection[14][playerid], 0);
	PlayerTextDrawAlignment(playerid, VehicleSelection[14][playerid], 2);
	PlayerTextDrawColor(playerid, VehicleSelection[14][playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, VehicleSelection[14][playerid], 255);
	PlayerTextDrawBoxColor(playerid, VehicleSelection[14][playerid], -764862721);
	PlayerTextDrawUseBox(playerid, VehicleSelection[14][playerid], 1);
	PlayerTextDrawSetProportional(playerid, VehicleSelection[14][playerid], 1);
	PlayerTextDrawSetSelectable(playerid, VehicleSelection[14][playerid], 1);

	VehicleSelection[15][playerid] = CreatePlayerTextDraw(playerid, 285.000000, 269.000000, "FIND");
	PlayerTextDrawFont(playerid, VehicleSelection[15][playerid], 1);
	PlayerTextDrawLetterSize(playerid, VehicleSelection[15][playerid], 0.216667, 1.000000);
	PlayerTextDrawTextSize(playerid, VehicleSelection[15][playerid], 400.000000, 57.000000);
	PlayerTextDrawSetOutline(playerid, VehicleSelection[15][playerid], 1);
	PlayerTextDrawSetShadow(playerid, VehicleSelection[15][playerid], 0);
	PlayerTextDrawAlignment(playerid, VehicleSelection[15][playerid], 2);
	PlayerTextDrawColor(playerid, VehicleSelection[15][playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, VehicleSelection[15][playerid], 255);
	PlayerTextDrawBoxColor(playerid, VehicleSelection[15][playerid], -764862721);
	PlayerTextDrawUseBox(playerid, VehicleSelection[15][playerid], 1);
	PlayerTextDrawSetProportional(playerid, VehicleSelection[15][playerid], 1);
	PlayerTextDrawSetSelectable(playerid, VehicleSelection[15][playerid], 1);

	VehicleSelection[16][playerid] = CreatePlayerTextDraw(playerid, 355.000000, 269.000000, "FIND");
	PlayerTextDrawFont(playerid, VehicleSelection[16][playerid], 1);
	PlayerTextDrawLetterSize(playerid, VehicleSelection[16][playerid], 0.216667, 1.000000);
	PlayerTextDrawTextSize(playerid, VehicleSelection[16][playerid], 400.000000, 57.000000);
	PlayerTextDrawSetOutline(playerid, VehicleSelection[16][playerid], 1);
	PlayerTextDrawSetShadow(playerid, VehicleSelection[16][playerid], 0);
	PlayerTextDrawAlignment(playerid, VehicleSelection[16][playerid], 2);
	PlayerTextDrawColor(playerid, VehicleSelection[16][playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, VehicleSelection[16][playerid], 255);
	PlayerTextDrawBoxColor(playerid, VehicleSelection[16][playerid], -764862721);
	PlayerTextDrawUseBox(playerid, VehicleSelection[16][playerid], 1);
	PlayerTextDrawSetProportional(playerid, VehicleSelection[16][playerid], 1);
	PlayerTextDrawSetSelectable(playerid, VehicleSelection[16][playerid], 1);

	VehicleSelection[17][playerid] = CreatePlayerTextDraw(playerid, 425.000000, 269.000000, "FIND");
	PlayerTextDrawFont(playerid, VehicleSelection[17][playerid], 1);
	PlayerTextDrawLetterSize(playerid, VehicleSelection[17][playerid], 0.216667, 1.000000);
	PlayerTextDrawTextSize(playerid, VehicleSelection[17][playerid], 400.000000, 57.000000);
	PlayerTextDrawSetOutline(playerid, VehicleSelection[17][playerid], 1);
	PlayerTextDrawSetShadow(playerid, VehicleSelection[17][playerid], 0);
	PlayerTextDrawAlignment(playerid, VehicleSelection[17][playerid], 2);
	PlayerTextDrawColor(playerid, VehicleSelection[17][playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, VehicleSelection[17][playerid], 255);
	PlayerTextDrawBoxColor(playerid, VehicleSelection[17][playerid], -764862721);
	PlayerTextDrawUseBox(playerid, VehicleSelection[17][playerid], 1);
	PlayerTextDrawSetProportional(playerid, VehicleSelection[17][playerid], 1);
	PlayerTextDrawSetSelectable(playerid, VehicleSelection[17][playerid], 1);

	VehicleSelection[18][playerid] = CreatePlayerTextDraw(playerid, 451.000000, 153.000000, "X");
	PlayerTextDrawFont(playerid, VehicleSelection[18][playerid], 1);
	PlayerTextDrawLetterSize(playerid, VehicleSelection[18][playerid], 0.408333, 1.250000);
	PlayerTextDrawTextSize(playerid, VehicleSelection[18][playerid], 400.000000, 11.500000);
	PlayerTextDrawSetOutline(playerid, VehicleSelection[18][playerid], 1);
	PlayerTextDrawSetShadow(playerid, VehicleSelection[18][playerid], 0);
	PlayerTextDrawAlignment(playerid, VehicleSelection[18][playerid], 2);
	PlayerTextDrawColor(playerid, VehicleSelection[18][playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, VehicleSelection[18][playerid], 255);
	PlayerTextDrawBoxColor(playerid, VehicleSelection[18][playerid], 50);
	PlayerTextDrawUseBox(playerid, VehicleSelection[18][playerid], 0);
	PlayerTextDrawSetProportional(playerid, VehicleSelection[18][playerid], 1);
	PlayerTextDrawSetSelectable(playerid, VehicleSelection[18][playerid], 1);
}

CreateTutorialTextDraws(playerid)
{
	tutorialbox[playerid] = CreatePlayerTextDraw(playerid, 321.000000, 308.000000, "_");
	PlayerTextDrawFont(playerid, tutorialbox[playerid], 1);
	PlayerTextDrawLetterSize(playerid, tutorialbox[playerid], 0.600000, 11.650008);
	PlayerTextDrawTextSize(playerid, tutorialbox[playerid], 298.500000, 253.000000);
	PlayerTextDrawSetOutline(playerid, tutorialbox[playerid], 1);
	PlayerTextDrawSetShadow(playerid, tutorialbox[playerid], 0);
	PlayerTextDrawAlignment(playerid, tutorialbox[playerid], 2);
	PlayerTextDrawColor(playerid, tutorialbox[playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, tutorialbox[playerid], 255);
	PlayerTextDrawBoxColor(playerid, tutorialbox[playerid], 200);
	PlayerTextDrawUseBox(playerid, tutorialbox[playerid], 1);
	PlayerTextDrawSetProportional(playerid, tutorialbox[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, tutorialbox[playerid], 0);

	tutorialtext[playerid] = CreatePlayerTextDraw(playerid, 195.000000, 309.000000, "Welcome to the los santos, a city tearing it self apart with gang trouble, drugs and corruption.");
	PlayerTextDrawFont(playerid, tutorialtext[playerid], 1);
	PlayerTextDrawLetterSize(playerid, tutorialtext[playerid], 0.233331, 1.149999);
	PlayerTextDrawTextSize(playerid, tutorialtext[playerid], 447.500000, 17.000000);
	PlayerTextDrawSetOutline(playerid, tutorialtext[playerid], 0);
	PlayerTextDrawSetShadow(playerid, tutorialtext[playerid], 0);
	PlayerTextDrawAlignment(playerid, tutorialtext[playerid], 1);
	PlayerTextDrawColor(playerid, tutorialtext[playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, tutorialtext[playerid], 255);
	PlayerTextDrawBoxColor(playerid, tutorialtext[playerid], 200);
	PlayerTextDrawUseBox(playerid, tutorialtext[playerid], 0);
	PlayerTextDrawSetProportional(playerid, tutorialtext[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, tutorialtext[playerid], 0);

	tutorialheader[playerid] = CreatePlayerTextDraw(playerid, 191.000000, 292.000000, "The Introduction");
	PlayerTextDrawFont(playerid, tutorialheader[playerid], 0);
	PlayerTextDrawLetterSize(playerid, tutorialheader[playerid], 0.495833, 1.549998);
	PlayerTextDrawTextSize(playerid, tutorialheader[playerid], 400.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, tutorialheader[playerid], 1);
	PlayerTextDrawSetShadow(playerid, tutorialheader[playerid], 0);
	PlayerTextDrawAlignment(playerid, tutorialheader[playerid], 1);
	PlayerTextDrawColor(playerid, tutorialheader[playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, tutorialheader[playerid], 255);
	PlayerTextDrawBoxColor(playerid, tutorialheader[playerid], 200);
	PlayerTextDrawUseBox(playerid, tutorialheader[playerid], 0);
	PlayerTextDrawSetProportional(playerid, tutorialheader[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, tutorialheader[playerid], 0);

	tutorialclick[playerid] = CreatePlayerTextDraw(playerid, 438.000000, 404.000000, "NEXT");
	PlayerTextDrawFont(playerid, tutorialclick[playerid], 3);
	PlayerTextDrawLetterSize(playerid, tutorialclick[playerid], 0.245833, 1.049999);
	PlayerTextDrawTextSize(playerid, tutorialclick[playerid], 446.000000, 24.000000);
	PlayerTextDrawSetOutline(playerid, tutorialclick[playerid], 1);
	PlayerTextDrawSetShadow(playerid, tutorialclick[playerid], 0);
	PlayerTextDrawAlignment(playerid, tutorialclick[playerid], 2);
	PlayerTextDrawColor(playerid, tutorialclick[playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, tutorialclick[playerid], 255);
	PlayerTextDrawBoxColor(playerid, tutorialclick[playerid], 200);
	PlayerTextDrawUseBox(playerid, tutorialclick[playerid], 0);
	PlayerTextDrawSetProportional(playerid, tutorialclick[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, tutorialclick[playerid], 1);

	tutorialskip[playerid] = CreatePlayerTextDraw(playerid, 440.000000, 296.000000, "SKIP");
	PlayerTextDrawFont(playerid, tutorialskip[playerid], 3);
	PlayerTextDrawLetterSize(playerid, tutorialskip[playerid], 0.245832, 1.049998);
	PlayerTextDrawTextSize(playerid, tutorialskip[playerid], 446.000000, 24.000000);
	PlayerTextDrawSetOutline(playerid, tutorialskip[playerid], 1);
	PlayerTextDrawSetShadow(playerid, tutorialskip[playerid], 0);
	PlayerTextDrawAlignment(playerid, tutorialskip[playerid], 2);
	PlayerTextDrawColor(playerid, tutorialskip[playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, tutorialskip[playerid], 255);
	PlayerTextDrawBoxColor(playerid, tutorialskip[playerid], 200);
	PlayerTextDrawUseBox(playerid, tutorialskip[playerid], 0);
	PlayerTextDrawSetProportional(playerid, tutorialskip[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, tutorialskip[playerid], 1);
}

CreateSelectFactionTextDraws(playerid)
{
	SelectFactionLocation[playerid] = CreatePlayerTextDraw(playerid, 319.000000, 355.000000, "Jayvon_Williams");
	PlayerTextDrawFont(playerid, SelectFactionLocation[playerid], 0);
	PlayerTextDrawLetterSize(playerid, SelectFactionLocation[playerid], 0.454166, 1.599999);
	PlayerTextDrawTextSize(playerid, SelectFactionLocation[playerid], 400.000000, 141.500000);
	PlayerTextDrawSetOutline(playerid, SelectFactionLocation[playerid], 1);
	PlayerTextDrawSetShadow(playerid, SelectFactionLocation[playerid], 0);
	PlayerTextDrawAlignment(playerid, SelectFactionLocation[playerid], 2);
	PlayerTextDrawColor(playerid, SelectFactionLocation[playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, SelectFactionLocation[playerid], 255);
	PlayerTextDrawBoxColor(playerid, SelectFactionLocation[playerid], 50);
	PlayerTextDrawUseBox(playerid, SelectFactionLocation[playerid], 0);
	PlayerTextDrawSetProportional(playerid, SelectFactionLocation[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, SelectFactionLocation[playerid], 0);

	SelectFaction[0][playerid] = CreatePlayerTextDraw(playerid, 262.000000, 390.000000, "Press '~r~LEFT~w~' or '~r~RIGHT~w~' to switch");
	PlayerTextDrawFont(playerid, SelectFaction[0][playerid], 1);
	PlayerTextDrawLetterSize(playerid, SelectFaction[0][playerid], 0.200000, 1.200000);
	PlayerTextDrawTextSize(playerid, SelectFaction[0][playerid], 400.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, SelectFaction[0][playerid], 1);
	PlayerTextDrawSetShadow(playerid, SelectFaction[0][playerid], 0);
	PlayerTextDrawAlignment(playerid, SelectFaction[0][playerid], 1);
	PlayerTextDrawColor(playerid, SelectFaction[0][playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, SelectFaction[0][playerid], 255);
	PlayerTextDrawBoxColor(playerid, SelectFaction[0][playerid], 50);
	PlayerTextDrawUseBox(playerid, SelectFaction[0][playerid], 0);
	PlayerTextDrawSetProportional(playerid, SelectFaction[0][playerid], 1);
	PlayerTextDrawSetSelectable(playerid, SelectFaction[0][playerid], 0);

	SelectFactionName[playerid] = CreatePlayerTextDraw(playerid, 319.000000, 374.000000, "San Andreas Police Departement");
	PlayerTextDrawFont(playerid, SelectFactionName[playerid], 0);
	PlayerTextDrawLetterSize(playerid, SelectFactionName[playerid], 0.312499, 1.200000);
	PlayerTextDrawTextSize(playerid, SelectFactionName[playerid], 407.500000, 166.500000);
	PlayerTextDrawSetOutline(playerid, SelectFactionName[playerid], 1);
	PlayerTextDrawSetShadow(playerid, SelectFactionName[playerid], 0);
	PlayerTextDrawAlignment(playerid, SelectFactionName[playerid], 2);
	PlayerTextDrawColor(playerid, SelectFactionName[playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, SelectFactionName[playerid], 255);
	PlayerTextDrawBoxColor(playerid, SelectFactionName[playerid], 50);
	PlayerTextDrawUseBox(playerid, SelectFactionName[playerid], 0);
	PlayerTextDrawSetProportional(playerid, SelectFactionName[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, SelectFactionName[playerid], 0);

	SelectFaction[1][playerid] = CreatePlayerTextDraw(playerid, 280.000000, 404.000000, "Press '~y~SPAWN~w~' to select");
	PlayerTextDrawFont(playerid, SelectFaction[1][playerid], 1);
	PlayerTextDrawLetterSize(playerid, SelectFaction[1][playerid], 0.191667, 1.200000);
	PlayerTextDrawTextSize(playerid, SelectFaction[1][playerid], 400.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, SelectFaction[1][playerid], 1);
	PlayerTextDrawSetShadow(playerid, SelectFaction[1][playerid], 0);
	PlayerTextDrawAlignment(playerid, SelectFaction[1][playerid], 1);
	PlayerTextDrawColor(playerid, SelectFaction[1][playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, SelectFaction[1][playerid], 255);
	PlayerTextDrawBoxColor(playerid, SelectFaction[1][playerid], 50);
	PlayerTextDrawUseBox(playerid, SelectFaction[1][playerid], 0);
	PlayerTextDrawSetProportional(playerid, SelectFaction[1][playerid], 1);
	PlayerTextDrawSetSelectable(playerid, SelectFaction[1][playerid], 0);

	SelectFactionClick[0][playerid] = CreatePlayerTextDraw(playerid, 239.000000, 388.000000, "ld_beat:left");
	PlayerTextDrawFont(playerid, SelectFactionClick[0][playerid], 4);
	PlayerTextDrawLetterSize(playerid, SelectFactionClick[0][playerid], 0.600000, 2.000000);
	PlayerTextDrawTextSize(playerid, SelectFactionClick[0][playerid], 17.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, SelectFactionClick[0][playerid], 1);
	PlayerTextDrawSetShadow(playerid, SelectFactionClick[0][playerid], 0);
	PlayerTextDrawAlignment(playerid, SelectFactionClick[0][playerid], 1);
	PlayerTextDrawColor(playerid, SelectFactionClick[0][playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, SelectFactionClick[0][playerid], 255);
	PlayerTextDrawBoxColor(playerid, SelectFactionClick[0][playerid], 50);
	PlayerTextDrawUseBox(playerid, SelectFactionClick[0][playerid], 1);
	PlayerTextDrawSetProportional(playerid, SelectFactionClick[0][playerid], 1);
	PlayerTextDrawSetSelectable(playerid, SelectFactionClick[0][playerid], 1);

	SelectFactionClick[1][playerid] = CreatePlayerTextDraw(playerid, 382.000000, 388.000000, "ld_beat:right");
	PlayerTextDrawFont(playerid, SelectFactionClick[1][playerid], 4);
	PlayerTextDrawLetterSize(playerid, SelectFactionClick[1][playerid], 0.600000, 2.000000);
	PlayerTextDrawTextSize(playerid, SelectFactionClick[1][playerid], 17.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, SelectFactionClick[1][playerid], 1);
	PlayerTextDrawSetShadow(playerid, SelectFactionClick[1][playerid], 0);
	PlayerTextDrawAlignment(playerid, SelectFactionClick[1][playerid], 1);
	PlayerTextDrawColor(playerid, SelectFactionClick[1][playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, SelectFactionClick[1][playerid], 255);
	PlayerTextDrawBoxColor(playerid, SelectFactionClick[1][playerid], 50);
	PlayerTextDrawUseBox(playerid, SelectFactionClick[1][playerid], 1);
	PlayerTextDrawSetProportional(playerid, SelectFactionClick[1][playerid], 1);
	PlayerTextDrawSetSelectable(playerid, SelectFactionClick[1][playerid], 1);

	SelectFactionClick[2][playerid] = CreatePlayerTextDraw(playerid, 319.000000, 417.000000, "~y~Spawn");
	PlayerTextDrawFont(playerid, SelectFactionClick[2][playerid], 0);
	PlayerTextDrawLetterSize(playerid, SelectFactionClick[2][playerid], 0.379166, 1.499999);
	PlayerTextDrawTextSize(playerid, SelectFactionClick[2][playerid], 400.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, SelectFactionClick[2][playerid], 1);
	PlayerTextDrawSetShadow(playerid, SelectFactionClick[2][playerid], 0);
	PlayerTextDrawAlignment(playerid, SelectFactionClick[2][playerid], 2);
	PlayerTextDrawColor(playerid, SelectFactionClick[2][playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, SelectFactionClick[2][playerid], 255);
	PlayerTextDrawBoxColor(playerid, SelectFactionClick[2][playerid], 50);
	PlayerTextDrawUseBox(playerid, SelectFactionClick[2][playerid], 0);
	PlayerTextDrawSetProportional(playerid, SelectFactionClick[2][playerid], 1);
	PlayerTextDrawSetSelectable(playerid, SelectFactionClick[2][playerid], 1);
}

CreatePoolTextDraws(playerid)
{
	pool[0][playerid] = CreatePlayerTextDraw(playerid, 288.000000, 396.000000, "~y~Shoot");
	PlayerTextDrawFont(playerid, pool[0][playerid], 0);
	PlayerTextDrawLetterSize(playerid, pool[0][playerid], 0.454165, 1.649999);
	PlayerTextDrawTextSize(playerid, pool[0][playerid], 17.000000, 43.500000);
	PlayerTextDrawSetOutline(playerid, pool[0][playerid], 1);
	PlayerTextDrawSetShadow(playerid, pool[0][playerid], 0);
	PlayerTextDrawAlignment(playerid, pool[0][playerid], 2);
	PlayerTextDrawColor(playerid, pool[0][playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, pool[0][playerid], 255);
	PlayerTextDrawBoxColor(playerid, pool[0][playerid], 50);
	PlayerTextDrawUseBox(playerid, pool[0][playerid], 0);
	PlayerTextDrawSetProportional(playerid, pool[0][playerid], 1);
	PlayerTextDrawSetSelectable(playerid, pool[0][playerid], 1);

	pool[1][playerid] = CreatePlayerTextDraw(playerid, 248.000000, 358.000000, "ld_beat:left");
	PlayerTextDrawFont(playerid, pool[1][playerid], 4);
	PlayerTextDrawLetterSize(playerid, pool[1][playerid], 0.400000, 1.549998);
	PlayerTextDrawTextSize(playerid, pool[1][playerid], 17.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, pool[1][playerid], 1);
	PlayerTextDrawSetShadow(playerid, pool[1][playerid], 0);
	PlayerTextDrawAlignment(playerid, pool[1][playerid], 2);
	PlayerTextDrawColor(playerid, pool[1][playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, pool[1][playerid], 255);
	PlayerTextDrawBoxColor(playerid, pool[1][playerid], 50);
	PlayerTextDrawUseBox(playerid, pool[1][playerid], 0);
	PlayerTextDrawSetProportional(playerid, pool[1][playerid], 1);
	PlayerTextDrawSetSelectable(playerid, pool[1][playerid], 1);

	pool[2][playerid] = CreatePlayerTextDraw(playerid, 374.000000, 358.000000, "ld_beat:right");
	PlayerTextDrawFont(playerid, pool[2][playerid], 4);
	PlayerTextDrawLetterSize(playerid, pool[2][playerid], 0.400000, 1.549998);
	PlayerTextDrawTextSize(playerid, pool[2][playerid], 17.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, pool[2][playerid], 1);
	PlayerTextDrawSetShadow(playerid, pool[2][playerid], 0);
	PlayerTextDrawAlignment(playerid, pool[2][playerid], 2);
	PlayerTextDrawColor(playerid, pool[2][playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, pool[2][playerid], 255);
	PlayerTextDrawBoxColor(playerid, pool[2][playerid], 50);
	PlayerTextDrawUseBox(playerid, pool[2][playerid], 0);
	PlayerTextDrawSetProportional(playerid, pool[2][playerid], 1);
	PlayerTextDrawSetSelectable(playerid, pool[2][playerid], 1);

	pool[3][playerid] = CreatePlayerTextDraw(playerid, 321.000000, 350.000000, "Press '~r~LEFT~w~' or '~r~RIGHT~w~' to change your camera position~n~Press '~y~Shoot~w~' to shoot~n~You power : ~y~50%");
	PlayerTextDrawFont(playerid, pool[3][playerid], 1);
	PlayerTextDrawLetterSize(playerid, pool[3][playerid], 0.179166, 1.100000);
	PlayerTextDrawTextSize(playerid, pool[3][playerid], 17.000000, 107.500000);
	PlayerTextDrawSetOutline(playerid, pool[3][playerid], 1);
	PlayerTextDrawSetShadow(playerid, pool[3][playerid], 0);
	PlayerTextDrawAlignment(playerid, pool[3][playerid], 2);
	PlayerTextDrawColor(playerid, pool[3][playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, pool[3][playerid], 255);
	PlayerTextDrawBoxColor(playerid, pool[3][playerid], 50);
	PlayerTextDrawUseBox(playerid, pool[3][playerid], 0);
	PlayerTextDrawSetProportional(playerid, pool[3][playerid], 1);
	PlayerTextDrawSetSelectable(playerid, pool[3][playerid], 0);

	pool[4][playerid] = CreatePlayerTextDraw(playerid, 356.000000, 396.000000, "Exit");
	PlayerTextDrawFont(playerid, pool[4][playerid], 0);
	PlayerTextDrawLetterSize(playerid, pool[4][playerid], 0.454165, 1.649999);
	PlayerTextDrawTextSize(playerid, pool[4][playerid], 17.000000, 43.500000);
	PlayerTextDrawSetOutline(playerid, pool[4][playerid], 1);
	PlayerTextDrawSetShadow(playerid, pool[4][playerid], 0);
	PlayerTextDrawAlignment(playerid, pool[4][playerid], 2);
	PlayerTextDrawColor(playerid, pool[4][playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, pool[4][playerid], 255);
	PlayerTextDrawBoxColor(playerid, pool[4][playerid], 50);
	PlayerTextDrawUseBox(playerid, pool[4][playerid], 0);
	PlayerTextDrawSetProportional(playerid, pool[4][playerid], 1);
	PlayerTextDrawSetSelectable(playerid, pool[4][playerid], 1);
}

CreateALPRTextdraws(playerid)
{
	ALPR[0][playerid] = CreatePlayerTextDraw(playerid, 554.000000, 154.000000, "ALPR");
	PlayerTextDrawFont(playerid, ALPR[0][playerid], 2);
	PlayerTextDrawLetterSize(playerid, ALPR[0][playerid], 0.324995, 1.150009);
	PlayerTextDrawTextSize(playerid, ALPR[0][playerid], 400.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, ALPR[0][playerid], 1);
	PlayerTextDrawSetShadow(playerid, ALPR[0][playerid], 0);
	PlayerTextDrawAlignment(playerid, ALPR[0][playerid], 2);
	PlayerTextDrawColor(playerid, ALPR[0][playerid], -1379670017);
	PlayerTextDrawBackgroundColor(playerid, ALPR[0][playerid], 255);
	PlayerTextDrawBoxColor(playerid, ALPR[0][playerid], 50);
	PlayerTextDrawUseBox(playerid, ALPR[0][playerid], 0);
	PlayerTextDrawSetProportional(playerid, ALPR[0][playerid], 1);
	PlayerTextDrawSetSelectable(playerid, ALPR[0][playerid], 0);

	ALPR[1][playerid] = CreatePlayerTextDraw(playerid, 554.000000, 166.000000, "Model : Elegy");
	PlayerTextDrawFont(playerid, ALPR[1][playerid], 2);
	PlayerTextDrawLetterSize(playerid, ALPR[1][playerid], 0.241655, 1.099993);
	PlayerTextDrawTextSize(playerid, ALPR[1][playerid], 605.000000, 258.000000);
	PlayerTextDrawSetOutline(playerid, ALPR[1][playerid], 1);
	PlayerTextDrawSetShadow(playerid, ALPR[1][playerid], 0);
	PlayerTextDrawAlignment(playerid, ALPR[1][playerid], 2);
	PlayerTextDrawColor(playerid, ALPR[1][playerid], -1379670017);
	PlayerTextDrawBackgroundColor(playerid, ALPR[1][playerid], 255);
	PlayerTextDrawBoxColor(playerid, ALPR[1][playerid], 50);
	PlayerTextDrawUseBox(playerid, ALPR[1][playerid], 0);
	PlayerTextDrawSetProportional(playerid, ALPR[1][playerid], 1);
	PlayerTextDrawSetSelectable(playerid, ALPR[1][playerid], 0);

	ALPR[2][playerid] = CreatePlayerTextDraw(playerid, 554.000000, 178.000000, "Plates : 010101");
	PlayerTextDrawFont(playerid, ALPR[2][playerid], 2);
	PlayerTextDrawLetterSize(playerid, ALPR[2][playerid], 0.266659, 1.099993);
	PlayerTextDrawTextSize(playerid, ALPR[2][playerid], 605.000000, 258.000000);
	PlayerTextDrawSetOutline(playerid, ALPR[2][playerid], 1);
	PlayerTextDrawSetShadow(playerid, ALPR[2][playerid], 0);
	PlayerTextDrawAlignment(playerid, ALPR[2][playerid], 2);
	PlayerTextDrawColor(playerid, ALPR[2][playerid], -1379670017);
	PlayerTextDrawBackgroundColor(playerid, ALPR[2][playerid], 255);
	PlayerTextDrawBoxColor(playerid, ALPR[2][playerid], 50);
	PlayerTextDrawUseBox(playerid, ALPR[2][playerid], 0);
	PlayerTextDrawSetProportional(playerid, ALPR[2][playerid], 1);
	PlayerTextDrawSetSelectable(playerid, ALPR[2][playerid], 0);

	ALPR[3][playerid] = CreatePlayerTextDraw(playerid, 554.000000, 191.000000, "R.O : Registered");
	PlayerTextDrawFont(playerid, ALPR[3][playerid], 2);
	PlayerTextDrawLetterSize(playerid, ALPR[3][playerid], 0.216658, 1.149993);
	PlayerTextDrawTextSize(playerid, ALPR[3][playerid], 605.000000, 258.000000);
	PlayerTextDrawSetOutline(playerid, ALPR[3][playerid], 1);
	PlayerTextDrawSetShadow(playerid, ALPR[3][playerid], 0);
	PlayerTextDrawAlignment(playerid, ALPR[3][playerid], 2);
	PlayerTextDrawColor(playerid, ALPR[3][playerid], -1379670017);
	PlayerTextDrawBackgroundColor(playerid, ALPR[3][playerid], 255);
	PlayerTextDrawBoxColor(playerid, ALPR[3][playerid], 50);
	PlayerTextDrawUseBox(playerid, ALPR[3][playerid], 0);
	PlayerTextDrawSetProportional(playerid, ALPR[3][playerid], 1);
	PlayerTextDrawSetSelectable(playerid, ALPR[3][playerid], 0);
}

CreateFoodOrderTextDraws(playerid)
{
	FoodOrder[0][playerid] = CreatePlayerTextDraw(playerid, 322.000000, 143.000000, "_");
	PlayerTextDrawFont(playerid, FoodOrder[0][playerid], 1);
	PlayerTextDrawLetterSize(playerid, FoodOrder[0][playerid], 0.600000, 19.300012);
	PlayerTextDrawTextSize(playerid, FoodOrder[0][playerid], 298.500000, 225.500000);
	PlayerTextDrawSetOutline(playerid, FoodOrder[0][playerid], 1);
	PlayerTextDrawSetShadow(playerid, FoodOrder[0][playerid], 0);
	PlayerTextDrawAlignment(playerid, FoodOrder[0][playerid], 2);
	PlayerTextDrawColor(playerid, FoodOrder[0][playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, FoodOrder[0][playerid], 255);
	PlayerTextDrawBoxColor(playerid, FoodOrder[0][playerid], 255);
	PlayerTextDrawUseBox(playerid, FoodOrder[0][playerid], 1);
	PlayerTextDrawSetProportional(playerid, FoodOrder[0][playerid], 1);
	PlayerTextDrawSetSelectable(playerid, FoodOrder[0][playerid], 0);

	FoodOrder[1][playerid] = CreatePlayerTextDraw(playerid, 208.000000, 144.000000, "The Pizzeria");
	PlayerTextDrawFont(playerid, FoodOrder[1][playerid], 0);
	PlayerTextDrawLetterSize(playerid, FoodOrder[1][playerid], 0.416663, 1.949999);
	PlayerTextDrawTextSize(playerid, FoodOrder[1][playerid], 400.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, FoodOrder[1][playerid], 1);
	PlayerTextDrawSetShadow(playerid, FoodOrder[1][playerid], 0);
	PlayerTextDrawAlignment(playerid, FoodOrder[1][playerid], 1);
	PlayerTextDrawColor(playerid, FoodOrder[1][playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, FoodOrder[1][playerid], 255);
	PlayerTextDrawBoxColor(playerid, FoodOrder[1][playerid], 50);
	PlayerTextDrawUseBox(playerid, FoodOrder[1][playerid], 0);
	PlayerTextDrawSetProportional(playerid, FoodOrder[1][playerid], 1);
	PlayerTextDrawSetSelectable(playerid, FoodOrder[1][playerid], 0);

	FoodOrder[2][playerid] = CreatePlayerTextDraw(playerid, 209.000000, 167.000000, "Preview_Model");
	PlayerTextDrawFont(playerid, FoodOrder[2][playerid], 5);
	PlayerTextDrawLetterSize(playerid, FoodOrder[2][playerid], 0.600000, 2.000000);
	PlayerTextDrawTextSize(playerid, FoodOrder[2][playerid], 71.500000, 88.000000);
	PlayerTextDrawSetOutline(playerid, FoodOrder[2][playerid], 0);
	PlayerTextDrawSetShadow(playerid, FoodOrder[2][playerid], 0);
	PlayerTextDrawAlignment(playerid, FoodOrder[2][playerid], 1);
	PlayerTextDrawColor(playerid, FoodOrder[2][playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, FoodOrder[2][playerid], 0);
	PlayerTextDrawBoxColor(playerid, FoodOrder[2][playerid], 0);
	PlayerTextDrawUseBox(playerid, FoodOrder[2][playerid], 0);
	PlayerTextDrawSetProportional(playerid, FoodOrder[2][playerid], 1);
	PlayerTextDrawSetSelectable(playerid, FoodOrder[2][playerid], 1);
	PlayerTextDrawSetPreviewModel(playerid, FoodOrder[2][playerid], 2218);
	PlayerTextDrawSetPreviewRot(playerid, FoodOrder[2][playerid], -37.000000, 6.000000, 28.000000, 1.000000);
	PlayerTextDrawSetPreviewVehCol(playerid, FoodOrder[2][playerid], 1, 1);

	FoodOrder[3][playerid] = CreatePlayerTextDraw(playerid, 282.000000, 167.000000, "Preview_Model");
	PlayerTextDrawFont(playerid, FoodOrder[3][playerid], 5);
	PlayerTextDrawLetterSize(playerid, FoodOrder[3][playerid], 0.600000, 2.000000);
	PlayerTextDrawTextSize(playerid, FoodOrder[3][playerid], 71.500000, 88.000000);
	PlayerTextDrawSetOutline(playerid, FoodOrder[3][playerid], 0);
	PlayerTextDrawSetShadow(playerid, FoodOrder[3][playerid], 0);
	PlayerTextDrawAlignment(playerid, FoodOrder[3][playerid], 1);
	PlayerTextDrawColor(playerid, FoodOrder[3][playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, FoodOrder[3][playerid], 0);
	PlayerTextDrawBoxColor(playerid, FoodOrder[3][playerid], 0);
	PlayerTextDrawUseBox(playerid, FoodOrder[3][playerid], 0);
	PlayerTextDrawSetProportional(playerid, FoodOrder[3][playerid], 1);
	PlayerTextDrawSetSelectable(playerid, FoodOrder[3][playerid], 1);
	PlayerTextDrawSetPreviewModel(playerid, FoodOrder[3][playerid], 2219);
	PlayerTextDrawSetPreviewRot(playerid, FoodOrder[3][playerid], -37.000000, 6.000000, 28.000000, 1.000000);
	PlayerTextDrawSetPreviewVehCol(playerid, FoodOrder[3][playerid], 1, 1);

	FoodOrder[4][playerid] = CreatePlayerTextDraw(playerid, 355.000000, 168.000000, "Preview_Model");
	PlayerTextDrawFont(playerid, FoodOrder[4][playerid], 5);
	PlayerTextDrawLetterSize(playerid, FoodOrder[4][playerid], 0.600000, 2.000000);
	PlayerTextDrawTextSize(playerid, FoodOrder[4][playerid], 71.500000, 88.000000);
	PlayerTextDrawSetOutline(playerid, FoodOrder[4][playerid], 0);
	PlayerTextDrawSetShadow(playerid, FoodOrder[4][playerid], 0);
	PlayerTextDrawAlignment(playerid, FoodOrder[4][playerid], 1);
	PlayerTextDrawColor(playerid, FoodOrder[4][playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, FoodOrder[4][playerid], 0);
	PlayerTextDrawBoxColor(playerid, FoodOrder[4][playerid], 0);
	PlayerTextDrawUseBox(playerid, FoodOrder[4][playerid], 0);
	PlayerTextDrawSetProportional(playerid, FoodOrder[4][playerid], 1);
	PlayerTextDrawSetSelectable(playerid, FoodOrder[4][playerid], 1);
	PlayerTextDrawSetPreviewModel(playerid, FoodOrder[4][playerid], 2220);
	PlayerTextDrawSetPreviewRot(playerid, FoodOrder[4][playerid], -37.000000, 6.000000, 28.000000, 1.000000);
	PlayerTextDrawSetPreviewVehCol(playerid, FoodOrder[4][playerid], 1, 1);

	FoodOrder[5][playerid] = CreatePlayerTextDraw(playerid, 251.000000, 257.000000, "Buster~n~~r~Health +10.0~n~~b~Price $50");
	PlayerTextDrawFont(playerid, FoodOrder[5][playerid], 1);
	PlayerTextDrawLetterSize(playerid, FoodOrder[5][playerid], 0.199997, 0.850000);
	PlayerTextDrawTextSize(playerid, FoodOrder[5][playerid], 400.000000, 65.000000);
	PlayerTextDrawSetOutline(playerid, FoodOrder[5][playerid], 0);
	PlayerTextDrawSetShadow(playerid, FoodOrder[5][playerid], 0);
	PlayerTextDrawAlignment(playerid, FoodOrder[5][playerid], 2);
	PlayerTextDrawColor(playerid, FoodOrder[5][playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, FoodOrder[5][playerid], 255);
	PlayerTextDrawBoxColor(playerid, FoodOrder[5][playerid], 50);
	PlayerTextDrawUseBox(playerid, FoodOrder[5][playerid], 0);
	PlayerTextDrawSetProportional(playerid, FoodOrder[5][playerid], 1);
	PlayerTextDrawSetSelectable(playerid, FoodOrder[5][playerid], 0);

	FoodOrder[6][playerid] = CreatePlayerTextDraw(playerid, 210.000000, 167.000000, "This restaurant offers multiple meals.~n~Choose one by clicking on its pictures");
	PlayerTextDrawFont(playerid, FoodOrder[6][playerid], 1);
	PlayerTextDrawLetterSize(playerid, FoodOrder[6][playerid], 0.174997, 0.849999);
	PlayerTextDrawTextSize(playerid, FoodOrder[6][playerid], 400.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, FoodOrder[6][playerid], 1);
	PlayerTextDrawSetShadow(playerid, FoodOrder[6][playerid], 0);
	PlayerTextDrawAlignment(playerid, FoodOrder[6][playerid], 1);
	PlayerTextDrawColor(playerid, FoodOrder[6][playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, FoodOrder[6][playerid], 255);
	PlayerTextDrawBoxColor(playerid, FoodOrder[6][playerid], 50);
	PlayerTextDrawUseBox(playerid, FoodOrder[6][playerid], 0);
	PlayerTextDrawSetProportional(playerid, FoodOrder[6][playerid], 1);
	PlayerTextDrawSetSelectable(playerid, FoodOrder[6][playerid], 0);

	FoodOrder[7][playerid] = CreatePlayerTextDraw(playerid, 327.000000, 257.000000, "Duoble D-Luxe~n~~r~Health +10.0~n~~b~Price $50");
	PlayerTextDrawFont(playerid, FoodOrder[7][playerid], 1);
	PlayerTextDrawLetterSize(playerid, FoodOrder[7][playerid], 0.199997, 0.850000);
	PlayerTextDrawTextSize(playerid, FoodOrder[7][playerid], 400.000000, 65.000000);
	PlayerTextDrawSetOutline(playerid, FoodOrder[7][playerid], 0);
	PlayerTextDrawSetShadow(playerid, FoodOrder[7][playerid], 0);
	PlayerTextDrawAlignment(playerid, FoodOrder[7][playerid], 2);
	PlayerTextDrawColor(playerid, FoodOrder[7][playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, FoodOrder[7][playerid], 255);
	PlayerTextDrawBoxColor(playerid, FoodOrder[7][playerid], 50);
	PlayerTextDrawUseBox(playerid, FoodOrder[7][playerid], 0);
	PlayerTextDrawSetProportional(playerid, FoodOrder[7][playerid], 1);
	PlayerTextDrawSetSelectable(playerid, FoodOrder[7][playerid], 0);

	FoodOrder[8][playerid] = CreatePlayerTextDraw(playerid, 401.000000, 257.000000, "Full Rack~n~~r~Health +10.0~n~~b~Price $50");
	PlayerTextDrawFont(playerid, FoodOrder[8][playerid], 1);
	PlayerTextDrawLetterSize(playerid, FoodOrder[8][playerid], 0.199997, 0.850000);
	PlayerTextDrawTextSize(playerid, FoodOrder[8][playerid], 400.000000, 65.000000);
	PlayerTextDrawSetOutline(playerid, FoodOrder[8][playerid], 0);
	PlayerTextDrawSetShadow(playerid, FoodOrder[8][playerid], 0);
	PlayerTextDrawAlignment(playerid, FoodOrder[8][playerid], 2);
	PlayerTextDrawColor(playerid, FoodOrder[8][playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, FoodOrder[8][playerid], 255);
	PlayerTextDrawBoxColor(playerid, FoodOrder[8][playerid], 50);
	PlayerTextDrawUseBox(playerid, FoodOrder[8][playerid], 0);
	PlayerTextDrawSetProportional(playerid, FoodOrder[8][playerid], 1);
	PlayerTextDrawSetSelectable(playerid, FoodOrder[8][playerid], 0);

	FoodOrder[9][playerid] = CreatePlayerTextDraw(playerid, 428.000000, 143.000000, "X");
	PlayerTextDrawFont(playerid, FoodOrder[9][playerid], 1);
	PlayerTextDrawLetterSize(playerid, FoodOrder[9][playerid], 0.349997, 1.449999);
	PlayerTextDrawTextSize(playerid, FoodOrder[9][playerid], 400.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, FoodOrder[9][playerid], 1);
	PlayerTextDrawSetShadow(playerid, FoodOrder[9][playerid], 0);
	PlayerTextDrawAlignment(playerid, FoodOrder[9][playerid], 2);
	PlayerTextDrawColor(playerid, FoodOrder[9][playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, FoodOrder[9][playerid], 255);
	PlayerTextDrawBoxColor(playerid, FoodOrder[9][playerid], 50);
	PlayerTextDrawUseBox(playerid, FoodOrder[9][playerid], 0);
	PlayerTextDrawSetProportional(playerid, FoodOrder[9][playerid], 1);
	PlayerTextDrawSetSelectable(playerid, FoodOrder[9][playerid], 1);
}

stock ShowBoxMessage(playerid, string[], time, type=0)
{
	new validtime = time*1000;

	switch(type)
	{
		case 0:
		{
			PlayerTextDrawSetString(playerid, Footers[playerid], string);
			PlayerTextDrawShow(playerid, Footers[playerid]);
		}
		case 1:
		{
			PlayerTextDrawSetString(playerid, Subtittles[playerid], string);
			PlayerTextDrawShow(playerid, Subtittles[playerid]);
		}
		case 2:
		{
			PlayerTextDrawSetString(playerid, Messages[playerid], string);
			PlayerTextDrawShow(playerid, Messages[playerid]);
		}
	}
	SetTimerEx("HideBoxMessage", validtime, false, "d", playerid);
	return 1;
}
function:HideBoxMessage(playerid)
{
	PlayerTextDrawHide(playerid, Footers[playerid]);
	PlayerTextDrawHide(playerid, Messages[playerid]);
	PlayerTextDrawHide(playerid, Subtittles[playerid]);
	return 1; 
}

stock ShowHeaderMessage(playerid, header[], string[], hide = 0)
{
	if(!hide)
	{
		PlayerTextDrawSetString(playerid, HeaderTD[1][playerid], header);
		PlayerTextDrawShow(playerid, HeaderTD[1][playerid]);

		PlayerTextDrawSetString(playerid, HeaderTD[0][playerid], string);
		PlayerTextDrawShow(playerid, HeaderTD[0][playerid]);

		SetTimerEx("HideHeaderMessage", 5000, false, "d", playerid);
	}

	PlayerTextDrawSetString(playerid, HeaderTD[1][playerid], header);
	PlayerTextDrawShow(playerid, HeaderTD[1][playerid]);

	PlayerTextDrawSetString(playerid, HeaderTD[0][playerid], string);
	PlayerTextDrawShow(playerid, HeaderTD[0][playerid]);
	return 1;
}

function:HideHeaderMessage(playerid)
{
	PlayerTextDrawHide(playerid, HeaderTD[0][playerid]);
	PlayerTextDrawHide(playerid, HeaderTD[1][playerid]);
	return 1;
}

stock ShowVehicleSpeedometer(playerid)
{
	for(new i; i < 15; i++){
		PlayerTextDrawShow(playerid, speedo[i][playerid]);
	}
	return 1;
}

stock HideVehicleSpeedometer(playerid)
{
	for(new i; i < 15; i++){
		PlayerTextDrawHide(playerid, speedo[i][playerid]);
	}
	return 1;
}

stock ShowMoneyFormat(playerid)
{
	PlayerTextDrawShow(playerid, MoneyFormat[playerid]);
	return 1;
}

stock HideMoneyFormat(playerid)
{
	PlayerTextDrawHide(playerid, MoneyFormat[playerid]);
	return 1;
}

stock ShowGameBar(playerid, value, header[])
{
	SetPlayerProgressBarColour(playerid, HeaderBar[playerid], ConvertHBEColor(value));
	ShowPlayerProgressBar(playerid, HeaderBar[playerid]);
	PlayerTextDrawShow(playerid, GameBar[0][playerid]);
	PlayerTextDrawShow(playerid, GameBar[2][playerid]);
	PlayerTextDrawSetString(playerid, GameBar[0][playerid], header);
	SetPlayerGameBar(playerid, value);
	return 1;
}

stock DestroyGameBar(playerid)
{
	PlayerTextDrawHide(playerid, GameBar[0][playerid]);
	PlayerTextDrawHide(playerid, GameBar[2][playerid]);
	HidePlayerProgressBar(playerid, HeaderBar[playerid]);
	return 1;
}

DestroySpectatorPanel(playerid) 
{
	for ( new i, j = 5; i < j ; i ++ ) 
	{
		PlayerTextDrawHide(playerid, gui_spec_label[playerid][i]);
	}
	return 1;
}

CreateSpectatorTextDraws(playerid) {

	gui_spec_label[playerid][0] = CreatePlayerTextDraw(playerid, 320.0000, 300.0000, "(0) Firstname_Lastname (Account)");
	PlayerTextDrawFont(playerid, gui_spec_label[playerid][0], 1);
	PlayerTextDrawLetterSize(playerid, gui_spec_label[playerid][0], 0.3499, 1.5000);
	PlayerTextDrawAlignment(playerid, gui_spec_label[playerid][0], 2);
	PlayerTextDrawColor(playerid, gui_spec_label[playerid][0], -1);
	PlayerTextDrawSetShadow(playerid, gui_spec_label[playerid][0], 0);
	PlayerTextDrawSetOutline(playerid, gui_spec_label[playerid][0], 1);
	PlayerTextDrawBackgroundColor(playerid, gui_spec_label[playerid][0], 255);
	PlayerTextDrawSetProportional(playerid, gui_spec_label[playerid][0], 1);
	PlayerTextDrawTextSize(playerid, gui_spec_label[playerid][0], 0.0000, 500.0000);

	gui_spec_label[playerid][1] = CreatePlayerTextDraw(playerid, 320.0000, 319.5000, "~w~Interior ~p~<1> ~w~World ~p~<2> ~w~Coords: ~p~<1234.56 7890.12 3456.78>");
	PlayerTextDrawFont(playerid, gui_spec_label[playerid][1], 1);
	PlayerTextDrawLetterSize(playerid, gui_spec_label[playerid][1], 0.2000, 0.8500);
	PlayerTextDrawAlignment(playerid, gui_spec_label[playerid][1], 2);
	PlayerTextDrawColor(playerid, gui_spec_label[playerid][1], -1);
	PlayerTextDrawSetShadow(playerid, gui_spec_label[playerid][1], 0);
	PlayerTextDrawSetOutline(playerid, gui_spec_label[playerid][1], 1);
	PlayerTextDrawBackgroundColor(playerid, gui_spec_label[playerid][1], 255);
	PlayerTextDrawSetProportional(playerid, gui_spec_label[playerid][1], 1);
	PlayerTextDrawTextSize(playerid, gui_spec_label[playerid][1], 0.0000, 500.0000);

	gui_spec_label[playerid][2] = CreatePlayerTextDraw(playerid, 320.0000, 329.5000, "State: ~r~ON FOOT~w~ Health: ~r~100.0 (client: 95)~w~ Armour: ~r~24.0 (client: 24.0)");
	PlayerTextDrawFont(playerid, gui_spec_label[playerid][2], 1);
	PlayerTextDrawLetterSize(playerid, gui_spec_label[playerid][2], 0.2000, 0.8500);
	PlayerTextDrawAlignment(playerid, gui_spec_label[playerid][2], 2);
	PlayerTextDrawColor(playerid, gui_spec_label[playerid][2], -1);
	PlayerTextDrawSetShadow(playerid, gui_spec_label[playerid][2], 0);
	PlayerTextDrawSetOutline(playerid, gui_spec_label[playerid][2], 1);
	PlayerTextDrawBackgroundColor(playerid, gui_spec_label[playerid][2], 255);
	PlayerTextDrawSetProportional(playerid, gui_spec_label[playerid][2], 1);
	PlayerTextDrawTextSize(playerid, gui_spec_label[playerid][2], 0.0000, 500.0000);

	gui_spec_label[playerid][3] = CreatePlayerTextDraw(playerid, 320.0000, 339.5000, "Packet Loss:~g~ 17.4'/.~w~ Ping:~g~ 64~w~ Drunk Level: ~g~234~w~ FPS: ~g~75");
	PlayerTextDrawFont(playerid, gui_spec_label[playerid][3], 1);
	PlayerTextDrawLetterSize(playerid, gui_spec_label[playerid][3], 0.2000, 0.8500);
	PlayerTextDrawAlignment(playerid, gui_spec_label[playerid][3], 2);
	PlayerTextDrawColor(playerid, gui_spec_label[playerid][3], -1);
	PlayerTextDrawSetShadow(playerid, gui_spec_label[playerid][3], 0);
	PlayerTextDrawSetOutline(playerid, gui_spec_label[playerid][3], 1);
	PlayerTextDrawBackgroundColor(playerid, gui_spec_label[playerid][3], 255);
	PlayerTextDrawSetProportional(playerid, gui_spec_label[playerid][3], 1);
	PlayerTextDrawTextSize(playerid, gui_spec_label[playerid][3], 0.0000, 500.0000);

	gui_spec_label[playerid][4] = CreatePlayerTextDraw(playerid, 320.0000, 349.5000, "Vehicle:~b~ None: ~y~MOD: 0, VID: 0~w~ Vehicle Health:~b~ 1000.0");
	PlayerTextDrawFont(playerid, gui_spec_label[playerid][4], 1);
	PlayerTextDrawLetterSize(playerid, gui_spec_label[playerid][4], 0.2000, 0.8500);
	PlayerTextDrawAlignment(playerid, gui_spec_label[playerid][4], 2);
	PlayerTextDrawColor(playerid, gui_spec_label[playerid][4], -1);
	PlayerTextDrawSetShadow(playerid, gui_spec_label[playerid][4], 0);
	PlayerTextDrawSetOutline(playerid, gui_spec_label[playerid][4], 1);
	PlayerTextDrawBackgroundColor(playerid, gui_spec_label[playerid][4], 255);
	PlayerTextDrawSetProportional(playerid, gui_spec_label[playerid][4], 1);
	PlayerTextDrawTextSize(playerid, gui_spec_label[playerid][4], 0.0000, 500.0000);
	return 1;
}
