
new SystemUpdate, SystemTimer;

CMD:maintenance(playerid, params[])
{
	if(IsPlayerAdmins(playerid) < ADMINS_OWNER)
		return SendUnauthMessage(playerid);
		
	new time, str[128], string[32];
	
	if(sscanf(params, "d", time))
		return SendUsageMessage(playerid, "/maintenance [time]");

    if(time < 60 || time > 21600)
        return SendErrorMessage(playerid, "Server can't be restart less than 60 seconds or longer than 21600 seconds");

    SystemUpdate = time;
    format(string, sizeof(string), "Server will restart in %s", STimeConvert(SystemUpdate));
    TextDrawSetString(UpdateIn, string);
    TextDrawShowForAll(UpdateIn);
    SystemTimer = SetTimer("MaintenanceTimer", 1000, true);

    if(SystemUpdate)
    {
        SendClientMessageToAll(-1, "" ) ;
        SendClientMessageToAll(-1, "" ) ;
        SendClientMessageToAll(COLOR_BLUE, "* The server will be going down for Scheduled Maintenance. (See bottom right screen)");
        SendClientMessageToAll(COLOR_YELLOW, "! End your scenes A.S.A.P. and don't engage in new activities until after the restart !") ;
        SendClientMessageToAll(-1, "" ) ;
        SendClientMessageToAll(-1, "" ) ;

        GameTextForAll("~n~~n~~n~~n~~y~] Scheduled Maintenance Alert ]", 5000, 3);
    }
    
    format(str, sizeof(str), "%s has scheduled server maintenance in %d seconds.", ReturnMixedName(playerid), SystemUpdate);
	SendAdminMessage(1, str);
	return 1;
}

function:MaintenanceTimer() {
	new string[32];
	if(--SystemUpdate <= 0) KillTimer(SystemTimer), Maintenance();
	if(SystemUpdate == 15) GameTextForAll("~n~~n~~n~~n~~w~Please ~r~log out ~w~now to ensure ~y~account data ~w~has been ~g~saved~w~!", 5000, 3);
	if(SystemUpdate < 0) SystemUpdate = 0;
	format(string, sizeof(string), "Server will restart in %s", STimeConvert(SystemUpdate));
	TextDrawSetString(UpdateIn, string);
	TextDrawShowForAll(UpdateIn);
	return 1;
}

STimeConvert(time) {
    new jmin;
    new jsec;
    new string[128];
	if(time > 59 && time < 3600){
        jmin = floatround(time/60);
        jsec = floatround(time - jmin*60);
        format(string,sizeof(string),"%02d:%02d",jmin,jsec);
    }
    else{
        jsec = floatround(time);
        format(string,sizeof(string),"00:%02d",jsec);
    }
    return string;
}

function:Maintenance()
{
    foreach(new i: Player)
	{
		TogglePlayerControllable(i, false);
		GameTextForPlayer(i, "Scheduled Maintenance..~n~~n~~w~Please ~r~log out ~w~now to ensure ~y~account data ~w~has been ~g~saved~w~!", 66000, 5);

	}

	SendRconCommand("password asdatasdhwda");
	SetTimer("FinishMaintenance", 60000, false);
	return 1;
}

function:FinishMaintenance()
{
    foreach(new i: Player) {
    	SendClientMessage(i, COLOR_RED, "You've been kicked from the server because the server is restarting." ) ;
    	KickEx(i);
   	}

	SetTimer("ShutDown", 5000, false);
	return 1;
}

function:ShutDown()
{
	return SendRconCommand("exit");
}