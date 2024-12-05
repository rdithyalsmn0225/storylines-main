stock ShowPublicLocation(playerid)
{
	new str[1524];
	format(str, sizeof(str), "Name\tDistance\n");
	forex(i, sizeof(PublicName))
	{
		format(str, sizeof(str), "%s%s\t%.2f Meter\n", str, PublicName[i], GetPlayerDistanceFromPoint(playerid, PublicPoint[i][0], PublicPoint[i][1], PublicPoint[i][2]));
	}
	Dialog_ShowPages(playerid, GPSPUBLIC, DIALOG_STYLE_TABLIST_HEADERS, "GPS: Public", str, "Select", "Close");
	return 1;
}

stock ShowTreeLocation(playerid)
{
	new str[1524];
	format(str, sizeof(str), "Index\tStatus\tDistance\n");
	forex(i, MAX_TREES) if(TreeInfo[i][E_TREE_EXISTS])
	{
		if(TreeInfo[i][E_TREE_TIMER] > 0)
		{
			format(str, sizeof(str), "%s%d\t{FF6347}Unavailable{ffffff}\t%.2f Meter\n", str, i, GetPlayerDistanceFromPoint(playerid, TreeInfo[i][E_TREE_POS][0], TreeInfo[i][E_TREE_POS][1], TreeInfo[i][E_TREE_POS][2]));
		}
		else
		{
			format(str, sizeof(str), "%s%d\t{33AA33}Available{ffffff}\t%.2f Meter\n", str,i, GetPlayerDistanceFromPoint(playerid, TreeInfo[i][E_TREE_POS][0], TreeInfo[i][E_TREE_POS][1], TreeInfo[i][E_TREE_POS][2]));
		}
	}
	return Dialog_ShowPages(playerid, GPSTREE, DIALOG_STYLE_TABLIST_HEADERS, "Tree Location", str, "Find", "Close");
}

stock ShowGarbageLocation(playerid)
{
	new str[1524];
	format(str, sizeof(str), "Index\tStatus\tDistance\n");
	for(new i; i < sizeof(Garbage_Locations); i++)
	{
		for(new b; b < sizeof(Garbage_Locations); b++)
		{
			for (new a = 0; a < GarbageCount; a++) 
			{
				if(GarbageObject[a] != INVALID_OBJECT_ID)
				{
					format(str, sizeof(str), "%s#%d\t{33AA33}Available{ffffff}\t%.2f Meter\n", str, b, GetPlayerDistanceFromPoint(playerid, Garbage_Locations[b][0], Garbage_Locations[b][1], Garbage_Locations[b][2]));
				}
				else
				{
					format(str, sizeof(str), "%s#%d\t{FF6347}Unavailable{ffffff}\t%.2f Meter\n", str, b, GetPlayerDistanceFromPoint(playerid, Garbage_Locations[b][0], Garbage_Locations[b][1], Garbage_Locations[b][2]));
				}
			}
		}
	}
	return Dialog_ShowPages(playerid, GPSGARBAGE, DIALOG_STYLE_TABLIST_HEADERS, "Garbage Location", str, "Find", "Close");
}

stock ShowENEXLocation(playerid)
{
	new str[1524];
	format(str, sizeof(str), "Name\tDistance\n");
	forex(i, sizeof(ENEXName))
	{
		format(str, sizeof(str), "%s%s\t%.2f Meter\n", str, ENEXName[i], GetPlayerDistanceFromPoint(playerid, ENEXPoint[i][0], ENEXPoint[i][1], ENEXPoint[i][2]));
	}
	Dialog_ShowPages(playerid, GPSENEX, DIALOG_STYLE_TABLIST_HEADERS, "GPS: ENEX", str, "Select", "Close");
	return 1;
}

stock ShowJobLocation(playerid)
{
	new str[1524];
	format(str, sizeof(str), "Name\tDistance\n");
	forex(i, sizeof(JobLocName))
	{
		format(str, sizeof(str), "%s%s\t%.2f Meter\n", str, JobLocName[i], GetPlayerDistanceFromPoint(playerid, JobPoint[i][0], JobPoint[i][1], JobPoint[i][2]));
	}
	Dialog_ShowPages(playerid, GPSJOBS, DIALOG_STYLE_TABLIST_HEADERS, "GPS: Jobs", str, "Select", "Close");
	return 1;
}

stock ShowBusinessLocation(playerid)
{
	new str[1524];
	format(str, sizeof(str), "Name\tDistance\n");
	forex(i, MAX_BUSINESS) if(BusinessInfo[i][E_BUSINESS_EXISTS] && BusinessInfo[i][E_BUSINESS_TYPE] != BUSINESS_TYPE_ACID && BusinessInfo[i][E_BUSINESS_TYPE] != BUSINESS_TYPE_GUNSTORE)
	{
		format(str, sizeof(str), "%s%s\t%.2f Meter\n", str, BusinessInfo[i][E_BUSINESS_NAME], GetPlayerDistanceFromPoint(playerid, BusinessInfo[i][E_BUSINESS_ENTRANCEPOS][0], BusinessInfo[i][E_BUSINESS_ENTRANCEPOS][1], BusinessInfo[i][E_BUSINESS_ENTRANCEPOS][2]));
	}
	Dialog_ShowPages(playerid, GPSBIZ, DIALOG_STYLE_TABLIST_HEADERS, "GPS: Business", str, "Select", "Close");
	return 1;
}

GPS_SetPlayerRaceCheckPoint(playerid, type, Float:x, Float:y, Float:z, Float:nextx, Float:nexty, Float:nextz, gps = GPS_NONE)
{
	if(gps == GPS_NONE)
	{
		ShowBoxMessage(playerid, "Go to checkpoint on your maps.", 5);
	}
	
	PlayerCheckpoint[playerid] = gps;
	return SetPlayerRaceCheckpoint(playerid, type, Float:x, Float:y, Float:z, Float:nextx, Float:nexty, Float:nextz, 2.0);
}

GPS_DisablePlayerRaceCheckPoint(playerid)
{
	PlayerCheckpoint[playerid] = GPS_NONE; 
	return DisablePlayerRaceCheckpoint(playerid);
}

// Dialog:
Dialog:GPS(playerid, response, listitem, inputtext[])
{
	if(response)
	{
		switch(listitem)
		{
			case 0: //Point Of Interest
				Dialog_Show(playerid, GPSPOI, DIALOG_STYLE_LIST, "GPS: Point of Interest", "Public Locations\nJobs Locations\nBusiness Locations\nTree Locations", "Select", "Cancel");
			case 1:
				Dialog_Show(playerid, GPSPROP, DIALOG_STYLE_INPUT, "GPS: Properties", "Please enter the address of the properties below:", "Submit", "Cancel");
			case 2: //ENEX
				ShowENEXLocation(playerid);
			case 3: //Disable CP
				GPS_DisablePlayerRaceCheckPoint(playerid);
		}
	}
	return 1;
}

Dialog:GPSPROP(playerid, response, listitem, inputtext[])
{
	if (response)
	{
		if (isnull(inputtext) || strlen(inputtext) > 32)
			return Dialog_Show(playerid, GPSPROP, DIALOG_STYLE_INPUT, "GPS: Properties", "Please enter the address of the properties below:", "Submit", "Cancel");

		for (new i = 1; i != MAX_PROPERTY; i ++)
		{
			if (PropertyInfo[i][E_PROPERTY_DBID] && !strcmp(PropertyInfo[i][E_PROPERTY_ADDRESS], inputtext, true))
			{
				GPS_SetPlayerRaceCheckPoint(playerid, 1, PropertyInfo[i][E_PROPERTY_ENTRANCEPOS][0], PropertyInfo[i][E_PROPERTY_ENTRANCEPOS][1], PropertyInfo[i][E_PROPERTY_ENTRANCEPOS][2], 0.0, 0.0, 0.0);
			}
		}
		Dialog_Show(playerid, GPSPROP, DIALOG_STYLE_INPUT, "GPS: Properties", "No results found for.\nPlease enter the address of the properties below:", "Submit", "Cancel");
	}
	return 1;
}

Dialog:GPSPOI(playerid, response, listitem, inputtext[])
{
	if (response)
	{
		switch (listitem)
		{
			case 0: //Public
			{
				ShowPublicLocation(playerid);
			}
			case 1: //Jobs
			{
				ShowJobLocation(playerid);
			}  
			case 2: //Business
			{
				ShowBusinessLocation(playerid);
			} 
			case 3: //Tree
			{
				ShowTreeLocation(playerid);
			}
		}
	}
	return 1;
}

Dialog:GPSPUBLIC(playerid, response, listitem, inputtext[])
{
	if (response)
	{
		GPS_SetPlayerRaceCheckPoint(playerid, 1, PublicPoint[listitem][0], PublicPoint[listitem][1], PublicPoint[listitem][2], 0.0, 0.0, 0.0);
	}
	return 1;
}

Dialog:GPSBIZ(playerid, response, listitem, inputtext[])
{
	if (response)
	{
		GPS_SetPlayerRaceCheckPoint(playerid, 1, BusinessInfo[listitem+3][E_BUSINESS_ENTRANCEPOS][0], BusinessInfo[listitem+3][E_BUSINESS_ENTRANCEPOS][1], BusinessInfo[listitem+3][E_BUSINESS_ENTRANCEPOS][2], 0.0, 0.0, 0.0);
	}
	return 1;
}

Dialog:GPSGARBAGE(playerid, response, listitem, inputtext[])
{
	if (response)
	{
		GPS_SetPlayerRaceCheckPoint(playerid, 1, Garbage_Locations[listitem][0], Garbage_Locations[listitem][1], Garbage_Locations[listitem][2], 0.0, 0.0, 0.0);
	}
	return 1;
}

Dialog:GPSTREE(playerid, response, listitem, inputtext[])
{
	if (response)
	{
		GPS_SetPlayerRaceCheckPoint(playerid, 1, TreeInfo[listitem][E_TREE_POS][0], TreeInfo[listitem][E_TREE_POS][1], TreeInfo[listitem][E_TREE_POS][2], 0.0, 0.0, 0.0);
	}
	return 1;
}

Dialog:GPSENEX(playerid, response, listitem, inputtext[])
{
	if (response)
	{
		GPS_SetPlayerRaceCheckPoint(playerid, 1, ENEXPoint[listitem][0], ENEXPoint[listitem][1], ENEXPoint[listitem][2], 0.0, 0.0, 0.0);
	}
	return 1;
}

Dialog:GPSJOBS(playerid, response, listitem, inputtext[])
{
	if (response)
	{
		GPS_SetPlayerRaceCheckPoint(playerid, 1, JobPoint[listitem][0], JobPoint[listitem][1], JobPoint[listitem][2], 0.0, 0.0, 0.0);
	}
	return 1;
}

// CMD:
CMD:map(playerid, params[]) return cmd_gps(playerid, params);
CMD:gps(playerid, params[])
{
	Dialog_Show(playerid, GPS, DIALOG_STYLE_LIST, "GPS:", "Point of Interest\nBrowse All Properties\nBrowse All ENEX\n{cd6767}Disable Checkpoint", "Select", "Cancel");
	return 1;
}