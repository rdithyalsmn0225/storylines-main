function:Query_LoadProperties()
{
	if(!cache_num_rows())
		return printf("[SERVER]: No properties were loaded from \"%s\" database...", SQL_DATABASE);
	
	new rows, fields; 
	cache_get_row_count(rows);
	cache_get_field_count(fields);
	new countProperties = 0;

	for(new i = 0; i < rows && i < MAX_PROPERTY; i++)
	{
		cache_get_value_name_int(i, "PropertyDBID", PropertyInfo[i+1][E_PROPERTY_DBID]);
		cache_get_value_name_int(i, "PropertyOwnerDBID", PropertyInfo[i+1][E_PROPERTY_OWNERDBID]);

		cache_get_value_name(i, "PropertyAddress", PropertyInfo[i+1][E_PROPERTY_ADDRESS], 128);
		
		cache_get_value_name_int(i, "PropertyType", PropertyInfo[i+1][E_PROPERTY_TYPE]);
		cache_get_value_name_int(i, "PropertyFaction", PropertyInfo[i+1][E_PROPERTY_FACTION]);
		
		cache_get_value_name_float(i, "PropertyEntranceX", PropertyInfo[i+1][E_PROPERTY_ENTRANCEPOS][0]);
		cache_get_value_name_float(i, "PropertyEntranceY", PropertyInfo[i+1][E_PROPERTY_ENTRANCEPOS][1]);
		cache_get_value_name_float(i, "PropertyEntranceZ", PropertyInfo[i+1][E_PROPERTY_ENTRANCEPOS][2]);
		
		cache_get_value_name_int(i, "PropertyEntranceInterior", PropertyInfo[i+1][E_PROPERTY_ENTRANCEINTERIOR]);
		cache_get_value_name_int(i, "PropertyEntranceWorld", PropertyInfo[i+1][E_PROPERTY_ENTRANCEWORLD]);
		
		cache_get_value_name_float(i, "PropertyInteriorX", PropertyInfo[i+1][E_PROPERTY_INTERIORPOS][0]);
		cache_get_value_name_float(i, "PropertyInteriorY", PropertyInfo[i+1][E_PROPERTY_INTERIORPOS][1]);
		cache_get_value_name_float(i, "PropertyInteriorZ", PropertyInfo[i+1][E_PROPERTY_INTERIORPOS][2]);
		
		cache_get_value_name_int(i, "PropertyInteriorIntID", PropertyInfo[i+1][E_PROPERTY_INTERIORINTERIOR]);
		cache_get_value_name_int(i, "PropertyInteriorWorld", PropertyInfo[i+1][E_PROPERTY_INTERIORWORLD]);
		
		cache_get_value_name_int(i, "PropertyMarketPrice", PropertyInfo[i+1][E_PROPERTY_PRICE]);
		cache_get_value_name_int(i, "PropertyLocked", PropertyInfo[i+1][E_PROPERTY_LEVEL]);
		
		cache_get_value_name_bool(i, "PropertyLocked", PropertyInfo[i+1][E_PROPERTY_LOCKED]);
		
		cache_get_value_name_int(i, "PropertyCashbox", PropertyInfo[i+1][E_PROPERTY_CASH]);
		PropertyInfo[i+1][E_PROPERTY_PICKUP] = CreateDynamicObject(19198, PropertyInfo[i+1][E_PROPERTY_ENTRANCEPOS][0], PropertyInfo[i+1][E_PROPERTY_ENTRANCEPOS][1], PropertyInfo[i+1][E_PROPERTY_ENTRANCEPOS][2]+0.8, 0.0, 0.0, 0.0, 0, 0, -1, 3.0); 

		countProperties++; 
	}
	
	printf("[SERVER]: %i properties were loaded from \"%s\" database...", countProperties, SQL_DATABASE);
	return 1;
}

function:OnPropertyCreate(playerid, newid, type)
{	
	new
			world = random(40000)+playerid+2;
	PropertyInfo[newid][E_PROPERTY_DBID] = cache_insert_id(); 
	PropertyInfo[newid][E_PROPERTY_TYPE] = type; 

	PropertyInfo[newid][E_PROPERTY_INTERIORPOS][0] = PropertyInteriors[type][E_INT_X]; 
	PropertyInfo[newid][E_PROPERTY_INTERIORPOS][1] = PropertyInteriors[type][E_INT_Y]; 
	PropertyInfo[newid][E_PROPERTY_INTERIORPOS][2] = PropertyInteriors[type][E_INT_Z]; 
	PropertyInfo[newid][E_PROPERTY_INTERIORINTERIOR] = PropertyInteriors[type][E_INT_ID]; 
	PropertyInfo[newid][E_PROPERTY_INTERIORWORLD] = world;

	SendServerMessage(playerid, "You created property ID %i. To configure, use \"/editproperty\". ", newid); 
	return 1;
}

function:OnEntranceChange(playerid, response, property)
{
	if(response)
	{
		GetPlayerPos(playerid, PropertyInfo[property][E_PROPERTY_ENTRANCEPOS][0], PropertyInfo[property][E_PROPERTY_ENTRANCEPOS][1], PropertyInfo[property][E_PROPERTY_ENTRANCEPOS][2]);
		
		if(IsValidDynamicObject(PropertyInfo[property][E_PROPERTY_PICKUP]))
			DestroyDynamicObject(PropertyInfo[property][E_PROPERTY_PICKUP]); 

		PropertyInfo[property][E_PROPERTY_ENTRANCEINTERIOR] = GetPlayerInterior(playerid);
		PropertyInfo[property][E_PROPERTY_ENTRANCEWORLD] = GetPlayerVirtualWorld(playerid);

		format(PropertyInfo[property][E_PROPERTY_ADDRESS], 128, "%dth %s", property, ReturnLocationStreet(playerid));

		PropertyInfo[property][E_PROPERTY_PICKUP] = CreateDynamicObject(19198, PropertyInfo[property][E_PROPERTY_ENTRANCEPOS][0], PropertyInfo[property][E_PROPERTY_ENTRANCEPOS][1], PropertyInfo[property][E_PROPERTY_ENTRANCEPOS][2]+0.8, 0.0, 0.0, 0.0, 0, 0, -1, 3.0); 
		
		SaveProperty(property);
		SendServerMessage(playerid, "You set Property %i's entrance.", property);
	}
	return 1;
}

function:OnInteriorChange(playerid, response, property)
{
	if(response)
	{
		GetPlayerPos(playerid, PropertyInfo[property][E_PROPERTY_INTERIORPOS][0], PropertyInfo[property][E_PROPERTY_INTERIORPOS][1], PropertyInfo[property][E_PROPERTY_INTERIORPOS][2]);
		
		new
			world = random(40000)+playerid+2;
		
		PropertyInfo[property][E_PROPERTY_INTERIORINTERIOR] = GetPlayerInterior(playerid);
		PropertyInfo[property][E_PROPERTY_INTERIORWORLD] = world;
		
		foreach(new i : Player) if(IsPlayerInProperty(i) == property)
		{
			SetPlayerPosEx(i, PropertyInfo[property][E_PROPERTY_INTERIORPOS][0], PropertyInfo[property][E_PROPERTY_INTERIORPOS][1], PropertyInfo[property][E_PROPERTY_INTERIORPOS][2]);
			SetPlayerInterior(i, GetPlayerInterior(playerid)); SetPlayerVirtualWorld(i, world); 
			
			SendServerMessage(i, "The property you were in was amended."); 
		}
		
		SaveProperty(property);
		SendServerMessage(playerid, "You set Property %i's interior.", property);
	}
	return 1;
}

function:OnPlayerEnterProperty(playerid, id)
{
	CreateBurglary(id);
	SetPlayerPosEx(playerid, PropertyInfo[id][E_PROPERTY_INTERIORPOS][0], PropertyInfo[id][E_PROPERTY_INTERIORPOS][1], PropertyInfo[id][E_PROPERTY_INTERIORPOS][2]);
	return TogglePlayerControllable(playerid, true);
}

stock IsPlayerInProperty(playerid)
{
	if(PlayerInfo[playerid][E_CHARACTER_INSEIDEPROP])
	{
		for(new i = 1; i < MAX_PROPERTY; i++)
		{
			if(i == PlayerInfo[playerid][E_CHARACTER_INSEIDEPROP] && GetPlayerVirtualWorld(playerid) == PropertyInfo[i][E_PROPERTY_INTERIORWORLD])
				return i;
		}
	}
	return 0;
}

stock IsPlayerNearProperty(playerid)
{
	for(new i = 1; i < MAX_PROPERTY; i++)
	{
		if(IsPlayerInRangeOfPoint(playerid, 3.0, PropertyInfo[i][E_PROPERTY_ENTRANCEPOS][0], PropertyInfo[i][E_PROPERTY_ENTRANCEPOS][1], PropertyInfo[i][E_PROPERTY_ENTRANCEPOS][2]) && GetPlayerVirtualWorld(playerid) == PropertyInfo[i][E_PROPERTY_ENTRANCEWORLD])
			return i;
	} 
	return 0; 
}

stock CountPlayerProperties(playerid)
{
	new
		count = 0
	;

	for(new i = 1; i < MAX_PROPERTY; i++)
	{
		if(!PropertyInfo[i][E_PROPERTY_DBID])
			continue;
			
		if(PropertyInfo[i][E_PROPERTY_OWNERDBID] == PlayerInfo[playerid][E_CHARACTER_DBID])
			count++; 
	}
	return count; 
}

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
		SendClientMessage(playerid, COLOR_RED, "[Type]:{d7d7d7} 1. House, 2. Apartment Complex, 3. Burglary House.");
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
		SendClientMessage(playerid, COLOR_RED, "[Type]:{d7d7d7} Entrance, Faction,");
		SendClientMessage(playerid, COLOR_RED, "[Type]:{d7d7d7} Type, MarketPrice, Level.");
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
		
		SendServerMessage(playerid, "You set Property %i's faction to %i.", id, factionid);
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
		if(vartype == PROPERTY_TYPE_NPC) typeName = "Burglary House";
		
		PropertyInfo[id][E_PROPERTY_TYPE] = vartype;
		SaveProperty(id);
		
		SendServerMessage(playerid, "You set Property %i's type to %s.", id, typeName);	
	}
	else if(!strcmp(indx, "marketprice"))
	{
		new price;
		
		if(sscanf(specifier, "i", price))
			return SendUsageMessage(playerid, "/editproperty %i MarketPrice [price]", id);
			
		if(price < 1)
			return SendErrorMessage(playerid, "The price has to be greater than or equal to 1."); 
			 
		PropertyInfo[id][E_PROPERTY_PRICE] = price;
		SaveProperty(id);
		
		SendServerMessage(playerid, "You set Property %i's market price to %i.", id, price);
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
		
		SendServerMessage(playerid, "You set Property %i's level to %i.", id, level);
	}
	else return SendServerMessage(playerid, "Invalid Paramater.");	
	return 1;
}