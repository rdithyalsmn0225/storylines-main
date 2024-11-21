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
	format(str, sizeof(str), "Streets TextDraws\t%s\n", (PlayerInfo[playerid][E_CHARACTER_TOGHUD] == false) ? ("{93C47D}ENABLE{ffffff}") : ("{FF6347}DISABLE{ffffff}"));
	format(str, sizeof(str), "%sJoined Logs\t%s\n", str, (PlayerInfo[playerid][E_CHARACTER_TOGJOIN] == false) ? ("{93C47D}ENABLE{ffffff}") : ("{FF6347}DISABLE{ffffff}"));
	format(str, sizeof(str), "%sAdmin Messages\t%s\n", str, (PlayerInfo[playerid][E_CHARACTER_TOGADMIN] == false) ? ("{93C47D}ENABLE{ffffff}") : ("{FF6347}DISABLE{ffffff}"));
	format(str, sizeof(str), "%sFaction Messages\t%s\n", str, (PlayerInfo[playerid][E_CHARACTER_TOGFMS] == false) ? ("{93C47D}ENABLE{ffffff}") : ("{FF6347}DISABLE{ffffff}"));
	format(str, sizeof(str), "%sPrivate Messages\t%s\n", str, (PlayerInfo[playerid][E_CHARACTER_TOGPMS] == false) ? ("{93C47D}ENABLE{ffffff}") : ("{FF6347}DISABLE{ffffff}"));
	format(str, sizeof(str), "%sDamages Messages\t%s\n", str, (PlayerInfo[playerid][E_CHARACTER_TOGDMS] == false) ? ("{93C47D}ENABLE{ffffff}") : ("{FF6347}DISABLE{ffffff}"));
	format(str, sizeof(str), "%sPhone Style\t%s\n", str, (PlayerInfo[playerid][E_CHARACTER_TOGPHONE] == false) ? ("{93C47D}Modern{ffffff}") : ("{FF6347}Old School{ffffff}"));
	format(str, sizeof(str), "%sDraw Distance\t%s\n", str, (PlayerInfo[playerid][E_CHARACTER_TOGDD] == false) ? ("{93C47D}LOW{ffffff}") : ("{FF6347}HIGH{ffffff}"));
	ShowPlayerDialog(playerid, DIALOG_SETTINGS, DIALOG_STYLE_TABLIST, "Settings:", str, "Select", "Close");
	return 1;
}

CMD:coin(playerid, params[])
{
    SendNearbyMessage(playerid, 20.0, COLOR_EMOTE, "* %s flips a coin and it lands on %s.", ReturnName(playerid), (random(2)) ? ("Heads") : ("Tails"));
	return true;
}

CMD:dice(playerid, params[])
{
	SendNearbyMessage(playerid, 20.0, COLOR_EMOTE, "* %s rolls a dice and it lands on %d.", ReturnName(playerid), random(6) + 1);
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
		SendClientMessage(playerid, COLOR_DARKGREEN, "|__________ Admins __________|");
		foreach(new i : Player)
		{
			if(PlayerInfo[i][E_CHARACTER_ADMIN])
			{
				if(PlayerInfo[i][E_CHARACTER_ADMINDUTY])
				{
					SendClientMessageEx(playerid, COLOR_ORANGE, "(Level: %d) %s (%s): On-Duty", PlayerInfo[i][E_CHARACTER_ADMIN], ReturnName(i, i), AccountInfo[i][E_MASTERS_FORUMNAME]);
				}
				else SendClientMessageEx(playerid, COLOR_ORANGE, "(Level: %d) %s (%s): Roleplaying", PlayerInfo[i][E_CHARACTER_ADMIN], ReturnName(i, i), AccountInfo[i][E_MASTERS_FORUMNAME]);
			}
		}
	}
	else
	{
		return SendInfoMessage(playerid, "There are no administrators online.");
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
    new playerb, str[128];
    new Float:amount;

    if (sscanf(params, "uf", playerb, amount))
        return SendUsageMessage(playerid, "/pay [playerid OR name] [amount]");

    if (!IsPlayerConnected(playerb))
        return SendErrorMessage(playerid, "The player you specified isn't connected.");
        
    if (AccountInfo[playerb][E_MASTERS_LOGGED] == false)
        return SendErrorMessage(playerid, "The player you specified isn't logged in.");
        
    if (!IsPlayerNearPlayer(playerid, playerb, 5.0))
        return SendErrorMessage(playerid, "You aren't near that player.");

    if (playerb == playerid)
        return SendErrorMessage(playerid, "You can't pay yourself.");
        
    new Cents = floatround(amount * 100, floatround_round);

    if (amount > PlayerInfo[playerid][E_CHARACTER_MONEY])
        return SendErrorMessage(playerid, "You don't have that amount of money.");

    if (amount < 0.0)
        return SendErrorMessage(playerid, "Amount must be greater than 0.0.");
        
    if (gettime() - playerLastpay[playerid] < 3)
        return SendErrorMessage(playerid, "Please wait before paying again.");
        
    PlayerPlaySound(playerid, 1052, 0.0, 0.0, 0.0); 
    PlayerPlaySound(playerb, 1052, 0.0, 0.0, 0.0);
    playerLastpay[playerid] = gettime(); 
    
    SendServerMessage(playerid, "[Pay] {cdd0d1}You have sent {93C47D}$%s{cdd0d1} to {d7d292}%s{cdd0d1}.", FormatMoney(Cents), ReturnName(playerb)); 
    SendServerMessage(playerb, "[Pay] {cdd0d1}You have received {93C47D}$%s{cdd0d1} from {d7d292}%s{cdd0d1}.", FormatMoney(Cents), ReturnName(playerid)); 
    
    if ((PlayerInfo[playerid][E_CHARACTER_LEVEL] <= 3 && PlayerInfo[playerb][E_CHARACTER_LEVEL] <= 3) || Cents >= 5000) 
    {
        format(str, sizeof(str), "%s has paid $%s to %s.", ReturnName(playerid), FormatMoney(Cents), ReturnName(playerb)); 
        SendAdminMessage(1, str);
    }
    
    GiveMoney(playerid, -Cents); 
    GiveMoney(playerb, Cents);
    return 1;
}


CMD:charity(playerid, params[])
{
	new charity;
		
	if(sscanf(params, "f", charity))
		return SendUsageMessage(playerid, "/charity [amount]");
		
	if(charity < 1 || charity > PlayerInfo[playerid][E_CHARACTER_MONEY])
		return SendErrorMessage(playerid, "You can't charity that amount."); 
	
	new Cents = floatround(charity * 100, floatround_round);

    GiveMoney(playerid, -Cents);

	SaveCharacter(playerid);
	SendServerMessage(playerid, "[Charity] {cdd0d1}You've charity {93C47D}%s{cdd0d1} for this server.", FormatMoney(Cents));
	return 1;
}

CMD:id(playerid, params[])
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
			
		SendClientMessageEx(playerid, COLOR_GREY, "(ID: %i) %s | Level: %i", playerb, ReturnName(playerb), PlayerInfo[playerb][E_CHARACTER_LEVEL]); 
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
				if(strfind(ReturnName(b, playerid), params, true) != -1)
				{
					SendClientMessageEx(playerid, COLOR_GREY, "(ID: %i) %s | Level: %i", b, ReturnName(b), PlayerInfo[b][E_CHARACTER_LEVEL]); 
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
					if(strfind(ReturnName(a), params, true) != -1)
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
					if(IsPlayerConnected(f) && strfind(ReturnName(f), params, true) != -1)
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
							
						format(string, sizeof(string), "%s(ID: %i) %s, ", string, matchesFound[l], ReturnName(matchesFound[l])); 
											
						if(l % 3 == 0 && l != 0 || l == 5-1)
						{
							SendClientMessage(playerid, COLOR_GREY, string);
							string[0] = 0;
						}
					}
				}
				else if(countMatches == 1)
				{
					SendClientMessageEx(playerid, COLOR_GREY, "(ID: %i) %s | Level: %i", matchesFound[0], ReturnName(matchesFound[0]), PlayerInfo[matchesFound[0]][E_CHARACTER_LEVEL]); 
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

	if(IsPlayerNearCashiers(playerid))
	{	
		if(BusinessInfo[id][E_BUSINESS_TYPE] != BUSINESS_TYPE_CLUB && BusinessInfo[id][E_BUSINESS_TYPE] != BUSINESS_TYPE_BAR)
			return SendErrorMessage(playerid, "You aren't in a club or bar."); 
		ShowBusinessShop(playerid, id);
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

	if(IsPlayerNearCashiers(playerid))
	{	
		if(BusinessInfo[id][E_BUSINESS_TYPE] != BUSINESS_TYPE_DINNER)
			return SendErrorMessage(playerid, "You aren't in a restaurant.");
			
		ShowBusinessShop(playerid, id);
	}
	else
	{
		return SendErrorMessage(playerid, "You aren't in a business."); 
	} 
	return 1;
}

CMD:haircut(playerid, params[])
{
	if(IsPlayerNearCashiers(playerid))
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
		Dialog_Show(playerid, Haircuts, DIALOG_STYLE_PREVIEW_MODEL, "Choose your skins:", str, "Select", "Close");
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

	if(!IsPlayerNearCashiers(playerid))
		return SendErrorMessage(playerid, "You aren't near cashiers.");
		
	if(BusinessInfo[id][E_BUSINESS_TYPE] != BUSINESS_TYPE_CLOTHES)
		return SendErrorMessage(playerid, "You aren't in a clothes.");

    ShowBusinessShop(playerid, id);
	return 1;
}

CMD:fightstyle(playerid, params[])
{
	new 
	    id = IsPlayerInBusiness(playerid);

	if(!IsPlayerNearCashiers(playerid))
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
	strcat(str, "#911\tCENTRAL\tLSPD Central Bureau Dispatch\n"); 
	strcat(str, "#931\tCW.TAC1\tLSPD Citywide TAC #1\n"); 
	strcat(str, "#932\tCW.TAC2\tLSPD Citywide TAC #2\n"); 
	strcat(str, "#933\tCW.TAC3\tLSPD Citywide TAC #3\n"); 
	strcat(str, "#977\t24.CTD\tLSPD Central Traffic Dispatch\n"); 
	strcat(str, "#978\t53.DBU\tLSPD Detective Bureau Dispatch\n"); 
	strcat(str, "#979\t54.GND\tLSPD Gang & Narcotics Division\n"); 
	strcat(str, "#981\t55.OCVD\tLSPD Organzied Crime & Vice Division\n"); 
	strcat(str, "#982\t65.METRO\tLSPD Metropolitan Dispatch\n"); 
	strcat(str, "#983\t31.IAG\tLSPD Internal Affairs\n"); 
	strcat(str, "#987\tLSC DISP\tLSSD Los Santos County Dispatch\n"); 
	strcat(str, "#912\tL-TAC 1\tLSSD Law Enforcement Tactical Channel\n"); 
	strcat(str, "#991\tDispatch\tLSFD Dispact\n"); 
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
		SendTipMessage(playerid, "/radiochannel to see LSPD Channel List"); 
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
	
	if(channel == 911 || channel == 931 || channel == 932 || channel == 933 || channel == 977 || channel == 978 || channel == 979 || 
		channel == 981 || channel == 982 || channel == 983 || channel == 987 || channel == 912 && FactionInfo[PlayerInfo[playerid][E_CHARACTER_FACTION]][E_FACTION_TYPE] != FACTION_TYPE_POLICE)
		return SendErrorMessage(playerid, "You're not authorized to use this channel."); 
	
	if(channel == 991 && FactionInfo[PlayerInfo[playerid][E_CHARACTER_FACTION]][E_FACTION_TYPE] != FACTION_TYPE_MEDICAL)
			return SendErrorMessage(playerid, "You're not authorized to use this channel."); 

	PlayerInfo[playerid][E_CHARACTER_RADIO][slot] = channel;
	
	SendInfoMessage(playerid, "You're now listening to channel {d7d292}%d{cdd0d1} under slot {d7d292}%d{cdd0d1}.", channel, slot);
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
		
	SendInfoMessage(playerid, "Your local radio slot is now {d7d292}%d{cdd0d1}.", slot); 
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
					SendClientMessageEx(i, COLOR_RADIOEX, "**[CH: %s, S: %d] %s says: %s", ReturnChannelName(PlayerInfo[i][E_CHARACTER_RADIO][r]), IsChannelSlot(i, channel), ReturnName(playerid), params);
					
				else SendClientMessageEx(i, COLOR_RADIO, "**[CH: %s, S: %d] %s says: %s", ReturnChannelName(PlayerInfo[i][E_CHARACTER_RADIO][r]), IsChannelSlot(i, channel), ReturnName(playerid), params);
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
			SendClientMessageEx(playerid, COLOR_GRAD1, "(Radio) %s says: %s", ReturnName(playerid), params);
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
					SendClientMessageEx(i, COLOR_RADIOEX, "**[CH: %d, S: %d] %s says: %s", PlayerInfo[i][E_CHARACTER_RADIO][r], IsChannelSlot(i, channel), ReturnName(playerid), params);
					
				else SendClientMessageEx(i, COLOR_RADIO, "**[CH: %d, S: %d] %s says: %s", PlayerInfo[i][E_CHARACTER_RADIO][r], IsChannelSlot(i, channel), ReturnName(playerid), params);
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
			SendClientMessageEx(playerid, COLOR_GRAD1, "(Radio) %s says[low]: %s", ReturnName(playerid), params);
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
					SendClientMessageEx(i, COLOR_RADIOEX, "**[CH: %d, S: %d] %s says: %s", PlayerInfo[i][E_CHARACTER_RADIO][r], IsChannelSlot(i, channel), ReturnName(playerid), params);
					
				else SendClientMessageEx(i, COLOR_RADIO, "**[CH: %d, S: %d] %s says: %s", PlayerInfo[i][E_CHARACTER_RADIO][r], IsChannelSlot(i, channel), ReturnName(playerid), params);
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
			SendClientMessageEx(playerid, COLOR_GRAD1, "(Radio) %s says: %s", ReturnName(playerid), params);
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
					SendClientMessageEx(i, COLOR_RADIOEX, "**[CH: %d, S: %d] %s says: %s", PlayerInfo[i][E_CHARACTER_RADIO][r], IsChannelSlot(i, channel), ReturnName(playerid), params);
					
				else SendClientMessageEx(i, COLOR_RADIO, "**[CH: %d, S: %d] %s says: %s", PlayerInfo[i][E_CHARACTER_RADIO][r], IsChannelSlot(i, channel), ReturnName(playerid), params);
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
			SendClientMessageEx(playerid, COLOR_GRAD1, "(Radio) %s says[low]: %s", ReturnName(playerid), params);
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
		SendTipMessage(playerid, "1. Hoodrats, 2. Last Position, 3. Faction");
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
		
	if(sscanf(params, "f", amount))
		return SendUsageMessage(playerid, "/deposit [deposit amount]");
		
	if(amount < 0.0 || amount > PlayerInfo[playerid][E_CHARACTER_MONEY])
		return SendErrorMessage(playerid, "You can't deposit that amount."); 
		
	new Cents = floatround(amount * 100, floatround_round);

    GiveMoney(playerid, -Cents);
	PlayerInfo[playerid][E_CHARACTER_BANK]+= Cents;
	
	SendInfoMessage(playerid, "You have deposited {93C47D}$%s{cdd0d1} into Your account, Total:{93C47D}$%s{cdd0d1}.", FormatMoney(Cents), FormatMoney(PlayerInfo[playerid][E_CHARACTER_BANK]));
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
		
	if(sscanf(params, "f", amount))
		return SendUsageMessage(playerid, "/withdraw [amount]");
		
	if(amount < 1 || amount > PlayerInfo[playerid][E_CHARACTER_BANK])
		return SendErrorMessage(playerid, "You can't withdraw that amount."); 

		
	new Cents = floatround(amount * 100, floatround_round);

    GiveMoney(playerid, Cents);
	PlayerInfo[playerid][E_CHARACTER_BANK]-= Cents;

	SendInfoMessage(playerid, "You have withdrawn {93C47D}$%s{cdd0d1} from Your account, Total:{93C47D}$%s{cdd0d1}", FormatMoney(Cents), FormatMoney(PlayerInfo[playerid][E_CHARACTER_BANK]));
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
	
	SendInfoMessage(playerid, "You have {93C47D}$%s{cdd0d1} in your bank and {93C47D}$%s{cdd0d1} in your paycheck. (%s)", FormatMoney(PlayerInfo[playerid][E_CHARACTER_BANK]), FormatMoney(PlayerInfo[playerid][E_CHARACTER_PAYCHECK]), ReturnDate());	
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
		
		if(GetPlayerSpecialAction(playerid) == SPECIAL_ACTION_USECELLPHONE){
			SetPlayerSpecialAction(playerid, SPECIAL_ACTION_STOPUSECELLPHONE);
		}
		
		if(GetPlayerSpecialAction(PlayerInfo[playerid][E_CHARACTER_PHONELINE]) == SPECIAL_ACTION_USECELLPHONE){
			SetPlayerSpecialAction(PlayerInfo[playerid][E_CHARACTER_PHONELINE], SPECIAL_ACTION_STOPUSECELLPHONE);
		}
		
		format(str, sizeof(str), "* %s puts their phone away.", ReturnName(playerid));
		SetPlayerChatBubble(playerid, str, COLOR_EMOTE, 20.0, 3000);
		
		format(str, sizeof(str), "* %s puts their phone away.", ReturnName(PlayerInfo[playerid][E_CHARACTER_PHONELINE], playerid));
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
	{
		SendUsageMessage(playerid, "/call [phone number]"); 
		SendTipMessage(playerid, "911.Emergency Service | 111.Taxi Drivers | 222.Mechanic Service");
		return 1;
	}	

	foreach(new i : Player) if(PlayerInfo[i][E_CHARACTER_PHONE] == phone_number){
			playerb = i;
	}
	
	format(str, sizeof(str), "* %s dials a number on their phone.", ReturnName(playerid));
	SetPlayerChatBubble(playerid, str, COLOR_EMOTE, 20.0, 3000);
	SendClientMessage(playerid, COLOR_EMOTE, str); 
	
	SetPlayerSpecialAction(playerid, SPECIAL_ACTION_USECELLPHONE);
	PlayerPlaySound(playerid, 3600, 0.0, 0.0, 0.0);
	
	if (!phone_number)
	    return SendErrorMessage(playerid, "The specified phone number is not in service.");

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

		SetTimerEx("SendMechanicMessage", 2000, false, "i", playerid);
	}
	if(phone_number == 222)
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
		if (playerb == playerid)
	        return SendErrorMessage(playerid, "You can't call yourself!");

		playerPhone[playerid] = SetTimerEx("OnPhoneCall", 3300, false, "ii", playerid, 4);
		return 1;
	}
	
	SendNearbyMessage(playerb, 20.0, COLOR_EMOTE, "* %s's phone begins to ring.", ReturnName(playerid)); 
	SendClientMessageEx(playerb, COLOR_GREY, "[!] To pickup the call, use /pickup. Incoming call from %i.", PlayerInfo[playerid][E_CHARACTER_PHONE]); 

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
		return SendClientMessage(playerid, COLOR_GREY, "Please Wait..."); 
		
	if(sscanf(params, "is[128]", phone_number, text))
		return SendUsageMessage(playerid, "/sms [phone number] [text]"); 
		
	foreach(new i : Player) if(PlayerInfo[i][E_CHARACTER_PHONE] == phone_number){
		playerb = i;
	}
	
	SendErrorMessage(playerid, "Your text message is being sent.");

	format(str, sizeof(str), "* %s takes out their cellphone.", ReturnName(playerid));
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
		
	format(playerSMS[playerid], 128, text);
	playerText[playerid] = SetTimerEx("OnPhoneSMS", 1500, false, "iii", playerid, 3, playerb); 
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
		SendNearbyMessage(playerid, 20.0, COLOR_EMOTE, "* %s turns their phones loudspeaker off.", ReturnName(playerid));
		PlayerInfo[playerid][E_CHARACTER_PHONESPEAKER] = false;
	}
	else
	{
		SendNearbyMessage(playerid, 20.0, COLOR_EMOTE, "* %s turns their phones loudspeaker on.", ReturnName(playerid));
		PlayerInfo[playerid][E_CHARACTER_PHONESPEAKER] = true;
	}
	
	return 1; 
}

CMD:mylicense(playerid, params[])
{
	new
		playerb;
		
	if(sscanf(params, "u", playerb))
		return SendUsageMessage(playerid, "/mylicense [playerid OR name]"); 
	
	if(!IsPlayerConnected(playerb))
		return SendErrorMessage(playerid, "You specified an invalid player.");
		
	if(AccountInfo[playerb][E_MASTERS_LOGGED] == false)
		return SendErrorMessage(playerid, "You specified a player that isn't logged in.");
		
	if(!IsPlayerNearPlayer(playerid, playerb, 5.0))
		return SendErrorMessage(playerid, "You aren't near that player."); 
		
	if(playerb != playerid)
		SendNearbyMessage(playerid, 20.0, COLOR_EMOTE, "* %s shows %s their identification card.", ReturnName(playerid), ReturnName(playerb));
		
	else SendNearbyMessage(playerid, 20.0, COLOR_EMOTE, "* %s looks at their identification card.", ReturnName(playerid));
	
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
	new Cents = floatround(500 * 100, floatround_round);

    GiveMoney(playerid, -Cents);
	
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
	
	SendClientMessage(playerid, COLOR_DARKGREEN, "|__________ Player(s) Cooldowns __________|");
	SendClientMessageEx(playerid, COLOR_ORANGE, "ADMIN JAIL : %d minutes.", PlayerInfo[playerid][E_CHARACTER_ADMINJAIL] * 60);
	SendClientMessageEx(playerid, COLOR_ORANGE, "PRISON : %d minutes.", PlayerInfo[playerid][E_CHARACTER_PRISON] * 60);
	SendClientMessageEx(playerid, COLOR_ORANGE, "MAIN JOBS : %d minutes.", PlayerInfo[playerid][E_CHARACTER_JOBSCD]);
	SendClientMessageEx(playerid, COLOR_ORANGE, "STREET CLEANER : %d minutes.", PlayerInfo[playerid][E_CHARACTER_SWEEPERCD]);
	SendClientMessageEx(playerid, COLOR_ORANGE, "GARBAGEMAN : %d minutes.", PlayerInfo[playerid][E_CHARACTER_GARBAGECD]);
	SendClientMessageEx(playerid, COLOR_ORANGE, "BUS DRIVER : %d minutes.", PlayerInfo[playerid][E_CHARACTER_BUSDRIVERCD]);
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
	new id, b_id, e_id; 

	//Enter
	if((id = IsPlayerNearProperty(playerid)) != 0)
	{
		if(PlayerInfo[playerid][E_CHARACTER_EDITINGOBJECT])
			return SendErrorMessage(playerid, "You can't leave while editing an object.");

		if(PlayerEnterTimer[playerid])
			return ShowBoxMessage(playerid, "Please wait....", 3);

		if(PropertyInfo[id][E_PROPERTY_LOCKED])
			return GameTextForPlayer(playerid, "~r~Locked", 3000, 3);
				
		PlayerInfo[playerid][E_CHARACTER_INSIDEPROP] = id;
		PlayerEnterTimer[playerid] = true;

		SetPlayerPosEx(playerid, PropertyInfo[id][E_PROPERTY_INTERIORPOS][0], PropertyInfo[id][E_PROPERTY_INTERIORPOS][1], PropertyInfo[id][E_PROPERTY_INTERIORPOS][2]);
			
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
			
		if(BusinessInfo[b_id][E_BUSINESS_TYPE] == BUSINESS_TYPE_DMV || BusinessInfo[b_id][E_BUSINESS_TYPE] == BUSINESS_TYPE_RENT)
			return GameTextForPlayer(playerid, "~r~Closed", 3000, 3); 
			
		if(BusinessInfo[b_id][E_BUSINESS_ENTRANCEFEE] > PlayerInfo[playerid][E_CHARACTER_MONEY])
			return GameTextForPlayer(playerid, "~r~You can't afford this.", 3000, 1); 
			
		if(PlayerInfo[playerid][E_CHARACTER_DBID] != BusinessInfo[b_id][E_BUSINESS_OWNERDBID] && BusinessInfo[b_id][E_BUSINESS_TYPE] != BUSINESS_TYPE_BANK)
		{
			GiveMoney(playerid, -BusinessInfo[b_id][E_BUSINESS_ENTRANCEFEE]); 
			BusinessInfo[b_id][E_BUSINESS_CASH]+= BusinessInfo[b_id][E_BUSINESS_ENTRANCEFEE]; 
		}

		if(PlayerEnterTimer[playerid])
			return ShowBoxMessage(playerid, "Please wait....", 3);

		PlayerEnterTimer[playerid] = true;

		PlayerInfo[playerid][E_CHARACTER_INSIDEBIZ] = b_id; 
		
		SetPlayerPosEx(playerid, BusinessInfo[b_id][E_BUSINESS_INTERIORPOS][0], BusinessInfo[b_id][E_BUSINESS_INTERIORPOS][1], BusinessInfo[b_id][E_BUSINESS_INTERIORPOS][2]); 
		
		SetPlayerInterior(playerid, BusinessInfo[b_id][E_BUSINESS_INTERIORPOSINTERIOR]); 
		SetPlayerVirtualWorld(playerid, BusinessInfo[b_id][E_BUSINESS_INTERIORPOSWORLD]); 
		
		TogglePlayerControllable(playerid, false);
		SetTimerEx("OnPlayerEnterBusiness", 2000, false, "ii", playerid, e_id); 

		SendBusinessType(playerid, b_id);
		return 1;
	}
	if((e_id = IsPlayerNearEntrance(playerid)) != 0)
	{
		if(PlayerInfo[playerid][E_CHARACTER_EDITINGOBJECT])
			return SendErrorMessage(playerid, "You can't leave while editing an object.");
					
		if(PlayerEnterTimer[playerid])
			return ShowBoxMessage(playerid, "Please wait....", 3);

		PlayerEnterTimer[playerid] = true;

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

		if(IsPlayerInRangeOfPoint(playerid, 3.0, PropertyInfo[id][E_PROPERTY_INTERIORPOS][0], PropertyInfo[id][E_PROPERTY_INTERIORPOS][1], PropertyInfo[id][E_PROPERTY_INTERIORPOS][2]))
		{
			SetPlayerPosEx(playerid, PropertyInfo[id][E_PROPERTY_ENTRANCEPOS][0], PropertyInfo[id][E_PROPERTY_ENTRANCEPOS][1], PropertyInfo[id][E_PROPERTY_ENTRANCEPOS][2]);
			
			SetPlayerVirtualWorld(playerid, PropertyInfo[id][E_PROPERTY_ENTRANCEWORLD]);
			SetPlayerInterior(playerid, PropertyInfo[id][E_PROPERTY_ENTRANCEINTERIOR]); 
			
			PlayerInfo[playerid][E_CHARACTER_INSIDEPROP] = 0;
		}
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

	format(str, sizeof(str), "> * %s %s", ReturnName(playerid), text);
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
	ProxDetectorEx(playerid, range, 0xFCE7AEFF, "", string, .annonated=true); 

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

						format(string, sizeof(string), "(Windows Closed) %s says [low]: %s", ReturnName(playerid), text);
						SendClientMessageEx(targetid, 0xDEDEDEFF, string);
					}
				}
			}
			
			else if (!VehicleInfo[vehicleid][E_VEHICLE_WINDOWS]) {// down
				format(string, sizeof(string), "says [low]: %s", text);
				ProxDetectorEx(playerid, 5.0, 0xA3A3A3FF, "(Windows Open)", string, .annonated=true); 
			}
		}
	}
	else 
	{

		format(string, sizeof(string), "says [low]: %s", text);
		ProxDetectorEx(playerid, 5.0, 0xA3A3A3FF, "", string); 
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
							format ( prox, sizeof ( prox ), "(Windows Closed) %s{DEDEDE} says (to self): %s",  ReturnName(playerid), text ) ;
						} 
						else format ( prox, sizeof ( prox ), "(Windows Closed) %s{DEDEDE} says (to %s{DEDEDE}): %s",  ReturnName(playerid), ReturnName(userid), text ) ;
		
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
						format(prox, sizeof(prox), "(Windows Open) %s{%06x} says (to self): %s", ReturnName(playerid), (final_color >>> 8), text);
					} 
					else format(prox, sizeof(prox), "(Windows Open) %s{%06x} says (to %s{%06x}): %s", ReturnName(playerid), (final_color >>> 8), ReturnName(userid), (final_color >>> 8), text);

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
				format(prox, sizeof(prox), "%s{%06x} says (to self): %s", ReturnName(playerid), (final_color >>> 8), text);
			} 
			else format(prox, sizeof(prox), "%s{%06x} says (to %s{%06x}): %s", ReturnName(playerid), (final_color >>> 8), ReturnName(userid), (final_color >>> 8), text);

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

	format(string, sizeof (string), "Whisper to %s{FFFF22}: %s", ReturnName(userid), text )  ;
	SendClientMessageEx(playerid, 0xFFFF22AA, string ); 

	format(string, sizeof ( string ), "%s{FFCC22} whispers: %s", ReturnName(playerid), text )  ;
	SendClientMessageEx(userid, 0xFFCC2299, string );

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

			format (string, sizeof(string), "[%s] %s {D99564}whispers: %s", ReturnVehicleName(vehicleid), ReturnName(playerid), text);
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
				if (PlayerInfo[playerid][E_CHARACTER_ADMINDUTY]) format ( string, sizeof ( string ), "(( [%s] (%d) %s{A3A3A3}: %s ))", ReturnVehicleName(vehicleid), playerid, ReturnName(playerid, targetid), text );
				else format ( string, sizeof ( string ), "(( [%s] (%d) %s: %s ))", ReturnVehicleName(vehicleid), playerid, ReturnName(playerid, targetid), text ) ;

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
		SendClientMessageEx(playerb, COLOR_PMRECEIVED, "(( PM from {FF9900}%s{FFDC18} (ID: %d): %s ))", ReturnName(playerid), playerid, text); 
		
		if(!PlayerInfo[playerb][E_CHARACTER_ADMINDUTY])
			SendClientMessageEx(playerid, COLOR_PMSENT, "(( PM sent to %s (ID: %d): %s ))", ReturnName(playerb), playerb, text); 
			
		else SendClientMessageEx(playerid, COLOR_PMSENT, "(( PM sent to {FF9900}%s{EEE854} (ID: %d): %s ))", ReturnName(playerb), playerb, text); 
	}
	else
	{
		if(PlayerInfo[playerb][E_CHARACTER_ADMINDUTY])
		{
			SendClientMessageEx(playerb, COLOR_PMRECEIVED, "(( PM from %s (ID: %d): %s ))", ReturnName(playerid), playerid, text); 
			SendClientMessageEx(playerid, COLOR_PMSENT, "(( PM sent to {FF9900}%s{EEE854} (ID: %d): %s ))", ReturnName(playerb), playerb, text); 
		}
		else
		{
			SendClientMessageEx(playerb, COLOR_PMRECEIVED, "(( PM from %s (ID: %d): %s ))", ReturnName(playerid), playerid, text); 
			SendClientMessageEx(playerid, COLOR_PMSENT, "(( PM sent to %s (ID: %d): %s ))", ReturnName(playerb), playerb, text); 
		}
	}
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
			format(string, sizeof(string), "%s[SLOT]: #%d\t%d\t%s\n", string, i, pToys[playerid][i][E_TOY_MODEL], Bone_Name[pToys[playerid][i][E_TOY_BONE]]);
		}
		else
		{
			format(string, sizeof(string), "%s[SLOT]: <EMPTY>\n", string);
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
		SendTipMessage(playerid, "Faction, Frisk, Handshake, Vehicle, Business, Property");
		return 1;
	}
	if (!strcmp(params, "faction", true) && PlayerInfo[playerid][E_CHARACTER_FACTIONINVITE] != INVALID_PLAYER_ID)
	{
		if(PlayerInfo[playerid][E_CHARACTER_FACTION])
			return SendErrorMessage(playerid, "You're already in a faction.");
		
		SendClientMessageEx(PlayerInfo[playerid][E_CHARACTER_FACTIONINVITED], COLOR_FACTION, "%s accepted your faction invitation.", ReturnName(playerid));
		SendInfoMessage(playerid, "You joined the {d7d292}%s{cdd0d1}!", ReturnFactionNameEx(PlayerInfo[playerid][E_CHARACTER_FACTIONINVITE]));
		
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
	    SendInfoMessage(playerid, "You've accepted {d7d292}%s{cdd0d1} handshake.", ReturnName(targetid));
	    SendInfoMessage(targetid, "{d7d292}%s{cdd0d1} accepted your handshake.", ReturnName(playerid));
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

		SaveVehicle(vehicleid); SaveCharacter(playerid); SaveCharacter(userid);

		SendInfoMessage(playerid, "You've accepted {d7d292}%s{cdd0d1} offered selling vehicle.", ReturnName(userid));
	    SendInfoMessage(userid, "{d7d292}%s{cdd0d1} accepted offered selling your vehicle.", ReturnName(playerid));
	}
	if (!strcmp(params, "business", true) && PlayerInfo[playerid][E_CHARACTER_BIZOFFER] != INVALID_PLAYER_ID)
	{
		new id = PlayerInfo[playerid][E_CHARACTER_BIZOFFERID], userid = PlayerInfo[playerid][E_CHARACTER_BIZOFFER];

		BusinessInfo[id][E_BUSINESS_OWNERDBID] = PlayerInfo[playerid][E_CHARACTER_DBID];

		PlayerInfo[playerid][E_CHARACTER_BIZOFFER] = INVALID_PLAYER_ID;
		PlayerInfo[playerid][E_CHARACTER_BIZOFFERID] = 0;

		PlayerPlaySound(playerid, 1052, 0.0, 0.0, 0.0);
		PlayerPlaySound(userid, 1052, 0.0, 0.0, 0.0);

		SaveBusiness(id); SaveCharacter(playerid); SaveCharacter(userid);

		SendInfoMessage(playerid, "You've accepted {d7d292}%s{cdd0d1} offered given business.", ReturnName(userid));
	    SendInfoMessage(userid, "{d7d292}%s{cdd0d1} accepted offered given your business.", ReturnName(playerid));
	}
	if (!strcmp(params, "property", true) && PlayerInfo[playerid][E_CHARACTER_PROPOFFER] != INVALID_PLAYER_ID)
	{
		new id = PlayerInfo[playerid][E_CHARACTER_PROPOFFERID], userid = PlayerInfo[playerid][E_CHARACTER_PROPOFFER];

		BusinessInfo[id][E_BUSINESS_OWNERDBID] = PlayerInfo[playerid][E_CHARACTER_DBID];

		PlayerInfo[playerid][E_CHARACTER_PROPOFFER] = INVALID_PLAYER_ID;
		PlayerInfo[playerid][E_CHARACTER_PROPOFFERID] = 0;

		PlayerPlaySound(playerid, 1052, 0.0, 0.0, 0.0);
		PlayerPlaySound(userid, 1052, 0.0, 0.0, 0.0);

		SaveProperty(id); SaveCharacter(playerid); SaveCharacter(userid);

		SendInfoMessage(playerid, "You've accepted {d7d292}%s{cdd0d1} offered given property.", ReturnName(userid));
	    SendInfoMessage(userid, "{d7d292}%s{cdd0d1} accepted offered given your property.", ReturnName(playerid));
	}
	return 1;
}

CMD:deny(playerid, params[])
{
	if (isnull(params))
 	{
	 	SendUsageMessage(playerid, "/deny [name]");
		SendTipMessage(playerid, "Faction, Frisk, Handshake, Vehicle, Business, Property");
		return 1;
	}

	if (!strcmp(params, "faction", true) && PlayerInfo[playerid][E_CHARACTER_FACTIONINVITED] != INVALID_PLAYER_ID)
	{
		new targetid = PlayerInfo[playerid][E_CHARACTER_FACTIONINVITED];

		PlayerInfo[playerid][E_CHARACTER_FACTIONINVITE] = 0;
		PlayerInfo[playerid][E_CHARACTER_FACTIONINVITED] = INVALID_PLAYER_ID;

		SendInfoMessage(playerid, "You've denied {d7d292}%s{cdd0d1} faction invite.", ReturnName(targetid));
	    SendInfoMessage(targetid, "{d7d292}%s{cdd0d1} denied your faction invite.", ReturnName(playerid));

	}
	if (!strcmp(params, "frisk", true) && PlayerInfo[playerid][E_CHARACTER_FRISKOFFER] != INVALID_PLAYER_ID)
	{
	    new targetid = PlayerInfo[playerid][E_CHARACTER_FRISKOFFER];

		PlayerInfo[playerid][E_CHARACTER_FRISKOFFER] = INVALID_PLAYER_ID;

		SendInfoMessage(playerid, "You've denied {d7d292}%s{cdd0d1} frisk.", ReturnName(targetid));
	    SendInfoMessage(targetid, "{d7d292}%s{cdd0d1} denied your frisk.", ReturnName(playerid));
		
	}
	if (!strcmp(params, "handshake", true) && PlayerInfo[playerid][E_CHARACTER_SHAKEOFFER] != INVALID_PLAYER_ID)
	{
	    new targetid = PlayerInfo[playerid][E_CHARACTER_SHAKEOFFER];

		PlayerInfo[playerid][E_CHARACTER_SHAKEOFFER] = INVALID_PLAYER_ID;
		PlayerInfo[playerid][E_CHARACTER_SHAKETYPE] = 0;

	    SendInfoMessage(playerid, "You've denied {d7d292}%s{cdd0d1} handshake.", ReturnName(targetid));
	    SendInfoMessage(targetid, "{d7d292}%s{cdd0d1} denied your handshake.", ReturnName(playerid));
	}
	if (!strcmp(params, "vehicle", true) && PlayerInfo[playerid][E_CHARACTER_SELLOFFER] != INVALID_PLAYER_ID)
	{
		new targetid = PlayerInfo[playerid][E_CHARACTER_SELLOFFER];

		PlayerInfo[playerid][E_CHARACTER_PRICEOFFER] = 0;
		PlayerInfo[playerid][E_CHARACTER_SELLVOFFER] = 0;
		PlayerInfo[playerid][E_CHARACTER_SELLOFFER] = INVALID_PLAYER_ID;

		SendInfoMessage(playerid, "You've denied {d7d292}%s{cdd0d1} offered selling vehicle.", ReturnName(targetid));
	    SendInfoMessage(targetid, "{d7d292}%s{cdd0d1} denied offered selling your vehicle.", ReturnName(playerid));
	}
	if (!strcmp(params, "business", true) && PlayerInfo[playerid][E_CHARACTER_BIZOFFER] != INVALID_PLAYER_ID)
	{
		new targetid = PlayerInfo[playerid][E_CHARACTER_BIZOFFER];

		PlayerInfo[playerid][E_CHARACTER_BIZOFFERID] = 0;
		PlayerInfo[playerid][E_CHARACTER_BIZOFFER] = INVALID_PLAYER_ID;

		SendInfoMessage(playerid, "You've denied {d7d292}%s{cdd0d1} offered given business.", ReturnName(targetid));
	    SendInfoMessage(targetid, "{d7d292}%s{cdd0d1} denied offered given your business.", ReturnName(playerid));
	}
	if (!strcmp(params, "property", true) && PlayerInfo[playerid][E_CHARACTER_PROPOFFER] != INVALID_PLAYER_ID)
	{
		new targetid = PlayerInfo[playerid][E_CHARACTER_PROPOFFER];

		PlayerInfo[playerid][E_CHARACTER_PROPOFFERID] = 0;
		PlayerInfo[playerid][E_CHARACTER_PROPOFFER] = INVALID_PLAYER_ID;

		SendInfoMessage(playerid, "You've denied {d7d292}%s{cdd0d1} offered given property.", ReturnName(targetid));
	    SendInfoMessage(targetid, "{d7d292}%s{cdd0d1} denied offered given your property.", ReturnName(playerid));
	}
	return 1;
}

CMD:handshake(playerid, params[])
{
	new
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

	SendTipMessage(userid, "{d7d292}%s{cdd0d1} has offered to shake your hand, type /approve handshake to approve.", ReturnName(playerid));
	SendInfoMessage(playerid, "You have offered to shake {d7d292}%s{cdd0d1} hand.", ReturnName(userid));
	return 1;
}

CMD:frisk(playerid, params[])
{
	new
	    userid;

	if (sscanf(params, "u", userid))
	    return SendUsageMessage(playerid, "/frisk [playerid/name]");

    if (userid == INVALID_PLAYER_ID || !IsPlayerNearPlayer(playerid, userid, 6.0))
	    return SendErrorMessage(playerid, "The specified player is disconnected or not near you.");

    if (userid == playerid)
		return SendErrorMessage(playerid, "You cannot frisk yourself.");

	PlayerInfo[userid][E_CHARACTER_FRISKOFFER] = playerid;

	SendTipMessage(userid, "{d7d292}%s{cdd0d1} has offered to frisk you, type /approve frisk to approve.", ReturnName(playerid));
	SendInfoMessage(playerid, "You have offered to frisk {d7d292}%s{cdd0d1}.", ReturnName(userid, playerid));
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
	    SendServerMessage(playerid, "[Afk] {cdd0d1}{d7d292}%s{cdd0d1} has been marked as Away from keyboard for {d7d292}%i{cdd0d1} minutes.", ReturnName(targetid), PlayerInfo[targetid][E_CHARACTER_AFKTIME] / 60);
	}
	else
	{
	    SendServerMessage(playerid, "[Afk] {cdd0d1}{d7d292}%s{cdd0d1} is currently not marked as Away from keyboard.", ReturnName(targetid));
	}

	return 1;
}