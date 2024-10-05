stock ShowPublicLocation(playerid)
{
	new str[1024];
	format(str, sizeof(str), "Name\tDistance\n");
	forex(i, sizeof(PublicName))
	{
		format(str, sizeof(str), "%s%s\t%.2f Meter\n", str, PublicName[i], GetPlayerDistanceFromPoint(playerid, PublicPoint[i][0], PublicPoint[i][1], PublicPoint[i][2]));
	}
	ShowPlayerDialog(playerid, DIALOG_GPS_PUBLIC, DIALOG_STYLE_TABLIST_HEADERS, "GPS: Public", str, "Select", "Close");
	return 1;
}

stock ShowENEXLocation(playerid)
{
	new str[1024];
	format(str, sizeof(str), "Name\tDistance\n");
	forex(i, sizeof(ENEXName))
	{
		format(str, sizeof(str), "%s%s\t%.2f Meter\n", str, ENEXName[i], GetPlayerDistanceFromPoint(playerid, ENEXPoint[i][0], ENEXPoint[i][1], ENEXPoint[i][2]));
	}
	ShowPlayerDialog(playerid, DIALOG_GPS_PUBLIC, DIALOG_STYLE_TABLIST_HEADERS, "GPS: ENEX", str, "Select", "Close");
	return 1;
}

stock ShowJobLocation(playerid)
{
	new str[1024];
	format(str, sizeof(str), "Name\tDistance\n");
	forex(i, sizeof(JobLocName))
	{
		format(str, sizeof(str), "%s%s\t%.2f Meter\n", str, JobLocName[i], GetPlayerDistanceFromPoint(playerid, JobPoint[i][0], JobPoint[i][1], JobPoint[i][2]));
	}
	ShowPlayerDialog(playerid, DIALOG_GPS_JOBS, DIALOG_STYLE_TABLIST_HEADERS, "GPS: Jobs", str, "Select", "Close");
	return 1;
}

stock ShowBusinessLocation(playerid)
{
	new str[1024];
	format(str, sizeof(str), "Name\tDistance\n");
	forex(i, MAX_BUSINESS) if(BusinessInfo[i][E_BUSINESS_EXISTS])
	{
		format(str, sizeof(str), "%s%s\t%.2f Meter\n", str, BusinessInfo[i][E_BUSINESS_NAME], GetPlayerDistanceFromPoint(playerid, BusinessInfo[i][E_BUSINESS_ENTRANCEPOS][0], BusinessInfo[i][E_BUSINESS_ENTRANCEPOS][1], BusinessInfo[i][E_BUSINESS_ENTRANCEPOS][2]));
	}
	ShowPlayerDialog(playerid, DIALOG_GPS_BUSINESS, DIALOG_STYLE_TABLIST_HEADERS, "GPS: Business", str, "Select", "Close");
	return 1;
}

CMD:map(playerid, params[]) return cmd_gps(playerid, params);
CMD:gps(playerid, params[])
{
	ShowPlayerDialog(playerid, DIALOG_GPS, DIALOG_STYLE_LIST, "GPS:", "Point of Interest\nBrowse All Properties\nBrowse All ENEX\n{cd6767}Disable Checkpoint", "Select", "Cancel");
	return 1;
}

GPS_SetPlayerRaceCheckPoint(playerid, type, Float:x, Float:y, Float:z, Float:nextx, Float:nexty, Float:nextz, gps = GPS_NONE)
{
	ShowBoxMessage(playerid, "Go to checkpoint on your maps.", 5, 2);
	PlayerCheckpoint[playerid] = gps;
	return SetPlayerRaceCheckpoint(playerid, type, Float:x, Float:y, Float:z, Float:nextx, Float:nexty, Float:nextz, 2.0);
}

GPS_DisablePlayerRaceCheckPoint(playerid)
{
	PlayerCheckpoint[playerid] = GPS_NONE; 
	return DisablePlayerRaceCheckpoint(playerid);
}