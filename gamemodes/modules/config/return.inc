stock ReturnIP(playerid)
{
	new
		ipAddress[20];

	GetPlayerIp(playerid, ipAddress, sizeof(ipAddress));
	return ipAddress; 
}

stock ReturnGPCI(playerid)
{
	new szSerial[41]; // 40 + \0
 
	gpci(playerid, szSerial, sizeof(szSerial));
	return szSerial;
}

stock ReturnLastOnline(playerid)
{
	new returnString[90]; 
	
	if(isnull(PlayerInfo[playerid][E_CHARACTER_LASTONLINEDATE]))
		returnString = "Never";
	
	else
		format(returnString, 90, "%s", PlayerInfo[playerid][E_CHARACTER_LASTONLINEDATE]);
	
	return returnString;
}

stock ReturnTotalMembers(factionid)
{
	if(factionid == 0 || !FactionInfo[factionid][E_FACTION_DBID])
		return 0; 
		
	new threadCheck[128], counter;
	
	mysql_format(ourConnection, threadCheck, sizeof(threadCheck), "SELECT COUNT(*) FROM characters WHERE pFaction = %i", factionid);
	mysql_query(ourConnection, threadCheck); 
	
	cache_get_value_index_int(0, 0, counter);
	return counter;
}

stock ReturnOnlineMembers(factionid)
{
	new counter;
		
	foreach(new i : Player)
	{
		if(AccountInfo[i][E_MASTERS_LOGGED] == false)
			continue;
		
		if(PlayerInfo[i][E_CHARACTER_FACTION] == factionid)
		{
			counter++;
		}
	}
	return counter;
}

stock ReturnFactionName(playerid)
{
	new factionName[90];
	
	if(!PlayerInfo[playerid][E_CHARACTER_FACTION])
		factionName = "Hoodrats";
		
	else
		format(factionName, sizeof(factionName), "%s", FactionInfo[PlayerInfo[playerid][E_CHARACTER_FACTION]][E_FACTION_NAME]);
		
	return factionName;
}

stock ReturnFactionNameEx(factionid)
{
	new factionName[90];
	
	if(factionid == 0)
	{
		format(factionName, sizeof(factionName), "Hoodrats");
	}
	else

	format(factionName, sizeof(factionName), "%s", FactionInfo[factionid][E_FACTION_NAME]);
	return factionName;
}

stock ReturnFactionAbbrev(factionid)
{		
	 new facAbbrev[90];
	 
	 format(facAbbrev, sizeof(facAbbrev), "%s", FactionInfo[factionid][E_FACTION_ABBREV]);
	 return facAbbrev; 
}

stock ReturnFactionType(playerid)
{
	if(!PlayerInfo[playerid][E_CHARACTER_FACTION])
		return 0;
	
	return FactionInfo[PlayerInfo[playerid][E_CHARACTER_FACTION]][E_FACTION_TYPE];
}

stock ReturnDate()
{
	new sendString[90], MonthStr[40], month, day, year;
	new hour, minute, second;
	
	gettime(hour, minute, second);
	getdate(year, month, day);
	switch(month)
	{
	    case 1:  MonthStr = "January";
	    case 2:  MonthStr = "February";
	    case 3:  MonthStr = "March";
	    case 4:  MonthStr = "April";
	    case 5:  MonthStr = "May";
	    case 6:  MonthStr = "June";
	    case 7:  MonthStr = "July";
	    case 8:  MonthStr = "August";
	    case 9:  MonthStr = "September";
	    case 10: MonthStr = "October";
	    case 11: MonthStr = "November";
	    case 12: MonthStr = "December";
	}
	
	format(sendString, 90, "%s %d, %d %02d:%02d:%02d", MonthStr, day, year, hour, minute, second);
	return sendString;
}

ReturnName(playerid, underscore=0)
{
	static
	    name[MAX_PLAYER_NAME + 1];

	GetPlayerName(playerid, name, sizeof(name));

	if (!underscore) {
	    for (new i = 0, len = strlen(name); i < len; i ++) {
	        if (name[i] == '_') name[i] = ' ';
		}
	}
	if (PlayerInfo[playerid][E_CHARACTER_MASKON])
	    format(name, sizeof(name), "Mask_#%d", PlayerInfo[playerid][E_CHARACTER_MASKID]);

	return name;
}

static stock g_arrVehicleNames[][] = {
    "Landstalker", "Bravura", "Buffalo", "Linerunner", "Perrenial", "Sentinel", "Dumper", "Firetruck", "Trashmaster",
    "Stretch", "Manana", "Infernus", "Voodoo", "Pony", "Mule", "Cheetah", "Ambulance", "Leviathan", "Moonbeam",
    "Esperanto", "Taxi", "Washington", "Bobcat", "Whoopee", "BF Injection", "Hunter", "Premier", "Enforcer",
    "Securicar", "Banshee", "Predator", "Bus", "Rhino", "Barracks", "Hotknife", "Trailer", "Previon", "Coach",
    "Cabbie", "Stallion", "Rumpo", "RC Bandit", "Romero", "Packer", "Monster", "Admiral", "Squalo", "Seasparrow",
    "Pizzaboy", "Tram", "Trailer", "Turismo", "Speeder", "Reefer", "Tropic", "Flatbed", "Yankee", "Caddy", "Solair",
    "Berkley's RC Van", "Skimmer", "PCJ-600", "Faggio", "Freeway", "RC Baron", "RC Raider", "Glendale", "Oceanic",
    "Sanchez", "Sparrow", "Patriot", "Quad", "Coastguard", "Dinghy", "Hermes", "Sabre", "Rustler", "ZR-350", "Walton",
    "Regina", "Comet", "BMX", "Burrito", "Camper", "Marquis", "Baggage", "Dozer", "Maverick", "News Chopper", "Rancher",
    "FBI Rancher", "Virgo", "Greenwood", "Jetmax", "Hotring", "Sandking", "Blista Compact", "Police Maverick",
    "Boxville", "Benson", "Mesa", "RC Goblin", "Hotring Racer A", "Hotring Racer B", "Bloodring Banger", "Rancher",
    "Super GT", "Elegant", "Journey", "Bike", "Mountain Bike", "Beagle", "Cropduster", "Stunt", "Tanker", "Roadtrain",
    "Nebula", "Majestic", "Buccaneer", "Shamal", "Hydra", "FCR-900", "NRG-500", "HPV1000", "Cement Truck", "Tow Truck",
    "Fortune", "Cadrona", "SWAT Truck", "Willard", "Forklift", "Tractor", "Combine", "Feltzer", "Remington", "Slamvan",
    "Blade", "Streak", "Freight", "Vortex", "Vincent", "Bullet", "Clover", "Sadler", "Firetruck", "Hustler", "Intruder",
    "Primo", "Cargobob", "Tampa", "Sunrise", "Merit", "Utility", "Nevada", "Yosemite", "Windsor", "Monster", "Monster",
    "Uranus", "Jester", "Sultan", "Stratum", "Elegy", "Raindance", "RC Tiger", "Flash", "Tahoma", "Savanna", "Bandito",
    "Freight Flat", "Streak Carriage", "Kart", "Mower", "Dune", "Sweeper", "Broadway", "Tornado", "AT-400", "DFT-30",
    "Huntley", "Stafford", "BF-400", "News Van", "Tug", "Trailer", "Emperor", "Wayfarer", "Euros", "Hotdog", "Club",
    "Freight Box", "Trailer", "Andromada", "Dodo", "RC Cam", "Launch", "LSPD Cruiser", "SFPD Cruiser", "LVPD Cruiser",
    "Police Rancher", "Picador", "S.W.A.T", "Alpha", "Phoenix", "Glendale", "Sadler", "Luggage", "Luggage", "Stairs",
    "Boxville", "Tiller", "Utility Trailer"
};

stock ReturnVehicleName(vehicleid)
{
	new
		model = GetVehicleModel(vehicleid),
		name[32] = "None";

    if (model < 400 || model > 611)
	    return name;

	format(name, sizeof(name), g_arrVehicleNames[model - 400]);
	return name;
}

ReturnVehicleHealth(vehicleid)
{
	if (!IsValidVehicle(vehicleid))
	    return 0;

	static
	    Float:amount;

	GetVehicleHealth(vehicleid, amount);
	return floatround(amount, floatround_round);
}

stock ReturnVehicleModelName(model)
{
	new
	    name[32] = "None";

    if (model < 400 || model > 611)
	    return name;

	format(name, sizeof(name), g_arrVehicleNames[model - 400]);
	return name;
}

stock ResetVehicleVars(vehicleid)
{
	if(vehicleid == INVALID_VEHICLE_ID)
		return 0;
		
	VehicleInfo[vehicleid][E_VEHICLE_DBID] = 0; 
	VehicleInfo[vehicleid][E_VEHICLE_EXISTS] = false;
	
	VehicleInfo[vehicleid][E_VEHICLE_OWNERDBID] = 0;
	
	VehicleInfo[vehicleid][E_VEHICLE_IMPOUND] = false;
	VehicleInfo[vehicleid][E_VEHICLE_PAINTJOB] = -1; 
	
	VehicleInfo[vehicleid][E_VEHICLE_FUEL] = 100.0; 
	
	for(new i = 1; i < 5; i++)
	{
		VehicleInfo[vehicleid][E_VEHICLE_LASTDRIVER][i] = 0;
		VehicleInfo[vehicleid][E_VEHICLE_LASTPASSENGERS][i] = 0;
	}
	
	VehicleInfo[vehicleid][E_VEHICLE_TOWCOUNT] = 0;
	
	VehicleInfo[vehicleid][E_VEHICLE_DESTROYED] = 0;
	
	VehicleInfo[vehicleid][E_VEHICLE_ENGINE] = false;
	VehicleInfo[vehicleid][E_VEHICLE_LIGHTS] = false;
	return 1;
}

stock ReturnDBIDName(dbid)
{
	new query[120], returnString[60];
	
	mysql_format(ourConnection, query, sizeof(query), "SELECT char_name FROM characters WHERE char_dbid = %i", dbid); 
	new Cache:cache = mysql_query(ourConnection, query);
	
	if(!cache_num_rows())
		returnString = "None";
		
	else
		cache_get_value_name(0, "char_name", returnString);
	
	cache_delete(cache);
	return returnString;
}

ReturnMixedName(playerid) 
{
	new name[64], shortname[MAX_PLAYER_NAME];
	format(shortname, sizeof ( shortname ), "%s", PlayerInfo[playerid][E_CHARACTER_NAME]) ;
    strdel(shortname, 0, strfind(shortname,"_",true) + 1);

    format(name, sizeof(name), "%s (%.1s. %s)", AccountInfo[playerid][E_MASTERS_ACCNAME], PlayerInfo[playerid][E_CHARACTER_NAME], shortname ) ;
    return name;
}

stock ReturnDBIDFromName(name[])
{
	new checkQuery[128], dbid;
	
	mysql_format(ourConnection, checkQuery, sizeof(checkQuery), "SELECT char_dbid FROM characters WHERE char_name = '%e'", name);
	new Cache:cache = mysql_query(ourConnection, checkQuery); 
	
	
	if(!cache_num_rows())
	{
		cache_delete(cache);
		return 0;
	}
	
	cache_get_value_name_int(0, "char_dbid", dbid); 
	cache_delete(cache);
	return dbid; 
}

stock ReturnChannelName(channel)
{
	new channelName[24];

	switch(channel)
	{
	    case 1:
			channelName = "CENTRAL"; // LSPD
	    case 2:
			channelName = "CW.TAC1"; // LSPD
	    case 3:
			channelName = "CW.TAC2"; // LSPD
		case 4:
		    channelName = "CW.TAC3"; // LSPD
	    case 5:
			channelName = "24.CTD"; // LSPD
	    case 6:
			channelName = "53.DBU"; // LSPD
		case 7:
		    channelName = "54.GND"; // LSPD
		case 8:
		    channelName = "55.OCVD"; // LSPD
		case 9:
			channelName = "65.METRO"; // LSPD
		case 10:
			channelName = "31.IAG"; // LSPD
		default:
			format(channelName, 24, "%d", channel);
	}

	return channelName;
}