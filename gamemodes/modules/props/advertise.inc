static adcooldown = 0;
static rumorcooldown = 0;

InsertAdvertise() 
{
	CreateDynamic3DTextLabel("[Advertisement]\n{ffffff}Available commands: /advert, /rumour", COLOR_POINT, 1743.3409,-1457.5900,13.5181, 10.0);

	CreateDynamicPickup(1239, 1,  1743.3409,-1457.5900,13.5181);
	CreateDynamicMapIcon(1743.3409,-1457.5900,13.5181, 36, 0);
}

function:OnPlayerMakeRumour(playerid, response, price)
{
	if(response)
	{
		new string[128];
		format(string, sizeof(string), "[Rumour]:{D7D7D7} %s", PlayerInfo[playerid][E_CHARACTER_OBJECTSTRING]);
		SendClientMessageToAll(COLOR_ADVERTISE, string);
		CreateLogs(playerid, LOGS_ADVERT, PlayerInfo[playerid][E_CHARACTER_OBJECTSTRING]);

        GiveMoney(playerid, -price);
		rumorcooldown = gettime();
    }
    return 1;
}

CMD:advertise(playerid, params[]) 
{
	if(IsPlayerAdmins(playerid) < ADMINS_HIGH) 
    {
		if (!IsPlayerInRangeOfPoint(playerid, 3.0, 1743.3409,-1457.5900,13.5181))
			return SendErrorMessage(playerid, "You're not in range of the advertisment place!");
	}

	if (adcooldown && (gettime() - adcooldown) < 300)
        return SendErrorMessage(playerid, "You must wait %d seconds until another advertisement can be placed.", 300 - (gettime() - adcooldown));

	new text[128];

	if(sscanf(params, "s[128]", text))
		return SendUsageMessage(playerid, "/advertise [text] (you will be charged for text length)");

	if (strlen(text) < 6 || strlen(text) > 128)
		return SendErrorMessage(playerid, "Your text can't have less than 6 or more than 128 characters.");

    if (PlayerInfo[playerid][E_CHARACTER_LEVEL] < 3)
		return SendErrorMessage(playerid, "Your level must exceed level 3 to create an advertise");

	if(!Inventory_Count(playerid, "Cellphone") && PlayerInfo[playerid][E_CHARACTER_EQUIPITEMS] != CELLPHONE)
		return SendErrorMessage(playerid, "You must hold the cellphone in your hands."); 

	new price = 1 * strlen(text);

	if(price > PlayerInfo[playerid][E_CHARACTER_MONEY])
		return SendErrorMessage(playerid, "You don't have enough money for this advertisement! You need at least $%s.", FormatMoney(price));

	GiveMoney(playerid, -price);

	new string[256];
	format(string, sizeof(string), "[Advertisement]:{D7D7D7} %s (Phone: %d)", text, PlayerInfo[playerid][E_CHARACTER_PHONE]);
	SendClientMessageToAll(COLOR_ADVERTISE, string);
	CreateLogs(playerid, LOGS_ADVERT, text);

	adcooldown = gettime();
	return 1;
}

CMD:rumour(playerid, params[]) {

	if(IsPlayerAdmins(playerid) < ADMINS_HIGH) 
    {
		if (!IsPlayerInRangeOfPoint(playerid, 3.0, 1743.3409,-1457.5900,13.5181))
			return SendErrorMessage(playerid, "You're not in range of the advertisment place!");
	}

	if (rumorcooldown && (gettime() - rumorcooldown) < 600)
        return SendErrorMessage(playerid, "You must wait %d seconds until another rumour can be sent.", 600 - (gettime() - rumorcooldown));

	new text[144];

	if (sscanf(params, "s[144]", text))
		return SendErrorMessage(playerid, "/rumour [text] (you will be charged for text length)" );

	if (strlen(text) < 5 || strlen (text) > 144 )
		return SendErrorMessage(playerid, "Your text can't have less than 5 or more than 144 characters." );

    if (PlayerInfo[playerid][E_CHARACTER_LEVEL] < 3)
		return SendErrorMessage(playerid, "Your level must exceed level 3 to create an advertise");

	if(!Inventory_Count(playerid, "Cellphone") && PlayerInfo[playerid][E_CHARACTER_EQUIPITEMS] != CELLPHONE)
		return SendErrorMessage(playerid, "You must hold the cellphone in your hands."); 

	new price = 1 * strlen(text);

	if(price > PlayerInfo[playerid][E_CHARACTER_MONEY])
		return SendServerMessage(playerid, "You don't have enough money for this rumour! You need at least $%s.", FormatMoney(price));

	new string [512] = "WARNING: /rumour is only meant to be used for events.\n\n\
		It can not be used to defame another faction or to send random messages or adverts to the server.\n\n\
		If you are abusing this feature, you will be punished severely. Admins can see who use it.\n\n\
		Thanks for understanding.";

    format(PlayerInfo[playerid][E_CHARACTER_OBJECTSTRING], 512, text);
	ConfirmDialog(playerid, "Confirmation", string, "OnPlayerMakeRumour", price); 
	return 1;
}