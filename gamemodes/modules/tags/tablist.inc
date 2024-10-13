



SetPlayerNameForPlayer(playerid, forplayerid, const name[]) 
{
    new BitStream:bs = BS_New();

    BS_WriteValue(
        bs, 
        PR_UINT16, playerid, 
        PR_UINT8, strlen(name), 
        PR_STRING, name, 
        PR_UINT8, 1
    );

    PR_SendRPC(bs, forplayerid, 11);
    BS_Delete(bs);
    return 1;
}

SetPlayerColorForPlayer(playerid, toplayerid, color, bool:force_color=true) {
    new BitStream:bs = BS_New();

    if(!force_color) 
	{
        if(PlayerInfo[playerid][E_CHARACTER_ADMINDUTY]) 
		{
            color = 0xD5A04EFF;
		}
    }

    BS_WriteValue(
        bs,
        PR_UINT16, playerid,
        PR_UINT32, color
    );

    PR_SendRPC(bs, toplayerid, 72);
    BS_Delete(bs);
    return 1;
}

Faction_GetHex(faction_sqlid) 
{

	new factionid = faction_sqlid;

	if(!factionid) 
    {
		return COLOR_GREY;
	}

	if(factionid == -1) 
    {
		return COLOR_GREY;
	}

	return FactionInfo[factionid][E_FACTION_COLORHEX];
}

UpdateTabListForOthers(playerid) 
{
    for(new targetid=GetMaxPlayers()-1; targetid != -1; targetid--) {

        if (!IsPlayerConnected(targetid) || !PlayerInfo[targetid][E_CHARACTER_SPAWNED] || !AccountInfo[targetid][E_MASTERS_LOGGED]) continue;
        UpdateTabList(playerid, targetid);
    }
    return 1;
}


UpdateTabListForPlayer(playerid) 
{
    for(new targetid=GetMaxPlayers()-1; targetid != -1; targetid--) {

        if (!IsPlayerConnected(targetid)  || !PlayerInfo[targetid][E_CHARACTER_SPAWNED] || !AccountInfo[targetid][E_MASTERS_LOGGED]) continue;
        UpdateTabList(targetid, playerid);
    }

    return 1;
}

UpdateTabList(playerid, forplayerid) 
{
    new color = (GetPlayerNametagPreference(forplayerid) ? COLOR_GREY : Faction_GetHex(PlayerInfo[playerid][E_CHARACTER_FACTION]));
    
    if (!IsPlayerConnected(forplayerid)  || !PlayerInfo[forplayerid][E_CHARACTER_SPAWNED] || !AccountInfo[forplayerid][E_MASTERS_LOGGED]) {
        return 1;
    }

    new title[64];

    SetPlayerNameForPlayer(playerid, forplayerid, (strlen(title) > 0) ? title : ReturnSettingsName(playerid, forplayerid));
    SetPlayerColorForPlayer(playerid, forplayerid, color, .force_color=false); 
    return 1;
}

UpdateNametagsTick(playerid) {
    for(new targetid=GetMaxPlayers()-1; targetid != -1; targetid--) {
        if (!IsPlayerConnected(targetid)  || !PlayerInfo[targetid][E_CHARACTER_SPAWNED] || !AccountInfo[targetid][E_MASTERS_LOGGED]) continue;
        UpdateTabList(playerid, targetid);
    }
    return 1;
}