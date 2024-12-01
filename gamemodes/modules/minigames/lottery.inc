// LOTTERY
new LotteryActive = 0;
new LotteryPrice = 250;
new LotteryPlayerNumber[MAX_PLAYERS];
new LotteryPlayerHasTicket[MAX_PLAYERS];

ResetLotteryVar(playerid)
{
    LotteryPlayerHasTicket[playerid] = 0;
    LotteryPlayerNumber[playerid] = 0;
    return 1;
}

function:OnPlayerLotteryUpdate()
{
    if (LotteryActive == 1) return 0;
    LotteryActive = 1;
    SendClientMessageToAll(COLOR_PINK, "[Lottery] lottery has started checking winners numbers will be random in 5 minutes.");
    
    SetTimer("EndLottery", 300000, false);
    return 1;
}

function:EndLottery()
{
    if (LotteryActive == 0) return 0;
    new winner = -1;
    new winningNumber = random(100) + 1;
    new winningPrice = randomEx(3000, 5000);
    
    for (new i = 0; i < MAX_PLAYERS; i++)
    {
        if (LotteryPlayerHasTicket[i] && LotteryPlayerNumber[i] == winningNumber)
        {
            winner = i;
            break;
        }
    }
    
    if (winner != -1)
    {
        GivePaycheck(winner, winningPrice);
        new string[128];
        format(string, sizeof(string), "[Lottery] Congratulations %s! You won a lottery $%s with the number %d.", ReturnName(winner, winner), FormatMoney(winningPrice), winningNumber);
        SendClientMessageToAll(COLOR_PINK, string);
    }
    else
    {
        SendClientMessageToAllEx(COLOR_PINK, "[Lottery] There is no lottery winner with a prize of $%s with the number %d.", FormatMoney(winningPrice), winningNumber);
    }
    
    LotteryActive = 0;
    for (new i = 0; i < MAX_PLAYERS; i++)
    {
        LotteryPlayerNumber[i] = 0;
        LotteryPlayerHasTicket[i] = 0;
    }
    
    SetTimer("OnPlayerLotteryUpdate", 1800000, false);
    return 1;
}

// Command untuk membeli tiket
CMD:buylottery(playerid, params[])
{
    if (LotteryActive == 0)
        return SendErrorMessage(playerid, "There are no active lottery at this time.");
    
    if (LotteryPlayerHasTicket[playerid] == 1)
        return SendErrorMessage(playerid, "You already own lottery ticket.");
    
    if(!IsPlayerInRangeOfPoint(playerid, 3.0, 1098.1724,-1495.9231,15.7969))
        return SendErrorMessage(playerid, "You aren't near lottery point.");

    new number;
    if (sscanf(params, "i", number) || number < 1 || number > 100)
        return SendUsageMessage(playerid, "/buyticket [nomor (1-100)].");
    
    if (LotteryPrice > PlayerInfo[playerid][E_CHARACTER_MONEY])
        return SendErrorMessage(playerid, "You can't afford this. (Cost: $%s, Total: $%s)", FormatMoney(LotteryPrice), FormatMoney(PlayerInfo[playerid][E_CHARACTER_MONEY]));
    
    new Cents = floatround(LotteryPrice * 100, floatround_round);

	GiveMoney(playerid, -Cents);
    LotteryPlayerHasTicket[playerid] = 1;
    LotteryPlayerNumber[playerid] = number;

    SendServerMessage(playerid, "[Lottery] {DEDEDE}You have purchased a lottery with a number %d.", number);
    return 1;
}