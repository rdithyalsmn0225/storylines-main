/*=====[COOKED DRUGS]=====*/
function:CookDrugs(playerid, type, id)
{
	new text[256];
    DroppedInfo[id][E_DROPPED_LOADINGCOUNT]++;
	switch(type)
	{
		case 1:
		{
			switch(DroppedInfo[id][E_DROPPED_LOADINGCOUNT])
			{
				case 2: text = "CRACK COOK IN PROCESS\nSupplied Coke: 5 gram\nExpected Output: 5-7 gram\nTime Left: ((||-----))";
				case 3: text = "CRACK COOK IN PROCESS\nSupplied Coke: 5 gram\nExpected Output: 5-7 gram\nTime Left: ((|||----))";
				case 4: text = "CRACK COOK IN PROCESS\nSupplied Coke: 5 gram\nExpected Output: 5-7 gram\nTime Left: ((||||---))";
				case 5: text = "CRACK COOK IN PROCESS\nSupplied Coke: 5 gram\nExpected Output: 5-7 gram\nTime Left: ((|||||--))";
				case 6: text = "CRACK COOK IN PROCESS\nSupplied Coke: 5 gram\nExpected Output: 5-7 gram\nTime Left: ((||||||-))";
				case 7: text = "CRACK COOK IN PROCESS\nSupplied Coke: 5 gram\nExpected Output: 5-7 gram\nTime Left: ((|||||||))";
				case 8:
				{
					Delete3DTextLabel(DroppedInfo[id][E_DROPPED_LOADINGDISPLAY]); 
					KillTimer(DroppedInfo[id][E_DROPPED_LOADINGTIMER]);
					DroppedInfo[id][E_DROPPED_LOADINGCOUNT] = 0;
					DroppedInfo[id][E_DROPPED_LOADING] = true;
					
					DroppedInfo[id][E_DROPPED_AMOUNT] = 1;

					new string[512];
					format(string, sizeof(string), "UPDATE `dropped` SET `itemAmount` = %d WHERE `ID` = '%d'", 1, id);
	    			mysql_pquery(ourConnection, string);

					Inventory_Remove(playerid, "Cocaine", 2);
					Inventory_Remove(playerid, "Baking Soda", 2);

					PlayerInfo[playerid][E_CHARACTER_SELECTITEMS] = 1;
				}
			}
		}
		case 2:
		{
			switch(DroppedInfo[id][E_DROPPED_LOADINGCOUNT])
			{
				case 2: text = "PCP COOK IN PROCESS\nSupplied Marijuana: 5 gram\nExpected Output: 3-5 gram\nTime Left: ((||-----))";
				case 3: text = "PCP COOK IN PROCESS\nSupplied Marijuana: 5 gram\nExpected Output: 3-5 gram\nTime Left: ((|||----))";
				case 4: text = "PCP COOK IN PROCESS\nSupplied Marijuana: 5 gram\nExpected Output: 3-5 gram\nTime Left: ((||||---))";
				case 5: text = "PCP COOK IN PROCESS\nSupplied Marijuana: 5 gram\nExpected Output: 3-5 gram\nTime Left: ((|||||--))";
				case 6: text = "PCP COOK IN PROCESS\nSupplied Marijuana: 5 gram\nExpected Output: 3-5 gram\nTime Left: ((||||||-))";
				case 7: text = "PCP COOK IN PROCESS\nSupplied Marijuana: 5 gram\nExpected Output: 3-5 gram\nTime Left: ((|||||||))";
				case 8:
				{
					Delete3DTextLabel(DroppedInfo[id][E_DROPPED_LOADINGDISPLAY]); 
					KillTimer(DroppedInfo[id][E_DROPPED_LOADINGTIMER]);
					DroppedInfo[id][E_DROPPED_LOADINGCOUNT] = 0;
					DroppedInfo[id][E_DROPPED_LOADING] = true;
					
					DroppedInfo[id][E_DROPPED_AMOUNT] = 1;

					new string[512];
					format(string, sizeof(string), "UPDATE `dropped` SET `itemAmount` = %d WHERE `ID` = '%d'", 1, id);
	    			mysql_pquery(ourConnection, string);
					
					Inventory_Remove(playerid, "Marijuana", 2);
					Inventory_Remove(playerid, "Parsley", 2);
					Inventory_Remove(playerid, "Mint", 1);
					Inventory_Remove(playerid, "Baking Soda", 1);

					PlayerInfo[playerid][E_CHARACTER_SELECTITEMS] = 2;
				}
			}
		}
    }
    Update3DTextLabelText(DroppedInfo[id][E_DROPPED_LOADINGDISPLAY], COLOR_DARKGREEN, text); 
}

/*=====[PURCHASE DRUGS]=====*/
function:OnPlayerPurchaseDrugs(playerid, response, type, amount, price)
{
	if(response)
	{
		if(type == 0)
		{
			new str[128];

			if(price > PlayerInfo[playerid][E_CHARACTER_MONEY])
				return SendErrorMessage(playerid, "You can't afford this. (Cost: $%s, Total: $%s)", FormatMoney(price), FormatMoney(PlayerInfo[playerid][E_CHARACTER_MONEY]));

			GiveMoney(playerid, -price);
			Inventory_Add(playerid, "Marijuana", -2501, amount);
			FactionInfo[PlayerInfo[playerid][E_CHARACTER_FACTION]][E_FACTION_STORAGE] -= amount;
			SaveFaction(PlayerInfo[playerid][E_CHARACTER_FACTION]);
			
			format(str, sizeof(str), "%s bought %d Marijuana Ammo", ReturnSettingsName(playerid, playerid), amount);
			SendAdminMessage(1, str); 
		}
		else if(type == 1)
		{
			new str[128];
			
			if(price > PlayerInfo[playerid][E_CHARACTER_MONEY])
				return SendErrorMessage(playerid, "You can't afford this. (Cost: $%s, Total: $%s)", FormatMoney(price), FormatMoney(PlayerInfo[playerid][E_CHARACTER_MONEY]));
		
			GiveMoney(playerid, -price);
			Inventory_Add(playerid, "Cocaine", -2502, amount);
			FactionInfo[PlayerInfo[playerid][E_CHARACTER_FACTION]][E_FACTION_STORAGE] -= amount;
			SaveFaction(PlayerInfo[playerid][E_CHARACTER_FACTION]);
			
			format(str, sizeof(str), "%s bought %d Cocaine Ammo for %s", ReturnSettingsName(playerid, playerid), amount);
			SendAdminMessage(1, str); 
		}
		else if(type == 2)
		{
			new str[128];
			
			GiveMoney(playerid, -price);
			Inventory_Add(playerid, "Heroin", -2500, amount);
			FactionInfo[PlayerInfo[playerid][E_CHARACTER_FACTION]][E_FACTION_STORAGE] -= amount;
			SaveFaction(PlayerInfo[playerid][E_CHARACTER_FACTION]);
			
			format(str, sizeof(str), "%s bought %d Cocaine Ammo for %s", ReturnSettingsName(playerid, playerid), amount);
			SendAdminMessage(1, str); 
		}
	}
	return 1;
}

/*=====[CONSUME DRUGS]=====*/
stock IsPlayerUsingDrugs(playerid, type)
{
	switch(type)
	{
		case 1: //Marijuana
		{
			if(!Inventory_Count(playerid, "Marijuana"))
				return SendErrorMessage(playerid, "You don't have any marijuana in inventory.");

			if(Inventory_Count(playerid, "Marijuana") < 5)
				return SendErrorMessage(playerid, "You need at least 5 grams of marijuana.");

			if(GetPlayerTeam(playerid) != PLAYER_STATE_ALIVE) return SendErrorMessage(playerid, "You can't use this command while injured!");

			if(gettime() - PlayerInfo[playerid][E_CHARACTER_DRUGSCD] < 60)
				return SendErrorMessage(playerid, "You've only been consume drugs for %i seconds. You need to wait at least 60 sec to consume drugs.", gettime() - PlayerInfo[playerid][E_CHARACTER_DRUGSCD]); 

			Inventory_Remove(playerid, "Marijuana", 5);
			ApplyAnimation(playerid, "SMOKING", "M_smk_in", 4.1, 0, 0, 0, 0, 0, 1);

			new Float:health;
			GetPlayerHealth(playerid, health);
			PlayerInfo[playerid][E_CHARACTER_DRUGSCD] = gettime();
			if(health > 125)
			{
				SetPlayerHealthEx(playerid, 125);
			}
			SetPlayerHealthEx(playerid, health+10);

			SetPlayerDrunkLevel(playerid, 2000);

			new turfid = IsPlayerNearTurf(playerid);
			if(turfid)
			{	
				if(GetPlayerTeam(playerid) != PLAYER_STATE_WOUNDED && GlobalTurf == 0 && TurfInfo[turfid][E_FACTION_TURFTYPE] == 0 && FactionInfo[PlayerInfo[playerid][E_CHARACTER_FACTION]][E_FACTION_TYPE] == FACTION_TYPE_ILLEGAL)
				{
					TurfsPoints(playerid, turfid);
				}
			}
			if(PlayerInfo[playerid][E_CHARACTER_EQUIPITEMS] > INVENTORY_NONE)
			{
				ResetVarInventory(playerid);
			}
		}
		case 2: //Cocaine
		{
			if(!Inventory_Count(playerid, "Cocaine"))
				return SendErrorMessage(playerid, "You don't have any cocaine in inventory.");

			if(Inventory_Count(playerid, "Cocaine") < 5)
				return SendErrorMessage(playerid, "You need at least 5 grams of cocaine.");

			if(GetPlayerTeam(playerid) != PLAYER_STATE_ALIVE) return SendErrorMessage(playerid, "You can't use this command while injured!");

			if(gettime() - PlayerInfo[playerid][E_CHARACTER_DRUGSCD] < 60)
				return SendErrorMessage(playerid, "You've only been consume drugs for %i seconds. You need to wait at least 60 sec to consume drugs.", gettime() - PlayerInfo[playerid][E_CHARACTER_DRUGSCD]); 

			Inventory_Remove(playerid, "Cocaine", 5);
			ApplyAnimation(playerid, "SMOKING", "M_smk_in", 4.1, 0, 0, 0, 0, 0, 1);

			new Float:health;
			GetPlayerHealth(playerid, health);
			PlayerInfo[playerid][E_CHARACTER_DRUGSCD] = gettime();
			if(health > 125)
			{
				SetPlayerHealthEx(playerid, 125);
			}
			SetPlayerHealthEx(playerid, health+10);

			SetPlayerDrunkLevel(playerid, 2000);

			new turfid = IsPlayerNearTurf(playerid);
			if(turfid)
			{	
				if(GetPlayerTeam(playerid) != PLAYER_STATE_WOUNDED && GlobalTurf == 0 && TurfInfo[turfid][E_FACTION_TURFTYPE] == 0 && FactionInfo[PlayerInfo[playerid][E_CHARACTER_FACTION]][E_FACTION_TYPE] == FACTION_TYPE_ILLEGAL)
				{
					TurfsPoints(playerid, turfid);
				}
			}
			if(PlayerInfo[playerid][E_CHARACTER_EQUIPITEMS] > INVENTORY_NONE)
			{
				ResetVarInventory(playerid);
			}
		}
		case 3: //Heroin
		{
			if(!Inventory_Count(playerid, "Heroin"))
				return SendErrorMessage(playerid, "You don't have any heroin in inventory.");

			if(Inventory_Count(playerid, "Heroin") < 5)
				return SendErrorMessage(playerid, "You need at least 5 grams of heroin.");

			Inventory_Remove(playerid, "Heroin", 5);
			ApplyAnimation(playerid, "SMOKING", "M_smk_in", 4.1, 0, 0, 0, 0, 0, 1);

			SetPlayerSpecialAction(playerid, SPECIAL_ACTION_SMOKE_CIGGY);

			new turfid = IsPlayerNearTurf(playerid);
			if(turfid)
			{	
				if(GetPlayerTeam(playerid) != PLAYER_STATE_WOUNDED && GlobalTurf == 0 && TurfInfo[turfid][E_FACTION_TURFTYPE] == 0 && FactionInfo[PlayerInfo[playerid][E_CHARACTER_FACTION]][E_FACTION_TYPE] == FACTION_TYPE_ILLEGAL)
				{
					TurfsPoints(playerid, turfid);
				}
			}
			if(PlayerInfo[playerid][E_CHARACTER_EQUIPITEMS] > INVENTORY_NONE)
			{
				ResetVarInventory(playerid);
			}
		}
		case 4: //Cocaine Crack
		{
			if(!Inventory_Count(playerid, "Cocaine Crack"))
				return SendErrorMessage(playerid, "You don't have any crack in inventory.");

			if(Inventory_Count(playerid, "Cocaine Crack") < 5)
				return SendErrorMessage(playerid, "You need at least 5 grams of crack.");

			if(gettime() - PlayerInfo[playerid][E_CHARACTER_DRUGSCD] < 60)
				return SendErrorMessage(playerid,  "You've only been consume drugs for %i seconds. You need to wait at least 60 sec to consume drugs.", gettime() - PlayerInfo[playerid][E_CHARACTER_DRUGSCD]); 

			if(GetPlayerTeam(playerid) != PLAYER_STATE_ALIVE) return SendErrorMessage(playerid, "You can't use this command while injured!");

			Inventory_Remove(playerid, "Cocaine Crack", 5);
			ApplyAnimation(playerid, "SMOKING", "M_smk_in", 4.1, 0, 0, 0, 0, 0, 1);

			new Float:health;
			GetPlayerHealth(playerid, health);
			PlayerInfo[playerid][E_CHARACTER_DRUGSCD] = gettime();
			if(health > 150)
			{
				SetPlayerHealthEx(playerid, 150);
			}
			SetPlayerHealthEx(playerid, health+15);
			SetPlayerDrunkLevel(playerid, 4000);

			new turfid = IsPlayerNearTurf(playerid);
			if(turfid)
			{	
				if(GetPlayerTeam(playerid) != PLAYER_STATE_WOUNDED && GlobalTurf == 0 && TurfInfo[turfid][E_FACTION_TURFTYPE] == 0 && FactionInfo[PlayerInfo[playerid][E_CHARACTER_FACTION]][E_FACTION_TYPE] == FACTION_TYPE_ILLEGAL)
				{
					TurfsPoints(playerid, turfid);
				}
			}
			if(PlayerInfo[playerid][E_CHARACTER_EQUIPITEMS] > INVENTORY_NONE)
			{
				ResetVarInventory(playerid);
			}
		}
		case 5: //PCP
		{
			if(!Inventory_Count(playerid, "PCP"))
				return SendErrorMessage(playerid, "You don't have any pcp in inventory.");

			if(Inventory_Count(playerid, "PCP") < 5)
				return SendErrorMessage(playerid, "You need at least 5 grams of pcp.");

			if(GetPlayerTeam(playerid) != PLAYER_STATE_ALIVE) return SendErrorMessage(playerid, "You can't use this command while injured!");

			if(gettime() - PlayerInfo[playerid][E_CHARACTER_DRUGSCD] < 60)
				return SendErrorMessage(playerid, "You've only been consume drugs for %i seconds. You need to wait at least 60 sec to consume drugs.", gettime() - PlayerInfo[playerid][E_CHARACTER_DRUGSCD]); 

			Inventory_Remove(playerid, "PCP", 5);
			ApplyAnimation(playerid, "SMOKING", "M_smk_in", 4.1, 0, 0, 0, 0, 0, 1);

			new Float:health;
			GetPlayerHealth(playerid, health);
			PlayerInfo[playerid][E_CHARACTER_DRUGSCD] = gettime();
			if(health > 125)
			{
				SetPlayerHealthEx(playerid, 125);
			}
			SetPlayerHealthEx(playerid, health+10);

			SetPlayerDrunkLevel(playerid, 2000);

			new turfid = IsPlayerNearTurf(playerid);
			if(turfid)
			{	
				if(GetPlayerTeam(playerid) != PLAYER_STATE_WOUNDED && GlobalTurf == 0 && TurfInfo[turfid][E_FACTION_TURFTYPE] == 0 && FactionInfo[PlayerInfo[playerid][E_CHARACTER_FACTION]][E_FACTION_TYPE] == FACTION_TYPE_ILLEGAL)
				{
					TurfsPoints(playerid, turfid);
				}
			}
			if(PlayerInfo[playerid][E_CHARACTER_EQUIPITEMS] > INVENTORY_NONE)
			{
				ResetVarInventory(playerid);
			}
		}
	}
	return 1;
}