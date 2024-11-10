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
		PropertyInfo[i+1][E_PROPERTY_PICKUP] = CreateDynamicPickup(1273, 1, PropertyInfo[i+1][E_PROPERTY_ENTRANCEPOS][0], PropertyInfo[i+1][E_PROPERTY_ENTRANCEPOS][1], PropertyInfo[i+1][E_PROPERTY_ENTRANCEPOS][2], 0, 0, -1, 5.0); 
		PropertyInfo[i+1][E_PROPERTY_3DTEXT] = CreateDynamic3DTextLabel(PropertyInfo[i+1][E_PROPERTY_ADDRESS], COLOR_DARKGREEN, PropertyInfo[i+1][E_PROPERTY_ENTRANCEPOS][0], PropertyInfo[i+1][E_PROPERTY_ENTRANCEPOS][1], PropertyInfo[i+1][E_PROPERTY_ENTRANCEPOS][2], 5.0);
		
		PropertyInfo[i+1][E_PROPERTY_LABELS] = 0;

		new str[512];
		mysql_format(ourConnection, str, sizeof(str), "SELECT * FROM `propertiesstorage` WHERE `ID` = '%d'", PropertyInfo[i+1][E_PROPERTY_DBID]);
		mysql_pquery(ourConnection, str, "Query_LoadPropertiesStorage", "d", PropertyInfo[i+1][E_PROPERTY_DBID]);
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

	SendInfoMessage(playerid, "You created property ID #%i. To configure, use \"/editproperty\". ", newid); 
	return 1;
}

function:OnEntranceChange(playerid, response, property)
{
	if(response)
	{
		GetPlayerPos(playerid, PropertyInfo[property][E_PROPERTY_ENTRANCEPOS][0], PropertyInfo[property][E_PROPERTY_ENTRANCEPOS][1], PropertyInfo[property][E_PROPERTY_ENTRANCEPOS][2]);
		
		if(IsValidDynamicPickup(PropertyInfo[property][E_PROPERTY_PICKUP]))
			DestroyDynamicPickup(PropertyInfo[property][E_PROPERTY_PICKUP]); 

		if(IsValidDynamic3DTextLabel(PropertyInfo[property][E_PROPERTY_3DTEXT]))
			DestroyDynamic3DTextLabel(PropertyInfo[property][E_PROPERTY_3DTEXT]); 

		PropertyInfo[property][E_PROPERTY_ENTRANCEINTERIOR] = GetPlayerInterior(playerid);
		PropertyInfo[property][E_PROPERTY_ENTRANCEWORLD] = GetPlayerVirtualWorld(playerid);

		format(PropertyInfo[property][E_PROPERTY_ADDRESS], 128, "%dth %s", property, ReturnLocationStreet(playerid));

		PropertyInfo[property][E_PROPERTY_PICKUP] = CreateDynamicPickup(1273, 1, PropertyInfo[property][E_PROPERTY_ENTRANCEPOS][0], PropertyInfo[property][E_PROPERTY_ENTRANCEPOS][1], PropertyInfo[property][E_PROPERTY_ENTRANCEPOS][2], 0, 0, -1, 5.0); 
		PropertyInfo[property][E_PROPERTY_3DTEXT] = CreateDynamic3DTextLabel(PropertyInfo[property][E_PROPERTY_ADDRESS], COLOR_DARKGREEN, PropertyInfo[property][E_PROPERTY_ENTRANCEPOS][0], PropertyInfo[property][E_PROPERTY_ENTRANCEPOS][1], PropertyInfo[property][E_PROPERTY_ENTRANCEPOS][2], 5.0);
		SaveProperty(property);
		SendInfoMessage(playerid, "You set Property #%i's entrance.", property);
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
			
			SendInfoMessage(i, "The property you were in was amended."); 
		}
		
		SaveProperty(property);
		SendInfoMessage(playerid, "You set Property #%i's interior.", property);
	}
	return 1;
}

function:OnPlayerEnterProperty(playerid, id)
{
	PlayerEnterTimer[playerid] = false;
	//SetPlayerPosEx(playerid, PropertyInfo[id][E_PROPERTY_INTERIORPOS][0], PropertyInfo[id][E_PROPERTY_INTERIORPOS][1], PropertyInfo[id][E_PROPERTY_INTERIORPOS][2]);
	return TogglePlayerControllable(playerid, true);
}

stock IsPlayerInProperty(playerid)
{
	if(PlayerInfo[playerid][E_CHARACTER_INSIDEPROP])
	{
		for(new i = 1; i < MAX_PROPERTY; i++)
		{
			if(i == PlayerInfo[playerid][E_CHARACTER_INSIDEPROP] && GetPlayerVirtualWorld(playerid) == PropertyInfo[i][E_PROPERTY_INTERIORWORLD])
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