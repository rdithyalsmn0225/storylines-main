/*
	NOTE:There is Drugs Types
	1. Crack/1.0g $350
	2. Marijuana/1.0g $200
	3. Heroin/1.0g $200
	4. PCP/1.0g $150
*/

stock IsPlayerNearDrugsDealing(playerid)
{
	for(new i; i < MAX_TURFS; i++)
	{
		if(TurfInfo[i][E_FACTION_TURFDRUGSEXISTS] == 1 && IsPlayerInRangeOfPoint(playerid, 3.0, TurfInfo[i][E_FACTION_TURFDRUGSX], TurfInfo[i][E_FACTION_TURFDRUGSY], TurfInfo[i][E_FACTION_TURFDRUGSZ]))
			return i;
	}
	return -1;
}

CMD:drugdeal(playerid, params[])
{
	new turfid, str[156];
	if(!PlayerInfo[playerid][E_CHARACTER_FACTION])
		return SendErrorMessage(playerid, "You are not apart a gang members");

	if((turfid = IsPlayerNearTurf(playerid)) == -1)
	    return SendErrorMessage(playerid, "You are not in range of any turfs.");

	if(TurfInfo[turfid][E_FACTION_TURFGANG] != PlayerInfo[playerid][E_CHARACTER_FACTION])
		return SendErrorMessage(playerid, "You are not in range of your gang turf.");

	if(TurfInfo[turfid][E_FACTION_TURFDRUGSEXISTS] == 0)
	{
		if(PlayerInfo[playerid][E_CHARACTER_FACTION] == 7 || PlayerInfo[playerid][E_CHARACTER_FACTION] == 8)
			ShowPlayerDialog(playerid, DIALOG_DRUGSDEALTYPE1, DIALOG_STYLE_TABLIST_HEADERS, "Choose type of drugs to deal", "Drugs\tCost\nCrack, Marijuana\t(Cost Influenced)\nHeroin\t(No Cost Influenced)", "Select", "Cancel");
		else
			ShowPlayerDialog(playerid, DIALOG_DRUGSDEALTYPE2, DIALOG_STYLE_TABLIST_HEADERS, "Choose type of drugs to deal", "Drugs\tCost\nCrack, Marijuana\t(Cost Influenced)\nPCP\t(No Cost Influenced)", "Select", "Cancel");
	}
	else if(TurfInfo[turfid][E_FACTION_TURFDRUGSEXISTS] == 1)
	{
		if(IsPlayerNearDrugsDealing(playerid))
		{
			if(TurfInfo[turfid][E_FACTION_TURFDRUGSTYPE] == 1)
			{
				TurfInfo[turfid][E_FACTION_TURFDRUGS] = randomEx(1, 5);
				format(str, sizeof(str), "The customers want %d Crack\nNOTE: If you don't have this drugs, customers will run and insult.", TurfInfo[turfid][E_FACTION_TURFDRUGS]);
				ShowPlayerDialog(playerid, DIALOG_DRUGSDEAL, DIALOG_STYLE_MSGBOX, "Drugs Dealing:", str, "Confirm", "Reject");
				SetDynamicActorAngleToPlayer(TurfInfo[turfid][E_FACTION_TURFDRUGSACTOR], playerid);
			}
			else if(TurfInfo[turfid][E_FACTION_TURFDRUGSTYPE] == 2)
			{
				TurfInfo[turfid][E_FACTION_TURFDRUGS] = randomEx(1, 5);
				format(str, sizeof(str), "The customers want %d Marijuana\nNOTE: If you don't have this drugs, customers will run and insult.", TurfInfo[turfid][E_FACTION_TURFDRUGS]);
				ShowPlayerDialog(playerid, DIALOG_DRUGSDEAL, DIALOG_STYLE_MSGBOX, "Drugs Dealing:", str, "Confirm", "Reject");
				SetDynamicActorAngleToPlayer(TurfInfo[turfid][E_FACTION_TURFDRUGSACTOR], playerid);
			}
			else if(TurfInfo[turfid][E_FACTION_TURFDRUGSTYPE] == 3)
			{
				TurfInfo[turfid][E_FACTION_TURFDRUGS] = randomEx(1, 5);
				format(str, sizeof(str), "The customers want %d Heroin\nNOTE: If you don't have this drugs, customers will run and insult.", TurfInfo[turfid][E_FACTION_TURFDRUGS]);
				ShowPlayerDialog(playerid, DIALOG_DRUGSDEAL, DIALOG_STYLE_MSGBOX, "Drugs Dealing:", str, "Confirm", "Reject");
				SetDynamicActorAngleToPlayer(TurfInfo[turfid][E_FACTION_TURFDRUGSACTOR], playerid);
			}
			else if(TurfInfo[turfid][E_FACTION_TURFDRUGSTYPE] == 4)
			{
				TurfInfo[turfid][E_FACTION_TURFDRUGS] = randomEx(1, 5);
				format(str, sizeof(str), "The customers want %d PCP\nNOTE: If you don't have this drugs, customers will run and insult.", TurfInfo[turfid][E_FACTION_TURFDRUGS]);
				ShowPlayerDialog(playerid, DIALOG_DRUGSDEAL, DIALOG_STYLE_MSGBOX, "Drugs Dealing:", str, "Confirm", "Reject");
				SetDynamicActorAngleToPlayer(TurfInfo[turfid][E_FACTION_TURFDRUGSACTOR], playerid);
			}
		}
		else return SendErrorMessage(playerid, "You aren't nearest drugs customers.");
	}
	return 1;
}

function:DrugsDealing(turfid, type, Float:x, Float:y, Float:z, Float:a)
{
	new rand = random(sizeof(g_aDrugsDealSkins)), queryBuffer[512];

	mysql_format(ourConnection, queryBuffer, sizeof(queryBuffer), "UPDATE turfs SET drugsx = '%f', drugsy = '%f', drugsz = '%f', drugsa = '%f' WHERE id = %i", x, y, z, a, turfid);
	mysql_pquery(ourConnection, queryBuffer);

	TurfInfo[turfid][E_FACTION_TURFDRUGSACTOR] = CreateDynamicActor(g_aDrugsDealSkins[rand], x, y ,z , a);
	SetDynamicActorFacingAngle(TurfInfo[turfid][E_FACTION_TURFDRUGSACTOR], a);
	SetDynamicActorVirtualWorld(TurfInfo[turfid][E_FACTION_TURFDRUGSACTOR], 0);
	ApplyDynamicActorAnimation(TurfInfo[turfid][E_FACTION_TURFDRUGSACTOR], "DEALER", "DEALER_IDLE", 4.1, 0, 0, 0, 0, 0);

	TurfInfo[turfid][E_FACTION_TURFDRUGSTYPE] = type;
	TurfInfo[turfid][E_FACTION_TURFDRUGSEXISTS] = 1;
	return 1;
}

function:DrugsDealingRun(turfid, type)
{
	switch(type)
	{
		case 0:
		{
			ApplyDynamicActorAnimation(TurfInfo[turfid][E_FACTION_TURFDRUGSACTOR], "SMOKING", "M_smk_in", 4.1, 0, 0, 0, 0, 0);
			SetTimerEx("DrugsDealingRun", 3000, false, "ii", turfid, 1);
		}
		case 1:
		{
			SetDynamicActorVirtualWorld(TurfInfo[turfid][E_FACTION_TURFDRUGSACTOR], 99);
			TurfInfo[turfid][E_FACTION_TURFDRUGSEXISTS] = 0;
			SetTimerEx("DrugsDealingRun", 2000, false, "ii", turfid, 2);
		}
		case 2:
		{
			if(IsValidDynamicActor(TurfInfo[turfid][E_FACTION_TURFDRUGSACTOR]))
				DestroyDynamicActor(TurfInfo[turfid][E_FACTION_TURFDRUGSACTOR]);
		}
	}
	return 1;
}