Ticket_Add(suspectid, price, reason[])
{
	new
	    string[160];

	for (new i = 0; i != MAX_TICKETS; i ++) if (!TicketInfo[suspectid][i][E_TICKET_EXISTS])
	{
	    TicketInfo[suspectid][i][E_TICKET_EXISTS] = true;
	    TicketInfo[suspectid][i][E_TICKET_FEE] = price;

	    format(TicketInfo[suspectid][i][E_TICKET_DATE], 36, ReturnDate());
	    format(TicketInfo[suspectid][i][E_TICKET_REASON], 64, reason);

		format(string, sizeof(string), "INSERT INTO `tickets` (`ID`, `Fee`, `Date`, `Reason`) VALUES('%d', '%d', '%s', '%s')", PlayerInfo[suspectid][E_CHARACTER_DBID], price, TicketInfo[suspectid][i][E_TICKET_DATE], reason);
		mysql_pquery(ourConnection, string, "OnTicketCreated", "dd", suspectid, i);

		return i;
	}
	return -1;
}

Ticket_Remove(playerid, ticketid)
{
	if (ticketid != -1 && TicketInfo[playerid][ticketid][E_TICKET_EXISTS])
	{
	    new
	        string[90];

		format(string, sizeof(string), "DELETE FROM `tickets` WHERE `ID` = '%d' AND `DBID` = '%d'", PlayerInfo[playerid][E_CHARACTER_DBID], TicketInfo[playerid][ticketid][E_TICKET_DBID]);
		mysql_pquery(ourConnection, string);

	    TicketInfo[playerid][ticketid][E_TICKET_EXISTS] = false;
	    TicketInfo[playerid][ticketid][E_TICKET_DBID] = 0;
	    TicketInfo[playerid][ticketid][E_TICKET_FEE] = 0;
	}
	return 1;
}

function:OnTicketCreated(playerid, ticketid)
{
	TicketInfo[playerid][ticketid][E_TICKET_DBID] = cache_insert_id();
	return 1;
}

function:Query_LoadTicket(playerid)
{
    new rows, fields;
    cache_get_row_count(rows);
    cache_get_field_count(fields);

    for (new i = 0; i < rows && i < MAX_TICKETS; i ++) 
    {
        cache_get_value_name(i, "Reason", TicketInfo[playerid][i][E_TICKET_REASON], 64);
		cache_get_value_name(i, "Date", TicketInfo[playerid][i][E_TICKET_DATE], 36);
        cache_get_value_name_int(i, "DBID", TicketInfo[playerid][i][E_TICKET_DBID]);
		cache_get_value_name_int(i, "Fee", TicketInfo[playerid][i][E_TICKET_FEE]);
        TicketInfo[playerid][i][E_TICKET_EXISTS] = true;
    }
    printf("[SERVER]: %s ticket were loaded from \"%s\" database...", ReturnName(playerid), SQL_DATABASE);
    return 1;
}

CMD:ticket(playerid, params[])
{
	new
	    userid,
	    price,
	    reason[64];

	if (ReturnFactionType(playerid) != FACTION_TYPE_POLICE)
		return SendErrorMessage(playerid, "You can't use this command..");

    if(!PlayerInfo[playerid][E_CHARACTER_POLICEDUTY])
		return SendUnauthMessage(playerid);

	if (sscanf(params, "ufs[64]", userid, price, reason))
		return SendUsageMessage(playerid, "/ticket [playerid/name] [price] [reason]");

	if (userid == INVALID_PLAYER_ID || !IsPlayerNearPlayer(playerid, userid, 5.0))
	    return SendErrorMessage(playerid, "That player is disconnected or not near you.");

	if (userid == playerid)
	    return SendErrorMessage(playerid, "You can't write a ticket to yourself.");

	if (price < 1.00 || price > 200.00)
	    return SendErrorMessage(playerid, "The price can't be below $1.00 or above $1.000.00.");

	new Cents = floatround(price * 100, floatround_round);

	new id = Ticket_Add(userid, Cents, reason);

	if (id != -1) {
	    SendServerMessage(playerid, "[Tickets] {DEDEDE}You have written %s a ticket for $%s, reason: %s", ReturnName(userid, 0), FormatMoney(Cents), reason);
	    SendServerMessage(userid, "[Tickets] {DEDEDE}%s has written you a ticket for $%s, reason: %s", ReturnName(playerid, 0), FormatMoney(Cents), reason);

	    SendNearbyMessage(playerid, 30.0, COLOR_EMOTE, "** %s has written up a ticket for%s.", ReturnName(playerid, 0), ReturnName(userid, 0));
	}
	else return SendErrorMessage(playerid, "That player already has %d outstanding tickets.", MAX_TICKETS);
	return 1;
}

CMD:tickets(playerid, params[])
{
	new
	    string[MAX_TICKETS * 64];

	if (!IsPlayerInRangeOfPoint(playerid, 3.0, 249.1299,67.8123,1003.6406))
	    return SendErrorMessage(playerid, "You aren't in los santos police departement.");

	string[0] = 0;

    format(string, sizeof(string), "Reason\tFee\tDate\n");
	for (new i = 0; i < MAX_TICKETS; i ++)
	{
	    if (TicketInfo[playerid][i][E_TICKET_EXISTS])
	        format(string, sizeof(string), "%s[SLOT]: %s\t%s\t%s\n", string, TicketInfo[playerid][i][E_TICKET_REASON], FormatMoney(TicketInfo[playerid][i][E_TICKET_FEE]), TicketInfo[playerid][i][E_TICKET_DATE]);

		else format(string, sizeof(string), "%s[SLOT]: <EMPTY>\n", string);
	}
	return Dialog_Show(playerid, Tickets, DIALOG_STYLE_TABLIST_HEADERS, "Tickets:", string, "Pay", "Cancel");
}

Dialog:Tickets(playerid, response, listitem, inputtext[])
{
	if (response)
	{
	    if (!TicketInfo[playerid][listitem][E_TICKET_EXISTS])
	        return SendErrorMessage(playerid, "There is no ticket in the selected slot.");

		if (TicketInfo[playerid][listitem][E_TICKET_FEE] > PlayerInfo[playerid][E_CHARACTER_MONEY])
		    return SendErrorMessage(playerid, "You can't afford this. (Cost: $%s, Total: $%s)", FormatMoney(TicketInfo[playerid][listitem][E_TICKET_FEE]), FormatMoney(PlayerInfo[playerid][E_CHARACTER_MONEY]));

		GiveMoney(playerid, -TicketInfo[playerid][listitem][E_TICKET_FEE]);

		SendServerMessage(playerid, "[Tickets] {DEDEDE}You have paid off a $%s ticket for %s.", FormatMoney(TicketInfo[playerid][listitem][E_TICKET_FEE]), TicketInfo[playerid][listitem][E_TICKET_REASON]);
		Ticket_Remove(playerid, listitem);
	}
	return 1;
}