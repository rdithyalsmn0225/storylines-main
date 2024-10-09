stock SetPlayerInPrison(playerid)
{
	SetPlayerPosEx(playerid, 264.4271,78.0998,1001.0391);
	SetPlayerFacingAngle(playerid, 280.6937);

	SetPlayerInterior(playerid, 6);
	SetPlayerVirtualWorld(playerid, 0);

	PlayerInfo[PlayerInfo[playerid][E_CHARACTER_MDCSELECT]][E_CHARACTER_PRISON] = true;
	PlayerInfo[PlayerInfo[playerid][E_CHARACTER_MDCSELECT]][E_CHARACTER_PRISON] = PlayerInfo[playerid][E_CHARACTER_MDCTIME] * 60;
	SaveCharacter(playerid);
	return 1;
}