//Function
function:OnPlayerWounded(playerid, killerid, reason)
{
	new
		str[128]
	;
	
	PlayerInfo[playerid][E_CHARACTER_DEATHFIX] = 1; 
	
	format(str, sizeof(str), "%s has been brutally wounded by %s. (%s)", ReturnSettingsName(playerid, playerid), ReturnSettingsName(killerid, killerid), ReturnWeaponName(reason)); 
	SendAdminMessageEx(COLOR_RED, 1, str); 

	if(IsPlayerInAnyVehicle(playerid))
	{
		ApplyAnimation(playerid, "ped", "CAR_dead_LHS", 4.1, 0, 0, 0, 1, 0, 1);
	}
	else
	{
		ApplyAnimation(playerid, "WUZI", "CS_Dead_Guy", 4.1, 0, 1, 1, 1, 0, 1);	
	}	
	ShowBoxMessage(playerid, "Injury", 5, 1);
	SetPlayerHealthEx(playerid, 26); 
	PlayerInfo[playerid][E_CHARACTER_INJURED] = 1;
	PlayerInfo[playerid][E_CHARACTER_COURT] = 0;
	PlayerInfo[playerid][E_CHARACTER_HAVEBALL] = 0;
    PlayerInfo[playerid][E_CHARACTER_ANIMBALL] = 0;
	PlayerInfo[playerid][E_CHARACTER_COURTTEAM] = 0;
    if(PlayerInfo[playerid][E_CHARACTER_HAVEBALL]) CourtInfo[PlayerInfo[playerid][E_CHARACTER_COURT]][E_BALLER] = 999;
	
	SetPlayerTeam(playerid, PLAYER_STATE_WOUNDED); 
	
	SendClientMessage(playerid, COLOR_RED, "[Injured]:{d7d7d7} You have been brutally wounded. If you aren't saved, you will die.");
	SendClientMessage(playerid, COLOR_RED, "[Injured]:{d7d7d7} To accept death, type: /acceptdeath."); 
	return 1;
}

function:OnPlayerDead(playerid, killerid, reason, executed)
{
	new
		str[128]
	;
	
	if(executed == 1)
	{
		format(str, sizeof(str), "%s has been executed by %s. (%s)", ReturnSettingsName(playerid, playerid), ReturnSettingsName(killerid, killerid), ReturnWeaponName(reason)); 
		SendAdminMessageEx(COLOR_RED, 1, str); 
	}
	
	ShowBoxMessage(playerid, "Wasted", 5, 1);
	SetPlayerTeam(playerid, PLAYER_STATE_DEAD); 
	PlayerInfo[playerid][E_CHARACTER_RESPAWNTIME] = gettime(); 
	PlayerInfo[playerid][E_CHARACTER_DEATH] = 1;
	PlayerInfo[playerid][E_CHARACTER_INJURED] = 0;
	PlayerInfo[playerid][E_CHARACTER_COURT] = 0;
	PlayerInfo[playerid][E_CHARACTER_HAVEBALL] = 0;
    PlayerInfo[playerid][E_CHARACTER_ANIMBALL] = 0;
	PlayerInfo[playerid][E_CHARACTER_COURTTEAM] = 0;
    if(PlayerInfo[playerid][E_CHARACTER_HAVEBALL]) CourtInfo[PlayerInfo[playerid][E_CHARACTER_COURT]][E_BALLER] = 999;
	
	SendClientMessage(playerid, COLOR_RED, "[Death]:{d7d7d7} You're now dead. You need to wait 60 seconds until you can /respawnme."); 

	if(IsPlayerInAnyVehicle(playerid))
	{
		ApplyAnimation(playerid, "ped", "CAR_dead_LHS", 4.1, 0, 0, 0, 1, 0, 1);
	}
	else
	{
		ApplyAnimation(playerid, "WUZI", "CS_Dead_Guy", 4.1, 0, 1, 1, 1, 0, 1);	
	}
	Inventory_Clear(playerid);
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

stock ShowPlayerDamages(damageid, playerid, adminView)
{
	new
		caption[33],
		str[355], 
		longstr[512]
	; 
	
	format(caption, sizeof(caption), "%s:", ReturnSettingsName(damageid, playerid));
	
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