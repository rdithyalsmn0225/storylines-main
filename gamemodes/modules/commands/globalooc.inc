//Global variables:
new bool:oocEnabled = false; 

CMD:noooc(playerid, params[])
{
	if(IsPlayerAdmins(playerid) < ADMINS_HIGH)
		return SendUnauthMessage(playerid);
		
	new
		str[128]
	;
		
	if(!oocEnabled)
	{
		format(str, sizeof(str), "%s enabled OOC chat.", ReturnSettingsName(playerid, playerid));
		SendAdminMessage(1, str); 
		
		SendClientMessageToAll(COLOR_GREY, "OOC chat has been enabled by an admin."); 
		oocEnabled = true;
	}
	else
	{
		format(str, sizeof(str), "%s disabled OOC chat.", ReturnSettingsName(playerid, playerid));
		SendAdminMessage(1, str); 
		
		SendClientMessageToAll(COLOR_GREY, "OOC chat has been disabled by an admin."); 
		oocEnabled = false;
	}
	return 1;
}

CMD:o(playerid, params[]) return cmd_ooc(playerid, params);
CMD:ooc(playerid, params[]) {

	new text [ 144 ] ;

	if (sscanf(params, "s[144]", text))
		return SendUsageMessage(playerid, "/ooc [text]");

	if (!oocEnabled)
		return SendErrorMessage(playerid, "OOC is currently disabled." ) ;
	
	new string [256];

	foreach(new targetid: Player) 
	{
		format(string, sizeof(string), "(( [GLOBAL] (%d) %s{AAC4E5}: %s ))",  playerid, ReturnSettingsName(playerid, targetid, false), text);
		SendClientMessage(targetid, COLOR_OOC, string);
	}
	return 1;
}