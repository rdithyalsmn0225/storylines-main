//All Timer in gamemode init

stock ReturnHour()
{
	new time[36]; 
	new hour, minute, second;
	gettime(hour, minute, second);
	format(time, sizeof(time), "%02d:%02d", hour, minute);
	return time;
}

function:SyncPlayerTime(playerid)
{
	new hour, minutes, second;
	gettime(hour, minutes, second);
	SetPlayerTime(playerid, hour, minutes);
	SetClock(hour, minutes, second);
	return 1;
}

function:WeatherRotator()
{
	new index = random(sizeof(g_aWeatherRotations));
	SetWeather(g_aWeatherRotations[index]);
}

function:OnPlayerUpdateEx()
{
	foreach(new playerid : Player)
	{
		if(AccountInfo[playerid][E_MASTERS_LOGGED] == false)
		{
			if(loginTime[playerid] > 0)
			{
				loginTime[playerid]++;
						
				if(loginTime[playerid] >= 300)
				{
					SendServerMessage(playerid, "You were kicked for not logging in."); 
					KickEx(playerid); 
				}
			}
					
			if(registerTime[playerid] > 0)
			{
				registerTime[playerid]++;
						
				if(registerTime[playerid] >= 300)
				{
					SendServerMessage(playerid, "You were kicked for not registering.");
					KickEx(playerid); 
				}
			}
		}
		if(PlayerInfo[playerid][E_CHARACTER_SPAWNED] == true)
		{
			AFKCheck(playerid);
			UpdateNameTagsTicks(playerid);
			SyncPlayerTime(playerid);

			new string[128];
			
			if(GetPlayerTeam(playerid) == PLAYER_STATE_WOUNDED && PlayerInfo[playerid][E_CHARACTER_INJURED])
			{
				SetPlayerHealthEx(playerid, 100);
				format(string, sizeof(string), "(( Has been injured %d times, /damages %d for more information. ))", TotalPlayerDamages[playerid], playerid);
				SetPlayerChatBubble(playerid, string, COLOR_ORANGE, 30.0, 2500); 
				
				if(IsPlayerInAnyVehicle(playerid))
				{
					ApplyAnimation(playerid, "ped", "CAR_dead_LHS", 4.1, 0, 0, 0, 1, 0, 1);
				}
				else
				{
					ApplyAnimation(playerid, "WUZI", "CS_Dead_Guy", 4.1, 0, 1, 1, 1, 0, 1);	
				}	
			}

			else if(GetPlayerTeam(playerid) == PLAYER_STATE_DEAD && PlayerInfo[playerid][E_CHARACTER_DEATH])
			{
				SetPlayerHealthEx(playerid, 100);
				SetPlayerChatBubble(playerid, "(( THIS PLAYER IS DEAD ))", COLOR_ORANGE, 30.0, 2500); 
				if(IsPlayerInAnyVehicle(playerid))
				{
					ApplyAnimation(playerid, "ped", "CAR_dead_LHS", 4.1, 0, 0, 0, 1, 0, 1);
				}
				else
				{
					ApplyAnimation(playerid, "WUZI", "CS_Dead_Guy", 4.1, 0, 1, 1, 1, 0, 1);	
				}	
			}

			if(IsPlayerInAnyVehicle(playerid) && IsPoliceVehicle(GetPlayerVehicleID(playerid)))
			{
				if(ReturnFactionType(playerid) == FACTION_TYPE_POLICE)
				{
					DetectVehicleInFront(playerid);
				}
			}
			
			if(PlayerInfo[playerid][E_CHARACTER_TOGHUD] == false)
	    	{
				if(IsPlayerInAnyVehicle(playerid))
				{
					PlayerTextDrawShow(playerid, Street[0][playerid]);
					PlayerTextDrawShow(playerid, Street[1][playerid]);
					p_Direction[playerid] = true;
				}
				else
				{
					PlayerTextDrawHide(playerid, Street[0][playerid]);
					PlayerTextDrawHide(playerid, Street[1][playerid]);
					p_Direction[playerid] = false;
				}

				SetPlayerProgressBarValue(playerid, HEBAR[0][playerid], PlayerInfo[playerid][E_CHARACTER_HUNGRY]);
				SetPlayerProgressBarColour(playerid, HEBAR[0][playerid], ConvertHBEColor(PlayerInfo[playerid][E_CHARACTER_HUNGRY]));
				ShowPlayerProgressBar(playerid, HEBAR[0][playerid]);
			}

			if(characterPickTime[playerid] > 0)
			{
				characterPickTime[playerid]++;
					
				if(characterPickTime[playerid] >= 300)
				{
					SendServerMessage(playerid, "You were kicked for not selecting a character.");
					KickEx(playerid);
				}
			}
					
			if(PlayerInfo[playerid][E_CHARACTER_HUNGRY] > 100.0)
			{
				PlayerInfo[playerid][E_CHARACTER_HUNGRY] = 100.0;
			}
			if(PlayerInfo[playerid][E_CHARACTER_HUNGRY] < 0)
			{
				PlayerInfo[playerid][E_CHARACTER_HUNGRY] = 0;
			}
			for(new i; i < 8; i++)
			{
				if(PlayerInfo[playerid][E_CHARACTER_WOUND][i] < 0)
				{
					PlayerInfo[playerid][E_CHARACTER_WOUND][i] = 0;
				}
			}

			if (PlayerInfo[playerid][E_CHARACTER_ADMINJAILED] == true)
			{
				PlayerInfo[playerid][E_CHARACTER_ADMINJAIL]--; 
					
				if(PlayerInfo[playerid][E_CHARACTER_ADMINJAIL] < 1)
				{
					PlayerInfo[playerid][E_CHARACTER_ADMINJAILED] = false; 
					PlayerInfo[playerid][E_CHARACTER_ADMINJAIL] = 0; 
						
					SendInfoMessage(playerid, "[JAIL] You served your admin jail time.");
						
					new str[128];
					format(str, sizeof(str), "%s was released from admin jail.", ReturnName(playerid));
					SendAdminMessage(1, str);
						
					SetPlayerVirtualWorldEx(playerid, 0); SetPlayerInteriorEx(playerid, 0);
					SetPlayerPosEx(playerid, 1553.0421, -1675.4706, 16.1953);
				}
			}

			if (PlayerInfo[playerid][E_CHARACTER_PRISONED] == true && PlayerInfo[playerid][E_CHARACTER_PRISON])
			{
				PlayerInfo[playerid][E_CHARACTER_PRISON]--; 
				new str[64];
				format(str, sizeof(str), "~w~%d Prison Time", PlayerInfo[playerid][E_CHARACTER_PRISON]);
				ShowHeaderMessage(playerid, "Prison", str, 1);
				
				if(PlayerInfo[playerid][E_CHARACTER_PRISON] < 1)
				{
					PlayerInfo[playerid][E_CHARACTER_PRISONED] = false; 
					PlayerInfo[playerid][E_CHARACTER_PRISON] = 0; 
						
					SendInfoMessage(playerid, "[PRISON] you have been released from prison.");
						
					SetPlayerVirtualWorldEx(playerid, 0); SetPlayerInteriorEx(playerid, 0);
					SetPlayerPosEx(playerid, 1797.4276,-1578.8496,14.0764);
					HideHeaderMessage(playerid);
				}
			}
				
			if(PlayerTakingLicense[playerid] && PlayerLicenseTime[playerid] <= 60)
			{
				PlayerLicenseTime[playerid]--; 
					
				new	str[128];
					
				format(str, sizeof(str), "~w~%d", PlayerLicenseTime[playerid]);
				GameTextForPlayer(playerid, str, 2000, 3); 
					
				if(PlayerLicenseTime[playerid] < 1)
				{
					StopDriverstest(playerid);
					SendClientMessage(playerid, COLOR_DARKGREEN, "You took too long and failed."); 
				}
			}

			new vehicleid = GetPlayerVehicleID(playerid);
			if(IsPlayerInAnyVehicle(playerid) && GetPlayerState(playerid) == PLAYER_STATE_DRIVER && IsEngineVehicle(vehicleid))
			{
				new Float:velocity[3];
				GetVehicleVelocity(vehicleid, velocity[0], velocity[1], velocity[2]);

				new Float:speed = floatsqroot((velocity[0] * velocity[0]) + (velocity[1] * velocity[1]) + (velocity[2] * velocity[2])) * 100;

				if (PlayerSpeedLimit[playerid] > 0 && speed > float(PlayerSpeedLimit[playerid])) 
				{
					SetVehicleVelocity(vehicleid, velocity[0] * 0.8, velocity[1] * 0.8, velocity[2] * 0.8); 
				}

				new Float:rz;
				new p_PreviousDirection[8];

				strcat((p_PreviousDirection[0] = EOS, p_PreviousDirection), PlayerDirection[playerid]);
				GetVehicleZAngle(GetPlayerVehicleID(playerid), rz);

				if(rz >= 348.75 && rz < 11.25) PlayerDirection[playerid] = "N";
				else if(rz >= 303.75 && rz < 326.25) PlayerDirection[playerid] = "NE";
				else if(rz >= 258.75 && rz < 281.25) PlayerDirection[playerid] = "E";
				else if(rz >= 213.75 && rz < 236.25) PlayerDirection[playerid] = "SE";
				else if(rz >= 168.75 && rz < 191.25) PlayerDirection[playerid] = "S";
				else if(rz >= 123.25 && rz < 146.25) PlayerDirection[playerid] = "SW";
				else if(rz >= 78.75 && rz < 101.25) PlayerDirection[playerid] = "W";
				else if(rz >= 33.75 && rz < 56.25) PlayerDirection[playerid] = "NW";

				PlayerTextDrawSetString(playerid, Street[0][playerid], PlayerDirection[playerid]);

				new str1[180];
				format(str1, sizeof(str1), "%s~n~%s", ReturnLocationStreet(playerid), ReturnLocation(playerid));
				PlayerTextDrawSetString(playerid, Street[1][playerid], str1);

				static
					Float:fSpeed,
					Float:fVelocity[3],
					Float:vhealth;

				GetVehicleHealth(vehicleid, vhealth);
				GetVehicleVelocity(vehicleid, fVelocity[0], fVelocity[1], fVelocity[2]);
				fSpeed = floatmul(floatsqroot((fVelocity[0] * fVelocity[0]) + (fVelocity[1] * fVelocity[1]) + (fVelocity[2] * fVelocity[2])), 100.0);
				
				new str[128], stra[128];
				format(str, sizeof(str), "%.0f Mph", fSpeed);

				if(vhealth <= 350.0) vhealth = 0.0;
				else if(vhealth > 1000.0) vhealth = 1000.0;

				format(stra, sizeof(stra), "%s", ConvertTextDrawsToDots(VehicleInfo[vehicleid][E_VEHICLE_FUEL]));

				if(PlayerInfo[playerid][E_CHARACTER_TOGHUD] == false && PlayerInfo[playerid][E_CHARACTER_SPAWNED] == true)
	    		{
					PlayerTextDrawSetString(playerid, speedo[14][playerid], str);
					PlayerTextDrawShow(playerid, speedo[14][playerid]);
					PlayerTextDrawSetString(playerid, speedo[13][playerid], stra);
					PlayerTextDrawShow(playerid, speedo[13][playerid]);
				}

				for (new i = 0; i != MAX_BARRICADES; i ++) if (BarricadeInfo[i][E_CADE_EXISTS] && BarricadeInfo[i][E_CADE_TYPE] == 1 && IsPlayerInRangeOfPoint(playerid, 3.0, BarricadeInfo[i][E_CADE_POS][0], BarricadeInfo[i][E_CADE_POS][1], BarricadeInfo[i][E_CADE_POS][2]))
				{
					new
						tires[4];

					GetVehicleDamageStatus(vehicleid, tires[0], tires[1], tires[2], tires[3]);

					if (tires[3] != 1111) {
						UpdateVehicleDamageStatus(vehicleid, tires[0], tires[1], tires[2], 1111);
					}
					break;
				}
			}
		}
	}
	return 1;
}

function:OnPlayerWeaponUpdate()
{
	foreach(new i : Player)
	{
		if(PlayerInfo[i][E_CHARACTER_SPAWNED] == true && AccountInfo[i][E_MASTERS_LOGGED] == true)
		{
			new astring[64];
			if(GetPlayerWeapon(i) == 22 || GetPlayerWeapon(i) == 23 || GetPlayerWeapon(i) == 24 || GetPlayerWeapon(i) == 25
	 		|| GetPlayerWeapon(i) == 26 || GetPlayerWeapon(i) == 28 || GetPlayerWeapon(i) == 29 || GetPlayerWeapon(i) == 32)
			{
				
				if(PlayerInfo[i][E_CHARACTER_AMMOTYPE] == AMMO_TYPE_NORMAL)
				{
					if(Inventory_Count(i, "Regular Ammo"))
					{

						format(astring, sizeof(astring), "Weapons - %s - %d Regular", ReturnWeaponName(GetPlayerWeapon(i)), Inventory_Count(i, "Regular Ammo"));
						PlayerTextDrawSetString(i, WeaponType[i], astring);
						PlayerTextDrawShow(i, WeaponType[i]);
					}
					else
					{
						PlayerInfo[i][E_CHARACTER_AMMOTYPE] = AMMO_TYPE_NONE;
						PlayerInfo[i][E_CHARACTER_EQUIPITEMS] = INVENTORY_NONE;
						ResetPlayerWeapons(i);
						PlayerTextDrawHide(i, WeaponType[i]);
					}
				}
				else if(PlayerInfo[i][E_CHARACTER_AMMOTYPE] == AMMO_TYPE_SURPLUS)
				{
					if(Inventory_Count(i, "Surplus Ammo"))
					{

						format(astring, sizeof(astring), "Weapons - %s - %d Surplus", ReturnWeaponName(GetPlayerWeapon(i)), Inventory_Count(i, "Surplus Ammo"));
						PlayerTextDrawSetString(i, WeaponType[i], astring);
						PlayerTextDrawShow(i, WeaponType[i]);
					}
					else
					{
						PlayerInfo[i][E_CHARACTER_AMMOTYPE] = AMMO_TYPE_NONE;
						PlayerInfo[i][E_CHARACTER_EQUIPITEMS] = INVENTORY_NONE;
						ResetPlayerWeapons(i);
						PlayerTextDrawHide(i, WeaponType[i]);
					}
				}
				else if(PlayerInfo[i][E_CHARACTER_AMMOTYPE] == AMMO_TYPE_JHP)
				{
					if(Inventory_Count(i, "JHP Ammo"))
					{

						format(astring, sizeof(astring), "Weapons - %s - %d Jacket Hollow Point", ReturnWeaponName(GetPlayerWeapon(i)), Inventory_Count(i, "JHP Ammo"));
						PlayerTextDrawSetString(i, WeaponType[i], astring);
						PlayerTextDrawShow(i, WeaponType[i]);
					}
					else
					{
						PlayerInfo[i][E_CHARACTER_AMMOTYPE] = AMMO_TYPE_NONE;
						PlayerInfo[i][E_CHARACTER_EQUIPITEMS] = INVENTORY_NONE;
						ResetPlayerWeapons(i);
						PlayerTextDrawHide(i, WeaponType[i]);
					}
				}
				else if(PlayerInfo[i][E_CHARACTER_AMMOTYPE] == AMMO_TYPE_RUBBER)
				{
					if(Inventory_Count(i, "Rubber Ammo"))
					{

						format(astring, sizeof(astring), "Weapons - %s - %d Rubber", ReturnWeaponName(GetPlayerWeapon(i)), Inventory_Count(i, "Rubber Ammo"));
						PlayerTextDrawSetString(i, WeaponType[i], astring);
						PlayerTextDrawShow(i, WeaponType[i]);
					}
					else
					{
						PlayerInfo[i][E_CHARACTER_AMMOTYPE] = AMMO_TYPE_NONE;
						PlayerInfo[i][E_CHARACTER_EQUIPITEMS] = INVENTORY_NONE;
						ResetPlayerWeapons(i);
						PlayerTextDrawHide(i, WeaponType[i]);
					}
				}
				else if(PlayerInfo[i][E_CHARACTER_POLICEAMMO])
				{
					format(astring, sizeof(astring), "Weapons - %s - Tazer", ReturnWeaponName(GetPlayerWeapon(i)));
					PlayerTextDrawSetString(i, WeaponType[i], astring);
					PlayerTextDrawShow(i, WeaponType[i]);
				}
				else
				{
					PlayerInfo[i][E_CHARACTER_AMMOTYPE] = AMMO_TYPE_NONE;
					PlayerInfo[i][E_CHARACTER_EQUIPITEMS] = INVENTORY_NONE;
					PlayerTextDrawHide(i, WeaponType[i]);
				}
			}
			else if(GetPlayerWeapon(i) == 5) 
			{
				if (PlayerInfo[i][E_CHARACTER_WEAPONTYPE] == 1)
				{
					format(astring, sizeof(astring), "Weapons - Spike_Bat");
					SetPlayerAttachedObject(i, ATTACH_WEAPONS, 2045, 6, 0.048000, 0.021999, 0.218000, 94.899993, 0.000000, 0.000000, 1.557000, 1.229001, 1.445999);
				}
				else if (PlayerInfo[i][E_CHARACTER_WEAPONTYPE] == 2)
				{
					format(astring, sizeof(astring), "Weapons - Cutscene_Bat");
					SetPlayerAttachedObject(i, ATTACH_WEAPONS, 19914, 6, 0.067000, 0.040999, -0.120000, 0.000000, -89.700027, -4.099999, 1.060000, 1.350001, 1.193000);
				}
				else if (PlayerInfo[i][E_CHARACTER_WEAPONTYPE] == 3)
				{
					format(astring, sizeof(astring), "Weapons - Baseball_Bat");
				}
				PlayerTextDrawSetString(i, WeaponType[i], astring);
				PlayerTextDrawShow(i, WeaponType[i]);
			}
			else if(GetPlayerWeapon(i) == 4) 
			{
				if (PlayerInfo[i][E_CHARACTER_WEAPONTYPE] == 1)
				{
					format(astring, sizeof(astring), "Weapons - Beer Bottle");
					SetPlayerAttachedObject(i, ATTACH_WEAPONS, 1484, 6, 0.164000, -0.026000, 0.051999, 11.900003, -156.600097, 0.000000, 1.353998, 1.580001, 1.470999);
				}
				else if (PlayerInfo[i][E_CHARACTER_WEAPONTYPE] == 2)
				{
					format(astring, sizeof(astring), "Weapons - Marcos_Knife");
					SetPlayerAttachedObject(i, ATTACH_WEAPONS, 19583, 6, 0.089000, 0.039000, 0.000000, -89.199966, 176.400009, 3.699986, 1.000000, 1.000000, 1.526998);
				}
				else if (PlayerInfo[i][E_CHARACTER_WEAPONTYPE] == 3)
				{
					format(astring, sizeof(astring), "Weapons - Knife");
					RemovePlayerAttachedObject(i, 7);
				}
				PlayerTextDrawSetString(i, WeaponType[i], astring);
				PlayerTextDrawShow(i, WeaponType[i]);
			}
			else if(GetPlayerWeapon(i) == 1) 
			{
				if (PlayerInfo[i][E_CHARACTER_WEAPONTYPE] == 1)
				{
					format(astring, sizeof(astring), "Weapons - Glove");
					SetPlayerAttachedObject(i, ATTACH_WEAPONS, 19556, 6, 0.000000, -0.004000, 0.000000, -14.500018, -103.900199, -18.500011, 0.874999, 1.501999, 1.643999);
					SetPlayerAttachedObject(i, ATTACH_WEAPONS2, 19555, 5, 0.027000, 0.010999, -0.009999, 65.199920, -69.500038, -98.999908, 1.201999, 1.312999, 1.600999);
				}
				PlayerTextDrawSetString(i, WeaponType[i], astring);
				PlayerTextDrawShow(i, WeaponType[i]);
			}
			else if(GetPlayerWeapon(i) == 11) 
			{
				if (PlayerInfo[i][E_CHARACTER_WEAPONTYPE] == 1)
				{
					format(astring, sizeof(astring), "Weapons - Hammer");
					SetPlayerAttachedObject(i, ATTACH_WEAPONS, 18635, 6, -0.051999, -0.032999, -0.003999, 0.000000, 4.299999, 0.000000, 1.745000, 1.808000, 1.000000);
				}
				else if (PlayerInfo[i][E_CHARACTER_WEAPONTYPE] == 2)
				{
					format(astring, sizeof(astring), "Weapons - Wrench");
					SetPlayerAttachedObject(i, ATTACH_WEAPONS, 18633, 6, 0.082000, 0.028999, 0.000000, 93.500076, -82.800064, 3.700004, 2.883999, 0.853999, 1.561998);
				}
				else if (PlayerInfo[i][E_CHARACTER_WEAPONTYPE] == 3)
				{
					format(astring, sizeof(astring), "Weapons - Broom");
					SetPlayerAttachedObject(i, ATTACH_WEAPONS, 19622, 6, 0.076999, 0.032000, 0.029000, 178.999984, 6.899997, 0.000000, 1.763000, 1.664000, 0.796000);
				}
				PlayerTextDrawSetString(i, WeaponType[i], astring);
				PlayerTextDrawShow(i, WeaponType[i]);
			}
			else
			{
				RemovePlayerAttachedObject(i, ATTACH_WEAPONS);
				RemovePlayerAttachedObject(i, ATTACH_WEAPONS2);
				PlayerTextDrawHide(i, WeaponType[i]);
			}
		}
	}
	return 1;
}

function:FunctionPaychecks()
{
	foreach(new i : Player)
	{
		PlayerInfo[i][E_CHARACTER_PAYCHECKTIMER]++;
		if(PlayerInfo[i][E_CHARACTER_PAYCHECKTIMER] >= 60)
		{
			if(PlayerInfo[i][E_CHARACTER_AFK] && PlayerInfo[i][E_CHARACTER_AFKTIME] > 900)
			{
				PlayerInfo[i][E_CHARACTER_PAYCHECKTIMER] = 0;
				return SendInfoMessage(i, "[Paycheck] You didn't receive a paycheck this hour as you were AFK for more than 15 minutes.");
			}
			else
			{
				PlayerInfo[i][E_CHARACTER_PAYCHECKTIMER] = 0;
				CallPaycheck(i); 
			}
		}
	}
	return 1;
}

function:OnPlayerMinutesUpdate()
{
	foreach(new i : Player)
	{
		if(PlayerInfo[i][E_CHARACTER_ROBBERYCD] > 0)
		{
			PlayerInfo[i][E_CHARACTER_ROBBERYCD]--;
		}
		if(!PlayerInfo[i][E_CHARACTER_ROBBERYCD])
		{
			PlayerInfo[i][E_CHARACTER_ROBBERYCD] = 0;
		}
	}
	for(new id = 1; id < MAX_BUSINESS; id++)
	{
		if(BusinessInfo[id][E_BUSINESS_ROBBERYTIME] > 0)
		{
			BusinessInfo[id][E_BUSINESS_ROBBERYTIME]--;
			ClearDynamicActorAnimations(BusinessInfo[id][E_BUSINESS_ACTOR]);
			ApplyDynamicActorAnimation(BusinessInfo[id][E_BUSINESS_ACTOR], "PED", "DUCK_cower", 4.1, 0, 0, 0, 1, 0);
		}
		else
		{
			ClearDynamicActorAnimations(BusinessInfo[id][E_BUSINESS_ACTOR]);
			ApplyDynamicActorAnimation(BusinessInfo[id][E_BUSINESS_ACTOR], "SHOP", "SHP_Serve_Idle", 4.1, 0, 0, 0, 1, 0);
			BusinessInfo[id][E_BUSINESS_ROBBERYTIME] = 0;
			foreach(new playerid : Player)
			{
				PlayerPlaySound(playerid, 0, 0, 0, 0);
			}
		}
	}	
	return 1;
}