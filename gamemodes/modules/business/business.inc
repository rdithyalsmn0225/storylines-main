function:OnBusinessInteriorChange(playerid, response, businessid)
{
	if(response)
	{
		GetPlayerPos(playerid, BusinessInfo[businessid][E_BUSINESS_INTERIORPOS][0], BusinessInfo[businessid][E_BUSINESS_INTERIORPOS][1], BusinessInfo[businessid][E_BUSINESS_INTERIORPOS][2]);
		
		new 
			world = random(20000)+playerid+2; 
		
		BusinessInfo[businessid][E_BUSINESS_INTERIORPOSINTERIOR] = GetPlayerInterior(playerid);
		BusinessInfo[businessid][E_BUSINESS_INTERIORPOSWORLD] = world;
		
		SendServerMessage(playerid, "You changed Business %i's interior ID.", businessid);
		
		foreach(new i : Player) if(IsPlayerInBusiness(i) == businessid)
		{
			SetPlayerPosEx(i, BusinessInfo[businessid][E_BUSINESS_INTERIORPOS][0], BusinessInfo[businessid][E_BUSINESS_INTERIORPOS][1], BusinessInfo[businessid][E_BUSINESS_INTERIORPOS][2]);
			SetPlayerInterior(i, GetPlayerInterior(playerid)); SetPlayerVirtualWorld(playerid, world); 
			
			SendServerMessage(i, "The business you were in was amended."); 
		}
	
		SaveBusiness(businessid); 
	}
	else return SendServerMessage(playerid, "You cancelled."); 
	return 1; 
}

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

	if(IsValidDynamic3DTextLabel(BusinessInfo[businessid][E_BUSINESS_ENTRANCETEXT3D]))
		DestroyDynamic3DTextLabel(BusinessInfo[businessid][E_BUSINESS_ENTRANCETEXT3D]);

	if(IsValidDynamicActor(BusinessInfo[businessid][E_BUSINESS_ACTOR]))
		DestroyDynamicActor(BusinessInfo[businessid][E_BUSINESS_ACTOR]);

	switch(BusinessInfo[businessid][E_BUSINESS_TYPE])
	{
		case BUSINESS_TYPE_BANK:
		{
			BusinessInfo[businessid][E_BUSINESS_ENTRANCEPOINTTEXT3D] = CreateDynamic3DTextLabel("[Cashiers]\n{ffffff}Available commands: /bank to see bank menu.", COLOR_POINT, BusinessInfo[businessid][E_BUSINESS_ENTRANCEPOINT][0], BusinessInfo[businessid][E_BUSINESS_ENTRANCEPOINT][1], BusinessInfo[businessid][E_BUSINESS_ENTRANCEPOINT][2], 2.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, BusinessInfo[businessid][E_BUSINESS_INTERIORPOSWORLD], BusinessInfo[businessid][E_BUSINESS_INTERIORPOSINTERIOR]);
		}
		case BUSINESS_TYPE_DINNER:
		{
			BusinessInfo[businessid][E_BUSINESS_ENTRANCEPOINTTEXT3D] = CreateDynamic3DTextLabel("[Cashiers]\n{ffffff}Available commands: /menu to see food & drink menu.", COLOR_POINT, BusinessInfo[businessid][E_BUSINESS_ENTRANCEPOINT][0], BusinessInfo[businessid][E_BUSINESS_ENTRANCEPOINT][1], BusinessInfo[businessid][E_BUSINESS_ENTRANCEPOINT][2], 2.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, BusinessInfo[businessid][E_BUSINESS_INTERIORPOSWORLD], BusinessInfo[businessid][E_BUSINESS_INTERIORPOSINTERIOR]);
		}
		case BUSINESS_TYPE_BAR:
		{
			BusinessInfo[businessid][E_BUSINESS_ENTRANCEPOINTTEXT3D] = CreateDynamic3DTextLabel("[Cashiers]\n{ffffff}Available commands: /buybeer to see menu.", COLOR_POINT, BusinessInfo[businessid][E_BUSINESS_ENTRANCEPOINT][0], BusinessInfo[businessid][E_BUSINESS_ENTRANCEPOINT][1], BusinessInfo[businessid][E_BUSINESS_ENTRANCEPOINT][2], 2.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, BusinessInfo[businessid][E_BUSINESS_INTERIORPOSWORLD], BusinessInfo[businessid][E_BUSINESS_INTERIORPOSINTERIOR]);
		}
			
		case BUSINESS_TYPE_ACID:
		{
			BusinessInfo[businessid][E_BUSINESS_ENTRANCEPOINTTEXT3D] = CreateDynamic3DTextLabel("[Production]\n{ffffff}Available commands: /production to opens the production menu.", COLOR_POINT, BusinessInfo[businessid][E_BUSINESS_ENTRANCEPOINT][0], BusinessInfo[businessid][E_BUSINESS_ENTRANCEPOINT][1], BusinessInfo[businessid][E_BUSINESS_ENTRANCEPOINT][2], 2.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, BusinessInfo[businessid][E_BUSINESS_INTERIORPOSWORLD], BusinessInfo[businessid][E_BUSINESS_INTERIORPOSINTERIOR]);
		}
		    
		case BUSINESS_TYPE_GENERAL:
		{
			BusinessInfo[businessid][E_BUSINESS_ENTRANCEPOINTTEXT3D] = CreateDynamic3DTextLabel("[Cashiers]\n{ffffff}Press 'N' to pay items to clerk.", COLOR_POINT, BusinessInfo[businessid][E_BUSINESS_ENTRANCEPOINT][0], BusinessInfo[businessid][E_BUSINESS_ENTRANCEPOINT][1], BusinessInfo[businessid][E_BUSINESS_ENTRANCEPOINT][2], 2.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, BusinessInfo[businessid][E_BUSINESS_INTERIORPOSWORLD], BusinessInfo[businessid][E_BUSINESS_INTERIORPOSINTERIOR]);
		}
		    
		case BUSINESS_TYPE_GUNSTORE:
		{
			BusinessInfo[businessid][E_BUSINESS_ENTRANCEPOINTTEXT3D] = CreateDynamic3DTextLabel("[Production]\n{ffffff}Available commands: /creategun to create weapons / ammo with materials..", COLOR_POINT, BusinessInfo[businessid][E_BUSINESS_ENTRANCEPOINT][0], BusinessInfo[businessid][E_BUSINESS_ENTRANCEPOINT][1], BusinessInfo[businessid][E_BUSINESS_ENTRANCEPOINT][2], 2.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, BusinessInfo[businessid][E_BUSINESS_INTERIORPOSWORLD], BusinessInfo[businessid][E_BUSINESS_INTERIORPOSINTERIOR]);
		}
		    
		case BUSINESS_TYPE_CLOTHES:
		{
			BusinessInfo[businessid][E_BUSINESS_ENTRANCEPOINTTEXT3D] = CreateDynamic3DTextLabel("[Cashiers]\n{ffffff}Available commands: /clothes to see list clothing.", COLOR_POINT, BusinessInfo[businessid][E_BUSINESS_ENTRANCEPOINT][0], BusinessInfo[businessid][E_BUSINESS_ENTRANCEPOINT][1], BusinessInfo[businessid][E_BUSINESS_ENTRANCEPOINT][2], 2.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, BusinessInfo[businessid][E_BUSINESS_INTERIORPOSWORLD], BusinessInfo[businessid][E_BUSINESS_INTERIORPOSINTERIOR]);
		}
		    
		case BUSINESS_TYPE_HAIRCUT:
		{
			BusinessInfo[businessid][E_BUSINESS_ENTRANCEPOINTTEXT3D] = CreateDynamic3DTextLabel("[Cashiers]\n{ffffff}Available commands: /haircut to see list style haircut.", COLOR_POINT, BusinessInfo[businessid][E_BUSINESS_ENTRANCEPOINT][0], BusinessInfo[businessid][E_BUSINESS_ENTRANCEPOINT][1], BusinessInfo[businessid][E_BUSINESS_ENTRANCEPOINT][2], 2.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, BusinessInfo[businessid][E_BUSINESS_INTERIORPOSWORLD], BusinessInfo[businessid][E_BUSINESS_INTERIORPOSINTERIOR]);
		}
		   
		case BUSINESS_TYPE_FURNITURE:
		{
			BusinessInfo[businessid][E_BUSINESS_ENTRANCEPOINTTEXT3D] = CreateDynamic3DTextLabel("[Cashiers]\n{ffffff}Available commands: Press 'N' to pay items to clerk.", COLOR_POINT, BusinessInfo[businessid][E_BUSINESS_ENTRANCEPOINT][0], BusinessInfo[businessid][E_BUSINESS_ENTRANCEPOINT][1], BusinessInfo[businessid][E_BUSINESS_ENTRANCEPOINT][2], 2.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, BusinessInfo[businessid][E_BUSINESS_INTERIORPOSWORLD], BusinessInfo[businessid][E_BUSINESS_INTERIORPOSINTERIOR]);
		}
		    
		case BUSINESS_TYPE_CLUB:
		{
			BusinessInfo[businessid][E_BUSINESS_ENTRANCEPOINTTEXT3D] = CreateDynamic3DTextLabel("[Cashiers]\n{ffffff}Available commands: /buybeer to see menu.", COLOR_POINT, BusinessInfo[businessid][E_BUSINESS_ENTRANCEPOINT][0], BusinessInfo[businessid][E_BUSINESS_ENTRANCEPOINT][1], BusinessInfo[businessid][E_BUSINESS_ENTRANCEPOINT][2], 2.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, BusinessInfo[businessid][E_BUSINESS_INTERIORPOSWORLD], BusinessInfo[businessid][E_BUSINESS_INTERIORPOSINTERIOR]);
		}
			
		case BUSINESS_TYPE_DEALERSHIP:
		{
			BusinessInfo[businessid][E_BUSINESS_ENTRANCEPOINTTEXT3D] = CreateDynamic3DTextLabel("[Cashiers]\n{ffffff}Available commands: /carbuy to see menu.", COLOR_POINT, BusinessInfo[businessid][E_BUSINESS_ENTRANCEPOINT][0], BusinessInfo[businessid][E_BUSINESS_ENTRANCEPOINT][1], BusinessInfo[businessid][E_BUSINESS_ENTRANCEPOINT][2], 2.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, BusinessInfo[businessid][E_BUSINESS_INTERIORPOSWORLD], BusinessInfo[businessid][E_BUSINESS_INTERIORPOSINTERIOR]);
		}
			
		case BUSINESS_TYPE_DMV:
		{
			BusinessInfo[businessid][E_BUSINESS_ENTRANCEPOINTTEXT3D] = CreateDynamic3DTextLabel("[Cashiers]\n{ffffff}Available commands: /drivetest to see menu.", COLOR_POINT, BusinessInfo[businessid][E_BUSINESS_ENTRANCEPOINT][0], BusinessInfo[businessid][E_BUSINESS_ENTRANCEPOINT][1], BusinessInfo[businessid][E_BUSINESS_ENTRANCEPOINT][2], 2.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, BusinessInfo[businessid][E_BUSINESS_INTERIORPOSWORLD], BusinessInfo[businessid][E_BUSINESS_INTERIORPOSINTERIOR]);
		}
			
		case BUSINESS_TYPE_GYM:
		{
			BusinessInfo[businessid][E_BUSINESS_ENTRANCEPOINTTEXT3D] = CreateDynamic3DTextLabel("[Cashiers]\n{ffffff}Available commands: /fightstyle to learn fightstyles.", COLOR_POINT, BusinessInfo[businessid][E_BUSINESS_ENTRANCEPOINT][0], BusinessInfo[businessid][E_BUSINESS_ENTRANCEPOINT][1], BusinessInfo[businessid][E_BUSINESS_ENTRANCEPOINT][2], 2.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, BusinessInfo[businessid][E_BUSINESS_INTERIORPOSWORLD], BusinessInfo[businessid][E_BUSINESS_INTERIORPOSINTERIOR]);
		}
	}

	BusinessInfo[businessid][E_BUSINESS_ACTOR] = CreateDynamicActor(BusinessActor[BusinessInfo[businessid][E_BUSINESS_TYPE]][E_BACTOR_SKIN], BusinessActor[BusinessInfo[businessid][E_BUSINESS_TYPE]][E_BACTOR_POS][0], BusinessActor[BusinessInfo[businessid][E_BUSINESS_TYPE]][E_BACTOR_POS][1], BusinessActor[BusinessInfo[businessid][E_BUSINESS_TYPE]][E_BACTOR_POS][2], BusinessActor[BusinessInfo[businessid][E_BUSINESS_TYPE]][E_BACTOR_POS][3], false);
	SetDynamicActorVirtualWorld(BusinessInfo[businessid][E_BUSINESS_ACTOR], BusinessInfo[businessid][E_BUSINESS_INTERIORPOSWORLD]);

	BusinessInfo[businessid][E_BUSINESS_PICKUP] = CreateDynamicPickup(1272, 1, BusinessInfo[businessid][E_BUSINESS_ENTRANCEPOS][0], BusinessInfo[businessid][E_BUSINESS_ENTRANCEPOS][1], BusinessInfo[businessid][E_BUSINESS_ENTRANCEPOS][2], 0, 0, -1, 5.0);
	BusinessInfo[businessid][E_BUSINESS_ENTRANCETEXT3D] = CreateDynamic3DTextLabel(BusinessInfo[businessid][E_BUSINESS_NAME], COLOR_DARKGREEN, BusinessInfo[businessid][E_BUSINESS_ENTRANCEPOS][0], BusinessInfo[businessid][E_BUSINESS_ENTRANCEPOS][1], BusinessInfo[businessid][E_BUSINESS_ENTRANCEPOS][2], 5.0);
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
		SendServerMessage(playerid, "You changed Business %i's entrance.", businessid);
		SaveBusiness(businessid); 
	}
	else return SendServerMessage(playerid, "You cancelled.");
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
		SendServerMessage(playerid, "You changed Business %i's point.", businessid);
		SaveBusiness(businessid); 
	}
	else return SendServerMessage(playerid, "You cancelled.");
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
			format(str, sizeof(str), "Welcome to %s.\nAvailable commands: /creategun create weapons / ammo with materials.", BusinessInfo[id][E_BUSINESS_NAME]);
			SendClientMessage(playerid, COLOR_SERVER, str);
		}
		case BUSINESS_TYPE_BANK:
		{
			format(str, sizeof(str), "Welcome to %s.\nAvailable commands: /withdraw, /deposit, /balance to see bank menu.", BusinessInfo[id][E_BUSINESS_NAME]);
			SendClientMessage(playerid, COLOR_SERVER, str);
		}
		case BUSINESS_TYPE_GENERAL:
		{
			format(str, sizeof(str), "Welcome to %s.\nThis is a general store you can buy anything.", BusinessInfo[id][E_BUSINESS_NAME]);
			SendClientMessage(playerid, COLOR_SERVER, str);
		}
		case BUSINESS_TYPE_CLUB:
		{
			format(str, sizeof(str), "Welcome to %s.\nAvailable commands: /buybeer to see business menu.", BusinessInfo[id][E_BUSINESS_NAME]);
			SendClientMessage(playerid, COLOR_SERVER, str);
		}
		case BUSINESS_TYPE_DINNER:
		{
			format(str, sizeof(str), "Welcome to %s.\nAvailable commands: /menu to see business menu.", BusinessInfo[id][E_BUSINESS_NAME]);
			SendClientMessage(playerid, COLOR_SERVER, str);
		}
		case BUSINESS_TYPE_BAR:
		{
			format(str, sizeof(str), "Welcome to %s.\nAvailable commands: /buybeer to see business menu.", BusinessInfo[id][E_BUSINESS_NAME]);
			SendClientMessage(playerid, COLOR_SERVER, str);
		}
		case BUSINESS_TYPE_ACID:
		{
			SendClientMessageEx(playerid, COLOR_DARKGREEN, "Welcome to %s\nAvailable commands: /production to opens the production menu", BusinessInfo[id][E_BUSINESS_NAME]);
		}
		case BUSINESS_TYPE_CLOTHES:
		{
			format(str, sizeof(str), "Welcome to %s.\nAvailable commands: /clothes to see business menu.", BusinessInfo[id][E_BUSINESS_NAME]);
			SendClientMessage(playerid, COLOR_SERVER, str);
		}
		case BUSINESS_TYPE_HAIRCUT:
		{
			format(str, sizeof(str), "Welcome to %s.\nAvailable commands: /haircut to see haircut style list.", BusinessInfo[id][E_BUSINESS_NAME]);
			SendClientMessage(playerid, COLOR_SERVER, str);
		}
		case BUSINESS_TYPE_FURNITURE:
		{
			format(str, sizeof(str), "Welcome to %s.\nAvailable commands: /props to see business menu.", BusinessInfo[id][E_BUSINESS_NAME]);
			SendClientMessage(playerid, COLOR_SERVER, str);
		}
		case BUSINESS_TYPE_GYM:
		{
			format(str, sizeof(str), "Welcome to %s.\nAvailable commands: /fightstyle to see business menu.", BusinessInfo[id][E_BUSINESS_NAME]);
			SendClientMessage(playerid, COLOR_SERVER, str);
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
		SendServerMessage(playerid, "You sold your business and earned $%s.", FormatMoney(totalPay)); 
		
		SaveBusiness(businessid); SaveCharacter(playerid); 
	}
	else return SendServerMessage(playerid, "You cancelled selling your business.");
	return 1;
}

function:OnPlayerExitDealership(playerid, response)
{
	if(response)
	{
		SendServerMessage(playerid, "You exited out the dealership.");
		
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
	
	BusinessInfo[newid][E_BUSINESS_INTERIORPOS][0] = bizInteriors[type][E_INT_X]; 
	BusinessInfo[newid][E_BUSINESS_INTERIORPOS][1] = bizInteriors[type][E_INT_Y]; 
	BusinessInfo[newid][E_BUSINESS_INTERIORPOS][2] = bizInteriors[type][E_INT_Z]; 
	BusinessInfo[newid][E_BUSINESS_INTERIORPOSINTERIOR] = bizInteriors[type][E_INT_ID];
	BusinessInfo[newid][E_BUSINESS_INTERIORPOSWORLD] = world;  

	BusinessRefresh(newid);
	SendServerMessage(playerid, "You created business ID #%i. To configure, use \"/editbusiness\". ", newid); 
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

CMD:createbusiness(playerid, params[])
{
	if(IsPlayerAdmins(playerid) < ADMINS_OWNER)
		return 0;		

	new 
		type_id,
		idx,
		query[128]
	; 
	
	if(sscanf(params, "i", type_id))
	{
		SendUsageMessage(playerid, "/createbusiness business id [business type]"); 
		SendClientMessage(playerid, COLOR_WHITE, "Types: 1. Dinner's, 2. Bar, 3. Acidlabs, 4. Gunstore, 5. Club, 6. Bank, 7. General.");
		SendClientMessage(playerid, COLOR_WHITE, "Types: 8. Clothes, 9. Dealership, 10. DMV, 11. Barbershop, 12. Furniture, 13. Gym."); 
		return 1;
	}
	
	if(type_id > 13 || type_id < 1)
		return SendErrorMessage(playerid, "You specified an invalid type.");
	
	for(new i = 1; i < MAX_BUSINESS; i++)
	{
		if(!BusinessInfo[i][E_BUSINESS_DBID])
		{
			idx = i;
			break;
		}
	}
	
	if(idx == 0)
		return SendErrorMessage(playerid, "You can't make anymore businesses."); 
		
	
	mysql_format(ourConnection, query, sizeof(query), "INSERT INTO businesses (BusinessType) VALUES(%i)", type_id); 
	mysql_pquery(ourConnection, query, "Query_InsertBusiness", "iii", playerid, idx, type_id); 
	return 1;
}

CMD:editbusiness(playerid, params[])
{
	if(IsPlayerAdmins(playerid) < ADMINS_OWNER)
		return 0;

	new 
		id,
		astr[90],
		bstr[90];
		
	if(sscanf(params, "is[90]S()[90]", id, astr, bstr))
	{
		SendUsageMessage(playerid, "/editbusiness [business ID] [configuration]");
		SendClientMessage(playerid, COLOR_WHITE, "entrance, point, type, level, mapicon");
		SendClientMessage(playerid, COLOR_WHITE, "entrancefee, name, bankpickup, marketprice"); 
		return 1;
	}
	
	if(!BusinessInfo[id][E_BUSINESS_DBID] || id > MAX_BUSINESS)
		return SendErrorMessage(playerid, "You specified an invalid business ID.");
		
	if(!strcmp(astr, "entrance"))
	{
		ConfirmDialog(playerid, "Confirmation", "Are you sure you want to change this businesses entrance?", "OnBusinessEntranceChange", id); 
	}
	else if(!strcmp(astr, "point"))
	{
		new Float:x, Float:y, Float:z;
		GetPlayerPos(playerid, x, y, z);
		PlayerInfo[playerid][E_CHARACTER_ADDOBJECT] = CreateDynamicObject(1239, x, y, z, 0.0, 0.0, 0.0, GetPlayerVirtualWorld(playerid), GetPlayerInterior(playerid)); 
		EditDynamicObject(playerid, PlayerInfo[playerid][E_CHARACTER_ADDOBJECT]); 
		PlayerInfo[playerid][E_CHARACTER_EDITINGOBJECT] = 6;
	}
	else if(!strcmp(astr, "type"))
	{
		new type;
		
		if(sscanf(bstr, "i", type))
		{
			SendUsageMessage(playerid, "/editbusiness %i [business type]"); 
			SendClientMessage(playerid, COLOR_WHITE, "Types: 1. Dinner's, 2. Bar, 3. Acidlabs, 4. Gunstore, 5. Club, 6. Bank, 7. General.");
			SendClientMessage(playerid, COLOR_WHITE, "Types: 8. Clothes, 9. Dealership, 10. DMV, 11. Barbershop, 12. Furniture, 13. Gym."); 
			return 1;
		}

		if(type > 13 || type < 1)
			return SendErrorMessage(playerid, "You specified an invalid type.");
			
		if(type == BusinessInfo[id][E_BUSINESS_TYPE])
			return SendErrorMessage(playerid, "You can't set the businesses type to what it already is."); 
			
		BusinessRefresh(id);
		SendServerMessage(playerid, "You changed business %i's type to %i.", id, type);
		SaveBusiness(id);	
	}
	else if(!strcmp(astr, "level"))
	{
		new level;
		
		if(sscanf(bstr, "i", level))
			return SendUsageMessage(playerid, "/editbusiness %i level [level]", id);
			
		if(level < 1)
			return SendErrorMessage(playerid, "You can't make the level below 1."); 
			
		BusinessInfo[id][E_BUSINESS_LEVEL] = level;
		
		SendServerMessage(playerid, "You set business %i's level to %i.", id, level);
		SaveBusiness(id);
	}
	else if(!strcmp(astr, "entrancefee"))
	{
		new fee;
		
		if(sscanf(bstr, "i", fee))
			return SendUsageMessage(playerid, "/editbusiness %i entrancefee [amount]", id);
			
		if(fee > 1500)
			return SendErrorMessage(playerid, "The entrance fee can't be above 1500.");
			
		BusinessInfo[id][E_BUSINESS_ENTRANCEFEE] = fee;
		
		SendServerMessage(playerid, "You set business %i's entrance fee to %i.", id, fee);
		SaveBusiness(id);
	}
	else if(!strcmp(astr, "name"))
	{
		new bizname[90]; 
		
		if(sscanf(bstr, "s[90]", bizname))
		{
			SendUsageMessage(playerid, "/editbusiness %i name [business name]", id);
			SendServerMessage(playerid, "You can use text colors (i.e ~r~Red ~b~Blue) in the name."); 
			return 1;
		}
		
		if(strlen(bizname) > 90)
			return SendErrorMessage(playerid, "Stay below 90 characters.");
			
		SendServerMessage(playerid, "You set business %i's name from \"%s\" to \"%s\". ", id, BusinessInfo[id][E_BUSINESS_NAME], bizname); 
		
		format(BusinessInfo[id][E_BUSINESS_NAME], 90, "%s", bizname);
		SaveBusiness(id); 
	}
	else if(!strcmp(astr, "bankpickup"))
	{
		if(BusinessInfo[id][E_BUSINESS_TYPE] != BUSINESS_TYPE_BANK)
			return SendErrorMessage(playerid, "This business isn't a bank."); 
			
		ConfirmDialog(playerid, "Confirmation", "Are you sure you want to set / change this banks pickup?", "OnBusinessBankpickupChange", id);
	}
	else if(!strcmp(astr, "price"))
	{
		new price;
		
		if(sscanf(bstr, "i", price))
			return SendUsageMessage(playerid, "/editbusiness %i price [amount]", id);
			
		BusinessInfo[id][E_BUSINESS_PRICE] = price;
		
		SendServerMessage(playerid, "You set business %i's market price to $%s.", id, FormatMoney(price));
		SaveBusiness(id);
	}
	else return SendErrorMessage(playerid, "Invalid Parameter.");
	return 1;
}