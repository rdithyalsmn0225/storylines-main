//Textdraws
new PlayerText:ServerName[2][MAX_PLAYERS];
new PlayerText:VehicleName[MAX_PLAYERS];
new PlayerText:loginscreen[3][MAX_PLAYERS];
new PlayerText:Notification[2][MAX_PLAYERS];
new PlayerText:HeaderTD[2][MAX_PLAYERS];
new Text:Times;
new PlayerText:Street[2][MAX_PLAYERS];
new PlayerText:Subtitles[MAX_PLAYERS];
new PlayerText:speedo[7][MAX_PLAYERS];
new PlayerText:phone[9][MAX_PLAYERS];
new Text:phonetimes;

new PlayerText:Fades[MAX_PLAYERS];

new PlayerText:SelectFactionLocation[MAX_PLAYERS];
new PlayerText:SelectFactionName[MAX_PLAYERS];
new PlayerText:SelectFaction[2][MAX_PLAYERS];
new PlayerText:SelectFactionClick[3][MAX_PLAYERS];

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

//Textdraws

stock CreateTextdraws(playerid)
{
	ServerName[0][playerid] = CreatePlayerTextDraw(playerid, 24.000000, 438.000000, "idlestreet");
	PlayerTextDrawFont(playerid, ServerName[0][playerid], 2);
	PlayerTextDrawLetterSize(playerid, ServerName[0][playerid], 0.179161, 0.999997);
	PlayerTextDrawTextSize(playerid, ServerName[0][playerid], 604.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, ServerName[0][playerid], 1);
	PlayerTextDrawSetShadow(playerid, ServerName[0][playerid], 0);
	PlayerTextDrawAlignment(playerid, ServerName[0][playerid], 1);
	PlayerTextDrawColor(playerid, ServerName[0][playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, ServerName[0][playerid], 255);
	PlayerTextDrawBoxColor(playerid, ServerName[0][playerid], 100);
	PlayerTextDrawUseBox(playerid, ServerName[0][playerid], 0);
	PlayerTextDrawSetProportional(playerid, ServerName[0][playerid], 1);
	PlayerTextDrawSetSelectable(playerid, ServerName[0][playerid], 0);

	ServerName[1][playerid] = CreatePlayerTextDraw(playerid, 72.000000, 438.000000, "~y~Los Santos");
	PlayerTextDrawFont(playerid, ServerName[1][playerid], 2);
	PlayerTextDrawLetterSize(playerid, ServerName[1][playerid], 0.179161, 0.999997);
	PlayerTextDrawTextSize(playerid, ServerName[1][playerid], 604.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, ServerName[1][playerid], 1);
	PlayerTextDrawSetShadow(playerid, ServerName[1][playerid], 0);
	PlayerTextDrawAlignment(playerid, ServerName[1][playerid], 1);
	PlayerTextDrawColor(playerid, ServerName[1][playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, ServerName[1][playerid], 255);
	PlayerTextDrawBoxColor(playerid, ServerName[1][playerid], 100);
	PlayerTextDrawUseBox(playerid, ServerName[1][playerid], 0);
	PlayerTextDrawSetProportional(playerid, ServerName[1][playerid], 1);
	PlayerTextDrawSetSelectable(playerid, ServerName[1][playerid], 0);

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
	phone[0][playerid] = CreatePlayerTextDraw(playerid, 466.000000, 357.000000, "mdl-2001:phone_black");
	PlayerTextDrawFont(playerid, phone[0][playerid], 4);
	PlayerTextDrawLetterSize(playerid, phone[0][playerid], 0.600000, 2.000000);
	PlayerTextDrawTextSize(playerid, phone[0][playerid], 58.500000, 94.000000);
	PlayerTextDrawSetOutline(playerid, phone[0][playerid], 1);
	PlayerTextDrawSetShadow(playerid, phone[0][playerid], 0);
	PlayerTextDrawAlignment(playerid, phone[0][playerid], 1);
	PlayerTextDrawColor(playerid, phone[0][playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, phone[0][playerid], 255);
	PlayerTextDrawBoxColor(playerid, phone[0][playerid], 50);
	PlayerTextDrawUseBox(playerid, phone[0][playerid], 1);
	PlayerTextDrawSetProportional(playerid, phone[0][playerid], 1);
	PlayerTextDrawSetSelectable(playerid, phone[0][playerid], 0);

	phone[1][playerid] = CreatePlayerTextDraw(playerid, 466.000000, 357.000000, "mdl-2001:bg_3");
	PlayerTextDrawFont(playerid, phone[1][playerid], 4);
	PlayerTextDrawLetterSize(playerid, phone[1][playerid], 0.600000, 2.000000);
	PlayerTextDrawTextSize(playerid, phone[1][playerid], 58.500000, 94.000000);
	PlayerTextDrawSetOutline(playerid, phone[1][playerid], 1);
	PlayerTextDrawSetShadow(playerid, phone[1][playerid], 0);
	PlayerTextDrawAlignment(playerid, phone[1][playerid], 1);
	PlayerTextDrawColor(playerid, phone[1][playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, phone[1][playerid], 255);
	PlayerTextDrawBoxColor(playerid, phone[1][playerid], 50);
	PlayerTextDrawUseBox(playerid, phone[1][playerid], 1);
	PlayerTextDrawSetProportional(playerid, phone[1][playerid], 1);
	PlayerTextDrawSetSelectable(playerid, phone[1][playerid], 0);

	phone[2][playerid] = CreatePlayerTextDraw(playerid, 466.000000, 357.000000, "mdl-2001:screen_border");
	PlayerTextDrawFont(playerid, phone[2][playerid], 4);
	PlayerTextDrawLetterSize(playerid, phone[2][playerid], 0.600000, 2.000000);
	PlayerTextDrawTextSize(playerid, phone[2][playerid], 58.500000, 94.000000);
	PlayerTextDrawSetOutline(playerid, phone[2][playerid], 1);
	PlayerTextDrawSetShadow(playerid, phone[2][playerid], 0);
	PlayerTextDrawAlignment(playerid, phone[2][playerid], 1);
	PlayerTextDrawColor(playerid, phone[2][playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, phone[2][playerid], 255);
	PlayerTextDrawBoxColor(playerid, phone[2][playerid], 50);
	PlayerTextDrawUseBox(playerid, phone[2][playerid], 1);
	PlayerTextDrawSetProportional(playerid, phone[2][playerid], 1);
	PlayerTextDrawSetSelectable(playerid, phone[2][playerid], 0);

	phone[3][playerid] = CreatePlayerTextDraw(playerid, 469.000000, 428.000000, "mdl-2001:mb_answer_left");
	PlayerTextDrawFont(playerid, phone[3][playerid], 4);
	PlayerTextDrawLetterSize(playerid, phone[3][playerid], 0.600000, 2.000000);
	PlayerTextDrawTextSize(playerid, phone[3][playerid], 16.000000, 23.000000);
	PlayerTextDrawSetOutline(playerid, phone[3][playerid], 1);
	PlayerTextDrawSetShadow(playerid, phone[3][playerid], 0);
	PlayerTextDrawAlignment(playerid, phone[3][playerid], 1);
	PlayerTextDrawColor(playerid, phone[3][playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, phone[3][playerid], 255);
	PlayerTextDrawBoxColor(playerid, phone[3][playerid], 50);
	PlayerTextDrawUseBox(playerid, phone[3][playerid], 1);
	PlayerTextDrawSetProportional(playerid, phone[3][playerid], 1);
	PlayerTextDrawSetSelectable(playerid, phone[3][playerid], 1);

	phone[4][playerid] = CreatePlayerTextDraw(playerid, 506.000000, 428.000000, "mdl-2001:mb_decline_right");
	PlayerTextDrawFont(playerid, phone[4][playerid], 4);
	PlayerTextDrawLetterSize(playerid, phone[4][playerid], 0.600000, 2.000000);
	PlayerTextDrawTextSize(playerid, phone[4][playerid], 16.000000, 23.000000);
	PlayerTextDrawSetOutline(playerid, phone[4][playerid], 1);
	PlayerTextDrawSetShadow(playerid, phone[4][playerid], 0);
	PlayerTextDrawAlignment(playerid, phone[4][playerid], 1);
	PlayerTextDrawColor(playerid, phone[4][playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, phone[4][playerid], 255);
	PlayerTextDrawBoxColor(playerid, phone[4][playerid], 50);
	PlayerTextDrawUseBox(playerid, phone[4][playerid], 1);
	PlayerTextDrawSetProportional(playerid, phone[4][playerid], 1);
	PlayerTextDrawSetSelectable(playerid, phone[4][playerid], 1);

	phone[5][playerid] = CreatePlayerTextDraw(playerid, 499.000000, 366.000000, "mdl-2001:battery_red");
	PlayerTextDrawFont(playerid, phone[5][playerid], 4);
	PlayerTextDrawLetterSize(playerid, phone[5][playerid], 0.600000, 2.000000);
	PlayerTextDrawTextSize(playerid, phone[5][playerid], 26.500000, 32.000000);
	PlayerTextDrawSetOutline(playerid, phone[5][playerid], 1);
	PlayerTextDrawSetShadow(playerid, phone[5][playerid], 0);
	PlayerTextDrawAlignment(playerid, phone[5][playerid], 1);
	PlayerTextDrawColor(playerid, phone[5][playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, phone[5][playerid], 255);
	PlayerTextDrawBoxColor(playerid, phone[5][playerid], 50);
	PlayerTextDrawUseBox(playerid, phone[5][playerid], 1);
	PlayerTextDrawSetProportional(playerid, phone[5][playerid], 1);
	PlayerTextDrawSetSelectable(playerid, phone[5][playerid], 0);

	phone[6][playerid] = CreatePlayerTextDraw(playerid, 472.000000, 418.000000, "mdl-2001:config");
	PlayerTextDrawFont(playerid, phone[6][playerid], 4);
	PlayerTextDrawLetterSize(playerid, phone[6][playerid], 0.600000, 2.000000);
	PlayerTextDrawTextSize(playerid, phone[6][playerid], 8.000000, 9.500000);
	PlayerTextDrawSetOutline(playerid, phone[6][playerid], 1);
	PlayerTextDrawSetShadow(playerid, phone[6][playerid], 0);
	PlayerTextDrawAlignment(playerid, phone[6][playerid], 1);
	PlayerTextDrawColor(playerid, phone[6][playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, phone[6][playerid], 255);
	PlayerTextDrawBoxColor(playerid, phone[6][playerid], 50);
	PlayerTextDrawUseBox(playerid, phone[6][playerid], 1);
	PlayerTextDrawSetProportional(playerid, phone[6][playerid], 1);
	PlayerTextDrawSetSelectable(playerid, phone[6][playerid], 1);

	phone[7][playerid] = CreatePlayerTextDraw(playerid, 496.000000, 399.000000, "connected");
	PlayerTextDrawFont(playerid, phone[7][playerid], 1);
	PlayerTextDrawLetterSize(playerid, phone[7][playerid], 0.191664, 1.000000);
	PlayerTextDrawTextSize(playerid, phone[7][playerid], 400.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, phone[7][playerid], 1);
	PlayerTextDrawSetShadow(playerid, phone[7][playerid], 0);
	PlayerTextDrawAlignment(playerid, phone[7][playerid], 2);
	PlayerTextDrawColor(playerid, phone[7][playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, phone[7][playerid], 255);
	PlayerTextDrawBoxColor(playerid, phone[7][playerid], 50);
	PlayerTextDrawUseBox(playerid, phone[7][playerid], 0);
	PlayerTextDrawSetProportional(playerid, phone[7][playerid], 1);
	PlayerTextDrawSetSelectable(playerid, phone[7][playerid], 0);

	phone[8][playerid] = CreatePlayerTextDraw(playerid, 464.000000, 382.000000, "mdl-2001:sidebutton");
	PlayerTextDrawFont(playerid, phone[8][playerid], 4);
	PlayerTextDrawLetterSize(playerid, phone[8][playerid], 0.600000, 2.000000);
	PlayerTextDrawTextSize(playerid, phone[8][playerid], 4.000000, 16.000000);
	PlayerTextDrawSetOutline(playerid, phone[8][playerid], 1);
	PlayerTextDrawSetShadow(playerid, phone[8][playerid], 0);
	PlayerTextDrawAlignment(playerid, phone[8][playerid], 1);
	PlayerTextDrawColor(playerid, phone[8][playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, phone[8][playerid], 255);
	PlayerTextDrawBoxColor(playerid, phone[8][playerid], 50);
	PlayerTextDrawUseBox(playerid, phone[8][playerid], 1);
	PlayerTextDrawSetProportional(playerid, phone[8][playerid], 1);
	PlayerTextDrawSetSelectable(playerid, phone[8][playerid], 1);
}

CreateNotificationTextDraws(playerid)
{
	Notification[0][playerid] = CreatePlayerTextDraw(playerid, 9.000000, 198.000000, "To beggin running, use SPACE to rapidly. Do not allow your power bar to empty or you will fall of the treadmill.");
	PlayerTextDrawFont(playerid, Notification[0][playerid], 1);
	PlayerTextDrawLetterSize(playerid, Notification[0][playerid], 0.220825, 1.399994);
	PlayerTextDrawTextSize(playerid, Notification[0][playerid], 158.500000, 26.000000);
	PlayerTextDrawSetOutline(playerid, Notification[0][playerid], 0);
	PlayerTextDrawSetShadow(playerid, Notification[0][playerid], 0);
	PlayerTextDrawAlignment(playerid, Notification[0][playerid], 1);
	PlayerTextDrawColor(playerid, Notification[0][playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, Notification[0][playerid], 255);
	PlayerTextDrawBoxColor(playerid, Notification[0][playerid], 185);
	PlayerTextDrawUseBox(playerid, Notification[0][playerid], 1);
	PlayerTextDrawSetProportional(playerid, Notification[0][playerid], 1);
	PlayerTextDrawSetSelectable(playerid, Notification[0][playerid], 0);

	Notification[1][playerid] = CreatePlayerTextDraw(playerid, 319.000000, 140.000000, "Injured");
	PlayerTextDrawFont(playerid, Notification[1][playerid], 0);
	PlayerTextDrawLetterSize(playerid, Notification[1][playerid], 1.024991, 3.599987);
	PlayerTextDrawTextSize(playerid, Notification[1][playerid], 191.000000, 23.500000);
	PlayerTextDrawSetOutline(playerid, Notification[1][playerid], 2);
	PlayerTextDrawSetShadow(playerid, Notification[1][playerid], 0);
	PlayerTextDrawAlignment(playerid, Notification[1][playerid], 2);
	PlayerTextDrawColor(playerid, Notification[1][playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, Notification[1][playerid], 255);
	PlayerTextDrawBoxColor(playerid, Notification[1][playerid], 200);
	PlayerTextDrawUseBox(playerid, Notification[1][playerid], 0);
	PlayerTextDrawSetProportional(playerid, Notification[1][playerid], 1);
	PlayerTextDrawSetSelectable(playerid, Notification[1][playerid], 0);

	Subtitles[playerid] = CreatePlayerTextDraw(playerid, 320.000000, 376.000000, "the engine is off use /engine or N to turn on the engine");
	PlayerTextDrawFont(playerid, Subtitles[playerid], 1);
	PlayerTextDrawLetterSize(playerid, Subtitles[playerid], 0.241664, 1.099998);
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
}

CreateHUDTextDraws(playerid)
{
	Street[0][playerid] = CreatePlayerTextDraw(playerid, 614.000000, 418.000000, "South North~n~~y~SW");
	PlayerTextDrawFont(playerid, Street[0][playerid], 1);
	PlayerTextDrawLetterSize(playerid, Street[0][playerid], 0.204160, 1.249999);
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

	Street[1][playerid] = CreatePlayerTextDraw(playerid, 556.000000, 416.000000, "Westmont Avenue~n~El Corona~n~Los Santos");
	PlayerTextDrawFont(playerid, Street[1][playerid], 1);
	PlayerTextDrawLetterSize(playerid, Street[1][playerid], 0.199993, 1.050000);
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

	GameBar[1][playerid] = CreatePlayerTextDraw(playerid, 500.000000, 117.000000, "mdl-2001:15");
	PlayerTextDrawFont(playerid, GameBar[1][playerid], 4);
	PlayerTextDrawLetterSize(playerid, GameBar[1][playerid], 0.600000, 2.000000);
	PlayerTextDrawTextSize(playerid, GameBar[1][playerid], 107.500000, 12.500000);
	PlayerTextDrawSetOutline(playerid, GameBar[1][playerid], 1);
	PlayerTextDrawSetShadow(playerid, GameBar[1][playerid], 0);
	PlayerTextDrawAlignment(playerid, GameBar[1][playerid], 3);
	PlayerTextDrawColor(playerid, GameBar[1][playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, GameBar[1][playerid], 255);
	PlayerTextDrawBoxColor(playerid, GameBar[1][playerid], 50);
	PlayerTextDrawUseBox(playerid, GameBar[1][playerid], 1);
	PlayerTextDrawSetProportional(playerid, GameBar[1][playerid], 1);
	PlayerTextDrawSetSelectable(playerid, GameBar[1][playerid], 0);

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
}

CreateVehicleTextDraws(playerid)
{
	VehicleName[playerid] = CreatePlayerTextDraw(playerid, 630.000000, 402.000000, "~g~BMX");
	PlayerTextDrawFont(playerid, VehicleName[playerid], 2);
	PlayerTextDrawLetterSize(playerid, VehicleName[playerid], 0.379164, 1.599997);
	PlayerTextDrawTextSize(playerid, VehicleName[playerid], 400.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, VehicleName[playerid], 1);
	PlayerTextDrawSetShadow(playerid, VehicleName[playerid], 0);
	PlayerTextDrawAlignment(playerid, VehicleName[playerid], 3);
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

	SelectFaction[0][playerid] = CreatePlayerTextDraw(playerid, 262.000000, 392.000000, "Press_\"~y~LEFT~w~\"_or_\"~y~RIGHT~w~\"_to_switch");
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

	SelectFactionName[playerid] = CreatePlayerTextDraw(playerid, 319.000000, 377.000000, "~p~Seville Boulevard Famillies");
	PlayerTextDrawFont(playerid, SelectFactionName[playerid], 0);
	PlayerTextDrawLetterSize(playerid, SelectFactionName[playerid], 0.349999, 1.250000);
	PlayerTextDrawTextSize(playerid, SelectFactionName[playerid], 400.000000, 115.000000);
	PlayerTextDrawSetOutline(playerid, SelectFactionName[playerid], 1);
	PlayerTextDrawSetShadow(playerid, SelectFactionName[playerid], 0);
	PlayerTextDrawAlignment(playerid, SelectFactionName[playerid], 2);
	PlayerTextDrawColor(playerid, SelectFactionName[playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, SelectFactionName[playerid], 255);
	PlayerTextDrawBoxColor(playerid, SelectFactionName[playerid], 50);
	PlayerTextDrawUseBox(playerid, SelectFactionName[playerid], 0);
	PlayerTextDrawSetProportional(playerid, SelectFactionName[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, SelectFactionName[playerid], 0);

	SelectFaction[1][playerid] = CreatePlayerTextDraw(playerid, 280.000000, 405.000000, "Press ~w~\"~y~SELECT~w~\" to select");
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

	SelectFactionClick[0][playerid] = CreatePlayerTextDraw(playerid, 245.000000, 375.000000, "ld_beat:left");
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

	SelectFactionClick[1][playerid] = CreatePlayerTextDraw(playerid, 377.000000, 375.000000, "ld_beat:right");
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

stock ShowBoxMessage(playerid, string[], time, type=0)
{
	new validtime = time*1000;

	if(type == 0)
	{
		PlayerTextDrawSetString(playerid, Notification[0][playerid], string);
		PlayerTextDrawShow(playerid, Notification[0][playerid]);
		SetTimerEx("HideBoxMessage", validtime, false, "d", playerid);
	}
	else if(type == 1)
	{
		PlayerTextDrawSetString(playerid, Notification[1][playerid], string);
		PlayerTextDrawShow(playerid, Notification[1][playerid]);
		SetTimerEx("HideBoxMessage1", validtime, false, "d", playerid);
	}
	else if(type == 2)
	{
		PlayerTextDrawSetString(playerid, Subtitles[playerid], string);
		PlayerTextDrawShow(playerid, Subtitles[playerid]);
		SetTimerEx("HideBoxMessage2", validtime, false, "d", playerid);
	}
	PlayerPlaySound(playerid, 1054, 0.0, 0.0, 0.0);
	return 1;
}

function:HideBoxMessage(playerid)
{
	return PlayerTextDrawHide(playerid, Notification[0][playerid]);
}

function:HideBoxMessage1(playerid)
{
	return PlayerTextDrawHide(playerid, Notification[1][playerid]);
}

function:HideBoxMessage2(playerid)
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

stock ShowCustomHud(playerid, hud1[], hud2[], hud3[], hud4[], hud5[], hud6[], hud7[])//Time in Sec.
{
	PlayerTextDrawSetString(playerid, speedo[0][playerid], hud1);
	PlayerTextDrawSetString(playerid, speedo[1][playerid], hud2);
	PlayerTextDrawSetString(playerid, speedo[2][playerid], hud3);
	PlayerTextDrawSetString(playerid, speedo[3][playerid], hud4);
	PlayerTextDrawSetString(playerid, speedo[4][playerid], hud5);
	PlayerTextDrawSetString(playerid, speedo[5][playerid], hud6);
	PlayerTextDrawSetString(playerid, speedo[6][playerid], hud7);

	PlayerTextDrawShow(playerid, speedo[0][playerid]);
	PlayerTextDrawShow(playerid, speedo[1][playerid]);
	PlayerTextDrawShow(playerid, speedo[2][playerid]);
	PlayerTextDrawShow(playerid, speedo[3][playerid]);
	PlayerTextDrawShow(playerid, speedo[4][playerid]);
	PlayerTextDrawShow(playerid, speedo[5][playerid]);
	PlayerTextDrawShow(playerid, speedo[6][playerid]);
	return 1;
}

stock DestroyCustomHUD(playerid)
{
	PlayerTextDrawHide(playerid, speedo[0][playerid]);
	PlayerTextDrawHide(playerid, speedo[1][playerid]);
	PlayerTextDrawHide(playerid, speedo[2][playerid]);
	PlayerTextDrawHide(playerid, speedo[3][playerid]);
	PlayerTextDrawHide(playerid, speedo[4][playerid]);
	PlayerTextDrawHide(playerid, speedo[5][playerid]);
	PlayerTextDrawHide(playerid, speedo[6][playerid]);
	PlayerTextDrawHide(playerid, VehicleName[playerid]);
	return 1;
}

stock ShowBarInfo(playerid, text[], value, type, time=5)
{
	new validtime = time*1000;
	switch(type)
	{
		case 0: //Plus
		{
			PlayerTextDrawSetString(playerid, barinfotd[1][playerid], text);
			PlayerTextDrawSetString(playerid, barinfotd[2][playerid], "+");
			SetPlayerGameBar(playerid, barinfotd[3][playerid], value, GAMEBAR_PLUS);
		}
		case 1: //Minus
		{
			PlayerTextDrawSetString(playerid, barinfotd[1][playerid], text);
			PlayerTextDrawSetString(playerid, barinfotd[2][playerid], "-");
			SetPlayerGameBar(playerid, barinfotd[3][playerid], value, GAMEBAR_MINUS);
		}
	}
	PlayerTextDrawShow(playerid, barinfotd[0][playerid]);
	PlayerTextDrawShow(playerid, barinfotd[1][playerid]);
	PlayerTextDrawShow(playerid, barinfotd[2][playerid]);
	PlayerTextDrawShow(playerid, barinfotd[3][playerid]);

	SetTimerEx("DestroyBarInfo", validtime, false, "d", playerid);
	return 1;
}
function:DestroyBarInfo(playerid)
{
	PlayerTextDrawHide(playerid, barinfotd[0][playerid]);
	PlayerTextDrawHide(playerid, barinfotd[1][playerid]);
	PlayerTextDrawHide(playerid, barinfotd[2][playerid]);
	PlayerTextDrawHide(playerid, barinfotd[3][playerid]);
	return 1;
}

stock ShowGameBar(playerid, value, header[])
{
	PlayerTextDrawShow(playerid, GameBar[0][playerid]);
	PlayerTextDrawShow(playerid, GameBar[1][playerid]);
	PlayerTextDrawShow(playerid, GameBar[2][playerid]);
	PlayerTextDrawSetString(playerid, GameBar[0][playerid], header);
	SetPlayerGameBar(playerid, GameBar[1][playerid], value, GAMEBAR_PLUS);
	return 1;
}

stock DestroyGameBar(playerid)
{
	PlayerTextDrawHide(playerid, GameBar[0][playerid]);
	PlayerTextDrawHide(playerid, GameBar[1][playerid]);
	PlayerTextDrawHide(playerid, GameBar[2][playerid]);
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
