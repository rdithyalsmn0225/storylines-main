function:OnPlayerReport(playerid, reportid, const text[])
{
	if(ReportInfo[reportid][E_REPORT_EXISTS] == true)
	{
		for (new i = 1; i < sizeof(ReportInfo); i ++)
		{
			if(ReportInfo[i][E_REPORT_EXISTS] == false)
			{
				reportid = i;
				break;
			}
		}
	}
		
	ReportInfo[reportid][E_REPORT_EXISTS] = true;
	ReportInfo[reportid][E_REPORT_TIME] = gettime();
		
	format(ReportInfo[reportid][E_REPORT_DETAILS], 90, "%s", text);
	ReportInfo[reportid][E_REPORT_BY] = playerid;
		
	SendClientMessageEx(playerid, COLOR_WHITE, "Report: Your report was sent to all online admins.");
		
	if(strlen(text) > 67)
	{
		SendAdminMessageEx(COLOR_REPORT, 1, "[Report: %d] %s (%d): %.75s", reportid, ReturnSettingsName(playerid, playerid), playerid, text);
		SendAdminMessageEx(COLOR_REPORT, 1, "[Report: %d] ...%s", reportid, text[75]);
	}
	else SendAdminMessageEx(COLOR_REPORT, 1, "[Report: %d] %s (%d): %s", reportid, ReturnSettingsName(playerid, playerid), playerid, text);
		
	if(strfind(text, "hack", true) != -1 || strfind(text, "cheat", true) != -1)
	{
		foreach(new i : Player)
		{
			if(PlayerInfo[i][E_CHARACTER_ADMIN]) GameTextForPlayer(i, "~y~~h~Priority Report", 4000, 1);
		}
	}
	return 1;
}

function:ClearReports(playerid, response, reports)
{
	if(response)
	{
		for (new i = 0; i < sizeof(ReportInfo); i ++)
		{
			ReportInfo[i][E_REPORT_EXISTS] = false;
			ReportInfo[i][E_REPORT_DETAILS] = ' '; 
			ReportInfo[i][E_REPORT_BY] = INVALID_PLAYER_ID;
			ReportInfo[i][E_REPORT_TIME] = 0; 
		}
		
		new str[128];
		
		format(str, sizeof(str), "%s cleared %d active reports.", ReturnSettingsName(playerid, playerid), reports);
		SendAdminMessage(1, str); 
	}
	else return SendClientMessageEx(playerid, COLOR_WHITE, "Report: You cancelled the confirmation.");
	return 1;
}