#define MAX_COMPENSATION (1)
enum E_COMPETATION_DATA
{
    E_COMPETATION_DBID,
    E_COMPETATION_CODE[32],
    E_COMPETATION_PLAYERS,
    E_COMPETATION_EXPIRED,
    E_COMPETATION_MONEY,
    E_COMPETATION_USED,
    bool:E_COMPETATION_EXISTS
};
new CompetationInfo[MAX_COMPENSATION][E_COMPETATION_DATA];

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
        cache_get_value_name_int(i, "players_used", CompetationInfo[i][E_COMPETATION_USED]);
        CompetationInfo[i][E_COMPETATION_CODE] = true;
        total++;
	}	

    printf("[SERVER]: %i compensation were loaded from \"%s\" database...", total, SQL_DATABASE);
    return 1;
}

function:CleanupExpiredCodes()
{
    for (new i = 0; i < MAX_COMPENSATION; i++)
    {
        if (gettime() > CompetationInfo[i][E_COMPETATION_EXPIRED] || CompetationInfo[i][E_COMPETATION_USED] >= CompetationInfo[i][E_COMPETATION_PLAYERS])
        {
            new query[256];
            mysql_format(ourConnection, query, sizeof(query), "DELETE FROM compensation_codes WHERE code = '%s'", CompetationInfo[i][E_COMPETATION_CODE]);
            mysql_tquery(ourConnection, query);

            mysql_format(ourConnection, query, sizeof(query), "DELETE FROM compensation_claims WHERE code = '%s'", CompetationInfo[i][E_COMPETATION_CODE]);
            mysql_tquery(ourConnection, query);

            CompetationInfo[i][E_COMPETATION_CODE] = false;
        }
    }
    return 1;
}

CMD:createcode(playerid, params[])
{
    if(IsPlayerAdmins(playerid) < ADMINS_OPERATOR)
        return 0;

    new code[32], players, days, moneyc;
    if (sscanf(params, "s[32]iii", code, players, days, moneyc))
        return SendUsageMessage(playerid, "/createcode [code] [max players] [days] [money]");

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
    CompetationInfo[freeSlot][E_COMPETATION_USED] = 0;
    CompetationInfo[freeSlot][E_COMPETATION_EXISTS] = true;
    
    
    new query[256];
    mysql_format(ourConnection, query, sizeof(query), "INSERT INTO compensation_codes (code, max_players, expired, money, players_used) VALUES ('%s', %d, %d, %d, 0)", code, players, expired, Cents);
    mysql_tquery(ourConnection, query);

    SendServerMessage(playerid, "[Compensation] {DEDEDE}Compensation code created successfully!");
    return 1;
}

CMD:claim(playerid, params[])
{
    Dialog_Show(playerid, Compensation, DIALOG_STYLE_INPUT, "Claim Compensation:", "Enter your compensation code:", "Submit", "Cancel");
    return 1;
}

Dialog:Compensation(playerid, response, listitem, inputtext[])
{
    for (new i = 0; i < MAX_COMPENSATION; i++)
    {
        if (strcmp(CompetationInfo[i][E_COMPETATION_CODE], inputtext, true) == 0 && CompetationInfo[i][E_COMPETATION_EXISTS])
        {
            if (gettime() > CompetationInfo[i][E_COMPETATION_EXPIRED])
            {
                new query[256];
                mysql_format(ourConnection, query, sizeof(query), "DELETE FROM compensation_codes WHERE code = '%s'", CompetationInfo[i][E_COMPETATION_CODE]);
                mysql_tquery(ourConnection, query);

                mysql_format(ourConnection, query, sizeof(query), "DELETE FROM compensation_claims WHERE code = '%s'", CompetationInfo[i][E_COMPETATION_CODE]);
                mysql_tquery(ourConnection, query);

                CompetationInfo[i][E_COMPETATION_EXISTS] = false;
                
                return SendErrorMessage(playerid, "This compensation code has expired.");
            }

            if (CompetationInfo[i][E_COMPETATION_USED] >= CompetationInfo[i][E_COMPETATION_PLAYERS])
            {
                new query[256];
                mysql_format(ourConnection, query, sizeof(query), "DELETE FROM compensation_codes WHERE code = '%s'", CompetationInfo[i][E_COMPETATION_CODE]);
                mysql_tquery(ourConnection, query);

                mysql_format(ourConnection, query, sizeof(query), "DELETE FROM compensation_claims WHERE code = '%s'", CompetationInfo[i][E_COMPETATION_CODE]);
                mysql_tquery(ourConnection, query);

                CompetationInfo[i][E_COMPETATION_EXISTS] = false;

                return SendErrorMessage(playerid, "This compensation code has reached its limit.");
            }

            new query[256];
            mysql_format(ourConnection, query, sizeof(query), "SELECT * FROM compensation_claims WHERE player_id = %d AND code = '%s'", PlayerInfo[playerid][E_CHARACTER_DBID], inputtext);
            mysql_pquery(ourConnection, query, "CompensationCallback", "ii", playerid, i);
        }
        else
        {
            SendErrorMessage(playerid, "Invalid or not available compensation code at this time.");
        }
    }
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

        SendServerMessage(playerid, "[Competation] {DEDEDE}You have successfully claimed your compensation!");
    }
    return 1;
}
