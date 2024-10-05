function:CallPaycheck()
{
	foreach(new i : Player)
	{
		if(!AccountInfo[i][E_MASTERS_LOGGED])
			return 0;
			
		new
			str[128]; 

		new gTax;
		new paycheck = PlayerInfo[i][E_CHARACTER_PAYCHECK];
    	new interest, rate;
    	new tax = (paycheck / 100) * gTax; // 10% tax
		new total = paycheck - tax;

		if(PlayerInfo[i][E_CHARACTER_EXP] == 8)
		{
			PlayerInfo[i][E_CHARACTER_EXP] = 0;
			PlayerInfo[i][E_CHARACTER_LEVEL]++;
			format(str, sizeof(str), "Leveled up to level %i", PlayerInfo[i][E_CHARACTER_LEVEL]);
			ShowBoxMessage(i, str, 5);

			PlayerPlaySound(i, 1052, 0.0, 0.0, 0.0);
			SetPlayerScore(i, PlayerInfo[i][E_CHARACTER_LEVEL]); 
			SaveCharacter(i); 
		}

		PlayerInfo[i][E_CHARACTER_TIMEPLAYED]++; 
		PlayerInfo[i][E_CHARACTER_EXP]++;

		interest = (PlayerInfo[i][E_CHARACTER_BANK] / 1000) * rate;

		total += interest;
		
		SendClientMessageEx(i, COLOR_WHITE, "SERVER TIME:[ %s ]", ReturnHour()); 
		
		SendClientMessage(i, COLOR_HEADER, "|___ BANK STATEMENT ___|"); 
		SendClientMessageEx(i, COLOR_GREY, "   Balance: $%s", FormatMoney(PlayerInfo[i][E_CHARACTER_BANK])); 
		SendClientMessageEx(i, COLOR_GREY, "   Interest rate: $%s (rate: %.1f)", FormatMoney(interest), floatdiv(float(rate), 10));
		SendClientMessageEx(i, COLOR_GREY, "   Interest Gained: $%s", FormatMoney(paycheck));
		SendClientMessageEx(i, COLOR_GREY, "   Tax paid: $%s (%i percent)", FormatMoney(tax), gTax); 
		SendClientMessage(i, COLOR_HEADER, "|________________________|");
		
		PlayerInfo[i][E_CHARACTER_PAYCHECK] = 0; 
		PlayerInfo[i][E_CHARACTER_BANK]+= total; 
		
		SendClientMessageEx(i, COLOR_WHITE, "   New Balance: $%s", FormatMoney(PlayerInfo[i][E_CHARACTER_BANK] + total));
	
		SaveCharacter(i); 
	}
	return 1;
}

stock GivePaycheck(playerid, amount)
{
	PlayerInfo[playerid][E_CHARACTER_PAYCHECK] += amount; 
	SaveCharacter(playerid); 
	SendClientMessageEx(playerid, COLOR_PHONE, "[Paycheck]{d7d7d7} $%s has been added to paycheck.", FormatMoney(amount));
	PlayerPlaySound(playerid, 5205, 0, 0, 0);
	return 1;
}