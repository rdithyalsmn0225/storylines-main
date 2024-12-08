public PHY_OnObjectUpdate(objectid)
{
    foreach(new ii : Player)
    {
        if(PlayingPool[ii])
        {
            new businessid = IsPlayerInBusiness(ii);
            
            if (PoolInfo[businessid][E_POOL_STARTED])
            {
                for (new i; i < sizeof PoolBall; i++)
                {
                    if (objectid == PoolBall[i][businessid][E_POOLBALL_OBJECT] && PHY_IsObjectMoving(PoolBall[i][businessid][E_POOLBALL_OBJECT]))
                    {
                        new hole = IsPoolBallInHole(i, businessid);
                        if (hole)
                        {
                            new Float:speed, Float:vx, Float:vy, Float:vz;
                            PHY_GetObjectVelocity(PoolBall[i][businessid][E_POOLBALL_OBJECT], vx, vy, vz);
                            speed = floatsqroot(vx * vx + vy * vy) + 0.2;

                            PoolBall[i][businessid][E_POOLBALL_EXISTS] = 0;
                            PHY_DeleteObject(PoolBall[i][businessid][E_POOLBALL_OBJECT]);

                            PlayPoolSound(31803 + random(3));

                            switch (hole)
                            {
                                case 1: MoveObject(PoolBall[i][businessid][E_POOLBALL_OBJECT], 509.61123657, -85.79737091, 998.86785889 - 0.25, speed);
                                case 2: MoveObject(PoolBall[i][businessid][E_POOLBALL_OBJECT], 510.67373657, -84.84423065, 998.86785889 - 0.25, speed);
                                case 3: MoveObject(PoolBall[i][businessid][E_POOLBALL_OBJECT], 510.61914062, -83.88769531, 998.86785889 - 0.25, speed);
                                case 4: MoveObject(PoolBall[i][businessid][E_POOLBALL_OBJECT], 509.61077881, -83.89227295, 998.86785889 - 0.25, speed);
                                case 5: MoveObject(PoolBall[i][businessid][E_POOLBALL_OBJECT], 510.61825562, -85.80107880, 998.86785889 - 0.25, speed);
                                case 6: MoveObject(PoolBall[i][businessid][E_POOLBALL_OBJECT], 509.55642700, -84.84602356, 998.86785889 - 0.25, speed);
                            }

                            if (i == 15)
                            {
                                new string[128];
                                foreach (new p : Player)
                                {
                                    if (PlayingPool[p])
                                    {
                                        format(string, sizeof(string), "[8Ball] {DEDEDE}The winner is: %s because PoolBall 8 was pocketed.", ReturnName(p));
                                        SendPoolPlayersMessage(string);

                                        PlayingPool[p] = false;

                                        RestorePoolStick(p);
                                        HideHeaderMessage(p);
                                        PlayingPool[p] = false;

                                        if(PoolInfo[businessid][E_POOL_PLAYER1] == p)
                                        {
                                            PoolInfo[businessid][E_POOL_PLAYER1] = -1;
                                        }
                                        if(PoolInfo[businessid][E_POOL_PLAYER2] == p)
                                        {
                                            PoolInfo[businessid][E_POOL_PLAYER2] = -1;
                                        }
                                    }
                                }

                                PoolInfo[businessid][E_POOL_STARTED] = false;
                                PoolInfo[businessid][E_POOL_PLAYERAIMER] = -1;
                                if(PoolInfo[businessid][E_POOL_PLAYER1] == -1 && PoolInfo[businessid][E_POOL_PLAYER1] == -1)
                                {
                                    PoolInfo[businessid][E_POOL_STARTED] = false;
                                    RespawnPoolBalls(0, businessid);
                                }

                                RestoreCamera(PoolInfo[businessid][E_POOL_LASTSHOOTER], businessid);
                                PoolInfo[businessid][E_POOL_LASTSHOOTER] = -1;

                                return 1;
                            }
                            else
                            {
                                if (PlayerPoolBallType[PoolInfo[businessid][E_POOL_LASTSHOOTER]] == 0)
                                {
                                    if (i >= 1 && i <= 7)
                                        PlayerPoolBallType[PoolInfo[businessid][E_POOL_LASTSHOOTER]] = 1;
                                    else if (i >= 8 && i <= 14)
                                        PlayerPoolBallType[PoolInfo[businessid][E_POOL_LASTSHOOTER]] = 2;
                                }
                                else
                                {
                                    if ((PlayerPoolBallType[PoolInfo[businessid][E_POOL_LASTSHOOTER]] == 1 && i >= 8 && i <= 14) ||
                                        (PlayerPoolBallType[PoolInfo[businessid][E_POOL_LASTSHOOTER]] == 2 && i >= 1 && i <= 7))
                                    {
                                        if (PoolInfo[businessid][E_POOL_TURN] == PoolInfo[businessid][E_POOL_PLAYER1])
                                            PoolInfo[businessid][E_POOL_PLAYER2SCORE]++;
                                        else
                                            PoolInfo[businessid][E_POOL_PLAYER1SCORE]++;

                                        PoolInfo[businessid][E_POOL_TURN] = (PoolInfo[businessid][E_POOL_TURN] == PoolInfo[businessid][E_POOL_PLAYER1]
                                        ? PoolInfo[businessid][E_POOL_PLAYER2]
                                        : PoolInfo[businessid][E_POOL_PLAYER1]);

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
                                        
                                        SendPoolPlayersMessage("[8Ball] {DEDEDE}Wrong ball type! Opponent scores a point.");
                                        RestoreCamera(PoolInfo[businessid][E_POOL_LASTSHOOTER], businessid);
                                        return 1;
                                    }
                                }

                                if (PoolInfo[businessid][E_POOL_TURN] == PoolInfo[businessid][E_POOL_PLAYER1])
                                {
                                    PoolInfo[businessid][E_POOL_PLAYER1SCORE]++;
                                }
                                else
                                {
                                    PoolInfo[businessid][E_POOL_PLAYER2SCORE]++;
                                }

                                PoolInfo[businessid][E_POOL_TURN] = (PoolInfo[businessid][E_POOL_TURN] == PoolInfo[businessid][E_POOL_PLAYER1]
                                ? PoolInfo[businessid][E_POOL_PLAYER2]
                                : PoolInfo[businessid][E_POOL_PLAYER1]);

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

                                PlayerPlaySound(PoolInfo[businessid][E_POOL_TURN], 1250, 0.0, 0.0, 0.0);
                            }    
                            if (GetPoolBallsCount(businessid) <= 1)
                            {
                                PoolInfo[businessid][E_POOL_STARTED] = false;
                                PoolInfo[businessid][E_POOL_PLAYERAIMER] = -1;

                                RestoreCamera(PoolInfo[businessid][E_POOL_LASTSHOOTER], businessid);
                                PoolInfo[businessid][E_POOL_LASTSHOOTER] = -1;

                                foreach (new p : Player)
                                {
                                    if (PlayingPool[p])
                                    {
                                        new string[128];
                                        if (PoolInfo[businessid][E_POOL_PLAYER1SCORE] > PoolInfo[businessid][E_POOL_PLAYER2SCORE])
                                        {
                                            format(string, sizeof(string), "[8Ball] {DEDEDE}The winner is: %s with %d points.", ReturnName(PoolInfo[businessid][E_POOL_PLAYER1]), PoolInfo[businessid][E_POOL_PLAYER1SCORE]);
                                        }
                                        else if (PoolInfo[businessid][E_POOL_PLAYER2SCORE] > PoolInfo[businessid][E_POOL_PLAYER1SCORE])
                                        {
                                            format(string, sizeof(string), "[8Ball] {DEDEDE}The winner is: %s with %d points.", ReturnName(PoolInfo[businessid][E_POOL_PLAYER2]), PoolInfo[businessid][E_POOL_PLAYER2SCORE]);
                                        }
                                        else
                                        {
                                            format(string, sizeof(string), "[8Ball] {DEDEDE}The game is a draw with %d points each.", PoolInfo[businessid][E_POOL_PLAYER1SCORE]);
                                        }

                                        SendPoolPlayersMessage(string);
                                        RestorePoolStick(p);
                                        PlayingPool[p] = false;
                                        HideHeaderMessage(p);
                                        if(PoolInfo[businessid][E_POOL_PLAYER1] == p)
                                        {
                                            PoolInfo[businessid][E_POOL_PLAYER1] = -1;
                                        }
                                        if(PoolInfo[businessid][E_POOL_PLAYER2] == p)
                                        {
                                            PoolInfo[businessid][E_POOL_PLAYER2] = -1;
                                        }

                                        if(PoolInfo[businessid][E_POOL_PLAYER1] == -1 && PoolInfo[businessid][E_POOL_PLAYER1] == -1)
                                        {
                                            PoolInfo[businessid][E_POOL_STARTED] = false;
                                            RespawnPoolBalls(0, businessid);
                                        }
                                    }
                                }
                            }
                            else if (AreAllBallsStopped(businessid))
                            {
                                SetTimerEx("RestoreCamera", 800, 0, "dd", PoolInfo[businessid][E_POOL_LASTSHOOTER], businessid);
                                PoolInfo[businessid][E_POOL_LASTSHOOTER] = -1;
                            }
                        }
                        return 1;
                    }
                }
            }
        }
    }

	return 1;
}