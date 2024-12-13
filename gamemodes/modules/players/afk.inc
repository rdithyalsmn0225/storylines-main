AFKCheck(playerid)
{
	new
	    Float:x,
	    Float:y,
	    Float:z,
	    Float:cx,
	    Float:cy,
	    Float:cz;

	GetPlayerPos(playerid, x, y, z);
	GetPlayerCameraPos(playerid, cx, cy, cz);

	if(PlayerInfo[playerid][E_CHARACTER_AFKPOS][0] == x && PlayerInfo[playerid][E_CHARACTER_AFKPOS][1] == y && PlayerInfo[playerid][E_CHARACTER_AFKPOS][2] == z && PlayerInfo[playerid][E_CHARACTER_AFKPOS][3] == cx && PlayerInfo[playerid][E_CHARACTER_AFKPOS][4] == cy && PlayerInfo[playerid][E_CHARACTER_AFKPOS][5] == cz)
	{
		PlayerInfo[playerid][E_CHARACTER_AFKTIME]++;

	    if(!PlayerInfo[playerid][E_CHARACTER_AFK] && PlayerInfo[playerid][E_CHARACTER_AFKTIME] >= 60)
	    {
			new str[64];
	    	format(str, sizeof(str), "[PAUSED]", PlayerInfo[playerid][E_CHARACTER_AFKTIME]);
	    	SetPlayerChatBubble(playerid, str, COLOR_RED, 3.0, 10000);
			
		    SendServerMessage(playerid, "[AFK] {cdcdcd}You are now marked as away from keyboard as you haven't moved in one minute.");
		    PlayerInfo[playerid][E_CHARACTER_AFK] = 1;
		}
	}
	else
	{
		if(PlayerInfo[playerid][E_CHARACTER_AFK])
		{
		    if(PlayerInfo[playerid][E_CHARACTER_AFKTIME] < 120) 
		    {
		    	SendServerMessage(playerid, "[AFK] {cdcdcd}You are no longer marked as away from keyboard after %d seconds.", PlayerInfo[playerid][E_CHARACTER_AFKTIME]);
			} 
			else 
			{
			    SendServerMessage(playerid, "[AFK] {cdcdcd}You are no longer marked as away from keyboard after %d minutes.", PlayerInfo[playerid][E_CHARACTER_AFKTIME] / 60);
			}
			PlayerInfo[playerid][E_CHARACTER_AFK] = 0;
		}

		PlayerInfo[playerid][E_CHARACTER_AFKTIME] = 0;
	}

	PlayerInfo[playerid][E_CHARACTER_AFKPOS][0] = x;
	PlayerInfo[playerid][E_CHARACTER_AFKPOS][1] = y;
	PlayerInfo[playerid][E_CHARACTER_AFKPOS][2] = z;
	PlayerInfo[playerid][E_CHARACTER_AFKPOS][3] = cx;
	PlayerInfo[playerid][E_CHARACTER_AFKPOS][4] = cy;
	PlayerInfo[playerid][E_CHARACTER_AFKPOS][5] = cz;
}

CMD:afklist(playerid, params[])
{
	if(IsPlayerAdmins(playerid) < ADMINS_HIGH)
	    return 0;

	SendClientMessage(playerid, COLOR_DARKGREEN, "|__________ AFK List __________|");

	foreach(new i : Player)
	{
	    if(PlayerInfo[i][E_CHARACTER_AFK])
	    {
	        SendClientMessageEx(playerid, COLOR_ORANGE, "(ID: %i) %s - Time: %i seconds", i, ReturnName(i, i), PlayerInfo[i][E_CHARACTER_AFKTIME]);
		}
	}

	return 1;
}