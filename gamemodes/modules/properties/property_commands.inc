CMD:createproperty(playerid, params[])
{
	if(IsPlayerAdmins(playerid) < ADMINS_OWNER)
		return 0;
		
	new 
		vartype, 
		idx,
		query[128]
	; 
	
	if(sscanf(params, "i", vartype))
	{
		SendUsageMessage(playerid, "/createproperty [type]");
		SendTipMessage(playerid, "1. House, 2. Apartment Complex, 3. High House.");
		return 1;
	}
	
	if(vartype > 3 || vartype < 1) 
		return SendErrorMessage(playerid, "You specified an invalid type.");

	for(new i = 1; i < MAX_PROPERTY; i++)
	{
		if(!PropertyInfo[i][E_PROPERTY_DBID])
		{
			idx = i;
			break;
		}
	}
		
	if(idx == 0)
		return SendErrorMessage(playerid, "You can't make anymore property."); 

	mysql_format(ourConnection, query, sizeof(query), "INSERT INTO properties (`PropertyType`) VALUES(%i)", vartype);
	mysql_pquery(ourConnection, query, "OnPropertyCreate", "iii", playerid, idx, vartype);
	return 1;
}

CMD:editproperty(playerid, params[])
{
	if(IsPlayerAdmins(playerid) < ADMINS_OWNER)
		return 0;
		
	new id, indx[60], specifier[60];
	
	if(sscanf(params, "is[60]S()[60]", id, indx, specifier))
	{
		SendUsageMessage(playerid, "/editproperty [property id] [configuration]");
		SendTipMessage(playerid, "Entrance, Faction,");
		SendTipMessage(playerid, "Type, Price, Level.");
		return 1; 
	}
	
	if(!PropertyInfo[id][E_PROPERTY_DBID] || id > MAX_PROPERTY)
		return SendErrorMessage(playerid, "That Property doesn't exist.");
	
	if(!strcmp(indx, "entrance"))
	{
		ConfirmDialog(playerid, "Confirmation", "Are you sure you want to set this properties entrance?", "OnEntranceChange", id); 
	}
	else if(!strcmp(indx, "faction"))
	{		
		new factionid;
		
		if(sscanf(specifier, "i", factionid))
			return SendUsageMessage(playerid, "/editproperty %i Faction [faction ID]", id);
			
		if(!FactionInfo[factionid][E_FACTION_DBID] || factionid > MAX_FACTIONS)
			return SendErrorMessage(playerid, "You specifier an invalid faction ID.");
			
		PropertyInfo[id][E_PROPERTY_FACTION] = factionid;
		SaveProperty(factionid);
		
		SendInfoMessage(playerid, "You set Property #%i's faction to #%i.", id, factionid);
	}
	else if(!strcmp(indx, "type"))
	{
		new vartype, typeName[30];
		
		if(sscanf(specifier, "i", vartype))
		{
			SendUsageMessage(playerid, "/editproperty %i Type [type id]", id);
			SendTipMessage(playerid, "1. House, 2. Apartment Complex, 3. Apartment Room.");
			return 1;
		}
		
		if(vartype > 3 || vartype < 1) 
			return SendErrorMessage(playerid, "You specified an invalid type.");
			
		if(vartype == PROPERTY_TYPE_HOUSE) typeName = "House";
		if(vartype == PROPERTY_TYPE_APTCOMPLEX) typeName = "Apartment Complex";
		if(vartype == PROPERTY_TYPE_HIGHHOUSE) typeName = "High House";
		
		PropertyInfo[id][E_PROPERTY_TYPE] = vartype;
		SaveProperty(id);
		Property_RemoveAllItems(id);
		RemoveAllFurniture(id);
		
		SendInfoMessage(playerid, "You set Property #%i's type to %s.", id, typeName);	
	}
	else if(!strcmp(indx, "price"))
	{
		new Float:price;
		
		if(sscanf(specifier, "f", price))
			return SendUsageMessage(playerid, "/editproperty %i price [price]", id);
			
		if(price < 1)
			return SendErrorMessage(playerid, "The price has to be greater than or equal to 1."); 
			 
		new Cents = floatround(price * 100, floatround_round);

		PropertyInfo[id][E_PROPERTY_PRICE] = Cents;
		SaveProperty(id);
		
		SendInfoMessage(playerid, "You set Property #%i's market price to %i.", id, price);
	}
	else if(!strcmp(indx, "level"))
	{
		new level;
		
		if(sscanf(specifier, "i", level))
			return SendUsageMessage(playerid, "/editproperty %i Level [level]", id);
			
		if(level < 1)
			return SendErrorMessage(playerid, "The level can't be less than 1.");
			
		PropertyInfo[id][E_PROPERTY_LEVEL] = level;
		SaveProperty(id);
		
		SendInfoMessage(playerid, "You set Property #%i's level to #%i.", id, level);
	}
	else return SendErrorMessage(playerid, "Invalid Paramater.");	
	return 1;
}

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

CMD:giveproperty(playerid, params[])
{
	new
		id;
	
	new
	    userid;

	if (sscanf(params, "u", userid))
	    return SendUsageMessage(playerid, "/giveproperty [playerid/name]");

    if (userid == INVALID_PLAYER_ID || !IsPlayerNearPlayer(playerid, userid, 6.0))
	    return SendErrorMessage(playerid, "The specified player is disconnected or not near you.");

    if (userid == playerid)
		return SendErrorMessage(playerid, "You cannot frisk yourself.");

	if(!CountPlayerProperties(playerid))
		return SendErrorMessage(playerid, "You don't own a business.");
		
	if((id = IsPlayerNearProperty(playerid)) != 0)
	{
		if(PropertyInfo[id][E_PROPERTY_OWNERDBID] != PlayerInfo[playerid][E_CHARACTER_DBID])
			return SendErrorMessage(playerid, "You don't own this business."); 
			
		PlayerInfo[userid][E_CHARACTER_PROPOFFER] = playerid;
		PlayerInfo[userid][E_CHARACTER_PROPOFFERID] = id;

		SendTipMessage(userid, "%s has offered to give their property, type /approve property to approve.", ReturnName(playerid));
		SendInfoMessage(playerid, "You have offered to give %s your property.", ReturnName(userid));
	}
	else return SendErrorMessage(playerid, "You aren't near a property.");
	return 1;
}

CMD:sellproperty(playerid, params[])
{
	new
		id,
		str[128];
	
	if(!CountPlayerProperties(playerid))
		return SendErrorMessage(playerid, "You don't own a property.");
		
	if((id = IsPlayerInProperty(playerid)) != 0)
	{
		if(PropertyInfo[id][E_PROPERTY_OWNERDBID] != PlayerInfo[playerid][E_CHARACTER_DBID])
			return SendErrorMessage(playerid, "You don't own this property."); 
			
		format(str, sizeof(str), "Are you sure you want to sell your property?\nYou'll earn {33AA33}$%s{ffffff} from selling and {33AA33}$%s{ffffff} from the cashbox.", FormatMoney(PropertyInfo[id][E_PROPERTY_PRICE] / 2), FormatMoney(PropertyInfo[id][E_PROPERTY_CASH]));
		ConfirmDialog(playerid, "Confirmation", str, "OnSellProperty", id); 
	}
	else return SendErrorMessage(playerid, "You aren't in a property.");
	return 1;
}

CMD:knock(playerid, params[])
{
	new id, bid;
	if((id = IsPlayerNearProperty(playerid)) != 0)
	{
		SendNearbyMessage(playerid, 15.0, COLOR_EMOTE, "* %s knocks on the door.", ReturnName(playerid));

		foreach (new p : Player)
		{
			if(PlayerInfo[p][E_CHARACTER_INSIDEPROP] == id)
			{
				SendClientMessageEx(p, COLOR_EMOTE, "* [DOOR] KNOCK! KNOCK! (( %s ))", ReturnName(playerid));
			}
		}
		return 1;
	}

	if((bid = IsPlayerNearBusiness(playerid)) != 0)
	{
		SendNearbyMessage(playerid, 15.0, COLOR_EMOTE, "* %s knocks on the door.", ReturnName(playerid));

		foreach (new p : Player)
		{
			if(PlayerInfo[p][E_CHARACTER_INSIDEBIZ] == bid)
			{
				SendClientMessageEx(p, COLOR_EMOTE, "* [DOOR] KNOCK! KNOCK! (( %s ))", ReturnName(playerid));
			}
		}
		return 1;
	}
	return 1;
}

CMD:ringbell(playerid, params[])
{
	new id;
	if((id = IsPlayerNearProperty(playerid)) != 0)
	{
		SendNearbyMessage(playerid, 15.0, COLOR_EMOTE, "* %s rings the door bell.", ReturnName(playerid));

		foreach (new p : Player)
		{
			if(PlayerInfo[p][E_CHARACTER_INSIDEPROP] == id)
			{
				SendClientMessageEx(p, COLOR_EMOTE, "* The bell rings (( %s ))", ReturnName(playerid));
			}
		}
		return 1;
	}
	return 1;
}

CMD:prop(playerid, params[]) return cmd_property(playerid, params);
CMD:property(playerid, params[])
{
	if(!CountPlayerProperties(playerid))
		return SendErrorMessage(playerid, "You don't own a property."); 
		
	new id, str[90], bstr[90], cstr[60];
	
	if((id = IsPlayerInProperty(playerid)) == 0)
		return SendErrorMessage(playerid, "You aren't inside your property.");
		
	if(PropertyInfo[id][E_PROPERTY_OWNERDBID] != PlayerInfo[playerid][E_CHARACTER_DBID])
		return SendErrorMessage(playerid, "You don't own this property."); 
		
	if(sscanf(params, "s[90]S()[90]S()[60]", str, bstr, cstr))
	{
		SendUsageMessage(playerid, "/property [types]");
		SendTipMessage(playerid, "info, cashbox, safe, furniture"); 
		return 1;
	}
	
	if(!strcmp(str, "info"))
	{
		new type[30];
		
		if(PropertyInfo[id][E_PROPERTY_TYPE] == PROPERTY_TYPE_HOUSE)
			type = "House";
		
		else if(PropertyInfo[id][E_PROPERTY_TYPE] == PROPERTY_TYPE_HIGHHOUSE)
			type = "High House";
			
		else if(PropertyInfo[id][E_PROPERTY_TYPE] == PROPERTY_TYPE_APTCOMPLEX)
			type = "Apartment Complex"; 
	
		SendClientMessage(playerid, COLOR_DARKGREEN, "|__________ Property Info __________|");
		SendClientMessageEx(playerid, COLOR_ORANGE, "House ID:[%i], Price:[$%s], Level:[%i], Type:[%s], Furniture Capacity:[%d]", PropertyInfo[id][E_PROPERTY_DBID], FormatMoney(PropertyInfo[id][E_PROPERTY_PRICE]), PropertyInfo[id][E_PROPERTY_LEVEL], type, GetPropertyFurniture(id)); 
	}
	else if(!strcmp(str, "cashbox"))
	{
		new pick[30], amount;
		
		if(sscanf(bstr, "s[30]", pick))
			return SendUsageMessage(playerid, "/property cashbox [Info, Place, Take, Furniture]"); 
			
		if(!strcmp(pick, "info"))
		{
			SendClientMessage(playerid, COLOR_DARKGREEN, "|__________ Property Info __________|");
			SendClientMessageEx(playerid, COLOR_ORANGE, "You have $%s inside your houses' cashbox.", FormatMoney(PropertyInfo[id][E_PROPERTY_CASH])); 
		}
		else if(!strcmp(pick, "place"))
		{	
			if(sscanf(cstr, "f", amount))
				return SendUsageMessage(playerid, "/property cashbox place [amount]"); 
				
			if(amount > PlayerInfo[playerid][E_CHARACTER_MONEY])
				return SendErrorMessage(playerid, "You don't have that amount on you.");
				
			new Cents = floatround(amount * 100, floatround_round);

			GiveMoney(playerid, -Cents);
			PropertyInfo[id][E_PROPERTY_CASH]+= amount; 
			
			SendPropertyMessage(playerid, "[Property] {DEDEDE}You added $%s to your cashbox.", amount); 
			SaveProperty(id);
		}
		else if(!strcmp(pick, "take"))
		{
			if(sscanf(cstr, "f", amount))
				return SendUsageMessage(playerid, "/property cashbox take [amount]");
				
			if(amount > PropertyInfo[id][E_PROPERTY_CASH])
				return SendErrorMessage(playerid, "Your cashbox doesn't have that much.");
				
			new Cents = floatround(amount * 100, floatround_round);

			GiveMoney(playerid, Cents);
			PropertyInfo[id][E_PROPERTY_CASH]-= amount;
			
			SendPropertyMessage(playerid, "[Property] {DEDEDE}You took {33AA33}$%s{ffffff} from your cashbox.", amount); 
			SaveProperty(id); 
		}
		else return SendErrorMessage(playerid, "Invalid Paramater."); 
	}
	else if(!strcmp(str, "safe"))
	{
		Property_ShowItems(playerid, id);
	}
	else if(!strcmp(str, "furniture"))
	{
		new pick[30];
		
		if(sscanf(bstr, "s[30]", pick))
			return SendUsageMessage(playerid, "/property furniture [Add, Edit, Destroy, Clear, Textures, Labels]"); 
			
		if(!strcmp(pick, "add"))
		{
			new queryBuffer[512];
			mysql_format(ourConnection, queryBuffer, sizeof(queryBuffer), "SELECT COUNT(*) FROM furniture WHERE propertydbid = %i", PropertyInfo[id][E_PROPERTY_DBID]);
	    	mysql_pquery(ourConnection, queryBuffer, "FurnitureCount", "i", playerid);
		}
		else if(!strcmp(pick, "edit"))
		{	
			new objectid;

			if(sscanf(cstr, "i", objectid))
				return SendUsageMessage(playerid, "/property furniture edit [objectid]");

			if(!IsValidDynamicObject(objectid) || Streamer_GetExtraInt(objectid, E_OBJECT_TYPE) != E_OBJECT_FURNITURE)
				return SendErrorMessage(playerid, "Invalid object. You can find the object IDs for your furniture by enabling labels. [/property furniture labels]");

			if(Streamer_GetExtraInt(objectid, E_OBJECT_EXTRA_ID) != PropertyInfo[id][E_PROPERTY_DBID])
				return SendErrorMessage(playerid, "Invalid object. This furniture object is not inside of your house.");

			if(Streamer_GetExtraInt(objectid, E_OBJECT_TYPE_ID) != 0)
				return SendErrorMessage(playerid, "Invalid object. This furniture object is static of your properties.");

			PlayerInfo[playerid][E_CHARACTER_EDITINGOBJECT] = 8;
			PlayerInfo[playerid][E_CHARACTER_ADDOBJECT] = objectid;
			PlayerInfo[playerid][E_CHARACTER_SELECTINDEX] = id;

			EditDynamicObject(playerid, objectid);
		}
		else if(!strcmp(pick, "destroy"))
		{
			new objectid, queryBuffer[512];

			if(sscanf(cstr, "i", objectid))
				return SendUsageMessage(playerid, "/property furniture destroy [objectid]");

			if(!IsValidDynamicObject(objectid) || Streamer_GetExtraInt(objectid, E_OBJECT_TYPE) != E_OBJECT_FURNITURE)
				return SendErrorMessage(playerid, "Invalid object. You can find the object IDs for your furniture by enabling labels. [/property furniture labels]");
			
			if(Streamer_GetExtraInt(objectid, E_OBJECT_EXTRA_ID) != PropertyInfo[id][E_PROPERTY_DBID])
				return SendErrorMessage(playerid, "Invalid object. This furniture object is not inside of your properties.");

			if(Streamer_GetExtraInt(objectid, E_OBJECT_TYPE_ID) != 0)
				return SendErrorMessage(playerid, "Invalid object. This furniture object is static of your properties.");

			PlayerInfo[playerid][E_CHARACTER_LISTITEM] = objectid;

			mysql_format(ourConnection, queryBuffer, sizeof(queryBuffer), "SELECT name, price FROM furniture WHERE id = %i", Streamer_GetExtraInt(objectid, 1));
			mysql_pquery(ourConnection, queryBuffer, "FurnitureSell", "i", playerid);
		}
		else if(!strcmp(pick, "clear"))
		{	
			if(isnull(cstr) || strcmp(cstr, "confirm", true) != 0)
			{
				SendUsageMessage(playerid, "/property furniture clear [confirm]");
				SendTipMessage(playerid, "This sells all of your furniture in your properties. This action is irreversible.");
				return 1;
			}

			new queryBuffer[512];
			mysql_format(ourConnection, queryBuffer, sizeof(queryBuffer), "SELECT price FROM furniture WHERE propertydbid = %i", PropertyInfo[id][E_PROPERTY_DBID]);
			mysql_pquery(ourConnection, queryBuffer, "FurnitureClear", "i", playerid);
		}
		else if(!strcmp(pick, "textures"))
		{	
			new objectid, index, modelid, txd[32], name[32];

			if(sscanf(cstr, "iiis[32]s[32]", objectid, index, modelid, txd, name))
			{
				SendUsageMessage(playerid, "/property furniture texture [objectid] [index] [modelid] [txd] [texturename]");
				SendTipMessage(playerid, "You can see all textures availables on 'gtxd.net' or 'textures.xyin.ws'");
				SendTipMessage(playerid, "'/property furniture texture 11177 0 10810 ap_build4e weewall256'");
				return 1;
			}

			if(!IsValidDynamicObject(objectid) || Streamer_GetExtraInt(objectid, E_OBJECT_TYPE) != E_OBJECT_FURNITURE)
				return SendErrorMessage(playerid, "Invalid object. You can find the object IDs for your furniture by enabling labels. [/property furniture labels]");

			if(Streamer_GetExtraInt(objectid, E_OBJECT_EXTRA_ID) != PropertyInfo[id][E_PROPERTY_DBID])
				return SendErrorMessage(playerid, "Invalid object. This furniture object is not inside of your house.");

			SetFurnitureMaterial(playerid, objectid, index, modelid, txd, name);
		}
		else if(!strcmp(pick, "labels"))
		{
			if(!PropertyInfo[id][E_PROPERTY_LABELS])
			{
				PropertyInfo[id][E_PROPERTY_LABELS] = 1;
				ReloadAllFurniture(id);
				SendServerMessage(playerid, "[Furniture] {DEDEDE}You will now see labels appear above all of your furniture.");
			}
			else
			{
				PropertyInfo[id][E_PROPERTY_LABELS] = 0;
				ReloadAllFurniture(id);
				SendServerMessage(playerid, "[Furniture] {DEDEDE}You will no longer see any labels appear above your furniture.");
			}
		}
		else return SendErrorMessage(playerid, "Invalid Paramater."); 
	}
	else return SendErrorMessage(playerid, "Invalid Paramater."); 
	return 1;
}

CMD:removefurniture(playerid, params[])
{
	new id, str[512];

	if(IsPlayerAdmins(playerid) < ADMINS_OPERATOR)
	    return 0;

	if(sscanf(params, "i", id))
	    return SendUsageMessage(playerid, "/removefurniture [propertyid]");

	if(!PropertyInfo[id][E_PROPERTY_DBID] || id > MAX_PROPERTY)
		return SendErrorMessage(playerid, "That Property doesn't exist.");

	RemoveAllFurniture(id);
	format(str, sizeof(str), "%s has been removed all furniture properties #%d", ReturnName(playerid), id);
	SendAdminMessage(ADMINS_OPERATOR, str);
	return 1;
}