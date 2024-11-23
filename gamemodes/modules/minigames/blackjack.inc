
new 
    blackjackPlayerBet[MAX_PLAYERS],
    blackjackPlayerScore[MAX_PLAYERS],
    bool:blackjackInProgress[MAX_PLAYERS],
    blackjackPlayerCardsCount[MAX_PLAYERS],
    blackjackPlayerCards[MAX_PLAYERS][MAX_CARDS],
    cardDeck[52];


InsertBlackjack()
{
    CreateDynamic3DTextLabel("[Blackjack]\n{ffffff}Available commands: /blackjack", COLOR_3DTEXT, 1128.7081,-1.6211,1000.6797, 5.0);
}

stock ShowBlackJack(playerid)
{
    PlayerTextDrawShow(playerid, blackjack[0][playerid]);
    PlayerTextDrawShow(playerid, blackjack[1][playerid]);
    PlayerTextDrawShow(playerid, blackjack[2][playerid]);
    PlayerTextDrawShow(playerid, blackjack[13][playerid]);
    PlayerTextDrawShow(playerid, blackjack[14][playerid]);
    return 1;
}

stock HideBlackJack(playerid)
{
    for(new i; i < 15; i++)
    {
        PlayerTextDrawHide(playerid, blackjack[i][playerid]);
    }
    return 1;
}

ShuffleDeck()
{
    for (new i = 0; i < 52; i++)
    {
        cardDeck[i] = i;
    }
    for (new i = 0; i < 52; i++)
    {
        new randomIndex = random(52);
        new temp = cardDeck[i];
        cardDeck[i] = cardDeck[randomIndex];
        cardDeck[randomIndex] = temp;
    }
    return 1;
}

CalculateScore(cards[], cardCount)
{
    new score = 0, aces = 0;
    for (new i = 0; i < cardCount; i++)
    {
        new cardValue = (cards[i] % 13) + 1;
        if (cardValue > 10) cardValue = 10;
        if (cardValue == 1) aces++;        
        score += cardValue;
    }
    while (aces > 0 && score <= 11)
    {
        score += 10;
        aces--;
    }
    return score;
}

stock ShowCards(playerid, cards[], cardCount, const name[])
{
    new suitChar[32];
    new cardValue, suit;

    for (new i = 0; i < cardCount; i++)
    {
        cardValue = (cards[i] % 13) + 1;
        suit = cards[i] / 13;


        switch (suit)
        {
            case 0: format(suitChar, sizeof(suitChar), "s"); // Spades
            case 1: format(suitChar, sizeof(suitChar), "h"); // Hearts
            case 2: format(suitChar, sizeof(suitChar), "d"); // Diamonds
            case 3: format(suitChar, sizeof(suitChar), "c"); // Clubs
        }

        new cardText[64];
        
        if (strcmp(name, "Player", true) == 0) 
        {
            format(cardText, sizeof(cardText), "ld_card:cd%d%s", cardValue, suitChar);
            PlayerTextDrawSetString(playerid, blackjack[3 + i][playerid], cardText);
            PlayerTextDrawShow(playerid, blackjack[3 + i][playerid]); 
        }
        else if (strcmp(name, "Dealer", true) == 0)
        {
            if (i == 1)
            {
                format(cardText, sizeof(cardText), "ld_card:cdback");
            }
            else
            {
                format(cardText, sizeof(cardText), "ld_card:cd%d%s", cardValue, suitChar);
            }
            PlayerTextDrawSetString(playerid, blackjack[8 + i][playerid], cardText);
            PlayerTextDrawShow(playerid, blackjack[8 + i][playerid]); 
        }
    }

    return 1;
}

CMD:blackjack(playerid, params[])
{
    new Float:amount;
    new businessid = IsPlayerInBusiness(playerid);

    if (sscanf(params, "f", amount))
        return SendUsageMessage(playerid, "/blackjack [place your bet]");

    new Cents = floatround(amount * 100, floatround_round);
    
    if (amount < 0)
        return SendErrorMessage(playerid, "The bet amount must be greater than 0.");
        
    if (blackjackInProgress[playerid])
        return SendErrorMessage(playerid, "You already started blackjack.");

    if (amount > PlayerInfo[playerid][E_CHARACTER_MONEY])
        return SendErrorMessage(playerid, "You don't have enough money for this bet.");

    if(!IsPlayerInBusiness(playerid))
        return SendErrorMessage(playerid, "You aren't in any business.");
    
    if(BusinessInfo[businessid][E_BUSINESS_TYPE] != BUSINESS_TYPE_BAR)
        return SendErrorMessage(playerid, "You aren't in any business bar.");

    if(BusinessInfo[businessid][E_BUSINESS_BLACKJACK])
        return SendErrorMessage(playerid, "There is player using this table.");

    if(!IsPlayerInRangeOfPoint(playerid, 2.0, 1128.7081,-1.6211,1000.6797))
        return SendErrorMessage(playerid, "You aren't near blackjack table.");

    GivePlayerMoney(playerid, -Cents);
    blackjackPlayerBet[playerid] = Cents;

    ShuffleDeck();

    blackjackPlayerCards[playerid][blackjackPlayerCardsCount[playerid]++] = cardDeck[0];
    blackjackPlayerCards[playerid][blackjackPlayerCardsCount[playerid]++] = cardDeck[1];
    BusinessInfo[businessid][E_BUSINESS_DEALER_CARD][BusinessInfo[businessid][E_BUSINESS_DEALER_CARDCOUNT]++] = cardDeck[2];
    BusinessInfo[businessid][E_BUSINESS_DEALER_CARD][BusinessInfo[businessid][E_BUSINESS_DEALER_CARDCOUNT]++] = cardDeck[3];

    blackjackPlayerScore[playerid] = CalculateScore(blackjackPlayerCards[playerid], blackjackPlayerCardsCount[playerid]);
    BusinessInfo[businessid][E_BUSINESS_DEALER_SCORE] = CalculateScore(BusinessInfo[businessid][E_BUSINESS_DEALER_CARD], BusinessInfo[businessid][E_BUSINESS_DEALER_CARDCOUNT]);

    ShowCards(playerid, blackjackPlayerCards[playerid], blackjackPlayerCardsCount[playerid], "Player");
    ShowCards(playerid, BusinessInfo[businessid][E_BUSINESS_DEALER_CARD], BusinessInfo[businessid][E_BUSINESS_DEALER_CARDCOUNT], "Dealer");

    blackjackInProgress[playerid] = true;
    BusinessInfo[businessid][E_BUSINESS_BLACKJACK] = true;
    ShowBlackJack(playerid);
    SelectTextDraw(playerid, COLOR_YELLOW);
    SendServerMessage(playerid, "[Blackjack] {cdd0d1}You place blackjack bet for $%s to start blackjack type /hit or /stand.", FormatMoney(Cents));
    return 1;
}

ResetBlackjack(playerid)
{
    new businessid = IsPlayerInBusiness(playerid);
    BusinessInfo[businessid][E_BUSINESS_BLACKJACK] = false;
    blackjackInProgress[playerid] = false;
    blackjackPlayerCardsCount[playerid] = 0;
    BusinessInfo[businessid][E_BUSINESS_DEALER_CARDCOUNT] = 0;
    blackjackPlayerScore[playerid] = 0;
    BusinessInfo[businessid][E_BUSINESS_DEALER_SCORE] = 0;
    blackjackPlayerBet[playerid] = 0;
    HideBlackJack(playerid);
    CancelSelectTextDraw(playerid);
    return 1;
}