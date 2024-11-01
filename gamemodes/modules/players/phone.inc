stock Send911Message(playerid, type)
{
	switch(type)
	{
		case 911:
		{
			foreach(new i : Player) if(PlayerInfo[i][E_CHARACTER_POLICEDUTY])
			{
				SendClientMessage(i, COLOR_CYAN, "|____________ Emergency Call ____________|");
				SendClientMessageEx(i, COLOR_CYAN, "Caller: %s, Phone: %d, Trace: %s", ReturnName(playerid), PlayerInfo[playerid][E_CHARACTER_PHONE], ReturnLocation(playerid));
				SendClientMessageEx(i, COLOR_CYAN, "Service required: %s", Player911Text[playerid][0]);
				SendClientMessageEx(i, COLOR_CYAN, "Situation: %s", Player911Text[playerid][1]);
				SendClientMessageEx(i, COLOR_CYAN, "Location: %s", Player911Text[playerid][2]); 
			}
		}
		case 800:
		{
			foreach(new i : Player) if(PlayerInfo[i][E_CHARACTER_MEDICDUTY])
			{
				SendClientMessage(i, COLOR_PINK, "|____________ Emergency Call ____________|");
				SendClientMessageEx(i, COLOR_PINK, "Caller: %s, Phone: %d, Trace: %s", ReturnName(playerid), PlayerInfo[playerid][E_CHARACTER_PHONE], ReturnLocation(playerid));
				SendClientMessageEx(i, COLOR_PINK, "Service required: %s", Player911Text[playerid][0]);
				SendClientMessageEx(i, COLOR_PINK, "Situation: %s", Player911Text[playerid][1]);
				SendClientMessageEx(i, COLOR_PINK, "Location: %s", Player911Text[playerid][2]); 
			}
		}
	}
	

	Player911Type[playerid] = 0;	
	cmd_hangup(playerid, ""); 
	return 1;
}

function:SendTaxiMessage(playerid)
{
	PlayerInfo[playerid][E_CHARACTER_TAXICALLED] = 1;
	SendClientMessage(playerid, COLOR_GREY, "[ ! ] They picked up. The taxi department has been notified of your call.");

	foreach(new i : Player) if(PlayerInfo[i][E_CHARACTER_TAXIDUTY])
	{
		SendClientMessage(i, COLOR_TAXI, "|____________ Taxi Call ____________|");
		SendClientMessageEx(i, COLOR_TAXI, "Caller: %s, Phone: %d, Trace: %s", ReturnName(playerid), PlayerInfo[playerid][E_CHARACTER_PHONE], ReturnLocation(playerid));
		SendClientMessageEx(i, COLOR_TAXI, "Service required: Taxi Drivers");
		SendClientMessageEx(i, COLOR_TAXI, "Location: %s", ReturnLocation(playerid)); 
	}

	cmd_hangup(playerid, ""); 

	if(GetPlayerSpecialAction(playerid) == SPECIAL_ACTION_USECELLPHONE){
		SetPlayerSpecialAction(playerid, SPECIAL_ACTION_STOPUSECELLPHONE);
	}
	return 1;
}

function:SendMechanicMessage(playerid)
{
	PlayerInfo[playerid][E_CHARACTER_TAXICALLED] = 1;
	SendClientMessage(playerid, COLOR_GREY, "[ ! ] They picked up. The taxi department has been notified of your call.");

	foreach(new i : Player) if(PlayerInfo[i][E_CHARACTER_MECHDUTY])
	{
		SendClientMessage(i, COLOR_MECHANIC, "|____________ Mechanic Call ____________|");
		SendClientMessageEx(i, COLOR_MECHANIC, "Caller: %s, Phone: %d, Trace: %s", ReturnName(playerid), PlayerInfo[playerid][E_CHARACTER_PHONE], ReturnLocation(playerid));
		SendClientMessage(i, COLOR_MECHANIC, "Service required: Mechanic Service");
		SendClientMessageEx(i, COLOR_MECHANIC, "Location: %s", ReturnLocation(playerid)); 
	}

	cmd_hangup(playerid, ""); 

	if(GetPlayerSpecialAction(playerid) == SPECIAL_ACTION_USECELLPHONE){
		SetPlayerSpecialAction(playerid, SPECIAL_ACTION_STOPUSECELLPHONE);
	}
	return 1;
}

function:On911Call(playerid)
{
	SendClientMessage(playerid, COLOR_GREY, "[ ! ] They picked up. You can talk now by using the chat box.");
	Player911Timer[1][playerid] = SetTimerEx("On911Pickup", 1500, false, "i", playerid);
	return 1;
}

function:On911Pickup(playerid)
{
	SendClientMessage(playerid, COLOR_YELLOW, "911 Operator says: 911, what service do you require?"); 
	
	PlayerInfo[playerid][E_CHARACTER_PHONELINE] = 911;
	PlayerInfo[playerid][E_CHARACTER_CALL] = 0; 
	return 1; 
}

function:OnPhoneCall(playerid, type)
{
	switch(type)
	{
		case 1:
		{
			SendClientMessage(playerid, COLOR_GREY, "[ ! ] The number you dialed is out of service."); 
			playerPhone[playerid] = 0;
			
			if(GetPlayerSpecialAction(playerid) == SPECIAL_ACTION_USECELLPHONE){
				SetPlayerSpecialAction(playerid, SPECIAL_ACTION_STOPUSECELLPHONE);
			}
			
			return 1;
		}
		case 2:
		{
			SendClientMessage(playerid, COLOR_GREY, "[ ! ] The number you dialed cannot be reached at this time.");
			playerPhone[playerid] = 0;
			
			if(GetPlayerSpecialAction(playerid) == SPECIAL_ACTION_USECELLPHONE){
				SetPlayerSpecialAction(playerid, SPECIAL_ACTION_STOPUSECELLPHONE);
			}
			
			return 1;
		}
		case 3:
		{
			SendClientMessage(playerid, COLOR_GREY, "[ ! ] You received a busy tone.");
			playerPhone[playerid] = 0;
			
			if(GetPlayerSpecialAction(playerid) == SPECIAL_ACTION_USECELLPHONE){
				SetPlayerSpecialAction(playerid, SPECIAL_ACTION_STOPUSECELLPHONE);
			}
			ShowPhone(playerid, 3);
			return 1;
		}
		case 4:
		{
			SendClientMessage(playerid, COLOR_GREY, "[ ! ] You received a busy tone.");
			playerPhone[playerid] = 0;
			ShowPhone(playerid, 3);
			
			if(GetPlayerSpecialAction(playerid) == SPECIAL_ACTION_USECELLPHONE){
				SetPlayerSpecialAction(playerid, SPECIAL_ACTION_STOPUSECELLPHONE);
			}
			
			return 1;
		}
	}
	return 1;
}

function:OnSuccessCall(playerid)
{
	if(playerid != INVALID_PLAYER_ID){
		PlayNearbySound(playerid, 23000);
		ShowPhone(playerid, 4);
		return 1;
	}
	
	return 0;
}

function:OnPhoneSMS(playerid, type, playerb)
{
	switch(type)
	{
		case 1:
		{
			SendClientMessage(playerid, COLOR_GREY, "[ ! ] Your text failed to deliver."); 
			playerText[playerid] = 0;
			return 1; 
		}
		case 2:
		{
			SendClientMessage(playerid, COLOR_GREY, "[ ! ] Your text failed to deliver."); 
			playerText[playerid] = 0;
			return 1;
		}
		case 3:
		{
			if(!IsPlayerConnected(playerb))
			{
				SendClientMessage(playerid, COLOR_GREY, "[ ! ] Your text failed to deliver."); 
				playerText[playerid] = 0;
				return 1;
			}
			
			SendClientMessage(playerid, COLOR_GREY, "[ ! ] Your text message delivered."); 
			
			if(strlen(playerSMS[playerid]) > 64)
			{
				SendClientMessageEx(playerb, COLOR_WHITE, "SMS From: {a0d0ff}%i", PlayerInfo[playerid][E_CHARACTER_PHONE]); 
				SendClientMessageEx(playerb, COLOR_WHITE, "Messages: {a0d0ff}%.64s...", playerSMS[playerid]); 
				SendClientMessageEx(playerb, COLOR_WHITE, "Messages: {a0d0ff}...%s", playerSMS[playerid][64]); 
			}
			else 
			{
				SendClientMessageEx(playerb, COLOR_WHITE, "SMS From: {a0d0ff}%i", PlayerInfo[playerid][E_CHARACTER_PHONE]); 
				SendClientMessageEx(playerb, COLOR_WHITE, "Messages: {a0d0ff}%s", playerSMS[playerid]);
			}
			playerText[playerid] = 0;
			return 1;
		}
	}
	return 1;
}

GetNumberOwner(number)
{
	foreach (new i : Player) if (PlayerInfo[i][E_CHARACTER_PHONE] == number && PlayerHasItem(i, "Cellphone")) {
		return i;
	}
	return INVALID_PLAYER_ID;
}

function:LoadPlayerContacts(playerid)
{
	new rows, fields;
	cache_get_row_count(rows);
	cache_get_field_count(fields);

	for (new i = 0; i < rows && i < MAX_CONTACTS; i ++) 
	{
		cache_get_value_name(i, "E_CONTACT_NAME", ContactInfo[playerid][i][E_CONTACT_NAME], 32);

		ContactInfo[playerid][i][E_CONTACT_EXISTS] = true;
		cache_get_value_name_int(i, "E_CONTACT_DBID", ContactInfo[playerid][i][E_CONTACT_DBID]);
		cache_get_value_name_int(i, "E_CONTACT_NUMBER", ContactInfo[playerid][i][E_CONTACT_NUMBER]);
	}
	printf("[SERVER]: %s contacts were loaded from \"%s\" database...", ReturnName(playerid), SQL_DATABASE);
	return 1;
}

function:OnContactAdd(playerid, id)
{
	ContactInfo[playerid][id][E_CONTACT_DBID] = cache_insert_id();
	return 1;
}

stock ShowContacts(playerid)
{
	new
	    string[32 * MAX_CONTACTS],
		count = 0;

	string = "Add Contact\n";

	for (new i = 0; i != MAX_CONTACTS; i ++) if (ContactInfo[playerid][i][E_CONTACT_EXISTS]) {
	    format(string, sizeof(string), "%s%s\t#%d\n", string, ContactInfo[playerid][i][E_CONTACT_NAME], ContactInfo[playerid][i][E_CONTACT_NUMBER]);

		ListedContacts[playerid][count++] = i;
	}
	ShowPlayerDialog(playerid, DIALOG_CONTACTS, DIALOG_STYLE_TABLIST, "My Contacts:", string, "Select", "Back");
	return 1;
}

stock ShowPhone(playerid, type)
{
	PlayerTextDrawShow(playerid, phone[0][playerid]);
	PlayerTextDrawShow(playerid, phone[1][playerid]);
	PlayerTextDrawShow(playerid, phone[2][playerid]);
	PlayerTextDrawShow(playerid, phone[3][playerid]);
	PlayerTextDrawShow(playerid, phone[4][playerid]);
	PlayerTextDrawShow(playerid, phone[5][playerid]);
	PlayerTextDrawShow(playerid, phone[6][playerid]);
	PlayerTextDrawShow(playerid, phone[7][playerid]);
	PlayerTextDrawShow(playerid, phone[8][playerid]);

	switch(type)
	{
		case 0:
			PlayerTextDrawSetString(playerid, phone[7][playerid], "");
		case 1:
			PlayerTextDrawSetString(playerid, phone[7][playerid], "Calling...");
		case 2:
			PlayerTextDrawSetString(playerid, phone[7][playerid], "Rings...");
		case 3:
			PlayerTextDrawSetString(playerid, phone[7][playerid], "Busy...");
		case 4:
			PlayerTextDrawSetString(playerid, phone[7][playerid], "Connected...");
	}
	return 1;
}

stock HidePhone(playerid)
{
	PlayerTextDrawHide(playerid, phone[0][playerid]);
	PlayerTextDrawHide(playerid, phone[1][playerid]);
	PlayerTextDrawHide(playerid, phone[2][playerid]);
	PlayerTextDrawHide(playerid, phone[3][playerid]);
	PlayerTextDrawHide(playerid, phone[4][playerid]);
	PlayerTextDrawHide(playerid, phone[5][playerid]);
	PlayerTextDrawHide(playerid, phone[6][playerid]);
	PlayerTextDrawHide(playerid, phone[7][playerid]);
	PlayerTextDrawHide(playerid, phone[8][playerid]);
	return 1;
}