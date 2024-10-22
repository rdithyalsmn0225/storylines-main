//General commands:

CMD:credits(playerid, params[])
{
	SendClientMessage(playerid, COLOR_DARKGREEN, "[Development Help]:");
	SendClientMessage(playerid, COLOR_CREDITS, "PatrickGTR:{ffffff} Open sourcing their actor robbery script.");
	SendClientMessage(playerid, COLOR_CREDITS, "GTA-C:{ffffff} Open sourcing / leaked their environment.");
	SendClientMessage(playerid, COLOR_CREDITS, "Radeetz:{ffffff} Development & Script gamemods for IDLS.");
	SendClientMessage(playerid, COLOR_CREDITS, "Crashout:{ffffff} Helping Radeetz with ideas / troubleshoting and management.");
	SendClientMessage(playerid, COLOR_CREDITS, "Arielnatanael:{ffffff} Helping Radeetz with ideas / troubleshoting and management.");
	SendClientMessage(playerid, COLOR_DARKGREEN, "[Server Management]:");
	SendClientMessage(playerid, COLOR_CREDITS, "Marv:{ffffff} Helping with reassembling the community & pre-launch server.");
	SendClientMessage(playerid, COLOR_CREDITS, "Boris:{ffffff} Helping with reassembling the community management.");
	SendClientMessage(playerid, COLOR_CREDITS, "Nhces:{ffffff} Helping with reassembling the community management.");
	SendClientMessage(playerid, COLOR_DARKGREEN, "[Conclussion]:");
	SendClientMessage(playerid, COLOR_CREDITS, "The Community:{ffffff} for making this server possible and sticking by the staff team through sweat and frustation.");
	return 1;
}
CMD:help(playerid, params[])
{
	new str[256];
	format(str, sizeof(str), "General Commands\nRoleplay Commands\nProperty Commands\nBusiness Commands\nFaction Commands\nVehicle Commands\nMinigames Commands\nJobs Commands\nCrime Professions Commands");
	ShowPlayerDialog(playerid, DIALOG_HELP, DIALOG_STYLE_LIST, "Commands:", str, "Select", "Close");
	return 1; 
}

CMD:cursor(playerid, params[])
{
	if(isnull(params))
		return SendUsageMessage(playerid, "/cursor [show/hide]");

	if(!strcmp(params, "show", true))
	{
		SelectTextDraw(playerid, COLOR_YELLOW);
	}
	else if(!strcmp(params, "hide", true))
	{
		CancelSelectTextDraw(playerid);
	}
	return 1;
}

CMD:settings(playerid, params[])
{
	new str[512];
	format(str, sizeof(str), "Streets TextDraws\t%s\n", (PlayerInfo[playerid][E_CHARACTER_TOGHUD] == false) ? ("{5B9460}ENABLE{ffffff}") : ("{FF6347}DISABLE{ffffff}"));
	format(str, sizeof(str), "%sJoined Logs\t%s\n", str, (PlayerInfo[playerid][E_CHARACTER_TOGJOIN] == false) ? ("{5B9460}ENABLE{ffffff}") : ("{FF6347}DISABLE{ffffff}"));
	format(str, sizeof(str), "%sAdmin Messages\t%s\n", str, (PlayerInfo[playerid][E_CHARACTER_TOGADMIN] == false) ? ("{5B9460}ENABLE{ffffff}") : ("{FF6347}DISABLE{ffffff}"));
	format(str, sizeof(str), "%sFaction Messages\t%s\n", str, (PlayerInfo[playerid][E_CHARACTER_TOGFMS] == false) ? ("{5B9460}ENABLE{ffffff}") : ("{FF6347}DISABLE{ffffff}"));
	format(str, sizeof(str), "%sPrivate Messages\t%s\n", str, (PlayerInfo[playerid][E_CHARACTER_TOGPMS] == false) ? ("{5B9460}ENABLE{ffffff}") : ("{FF6347}DISABLE{ffffff}"));
	format(str, sizeof(str), "%sDamages Messages\t%s\n", str, (PlayerInfo[playerid][E_CHARACTER_TOGDMS] == false) ? ("{5B9460}ENABLE{ffffff}") : ("{FF6347}DISABLE{ffffff}"));
	format(str, sizeof(str), "%sSwitch Namestyles\t%s\n", str, (PlayerInfo[playerid][E_CHARACTER_TOGNAMESTYLE]) ? ("{5B9460}Fn_Ln{ffffff}") : ("{FF6347}Mixed.Name{ffffff}"));
	format(str, sizeof(str), "%sDraw Distance\t%s\n", str, (PlayerInfo[playerid][E_CHARACTER_TOGDD] == false) ? ("{5B9460}LOW{ffffff}") : ("{FF6347}HIGH{ffffff}"));
	ShowPlayerDialog(playerid, DIALOG_SETTINGS, DIALOG_STYLE_TABLIST, "Settings:", str, "Select", "Close");
	return 1;
}

CMD:coin(playerid, params[])
{
    SendNearbyMessage(playerid, 20.0, COLOR_EMOTE, "* %s flips a coin and it lands on %s.", ReturnSettingsName(playerid, playerid), (random(2)) ? ("Heads") : ("Tails"));
	return true;
}

CMD:dice(playerid, params[])
{
	SendNearbyMessage(playerid, 20.0, COLOR_EMOTE, "* %s rolls a dice and it lands on %d.", ReturnSettingsName(playerid, playerid), random(6) + 1);
    return true;
}

CMD:fix(playerid, params[])
{
	if(PlayerInfo[playerid][E_CHARACTER_TOGMENU] == false)
	{
		TogglePlayerControllable(playerid, true);
	}
	return 1;
}

CMD:hesoyam(playerid, params[])
{
	ShowBoxMessage(playerid, "Cheat Activated", 5);
	SendServerMessage(playerid, "CHEAT: {ffffff}You've given $150,000 from Rockstar West!");
	return 1;
}

CMD:stats(playerid, params[])
{
	new playerb;
	
	if(IsPlayerAdmins(playerid))
	{
		if (sscanf(params, "I(-1)", playerb))
			return 1; 
			
		if(playerb == -1)
		{
			return ShowCharacterStats(playerid, playerid);
		}
		else
		{
			if(!IsPlayerConnected(playerb))
				return SendErrorMessage(playerid, "The player you specified isn't connected.");
				
			if(AccountInfo[playerid][E_MASTERS_LOGGED] == false)
				return SendErrorMessage(playerid, "The player you specified isn't logged in."); 
				
			ShowCharacterStats(playerb, playerid); 
		}
	}
	else return ShowCharacterStats(playerid, playerid);
	return 1;
}

CMD:inventory(playerid, params[])
{
	PlayerInfo[playerid][E_CHARACTER_STORAGESELECT] = 0;
	OpenInventory(playerid);
	return 1;
}

CMD:admins(playerid, params[])
{
	new bool:adminOn = false;
	
	foreach (new i : Player)
	{
		if (PlayerInfo[playerid][E_CHARACTER_ADMIN]) adminOn = true;
	}
	
	if(adminOn == true)
	{
		SendClientMessage(playerid, COLOR_HEADER, "Admins List:");
		foreach(new i : Player)
		{
			if(PlayerInfo[i][E_CHARACTER_ADMIN])
			{
				if(PlayerInfo[i][E_CHARACTER_ADMINDUTY])
				{
					SendClientMessageEx(playerid, COLOR_WHITE, "(Level: %d) %s (%s) - On Duty: Yes", PlayerInfo[i][E_CHARACTER_ADMIN], ReturnSettingsName(i, i), AccountInfo[i][E_MASTERS_FORUMNAME]);
				}
				else SendClientMessageEx(playerid, COLOR_GREY, "(Level: %d) %s (%s) - On Duty: No", PlayerInfo[i][E_CHARACTER_ADMIN], ReturnSettingsName(i, i), AccountInfo[i][E_MASTERS_FORUMNAME]);
			}
		}
	}
	else
	{
		return SendClientMessage(playerid, COLOR_GREY, "There are no administrators' online.");
	}

	return 1;
}

CMD:re(playerid, params[])return cmd_report(playerid, params);
CMD:report(playerid, params[])
{
	if(isnull(params) || strlen(params) < 3)
		return SendUsageMessage(playerid, "/re(port) [text]"); 
	
	new 
		showString[350]
	;
	
	format(showString, sizeof(showString), "{FFFFFF}Are you sure you want to send this report?\n\n{F81414}Remember that, reporting actions which do not happen at the moment is extremely difficult for online admins to handle on the spot, since no proof is presented to them.\n{FFFFFF}Report: %s", params);
	ShowPlayerDialog(playerid, DIALOG_REPORT, DIALOG_STYLE_MSGBOX, "Confirmation:", showString, "Yes", "No"); 
	
	format(playerReport[playerid], 128, "%s", params);
	return 1;
}

CMD:helpup(playerid, params[])
{
	new 
		playerb;

	if(sscanf(params, "u", playerb))
		return SendUsageMessage(playerid, "/helpup [playerid OR name]"); 
		
	if(!IsPlayerConnected(playerb))
		return SendErrorMessage(playerid, "The player you specified isn't connected."); 
		
	if(AccountInfo[playerb][E_MASTERS_LOGGED] == false)
		return SendErrorMessage(playerid, "The player you specified isn't logged in."); 

	if(!IsPlayerNearPlayer(playerid, playerb, 5.0))
		return SendErrorMessage(playerid, "You aren't near that player."); 

	if (playerb == playerid)
	    return SendErrorMessage(playerid, "You cannot revive yourself.");
		
	if(GetPlayerTeam(playerb) == PLAYER_STATE_ALIVE)
		return SendErrorMessage(playerid, "That player isn't dead or brutally wounded.");
	
	SetPlayerTeam(playerb, PLAYER_STATE_ALIVE); 
	SetPlayerHealthEx(playerb, 100); 
	
	TogglePlayerControllable(playerb, true); 
	PlayerInfo[playerb][E_CHARACTER_INJURED] = 0;
	PlayerInfo[playerb][E_CHARACTER_DEATH] = 0;
	
	SetPlayerChatBubble(playerb, "(( Respawned ))", COLOR_WHITE, 21.0, 3000); 
	ShowBoxMessage(playerb, "You were revived", 3);
	
	ClearDamages(playerb);
	return 1;
}

CMD:pay(playerid, params[])
{
	new playerb, amount, str[128]; 

	if(sscanf(params, "ui", playerb, amount))
		return SendUsageMessage(playerid, "/pay [playerid OR name] [amount] [emote (Optional)]");

	if(!IsPlayerConnected(playerb))
		return SendErrorMessage(playerid, "The player you specified isn't connected.");
		
	if(AccountInfo[playerb][E_MASTERS_LOGGED] == false)
		return SendErrorMessage(playerid, "The player you specified isn't logged in.");
		
	if(!IsPlayerNearPlayer(playerid, playerb, 5.0))
		return SendErrorMessage(playerid, "You aren't near that player."); 

	if(playerb == playerid)
		return SendErrorMessage(playerid, "You can't pay yourself.");
		
	if(amount > PlayerInfo[playerid][E_CHARACTER_MONEY])
		return SendErrorMessage(playerid, "You don't have that amount of money.");

	if(amount < 1)
		return SendErrorMessage(playerid, "You don't have that amount of money.");
		
	if(gettime() - playerLastpay[playerid] < 3)
		return SendErrorMessage(playerid, "Please wait before paying again.");
		
	PlayerPlaySound(playerid, 1052, 0.0, 0.0, 0.0); PlayerPlaySound(playerb, 1052, 0.0, 0.0, 0.0);
	playerLastpay[playerid] = gettime(); 
	
	SendServerMessage(playerid, "PAY: {ffffff}You have sent {5B9460}$%s{ffffff} to %s.", FormatMoney(amount), ReturnSettingsName(playerb, playerid)); 
	SendServerMessage(playerb, "PAY: {ffffff}You have received {5B9460}$%s{ffffff} from %s.", FormatMoney(amount), ReturnSettingsName(playerid, playerid)); 
	
	if(PlayerInfo[playerid][E_CHARACTER_LEVEL] <= 3 && PlayerInfo[playerb][E_CHARACTER_LEVEL] <= 3 || amount >= 50000)
	{
		format(str, sizeof(str), "%s has paid $%s to %s.", ReturnSettingsName(playerid, playerid), FormatMoney(amount), ReturnSettingsName(playerb, playerid)); 
		SendAdminMessage(1, str);
	}
	
	GiveMoney(playerid, -amount); GiveMoney(playerb, amount);
	return 1;
}

CMD:respect(playerid, params[])
{
	new playerb, amount; 

	if(sscanf(params, "ui", playerb, amount))
		return SendUsageMessage(playerid, "/respect [playerid OR name] [amount]");

	if(!IsPlayerConnected(playerb))
		return SendErrorMessage(playerid, "The player you specified isn't connected.");
		
	if(AccountInfo[playerb][E_MASTERS_LOGGED] == false)
		return SendErrorMessage(playerid, "The player you specified isn't logged in.");
		
	if(!IsPlayerNearPlayer(playerid, playerb, 5.0))
		return SendErrorMessage(playerid, "You aren't near that player."); 
		
	if(amount > PlayerInfo[playerid][E_CHARACTER_RESPECT])
		return SendErrorMessage(playerid, "You don't have that amount of respect.");

	if(amount < 1)
		return SendErrorMessage(playerid, "You don't have that amount of money.");
		
	new str[64], str1[64];
    format(str, sizeof(str), "~h~Respected~n~~w~Respect +");
    GameTextForPlayer(playerb, str, 3, 6);

	format(str1, sizeof(str1), "~h~Respected~n~~w~Respect -");
    GameTextForPlayer(playerid, str1, 3, 6);

	PlayerInfo[playerid][E_CHARACTER_RESPECT] -= amount;
	PlayerInfo[playerb][E_CHARACTER_RESPECT] += amount;
	return 1;
}

CMD:charity(playerid, params[])
{
	new charity;
		
	if(sscanf(params, "d", charity))
		return SendUsageMessage(playerid, "/charity [amount]");
		
	if(charity < 1 || charity > PlayerInfo[playerid][E_CHARACTER_MONEY])
		return SendErrorMessage(playerid, "You can't charity that amount."); 
	
	GiveMoney(playerid, -charity);
	SaveCharacter(playerid);
	SendServerMessage(playerid, "CHARITY: {ffffff}You've charity %s for this server.", FormatMoney(charity));
	return 1;
}

CMD:id(playerid, params[]) // This command was a hefty test. Can be commented out if need be. 
{
	if(isnull(params))
		return SendUsageMessage(playerid, "/id [playerid OR name]"); 
		
	new
		bool:inputID = false,
		playerb
	;
		
	for(new ix = 0, j = strlen(params); ix < j; ix++)
	{
		if (params[ix] > '9' || params[ix] < '0')
		{
			inputID = false; 
		}
		else inputID = true;
	}
	
	if(inputID)
	{
		playerb = strval(params);
		
		if(!IsPlayerConnected(playerb))
			return SendClientMessage(playerid, COLOR_RED, "Player not found."); 
			
		SendClientMessageEx(playerid, COLOR_GREY, "(ID: %i) %s | Level: %i", playerb, ReturnSettingsName(playerb, playerid), PlayerInfo[playerb][E_CHARACTER_LEVEL]); 
	}
	else
	{
		new
			bool:matchFound = false,
			bool:fullName = false,
			countMatches = 0,
			matchesFound[6],
			string[128]
		;
		
		for(new cc = 0; cc < 5; cc++) { matchesFound[cc] = INVALID_PLAYER_ID; }
		
		for(new i = 0, j = strlen(params); i < j; i++)
		{
			if (params[i] != '_')
			{
				fullName = false; 
			}
			else
			{
				fullName = true; 
			}
		}
		
		if(fullName)
		{
			foreach(new b : Player)
			{
				if(strfind(ReturnSettingsName(b, playerid), params, true) != -1)
				{
					SendClientMessageEx(playerid, COLOR_GREY, "(ID: %i) %s | Level: %i", b, ReturnSettingsName(b, playerid), PlayerInfo[b][E_CHARACTER_LEVEL]); 
				}
				else return SendClientMessage(playerid, COLOR_RED, "Player not found."); 
			}
		}
		else
		{
			for(new a = 0; a < MAX_PLAYERS; a++)
			{
				if(IsPlayerConnected(a))
				{
					if(strfind(ReturnSettingsName(a, playerid, 0), params, true) != -1)
					{
						matchFound = true;
						countMatches ++; 
					}
				}
			}
		
			if(matchFound)
			{
				for(new f = 0, g = GetPlayerPoolSize(), t = 0; f <= g; f++)
				{		
					if(IsPlayerConnected(f) && strfind(ReturnSettingsName(f, playerid), params, true) != -1)
					{
						matchesFound[t] = f;
						t++; 
						
						if(t >= 5) break; 
					}
				}
			
				if(countMatches != 0 && countMatches > 1)
				{
					for(new l = 0; l < sizeof(matchesFound); l++)
					{
						if(matchesFound[l] == INVALID_PLAYER_ID)
							continue; 
							
						format(string, sizeof(string), "%s(ID: %i) %s, ", string, matchesFound[l], ReturnSettingsName(matchesFound[l], playerid)); 
											
						if(l % 3 == 0 && l != 0 || l == 5-1)
						{
							SendClientMessage(playerid, COLOR_GREY, string);
							string[0] = 0;
						}
					}
				}
				else if(countMatches == 1)
				{
					SendClientMessageEx(playerid, COLOR_GREY, "(ID: %i) %s | Level: %i", matchesFound[0], ReturnSettingsName(matchesFound[0], playerid), PlayerInfo[matchesFound[0]][E_CHARACTER_LEVEL]); 
				}
			}
			else return SendClientMessage(playerid, COLOR_RED, "Player not found."); 
		}
	}
	return 1; 
}

CMD:buybeer(playerid, params[])
{
	new
		id = IsPlayerInBusiness(playerid);

	if(BusinessInfo[IsPlayerInBusiness(playerid)][E_BUSINESS_ROBBERYTIME] > 0)
		return SendErrorMessage(playerid, "This Business has been robbery.");

	if(IsPlayerInBusiness(playerid) && IsPlayerNearCashiers(playerid))
	{	
		if(BusinessInfo[id][E_BUSINESS_TYPE] != BUSINESS_TYPE_CLUB && BusinessInfo[id][E_BUSINESS_TYPE] != BUSINESS_TYPE_BAR)
			return SendErrorMessage(playerid, "You aren't in a club or bar."); 
		ShowBeerlist(playerid);
	}
	else if(IsPlayerInRangeOfPoint(playerid, 3.0, 2130.7271,-1769.0083,13.5510) || IsPlayerInRangeOfPoint(playerid, 3.0, 2139.9614,-1769.1486,13.5510))
	{
		ShowBeerlist(playerid);
	}
	else
	{
		return SendErrorMessage(playerid, "You aren't in a business."); 
	} 
	return 1;
}

CMD:menu(playerid, params[])
{
    new
		id = IsPlayerInBusiness(playerid);

	if(BusinessInfo[IsPlayerInBusiness(playerid)][E_BUSINESS_ROBBERYTIME] > 0)
		return SendErrorMessage(playerid, "This Business has been robbery.");

	if(IsPlayerInBusiness(playerid) && IsPlayerNearCashiers(playerid))
	{	
		if(BusinessInfo[id][E_BUSINESS_TYPE] != BUSINESS_TYPE_DINNER)
			return SendErrorMessage(playerid, "You aren't in a restaurant.");
		ShowFoodMenu(playerid);
	}
	else if(IsPlayerInRangeOfPoint(playerid, 3.0, 1705.7178,-1650.0876,13.5276) || IsPlayerInRangeOfPoint(playerid, 3.0, 2106.5166,-1797.5454,13.5625) || IsPlayerInRangeOfPoint(playerid, 3.0, 2414.0591,-1504.1791,24.0031) || IsPlayerInRangeOfPoint(playerid, 3.0, 2392.0125,-1905.1108,13.5234) || IsPlayerInRangeOfPoint(playerid, 3.0, 1859.9919,-1670.8585,13.3731))
	{
		ShowFoodMenu(playerid);
	}
	else
	{
		return SendErrorMessage(playerid, "You aren't in a business."); 
	} 
	return 1;
}

CMD:haircut(playerid, params[])
{
	if(IsPlayerInBusiness(playerid) && IsPlayerNearCashiers(playerid))
	{
		if(BusinessInfo[IsPlayerInBusiness(playerid)][E_BUSINESS_TYPE] != BUSINESS_TYPE_HAIRCUT)
			return SendErrorMessage(playerid, "You aren't in a haircut.");

		SetPlayerPos(playerid, 414.4374,-19.8381,1001.8047);
		SetPlayerFacingAngle(playerid, 88.7491);

		new str[512];
		for(new i; i < sizeof(g_aHaircut); i++)
		{
			format(str, sizeof(str), "%s%d\n", str, g_aHaircut[i]);
		}
		Dialog_Show(playerid, Haircuts, DIALOG_STYLE_PREVIEW_MODEL, "Skins:", str, "Select", "Close");
	}
	else return SendErrorMessage(playerid, "You aren't in a business.");
	return 1;
}

Dialog:Haircuts(playerid, response, listitem, inputtext[])
{
	if(response)
	{
		if(250 > PlayerInfo[playerid][E_CHARACTER_MONEY])
		{
			ApplyDynamicActorAnimation(BusinessInfo[IsPlayerInBusiness(playerid)][E_BUSINESS_ACTOR], "HAIRCUTS", "BRB_Cut_Out", 4.1, 0, 0, 0, 0, 0);
			ApplyAnimation(playerid, "HAIRCUTS", "BRB_Sit_Out", 4.1, 0, 0, 0, 0, 0, 0);
			SetTimerEx("ExitHairCut", 1000, false, "i", playerid);
			return SendErrorMessage(playerid, "You can't afford a clothes.");
		}

		if(BusinessInfo[IsPlayerInBusiness(playerid)][E_BUSINESS_STOCK] < 1)
		{
			ApplyDynamicActorAnimation(BusinessInfo[IsPlayerInBusiness(playerid)][E_BUSINESS_ACTOR], "HAIRCUTS", "BRB_Cut_Out", 4.1, 0, 0, 0, 0, 0);
			ApplyAnimation(playerid, "HAIRCUTS", "BRB_Sit_Out", 4.1, 0, 0, 0, 0, 0, 0);
			SetTimerEx("ExitHairCut", 1000, false, "i", playerid);
			return SendErrorMessage(playerid, "This business is out of stock");
		}

		if(GetPlayerFreeToySlot(playerid) == -1)
		{
			ApplyDynamicActorAnimation(BusinessInfo[IsPlayerInBusiness(playerid)][E_BUSINESS_ACTOR], "HAIRCUTS", "BRB_Cut_Out", 4.1, 0, 0, 0, 0, 0);
			ApplyAnimation(playerid, "HAIRCUTS", "BRB_Sit_Out", 4.1, 0, 0, 0, 0, 0, 0);
			SetTimerEx("ExitHairCut", 1000, false, "i", playerid);
			return SendErrorMessage(playerid, "You already have full slot of Accessory!");
		}

		SetTimerEx("StartHairCut", 500, false, "ii", playerid, g_aHaircut[listitem]);
	}
	else
	{
		SetCameraBehindPlayer(playerid);
		TogglePlayerControllable(playerid, true);
	}
	return 1;
}

CMD:clothes(playerid, params[])
{
	new 
	    id = IsPlayerInBusiness(playerid);
	
	if(BusinessInfo[id][E_BUSINESS_ROBBERYTIME] > 0)
		return SendErrorMessage(playerid, "This Business has been robbery.");

	if(!IsPlayerInBusiness(playerid) && !IsPlayerNearCashiers(playerid))
		return SendErrorMessage(playerid, "You aren't in a business.");
		
	if(BusinessInfo[id][E_BUSINESS_TYPE] != BUSINESS_TYPE_CLOTHES)
		return SendErrorMessage(playerid, "You aren't in a clothes.");

    ShowClothesMenu(playerid);
	return 1;
}

CMD:fightstyle(playerid, params[])
{
	new 
	    id = IsPlayerInBusiness(playerid);

	if(!IsPlayerInBusiness(playerid) && !IsPlayerNearCashiers(playerid))
		return SendErrorMessage(playerid, "You aren't in a business.");

	if(BusinessInfo[id][E_BUSINESS_TYPE] != BUSINESS_TYPE_GYM)
		return SendErrorMessage(playerid, "You aren't in a gym.");

    ShowFightStyleMenu(playerid);
	return 1;
}

CMD:radiochannel(playerid, params[])
{
	new str[512];
	strcat(str, "Channel\tTag\tDescription\n"); 
	strcat(str, "1\tCENTRAL\tLSPD Central Bureau Dispatch\n"); 
	strcat(str, "2\tCW.TAC1\tLSPD Citywide TAC #1\n"); 
	strcat(str, "3\tCW.TAC2\tLSPD Citywide TAC #2\n"); 
	strcat(str, "4\tCW.TAC3\tLSPD Citywide TAC #3\n"); 
	strcat(str, "5\t24.CTD\tLSPD Central Traffic Dispatch\n"); 
	strcat(str, "6\t53.DBU\tLSPD Detective Bureau Dispatch\n"); 
	strcat(str, "7\t54.GND\tLSPD Gang & Narcotics Division\n"); 
	strcat(str, "8\t55.OCVD\tLSPD Organzied Crime & Vice Division\n"); 
	strcat(str, "9\t65.METRO\tLSPD Metropolitan Dispatch\n"); 
	strcat(str, "10\t31.IAG\tLSPD Internal Affairs\n"); 
	ShowPlayerDialog(playerid, DIALOG_DEFAULT, DIALOG_STYLE_TABLIST_HEADERS, "Radio Channels:", str, "Select", "Cancel");
	return 1;
}
CMD:setchannel(playerid, params[])
{
	new 
		slot, 
		channel;
	
	if(sscanf(params, "ii", channel, slot))
	{
		SendUsageMessage(playerid, "/setchannel [channel] [slot]"); 
		SendClientMessage(playerid, COLOR_WHITE, "/radiochannel to see LSPD Channel List"); 
		return 1;
	}
		
	if(!Inventory_Count(playerid, "Portable Radio"))
		return SendErrorMessage(playerid, "You don't own a radio.");
		
	if(slot > 2 || slot < 1)
		return SendErrorMessage(playerid, "You specified an invalid slot. (1-2)");
		
	if(channel < 1 || channel > 1000000)
		return SendErrorMessage(playerid, "You specified an invalid channel. (1-1000000)"); 
		
	for(new i = 1; i < 3; i++)
	{
		if(PlayerInfo[i][E_CHARACTER_RADIO][i] == channel)
		{
			SendErrorMessage(playerid, "Your radio slot %i already supports channel %i.", i, channel);
			return 1;
		}
	}
	
	if(channel == 1 || channel == 2 || channel == 3 || channel == 4 || channel == 5 || channel == 6 || channel == 7 || channel == 8 || channel == 9 || channel == 10)
	{
		if(FactionInfo[PlayerInfo[playerid][E_CHARACTER_FACTION]][E_FACTION_TYPE] != FACTION_TYPE_POLICE)
			return SendErrorMessage(playerid, "You're not authorized to use this channel."); 
	}
	
	PlayerInfo[playerid][E_CHARACTER_RADIO][slot] = channel;
	
	SendInfoMessage(playerid, "You're now listening to channel %i under slot %i.", channel, slot);
	SaveCharacter(playerid); 
	return 1;
}

CMD:setslot(playerid, params[])
{
	new
		slot
	;
	
	if(sscanf(params, "i", slot))
		return SendUsageMessage(playerid, "/setslot [slot id]");
		
	if(!Inventory_Count(playerid, "Portable Radio"))
		return SendErrorMessage(playerid, "You don't own a radio.");
		
	if(slot > 2 || slot < 1)
		return SendErrorMessage(playerid, "You specified an invalid slot. (1-2)");
		
	PlayerInfo[playerid][E_CHARACTER_MAINSLOT] = slot;
		
	SendInfoMessage(playerid, "Your local radio slot is now %i.", slot); 
	SaveCharacter(playerid);
	return 1;
}

CMD:r(playerid, params[]) return cmd_radio(playerid, params);
CMD:radio(playerid, params[])
{
	if(!Inventory_Count(playerid, "Portable Radio"))
		return SendErrorMessage(playerid, "You don't own a radio.");

	if(PlayerInfo[playerid][E_CHARACTER_EQUIPITEMS] != PORTABLE_RADIO)
		return SendErrorMessage(playerid, "You must hold the portable radio in your hands.");

	new
		local,
		channel
	;
		
	local = PlayerInfo[playerid][E_CHARACTER_MAINSLOT]; 
	channel = PlayerInfo[playerid][E_CHARACTER_RADIO][local]; 
	
	if(!PlayerInfo[playerid][E_CHARACTER_RADIO][local])
		return SendErrorMessage(playerid, "Your local radio slot isn't set to a channel."); 
		
	if(isnull(params))
		return SendUsageMessage(playerid, "/r [text], /rlow [text], /r[ch] [text], /r[ch]low [text]");
		
	foreach(new i : Player)
	{
		for(new r = 1; r < 3; r ++)
		{
			if(PlayerInfo[i][E_CHARACTER_RADIO][r] == channel)
			{
				if(r != PlayerInfo[i][E_CHARACTER_MAINSLOT])
					SendClientMessageEx(i, COLOR_RADIOEX, "**[CH: %s, S: %d] %s says: %s", ReturnChannelName(PlayerInfo[i][E_CHARACTER_RADIO][r]), IsChannelSlot(i, channel), ReturnSettingsName(playerid, playerid), params);
					
				else SendClientMessageEx(i, COLOR_RADIO, "**[CH: %s, S: %d] %s says: %s", ReturnChannelName(PlayerInfo[i][E_CHARACTER_RADIO][r]), IsChannelSlot(i, channel), ReturnSettingsName(playerid, playerid), params);
			}
		}
	}
	
	new Float:posx, Float:posy, Float:posz;
	GetPlayerPos(playerid, posx,posy,posz);

	foreach(new i : Player)
	{
	   	if(i == playerid)
	       continue;

		else if(IsPlayerInRangeOfPoint(i, 20.0, posx,posy,posz))
		{
			SendClientMessageEx(playerid, COLOR_GRAD1, "(Radio) %s says: %s", ReturnSettingsName(playerid, playerid), params);
		}
	}
	return 1;
}

CMD:rlow(playerid, params[])
{
	if(!Inventory_Count(playerid, "Portable Radio"))
		return SendErrorMessage(playerid, "You don't own a radio.");

	new
		local,
		channel
	;
		
	local = PlayerInfo[playerid][E_CHARACTER_MAINSLOT]; 
	channel = PlayerInfo[playerid][E_CHARACTER_RADIO][local]; 
	
	if(!PlayerInfo[playerid][E_CHARACTER_RADIO][local])
		return SendErrorMessage(playerid, "Your local radio slot isn't set to a channel."); 
		
	if(isnull(params))
		return SendErrorMessage(playerid, "/rlow [text]");
		
	foreach(new i : Player)
	{
		for(new r = 1; r < 3; r ++)
		{
			if(PlayerInfo[i][E_CHARACTER_RADIO][r] == channel)
			{
				if(r != PlayerInfo[i][E_CHARACTER_MAINSLOT])
					SendClientMessageEx(i, COLOR_RADIOEX, "**[CH: %d, S: %d] %s says: %s", PlayerInfo[i][E_CHARACTER_RADIO][r], IsChannelSlot(i, channel), ReturnSettingsName(playerid, playerid), params);
					
				else SendClientMessageEx(i, COLOR_RADIO, "**[CH: %d, S: %d] %s says: %s", PlayerInfo[i][E_CHARACTER_RADIO][r], IsChannelSlot(i, channel), ReturnSettingsName(playerid, playerid), params);
			}
		}
	}
	
	new Float:posx, Float:posy, Float:posz;
	GetPlayerPos(playerid, posx,posy,posz);

	foreach(new i : Player)
	{
	   	if(i == playerid)
	       continue;

		else if(IsPlayerInRangeOfPoint(i, 5.0, posx,posy,posz))
		{
			SendClientMessageEx(playerid, COLOR_GRAD1, "(Radio) %s says[low]: %s", ReturnSettingsName(playerid, playerid), params);
		}
	}
	return 1;
}

CMD:r2(playerid, params[])
{
	if(!Inventory_Count(playerid, "Portable Radio"))
		return SendErrorMessage(playerid, "You don't own a radio.");

	new
		channel
	;
		
	channel = PlayerInfo[playerid][E_CHARACTER_RADIO][2]; 
	
	if(!PlayerInfo[playerid][E_CHARACTER_RADIO][2])
		return SendErrorMessage(playerid, "Your local radio slot isn't set to a channel."); 
		
	if(isnull(params))
		return SendUsageMessage(playerid, "/r2 [text]");
		
	foreach(new i : Player)
	{
		for(new r = 1; r < 3; r ++)
		{
			if(PlayerInfo[i][E_CHARACTER_RADIO][r] == channel)
			{
				if(r != PlayerInfo[i][E_CHARACTER_MAINSLOT])
					SendClientMessageEx(i, COLOR_RADIOEX, "**[CH: %d, S: %d] %s says: %s", PlayerInfo[i][E_CHARACTER_RADIO][r], IsChannelSlot(i, channel), ReturnSettingsName(playerid, playerid), params);
					
				else SendClientMessageEx(i, COLOR_RADIO, "**[CH: %d, S: %d] %s says: %s", PlayerInfo[i][E_CHARACTER_RADIO][r], IsChannelSlot(i, channel), ReturnSettingsName(playerid, playerid), params);
			}
		}
	}
	
	new Float:posx, Float:posy, Float:posz;
	GetPlayerPos(playerid, posx,posy,posz);

	foreach(new i : Player)
	{
	   	if(i == playerid)
	       continue;

		else if(IsPlayerInRangeOfPoint(i, 20.0, posx,posy,posz))
		{
			SendClientMessageEx(playerid, COLOR_GRAD1, "(Radio) %s says: %s", ReturnSettingsName(playerid, playerid), params);
		}
	}
	return 1;
}

CMD:r2low(playerid, params[])
{
	if(!Inventory_Count(playerid, "Portable Radio"))
		return SendErrorMessage(playerid, "You don't own a radio.");

	new
		channel
	;
		
	channel = PlayerInfo[playerid][E_CHARACTER_RADIO][2]; 
	
	if(!PlayerInfo[playerid][E_CHARACTER_RADIO][2])
		return SendErrorMessage(playerid, "Your local radio slot isn't set to a channel."); 
		
	if(isnull(params))
		return SendUsageMessage(playerid, "/r2low [text]");
		
	foreach(new i : Player)
	{
		for(new r = 1; r < 3; r ++)
		{
			if(PlayerInfo[i][E_CHARACTER_RADIO][r] == channel)
			{
				if(r != PlayerInfo[i][E_CHARACTER_MAINSLOT])
					SendClientMessageEx(i, COLOR_RADIOEX, "**[CH: %d, S: %d] %s says: %s", PlayerInfo[i][E_CHARACTER_RADIO][r], IsChannelSlot(i, channel), ReturnSettingsName(playerid, playerid), params);
					
				else SendClientMessageEx(i, COLOR_RADIO, "**[CH: %d, S: %d] %s says: %s", PlayerInfo[i][E_CHARACTER_RADIO][r], IsChannelSlot(i, channel), ReturnSettingsName(playerid, playerid), params);
			}
		}
	}
	
	new Float:posx, Float:posy, Float:posz;
	GetPlayerPos(playerid, posx,posy,posz);

	foreach(new i : Player)
	{
	   	if(i == playerid)
	       continue;

		else if(IsPlayerInRangeOfPoint(i, 6.0, posx,posy,posz))
		{
			SendClientMessageEx(playerid, COLOR_GRAD1, "(Radio) %s says[low]: %s", ReturnSettingsName(playerid, playerid), params);
		}
	}
	return 1;
}
 
CMD:acceptdeath(playerid, params[])
{
	if(GetPlayerTeam(playerid) != PLAYER_STATE_WOUNDED)
		return SendErrorMessage(playerid, "You aren't brutally wounded.");
		
	CallLocalFunction("OnPlayerDead", "ddd", playerid, INVALID_PLAYER_ID, -1, 0); 
	return 1;
}

CMD:respawnme(playerid, params[])
{
	if(GetPlayerTeam(playerid) != PLAYER_STATE_DEAD)
		return SendErrorMessage(playerid, "You aren't dead right now.");
		
	if(gettime() - PlayerInfo[playerid][E_CHARACTER_RESPAWNTIME] < 60)
		return SendErrorMessage(playerid, "You've only been dead for %i seconds. You need to wait at least 60 sec to respawn.", gettime() - PlayerInfo[playerid][E_CHARACTER_RESPAWNTIME]); 

	PlayerInfo[playerid][E_CHARACTER_RESPAWNTIME] = 0;
	PlayerInfo[playerid][E_CHARACTER_DEATH] = 0;
	SetPlayerChatBubble(playerid, "Respawned", COLOR_WHITE, 20.0, 1500);
	
	TogglePlayerControllable(playerid, true);

	SetPlayerHealthEx(playerid, 50);
	SetPlayerTeam(playerid, PLAYER_STATE_ALIVE); 
	SetPlayerPosEx(playerid, 2032.9578,-1416.1289,16.9922);
	SetPlayerInterior(playerid, 0);
	SetPlayerVirtualWorld(playerid, 0);
 
	return 1;
}

CMD:setspawn(playerid, params[])
{
	new 
		id;

	if(sscanf(params, "i", id))
	{
		SendUsageMessage(playerid, "/setspawn [spawn id]");
		SendClientMessage(playerid, COLOR_WHITE, "1. Hoodrats, 2. Last Position, 3. Faction");
		return 1;
	}
	
	if(id > 3 || id < 1)
		return SendErrorMessage(playerid, "You specified an invalid ID."); 
		
	switch(id)
	{
		case 1:
		{
			if(PlayerInfo[playerid][E_CHARACTER_SPAWNPOINT] == 0)
				return SendErrorMessage(playerid, "This is already your spawn point."); 
				
			PlayerInfo[playerid][E_CHARACTER_SPAWNPOINT] = 0; 
			SendInfoMessage(playerid, "You will now spawn at the hoodrats position."); 
			SaveCharacter(playerid);
		}
		case 2:
		{
			if(PlayerInfo[playerid][E_CHARACTER_SPAWNPOINT] == 1)
				return SendErrorMessage(playerid, "This is already your spawn point."); 
				
			PlayerInfo[playerid][E_CHARACTER_SPAWNPOINT] = 1; 
			SendInfoMessage(playerid, "You will now spawn at the last position."); 
			SaveCharacter(playerid);
		}
		case 3:
		{
			if(PlayerInfo[playerid][E_CHARACTER_SPAWNPOINT] == 2)
				return SendErrorMessage(playerid, "This is already your spawn point.");
		
			if(!IsPlayerFaction(playerid))
				return SendErrorMessage(playerid, "You aren't in any faction.");
				
			PlayerInfo[playerid][E_CHARACTER_SPAWNPOINT] = 2;
			SendInfoMessage(playerid, "You will now spawn at your faction."); 
			SaveCharacter(playerid);
		}
	}

	return 1;
}

CMD:deposit(playerid, params[])
{
	new
		id = IsPlayerInBusiness(playerid),
		amount
	;
		
	if(!id)
		return SendErrorMessage(playerid, "You aren't in a business.");
		
	if(BusinessInfo[id][E_BUSINESS_TYPE] != BUSINESS_TYPE_BANK)
		return SendErrorMessage(playerid, "You aren't inside a bank."); 
		
	if(sscanf(params, "d", amount))
		return SendUsageMessage(playerid, "/deposit [deposit amount]");
		
	if(amount < 1 || amount > PlayerInfo[playerid][E_CHARACTER_MONEY])
		return SendErrorMessage(playerid, "You can't deposit that amount."); 
		
	PlayerInfo[playerid][E_CHARACTER_BANK]+= amount;
	GiveMoney(playerid, -amount); 
	
	SendInfoMessage(playerid, "You have deposited {5B9460}$%s{ffffff} into Your account, Total:{5B9460}$%s{ffffff}", FormatMoney(amount), FormatMoney(PlayerInfo[playerid][E_CHARACTER_BANK]));
	SaveCharacter(playerid);
	return 1; 
}

CMD:withdraw(playerid, params[])
{
	new
		id = IsPlayerInBusiness(playerid),
		amount
	;
		
	if(!id)
		return SendErrorMessage(playerid, "You aren't in a business.");
		
	if(BusinessInfo[id][E_BUSINESS_TYPE] != BUSINESS_TYPE_BANK && BusinessInfo[id][E_BUSINESS_TYPE] != BUSINESS_TYPE_GENERAL)
		return SendErrorMessage(playerid, "You can't do this inside this business."); 
		
	if(sscanf(params, "i", amount))
		return SendUsageMessage(playerid, "/withdraw [amount]");
		
	if(amount < 1 || amount > PlayerInfo[playerid][E_CHARACTER_BANK])
		return SendErrorMessage(playerid, "You can't withdraw that amount."); 

		
	PlayerInfo[playerid][E_CHARACTER_BANK]-= amount;
	GiveMoney(playerid, amount);
	
	SendInfoMessage(playerid, "You have withdrawn {5B9460}$%s{ffffff} from Your account, Total:{5B9460}$%s{ffffff}", FormatMoney(amount), FormatMoney(PlayerInfo[playerid][E_CHARACTER_BANK]));
	SaveCharacter(playerid);
	return 1;
}

CMD:balance(playerid, params[])
{
	new
		id = IsPlayerInBusiness(playerid)
	;
		
	if(!id)
		return SendErrorMessage(playerid, "You aren't in a business.");
		
	if(BusinessInfo[id][E_BUSINESS_TYPE] != BUSINESS_TYPE_BANK && BusinessInfo[id][E_BUSINESS_TYPE] != BUSINESS_TYPE_GENERAL)
		return SendErrorMessage(playerid, "You can't do this inside this business."); 
	
	SendInfoMessage(playerid, "You have {5B9460}$%s{ffffff} in your bank and {5B9460}$%s{ffffff} in your paycheck. (%s)", FormatMoney(PlayerInfo[playerid][E_CHARACTER_BANK]), FormatMoney(PlayerInfo[playerid][E_CHARACTER_PAYCHECK]), ReturnDate());	
	return 1;
}

CMD:h(playerid, params[]) return cmd_hangup(playerid, params); 
CMD:hangup(playerid, params[])
{
	if(PlayerInfo[playerid][E_CHARACTER_PHONEOFF])
		return SendErrorMessage(playerid, "Your cellphone is turned off.");
		
	if(PlayerInfo[playerid][E_CHARACTER_HANDCUFF])
		return SendErrorMessage(playerid, "You can't use your phone right now."); 
		
	new
		str[128]
	;
		
	if(playerPhone[playerid])
	{
		KillTimer(playerPhone[playerid]); 
		
		SendErrorMessage(playerid, "You hung up..."); 
		return 1;
	}
	
	if(PlayerInfo[playerid][E_CHARACTER_PHONELINE] == 999 || PlayerInfo[playerid][E_CHARACTER_PHONELINE] == 911 || PlayerInfo[playerid][E_CHARACTER_PHONELINE] == 555)
	{
		for(new i = 0; i < 2; i++) 
		{
			KillTimer(Player911Timer[i][playerid]); 
		}
		SendErrorMessage(playerid, "You hung up..."); 
		
		PlayerInfo[playerid][E_CHARACTER_PHONELINE] = INVALID_PLAYER_ID;
		PlayerInfo[playerid][E_CHARACTER_CALL] = 0;
		
		if(GetPlayerSpecialAction(playerid) == SPECIAL_ACTION_USECELLPHONE){
			SetPlayerSpecialAction(playerid, SPECIAL_ACTION_STOPUSECELLPHONE);
		}
		return 1;
	}
	
	if(PlayerInfo[playerid][E_CHARACTER_PHONELINE] == INVALID_PLAYER_ID)
		return SendErrorMessage(playerid, "You aren't in a call or being called."); 
	
	if(PlayerInfo[playerid][E_CHARACTER_CALL] && PlayerInfo[playerid][E_CHARACTER_PHONELINE] != INVALID_PLAYER_ID)
	{	
		SendErrorMessage(playerid, "You hung up..."); 
		SendClientMessage(PlayerInfo[playerid][E_CHARACTER_PHONELINE], COLOR_GREY, "[!] The call was disconnected."); 
		
		if(GetPlayerSpecialAction(playerid) == SPECIAL_ACTION_USECELLPHONE){
			SetPlayerSpecialAction(playerid, SPECIAL_ACTION_STOPUSECELLPHONE);
		}
		
		PlayerInfo[ PlayerInfo[playerid][E_CHARACTER_PHONELINE] ][E_CHARACTER_PHONELINE] = INVALID_PLAYER_ID; 
		PlayerInfo[ PlayerInfo[playerid][E_CHARACTER_PHONELINE] ][E_CHARACTER_CALL] = 0; 
		
		PlayerInfo[playerid][E_CHARACTER_CALL] = 0; 
		PlayerInfo[playerid][E_CHARACTER_PHONELINE] = INVALID_PLAYER_ID; 
		return 1;
	}
	
	if(!PlayerInfo[playerid][E_CHARACTER_CALL] && PlayerInfo[playerid][E_CHARACTER_PHONELINE] != INVALID_PLAYER_ID)
	{
		SendErrorMessage(playerid, "You hung up..."); 
		SendClientMessage(PlayerInfo[playerid][E_CHARACTER_PHONELINE], COLOR_GREY, "[!] They hung up..."); 
		
		printf("pPhoneline = %i", PlayerInfo[playerid][E_CHARACTER_PHONELINE]);
		
		if(GetPlayerSpecialAction(playerid) == SPECIAL_ACTION_USECELLPHONE){
			SetPlayerSpecialAction(playerid, SPECIAL_ACTION_STOPUSECELLPHONE);
		}
		
		if(GetPlayerSpecialAction(PlayerInfo[playerid][E_CHARACTER_PHONELINE]) == SPECIAL_ACTION_USECELLPHONE){
			SetPlayerSpecialAction(PlayerInfo[playerid][E_CHARACTER_PHONELINE], SPECIAL_ACTION_STOPUSECELLPHONE);
		}
		
		format(str, sizeof(str), "* %s puts their phone away.", ReturnSettingsName(playerid, playerid));
		SetPlayerChatBubble(playerid, str, COLOR_EMOTE, 20.0, 3000);
		
		format(str, sizeof(str), "* %s puts their phone away.", ReturnSettingsName(PlayerInfo[playerid][E_CHARACTER_PHONELINE], playerid));
		SetPlayerChatBubble(PlayerInfo[playerid][E_CHARACTER_PHONELINE], str, COLOR_EMOTE, 20.0, 3000);
		
		PlayerInfo[playerid][E_CHARACTER_CALL] = 0;
		PlayerInfo[ PlayerInfo[playerid][E_CHARACTER_PHONELINE] ][E_CHARACTER_CALL] = 0;
		
		PlayerInfo[ PlayerInfo[playerid][E_CHARACTER_PHONELINE] ][E_CHARACTER_PHONELINE] = INVALID_PLAYER_ID;
		PlayerInfo[playerid][E_CHARACTER_PHONELINE] = INVALID_PLAYER_ID;
		return 1;
	}
	
	return 1;
}

CMD:p(playerid, params[]) return cmd_pickup(playerid, params); 
CMD:pickup(playerid, params[])
{
	if(PlayerInfo[playerid][E_CHARACTER_PHONEOFF])
		return SendErrorMessage(playerid, "Your cellphone is turned off.");
		
	if(PlayerInfo[playerid][E_CHARACTER_HANDCUFF])
		return SendErrorMessage(playerid, "You can't use your phone right now."); 

	if(PlayerInfo[playerid][E_CHARACTER_PRISON])
		return SendErrorMessage(playerid, "You can't use your phone right now."); 

	if(PlayerInfo[playerid][E_CHARACTER_PHONELINE] == INVALID_PLAYER_ID)
		return SendErrorMessage(playerid, "You aren't being called."); 
		
	if(PlayerInfo[playerid][E_CHARACTER_PHONELINE] != INVALID_PLAYER_ID && !PlayerInfo[playerid][E_CHARACTER_CALL])
		return SendErrorMessage(playerid, "You're already in a phone call."); 
		
	SendClientMessage(PlayerInfo[playerid][E_CHARACTER_PHONELINE], COLOR_GREY, "[!] They picked up. You can talk now by using the chat box.");
	SendClientMessage(playerid, COLOR_FACTION, "You can talk now by using the chatbox.");	

	ShowPhone(PlayerInfo[playerid][E_CHARACTER_PHONELINE], 4);
	ShowPhone(playerid, 4);

	PlayerInfo[playerid][E_CHARACTER_CALL] = 0; 
	PlayerInfo[ PlayerInfo[playerid][E_CHARACTER_PHONELINE] ][E_CHARACTER_CALL] = 0;
	
	SetPlayerSpecialAction(playerid, SPECIAL_ACTION_USECELLPHONE);
	KillTimer(playerPhone[playerid]); 
	
	playerPhone[playerid] = 0; playerPhone[ PlayerInfo[playerid][E_CHARACTER_PHONELINE] ] = 0; 
	return 1;
}

CMD:call(playerid, params[])
{
	new
		str[128],
		phone_number,
		playerb = INVALID_PLAYER_ID; 

	if(GetPlayerTeam(playerid) != PLAYER_STATE_ALIVE)
		return SendErrorMessage(playerid, "You aren't alive.");
		
	if(!Inventory_Count(playerid, "Cellphone") && PlayerInfo[playerid][E_CHARACTER_EQUIPITEMS] != CELLPHONE)
		return SendErrorMessage(playerid, "You must hold the cellphone in your hands."); 

	if(PlayerInfo[playerid][E_CHARACTER_PHONEOFF])
		return SendErrorMessage(playerid, "Your cellphone is turned off.");
		
	if(PlayerInfo[playerid][E_CHARACTER_HANDCUFF])
		return SendErrorMessage(playerid, "You can't use your phone right now."); 

	if(PlayerInfo[playerid][E_CHARACTER_PRISON])
		return SendErrorMessage(playerid, "You can't use your phone right now."); 
		
	if(playerPhone[playerid])
		return SendErrorMessage(playerid, "You can't make a call right now.");
		
	if(sscanf(params, "i", phone_number))
		return SendUsageMessage(playerid, "/call [phone number]"); 
		
	foreach(new i : Player) if(PlayerInfo[i][E_CHARACTER_PHONE] == phone_number){
			playerb = i;
	}
	
	format(str, sizeof(str), "* %s dials a number on their phone.", ReturnSettingsName(playerid, playerid));
	SetPlayerChatBubble(playerid, str, COLOR_EMOTE, 20.0, 3000);
	SendClientMessage(playerid, COLOR_EMOTE, str); 
	
	SetPlayerSpecialAction(playerid, SPECIAL_ACTION_USECELLPHONE);
	PlayerPlaySound(playerid, 3600, 0.0, 0.0, 0.0);
	
	if(phone_number == 911)
	{
		PlayerInfo[playerid][E_CHARACTER_PHONELINE] = 999;
		PlayerInfo[playerid][E_CHARACTER_CALL] = 0; 
	
		Player911Timer[0][playerid] = SetTimerEx("On911Call", 2000, false, "i", playerid);
		return 1;
	}
	if(phone_number == 111)
	{
		PlayerInfo[playerid][E_CHARACTER_PHONELINE] = 111;
		PlayerInfo[playerid][E_CHARACTER_CALL] = 0; 
		playerPhone[playerid] = 0;

		SetTimerEx("SendTaxiMessage", 2000, false, "i", playerid);
	}
	
	if(playerb == INVALID_PLAYER_ID)
	{
		playerPhone[playerid] = SetTimerEx("OnPhoneCall", 4500, false, "ii", playerid, 1); 
		return 1;
	}
	
	if(PlayerInfo[playerb][E_CHARACTER_PHONEOFF])
	{
		playerPhone[playerid] = SetTimerEx("OnPhoneCall", 3000, false, "ii", playerid, 2); 
		return 1;
	}
	
	if(PlayerInfo[playerb][E_CHARACTER_CALL])
	{
		playerPhone[playerid] = SetTimerEx("OnPhoneCall", 3000, false, "ii", playerid, 3);
		return 1;
	}
	
	if(PlayerInfo[playerb][E_CHARACTER_PHONELINE] != INVALID_PLAYER_ID)
	{
		playerPhone[playerid] = SetTimerEx("OnPhoneCall", 3300, false, "ii", playerid, 4);
		return 1;
	}
	
	SendNearbyMessage(playerb, 20.0, COLOR_EMOTE, "* %s's phone begins to ring.", ReturnSettingsName(playerid, playerid)); 
	SendClientMessageEx(playerb, COLOR_GREY, "[!] To pickup the call, use /pickup. Incoming call from %i.", PlayerInfo[playerid][E_CHARACTER_PHONE]); 
	
	ShowPhone(playerid, 1);
	ShowPhone(playerb, 2);

	PlayerInfo[playerid][E_CHARACTER_CALL] = 1; PlayerInfo[playerb][E_CHARACTER_CALL] = 1;
	
	PlayerInfo[playerid][E_CHARACTER_PHONELINE] = playerb;
	PlayerInfo[playerb][E_CHARACTER_PHONELINE] = playerid; 
	
	playerPhone[playerb] = SetTimerEx("OnSuccessCall", 3000, true, "i", playerid); 
	return 1;
}

CMD:sms(playerid, params[])
{
	new
		text[128],
		str[128],
		phone_number,
		playerb = INVALID_PLAYER_ID
	;
	
	if(!Inventory_Count(playerid, "Cellphone") && PlayerInfo[playerid][E_CHARACTER_EQUIPITEMS] != CELLPHONE)
		return SendErrorMessage(playerid, "You must hold the cellphone in your hands."); 

	if(PlayerInfo[playerid][E_CHARACTER_PHONEOFF])
		return SendErrorMessage(playerid, "Your cellphone is turned off.");
		
	if(PlayerInfo[playerid][E_CHARACTER_HANDCUFF])
		return SendErrorMessage(playerid, "You can't use your phone right now."); 

	if(PlayerInfo[playerid][E_CHARACTER_PRISON])
		return SendErrorMessage(playerid, "You can't use your phone right now."); 
		
	if(playerText[playerid])
		return SendClientMessage(playerid, COLOR_WHITE, "Please Wait."); 
		
	if(sscanf(params, "is[128]", phone_number, text))
		return SendUsageMessage(playerid, "/sms [phone number] [text]"); 
		
	foreach(new i : Player) if(PlayerInfo[i][E_CHARACTER_PHONE] == phone_number){
		playerb = i;
	}
	
	SendErrorMessage(playerid, "Your text message is being sent.");

	format(str, sizeof(str), "* %s takes out their cellphone.", ReturnSettingsName(playerid, playerid));
	SetPlayerChatBubble(playerid, str, COLOR_EMOTE, 20.0, 3000); 
	
	if(playerb == INVALID_PLAYER_ID)
	{
		playerText[playerid] = SetTimerEx("OnPhoneSMS", 3000, false, "ii", playerid, 1); 
		return 1;
	}
	
	if(PlayerInfo[playerb][E_CHARACTER_PHONEOFF])
	{
		playerText[playerid] = SetTimerEx("OnPhoneSMS", 3000, false, "ii", playerid, 2);
		return 1;
	}
		
	playerText[playerid] = SetTimerEx("OnPhoneSMS", 1500, false, "iiis", playerid, 3, playerb, text); 
	return 1;
}

CMD:loudspeaker(playerid, params[])
{
	if(PlayerInfo[playerid][E_CHARACTER_PHONEOFF])
		return SendErrorMessage(playerid, "Your cellphone is turned off.");
		
	if(PlayerInfo[playerid][E_CHARACTER_HANDCUFF])
		return SendErrorMessage(playerid, "You can't use your phone right now."); 

	if(PlayerInfo[playerid][E_CHARACTER_PRISON])
		return SendErrorMessage(playerid, "You can't use your phone right now."); 
		
	if(PlayerInfo[playerid][E_CHARACTER_PHONESPEAKER])
	{
		SendNearbyMessage(playerid, 20.0, COLOR_EMOTE, "* %s turns their phones loudspeaker off.", ReturnSettingsName(playerid, playerid));
		PlayerInfo[playerid][E_CHARACTER_PHONESPEAKER] = false;
	}
	else
	{
		SendNearbyMessage(playerid, 20.0, COLOR_EMOTE, "* %s turns their phones loudspeaker on.", ReturnSettingsName(playerid, playerid));
		PlayerInfo[playerid][E_CHARACTER_PHONESPEAKER] = true;
	}
	
	return 1; 
}

CMD:license(playerid, params[])
{
	new
		playerb;
		
	if(sscanf(params, "u", playerb))
		return SendUsageMessage(playerid, "/license [playerid OR name]"); 
	
	if(!IsPlayerConnected(playerb))
		return SendErrorMessage(playerid, "You specified an invalid player.");
		
	if(AccountInfo[playerb][E_MASTERS_LOGGED] == false)
		return SendErrorMessage(playerid, "You specified a player that isn't logged in.");
		
	if(!IsPlayerNearPlayer(playerid, playerb, 5.0))
		return SendErrorMessage(playerid, "You aren't near that player."); 
		
	if(playerb != playerid)
		SendNearbyMessage(playerid, 20.0, COLOR_EMOTE, "* %s shows %s their identification card.", ReturnSettingsName(playerid, playerid), ReturnSettingsName(playerb, playerid));
		
	else SendNearbyMessage(playerid, 20.0, COLOR_EMOTE, "* %s looks at their identification card.", ReturnSettingsName(playerid, playerid));
	
	ReturnLicenses(playerid, playerb); 	
	return 1;
}

CMD:unimpound(playerid, params[])
{
	if(!PlayerInfo[playerid][E_CHARACTER_VEHICLESPAWNED] && !PlayerInfo[playerid][E_CHARACTER_ADMINDUTY])
		return SendErrorMessage(playerid, "You don't have a vehicle spawned.");
	
	if(GetPlayerState(playerid) != PLAYER_STATE_DRIVER)
		return SendErrorMessage(playerid, "You aren't in the driver's seat of a vehicle."); 
		
	new vehicleid = GetPlayerVehicleID(playerid);

	if(VehicleInfo[vehicleid][E_VEHICLE_OWNERDBID] != PlayerInfo[playerid][E_CHARACTER_DBID])
		return SendErrorMessage(playerid, "You don't own this vehicle.");
		
	if(!VehicleInfo[vehicleid][E_VEHICLE_IMPOUND])
		return SendErrorMessage(playerid, "Your vehicle isn't impounded.");
		
	if(1500 > PlayerInfo[playerid][E_CHARACTER_MONEY])
		return SendErrorMessage(playerid, "You don't have $1,500 to pay the fee.");
		
	VehicleInfo[vehicleid][E_VEHICLE_IMPOUND] = false;	
	GiveMoney(playerid, -1500);
	
	SendClientMessageEx(playerid, COLOR_WHITE, "[IMPOUND] You have unimpounded your %s.", ReturnVehicleName(vehicleid));
	SaveVehicle(vehicleid);
	SaveVehicle(vehicleid);
	return 1;
}

CMD:fixr(playerid, params[])
{
	StopAudioStreamForPlayer(playerid);
	return 1;
}

CMD:time(playerid, params[])
{
	cmd_ame(playerid, "checks the time.");
	
	new string[128], hour, minute, seconds;
	
	gettime(hour, minute, seconds);
	
	if(PlayerInfo[playerid][E_CHARACTER_ADMINJAILED] == true)
		format(string, sizeof(string), "~g~|~w~%02d:%02d~g~|~n~~w~Jail Time left: %d SEC", hour, minute, PlayerInfo[playerid][E_CHARACTER_ADMINJAIL]);
	else if(PlayerInfo[playerid][E_CHARACTER_PRISONED] == true)
		format(string, sizeof(string), "~g~|~w~%02d:%02d~g~|~n~~w~Prison Time left: %d SEC", hour, minute, PlayerInfo[playerid][E_CHARACTER_PRISON]);

	else
		format(string, sizeof(string), "~g~|~w~%02d:%02d~g~|", hour, minute);
		
	GameTextForPlayer(playerid, string, 2000, 1);
	
	return 1;
}

CMD:rcp(playerid, params[])
{
	GPS_DisablePlayerRaceCheckPoint(playerid);
	PlayerCheckpoint[playerid] = GPS_NONE;
	return 1;
}

CMD:enter(playerid, params[])
{
	new id, b_id, e_id, str[128]; 

	//Enter
	if((id = IsPlayerNearProperty(playerid)) != 0)
	{
		if(PlayerInfo[playerid][E_CHARACTER_EDITINGOBJECT])
			return SendErrorMessage(playerid, "You can't leave while editing an object.");

		if(PropertyInfo[id][E_PROPERTY_LOCKED])
			return GameTextForPlayer(playerid, "~r~Locked", 3000, 3);
				
		PlayerInfo[playerid][E_CHARACTER_INSIDEPROP] = id;

		SetPlayerPosEx(playerid, PropertyInfo[id][E_PROPERTY_INTERIORPOS][0], PropertyInfo[id][E_PROPERTY_INTERIORPOS][1], PropertyInfo[id][E_PROPERTY_INTERIORPOS][2] - 3);
			
		SetPlayerVirtualWorld(playerid, PropertyInfo[id][E_PROPERTY_INTERIORWORLD]);
		SetPlayerInterior(playerid, PropertyInfo[id][E_PROPERTY_INTERIORINTERIOR]);
			
		TogglePlayerControllable(playerid, false);
		SetTimerEx("OnPlayerEnterProperty", 2000, false, "ii", playerid, id); 	
	}
	if((b_id = IsPlayerNearBusiness(playerid)) != 0)
	{
		if(PlayerInfo[playerid][E_CHARACTER_EDITINGOBJECT])
			return SendErrorMessage(playerid, "You can't leave while editing an object.");

		if(BusinessInfo[b_id][E_BUSINESS_LOCKED])
			return GameTextForPlayer(playerid, "~r~Locked", 3000, 3); 
			
		if(BusinessInfo[b_id][E_BUSINESS_TYPE] == BUSINESS_TYPE_DEALERSHIP || BusinessInfo[b_id][E_BUSINESS_TYPE] == BUSINESS_TYPE_DMV)
			return GameTextForPlayer(playerid, "~r~Closed", 3000, 3); 
			
		if(BusinessInfo[b_id][E_BUSINESS_ENTRANCEFEE] > PlayerInfo[playerid][E_CHARACTER_MONEY])
			return GameTextForPlayer(playerid, "~r~You can't afford this.", 3000, 1); 
			
		if(PlayerInfo[playerid][E_CHARACTER_DBID] != BusinessInfo[b_id][E_BUSINESS_OWNERDBID] && BusinessInfo[b_id][E_BUSINESS_TYPE] != BUSINESS_TYPE_BANK)
		{
			GiveMoney(playerid, -BusinessInfo[b_id][E_BUSINESS_ENTRANCEFEE]); 
			BusinessInfo[b_id][E_BUSINESS_CASH]+= BusinessInfo[b_id][E_BUSINESS_ENTRANCEFEE]; 
		}
			
		format(str, sizeof(str), "%s", BusinessInfo[b_id][E_BUSINESS_NAME]); 
		GameTextForPlayer(playerid, str, 3000, 1); 
		
		SetPlayerPosEx(playerid, BusinessInfo[b_id][E_BUSINESS_INTERIORPOS][0], BusinessInfo[b_id][E_BUSINESS_INTERIORPOS][1], BusinessInfo[b_id][E_BUSINESS_INTERIORPOS][2]); 
		
		SetPlayerInterior(playerid, BusinessInfo[b_id][E_BUSINESS_INTERIORPOSINTERIOR]); 
		SetPlayerVirtualWorld(playerid, BusinessInfo[b_id][E_BUSINESS_INTERIORPOSWORLD]); 
		
		PlayerInfo[playerid][E_CHARACTER_INSIDEBIZ] = b_id; 

		SendBusinessType(playerid, b_id);
		return 1;
	}
	if((e_id = IsPlayerNearEntrance(playerid)) != 0)
	{
		if(PlayerInfo[playerid][E_CHARACTER_EDITINGOBJECT])
			return SendErrorMessage(playerid, "You can't leave while editing an object.");
					
		PlayerInfo[playerid][E_CHARACTER_INSIDEENT] = e_id;

		SetPlayerPosEx(playerid, EntranceInfo[e_id][E_ENTRANCE_INT][0], EntranceInfo[e_id][E_ENTRANCE_INT][1], EntranceInfo[e_id][E_ENTRANCE_INT][2]);
				
		SetPlayerVirtualWorld(playerid, EntranceInfo[e_id][E_ENTRANCE_WORLD]);
		SetPlayerInterior(playerid, EntranceInfo[e_id][E_ENTRANCE_INTERIOR]); 
				
		TogglePlayerControllable(playerid, false);
		SetTimerEx("OnPlayerEnterEntrance", 2000, false, "ii", playerid, e_id); 	
	}
	
	//Exit
	if((id = IsPlayerInProperty(playerid)) != 0)
	{
		if(PlayerInfo[playerid][E_CHARACTER_EDITINGOBJECT])
			return SendErrorMessage(playerid, "You can't leave while editing an object.");

		if(!IsPlayerInRangeOfPoint(playerid, 3.0, PropertyInfo[id][E_PROPERTY_INTERIORPOS][0], PropertyInfo[id][E_PROPERTY_INTERIORPOS][1], PropertyInfo[id][E_PROPERTY_INTERIORPOS][2]))
			return SendErrorMessage(playerid, "You aren't near the door.");
	
		SetPlayerPosEx(playerid, PropertyInfo[id][E_PROPERTY_ENTRANCEPOS][0], PropertyInfo[id][E_PROPERTY_ENTRANCEPOS][1], PropertyInfo[id][E_PROPERTY_ENTRANCEPOS][2]);
		
		SetPlayerVirtualWorld(playerid, PropertyInfo[id][E_PROPERTY_ENTRANCEWORLD]);
		SetPlayerInterior(playerid, PropertyInfo[id][E_PROPERTY_ENTRANCEINTERIOR]); 
		
		PlayerInfo[playerid][E_CHARACTER_INSIDEPROP] = 0;
		return 1;
	}
	
	if((b_id = IsPlayerInBusiness(playerid)) != 0)
	{
		if(PlayerInfo[playerid][E_CHARACTER_EDITINGOBJECT])
			return SendErrorMessage(playerid, "You can't leave while editing an object.");

		if(IsPlayerInRangeOfPoint(playerid, 3.0, BusinessInfo[b_id][E_BUSINESS_INTERIORPOS][0], BusinessInfo[b_id][E_BUSINESS_INTERIORPOS][1], BusinessInfo[b_id][E_BUSINESS_INTERIORPOS][2]))
		{
			if(PlayerInfo[playerid][E_CHARACTER_PURCHASE] > 0)
			{
				SaveCharacter(playerid);
			}
		
			SetPlayerPosEx(playerid, BusinessInfo[b_id][E_BUSINESS_ENTRANCEPOS][0], BusinessInfo[b_id][E_BUSINESS_ENTRANCEPOS][1], BusinessInfo[b_id][E_BUSINESS_ENTRANCEPOS][2]);
			
			SetPlayerVirtualWorld(playerid, 0);
			SetPlayerInterior(playerid, 0);
			
			PlayerInfo[playerid][E_CHARACTER_INSIDEBIZ] = 0;
		}
		return 1;
	}
	if((e_id = IsPlayerInEntrance(playerid)) != 0)
	{
		if(PlayerInfo[playerid][E_CHARACTER_EDITINGOBJECT])
			return SendErrorMessage(playerid, "You can't leave while editing an object.");

		if(IsPlayerInRangeOfPoint(playerid, 3.0, EntranceInfo[e_id][E_ENTRANCE_INT][0], EntranceInfo[e_id][E_ENTRANCE_INT][1], EntranceInfo[e_id][E_ENTRANCE_INT][2]))
		{
			SetPlayerPosEx(playerid, EntranceInfo[e_id][E_ENTRANCE_POS][0], EntranceInfo[e_id][E_ENTRANCE_POS][1], EntranceInfo[e_id][E_ENTRANCE_POS][2]);
			
			SetPlayerVirtualWorld(playerid, 0);
			SetPlayerInterior(playerid, 0); 
			
			PlayerInfo[playerid][E_CHARACTER_INSIDEPROP] = 0;
		}
		return 1;
	}

	return 1;
}

CMD:exit(playerid, params[])
{
	new id, b_id, e_id;
	
	if(PlayerInfo[playerid][E_CHARACTER_EDITINGOBJECT])
		return SendErrorMessage(playerid, "You can't leave while editing an object.");
	
	if((id = IsPlayerInProperty(playerid)) != 0)
	{
		if(PlayerInfo[playerid][E_CHARACTER_EDITINGOBJECT])
			return SendErrorMessage(playerid, "You can't leave while editing an object.");

		if(!IsPlayerInRangeOfPoint(playerid, 3.0, PropertyInfo[id][E_PROPERTY_INTERIORPOS][0], PropertyInfo[id][E_PROPERTY_INTERIORPOS][1], PropertyInfo[id][E_PROPERTY_INTERIORPOS][2]))
			return SendErrorMessage(playerid, "You aren't near the door.");
	
		SetPlayerPosEx(playerid, PropertyInfo[id][E_PROPERTY_ENTRANCEPOS][0], PropertyInfo[id][E_PROPERTY_ENTRANCEPOS][1], PropertyInfo[id][E_PROPERTY_ENTRANCEPOS][2]);
		
		SetPlayerVirtualWorld(playerid, PropertyInfo[id][E_PROPERTY_ENTRANCEWORLD]);
		SetPlayerInterior(playerid, PropertyInfo[id][E_PROPERTY_ENTRANCEINTERIOR]); 
		
		PlayerInfo[playerid][E_CHARACTER_INSIDEPROP] = 0;
		return 1;
	}
	
	if((b_id = IsPlayerInBusiness(playerid)) != 0)
	{
		if(PlayerInfo[playerid][E_CHARACTER_EDITINGOBJECT])
			return SendErrorMessage(playerid, "You can't leave while editing an object.");

		if(IsPlayerInRangeOfPoint(playerid, 2.0, BusinessInfo[b_id][E_BUSINESS_INTERIORPOS][0], BusinessInfo[b_id][E_BUSINESS_INTERIORPOS][1], BusinessInfo[b_id][E_BUSINESS_INTERIORPOS][2]))
		{
			if(PlayerInfo[playerid][E_CHARACTER_PURCHASE] > 0)
			{
				SaveCharacter(playerid);
			}
		
			SetPlayerPosEx(playerid, BusinessInfo[b_id][E_BUSINESS_ENTRANCEPOS][0], BusinessInfo[b_id][E_BUSINESS_ENTRANCEPOS][1], BusinessInfo[b_id][E_BUSINESS_ENTRANCEPOS][2]);
			
			SetPlayerVirtualWorld(playerid, 0);
			SetPlayerInterior(playerid, 0);
			
			PlayerInfo[playerid][E_CHARACTER_INSIDEBIZ] = 0;
		}
		return 1;
	}
	if((e_id = IsPlayerInEntrance(playerid)) != 0)
	{
		if(PlayerInfo[playerid][E_CHARACTER_EDITINGOBJECT])
			return SendErrorMessage(playerid, "You can't leave while editing an object.");

		if(IsPlayerInRangeOfPoint(playerid, 3.0, EntranceInfo[e_id][E_ENTRANCE_INT][0], EntranceInfo[e_id][E_ENTRANCE_INT][1], EntranceInfo[e_id][E_ENTRANCE_INT][2]))
		{
			SetPlayerPosEx(playerid, EntranceInfo[e_id][E_ENTRANCE_POS][0], EntranceInfo[e_id][E_ENTRANCE_POS][1], EntranceInfo[e_id][E_ENTRANCE_POS][2]);
			
			SetPlayerVirtualWorld(playerid, 0);
			SetPlayerInterior(playerid, 0); 
			
			PlayerInfo[playerid][E_CHARACTER_INSIDEPROP] = 0;
		}
		return 1;
	}
	return 1;
}

//Property commands:
CMD:buyproperty(playerid, params[])
{
	new
		bool:nearProperty = false,
		id,
		str[128]
	;
	
	for(new i = 1; i < MAX_PROPERTY; i++)
	{
		if(!PropertyInfo[i][E_PROPERTY_DBID])
			continue;
			
		if(IsPlayerInRangeOfPoint(playerid, 3.0, PropertyInfo[i][E_PROPERTY_ENTRANCEPOS][0], PropertyInfo[i][E_PROPERTY_ENTRANCEPOS][1], PropertyInfo[i][E_PROPERTY_ENTRANCEPOS][2]))
		{
			nearProperty = true;
			id = i;
			break; 
		}
	}
	
	if(nearProperty)
	{
		if(PropertyInfo[id][E_PROPERTY_OWNERDBID])
			return SendErrorMessage(playerid, "This property isn't for sale."); 

		if(PropertyInfo[id][E_PROPERTY_TYPE] == PROPERTY_TYPE_HIGHHOUSE)
			return SendErrorMessage(playerid, "This property isn't for sale."); 
			
		if(PropertyInfo[id][E_PROPERTY_PRICE] > PlayerInfo[playerid][E_CHARACTER_MONEY])
			return SendErrorMessage(playerid, "You can't afford to buy this property.");
			
		if(CountPlayerProperties(playerid) > 3)
			return SendErrorMessage(playerid, "You already own 3 properties."); 
			
		GiveMoney(playerid, -PropertyInfo[id][E_PROPERTY_PRICE]); 	
		PlayerPlaySound(playerid, 1052, 0.0, 0.0, 0.0);
		
		format(str, sizeof(str), "Congratulations!~n~You're now the owner of this property!");
		ShowBoxMessage(playerid, str, 4);
		
		PropertyInfo[id][E_PROPERTY_OWNERDBID] = PlayerInfo[playerid][E_CHARACTER_DBID]; 
		SaveCharacter(playerid); SaveProperty(id);
	}
	else return SendErrorMessage(playerid, "You aren't near a property.");
	return 1; 
}

CMD:lock(playerid, params[])
{
	new
		id,
		b_id
	;
	
	if((id = IsPlayerNearProperty(playerid)) != 0)
	{
		if(PlayerInfo[playerid][E_CHARACTER_DBID] != PropertyInfo[id][E_PROPERTY_OWNERDBID])
			return SendErrorMessage(playerid, "You don't have the keys to this property."); 
			
		if(!PropertyInfo[id][E_PROPERTY_LOCKED])
		{	
			GameTextForPlayer(playerid, "~w~DOOR ~r~LOCKED", 1000, 3);
			PlayerPlaySound(playerid, 1052, 0.0, 0.0, 0.0);
			
			PropertyInfo[id][E_PROPERTY_LOCKED] = true; 
		}
		else
		{
			GameTextForPlayer(playerid, "~w~DOOR ~g~UNLOCKED", 1000, 3);
			PlayerPlaySound(playerid, 1052, 0.0, 0.0, 0.0);
			
			PropertyInfo[id][E_PROPERTY_LOCKED] = false; 
		}
	}
	else if((id = IsPlayerInProperty(playerid)) != 0)
	{
		if(PlayerInfo[playerid][E_CHARACTER_DBID] != PropertyInfo[id][E_PROPERTY_OWNERDBID])
			return SendErrorMessage(playerid, "You don't have the keys to this property."); 
			
		if(!IsPlayerInRangeOfPoint(playerid, 3.0, PropertyInfo[id][E_PROPERTY_INTERIORPOS][0], PropertyInfo[id][E_PROPERTY_INTERIORPOS][1], PropertyInfo[id][E_PROPERTY_INTERIORPOS][2]))
			return SendErrorMessage(playerid, "You aren't near your properties door."); 
			
		if(!PropertyInfo[id][E_PROPERTY_LOCKED])
		{	
			GameTextForPlayer(playerid, "~w~DOOR ~r~LOCKED", 1000, 3);
			PlayerPlaySound(playerid, 1052, 0.0, 0.0, 0.0);
			
			PropertyInfo[id][E_PROPERTY_LOCKED] = true; 
		}
		else
		{
			GameTextForPlayer(playerid, "~w~DOOR ~g~UNLOCKED", 1000, 3);
			PlayerPlaySound(playerid, 1052, 0.0, 0.0, 0.0);
			
			PropertyInfo[id][E_PROPERTY_LOCKED] = false; 
		}
	}
	
	if((b_id = IsPlayerNearBusiness(playerid)) != 0)
	{
		if(BusinessInfo[b_id][E_BUSINESS_OWNERDBID] != PlayerInfo[playerid][E_CHARACTER_DBID])
			return SendErrorMessage(playerid, "You don't have the keys to this business."); 
			
		if(!BusinessInfo[b_id][E_BUSINESS_LOCKED])
		{
			GameTextForPlayer(playerid, "~w~DOOR ~r~LOCKED", 1000, 3);
			PlayerPlaySound(playerid, 1052, 0.0, 0.0, 0.0);
			
			BusinessInfo[b_id][E_BUSINESS_LOCKED] = true;
		}
		else
		{
			GameTextForPlayer(playerid, "~w~DOOR ~g~UNLOCKED", 1000, 3);
			PlayerPlaySound(playerid, 1052, 0.0, 0.0, 0.0);
			
			BusinessInfo[b_id][E_BUSINESS_LOCKED] = false;
		}
	}
	else if((b_id = IsPlayerInBusiness(playerid)) != 0)
	{
		if(!IsPlayerInRangeOfPoint(playerid, 3.0, BusinessInfo[b_id][E_BUSINESS_INTERIORPOS][0], BusinessInfo[b_id][E_BUSINESS_INTERIORPOS][1], BusinessInfo[b_id][E_BUSINESS_INTERIORPOS][2]))
			return SendErrorMessage(playerid, "You aren't near the door.");
		
		if(BusinessInfo[b_id][E_BUSINESS_OWNERDBID] != PlayerInfo[playerid][E_CHARACTER_DBID])
			return SendErrorMessage(playerid, "You don't have the keys to this business."); 
			
		if(!BusinessInfo[b_id][E_BUSINESS_LOCKED])
		{
			GameTextForPlayer(playerid, "~w~DOOR ~r~LOCKED", 1000, 3);
			PlayerPlaySound(playerid, 1052, 0.0, 0.0, 0.0);
			
			BusinessInfo[b_id][E_BUSINESS_LOCKED] = true;
		}
		else
		{
			GameTextForPlayer(playerid, "~w~DOOR ~g~UNLOCKED", 1000, 3);
			PlayerPlaySound(playerid, 1052, 0.0, 0.0, 0.0);
			
			BusinessInfo[b_id][E_BUSINESS_LOCKED] = false;
		}
	}
	return 1;
}

//Emote commands:
static SendPlayerMeAction(playerid, text[144], bool:islow=false)
{
	new logString[150];
	new Float: range = 15.0, color = COLOR_EMOTE;
	if(islow) {
		range = 30.0;
		color = COLOR_EMOTE_LOW;
	}

	format(logString, sizeof(logString), "%s", text);
	ProxDetectorEx(playerid, range, color, "*", logString);
	return true ;
}

static SendPlayerDoAction(playerid, text[144], bool:islow=false)
{
	new Float: range = 15.0, color = COLOR_EMOTE;
	if(islow) {
		range = 30.0;
		color = COLOR_EMOTE_LOW;
	}

	ProxDetectorEx(playerid, range, color, "*", text, .inverted = true);
	return true ;
}

CMD:me(playerid, params[]) 
{

	new text[144], bool:quiet = PlayerInfo[playerid][E_CHARACTER_PRISON] > 0;

	if(sscanf(params, "s[144]", text)) 
		return SendUsageMessage(playerid, "/me [text]");

	SendPlayerMeAction(playerid, text, quiet);
	return 1;
}

CMD:melow(playerid, params[]) 
{

	new text[144];

	if(sscanf(params, "s[144]", text)) 
		return SendUsageMessage(playerid, "/melow [text]") ;

	SendPlayerMeAction(playerid, text, true);
	return 1;
}

CMD:mel(playerid, params[]) return cmd_melow(playerid, params);


CMD:do(playerid, params[]) 
{

	new text[144], bool:quiet = PlayerInfo[playerid][E_CHARACTER_PRISON] > 0;

	if(sscanf(params, "s[144]", text)) 
		return SendUsageMessage(playerid, "/do [text]");

	SendPlayerDoAction(playerid, text, quiet);
	return 1;
}

CMD:ado(playerid, params[])
{
	new Float:radius, text[144], string[150];
	if(sscanf(params, "fs[144]", radius, text)) 
		return SendUsageMessage(playerid, "/ado [radius] [text]") ;

	format(string, sizeof(string), "* %s", text);
	ProxDetectorEx(playerid, radius, COLOR_EMOTE, "*", text, .inverted = true);
	return 1;
}

CMD:dolow(playerid, params[]) {

	new text[144];

	if(sscanf(params, "s[144]", text)) 
		return SendUsageMessage(playerid, "/dolow [text]") ;

	SendPlayerDoAction(playerid, text, true);
	return 1;
}

CMD:dol(playerid, params[]) return cmd_dolow(playerid, params);

CMD:ame(playerid, params[]) 
{
	new text [144];

	if(sscanf(params, "s[144]", text))
		return SendUsageMessage(playerid, "/ame [text]");

	new string[150], str[150];
	format(string, sizeof(string), "> %s", text);
	SetPlayerChatBubble(playerid, string, COLOR_EMOTE, 20.0, 3000 + (strlen(text) * 60));

	format(str, sizeof(str), "> * %s %s", ReturnSettingsName(playerid, playerid), text);
	SendClientMessage(playerid, COLOR_EMOTE, str);
	return 1;
}

CMD:my(playerid, params[]) {

	new text[144];

	if (sscanf(params, "s[144]", text))
		return SendUsageMessage(playerid, "/my [text]") ;
    
	new string[256];
	format(string, sizeof(string), "'s %s", text);
	ProxDetectorEx(playerid, 30.0, COLOR_EMOTE, "*", string, .autospacing=false);
	return 1;
}

CMD:s(playerid, params[]) return cmd_shout(playerid, params);
CMD:shout(playerid, params[]) 
{
	new text[144];

	if (sscanf(params, "s[144]", text)) {

		return SendUsageMessage(playerid, "/shout [text]" ) ;
	}

	new Float:range = 30.0;

	if(PlayerInfo[playerid][E_CHARACTER_PRISON]) range = 15.0;

	new string[256];
	format(string, sizeof(string), "shouts: %s", text);
	ProxDetectorEx(playerid, range, 0xFCE7AEFF, "", string, .showtagcolor=true, .annonated=true); 

	format(string, sizeof (string), "%s shouts: %s", ReturnMixedName(playerid), text ) ;
	//SendMoleMessage(playerid, string);
	return 1;
}
CMD:l(playerid, params[]) return cmd_low(playerid, params);

CMD:low(playerid, params[]) 
{
	new text [ 144 ] ;
	if (sscanf (params, "s[144]", text))
		return SendUsageMessage(playerid, "/low [text]" ) ;
	
	new string [256];

	if (IsPlayerInAnyVehicle(playerid) && IsWindowedVehicle(GetPlayerVehicleID(playerid))) 
	{
		new vehicleid = GetPlayerVehicleID(playerid);

		if ( vehicleid != -1 ) {
			if (VehicleInfo[vehicleid][E_VEHICLE_WINDOWS]) {

				foreach(new targetid: Player) 
				{
					if (GetPlayerVehicleID(targetid) == GetPlayerVehicleID (playerid) ) {

						format(string, sizeof(string), "(Windows Closed) %s says [low]: %s", ReturnSettingsName(playerid, targetid, true), text);
						SendClientMessageEx(targetid, 0xDEDEDEFF, string);
					}
				}
			}
			
			else if (!VehicleInfo[vehicleid][E_VEHICLE_WINDOWS]) {// down
				format(string, sizeof(string), "says [low]: %s", text);
				ProxDetectorEx(playerid, 5.0, 0xA3A3A3FF, "(Windows Open)", string, .showtagcolor=true, .annonated=true); 
			}
		}
	}
	else 
	{

		format(string, sizeof(string), "says [low]: %s", text);
		ProxDetectorEx(playerid, 5.0, 0xA3A3A3FF, "", string, .showtagcolor=true); 
	}

	ChatAnimation(playerid, strlen(text));
	//SendMoleMessage(playerid, string);
	return 1;
}

CMD:to(playerid, params[]) 
{
	new userid, text[144];

	if (sscanf(params, "k<player>s[128]", userid, text))
		return SendUsageMessage(playerid, "/to [id] [text]" ) ;

	if (!IsPlayerConnected(userid))
		return SendErrorMessage(playerid, "Player isn't connected." ) ;


	new Float: pos_x, Float: pos_y, Float: pos_z ;
	GetPlayerPos (userid, pos_x, pos_y, pos_z ) ;

	if (!IsPlayerInRangeOfPoint(playerid, 15.0, pos_x, pos_y, pos_z) || GetPlayerInterior(userid) != GetPlayerInterior(playerid) || GetPlayerVirtualWorld(userid) != GetPlayerVirtualWorld(playerid)) {
		return SendErrorMessage(playerid, "You're not near the player you're trying to talk to!" ) ;
	}

	if(!GetPlayerPos (playerid, pos_x, pos_y, pos_z )) return 0;

	new prox[256];
	new Float: max_range = 15.0;
	new color = 0xDEDEDEFF;
	
	new vehicleid = GetPlayerVehicleID(playerid);
	if (vehicleid && IsPlayerInAnyVehicle(playerid) && IsWindowedVehicle(vehicleid)) 
	{
		if (vehicleid != INVALID_VEHICLE_ID ) {
			if (VehicleInfo[vehicleid][E_VEHICLE_WINDOWS]) {// up

				foreach(new targetid: Player) {
					if ( GetPlayerVehicleID(targetid) == GetPlayerVehicleID ( playerid ) ) {

						if(playerid == userid) {
							format ( prox, sizeof ( prox ), "(Windows Closed) %s{DEDEDE} says (to self): %s",  ReturnSettingsName(playerid, targetid, true), text ) ;
						} 
						else format ( prox, sizeof ( prox ), "(Windows Closed) %s{DEDEDE} says (to %s{DEDEDE}): %s",  ReturnSettingsName(playerid, targetid, true), ReturnSettingsName(userid, targetid, true), text ) ;
		
						SendClientMessageEx(targetid, 0xDEDEDEFF, prox);
						
					}
				}
			}		
			else if (!VehicleInfo[vehicleid][E_VEHICLE_WINDOWS]) {// down
			
				new Float:range, Float:range_ratio, Float:max_ratio = 1.6, Float:range_with_ratio = (max_range * max_ratio), final_color;
				new clr_r, clr_g, clr_b, Float:color_r = float(color >> 24 & 0xFF), Float:color_g = float(color >> 16 & 0xFF), Float:color_b = float(color >> 8 & 0xFF);

				foreach(new i: Player) {
					range = GetPlayerDistanceFromPoint(i, pos_x, pos_y, pos_z);

					if (range > max_range) {
						continue ;
					}

					if(GetPlayerInterior(i) != GetPlayerInterior(playerid) || GetPlayerVirtualWorld(i) != GetPlayerVirtualWorld(playerid))
						continue;

					range_ratio = (range_with_ratio - range) / range_with_ratio;
					clr_r = floatround(range_ratio * color_r);
					clr_g = floatround(range_ratio * color_g);
					clr_b = floatround(range_ratio * color_b);
					final_color = (color & 0xFF) | (clr_b << 8) | (clr_g << 16) | (clr_r << 24);
								
					if(playerid == userid) {
						format(prox, sizeof(prox), "(Windows Open) %s{%06x} says (to self): %s", ReturnSettingsName(playerid, i, true), (final_color >>> 8), text);
					} 
					else format(prox, sizeof(prox), "(Windows Open) %s{%06x} says (to %s{%06x}): %s", ReturnSettingsName(playerid, i, true), (final_color >>> 8), ReturnSettingsName(userid, i, true), (final_color >>> 8), text);

					SendClientMessageEx(i, final_color, prox);

					format(prox, sizeof(prox), "says: %s", text);
					SetPlayerChatBubble(playerid, prox, color, 7.5, 5000);
				}
    		}
		}
	} 
	else 
	{
		if (PlayerInfo[playerid][E_CHARACTER_PRISON]) max_range = 7.5;
		else if ( GetPlayerVirtualWorld(playerid) != 0 ) max_range = 10.0;

		new Float:range, Float:range_ratio, Float:max_ratio = 1.6, Float:range_with_ratio = (max_range * max_ratio), final_color;
		new clr_r, clr_g, clr_b, Float:color_r = float(color >> 24 & 0xFF), Float:color_g = float(color >> 16 & 0xFF), Float:color_b = float(color >> 8 & 0xFF);

		foreach(new i: Player) {

			range = GetPlayerDistanceFromPoint(i, pos_x, pos_y, pos_z);

			if (range > max_range) {
				continue ;
			}

			if(GetPlayerInterior(i) != GetPlayerInterior(playerid) || GetPlayerVirtualWorld(i) != GetPlayerVirtualWorld(playerid))
				continue;

			range_ratio = (range_with_ratio - range) / range_with_ratio;
			clr_r = floatround(range_ratio * color_r);
			clr_g = floatround(range_ratio * color_g);
			clr_b = floatround(range_ratio * color_b);
			final_color = (color & 0xFF) | (clr_b << 8) | (clr_g << 16) | (clr_r << 24);
								
			if(playerid == userid) 
			{
				format(prox, sizeof(prox), "%s{%06x} says (to self): %s", ReturnSettingsName(playerid, i, true), (final_color >>> 8), text);
			} 
			else format(prox, sizeof(prox), "%s{%06x} says (to %s{%06x}): %s", ReturnSettingsName(playerid, i, true), (final_color >>> 8), ReturnSettingsName(userid, i, true), (final_color >>> 8), text);

			SendClientMessageEx(i, final_color, prox);

			format(prox, sizeof(prox), "says: %s", text);
			SetPlayerChatBubble(playerid, prox, color, 7.5, 5000);
		}
		ChatAnimation(playerid, strlen(text));
	}

	return 1;
}

CMD:whisper(playerid, params[]) 
{
	new userid, text[144];

	if (sscanf(params, "k<player>s[128]", userid, text))
		return SendUsageMessage(playerid, "/whisper [id] [text]");

	if (!IsPlayerConnected(userid))
		return SendErrorMessage(playerid, "Player isn't connected.");

	if (PlayerInfo[userid][E_CHARACTER_SPECTATE] == playerid) 
		return SendErrorMessage(playerid, "You're not near your target.");

    if ( userid == playerid )
		return SendErrorMessage(playerid, "You can't whisper yourself." ) ;

	new Float: x, Float: y, Float: z ;
	GetPlayerPos ( userid, x, y, z ) ;

	if (!IsPlayerInRangeOfPoint(playerid, 2.5, x, y, z))
		return SendErrorMessage(playerid, "You're not near the player you're trying to whisper!");
 
	new string[384];

	format(string, sizeof (string), "Whisper to %s{FFFF22}: %s", ReturnSettingsName(userid, playerid, true), text )  ;
	SendClientMessageEx(playerid, 0xFFFF22AA, string ); 

	format(string, sizeof ( string ), "%s{FFCC22} whispers: %s", ReturnSettingsName(playerid, userid, true), text )  ;
	SendClientMessageEx(userid, 0xFFCC2299, string );

	//SendMoleMessage(playerid, string);
	ProxDetectorEx(playerid, 5.0, COLOR_EMOTE, "", sprintf("mutters something to %s.", ReturnMixedName(userid)));
	return 1;
}

CMD:w(playerid, params[]){
	return cmd_whisper ( playerid, params ) ;
}

CMD:carwhisper(playerid, params[]) {

	if (!IsPlayerInAnyVehicle(playerid)) 
		return SendErrorMessage(playerid, "You aren't inside vehicle.");

	new vehicleid = GetPlayerVehicleID(playerid);
	if (!IsWindowedVehicle(vehicleid))
		return SendErrorMessage(playerid, "You are not in any vehicle with windows.");

	new text[144], string[256];

	if (sscanf(params, "s[144]", text))
		return SendUsageMessage(playerid, "/c(ar)w(hisper) [text]" ) ;

	foreach (new userid: Player) 
	{
		if ( GetPlayerVehicleID(userid) == vehicleid) 
		{

			format (string, sizeof(string), "[%s] %s {D99564}whispers: %s", ReturnVehicleName(vehicleid), ReturnSettingsName(playerid, userid, true), text);
			SendClientMessageEx(userid, 0xD9956499, string );
		}
	}

	//SendMoleMessage(playerid, string);
	ProxDetectorEx(playerid, 7.5, COLOR_EMOTE, "", "mutters something inside the vehicle.");
	return 1;
}

CMD:cw(playerid, params[]) return cmd_carwhisper ( playerid, params ) ;

static SendPlayerLocalOOC(playerid, text[144], bool:islow=false, bool:insidecar = false)
{
	new string[256];

	if (!insidecar)
	{
		if (islow)
		{
			if (PlayerInfo[playerid][E_CHARACTER_ADMINDUTY])  {
				format(string,sizeof(string), "{A3A3A3} [low]: %s ))", text);
				ProxDetectorEx(playerid, 10.0, 0xA3A3A3FF, sprintf("(( (%d){E8871B}", playerid), string, .autospacing=false); 
			}
			else {
				format ( string, sizeof ( string ), "[low]: %s ))", text ) ;
				ProxDetectorEx(playerid, 10.0, 0xA3A3A3FF, "((", string, .showid = true, .autospacing=false); 
			}
		}
		else
		{
			if (PlayerInfo[playerid][E_CHARACTER_ADMINDUTY])  {
				format(string,sizeof(string), "{A3A3A3}: %s ))", text);
				ProxDetectorEx(playerid, 10.0, 0xA3A3A3FF, sprintf("(( (%d){E8871B}", playerid), string, .autospacing=false); 
			}
			else {
				format(string, sizeof (string), ": %s ))", text);
				ProxDetectorEx(playerid, 10.0, 0xA3A3A3FF, "((", string, .showid = true, .autospacing=false); 
			}
		}
	}
	else
	{
		new vehicleid = GetPlayerVehicleID(playerid);
		foreach(new targetid: Player) 
		{
			if (GetPlayerVehicleID(targetid) == vehicleid)
			{
				if (PlayerInfo[playerid][E_CHARACTER_ADMINDUTY]) format ( string, sizeof ( string ), "(( [%s] (%d) %s{A3A3A3}: %s ))", ReturnVehicleName(vehicleid), playerid, ReturnSettingsName(playerid, targetid), text );
				else format ( string, sizeof ( string ), "(( [%s] (%d) %s: %s ))", ReturnVehicleName(vehicleid), playerid, ReturnSettingsName(playerid, targetid), text ) ;

				SendClientMessageEx(targetid, 0xA3A3A3FF, string);
			}
		}
	}

	return 1;
}

CMD:b(playerid, params[]) {

	new text[144], bool:quiet = PlayerInfo[playerid][E_CHARACTER_PRISON] > 0;

	if ( sscanf ( params, "s[144]", text ) ) 
		return SendUsageMessage(playerid, "/b [text]");

	SendPlayerLocalOOC(playerid, text, quiet);
	return 1;
}

CMD:blow(playerid, params[]) {

	new text[144];

	if ( sscanf ( params, "s[144]", text ) ) 
		return SendUsageMessage(playerid, "/blow [text]" ) ;

	SendPlayerLocalOOC(playerid, text, true);
	return 1;
}

CMD:bl(playerid, params[])
{
	return cmd_blow(playerid, params);
}

CMD:carb(playerid, params[]) {

	new text[144];

	if (sscanf(params, "s[144]", text)) 
		return SendUsageMessage(playerid, "/carb [text]" ) ;

	if (!IsPlayerInAnyVehicle(playerid))
		return SendErrorMessage(playerid, "You must be in a vehicle to use this chat.");

	SendPlayerLocalOOC(playerid, text, false, .insidecar = true);
	return 1;
}

CMD:cb(playerid, params[]) return cmd_carb(playerid, params);

CMD:pm(playerid, params[])
{
	new
		playerb,
		text[144]
	;
		
	if(sscanf(params, "us[144]", playerb, text))
		return SendUsageMessage(playerid, "/pm [playerid OR name] [text]");
		
	if(!IsPlayerConnected(playerb))
		return SendErrorMessage(playerid, "The player you specified isn't connected.");

	if(PlayerInfo[playerid][E_CHARACTER_TOGPMS] == true)
		return SendErrorMessage(playerid, "You must enable Private Messages at /settings.");

	if(PlayerInfo[playerb][E_CHARACTER_TOGPMS] == true)
		return SendErrorMessage(playerid, "The player you specified has blocking private messages.");
		
	if(PlayerInfo[playerid][E_CHARACTER_ADMINDUTY])
	{
		SendClientMessageEx(playerb, COLOR_PMRECEIVED, "(( PM from {FF9900}%s{FFDC18} (ID: %d): %s ))", ReturnSettingsName(playerid, playerid), playerid, text); 
		
		if(!PlayerInfo[playerb][E_CHARACTER_ADMINDUTY])
			SendClientMessageEx(playerid, COLOR_PMSENT, "(( PM sent to %s (ID: %d): %s ))", ReturnSettingsName(playerb, playerid), playerb, text); 
			
		else SendClientMessageEx(playerid, COLOR_PMSENT, "(( PM sent to {FF9900}%s{EEE854} (ID: %d): %s ))", ReturnSettingsName(playerb, playerid), playerb, text); 
	}
	else
	{
		if(PlayerInfo[playerb][E_CHARACTER_ADMINDUTY])
		{
			SendClientMessageEx(playerb, COLOR_PMRECEIVED, "(( PM from %s (ID: %d): %s ))", ReturnSettingsName(playerid, playerid), playerid, text); 
			SendClientMessageEx(playerid, COLOR_PMSENT, "(( PM sent to {FF9900}%s{EEE854} (ID: %d): %s ))", ReturnSettingsName(playerb, playerid), playerb, text); 
		}
		else
		{
			SendClientMessageEx(playerb, COLOR_PMRECEIVED, "(( PM from %s (ID: %d): %s ))", ReturnSettingsName(playerid, playerid), playerid, text); 
			SendClientMessageEx(playerid, COLOR_PMSENT, "(( PM sent to %s (ID: %d): %s ))", ReturnSettingsName(playerb, playerid), playerb, text); 
		}
	}
	return 1;
}

//Business commands:
CMD:buybiz(playerid, params[])
{
	new
		id
	; 
	
	if((id = IsPlayerNearBusiness(playerid)) != 0)
	{
		if(CountPlayerBusiness(playerid) == 1)
			return SendErrorMessage(playerid, "You can't own more than 1 business."); 
			
		if(BusinessInfo[id][E_BUSINESS_OWNERDBID])
			return SendErrorMessage(playerid, "This business isn't for sale."); 

		if(BusinessInfo[id][E_BUSINESS_TYPE] == BUSINESS_TYPE_BANK || BusinessInfo[id][E_BUSINESS_TYPE] == BUSINESS_TYPE_DMV || BusinessInfo[id][E_BUSINESS_TYPE] == BUSINESS_TYPE_DEALERSHIP || BusinessInfo[id][E_BUSINESS_TYPE] == BUSINESS_TYPE_HAIRCUT
		|| BusinessInfo[id][E_BUSINESS_TYPE] == BUSINESS_TYPE_GUNSTORE || BusinessInfo[id][E_BUSINESS_TYPE] == BUSINESS_TYPE_ACID)
			return SendErrorMessage(playerid, "This property isn't for sale."); 
			
		if(PlayerInfo[playerid][E_CHARACTER_LEVEL] < BusinessInfo[id][E_BUSINESS_LEVEL])
			return SendErrorMessage(playerid, "You need to be level %i to buy this.", BusinessInfo[id][E_BUSINESS_LEVEL]);
			
		if(PlayerInfo[playerid][E_CHARACTER_MONEY] < BusinessInfo[id][E_BUSINESS_PRICE])
			return SendErrorMessage(playerid, "You can't afford this business."); 
			
		PlayerPlaySound(playerid, 1052, 0.0, 0.0, 0.0);
		ShowBoxMessage(playerid, "Congratulations!~n~You're now the owner of this business!", 4);
		
		SendInfoMessage(playerid, "You purchased the %s for {5B9460}$%s{ffffff}!", BusinessInfo[id][E_BUSINESS_NAME], FormatMoney(BusinessInfo[id][E_BUSINESS_PRICE]));
		
		BusinessInfo[id][E_BUSINESS_OWNERDBID] = PlayerInfo[playerid][E_CHARACTER_DBID]; 
		GiveMoney(playerid, -BusinessInfo[id][E_BUSINESS_PRICE]); 
		
		SaveBusiness(id); SaveCharacter(playerid); 
	}
	else return SendErrorMessage(playerid, "You aren't near a business.");

	return 1;
}

CMD:bizinfo(playerid, params[])
{
	if(!CountPlayerBusiness(playerid))
		return SendErrorMessage(playerid, "You don't own a business.");
		
	new
		id
	;
	
	if((id = IsPlayerInBusiness(playerid)) != 0)
	{
		if(BusinessInfo[id][E_BUSINESS_OWNERDBID] != PlayerInfo[playerid][E_CHARACTER_DBID])
			return SendErrorMessage(playerid, "You don't own this business."); 
			
		SendClientMessage(playerid, COLOR_HEADER, "Business Info");
		SendClientMessageEx(playerid, COLOR_WHITE, "*** %s ***", BusinessInfo[id][E_BUSINESS_NAME]); 
		SendClientMessageEx(playerid, COLOR_GREY, "Owner:[%s] Level:[%d] Value:[{5B9460}$%s{ffffff}] Type:[%d] Locked:[%s] ID:[%d]", ReturnSettingsName(playerid, playerid), BusinessInfo[id][E_BUSINESS_LEVEL], FormatMoney(BusinessInfo[id][E_BUSINESS_PRICE]),
			BusinessInfo[id][E_BUSINESS_TYPE], (BusinessInfo[id][E_BUSINESS_LOCKED] != true) ? ("No") : ("Yes"), BusinessInfo[id][E_BUSINESS_DBID]); 
		SendClientMessageEx(playerid, COLOR_WHITE, "Cashbox:[{5B9460}$%s{ffffff}] Entrance fee:[{5B9460}$%s{ffffff}] Products:[%d / %d]", FormatMoney(BusinessInfo[id][E_BUSINESS_CASH]), FormatMoney(BusinessInfo[id][E_BUSINESS_ENTRANCEFEE]), BusinessInfo[id][E_BUSINESS_STOCK], MAX_BUSINESS_PRODUCTS);		
	}
	else return SendErrorMessage(playerid, "You aren't in a business.");

	return 1;
}

CMD:bizfee(playerid, params[])
{
	if(!CountPlayerBusiness(playerid))
		return SendErrorMessage(playerid, "You don't own a business.");
		
	new
		id,
		amount
	;
	
	if((id = IsPlayerInBusiness(playerid)) != 0)
	{
		if(BusinessInfo[id][E_BUSINESS_OWNERDBID] != PlayerInfo[playerid][E_CHARACTER_DBID])
			return SendErrorMessage(playerid, "You don't own this business."); 
			
		if(sscanf(params, "i", amount))
			return SendUsageMessage(playerid, "/bizfee [amount]"); 
			
		if(amount > 1500)
			return SendErrorMessage(playerid, "The amount can't be above $1,500.");
			
		SendInfoMessage(playerid, "You set your businesses entrance fee to {5B9460}$%s{ffffff}.", FormatMoney(amount));
		
		BusinessInfo[id][E_BUSINESS_ENTRANCEFEE] = amount;
		SaveBusiness(id);
	}
	else return SendErrorMessage(playerid, "You aren't in a business."); 
	return 1;
}

CMD:bizcash(playerid, params[])
{
	if(!CountPlayerBusiness(playerid))
		return SendErrorMessage(playerid, "You don't own a business.");
		
	new
		id,
		amount,
		astr[30],
		bstr[30]
	;
	
	if((id = IsPlayerInBusiness(playerid)) != 0)
	{
		if(BusinessInfo[id][E_BUSINESS_OWNERDBID] != PlayerInfo[playerid][E_CHARACTER_DBID])
			return SendErrorMessage(playerid, "You don't own this business."); 
			
		if(sscanf(params, "s[30]S()[30]", astr, bstr))
			return SendUsageMessage(playerid, "/bizcash [balance, deposit, withdraw]"); 
			
		if(!strcmp(astr, "balance"))
		{
			SendInfoMessage(playerid, "You have {5B9460}$%s{ffffff} in your businesses cashbox.", FormatMoney(BusinessInfo[id][E_BUSINESS_CASH])); 
		}
		else if(!strcmp(astr, "deposit"))
		{	
			if(sscanf(bstr, "i", amount))
				return SendUsageMessage(playerid, "/bizcash deposit [amount]"); 
				
			if(amount > PlayerInfo[playerid][E_CHARACTER_MONEY])
				return SendErrorMessage(playerid, "You don't have that much money.");
				
			BusinessInfo[id][E_BUSINESS_CASH]+= amount;
			GiveMoney(playerid, -amount);
			
			SendInfoMessage(playerid, "You deposited {5B9460}$%s{ffffff} into your business. (Total: {5B9460}$%s{ffffff})", FormatMoney(amount), FormatMoney(BusinessInfo[id][E_BUSINESS_CASH]));
			SaveBusiness(id); SaveCharacter(playerid);
		}
		else if(!strcmp(astr, "withdraw"))
		{	
			if(sscanf(bstr, "i", amount))
				return SendUsageMessage(playerid, "/bizcash deposit [amount]"); 
			
			if(amount > BusinessInfo[id][E_BUSINESS_CASH])
				return SendErrorMessage(playerid, "Your business doesn't have that much money.");
				
			BusinessInfo[id][E_BUSINESS_CASH] -= amount; 
			GiveMoney(playerid, amount); 
			
			SendInfoMessage(playerid, "You withdrew {5B9460}$%s{ffffff} from your business. (Total: {5B9460}$%s{ffffff})", FormatMoney(amount), FormatMoney(BusinessInfo[id][E_BUSINESS_CASH]));
			SaveBusiness(id); SaveCharacter(playerid);
		}
		else return SendErrorMessage(playerid, "Invalid Parameter.");
	}
	else return SendErrorMessage(playerid, "You aren't in a business."); 
	return 1;
}

CMD:sellbiz(playerid, params[])
{
	new
		id,
		str[128]
	;
	
	if(!CountPlayerBusiness(playerid))
		return SendErrorMessage(playerid, "You don't own a business.");
		
	if((id = IsPlayerInBusiness(playerid)) != 0)
	{
		if(BusinessInfo[id][E_BUSINESS_OWNERDBID] != PlayerInfo[playerid][E_CHARACTER_DBID])
			return SendErrorMessage(playerid, "You don't own this business."); 
			
		format(str, sizeof(str), "Are you sure you want to sell your business?\nYou'll earn {5B9460}$%s{ffffff} from selling and {5B9460}$%s{ffffff} from the cashbox.", FormatMoney(BusinessInfo[id][E_BUSINESS_PRICE] / 2), FormatMoney(BusinessInfo[id][E_BUSINESS_CASH]));
		ConfirmDialog(playerid, "Confirmation", str, "OnSellBusiness", id); 
	}
	else return SendErrorMessage(playerid, "You aren't in a business.");
	return 1;
}

CMD:cc(playerid, params[])return cmd_clearchat(playerid, params);
CMD:clearchat(playerid, params[])
{
	for (new i = 0; i < 20; i++){SendClientMessage(playerid, -1, " "); }
	return 1;
}

CMD:aoe(playerid, params[]) return cmd_accessories(playerid, "");
CMD:accessories(playerid, params[])
{
	if(IsPlayerInAnyVehicle(playerid)) 
		return SendErrorMessage(playerid, "This command can only be used on foot, exit your vehicle!");

	new string[350];
	format(string, sizeof(string), "ID\tModel\tBone\n");
	forex(i, 4)
	{
		if(pToys[playerid][i][E_TOY_MODEL] != 0)
		{
			format(string, sizeof(string), "%s{FFFFFF}#%d\t%d\t%s\n", string, i, pToys[playerid][i][E_TOY_MODEL], Bone_Name[pToys[playerid][i][E_TOY_BONE]]);
		}
		else
		{
			format(string, sizeof(string), "%s{AFAFAF}Empty Slot\n", string);
		}
	}
	ShowPlayerDialog(playerid, DIALOG_CLOTHSHOW, DIALOG_STYLE_TABLIST_HEADERS, "Accessory Menu:", string, "Select", "Close");
	SavePlayerToys(playerid);
	return 1;
}

CMD:approve(playerid, params[])
{
	if (isnull(params))
 	{
	 	SendUsageMessage(playerid, "/approve [name]");
		SendClientMessage(playerid, COLOR_WHITE, "faction, frisk, handshake");
		return 1;
	}
	if (!strcmp(params, "faction", true) /*&& PlayerInfo[playerid][E_CHARACTER_FRISKOFFER] != INVALID_PLAYER_ID*/)
	{
		if(!PlayerInfo[playerid][E_CHARACTER_FACTIONINVITE])
			return SendErrorMessage(playerid, "You aren't invited to join any faction.");

		if(PlayerInfo[playerid][E_CHARACTER_FACTION])
			return SendErrorMessage(playerid, "You're already in a faction.");

		
				
		SendClientMessageEx(PlayerInfo[playerid][E_CHARACTER_FACTIONINVITED], COLOR_FACTION, "%s accepted your faction invitation.", ReturnSettingsName(playerid, playerid));
		SendInfoMessage(playerid, "You joined the %s!", ReturnFactionNameEx(PlayerInfo[playerid][E_CHARACTER_FACTIONINVITE]));
		
		
		PlayerInfo[playerid][E_CHARACTER_FACTION] = PlayerInfo[playerid][E_CHARACTER_FACTIONINVITE]; 
		PlayerInfo[playerid][E_CHARACTER_FACTIONRANK] = 1; 
		if(PlayerInfo[playerid][E_CHARACTER_FACTION] == 3 || PlayerInfo[playerid][E_CHARACTER_FACTION] == 5 || PlayerInfo[playerid][E_CHARACTER_FACTION] == 9)
		{
			new rand = randomEx(1, 4);
			PlayerInfo[playerid][E_CHARACTER_FACTIONSUBSETS] = rand;
		}
		else if(PlayerInfo[playerid][E_CHARACTER_FACTION] == 4 || PlayerInfo[playerid][E_CHARACTER_FACTION] == 6 || PlayerInfo[playerid][E_CHARACTER_FACTION] == 7 || PlayerInfo[playerid][E_CHARACTER_FACTION] == 8 || PlayerInfo[playerid][E_CHARACTER_FACTION] == 10)
		{
			new rand = randomEx(1, 3);
			PlayerInfo[playerid][E_CHARACTER_FACTIONSUBSETS] = rand;
		}
		new thread[128];
		mysql_format(ourConnection, thread, sizeof(thread), "SELECT * FROM characters WHERE char_name = '%e'", ReturnSettingsName(playerid, playerid));
		mysql_pquery(ourConnection, thread, "RefreshNamesFunc", "i", playerid);
		
		PlayerInfo[playerid][E_CHARACTER_FACTIONINVITE] = 0;
		PlayerInfo[playerid][E_CHARACTER_FACTIONINVITED] = INVALID_PLAYER_ID;
		
		SaveCharacter(playerid);
	}
	if (!strcmp(params, "frisk", true) && PlayerInfo[playerid][E_CHARACTER_FRISKOFFER] != INVALID_PLAYER_ID)
	{
	    new
			targetid = PlayerInfo[playerid][E_CHARACTER_FRISKOFFER];

	    if (!IsPlayerNearPlayer(playerid, targetid, 6.0))
		    return SendErrorMessage(playerid, "You aren't near that player.");

		PlayerInfo[playerid][E_CHARACTER_FRISKOFFER] = INVALID_PLAYER_ID;
		ShowInventory(targetid, playerid);
	}
	if (!strcmp(params, "handshake", true) && PlayerInfo[playerid][E_CHARACTER_SHAKEOFFER] != INVALID_PLAYER_ID)
	{
	    new
	        targetid = PlayerInfo[playerid][E_CHARACTER_SHAKEOFFER],
	        type = PlayerInfo[playerid][E_CHARACTER_SHAKETYPE];

        if (!IsPlayerNearPlayer(playerid, targetid, 6.0))
		    return SendErrorMessage(playerid, "You are not near that player.");

		SetPlayerToFacePlayer(playerid, targetid);
		SetPlayerToFacePlayer(targetid, playerid);

		PlayerInfo[playerid][E_CHARACTER_SHAKEOFFER] = INVALID_PLAYER_ID;
		PlayerInfo[playerid][E_CHARACTER_SHAKETYPE] = 0;

		switch (type)
		{
		    case 1:
			{
				ApplyAnimation(playerid, "GANGS", "hndshkaa", 4.0, 0, 0, 0, 0, 0, 1);
				ApplyAnimation(targetid, "GANGS", "hndshkaa", 4.0, 0, 0, 0, 0, 0, 1);
			}
			case 2:
			{
				ApplyAnimation(playerid, "GANGS", "hndshkba", 4.0, 0, 0, 0, 0, 0, 1);
				ApplyAnimation(targetid, "GANGS", "hndshkba", 4.0, 0, 0, 0, 0, 0, 1);
			}
			case 3:
			{
				ApplyAnimation(playerid, "GANGS", "hndshkda", 4.0, 0, 0, 0, 0, 0, 1);
				ApplyAnimation(targetid, "GANGS", "hndshkda", 4.0, 0, 0, 0, 0, 0, 1);
			}
			case 4:
			{
				ApplyAnimation(playerid, "GANGS", "hndshkea", 4.0, 0, 0, 0, 0, 0, 1);
				ApplyAnimation(targetid, "GANGS", "hndshkea", 4.0, 0, 0, 0, 0, 0, 1);
			}
			case 5:
			{
				ApplyAnimation(playerid, "GANGS", "hndshkfa", 4.0, 0, 0, 0, 0, 0, 1);
				ApplyAnimation(targetid, "GANGS", "hndshkfa", 4.0, 0, 0, 0, 0, 0, 1);
			}
			case 6:
			{
			    ApplyAnimation(playerid, "GANGS", "prtial_hndshk_biz_01", 4.0, 0, 0, 0, 0, 0, 1);
			    ApplyAnimation(targetid, "GANGS", "prtial_hndshk_biz_01", 4.0, 0, 0, 0, 0, 0, 1);
			}
	    }
	    SendInfoMessage(playerid, "You've accepted %s's handshake.", ReturnSettingsName(targetid, playerid));
	    SendInfoMessage(targetid, "%s accepted your handshake.", ReturnSettingsName(playerid, playerid));
	}
	if (!strcmp(params, "vehicle", true) && PlayerInfo[playerid][E_CHARACTER_SELLOFFER] != INVALID_PLAYER_ID)
	{
		new idx;

		new userid = PlayerInfo[playerid][E_CHARACTER_SELLOFFER], price = PlayerInfo[playerid][E_CHARACTER_PRICEOFFER], vehicleid = PlayerInfo[playerid][E_CHARACTER_SELLVOFFER];
		
		for(new i = 1; i < MAX_PLAYER_VEHICLES; i++)
		{
			if(!PlayerInfo[playerid][E_CHARACTER_OWNEDVEHICLE][i])
			{
				idx = i;
				break;
			}
		}

		for(new i = 1; i < MAX_PLAYER_VEHICLES; i++)
		{
			if(!PlayerInfo[userid][E_CHARACTER_OWNEDVEHICLE][i])
			{
				idx = i;
				break;
			}
		}

		PlayerInfo[playerid][E_CHARACTER_OWNEDVEHICLE][idx] = VehicleInfo[vehicleid][E_VEHICLE_DBID];

		PlayerInfo[userid][E_CHARACTER_OWNEDVEHICLE][idx] = 0;

		VehicleInfo[vehicleid][E_VEHICLE_OWNERDBID] = PlayerInfo[playerid][E_CHARACTER_DBID];

		GiveMoney(playerid, -price);
		GiveMoney(userid, price);

		PlayerInfo[playerid][E_CHARACTER_SELLOFFER] = INVALID_PLAYER_ID;
		PlayerInfo[playerid][E_CHARACTER_PRICEOFFER] = 0;
		PlayerInfo[playerid][E_CHARACTER_SELLVOFFER] = 0;

		SaveVehicle(vehicleid);

		SendInfoMessage(playerid, "You've accepted %s's offered selling vehicle.", ReturnSettingsName(userid, playerid));
	    SendInfoMessage(userid, "%s accepted offered selling your vehicle.", ReturnSettingsName(playerid, playerid));
	}
	return 1;
}

CMD:handshake(playerid, params[])
{
	static
	    userid,
	    type;

	if (sscanf(params, "ud", userid, type))
	    return SendUsageMessage(playerid, "/handshake [playerid/name] [1-6]");

    if (userid == INVALID_PLAYER_ID || !IsPlayerNearPlayer(playerid, userid, 6.0))
	    return SendErrorMessage(playerid, "The specified player is disconnected or not near you.");

    if (userid == playerid)
		return SendErrorMessage(playerid, "You cannot shake your own hand.");

	if (type < 1 || type > 6)
	    return SendErrorMessage(playerid, "Invalid handshake type.");

	PlayerInfo[userid][E_CHARACTER_SHAKEOFFER] = playerid;
	PlayerInfo[userid][E_CHARACTER_SHAKETYPE] = type;

	SendTipMessage(userid, "%s has offered to shake your hand, type /approve handshake to approve.", ReturnSettingsName(playerid, playerid));
	SendInfoMessage(playerid, "You have offered to shake %s's hand.", ReturnSettingsName(userid, playerid));
	return 1;
}
CMD:frisk(playerid, params[])
{
	static
	    userid;

	if (sscanf(params, "u", userid))
	    return SendUsageMessage(playerid, "/frisk [playerid/name]");

    if (userid == INVALID_PLAYER_ID || !IsPlayerNearPlayer(playerid, userid, 6.0))
	    return SendErrorMessage(playerid, "The specified player is disconnected or not near you.");

    if (userid == playerid)
		return SendErrorMessage(playerid, "You cannot frisk yourself.");

	PlayerInfo[userid][E_CHARACTER_FRISKOFFER] = playerid;

	SendTipMessage(userid, "%s has offered to frisk you, type /approve frisk to approve.", ReturnSettingsName(playerid, playerid));
	SendInfoMessage(playerid, "You have offered to frisk %s.", ReturnSettingsName(userid, playerid));
	return 1;
}

CMD:afk(playerid, params[])
{
	new targetid;

	if(sscanf(params, "u", targetid))
	    return SendUsageMessage(playerid, "/afk [playerid]");

	if(!IsPlayerConnected(targetid))
	    return SendErrorMessage(playerid, "The player specified is disconnected.");

	if(PlayerInfo[targetid][E_CHARACTER_AFK])
	{
	    SendServerMessage(playerid, "AFK: {ffffff}%s has been marked as Away from keyboard for %i minutes.", ReturnSettingsName(targetid, playerid), PlayerInfo[targetid][E_CHARACTER_AFKTIME] / 60);
	}
	else
	{
	    SendServerMessage(playerid, "AFK: {ffffff}%s is currently not marked as Away from keyboard.", ReturnSettingsName(targetid, playerid));
	}

	return 1;
}

CMD:gascan(playerid, params[])
{
	if(PlayerInfo[playerid][E_CHARACTER_EQUIPITEMS] != GASCAN)
		return SendErrorMessage(playerid, "You must hold the gascan in your hands.");

	if(!Inventory_Count(playerid, "Gascan"))
		return SendErrorMessage(playerid, "You don't have any gascan in your inventory."); 

	if(IsPlayerInAnyVehicle(playerid))
		return SendErrorMessage(playerid, "You can't be in a vehicle.");
			
	if(GetNearestVehicle(playerid) == INVALID_VEHICLE_ID)
		return SendErrorMessage(playerid, "You aren't near a vehicle."); 
			
	if(playerRefillingVehicle[playerid])
		return SendErrorMessage(playerid, "You're already refilling a vehicle."); 
			
	new vehicleid = GetNearestVehicle(playerid), Float:vx, Float:vy, Float:vz;

		
	GetVehicleModelInfo(GetVehicleModel(vehicleid), VEHICLE_MODEL_INFO_PETROLCAP, vx, vy, vz); 
	GetVehiclePos(vehicleid, vx, vy, vz);
		
	GetPlayerPos(playerid, PlayerInfo[playerid][E_CHARACTER_LASTPOS][0], PlayerInfo[playerid][E_CHARACTER_LASTPOS][1], PlayerInfo[playerid][E_CHARACTER_LASTPOS][2]); 
				
	if(!IsPlayerInRangeOfPoint(playerid, 5.0, vx, vy, vz))
		return SendErrorMessage(playerid, "You aren't near the vehicles gas cap.");
			
	if(VehicleInfo[vehicleid][E_VEHICLE_FUEL] > 50)
		return SendErrorMessage(playerid, "This vehicle doesn't need fuel."); 
			
	SendInfoMessage(playerid, "You're starting to refill the vehicle.");
	SendInfoMessage(playerid, "If you, or the vehicle moves then this process will be interrupted."); 
		
	VehicleInfo[vehicleid][E_VEHICLE_REFILLDISPLAY] = Create3DTextLabel("Loading refilling fuel process\n(( |------ ))", COLOR_POINT, vx, vy, vz, 25.0, 0, 1);
	Attach3DTextLabelToVehicle(VehicleInfo[vehicleid][E_VEHICLE_REFILLDISPLAY], vehicleid, -0.0, -0.0, -0.0); 

	VehicleInfo[vehicleid][E_VEHICLE_REFILLCOUNT] = 1;
		
	playerRefillingVehicle[playerid] = true; 
	playerRefillTimer[playerid] = SetTimerEx("OnGascanRefill", 4500, true, "iifff", playerid, vehicleid, vx, vy, vz);
	return 1;
}