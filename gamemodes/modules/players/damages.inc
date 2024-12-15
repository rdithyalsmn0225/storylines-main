//Function
function:OnPlayerWounded(playerid, killerid, reason)
{
	new
		str[128];
	
	PlayerInfo[playerid][E_CHARACTER_DEATHFIX] = 1; 
	
	format(str, sizeof(str), "%s has been brutally wounded by %s. (%s)", ReturnName(playerid), ReturnName(killerid, killerid), ReturnWeaponName(reason)); 
	SendAdminMessageEx(COLOR_RED, 1, str); 

	if(IsPlayerInAnyVehicle(playerid))
	{
		ApplyAnimation(playerid, "ped", "CAR_dead_LHS", 4.1, 0, 0, 0, 1, 0, 1);
	}
	else
	{
		ApplyAnimation(playerid, "WUZI", "CS_Dead_Guy", 4.1, 0, 1, 1, 1, 0, 1);	
	}

	SetPlayerTeam(playerid, PLAYER_STATE_WOUNDED); 
	PlayerInfo[playerid][E_CHARACTER_INJURED] = 1;
	PlayerInfo[playerid][E_CHARACTER_DEATH] = 0;
	PlayerInfo[playerid][E_CHARACTER_COURT] = 0;
	PlayerInfo[playerid][E_CHARACTER_HAVEBALL] = 0;
    PlayerInfo[playerid][E_CHARACTER_ANIMBALL] = 0;
	PlayerInfo[playerid][E_CHARACTER_COURTTEAM] = 0;
    if(PlayerInfo[playerid][E_CHARACTER_HAVEBALL]) Court_Refresh(PlayerInfo[playerid][E_CHARACTER_COURT]);

	new businessid = IsPlayerInBusiness(playerid);
	if(PoolInfo[businessid][E_POOL_PLAYERAIMER] == playerid)
	{
		PoolInfo[businessid][E_POOL_PLAYERAIMER] = -1;
		DestroyDynamicObject(PoolInfo[businessid][E_POOL_AIMOBJECT]);
	}
	if(PoolInfo[businessid][E_POOL_STARTED])
	{
		foreach(new i : Player)
		{
			if(PlayingPool[i])
			{
				if(PoolInfo[businessid][E_POOL_PLAYERAIMER] != i)
				{
					PlayingPool[i] = false;

					if(PoolInfo[businessid][E_POOL_PLAYER1] == i)
					{
						PoolInfo[businessid][E_POOL_PLAYER1] = -1;
					}
					if(PoolInfo[businessid][E_POOL_PLAYER2] == i)
					{
						PoolInfo[businessid][E_POOL_PLAYER2] = -1;
					}

					if(PoolInfo[businessid][E_POOL_PLAYER1] == -1 && PoolInfo[businessid][E_POOL_PLAYER1] == -1)
					{
						PoolInfo[businessid][E_POOL_STARTED] = false;
						RespawnPoolBalls(0, businessid);
					}

					PoolInfo[businessid][E_POOL_STARTED] = false;
					RestorePoolStick(i);
					HideHeaderMessage(i);
					SendServerMessage(i, "[8Ball] {cdcdcd}%s has ended pool at %s.", BusinessInfo[businessid][E_BUSINESS_NAME]);
				}
			}
		}
	}
	
	new Float:x, Float:y, Float:z;
	GetPlayerPos(playerid, x, y, z);
	if(PlayerInfo[playerid][E_CHARACTER_TAKEPACKET] == true)
	{
		PlayerInfo[playerid][E_CHARACTER_TAKEPACKET] = false;
		InsertPacket(x, y, z-1);
		foreach(new p : Player) if(PlayerInfo[p][E_CHARACTER_JOBS] == JOB_SMUGGLER)
		{
			SendClientMessage(p, COLOR_DARKGREEN, "[Word on the Streetz] Smuggler packet has been spawned '/findpacket' to track packet");
		}
	}
	
	SetPlayerPosEx(playerid, x, y, z);
	SendInfoMessage(playerid, "You have been brutally wounded. If you aren't saved, you will die.");
	SendTipMessage(playerid, "To accept death, type: /acceptdeath."); 

	RemovePlayerAttachedObject(playerid, ATTACH_HAND);
	return 1;
}

function:OnPlayerDead(playerid, killerid, reason, executed)
{
	new str[128];
	
	if(executed == 1)
	{
		format(str, sizeof(str), "%s has been executed by %s. (%s)", ReturnName(playerid), ReturnName(killerid, killerid), ReturnWeaponName(reason)); 
		SendAdminMessageEx(COLOR_RED, 1, str); 
	}

	ShowBoxMessage(playerid, "~r~Died...", 5);
	SetPlayerTeam(playerid, PLAYER_STATE_DEAD); 

	PlayerInfo[playerid][E_CHARACTER_RESPAWNTIME] = gettime(); 
	PlayerInfo[playerid][E_CHARACTER_DEATH] = 1;
	PlayerInfo[playerid][E_CHARACTER_INJURED] = 0;
	PlayerInfo[playerid][E_CHARACTER_COURT] = 0;
	PlayerInfo[playerid][E_CHARACTER_HAVEBALL] = 0;
    PlayerInfo[playerid][E_CHARACTER_ANIMBALL] = 0;
	PlayerInfo[playerid][E_CHARACTER_COURTTEAM] = 0;
    if(PlayerInfo[playerid][E_CHARACTER_HAVEBALL]) Court_Refresh(PlayerInfo[playerid][E_CHARACTER_COURT]);

	new businessid = IsPlayerInBusiness(playerid);
	if(PoolInfo[businessid][E_POOL_PLAYERAIMER] == playerid)
	{
		PoolInfo[businessid][E_POOL_PLAYERAIMER] = -1;
		DestroyDynamicObject(PoolInfo[businessid][E_POOL_AIMOBJECT]);
	}
	if(PoolInfo[businessid][E_POOL_STARTED])
	{
		foreach(new i : Player)
		{
			if(PlayingPool[i])
			{
				if(PoolInfo[businessid][E_POOL_PLAYERAIMER] != i)
				{
					PlayingPool[i] = false;

					if(PoolInfo[businessid][E_POOL_PLAYER1] == i)
					{
						PoolInfo[businessid][E_POOL_PLAYER1] = -1;
					}
					if(PoolInfo[businessid][E_POOL_PLAYER2] == i)
					{
						PoolInfo[businessid][E_POOL_PLAYER2] = -1;
					}

					if(PoolInfo[businessid][E_POOL_PLAYER1] == -1 && PoolInfo[businessid][E_POOL_PLAYER1] == -1)
					{
						PoolInfo[businessid][E_POOL_STARTED] = false;
						RespawnPoolBalls(0, businessid);
					}

					PoolInfo[businessid][E_POOL_STARTED] = false;
					RestorePoolStick(i);
					HideHeaderMessage(i);
					SendServerMessage(i, "[8Ball] {cdcdcd}%s has ended pool at %s.", BusinessInfo[businessid][E_BUSINESS_NAME]);
				}
			}
		}
	}
	
	SendTipMessage(playerid, "You're now dead. You need to wait 60 seconds until you can /respawnme."); 

	if(IsPlayerInAnyVehicle(playerid))
	{
		ApplyAnimation(playerid, "ped", "CAR_dead_LHS", 4.1, 0, 0, 0, 1, 0, 1);
	}
	else
	{
		ApplyAnimation(playerid, "WUZI", "CS_Dead_Guy", 4.1, 0, 1, 1, 1, 0, 1);	
	}
	Inventory_Clear(playerid);

	new Float:x, Float:y, Float:z;
	GetPlayerPos(playerid, x, y, z);
	if(PlayerInfo[playerid][E_CHARACTER_TAKEPACKET] == true)
	{
		PlayerInfo[playerid][E_CHARACTER_TAKEPACKET] = false;
		InsertPacket(x, y, z-1);
		foreach(new p : Player) if(PlayerInfo[p][E_CHARACTER_JOBS] == JOB_SMUGGLER)
		{
			SendClientMessage(p, COLOR_DARKGREEN, "[Word on the Streetz] Smuggler packet has been spawned '/findpacket' to track packet");
		}
	}
	SetPlayerPosEx(playerid, x, y, z);
	RemovePlayerAttachedObject(playerid, ATTACH_HAND);
	ResetPlayerWeaponEx(playerid);
	return 1;
}

stock ReturnBodypartName(bodypart)
{
	new bodyname[20];
	
	switch(bodypart)
	{
		case BODY_PART_CHEST:bodyname = "CHEST";
		case BODY_PART_GROIN:bodyname = "GROIN";
		case BODY_PART_LEFT_ARM:bodyname = "LEFT ARM";
		case BODY_PART_RIGHT_ARM:bodyname = "RIGHT ARM";
		case BODY_PART_LEFT_LEG:bodyname = "LEFT LEG";
		case BODY_PART_RIGHT_LEG:bodyname = "RIGHT LEG";
		case BODY_PART_HEAD:bodyname = "HEAD";
	}
	
	return bodyname;
}

stock CallbackDamages(playerid, issuerid, bodypart, weaponid, Float:amount)
{
	new
		id,
		Float:armor
	;
	
	TotalPlayerDamages[playerid] ++; 
	
	for(new i = 0; i < 100; i++)
	{
		if(!DamageInfo[playerid][i][E_DAMAGE_TAKEN])
		{
			id = i;
			break;
		}
	}
	
	GetPlayerArmour(playerid, armor);
	
	if(armor > 1 && bodypart == BODY_PART_CHEST)
		DamageInfo[playerid][id][E_DAMAGE_ARMOR] = 1;
		
	else DamageInfo[playerid][id][E_DAMAGE_ARMOR] = 0;
	
	DamageInfo[playerid][id][E_DAMAGE_TAKEN] = floatround(amount, floatround_round); 
	DamageInfo[playerid][id][E_DAMAGE_WEAPON] = weaponid;
	
	DamageInfo[playerid][id][E_DAMAGE_BODYPART] = bodypart; 
	DamageInfo[playerid][id][E_DAMAGE_TIME] = gettime();
	
	DamageInfo[playerid][id][E_DAMAGE_BY] = PlayerInfo[issuerid][E_CHARACTER_DBID]; 
	return 1; 
}

stock GetWoundStatus(condition)
{
	new str[64];
	if (condition == WOUND_TYPE_BROKEN) str = "{FF6347}Broken";
	else if (condition == WOUND_TYPE_BURN) str = "{FF6347}Broken";
	else if (condition == WOUND_TYPE_BLEED) str = "{DAA650}Bullet";
	else if (condition == WOUND_TYPE_BLEED) str = "{DAA650}Bleedin";
    else if (condition == WOUND_TYPE_NONE) str = "{33AA33}Normal";
    return str;
}

function:OnPlayerConditionUpdate()
{
	foreach(new i : Player)
	{
		if(PlayerInfo[i][E_CHARACTER_BODYPART][0] <= 0)
		{
			PlayerInfo[i][E_CHARACTER_BODYPART][0] = 0;
		}
		if(PlayerInfo[i][E_CHARACTER_BODYPART][1] <= 0)
		{
			PlayerInfo[i][E_CHARACTER_BODYPART][1] = 0;
		}
		if(PlayerInfo[i][E_CHARACTER_BODYPART][2] <= 0)
		{
			PlayerInfo[i][E_CHARACTER_BODYPART][2] = 0;
		}
		if(PlayerInfo[i][E_CHARACTER_BODYPART][3] <= 0)
		{
			PlayerInfo[i][E_CHARACTER_BODYPART][3] = 0;
		}
		if(PlayerInfo[i][E_CHARACTER_BODYPART][4] <= 0)
		{
			PlayerInfo[i][E_CHARACTER_BODYPART][5] = 0;
		}
		if(PlayerInfo[i][E_CHARACTER_BODYPART][6] <= 0)
		{
			PlayerInfo[i][E_CHARACTER_BODYPART][6] = 0;
		}
		if(PlayerInfo[i][E_CHARACTER_BODYPART][7] <= 0)
		{
			PlayerInfo[i][E_CHARACTER_BODYPART][7] = 0;
		}

		if(PlayerInfo[i][E_CHARACTER_BODYPART][7] <= 50)
		{
			SetPlayerDrunkLevel(i, 4000);
		}

		if(PlayerInfo[i][E_CHARACTER_BODYPART][7] >= 50)
		{
			SetPlayerDrunkLevel(i, 0);
		}

		if(PlayerInfo[i][E_CHARACTER_BODYPART][0] >= 100)
		{
			PlayerInfo[i][E_CHARACTER_BODYPART][0] = 100;
		}
		if(PlayerInfo[i][E_CHARACTER_BODYPART][1] >= 100)
		{
			PlayerInfo[i][E_CHARACTER_BODYPART][1] = 100;
		}
		if(PlayerInfo[i][E_CHARACTER_BODYPART][2] >= 100)
		{
			PlayerInfo[i][E_CHARACTER_BODYPART][2] = 100;
		}
		if(PlayerInfo[i][E_CHARACTER_BODYPART][3] >= 100)
		{
			PlayerInfo[i][E_CHARACTER_BODYPART][3] = 100;
		}
		if(PlayerInfo[i][E_CHARACTER_BODYPART][4] >= 100)
		{
			PlayerInfo[i][E_CHARACTER_BODYPART][5] = 100;
		}
		if(PlayerInfo[i][E_CHARACTER_BODYPART][6] >= 100)
		{
			PlayerInfo[i][E_CHARACTER_BODYPART][6] = 100;
		}
		if(PlayerInfo[i][E_CHARACTER_BODYPART][7] >= 100)
		{
			PlayerInfo[i][E_CHARACTER_BODYPART][7] = 100;
		}
	}
	return 1;
}

stock ShowPlayerCondition(playerid, targetid)
{
	new str[1024], str2[64];

	
	format(str2, sizeof(str2), "%s Condition", ReturnName(targetid, 0));

	format(str, sizeof(str), "{33AA33}|__________ Body Condition Status __________|\n");
	format(str, sizeof(str), "%s{ffffff}Part : {DAA650}Chest | {ffffff}Rating : {DAA650}%d\n", str, PlayerInfo[targetid][E_CHARACTER_BODYPART][0]);
	format(str, sizeof(str), "%s{ffffff}Part : {DAA650}Torso | {ffffff}Rating : {DAA650}%d\n", str, PlayerInfo[targetid][E_CHARACTER_BODYPART][1]);
	format(str, sizeof(str), "%s{ffffff}Part : {DAA650}Groin | {ffffff}Rating : {DAA650}%d\n", str, PlayerInfo[targetid][E_CHARACTER_BODYPART][2]);
	format(str, sizeof(str), "%s{ffffff}Part : {DAA650}Right Arm | {ffffff}Rating : {DAA650}%d\n", str, PlayerInfo[targetid][E_CHARACTER_BODYPART][3]);
	format(str, sizeof(str), "%s{ffffff}Part : {DAA650}Left Arm | {ffffff}Rating : {DAA650}%d\n", str, PlayerInfo[targetid][E_CHARACTER_BODYPART][4]);
	format(str, sizeof(str), "%s{ffffff}Part : {DAA650}Right Leg | {ffffff}Rating : {DAA650}%d\n", str, PlayerInfo[targetid][E_CHARACTER_BODYPART][5]);
	format(str, sizeof(str), "%s{ffffff}Part : {DAA650}Left Leg | {ffffff}Rating : {DAA650}%d\n", str, PlayerInfo[targetid][E_CHARACTER_BODYPART][6]);
	format(str, sizeof(str), "%s{ffffff}Part : {DAA650}Head | {ffffff}Rating : {DAA650}%d\n", str, PlayerInfo[targetid][E_CHARACTER_BODYPART][7]);

	format(str, sizeof(str), "%s{33AA33}|__________ Body Wound Status __________|\n", str);
	format(str, sizeof(str), "%s{ffffff}Part : Chest - %s\n", str,  GetWoundStatus(PlayerInfo[targetid][E_CHARACTER_WOUND][0]));
	format(str, sizeof(str), "%s{ffffff}Part : Torso - %s\n", str,  GetWoundStatus(PlayerInfo[targetid][E_CHARACTER_WOUND][0]));
	format(str, sizeof(str), "%s{ffffff}Part : Groin - %s\n", str,  GetWoundStatus(PlayerInfo[targetid][E_CHARACTER_WOUND][0]));
	format(str, sizeof(str), "%s{ffffff}Part : Right Arm - %s\n", str,  GetWoundStatus(PlayerInfo[targetid][E_CHARACTER_WOUND][0]));
	format(str, sizeof(str), "%s{ffffff}Part : Left Arm - %s\n", str,  GetWoundStatus(PlayerInfo[targetid][E_CHARACTER_WOUND][0]));
	format(str, sizeof(str), "%s{ffffff}Part : Right Leg - %s\n", str,  GetWoundStatus(PlayerInfo[targetid][E_CHARACTER_WOUND][0]));
	format(str, sizeof(str), "%s{ffffff}Part : Left Leg - %s\n", str,  GetWoundStatus(PlayerInfo[targetid][E_CHARACTER_WOUND][0]));
	format(str, sizeof(str), "%s{ffffff}Part : Head - %s\n", str,  GetWoundStatus(PlayerInfo[targetid][E_CHARACTER_WOUND][0]));

	ShowPlayerDialog(playerid, DIALOG_DEFAULT, DIALOG_STYLE_MSGBOX, str2, str, "Close", "");
	return 1;
}

stock ShowPlayerDamages(damageid, playerid, adminView)
{
	new
		caption[33],
		str[128], 
		longstr[128]
	; 
	
	format(caption, sizeof(caption), "%s:", ReturnName(damageid, playerid));
	
	if (TotalPlayerDamages[damageid] < 1)
		return ShowPlayerDialog(playerid, DIALOG_DEFAULT, DIALOG_STYLE_LIST, caption, "There aren't any damages to show.", "<<", ""); 

	switch(adminView)
	{
		case 0:
		{
			for(new i = 0; i < 100; i ++)
			{
				if(!DamageInfo[damageid][i][E_DAMAGE_TAKEN])
					continue;
					
				format(str, sizeof(str), "%d dmg from %s to %s (Kevlarhit: %d) %d s ago\n", DamageInfo[damageid][i][E_DAMAGE_TAKEN], ReturnWeaponName(DamageInfo[damageid][i][E_DAMAGE_WEAPON]), ReturnBodypartName(DamageInfo[damageid][i][E_DAMAGE_BODYPART]), DamageInfo[damageid][i][E_DAMAGE_ARMOR], gettime() - DamageInfo[damageid][i][E_DAMAGE_TIME]); 
				strcat(longstr, str); 
			}
			
			ShowPlayerDialog(playerid, DIALOG_DEFAULT, DIALOG_STYLE_LIST, caption, longstr, "<<", ""); 
		}
		case 1:
		{
			for(new i = 0; i < 100; i ++)
			{
				if(!DamageInfo[damageid][i][E_DAMAGE_TAKEN])
					continue;
					
				format(str, sizeof(str), "{FF6346}(%s){FFFFFF} %d dmg from %s to %s (Kevlarhit: %d) %d s ago\n", ReturnDBIDName(DamageInfo[damageid][i][E_DAMAGE_BY]), DamageInfo[damageid][i][E_DAMAGE_TAKEN], ReturnWeaponName(DamageInfo[damageid][i][E_DAMAGE_WEAPON]), ReturnBodypartName(DamageInfo[damageid][i][E_DAMAGE_BODYPART]), DamageInfo[damageid][i][E_DAMAGE_ARMOR], gettime() - DamageInfo[damageid][i][E_DAMAGE_TIME]); 
				strcat(longstr, str); 
			}
			
			ShowPlayerDialog(playerid, DIALOG_DEFAULT, DIALOG_STYLE_LIST, caption, longstr, "<<", ""); 
		}
	}
	return 1;
}

stock ClearDamages(playerid)
{
	for(new i = 0; i < 100; i++)
	{
		DamageInfo[playerid][i][E_DAMAGE_TAKEN] = 0;
		DamageInfo[playerid][i][E_DAMAGE_BY] = 0; 
		
		DamageInfo[playerid][i][E_DAMAGE_ARMOR] = 0;
		DamageInfo[playerid][i][E_DAMAGE_BODYPART] = 0;
		
		DamageInfo[playerid][i][E_DAMAGE_TIME] = 0;
		DamageInfo[playerid][i][E_DAMAGE_WEAPON] = 0; 
	}
	
	return 1;
}

CMD:damages(playerid, params[])
{
	new playerb;
	
	if(sscanf(params, "u", playerb))
		return SendUsageMessage(playerid, "/damages [playerid OR name]");
		
	if(!IsPlayerConnected(playerb))	
		return SendErrorMessage(playerid, "The player you specified isn't connected.");
		
	if(AccountInfo[playerb][E_MASTERS_LOGGED] == false)
		return SendErrorMessage(playerid, "The player you specified isn't logged in.");
		
	if(PlayerInfo[playerid][E_CHARACTER_ADMINDUTY])
	{
		ShowPlayerDamages(playerb, playerid, 1); 
	}
	else
	{
		if(!IsPlayerNearPlayer(playerid, playerb, 5.0))
			return SendErrorMessage(playerid, "You aren't near that player.");
		
		if(GetPlayerTeam(playerb) == PLAYER_STATE_ALIVE)
			return SendErrorMessage(playerid, "That player isn't brutally wounded.");
			
		ShowPlayerDamages(playerb, playerid, 0); 
	}
	return 1;
}

CMD:health(playerid, params[])
{
	new playerb;

	if(IsPlayerAdmins(playerid))
	{
		if (sscanf(params, "I(-1)", playerb))
			return 1; 
			
		if(playerb == -1)
		{
			return ShowPlayerCondition(playerid, playerid);
		}
		else
		{
			if(!IsPlayerConnected(playerb))
				return SendErrorMessage(playerid, "The player you specified isn't connected.");
				
			if(AccountInfo[playerid][E_MASTERS_LOGGED] == false)
				return SendErrorMessage(playerid, "The player you specified isn't logged in."); 
				
			ShowPlayerCondition(playerid, playerb);
		}
	}
	else return ShowPlayerCondition(playerid, playerid);
	return 1;
}
