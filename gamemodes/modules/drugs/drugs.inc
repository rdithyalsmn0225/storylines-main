// COOKED DRUGS:
function:CookDrugs(playerid, type, id)
{
	new text[256];
    BusinessInfo[id][E_BUSINESS_LOADINGCOUNT]++;
	switch(type)
	{
		case 1:
		{
			switch(BusinessInfo[id][E_BUSINESS_LOADINGCOUNT])
			{
				case 2: text = "CRACK COOK IN PROCESS\nSupplied Coke: 5 gram\nExpected Output: 5-7 gram\nTime Left: ((||-----))";
				case 3: text = "CRACK COOK IN PROCESS\nSupplied Coke: 5 gram\nExpected Output: 5-7 gram\nTime Left: ((|||----))";
				case 4: text = "CRACK COOK IN PROCESS\nSupplied Coke: 5 gram\nExpected Output: 5-7 gram\nTime Left: ((||||---))";
				case 5: text = "CRACK COOK IN PROCESS\nSupplied Coke: 5 gram\nExpected Output: 5-7 gram\nTime Left: ((|||||--))";
				case 6: text = "CRACK COOK IN PROCESS\nSupplied Coke: 5 gram\nExpected Output: 5-7 gram\nTime Left: ((||||||-))";
				case 7: text = "CRACK COOK IN PROCESS\nSupplied Coke: 5 gram\nExpected Output: 5-7 gram\nTime Left: ((|||||||))";
				case 8:
				{
					Delete3DTextLabel(BusinessInfo[id][E_BUSINESS_LOADINGDISPLAY]); 
					KillTimer(BusinessInfo[id][E_BUSINESS_LOADINGTIMER]);
					BusinessInfo[id][E_BUSINESS_LOADINGCOUNT] = 0;
					BusinessInfo[id][E_BUSINESS_LOADING] = true;
					
					BusinessInfo[id][E_BUSINESS_AMOUNT] = 1;

					new string[512];
					format(string, sizeof(string), "UPDATE `businesses` SET `BusinessAmount` = %d WHERE `BusinessDBID` = '%d'", 1, id);
	    			mysql_pquery(ourConnection, string);

					Inventory_Remove(playerid, "Cocaine", 2);
					Inventory_Remove(playerid, "Baking Soda", 2);

					PlayerInfo[playerid][E_CHARACTER_SELECTITEMS] = 1;
				}
			}
		}
		case 2:
		{
			switch(BusinessInfo[id][E_BUSINESS_LOADINGCOUNT])
			{
				case 2: text = "PCP COOK IN PROCESS\nSupplied Marijuana: 5 gram\nExpected Output: 3-5 gram\nTime Left: ((||-----))";
				case 3: text = "PCP COOK IN PROCESS\nSupplied Marijuana: 5 gram\nExpected Output: 3-5 gram\nTime Left: ((|||----))";
				case 4: text = "PCP COOK IN PROCESS\nSupplied Marijuana: 5 gram\nExpected Output: 3-5 gram\nTime Left: ((||||---))";
				case 5: text = "PCP COOK IN PROCESS\nSupplied Marijuana: 5 gram\nExpected Output: 3-5 gram\nTime Left: ((|||||--))";
				case 6: text = "PCP COOK IN PROCESS\nSupplied Marijuana: 5 gram\nExpected Output: 3-5 gram\nTime Left: ((||||||-))";
				case 7: text = "PCP COOK IN PROCESS\nSupplied Marijuana: 5 gram\nExpected Output: 3-5 gram\nTime Left: ((|||||||))";
				case 8:
				{
					Delete3DTextLabel(BusinessInfo[id][E_BUSINESS_LOADINGDISPLAY]); 
					KillTimer(BusinessInfo[id][E_BUSINESS_LOADINGTIMER]);
					BusinessInfo[id][E_BUSINESS_LOADINGCOUNT] = 0;
					BusinessInfo[id][E_BUSINESS_LOADING] = true;
					
					BusinessInfo[id][E_BUSINESS_AMOUNT] = 1;

					new string[512];
					format(string, sizeof(string), "UPDATE `businesses` SET `BusinessAmount` = %d WHERE `BusinessDBID` = '%d'", 1, id);
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
    Update3DTextLabelText(BusinessInfo[id][E_BUSINESS_LOADINGDISPLAY], COLOR_3DTEXT, text); 
}

// PURCHASE DRUGS:
function:OnPlayerPurchaseDrugs(playerid, response, type, amount, price)
{
	if(response)
	{
		new Cents = floatround(price * 100, floatround_round);

		if(type == 0)
		{

			if(price > PlayerInfo[playerid][E_CHARACTER_MONEY])
				return SendErrorMessage(playerid, "You can't afford this. (Cost: $%s, Total: $%s)", FormatMoney(Cents), FormatMoney(PlayerInfo[playerid][E_CHARACTER_MONEY]));

			GiveMoney(playerid, Cents);
			Inventory_Add(playerid, "Marijuana", -2501, amount);
			FactionInfo[PlayerInfo[playerid][E_CHARACTER_FACTION]][E_FACTION_STORAGE] -= amount;
			SaveFaction(PlayerInfo[playerid][E_CHARACTER_FACTION]);
			
			SendInfoMessage(playerid, "%s bought %d marijuana for $%s", ReturnName(playerid), FormatMoney(Cents)); 
		}
		else if(type == 1)
		{
			
			if(price > PlayerInfo[playerid][E_CHARACTER_MONEY])
				return SendErrorMessage(playerid, "You can't afford this. (Cost: $%s, Total: $%s)", FormatMoney(Cents), FormatMoney(PlayerInfo[playerid][E_CHARACTER_MONEY]));
		
			
			GiveMoney(playerid, Cents);
			Inventory_Add(playerid, "Cocaine", -2502, amount);
			FactionInfo[PlayerInfo[playerid][E_CHARACTER_FACTION]][E_FACTION_STORAGE] -= amount;
			SaveFaction(PlayerInfo[playerid][E_CHARACTER_FACTION]);

			SendInfoMessage(playerid, "%s bought %d cocaine for $%s", ReturnName(playerid), FormatMoney(Cents)); 
		}
		else if(type == 2)
		{
			
			
			GiveMoney(playerid, Cents);
			Inventory_Add(playerid, "Heroin", -2500, amount);
			FactionInfo[PlayerInfo[playerid][E_CHARACTER_FACTION]][E_FACTION_STORAGE] -= amount;
			SaveFaction(PlayerInfo[playerid][E_CHARACTER_FACTION]);

			SendInfoMessage(playerid, "%s bought %d heroin for $%s", ReturnName(playerid), FormatMoney(Cents)); 
		}
	}
	return 1;
}

// CONSUME DRUGS:
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
			PlayerInfo[playerid][E_CHARACTER_MAXHEALTH] = 115.0;
			SaveCharacter(playerid);
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
			
			SetPlayerHealthEx(playerid, health+10);

			SetPlayerDrunkLevel(playerid, 2000);
			PlayerInfo[playerid][E_CHARACTER_MAXHEALTH] = 125.0;
			SaveCharacter(playerid);
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

			new Float:health;
			GetPlayerHealth(playerid, health);
			PlayerInfo[playerid][E_CHARACTER_DRUGSCD] = gettime();
			
			SetPlayerHealthEx(playerid, health+10);

			SetPlayerDrunkLevel(playerid, 2000);
			PlayerInfo[playerid][E_CHARACTER_MAXHEALTH] = 150.0;
			SaveCharacter(playerid);
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
			
			SetPlayerHealthEx(playerid, health+15);
			SetPlayerDrunkLevel(playerid, 4000);
			PlayerInfo[playerid][E_CHARACTER_MAXHEALTH] = 150.0;
			SaveCharacter(playerid);
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
			
			SetPlayerHealthEx(playerid, health+10);
			
			SetPlayerDrunkLevel(playerid, 2000);
			PlayerInfo[playerid][E_CHARACTER_MAXHEALTH] = 125.0;
			SaveCharacter(playerid);
			if(PlayerInfo[playerid][E_CHARACTER_EQUIPITEMS] > INVENTORY_NONE)
			{
				ResetVarInventory(playerid);
			}
		}
	}
	return 1;
}

CMD:production(playerid, params[])
{
	new id = IsPlayerInBusiness(playerid);
	if (IsPlayerNearCashiers(playerid))
	{
		if(BusinessInfo[id][E_BUSINESS_TYPE] == BUSINESS_TYPE_ACID && BusinessInfo[playerid][E_BUSINESS_LOADING] == false)
		{
			if(BusinessInfo[id][E_BUSINESS_AMOUNT] == 0)
			{
				ShowPlayerDialog(playerid, DIALOG_DRUGSCOMBINE, DIALOG_STYLE_TABLIST_HEADERS, "Choose your drugs:", "Drugs Name\tIngredient\nCocaine Crack\tBaking Soda & Cocaine\nPCP\tMarijuana, Parsley, Mint & Baking Soda", "Select", "Cancel");
			}

			if(BusinessInfo[id][E_BUSINESS_AMOUNT] == 1)
			{
				if(PlayerInfo[playerid][E_CHARACTER_SELECTITEMS] == 1)
				{
					new rand = randomEx(5, 7);
					PlayerInfo[playerid][E_CHARACTER_SELECTITEMS] = 0;
					BusinessInfo[id][E_BUSINESS_AMOUNT] = 0;
					BusinessInfo[id][E_BUSINESS_LOADING] = false;
					
					Inventory_Add(playerid, "Cocaine Crack", -2502, rand);
					SendServerMessage(playerid, "[Production] {cdd0d1}You've receive %d grams of Cocaine Crack.", rand);
				}
				else if(PlayerInfo[playerid][E_CHARACTER_SELECTITEMS] == 2)
				{
					new rand = randomEx(3, 5);
					PlayerInfo[playerid][E_CHARACTER_SELECTITEMS] = 0;
					BusinessInfo[id][E_BUSINESS_AMOUNT] = 0;
					BusinessInfo[id][E_BUSINESS_LOADING] = false;

					Inventory_Add(playerid, "PCP", -2500, rand);
					SendServerMessage(playerid, "[Production] {cdd0d1}You've receive %d grams of PCP.", rand);
				}
			}
		}
	}
	return 1;
}

CMD:buydrugs(playerid, params[])
{
	if(!IsPlayerInRangeOfPoint(playerid, 3.0, 122.0707,-319.1785,1.5781))
		return SendErrorMessage(playerid, "You aren't near drugs labs.");

	new str[512];
	strcat(str, "Drugs\tPrice\n");
	strcat(str, "Marijuana\t$3000\n");
	strcat(str, "Cocaine\t$5000\n");
	strcat(str, "Heroin\t$5000\n");
	Dialog_Show(playerid, BuyDrugs, DIALOG_STYLE_TABLIST_HEADERS, "Drugs Labs:", str, "Select", "Close");
	return 1;
}

Dialog:BuyDrugs(playerid, response, listitem, inputtext[])
{
	if(response)
	{
		new str[512];
        switch(listitem)
        {
            case 0:
            {
				new Cents = floatround(PMARIJUANA * 100, floatround_round);
                format(str, sizeof(str), "Are you sure you want to buy this drugs for {93C47D}$%s{ffffff}?", FormatMoney(Cents)); 
                ConfirmDialog(playerid, "Confirmation", str, "OnPlayerPurchaseDrugs", 0, 25, PMARIJUANA); 
            }
            case 1:
            {
				new Cents = floatround(PCOCAINE * 100, floatround_round);
                format(str, sizeof(str), "Are you sure you want to buy this drugs for {93C47D}$%s{ffffff}?", FormatMoney(Cents)); 
                ConfirmDialog(playerid, "Confirmation", str, "OnPlayerPurchaseDrugs", 1, 20, PCOCAINE); 
            }
			case 2:
			{
				new Cents = floatround(PHEROIN * 100, floatround_round);
				format(str, sizeof(str), "Are you sure you want to buy this drugs for {93C47D}$%s{ffffff}?", FormatMoney(Cents)); 
                ConfirmDialog(playerid, "Confirmation", str, "OnPlayerPurchaseDrugs", 2, 20, PHEROIN); 
			}
		}
	}
	return 1;
}