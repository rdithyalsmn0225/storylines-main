new BackupCheckpoint[MAX_PLAYERS],
    BackupFlare[MAX_PLAYERS],
    Float: BackupPosX, 
    Float: BackupPosY, 
    Float: BackupPosZ;

stock RequestPoliceBackup(playerid)
{
    if (ReturnFactionType(playerid) != FACTION_TYPE_POLICE || !IsPoliceVehicle(GetPlayerVehicleID(playerid)) && BackupCheckpoint[playerid])
		return 0;

    GetPlayerPos(playerid, BackupPosX, BackupPosY, BackupPosZ);

    foreach (new i : Player)
    {
        if (ReturnFactionType(i) == FACTION_TYPE_POLICE)
        {
            GPS_SetPlayerRaceCheckPoint(i, 1, BackupPosX, BackupPosY, BackupPosZ, 0.0, 0.0, 0.0);
            BackupCheckpoint[i] = 1; 
            SendPoliceMessage(COLOR_COP, "** HQ: %s has send backup request!.", ReturnName(playerid, 0));
        }
    }

    BackupFlare[playerid] = CreateDynamicObject(1225, BackupPosX, BackupPosY, BackupPosZ + 1.0, 0.0, 0.0, 0.0, -1, -1, -1, 300.0);
    SendServerMessage(playerid, "[Backup] {cdd0d1}Backup requested!.");

    SetTimerEx("ClearBackup", 600000, false, "i", playerid);
    return 1;
}

function:ClearBackup(playerid)
{
    foreach (new i : Player)
    {
        if (BackupCheckpoint[i] == 1)
        {
            DisablePlayerCheckpoint(i);
            BackupCheckpoint[i] = 0;
        }
    }

    if (BackupFlare[playerid] != INVALID_OBJECT_ID)
    {
        DestroyDynamicObject(BackupFlare[playerid]);
        BackupFlare[playerid] = INVALID_OBJECT_ID;
    }

    SendServerMessage(playerid, "[Backup] {cdd0d1}Backup has been cleared.");
    return 1;
}