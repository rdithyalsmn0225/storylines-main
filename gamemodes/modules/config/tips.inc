new tips;

function:OnPlayerTipsUpdate ()
{
	tips++;

	switch (tips) {

		case 0: SendTipsMessage(COLOR_TIP, "[TIP]{F5F6DF} To view a list of server commands, you may use /help or ask a question via /ask." ) ;
		case 1: SendTipsMessage(COLOR_TIP, "[TIP]{F5F6DF} To view a list of server animations, you can use /animhelp and /stopanim to cancel an animation.") ;
		case 2: SendTipsMessage(COLOR_TIP, "[TIP]{F5F6DF} To ensure a smooth experience, follow and stay up to date with the server rules in our discord @ discord.gg/storylines. ") ;
		case 3: SendTipsMessage(COLOR_TIP, "[TIP]{F5F6DF} To see all people who contributed to the server you can type /credits. These people all helped make this server possible.") ;
		case 4: SendTipsMessage(COLOR_TIP, "[TIP]{F5F6DF} Did you know that you can playing minigames like 8pool, basketball, lottery, and blackjack!") ;
		default: 
        {
			SendTipsMessage(COLOR_TIP, "[TIP]{F5F6DF} To see upcoming updates, script changelogs and or keep up with announcements, tune in on our Discord @ discord.gg/storylines." ) ;
			tips = 0;
		}
	}
}

SendTipsMessage(color, const text[]) 
{
	foreach(new playerid: Player) 
    {
		if (!PlayerInfo[playerid][E_CHARACTER_TOGTIPS]) 
        {
			SendClientMessage(playerid, color, text);
		}
		else continue;
	}
}