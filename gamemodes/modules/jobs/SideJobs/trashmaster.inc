stock CollectGarbage(playerid, trashid) 
{
    TrashInfo[trashid][E_TRASH_CAPACITY]--;
    PlayerInfo[playerid][E_CHARACTER_GARBAGEMAN_VALUE]++;

    if(PlayerInfo[playerid][E_CHARACTER_GARBAGEMAN_VALUE] >= 30)
        return SendTipMessage(playerid, "Your garbage bag is full, take it to the HQ and empty it");

    SetPlayerNeeds(playerid, -0.1, -0.1);

    ApplyAnimation(playerid, "BOMBER", "BOM_Plant", 4.1, 0, 0, 0, 0, 0, 0);
    SendJobsMessage(playerid, "[Garbageman] {DEDEDE}You've picked up rubbish, current garbage bag %d x rubbish.", PlayerInfo[playerid][E_CHARACTER_GARBAGEMAN_VALUE]);
    SendTipMessage(playerid, "You can empty your garbage bag in HQ by type '/dumpgarbage'");
    return 1;
}

CMD:collectgarbage(playerid, params[])
{
    if(PlayerInfo[playerid][E_CHARACTER_GARBAGEMAN])
    {
        if(PlayerInfo[playerid][E_CHARACTER_HUNGRY] < 20 || PlayerInfo[playerid][E_CHARACTER_THIRSTY] < 20)
		    return SendErrorMessage(playerid, "You're hungry or thirsty right now.");

        new id = -1;
        
        if ((id = IsPlayerNearTrashcan(playerid)) != -1)
        { 
            if(!TrashInfo[id][E_TRASH_CAPACITY])
        		return SendErrorMessage(playerid, "Trashcan is empty.");
            
            CollectGarbage(playerid, id);
        }
    }
    return 1;
}

CMD:dumpgarbage(playerid, params[])
{
    if(PlayerInfo[playerid][E_CHARACTER_GARBAGEMAN])
    {
        if(PlayerInfo[playerid][E_CHARACTER_GARBAGEMAN_VALUE])
        {
            new rand = randomEx(3, 5);
            new total = (PlayerInfo[playerid][E_CHARACTER_GARBAGEMAN_VALUE] * rand);

            new Cents = floatround(total * 100, floatround_round);

	        GiveMoney(playerid, Cents);
            SendJobsMessage(playerid, "[Garbageman] {DEDEDE}You've empty your garbage bag, current garbage bag %d x rubbish and earn $%s.", PlayerInfo[playerid][E_CHARACTER_GARBAGEMAN_VALUE], FormatMoney(Cents));
            PlayerInfo[playerid][E_CHARACTER_GARBAGEMAN_VALUE] = 0;
            PlayerInfo[playerid][E_CHARACTER_GARBAGECD] = 10;
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