// Taxi:
IsPlayerInsideTaxi(playerid)
{
	new vehicleid = GetPlayerVehicleID(playerid);

	if (GetVehicleModel(vehicleid) == 420 || GetVehicleModel(vehicleid) == 438)
	{
	    foreach (new i : Player)
		{
			if ((i != playerid) && (PlayerInfo[i][E_CHARACTER_JOBS] == JOB_TAXI && PlayerInfo[i][E_CHARACTER_TAXIDUTY] && GetPlayerState(i) == PLAYER_STATE_DRIVER) && GetPlayerVehicleID(i) == vehicleid)
				return 1;
		}
	}
	return 0;
}

stock Taxi_ShowCalls(playerid)
{
    static
	    string[2048];

	string[0] = 0;

	foreach (new i : Player) if (PlayerInfo[i][E_CHARACTER_TAXICALLED]) {
	    format(string, sizeof(string), "%s%d: %s\t%s\t%s\n", string, i, ReturnSettingsName(i, playerid), ReturnLocation(i), ReturnLocationStreet(i));
	}
	if (!strlen(string)) {
	    SendErrorMessage(playerid, "There are no taxi calls to accept.");
	}
	else Dialog_ShowPages(playerid, AcceptTaxi, DIALOG_STYLE_TABLIST, "Taxi Calls:", string, "Accept", "Cancel");
	return 1;
}

stock LeaveTaxi(playerid, driverid)
{
	if (driverid != INVALID_PLAYER_ID && IsPlayerConnected(driverid))
	{
	    GiveMoney(playerid, -PlayerInfo[playerid][E_CHARACTER_TAXIFARE]);
   		GiveMoney(driverid, PlayerInfo[playerid][E_CHARACTER_TAXIFARE]);

        SendServerMessage(driverid, "TAXI: {ffffff}%s has exit your taxi and paid {5B9460}$%d{ffffff}.", ReturnSettingsName(playerid, driverid), PlayerInfo[playerid][E_CHARACTER_TAXIFARE]);
		SendNearbyMessage(playerid, 30.0, COLOR_EMOTE, "** %s has paid $%d to the taxi driver.", ReturnSettingsName(playerid, driverid), PlayerInfo[playerid][E_CHARACTER_TAXIFARE]);

	    PlayerInfo[playerid][E_CHARACTER_TAXIFARE] = 0;
	    PlayerInfo[playerid][E_CHARACTER_TAXITIMER] = 0;
	    PlayerInfo[playerid][E_CHARACTER_TAXIPLAYER] = INVALID_PLAYER_ID;
	}
	return 1;
}

function:TaxiTimers()
{
    foreach(new i : Player)
    {
        if (IsPlayerInsideTaxi(i))
		{
		    PlayerInfo[i][E_CHARACTER_TAXITIMER]++;

		    if (PlayerInfo[i][E_CHARACTER_TAXITIMER] == 3)
		    {
		        PlayerInfo[i][E_CHARACTER_TAXITIMER] = 0;
		        PlayerInfo[i][E_CHARACTER_TAXIFARE] += 1;
		    }
            new str[512];
		    format(str, sizeof(str), "~y~Taxi Fare: ~g~$%d", PlayerInfo[i][E_CHARACTER_TAXIFARE], PlayerInfo[i][E_CHARACTER_TAXITIMER]);
            ShowBoxMessage(i, str, 5);
            ShowBoxMessage(GetVehicleDriver(GetPlayerVehicleID(i)), str, 5);
		}
    }
}

Dialog:AcceptTaxi(playerid, response, listitem, inputtext[])
{
	if (response)
	{
	    new targetid = strval(inputtext);

	    if (!IsPlayerConnected(targetid))
	        return SendErrorMessage(playerid, "The specified player has disconnected.");

		if (!PlayerInfo[targetid][E_CHARACTER_TAXICALLED])
		    return SendErrorMessage(playerid, "That player's call was accepted by another taxi driver.");

		static
			Float:x,
			Float:y,
			Float:z;

		GetPlayerPos(targetid, x, y, z);

		PlayerInfo[targetid][E_CHARACTER_TAXICALLED] = 0;
		GPS_SetPlayerRaceCheckPoint(playerid, 1, x, y, z, 0.0, 0.0, 0.0);

        SendServerMessage(playerid, "TAXI: {ffffff}You have accepted %s's taxi call.", ReturnSettingsName(targetid, playerid));
        SendServerMessage(targetid, "TAXI: {ffffff}%s has accepted your taxi call and is on their way.", ReturnSettingsName(playerid, targetid));
	}
	return 1;
}

CMD:taxicall(playerid, params[])
{
    if (PlayerInfo[playerid][E_CHARACTER_JOBS] != JOB_TAXI)
	    return SendErrorMessage(playerid, "You don't have the appropriate job.");

	if (!PlayerInfo[playerid][E_CHARACTER_TAXIDUTY])
	    return SendErrorMessage(playerid, "You must be on taxi duty to accept calls.");

	Taxi_ShowCalls(playerid);
	return 1;
}