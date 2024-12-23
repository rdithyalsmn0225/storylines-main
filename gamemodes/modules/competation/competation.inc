function:Query_LoadCompensation()
{
    new
	    rows,
	    fields;

	cache_get_row_count(rows);
	cache_get_field_count(fields);

    if(!cache_num_rows())
		return printf("[SERVER]: No compensation were loaded from \"%s\" database...", SQL_DATABASE);

    new total = 0;
    for (new i = 0; i < rows; i ++) if (i < MAX_COMPENSATION)
	{
        cache_get_value_name_int(i, "id", CompetationInfo[i][E_COMPETATION_DBID]);
		cache_get_value_name(i, "code", CompetationInfo[i][E_COMPETATION_CODE], 32);
		cache_get_value_name_int(i, "max_players", CompetationInfo[i][E_COMPETATION_PLAYERS]);
		cache_get_value_name_int(i, "expired", CompetationInfo[i][E_COMPETATION_EXPIRED]);
        cache_get_value_name_int(i, "money", CompetationInfo[i][E_COMPETATION_MONEY]);
        cache_get_value_name_int(i, "street_credits", CompetationInfo[i][E_COMPENTATION_STREETCREDITS]);
        cache_get_value_name_int(i, "players_used", CompetationInfo[i][E_COMPETATION_USED]);
        CompetationInfo[i][E_COMPETATION_EXISTS] = true;
        total++;
	}	

    printf("[SERVER]: %i compensation were loaded from \"%s\" database...", total, SQL_DATABASE);
    return 1;
}

CMD:createcode(playerid, params[])
{
    if(IsPlayerAdmins(playerid) < ADMINS_OWNER)
        return 0;

    new code[32], players, days, moneyc, streetcredits;
    if (sscanf(params, "s[32]iiii", code, players, days, moneyc, streetcredits))
        return SendUsageMessage(playerid, "/createcode [code] [max players] [days] [money] [streetcredits]");

    new expired = gettime() + (days * 86400);
    new Cents = floatround(moneyc * 100, floatround_round);

    new freeSlot = -1;
    for (new i = 0; i < MAX_COMPENSATION; i++)
    {
        if (!CompetationInfo[i][E_COMPETATION_EXISTS]) // Cek jika slot kosong
        {
            freeSlot = i;
            break;
        }
    }

    if (freeSlot == -1)
    {
        return SendErrorMessage(playerid, "You can't make anymore compensation.");
    }

    
    format(CompetationInfo[freeSlot][E_COMPETATION_CODE], 32, "%s", code);
    CompetationInfo[freeSlot][E_COMPETATION_PLAYERS] = players;
    CompetationInfo[freeSlot][E_COMPETATION_EXPIRED] = expired;
    CompetationInfo[freeSlot][E_COMPETATION_MONEY] = Cents;
    CompetationInfo[freeSlot][E_COMPENTATION_STREETCREDITS] = streetcredits;
    CompetationInfo[freeSlot][E_COMPETATION_USED] = 0;
    CompetationInfo[freeSlot][E_COMPETATION_EXISTS] = true;
    
    
    new query[256];
    mysql_format(ourConnection, query, sizeof(query), "INSERT INTO compensation_codes (code, max_players, expired, money, street_credits, players_used) VALUES ('%s', %d, %d, %d, %d, 0)", code, players, expired, Cents, streetcredits);
    mysql_tquery(ourConnection, query);

    SendInfoMessage(playerid, "[COMPENSATION] Compensation code created successfully!");
    return 1;
}

CMD:clearcode(playerid, params[])
{
    if (IsPlayerAdmins(playerid) < ADMINS_OWNER)
        return 0;

    new query[256];
    
    for (new i = 0; i < MAX_COMPENSATION; i++)
    {
        CompetationInfo[i][E_COMPETATION_EXISTS] = false;
        CompetationInfo[i][E_COMPETATION_USED] = 0;
        CompetationInfo[i][E_COMPETATION_PLAYERS] = 0;
        CompetationInfo[i][E_COMPETATION_EXPIRED] = 0;
        CompetationInfo[i][E_COMPETATION_MONEY] = 0;

        mysql_format(ourConnection, query, sizeof(query), "DELETE FROM compensation_claims WHERE code = '%s'", CompetationInfo[i][E_COMPETATION_CODE]);
        mysql_tquery(ourConnection, query);
    }

    mysql_format(ourConnection, query, sizeof(query), "DELETE FROM compensation_codes");
    mysql_tquery(ourConnection, query);

    SendInfoMessage(playerid, "[COMPENSATION] All compensation codes have been cleared successfully!");
    return 1;
}

CMD:claim(playerid, params[])
{
    ShowPlayerDialog(playerid, DIALOG_COMPENTATION, DIALOG_STYLE_INPUT, "Claim Compensation:", "Enter your compensation code:", "Submit", "Cancel");
    return 1;
}

function:CompensationCallback(playerid, codeid)
{
    new rows, fields; 
	cache_get_row_count(rows);
	cache_get_field_count(fields);
    if (rows > 0)
    {
        SendErrorMessage(playerid, "You have already claimed this compensation code.");
    }
    else
    {
        new moneyc = CompetationInfo[codeid][E_COMPETATION_MONEY];
        GiveMoney(playerid, moneyc);
        
        CompetationInfo[codeid][E_COMPETATION_USED]++;

        new query[256];
        mysql_format(ourConnection, query, sizeof(query), "INSERT INTO compensation_claims (player_id, code) VALUES (%d, '%s')", PlayerInfo[playerid][E_CHARACTER_DBID], CompetationInfo[codeid][E_COMPETATION_CODE]);
        mysql_tquery(ourConnection, query);

        mysql_format(ourConnection, query, sizeof(query), "UPDATE compensation_codes SET players_used = players_used + 1 WHERE code = '%s'", CompetationInfo[codeid][E_COMPETATION_CODE]);
        mysql_tquery(ourConnection, query);

        SendInfoMessage(playerid, "[COMPENSATION] You have successfully claimed your compensation!");
    }
    return 1;
}
