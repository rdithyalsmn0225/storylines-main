//Animation
static const g_aPreloadLibs[][] =
{
	"AIRPORT",      "ATTRACTORS",   "BAR",          "BASEBALL",     "BD_FIRE",
	"BEACH",        "BENCHPRESS",   "BF_INJECTION", "BIKE_DBZ",     "BIKED",
	"BIKEH",        "BIKELEAP",     "BIKES",        "BIKEV",        "BLOWJOBZ",
	"BMX",          "BOMBER",       "BOX",          "BSKTBALL",     "BUDDY",
	"BUS",          "CAMERA",       "CAR",          "CAR_CHAT",     "CARRY",
	"CASINO",       "CHAINSAW",     "CHOPPA",       "CLOTHES",      "COACH",
	"COLT45",       "COP_AMBIENT",  "COP_DVBYZ",    "CRACK",        "CRIB",
	"DAM_JUMP",     "DANCING",      "DEALER",       "DILDO",        "DODGE",
	"DOZER",        "DRIVEBYS",     "FAT",          "FIGHT_B",      "FIGHT_C",
	"FIGHT_D",      "FIGHT_E",      "FINALE",       "FINALE2",      "FLAME",
	"FLOWERS",      "FOOD",         "FREEWEIGHTS",  "GANGS",        "GFUNK",
	"GHANDS",       "GHETTO_DB",    "GOGGLES",      "GRAFFITI",     "GRAVEYARD",
	"GRENADE",      "GYMNASIUM",    "HAIRCUTS",     "HEIST9",       "INT_HOUSE",
	"INT_OFFICE",   "INT_SHOP",     "JST_BUISNESS", "KART",         "KISSING",
	"KNIFE",        "LAPDAN1",      "LAPDAN2",      "LAPDAN3",      "LOWRIDER",
	"MD_CHASE",     "MD_END",       "MEDIC",        "MISC",         "MTB",
	"MUSCULAR",     "NEVADA",       "ON_LOOKERS",   "OTB",          "PARACHUTE",
	"PARK",         "PAULNMAC",     "PED",          "PLAYER_DVBYS", "PLAYIDLES",
	"POLICE",       "POOL",         "POOR",         "PYTHON",       "QUAD",
	"QUAD_DBZ",     "RAPPING",      "RIFLE",        "RIOT",         "ROB_BANK",
	"ROCKET",       "RUNNINGMAN",   "RUSTLER",      "RYDER",        "SCRATCHING",
	"SEX",          "SHAMAL",       "SHOP",         "SHOTGUN",      "SILENCED",
	"SKATE",        "SMOKING",      "SNIPER",       "SNM",          "SPRAYCAN",
	"STRIP",        "SUNBATHE",     "SWAT",         "SWEET",        "SWIM",
	"SWORD",        "TANK",         "TATTOOS",      "TEC",          "TRAIN",
	"TRUCK",        "UZI",          "VAN",          "VENDING",      "VORTEX",
	"WAYFARER",     "WEAPONS",      "WOP",          "WUZI"
};

stock PreloadAnimations(playerid)
{
	for (new i = 0; i < sizeof(g_aPreloadLibs); i ++) {
	    ApplyAnimation(playerid, g_aPreloadLibs[i], "null", 4.0, 0, 0, 0, 0, 0, 1);
	}
	return 1;
}

IsAnimationPermitted(playerid)
{
	return (GetPlayerState(playerid) == PLAYER_STATE_ONFOOT && GetPlayerTeam(playerid) == PLAYER_STATE_ALIVE);
}

IsAnimationPermittedInVehicle(playerid)
{
	return (IsPlayerInVehicle(playerid, GetPlayerVehicleID(playerid)) && GetPlayerTeam(playerid) == PLAYER_STATE_ALIVE);
}

ApplyAnimationEx(playerid, animlib[], animname[], Float:fDelta, loop, lockx, locky, freeze, time)
{
	ApplyAnimation(playerid, animlib, animname, fDelta, loop, lockx, locky, freeze, time, 1);

	if(loop > 0 || freeze > 0)
	{
		PlayerInfo[playerid][E_CHARACTER_LOOPANIM] = 1;

	}
}

CMD:animhelp(playerid, params[])
{
	SendClientMessage(playerid, COLOR_DARKGREEN, "|__________ Animations List __________|");
	SendClientMessage(playerid, COLOR_ORANGE, "/dance, /wave, /point, /salute, /laugh, /cry, /deal, /sit, /lay, /fall, /handsup.");
	SendClientMessage(playerid, COLOR_ORANGE, "/tired, /cower, /crack, /injured, /reload, /aim, /bomb, /checktime, /celebrate.");
	SendClientMessage(playerid, COLOR_ORANGE, "/dodge, /stop, /scratch, /what, /wash, /come, /hitch, /cpr, /slapass, /drunk.");
	SendClientMessage(playerid, COLOR_ORANGE, "/shit, /fucku, /taichi, /shifty, /smoke, /lean, /wank, /crossarms, /angry.");
	SendClientMessage(playerid, COLOR_ORANGE, "/lowrider, /vlowrider, /lrtalk, /idles, /flip, /facepalm, /pistolwhip, /jogging.");
	SendClientMessage(playerid, COLOR_ORANGE, "/cmon, /recruit, /gsign, /rap, /dj, /fuckme, /bj, /kiss, /piss, /robman.");
	SendClientMessage(playerid, COLOR_ORANGE, "/getup, /gkick, /plunger, /swipe, /puke.");
	SendTipMessage(playerid, "Search animation by ID '/anim'.");
	SendTipMessage(playerid, "To stop animation type '/stopanim'.");
	return 1;
}

CMD:anim(playerid, params[])
{
	if(!IsAnimationPermitted(playerid))
	{
	    return SendErrorMessage(playerid, "You cannot use this command right now.");
	}

	#if defined ADD_RCON_PROTECTION
	if(!IsPlayerAdmin(playerid))
	return 1;
	#endif
	new
	animlib[32], animname[32],
	iAnimIndex = strval(params);
	if(iAnimIndex < 1 || iAnimIndex >= 1812)return SendUsageMessage(playerid, "/anim (Index 1-1812)");
	else
	{
		GetAnimationName(iAnimIndex, animlib, 32, animname, 32);
		ApplyAnimationEx(playerid , animlib, animname, 2.0, 1, 0, 0, 1, 1);
	}
	return 1;
}

CMD:jogging(playerid)
{
	if(!IsAnimationPermitted(playerid))
	    return SendErrorMessage(playerid, "You cannot use this command right now.");

	ApplyAnimationEx(playerid, "PED", "JOG_maleA", 4.1, 1, 1, 1, 1, 1);
	return 1;
}

CMD:cmon(playerid, params[])
{
    if(!IsAnimationPermitted(playerid))
	    return SendErrorMessage(playerid, "You cannot use this command right now.");

	ApplyAnimationEx(playerid, "CAMERA", "CAMCRCH_CMON", 4.1, 1, 0, 0, 0, 0);
	return 1;
}

CMD:getup(playerid, params[]) 
{
    if(!IsAnimationPermitted(playerid))
	    return SendErrorMessage(playerid, "You cannot use this command right now.");

	ApplyAnimationEx(playerid, "PED", "getup", 4.1, 0, 0, 0, 0, 0);

	return 1;
}


CMD:gkick(playerid, params[]) 
{
    if(!IsAnimationPermitted(playerid))
	    return SendErrorMessage(playerid, "You cannot use this command right now.");

	ApplyAnimationEx(playerid, "FIGHT_D", "FightD_1", 4.1, 1, 0, 0, 0, 0);
	return 1;
}

CMD:plunger(playerid, params[])
{
    if(!IsAnimationPermitted(playerid))
	    return SendErrorMessage(playerid, "You cannot use this command right now.");

	ApplyAnimationEx(playerid, "MISC", "PLUNGER_01", 4.1, 0, 0, 0, 0, 0);
	return 1;
}

CMD:swipe(playerid, params[])
{
    if(!IsAnimationPermitted(playerid))
	    return SendErrorMessage(playerid, "You cannot use this command right now.");

	ApplyAnimationEx(playerid, "HEIST9", "Use_SwipeCard",4.1, 0, 0, 0, 0, 0);
	return 1;
}

CMD:puke(playerid, params[]) 
{
    if(!IsAnimationPermitted(playerid))
	    return SendErrorMessage(playerid, "You cannot use this command right now.");

	ApplyAnimationEx(playerid, "FOOD", "EAT_Vomit_P", 4.1, 0, 0, 0, 0, 0);
	return 1;
}

CMD:pistolwhip(playerid, params[])
{
    if(!IsAnimationPermitted(playerid))
	    return SendErrorMessage(playerid, "You cannot use this command right now.");

	ApplyAnimationEx(playerid, "FLOWERS", "FLOWER_ATTACK_M", 4.1, 1, 0, 0, 0, 0);

	return 1;
}

CMD:facepalm( playerid, cmdtext[] )
{
    if(!IsAnimationPermitted(playerid))
	    return SendErrorMessage(playerid, "You cannot use this command right now.");

	ApplyAnimationEx(playerid, "MISC", "plyr_shkhead", 4.1, 1, 0, 0, 0, 0);
	return 1;
}
CMD:flip(playerid)
{
    if(!IsAnimationPermitted(playerid))
	    return SendErrorMessage(playerid, "You cannot use this command right now.");

	ClearAnimations(playerid);
	ApplyAnimationEx(playerid, "ped", "KD_right", 4.1, 1, 0, 0, 0, 0);
	return true ;
}

CMD:idles(playerid, params[])
{
	if(!IsAnimationPermitted(playerid))
	    return SendErrorMessage(playerid, "You cannot use this command right now.");

	switch(strval(params))
	{
		case 1: ApplyAnimationEx(playerid, "PLAYIDLES", "shift", 4.1, 1, 1, 1, 1, 1);
		case 2: ApplyAnimationEx(playerid, "PLAYIDLES", "shldr", 4.1, 1, 1, 1, 1, 1);
		case 3: ApplyAnimationEx(playerid, "PLAYIDLES", "stretch", 4.1, 1, 1, 1, 1, 1);
		case 4: ApplyAnimationEx(playerid, "PLAYIDLES", "strleg", 4.1, 1, 1, 1, 1, 1);
		case 5: ApplyAnimationEx(playerid, "PLAYIDLES", "time", 4.1, 1, 1, 1, 1, 1);
		case 6: ApplyAnimationEx(playerid, "COP_AMBIENT", "Copbrowse_loop", 4.1, 1, 0, 0, 0, 1);
		case 7: ApplyAnimationEx(playerid, "COP_AMBIENT", "Coplook_loop", 4.1, 1, 0, 0, 0, 1);
		case 8: ApplyAnimationEx(playerid, "COP_AMBIENT", "Coplook_shake", 4.1, 1, 0, 0, 0, 1);
		case 9: ApplyAnimationEx(playerid, "COP_AMBIENT", "Coplook_think", 4.1, 1, 0, 0, 0, 1);
		case 10: ApplyAnimationEx(playerid, "COP_AMBIENT", "Coplook_watch", 4.1, 1, 0, 0, 0, 1);
		case 11: ApplyAnimationEx(playerid, "PED", "roadcross", 4.1, 1, 0, 0, 0, 1);
		case 12: ApplyAnimationEx(playerid, "PED", "roadcross_female", 4.1, 1, 0, 0, 0, 1);
		case 13: ApplyAnimationEx(playerid, "PED", "roadcross_gang", 4.1, 1, 0, 0, 0, 1);
		case 14: ApplyAnimationEx(playerid, "PED", "roadcross_old", 4.1, 1, 0, 0, 0, 1);
		case 15: ApplyAnimationEx(playerid, "PED", "woman_idlestance", 4.1, 1, 0, 0, 0, 1);
		default: SendUsageMessage(playerid, "/idles [1-15]");
	}
	return 1;
}

CMD:dance(playerid, params[])
{
	if(!IsAnimationPermitted(playerid))
	{
	    return SendErrorMessage(playerid, "You cannot use this command right now.");
	}

	switch(strval(params))
	{
		case 1: ApplyAnimationEx(playerid, "DANCING", "DAN_Down_A", 4.1, 1, 0, 0, 0, 0);
		case 2: ApplyAnimationEx(playerid, "DANCING", "DAN_Left_A", 4.1, 1, 0, 0, 0, 0);
		case 3: ApplyAnimationEx(playerid, "DANCING", "DAN_Loop_A", 4.1, 1, 0, 0, 0, 0);
		case 4: ApplyAnimationEx(playerid, "DANCING", "DAN_Right_A", 4.1, 1, 0, 0, 0, 0);
		case 5: ApplyAnimationEx(playerid, "DANCING", "DAN_Up_A", 4.1, 1, 0, 0, 0, 0);
        case 6: ApplyAnimationEx(playerid, "DANCING", "dnce_M_a", 4.1, 1, 0, 0, 0, 0);
		case 7: ApplyAnimationEx(playerid, "DANCING", "dnce_M_b", 4.1, 1, 0, 0, 0, 0);
		case 8: ApplyAnimationEx(playerid, "DANCING", "dnce_M_c", 4.1, 1, 0, 0, 0, 0);
		case 9: ApplyAnimationEx(playerid, "DANCING", "dnce_M_d", 4.1, 1, 0, 0, 0, 0);
		case 10: ApplyAnimationEx(playerid, "DANCING", "dnce_M_e", 4.1, 1, 0, 0, 0, 0);
		default: SendUsageMessage(playerid, "/dance [1-14]");
	}

	return 1;
}

CMD:vlowrider(playerid, params[])
{
	if(!IsAnimationPermittedInVehicle(playerid))
	{
	    return SendErrorMessage(playerid, "You cannot use this command right now.");
	}

	switch(strval(params))
	{
	    case 1: ApplyAnimationEx(playerid, "LOWRIDER", "lrgirl_hair", 4.1, 1, 0, 0, 0, 0);
	    case 2: ApplyAnimationEx(playerid, "LOWRIDER", "lrgirl_hurry", 4.1, 1, 0, 0, 0, 0);
	    case 3: ApplyAnimationEx(playerid, "LOWRIDER", "lrgirl_idleloop", 4.1, 1, 0, 0, 0, 0);
		case 4: ApplyAnimationEx(playerid, "LOWRIDER", "lrgirl_l5_loop", 4.1, 1, 0, 0, 0, 0);
		case 5: ApplyAnimationEx(playerid, "LOWRIDER", "lrgirl_l0_bnce", 4.1, 1, 0, 0, 0, 0);
        case 6: ApplyAnimationEx(playerid, "LOWRIDER", "lrgirl_l0_loop", 4.1, 1, 0, 0, 0, 0);
		case 7: ApplyAnimationEx(playerid, "LOWRIDER", "lrgirl_l0_to_l1", 4.1, 1, 0, 0, 0, 0);
		case 8: ApplyAnimationEx(playerid, "LOWRIDER", "lrgirl_l12_to_l0", 4.1, 1, 0, 0, 0, 0);
		case 9: ApplyAnimationEx(playerid, "LOWRIDER", "lrgirl_l1_bnce", 4.1, 1, 0, 0, 0, 0);
		case 10: ApplyAnimationEx(playerid, "LOWRIDER", "lrgirl_l1_loop", 4.1, 1, 0, 0, 0, 0);
		case 11: ApplyAnimationEx(playerid, "LOWRIDER", "lrgirl_l1_to_l2", 4.1, 1, 0, 0, 0, 0);
		case 12: ApplyAnimationEx(playerid, "LOWRIDER", "lrgirl_l2_bnce", 4.1, 1, 0, 0, 0, 0);
		case 13: ApplyAnimationEx(playerid, "LOWRIDER", "lrgirl_l2_loop", 4.1, 1, 0, 0, 0, 0);
		default: SendUsageMessage(playerid, "/lowrider [1-13]");
	}

	return 1;
}

CMD:lowrider(playerid, params[])
{
	if(!IsAnimationPermitted(playerid))
	{
	    return SendErrorMessage(playerid, "You cannot use this command right now.");
	}

	switch(strval(params))
	{
	    case 1: ApplyAnimationEx(playerid, "LOWRIDER", "F_smklean_loop", 4.1, 1, 0, 0, 0, 0);
		case 2: ApplyAnimationEx(playerid, "LOWRIDER", "RAP_A_Loop", 4.1, 1, 0, 0, 0, 0);
		case 3: ApplyAnimationEx(playerid, "LOWRIDER", "RAP_B_Loop", 4.1, 1, 0, 0, 0, 0);
		case 4: ApplyAnimationEx(playerid, "LOWRIDER", "RAP_C_Loop", 4.1, 1, 0, 0, 0, 0);
		case 5: ApplyAnimationEx(playerid, "LOWRIDER", "lrgirl_l2_to_l3", 4.1, 1, 0, 0, 0, 0);
		case 6: ApplyAnimationEx(playerid, "LOWRIDER", "lrgirl_l3_bnce", 4.1, 1, 0, 0, 0, 0);
        case 7: ApplyAnimationEx(playerid, "LOWRIDER", "lrgirl_l3_loop", 4.1, 1, 0, 0, 0, 0);
		case 8: ApplyAnimationEx(playerid, "LOWRIDER", "lrgirl_l3_to_l4", 4.1, 1, 0, 0, 0, 0);
		case 9: ApplyAnimationEx(playerid, "LOWRIDER", "lrgirl_l4_bnce", 4.1, 1, 0, 0, 0, 0);
		case 10: ApplyAnimationEx(playerid, "LOWRIDER", "lrgirl_l4_loop", 4.1, 1, 0, 0, 0, 0);
		case 12: ApplyAnimationEx(playerid, "LOWRIDER", "lrgirl_l4_to_l5", 4.1, 1, 0, 0, 0, 0);
		case 13: ApplyAnimationEx(playerid, "LOWRIDER", "lrgirl_l5_bnce", 4.1, 1, 0, 0, 0, 0);
		case 14: ApplyAnimationEx(playerid, "LOWRIDER", "lrgirl_l5_loop", 4.1, 1, 0, 0, 0, 0);
		case 15: ApplyAnimationEx(playerid, "LOWRIDER", "M_smklean_loop", 4.1, 1, 0, 0, 0, 0);
		case 16: ApplyAnimationEx(playerid, "LOWRIDER", "M_smklean_loop", 4.1, 1, 0, 0, 0, 0);
		default: SendUsageMessage(playerid, "/lowrider [1-16]");
	}

	return 1;
}

CMD:lrtalk(playerid, params[])
{
    if(!IsAnimationPermitted(playerid))
	{
	    return SendErrorMessage(playerid, "You cannot use this command right now.");
	}

	switch(strval(params))
	{
		case 1: ApplyAnimationEx(playerid, "LOWRIDER", "prtial_gngtlkA", 4.1, 1, 1, 1, 1, 1);
		case 2: ApplyAnimationEx(playerid, "LOWRIDER", "prtial_gngtlkB", 4.1, 1, 1, 1, 1, 1);
		case 3: ApplyAnimationEx(playerid, "LOWRIDER", "prtial_gngtlkC", 4.1, 1, 1, 1, 1, 1);
		case 4: ApplyAnimationEx(playerid, "LOWRIDER", "prtial_gngtlkD", 4.1, 1, 1, 1, 1, 1);
        case 5: ApplyAnimationEx(playerid, "LOWRIDER", "prtial_gngtlkE", 4.1, 1, 1, 1, 1, 1);
		case 6: ApplyAnimationEx(playerid, "LOWRIDER", "prtial_gngtlkF", 4.1, 1, 1, 1, 1, 1);
		case 7: ApplyAnimationEx(playerid, "LOWRIDER", "prtial_gngtlkG", 4.1, 1, 1, 1, 1, 1);
		case 8: ApplyAnimationEx(playerid, "LOWRIDER", "prtial_gngtlkH", 4.1, 1, 1, 1, 1, 1);
		default: SendUsageMessage(playerid, "/lrtalk [1-8]");
	}

	return 1;
}

CMD:wave(playerid, params[])
{
	if(!IsAnimationPermitted(playerid))
	{
	    return SendErrorMessage(playerid, "You cannot use this command right now.");
	}

	switch(strval(params))
	{
	    case 1: ApplyAnimationEx(playerid, "ON_LOOKERS", "wave_loop", 4.1, 1, 0, 0, 0, 0);
	    case 2: ApplyAnimationEx(playerid, "PED", "endchat_03", 4.1, 0, 0, 0, 0, 0);
		case 3: ApplyAnimationEx(playerid, "KISSING", "gfwave2", 4.1, 0, 0, 0, 0, 0);
		default: SendUsageMessage(playerid, "/wave [1-3]");
	}

	return 1;
}

CMD:point(playerid, params[])
{
    if(!IsAnimationPermitted(playerid))
	{
	    return SendErrorMessage(playerid, "You cannot use this command right now.");
	}

	switch(strval(params))
	{
	    case 1: ApplyAnimationEx(playerid, "ON_LOOKERS", "panic_point", 4.1, 0, 0, 0, 0, 0);
		case 2: ApplyAnimationEx(playerid, "ON_LOOKERS", "point_loop", 4.1, 1, 0, 0, 0, 0);
		default: SendUsageMessage(playerid, "/point [1-2]");
	}

	return 1;
}

CMD:salute(playerid, params[])
{
    if(!IsAnimationPermitted(playerid))
	{
	    return SendErrorMessage(playerid, "You cannot use this command right now.");
	}

	ApplyAnimationEx(playerid, "PED", "CAR_HOOKERTALK", 4.1, 1, 0, 0, 0, 0);
	return 1;
}

CMD:laugh(playerid, params[])
{
    if(!IsAnimationPermitted(playerid))
	{
	    return SendErrorMessage(playerid, "You cannot use this command right now.");
	}

	ApplyAnimationEx(playerid, "RAPPING", "Laugh_01", 4.1, 1, 0, 0, 0, 0);
	return 1;
}

CMD:cry(playerid, params[])
{
    if(!IsAnimationPermitted(playerid))
	{
	    return SendErrorMessage(playerid, "You cannot use this command right now.");
	}

	ApplyAnimationEx(playerid, "GRAVEYARD", "mrnF_loop", 4.1, 1, 0, 0, 0, 0);
	return 1;
}

CMD:deal(playerid, params[])
{
    if(!IsAnimationPermitted(playerid))
	{
	    return SendErrorMessage(playerid, "You cannot use this command right now.");
	}

	ApplyAnimationEx(playerid, "DEALER", "shop_pay", 4.1, 0, 0, 0, 0, 0);
	return 1;
}

CMD:sit(playerid, params[])
{
    if(!IsAnimationPermitted(playerid))
	{
	    return SendErrorMessage(playerid, "You cannot use this command right now.");
	}

	switch(strval(params))
	{
	    case 1: ApplyAnimationEx(playerid, "BEACH", "ParkSit_M_loop", 4.1, 1, 0, 0, 0, 0);
        case 2: ApplyAnimationEx(playerid, "BEACH", "ParkSit_W_loop", 4.1, 1, 0, 0, 0, 0);
	    case 3: ApplyAnimationEx(playerid, "MISC", "SEAT_LR", 4.1, 0, 0, 0, 1, 0);
	    case 4: ApplyAnimationEx(playerid, "MISC", "Seat_talk_01", 4.1, 1, 0, 0, 0, 0);
	    case 5: ApplyAnimationEx(playerid, "PED", "SEAT_down", 4.1, 0, 0, 0, 1, 0);
     	case 6: ApplyAnimationEx(playerid, "INT_OFFICE", "OFF_Sit_Bored_Loop", 4.1, 1, 0, 0, 0, 0);
       	case 7: ApplyAnimationEx(playerid, "INT_OFFICE", "OFF_Sit_Read", 4.1, 1, 0, 0, 0, 0);
       	case 8: ApplyAnimationEx(playerid, "INT_OFFICE", "OFF_Sit_Crash", 4.1, 1, 0, 0, 0, 0);
       	case 9: ApplyAnimationEx(playerid, "FOOD", "FF_Sit_Eat1", 4.1, 1, 0, 0, 0, 0);
       	case 10: ApplyAnimationEx(playerid, "CRIB", "PED_Console_Loop", 4.1, 0, 0, 0, 1, 0);
	    default: SendUsageMessage(playerid, "/sit [1-10]");
	}

	return 1;
}

CMD:lay(playerid, params[])
{
    if(!IsAnimationPermitted(playerid))
	{
	    return SendErrorMessage(playerid, "You cannot use this command right now.");
	}

	switch(strval(params))
	{
	    case 1: ApplyAnimationEx(playerid, "BEACH", "bather", 4.1, 1, 0, 0, 0, 0);
        case 2: ApplyAnimationEx(playerid, "BEACH", "Lay_Bac_Loop", 4.1, 1, 0, 0, 0, 0);
        case 3: ApplyAnimationEx(playerid, "BEACH", "SitnWait_loop_W", 4.1, 1, 0, 0, 0, 0);
	    default: SendUsageMessage(playerid, "/lay [1-3]");
	}

	return 1;
}


CMD:fall(playerid, params[])
{
    if(!IsAnimationPermitted(playerid))
	{
	    return SendErrorMessage(playerid, "You cannot use this command right now.");
	}

	switch(strval(params))
	{
	    case 1: ApplyAnimationEx(playerid, "PED", "KO_skid_front", 4.1, 0, 0, 0, 1, 0);
	    case 2: ApplyAnimationEx(playerid, "PED", "KO_skid_back", 4.1, 0, 0, 0, 1, 0);
	    case 3: ApplyAnimationEx(playerid, "PED", "KO_shot_face", 4.1, 0, 1, 1, 1, 0);
	    case 4: ApplyAnimationEx(playerid, "PED", "KO_shot_front", 4.1, 0, 1, 1, 1, 0);
	    case 5: ApplyAnimationEx(playerid, "PED", "KO_shot_stom", 4.1, 0, 1, 1, 1, 0);
	    case 6: ApplyAnimationEx(playerid, "PED", "BIKE_fallR", 4.1, 0, 1, 1, 1, 0);
	    default: SendUsageMessage(playerid, "/fall [1-6]");
	}

	return 1;
}

CMD:handsup(playerid, params[])
{
    if(!IsAnimationPermitted(playerid))
	{
	    return SendErrorMessage(playerid, "You cannot use this command right now.");
	}

	ApplyAnimationEx(playerid, "SHOP", "SHP_HandsUp_Scr", 4.1, 0, 0, 0, 1, 0);
	return 1;
}

CMD:celebrate(playerid, params[]) 
{
   	if(!IsAnimationPermitted(playerid))
	    return SendErrorMessage(playerid, "You cannot use this command right now.");

	SetPlayerAttachedObject(playerid, ATTACH_ANIMS, -2503, 6, 0.051001, 0.037000, -0.000999, -3.499976, 63.500053, -3.400005, 1.000000, 1.000000, 1.258999 ) ;
	SetPlayerAttachedObject(playerid, ATTACH_ANIMS2, 18706, 6, -1.334998, -0.005000, -0.679999, -3.499975, 63.500053, -3.400005, 1.000000, 1.000000, 1.258998 ) ;

   	ApplyAnimationEx(playerid, "BUDDY", "buddy_reload", 4.1, 1, 0, 0, 0, 0);
   	return 1;
}

CMD:angry(playerid, params[]){

	if(!IsAnimationPermitted(playerid))
	    return SendErrorMessage(playerid, "You cannot use this command right now.");

	ApplyAnimationEx(playerid, "RIOT", "RIOT_ANGRY", 4.1, 0, 0, 0, 0, 0);
	return 1;
}

CMD:flex(playerid, params[])
{
    if(!IsAnimationPermitted(playerid))
	    return SendErrorMessage(playerid, "You cannot use this command right now.");
	if(20 > PlayerInfo[playerid][E_CHARACTER_MONEY])
		return SendErrorMessage(playerid, "You must have $20 for flexin'.");

	switch(strval(params))
	{
		case 1: 
		{
			ApplyAnimationEx(playerid, "PED", "phone_talk", 4.1, 1, 1, 1, 1, 1);
			SetPlayerAttachedObject(playerid, ATTACH_ANIMS, -25164, 6, 0.0169, 0.0130, 0.0000, 0.0000, 89.3999, 0.0000, 1.0000, 1.0000, 1.0000, 0xFFFFFFFF, 0xFFFFFFFF);
		}
		case 2: 
		{
			ApplyAnimationEx(playerid, "PED", "ARRESTgun", 4.1, 1, 1, 1, 1, 1);
			SetPlayerAttachedObject(playerid, ATTACH_ANIMS, -25164, 6, 0.0169, 0.0130, 0.0000, 0.0000, 89.3999, 0.0000, 1.0000, 1.0000, 1.0000, 0xFFFFFFFF, 0xFFFFFFFF);
		}
		default: SendUsageMessage(playerid, "/flex [1-2]");
	}

	return 1;
}

CMD:tired(playerid, params[])
{
    if(!IsAnimationPermitted(playerid))
	{
	    return SendErrorMessage(playerid, "You cannot use this command right now.");
	}

	switch(strval(params))
	{
	    case 1: ApplyAnimationEx(playerid, "PED", "IDLE_tired", 4.1, 1, 0, 0, 0, 0);
        case 2: ApplyAnimationEx(playerid, "FAT", "IDLE_tired", 4.1, 1, 0, 0, 0, 0);
	    default: SendUsageMessage(playerid, "/tired [1-2]");
	}

	return 1;
}

CMD:hide(playerid, params[])
{
	return cmd_cower(playerid, params);
}

CMD:cover(playerid, params[])
{
	return cmd_cower(playerid, params);
}

CMD:cower(playerid, params[])
{
    if(!IsAnimationPermitted(playerid))
	{
	    return SendErrorMessage(playerid, "You cannot use this command right now.");
	}

	ApplyAnimationEx(playerid, "PED", "cower", 4.1, 1, 0, 0, 0, 0);
	return 1;
}

CMD:recruit(playerid, params[]) 
{
	new type;

	if(!IsAnimationPermitted(playerid))
	    return SendErrorMessage(playerid, "You cannot use this command right now.");

	if (sscanf(params, "d", type))
	    return SendErrorMessage(playerid, "/recruit [1-2]");

	if (type < 1 || type > 2)
	    return SendErrorMessage(playerid, "Invalid type specified.");

	switch (type) {
		case 1: ApplyAnimationEx(playerid, "GANGS", "Invite_No", 4.1, 1, 0, 0, 0, 0);
		case 2: ApplyAnimationEx(playerid, "GANGS", "Invite_Yes", 4.1, 1, 0, 0, 0, 0);
	}
	return 1;
}

CMD:crack(playerid, params[])
{
    if(!IsAnimationPermitted(playerid))
	    return SendErrorMessage(playerid, "You cannot use this command right now.");

	switch(strval(params))
	{
	    case 1: ApplyAnimationEx(playerid, "CRACK", "crckdeth1", 4.1, 0, 0, 0, 1, 0);
        case 2: ApplyAnimationEx(playerid, "CRACK", "crckdeth2", 4.1, 1, 0, 0, 0, 0);
        case 3: ApplyAnimationEx(playerid, "CRACK", "crckdeth3", 4.1, 0, 0, 0, 1, 0);
        case 4: ApplyAnimationEx(playerid, "CRACK", "crckdeth4", 4.1, 0, 0, 0, 1, 0);
	    default: SendUsageMessage(playerid, "/crack [1-4]");
	}

	return 1;
}

CMD:injured(playerid, params[])
{
    if(!IsAnimationPermitted(playerid))
	{
	    return SendErrorMessage(playerid, "You cannot use this command right now.");
	}

	switch(strval(params))
	{
	    case 1: ApplyAnimationEx(playerid, "SWAT", "gnstwall_injurd", 4.1, 1, 0, 0, 0, 0);
        case 2: ApplyAnimationEx(playerid, "SWEET", "Sweet_injuredloop", 4.1, 1, 0, 0, 0, 0);
	    default: SendUsageMessage(playerid, "/injured [1-2]");
	}

	return 1;
}

CMD:reload(playerid, params[])
{
    if(!IsAnimationPermitted(playerid))
	{
	    return SendErrorMessage(playerid, "You cannot use this command right now.");
	}

	switch(strval(params))
	{
	    case 1: ApplyAnimationEx(playerid, "BUDDY", "buddy_reload", 4.1, 0, 0, 0, 0, 0);
        case 2: ApplyAnimationEx(playerid, "PYTHON", "python_reload", 4.1, 0, 0, 0, 0, 0);
        case 3: ApplyAnimationEx(playerid, "UZI", "UZI_reload", 4.1, 0, 0, 0, 0, 0);
        case 4: ApplyAnimationEx(playerid, "RIFLE", "RIFLE_load", 4.1, 0, 0, 0, 0, 0);
	    default: SendUsageMessage(playerid, "/reload [1-4]");
	}

	return 1;
}

CMD:aim(playerid, params[])
{
    if(!IsAnimationPermitted(playerid))
	{
	    return SendErrorMessage(playerid, "You cannot use this command right now.");
	}

	switch(strval(params))
	{
	    case 1: ApplyAnimationEx(playerid, "SHOP", "ROB_loop", 4.1, 1, 0, 0, 0, 0);
        case 2: ApplyAnimationEx(playerid, "PED", "ARRESTgun", 4.1, 0, 0, 0, 1, 0);
	    default: SendUsageMessage(playerid, "/aim [1-2]");
	}

	return 1;
}

CMD:bomb(playerid, params[])
{
    if(!IsAnimationPermitted(playerid))
	{
	    return SendErrorMessage(playerid, "You cannot use this command right now.");
	}

	ApplyAnimationEx(playerid, "BOMBER", "BOM_Plant", 4.1, 0, 0, 0, 0, 0);
	return 1;
}

CMD:checktime(playerid, params[])
{
    if(!IsAnimationPermitted(playerid))
	{
	    return SendErrorMessage(playerid, "You cannot use this command right now.");
	}

	ApplyAnimationEx(playerid, "COP_AMBIENT", "Coplook_watch", 4.1, 0, 0, 0, 0, 0);
	return 1;
}

CMD:dodge(playerid, params[])
{
    if(!IsAnimationPermitted(playerid))
	{
	    return SendErrorMessage(playerid, "You cannot use this command right now.");
	}

	ApplyAnimationEx(playerid, "DODGE", "Crush_Jump", 4.1, 0, 0, 0, 0, 0);
	return 1;
}

CMD:stop(playerid, params[])
{
    if(!IsAnimationPermitted(playerid))
	{
	    return SendErrorMessage(playerid, "You cannot use this command right now.");
	}

	ApplyAnimationEx(playerid, "PED", "endchat_01", 4.1, 0, 0, 0, 0, 0);
	return 1;
}

CMD:scratch(playerid, params[])
{
    if(!IsAnimationPermitted(playerid))
	{
	    return SendErrorMessage(playerid, "You cannot use this command right now.");
	}

	ApplyAnimationEx(playerid, "MISC", "Scratchballs_01", 4.1, 0, 0, 0, 0, 0);
	return 1;
}

CMD:what(playerid, params[])
{
    if(!IsAnimationPermitted(playerid))
	{
	    return SendErrorMessage(playerid, "You cannot use this command right now.");
	}

	ApplyAnimationEx(playerid, "RIOT", "RIOT_ANGRY", 4.1, 0, 0, 0, 0, 0);
	return 1;
}

CMD:wash(playerid, params[])
{
    if(!IsAnimationPermitted(playerid))
	{
	    return SendErrorMessage(playerid, "You cannot use this command right now.");
	}

	ApplyAnimationEx(playerid, "BD_FIRE", "wash_up", 4.1, 0, 0, 0, 0, 0);
	return 1;
}

CMD:come(playerid, params[])
{
    if(!IsAnimationPermitted(playerid))
	{
	    return SendErrorMessage(playerid, "You cannot use this command right now.");
	}

	ApplyAnimationEx(playerid, "WUZI", "Wuzi_follow", 4.1, 0, 0, 0, 0, 0);
	return 1;
}

CMD:hitch(playerid, params[])
{
    if(!IsAnimationPermitted(playerid))
	{
	    return SendErrorMessage(playerid, "You cannot use this command right now.");
	}

	ApplyAnimationEx(playerid, "MISC", "Hiker_Pose", 4.1, 0, 0, 0, 1, 0);
	return 1;
}

CMD:cpr(playerid, params[])
{
    if(!IsAnimationPermitted(playerid))
	{
	    return SendErrorMessage(playerid, "You cannot use this command right now.");
	}

	ApplyAnimationEx(playerid, "MEDIC", "CPR", 4.1, 0, 0, 0, 0, 0);
	return 1;
}

CMD:slapass(playerid, params[])
{
    if(!IsAnimationPermitted(playerid))
	    return SendErrorMessage(playerid, "You cannot use this command right now.");

	ApplyAnimationEx(playerid, "SWEET", "sweet_ass_slap", 4.1, 0, 0, 0, 0, 0);
	return 1;
}

CMD:drunk(playerid, params[])
{
    if(!IsAnimationPermitted(playerid))
	    return SendErrorMessage(playerid, "You cannot use this command right now.");

	ApplyAnimationEx(playerid, "PED", "WALK_DRUNK", 4.1, 1, 1, 1, 1, 1);
	return 1;
}

CMD:shit(playerid, params[])
{
    if(!IsAnimationPermitted(playerid))
	    return SendErrorMessage(playerid, "You cannot use this command right now.");

	ApplyAnimationEx(playerid, "PED", "cower", 4.1, 0, 0, 0, 0, 0);
	SetPlayerAttachedObject(playerid, ATTACH_ANIMS, 18722, 1, -1.773999, 0.234999,-0.091000, 2.300002, 88.499984, 0.0, 1.0, 1.0, 1.0);
	return 1;
}

CMD:fucku(playerid, params[])
{
    if(!IsAnimationPermitted(playerid))
	    return SendErrorMessage(playerid, "You cannot use this command right now.");

	ApplyAnimationEx(playerid, "PED", "fucku", 4.1, 0, 0, 0, 0, 0);
	return 1;
}

CMD:taichi(playerid, params[])
{
    if(!IsAnimationPermitted(playerid))
	    return SendErrorMessage(playerid, "You cannot use this command right now.");

	ApplyAnimationEx(playerid, "PARK", "Tai_Chi_Loop", 4.1, 1, 0, 0, 0, 0);
	return 1;
}

CMD:shifty(playerid, params[])
{
    if(!IsAnimationPermitted(playerid))
	    return SendErrorMessage(playerid, "You cannot use this command right now.");

	ApplyAnimationEx(playerid, "SHOP", "ROB_Shifty", 4.1, 0, 0, 0, 0, 0);
	return 1;
}

CMD:smoke(playerid, params[])
{
    if(!IsAnimationPermitted(playerid))
	{
	    return SendErrorMessage(playerid, "You cannot use this command right now.");
	}

	switch(strval(params))
	{
	    case 1: ApplyAnimationEx(playerid, "SMOKING", "M_smklean_loop", 4.1, 1, 0, 0, 0, 0);
        case 2: ApplyAnimationEx(playerid, "SMOKING", "M_smk_in", 4.1, 0, 0, 0, 0, 0);
	    default: SendUsageMessage(playerid, "/smoke [1-2]");
	}

	return 1;
}

CMD:chat(playerid, params[])
{
    if(!IsAnimationPermitted(playerid))
	{
	    return SendErrorMessage(playerid, "You cannot use this command right now.");
	}

	switch(strval(params))
	{
		case 1: ApplyAnimationEx(playerid, "PED", "IDLE_CHAT", 4.1, 1, 1, 1, 1, 1);
		case 2: ApplyAnimationEx(playerid, "GANGS", "prtial_gngtlkA", 4.1, 1, 1, 1, 1, 1);
		case 3: ApplyAnimationEx(playerid, "GANGS", "prtial_gngtlkB", 4.1, 1, 1, 1, 1, 1);
		case 4: ApplyAnimationEx(playerid, "GANGS", "prtial_gngtlkC", 4.1, 1, 1, 1, 1, 1);
		case 5: ApplyAnimationEx(playerid, "GANGS", "prtial_gngtlkD", 4.1, 1, 1, 1, 1, 1);
        case 6: ApplyAnimationEx(playerid, "GANGS", "prtial_gngtlkE", 4.1, 1, 1, 1, 1, 1);
		case 7: ApplyAnimationEx(playerid, "GANGS", "prtial_gngtlkF", 4.1, 1, 1, 1, 1, 1);
		case 8: ApplyAnimationEx(playerid, "GANGS", "prtial_gngtlkG", 4.1, 1, 1, 1, 1, 1);
		case 9: ApplyAnimationEx(playerid, "GANGS", "prtial_gngtlkH", 4.1, 1, 1, 1, 1, 1);
		default: SendUsageMessage(playerid, "/chat [1-9]");
	}

	return 1;
}

CMD:lean(playerid, params[])
{
    if(!IsAnimationPermitted(playerid))
	{
	    return SendErrorMessage(playerid, "You cannot use this command right now.");
	}

	switch(strval(params))
	{
	    case 1: ApplyAnimationEx(playerid, "GANGS", "leanIDLE", 4.1, 1, 0, 0, 0, 0);
        case 2: ApplyAnimationEx(playerid, "MISC", "Plyrlean_loop", 4.1, 1, 0, 0, 0, 0);
	    default: SendUsageMessage(playerid, "/lean [1-2]");
	}

	return 1;
}

CMD:wank(playerid, params[])
{
    if(!IsAnimationPermitted(playerid))
	{
	    return SendErrorMessage(playerid, "You cannot use this command right now.");
	}

	ApplyAnimationEx(playerid, "PAULNMAC", "wank_loop", 4.1, 1, 0, 0, 0, 0);
	return 1;
}

CMD:traffic(playerid, params[])
{
    if(!IsAnimationPermitted(playerid))
	{
	    return SendErrorMessage(playerid, "You cannot use this command right now.");
	}

	switch(strval(params))
	{
	    case 1: ApplyAnimationEx(playerid, "POLICE", "CopTraf_Stop", 4.1, 0, 0, 0, 0, 0);
        case 2: ApplyAnimationEx(playerid, "POLICE", "CopTraf_Come", 4.1, 0, 0, 0, 0, 0);
	    default: SendUsageMessage(playerid, "/traffic [1-2]");
	}

	return 1;
}

CMD:rap(playerid, params[])
{
    if(!IsAnimationPermitted(playerid))
	{
	    return SendErrorMessage(playerid, "You cannot use this command right now.");
	}

	switch(strval(params))
	{
	    case 1: ApplyAnimationEx(playerid, "RAPPING", "RAP_A_LOOP", 4.1, 1, 0, 0, 0, 0);
        case 2: ApplyAnimationEx(playerid, "RAPPING", "RAP_B_LOOP", 4.1, 1, 0, 0, 0, 0);
        case 3: ApplyAnimationEx(playerid, "RAPPING", "RAP_C_LOOP", 4.1, 1, 0, 0, 0, 0);
	    default: SendUsageMessage(playerid, "/rap [1-3]");
	}

	return 1;
}

CMD:dj(playerid, params[])
{
    if(!IsAnimationPermitted(playerid))
	{
	    return SendErrorMessage(playerid, "You cannot use this command right now.");
	}

	switch(strval(params))
	{
	    case 1: ApplyAnimationEx(playerid, "SCRATCHING", "scdldlp", 4.1, 1, 0, 0, 0, 0);
        case 2: ApplyAnimationEx(playerid, "SCRATCHING", "scdlulp", 4.1, 1, 0, 0, 0, 0);
        case 3: ApplyAnimationEx(playerid, "SCRATCHING", "scdrdlp", 4.1, 1, 0, 0, 0, 0);
        case 4: ApplyAnimationEx(playerid, "SCRATCHING", "scdrulp", 4.1, 1, 0, 0, 0, 0);
	    default: SendUsageMessage(playerid, "/dj [1-4]");
	}

	return 1;
}

CMD:crossarms(playerid, params[])
{
    if(!IsAnimationPermitted(playerid))
	{
	    return SendErrorMessage(playerid, "You cannot use this command right now.");
	}

	switch(strval(params))
	{
	    case 1: ApplyAnimationEx(playerid, "COP_AMBIENT", "Coplook_loop", 4.1, 1, 0, 0, 0, 0);
	    case 2: ApplyAnimationEx(playerid, "DEALER", "DEALER_IDLE", 4.1, 1, 0, 0, 0, 0);
        case 3: ApplyAnimationEx(playerid, "GRAVEYARD", "mrnM_loop", 4.1, 1, 0, 0, 0, 0);
	    default: SendUsageMessage(playerid, "/crossarms [1-3]");
	}

	return 1;
}

CMD:gsign(playerid, params[])
{
    if(!IsAnimationPermitted(playerid))
	{
	    return SendErrorMessage(playerid, "You cannot use this command right now.");
	}

	switch(strval(params))
	{
		case 1: ApplyAnimationEx(playerid, "GHANDS", "gsign1", 4.1, 0, 0, 0, 0, 0);
		case 2: ApplyAnimationEx(playerid, "GHANDS", "gsign1LH", 4.1, 0, 0, 0, 0, 0);
		case 3: ApplyAnimationEx(playerid, "GHANDS", "gsign2", 4.1, 0, 0, 0, 0, 0);
		case 4: ApplyAnimationEx(playerid, "GHANDS", "gsign2LH", 4.1, 0, 0, 0, 0, 0);
		case 5: ApplyAnimationEx(playerid, "GHANDS", "gsign3", 4.1, 0, 0, 0, 0, 0);
        case 6: ApplyAnimationEx(playerid, "GHANDS", "gsign3LH", 4.1, 0, 0, 0, 0, 0);
		case 7: ApplyAnimationEx(playerid, "GHANDS", "gsign4", 4.1, 0, 0, 0, 0, 0);
		case 8: ApplyAnimationEx(playerid, "GHANDS", "gsign4LH", 4.1, 0, 0, 0, 0, 0);
		case 9: ApplyAnimationEx(playerid, "GHANDS", "gsign5", 4.1, 0, 0, 0, 0, 0);
		case 10: ApplyAnimationEx(playerid, "GHANDS", "gsign5LH", 4.1, 0, 0, 0, 0, 0);
		default: SendUsageMessage(playerid, "/gsign [1-10]");
	}

	return 1;
}

CMD:fuckme(playerid, params[])
{
    if(!IsAnimationPermitted(playerid))
	{
	    return SendErrorMessage(playerid, "You cannot use this command right now.");
	}

	switch(strval(params))
	{
	    case 1: ApplyAnimationEx(playerid, "SNM", "SPANKING_IDLEW", 4.1, 0, 1, 1, 1, 0);
		case 2: ApplyAnimationEx(playerid, "SNM", "SPANKING_IDLEP", 4.1, 0, 1, 1, 1, 0);
		case 3: ApplyAnimationEx(playerid, "SNM", "SPANKINGW", 4.1, 0, 1, 1, 1, 0);
		case 4: ApplyAnimationEx(playerid, "SNM", "SPANKINGP", 4.1, 0, 1, 1, 1, 0);
		case 5: ApplyAnimationEx(playerid, "SNM", "SPANKEDW", 4.1, 0, 1, 1, 1, 0);
		case 6: ApplyAnimationEx(playerid, "SNM", "SPANKEDP", 4.1, 0, 1, 1, 1, 0);
		case 7: ApplyAnimationEx(playerid, "SNM", "SPANKING_ENDW", 4.1, 0, 1, 1, 1, 0);
		case 8: ApplyAnimationEx(playerid, "SNM", "SPANKING_ENDP", 4.1, 0, 1, 1, 1, 0);
        default: SendUsageMessage(playerid, "/fuckme [1-8]");
	}

	return 1;
}

CMD:bj(playerid, params[])
{
    if(!IsAnimationPermitted(playerid))
	{
	    return SendErrorMessage(playerid, "You cannot use this command right now.");
	}

	switch(strval(params))
	{
	    case 1: ApplyAnimationEx(playerid, "BLOWJOBZ", "BJ_COUCH_START_P", 4.1, 0, 1, 1, 1, 0);
		case 2: ApplyAnimationEx(playerid, "BLOWJOBZ", "BJ_COUCH_START_W", 4.1, 0, 1, 1, 1, 0);
		case 3: ApplyAnimationEx(playerid, "BLOWJOBZ", "BJ_COUCH_LOOP_P", 4.1, 0, 1, 1, 1, 0);
		case 4: ApplyAnimationEx(playerid, "BLOWJOBZ", "BJ_COUCH_LOOP_W", 4.1, 0, 1, 1, 1, 0);
		case 5: ApplyAnimationEx(playerid, "BLOWJOBZ", "BJ_COUCH_END_P", 4.1, 0, 1, 1, 1, 0);
		case 6: ApplyAnimationEx(playerid, "BLOWJOBZ", "BJ_COUCH_END_W", 4.1, 0, 1, 1, 1, 0);
		case 7: ApplyAnimationEx(playerid, "BLOWJOBZ", "BJ_STAND_START_P", 4.1, 0, 1, 1, 1, 0);
		case 8: ApplyAnimationEx(playerid, "BLOWJOBZ", "BJ_STAND_START_W", 4.1, 0, 1, 1, 1, 0);
		case 9: ApplyAnimationEx(playerid, "BLOWJOBZ", "BJ_STAND_LOOP_P", 4.1, 1, 0, 0, 0, 0);
		case 10: ApplyAnimationEx(playerid, "BLOWJOBZ", "BJ_STAND_LOOP_W", 4.1, 1, 0, 0, 0, 0);
		case 11: ApplyAnimationEx(playerid, "BLOWJOBZ", "BJ_STAND_END_P", 4.1, 0, 1, 1, 1, 0);
		case 12: ApplyAnimationEx(playerid, "BLOWJOBZ", "BJ_STAND_END_W", 4.1, 0, 1, 1, 1, 0);
        default: SendUsageMessage(playerid, "/bj [1-12]");
	}

	return 1;
}

CMD:kiss(playerid, params[])
{
    if(!IsAnimationPermitted(playerid))
	{
	    return SendErrorMessage(playerid, "You cannot use this command right now.");
	}

    ApplyAnimationEx(playerid, "KISSING", "Playa_Kiss_01", 4.0, 0, 0, 0, 0, 0);
    return 1;
}

CMD:piss(playerid, params[])
{
    if(!IsAnimationPermitted(playerid) || GetPlayerSpecialAction(playerid) == SPECIAL_ACTION_CARRY)
	{
	    return SendErrorMessage(playerid, "You're currently unable to use animations at this moment.");
	}
	
	SetPlayerSpecialAction(playerid, 68);
	return 1;
}

CMD:robman(playerid, params[])
{
    if(!IsAnimationPermitted(playerid))
	{
	    return SendErrorMessage(playerid, "You cannot use this command right now.");
	}

    ApplyAnimationEx(playerid, "SHOP", "ROB_Loop_Threat", 4.0, 1, 0, 0, 0, 0);
	return 1;
}

CMD:stopanim(playerid, params[])
{
    if(!IsAnimationPermitted(playerid))
	{
	    return SendErrorMessage(playerid, "You cannot use this command right now.");
	}

    PlayerInfo[playerid][E_CHARACTER_LOOPANIM] = 0;

   	ClearAnimations(playerid, 1);
	RemovePlayerAttachedObject(playerid, ATTACH_ANIMS);
	RemovePlayerAttachedObject(playerid, ATTACH_ANIMS2);

	ApplyAnimation(playerid, "CARRY", "crry_prtial", 4.0, 0, 0, 0, 0, 0, 1);
    return 1;
}

CMD:walkstyle(playerid, params[])
{
    if(!IsAnimationPermitted(playerid))
	{
	    return SendErrorMessage(playerid, "You cannot use this command right now.");
	}

	switch(strval(params))
	{
		case 1: ApplyAnimationEx(playerid, "PED", "WALK_gang1", 4.1, 1, 1, 1, 1, 1);
		case 2: ApplyAnimationEx(playerid, "PED", "WALK_gang2", 4.1, 1, 1, 1, 1, 1);
		case 3: ApplyAnimationEx(playerid, "PED", "WALK_civi", 4.1, 1, 1, 1, 1, 1);
		case 4: ApplyAnimationEx(playerid, "PED", "WALK_armed", 4.1, 1, 1, 1, 1, 1);
		case 5: ApplyAnimationEx(playerid, "PED", "WALK_fat", 4.1, 1, 1, 1, 1, 1);
        case 6: ApplyAnimationEx(playerid, "PED", "WALK_fatold", 4.1, 1, 1, 1, 1, 1);
		case 7: ApplyAnimationEx(playerid, "PED", "WALK_old", 4.1, 1, 1, 1, 1, 1);
		case 8: ApplyAnimationEx(playerid, "PED", "WALK_player", 4.1, 1, 1, 1, 1, 1);
		case 9: ApplyAnimationEx(playerid, "PED", "WALK_shuffle", 4.1, 1, 1, 1, 1, 1);
		case 10: ApplyAnimationEx(playerid, "PED", "WALK_Wuzi", 4.1, 1, 1, 1, 1, 1);
		case 11: ApplyAnimationEx(playerid, "PED", "WOMAN_walkbusy", 4.1, 1, 1, 1, 1, 1);
		case 12: ApplyAnimationEx(playerid, "PED", "WOMAN_walkfatold", 4.1, 1, 1, 1, 1, 1);
		case 13: ApplyAnimationEx(playerid, "PED", "WOMAN_walknorm", 4.1, 1, 1, 1, 1, 1);
		case 14: ApplyAnimationEx(playerid, "PED", "WOMAN_walksexy", 4.1, 1, 1, 1, 1, 1);
		case 15: ApplyAnimationEx(playerid, "PED", "WOMAN_walkpro", 4.1, 1, 1, 1, 1, 1);
		default: SendUsageMessage(playerid, "/walkstyle [1-15]");
	}

	return 1;
}

CMD:chatstyle(playerid, params[])
{
    if(!IsAnimationPermitted(playerid))
	{
	    return SendErrorMessage(playerid, "You cannot use this command right now.");
	}

	switch(strval(params))
	{
		case 1: ApplyAnimationEx(playerid, "PED", "IDLE_CHAT", 4.1, 1, 1, 1, 1, 1);
		case 2: ApplyAnimationEx(playerid, "GANGS", "prtial_gngtlkA", 4.1, 1, 1, 1, 1, 1);
		case 3: ApplyAnimationEx(playerid, "GANGS", "prtial_gngtlkB", 4.1, 1, 1, 1, 1, 1);
		case 4: ApplyAnimationEx(playerid, "GANGS", "prtial_gngtlkC", 4.1, 1, 1, 1, 1, 1);
		case 5: ApplyAnimationEx(playerid, "GANGS", "prtial_gngtlkD", 4.1, 1, 1, 1, 1, 1);
        case 6: ApplyAnimationEx(playerid, "GANGS", "prtial_gngtlkE", 4.1, 1, 1, 1, 1, 1);
		case 7: ApplyAnimationEx(playerid, "GANGS", "prtial_gngtlkF", 4.1, 1, 1, 1, 1, 1);
		case 8: ApplyAnimationEx(playerid, "GANGS", "prtial_gngtlkG", 4.1, 1, 1, 1, 1, 1);
		case 9: ApplyAnimationEx(playerid, "GANGS", "prtial_gngtlkH", 4.1, 1, 1, 1, 1, 1);
		default: SendUsageMessage(playerid, "/chatstyle [1-9]");
	}

	return 1;
}

CMD:taxil(playerid, params[])
{
	if(!IsAnimationPermitted(playerid))
	{
	    return SendErrorMessage(playerid, "You cannot use this command right now.");
	}

	ApplyAnimationEx(playerid, "MISC", "Hiker_Pose", 4.0, 0, 1, 1, 1, 1);
	return 1;
}

CMD:agree(playerid, params[])
{
	if(!IsAnimationPermitted(playerid))
	{
	    return SendErrorMessage(playerid, "You cannot use this command right now.");
	}

	ApplyAnimationEx(playerid, "GANGS", "INVITE_YES", 4.1, 0, 0, 0, 0, 1);
	return 1;
}