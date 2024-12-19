//Business commands:
CMD:buybiz(playerid, params[])
{
	new
		id
	; 
	
	if((id = IsPlayerNearBusiness(playerid)) != 0)
	{
		new maxBusinesses = AccountInfo[playerid][E_MASTERS_VIP] ? 2 : 1;

		if(CountPlayerBusiness(playerid) >= maxBusinesses)
			return SendErrorMessage(playerid, "You can't own more than %d business(es).", maxBusinesses);
			
		if(BusinessInfo[id][E_BUSINESS_OWNERDBID])
			return SendErrorMessage(playerid, "This business isn't for sale."); 

		if(BusinessInfo[id][E_BUSINESS_TYPE] == BUSINESS_TYPE_BANK || BusinessInfo[id][E_BUSINESS_TYPE] == BUSINESS_TYPE_DMV || BusinessInfo[id][E_BUSINESS_TYPE] == BUSINESS_TYPE_AMMUNATION || BusinessInfo[id][E_BUSINESS_TYPE] == BUSINESS_TYPE_HAIRCUT
		|| BusinessInfo[id][E_BUSINESS_TYPE] == BUSINESS_TYPE_GUNSTORE || BusinessInfo[id][E_BUSINESS_TYPE] == BUSINESS_TYPE_ACID || BusinessInfo[id][E_BUSINESS_TYPE] == BUSINESS_TYPE_RENT)
			return SendErrorMessage(playerid, "This property isn't for sale."); 
			
		if(PlayerInfo[playerid][E_CHARACTER_LEVEL] < BusinessInfo[id][E_BUSINESS_LEVEL])
			return SendErrorMessage(playerid, "You need to be level %i to buy this.", BusinessInfo[id][E_BUSINESS_LEVEL]);
			
		if(PlayerInfo[playerid][E_CHARACTER_MONEY] < BusinessInfo[id][E_BUSINESS_PRICE])
			return SendErrorMessage(playerid, "You can't afford this business."); 
			
		PlayerPlaySound(playerid, 1052, 0.0, 0.0, 0.0);
		ShowBoxMessage(playerid, "Congratulations!~n~You're now the owner of this business!", 4);
		
		SendInfoMessage(playerid, "You purchased the %s for $%s!", BusinessInfo[id][E_BUSINESS_NAME], FormatMoney(BusinessInfo[id][E_BUSINESS_PRICE]));
		
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
		SendClientMessageEx(playerid, COLOR_ORANGE, "Owner:[%s] Level:[%d] Value:[$%s] Type:[%d] Locked:[%s] ID:[%d]", ReturnName(playerid), BusinessInfo[id][E_BUSINESS_LEVEL], FormatMoney(BusinessInfo[id][E_BUSINESS_PRICE]),
			BusinessInfo[id][E_BUSINESS_TYPE], (BusinessInfo[id][E_BUSINESS_LOCKED] != true) ? ("No") : ("Yes"), BusinessInfo[id][E_BUSINESS_DBID]); 
		SendClientMessageEx(playerid, COLOR_ORANGE, "Cashbox:[$%s] Entrance fee:[$%s] Products:[%d / %d]", FormatMoney(BusinessInfo[id][E_BUSINESS_CASH]), FormatMoney(BusinessInfo[id][E_BUSINESS_ENTRANCEFEE]), BusinessInfo[id][E_BUSINESS_STOCK], MAX_BUSINESS_PRODUCTS);		
	}
	else return SendErrorMessage(playerid, "You aren't in a business.");

	return 1;
}

CMD:bizproduct(playerid, params[])
{
	if(!CountPlayerBusiness(playerid))
		return SendErrorMessage(playerid, "You don't own a business.");
		
	new id, type, Float:value;
	
	if((id = IsPlayerInBusiness(playerid)) == 0)
		return SendErrorMessage(playerid, "You aren't inside your property.");
		
	if(BusinessInfo[id][E_BUSINESS_OWNERDBID] != PlayerInfo[playerid][E_CHARACTER_DBID])
			return SendErrorMessage(playerid, "You don't own this business."); 
		
	if(sscanf(params, "if", type, value))
	{
		SendUsageMessage(playerid, "/bizproduct [types] [price]");
		SendTipMessage(playerid, "1.product #1, 2.product #2, 3.product #3, 4.product #4"); 
		return 1;
	}
	
	new Cents = floatround(value * 100, floatround_round);

	switch(type)
	{
		case 1:
		{
			if (value < 1.00 || value > 100.00)
        		return SendErrorMessage(playerid, "Your business product cannot be less than $1.00 or more than $10.00");

			BusinessInfo[id][E_BUSINESS_PRODUCTS][1] = Cents;
			SaveBusiness(id);
			SendPropertyMessage(playerid, "[Business] {cdcdcd}You has set your business product #1 to $%s.", FormatMoney(Cents));
		}
		case 2:
		{
			if (value < 1.00 || value > 100.00)
        		return SendErrorMessage(playerid, "Your business product cannot be less than $1.00 or more than $10.00");

			BusinessInfo[id][E_BUSINESS_PRODUCTS][2] = Cents;
			SaveBusiness(id);
			SendPropertyMessage(playerid, "[Business] {cdcdcd}You has set your business product #2 to $%s.", FormatMoney(Cents));
		}
		case 3:
		{
			if (value < 1.00 || value > 100.00)
        		return SendErrorMessage(playerid, "Your business product cannot be less than $1.00 or more than $10.00");

			BusinessInfo[id][E_BUSINESS_PRODUCTS][3] = Cents;
			SaveBusiness(id);
			SendPropertyMessage(playerid, "[Business] {cdcdcd}You has set your business product #3 to $%s.", FormatMoney(Cents));
		}
	}
	return 1;
}
CMD:bizfee(playerid, params[])
{
	if(!CountPlayerBusiness(playerid))
		return SendErrorMessage(playerid, "You don't own a business.");
		
	new
		id,
		Float:amount
	;
	
	if((id = IsPlayerInBusiness(playerid)) != 0)
	{
		if(BusinessInfo[id][E_BUSINESS_OWNERDBID] != PlayerInfo[playerid][E_CHARACTER_DBID])
			return SendErrorMessage(playerid, "You don't own this business."); 
			
		if(sscanf(params, "f", amount))
			return SendUsageMessage(playerid, "/bizfee [amount]"); 
			
		if(amount < 1.00 || amount > 5.00)
			return SendErrorMessage(playerid, "Your business fee cannot be less than $1.00 or more than $5.00.");
			
		new Cents = floatround(amount * 100, floatround_round);

		BusinessInfo[id][E_BUSINESS_ENTRANCEFEE] = Cents;
		SendInfoMessage(playerid, "You set your businesses entrance fee to $%s.", FormatMoney(Cents));
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
		Float:amount,
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
			SendInfoMessage(playerid, "You have $%s in your businesses cashbox.", FormatMoney(BusinessInfo[id][E_BUSINESS_CASH])); 
		}
		else if(!strcmp(astr, "deposit"))
		{	
			if(sscanf(bstr, "f", amount))
				return SendUsageMessage(playerid, "/bizcash deposit [amount]"); 
				
			new Cents = floatround(amount * 100, floatround_round);
			
			if(Cents > PlayerInfo[playerid][E_CHARACTER_MONEY])
				return SendErrorMessage(playerid, "You don't have that much money.");

			if (amount < 0.01)
        		return SendErrorMessage(playerid, "Amount must be greater than $0.01.");

    		GiveMoney(playerid, -Cents);
			BusinessInfo[id][E_BUSINESS_CASH]+= Cents;
			
			SendInfoMessage(playerid, "You deposited $%s into your business. (Total: $%s)", FormatMoney(Cents), FormatMoney(BusinessInfo[id][E_BUSINESS_CASH]));
			SaveBusiness(id); SaveCharacter(playerid);
		}
		else if(!strcmp(astr, "withdraw"))
		{	
			if(sscanf(bstr, "f", amount))
				return SendUsageMessage(playerid, "/bizcash deposit [amount]"); 
				
			new Cents = floatround(amount * 100, floatround_round);
			
			if(Cents > BusinessInfo[id][E_BUSINESS_CASH])
				return SendErrorMessage(playerid, "Your business doesn't have that much money.");

			if (amount < 0.01)
        		return SendErrorMessage(playerid, "Amount must be greater than $0.01.");
				
			
    		GiveMoney(playerid, -Cents);
			BusinessInfo[id][E_BUSINESS_CASH]-= Cents;
			
			SendInfoMessage(playerid, "You withdraw $%s from your business. (Total: $%s)", FormatMoney(Cents), FormatMoney(BusinessInfo[id][E_BUSINESS_CASH]));
			SaveBusiness(id); SaveCharacter(playerid);
		}
		else return SendErrorMessage(playerid, "Invalid Parameter.");
	}
	else return SendErrorMessage(playerid, "You aren't in a business."); 
	return 1;
}

CMD:givebusiness(playerid, params[])
{
	new id;
	
	new
	    userid;

	if (sscanf(params, "u", userid))
	    return SendUsageMessage(playerid, "/givebiz [playerid/name]");

    if (userid == INVALID_PLAYER_ID || !IsPlayerNearPlayer(playerid, userid, 6.0))
	    return SendErrorMessage(playerid, "The specified player is disconnected or not near you.");

    if (userid == playerid)
		return SendErrorMessage(playerid, "You cannot frisk yourself.");

	if(!CountPlayerBusiness(playerid))
		return SendErrorMessage(playerid, "You don't own a business.");
		
	if((id = IsPlayerNearBusiness(playerid)) != 0)
	{
		if(BusinessInfo[id][E_BUSINESS_OWNERDBID] != PlayerInfo[playerid][E_CHARACTER_DBID])
			return SendErrorMessage(playerid, "You don't own this business."); 
			
		PlayerInfo[userid][E_CHARACTER_BIZOFFER] = playerid;
		PlayerInfo[userid][E_CHARACTER_BIZOFFERID] = id;

		SendTipMessage(userid, "%s has offered to give their business, type /approve business to approve.", ReturnName(playerid));
		SendInfoMessage(playerid, "You have offered to give %s your business.", ReturnName(userid));
	}
	else return SendErrorMessage(playerid, "You aren't in a business.");
	return 1;
}

CMD:sellbusiness(playerid, params[])
{
	new
		id,
		str[256];
	
	if(!CountPlayerBusiness(playerid))
		return SendErrorMessage(playerid, "You don't own a business.");
		
	if((id = IsPlayerInBusiness(playerid)) != 0)
	{
		if(BusinessInfo[id][E_BUSINESS_OWNERDBID] != PlayerInfo[playerid][E_CHARACTER_DBID])
			return SendErrorMessage(playerid, "You don't own this business."); 
			
		format(str, sizeof(str), "Are you sure you want to sell your business?\nYou'll earn {33AA33}$%s{ffffff} from selling and {33AA33}$%s{ffffff} from the cashbox.", FormatMoney(BusinessInfo[id][E_BUSINESS_PRICE] / 2), FormatMoney(BusinessInfo[id][E_BUSINESS_CASH]));
		ConfirmDialog(playerid, "Confirmation", str, "OnSellBusiness", id); 
	}
	else return SendErrorMessage(playerid, "You aren't in a business.");
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
		SendTipMessage(playerid, "1. Dinner's, 2. Bar, 3. Acidlabs, 4. Gunstore, 5. Club, 6. Bank, 7. General.");
		SendTipMessage(playerid, "8. Clothes, 9. Dealership, 10. DMV, 11. Barbershop, 12. Rental, 13. Gym."); 
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
		SendTipMessage(playerid, "entrance, interior, point, fuel, type, level, stock");
		SendTipMessage(playerid, "mapicon, entrancefee, name, marketprice, actor"); 
		return 1;
	}
	
	if(!BusinessInfo[id][E_BUSINESS_DBID] || id > MAX_BUSINESS)
		return SendErrorMessage(playerid, "You specified an invalid business ID.");
		
	if(!strcmp(astr, "entrance"))
	{
		ConfirmDialog(playerid, "Confirmation", "Are you sure you want to change this businesses entrance?", "OnBusinessEntranceChange", id); 
	}
	else if(!strcmp(astr, "interior"))
	{
		ConfirmDialog(playerid, "Confirmation", "Are you sure you want to change this businesses entrance?", "OnBusinessInteriorChange", id); 
	}
	else if(!strcmp(astr, "point"))
	{
		new Float:x, Float:y, Float:z;
		GetPlayerPos(playerid, x, y, z);
		PlayerInfo[playerid][E_CHARACTER_ADDOBJECT] = CreateDynamicObject(1239, x, y, z, 0.0, 0.0, 0.0, GetPlayerVirtualWorld(playerid), GetPlayerInterior(playerid)); 
		EditDynamicObject(playerid, PlayerInfo[playerid][E_CHARACTER_ADDOBJECT]); 
		PlayerInfo[playerid][E_CHARACTER_EDITINGOBJECT] = 6;
	}
	else if(!strcmp(astr, "fuel"))
	{
		ConfirmDialog(playerid, "Confirmation", "Are you sure you want to change this businesses gas station?", "OnBusinessGasStationChange", id); 
	}
	else if(!strcmp(astr, "actor"))
	{
		ConfirmDialog(playerid, "Confirmation", "Are you sure you want to change this businesses gas station?", "OnBusinessActorChange", id); 
	}
	else if(!strcmp(astr, "type"))
	{
		new type;
		
		if(sscanf(bstr, "i", type))
		{
			SendUsageMessage(playerid, "/editbusiness %i [business type]"); 
			SendTipMessage(playerid, "1. Dinner's, 2. Bar, 3. Acidlabs, 4. Gunstore, 5. Club, 6. Bank, 7. General.");
			SendTipMessage(playerid, "8. Clothes, 9. Dealership, 10. DMV, 11. Barbershop, 12. Rental, 13. Gym."); 
			return 1;
		}

		if(type > 13 || type < 1)
			return SendErrorMessage(playerid, "You specified an invalid type.");
			
		if(type == BusinessInfo[id][E_BUSINESS_TYPE])
			return SendErrorMessage(playerid, "You can't set the businesses type to what it already is."); 
			
		BusinessInfo[id][E_BUSINESS_TYPE] = type;
		BusinessRefresh(id);
		SaveBusiness(id);	
		SendInfoMessage(playerid, "You changed business #%i's type to %i.", id, type);
	}
	else if(!strcmp(astr, "level"))
	{
		new level;
		
		if(sscanf(bstr, "i", level))
			return SendUsageMessage(playerid, "/editbusiness %i level [level]", id);
			
		if(level < 1)
			return SendErrorMessage(playerid, "You can't make the level below 1."); 
			
		BusinessInfo[id][E_BUSINESS_LEVEL] = level;
		
		SendInfoMessage(playerid, "You set business #%i's level to %i.", id, level);
		SaveBusiness(id);
	}
	else if(!strcmp(astr, "stock"))
	{
		new products;
		
		if(sscanf(bstr, "i", products))
			return SendUsageMessage(playerid, "/editbusiness %i level [level]", id);
			
		if(products < 1)
			return SendErrorMessage(playerid, "You can't make the stock below 1."); 
			
		BusinessInfo[id][E_BUSINESS_STOCK] = products;
		
		SendInfoMessage(playerid, "You set business #%i's stock to %i.", id, products);
		BusinessRefresh(id);
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
		
		SendInfoMessage(playerid, "You set business #%i's entrance fee to %i.", id, fee);
		BusinessRefresh(id);
		SaveBusiness(id);	
	}
	else if(!strcmp(astr, "name"))
	{
		new bizname[90]; 
		
		if(sscanf(bstr, "s[90]", bizname))
		{
			SendUsageMessage(playerid, "/editbusiness %i name [business name]", id);
			SendTipMessage(playerid, "You can use text colors (i.e ~r~Red ~b~Blue) in the name."); 
			return 1;
		}
		
		if(strlen(bizname) > 90)
			return SendErrorMessage(playerid, "Stay below 90 characters.");
			
		SendInfoMessage(playerid, "You set business #%i's name from \"%s\" to \"%s\". ", id, BusinessInfo[id][E_BUSINESS_NAME], bizname); 
		
		format(BusinessInfo[id][E_BUSINESS_NAME], 90, "%s", bizname);
		BusinessRefresh(id);
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
		new Float:price;
		
		if(sscanf(bstr, "f", price))
			return SendUsageMessage(playerid, "/editbusiness %i price [amount]", id);
			
		new Cents = floatround(price * 100, floatround_round);

		BusinessInfo[id][E_BUSINESS_PRICE] = Cents;
		
		SendInfoMessage(playerid, "You set business #%i's market price to $%s.", id, FormatMoney(Cents));
		BusinessRefresh(id);
		SaveBusiness(id);	
	}
	else return SendErrorMessage(playerid, "Invalid Parameter.");
	return 1;
}