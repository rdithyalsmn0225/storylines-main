
enum E_POOLBALL_DATA
{
	E_POOLBALL_OBJECT,
	E_POOLBALL_EXISTS
}

new PoolBall[16][MAX_BUSINESS][E_POOLBALL_DATA];

new
	bool:PlayingPool[MAX_PLAYERS],
	PoolCamera[MAX_PLAYERS],
	PlayerUsingChalk[MAX_PLAYERS],
	PoolScore[MAX_PLAYERS],
	PlayerPoolBallType[MAX_PLAYERS],
	PlayerPoolTurn[MAX_PLAYERS],
	PlayerPoolPlayer1[MAX_BUSINESS],
	PlayerPoolPlayer2[MAX_BUSINESS],
	Float:AimAngle[MAX_PLAYERS][2],
	PlayerPoolAimObject[MAX_BUSINESS],
	PlayerPoolStarted[MAX_BUSINESS] = 0,
	PlayerPoolAimer[MAX_BUSINESS] = -1,
	PlayerPoolLastShooter[MAX_BUSINESS] = -1,
	PlayerPoolLastScore[MAX_BUSINESS],
	Float:PlayerPoolPower[MAX_BUSINESS],
	PlayerPoolDirection[MAX_BUSINESS];

public PHY_OnObjectUpdate(objectid)
{
    for(new businessid = 1; businessid < MAX_BUSINESS; businessid++)
	{
        if(PlayerPoolStarted[businessid])
        {
            for(new i; i < sizeof PoolBall; i++)
            {
                if(objectid == PoolBall[i][businessid][E_POOLBALL_OBJECT] && PHY_IsObjectMoving(PoolBall[i][businessid][E_POOLBALL_OBJECT]))
                {
                    new
                        hole = IsBallInHole(i, businessid);
                    if(hole)
                    {
                        new
                            Float:speed,
                            Float:vx, Float:vy, Float:vz;
                        PHY_GetObjectVelocity(PoolBall[i][businessid][E_POOLBALL_OBJECT], vx, vy, vz);
                        speed = floatsqroot(vx * vx + vy * vy) + 0.2;

                        PoolBall[i][businessid][E_POOLBALL_EXISTS] = 0;
                        PHY_DeleteObject(PoolBall[i][businessid][E_POOLBALL_OBJECT]);

                        PlayPoolSound(31803 + random(3));

                        switch(hole)
                        {
                            case 1: MoveObject(PoolBall[i][businessid][E_POOLBALL_OBJECT], 509.61123657,-85.79737091,998.86785889-0.25, speed);
                            case 2: MoveObject(PoolBall[i][businessid][E_POOLBALL_OBJECT], 510.67373657,-84.84423065,998.86785889-0.25, speed);
                            case 3: MoveObject(PoolBall[i][businessid][E_POOLBALL_OBJECT], 510.61914062,-83.88769531,998.86785889-0.25, speed);
                            case 4: MoveObject(PoolBall[i][businessid][E_POOLBALL_OBJECT], 509.61077881,-83.89227295,998.86785889-0.25, speed);
                            case 5: MoveObject(PoolBall[i][businessid][E_POOLBALL_OBJECT], 510.61825562,-85.80107880,998.86785889-0.25, speed);
                            case 6: MoveObject(PoolBall[i][businessid][E_POOLBALL_OBJECT], 509.55642700,-84.84602356,998.86785889-0.25, speed);
                        }

						if (PlayerPoolBallType[PlayerPoolLastShooter[businessid]] == 0)
						{
							if (i >= 1 && i <= 7)
							{
								PlayerPoolBallType[PlayerPoolLastShooter[businessid]] = 1;
							}
							else if (i >= 8 && i <= 14)
							{
								PlayerPoolBallType[PlayerPoolLastShooter[businessid]] = 2;
							}
						}
						else
						{
							if ((PlayerPoolBallType[PlayerPoolLastShooter[businessid]] == 1 && i >= 8 && i <= 14) ||
								(PlayerPoolBallType[PlayerPoolLastShooter[businessid]] == 2 && i >= 1 && i <= 7))
							{
								PlayerPoolTurn[businessid] = (PlayerPoolTurn[businessid] == PlayerPoolPlayer1[businessid] ? PlayerPoolPlayer2[businessid] : PlayerPoolPlayer1[businessid]);
								SendPoolPlayersMessage("[8Ball] {a4a4a4}Wrong ball type! Turn ends.");
								RestoreCamera(PlayerPoolLastShooter[businessid], businessid);
								return 1;
							}
						}

						if (i == 15)
						{
							new string[128];
							foreach (new p : Player)
							{
								if (PlayingPool[p] && p != PlayerPoolLastShooter[businessid])
								{
									format(string, sizeof(string), "[8Ball] {a4a4a4}The winner is: %s because PoolBall 5 was pocketed.", ReturnName(p));
									SendPoolPlayersMessage(string);
									print(string);

									PlayingPool[p] = false;
								}
								else if (PlayingPool[p])
								{
									PlayingPool[p] = false;
								}
							}

							PlayerPoolStarted[businessid] = 0;
							PlayerPoolAimer[businessid] = -1;
							RespawnPoolBalls(0, businessid);
							RestoreCamera(PlayerPoolLastShooter[businessid], businessid);
							PlayerPoolLastShooter[businessid] = -1;

							return 1;
						}

                        if(i)
                        {
                            PoolScore[PlayerPoolLastShooter[businessid]] ++;
                            PlayerPoolLastScore[businessid] ++;
                            new string[128];
                            if(PlayerPoolLastScore[businessid] > 0) format(string, 128, "~g~~h~+%d", PlayerPoolLastScore[businessid]);
                            else format(string, 128, "~r~~h~%d", PlayerPoolLastScore[businessid]);
                            GameTextForPlayer(PlayerPoolLastShooter[businessid], string, 100000, 4);
                            PlayerPlaySound(PlayerPoolLastShooter[businessid], 1250, 0.0, 0.0, 0.0);
                        }
                        else
                        {
                            PoolScore[PlayerPoolLastShooter[businessid]] --;
                            PlayerPoolLastScore[businessid] --;
                            new string[128];
                            if(PlayerPoolLastScore[businessid] > 0) format(string, 128, "~g~~h~+~r~~h~%d", PlayerPoolLastScore[businessid]);
                            else format(string, 128, "~r~~h~%d", PlayerPoolLastScore[businessid]);
                            GameTextForPlayer(PlayerPoolLastShooter[businessid], string, 100000, 4);
                            PlayerPlaySound(PlayerPoolLastShooter[businessid], 1250, 0.0, 0.0, 0.0);
                        }
                        if(GetPoolBallsCount(businessid) <= 1)
                        {
                            PlayerPoolStarted[businessid] = 0;
                            PlayerPoolAimer[businessid] = -1;
                            new winscore = GetMaxPoolScore();

                            RespawnPoolBalls(0, businessid);
                            RestoreCamera(PlayerPoolLastShooter[businessid], businessid);
                            PlayerPoolLastShooter[businessid] = -1;
                            
							foreach(new p : Player)
							{
								if(PlayingPool[p] && PoolScore[p] == winscore)
								{
									new
										string[128];
									format(string, 128, "[8Ball] {a4a4a4}The winner is:%s with %d points.", ReturnName(p), winscore);
									SendPoolPlayersMessage(string);
									print(string);
								}
								
								if(PlayingPool[p])
								{
									PlayingPool[p] = false;
								}
							}   
                        }
                        else if(AreAllBallsStopped(businessid))
                        {
                            SetTimerEx("RestoreCamera", 800, 0, "dd", PlayerPoolLastShooter[businessid], businessid);
                            PlayerPoolLastShooter[businessid] = -1;
                        }
                    }
                    return 1;
                }
            }
        }
	}
	return 1;
}

public PHY_OnObjectCollideWithObject(object1, object2)
{
    for(new businessid = 1; businessid < MAX_BUSINESS; businessid++)
	{
        if(PlayerPoolStarted[businessid])
        {
            for(new i; i < sizeof PoolBall; i++)
            {
                if(object1 == PoolBall[i][businessid][E_POOLBALL_OBJECT])
                {
                    PlayPoolSound(31800 + random(3));
                    return 1;
                }
            }
        }
    }
	return 1;
}

public PHY_OnObjectCollideWithWall(objectid, wallid)
{
    for(new businessid = 1; businessid < MAX_BUSINESS; businessid++)
	{
        if(PlayerPoolStarted[businessid])
        {
            for(new i; i < sizeof PoolBall; i++)
            {
                if(objectid == PoolBall[i][businessid][E_POOLBALL_OBJECT])
                {
                    PlayPoolSound(31808);
                    return 1;
                }
            }
        }
    }
	return 1;
}

Float:GetPointDistanceToPoint(Float:x1,Float:y1,Float:x2,Float:y2)
{
	new Float:x, Float:y;
	x = x1-x2;
	y = y1-y2;
	return floatsqroot(x*x+y*y);
}


stock GetAngleToXY(Float:X, Float:Y, Float:CurrX, Float:CurrY, &Float:angle)
{
	angle = atan2(Y-CurrY, X-CurrX);
	angle = floatsub(angle, 90.0);
	if(angle < 0.0) angle = floatadd(angle, 360.0);
}


stock GetXYInFrontOfPos(Float:xx,Float:yy,Float:a, &Float:x2, &Float:y2, Float:distance)
{
	if(a>360)
	{
		a=a-360;
	}
	xx += (distance * floatsin(-a, degrees));
	yy += (distance * floatcos(-a, degrees));
	x2=xx;
	y2=yy;
}

stock IsPointFacingPoint(Float:dOffset, Float:X, Float:Y, Float:pA, Float:pX, Float:pY)
{
	new
		Float:ang;

	if( Y > pY ) ang = (-acos((X - pX) / floatsqroot((X - pX)*(X - pX) + (Y - pY)*(Y - pY))) - 90.0);
	else if( Y < pY && X < pX ) ang = (acos((X - pX) / floatsqroot((X - pX)*(X - pX) + (Y - pY)*(Y - pY))) - 450.0);
	else if( Y < pY ) ang = (acos((X - pX) / floatsqroot((X - pX)*(X - pX) + (Y - pY)*(Y - pY))) - 90.0);

	if(AngleInRangeOfAngle(-ang, pA, dOffset)) return true;

	return false;

}

stock Is2DPointInRangeOfPoint(Float:x, Float:y, Float:x2, Float:y2, Float:range)
{
	x2 -= x;
	y2 -= y;
	return ((x2 * x2) + (y2 * y2)) < (range * range);
}

stock IsObjectInSphere(objectid,Float:x,Float:y,Float:z,Float:radius2)
{
	new Float:x1,Float:y1,Float:z1,Float:tmpdis;
	GetObjectPos(objectid,x1,y1,z1);
	tmpdis = floatsqroot(floatpower(floatabs(floatsub(x,x1)),2)+ floatpower(floatabs(floatsub(y,y1)),2)+ floatpower(floatabs(floatsub(z,z1)),2));
	if(tmpdis < radius2) return 1;
	return 0;
}

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


stock GetMaxPoolScore()
{
	new
		scoremax = -1;
	foreach (new i : Player)
	{
		if(PlayingPool[i])
		{
			if(PoolScore[i] > scoremax)
			{
				scoremax = PoolScore[i];
			}
		}
	}
	return scoremax;
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

	if(PlayerPoolAimer[businessid] != -1)
	{
		TogglePlayerControllable(PlayerPoolAimer[businessid], 1);
		ClearAnimations(PlayerPoolAimer[businessid]);
		ApplyAnimation(PlayerPoolAimer[businessid], "CARRY", "crry_prtial", 1.0, 0, 0, 0, 0, 0);
		SetCameraBehindPlayer(PlayerPoolAimer[businessid]);
		PlayerPoolAimer[businessid] = -1;
		DestroyObject(PlayerPoolAimObject[businessid]);
	}

	CreateBalls(businessid);

	if(init)
	{
		for(new i; i < sizeof PoolBall; i++)
			InitBall(i, businessid);
	}
}

stock CreateBalls(businessid)
{
	PoolBall[0][businessid][E_POOLBALL_OBJECT] = CreateObject(3003, 510.11218261719, -84.40771484375, 998.86785888672, 0, 0, 0);
	PoolBall[1][businessid][E_POOLBALL_OBJECT] = CreateObject(3002, 510.10882568359, -85.166389465332, 998.86749267578, 0, 0, 0);
	PoolBall[3][businessid][E_POOLBALL_OBJECT] = CreateObject(3101, 510.14270019531, -85.232612609863, 998.86749267578, 0, 0, 0);
	PoolBall[8][businessid][E_POOLBALL_OBJECT] = CreateObject(2995, 510.0676574707, -85.232200622559, 998.86749267578, 0, 0, 0);
	PoolBall[9][businessid][E_POOLBALL_OBJECT] = CreateObject(2996, 510.18600463867, -85.295257568359, 998.86749267578, 0, 0, 0);
	PoolBall[5][businessid][E_POOLBALL_OBJECT] = CreateObject(3106, 510.11242675781, -85.297294616699, 998.86749267578, 0, 0, 0);
	PoolBall[7][businessid][E_POOLBALL_OBJECT] = CreateObject(3105, 510.03665161133, -85.299163818359, 998.86749267578, 0, 0, 0);
	PoolBall[5][businessid][E_POOLBALL_OBJECT] = CreateObject(3103, 510.22308349609, -85.362342834473, 998.86749267578, 0, 0, 0);
	PoolBall[14][businessid][E_POOLBALL_OBJECT] = CreateObject(3001, 510.14828491211, -85.365989685059, 998.86749267578, 0, 0, 0);
	PoolBall[2][businessid][E_POOLBALL_OBJECT] = CreateObject(3100, 510.07455444336, -85.365234375, 998.86749267578, 0, 0, 0);
	PoolBall[10][businessid][E_POOLBALL_OBJECT] = CreateObject(2997, 510.00054931641, -85.363563537598, 998.86749267578, 0, 0, 0);
	PoolBall[13][businessid][E_POOLBALL_OBJECT] = CreateObject(3000, 510.25915527344, -85.431137084961, 998.86749267578, 0, 0, 0);
	PoolBall[4][businessid][E_POOLBALL_OBJECT] = CreateObject(3102, 510.18399047852, -85.430549621582, 998.86749267578, 0, 0, 0);
	PoolBall[12][businessid][E_POOLBALL_OBJECT] = CreateObject(2999, 510.10900878906, -85.43196105957, 998.86749267578, 0, 0, 0);
	PoolBall[11][businessid][E_POOLBALL_OBJECT] = CreateObject(2998, 510.03570556641, -85.432624816895, 998.86749267578, 0, 0, 0);
	PoolBall[6][businessid][E_POOLBALL_OBJECT] = CreateObject(3104, 509.96197509766, -85.427406311035, 998.86749267578, 0, 0, 0);

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
	if(PlayerPoolStarted[businessid])
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
	if(!PlayerPoolStarted[businessid]) return 0;

	if(PlayerPoolAimer[businessid] != -1)
	{
		new
			playerid = PlayerPoolAimer[businessid];

		if(PlayerPoolDirection[businessid])
			PlayerPoolPower[businessid] -= 2.0;
		else
			PlayerPoolPower[businessid] += 2.0;
		if(PlayerPoolPower[businessid] <= 0)
		{
			PlayerPoolDirection[businessid] = 0;
			PlayerPoolPower[businessid] = 2.0;
		}
		else if(PlayerPoolPower[businessid] > 100.0)
		{
			PlayerPoolDirection[businessid] = 1;
			PlayerPoolPower[businessid] = 98.0;
		}
		new str[256];
		format(str, sizeof(str), "Press '~r~LEFT~w~' or '~r~RIGHT~w~' to change your camera position~n~Press '~y~Shoot~w~' to shoot~n~You power : ~y~%.0f%", PlayerPoolPower[businessid]);
		PlayerTextDrawSetString(playerid, pool[3][playerid], str);

		for(new a; a < 5; a++)
		{
			PlayerTextDrawShow(playerid, pool[a][playerid]);
		}
	}

	if(PlayerPoolLastShooter[businessid] != -1 && AreAllBallsStopped(businessid))
	{
		SetTimerEx("RestoreCamera", 800, 0, "dd", PlayerPoolLastShooter[businessid], businessid);
		PlayerPoolLastShooter[businessid] = -1;
	}
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
        SetObjectPos(PlayerPoolAimObject[businessid], x, y, Za);
        SetObjectRot(PlayerPoolAimObject[businessid], 7.0, 0, AimAngle[playerid][0] + 180);
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
	if(PlayerPoolAimer[businessid] == playerid) return 0;
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

stock IsBallInHole(i, businessid)
{
	if(IsObjectInSphere(PoolBall[i][businessid][E_POOLBALL_OBJECT],509.61123657,-85.79737091,998.86785889,0.0825)) return 1;
	else if(IsObjectInSphere(PoolBall[i][businessid][E_POOLBALL_OBJECT],510.67373657,-84.84423065,998.86785889,0.0825)) return 2;
	else if(IsObjectInSphere(PoolBall[i][businessid][E_POOLBALL_OBJECT],510.61914062,-83.88769531,998.86785889,0.0825)) return 3;
	else if(IsObjectInSphere(PoolBall[i][businessid][E_POOLBALL_OBJECT],509.61077881,-83.89227295,998.86785889,0.0825)) return 4;
	else if(IsObjectInSphere(PoolBall[i][businessid][E_POOLBALL_OBJECT],510.61825562,-85.80107880,998.86785889,0.0825)) return 5;
	else if(IsObjectInSphere(PoolBall[i][businessid][E_POOLBALL_OBJECT],509.55642700,-84.84602356,998.86785889,0.0825)) return 6;
	else return 0;
}

stock GetXYBehindObjectInAngle(objectid, Float:a, &Float:x2, &Float:y2, Float:distance)
{
	new Float:z;
	GetObjectPos(objectid, x2, y2, z);

	x2 += (distance * floatsin(-a+180, degrees));
	y2 += (distance * floatcos(-a+180, degrees));
}

forward PlayPoolSound(soundid);
public PlayPoolSound(soundid)
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

stock IsKeyJustDown(key, newkeys, oldkeys)
{
	if((newkeys & key) && !(oldkeys & key)) return 1;
	return 0;
}

stock IsKeyJustUp(key, newkeys, oldkeys)
{
	if(!(newkeys & key) && (oldkeys & key)) return 1;
	return 0;
}

CMD:pool(playerid, params[])
{
	if(!PlayingPool[playerid])
	{
		new businessid = IsPlayerInBusiness(playerid);
		PlayingPool[playerid] = true;
		
		PoolScore[playerid] = 0;
		if(!PlayerPoolStarted[businessid])
		{
			PlayerPoolStarted[businessid] = 1;
			RespawnPoolBalls(1, businessid);
		}
		new Cents = floatround(50 * 100, floatround_round);
		GiveMoney(playerid, -Cents);
        SendServerMessage(playerid, "[8Ball] {a4a4a4}You has started pool in %s you pay for %s.", BusinessInfo[businessid][E_BUSINESS_NAME], FormatMoney(Cents));
	}
	else
	{
		new businessid = IsPlayerInBusiness(playerid);
		if(PlayerPoolAimer[businessid] != playerid)
		{
			PlayingPool[playerid] = false;
			new
				count = GetPoolPlayersCount(businessid);

			if(count <= 0)
			{
				PlayerPoolStarted[businessid] = 0;
				RespawnPoolBalls(0, businessid);
			}
			RestorePoolStick(playerid);
            SendServerMessage(playerid, "[8Ball] {a4a4a4}You has exit pool in %s.", BusinessInfo[businessid][E_BUSINESS_NAME]);
		}
	}
	return 1;
}