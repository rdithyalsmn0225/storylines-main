function:Query_LoadRelations(playerid)
{
	new rows, fields;
	cache_get_row_count(rows);
	cache_get_field_count(fields);

	for (new i = 0; i < rows && i < MAX_RELATIONS; i ++) 
	{
		RelationsInfo[playerid][i][E_RELATIONS_EXISTS] = true;

        cache_get_value_name(i, "RelationsBusinessName", RelationsInfo[playerid][i][E_RELATIONS_BUSINESSNAME], 90);
		cache_get_value_name_int(i, "RelationsID", RelationsInfo[playerid][i][E_RELATIONS_DBID]);
		cache_get_value_name_int(i, "ID", RelationsInfo[playerid][i][ID]);
		cache_get_value_name_int(i, "BusinessID", RelationsInfo[playerid][i][E_RELATIONS_BUSINESSID]);
        cache_get_value_name_int(i, "RelationsPoints", RelationsInfo[playerid][i][E_RELATIONS_POINTS]);
	}
	printf("[SERVER]: %s relations were loaded from \"%s\" database...", ReturnName(playerid), SQL_DATABASE);
	return 1;
}

function:OnRelationsAdd(playerid, id)
{
	RelationsInfo[playerid][id][ID] = cache_insert_id();
	return 1;
}


stock Relations_GetID(playerid, name[])
{
	for (new i = 0; i < MAX_RELATIONS; i ++)
	{
	    if (!RelationsInfo[playerid][i][E_RELATIONS_EXISTS])
	        continue;

		if (!strcmp(RelationsInfo[playerid][i][E_RELATIONS_BUSINESSNAME], name)) return i;
	}
	return -1;
}

stock Relations_GetFreeID(playerid)
{
	if (Relations_Items(playerid) >= 100)
		return -1;

	for (new i = 0; i < MAX_RELATIONS; i ++)
	{
	    if (!RelationsInfo[playerid][i][E_RELATIONS_EXISTS])
	        return i;
	}
	return -1;
}

stock Relations_Items(playerid)
{
    new count;

    for (new i = 0; i != MAX_RELATIONS; i ++) if (RelationsInfo[playerid][i][E_RELATIONS_EXISTS]) {
        count++;
	}
	return count;
}


stock Relations_Count(playerid, name[])
{
	new rid = Relations_GetID(playerid, name);

	if (rid != -1)
	    return RelationsInfo[playerid][rid][E_RELATIONS_POINTS];

	return 0;
}


stock Relations_Add(playerid, name[])
{
	new
		rid = Relations_GetID(playerid, name),
		query[512];

	if (rid == -1)
	{
	    rid = Relations_GetFreeID(playerid);

	    if (rid != -1)
	    {
            SendServerMessage(playerid, "[Extort] {cdd0d1}You've got relations with %s.", name);

	        RelationsInfo[playerid][rid][E_RELATIONS_EXISTS] = true;
            RelationsInfo[playerid][rid][E_RELATIONS_POINTS] = 100;

			strpack(RelationsInfo[playerid][rid][E_RELATIONS_BUSINESSNAME], name, 90 char);

            format(query, sizeof(query), "INSERT INTO `relations` (`RelationsID`, `BusinessID`, `RelationsPoints`, `RelationsBusinessName`) VALUES('%i', '%i', '%i', '%s')", PlayerInfo[playerid][E_CHARACTER_DBID], BusinessInfo[IsPlayerInBusiness(playerid)][E_BUSINESS_DBID], RelationsInfo[playerid][rid][E_RELATIONS_POINTS], name);
            mysql_pquery(ourConnection, query, "OnRelationsAdd", "dd", playerid, rid);
	        return rid;
		}
		return -1;
	}
	else
	{
        RelationsInfo[playerid][rid][E_RELATIONS_POINTS] += 5;

        format(query, sizeof(query), "UPDATE relations SET RelationsPoints = %i WHERE RelationsID = %i AND ID = %i",
            RelationsInfo[playerid][rid][E_RELATIONS_POINTS],
            PlayerInfo[playerid][E_CHARACTER_DBID],
			RelationsInfo[playerid][rid][ID]
        );
        mysql_pquery(ourConnection, query);
	}
	return rid;
}

stock Relations_Remove(playerid, name[], value)
{
	new
		rid = Relations_GetID(playerid, name),
		query[128];

	if (rid != -1)
	{
	    if (RelationsInfo[playerid][rid][E_RELATIONS_POINTS] > 0)
	    {
	        RelationsInfo[playerid][rid][E_RELATIONS_POINTS] -= value;
			if (RelationsInfo[playerid][rid][E_RELATIONS_POINTS] < 0)
	    	{
				RelationsInfo[playerid][rid][E_RELATIONS_POINTS] = 0;
			}
            SendServerMessage(playerid, "[Extort] {cdd0d1}You've lost %d relations with %s.", value, name);

			format(query, sizeof(query), "UPDATE relations SET RelationsPoints = %i WHERE RelationsID = %i AND ID = %i",
                RelationsInfo[playerid][rid][E_RELATIONS_POINTS],
                PlayerInfo[playerid][E_CHARACTER_DBID],
				RelationsInfo[playerid][rid][ID]
            );
            mysql_pquery(ourConnection, query);
		}
		return 1;
	}
	return 0;
}

stock CheckRelations(playerid, type)
{
    new existCheck[256]; 
	mysql_format(ourConnection, existCheck, sizeof(existCheck), "SELECT * FROM relations WHERE BusinessID = '%i'", BusinessInfo[IsPlayerInBusiness(playerid)][E_BUSINESS_DBID]);
	mysql_pquery(ourConnection, existCheck, "RelationsAdd", "ii", playerid, type);
    return 1;
}

stock ShowRelations(playerid)
{
	new string[32 * MAX_RELATIONS], str[90];

	format(string, sizeof(string), "Relations\tNames\n");
	for (new i = 0; i != MAX_RELATIONS; i ++) 
	{
		if (RelationsInfo[playerid][i][E_RELATIONS_EXISTS]) 
		{
			strunpack(str, RelationsInfo[playerid][i][E_RELATIONS_BUSINESSNAME]);
			format(string, sizeof(string), "%s%d\t%s\n", string, RelationsInfo[playerid][i][E_RELATIONS_POINTS], str);
			return ShowPlayerDialog(playerid, DIALOG_DEFAULT, DIALOG_STYLE_TABLIST_HEADERS, "Relationships:", string, "OK", "Close");
		}
		else
			return ShowPlayerDialog(playerid, DIALOG_DEFAULT, DIALOG_STYLE_MSGBOX, "Relationships:", "You don't have any relationship with business.", "OK", "Close");
	}
	return 1;
}

CMD:extort(playerid, params[])
{
	if(IsPlayerInBusiness(playerid))
	{
		if(!PlayerInfo[playerid][E_CHARACTER_EXTORTION] && BusinessInfo[IsPlayerInBusiness(playerid)][E_BUSINESS_CASH] > 500 && BusinessInfo[IsPlayerInBusiness(playerid)][E_BUSINESS_ROBBERYCASH] == false)
		{
			if(BusinessInfo[IsPlayerInBusiness(playerid)][E_BUSINESS_ROBBERYTIME] > 0)
				return SendErrorMessage(playerid, "This Business has recently robbery.");

			if(PlayerInfo[playerid][E_CHARACTER_ROBBERYCD] > 0)
				return SendErrorMessage(playerid, "You can't start extortion right now.");
				
			if(Relations_Count(playerid, BusinessInfo[IsPlayerInBusiness(playerid)][E_BUSINESS_NAME]) > 30)
				return ShowHeaderMessage(playerid, "Extortion", "The store owner is not scared of you. your relations must be lower than 20. extort it (Relations: 30)");
		
			PlayerInfo[playerid][E_CHARACTER_EXTORTION] = true;
			PlayerInfo[playerid][E_CHARACTER_EXTORTIONID] = IsPlayerInBusiness(playerid);
			PlayerInfo[playerid][E_CHARACTER_EXTORTIONPOINT] = 0;

			new Float: x, Float: y, Float: z;
			GetDynamicActorPos(BusinessInfo[IsPlayerInBusiness(playerid)][E_BUSINESS_ACTOR], x, y, z);
			new world = GetDynamicActorVirtualWorld(BusinessInfo[IsPlayerInBusiness(playerid)][E_BUSINESS_ACTOR]);
			new interior = GetPlayerInterior(playerid);

			switch (random(5)) {
				case 0: ProxDetectorXYZ ( x, y, z, interior, world, 10.0, 0xDEDEDEFF, "Cashiers says: Aye mane! Just take the cash don't shoot me!");
				case 1: ProxDetectorXYZ ( x, y, z, interior, world, 10.0, 0xDEDEDEFF, "Cashiers says: W-woah! Brozza please don't shoot... Just take the cash!");
				case 2: ProxDetectorXYZ ( x, y, z, interior, world, 10.0, 0xDEDEDEFF, "Cashiers says: Don't shoot! Take the cash, it ain't mine anyway!");
				case 3: ProxDetectorXYZ ( x, y, z, interior, world, 10.0, 0xDEDEDEFF, "Cashiers says: You makin' a big mistake.. Just take the cash and don't shoot!");
				case 4: ProxDetectorXYZ ( x, y, z, interior, world, 10.0, 0xDEDEDEFF, "Cashiers says: Please don't take my money! I need to feed my children!");
			}

			new str[512];
			format(str, sizeof(str), "You have started the extorting in %s.~n~~n~Hit the store clerk to break them. When the extortion bar is full use /extort again.", BusinessInfo[IsPlayerInBusiness(playerid)][E_BUSINESS_NAME]);
			ShowHeaderMessage(playerid, "Extortion", str);

			ShowGameBar(playerid, PlayerInfo[playerid][E_CHARACTER_EXTORTIONPOINT], "Extortions");
		}

		if(PlayerInfo[playerid][E_CHARACTER_EXTORTIONPOINT] >= 100.0)
		{
			if(IsPlayerInBusiness(playerid) != PlayerInfo[playerid][E_CHARACTER_EXTORTIONID])
				return ShowHeaderMessage(playerid, "Extortion", "You must be in the business you extorting");

			PlayerInfo[playerid][E_CHARACTER_EXTORTIONID] = 0;
			PlayerInfo[playerid][E_CHARACTER_EXTORTION] = false;
			BusinessInfo[IsPlayerInBusiness(playerid)][E_BUSINESS_ROBBERYTIME] = 5;
			BusinessInfo[IsPlayerInBusiness(playerid)][E_BUSINESS_ROBBERYCASH] = true;
			PlayerInfo[playerid][E_CHARACTER_ROBBERYCD] = 10;
			BusinessRefresh(IsPlayerInBusiness(playerid));

			new str[512];
			format(str, sizeof(str), "You have finished the extorting in %s.~n~~n~take the cash inside cashiers.", BusinessInfo[IsPlayerInBusiness(playerid)][E_BUSINESS_NAME]);
			ShowHeaderMessage(playerid, "Extortion", str);
			
			DestroyGameBar(playerid);
		}
	}
    return 1;
}

CMD:extortions(playerid, params[])
{
	ShowRelations(playerid);
	return 1;
}