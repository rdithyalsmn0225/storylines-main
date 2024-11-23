new PlayerActor[MAX_PLAYERS];

CreatePlayerActor(playerid, skin)
{
	new vwid = AccountInfo[playerid][E_MASTERS_DBID];

	if(IsValidDynamicActor(PlayerActor[playerid]))
		DestroyDynamicActor(PlayerActor[playerid]);

	PlayerActor[playerid] = CreateDynamicActor(skin, 1341.3151,890.9318,131.1577,356.6866); //hood
	ApplyDynamicActorAnimation(PlayerActor[playerid], "DEALER", "DEALER_IDLE", 4.1, 1, 0, 0, 0, 0);
	SetDynamicActorVirtualWorld(PlayerActor[playerid], vwid);
	return 1;
}

DestroyPlayerActor(playerid)
{
	DestroyDynamicActor(PlayerActor[playerid]);
	return 1;
}