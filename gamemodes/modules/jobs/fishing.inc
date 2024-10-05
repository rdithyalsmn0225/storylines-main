
stock ReturnFishArea(playerid)
{
	forex(i, 6) if(IsPlayerInDynamicArea(playerid, AreaInfo[E_AREA_FISHBIG][i]))
		return FISH_BIG;

	forex(i, 6) if(IsPlayerInDynamicArea(playerid, AreaInfo[E_AREA_FISHSMALL][i]))
		return FISH_SMALL;

	return FISH_NONE;
}

function:FishingTimer(playerid, type)
{
	if(PlayerInfo[playerid][E_CHARACTER_FISHING] == true)
	{
		switch(type)
		{
			case 1:
			{
				PlayerInfo[playerid][E_CHARACTER_FISHINGVALUE] = 10;
				PlayerInfo[playerid][E_CHARACTER_FISHINGSTART] = true;
				ShowGameBar(playerid, PlayerInfo[playerid][E_CHARACTER_FISHINGVALUE], "Fishing");
				ShowHeaderMessage(playerid, "Fishing", "Something is hooked in your line.\nPress SPACE to reel it in.");
				PlayerInfo[playerid][E_CHARACTER_FISHINGTIMER] = SetTimerEx("FishingTimer", 1000, true, "ii", playerid, 2);
			}
			case 2:
			{
				PlayerInfo[playerid][E_CHARACTER_FISHINGVALUE] -= 10;
				SetPlayerGameBar(playerid, GameBar[1][playerid], PlayerInfo[playerid][E_CHARACTER_FISHINGVALUE], GAMEBAR_MINUS);
				if(PlayerInfo[playerid][E_CHARACTER_FISHINGVALUE] < 0)
				{
					PlayerInfo[playerid][E_CHARACTER_FISHINGSTART] = false;
					PlayerInfo[playerid][E_CHARACTER_FISHINGVALUE] = 0;
					KillTimer(PlayerInfo[playerid][E_CHARACTER_FISHINGTIMER]);
					PlayerInfo[playerid][E_CHARACTER_FISHING] = false;
					DestroyGameBar(playerid);
					ClearAnimations(playerid);
					TogglePlayerControllable(playerid, true);
					ApplyAnimation(playerid, "CARRY", "crry_prtial", 4.0, 0, 0, 0, 0, 0, 1);
					SendClientMessageEx(playerid, COLOR_FISHING, "[Fishing]:{d7d7d7} You fish swarm away in your hook.");
				}
			}
		}
	}
	return 1;
}

CMD:sellfish(playerid, params[])
{
	if(!IsPlayerInRangeOfPoint(playerid, 3.0, 2895.6743,-2135.5847,3.6525))
	    return SendErrorMessage(playerid, "You are not inside Fish Factory!");

 	if(!Inventory_Count(playerid, "Fish"))
		return SendErrorMessage(playerid, "You don't have any fish!");
		
	new str[356];
	
	format(str, sizeof(str), "You have %d fish in your inventory are you sure you want to sell it for $%s", Inventory_Count(playerid, "Fish"), FormatMoney(5 * Inventory_Count(playerid, "Fish")));
	ShowPlayerDialog(playerid, DIALOG_SELLFISH, DIALOG_STYLE_MSGBOX, "Sell Fish:", str, "Sell", "Cancel");
	return 1;
}

CMD:buybait(playerid, params[])
{
	if(!IsPlayerInRangeOfPoint(playerid, 3.0, 2900.7317,-2099.5378,2.8997))
		return SendErrorMessage(playerid, "You aren't inside the Fish factory.");

	new amount;
	if(sscanf(params, "d", amount))
		return SendUsageMessage(playerid, "/buybait [amount] | $1/Bait");

	if(amount < 1 || amount < 0)
		return SendErrorMessage(playerid, "Invalid amount specified!");

	if(amount > PlayerInfo[playerid][E_CHARACTER_MONEY])
		return SendErrorMessage(playerid, "You don't have enough money! ($%s)", FormatMoney(amount));

	if(amount > 100)
		return SendErrorMessage(playerid, "Invalid bait amount!");
	
	Inventory_Add(playerid, "Fish Bait", 19566, amount);
	SendClientMessageEx(playerid, COLOR_FISHING, "[Fishing]:{d7d7d7} You have successfully purchase %d Fish bait for $%s", amount, FormatMoney(amount));
	GiveMoney(playerid, -amount);
	return 1;
}

CMD:fish(playerid, params[])
{	    
	if(PlayerInfo[playerid][E_CHARACTER_EQUIPITEMS] != FISHING_ROD)
		return SendErrorMessage(playerid, "You must hold the fishing rod in your hands.");

	if(Inventory_Count(playerid, "Fish Bait") < 1)
	    return SendErrorMessage(playerid, "You don't have fish bait");

	if(Inventory_Count(playerid, "Fishing rod") < 1)
	    return SendErrorMessage(playerid, "You don't have fishing rod");
	    
	if(PlayerInfo[playerid][E_CHARACTER_FISHING])
	    return SendErrorMessage(playerid, "You're currently in fishing activity.");
	    
 	if(Inventory_Count(playerid, "Fish") > 20)
		return SendErrorMessage(playerid, "You cannot bring more fish.");

	if(ReturnFishArea(playerid) == FISH_NONE)
		return SendErrorMessage(playerid, "You are not in any Fishing Area's.");

	if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT)
		return SendErrorMessage(playerid, "You must be onfoot!");

	PlayerInfo[playerid][E_CHARACTER_FISHING] = true;
	ApplyAnimation(playerid,"SWORD","sword_block", 4.1, 0, 1, 0, 1, 1);
	Inventory_Remove(playerid, "Fish Bait", 1);
	SetTimerEx("FishingTimer", 15000, false, "ii", playerid, 1);
	TogglePlayerControllable(playerid, false);
	SendClientMessageEx(playerid, COLOR_FISHING, "[Fishing]:{d7d7d7} You start fishing, please wait for the moment.");
	return 1;
}