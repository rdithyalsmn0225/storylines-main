new PlayerActor[MAX_PLAYERS];

CreatePlayerActor(playerid, skin)
{
	new vwid = AccountInfo[playerid][E_MASTERS_DBID];

	if(IsValidDynamicActor(PlayerActor[playerid]))
		DestroyDynamicActor(PlayerActor[playerid]);

	PlayerActor[playerid] = CreateDynamicActor(skin, 1673.8185,-2325.6941,-2.6797,271.9806); //hood
	ApplyDynamicActorAnimation(PlayerActor[playerid], "DEALER", "DEALER_IDLE", 4.1, 1, 0, 0, 0, 0);
	SetDynamicActorVirtualWorld(PlayerActor[playerid], vwid);
	return 1;
}

DestroyPlayerActor(playerid)
{
	DestroyDynamicActor(PlayerActor[playerid]);
	return 1;
}