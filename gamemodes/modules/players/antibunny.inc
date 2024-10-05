function:KillTimerSprung(playerid)
{
	InSprung[playerid] = 0;
	return 1;
}

function:FunctionInSprung(playerid)
{
	new animlib[32];
	new animname[32];
	new Float:vx,Float:vy,Float:vz;
	GetPlayerVelocity(playerid,vx,vy,vz);
	if(vz < -0.5)
	{
	    KillTimer(TimerIDSprung);
	    SetTimerEx("KillTimerSprung",1000,false,"i",playerid);
	    return 1;
	}
	GetAnimationName(GetPlayerAnimationIndex(playerid),animlib,32,animname,32);
	if(!strcmp(animname,"JUMP_LAND") || !strcmp(animname,"FALL_LAND"))
	{
		KillTimer(TimerIDSprung);
		ClearAnimations(playerid,1);
		ApplyAnimation(playerid,"ped","FALL_COLLAPSE",4.1,0,1,1,0,0,1);
		SetTimerEx("KillTimerSprung",1000,false,"i",playerid);
	}
	return 1;
}