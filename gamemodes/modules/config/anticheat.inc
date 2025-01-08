//Anti-Cheat

stock PauseAC(playerid)
{
	ACPauseTimer[playerid] = 30;
	return 1;
}

//Variable Check
new bool:AC_VHEALTH;
new bool:AC_ARMOR;
new bool:AC_HEALTH;
new bool:AC_FLY;
new bool:AC_WEAPON;
new bool:AC_MONEY;
new bool:AC_JETPACK;
new bool:AC_REM;
new bool:AC_WARP;
new bool:AC_VGOD;
new bool:AC_TELEPORT;


new 
    Float:ac_fly_x[MAX_PLAYERS],
    Float:ac_fly_y[MAX_PLAYERS],
    Float:ac_fly_z[MAX_PLAYERS];

new player_rpc_count[MAX_PLAYERS];
new player_rpc_last_time[MAX_PLAYERS];

new LastEnteredVehicle[MAX_PLAYERS];

new playerTeleportDelay[MAX_PLAYERS];
new playerInterior[MAX_PLAYERS];
new Float: playerPos[MAX_PLAYERS][3];

new playerTpDetections[MAX_PLAYERS];
new lastPlayerTpDetection[MAX_PLAYERS];

new legalmods[48][22] = {
        {400, 1024,1021,1020,1019,1018,1013,0000,0000,0000,0000,0000,0000,0000,0000,0000,0000,0000,0000},
        {401, 1145,1144,1143,1142,1020,1019,1017,1013,1007,1006,1005,1004,1003,1001,0000,0000,0000,0000},
        {404, 1021,1020,1019,1017,1016,1013,1007,1002,1000,0000,0000,0000,0000,0000,0000,0000,0000,0000},
        {405, 1023,1021,1020,1019,1018,1014,1001,1000,0000,0000,0000,0000,0000,0000,0000,0000,0000,0000},
        {410, 1024,1023,1021,1020,1019,1017,1013,1007,1003,1001,0000,0000,0000,0000,0000,0000,0000,0000},
        {415, 1023,1019,1018,1017,1007,1003,1001,0000,0000,0000,0000,0000,0000,0000,0000,0000,0000,0000},
        {418, 1021,1020,1016,1006,1002,0000,0000,0000,0000,0000,0000,0000,0000,0000,0000,0000,0000,0000},
        {420, 1021,1019,1005,1004,1003,1001,0000,0000,0000,0000,0000,0000,0000,0000,0000,0000,0000,0000},
        {421, 1023,1021,1020,1019,1018,1016,1014,1000,0000,0000,0000,0000,0000,0000,0000,0000,0000,0000},
        {422, 1021,1020,1019,1017,1013,1007,0000,0000,0000,0000,0000,0000,0000,0000,0000,0000,0000,0000},
        {426, 1021,1019,1006,1005,1004,1003,1001,0000,0000,0000,0000,0000,0000,0000,0000,0000,0000,0000},
        {436, 1022,1021,1020,1019,1017,1013,1007,1006,1003,1001,0000,0000,0000,0000,0000,0000,0000,0000},
        {439, 1145,1144,1143,1142,1023,1017,1013,1007,1003,1001,0000,0000,0000,0000,0000,0000,0000,0000},
        {477, 1021,1020,1019,1018,1017,1007,1006,0000,0000,0000,0000,0000,0000,0000,0000,0000,0000,0000},
        {478, 1024,1022,1021,1020,1013,1012,1005,1004,0000,0000,0000,0000,0000,0000,0000,0000,0000,0000},
        {489, 1024,1020,1019,1018,1016,1013,1006,1005,1004,1002,1000,0000,0000,0000,0000,0000,0000,0000},
        {491, 1145,1144,1143,1142,1023,1021,1020,1019,1018,1017,1014,1007,1003,0000,0000,0000,0000,0000},
        {492, 1016,1006,1005,1004,1000,0000,0000,0000,0000,0000,0000,0000,0000,0000,0000,0000,0000,0000},
        {496, 1143,1142,1023,1020,1019,1017,1011,1007,1006,1003,1002,1001,0000,0000,0000,0000,0000,0000},
        {500, 1024,1021,1020,1019,1013,0000,0000,0000,0000,0000,0000,0000,0000,0000,0000,0000,0000,0000},
        {516, 1021,1020,1019,1018,1017,1016,1015,1007,1004,1002,1000,0000,0000,0000,0000,0000,0000,0000},
        {517, 1145,1144,1143,1142,1023,1020,1019,1018,1017,1016,1007,1003,1002,0000,0000,0000,0000,0000},
        {518, 1145,1144,1143,1142,1023,1020,1018,1017,1013,1007,1006,1005,1003,1001,0000,0000,0000,0000},
        {527, 1021,1020,1018,1017,1015,1014,1007,1001,0000,0000,0000,0000,0000,0000,0000,0000,0000,0000},
        {529, 1023,1020,1019,1018,1017,1012,1011,1007,1006,1003,1001,0000,0000,0000,0000,0000,0000,0000},
        {534, 1185,1180,1179,1178,1127,1126,1125,1124,1123,1122,1106,1101,1100,0000,0000,0000,0000,0000},
        {535, 1121,1120,1119,1118,1117,1116,1115,1114,1113,1110,1109,0000,0000,0000,0000,0000,0000,0000},
        {536, 1184,1183,1182,1181,1128,1108,1107,1105,1104,1103,0000,0000,0000,0000,0000,0000,0000,0000},
        {540, 1145,1144,1143,1142,1024,1023,1020,1019,1018,1017,1007,1006,1004,1001,0000,0000,0000,0000},
        {542, 1145,1144,1021,1020,1019,1018,1015,1014,0000,0000,0000,0000,0000,0000,0000,0000,0000,0000},
        {546, 1145,1144,1143,1142,1024,1023,1019,1018,1017,1007,1006,1004,1002,1001,0000,0000,0000,0000},
        {547, 1143,1142,1021,1020,1019,1018,1016,1003,1000,0000,0000,0000,0000,0000,0000,0000,0000,0000},
        {549, 1145,1144,1143,1142,1023,1020,1019,1018,1017,1012,1011,1007,1003,1001,0000,0000,0000,0000},
        {550, 1145,1144,1143,1142,1023,1020,1019,1018,1006,1005,1004,1003,1001,0000,0000,0000,0000,0000},
        {551, 1023,1021,1020,1019,1018,1016,1006,1005,1003,1002,0000,0000,0000,0000,0000,0000,0000,0000},
        {558, 1168,1167,1166,1165,1164,1163,1095,1094,1093,1092,1091,1090,1089,1088,0000,0000,0000,0000},
        {559, 1173,1162,1161,1160,1159,1158,1072,1071,1070,1069,1068,1067,1066,1065,0000,0000,0000,0000},
        {560, 1170,1169,1141,1140,1139,1138,1033,1032,1031,1030,1029,1028,1027,1026,0000,0000,0000,0000},
        {561, 1157,1156,1155,1154,1064,1063,1062,1061,1060,1059,1058,1057,1056,1055,1031,1030,1027,1026},
        {562, 1172,1171,1149,1148,1147,1146,1041,1040,1039,1038,1037,1036,1035,1034,0000,0000,0000,0000},
        {565, 1153,1152,1151,1150,1054,1053,1052,1051,1050,1049,1048,1047,1046,1045,0000,0000,0000,0000},
        {567, 1189,1188,1187,1186,1133,1132,1131,1130,1129,1102,0000,0000,0000,0000,0000,0000,0000,0000},
        {575, 1177,1176,1175,1174,1099,1044,1043,1042,0000,0000,0000,0000,0000,0000,0000,0000,0000,0000},
        {576, 1193,1192,1191,1190,1137,1136,1135,1134,0000,0000,0000,0000,0000,0000,0000,0000,0000,0000},
        {580, 1023,1020,1018,1017,1007,1006,1001,0000,0000,0000,0000,0000,0000,0000,0000,0000,0000,0000},
        {589, 1145,1144,1024,1020,1018,1017,1016,1013,1007,1006,1005,1004,1000,0000,0000,0000,0000,0000},
        {600, 1022,1020,1018,1017,1013,1007,1006,1005,1004,0000,0000,0000,0000,0000,0000,0000,0000,0000},
        {603, 1145,1144,1143,1142,1024,1023,1020,1019,1018,1017,1007,1006,1001,0000,0000,0000,0000,0000}
};

stock DistancePointToPoint(Float: x, Float: y, Float: z, Float: fx, Float:fy, Float: fz) return floatround(floatsqroot(floatpower(fx - x, 2) + floatpower(fy - y, 2) + floatpower(fz - z, 2)));


// AC CONFIG:
stock InsertAntiCheat()
{
    AC_VHEALTH	    = true;
	AC_ARMOR		= true;
	AC_HEALTH		= true;
	AC_FLY		    = true;
	AC_WEAPON		= true;
	AC_MONEY		= true;
	AC_JETPACK	    = true;
	AC_REM	    	= true;
	AC_WARP        	= true;
    AC_TELEPORT     = true;
    AC_VGOD         = true;
    return 1;
}

stock ResetTeleportAC(playerid) {
    playerTeleportDelay[playerid] = 0;
    playerInterior[playerid] = 0;
    playerTpDetections[playerid] = 0;
    lastPlayerTpDetection[playerid] = 0;
    return 1;
}

// VEHICLE WARP CHECK:
function:PlayerPutIntoVehicle(playerid, vehicleid, seatid)
{
    LastEnteredVehicle[playerid] = vehicleid;
    PauseAC(playerid);
    PutPlayerInVehicle(playerid, vehicleid, seatid);
    return 1;
}

// VEHICLE MOD CHECK:
iswheelmodel(modelid) {
 
    new wheelmodels[17] = {1025,1073,1074,1075,1076,1077,1078,1079,1080,1081,1082,1083,1084,1085,1096,1097,1098};
 
    for(new I = 0, b = sizeof(wheelmodels); I != b; ++I) {
        if (modelid == wheelmodels[I])
            return 1;
 
    }
 
    return 0;
}
 
IllegalCarNitroIde(carmodel) {
 
    new illegalvehs[29] = { 581, 523, 462, 521, 463, 522, 461, 448, 468, 586, 509, 481, 510, 472, 473, 493, 595, 484, 430, 453, 452, 446, 454, 590, 569, 537, 538, 570, 449 };
 
    for(new I = 0, b = sizeof(illegalvehs); I != b; ++I) {
 
        if (carmodel == illegalvehs[I])
            return 1;
 
    }
 
    return 0;
}

 
islegalcarmod(vehicleide, componentid) 
{
    new modok = false;
 
    if ((iswheelmodel(componentid)) || (componentid == 1086) || (componentid == 1087) || ((componentid >= 1008) && (componentid <= 1010))) {
 
        new nosblocker = IllegalCarNitroIde(vehicleide);
 
        if (!nosblocker)
            modok = true;
 
    } else {
        for(new I = 0, b = sizeof(legalmods); I != b; ++I) {
 
            if (legalmods[I][0] == vehicleide) {
 
                for(new J = 1; J < 22; J++) {
                    if (legalmods[I][J] == componentid)
                        modok = true;
                }
 
            }
 
        }
 
    }
 
    return modok;
}

// VEHICLE CHECK:
stock VehicleSpeedCheck(vehicleid)
{
        if(vehicleid != INVALID_VEHICLE_ID)
        {
            new Float:Pos[3],Float:VS ;
            GetVehicleVelocity(vehicleid, Pos[0], Pos[1], Pos[2]);
            VS = floatsqroot(Pos[0]*Pos[0] + Pos[1]*Pos[1] + Pos[2]*Pos[2])*200;
            return floatround(VS,floatround_round);
        }
        return INVALID_VEHICLE_ID;
}

// SPEED CHECK:
stock PlayerSpeedCheck(playerid)
{
    if(playerid != INVALID_PLAYER_ID)
    {
        new Float:Pos[3],Float:PS;
        GetPlayerVelocity(playerid, Pos[0], Pos[1], Pos[2]);
        PS = floatsqroot(Pos[0]*Pos[0] + Pos[1]*Pos[1] + Pos[2]*Pos[2])*200;
        return floatround(PS,floatround_round);
    }
    return INVALID_PLAYER_ID;
}

stock SetPlayerHealthEx(playerid, Float:value)
{
	PauseAC(playerid);

    PlayerInfo[playerid][E_CHARACTER_HEALTH] = value;
    if(PlayerInfo[playerid][E_CHARACTER_HEALTH] > PlayerInfo[playerid][E_CHARACTER_MAXHEALTH])
    {
        PlayerInfo[playerid][E_CHARACTER_HEALTH] = PlayerInfo[playerid][E_CHARACTER_MAXHEALTH];
    }
    if(PlayerInfo[playerid][E_CHARACTER_HEALTH] == PlayerInfo[playerid][E_CHARACTER_MAXHEALTH])
    {
        PlayerInfo[playerid][E_CHARACTER_BODYPART][0] = 100;
        PlayerInfo[playerid][E_CHARACTER_BODYPART][1] = 100;
        PlayerInfo[playerid][E_CHARACTER_BODYPART][2] = 100;
        PlayerInfo[playerid][E_CHARACTER_BODYPART][3] = 100;
        PlayerInfo[playerid][E_CHARACTER_BODYPART][4] = 100;
        PlayerInfo[playerid][E_CHARACTER_BODYPART][5] = 100;
        PlayerInfo[playerid][E_CHARACTER_BODYPART][6] = 100;
        PlayerInfo[playerid][E_CHARACTER_BODYPART][7] = 100;

        PlayerInfo[playerid][E_CHARACTER_WOUND][0] = 0;
        PlayerInfo[playerid][E_CHARACTER_WOUND][1] = 0;
        PlayerInfo[playerid][E_CHARACTER_WOUND][2] = 0;
        PlayerInfo[playerid][E_CHARACTER_WOUND][3] = 0;
        PlayerInfo[playerid][E_CHARACTER_WOUND][4] = 0;
        PlayerInfo[playerid][E_CHARACTER_WOUND][5] = 0;
        PlayerInfo[playerid][E_CHARACTER_WOUND][6] = 0;
        PlayerInfo[playerid][E_CHARACTER_WOUND][7] = 0;
    }
	SetPlayerHealth(playerid, PlayerInfo[playerid][E_CHARACTER_HEALTH]);
    
    if(value <= 10) SetPlayerWeaponSkill(playerid, NORMAL_SKILL);
    else if(value >= 11 && value <= 30) SetPlayerWeaponSkill(playerid, MEDIUM_SKILL);
    else SetPlayerWeaponSkill(playerid, FULL_SKILL);
	
	SaveCharacter(playerid);
	return 1;
}

stock SetPlayerArmourEx(playerid, Float:value)
{
	PauseAC(playerid);
	PlayerInfo[playerid][E_CHARACTER_ARMOUR] = value;
	SetPlayerArmour(playerid, value);
	SaveCharacter(playerid);
	return 1;
}

// VEHICLE CHECK:
stock VehicleOnAntiCheatUpdate(vehicleid)
{
	new Float:currenthp, csh, cch;
	GetVehicleHealth(vehicleid, currenthp);

	cch = floatround(currenthp);
	csh = floatround(VehicleInfo[vehicleid][E_VEHICLE_HEALTH]);

	if(cch > csh) return false;
	VehicleInfo[vehicleid][E_VEHICLE_HEALTH] = currenthp;
	return 1;
}

// ARMOUR CHECK:
stock ArmourOnAntiCheatUpdate(playerid)
{
	GetPlayerArmour(playerid, CurrentArmourVar[playerid]);
	new cav = floatround(CurrentArmourVar[playerid]), av = floatround(PlayerInfo[playerid][E_CHARACTER_ARMOUR]);
	if(cav > av) return false;
	PlayerInfo[playerid][E_CHARACTER_ARMOUR] = CurrentArmourVar[playerid];
	return 1;
}

// HEALTH CHECK:
stock HealthOnAntiCheatUpdate(playerid)
{
	GetPlayerHealth(playerid, CurrentHealthVar[playerid]);
	new chv = floatround(CurrentHealthVar[playerid]), hv = floatround(PlayerInfo[playerid][E_CHARACTER_HEALTH]);
	if(chv > hv) return false;
	PlayerInfo[playerid][E_CHARACTER_HEALTH] = CurrentHealthVar[playerid];
	return 1;
}

// PAUSED CHECK:
stock PauseVehicleAC(vehicleid)
{
	VehicleInfo[vehicleid][E_VEHICLE_VCTIMER] = 5 * 4;
	return 1;
}

// WEAPONS CHECK:
static const WeaponSlots[] = {
    0, 0, 1, 1, 1, 1, 1, 1, 1, 
    1, 10, 10, 10, 10, 10, 10, 
    8, 8, 8, 0, 0, 0, 2, 2, 2, 
    3, 3, 3, 4, 4, 5, 5, 4, 6, 
    6, 7, 7, 7, 7, 8, 12, 9, 9, 
    9, 11, 11, 11
};

stock GetPlayerWeaponVar(playerid)
{
    new weaponid = GetPlayerWeapon(playerid);

    if(1 <= weaponid <= 46 && PlayerInfo[playerid][E_CHARACTER_WEAPONS][WeaponSlots[weaponid]] == weaponid)
        return weaponid;

    return 0;
}


// AC CHECK:
function:OnAntiCheatUpdate()
{
    foreach(new playerid : Player)
	{
        if(ACPauseTimer[playerid] != 0)
		{
			ACPauseTimer[playerid] --;
		}
        if(ACPauseTimer[playerid] < 0)
		{
			ACPauseTimer[playerid] = 0;
		}

        if(VehicleInfo[GetPlayerVehicleID(playerid)][E_VEHICLE_VCTIMER] != 0) VehicleInfo[GetPlayerVehicleID(playerid)][E_VEHICLE_VCTIMER] --;
        if(VehicleInfo[GetPlayerVehicleID(playerid)][E_VEHICLE_VCTIMER] < 0) VehicleInfo[GetPlayerVehicleID(playerid)][E_VEHICLE_VCTIMER] = 0;

        if(GetPlayerSpecialAction(playerid) == SPECIAL_ACTION_USEJETPACK && ACPauseTimer[playerid] == 0 && PlayerInfo[playerid][E_CHARACTER_SPAWNED] == true)
		{
	    	if(AC_JETPACK == true)
			{
                new gstr[128], str1[128];
				format(gstr, sizeof(gstr), "[ANTI-CHEAT] %s has been detected for using program hack [Jetpack Hack]", ReturnMixedName(playerid));
                SendClientMessage(playerid, COLOR_YELLOW, gstr);
                KickEx(playerid);

                format(str1, sizeof(str1), "%s has been detected for using program hack [Jetpack Hack]", ReturnMixedName(playerid)); 
		        SendAdminMessage(1, str1);
			}
 
		}

        if(AC_WARP == true)
        {
            if(ACPauseTimer[playerid] == 0 && PlayerInfo[playerid][E_CHARACTER_SPAWNED] == true)
		    {
                new vehicleid = GetPlayerVehicleID(playerid);
                if (vehicleid && vehicleid != LastEnteredVehicle[playerid])
                {
                    LastEnteredVehicle[playerid] = vehicleid;
                    
                    new gstr[128];
                    format(gstr, sizeof(gstr), "[ANTI-CHEAT] %s has been detected for using program hack [Vehicle WARP Hack]", ReturnMixedName(playerid));
                    SendClientMessage(playerid, COLOR_YELLOW, gstr);
                    KickEx(playerid);

                    new str1[128];
                    format(str1, sizeof(str1), "%s has been detected for using program hack [Vehicle WARP Hack]", ReturnMixedName(playerid)); 
		            SendAdminMessage(1, str1);
                }
            }
 
        }

        if(AC_REM == true)
		{
            if(ACPauseTimer[playerid] == 0 && PlayerInfo[playerid][E_CHARACTER_SPAWNED] == true)
		    {
                if(GetPlayerWeapon(playerid) == 40)
                {
                    new gstr[128];
                    format(gstr, sizeof(gstr), "[ANTI-CHEAT] %s has been detected for using program hack [Crash Hack]", ReturnMixedName(playerid));
                    SendClientMessage(playerid, COLOR_YELLOW, gstr);
                    KickEx(playerid);

                    new str1[128];
                    format(str1, sizeof(str1), "%s has been detected for using program hack [Crash Hack]", ReturnMixedName(playerid)); 
		            SendAdminMessage(1, str1);
                }
            }
        }

        if(GetPlayerMoney(playerid) > PlayerInfo[playerid][E_CHARACTER_MONEY] && ACPauseTimer[playerid] == 0 && PlayerInfo[playerid][E_CHARACTER_SPAWNED] == true)
		{
			new Diff = GetPlayerMoney(playerid) - PlayerInfo[playerid][E_CHARACTER_MONEY], gstr[128];
			if(Diff > 10000)
			{
				if(AC_MONEY == true)
				{
					format(gstr, sizeof(gstr), "[ANTI-CHEAT] %s has been detected for using program hack [Money Hack]", ReturnMixedName(playerid));
                    SendClientMessage(playerid, COLOR_YELLOW, gstr);
                    GivePlayerMoney(playerid, PlayerInfo[playerid][E_CHARACTER_MONEY]);
                    KickEx(playerid);
                    new str1[128];
                    format(str1, sizeof(str1), "%s has been detected for using program hack [Money Hack]", ReturnMixedName(playerid)); 
		            SendAdminMessage(1, str1); 
				}
			}
		}

        if(ACPauseTimer[playerid] == 0 && !Inventory_Count(playerid, "Colt 45") || !Inventory_Count(playerid, "Silenced Colt") || !Inventory_Count(playerid, "Uzi") || !Inventory_Count(playerid, "Shotgun") || !Inventory_Count(playerid, "Desert Eagle") 
        || !Inventory_Count(playerid, "Desert Eagle") || !Inventory_Count(playerid, "Spike Bat") || !Inventory_Count(playerid, "Cutscene Bat") || !Inventory_Count(playerid, "Baseball Bat") || !Inventory_Count(playerid, "Extinguisher")  || !Inventory_Count(playerid, "Broom")
        || !Inventory_Count(playerid, "Pisswasher") || !Inventory_Count(playerid, "Marcos Knife") || !Inventory_Count(playerid, "Knife") || !Inventory_Count(playerid, "Glove") || !Inventory_Count(playerid, "Hammer") || !Inventory_Count(playerid, "Wrench") || !Inventory_Count(playerid, "Regular Ammo") 
        || !Inventory_Count(playerid, "Surplus Ammo") && !PlayerInfo[playerid][E_CHARACTER_WEAPONTYPE] && !PlayerInfo[playerid][E_CHARACTER_AMMOTYPE] && !PlayerInfo[playerid][E_CHARACTER_POLICEGUN])
		{
			new clientID, clientAmmo, gstr[128];
            for(new w = 0; w < 12; w++)
			{
                GetPlayerWeaponData(playerid, w, clientID, clientAmmo);

                if(clientID > 0 && clientAmmo > 0)
				{
                    if(PlayerInfo[playerid][E_CHARACTER_WEAPONS][w] != clientID)
					{
                        if(AC_WEAPON == true)
                        {
                            
                            format(gstr, sizeof(gstr), "[ANTI-CHEAT] %s has been detected for using program hack [Weapon Hack]", ReturnMixedName(playerid));
                            SendClientMessage(playerid, COLOR_YELLOW, gstr);
                            KickEx(playerid);

                            new str1[128];
                            format(str1, sizeof(str1), "%s has been detected for using program hack [Weapon Hack]", ReturnMixedName(playerid)); 
                            SendAdminMessage(1, str1);
                        }
                    }
                }
            }
 
        }
        if(AC_FLY == true)
		{
            new Float:_x, Float:_y, Float:_z, distance, gstr[128];
            switch(GetPlayerState(playerid))
	        {
                /*case PLAYER_STATE_DRIVER:
                {
                    if(PlayerInfo[playerid][E_CHARACTER_SPAWNED] == true && ACPauseTimer[playerid] == 0)
                    {
                        GetVehiclePos(GetPlayerVehicleID(playerid), _x, _y, _z);
                        distance = floatround(DistancePointToPoint(_x, _y, _z, ac_fly_x[playerid], ac_fly_y[playerid], ac_fly_z[playerid]));
                        if((!VehicleSpeedCheck(GetPlayerVehicleID(playerid)) && floatround(_z - ac_fly_z[playerid]) == 0 && distance >= 20) || distance > 200)
                        {
                            SetPlayerPos(playerid, PlayerInfo[playerid][E_CHARACTER_LASTPOS][0], PlayerInfo[playerid][E_CHARACTER_LASTPOS][1], PlayerInfo[playerid][E_CHARACTER_LASTPOS][2]);
                            format(gstr, sizeof(gstr), "[ANTI-CHEAT] %s has been detected for using program hack [Vehicle Fly Hack]", ReturnMixedName(playerid));
                            SendClientMessage(playerid, COLOR_YELLOW, gstr);
                            KickEx(playerid);

                            new str1[128];
                            format(str1, sizeof(str1), "%s has been detected for using program hack [Vehicle Fly Hack]", ReturnMixedName(playerid)); 
                            SendAdminMessage(1, str1);
                        }
                    }
                }*/
                case PLAYER_STATE_ONFOOT:
                { 
                    if(PlayerInfo[playerid][E_CHARACTER_SPAWNED] == true && ACPauseTimer[playerid] == 0)
                    {
                        GetPlayerPos(playerid, _x, _y, _z);
                        distance = floatround(DistancePointToPoint(_x, _y, _z, ac_fly_x[playerid], ac_fly_y[playerid], ac_fly_z[playerid]));
                        if((!PlayerSpeedCheck(playerid) && floatround(_z - ac_fly_z[playerid]) == 0 && distance >= 2) || distance > 8)
                        {
                            switch(GetPlayerAnimationIndex(playerid))
                            {
                                case 958, 959, 963, 1060, 1097:
                                {
                                    SetPlayerPos(playerid, PlayerInfo[playerid][E_CHARACTER_LASTPOS][0], PlayerInfo[playerid][E_CHARACTER_LASTPOS][1], PlayerInfo[playerid][E_CHARACTER_LASTPOS][2]);
                                    format(gstr, sizeof(gstr), "[ANTI-CHEAT] %s has been detected for using program hack [Fly Hack]", ReturnMixedName(playerid));
                                    SendClientMessage(playerid, COLOR_YELLOW, gstr);
                                    KickEx(playerid);

                                    new str1[128];
                                    format(str1, sizeof(str1), "%s has been detected for using program hack [Fly Hack]", ReturnMixedName(playerid)); 
                                    SendAdminMessage(1, str1);
                                }
                            }
                        }
                    }
                }
            }
 
        }
        if(AC_HEALTH == true)
		{
			if(PlayerInfo[playerid][E_CHARACTER_SPAWNED] == true)
			{
				if(ACPauseTimer[playerid] == 0)
				{
					if(!HealthOnAntiCheatUpdate(playerid))
					{
						new Float:currenthealth, gstr[128];
						GetPlayerHealth(playerid, currenthealth);
                        SetPlayerHealthEx(playerid, PlayerInfo[playerid][E_CHARACTER_HEALTH]);

						format(gstr, sizeof(gstr), "[ANTI-CHEAT] %s has been detected for using program hack [Health Hack]", ReturnMixedName(playerid));
                        SendClientMessage(playerid, COLOR_YELLOW, gstr);
                        KickEx(playerid);

                        new str1[128];
                        format(str1, sizeof(str1), "%s has been detected for using program hack [Health Hack]", ReturnMixedName(playerid)); 
                        SendAdminMessage(1, str1);
					}
				}
			}
 
		}
        if(AC_ARMOR == true)
		{
			if(PlayerInfo[playerid][E_CHARACTER_SPAWNED] == true)
			{
				if(ACPauseTimer[playerid] == 0)
				{
					if(!ArmourOnAntiCheatUpdate(playerid))
					{
						new gstr[128];

                        SetPlayerArmour(playerid, PlayerInfo[playerid][E_CHARACTER_ARMOUR]);
						format(gstr, sizeof(gstr), "[ANTI-CHEAT] %s has been detected for using program hack [Armour Hack]", ReturnMixedName(playerid));
                        SendClientMessage(playerid, COLOR_YELLOW, gstr);
                        KickEx(playerid);

                        new str1[128];
                        format(str1, sizeof(str1), "%s has been detected for using program hack [Armour Hack]", ReturnMixedName(playerid)); 
                        SendAdminMessage(1, str1);
					}
				}
			}
 
		}
        if(AC_VHEALTH == true)
        {
            if(ACPauseTimer[playerid] == 0 && IsPlayerInAnyVehicle(playerid))
            {
                if(GetPlayerState(playerid) == PLAYER_STATE_DRIVER && VehicleInfo[GetPlayerVehicleID(playerid)][E_VEHICLE_ADMIN] == false && VehicleInfo[GetPlayerVehicleID(playerid)][E_VEHICLE_VCTIMER] == 0)
                {
                    new v = GetPlayerVehicleID(playerid);
                    if(!VehicleOnAntiCheatUpdate(v))
                    {
                        new Float:vhealth, gstr[128];
                        GetVehicleHealth(v, vhealth);

                        if(vhealth != VehicleInfo[GetPlayerVehicleID(playerid)][E_VEHICLE_HEALTH])
                        {
                            SetVehicleHealth(v, VehicleInfo[GetPlayerVehicleID(playerid)][E_VEHICLE_HEALTH]);

                            format(gstr, sizeof(gstr), "[ANTI-CHEAT] %s has been detected for using program hack [Vehicle Repair]", ReturnMixedName(playerid));
                            SendClientMessage(playerid, COLOR_YELLOW, gstr);
                            KickEx(playerid);

                            new str1[128];
                            format(str1, sizeof(str1), "%s has been detected for using program hack [Vehicle Repair]", ReturnMixedName(playerid)); 
                            SendAdminMessage(1, str1);
                        }
                    }
                }
            }
 
        }
        if(!IsPlayerAdmins(playerid) && GetPlayerSpecialAction(playerid) == SPECIAL_ACTION_USEJETPACK)
        {
            KickEx(playerid);
        }
    }
    return 1;
}

public OnVehicleDamageStatusUpdate(vehicleid, playerid)
{
	if (playerid != INVALID_PLAYER_ID)
    {
        new Float:health, gstr[128];
        GetVehicleHealth(vehicleid, health);

        // Jika kendaraan dalam kondisi god mode (tidak rusak sama sekali)
        if ((health >= VehicleInfo[vehicleid][E_VEHICLE_HEALTH] + 10.0))
        {
            if(PlayerInfo[playerid][E_CHARACTER_SPAWNED] == true)
			{
				if(ACPauseTimer[playerid] == 0 && AC_VGOD == true)
				{
                    if(VehicleInfo[vehicleid][E_VEHICLE_ADMIN])
                        return 0;
                        
					format(gstr, sizeof(gstr), "[ANTI-CHEAT] %s has been detected for using program hack [Vehicle God Hack]", ReturnMixedName(playerid));
                    SendClientMessage(playerid, COLOR_YELLOW, gstr);
					KickEx(playerid);

					new str1[128];
					format(str1, sizeof(str1), "%s has been detected for using program hack [Vehicle God Hack]", ReturnMixedName(playerid)); 
					SendAdminMessage(1, str1);
				}
			}
        }
    }
    return 1;
}

public OnVehicleMod(playerid, vehicleid, componentid)
{
	#if defined DEBUG_MODE
		printf("Callback OnVehicleMod called for player %s (ID: %i) vehicleid %s (ID: %i) componentid %i", ReturnName(playerid), playerid, ReturnVehicleName(vehicleid), vehicleid, componentid); 
	#endif

	new str1[128], gstr[128];
	new vehicleide = GetVehicleModel(vehicleid);
    new modok = islegalcarmod(vehicleide, componentid);
    if (!modok && ACPauseTimer[playerid] == 0 && PlayerInfo[playerid][E_CHARACTER_SPAWNED] == true) {

        format(gstr, sizeof(gstr), "[ANTI-CHEAT] %s has been detected for using program hack [Vehicle Mod Hack]", ReturnMixedName(playerid));
        SendClientMessage(playerid, COLOR_YELLOW, gstr);
        KickEx(playerid);

        format(str1, sizeof(str1), "%s has been detected for using program hack [Vehicle Mod Hack]", ReturnName(playerid)); 
		SendAdminMessage(1, str1);
        return 0; 
    }
	return 1;
}

public OnIncomingRPC(playerid, rpcid, BitStream:bs)
{
	#if defined DEBUG_MODE
		printf("Callback OnIncomingRPC called for player %s (ID: %i) rpcid : %d BitStream : %d", ReturnName(playerid), playerid, rpcid, bs); 
	#endif

    if (rpcid == 136)
    {
        new currentTime = GetTickCount();

        if (player_rpc_count[playerid] == 0)
        {
            player_rpc_count[playerid] = 1;
            player_rpc_last_time[playerid] = currentTime;
        }
        else
        {
            if (currentTime - player_rpc_last_time[playerid] <= 3000)
            {
                player_rpc_count[playerid]++;
                if (player_rpc_count[playerid] >= 5)
                {
                    new gstr[128];
                    format(gstr, sizeof(gstr), "[ANTI-CHEAT] %s has been detected for using program hack [Rem.cs]", ReturnMixedName(playerid));
                    SendClientMessage(playerid, COLOR_YELLOW, gstr);
					KickEx(playerid);

					new str1[128];
					format(str1, sizeof(str1), "%s has been detected for using program hack [Vehicle Repair]", ReturnMixedName(playerid)); 
					SendAdminMessage(1, str1);

                    player_rpc_count[playerid] = 0;
                    player_rpc_last_time[playerid] = 0;
                }
            }
            else
            {

                player_rpc_count[playerid] = 1;
                player_rpc_last_time[playerid] = currentTime;
            }
        }
    }
    return 1;
}

function:CBugFreezeOver(playerid)
{
	TogglePlayerControllable(playerid, true);
	pCBugging[playerid] = false;
    ClearAnimations(playerid);
	return 1;
}

stock TeleportACSpawn(playerid) { 
    GetPlayerPos(playerid, playerPos[playerid][0], playerPos[playerid][1], playerPos[playerid][2]);
    return 1;
}


const PLAYER_SYNC = 207;

IPacket:PLAYER_SYNC(playerid, BitStream:bs) {

    new onFootData[PR_OnFootSync];
    BS_IgnoreBits(bs, 8);
    BS_ReadOnFootSync(bs, onFootData);

    if(PlayerInfo[playerid][E_CHARACTER_SPAWNED] == true && AC_TELEPORT == true) {
        if (ACPauseTimer[playerid] == 0) {

            if (gettime() > playerTeleportDelay[playerid]){
                    
                new 
                    Float: distance = GetPlayerDistanceFromPoint(playerid, playerPos[playerid][0], playerPos[playerid][1], playerPos[playerid][2]),
                    Float:limit_distance = 15.0,
                    player_state = GetPlayerState(playerid);
                
                if (GetPlayerTeam(playerid) == PLAYER_STATE_DEAD || GetPlayerTeam(playerid) == PLAYER_STATE_WOUNDED) distance = 3.0;
                else
                {
                    switch(player_state)
                    {
                        case PLAYER_STATE_ONFOOT: limit_distance = 35.0;
                        case PLAYER_STATE_DRIVER, PLAYER_STATE_PASSENGER: limit_distance = 150.0;
                    }
                }

                if((onFootData[PR_surfingOffsets][0] != 0.0) && (onFootData[PR_surfingOffsets][1] != 0.0) && (onFootData[PR_surfingOffsets][2] != 0.0)){
                    limit_distance = 150.0;
                }

                if(IsABike(GetPlayerSurfingVehicleID(playerid))){
                    return 1;
                }

                if (distance > limit_distance && ACPauseTimer[playerid] == 0)
                {
                    lastPlayerTpDetection[playerid] = gettime();
                    ++ playerTpDetections[playerid];

                    if (playerTpDetections[playerid] >= 2)
                    {
                        new gstr[128];
                        format(gstr, sizeof(gstr), "[ANTI-CHEAT] %s has been detected for using program hack [Teleport On-Foot]", ReturnMixedName(playerid));
                        SendClientMessage(playerid, COLOR_YELLOW, gstr);
                        KickEx(playerid);
                    }
                }

                GetPlayerPos(playerid, playerPos[playerid][0], playerPos[playerid][1], playerPos[playerid][2]);
                playerTeleportDelay[playerid] = (gettime() + 2);
            }

        } else {
            GetPlayerPos(playerid, playerPos[playerid][0], playerPos[playerid][1], playerPos[playerid][2]); 
        }
    }

    return 1;
}

const VEHICLE_SYNC = 200;

IPacket:VEHICLE_SYNC(playerid, BitStream:bs)
{

    new inCarData[PR_InCarSync];
    BS_IgnoreBits(bs, 8);
    BS_ReadInCarSync(bs, inCarData);

    if(PlayerInfo[playerid][E_CHARACTER_SPAWNED] == true && AC_TELEPORT == true) {
        if (ACPauseTimer[playerid] == 0) {

            if (gettime() > playerTeleportDelay[playerid]){
                    
                new Float: distance = GetPlayerDistanceFromPoint(playerid, inCarData[PR_position][0], inCarData[PR_position][1], inCarData[PR_position][2]);

	            if (distance > 150.0 && ACPauseTimer[playerid] == 0)
			    {
                    lastPlayerTpDetection[playerid] = gettime();
                    ++ playerTpDetections[playerid];

                    if (playerTpDetections[playerid] >= 2)
                    {
                        new gstr[128];
                        format(gstr, sizeof(gstr), "[ANTI-CHEAT] %s has been detected for using program hack [Teleport In-Vehicle]", ReturnMixedName(playerid));
                        SendClientMessage(playerid, COLOR_YELLOW, gstr);
                        KickEx(playerid);
                    }
                }

                playerPos[playerid][0] = inCarData[PR_position][0];
                playerPos[playerid][1] = inCarData[PR_position][1];
                playerPos[playerid][2] = inCarData[PR_position][2];

                playerTeleportDelay[playerid] = (gettime() + 2);
            }
        } else {
            playerPos[playerid][0] = inCarData[PR_position][0];
            playerPos[playerid][1] = inCarData[PR_position][1];
            playerPos[playerid][2] = inCarData[PR_position][2];
        }
    }

    return 1;
}
