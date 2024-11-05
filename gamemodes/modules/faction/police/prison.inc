stock SetPlayerInPrison(playerid)
{
	PlayerInfo[PlayerInfo[playerid][E_CHARACTER_MDCSELECT]][E_CHARACTER_PRISON] = true;
	PlayerInfo[PlayerInfo[playerid][E_CHARACTER_MDCSELECT]][E_CHARACTER_PRISON] = PlayerInfo[playerid][E_CHARACTER_MDCTIME] * 60;
	SaveCharacter(playerid);
	ResetPlayerWeaponEx(playerid);
	return 1;
}


CreatePrisonCell(objectid)
{
    for(new i = 0; i < MAX_PRISON_CELLS; i++)
    {   
        if(!PrisonCells[i][E_CELL_EXISTS])
        {
            PrisonCells[i][E_CELL_EXISTS] = true;
            PrisonCells[i][E_CELL_OBJECT] = objectid;
            PrisonCells[i][E_CELL_CLOSED] = true;
            PrisonCells[i][E_CELL_LOCKED] = false;

            GetDynamicObjectPos(PrisonCells[i][E_CELL_OBJECT], PrisonCells[i][E_CELL_POS][0], PrisonCells[i][E_CELL_POS][1], PrisonCells[i][E_CELL_POS][2]);   
            return true;
        }
    }
    return 1;
}

stock OpenPrisonCell(id)
{
    if(!PrisonCells[id][E_CELL_CLOSED]) return 1;

    PrisonCells[id][E_CELL_CLOSED] = false;

    if((id >= 0 && id <= 4) || (id >= 9 && id <= 13))
    {
        MoveDynamicObject(PrisonCells[id][E_CELL_OBJECT], PrisonCells[id][E_CELL_POS][0] - 1.4, PrisonCells[id][E_CELL_POS][1], PrisonCells[id][E_CELL_POS][2], 1.7, 0.0, 0.0, 0.0);
    }
    else
    {
        MoveDynamicObject(PrisonCells[id][E_CELL_OBJECT], PrisonCells[id][E_CELL_POS][0], PrisonCells[id][E_CELL_POS][1] - 1.4, PrisonCells[id][E_CELL_POS][2], 1.7, 0.0, 0.0, 90.0);
    }
    return 1;
}

stock ClosePrisonCell(id)
{
    if(PrisonCells[id][E_CELL_CLOSED]) return 1;

    PrisonCells[id][E_CELL_CLOSED] = true;

    if((id >= 0 && id <= 4) || (id >= 9 && id <= 13))
    {
        MoveDynamicObject(PrisonCells[id][E_CELL_OBJECT], PrisonCells[id][E_CELL_POS][0], PrisonCells[id][E_CELL_POS][1], PrisonCells[id][E_CELL_POS][2], 1.7, 0.0, 0.0, 0.0);
    }
    else
    {
        MoveDynamicObject(PrisonCells[id][E_CELL_OBJECT], PrisonCells[id][E_CELL_POS][0], PrisonCells[id][E_CELL_POS][1], PrisonCells[id][E_CELL_POS][2], 1.7, 0.0, 0.0, 90.0);
    }
    return 1;
}

CMD:opencells(playerid, params[])
{
	if (!IsPlayerInRangeOfPoint(playerid, 4.0, 1256.9117,890.3147,1161.0986))
	    return SendErrorMessage(playerid, "You aren't in los santos correctional facility.");

    for(new i = 0; i < MAX_PRISON_CELLS; i++)
    {   
        OpenPrisonCell(i);
    }
    return 1;
}

CMD:closecells(playerid, params[])
{
	if (!IsPlayerInRangeOfPoint(playerid, 4.0, 1256.9117,890.3147,1161.0986))
	    return SendErrorMessage(playerid, "You aren't in los santos correctional facility.");
		
    for(new i = 0; i < MAX_PRISON_CELLS; i++)
    {   
        ClosePrisonCell(i);
    }
    return 1;
}

CMD:charge(playerid, params[])
{
	new
	    userid;

    if(!PlayerInfo[playerid][E_CHARACTER_FACTION])
		return SendErrorMessage(playerid, "You aren't in any faction.");
		
	if(FactionInfo[PlayerInfo[playerid][E_CHARACTER_FACTION]][E_FACTION_TYPE] != FACTION_TYPE_POLICE)
		return SendErrorMessage(playerid, "You can't use this command."); 

	if(sscanf(params, "u", userid))
		return SendUsageMessage(playerid, "/charge [playerid OR name]"); 

	if (!IsPlayerNearPlayer(playerid, userid, 10.0))
	    return SendErrorMessage(playerid, "The player is disconnected or not near you.");

	if (!PlayerInfo[userid][E_CHARACTER_HANDCUFF])
	    return SendErrorMessage(playerid, "The player must be cuffed before an arrest is made.");

	if (!IsPlayerInRangeOfPoint(playerid, 4.0, 1256.9117,890.3147,1161.0986))
	    return SendErrorMessage(playerid, "You aren't in los santos correctional facility.");

	PlayerInfo[playerid][E_CHARACTER_MDCSELECT] = userid;

	new str[2048];
	strcat(str, "Description\n");
	forex(i, sizeof(PenalInfo)){
		format(str, sizeof(str), "%s%s\n", str, PenalInfo[i][E_PENALCODES_TYPE]);
    }
	Dialog_ShowPages(playerid, Charges, DIALOG_STYLE_TABLIST_HEADERS, "State Penal Code (Arrest Offesenses):", str, "Select", "Cancel");
    return 1;
}

Dialog:Charges(playerid, response, listitem, inputtext[]) 
{
	if(response)
	{
		new str[256];
		PlayerInfo[playerid][E_CHARACTER_MDCCHARGE] = PenalInfo[listitem][E_PENALCODES_CHARGES];
		PlayerInfo[playerid][E_CHARACTER_MDCTIME] = PenalInfo[listitem][E_PENALCODES_JAILTIME];
		format(PlayerInfo[playerid][E_CHARACTER_MDCPLAYER], 32, "%s", PlayerInfo[PlayerInfo[playerid][E_CHARACTER_MDCSELECT]][E_CHARACTER_NAME]);
		format(PlayerInfo[playerid][E_CHARACTER_MDCDESC], 128, "%s", PenalInfo[listitem][E_PENALCODES_TYPE]);

		format(str, sizeof(str), "Suspect: %s\nDescription: (%s) %.150s\nCharges: {93C47D}$%d{ffffff}\nJail Times: %d Month (Minutes)", PlayerInfo[PlayerInfo[playerid][E_CHARACTER_MDCSELECT]][E_CHARACTER_NAME], PenalInfo[listitem][E_PENALCODES_TYPE], PenalInfo[listitem][E_PENALCODES_NAME], PenalInfo[listitem][E_PENALCODES_CHARGES], PenalInfo[listitem][E_PENALCODES_JAILTIME]);
		Dialog_Show(playerid, ChargesSelect, DIALOG_STYLE_MSGBOX, "State Penal Code (Arrest Offesenses):", str, "Enter", "Cancel");
	}
	return 1;
}

Dialog:ChargesSelect(playerid, response, listitem, inputtext[]) 
{
	if(response)
	{
		SetPlayerInPrison(PlayerInfo[playerid][E_CHARACTER_MDCSELECT]);
		
		ResetPlayerWeapons(PlayerInfo[playerid][E_CHARACTER_MDCSELECT]);
		SaveCharacter(PlayerInfo[playerid][E_CHARACTER_MDCSELECT]);
		RemovePlayerAttachedObject(playerid, 0);
		PlayerInfo[PlayerInfo[playerid][E_CHARACTER_MDCSELECT]][E_CHARACTER_HANDCUFF] = false;
		SetPlayerSpecialAction(PlayerInfo[playerid][E_CHARACTER_MDCSELECT], SPECIAL_ACTION_NONE);

		GiveMoney(PlayerInfo[playerid][E_CHARACTER_MDCSELECT], -PlayerInfo[playerid][E_CHARACTER_MDCCHARGE]);

		AddWanted(PlayerInfo[playerid][E_CHARACTER_MDCPLAYER], PlayerInfo[playerid][E_CHARACTER_MDCDESC]);
	}
	return 1;
}