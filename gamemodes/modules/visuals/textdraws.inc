//Textdraws
new Text:Times;
new PlayerText:servername[MAX_PLAYERS];
new PlayerText:VehicleName[MAX_PLAYERS];
new PlayerText:loginscreen[3][MAX_PLAYERS];
new PlayerText:HeaderTD[2][MAX_PLAYERS];
new PlayerText:Street[2][MAX_PLAYERS];
new PlayerText:Subtitles[MAX_PLAYERS];
new PlayerText:speedo[9][MAX_PLAYERS];
new PlayerText:Phone[14][MAX_PLAYERS];
new PlayerText:MDC[14][MAX_PLAYERS];
new PlayerText:money[MAX_PLAYERS];

new PlayerText:Fades[MAX_PLAYERS];

new PlayerText:SelectFactionLocation[MAX_PLAYERS];
new PlayerText:SelectFactionName[MAX_PLAYERS];
new PlayerText:SelectFaction[2][MAX_PLAYERS];
new PlayerText:SelectFactionClick[3][MAX_PLAYERS];

new PlayerText:ALPR[18][MAX_PLAYERS];
new PlayerText:FoodOrder[10][MAX_PLAYERS];

new PlayerText:WeaponType[MAX_PLAYERS];
new PlayerText:WeaponAmmo[MAX_PLAYERS];
new PlayerText:barinfotd[4][MAX_PLAYERS];
new PlayerText:GameBar[3][MAX_PLAYERS];

new PlayerText:VehicleBox[MAX_PLAYERS];
new PlayerText:VehicleHeader[MAX_PLAYERS];
new PlayerText:VehicleClose[MAX_PLAYERS];
new PlayerText:VehicleModels[3][MAX_PLAYERS];
new PlayerText:VehicleClick[3][MAX_PLAYERS];
new PlayerText:VehiclePlate[3][MAX_PLAYERS];

new PlayerText:tutorialtext[MAX_PLAYERS];
new PlayerText:tutorialbox[MAX_PLAYERS];
new PlayerText:tutorialheader[MAX_PLAYERS];
new PlayerText:tutorialclick[MAX_PLAYERS];

new PlayerText:gui_spec_label[MAX_PLAYERS][5];

new PlayerBar:HeaderBar[MAX_PLAYERS];

//Textdraws

stock CreateTextdraws(playerid)
{
	servername[playerid] = CreatePlayerTextDraw(playerid, 320.000000, 440.000000, "GTA Storylines - ~y~Roleplay~w~ v1.12.1");
	PlayerTextDrawFont(playerid, servername[playerid], 1);
	PlayerTextDrawLetterSize(playerid, servername[playerid], 0.141661, 0.749996);
	PlayerTextDrawTextSize(playerid, servername[playerid], 502.500000, 306.500000);
	PlayerTextDrawSetOutline(playerid, servername[playerid], 1);
	PlayerTextDrawSetShadow(playerid, servername[playerid], 0);
	PlayerTextDrawAlignment(playerid, servername[playerid], 2);
	PlayerTextDrawColor(playerid, servername[playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, servername[playerid], 255);
	PlayerTextDrawBoxColor(playerid, servername[playerid], 50);
	PlayerTextDrawUseBox(playerid, servername[playerid], 0);
	PlayerTextDrawSetProportional(playerid, servername[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, servername[playerid], 0);

	loginscreen[0][playerid] = CreatePlayerTextDraw(playerid, 269.000000, 93.000000, "THE");
	PlayerTextDrawFont(playerid, loginscreen[0][playerid], 3);
	PlayerTextDrawLetterSize(playerid, loginscreen[0][playerid], 0.612500, 2.449999);
	PlayerTextDrawTextSize(playerid, loginscreen[0][playerid], 400.000000, 210.500000);
	PlayerTextDrawSetOutline(playerid, loginscreen[0][playerid], 1);
	PlayerTextDrawSetShadow(playerid, loginscreen[0][playerid], 0);
	PlayerTextDrawAlignment(playerid, loginscreen[0][playerid], 2);
	PlayerTextDrawColor(playerid, loginscreen[0][playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, loginscreen[0][playerid], 255);
	PlayerTextDrawBoxColor(playerid, loginscreen[0][playerid], 50);
	PlayerTextDrawUseBox(playerid, loginscreen[0][playerid], 0);
	PlayerTextDrawSetProportional(playerid, loginscreen[0][playerid], 1);
	PlayerTextDrawSetSelectable(playerid, loginscreen[0][playerid], 0);

	loginscreen[1][playerid] = CreatePlayerTextDraw(playerid, 333.000000, 112.000000, "Storylines");
	PlayerTextDrawFont(playerid, loginscreen[1][playerid], 0);
	PlayerTextDrawLetterSize(playerid, loginscreen[1][playerid], 0.766666, 2.849999);
	PlayerTextDrawTextSize(playerid, loginscreen[1][playerid], 400.000000, 210.500000);
	PlayerTextDrawSetOutline(playerid, loginscreen[1][playerid], 1);
	PlayerTextDrawSetShadow(playerid, loginscreen[1][playerid], 0);
	PlayerTextDrawAlignment(playerid, loginscreen[1][playerid], 2);
	PlayerTextDrawColor(playerid, loginscreen[1][playerid], 1981534719);
	PlayerTextDrawBackgroundColor(playerid, loginscreen[1][playerid], 255);
	PlayerTextDrawBoxColor(playerid, loginscreen[1][playerid], 50);
	PlayerTextDrawUseBox(playerid, loginscreen[1][playerid], 0);
	PlayerTextDrawSetProportional(playerid, loginscreen[1][playerid], 1);
	PlayerTextDrawSetSelectable(playerid, loginscreen[1][playerid], 0);

	loginscreen[2][playerid] = CreatePlayerTextDraw(playerid, 353.000000, 94.000000, "~p~Fear ~w~n ~p~Respect v.1");
	PlayerTextDrawFont(playerid, loginscreen[2][playerid], 0);
	PlayerTextDrawLetterSize(playerid, loginscreen[2][playerid], 0.516666, 1.850000);
	PlayerTextDrawTextSize(playerid, loginscreen[2][playerid], 400.000000, 210.500000);
	PlayerTextDrawSetOutline(playerid, loginscreen[2][playerid], 1);
	PlayerTextDrawSetShadow(playerid, loginscreen[2][playerid], 0);
	PlayerTextDrawAlignment(playerid, loginscreen[2][playerid], 2);
	PlayerTextDrawColor(playerid, loginscreen[2][playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, loginscreen[2][playerid], 255);
	PlayerTextDrawBoxColor(playerid, loginscreen[2][playerid], 50);
	PlayerTextDrawUseBox(playerid, loginscreen[2][playerid], 0);
	PlayerTextDrawSetProportional(playerid, loginscreen[2][playerid], 1);
	PlayerTextDrawSetSelectable(playerid, loginscreen[2][playerid], 0);

	Fades[playerid] = CreatePlayerTextDraw(playerid, -20.000000, 0.000000, "_");
	PlayerTextDrawUseBox(playerid, Fades[playerid], 1);
	PlayerTextDrawBoxColor(playerid, Fades[playerid], 0x000000FF);
	PlayerTextDrawAlignment(playerid, Fades[playerid], 0);
	PlayerTextDrawBackgroundColor(playerid, Fades[playerid], 0x000000FF);
	PlayerTextDrawFont(playerid, Fades[playerid], 3);
	PlayerTextDrawLetterSize(playerid, Fades[playerid], 1.000000, 52.200000);
	PlayerTextDrawColor(playerid, Fades[playerid], 0x000000FF);
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

CreateNotificationTextDraws(playerid)
{
	Subtitles[playerid] = CreatePlayerTextDraw(playerid, 321.000000, 376.000000, "~b~Ganton Binco~n~~y~This business is for sell~n~~w~Press 'ENTER' to enter business");
	PlayerTextDrawFont(playerid, Subtitles[playerid], 1);
	PlayerTextDrawLetterSize(playerid, Subtitles[playerid], 0.191659, 0.999993);
	PlayerTextDrawTextSize(playerid, Subtitles[playerid], 502.500000, 306.500000);
	PlayerTextDrawSetOutline(playerid, Subtitles[playerid], 1);
	PlayerTextDrawSetShadow(playerid, Subtitles[playerid], 0);
	PlayerTextDrawAlignment(playerid, Subtitles[playerid], 2);
	PlayerTextDrawColor(playerid, Subtitles[playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, Subtitles[playerid], 255);
	PlayerTextDrawBoxColor(playerid, Subtitles[playerid], 50);
	PlayerTextDrawUseBox(playerid, Subtitles[playerid], 0);
	PlayerTextDrawSetProportional(playerid, Subtitles[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, Subtitles[playerid], 0);

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
}

CreateHUDTextDraws(playerid)
{
	Street[0][playerid] = CreatePlayerTextDraw(playerid, 156.000000, 354.000000, "South North~n~~y~SW");
	PlayerTextDrawFont(playerid, Street[0][playerid], 1);
	PlayerTextDrawLetterSize(playerid, Street[0][playerid], 0.191658, 1.199998);
	PlayerTextDrawTextSize(playerid, Street[0][playerid], 400.000000, 93.500000);
	PlayerTextDrawSetOutline(playerid, Street[0][playerid], 1);
	PlayerTextDrawSetShadow(playerid, Street[0][playerid], 0);
	PlayerTextDrawAlignment(playerid, Street[0][playerid], 2);
	PlayerTextDrawColor(playerid, Street[0][playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, Street[0][playerid], 255);
	PlayerTextDrawBoxColor(playerid, Street[0][playerid], 50);
	PlayerTextDrawUseBox(playerid, Street[0][playerid], 0);
	PlayerTextDrawSetProportional(playerid, Street[0][playerid], 1);
	PlayerTextDrawSetSelectable(playerid, Street[0][playerid], 0);

	Street[1][playerid] = CreatePlayerTextDraw(playerid, 156.000000, 378.000000, "Westmont Avenue~n~El Corona~n~Los Santos");
	PlayerTextDrawFont(playerid, Street[1][playerid], 1);
	PlayerTextDrawLetterSize(playerid, Street[1][playerid], 0.191657, 0.899995);
	PlayerTextDrawTextSize(playerid, Street[1][playerid], 400.000000, 93.500000);
	PlayerTextDrawSetOutline(playerid, Street[1][playerid], 1);
	PlayerTextDrawSetShadow(playerid, Street[1][playerid], 0);
	PlayerTextDrawAlignment(playerid, Street[1][playerid], 2);
	PlayerTextDrawColor(playerid, Street[1][playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, Street[1][playerid], 255);
	PlayerTextDrawBoxColor(playerid, Street[1][playerid], 50);
	PlayerTextDrawUseBox(playerid, Street[1][playerid], 0);
	PlayerTextDrawSetProportional(playerid, Street[1][playerid], 1);
	PlayerTextDrawSetSelectable(playerid, Street[1][playerid], 0);

	WeaponType[playerid] = CreatePlayerTextDraw(playerid, 522.000000, 71.000000, "Socimi_Type_821");
	PlayerTextDrawFont(playerid, WeaponType[playerid], 3);
	PlayerTextDrawLetterSize(playerid, WeaponType[playerid], 0.179161, 0.949998);
	PlayerTextDrawTextSize(playerid, WeaponType[playerid], 604.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, WeaponType[playerid], 1);
	PlayerTextDrawSetShadow(playerid, WeaponType[playerid], 0);
	PlayerTextDrawAlignment(playerid, WeaponType[playerid], 2);
	PlayerTextDrawColor(playerid, WeaponType[playerid], -1379670017);
	PlayerTextDrawBackgroundColor(playerid, WeaponType[playerid], 255);
	PlayerTextDrawBoxColor(playerid, WeaponType[playerid], 100);
	PlayerTextDrawUseBox(playerid, WeaponType[playerid], 0);
	PlayerTextDrawSetProportional(playerid, WeaponType[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, WeaponType[playerid], 0);

	WeaponAmmo[playerid] = CreatePlayerTextDraw(playerid, 521.000000, 62.000000, "100-9mm");
	PlayerTextDrawFont(playerid, WeaponAmmo[playerid], 3);
	PlayerTextDrawLetterSize(playerid, WeaponAmmo[playerid], 0.229161, 0.999998);
	PlayerTextDrawTextSize(playerid, WeaponAmmo[playerid], 604.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, WeaponAmmo[playerid], 1);
	PlayerTextDrawSetShadow(playerid, WeaponAmmo[playerid], 0);
	PlayerTextDrawAlignment(playerid, WeaponAmmo[playerid], 2);
	PlayerTextDrawColor(playerid, WeaponAmmo[playerid], -1379670017);
	PlayerTextDrawBackgroundColor(playerid, WeaponAmmo[playerid], 255);
	PlayerTextDrawBoxColor(playerid, WeaponAmmo[playerid], 100);
	PlayerTextDrawUseBox(playerid, WeaponAmmo[playerid], 0);
	PlayerTextDrawSetProportional(playerid, WeaponAmmo[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, WeaponAmmo[playerid], 0);
}

CreateBarInfoTextDraws(playerid)
{
	HeaderTD[0][playerid] = CreatePlayerTextDraw(playerid, 489.000000, 147.000000, "You have started the extorting in Pawnstore Plaza.~n~~n~Hit the store clerk to break them. When the extortion bar is full use /e");
	PlayerTextDrawFont(playerid, HeaderTD[0][playerid], 1);
	PlayerTextDrawLetterSize(playerid, HeaderTD[0][playerid], 0.208332, 0.949998);
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

	HeaderTD[1][playerid] = CreatePlayerTextDraw(playerid, 488.000000, 136.000000, "Extortion");
	PlayerTextDrawFont(playerid, HeaderTD[1][playerid], 0);
	PlayerTextDrawLetterSize(playerid, HeaderTD[1][playerid], 0.366665, 1.299998);
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

	GameBar[2][playerid] = CreatePlayerTextDraw(playerid, 554.000000, 117.000000, "_");
	PlayerTextDrawFont(playerid, GameBar[2][playerid], 1);
	PlayerTextDrawLetterSize(playerid, GameBar[2][playerid], 0.600000, 1.399999);
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

	GameBar[0][playerid] = CreatePlayerTextDraw(playerid, 524.000000, 101.000000, "Extortion");
	PlayerTextDrawFont(playerid, GameBar[0][playerid], 0);
	PlayerTextDrawLetterSize(playerid, GameBar[0][playerid], 0.408331, 1.599998);
	PlayerTextDrawTextSize(playerid, GameBar[0][playerid], 605.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, GameBar[0][playerid], 1);
	PlayerTextDrawSetShadow(playerid, GameBar[0][playerid], 0);
	PlayerTextDrawAlignment(playerid, GameBar[0][playerid], 2);
	PlayerTextDrawColor(playerid, GameBar[0][playerid], -1379670017);
	PlayerTextDrawBackgroundColor(playerid, GameBar[0][playerid], 255);
	PlayerTextDrawBoxColor(playerid, GameBar[0][playerid], 200);
	PlayerTextDrawUseBox(playerid, GameBar[0][playerid], 0);
	PlayerTextDrawSetProportional(playerid, GameBar[0][playerid], 1);
	PlayerTextDrawSetSelectable(playerid, GameBar[0][playerid], 0);

	barinfotd[0][playerid] = CreatePlayerTextDraw(playerid, 59.000000, 175.000000, "_");
	PlayerTextDrawFont(playerid, barinfotd[0][playerid], 1);
	PlayerTextDrawLetterSize(playerid, barinfotd[0][playerid], 0.558332, 1.250002);
	PlayerTextDrawTextSize(playerid, barinfotd[0][playerid], 295.000000, 100.000000);
	PlayerTextDrawSetOutline(playerid, barinfotd[0][playerid], 0);
	PlayerTextDrawSetShadow(playerid, barinfotd[0][playerid], 0);
	PlayerTextDrawAlignment(playerid, barinfotd[0][playerid], 2);
	PlayerTextDrawColor(playerid, barinfotd[0][playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, barinfotd[0][playerid], 255);
	PlayerTextDrawBoxColor(playerid, barinfotd[0][playerid], 255);
	PlayerTextDrawUseBox(playerid, barinfotd[0][playerid], 1);
	PlayerTextDrawSetProportional(playerid, barinfotd[0][playerid], 1);
	PlayerTextDrawSetSelectable(playerid, barinfotd[0][playerid], 0);

	barinfotd[1][playerid] = CreatePlayerTextDraw(playerid, 9.000000, 171.000000, "Respect");
	PlayerTextDrawFont(playerid, barinfotd[1][playerid], 1);
	PlayerTextDrawLetterSize(playerid, barinfotd[1][playerid], 0.295825, 1.749992);
	PlayerTextDrawTextSize(playerid, barinfotd[1][playerid], 158.500000, 26.000000);
	PlayerTextDrawSetOutline(playerid, barinfotd[1][playerid], 0);
	PlayerTextDrawSetShadow(playerid, barinfotd[1][playerid], 0);
	PlayerTextDrawAlignment(playerid, barinfotd[1][playerid], 1);
	PlayerTextDrawColor(playerid, barinfotd[1][playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, barinfotd[1][playerid], 255);
	PlayerTextDrawBoxColor(playerid, barinfotd[1][playerid], 185);
	PlayerTextDrawUseBox(playerid, barinfotd[1][playerid], 0);
	PlayerTextDrawSetProportional(playerid, barinfotd[1][playerid], 1);
	PlayerTextDrawSetSelectable(playerid, barinfotd[1][playerid], 0);

	barinfotd[2][playerid] = CreatePlayerTextDraw(playerid, 104.000000, 172.000000, "+");
	PlayerTextDrawFont(playerid, barinfotd[2][playerid], 1);
	PlayerTextDrawLetterSize(playerid, barinfotd[2][playerid], 0.424991, 1.649991);
	PlayerTextDrawTextSize(playerid, barinfotd[2][playerid], 154.000000, 24.500000);
	PlayerTextDrawSetOutline(playerid, barinfotd[2][playerid], 0);
	PlayerTextDrawSetShadow(playerid, barinfotd[2][playerid], 0);
	PlayerTextDrawAlignment(playerid, barinfotd[2][playerid], 2);
	PlayerTextDrawColor(playerid, barinfotd[2][playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, barinfotd[2][playerid], 255);
	PlayerTextDrawBoxColor(playerid, barinfotd[2][playerid], 185);
	PlayerTextDrawUseBox(playerid, barinfotd[2][playerid], 0);
	PlayerTextDrawSetProportional(playerid, barinfotd[2][playerid], 1);
	PlayerTextDrawSetSelectable(playerid, barinfotd[2][playerid], 0);

	barinfotd[3][playerid] = CreatePlayerTextDraw(playerid, 50.000000, 176.000000, "mdl-2001:15");
	PlayerTextDrawFont(playerid, barinfotd[3][playerid], 4);
	PlayerTextDrawLetterSize(playerid, barinfotd[3][playerid], 0.600000, 2.000000);
	PlayerTextDrawTextSize(playerid, barinfotd[3][playerid], 47.000000, 9.000000);
	PlayerTextDrawSetOutline(playerid, barinfotd[3][playerid], 1);
	PlayerTextDrawSetShadow(playerid, barinfotd[3][playerid], 0);
	PlayerTextDrawAlignment(playerid, barinfotd[3][playerid], 1);
	PlayerTextDrawColor(playerid, barinfotd[3][playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, barinfotd[3][playerid], 255);
	PlayerTextDrawBoxColor(playerid, barinfotd[3][playerid], 50);
	PlayerTextDrawUseBox(playerid, barinfotd[3][playerid], 1);
	PlayerTextDrawSetProportional(playerid, barinfotd[3][playerid], 1);
	PlayerTextDrawSetSelectable(playerid, barinfotd[3][playerid], 0);

	HeaderBar[playerid] = CreatePlayerProgressBar(playerid, 502.000000, 119.000000, 108.500000, 9.000000, -1, 100.000000, 0);
	SetPlayerProgressBarValue(playerid, HeaderBar[playerid], 0.0);
}

CreateVehicleTextDraws(playerid)
{
	VehicleName[playerid] = CreatePlayerTextDraw(playerid,  156.000000, 405.000000, "~g~BMX");
	PlayerTextDrawFont(playerid, VehicleName[playerid], 2);
	PlayerTextDrawLetterSize(playerid, VehicleName[playerid], 0.237496, 0.949994);
	PlayerTextDrawTextSize(playerid, VehicleName[playerid], 400.000000, 133.000000);
	PlayerTextDrawSetOutline(playerid, VehicleName[playerid], 1);
	PlayerTextDrawSetShadow(playerid, VehicleName[playerid], 0);
	PlayerTextDrawAlignment(playerid, VehicleName[playerid], 1);
	PlayerTextDrawColor(playerid, VehicleName[playerid], 9109759);
	PlayerTextDrawBackgroundColor(playerid, VehicleName[playerid], 255);
	PlayerTextDrawBoxColor(playerid, VehicleName[playerid], 50);
	PlayerTextDrawUseBox(playerid, VehicleName[playerid], 0);
	PlayerTextDrawSetProportional(playerid, VehicleName[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, VehicleName[playerid], 0);

	speedo[6][playerid] = CreatePlayerTextDraw(playerid, 526.000000, 186.000000, "-~n~-~n~-~n~-~n~-~n~-~n~-~n~");
	PlayerTextDrawFont(playerid, speedo[6][playerid], 1);
	PlayerTextDrawLetterSize(playerid, speedo[6][playerid], 0.770823, 0.500000);
	PlayerTextDrawTextSize(playerid, speedo[6][playerid], 400.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, speedo[6][playerid], 1);
	PlayerTextDrawSetShadow(playerid, speedo[6][playerid], 0);
	PlayerTextDrawAlignment(playerid, speedo[6][playerid], 1);
	PlayerTextDrawColor(playerid, speedo[6][playerid], 2094792959);
	PlayerTextDrawBackgroundColor(playerid, speedo[6][playerid], 255);
	PlayerTextDrawBoxColor(playerid, speedo[6][playerid], 50);
	PlayerTextDrawUseBox(playerid, speedo[6][playerid], 0);
	PlayerTextDrawSetProportional(playerid, speedo[6][playerid], 1);
	PlayerTextDrawSetSelectable(playerid, speedo[6][playerid], 0);

	speedo[1][playerid] = CreatePlayerTextDraw(playerid, 539.000000, 168.000000, "I");
	PlayerTextDrawFont(playerid, speedo[1][playerid], 2);
	PlayerTextDrawLetterSize(playerid, speedo[1][playerid], 0.358323, 6.600001);
	PlayerTextDrawTextSize(playerid, speedo[1][playerid], 400.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, speedo[1][playerid], 1);
	PlayerTextDrawSetShadow(playerid, speedo[1][playerid], 0);
	PlayerTextDrawAlignment(playerid, speedo[1][playerid], 1);
	PlayerTextDrawColor(playerid, speedo[1][playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, speedo[1][playerid], 255);
	PlayerTextDrawBoxColor(playerid, speedo[1][playerid], 50);
	PlayerTextDrawUseBox(playerid, speedo[1][playerid], 0);
	PlayerTextDrawSetProportional(playerid, speedo[1][playerid], 1);
	PlayerTextDrawSetSelectable(playerid, speedo[1][playerid], 0);

	speedo[5][playerid] = CreatePlayerTextDraw(playerid, 587.000000, 172.000000, "80");
	PlayerTextDrawFont(playerid, speedo[5][playerid], 2);
	PlayerTextDrawLetterSize(playerid, speedo[5][playerid], 0.579162, 5.650000);
	PlayerTextDrawTextSize(playerid, speedo[5][playerid], 400.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, speedo[5][playerid], 1);
	PlayerTextDrawSetShadow(playerid, speedo[5][playerid], 0);
	PlayerTextDrawAlignment(playerid, speedo[5][playerid], 3);
	PlayerTextDrawColor(playerid, speedo[5][playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, speedo[5][playerid], 255);
	PlayerTextDrawBoxColor(playerid, speedo[5][playerid], 50);
	PlayerTextDrawUseBox(playerid, speedo[5][playerid], 0);
	PlayerTextDrawSetProportional(playerid, speedo[5][playerid], 1);
	PlayerTextDrawSetSelectable(playerid, speedo[5][playerid], 0);

	speedo[0][playerid] = CreatePlayerTextDraw(playerid, 609.000000, 202.000000, "MPH");
	PlayerTextDrawFont(playerid, speedo[0][playerid], 2);
	PlayerTextDrawLetterSize(playerid, speedo[0][playerid], 0.245829, 1.550009);
	PlayerTextDrawTextSize(playerid, speedo[0][playerid], 400.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, speedo[0][playerid], 1);
	PlayerTextDrawSetShadow(playerid, speedo[0][playerid], 0);
	PlayerTextDrawAlignment(playerid, speedo[0][playerid], 3);
	PlayerTextDrawColor(playerid, speedo[0][playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, speedo[0][playerid], 255);
	PlayerTextDrawBoxColor(playerid, speedo[0][playerid], 50);
	PlayerTextDrawUseBox(playerid, speedo[0][playerid], 0);
	PlayerTextDrawSetProportional(playerid, speedo[0][playerid], 1);
	PlayerTextDrawSetSelectable(playerid, speedo[0][playerid], 0);

	speedo[4][playerid] = CreatePlayerTextDraw(playerid, 524.000000, 194.000000, "0");
	PlayerTextDrawFont(playerid, speedo[4][playerid], 2);
	PlayerTextDrawLetterSize(playerid, speedo[4][playerid], 0.295829, 2.450004);
	PlayerTextDrawTextSize(playerid, speedo[4][playerid], 400.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, speedo[4][playerid], 0);
	PlayerTextDrawSetShadow(playerid, speedo[4][playerid], 0);
	PlayerTextDrawAlignment(playerid, speedo[4][playerid], 3);
	PlayerTextDrawColor(playerid, speedo[4][playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, speedo[4][playerid], 255);
	PlayerTextDrawBoxColor(playerid, speedo[4][playerid], 50);
	PlayerTextDrawUseBox(playerid, speedo[4][playerid], 0);
	PlayerTextDrawSetProportional(playerid, speedo[4][playerid], 1);
	PlayerTextDrawSetSelectable(playerid, speedo[4][playerid], 0);

	speedo[2][playerid] = CreatePlayerTextDraw(playerid, 516.000000, 205.000000, "ld_dual:white");
	PlayerTextDrawFont(playerid, speedo[2][playerid], 4);
	PlayerTextDrawLetterSize(playerid, speedo[2][playerid], 0.379162, 2.450004);
	PlayerTextDrawTextSize(playerid, speedo[2][playerid], 7.000000, 11.500000);
	PlayerTextDrawSetOutline(playerid, speedo[2][playerid], 0);
	PlayerTextDrawSetShadow(playerid, speedo[2][playerid], 0);
	PlayerTextDrawAlignment(playerid, speedo[2][playerid], 3);
	PlayerTextDrawColor(playerid, speedo[2][playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, speedo[2][playerid], 255);
	PlayerTextDrawBoxColor(playerid, speedo[2][playerid], 50);
	PlayerTextDrawUseBox(playerid, speedo[2][playerid], 0);
	PlayerTextDrawSetProportional(playerid, speedo[2][playerid], 1);
	PlayerTextDrawSetSelectable(playerid, speedo[2][playerid], 0);

	speedo[3][playerid] = CreatePlayerTextDraw(playerid, 515.000000, 215.000000, "ld_dual:white");
	PlayerTextDrawFont(playerid, speedo[3][playerid], 4);
	PlayerTextDrawLetterSize(playerid, speedo[3][playerid], 0.379162, 2.450004);
	PlayerTextDrawTextSize(playerid, speedo[3][playerid], 9.000000, 2.000000);
	PlayerTextDrawSetOutline(playerid, speedo[3][playerid], 0);
	PlayerTextDrawSetShadow(playerid, speedo[3][playerid], 0);
	PlayerTextDrawAlignment(playerid, speedo[3][playerid], 3);
	PlayerTextDrawColor(playerid, speedo[3][playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, speedo[3][playerid], 255);
	PlayerTextDrawBoxColor(playerid, speedo[3][playerid], 50);
	PlayerTextDrawUseBox(playerid, speedo[3][playerid], 0);
	PlayerTextDrawSetProportional(playerid, speedo[3][playerid], 1);
	PlayerTextDrawSetSelectable(playerid, speedo[3][playerid], 0);

	speedo[7][playerid] = CreatePlayerTextDraw(playerid, 611.000000, 181.000000, "D");
	PlayerTextDrawFont(playerid, speedo[7][playerid], 2);
	PlayerTextDrawLetterSize(playerid, speedo[7][playerid], 0.308328, 2.050008);
	PlayerTextDrawTextSize(playerid, speedo[7][playerid], 400.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, speedo[7][playerid], 0);
	PlayerTextDrawSetShadow(playerid, speedo[7][playerid], 0);
	PlayerTextDrawAlignment(playerid, speedo[7][playerid], 3);
	PlayerTextDrawColor(playerid, speedo[7][playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, speedo[7][playerid], 255);
	PlayerTextDrawBoxColor(playerid, speedo[7][playerid], 50);
	PlayerTextDrawUseBox(playerid, speedo[7][playerid], 0);
	PlayerTextDrawSetProportional(playerid, speedo[7][playerid], 1);
	PlayerTextDrawSetSelectable(playerid, speedo[7][playerid], 0);

	speedo[8][playerid] = CreatePlayerTextDraw(playerid, 594.000000, 186.000000, "/~n~/~n~/");
	PlayerTextDrawFont(playerid, speedo[8][playerid], 2);
	PlayerTextDrawLetterSize(playerid, speedo[8][playerid], 0.583328, 0.500009);
	PlayerTextDrawTextSize(playerid, speedo[8][playerid], 400.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, speedo[8][playerid], 0);
	PlayerTextDrawSetShadow(playerid, speedo[8][playerid], 0);
	PlayerTextDrawAlignment(playerid, speedo[8][playerid], 1);
	PlayerTextDrawColor(playerid, speedo[8][playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, speedo[8][playerid], 255);
	PlayerTextDrawBoxColor(playerid, speedo[8][playerid], 50);
	PlayerTextDrawUseBox(playerid, speedo[8][playerid], 0);
	PlayerTextDrawSetProportional(playerid, speedo[8][playerid], 1);
	PlayerTextDrawSetSelectable(playerid, speedo[8][playerid], 0);

	VehicleBox[playerid] = CreatePlayerTextDraw(playerid, 321.000000, 190.000000, "_");
	PlayerTextDrawFont(playerid, VehicleBox[playerid], 1);
	PlayerTextDrawLetterSize(playerid, VehicleBox[playerid], 0.645833, 10.499998);
	PlayerTextDrawTextSize(playerid, VehicleBox[playerid], 298.500000, 215.500000);
	PlayerTextDrawSetOutline(playerid, VehicleBox[playerid], 1);
	PlayerTextDrawSetShadow(playerid, VehicleBox[playerid], 0);
	PlayerTextDrawAlignment(playerid, VehicleBox[playerid], 2);
	PlayerTextDrawColor(playerid, VehicleBox[playerid], 16777215);
	PlayerTextDrawBackgroundColor(playerid, VehicleBox[playerid], 255);
	PlayerTextDrawBoxColor(playerid, VehicleBox[playerid], -2016478585);
	PlayerTextDrawUseBox(playerid, VehicleBox[playerid], 1);
	PlayerTextDrawSetProportional(playerid, VehicleBox[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, VehicleBox[playerid], 0);

	VehicleHeader[playerid] = CreatePlayerTextDraw(playerid, 213.000000, 176.000000, "Your Vehicle");
	PlayerTextDrawFont(playerid, VehicleHeader[playerid], 2);
	PlayerTextDrawLetterSize(playerid, VehicleHeader[playerid], 0.245831, 1.200000);
	PlayerTextDrawTextSize(playerid, VehicleHeader[playerid], 429.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, VehicleHeader[playerid], 1);
	PlayerTextDrawSetShadow(playerid, VehicleHeader[playerid], 0);
	PlayerTextDrawAlignment(playerid, VehicleHeader[playerid], 1);
	PlayerTextDrawColor(playerid, VehicleHeader[playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, VehicleHeader[playerid], 255);
	PlayerTextDrawBoxColor(playerid, VehicleHeader[playerid], -764862841);
	PlayerTextDrawUseBox(playerid, VehicleHeader[playerid], 1);
	PlayerTextDrawSetProportional(playerid, VehicleHeader[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, VehicleHeader[playerid], 0);

	VehicleModels[0][playerid] = CreatePlayerTextDraw(playerid, 217.000000, 196.000000, "Preview_Model");
	PlayerTextDrawFont(playerid, VehicleModels[0][playerid], 5);
	PlayerTextDrawLetterSize(playerid, VehicleModels[0][playerid], 0.600000, 2.000000);
	PlayerTextDrawTextSize(playerid, VehicleModels[0][playerid], 58.000000, 61.000000);
	PlayerTextDrawSetOutline(playerid, VehicleModels[0][playerid], 0);
	PlayerTextDrawSetShadow(playerid, VehicleModels[0][playerid], 0);
	PlayerTextDrawAlignment(playerid, VehicleModels[0][playerid], 1);
	PlayerTextDrawColor(playerid, VehicleModels[0][playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, VehicleModels[0][playerid], -764862851);
	PlayerTextDrawBoxColor(playerid, VehicleModels[0][playerid], -764862721);
	PlayerTextDrawUseBox(playerid, VehicleModels[0][playerid], 0);
	PlayerTextDrawSetProportional(playerid, VehicleModels[0][playerid], 1);
	PlayerTextDrawSetSelectable(playerid, VehicleModels[0][playerid], 0);
	PlayerTextDrawSetPreviewModel(playerid, VehicleModels[0][playerid], 422);
	PlayerTextDrawSetPreviewRot(playerid, VehicleModels[0][playerid], -10.000000, 0.000000, -24.000000, 0.759998);
	PlayerTextDrawSetPreviewVehCol(playerid, VehicleModels[0][playerid], 1, 1);

	VehicleModels[1][playerid] = CreatePlayerTextDraw(playerid, 292.000000, 196.000000, "Preview_Model");
	PlayerTextDrawFont(playerid, VehicleModels[1][playerid], 5);
	PlayerTextDrawLetterSize(playerid, VehicleModels[1][playerid], 0.600000, 2.000000);
	PlayerTextDrawTextSize(playerid, VehicleModels[1][playerid], 58.000000, 61.000000);
	PlayerTextDrawSetOutline(playerid, VehicleModels[1][playerid], 0);
	PlayerTextDrawSetShadow(playerid, VehicleModels[1][playerid], 0);
	PlayerTextDrawAlignment(playerid, VehicleModels[1][playerid], 1);
	PlayerTextDrawColor(playerid, VehicleModels[1][playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, VehicleModels[1][playerid], -764862851);
	PlayerTextDrawBoxColor(playerid, VehicleModels[1][playerid], -764862721);
	PlayerTextDrawUseBox(playerid, VehicleModels[1][playerid], 0);
	PlayerTextDrawSetProportional(playerid, VehicleModels[1][playerid], 1);
	PlayerTextDrawSetSelectable(playerid, VehicleModels[1][playerid], 0);
	PlayerTextDrawSetPreviewModel(playerid, VehicleModels[1][playerid], 422);
	PlayerTextDrawSetPreviewRot(playerid, VehicleModels[1][playerid], -10.000000, 0.000000, -24.000000, 0.759998);
	PlayerTextDrawSetPreviewVehCol(playerid, VehicleModels[1][playerid], 1, 1);

	VehicleModels[2][playerid] = CreatePlayerTextDraw(playerid, 368.000000, 196.000000, "Preview_Model");
	PlayerTextDrawFont(playerid, VehicleModels[2][playerid], 5);
	PlayerTextDrawLetterSize(playerid, VehicleModels[2][playerid], 0.600000, 2.000000);
	PlayerTextDrawTextSize(playerid, VehicleModels[2][playerid], 58.000000, 61.000000);
	PlayerTextDrawSetOutline(playerid, VehicleModels[2][playerid], 0);
	PlayerTextDrawSetShadow(playerid, VehicleModels[2][playerid], 0);
	PlayerTextDrawAlignment(playerid, VehicleModels[2][playerid], 1);
	PlayerTextDrawColor(playerid, VehicleModels[2][playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, VehicleModels[2][playerid], -764862851);
	PlayerTextDrawBoxColor(playerid, VehicleModels[2][playerid], -764862721);
	PlayerTextDrawUseBox(playerid, VehicleModels[2][playerid], 0);
	PlayerTextDrawSetProportional(playerid, VehicleModels[2][playerid], 1);
	PlayerTextDrawSetSelectable(playerid, VehicleModels[2][playerid], 0);
	PlayerTextDrawSetPreviewModel(playerid, VehicleModels[2][playerid], 422);
	PlayerTextDrawSetPreviewRot(playerid, VehicleModels[2][playerid], -10.000000, 0.000000, -24.000000, 0.759998);
	PlayerTextDrawSetPreviewVehCol(playerid, VehicleModels[2][playerid], 1, 1);

	VehicleClick[0][playerid] = CreatePlayerTextDraw(playerid, 245.000000, 269.000000, "Spawned");
	PlayerTextDrawFont(playerid, VehicleClick[0][playerid], 3);
	PlayerTextDrawLetterSize(playerid, VehicleClick[0][playerid], 0.220832, 1.000000);
	PlayerTextDrawTextSize(playerid, VehicleClick[0][playerid], 264.500000, 43.500000);
	PlayerTextDrawSetOutline(playerid, VehicleClick[0][playerid], 1);
	PlayerTextDrawSetShadow(playerid, VehicleClick[0][playerid], 0);
	PlayerTextDrawAlignment(playerid, VehicleClick[0][playerid], 2);
	PlayerTextDrawColor(playerid, VehicleClick[0][playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, VehicleClick[0][playerid], 255);
	PlayerTextDrawBoxColor(playerid, VehicleClick[0][playerid], -764862841);
	PlayerTextDrawUseBox(playerid, VehicleClick[0][playerid], 1);
	PlayerTextDrawSetProportional(playerid, VehicleClick[0][playerid], 1);
	PlayerTextDrawSetSelectable(playerid, VehicleClick[0][playerid], 1);

	VehicleClick[1][playerid] = CreatePlayerTextDraw(playerid, 321.000000, 269.000000, "Spawned");
	PlayerTextDrawFont(playerid, VehicleClick[1][playerid], 3);
	PlayerTextDrawLetterSize(playerid, VehicleClick[1][playerid], 0.220832, 1.100000);
	PlayerTextDrawTextSize(playerid, VehicleClick[1][playerid], 264.500000, 43.500000);
	PlayerTextDrawSetOutline(playerid, VehicleClick[1][playerid], 1);
	PlayerTextDrawSetShadow(playerid, VehicleClick[1][playerid], 0);
	PlayerTextDrawAlignment(playerid, VehicleClick[1][playerid], 2);
	PlayerTextDrawColor(playerid, VehicleClick[1][playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, VehicleClick[1][playerid], 255);
	PlayerTextDrawBoxColor(playerid, VehicleClick[1][playerid], -764862841);
	PlayerTextDrawUseBox(playerid, VehicleClick[1][playerid], 1);
	PlayerTextDrawSetProportional(playerid, VehicleClick[1][playerid], 1);
	PlayerTextDrawSetSelectable(playerid, VehicleClick[1][playerid], 1);

	VehicleClick[2][playerid] = CreatePlayerTextDraw(playerid, 398.000000, 269.000000, "Spawned");
	PlayerTextDrawFont(playerid, VehicleClick[2][playerid], 3);
	PlayerTextDrawLetterSize(playerid, VehicleClick[2][playerid], 0.220832, 1.100000);
	PlayerTextDrawTextSize(playerid, VehicleClick[2][playerid], 264.500000, 43.500000);
	PlayerTextDrawSetOutline(playerid, VehicleClick[2][playerid], 1);
	PlayerTextDrawSetShadow(playerid, VehicleClick[2][playerid], 0);
	PlayerTextDrawAlignment(playerid, VehicleClick[2][playerid], 2);
	PlayerTextDrawColor(playerid, VehicleClick[2][playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, VehicleClick[2][playerid], 255);
	PlayerTextDrawBoxColor(playerid, VehicleClick[2][playerid], -764862841);
	PlayerTextDrawUseBox(playerid, VehicleClick[2][playerid], 1);
	PlayerTextDrawSetProportional(playerid, VehicleClick[2][playerid], 1);
	PlayerTextDrawSetSelectable(playerid, VehicleClick[2][playerid], 1);

	VehicleClose[playerid] = CreatePlayerTextDraw(playerid, 422.000000, 176.000000, "X");
	PlayerTextDrawFont(playerid, VehicleClose[playerid], 2);
	PlayerTextDrawLetterSize(playerid, VehicleClose[playerid], 0.245830, 1.200000);
	PlayerTextDrawTextSize(playerid, VehicleClose[playerid], 429.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, VehicleClose[playerid], 1);
	PlayerTextDrawSetShadow(playerid, VehicleClose[playerid], 0);
	PlayerTextDrawAlignment(playerid, VehicleClose[playerid], 1);
	PlayerTextDrawColor(playerid, VehicleClose[playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, VehicleClose[playerid], 255);
	PlayerTextDrawBoxColor(playerid, VehicleClose[playerid], 1687547391);
	PlayerTextDrawUseBox(playerid, VehicleClose[playerid], 1);
	PlayerTextDrawSetProportional(playerid, VehicleClose[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, VehicleClose[playerid], 1);

	VehiclePlate[0][playerid] = CreatePlayerTextDraw(playerid, 246.000000, 248.000000, "Plate: 3IBI36");
	PlayerTextDrawFont(playerid, VehiclePlate[0][playerid], 2);
	PlayerTextDrawLetterSize(playerid, VehiclePlate[0][playerid], 0.162500, 0.950000);
	PlayerTextDrawTextSize(playerid, VehiclePlate[0][playerid], 400.000000, 56.000000);
	PlayerTextDrawSetOutline(playerid, VehiclePlate[0][playerid], 0);
	PlayerTextDrawSetShadow(playerid, VehiclePlate[0][playerid], 0);
	PlayerTextDrawAlignment(playerid, VehiclePlate[0][playerid], 2);
	PlayerTextDrawColor(playerid, VehiclePlate[0][playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, VehiclePlate[0][playerid], 255);
	PlayerTextDrawBoxColor(playerid, VehiclePlate[0][playerid], 50);
	PlayerTextDrawUseBox(playerid, VehiclePlate[0][playerid], 0);
	PlayerTextDrawSetProportional(playerid, VehiclePlate[0][playerid], 1);
	PlayerTextDrawSetSelectable(playerid, VehiclePlate[0][playerid], 0);

	VehiclePlate[1][playerid] = CreatePlayerTextDraw(playerid, 321.000000, 248.000000, "Plate: 3IBI36");
	PlayerTextDrawFont(playerid, VehiclePlate[1][playerid], 2);
	PlayerTextDrawLetterSize(playerid, VehiclePlate[1][playerid], 0.162500, 0.950000);
	PlayerTextDrawTextSize(playerid, VehiclePlate[1][playerid], 400.000000, 56.000000);
	PlayerTextDrawSetOutline(playerid, VehiclePlate[1][playerid], 0);
	PlayerTextDrawSetShadow(playerid, VehiclePlate[1][playerid], 0);
	PlayerTextDrawAlignment(playerid, VehiclePlate[1][playerid], 2);
	PlayerTextDrawColor(playerid, VehiclePlate[1][playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, VehiclePlate[1][playerid], 255);
	PlayerTextDrawBoxColor(playerid, VehiclePlate[1][playerid], 50);
	PlayerTextDrawUseBox(playerid, VehiclePlate[1][playerid], 0);
	PlayerTextDrawSetProportional(playerid, VehiclePlate[1][playerid], 1);
	PlayerTextDrawSetSelectable(playerid, VehiclePlate[1][playerid], 0);

	VehiclePlate[2][playerid] = CreatePlayerTextDraw(playerid, 398.000000, 248.000000, "Plate: 3IBI36");
	PlayerTextDrawFont(playerid, VehiclePlate[2][playerid], 2);
	PlayerTextDrawLetterSize(playerid, VehiclePlate[2][playerid], 0.162500, 0.950000);
	PlayerTextDrawTextSize(playerid, VehiclePlate[2][playerid], 400.000000, 56.000000);
	PlayerTextDrawSetOutline(playerid, VehiclePlate[2][playerid], 0);
	PlayerTextDrawSetShadow(playerid, VehiclePlate[2][playerid], 0);
	PlayerTextDrawAlignment(playerid, VehiclePlate[2][playerid], 2);
	PlayerTextDrawColor(playerid, VehiclePlate[2][playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, VehiclePlate[2][playerid], 255);
	PlayerTextDrawBoxColor(playerid, VehiclePlate[2][playerid], 50);
	PlayerTextDrawUseBox(playerid, VehiclePlate[2][playerid], 0);
	PlayerTextDrawSetProportional(playerid, VehiclePlate[2][playerid], 1);
	PlayerTextDrawSetSelectable(playerid, VehiclePlate[2][playerid], 0);
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
}

CreateSelectFactionTextDraws(playerid)
{
	SelectFactionLocation[playerid] = CreatePlayerTextDraw(playerid, 319.000000, 356.000000, "Crenshaw");
	PlayerTextDrawFont(playerid, SelectFactionLocation[playerid], 0);
	PlayerTextDrawLetterSize(playerid, SelectFactionLocation[playerid], 0.466666, 1.899999);
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

	SelectFaction[0][playerid] = CreatePlayerTextDraw(playerid, 262.000000, 392.000000, "Press_'~y~LEFT~w~'_or_'~y~RIGHT~w~'_to_switch");
	PlayerTextDrawFont(playerid, SelectFaction[0][playerid], 1);
	PlayerTextDrawLetterSize(playerid, SelectFaction[0][playerid], 0.191667, 1.200000);
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

	SelectFactionName[playerid] = CreatePlayerTextDraw(playerid, 319.000000, 377.000000, "San Andreas Police Departement");
	PlayerTextDrawFont(playerid, SelectFactionName[playerid], 0);
	PlayerTextDrawLetterSize(playerid, SelectFactionName[playerid], 0.349999, 1.250000);
	PlayerTextDrawTextSize(playerid, SelectFactionName[playerid], 400.000000, 146.500000);
	PlayerTextDrawSetOutline(playerid, SelectFactionName[playerid], 1);
	PlayerTextDrawSetShadow(playerid, SelectFactionName[playerid], 0);
	PlayerTextDrawAlignment(playerid, SelectFactionName[playerid], 2);
	PlayerTextDrawColor(playerid, SelectFactionName[playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, SelectFactionName[playerid], 255);
	PlayerTextDrawBoxColor(playerid, SelectFactionName[playerid], 50);
	PlayerTextDrawUseBox(playerid, SelectFactionName[playerid], 0);
	PlayerTextDrawSetProportional(playerid, SelectFactionName[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, SelectFactionName[playerid], 0);

	SelectFaction[1][playerid] = CreatePlayerTextDraw(playerid, 280.000000, 405.000000, "Press ~w~'~y~SELECT~w~' to select");
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

	SelectFactionClick[0][playerid] = CreatePlayerTextDraw(playerid, 228.000000, 375.000000, "ld_beat:left");
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

	SelectFactionClick[1][playerid] = CreatePlayerTextDraw(playerid, 395.000000, 375.000000, "ld_beat:right");
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

	SelectFactionClick[2][playerid] = CreatePlayerTextDraw(playerid, 319.000000, 417.000000, "~p~SELECT");
	PlayerTextDrawFont(playerid, SelectFactionClick[2][playerid], 3);
	PlayerTextDrawLetterSize(playerid, SelectFactionClick[2][playerid], 0.275000, 1.200000);
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

CreateALPRTextdraws(playerid)
{
	ALPR[0][playerid] = CreatePlayerTextDraw(playerid, 555.000000, 334.000000, "_");
	PlayerTextDrawFont(playerid, ALPR[0][playerid], 1);
	PlayerTextDrawLetterSize(playerid, ALPR[0][playerid], 0.600000, 5.900001);
	PlayerTextDrawTextSize(playerid, ALPR[0][playerid], 298.500000, 110.000000);
	PlayerTextDrawSetOutline(playerid, ALPR[0][playerid], 1);
	PlayerTextDrawSetShadow(playerid, ALPR[0][playerid], 0);
	PlayerTextDrawAlignment(playerid, ALPR[0][playerid], 2);
	PlayerTextDrawColor(playerid, ALPR[0][playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, ALPR[0][playerid], 255);
	PlayerTextDrawBoxColor(playerid, ALPR[0][playerid], 255);
	PlayerTextDrawUseBox(playerid, ALPR[0][playerid], 1);
	PlayerTextDrawSetProportional(playerid, ALPR[0][playerid], 1);
	PlayerTextDrawSetSelectable(playerid, ALPR[0][playerid], 0);

	ALPR[1][playerid] = CreatePlayerTextDraw(playerid, 555.000000, 336.000000, "_");
	PlayerTextDrawFont(playerid, ALPR[1][playerid], 1);
	PlayerTextDrawLetterSize(playerid, ALPR[1][playerid], 0.600000, 5.399999);
	PlayerTextDrawTextSize(playerid, ALPR[1][playerid], 298.500000, 106.500000);
	PlayerTextDrawSetOutline(playerid, ALPR[1][playerid], 1);
	PlayerTextDrawSetShadow(playerid, ALPR[1][playerid], 0);
	PlayerTextDrawAlignment(playerid, ALPR[1][playerid], 2);
	PlayerTextDrawColor(playerid, ALPR[1][playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, ALPR[1][playerid], 255);
	PlayerTextDrawBoxColor(playerid, ALPR[1][playerid], 1296911871);
	PlayerTextDrawUseBox(playerid, ALPR[1][playerid], 1);
	PlayerTextDrawSetProportional(playerid, ALPR[1][playerid], 1);
	PlayerTextDrawSetSelectable(playerid, ALPR[1][playerid], 0);

	ALPR[2][playerid] = CreatePlayerTextDraw(playerid, 555.000000, 323.000000, "~b~ALPR");
	PlayerTextDrawFont(playerid, ALPR[2][playerid], 2);
	PlayerTextDrawLetterSize(playerid, ALPR[2][playerid], 0.245829, 1.550009);
	PlayerTextDrawTextSize(playerid, ALPR[2][playerid], 400.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, ALPR[2][playerid], 1);
	PlayerTextDrawSetShadow(playerid, ALPR[2][playerid], 0);
	PlayerTextDrawAlignment(playerid, ALPR[2][playerid], 2);
	PlayerTextDrawColor(playerid, ALPR[2][playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, ALPR[2][playerid], 255);
	PlayerTextDrawBoxColor(playerid, ALPR[2][playerid], 50);
	PlayerTextDrawUseBox(playerid, ALPR[2][playerid], 0);
	PlayerTextDrawSetProportional(playerid, ALPR[2][playerid], 1);
	PlayerTextDrawSetSelectable(playerid, ALPR[2][playerid], 0);

	ALPR[3][playerid] = CreatePlayerTextDraw(playerid, 527.000000, 354.000000, "NONE");
	PlayerTextDrawFont(playerid, ALPR[3][playerid], 2);
	PlayerTextDrawLetterSize(playerid, ALPR[3][playerid], 0.212493, 1.400007);
	PlayerTextDrawTextSize(playerid, ALPR[3][playerid], 605.000000, 226.000000);
	PlayerTextDrawSetOutline(playerid, ALPR[3][playerid], 0);
	PlayerTextDrawSetShadow(playerid, ALPR[3][playerid], 0);
	PlayerTextDrawAlignment(playerid, ALPR[3][playerid], 2);
	PlayerTextDrawColor(playerid, ALPR[3][playerid], 255);
	PlayerTextDrawBackgroundColor(playerid, ALPR[3][playerid], 255);
	PlayerTextDrawBoxColor(playerid, ALPR[3][playerid], 50);
	PlayerTextDrawUseBox(playerid, ALPR[3][playerid], 0);
	PlayerTextDrawSetProportional(playerid, ALPR[3][playerid], 1);
	PlayerTextDrawSetSelectable(playerid, ALPR[3][playerid], 0);

	ALPR[4][playerid] = CreatePlayerTextDraw(playerid, 583.000000, 354.000000, "NONE");
	PlayerTextDrawFont(playerid, ALPR[4][playerid], 2);
	PlayerTextDrawLetterSize(playerid, ALPR[4][playerid], 0.212493, 1.400007);
	PlayerTextDrawTextSize(playerid, ALPR[4][playerid], 605.000000, 226.000000);
	PlayerTextDrawSetOutline(playerid, ALPR[4][playerid], 0);
	PlayerTextDrawSetShadow(playerid, ALPR[4][playerid], 0);
	PlayerTextDrawAlignment(playerid, ALPR[4][playerid], 2);
	PlayerTextDrawColor(playerid, ALPR[4][playerid], 255);
	PlayerTextDrawBackgroundColor(playerid, ALPR[4][playerid], 255);
	PlayerTextDrawBoxColor(playerid, ALPR[4][playerid], 50);
	PlayerTextDrawUseBox(playerid, ALPR[4][playerid], 0);
	PlayerTextDrawSetProportional(playerid, ALPR[4][playerid], 1);
	PlayerTextDrawSetSelectable(playerid, ALPR[4][playerid], 0);

	ALPR[5][playerid] = CreatePlayerTextDraw(playerid, 516.000000, 335.000000, "Front");
	PlayerTextDrawFont(playerid, ALPR[5][playerid], 2);
	PlayerTextDrawLetterSize(playerid, ALPR[5][playerid], 0.166657, 0.950007);
	PlayerTextDrawTextSize(playerid, ALPR[5][playerid], 605.000000, 226.000000);
	PlayerTextDrawSetOutline(playerid, ALPR[5][playerid], 0);
	PlayerTextDrawSetShadow(playerid, ALPR[5][playerid], 0);
	PlayerTextDrawAlignment(playerid, ALPR[5][playerid], 1);
	PlayerTextDrawColor(playerid, ALPR[5][playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, ALPR[5][playerid], 255);
	PlayerTextDrawBoxColor(playerid, ALPR[5][playerid], 50);
	PlayerTextDrawUseBox(playerid, ALPR[5][playerid], 0);
	PlayerTextDrawSetProportional(playerid, ALPR[5][playerid], 1);
	PlayerTextDrawSetSelectable(playerid, ALPR[5][playerid], 0);

	ALPR[6][playerid] = CreatePlayerTextDraw(playerid, 575.000000, 335.000000, "Rear");
	PlayerTextDrawFont(playerid, ALPR[6][playerid], 2);
	PlayerTextDrawLetterSize(playerid, ALPR[6][playerid], 0.145829, 1.000007);
	PlayerTextDrawTextSize(playerid, ALPR[6][playerid], 605.000000, 226.000000);
	PlayerTextDrawSetOutline(playerid, ALPR[6][playerid], 0);
	PlayerTextDrawSetShadow(playerid, ALPR[6][playerid], 0);
	PlayerTextDrawAlignment(playerid, ALPR[6][playerid], 1);
	PlayerTextDrawColor(playerid, ALPR[6][playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, ALPR[6][playerid], 255);
	PlayerTextDrawBoxColor(playerid, ALPR[6][playerid], 50);
	PlayerTextDrawUseBox(playerid, ALPR[6][playerid], 0);
	PlayerTextDrawSetProportional(playerid, ALPR[6][playerid], 1);
	PlayerTextDrawSetSelectable(playerid, ALPR[6][playerid], 0);

	ALPR[10][playerid] = CreatePlayerTextDraw(playerid, 555.000000, 394.000000, "_");
	PlayerTextDrawFont(playerid, ALPR[10][playerid], 1);
	PlayerTextDrawLetterSize(playerid, ALPR[10][playerid], 0.600000, 5.499999);
	PlayerTextDrawTextSize(playerid, ALPR[10][playerid], 298.500000, 110.000000);
	PlayerTextDrawSetOutline(playerid, ALPR[10][playerid], 1);
	PlayerTextDrawSetShadow(playerid, ALPR[10][playerid], 0);
	PlayerTextDrawAlignment(playerid, ALPR[10][playerid], 2);
	PlayerTextDrawColor(playerid, ALPR[10][playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, ALPR[10][playerid], 255);
	PlayerTextDrawBoxColor(playerid, ALPR[10][playerid], 255);
	PlayerTextDrawUseBox(playerid, ALPR[10][playerid], 1);
	PlayerTextDrawSetProportional(playerid, ALPR[10][playerid], 1);
	PlayerTextDrawSetSelectable(playerid, ALPR[10][playerid], 0);

	ALPR[11][playerid] = CreatePlayerTextDraw(playerid, 555.000000, 396.000000, "_");
	PlayerTextDrawFont(playerid, ALPR[11][playerid], 1);
	PlayerTextDrawLetterSize(playerid, ALPR[11][playerid], 0.600000, 5.049997);
	PlayerTextDrawTextSize(playerid, ALPR[11][playerid], 298.500000, 106.500000);
	PlayerTextDrawSetOutline(playerid, ALPR[11][playerid], 1);
	PlayerTextDrawSetShadow(playerid, ALPR[11][playerid], 0);
	PlayerTextDrawAlignment(playerid, ALPR[11][playerid], 2);
	PlayerTextDrawColor(playerid, ALPR[11][playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, ALPR[11][playerid], 255);
	PlayerTextDrawBoxColor(playerid, ALPR[11][playerid], 1296911871);
	PlayerTextDrawUseBox(playerid, ALPR[11][playerid], 1);
	PlayerTextDrawSetProportional(playerid, ALPR[11][playerid], 1);
	PlayerTextDrawSetSelectable(playerid, ALPR[11][playerid], 0);

	ALPR[12][playerid] = CreatePlayerTextDraw(playerid, 526.000000, 408.000000, "000");
	PlayerTextDrawFont(playerid, ALPR[12][playerid], 3);
	PlayerTextDrawLetterSize(playerid, ALPR[12][playerid], 0.737493, 3.200006);
	PlayerTextDrawTextSize(playerid, ALPR[12][playerid], 605.000000, 46.000000);
	PlayerTextDrawSetOutline(playerid, ALPR[12][playerid], 0);
	PlayerTextDrawSetShadow(playerid, ALPR[12][playerid], 0);
	PlayerTextDrawAlignment(playerid, ALPR[12][playerid], 2);
	PlayerTextDrawColor(playerid, ALPR[12][playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, ALPR[12][playerid], 255);
	PlayerTextDrawBoxColor(playerid, ALPR[12][playerid], 255);
	PlayerTextDrawUseBox(playerid, ALPR[12][playerid], 1);
	PlayerTextDrawSetProportional(playerid, ALPR[12][playerid], 1);
	PlayerTextDrawSetSelectable(playerid, ALPR[12][playerid], 0);

	ALPR[13][playerid] = CreatePlayerTextDraw(playerid, 584.000000, 408.000000, "000");
	PlayerTextDrawFont(playerid, ALPR[13][playerid], 3);
	PlayerTextDrawLetterSize(playerid, ALPR[13][playerid], 0.737493, 3.200006);
	PlayerTextDrawTextSize(playerid, ALPR[13][playerid], 605.000000, 46.000000);
	PlayerTextDrawSetOutline(playerid, ALPR[13][playerid], 0);
	PlayerTextDrawSetShadow(playerid, ALPR[13][playerid], 0);
	PlayerTextDrawAlignment(playerid, ALPR[13][playerid], 2);
	PlayerTextDrawColor(playerid, ALPR[13][playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, ALPR[13][playerid], 255);
	PlayerTextDrawBoxColor(playerid, ALPR[13][playerid], 255);
	PlayerTextDrawUseBox(playerid, ALPR[13][playerid], 1);
	PlayerTextDrawSetProportional(playerid, ALPR[13][playerid], 1);
	PlayerTextDrawSetSelectable(playerid, ALPR[13][playerid], 0);

	ALPR[14][playerid] = CreatePlayerTextDraw(playerid, 516.000000, 395.000000, "Front");
	PlayerTextDrawFont(playerid, ALPR[14][playerid], 2);
	PlayerTextDrawLetterSize(playerid, ALPR[14][playerid], 0.166657, 0.950007);
	PlayerTextDrawTextSize(playerid, ALPR[14][playerid], 605.000000, 226.000000);
	PlayerTextDrawSetOutline(playerid, ALPR[14][playerid], 0);
	PlayerTextDrawSetShadow(playerid, ALPR[14][playerid], 0);
	PlayerTextDrawAlignment(playerid, ALPR[14][playerid], 1);
	PlayerTextDrawColor(playerid, ALPR[14][playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, ALPR[14][playerid], 255);
	PlayerTextDrawBoxColor(playerid, ALPR[14][playerid], 50);
	PlayerTextDrawUseBox(playerid, ALPR[14][playerid], 0);
	PlayerTextDrawSetProportional(playerid, ALPR[14][playerid], 1);
	PlayerTextDrawSetSelectable(playerid, ALPR[14][playerid], 0);

	ALPR[15][playerid] = CreatePlayerTextDraw(playerid, 575.000000, 395.000000, "Rear");
	PlayerTextDrawFont(playerid, ALPR[15][playerid], 2);
	PlayerTextDrawLetterSize(playerid, ALPR[15][playerid], 0.145829, 1.000007);
	PlayerTextDrawTextSize(playerid, ALPR[15][playerid], 605.000000, 226.000000);
	PlayerTextDrawSetOutline(playerid, ALPR[15][playerid], 0);
	PlayerTextDrawSetShadow(playerid, ALPR[15][playerid], 0);
	PlayerTextDrawAlignment(playerid, ALPR[15][playerid], 1);
	PlayerTextDrawColor(playerid, ALPR[15][playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, ALPR[15][playerid], 255);
	PlayerTextDrawBoxColor(playerid, ALPR[15][playerid], 50);
	PlayerTextDrawUseBox(playerid, ALPR[15][playerid], 0);
	PlayerTextDrawSetProportional(playerid, ALPR[15][playerid], 1);
	PlayerTextDrawSetSelectable(playerid, ALPR[15][playerid], 0);

	ALPR[16][playerid] = CreatePlayerTextDraw(playerid, 555.000000, 386.000000, "~b~Alert");
	PlayerTextDrawFont(playerid, ALPR[16][playerid], 2);
	PlayerTextDrawLetterSize(playerid, ALPR[16][playerid], 0.208329, 1.200009);
	PlayerTextDrawTextSize(playerid, ALPR[16][playerid], 400.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, ALPR[16][playerid], 1);
	PlayerTextDrawSetShadow(playerid, ALPR[16][playerid], 0);
	PlayerTextDrawAlignment(playerid, ALPR[16][playerid], 2);
	PlayerTextDrawColor(playerid, ALPR[16][playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, ALPR[16][playerid], 255);
	PlayerTextDrawBoxColor(playerid, ALPR[16][playerid], 50);
	PlayerTextDrawUseBox(playerid, ALPR[16][playerid], 0);
	PlayerTextDrawSetProportional(playerid, ALPR[16][playerid], 1);
	PlayerTextDrawSetSelectable(playerid, ALPR[16][playerid], 0);

	ALPR[17][playerid] = CreatePlayerTextDraw(playerid, 585.000000, 376.000000, "");
	PlayerTextDrawFont(playerid, ALPR[17][playerid], 2);
	PlayerTextDrawLetterSize(playerid, ALPR[17][playerid], 0.170826, 1.000007);
	PlayerTextDrawTextSize(playerid, ALPR[17][playerid], 605.000000, 226.000000);
	PlayerTextDrawSetOutline(playerid, ALPR[17][playerid], 0);
	PlayerTextDrawSetShadow(playerid, ALPR[17][playerid], 0);
	PlayerTextDrawAlignment(playerid, ALPR[17][playerid], 2);
	PlayerTextDrawColor(playerid, ALPR[17][playerid], 255);
	PlayerTextDrawBackgroundColor(playerid, ALPR[17][playerid], 255);
	PlayerTextDrawBoxColor(playerid, ALPR[17][playerid], 50);
	PlayerTextDrawUseBox(playerid, ALPR[17][playerid], 0);
	PlayerTextDrawSetProportional(playerid, ALPR[17][playerid], 1);
	PlayerTextDrawSetSelectable(playerid, ALPR[17][playerid], 0);

	ALPR[9][playerid] = CreatePlayerTextDraw(playerid, 529.000000, 376.000000, "");
	PlayerTextDrawFont(playerid, ALPR[9][playerid], 2);
	PlayerTextDrawLetterSize(playerid, ALPR[9][playerid], 0.162493, 0.950007);
	PlayerTextDrawTextSize(playerid, ALPR[9][playerid], 605.000000, 226.000000);
	PlayerTextDrawSetOutline(playerid, ALPR[9][playerid], 0);
	PlayerTextDrawSetShadow(playerid, ALPR[9][playerid], 0);
	PlayerTextDrawAlignment(playerid, ALPR[9][playerid], 2);
	PlayerTextDrawColor(playerid, ALPR[9][playerid], 255);
	PlayerTextDrawBackgroundColor(playerid, ALPR[9][playerid], 255);
	PlayerTextDrawBoxColor(playerid, ALPR[9][playerid], 50);
	PlayerTextDrawUseBox(playerid, ALPR[9][playerid], 0);
	PlayerTextDrawSetProportional(playerid, ALPR[9][playerid], 1);
	PlayerTextDrawSetSelectable(playerid, ALPR[9][playerid], 0);
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

stock ShowBoxMessage(playerid, string[], time)
{
	new validtime = time*1000;

	PlayerTextDrawSetString(playerid, Subtitles[playerid], string);
	PlayerTextDrawShow(playerid, Subtitles[playerid]);
	SetTimerEx("HideBoxMessage", validtime, false, "d", playerid);

	PlayerPlaySound(playerid, 1054, 0.0, 0.0, 0.0);
	return 1;
}
function:HideBoxMessage(playerid)
{
	return PlayerTextDrawHide(playerid, Subtitles[playerid]);
}

stock ShowHeaderMessage(playerid, header[], string[])
{
	PlayerTextDrawSetString(playerid, HeaderTD[1][playerid], header);
	PlayerTextDrawShow(playerid, HeaderTD[1][playerid]);

	PlayerTextDrawSetString(playerid, HeaderTD[0][playerid], string);
	PlayerTextDrawShow(playerid, HeaderTD[0][playerid]);
	SetTimerEx("HideHeaderMessage", 5000, false, "d", playerid);
	return 1;
}

function:HideHeaderMessage(playerid)
{
	PlayerTextDrawHide(playerid, HeaderTD[0][playerid]);
	PlayerTextDrawHide(playerid, HeaderTD[1][playerid]);
	return 1;
}

stock ShowVehicleSpeedometer(playerid, hud1[], hud2[], hud3[], hud4[], hud5[], hud6[], hud7[], hud8[], hud9[])
{
	PlayerTextDrawSetString(playerid, speedo[0][playerid], hud1);
	PlayerTextDrawSetString(playerid, speedo[1][playerid], hud2);
	PlayerTextDrawSetString(playerid, speedo[2][playerid], hud3);
	PlayerTextDrawSetString(playerid, speedo[3][playerid], hud4);
	PlayerTextDrawSetString(playerid, speedo[4][playerid], hud5);
	PlayerTextDrawSetString(playerid, speedo[5][playerid], hud6);
	PlayerTextDrawSetString(playerid, speedo[6][playerid], hud7);
	PlayerTextDrawSetString(playerid, speedo[7][playerid], hud8);
	PlayerTextDrawSetString(playerid, speedo[8][playerid], hud9);

	PlayerTextDrawShow(playerid, speedo[0][playerid]);
	PlayerTextDrawShow(playerid, speedo[1][playerid]);
	PlayerTextDrawShow(playerid, speedo[2][playerid]);
	PlayerTextDrawShow(playerid, speedo[3][playerid]);
	PlayerTextDrawShow(playerid, speedo[4][playerid]);
	PlayerTextDrawShow(playerid, speedo[5][playerid]);
	PlayerTextDrawShow(playerid, speedo[6][playerid]);
	PlayerTextDrawShow(playerid, speedo[7][playerid]);
	PlayerTextDrawShow(playerid, speedo[8][playerid]);
	return 1;
}

stock HideVehicleSpeedometer(playerid)
{
	PlayerTextDrawHide(playerid, speedo[0][playerid]);
	PlayerTextDrawHide(playerid, speedo[1][playerid]);
	PlayerTextDrawHide(playerid, speedo[2][playerid]);
	PlayerTextDrawHide(playerid, speedo[3][playerid]);
	PlayerTextDrawHide(playerid, speedo[4][playerid]);
	PlayerTextDrawHide(playerid, speedo[5][playerid]);
	PlayerTextDrawHide(playerid, speedo[6][playerid]);
	PlayerTextDrawHide(playerid, speedo[7][playerid]);
	PlayerTextDrawHide(playerid, speedo[8][playerid]);
	PlayerTextDrawHide(playerid, VehicleName[playerid]);
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
