//All Timer in gamemode init

stock ReturnHour()
{
	new time[36]; 
	
	format(time, sizeof(time), "%02d:%02d", RealTime_GetHour(), RealTime_GetMinute());
	return time;
}

function:PlayersUpdates()
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
						
					SendServerMessage(playerid, "[Jail] {cdd0d1}You served your admin jail time.");
						
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
						
					SendServerMessage(playerid, "[Prison] {cdd0d1}you have been released from prison.");
						
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
				new str[128], stri[128], stru[128], stra[128];
				format(str, sizeof(str), "%.0f", fSpeed);

				if(VehicleInfo[vehicleid][E_VEHICLE_FUEL] >= 100.0)
					format(stri, sizeof(stri), "-~n~-~n~-~n~-~n~-~n~-~n~-~n~");
				else if(VehicleInfo[vehicleid][E_VEHICLE_FUEL] >= 80.0)
					format(stri, sizeof(stri), "-~n~-~n~-~n~-~n~-~n~-~n~");
				else if(VehicleInfo[vehicleid][E_VEHICLE_FUEL] >= 70.0)
					format(stri, sizeof(stri), "-~n~-~n~-~n~-~n~-~n~");
				else if(VehicleInfo[vehicleid][E_VEHICLE_FUEL] >= 40.0)
					format(stri, sizeof(stri), "-~n~-~n~-~n~-~n~");
				else if(VehicleInfo[vehicleid][E_VEHICLE_FUEL] >= 30.0)
					format(stri, sizeof(stri), "-~n~-~n~-~n~");
				else if(VehicleInfo[vehicleid][E_VEHICLE_FUEL] >= 20.0)
					format(stri, sizeof(stri), "-~n~-~n~");
				else if(VehicleInfo[vehicleid][E_VEHICLE_FUEL] >= 0.0)
					format(stri, sizeof(stri), "-~n~");
				else if(VehicleInfo[vehicleid][E_VEHICLE_FUEL] <= 0.0)
					format(stri, sizeof(stri), "");

				if(VehicleInfo[vehicleid][E_VEHICLE_LIGHTS] == false)
				{
					format(stru, sizeof(stru), "~r~D");
					format(stra, sizeof(stra), "~r~/~n~/~n~/");
				}
				else
				{
					format(stru, sizeof(stru), "~g~D");
					format(stra, sizeof(stra), "~g~/~n~/~n~/");
				}
				ShowVehicleSpeedometer(playerid, "MPH", "I", "ld_dual:white", "ld_dual:white", "0", str, stri, stru, stra);

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
			RealTime_SyncPlayerWorldTime(playerid);
		}
	}
	return 1;
}

function:WeaponUpdate()
{
	foreach(new i : Player)
	{
		if(PlayerInfo[i][E_CHARACTER_SPAWNED] == true && AccountInfo[i][E_MASTERS_LOGGED] == true)
		{
			if(GetPlayerWeapon(i) == 22) 
			{
				if(Inventory_Count(i, "9mm"))
				{
					new astring[128];
					new tstr[128];
					if (PlayerInfo[i][E_CHARACTER_WEAPONTYPE] == 1)
					{
						format(astring, sizeof(astring), "Glock_19");
						SetPlayerAttachedObject(i, ATTACH_WEAPONS, -2204, 6, -0.036999, -0.009000, -0.021000, 0.000000, -5.499999, 6.799997, 1.043000, 1.172000, 1.069999);
					}
					else if (PlayerInfo[i][E_CHARACTER_WEAPONTYPE] == 2)
					{
						format(astring, sizeof(astring), "Glock_17");
						SetPlayerAttachedObject(i, ATTACH_WEAPONS, -2205, 6, -0.023000, -0.007000, -0.006000, 0.000000, 0.000000, -1.400000, 1.390999, 1.513000, 1.172000);
					}
					else if (PlayerInfo[i][E_CHARACTER_WEAPONTYPE] == 3)
					{
						format(astring, sizeof(astring), "Glock_P80");
						SetPlayerAttachedObject(i, ATTACH_WEAPONS, -2206, 6, 0.000000, -0.010999, 0.000000, 0.000000, -11.199995, 8.399997, 1.231001, 1.625002, 1.128000);
					}
						
					PlayerTextDrawSetString(i, WeaponType[i], astring);
					PlayerTextDrawShow(i, WeaponType[i]);

					format(tstr, sizeof(tstr), "%d", Inventory_Count(i, "9mm"));
					PlayerTextDrawSetString(i, WeaponAmmo[i], tstr);
					PlayerTextDrawShow(i, WeaponAmmo[i]);
				}
				else
				{
					PlayerInfo[i][E_CHARACTER_EQUIPITEMS] = INVENTORY_NONE;
					ResetPlayerWeapons(i);
					PlayerTextDrawHide(i, WeaponAmmo[i]);
				}
			}
			else if(GetPlayerWeapon(i) == 23) 
			{
				if(PlayerInfo[i][E_CHARACTER_POLICEAMMO])
				{
					new astring[128];
					new tstr[128];

					if (PlayerInfo[i][E_CHARACTER_WEAPONTYPE] == 1)format(astring, sizeof(astring), "Tazer");
					PlayerTextDrawSetString(i, WeaponType[i], astring);
					PlayerTextDrawShow(i, WeaponType[i]);
					PlayerTextDrawSetString(i, WeaponType[i], astring);
					PlayerTextDrawShow(i, WeaponType[i]);
						
					format(tstr, sizeof(tstr), "%d-XREP", PlayerInfo[i][E_CHARACTER_POLICEAMMO]);
					PlayerTextDrawSetString(i, WeaponAmmo[i], tstr);
					PlayerTextDrawShow(i, WeaponAmmo[i]);

					RemovePlayerAttachedObject(i, 7);
				}
				else
				{
					PlayerInfo[i][E_CHARACTER_EQUIPITEMS] = INVENTORY_NONE;
					ResetPlayerWeapons(i);
					PlayerTextDrawHide(i, WeaponAmmo[i]);
				}
			}
			else if(GetPlayerWeapon(i) == 24) 
			{
				if(Inventory_Count(i, "9mm"))
				{
					new astring[128];
					new tstr[128];
					if (PlayerInfo[i][E_CHARACTER_WEAPONTYPE] == 1)
					{
						format(astring, sizeof(astring), "Night Hawk");
						SetPlayerAttachedObject(i, ATTACH_WEAPONS, -2204, 6, -0.036999, -0.009000, -0.021000, 0.000000, -5.499999, 6.799997, 1.043000, 1.172000, 1.069999);
					}
					else if (PlayerInfo[i][E_CHARACTER_WEAPONTYPE] == 2)
					{
						format(astring, sizeof(astring), "Deagle");
						SetPlayerAttachedObject(i, ATTACH_WEAPONS, -2205, 6, -0.023000, -0.007000, -0.006000, 0.000000, 0.000000, -1.400000, 1.390999, 1.513000, 1.172000);
					}
					else if (PlayerInfo[i][E_CHARACTER_WEAPONTYPE] == 3)
					{
						format(astring, sizeof(astring), "Glock_P80");
						SetPlayerAttachedObject(i, ATTACH_WEAPONS, -2206, 6, 0.000000, -0.010999, 0.000000, 0.000000, -11.199995, 8.399997, 1.231001, 1.625002, 1.128000);
					}
						
					PlayerTextDrawSetString(i, WeaponType[i], astring);
					PlayerTextDrawShow(i, WeaponType[i]);

					format(tstr, sizeof(tstr), "%d", Inventory_Count(i, "9mm"));
					PlayerTextDrawSetString(i, WeaponAmmo[i], tstr);
					PlayerTextDrawShow(i, WeaponAmmo[i]);
				}
				else
				{
					PlayerInfo[i][E_CHARACTER_EQUIPITEMS] = INVENTORY_NONE;
					ResetPlayerWeapons(i);
					PlayerTextDrawHide(i, WeaponAmmo[i]);
				}
			}

			//RUBBER
			else if(GetPlayerWeapon(i) == 25) 
			{
				if(PlayerInfo[i][E_CHARACTER_POLICEAMMO])
				{
					new astring[128];
					new tstr[128];

					if (PlayerInfo[i][E_CHARACTER_WEAPONTYPE] == 1)format(astring, sizeof(astring), "Riot_Shotgun");
					PlayerTextDrawSetString(i, WeaponType[i], astring);
					PlayerTextDrawShow(i, WeaponType[i]);
					PlayerTextDrawSetString(i, WeaponType[i], astring);
					PlayerTextDrawShow(i, WeaponType[i]);
						
					format(tstr, sizeof(tstr), "%d-Rubber", PlayerInfo[i][E_CHARACTER_POLICEAMMO]);
					PlayerTextDrawSetString(i, WeaponAmmo[i], tstr);
					PlayerTextDrawShow(i, WeaponAmmo[i]);

					RemovePlayerAttachedObject(i, 7);
				}
				else
				{
					PlayerInfo[i][E_CHARACTER_EQUIPITEMS] = INVENTORY_NONE;
					ResetPlayerWeapons(i);
					PlayerTextDrawHide(i, WeaponAmmo[i]);
				}
			}

			//MAC
			else if(GetPlayerWeapon(i) == 28) 
			{
				if(Inventory_Count(i, "9x19mm"))
				{
					new astring[128];
					new tstr[128];

					if (PlayerInfo[i][E_CHARACTER_WEAPONTYPE] == 1)
					{
						format(astring, sizeof(astring), "MAC-11");
						SetPlayerAttachedObject(i, ATTACH_WEAPONS, -2207, 6, -0.021000, -0.026000, -0.027000, 0.000000, 0.000000, 2.199998, 1.212000, 2.153999, 1.350999);
					}

					else if (PlayerInfo[i][E_CHARACTER_WEAPONTYPE] == 2)
					{
						format(astring, sizeof(astring), "MAC-10");
						SetPlayerAttachedObject(i, ATTACH_WEAPONS, -2208, 6, 0.000000, -0.004999, -0.051999, 0.000000, 0.000000, 0.000000, 1.160001, 1.748001, 1.372001);
					}
						
					else if (PlayerInfo[i][E_CHARACTER_WEAPONTYPE] == 3)
					{
						format(astring, sizeof(astring), "Socimi_Type_821");
						SetPlayerAttachedObject(i, ATTACH_WEAPONS, -2209, 6, -0.026000, -0.070999, -0.059999, 0.499996, -8.299998, -3.299998, 1.565001, 2.388001, 1.568999);
					}
						
					PlayerTextDrawSetString(i, WeaponType[i], astring);
					PlayerTextDrawShow(i, WeaponType[i]);
					format(tstr, sizeof(tstr), "%d", Inventory_Count(i, "9x19mm"));
					PlayerTextDrawSetString(i, WeaponAmmo[i], tstr);
					PlayerTextDrawShow(i, WeaponAmmo[i]);
				}
				else
				{
					PlayerInfo[i][E_CHARACTER_EQUIPITEMS] = INVENTORY_NONE;
					ResetPlayerWeapons(i);
					PlayerTextDrawHide(i, WeaponAmmo[i]);
				}
			}
			else if(GetPlayerWeapon(i) == 29) 
			{
				new astring[128];
				if (PlayerInfo[i][E_CHARACTER_WEAPONTYPE] == 1)
				{
					format(astring, sizeof(astring), "HK_53");
				}
					
				else if (PlayerInfo[i][E_CHARACTER_WEAPONTYPE] == 2)
				{
					format(astring, sizeof(astring), "UMP9");
				}

				else if (PlayerInfo[i][E_CHARACTER_WEAPONTYPE] == 3)
				{
					format(astring, sizeof(astring), "AKS_74U");
				}
				
				PlayerTextDrawSetString(i, WeaponType[i], astring);
				PlayerTextDrawShow(i, WeaponType[i]);
			}
			else if(GetPlayerWeapon(i) == 32) 
			{
				new astring[128];
				if (PlayerInfo[i][E_CHARACTER_WEAPONTYPE] == 1)format(astring, sizeof(astring), "HK_53");
				else if (PlayerInfo[i][E_CHARACTER_WEAPONTYPE] == 2)format(astring, sizeof(astring), "KGP-9");
				else if (PlayerInfo[i][E_CHARACTER_WEAPONTYPE] == 3)format(astring, sizeof(astring), "Berreta_M12");
				PlayerTextDrawSetString(i, WeaponType[i], astring);
				PlayerTextDrawShow(i, WeaponType[i]);
				RemovePlayerAttachedObject(i, 7);
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
					format(astring, sizeof(astring), "Glass");
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
				return SendServerMessage(i, "[Paycheck] {cdd0d1}You didn't receive a paycheck this hour as you were AFK for more than 15 minutes.");
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

function:OnPlayerNearPickup()
{
	foreach(new i : Player)
	{
		new id, str[128];

		if((id = IsPlayerNearBusiness(i)) != 0)
		{
			if(!BusinessInfo[id][E_BUSINESS_DBID])
				continue;

			if(!BusinessInfo[id][E_BUSINESS_OWNERDBID])
			{
				if(BusinessInfo[id][E_BUSINESS_TYPE] == BUSINESS_TYPE_DMV)
					format(str, sizeof(str), "~b~%s~n~~w~enter the vehicle to start drivetest.", BusinessInfo[id][E_BUSINESS_NAME], BusinessInfo[id][E_BUSINESS_ENTRANCEFEE]); 
				else if(BusinessInfo[id][E_BUSINESS_TYPE] == BUSINESS_TYPE_HAIRCUT || BusinessInfo[id][E_BUSINESS_TYPE] == BUSINESS_TYPE_GUNSTORE || BusinessInfo[id][E_BUSINESS_TYPE] == BUSINESS_TYPE_ACID)
					format(str, sizeof(str), "~b~%s~n~~w~Owned By: NPC~n~~y~Entrance Fee: $%s.~n~~w~Press 'RETURN' to enter.", BusinessInfo[id][E_BUSINESS_NAME], BusinessInfo[id][E_BUSINESS_ENTRANCEFEE]); 
				else if(BusinessInfo[id][E_BUSINESS_TYPE] == BUSINESS_TYPE_BANK)
					format(str, sizeof(str), "~b~%s~n~~w~Owned By: Goverments~n~~y~Entrance Fee: $%s.~n~~w~Press 'RETURN' to enter.", BusinessInfo[id][E_BUSINESS_NAME], BusinessInfo[id][E_BUSINESS_ENTRANCEFEE]); 
				else if(BusinessInfo[id][E_BUSINESS_TYPE] == BUSINESS_TYPE_RENT)
					format(str, sizeof(str), "~b~%s~n~~w~Owned By: Goverments~n~~w~Type '/rentcars' to rent vehicle.", BusinessInfo[id][E_BUSINESS_NAME]); 
						
				else format(str, sizeof(str), "~b~%s~n~~y~This business is for sale price: $%s.~n~~w~Press 'RETURN' to enter.", BusinessInfo[id][E_BUSINESS_NAME], FormatMoney(BusinessInfo[id][E_BUSINESS_PRICE]), BusinessInfo[id][E_BUSINESS_LEVEL]); 
			}
			else format(str, sizeof(str), "~b~%s~n~~w~Owned By: %s~n~~y~Entrance Fee: $%s.~n~~w~Press 'RETURN' to enter.", BusinessInfo[id][E_BUSINESS_NAME], ReturnDBIDName(BusinessInfo[id][E_BUSINESS_OWNERDBID]), FormatMoney(BusinessInfo[id][E_BUSINESS_ENTRANCEFEE])); 
			
			ShowBoxMessage(i, str, 5); 	
		}
		if((id = IsPlayerNearEntrance(i)) != 0)
		{
			if(!EntranceInfo[id][E_ENTRANCE_DBID])
				continue;
			format(str, sizeof(str), "~b~Entrance point~n~~w~Press 'RETURN' to enter."); 
			ShowBoxMessage(i, str, 5); 	
		}
		for(new p = 1; p < MAX_PROPERTY; p++)
		{		
			if(IsPlayerInRangeOfPoint(i, 3.0, PropertyInfo[p][E_PROPERTY_ENTRANCEPOS][0], PropertyInfo[p][E_PROPERTY_ENTRANCEPOS][1], PropertyInfo[p][E_PROPERTY_ENTRANCEPOS][2]))
			{
				if(!PropertyInfo[p][E_PROPERTY_DBID])
					continue;
					
				if(GetPlayerInterior(i) != PropertyInfo[p][E_PROPERTY_ENTRANCEINTERIOR])
					continue;
					
				if(GetPlayerVirtualWorld(i) != PropertyInfo[p][E_PROPERTY_ENTRANCEWORLD])
					continue; 
		
				if(!PropertyInfo[p][E_PROPERTY_OWNERDBID])
				{
					format(str, sizeof(str), "~b~%s, %s~n~~y~This property is for sale price: $%s~n~~w~Press 'RETURN' to enter.", PropertyInfo[p][E_PROPERTY_ADDRESS], ReturnLocation(i), FormatMoney(PropertyInfo[p][E_PROPERTY_PRICE]));
					ShowBoxMessage(i, str, 5);
				}
				else
				{
					format(str, sizeof(str), "~b~%s, %s~n~~w~You're standing on %s's porch~n~~w~Press 'RETURN' to enter.", PropertyInfo[p][E_PROPERTY_ADDRESS], ReturnLocation(i),  ReturnDBIDName(PropertyInfo[p][E_PROPERTY_OWNERDBID]));
					ShowBoxMessage(i, str, 5);
				}	
			}
		}
	}
	return 1;
}

function:MinutesTimes()
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