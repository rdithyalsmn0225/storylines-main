function:OnPlayerVIPUpdate()
{
    foreach(new ii : Player)
    {
        if(AccountInfo[ii][E_MASTERS_VIP] > 0)
        {
            if(AccountInfo[ii][E_MASTERS_VIPTIMER] != 0 && AccountInfo[ii][E_MASTERS_VIPTIMER] <= gettime())
            {
                AccountInfo[ii][E_MASTERS_VIPTIMER] = 0;
                AccountInfo[ii][E_MASTERS_VIP] = 0;
                SendServerMessage(ii, "Sorry, your VIP player level has expired! now you are a regular player!");
            }
        }
    }
    return 1;
}

CMD:setvip(playerid, params[])
{
	if(IsPlayerAdmins(playerid) < ADMINS_OPERATOR)
		return 0;
	
	new alevel, dayz, otherid, str[128];
	if(sscanf(params, "udd", otherid, alevel, dayz))
	    return SendUsageMessage(playerid, "/setvip [playerid OR name] [level 0 - 3] [time (in days) 0 for permanent]");

	if(!IsPlayerConnected(otherid))
        return SendErrorMessage(playerid, "Player not connected!");
	if(alevel > 3)
		return SendErrorMessage(playerid, "Level can't be higher than 3!");
	if(alevel < 0)
		return SendErrorMessage(playerid, "Level can't be lower than 0!");
	if(dayz < 0)
		return SendErrorMessage(playerid, "Time can't be lower than 0!");
		
	if (AccountInfo[otherid][E_MASTERS_LOGGED] == false)
        return SendErrorMessage(playerid, "The player you specified isn't logged in.");
	
	AccountInfo[otherid][E_MASTERS_VIP] = alevel;
	if(dayz == 0)
	{
		AccountInfo[otherid][E_MASTERS_VIPTIMER] = 0;
		SendServerMessage(otherid, "%s has set your VIP level %s permanent!", ReturnMixedName(playerid), playerid, ReturnVIPLevel(otherid));

        format(str, sizeof(str), "%s gave vip to %s permanent", ReturnMixedName(playerid), ReturnMixedName(otherid));
        SendAdminMessage(3, str);
	}
	else
	{
		AccountInfo[otherid][E_MASTERS_VIPTIMER] = gettime() + (dayz * 86400);
		SendServerMessage(otherid, "%s(%d) has set your VIP level %s for %d days!", ReturnMixedName(playerid), ReturnVIPLevel(otherid), dayz);

        format(str, sizeof(str), "%s gave vip to %s for %d days", ReturnMixedName(playerid), ReturnMixedName(otherid), dayz);
        SendAdminMessage(3, str);
	}
	return 1;
}

CMD:streetshop(playerid, params[])
{
	new str[512];
	strcat(str, "Items\tPrice\n");
	strcat(str, "Change Phone Number\t50\n");
	strcat(str, "Change Mask ID\t70\n");
	strcat(str, "Change Name\t150\n");
	strcat(str, "VIP Supreme Player 7 Days\t80\n");
	strcat(str, "VIP Legend Player 7 Days\t120\n");
	strcat(str, "VIP Ultimate Player 7 Days\t150");
	ShowPlayerDialog(playerid, DIALOG_STREETSHOP, DIALOG_STYLE_TABLIST_HEADERS, "Street Shop:", str, "Select", "Close");
	return 1;
}