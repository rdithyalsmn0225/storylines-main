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

function:PlayersUpdates()
{
	foreach(new playerid : Player)
	{
		SyncPlayerTime(playerid);
		if(AccountInfo[playerid][E_MASTERS_LOGGED] == false)
		{
			if(loginTime[playerid] > 0)
			{
				loginTime[playerid]++;
						
				if(loginTime[playerid] >= 300)
				{
					SendInfoMessage(playerid, "You were kicked for not logging in."); 
					KickEx(playerid); 
				}
			}
					
			if(registerTime[playerid] > 0)
			{
				registerTime[playerid]++;
						
				if(registerTime[playerid] >= 300)
				{
					SendInfoMessage(playerid, "You were kicked for not registering.");
					KickEx(playerid); 
				}
			}
		}
		if(PlayerInfo[playerid][E_CHARACTER_SPAWNED] == true && AccountInfo[playerid][E_MASTERS_LOGGED] == true)
		{
			AFKCheck(playerid);
			
			//Anti-Money Hack
			if(GetPlayerMoney(playerid) > PlayerInfo[playerid][E_CHARACTER_MONEY])
			{
				ResetPlayerMoney(playerid);
				GivePlayerMoney(playerid, PlayerInfo[playerid][E_CHARACTER_MONEY]);
			}

			if(characterPickTime[playerid] > 0)
			{
				characterPickTime[playerid]++;
					
				if(characterPickTime[playerid] >= 300)
				{
					SendInfoMessage(playerid, "You were kicked for not selecting a character.");
					KickEx(playerid);
				}
			}
					
			if (PlayerInfo[playerid][E_CHARACTER_ADMINJAILED] == true)
			{
				PlayerInfo[playerid][E_CHARACTER_ADMINJAIL]--; 
					
				if(PlayerInfo[playerid][E_CHARACTER_ADMINJAIL] < 1)
				{
					PlayerInfo[playerid][E_CHARACTER_ADMINJAILED] = false; 
					PlayerInfo[playerid][E_CHARACTER_ADMINJAIL] = 0; 
						
					SendServerMessage(playerid, "[Jail] {DEDEDE}You served your admin jail time.");
						
					new str[128];
					format(str, sizeof(str), "%s was released from admin jail.", ReturnName(playerid));
					SendAdminMessage(1, str);
						
					SetPlayerVirtualWorld(playerid, 0); SetPlayerInterior(playerid, 0);
					SetPlayerPosEx(playerid, 1553.0421, -1675.4706, 16.1953);
				}
			}

			if (PlayerInfo[playerid][E_CHARACTER_PRISONED] == true)
			{
				PlayerInfo[playerid][E_CHARACTER_PRISON]--; 
				new str[512];
				format(str, sizeof(str), "~w~%d Prison Time", PlayerInfo[playerid][E_CHARACTER_PRISON]);
				GameTextForPlayer(playerid, str, 100, 1);
				
				if(PlayerInfo[playerid][E_CHARACTER_PRISON] < 1)
				{
					PlayerInfo[playerid][E_CHARACTER_PRISONED] = false; 
					PlayerInfo[playerid][E_CHARACTER_PRISON] = 0; 
						
					SendServerMessage(playerid, "[Prison] {DEDEDE}you have been released from prison.");
						
					SetPlayerVirtualWorld(playerid, 0); SetPlayerInterior(playerid, 0);
					SetPlayerPosEx(playerid, 1797.4276,-1578.8496,14.0764);
				}
			}
				
			if(PlayerInfo[playerid][E_CHARACTER_DEATHFIX])
			{
				PlayerInfo[playerid][E_CHARACTER_DEATHFIX]++;
				if(PlayerInfo[playerid][E_CHARACTER_DEATHFIX] == 5)
				{
					PlayerInfo[playerid][E_CHARACTER_DEATHFIX] = 0;
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
			//Speedo
			new vehicleid = GetPlayerVehicleID(playerid);

			static
				Float:fSpeed,
				Float:fVelocity[3],
				Float:vhealth;

			GetVehicleHealth(vehicleid, vhealth);
			GetVehicleVelocity(vehicleid, fVelocity[0], fVelocity[1], fVelocity[2]);
			fSpeed = floatmul(floatsqroot((fVelocity[0] * fVelocity[0]) + (fVelocity[1] * fVelocity[1]) + (fVelocity[2] * fVelocity[2])), 100.0);

			if(IsPlayerInAnyVehicle(playerid) && GetPlayerState(playerid) == PLAYER_STATE_DRIVER && IsEngineVehicle(vehicleid))
			{
				new str[128], stra[128], stru[128];
				format(str, sizeof(str), "%.0f", fSpeed);

				new siren = GetVehicleParamsSirenState(vehicleid);

				if(siren == 1)
				{
					format(stru, sizeof(stru), "on");
				}
				else
				{
					format(stru, sizeof(stru), "off");
				}

				format(stra, sizeof(stra), "%d", VehicleInfo[vehicleid][E_VEHICLE_MILES]);
				ShowVehicleSpeedometer(playerid, "mph", "fuel", "miles", "siren", str, stra, stru, VehicleInfo[vehicleid][E_VEHICLE_FUEL]);

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
			if(GetPlayerWeapon(i) == 22 || GetPlayerWeapon(i) == 23 || GetPlayerWeapon(i) == 24 || GetPlayerWeapon(i) == 25
	 		|| GetPlayerWeapon(i) == 26 || GetPlayerWeapon(i) == 28 || GetPlayerWeapon(i) == 29 || GetPlayerWeapon(i) == 32)
			{
				if(PlayerInfo[i][E_CHARACTER_AMMOTYPE] == AMMO_TYPE_NORMAL)
				{
					if(Inventory_Count(i, "Regular Ammo"))
					{
						new astring[64], tstr[64];

						format(astring, sizeof(astring), "%s", ReturnWeaponName(GetPlayerWeapon(i)));
						PlayerTextDrawSetString(i, WeaponType[i], astring);
						PlayerTextDrawShow(i, WeaponType[i]);

						format(tstr, sizeof(tstr), "%d Regular", Inventory_Count(i, "Regular Ammo"));
						PlayerTextDrawSetString(i, WeaponAmmo[i], tstr);
						PlayerTextDrawShow(i, WeaponAmmo[i]);
					}
					else
					{
						PlayerInfo[i][E_CHARACTER_AMMOTYPE] = AMMO_TYPE_NONE;
						PlayerInfo[i][E_CHARACTER_EQUIPITEMS] = INVENTORY_NONE;
						ResetPlayerWeapons(i);
						PlayerTextDrawHide(i, WeaponType[i]);
						PlayerTextDrawHide(i, WeaponAmmo[i]);
					}
				}
				else if(PlayerInfo[i][E_CHARACTER_AMMOTYPE] == AMMO_TYPE_SURPLUS)
				{
					if(Inventory_Count(i, "Surplus Ammo"))
					{
						new astring[64], tstr[64];

						format(astring, sizeof(astring), "%s", ReturnWeaponName(GetPlayerWeapon(i)));
						PlayerTextDrawSetString(i, WeaponType[i], astring);
						PlayerTextDrawShow(i, WeaponType[i]);

						format(tstr, sizeof(tstr), "%d Surplus", Inventory_Count(i, "Surplus Ammo"));
						PlayerTextDrawSetString(i, WeaponAmmo[i], tstr);
						PlayerTextDrawShow(i, WeaponAmmo[i]);
					}
					else
					{
						PlayerInfo[i][E_CHARACTER_AMMOTYPE] = AMMO_TYPE_NONE;
						PlayerInfo[i][E_CHARACTER_EQUIPITEMS] = INVENTORY_NONE;
						ResetPlayerWeapons(i);
						PlayerTextDrawHide(i, WeaponType[i]);
						PlayerTextDrawHide(i, WeaponAmmo[i]);
					}
				}
				else if(PlayerInfo[i][E_CHARACTER_AMMOTYPE] == AMMO_TYPE_JHP)
				{
					if(Inventory_Count(i, "JHP Ammo"))
					{
						new astring[64], tstr[64];

						format(astring, sizeof(astring), "%s", ReturnWeaponName(GetPlayerWeapon(i)));
						PlayerTextDrawSetString(i, WeaponType[i], astring);
						PlayerTextDrawShow(i, WeaponType[i]);

						format(tstr, sizeof(tstr), "%d JHP", Inventory_Count(i, "JHP Ammo"));
						PlayerTextDrawSetString(i, WeaponAmmo[i], tstr);
						PlayerTextDrawShow(i, WeaponAmmo[i]);
					}
					else
					{
						PlayerInfo[i][E_CHARACTER_AMMOTYPE] = AMMO_TYPE_NONE;
						PlayerInfo[i][E_CHARACTER_EQUIPITEMS] = INVENTORY_NONE;
						ResetPlayerWeapons(i);
						PlayerTextDrawHide(i, WeaponType[i]);
						PlayerTextDrawHide(i, WeaponAmmo[i]);
					}
				}
				else if(PlayerInfo[i][E_CHARACTER_AMMOTYPE] == AMMO_TYPE_RUBBER)
				{
					if(Inventory_Count(i, "Rubber Ammo"))
					{
						new astring[64], tstr[64];

						format(astring, sizeof(astring), "%s", ReturnWeaponName(GetPlayerWeapon(i)));
						PlayerTextDrawSetString(i, WeaponType[i], astring);
						PlayerTextDrawShow(i, WeaponType[i]);

						format(tstr, sizeof(tstr), "%d Rubber", Inventory_Count(i, "Rubber Ammo"));
						PlayerTextDrawSetString(i, WeaponAmmo[i], tstr);
						PlayerTextDrawHide(i, WeaponType[i]);
						PlayerTextDrawHide(i, WeaponAmmo[i]);
					}
					else
					{
						PlayerInfo[i][E_CHARACTER_AMMOTYPE] = AMMO_TYPE_NONE;
						PlayerInfo[i][E_CHARACTER_EQUIPITEMS] = INVENTORY_NONE;
						ResetPlayerWeapons(i);
						PlayerTextDrawHide(i, WeaponType[i]);
						PlayerTextDrawHide(i, WeaponAmmo[i]);
					}
				}
				else if(PlayerInfo[i][E_CHARACTER_POLICEAMMO])
				{
					new astring[64], tstr[64];

					format(astring, sizeof(astring), "%s", ReturnWeaponName(GetPlayerWeapon(i)));
					PlayerTextDrawSetString(i, WeaponType[i], astring);
					PlayerTextDrawShow(i, WeaponType[i]);

					format(tstr, sizeof(tstr), "Tazer");
					PlayerTextDrawSetString(i, WeaponAmmo[i], tstr);
					PlayerTextDrawShow(i, WeaponAmmo[i]);
				}
				else
				{
					PlayerInfo[i][E_CHARACTER_AMMOTYPE] = AMMO_TYPE_NONE;
					PlayerInfo[i][E_CHARACTER_EQUIPITEMS] = INVENTORY_NONE;
					PlayerTextDrawHide(i, WeaponType[i]);
					PlayerTextDrawHide(i, WeaponAmmo[i]);
				}
			}
			else if(GetPlayerWeapon(i) == 5) 
			{
				new astring[128];
				if (PlayerInfo[i][E_CHARACTER_WEAPONTYPE] == 1)
				{
					format(astring, sizeof(astring), "Spike_Bat");
					SetPlayerAttachedObject(i, ATTACH_WEAPONS, -2200, 6, -0.044999, -0.025000, 0.000000, -3.299999, 0.000000, 0.000000, 1.742000, 1.905999, 1.117000);
				}
				else if (PlayerInfo[i][E_CHARACTER_WEAPONTYPE] == 2)
				{
					format(astring, sizeof(astring), "Wooden");
					SetPlayerAttachedObject(i, ATTACH_WEAPONS, -2201, 6, -0.233000, -0.021000, -0.115000, 3.299999, 0.000000, 0.000000, 4.358999, 1.672000, 1.533000);
				}
				else if (PlayerInfo[i][E_CHARACTER_WEAPONTYPE] == 3)
				{
					format(astring, sizeof(astring), "Nail_Bat");
					SetPlayerAttachedObject(i, ATTACH_WEAPONS, -2203, 6, -0.055999, -0.023000, 0.041999, -0.300000, 0.000000, 0.000000, 1.966000, 1.612000, 1.240000);
				}
				PlayerTextDrawSetString(i, WeaponType[i], astring);
				PlayerTextDrawShow(i, WeaponType[i]);
				PlayerTextDrawHide(i, WeaponAmmo[i]);
			}
			else if(GetPlayerWeapon(i) == 4) 
			{
				new astring[128];
				if (PlayerInfo[i][E_CHARACTER_WEAPONTYPE] == 1)
				{
					format(astring, sizeof(astring), "Broken_Bottle");
					SetPlayerAttachedObject(i, ATTACH_WEAPONS, -2210, 6, -0.088000, -0.015000, -0.153999, 0.000000, -7.600001, 0.000000, 1.862000, 1.506000, 1.838002);
				}
				else if (PlayerInfo[i][E_CHARACTER_WEAPONTYPE] == 2)
				{
					format(astring, sizeof(astring), "Crowbar");
					SetPlayerAttachedObject(i, ATTACH_WEAPONS, -2211, 6, -0.013000, -0.165000, -0.026000, 1.000003, -12.199998, 0.000000, 1.184000, 5.491996, 1.000000);
				}
				else if (PlayerInfo[i][E_CHARACTER_WEAPONTYPE] == 3)
				{
					format(astring, sizeof(astring), "Knife");
					RemovePlayerAttachedObject(i, 7);
				}
				PlayerTextDrawSetString(i, WeaponType[i], astring);
				PlayerTextDrawShow(i, WeaponType[i]);
				PlayerTextDrawHide(i, WeaponAmmo[i]);
			}
			else
			{
				RemovePlayerAttachedObject(i, 7);
				PlayerTextDrawHide(i, WeaponType[i]);
				PlayerTextDrawHide(i, WeaponAmmo[i]);
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
				return SendServerMessage(i, "[Paycheck] {DEDEDE}You didn't receive a paycheck this hour as you were AFK for more than 15 minutes.");
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
			ClearActorAnimations(BusinessInfo[id][E_BUSINESS_ACTOR]);
			ApplyActorAnimation(BusinessInfo[id][E_BUSINESS_ACTOR], "PED", "DUCK_cower", 4.1, 1, 1, 1, 1, 1);
		}
		else if(!BusinessInfo[id][E_BUSINESS_ROBBERYTIME])
		{
			ClearActorAnimations(BusinessInfo[id][E_BUSINESS_ACTOR]);
			ApplyActorAnimation(BusinessInfo[id][E_BUSINESS_ACTOR], "INT_SHOP", "shop_lookA", 4.1, 1, 1, 1, 1, 0);
			BusinessInfo[id][E_BUSINESS_ROBBERYTIME] = 0;
			foreach(new playerid : Player)
			{
				PlayerPlaySound(playerid, 0, 0, 0, 0);
			}
		}
	}	
	return 1;
}