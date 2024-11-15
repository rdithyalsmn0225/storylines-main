
function:GarbageTimers()
{
    GarbageCount = 0;
    for (new i = 0; i < sizeof(Garbage_Locations); i++) {
        if (GarbageCount >= MAX_GARBAGE) break;
        
        new Float:x = Garbage_Locations[i][0];
        new Float:y = Garbage_Locations[i][1];
        new Float:z = Garbage_Locations[i][2];
        new Float:rx = Garbage_Locations[i][3];
        new Float:ry = Garbage_Locations[i][4];
        new Float:rz = Garbage_Locations[i][5];

        GarbageObject[GarbageCount] = CreateDynamicObject(2672, x, y, z, rx, ry, rz, -1, -1, -1, 800.0, 800.0);
        GarbageCount++;
    }
    return 1;
}

stock CollectGarbage(playerid) 
{
    new Float:x, Float:y, Float:z;
    GetPlayerPos(playerid, x, y, z);

    for (new i = 0; i < GarbageCount; i++) 
    {
        if (IsValidDynamicObject(GarbageObject[i])) 
        {
            new Float:gx, Float:gy, Float:gz;
            GetDynamicObjectPos(GarbageObject[i], gx, gy, gz);

            if (GetDistanceBetweenPoints(x, y, z, gx, gy, gz) <= 2.0) 
            { 
                DestroyDynamicObject(GarbageObject[i]);
                GarbageObject[i] = INVALID_OBJECT_ID;

                PlayerInfo[playerid][E_CHARACTER_GARBAGEMAN_VALUE]++;

                if(PlayerInfo[playerid][E_CHARACTER_GARBAGEMAN_VALUE] >= 30)
                    return SendTipMessage(playerid, "Your garbage bag is full, take it to the HQ and empty it");

                ApplyAnimation(playerid, "BOMBER", "BOM_Plant", 4.1, 0, 0, 0, 0, 0, 0);
                SendServerMessage(playerid, "[Garbageman] {cdd0d1}You've picked up rubbish, current garbage bag {d7d292}%d{cdd0d1} x rubbish.", PlayerInfo[playerid][E_CHARACTER_GARBAGEMAN_VALUE]);
                SendTipMessage(playerid, "You can empty your garbage bag in HQ by type '/dumpgarbage'");
                return 1;
            }
        }
    }
    return 1;
}

CMD:collectgarbage(playerid, params[])
{
    if(PlayerInfo[playerid][E_CHARACTER_GARBAGEMAN])
    {
        CollectGarbage(playerid);
    }
    return 1;
}

CMD:dumpgarbage(playerid, params[])
{
    if(PlayerInfo[playerid][E_CHARACTER_GARBAGEMAN])
    {
        if(PlayerInfo[playerid][E_CHARACTER_GARBAGEMAN_VALUE])
        {
            new total = (PlayerInfo[playerid][E_CHARACTER_GARBAGEMAN_VALUE] * GARBAGEMAN_SALARY);

            new Cents = floatround(total * 100, floatround_round);

	        GiveMoney(playerid, Cents);
            SendServerMessage(playerid, "[Garbageman] {cdd0d1}You've empty your garbage bag, current garbage bag {d7d292}%d{cdd0d1} x rubbish and earn {93C47D}$%s{cdd0d1}.", PlayerInfo[playerid][E_CHARACTER_GARBAGEMAN_VALUE], FormatMoney(Cents));
            PlayerInfo[playerid][E_CHARACTER_GARBAGEMAN_VALUE] = 0;
        }
    }
    return 1;
}

CMD:garbage(playerid, params[])
{
    if(PlayerInfo[playerid][E_CHARACTER_GARBAGEMAN])
    {
        ShowGarbageLocation(playerid);
    }
    return 1;
}