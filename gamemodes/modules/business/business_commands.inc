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
		
		SendInfoMessage(playerid, "You purchased the %s for {B3C99E}$%s{cdd0d1}!", BusinessInfo[id][E_BUSINESS_NAME], FormatMoney(BusinessInfo[id][E_BUSINESS_PRICE]));
		
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
			
		SendClientMessage(playerid, COLOR_DARKGREEN, "|__________ Business Info __________|");
		SendClientMessageEx(playerid, COLOR_ORANGE, "*** %s ***", BusinessInfo[id][E_BUSINESS_NAME]); 
		SendClientMessageEx(playerid, COLOR_ORANGE, "Owner:[%s] Level:[%d] Value:[$%s] Type:[%d] Locked:[%s] ID:[%d]", ReturnSettingsName(playerid, playerid), BusinessInfo[id][E_BUSINESS_LEVEL], FormatMoney(BusinessInfo[id][E_BUSINESS_PRICE]),
			BusinessInfo[id][E_BUSINESS_TYPE], (BusinessInfo[id][E_BUSINESS_LOCKED] != true) ? ("No") : ("Yes"), BusinessInfo[id][E_BUSINESS_DBID]); 
		SendClientMessageEx(playerid, COLOR_ORANGE, "Cashbox:[$%s] Entrance fee:[$%s] Products:[%d / %d]", FormatMoney(BusinessInfo[id][E_BUSINESS_CASH]), FormatMoney(BusinessInfo[id][E_BUSINESS_ENTRANCEFEE]), BusinessInfo[id][E_BUSINESS_STOCK], MAX_BUSINESS_PRODUCTS);		
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
			
		SendInfoMessage(playerid, "You set your businesses entrance fee to {B3C99E}$%s{cdd0d1}.", FormatMoney(amount));
		
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
			SendInfoMessage(playerid, "You have {B3C99E}$%s{cdd0d1} in your businesses cashbox.", FormatMoney(BusinessInfo[id][E_BUSINESS_CASH])); 
		}
		else if(!strcmp(astr, "deposit"))
		{	
			if(sscanf(bstr, "i", amount))
				return SendUsageMessage(playerid, "/bizcash deposit [amount]"); 
				
			if(amount > PlayerInfo[playerid][E_CHARACTER_MONEY])
				return SendErrorMessage(playerid, "You don't have that much money.");
				
			BusinessInfo[id][E_BUSINESS_CASH]+= amount;
			GiveMoney(playerid, -amount);
			
			SendInfoMessage(playerid, "You deposited {B3C99E}$%s{cdd0d1} into your business. (Total: {B3C99E}$%s{cdd0d1})", FormatMoney(amount), FormatMoney(BusinessInfo[id][E_BUSINESS_CASH]));
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
			
			SendInfoMessage(playerid, "You withdrew {B3C99E}$%s{cdd0d1} from your business. (Total: {B3C99E}$%s{cdd0d1})", FormatMoney(amount), FormatMoney(BusinessInfo[id][E_BUSINESS_CASH]));
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
			
		format(str, sizeof(str), "Are you sure you want to sell your business?\nYou'll earn {B3C99E}$%s{ffffff} from selling and {B3C99E}$%s{ffffff} from the cashbox.", FormatMoney(BusinessInfo[id][E_BUSINESS_PRICE] / 2), FormatMoney(BusinessInfo[id][E_BUSINESS_CASH]));
		ConfirmDialog(playerid, "Confirmation", str, "OnSellBusiness", id); 
	}
	else return SendErrorMessage(playerid, "You aren't in a business.");
	return 1;
}