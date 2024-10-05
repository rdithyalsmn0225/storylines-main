function:StartHairCut(playerid, modelid)
{
    ApplyAnimation(playerid, "HAIRCUTS", "BRB_Sit_Loop", 4.1, 1, 0, 0, 0, 0, 0);
	InterpolateCameraPos(playerid, 415.485565, -20.236553, 1002.263977, 415.485565, -20.236553, 1002.263977, 3000, 1);
	InterpolateCameraLookAt(playerid, 412.258148, -17.982490, 1001.554809, 412.278259, -17.922260, 1001.666198, 3000, 1);
		
    ApplyDynamicActorAnimation(BusinessInfo[IsPlayerInBusiness(playerid)][E_BUSINESS_ACTOR], "HAIRCUTS", "BRB_Cut", 4.1, 0, 0, 0, 0, 0);
    SetTimerEx("SetPlayerHairAndExit", 1300, false, "ii", playerid, modelid);
}

function:SetPlayerHairAndExit(playerid, modelid)
{
    ApplyDynamicActorAnimation(BusinessInfo[IsPlayerInBusiness(playerid)][E_BUSINESS_ACTOR], "HAIRCUTS", "BRB_Cut_Out", 4.1, 0, 0, 0, 0, 0);
    ApplyAnimation(playerid, "HAIRCUTS", "BRB_Sit_Out", 4.1, 0, 0, 0, 0, 0, 0);
    SetTimerEx("ExitHairCut", 1000, false, "i", playerid);

    GiveMoney(playerid, -250);
	BusinessInfo[IsPlayerInBusiness(playerid)][E_BUSINESS_STOCK]--;
	new slot = GetPlayerFreeToySlot(playerid);
	pToys[playerid][slot][E_TOY_MODEL] = modelid;
	pToys[playerid][slot][E_TOY_BONE] = 2;
	toyToggle[playerid][slot] = true;
    pToys[playerid][slot][E_TOY_X] = 0.067000;
	pToys[playerid][slot][E_TOY_Y] = 0.000000;
	pToys[playerid][slot][E_TOY_Z] = 0.000000;
	pToys[playerid][slot][E_TOY_RX] = 0.000000;
	pToys[playerid][slot][E_TOY_RY] = 0.000000;
	pToys[playerid][slot][E_TOY_RZ] = 0.000000;
	pToys[playerid][slot][E_TOY_SX] = 1.000000;
	pToys[playerid][slot][E_TOY_SY] = 1.000000;
	pToys[playerid][slot][E_TOY_SZ] = 1.000000;
    pToys[playerid][slot][E_TOY_TYPE] = ACC_TOYS;
    SetPlayerAttachedObject(playerid, slot, pToys[playerid][slot][E_TOY_MODEL], 2, 0.067000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 1.000000, 1.000000, 1.000000);
    SavePlayerToys(playerid);

    Relations_Add(playerid, BusinessInfo[IsPlayerInBusiness(playerid)][E_BUSINESS_NAME]);
}

function:ExitHairCut(playerid)
{
    ClearDynamicActorAnimations(BusinessInfo[IsPlayerInBusiness(playerid)][E_BUSINESS_ACTOR]);
    ClearAnimations(playerid);
    SetCameraBehindPlayer(playerid);
    SaveCharacter(playerid);
}