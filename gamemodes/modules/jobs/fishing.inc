
IsPlayerInWater(playerid)
{
	new Float:x,Float:y,Float:pz;
	GetPlayerPos(playerid,x,y,pz);
	if (
 	(IsPlayerInArea(playerid, 2032.1371, 1841.2656, 1703.1653, 1467.1099) && pz <= 9.0484) //lv piratenschiff
  	|| (IsPlayerInArea(playerid, 2109.0725, 2065.8232, 1962.5355, 10.8547) && pz <= 10.0792) //lv visage
  	|| (IsPlayerInArea(playerid, -492.5810, -1424.7122, 2836.8284, 2001.8235) && pz <= 41.06) //lv staucamm
  	|| (IsPlayerInArea(playerid, -2675.1492, -2762.1792, -413.3973, -514.3894) && pz <= 4.24) //sf südwesten kleiner teich
  	|| (IsPlayerInArea(playerid, -453.9256, -825.7167, -1869.9600, -2072.8215) && pz <= 5.72) //sf gammel teich
  	|| (IsPlayerInArea(playerid, 1281.0251, 1202.2368, -2346.7451, -2414.4492) && pz <= 9.3145) //ls neben dem airport
  	|| (IsPlayerInArea(playerid, 2012.6154, 1928.9028, -1178.6207, -1221.4043) && pz <= 18.45) //ls mitte teich
  	|| (IsPlayerInArea(playerid, 2326.4858, 2295.7471, -1400.2797, -1431.1266) && pz <= 22.615) //ls weiter südöstlich
  	|| (IsPlayerInArea(playerid, 2550.0454, 2513.7588, 1583.3751, 1553.0753) && pz <= 9.4171) //lv pool östlich
  	|| (IsPlayerInArea(playerid, 1102.3634, 1087.3705, -663.1653, -682.5446) && pz <= 112.45) //ls pool nordwestlich
  	|| (IsPlayerInArea(playerid, 1287.7906, 1270.4369, -801.3882, -810.0527) && pz <= 87.123) //pool bei maddog's haus oben
  	|| (pz < 1.5)
	)
	{
		return 1;
	}
	return 0;
}

IsPlayerInArea(playerid, Float:minx, Float:maxx, Float:miny, Float:maxy)
{
	new Float:x, Float:y, Float:z;
	GetPlayerPos(playerid, x, y, z);
	if (x > minx && x < maxx && y > miny && y < maxy) return 1;
	return 0;
}

IsAtFishPlace(playerid)
{
	if(IsPlayerConnected(playerid))
	{
	    if(IsPlayerInRangeOfPoint(playerid,1.0,403.8266,-2088.7598,7.8359) || IsPlayerInRangeOfPoint(playerid,1.0,398.7553,-2088.7490,7.8359))
		{
		    return 1;
		}
		else if(IsPlayerInRangeOfPoint(playerid,1.0,396.2197,-2088.6692,7.8359) || IsPlayerInRangeOfPoint(playerid,1.0,391.1094,-2088.7976,7.8359))
		{
		    return 1;
		}
		else if(IsPlayerInRangeOfPoint(playerid,1.0,383.4157,-2088.7849,7.8359) || IsPlayerInRangeOfPoint(playerid,1.0,374.9598,-2088.7979,7.8359))
		{
		    return 1;
		}
		else if(IsPlayerInRangeOfPoint(playerid,1.0,369.8107,-2088.7927,7.8359) || IsPlayerInRangeOfPoint(playerid,1.0,367.3637,-2088.7925,7.8359))
		{
		    return 1;
		}
		else if(IsPlayerInRangeOfPoint(playerid,1.0,362.2244,-2088.7981,7.8359) || IsPlayerInRangeOfPoint(playerid,1.0,354.5382,-2088.7979,7.8359))
		{
		    return 1;
		}
		else if(IsPlayerInWater(playerid))
		{
			return 1;
		}
	}
	return 0;
}

function:FishingTimer(playerid, type)
{
	if(PlayerInfo[playerid][E_CHARACTER_FISHING] == true)
	{
		switch(type)
		{
			case 1:
			{
				PlayerInfo[playerid][E_CHARACTER_FISHINGVALUE] = 10.0;
				PlayerInfo[playerid][E_CHARACTER_FISHINGSTART] = true;
				ShowGameBar(playerid, PlayerInfo[playerid][E_CHARACTER_FISHINGVALUE], "Fishing");
				ShowHeaderMessage(playerid, "Fishing", "Something is hooked in your line.\nPress SPACE to reel it in.");
				PlayerInfo[playerid][E_CHARACTER_FISHINGTIMER] = SetTimerEx("FishingTimer", 500, true, "ii", playerid, 2);
			}
			case 2:
			{
				PlayerInfo[playerid][E_CHARACTER_FISHINGVALUE] -= 10.0;
				SetPlayerGameBar(playerid, PlayerInfo[playerid][E_CHARACTER_FISHINGVALUE]);

				if(PlayerInfo[playerid][E_CHARACTER_FISHINGVALUE] < 0)
				{
					PlayerInfo[playerid][E_CHARACTER_FISHINGSTART] = false;
					PlayerInfo[playerid][E_CHARACTER_FISHINGVALUE] = 0;
					PlayerInfo[playerid][E_CHARACTER_FISHING] = false;

					DestroyGameBar(playerid);
					KillTimer(PlayerInfo[playerid][E_CHARACTER_FISHINGTIMER]);
					
					ClearAnimations(playerid);
					TogglePlayerControllable(playerid, true);
					ApplyAnimation(playerid, "CARRY", "crry_prtial", 4.0, 0, 0, 0, 0, 0, 1);
					SendServerMessage(playerid, "FISHING: {ffffff}You fish swarm away in your hook.");
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
	
	format(str, sizeof(str), "You have %d fish in your inventory are you sure you want to sell it for $%s", Inventory_Count(playerid, "Fish"), FormatMoney(FISHING_SALARY * Inventory_Count(playerid, "Fish")));
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
	SendServerMessage(playerid, "FISHING: {ffffff}You have successfully purchase %d Fish bait for $%s", amount, FormatMoney(amount));
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

	if(!IsAtFishPlace(playerid))
		return SendErrorMessage(playerid, "You are not in any Fishing Area's.");

	if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT)
		return SendErrorMessage(playerid, "You must be onfoot!");

	PlayerInfo[playerid][E_CHARACTER_FISHING] = true;
	
	Inventory_Remove(playerid, "Fish Bait", 1);
	SetTimerEx("FishingTimer", 15000, false, "ii", playerid, 1);
	TogglePlayerControllable(playerid, false);
	ApplyAnimation(playerid,"SWORD","sword_block",50.0 ,0,1,0,1,1);
	SendServerMessage(playerid, "FISHING: {ffffff}You start fishing, please wait for the moment...");
	return 1;
}