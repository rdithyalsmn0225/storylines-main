/*
	NOTE:There is Drugs Types
	1. Crack/1.0g $350
	2. Marijuana/1.0g $200
	3. Heroin/1.0g $200
	4. PCP/1.0g $150
*/

stock IsPlayerNearDrugsDealing(playerid)
{
	return IsPlayerInRangeOfPoint(playerid, 3.0, DrugsDealerPos[playerid][0], DrugsDealerPos[playerid][1], DrugsDealerPos[playerid][2]);
}

CMD:drugsdeal(playerid, params[])
{
	new str[156];
	
	if(DrugsDealerExists[playerid] == 0)
	{
		if(ReturnFactionType(playerid) == FACTION_TYPE_ILLEGAL)
			ShowPlayerDialog(playerid, DIALOG_DRUGSDEALTYPE1, DIALOG_STYLE_TABLIST_HEADERS, "Choose type of drugs to deal", "Drugs\tCost\nCrack, Marijuana\t(Cost Influenced)\nHeroin\t(No Cost Influenced)", "Select", "Cancel");
		else
			ShowPlayerDialog(playerid, DIALOG_DRUGSDEALTYPE2, DIALOG_STYLE_TABLIST_HEADERS, "Choose type of drugs to deal", "Drugs\tCost\nCrack, Marijuana\t(Cost Influenced)\nPCP\t(No Cost Influenced)", "Select", "Cancel");
	}
	else if(DrugsDealerExists[playerid] == 1)
	{
		if(IsValidDynamicActor(DrugsDealerActor[playerid]))
		{	
			SendServerMessage(playerid, "[Drugs Dealer] {cdcdcd}The customers already spawned.");
			GPS_SetPlayerRaceCheckPoint(playerid, 1, DrugsDealerPos[playerid][0], DrugsDealerPos[playerid][1], DrugsDealerPos[playerid][2], 0.0, 0.0, 0.0);
		}
		
		else if(IsPlayerNearDrugsDealing(playerid))
		{
			if(DrugsDealerType[playerid] == 1)
			{
				DrugsDealerAmount[playerid] = randomEx(1, 5);
				format(str, sizeof(str), "The customers want %d Crack\nNOTE: If you don't have this drugs, customers will run and insult.", DrugsDealerAmount[playerid]);
				ShowPlayerDialog(playerid, DIALOG_DRUGSDEAL, DIALOG_STYLE_MSGBOX, "Drugs Dealing:", str, "Confirm", "Reject");
				SetDynamicActorAngleToPlayer(DrugsDealerActor[playerid], playerid);
			}
			else if(DrugsDealerType[playerid] == 2)
			{
				DrugsDealerAmount[playerid] = randomEx(1, 5);
				format(str, sizeof(str), "The customers want %d Marijuana\nNOTE: If you don't have this drugs, customers will run and insult.", DrugsDealerAmount[playerid]);
				ShowPlayerDialog(playerid, DIALOG_DRUGSDEAL, DIALOG_STYLE_MSGBOX, "Drugs Dealing:", str, "Confirm", "Reject");
				SetDynamicActorAngleToPlayer(DrugsDealerActor[playerid], playerid);
			}
			else if(DrugsDealerType[playerid] == 3)
			{
				DrugsDealerAmount[playerid] = randomEx(1, 5);
				format(str, sizeof(str), "The customers want %d Heroin\nNOTE: If you don't have this drugs, customers will run and insult.", DrugsDealerAmount[playerid]);
				ShowPlayerDialog(playerid, DIALOG_DRUGSDEAL, DIALOG_STYLE_MSGBOX, "Drugs Dealing:", str, "Confirm", "Reject");
				SetDynamicActorAngleToPlayer(DrugsDealerActor[playerid], playerid);
			}
			else if(DrugsDealerType[playerid] == 4)
			{
				DrugsDealerAmount[playerid] = randomEx(1, 5);
				format(str, sizeof(str), "The customers want %d PCP\nNOTE: If you don't have this drugs, customers will run and insult.", DrugsDealerAmount[playerid]);
				ShowPlayerDialog(playerid, DIALOG_DRUGSDEAL, DIALOG_STYLE_MSGBOX, "Drugs Dealing:", str, "Confirm", "Reject");
				SetDynamicActorAngleToPlayer(DrugsDealerActor[playerid], playerid);
			}
		}
		else return SendErrorMessage(playerid, "You aren't near drugs customers.");
	}
	return 1;
}

function:DrugsDealing(playerid, type, Float:x, Float:y, Float:z, Float:a)
{
	new rand = random(sizeof(g_aDrugsDealSkins));

	DrugsDealerActor[playerid] = CreateDynamicActor(g_aDrugsDealSkins[rand], x, y ,z , a);
	DrugsDealerPos[playerid][0] = x;
	DrugsDealerPos[playerid][1] = y;
	DrugsDealerPos[playerid][2] = z;
	DrugsDealerPos[playerid][3] = a;
	SetDynamicActorFacingAngle(DrugsDealerActor[playerid], a);
	SetDynamicActorVirtualWorld(DrugsDealerActor[playerid], 0);
	ApplyDynamicActorAnimation(DrugsDealerActor[playerid], "DEALER", "DEALER_IDLE", 4.1, 0, 0, 0, 0, 0);

	DrugsDealerType[playerid] = type;
	DrugsDealerExists[playerid] = 1;
	return 1;
}

function:DrugsDealingRun(playerid, type)
{
	switch(type)
	{
		case 0:
		{
			ApplyDynamicActorAnimation(DrugsDealerActor[playerid], "SMOKING", "M_smk_in", 4.1, 0, 0, 0, 0, 0);
			SetTimerEx("DrugsDealingRun", 3000, false, "ii", playerid, 1);
		}
		case 1:
		{
			SetDynamicActorVirtualWorld(DrugsDealerActor[playerid], 99);
			DrugsDealerExists[playerid] = 0;
			SetTimerEx("DrugsDealingRun", 2000, false, "ii", playerid, 2);
		}
		case 2:
		{
			if(IsValidDynamicActor(DrugsDealerActor[playerid]))
				DestroyDynamicActor(DrugsDealerActor[playerid]);

			SendServerMessage(playerid, "[Drugs Dealer] {cdcdcd}The customers leave the area.");
		}
	}
	return 1;
}