new
	bool:PlayingPool[MAX_PLAYERS],
	PoolCamera[MAX_PLAYERS],
	PlayerUsingChalk[MAX_PLAYERS],
	PlayerPoolBallType[MAX_PLAYERS],
	Float:AimAngle[MAX_PLAYERS][2];

GetBallModel(i)
{
	switch(i)
	{
		//solid
		case 0: return 3003;
		case 1: return 3002;
		case 2: return 3100;
		case 3: return 3101;
		case 4: return 3102;
		case 5: return 3103;
		case 6: return 3104;
		case 7: return 3105;
		//stripe
		case 8: return 2995;
		case 9: return 2996;
		case 10: return 2997;
		case 11: return 2998;
		case 12: return 2999;
		case 13: return 3000;
		case 14: return 3001;
		case 15: return 3106;
	}
	return 0;
}

stock GetPoolBallsCount(businessid)
{
	new
		count;
	for(new i; i < 16; i++)
	{
		if(PoolBall[i][businessid][E_POOLBALL_EXISTS] || i == 0) count++;
	}
	return count;
}

stock SendPoolPlayersMessage(string[])
{
	foreach (new i : Player)
	{
		if(PlayingPool[i])
		{
			SendClientMessage(i, COLOR_INFO, string);
		}
	}
}

stock AreAllBallsStopped(businessid)
{
	new
		Float:x, Float:y, Float:z;
	for(new i; i < 16; i++)
	{
		if(PoolBall[i][businessid][E_POOLBALL_EXISTS])
		{
			PHY_GetObjectVelocity(PoolBall[i][businessid][E_POOLBALL_OBJECT], x, y, z);
			if(x != 0.0 || y != 0.0)
				return 0;
		}
	}
	return 1;
}

stock RespawnPoolBalls(init = 0, businessid)
{
	for(new i; i < 16; i++)
	{
		DestroyObject(PoolBall[i][businessid][E_POOLBALL_OBJECT]);
		if(PoolBall[i][businessid][E_POOLBALL_EXISTS])
		{
			PHY_DeleteObject(PoolBall[i][businessid][E_POOLBALL_OBJECT]);
			PoolBall[i][businessid][E_POOLBALL_EXISTS] = 0;
		}
	}

	if(PoolInfo[businessid][E_POOL_PLAYERAIMER] != -1)
	{
		TogglePlayerControllable(PoolInfo[businessid][E_POOL_PLAYERAIMER], 1);
		ClearAnimations(PoolInfo[businessid][E_POOL_PLAYERAIMER]);
		ApplyAnimation(PoolInfo[businessid][E_POOL_PLAYERAIMER], "CARRY", "crry_prtial", 1.0, 0, 0, 0, 0, 0);
		SetCameraBehindPlayer(PoolInfo[businessid][E_POOL_PLAYERAIMER]);
		PoolInfo[businessid][E_POOL_PLAYERAIMER] = -1;
		DestroyObject(PoolInfo[businessid][E_POOL_AIMOBJECT]);
	}

	PoolInfo[businessid][E_POOL_PLAYER1] = -1;
	PoolInfo[businessid][E_POOL_PLAYER2] = -1;
	PoolInfo[businessid][E_POOL_PLAYER1SCORE] = 0;
	PoolInfo[businessid][E_POOL_PLAYER2SCORE] = 0;

	if(init)
	{
		CreateBalls(businessid);

		for(new i; i < sizeof PoolBall; i++)
			InitBall(i, businessid);
	}
}

stock CreateBalls(businessid)
{
	PoolBall[0][businessid][E_POOLBALL_OBJECT] = CreateObject(3003, 510.11218261719, -84.40771484375, 998.86785888672, 0, 0, 0);
	PoolBall[1][businessid][E_POOLBALL_OBJECT] = CreateObject(3002, 510.10882568359, -85.166389465332, 998.86749267578, 0, 0, 0);
	PoolBall[2][businessid][E_POOLBALL_OBJECT] = CreateObject(3100, 510.07455444336, -85.365234375, 998.86749267578, 0, 0, 0);
	PoolBall[3][businessid][E_POOLBALL_OBJECT] = CreateObject(3101, 510.14270019531, -85.232612609863, 998.86749267578, 0, 0, 0);
	PoolBall[4][businessid][E_POOLBALL_OBJECT] = CreateObject(3102, 510.18399047852, -85.430549621582, 998.86749267578, 0, 0, 0);
	PoolBall[5][businessid][E_POOLBALL_OBJECT] = CreateObject(3103, 510.22308349609, -85.362342834473, 998.86749267578, 0, 0, 0);
	PoolBall[6][businessid][E_POOLBALL_OBJECT] = CreateObject(3104, 509.96197509766, -85.427406311035, 998.86749267578, 0, 0, 0);
	PoolBall[7][businessid][E_POOLBALL_OBJECT] = CreateObject(3105, 510.03665161133, -85.299163818359, 998.86749267578, 0, 0, 0);
	PoolBall[8][businessid][E_POOLBALL_OBJECT] = CreateObject(2995, 510.0676574707, -85.232200622559, 998.86749267578, 0, 0, 0);
	PoolBall[9][businessid][E_POOLBALL_OBJECT] = CreateObject(2996, 510.18600463867, -85.295257568359, 998.86749267578, 0, 0, 0);
	PoolBall[10][businessid][E_POOLBALL_OBJECT] = CreateObject(2997, 510.00054931641, -85.363563537598, 998.86749267578, 0, 0, 0);
	PoolBall[11][businessid][E_POOLBALL_OBJECT] = CreateObject(2998, 510.03570556641, -85.432624816895, 998.86749267578, 0, 0, 0);
	PoolBall[12][businessid][E_POOLBALL_OBJECT] = CreateObject(2999, 510.10900878906, -85.43196105957, 998.86749267578, 0, 0, 0);
	PoolBall[13][businessid][E_POOLBALL_OBJECT] = CreateObject(3000, 510.25915527344, -85.431137084961, 998.86749267578, 0, 0, 0);
	PoolBall[14][businessid][E_POOLBALL_OBJECT] = CreateObject(3001, 510.14828491211, -85.365989685059, 998.86749267578, 0, 0, 0);
	PoolBall[15][businessid][E_POOLBALL_OBJECT] = CreateObject(3106, 510.11242675781, -85.297294616699, 998.86749267578, 0, 0, 0);

	for(new i; i < sizeof PoolBall; i++)
		PHY_SetObjectWorld(PoolBall[i][businessid][E_POOLBALL_OBJECT], BusinessInfo[businessid][E_BUSINESS_INTERIORPOSWORLD]);
}

stock InitBall(i, businessid)
{
	PHY_InitObject(PoolBall[i][businessid][E_POOLBALL_OBJECT], 3003, _, _, PHY_MODE_2D);
	PHY_SetObjectFriction(PoolBall[i][businessid][E_POOLBALL_OBJECT], 0.40);
	PHY_RollObject(PoolBall[i][businessid][E_POOLBALL_OBJECT], _, PHY_ROLLING_MODE_ADVANCED);
	PHY_SetObjectWorld(PoolBall[i][businessid][E_POOLBALL_OBJECT], BusinessInfo[businessid][E_BUSINESS_INTERIORPOSWORLD]);
	PoolBall[i][businessid][E_POOLBALL_EXISTS] = 1;
}

stock Query_LoadBusinessPool(businessid)
{
	SetTimerEx("PoolTimer", 50, true, "d", businessid);
	PHY_SetWallWorld(PHY_CreateWall(509.627 - 0.038, -85.780 - 0.038, 510.598 + 0.038, -85.780 - 0.038), BusinessInfo[businessid][E_BUSINESS_INTERIORPOSWORLD]);
	PHY_SetWallWorld(PHY_CreateWall(510.598 + 0.038, -85.780 - 0.038, 510.598 + 0.038, -83.907 + 0.038), BusinessInfo[businessid][E_BUSINESS_INTERIORPOSWORLD]);
	PHY_SetWallWorld(PHY_CreateWall(510.598 + 0.038, -83.907 + 0.038, 509.627 - 0.038, -83.907 + 0.038), BusinessInfo[businessid][E_BUSINESS_INTERIORPOSWORLD]);
	PHY_SetWallWorld(PHY_CreateWall(509.627 - 0.038, -83.907 + 0.038, 509.627 - 0.038, -85.780 - 0.038), BusinessInfo[businessid][E_BUSINESS_INTERIORPOSWORLD]);
}

stock GetPoolPlayersCount(businessid)
{
	new count;
	if(PoolInfo[businessid][E_POOL_STARTED])
	{
		foreach (new i : Player)
		{
			if(PlayingPool[i])
			{
				count++;
			}
		}
	}
	return count;
}

function:PoolTimer(businessid)
{
	if(!PoolInfo[businessid][E_POOL_STARTED]) return 0;

	if(PoolInfo[businessid][E_POOL_PLAYERAIMER] != -1)
	{
		new
			playerid = PoolInfo[businessid][E_POOL_PLAYERAIMER];

		if(PoolInfo[businessid][E_POOL_DIRECTION])
			PoolInfo[businessid][E_POOL_POWER] -= 2.0;
		else
			PoolInfo[businessid][E_POOL_POWER] += 2.0;
		if(PoolInfo[businessid][E_POOL_POWER] <= 0)
		{
			PoolInfo[businessid][E_POOL_DIRECTION] = 0;
			PoolInfo[businessid][E_POOL_POWER] = 2.0;
		}
		else if(PoolInfo[businessid][E_POOL_POWER] > 100.0)
		{
			PoolInfo[businessid][E_POOL_DIRECTION] = 1;
			PoolInfo[businessid][E_POOL_POWER] = 98.0;
		}
		new str[256];
		format(str, sizeof(str), "Press '~r~LEFT~w~' or '~r~RIGHT~w~' to change your camera position~n~Press '~y~Shoot~w~' to shoot~n~You power : ~y~%.0f%", PoolInfo[businessid][E_POOL_POWER]);
		PlayerTextDrawSetString(playerid, pool[3][playerid], str);

		for(new a; a < 5; a++)
		{
			PlayerTextDrawShow(playerid, pool[a][playerid]);
		}
	}

	if(PoolInfo[businessid][E_POOL_LASTSHOOTER] != -1 && AreAllBallsStopped(businessid))
	{
		SetTimerEx("RestoreCamera", 800, 0, "dd", PoolInfo[businessid][E_POOL_LASTSHOOTER], businessid);
		PoolInfo[businessid][E_POOL_LASTSHOOTER] = -1;
	}

	new string[512], balltype[16];
	if(PlayerPoolBallType[PoolInfo[businessid][E_POOL_PLAYER1]] == 1) balltype = "Solid";
	else if(PlayerPoolBallType[PoolInfo[businessid][E_POOL_PLAYER1]] == 2) balltype = "Stripe";
	else balltype = "Unknown";

	if(PlayerPoolBallType[PoolInfo[businessid][E_POOL_PLAYER2]] == 1) balltype = "Solid";
	else if(PlayerPoolBallType[PoolInfo[businessid][E_POOL_PLAYER2]] == 2) balltype = "Stripe";
	else balltype = "Unknown";

	format(string, sizeof(string), "You are %s. It's %s turn~n~~n~~r~%s score: ~w~%d~n~~b~%s score: ~w~%d", 
	balltype, ReturnName(PoolInfo[businessid][E_POOL_TURN]), ReturnName(PoolInfo[businessid][E_POOL_PLAYER1]), PoolInfo[businessid][E_POOL_PLAYER1SCORE], ReturnName(PoolInfo[businessid][E_POOL_PLAYER2]), PoolInfo[businessid][E_POOL_PLAYER2SCORE]);

	ShowHeaderMessage(PoolInfo[businessid][E_POOL_PLAYER1], "Pool: 8-Ball", string, 1);
	ShowHeaderMessage(PoolInfo[businessid][E_POOL_PLAYER2], "Pool: 8-Ball", string, 1);
	return 1;
}

stock ProcessPoolMovement(playerid, lr)
{
    new
        Float:X,
        Float:Y,
        Float:Z,
        Float:Xa,
        Float:Ya,
        Float:Za,
        Float:x,
        Float:y,
        Float:newrot,
        Float:dist;

	new businessid = IsPlayerInBusiness(playerid);

    GetPlayerPos(playerid, X, Y, Z);
    GetObjectPos(PoolBall[0][businessid][E_POOLBALL_OBJECT], Xa, Ya, Za);
    newrot = AimAngle[playerid][0] + (lr > 0 ? 0.9 : -0.9);
    dist = GetPointDistanceToPoint(X, Y, Xa, Ya);

    if (AngleInRangeOfAngle(AimAngle[playerid][1], newrot, 30.0))
    {
        AimAngle[playerid][0] = newrot;
        switch (PoolCamera[playerid])
        {
            case 0:
            {
                GetXYBehindObjectInAngle(PoolBall[0][businessid][E_POOLBALL_OBJECT], newrot, x, y, 0.675);
                SetPlayerCameraPos(playerid, x, y, 998.86785888672 + 0.28);
                SetPlayerCameraLookAt(playerid, Xa, Ya, Za + 0.170);
            }
            case 1:
            {
                SetPlayerCameraPos(playerid, 511.84469604492, -84.831642150879, 1001.4904174805);
                SetPlayerCameraLookAt(playerid, 510.11267089844, -84.831642150879, 998.86785888672);
            }
            case 2:
            {
                SetPlayerCameraPos(playerid, 508.7971496582, -84.831642150879, 1001.4904174805);
                SetPlayerCameraLookAt(playerid, 510.11267089844, -84.831642150879, 998.86785888672);
            }
        }
        GetXYInFrontOfPos(Xa, Ya, newrot + 180, x, y, 0.085);
        SetObjectPos(PoolInfo[businessid][E_POOL_AIMOBJECT], x, y, Za);
        SetObjectRot(PoolInfo[businessid][E_POOL_AIMOBJECT], 7.0, 0, AimAngle[playerid][0] + 180);
        GetXYInFrontOfPos(Xa, Ya, newrot + 180, X, Y, dist);
        SetPlayerPos(playerid, X, Y, Z);
        SetPlayerFacingAngle(playerid, newrot);
    }
}

function:RestoreCamera(playerid, businessid)
{
	if(!PoolBall[0][businessid][E_POOLBALL_EXISTS])
	{
		DestroyObject(PoolBall[0][businessid][E_POOLBALL_OBJECT]);
		PoolBall[0][businessid][E_POOLBALL_OBJECT] = CreateObject(GetBallModel(0) ,510.11218261719, -84.40771484375, 998.86785888672, 0, 0, 0);
		PHY_SetObjectWorld(PoolBall[0][businessid][E_POOLBALL_OBJECT], BusinessInfo[businessid][E_BUSINESS_INTERIORPOSWORLD]);
		InitBall(0, businessid);
	}
	GameTextForPlayer(playerid, " ", 100000, 4);
	if(PoolInfo[businessid][E_POOL_PLAYERAIMER] == playerid) return 0;
	TogglePlayerControllable(playerid, 1);
	for(new a; a < 5; a++)
	{
		PlayerTextDrawHide(playerid, pool[a][playerid]);
	}
	CancelSelectTextDraw(playerid);
	return SetCameraBehindPlayer(playerid);
}

function:RestorePoolStick(playerid)
{
	for(new a; a < 5; a++)
	{
		PlayerTextDrawHide(playerid, pool[a][playerid]);
	}
	CancelSelectTextDraw(playerid);
	RemovePlayerAttachedObject(playerid, ATTACH_HAND);
	PlayerUsingChalk[playerid] = 0;
	ApplyAnimation(playerid, "CARRY", "crry_prtial", 1.0, 0, 0, 0, 0, 0, 1);
	return 1;
}

stock IsPoolBallInHole(i, businessid)
{
	if(IsObjectInSphere(PoolBall[i][businessid][E_POOLBALL_OBJECT],509.61123657,-85.79737091,998.86785889,0.0825)) return 1;
	else if(IsObjectInSphere(PoolBall[i][businessid][E_POOLBALL_OBJECT],510.67373657,-84.84423065,998.86785889,0.0825)) return 2;
	else if(IsObjectInSphere(PoolBall[i][businessid][E_POOLBALL_OBJECT],510.61914062,-83.88769531,998.86785889,0.0825)) return 3;
	else if(IsObjectInSphere(PoolBall[i][businessid][E_POOLBALL_OBJECT],509.61077881,-83.89227295,998.86785889,0.0825)) return 4;
	else if(IsObjectInSphere(PoolBall[i][businessid][E_POOLBALL_OBJECT],510.61825562,-85.80107880,998.86785889,0.0825)) return 5;
	else if(IsObjectInSphere(PoolBall[i][businessid][E_POOLBALL_OBJECT],509.55642700,-84.84602356,998.86785889,0.0825)) return 6;
	else return 0;
}

function:PlayPoolSound(soundid)
{
	foreach(new i : Player)
	{
		if(PlayingPool[i])
		{
			PlayerPlaySound(i, soundid, 0, 0, 0);
		}
	}
	return 1;
}

CMD:pool(playerid, params[])
{
	new playerb;
	new businessid = IsPlayerInBusiness(playerid);

	if(sscanf(params, "d", playerb)) 
		return SendUsageMessage(playerid, "/pool [playerid(opponent)]");

	if(!IsPlayerInBusiness(playerid))
        return SendErrorMessage(playerid, "You aren't in any business.");
    
    if(BusinessInfo[businessid][E_BUSINESS_TYPE] != BUSINESS_TYPE_BAR)
        return SendErrorMessage(playerid, "You aren't in any business bar.");

	if(!IsPlayerInRangeOfPoint(playerid, 3.0, 510.0676574707, -85.232200622559, 998.86749267578))
		return SendErrorMessage(playerid, "You aren't near pool table.");

	if(playerb == playerid)
		return SendErrorMessage(playerid, "You can't started pool with your self.");

	if(!PoolInfo[businessid][E_POOL_STARTED])
	{
		if(!PlayingPool[playerid] && !PlayingPool[playerb])
		{
			PlayingPool[playerid] = true;
			PlayingPool[playerb] = true;
			
			PoolInfo[businessid][E_POOL_PLAYER1] = playerid;
			PoolInfo[businessid][E_POOL_PLAYER2] = playerb;
			PoolInfo[businessid][E_POOL_PLAYER1SCORE] = 0;
			PoolInfo[businessid][E_POOL_PLAYER2SCORE] = 0;
			
			PoolInfo[businessid][E_POOL_STARTED] = true;
			RespawnPoolBalls(1, businessid);
			
			new Cents = floatround(50 * 100, floatround_round);
			GiveMoney(playerid, -Cents);
			GiveMoney(playerb, -Cents);
			SendServerMessage(playerid, "[8Ball] {a4a4a4}You has started pool at %s you paying %s for the fee.", BusinessInfo[businessid][E_BUSINESS_NAME], FormatMoney(Cents));
			SendServerMessage(playerb, "[8Ball] {a4a4a4}You has started pool at %s you paying %s for the fee.", BusinessInfo[businessid][E_BUSINESS_NAME], FormatMoney(Cents));
		}
	}
	else SendErrorMessage(playerid, "There is player using this table.");
	return 1;
}

CMD:poolexit(playerid, params[])
{
	new businessid = IsPlayerInBusiness(playerid);

	if(!IsPlayerInBusiness(playerid))
        return SendErrorMessage(playerid, "You aren't in any business.");
    
    if(BusinessInfo[businessid][E_BUSINESS_TYPE] != BUSINESS_TYPE_BAR)
        return SendErrorMessage(playerid, "You aren't in any business bar.");

	if(!IsPlayerInRangeOfPoint(playerid, 3.0, 510.0676574707, -85.232200622559, 998.86749267578))
		return SendErrorMessage(playerid, "You aren't near pool table.");

	if(PoolInfo[businessid][E_POOL_STARTED])
	{
		if(PlayingPool[playerid])
		{
			if(PoolInfo[businessid][E_POOL_PLAYERAIMER] != playerid)
			{
				PlayingPool[playerid] = false;
				
				new
					count = GetPoolPlayersCount(businessid);

				if(count <= 0)
				{
					PoolInfo[businessid][E_POOL_STARTED] = false;
					RespawnPoolBalls(0, businessid);
				}

				if(PoolInfo[businessid][E_POOL_PLAYER1] == playerid)
				{
					PoolInfo[businessid][E_POOL_PLAYER1] = -1;
				}
				if(PoolInfo[businessid][E_POOL_PLAYER2] == playerid)
				{
					PoolInfo[businessid][E_POOL_PLAYER2] = -1;
				}
				RestorePoolStick(playerid);
				HideHeaderMessage(playerid);
				SendServerMessage(playerid, "[8Ball] {a4a4a4}You has exit pool at %s.", BusinessInfo[businessid][E_BUSINESS_NAME]);
			}
		}
	}
	return 1;
}