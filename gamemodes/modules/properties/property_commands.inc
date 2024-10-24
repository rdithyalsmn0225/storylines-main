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
		SendClientMessage(playerid, COLOR_WHITE, "1. House, 2. Apartment Complex, 3. High House.");
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
		SendClientMessage(playerid, COLOR_WHITE, "Entrance, Faction,");
		SendClientMessage(playerid, COLOR_WHITE, "Type, Price, Level.");
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
			SendClientMessage(playerid, COLOR_WHITE, "Types: 1. House, 2. Apartment Complex, 3. Apartment Room.");
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
		new price;
		
		if(sscanf(specifier, "i", price))
			return SendUsageMessage(playerid, "/editproperty %i price [price]", id);
			
		if(price < 1)
			return SendErrorMessage(playerid, "The price has to be greater than or equal to 1."); 
			 
		PropertyInfo[id][E_PROPERTY_PRICE] = price;
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
		SendClientMessage(playerid, COLOR_WHITE, "Types: info, cashbox, safe, furniture"); 
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
			SendInfoMessage(playerid, "You have $%s inside your houses' cashbox.", FormatMoney(PropertyInfo[id][E_PROPERTY_CASH])); 
		}
		else if(!strcmp(pick, "place"))
		{	
			if(sscanf(cstr, "i", amount))
				return SendUsageMessage(playerid, "/property cashbox place [amount]"); 
				
			if(amount > PlayerInfo[playerid][E_CHARACTER_MONEY])
				return SendErrorMessage(playerid, "You don't have that amount on you.");
				
			GiveMoney(playerid, -amount);
			PropertyInfo[id][E_PROPERTY_CASH]+= amount; 
			
			SendServerMessage(playerid, "[Property] {cdd0d1}You added {B3C99E}$%s{cdd0d1} to your cashbox.", amount); 
			SaveProperty(id);
		}
		else if(!strcmp(pick, "take"))
		{
			if(sscanf(cstr, "i", amount))
				return SendUsageMessage(playerid, "/property cashbox take [amount]");
				
			if(amount > PropertyInfo[id][E_PROPERTY_CASH])
				return SendErrorMessage(playerid, "Your cashbox doesn't have that much.");
				
			GiveMoney(playerid, amount);
			PropertyInfo[id][E_PROPERTY_CASH]-= amount;
			
			SendServerMessage(playerid, "[Property] {cdd0d1}You took {B3C99E}$%s{ffffff} from your cashbox.", amount); 
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
				SendServerMessage(playerid, "[Furniture] {cdd0d1}You will now see labels appear above all of your furniture.");
			}
			else
			{
				PropertyInfo[id][E_PROPERTY_LABELS] = 0;
				ReloadAllFurniture(id);
				SendServerMessage(playerid, "[Furniture] {cdd0d1}You will no longer see any labels appear above your furniture.");
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
	format(str, sizeof(str), "%s has been removed all furniture properties #%d", ReturnSettingsName(playerid, playerid), id);
	SendAdminMessage(ADMINS_OPERATOR, str);
	return 1;
}