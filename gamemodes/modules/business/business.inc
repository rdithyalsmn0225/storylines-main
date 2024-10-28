stock BusinessRefresh(businessid)
{
	if(IsValidDynamicPickup(BusinessInfo[businessid][E_BUSINESS_PICKUP]))
		DestroyDynamicPickup(BusinessInfo[businessid][E_BUSINESS_PICKUP]); 

	if(IsValidDynamicMapIcon(BusinessInfo[businessid][E_BUSINESS_MAPICON]))
		DestroyDynamicMapIcon(BusinessInfo[businessid][E_BUSINESS_MAPICON]); 
			
	if(IsValidObject(BusinessInfo[businessid][E_BUSINESS_RDUMBELL]))
		DestroyObject(BusinessInfo[businessid][E_BUSINESS_RDUMBELL]); 

	if(IsValidObject(BusinessInfo[businessid][E_BUSINESS_LDUMBELL]))
		DestroyObject(BusinessInfo[businessid][E_BUSINESS_LDUMBELL]); 

	if(IsValidDynamic3DTextLabel(BusinessInfo[businessid][E_BUSINESS_ENTRANCEPOINTTEXT3D]))
		DestroyDynamic3DTextLabel(BusinessInfo[businessid][E_BUSINESS_ENTRANCEPOINTTEXT3D]);

	if(IsValidDynamic3DTextLabel(BusinessInfo[businessid][E_BUSINESS_FUELTEXT3D]))
		DestroyDynamic3DTextLabel(BusinessInfo[businessid][E_BUSINESS_FUELTEXT3D]);

	if(IsValidDynamic3DTextLabel(BusinessInfo[businessid][E_BUSINESS_ENTRANCETEXT3D]))
		DestroyDynamic3DTextLabel(BusinessInfo[businessid][E_BUSINESS_ENTRANCETEXT3D]);

	if(IsValidDynamicActor(BusinessInfo[businessid][E_BUSINESS_ACTOR]))
		DestroyDynamicActor(BusinessInfo[businessid][E_BUSINESS_ACTOR]);

	switch(BusinessInfo[businessid][E_BUSINESS_TYPE])
	{
		case BUSINESS_TYPE_BANK:
		{
			BusinessInfo[businessid][E_BUSINESS_ENTRANCEPOINTTEXT3D] = CreateDynamic3DTextLabel("[Cashiers]\n{ffffff}Available commands: '/bank' to see bank menu.", COLOR_DARKGREEN, BusinessInfo[businessid][E_BUSINESS_ENTRANCEPOINT][0], BusinessInfo[businessid][E_BUSINESS_ENTRANCEPOINT][1], BusinessInfo[businessid][E_BUSINESS_ENTRANCEPOINT][2], 2.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, BusinessInfo[businessid][E_BUSINESS_INTERIORPOSWORLD], BusinessInfo[businessid][E_BUSINESS_INTERIORPOSINTERIOR]);
		}
		case BUSINESS_TYPE_DINNER:
		{
			BusinessInfo[businessid][E_BUSINESS_ENTRANCEPOINTTEXT3D] = CreateDynamic3DTextLabel("[Cashiers]\n{ffffff}Available commands: '/menu' to see food & drink menu.", COLOR_DARKGREEN, BusinessInfo[businessid][E_BUSINESS_ENTRANCEPOINT][0], BusinessInfo[businessid][E_BUSINESS_ENTRANCEPOINT][1], BusinessInfo[businessid][E_BUSINESS_ENTRANCEPOINT][2], 2.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, BusinessInfo[businessid][E_BUSINESS_INTERIORPOSWORLD], BusinessInfo[businessid][E_BUSINESS_INTERIORPOSINTERIOR]);
		}
		case BUSINESS_TYPE_BAR:
		{
			BusinessInfo[businessid][E_BUSINESS_ENTRANCEPOINTTEXT3D] = CreateDynamic3DTextLabel("[Cashiers]\n{ffffff}Available commands: '/buybeer' to see menu.", COLOR_DARKGREEN, BusinessInfo[businessid][E_BUSINESS_ENTRANCEPOINT][0], BusinessInfo[businessid][E_BUSINESS_ENTRANCEPOINT][1], BusinessInfo[businessid][E_BUSINESS_ENTRANCEPOINT][2], 2.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, BusinessInfo[businessid][E_BUSINESS_INTERIORPOSWORLD], BusinessInfo[businessid][E_BUSINESS_INTERIORPOSINTERIOR]);
		}
			
		case BUSINESS_TYPE_ACID:
		{
			BusinessInfo[businessid][E_BUSINESS_ENTRANCEPOINTTEXT3D] = CreateDynamic3DTextLabel("[Production]\n{ffffff}Available commands: '/production' to opens the production drugs menu.", COLOR_DARKGREEN, BusinessInfo[businessid][E_BUSINESS_ENTRANCEPOINT][0], BusinessInfo[businessid][E_BUSINESS_ENTRANCEPOINT][1], BusinessInfo[businessid][E_BUSINESS_ENTRANCEPOINT][2], 2.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, BusinessInfo[businessid][E_BUSINESS_INTERIORPOSWORLD], BusinessInfo[businessid][E_BUSINESS_INTERIORPOSINTERIOR]);
		}
		    
		case BUSINESS_TYPE_GENERAL:
		{
			BusinessInfo[businessid][E_BUSINESS_ENTRANCEPOINTTEXT3D] = CreateDynamic3DTextLabel("[Cashiers]\n{ffffff}Press 'N' to pay items to clerk.", COLOR_DARKGREEN, BusinessInfo[businessid][E_BUSINESS_ENTRANCEPOINT][0], BusinessInfo[businessid][E_BUSINESS_ENTRANCEPOINT][1], BusinessInfo[businessid][E_BUSINESS_ENTRANCEPOINT][2], 2.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, BusinessInfo[businessid][E_BUSINESS_INTERIORPOSWORLD], BusinessInfo[businessid][E_BUSINESS_INTERIORPOSINTERIOR]);
		}
		    
		case BUSINESS_TYPE_GUNSTORE:
		{
			BusinessInfo[businessid][E_BUSINESS_ENTRANCEPOINTTEXT3D] = CreateDynamic3DTextLabel("[Production]\n{ffffff}Available commands: '/creategun' to create weapons / ammo with materials..", COLOR_DARKGREEN, BusinessInfo[businessid][E_BUSINESS_ENTRANCEPOINT][0], BusinessInfo[businessid][E_BUSINESS_ENTRANCEPOINT][1], BusinessInfo[businessid][E_BUSINESS_ENTRANCEPOINT][2], 2.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, BusinessInfo[businessid][E_BUSINESS_INTERIORPOSWORLD], BusinessInfo[businessid][E_BUSINESS_INTERIORPOSINTERIOR]);
		}
		    
		case BUSINESS_TYPE_CLOTHES:
		{
			BusinessInfo[businessid][E_BUSINESS_ENTRANCEPOINTTEXT3D] = CreateDynamic3DTextLabel("[Cashiers]\n{ffffff}Available commands: '/clothes' to see list clothing.", COLOR_DARKGREEN, BusinessInfo[businessid][E_BUSINESS_ENTRANCEPOINT][0], BusinessInfo[businessid][E_BUSINESS_ENTRANCEPOINT][1], BusinessInfo[businessid][E_BUSINESS_ENTRANCEPOINT][2], 2.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, BusinessInfo[businessid][E_BUSINESS_INTERIORPOSWORLD], BusinessInfo[businessid][E_BUSINESS_INTERIORPOSINTERIOR]);
		}
		    
		case BUSINESS_TYPE_HAIRCUT:
		{
			BusinessInfo[businessid][E_BUSINESS_ENTRANCEPOINTTEXT3D] = CreateDynamic3DTextLabel("[Cashiers]\n{ffffff}Available commands: '/haircut' to see list style haircut.", COLOR_DARKGREEN, BusinessInfo[businessid][E_BUSINESS_ENTRANCEPOINT][0], BusinessInfo[businessid][E_BUSINESS_ENTRANCEPOINT][1], BusinessInfo[businessid][E_BUSINESS_ENTRANCEPOINT][2], 2.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, BusinessInfo[businessid][E_BUSINESS_INTERIORPOSWORLD], BusinessInfo[businessid][E_BUSINESS_INTERIORPOSINTERIOR]);
		}
		   
		case BUSINESS_TYPE_RENT:
		{
			BusinessInfo[businessid][E_BUSINESS_ENTRANCEPOINTTEXT3D] = CreateDynamic3DTextLabel("[Cashiers]\n{ffffff}Available commands: Press 'N' to pay items to clerk.", COLOR_DARKGREEN, BusinessInfo[businessid][E_BUSINESS_ENTRANCEPOINT][0], BusinessInfo[businessid][E_BUSINESS_ENTRANCEPOINT][1], BusinessInfo[businessid][E_BUSINESS_ENTRANCEPOINT][2], 2.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, BusinessInfo[businessid][E_BUSINESS_INTERIORPOSWORLD], BusinessInfo[businessid][E_BUSINESS_INTERIORPOSINTERIOR]);
		}
		    
		case BUSINESS_TYPE_CLUB:
		{
			BusinessInfo[businessid][E_BUSINESS_ENTRANCEPOINTTEXT3D] = CreateDynamic3DTextLabel("[Cashiers]\n{ffffff}Available commands: '/buybeer' to see menu.", COLOR_DARKGREEN, BusinessInfo[businessid][E_BUSINESS_ENTRANCEPOINT][0], BusinessInfo[businessid][E_BUSINESS_ENTRANCEPOINT][1], BusinessInfo[businessid][E_BUSINESS_ENTRANCEPOINT][2], 2.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, BusinessInfo[businessid][E_BUSINESS_INTERIORPOSWORLD], BusinessInfo[businessid][E_BUSINESS_INTERIORPOSINTERIOR]);
		}
			
		case BUSINESS_TYPE_DEALERSHIP:
		{
			BusinessInfo[businessid][E_BUSINESS_ENTRANCEPOINTTEXT3D] = CreateDynamic3DTextLabel("[Cashiers]\n{ffffff}Available commands: '/carbuy' to see menu.", COLOR_DARKGREEN, BusinessInfo[businessid][E_BUSINESS_ENTRANCEPOINT][0], BusinessInfo[businessid][E_BUSINESS_ENTRANCEPOINT][1], BusinessInfo[businessid][E_BUSINESS_ENTRANCEPOINT][2], 2.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, BusinessInfo[businessid][E_BUSINESS_INTERIORPOSWORLD], BusinessInfo[businessid][E_BUSINESS_INTERIORPOSINTERIOR]);
		}
			
		case BUSINESS_TYPE_DMV:
		{
			BusinessInfo[businessid][E_BUSINESS_ENTRANCEPOINTTEXT3D] = CreateDynamic3DTextLabel("[Cashiers]\n{ffffff}Available commands: '/drivetest' to see menu.", COLOR_DARKGREEN, BusinessInfo[businessid][E_BUSINESS_ENTRANCEPOINT][0], BusinessInfo[businessid][E_BUSINESS_ENTRANCEPOINT][1], BusinessInfo[businessid][E_BUSINESS_ENTRANCEPOINT][2], 2.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, BusinessInfo[businessid][E_BUSINESS_INTERIORPOSWORLD], BusinessInfo[businessid][E_BUSINESS_INTERIORPOSINTERIOR]);
		}
			
		case BUSINESS_TYPE_GYM:
		{
			BusinessInfo[businessid][E_BUSINESS_ENTRANCEPOINTTEXT3D] = CreateDynamic3DTextLabel("[Cashiers]\n{ffffff}Available commands: '/fightstyle' to learn fightstyles.", COLOR_DARKGREEN, BusinessInfo[businessid][E_BUSINESS_ENTRANCEPOINT][0], BusinessInfo[businessid][E_BUSINESS_ENTRANCEPOINT][1], BusinessInfo[businessid][E_BUSINESS_ENTRANCEPOINT][2], 2.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, BusinessInfo[businessid][E_BUSINESS_INTERIORPOSWORLD], BusinessInfo[businessid][E_BUSINESS_INTERIORPOSINTERIOR]);
		}
	}

	BusinessInfo[businessid][E_BUSINESS_ACTOR] = CreateDynamicActor(BusinessActor[BusinessInfo[businessid][E_BUSINESS_TYPE]][E_BACTOR_SKIN], BusinessInfo[businessid][E_BUSINESS_ACTORPOS][0], BusinessInfo[businessid][E_BUSINESS_ACTORPOS][1], BusinessInfo[businessid][E_BUSINESS_ACTORPOS][2], BusinessInfo[businessid][E_BUSINESS_ACTORPOS][3], false);
	SetDynamicActorVirtualWorld(BusinessInfo[businessid][E_BUSINESS_ACTOR], BusinessInfo[businessid][E_BUSINESS_INTERIORPOSWORLD]);

	if(BusinessInfo[businessid][E_BUSINESS_TYPE] == BUSINESS_TYPE_RENT)
		BusinessInfo[businessid][E_BUSINESS_PICKUP] = CreateDynamicPickup(1239, 1, BusinessInfo[businessid][E_BUSINESS_ENTRANCEPOS][0], BusinessInfo[businessid][E_BUSINESS_ENTRANCEPOS][1], BusinessInfo[businessid][E_BUSINESS_ENTRANCEPOS][2], 0, 0, -1, 5.0);
	else
		BusinessInfo[businessid][E_BUSINESS_PICKUP] = CreateDynamicPickup(1272, 1, BusinessInfo[businessid][E_BUSINESS_ENTRANCEPOS][0], BusinessInfo[businessid][E_BUSINESS_ENTRANCEPOS][1], BusinessInfo[businessid][E_BUSINESS_ENTRANCEPOS][2], 0, 0, -1, 5.0);
	
	BusinessInfo[businessid][E_BUSINESS_ENTRANCETEXT3D] = CreateDynamic3DTextLabel(BusinessInfo[businessid][E_BUSINESS_NAME], COLOR_DARKGREEN, BusinessInfo[businessid][E_BUSINESS_ENTRANCEPOS][0], BusinessInfo[businessid][E_BUSINESS_ENTRANCEPOS][1], BusinessInfo[businessid][E_BUSINESS_ENTRANCEPOS][2], 5.0);
	BusinessInfo[businessid][E_BUSINESS_FUELTEXT3D] = CreateDynamic3DTextLabel("[Gas Station]\n{ffffff}Available Commands: '/refuel' to refill vehicles fuel", COLOR_DARKGREEN, BusinessInfo[businessid][E_BUSINESS_FUELPOS][0], BusinessInfo[businessid][E_BUSINESS_FUELPOS][1], BusinessInfo[businessid][E_BUSINESS_FUELPOS][2], 5.0);
	
	if(BusinessInfo[businessid][E_BUSINESS_TYPE] == BUSINESS_TYPE_GYM)
	{
		BusinessInfo[businessid][E_BUSINESS_RDUMBELL] = CreateObject(3071, 772.992,5.18281,999.927,0.0,90.0,90.0);
		BusinessInfo[businessid][E_BUSINESS_LDUMBELL] = CreateObject(3072, 772.992,5.62738,999.927,0.0,90.0,90.0);
	}

	BusinessInfo[businessid][E_BUSINESS_TREADMILL] = false;
	BusinessInfo[businessid][E_BUSINESS_DUMBELL] = false;
	BusinessInfo[businessid][E_BUSINESS_BYCICLE] = false;
	BusinessInfo[businessid][E_BUSINESS_BENCH] = false;

	BusinessInfo[businessid][E_BUSINESS_EXISTS] = true;
	if(BusinessInfo[businessid][E_BUSINESS_ROBBERYCASH] == true)
	{
		BusinessInfo[businessid][E_BUSINESS_CASHOBJECT] = CreateDynamicObject(1212, BusinessInfo[businessid][E_BUSINESS_ENTRANCEPOINT][0], BusinessInfo[businessid][E_BUSINESS_ENTRANCEPOINT][1], BusinessInfo[businessid][E_BUSINESS_ENTRANCEPOINT][2], 0.0, 0.0, 0.0, BusinessInfo[businessid][E_BUSINESS_INTERIORPOSWORLD], BusinessInfo[businessid][E_BUSINESS_INTERIORPOSINTERIOR], -1, 5.0);
	}
	else
	{
		DestroyDynamicObject(BusinessInfo[businessid][E_BUSINESS_CASHOBJECT]);
		BusinessInfo[businessid][E_BUSINESS_ROBBERYCASH] = false;
	}
	return 1;
}

function:OnBusinessInteriorChange(playerid, response, businessid)
{
	if(response)
	{
		new Float:x, Float:y, Float:z;
		GetPlayerPos(playerid, x, y, z);
		new interior = GetPlayerInterior(playerid); 
		
		BusinessInfo[businessid][E_BUSINESS_INTERIORPOS][0] = x; 
		BusinessInfo[businessid][E_BUSINESS_INTERIORPOS][1] = y; 
		BusinessInfo[businessid][E_BUSINESS_INTERIORPOS][2] = z; 
		BusinessInfo[businessid][E_BUSINESS_INTERIORPOSINTERIOR] = interior;

		BusinessRefresh(businessid);
		SendInfoMessage(playerid, "You changed Business #%i's interior.", businessid);
		SaveBusiness(businessid); 
	}
	else return SendErrorMessage(playerid, "You cancelled.");
	return 1;
}

function:OnBusinessEntranceChange(playerid, response, businessid)
{
	if(response)
	{
		new Float:x, Float:y, Float:z;
		GetPlayerPos(playerid, x, y, z); 
		
		BusinessInfo[businessid][E_BUSINESS_ENTRANCEPOS][0] = x;
		BusinessInfo[businessid][E_BUSINESS_ENTRANCEPOS][1] = y;
		BusinessInfo[businessid][E_BUSINESS_ENTRANCEPOS][2] = z;

		BusinessRefresh(businessid);
		SendInfoMessage(playerid, "You changed Business #%i's entrance.", businessid);
		SaveBusiness(businessid); 
	}
	else return SendErrorMessage(playerid, "You cancelled.");
	return 1;
}

function:OnBusinessGasStationChange(playerid, response, businessid)
{
	if(response)
	{
		new Float:x, Float:y, Float:z;
		GetPlayerPos(playerid, x, y, z); 
		
		BusinessInfo[businessid][E_BUSINESS_FUELPOS][0] = x;
		BusinessInfo[businessid][E_BUSINESS_FUELPOS][1] = y;
		BusinessInfo[businessid][E_BUSINESS_FUELPOS][2] = z;

		BusinessRefresh(businessid);
		SendInfoMessage(playerid, "You changed Business #%i's gas station.", businessid);
		SaveBusiness(businessid); 
	}
	else return SendErrorMessage(playerid, "You cancelled.");
	return 1;
}

function:OnBusinessActorChange(playerid, response, businessid)
{
	if(response)
	{
		new Float:x, Float:y, Float:z, Float:a;
		GetPlayerPos(playerid, x, y, z); 
		GetPlayerFacingAngle(playerid, a);
		
		BusinessInfo[businessid][E_BUSINESS_ACTORPOS][0] = x;
		BusinessInfo[businessid][E_BUSINESS_ACTORPOS][1] = y;
		BusinessInfo[businessid][E_BUSINESS_ACTORPOS][2] = z;
		BusinessInfo[businessid][E_BUSINESS_ACTORPOS][3] = a;

		BusinessRefresh(businessid);
		SendInfoMessage(playerid, "You changed Business #%i's actor.", businessid);
		SaveBusiness(businessid); 
	}
	else return SendErrorMessage(playerid, "You cancelled.");
	return 1;
}

function:OnBusinessPointChange(playerid, response, businessid, Float:x, Float:y, Float:z)
{
	if(response)
	{
		BusinessInfo[businessid][E_BUSINESS_ENTRANCEPOINT][0] = x;
		BusinessInfo[businessid][E_BUSINESS_ENTRANCEPOINT][1] = y;
		BusinessInfo[businessid][E_BUSINESS_ENTRANCEPOINT][2] = z;
		
		BusinessRefresh(businessid);
		SendInfoMessage(playerid, "You changed Business #%i's point.", businessid);
		SaveBusiness(businessid); 
	}
	else return SendErrorMessage(playerid, "You cancelled.");
	return 1;
}

stock IsPlayerNearBusiness(playerid)
{
	for(new i = 1; i < MAX_BUSINESS; i++)
	{
		if(IsPlayerInRangeOfPoint(playerid, 2.0, BusinessInfo[i][E_BUSINESS_ENTRANCEPOS][0], BusinessInfo[i][E_BUSINESS_ENTRANCEPOS][1], BusinessInfo[i][E_BUSINESS_ENTRANCEPOS][2]))
			return i;
	}
	return 0;
}

stock IsPlayerNearCashiers(playerid)
{
	for(new i = 1; i < MAX_BUSINESS; i++)
	{
		if(IsPlayerInRangeOfPoint(playerid, 2.0, BusinessInfo[i][E_BUSINESS_ENTRANCEPOINT][0], BusinessInfo[i][E_BUSINESS_ENTRANCEPOINT][1], BusinessInfo[i][E_BUSINESS_ENTRANCEPOINT][2]))
			return i;
	}
	return 0;
}

stock IsPlayerNearGasStation(playerid)
{
	for(new i = 1; i < MAX_BUSINESS; i++)
	{
		if(IsPlayerInRangeOfPoint(playerid, 2.0, BusinessInfo[i][E_BUSINESS_FUELPOS][0], BusinessInfo[i][E_BUSINESS_FUELPOS][1], BusinessInfo[i][E_BUSINESS_FUELPOS][2]))
			return i;
	}
	return 0;
}

stock GetClosestBusiness(playerid, type)
{
	new
	    Float:fDistance[2] = {99999.0, 0.0},
	    iIndex = -1
	;
	for (new i = 0; i < MAX_BUSINESS; i ++) if (BusinessInfo[i][E_BUSINESS_DBID] && BusinessInfo[i][E_BUSINESS_TYPE] == type && GetPlayerInterior(playerid) == BusinessInfo[i][E_BUSINESS_INTERIORPOSINTERIOR] && GetPlayerVirtualWorld(playerid) == BusinessInfo[i][E_BUSINESS_INTERIORPOSWORLD])
	{
		fDistance[1] = GetPlayerDistanceFromPoint(playerid, BusinessInfo[i][E_BUSINESS_ENTRANCEPOS][0], BusinessInfo[i][E_BUSINESS_ENTRANCEPOS][1], BusinessInfo[i][E_BUSINESS_ENTRANCEPOS][2]);

		if (fDistance[1] < fDistance[0])
		{
		    fDistance[0] = fDistance[1];
		    iIndex = i;
		}
	}
	return iIndex;
}

stock IsPlayerInBusiness(playerid)
{
	if(PlayerInfo[playerid][E_CHARACTER_INSIDEBIZ])
	{
		for(new i = 1; i < MAX_BUSINESS; i++)
		{
			if(!BusinessInfo[i][E_BUSINESS_DBID])
				continue;
				
			if(i == PlayerInfo[playerid][E_CHARACTER_INSIDEBIZ] && GetPlayerVirtualWorld(playerid) == BusinessInfo[i][E_BUSINESS_INTERIORPOSWORLD])
				return i;
		}
	}
	return 0;
}

stock CountPlayerBusiness(playerid)
{
	new
		count = 0
	;
	
	for(new i = 1; i < MAX_BUSINESS; i++)
	{
		if(!BusinessInfo[i][E_BUSINESS_DBID])
			continue;
			
		if(BusinessInfo[i][E_BUSINESS_OWNERDBID] == PlayerInfo[playerid][E_CHARACTER_DBID])
			count++;
	}
	return count;
}

stock SendBusinessType(playerid, id)
{
	new str[128];
	switch(BusinessInfo[id][E_BUSINESS_TYPE])
	{
		case BUSINESS_TYPE_GUNSTORE:
		{
			format(str, sizeof(str), "Welcome to %s.\nThis is a gun store you can create gun/ammo.", BusinessInfo[id][E_BUSINESS_NAME]);
			SendClientMessage(playerid, COLOR_ORANGE, str);
		}
		case BUSINESS_TYPE_BANK:
		{
			format(str, sizeof(str), "Welcome to %s.\nThis is a bank you can withdraw, deposit, or see balance your money in bank.", BusinessInfo[id][E_BUSINESS_NAME]);
			SendClientMessage(playerid, COLOR_ORANGE, str);
		}
		case BUSINESS_TYPE_GENERAL:
		{
			format(str, sizeof(str), "Welcome to %s.\nThis is a general store you can buy anything.", BusinessInfo[id][E_BUSINESS_NAME]);
			SendClientMessage(playerid, COLOR_ORANGE, str);
		}
		case BUSINESS_TYPE_CLUB:
		{
			format(str, sizeof(str), "Welcome to %s.\nThis is a club you can buy anything beer.", BusinessInfo[id][E_BUSINESS_NAME]);
			SendClientMessage(playerid, COLOR_ORANGE, str);
		}
		case BUSINESS_TYPE_DINNER:
		{
			format(str, sizeof(str), "Welcome to %s.\nThis is a restaurant you can buy anything food or drink if you hungry and thirsty.", BusinessInfo[id][E_BUSINESS_NAME]);
			SendClientMessage(playerid, COLOR_ORANGE, str);
		}
		case BUSINESS_TYPE_BAR:
		{
			format(str, sizeof(str), "Welcome to %s.\nThis is a bar you can buy anything beer.", BusinessInfo[id][E_BUSINESS_NAME]);
			SendClientMessage(playerid, COLOR_ORANGE, str);
		}
		case BUSINESS_TYPE_ACID:
		{
			format(str, sizeof(str), "Welcome to %s\nThis is a acid labs you can produce drugs or something.", BusinessInfo[id][E_BUSINESS_NAME]);
			SendClientMessage(playerid, COLOR_ORANGE, str);
		}
		case BUSINESS_TYPE_CLOTHES:
		{
			format(str, sizeof(str), "Welcome to %s.\nThis is a clothes store you can buy anything clothing or skins.", BusinessInfo[id][E_BUSINESS_NAME]);
			SendClientMessage(playerid, COLOR_ORANGE, str);
		}
		case BUSINESS_TYPE_HAIRCUT:
		{
			format(str, sizeof(str), "Welcome to %s.\nThis is a haircuts you can buy anything wigs or cuts your stylish hair.", BusinessInfo[id][E_BUSINESS_NAME]);
			SendClientMessage(playerid, COLOR_ORANGE, str);
		}
		case BUSINESS_TYPE_RENT:
		{
			format(str, sizeof(str), "Welcome to %s.\nThis is a rental you can rent anything vehicles.", BusinessInfo[id][E_BUSINESS_NAME]);
			SendClientMessage(playerid, COLOR_ORANGE, str);
		}
		case BUSINESS_TYPE_GYM:
		{
			format(str, sizeof(str), "Welcome to %s.\nThis is a gym you can learn fightsyle and increase your muscles.", BusinessInfo[id][E_BUSINESS_NAME]);
			SendClientMessage(playerid, COLOR_ORANGE, str);
		}
	}
	return 1;
}

function:OnSellBusiness(playerid, response, businessid)
{
	if(response)
	{
		new
			totalPay
		;
		
		totalPay = BusinessInfo[businessid][E_BUSINESS_PRICE] / 2 + BusinessInfo[businessid][E_BUSINESS_CASH]; 
		GiveMoney(playerid, totalPay); 
		
		BusinessInfo[businessid][E_BUSINESS_OWNERDBID] = 0; 
		
		PlayerPlaySound(playerid, 1052, 0.0, 0.0, 0.0);
		SendInfoMessage(playerid, "You sold your business and earned {B3C99E}$%s{cdd0d1}.", FormatMoney(totalPay)); 
		
		SaveBusiness(businessid); SaveCharacter(playerid); 
	}
	else return SendErrorMessage(playerid, "You cancelled selling your business.");
	return 1;
}

function:OnPlayerExitDealership(playerid, response)
{
	if(response)
	{
		SendInfoMessage(playerid, "You exited out the dealership.");
		
		ResetVehicleVars(DealershipPlayerCar[playerid]); 
		DestroyVehicle(DealershipPlayerCar[playerid]); 
		
		ResetDealershipVars(playerid);
		TogglePlayerControllable(playerid, true); 
	}
	else return ShowDealerAppend(playerid);
	return 1;
}

function:OnPlayerCreateWeapon(playerid, response, weapon, ammo, price, type)
{
	if(response)
	{
		if(weapon == WEAPON_COLT45 && type == 1)
		{
			if(price > PlayerInfo[playerid][E_CHARACTER_MONEY])
				return SendErrorMessage(playerid, "You can't afford this. (Cost: $%s, Total: $%s)", FormatMoney(price), FormatMoney(PlayerInfo[playerid][E_CHARACTER_MONEY]));

			if(Inventory_Count(playerid, "Materials") < 50)
				return SendErrorMessage(playerid, "You must have 50 gram of materials.");

			if(ReturnFactionType(playerid) == FACTION_TYPE_ILLEGAL)
			{
				GiveMoney(playerid, -price);
				Inventory_Add(playerid, "Glock 19", -2205, 1);
				Inventory_Add(playerid, "9mm", 2040, ammo);
				Inventory_Remove(playerid, "Materials", 50);
				SaveCharacter(playerid);
			}
			else
			{
				GiveMoney(playerid, -price);
				Inventory_Add(playerid, "Glock 19", -2205, 1);
				Inventory_Add(playerid, "9mm", 2040, ammo);
				Inventory_Remove(playerid, "Materials", 50);

				SaveCharacter(playerid);
			}
		}
		else if(weapon == WEAPON_COLT45 && type == 2)
		{
			if(price > PlayerInfo[playerid][E_CHARACTER_MONEY])
				return SendErrorMessage(playerid, "You can't afford this. (Cost: $%s, Total: $%s)", FormatMoney(price), FormatMoney(PlayerInfo[playerid][E_CHARACTER_MONEY]));
			
			if(Inventory_Count(playerid, "Materials") < 55)
				return SendErrorMessage(playerid, "You must have 50 gram of materials.");

			if(ReturnFactionType(playerid) == FACTION_TYPE_ILLEGAL)
			{
				GiveMoney(playerid, -price);
				Inventory_Add(playerid, "Glock 17", -2204, 1);
				Inventory_Add(playerid, "9mm", 2040, ammo);
				Inventory_Remove(playerid, "Materials", 55);

				SaveCharacter(playerid);
			}
			else
			{
				GiveMoney(playerid, -price);
				Inventory_Add(playerid, "Glock 17", -2204, 1);
				Inventory_Add(playerid, "9mm", 2040, ammo);
				Inventory_Remove(playerid, "Materials", 55);

				SaveCharacter(playerid);
			}
		}
		else if(weapon == WEAPON_COLT45 && type == 3)
		{
			if(price > PlayerInfo[playerid][E_CHARACTER_MONEY])
				return SendErrorMessage(playerid, "You can't afford this. (Cost: $%s, Total: $%s)", FormatMoney(price), FormatMoney(PlayerInfo[playerid][E_CHARACTER_MONEY]));

			if(Inventory_Count(playerid, "Materials") < 60)
				return SendErrorMessage(playerid, "You must have 50 gram of materials.");

			if(ReturnFactionType(playerid) == FACTION_TYPE_ILLEGAL)
			{
				GiveMoney(playerid, -price);
				Inventory_Add(playerid, "Glock P80", -2206, 1);
				Inventory_Add(playerid, "9mm", 2040, ammo);
				Inventory_Remove(playerid, "Materials", 60);

				SaveCharacter(playerid);
			}
			else
			{
				GiveMoney(playerid, -price);
				Inventory_Add(playerid, "Glock P80", -2206, 1);
				Inventory_Add(playerid, "9mm", 2040, ammo);
				Inventory_Remove(playerid, "Materials", 60);

				SaveCharacter(playerid);
			}
		}
		if(weapon == WEAPON_DEAGLE && type == 2)
		{
			if(price > PlayerInfo[playerid][E_CHARACTER_MONEY])
				return SendErrorMessage(playerid, "You can't afford this. (Cost: $%s, Total: $%s)", FormatMoney(price), FormatMoney(PlayerInfo[playerid][E_CHARACTER_MONEY]));

			if(Inventory_Count(playerid, "Materials") < 80)
				return SendErrorMessage(playerid, "You must have 50 gram of materials.");

			if(ReturnFactionType(playerid) == FACTION_TYPE_ILLEGAL)
			{
				GiveMoney(playerid, -price);
				Inventory_Add(playerid, "Deagle", 348, 1);
				Inventory_Add(playerid, "9mm", 2040, ammo);
				Inventory_Remove(playerid, "Materials", 80);
				SaveCharacter(playerid);
			}
			else
			{
				GiveMoney(playerid, -price);
				Inventory_Add(playerid, "Glock 19", -2205, 1);
				Inventory_Add(playerid, "9mm", 2040, ammo);
				Inventory_Remove(playerid, "Materials", 50);

				SaveCharacter(playerid);
			}
		}
		else if(weapon == WEAPON_UZI && type == 1)
		{
			if(price > PlayerInfo[playerid][E_CHARACTER_MONEY])
				return SendErrorMessage(playerid, "You can't afford this. (Cost: $%s, Total: $%s)", FormatMoney(price), FormatMoney(PlayerInfo[playerid][E_CHARACTER_MONEY]));

			if(Inventory_Count(playerid, "Materials") < 100)
				return SendErrorMessage(playerid, "You must have 50 gram of materials.");

			if(ReturnFactionType(playerid) == FACTION_TYPE_ILLEGAL)
			{
				GiveMoney(playerid, -price);
				Inventory_Add(playerid, "Mac 11", -2207, 1);
				Inventory_Add(playerid, "9x19mm", 2040, ammo);
				Inventory_Remove(playerid, "Materials", 100);

				SaveCharacter(playerid);
			}
			else
			{
				GiveMoney(playerid, -price);
				Inventory_Add(playerid, "Mac 11", -2207, 1);
				Inventory_Add(playerid, "9x19mm", 2040, ammo);
				Inventory_Remove(playerid, "Materials", 100);

				SaveCharacter(playerid);
			}
		}
		else if(weapon == WEAPON_UZI && type == 2)
		{
			if(price > PlayerInfo[playerid][E_CHARACTER_MONEY])
				return SendErrorMessage(playerid, "You can't afford this. (Cost: $%s, Total: $%s)", FormatMoney(price), FormatMoney(PlayerInfo[playerid][E_CHARACTER_MONEY]));
			
			if(Inventory_Count(playerid, "Materials") < 110)
				return SendErrorMessage(playerid, "You must have 50 gram of materials.");

			if(ReturnFactionType(playerid) == FACTION_TYPE_ILLEGAL)
			{
				GiveMoney(playerid, -price);
				Inventory_Add(playerid, "Mac 12", -2208, 1);
				Inventory_Add(playerid, "9x19mm", 2040, ammo);
				Inventory_Remove(playerid, "Materials", 110);

				SaveCharacter(playerid);
			}
			else
			{
				GiveMoney(playerid, -price);
				Inventory_Add(playerid, "Mac 12", -2208, 1);
				Inventory_Add(playerid, "9x19mm", 2040, ammo);
				Inventory_Remove(playerid, "Materials", 110);

				SaveCharacter(playerid);
			}
		}
		else if(weapon == WEAPON_UZI && type == 3)
		{
			if(Inventory_Count(playerid, "Materials") < 120)
				return SendErrorMessage(playerid, "You must have 50 gram of materials.");

			if(price > PlayerInfo[playerid][E_CHARACTER_MONEY])
				return SendErrorMessage(playerid, "You can't afford this. (Cost: $%s, Total: $%s)", FormatMoney(price), FormatMoney(PlayerInfo[playerid][E_CHARACTER_MONEY]));
			
			if(ReturnFactionType(playerid) == FACTION_TYPE_ILLEGAL)
			{
				GiveMoney(playerid, -price);
				Inventory_Add(playerid, "Socimi Type 821", -2209, 1);
				Inventory_Add(playerid, "9x19mm", 2040, ammo);
				Inventory_Remove(playerid, "Materials", 120);

				SaveCharacter(playerid);
			}
			else
			{
				GiveMoney(playerid, -price);
				Inventory_Add(playerid, "Socimi Type 821", -2209);
				Inventory_Add(playerid, "9x19mm", 2040, ammo);
				Inventory_Remove(playerid, "Materials", 120);

				SaveCharacter(playerid);
			}
		}
	}
	return 1;
}

function:OnPlayerCreateAmmo(playerid, response, type, ammo, price)
{
	if(response)
	{
		if(type == 0)
		{
			if(price > PlayerInfo[playerid][E_CHARACTER_MONEY])
				return SendErrorMessage(playerid, "You can't afford this. (Cost: $%s, Total: $%s)", FormatMoney(price), FormatMoney(PlayerInfo[playerid][E_CHARACTER_MONEY]));

			if(Inventory_Count(playerid, "Materials") < 120)
				return SendErrorMessage(playerid, "You must have 50 gram of materials.");

			if(ReturnFactionType(playerid) == FACTION_TYPE_ILLEGAL)
			{
				GiveMoney(playerid, -price);
				Inventory_Add(playerid, "9mm", 2040, ammo);
				Inventory_Remove(playerid, "Materials", 35);
				GiveMoney(playerid, -500);
				SaveCharacter(playerid);
			}
			else
			{
				GiveMoney(playerid, -price);
				Inventory_Add(playerid, "9mm", 2040, ammo);
				Inventory_Remove(playerid, "Materials", 35);
				GiveMoney(playerid, -500);
				SaveCharacter(playerid);
			}
		}
		else if(type == 1)
		{
			if(Inventory_Count(playerid, "Materials") < 120)
				return SendErrorMessage(playerid, "You must have 50 gram of materials.");

			if(price > PlayerInfo[playerid][E_CHARACTER_MONEY])
				return SendErrorMessage(playerid, "You can't afford this. (Cost: $%s, Total: $%s)", FormatMoney(price), FormatMoney(PlayerInfo[playerid][E_CHARACTER_MONEY]));
			
			if(ReturnFactionType(playerid) == FACTION_TYPE_ILLEGAL)
			{
				GiveMoney(playerid, -price);
				Inventory_Add(playerid, "9x19mm", 2040, ammo);
				Inventory_Remove(playerid, "Materials", 30);
				GiveMoney(playerid, -600);
				SaveCharacter(playerid);
			}
			else
			{
				GiveMoney(playerid, -price);
				Inventory_Add(playerid, "9x19mm", 2040, ammo);	
				Inventory_Remove(playerid, "Materials", 30);
				GiveMoney(playerid, -600);
				SaveCharacter(playerid);
			}
		}
	}
	return 1;
}



function:Query_InsertBusiness(playerid, newid, type)
{
	new 
		world = random(20000)+playerid+2;

	BusinessInfo[newid][E_BUSINESS_DBID] = cache_insert_id(); 
	BusinessInfo[newid][E_BUSINESS_TYPE] = type; 
 
 	format(BusinessInfo[newid][E_BUSINESS_NAME], 90, "Unknown");
	
	BusinessInfo[newid][E_BUSINESS_INTERIORPOS][0] = 0; 
	BusinessInfo[newid][E_BUSINESS_INTERIORPOS][1] = 0; 
	BusinessInfo[newid][E_BUSINESS_INTERIORPOS][2] = 0; 
	BusinessInfo[newid][E_BUSINESS_INTERIORPOSINTERIOR] = 0;
	BusinessInfo[newid][E_BUSINESS_INTERIORPOSWORLD] = world;  

	BusinessRefresh(newid);
	SendInfoMessage(playerid, "You created business ID #%i. To configure, use \"/editbusiness\". ", newid); 
	return 1;
}

function:Query_LoadBusinesses()
{
	if(!cache_num_rows())
		return printf("[SERVER]: No businesses were loaded from \"%s\" database...", SQL_DATABASE); 
		
	new rows, fields; 
	cache_get_row_count(rows);
	cache_get_field_count(fields);
	
	for(new i = 0; i < rows && i < MAX_BUSINESS; i++)
	{
		BusinessInfo[i+1][E_BUSINESS_EXISTS] = true;

		cache_get_value_name_int(i, "BusinessDBID", BusinessInfo[i+1][E_BUSINESS_DBID]);
		cache_get_value_name_int(i, "BusinessOwnerDBID", BusinessInfo[i+1][E_BUSINESS_OWNERDBID]); 
		
		cache_get_value_name_float(i, "BusinessInteriorX", BusinessInfo[i+1][E_BUSINESS_INTERIORPOS][0]);
		cache_get_value_name_float(i, "BusinessInteriorY", BusinessInfo[i+1][E_BUSINESS_INTERIORPOS][1]);
		cache_get_value_name_float(i, "BusinessInteriorZ", BusinessInfo[i+1][E_BUSINESS_INTERIORPOS][2]);
		
		cache_get_value_name_int(i, "BusinessInteriorWorld", BusinessInfo[i+1][E_BUSINESS_INTERIORPOSWORLD]);
		cache_get_value_name_int(i, "BusinessInteriorIntID", BusinessInfo[i+1][E_BUSINESS_INTERIORPOSINTERIOR]);
		
		cache_get_value_name_float(i, "BusinessEntranceX", BusinessInfo[i+1][E_BUSINESS_ENTRANCEPOS][0]);
		cache_get_value_name_float(i, "BusinessEntranceY", BusinessInfo[i+1][E_BUSINESS_ENTRANCEPOS][1]);
		cache_get_value_name_float(i, "BusinessEntranceZ", BusinessInfo[i+1][E_BUSINESS_ENTRANCEPOS][2]);

		cache_get_value_name_float(i, "BusinessPointX", BusinessInfo[i+1][E_BUSINESS_ENTRANCEPOINT][0]);
		cache_get_value_name_float(i, "BusinessPointY", BusinessInfo[i+1][E_BUSINESS_ENTRANCEPOINT][1]);
		cache_get_value_name_float(i, "BusinessPointZ", BusinessInfo[i+1][E_BUSINESS_ENTRANCEPOINT][2]);

		cache_get_value_name_float(i, "BusinessFuelX", BusinessInfo[i+1][E_BUSINESS_FUELPOS][0]);
		cache_get_value_name_float(i, "BusinessFuelY", BusinessInfo[i+1][E_BUSINESS_FUELPOS][1]);
		cache_get_value_name_float(i, "BusinessFuelZ", BusinessInfo[i+1][E_BUSINESS_FUELPOS][2]);

		cache_get_value_name_float(i, "BusinessActorX", BusinessInfo[i+1][E_BUSINESS_ACTORPOS][0]);
		cache_get_value_name_float(i, "BusinessActorY", BusinessInfo[i+1][E_BUSINESS_ACTORPOS][1]);
		cache_get_value_name_float(i, "BusinessActorZ", BusinessInfo[i+1][E_BUSINESS_ACTORPOS][2]);
		cache_get_value_name_float(i, "BusinessActorZ", BusinessInfo[i+1][E_BUSINESS_ACTORPOS][3]);
		
		cache_get_value_name(i, "BusinessName", BusinessInfo[i+1][E_BUSINESS_NAME], 90); 
		cache_get_value_name_int(i, "BusinessType", BusinessInfo[i+1][E_BUSINESS_TYPE]);
		
		cache_get_value_bool(i, "BusinessLocked", BusinessInfo[i+1][E_BUSINESS_LOCKED]); 
		cache_get_value_name_int(i, "BusinessEntranceFee", BusinessInfo[i+1][E_BUSINESS_ENTRANCEFEE]); 
		
		cache_get_value_name_int(i, "BusinessLevel", BusinessInfo[i+1][E_BUSINESS_LEVEL]); 
		cache_get_value_name_int(i, "BusinessMarketPrice", BusinessInfo[i+1][E_BUSINESS_PRICE]);
		
		cache_get_value_name_int(i, "BusinessCashbox", BusinessInfo[i+1][E_BUSINESS_CASH]);
		cache_get_value_name_int(i, "BusinessProducts", BusinessInfo[i+1][E_BUSINESS_STOCK]);

		cache_get_value_name_int(i, "BusinessRobberyTime", BusinessInfo[i+1][E_BUSINESS_ROBBERYTIME]);
		cache_get_value_name_int(i, "BusinessShipments", BusinessInfo[i+1][E_BUSINESS_SHIPMENTS]);

		cache_get_value_name_int(i, "BusinessAmount", BusinessInfo[i+1][E_BUSINESS_AMOUNT]);
		
		BusinessRefresh(i+1);
	}	
	printf("[SERVER]: %i businesses were loaded from \"%s\" database...", rows, SQL_DATABASE);
	return 1;
}