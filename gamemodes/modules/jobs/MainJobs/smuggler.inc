// Smugglers:
new TrackPackets[MAX_PLAYERS];

IsPlayerTakePacket()
{
    new found = 0;
    foreach(new i : Player)
    {
        if(PlayerInfo[i][E_CHARACTER_TAKEPACKET] == true)
        {
            found++;
        }
    }
    if(found) return 1;
    else return 0;
}

function:InsertPacket(Float:x, Float:y, Float:z)
{
    if(IsValidDynamic3DTextLabel(packetLabel))
        DestroyDynamic3DTextLabel(packetLabel);

    if(IsValidDynamicObject(packetObject))
        DestroyDynamicObject(packetObject), packetObject = INVALID_OBJECT_ID;

    packetpos[0] = x;
    packetpos[1] = y;
    packetpos[2] = z;
    packetObject = CreateDynamicObject(11745, x, y, z, 0, 0, 0, -1, -1, -1);
    packetLabel = CreateDynamic3DTextLabel("[Smugglers Packet]\n{ffffff}Press 'ALT' to pickup packet", COLOR_3DTEXT, x, y, z+0.3, 10.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, -1, -1, -1);
    return 1;
}

function:OnPlayerPacketUpdate()
{
    if(!IsPlayerTakePacket())
    {
        new rand = random(sizeof(RandomPacketPos));
        InsertPacket(RandomPacketPos[rand][0], RandomPacketPos[rand][1], RandomPacketPos[rand][2]);
        foreach(new p : Player) if(PlayerInfo[p][E_CHARACTER_JOBS] == JOB_SMUGGLER)
        {
            SendClientMessage(p, COLOR_DARKGREEN, "[Word on the Streetz] Smuggler packet has been spawned '/findpacket' to track packet");
        }
    }
}

CMD:findpacket(playerid, params[])
{
    if(PlayerInfo[playerid][E_CHARACTER_JOBS] != JOB_SMUGGLER) 
        return SendErrorMessage(playerid, "You aren't smugglers.");
    
    if(TrackPackets[playerid] >= gettime()) return SendErrorMessage(playerid, "You've only been track packet for %i seconds. You need to wait at least 10 sec to track again.", gettime() - TrackPackets[playerid]);

    new Float:x, Float:y, Float:z, found;
    foreach(new i : Player)
    {
        if(PlayerInfo[i][E_CHARACTER_TAKEPACKET] == true)
        {
            GetPlayerPos(i, x, y, z);
            found++;
        }
    }
    
    if(found)
    {
        SetPlayerCheckpoint(playerid, x, y, z, 3.0);
        SendServerMessage(playerid, "[Smugglers] {DEDEDE}Packet status has taken by another player at %s.", GetZoneName(x, y, z));
        SendTipMessage(playerid, "Type '/findpacket' to track packet.");
    }
    else if(packetpos[0] != 0.0 && packetpos[1] != 0.0)
    {
        GPS_SetPlayerRaceCheckPoint(playerid, 1, packetpos[0], packetpos[1], packetpos[1], 0.0, 0.0, 0.0);
        SendServerMessage(playerid, "[Smugglers] {DEDEDE}Packet status is still idle at %s.", GetZoneName(packetpos[0], packetpos[1], packetpos[1]));
        SendTipMessage(playerid, "Press 'ALT' to pickup packet.");
    }
    else if(packetpos[0] == 0.0 && packetpos[1] == 0.0) return SendErrorMessage(playerid, "Packet has not spawned at this time.");
    TrackPackets[playerid] = gettime() + 10;
    return 1;
}

CMD:afindpacket(playerid, params[])
{
    if(IsPlayerAdmins(playerid) < ADMINS_HIGH) return 0;
    
    new Float:x, Float:y, Float:z, found;
    foreach(new i : Player)
    {
        if(PlayerInfo[i][E_CHARACTER_TAKEPACKET] == true)
        {
            GetPlayerPos(i, x, y, z);
            found++;
        }
    }
    
    if(found)
    {
        SetPlayerCheckpoint(playerid, x, y, z, 3.0);
        SendServerMessage(playerid, "[Smugglers] {DEDEDE}Packet status has taken by another player at %s.", GetZoneName(x, y, z));
    }
    else if(packetpos[0] != 0.0 && packetpos[1] != 0.0)
    {
        GPS_SetPlayerRaceCheckPoint(playerid, 1, packetpos[0], packetpos[1], packetpos[1], 0.0, 0.0, 0.0);
        SendServerMessage(playerid, "[Smugglers] {DEDEDE}Packet status is still idle at %s.", GetZoneName(packetpos[0], packetpos[1], packetpos[1]));
    }
    else if(packetpos[0] == 0.0 && packetpos[1] == 0.0) return SendErrorMessage(playerid, "Packet has not spawned at this time.");
    TrackPackets[playerid] = gettime() + 10;
    return 1;
}

CMD:respawnpacket(playerid)
{
    if(IsPlayerAdmins(playerid) < ADMINS_OPERATOR) return 0;

    new rand = random(sizeof(RandomPacketPos));
    InsertPacket(RandomPacketPos[rand][0], RandomPacketPos[rand][1], RandomPacketPos[rand][2]);

    foreach(new p : Player) if(PlayerInfo[p][E_CHARACTER_JOBS] == JOB_SMUGGLER)
    {   
        SendClientMessage(p, COLOR_DARKGREEN, "[Word on the Streetz] Smuggler packet has been spawned '/findpacket' to track packet");
    }

    new str[128];
    format(str, sizeof(str), "%s has been spawned smuggler packet.", ReturnName(playerid));
    SendAdminMessage(3, str);
    return 1;
}

CMD:storepacket(playerid, params[])
{
	if(PlayerInfo[playerid][E_CHARACTER_JOBS] != JOB_SMUGGLER) 
        return SendErrorMessage(playerid, "You aren't smugglers.");

	if(IsPlayerInRangeOfPoint(playerid, 3.0, 122.0707,-319.1785,1.5781) )
    {
        if(PlayerInfo[playerid][E_CHARACTER_TAKEPACKET] == false) return SendErrorMessage(playerid, "You are not carrying your packet.");
	
        ApplyAnimation(playerid,"BOMBER","BOM_Plant",4.0,0 ,0,0,0,0,1);
        new bonus = randomEx(150, 250);
        new price = bonus+2;

        new rand = randomEx(3, 5);

        new Cents = floatround(price * 100, floatround_round);

	    GiveMoney(playerid, Cents);
        RemovePlayerAttachedObject(playerid, ATTACH_HAND);
        DisablePlayerCheckpoint(playerid);

        ServerData_Plus(INDUSTRY_DRUGS, rand);

        SendServerMessage(playerid, "[Smugglers] {DEDEDE}You has stored packet and earn $%s", FormatMoney(Cents));

        PlayerInfo[playerid][E_CHARACTER_TAKEPACKET] = false;
    } 
    if(IsPlayerInRangeOfPoint(playerid, 3.0, -576.3427,-505.8364,25.5234))
    {
        if(PlayerInfo[playerid][E_CHARACTER_TAKEPACKET] == false) return SendErrorMessage(playerid, "You are not carrying your packet.");
	
        ApplyAnimation(playerid,"BOMBER","BOM_Plant",4.0,0 ,0,0,0,0,1);
        new bonus = randomEx(800, 1000);
        new price = bonus+2;
        new rand = randomEx(3, 5);

        new Cents = floatround(price * 100, floatround_round);

	    GiveMoney(playerid, Cents);
        RemovePlayerAttachedObject(playerid, ATTACH_HAND);
        DisablePlayerCheckpoint(playerid);

        ServerData_Plus(INDUSTRY_MATERIALS, rand);

        SendServerMessage(playerid, "[Smugglers] {DEDEDE}You has stored packet and earn $%s", FormatMoney(Cents));

        PlayerInfo[playerid][E_CHARACTER_TAKEPACKET] = false;
    }
	
	return 1;
}

CMD:droppacket(playerid, params[])
{
    new Float:x, Float:y, Float:z;
	GetPlayerPos(playerid, x, y, z);

    if(PlayerInfo[playerid][E_CHARACTER_JOBS] != JOB_SMUGGLER) 
        return SendErrorMessage(playerid, "You aren't smugglers.");

	if(PlayerInfo[playerid][E_CHARACTER_TAKEPACKET] == true)
	{
		PlayerInfo[playerid][E_CHARACTER_TAKEPACKET] = false;
		InsertPacket(x, y, z-1);
		foreach(new p : Player) if(PlayerInfo[p][E_CHARACTER_JOBS] == JOB_SMUGGLER)
		{
			SendClientMessage(p, COLOR_DARKGREEN, "[Word on the Streetz] Smuggler packet has been spawned '/findpacket' to track packet");
		}
	}
    RemovePlayerAttachedObject(playerid, ATTACH_HAND);
    return 1;
}