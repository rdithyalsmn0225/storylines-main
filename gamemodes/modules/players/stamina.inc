//Running Stamina
stock IsPlayerRunning(playerid) // Check if the player is running
{
    if(!IsPlayerConnected(playerid) || IsPlayerInAnyVehicle(playerid || IsPlayerExhausted(playerid))) return 0;

    new keys, updown, leftright;
    GetPlayerKeys(playerid, keys, updown, leftright);
    if(keys & KEY_SPRINT && GetPlayerSpecialAction(playerid) != SPECIAL_ACTION_USEJETPACK) return 1;
    else return 0;
}

stock IsPlayerExhausted(playerid) // Check if the player is exhausted
{
	if(GetPVarInt(playerid, "Exhausted") == 1) return true;
	else return false;
}

function:SetPlayerExhausted(playerid, bool:Exhausted)  // If true the player will do the recovery animation for the time set by #define STAMINA_DEFAULT_RECOVERYTIME
{
	if(Exhausted) 
	{
		TogglePlayerControllable(playerid, false);
		TogglePlayerControllable(playerid, true);
        PlayerInfo[playerid][E_CHARACTER_STAMINA] = 250;

		ApplyAnimation(playerid, "FAT", "IDLE_tired", 4.1, 0, 1, 1, 0, 4000, 1);

		SetPVarInt(playerid, "Exhausted", 1);
		SetTimerEx("SetPlayerExhausted", 2000, false, "ib", playerid, false);
	}
	else SetPVarInt(playerid, "Exhausted", 0), ClearAnimations(playerid);
	return 1;
}