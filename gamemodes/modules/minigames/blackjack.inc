new
    blackjackPlayerScore[MAX_PLAYERS],
    blackjackDealerScore[MAX_PLAYERS],
    blackjackPlayerCards[MAX_PLAYERS][10],
    blackjackDealerCards[MAX_PLAYERS][10],
    blackjackPlayerCardsCount[MAX_PLAYERS],
    blackjackDealerCardsCount[MAX_PLAYERS],
    bool:blackjackPlay[MAX_PLAYERS],
    playerBet[MAX_PLAYERS];


InsertBlackjack()
{
    CreateDynamic3DTextLabel("[Blackjack]\n{ffffff}Available commands: /blackjack", COLOR_DARKGREEN, 1128.7081,-1.6211,1000.6797, 5.0);
}

StartBlackjack(playerid) 
{
    ResetBlackjack(playerid);
    Dialog_Show(playerid, BlackjackBet, DIALOG_STYLE_INPUT, "Blackjack:", "{ffffff}Welcome to Blackjack! Please enter the amount you wish to bet.\nRemember if you win you will get 2x the bet, and if you lose you will lose all your bets", "Enter", "Cancel");
    return 1;
}

ShowBlackjackStatus(playerid) 
{
    new businessid = IsPlayerInBusiness(playerid);
    blackjackPlay[playerid] = true;
    BusinessInfo[businessid][E_BUSINESS_BLACKJACK] = true;

    DealInitialCards(playerid);

    new str[1024];
    format(str, sizeof(str), "Your current score: {d7d292}%d{ffffff}\nDealer's current score: {d7d292}%d{ffffff}\nChoose your next move by typing {d7d292}'Hit'{ffffff} to draw another card or {d7d292}'Stand'{ffffff} to keep your current hand.", 
    blackjackPlayerScore[playerid], blackjackDealerScore[playerid]);
    Dialog_Show(playerid, Blackjacks, DIALOG_STYLE_MSGBOX, "Blackjack:", str, "Hit", "Stand");
    return 1;
}

ResetBlackjack(playerid)
{
    new businessid = IsPlayerInBusiness(playerid);
    BusinessInfo[businessid][E_BUSINESS_BLACKJACK] = false;

    blackjackPlayerScore[playerid] = 0;
    blackjackDealerScore[playerid] = 0;
    blackjackPlayerCardsCount[playerid] = 0;
    blackjackDealerCardsCount[playerid] = 0;
    blackjackPlay[playerid] = false;
    return 1;
}

DealInitialCards(playerid)
{
    new cardDeck[52];
    InitializeDeck(cardDeck);

    GiveCardToPlayer(playerid, cardDeck);
    GiveCardToDealer(playerid, cardDeck);
    GiveCardToPlayer(playerid, cardDeck);
    return 1;
}

InitializeDeck(cardDeck[])
{
    for (new i = 0; i < 52; i++) cardDeck[i] = i + 1;
    for (new i = 0; i < 52; i++)
    {
        new randIdx = random(52);
        new temp = cardDeck[i];
        cardDeck[i] = cardDeck[randIdx];
        cardDeck[randIdx] = temp;
    }
    return 1;
}

GiveCardToPlayer(playerid, cardDeck[])
{
    blackjackPlayerCards[playerid][blackjackPlayerCardsCount[playerid]++] = cardDeck[blackjackPlayerCardsCount[playerid] + blackjackDealerCardsCount[playerid]];
    blackjackPlayerScore[playerid] = CalculateScore(blackjackPlayerCards[playerid], blackjackPlayerCardsCount[playerid]);
}

GiveCardToDealer(playerid, cardDeck[])
{
    blackjackDealerCards[playerid][blackjackDealerCardsCount[playerid]++] = cardDeck[blackjackPlayerCardsCount[playerid] + blackjackDealerCardsCount[playerid]];
    blackjackDealerScore[playerid] = CalculateScore(blackjackDealerCards[playerid], blackjackDealerCardsCount[playerid]);
}

DealerTurn(playerid)
{
    new cardDeck[52];
    InitializeDeck(cardDeck);
    while(blackjackDealerScore[playerid] <= 17)
    {
        GiveCardToDealer(playerid, cardDeck);
    }
    return 1;
}

DetermineWinner(playerid)
{
    if(blackjackDealerScore[playerid] > 21 || blackjackPlayerScore[playerid] > blackjackDealerScore[playerid])
    {
        new reward = playerBet[playerid] * 2;
        GiveMoney(playerid, reward);
        ResetBlackjack(playerid);
        SendServerMessage(playerid, "[Blackjack] {cdd0d1}You won! Your reward is {93C47D}$%s{cdd0d1}.", FormatMoney(reward));
        return 1;
    }
    else if(blackjackDealerScore[playerid] == blackjackPlayerScore[playerid])
    {
        ResetBlackjack(playerid);
        SendServerMessage(playerid, "[Blackjack] {cdd0d1}It's a draw!");
        return 1;
    }
    else
    {
        SendServerMessage(playerid, "[Blackjack] {cdd0d1}You lost!");
        ResetBlackjack(playerid);
        return 1;
    }
}


CalculateScore(cards[], cardCount)
{
    new score = 0;
    for(new i = 0; i < cardCount; i++)
    {
        new cardValue = (cards[i] % 13) + 1;
        if(cardValue > 10) cardValue = 10;
        score += cardValue;
    }
    return score;
}

Dialog:BlackjackBet(playerid, response, listitem, inputtext[])
{
    if (response) 
    {
        if(!IsNumeric(inputtext))
        {
            StartBlackjack(playerid);
            SendErrorMessage(playerid, "Please enter a valid numeric amount for your bet.");
            return 1;
        }

        if(playerBet[playerid] <= 0)
        {
            StartBlackjack(playerid);
            SendErrorMessage(playerid, "Invalid bet amount! Please try again.");
            return 1;
        }

        new Cents = floatround(strval(inputtext) * 100, floatround_round);

	    GiveMoney(playerid, -Cents);
        playerBet[playerid] = strval(inputtext);
        ShowBlackjackStatus(playerid);
    }
    else return ResetBlackjack(playerid);
    return 1;
}

Dialog:Blackjacks(playerid, response, listitem, inputtext[])
{   
    if(!response)
    {
        DealerTurn(playerid);
        DetermineWinner(playerid);
        return 1;
    }
    
    if(blackjackPlayerScore[playerid] >= 21)
    {
        ResetBlackjack(playerid);
        SendServerMessage(playerid, "[Blackjack] {cdd0d1}You lost! Your score exceeded 21.");
        return 1;
    }

    new cardDeck[52];
    InitializeDeck(cardDeck);
    GiveCardToPlayer(playerid, cardDeck);
    ShowBlackjackStatus(playerid);

    return 1;
}

CMD:blackjack(playerid, params[])
{
    new businessid = IsPlayerInBusiness(playerid);

    if(!IsPlayerInBusiness(playerid))
        return SendErrorMessage(playerid, "You aren't in any business.");
    
    if(BusinessInfo[businessid][E_BUSINESS_TYPE] != BUSINESS_TYPE_BAR)
        return SendErrorMessage(playerid, "You aren't in any business bar.");

    if(BusinessInfo[businessid][E_BUSINESS_BLACKJACK])
        return SendErrorMessage(playerid, "There is player using this table.");

    if(!IsPlayerInRangeOfPoint(playerid, 2.0, 1128.7081,-1.6211,1000.6797))
        return SendErrorMessage(playerid, "You aren't near blackjack table.");

    StartBlackjack(playerid);
    return 1;
}