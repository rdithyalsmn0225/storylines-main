CallPaycheck(playerid)
{
	if(!AccountInfo[playerid][E_MASTERS_LOGGED])
		return 0;
		
	new
		str[128]; 

	new gTax;
	new paycheck = PlayerInfo[playerid][E_CHARACTER_PAYCHECK];
	new interest, rate;
	new tax = (paycheck / 100) * gTax; // 10% tax
	new total = paycheck - tax;

	if(PlayerInfo[playerid][E_CHARACTER_EXP] == 10)
	{
		PlayerInfo[playerid][E_CHARACTER_EXP] = 0;
		PlayerInfo[playerid][E_CHARACTER_LEVEL]++;
		format(str, sizeof(str), "Leveled up to level %i", PlayerInfo[playerid][E_CHARACTER_LEVEL]);
		ShowBoxMessage(playerid, str, 5);

		PlayerPlaySound(playerid, 1052, 0.0, 0.0, 0.0);
		SetPlayerScore(playerid, PlayerInfo[playerid][E_CHARACTER_LEVEL]); 
		SaveCharacter(playerid); 
	}

	PlayerInfo[playerid][E_CHARACTER_TIMEPLAYED]++; 
	PlayerInfo[playerid][E_CHARACTER_EXP]++;

	interest = (PlayerInfo[playerid][E_CHARACTER_BANK] / 1000) * rate;

	total += interest;
	
	SendClientMessageEx(playerid, COLOR_WHITE, "SERVER TIME:[ %s ]", ReturnHour()); 
	
	SendClientMessage(playerid, COLOR_DARKGREEN, "|___ BANK STATEMENT ___|"); 
	SendClientMessageEx(playerid, COLOR_GREY, "   Balance: {B3C99E}$%s{ffffff}", FormatMoney(PlayerInfo[playerid][E_CHARACTER_BANK])); 
	SendClientMessageEx(playerid, COLOR_GREY, "   Interest rate: {B3C99E}$%s{ffffff} (rate: %.1f)", FormatMoney(interest), floatdiv(float(rate), 10));
	SendClientMessageEx(playerid, COLOR_GREY, "   Interest Gained: {B3C99E}$%s{ffffff}", FormatMoney(paycheck));
	SendClientMessageEx(playerid, COLOR_GREY, "   Tax paid: {B3C99E}$%s{ffffff} (%i percent)", FormatMoney(tax), gTax); 
	SendClientMessage(playerid, COLOR_DARKGREEN, "|________________________|");
	
	PlayerInfo[playerid][E_CHARACTER_PAYCHECK] = 0; 
	PlayerInfo[playerid][E_CHARACTER_BANK]+= total; 
	
	SendClientMessageEx(playerid, COLOR_WHITE, "   New Balance: {B3C99E}$%s{ffffff}", FormatMoney(PlayerInfo[playerid][E_CHARACTER_BANK] + total));

	SaveCharacter(playerid); 
	return 1;
}

stock GivePaycheck(playerid, amount)
{
	PlayerInfo[playerid][E_CHARACTER_PAYCHECK] += amount; 
	SaveCharacter(playerid); 
	SendServerMessage(playerid, "PAYCHECK: {ffffff}{B3C99E}$%s{ffffff} has been added to paycheck.", FormatMoney(amount));
	PlayerPlaySound(playerid, 5205, 0, 0, 0);
	return 1;
}