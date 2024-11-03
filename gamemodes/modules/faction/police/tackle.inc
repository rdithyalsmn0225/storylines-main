CMD:tackle(playerid, params[])
{
	if(!IsPlayerFaction(playerid))
		return SendErrorMessage(playerid, "You aren't in any faction.");

    if(ReturnFactionType(playerid) != FACTION_TYPE_POLICE)
	    return SendErrorMessage(playerid, "You can't use this command."); 

	if(TackleMode[playerid])
	{
	    TackleMode[playerid] = false;

	    SendServerMessage(playerid, "[Tackle] {cdd0d1}Tackling mode has been disabled.");
	    return 1;
	}

	TackleMode[playerid] = true;

	SendServerMessage(playerid, "[Tackle] {cdd0d1}Tackling mode has been enabled.");

	SendTipMessage(playerid, "If you punch someone, a tackle attempt will be registered.");
	SendTipMessage(playerid, "The player you hit will have a message flashed to them indicating that a tackle has been attempted.");
	SendTipMessage(playerid, "An automated emote will be sent in the chat that notifies the other players of the attempt.");
	SendTipMessage(playerid, "You will be forced into a diving animation to prevent misuse of the command.");
	SendTipMessage(playerid, "If a player doesn't role-play the tackle, make a report in-game.");
	return 1;
}

function:TackleModes(playerid)
{
	ApplyAnimationEx(playerid, "ped", "EV_dive", 4.1, 0, 0, 0, 0, 0);
	return 1;
}

TacklePlayer(playerid, victimid)
{
	ApplyAnimationEx(victimid, "PED", "BIKE_fall_off", 4.1, 0, 1, 1, 1, 0);

 	SendNearbyMessage(playerid, 20.0, COLOR_EMOTE, "* %s runs at %s and tries to tackle them to the ground.", ReturnName(playerid, victimid), ReturnName(victimid, playerid));
	
	ShowBoxMessage(victimid, "~r~YOU HAVE BEEN TACKLED.", 5);
	return 1;
}