static adcooldown = 0;
static rumorcooldown = 0;

InsertAdvertise() 
{
	CreateDynamic3DTextLabel("[Advertisement]\n{ffffff}Available commands: /advert, /rumour", COLOR_3DTEXT, 1743.3409,-1457.5900,13.5181, 10.0);

	CreateDynamicPickup(1239, 1,  1743.3409,-1457.5900,13.5181);
	CreateDynamicMapIcon(1743.3409,-1457.5900,13.5181, 36, 0, -1, -1, -1, 10.0);
}

function:OnPlayerMakeRumour(playerid, response, Float: price)
{
	if(response)
	{
		new string[128], str[128];
		format(string, sizeof(string), "[Rumour]: %s", PlayerInfo[playerid][E_CHARACTER_OBJECTSTRING]);
		SendClientMessageToAll(COLOR_LBLUE, string);
		
		format(str, sizeof(str), "%s has used rumour.", ReturnName(playerid));
		SendAdminMessage(1, str);
        new Cents = floatround(price * 100, floatround_round);

		GiveMoney(playerid, -Cents);
		rumorcooldown = gettime();
    }
    return 1;
}

CMD:advert(playerid, params[]) return cmd_advertise(playerid, params);
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

	new Float: price = 0.10 * strlen(text);

	if(price > PlayerInfo[playerid][E_CHARACTER_MONEY])
		return SendErrorMessage(playerid, "You don't have enough money for this advertisement! You need at least $%s.", FormatMoney(price));

	new Cents = floatround(price * 100, floatround_round);

	GiveMoney(playerid, -Cents);

	new string[256], str[128];
	format(string, sizeof(string), "[Advertisement]: %s (Phone: %d)", text, PlayerInfo[playerid][E_CHARACTER_PHONE]);
	SendClientMessageToAll(COLOR_DARKGREEN, string);

	format(str, sizeof(str), "%s has used advertise.", ReturnName(playerid));
	SendAdminMessage(1, str);

	adcooldown = gettime();
	return 1;
}

CMD:badvert(playerid, params[]) 
{
	new businessid = IsPlayerNearBusiness(playerid);
	if(IsPlayerAdmins(playerid) < ADMINS_HIGH) 
    {
		if (!IsPlayerNearBusiness(playerid))
			return SendErrorMessage(playerid, "You're not in range of the advertisment place!");
	}

	if(BusinessInfo[businessid][E_BUSINESS_OWNERDBID] != PlayerInfo[playerid][E_CHARACTER_DBID])
		return SendErrorMessage(playerid, "You don't own this business."); 

	if (adcooldown && (gettime() - adcooldown) < 300)
        return SendErrorMessage(playerid, "You must wait %d seconds until another advertisement can be placed.", 300 - (gettime() - adcooldown));

	new text[128];

	if(sscanf(params, "s[128]", text))
		return SendUsageMessage(playerid, "/badvert [text] (you will be charged for text length)");

	if (strlen(text) < 6 || strlen(text) > 128)
		return SendErrorMessage(playerid, "Your text can't have less than 6 or more than 128 characters.");

    if (PlayerInfo[playerid][E_CHARACTER_LEVEL] < 3)
		return SendErrorMessage(playerid, "Your level must exceed level 3 to create an advertise");

	if(!Inventory_Count(playerid, "Cellphone") && PlayerInfo[playerid][E_CHARACTER_EQUIPITEMS] != CELLPHONE)
		return SendErrorMessage(playerid, "You must hold the cellphone in your hands."); 

	new Float: price = 0.10 * strlen(text);

	if(price > PlayerInfo[playerid][E_CHARACTER_MONEY])
		return SendErrorMessage(playerid, "You don't have enough money for this advertisement! You need at least $%s.", FormatMoney(price));

	new Cents = floatround(price * 100, floatround_round);

	GiveMoney(playerid, -Cents);

	new string[256], str[128];
	format(string, sizeof(string), "[Business]: %s (%s)", text, BusinessInfo[businessid][E_BUSINESS_NAME]);
	SendClientMessageToAll(COLOR_DARKGREEN, string);

	format(str, sizeof(str), "%s has used business advertise.", ReturnName(playerid));
	SendAdminMessage(1, str);

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

	new Float: price = 0.10 * strlen(text);

	if(price > PlayerInfo[playerid][E_CHARACTER_MONEY])
		return SendErrorMessage(playerid, "You don't have enough money for this rumour! You need at least {93C47D}$%s{ffffff}.", FormatMoney(price));

	new string [512] = "WARNING: /rumour is only meant to be used for events.\n\n\
		It can not be used to defame another faction or to send random messages or adverts to the server.\n\n\
		If you are abusing this feature, you will be punished severely. Admins can see who use it.\n\n\
		Thanks for understanding.";

    format(PlayerInfo[playerid][E_CHARACTER_OBJECTSTRING], 512, text);
	ConfirmDialog(playerid, "Confirmation", string, "OnPlayerMakeRumour", price); 
	return 1;
}