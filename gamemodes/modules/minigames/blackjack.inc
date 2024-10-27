new BlackJackBets[MAX_PLAYERS],
    BlackJackCard[MAX_PLAYERS][2][2],
    BlackJackCount[MAX_PLAYERS],
    bool:BlackJackPlay[MAX_PLAYERS],
    DealerCards[2][2];

stock GetCardValue(card[]) {
    if (card[0] == 1) return 11; // AS = 11
    if (card[0] > 10) return 10; // CARD 10, Jack, Queen, King
    return card[0];
}

stock GetPlayerBlackJackScore(playerid) {
    new score = 0;
    for (new i = 0; i < BlackJackCount[playerid]; i++) {
        score += GetCardValue(BlackJackCard[playerid][i]);
    }
    return score;
}

GetDealerBlackJackScore(businessid) {
    new score = 0;
    for (new i = 0; i < BusinessInfo[businessid][E_BUSINESS_DEALER_CARDCOUNT]; i++) {
        score += GetCardValue(DealerCards[i]);
    }
    return score;
}

StartBlackjack(playerid) 
{
    new businessid = IsPlayerInBusiness(playerid);

    BlackJackBets[playerid] = 0;
    BlackJackCount[playerid] = 0;
    BlackJackPlay[playerid] = true;
    BusinessInfo[businessid][E_BUSINESS_BLACKJACK] = true;
    Dialog_Show(playerid, BlackjackBet, DIALOG_STYLE_INPUT, "Blackjack:", "{ffffff}Welcome to Blackjack! Please enter the amount you wish to bet.\nRemember if you win you will get 2x the bet, and if you lose you will lose all your bets", "Enter", "Cancel");
    return 1;
}

ShowBlackjackStatus(playerid) 
{
    new str[1024];
    format(str, sizeof(str), "{ffffff}Your cards: {d7d292}%d{ffffff} and {d7d292}%d{ffffff}\nYour current score: {d7d292}%d{ffffff}\nDealer's cards: {d7d292}%d{ffffff} and {d7d292}?{ffffff}\nChoose your next move by typing {d7d292}'Hit'{ffffff} to draw another card or {d7d292}'Stand'{ffffff} to keep your current hand.", 
    BlackJackCard[playerid][0][0], BlackJackCard[playerid][1][0], GetPlayerBlackJackScore(playerid), DealerCards[0][0]);

    Dialog_Show(playerid, Blackjacks, DIALOG_STYLE_MSGBOX, "Blackjack:", str, "Hit", "Stand");
    return 1;
}

Dialog:BlackjackBet(playerid, response, listitem, inputtext[])
{
    if (response) 
    {
        new bet = strval(inputtext);

        if(bet > PlayerInfo[playerid][E_CHARACTER_MONEY])
            return SendErrorMessage(playerid, "You can't bet blackjack rightnow.");

        if (bet < 0) 
            return SendErrorMessage(playerid, "Your bet must be higher than 0!");
        
        BlackJackBets[playerid] = bet;
        GiveMoney(playerid, -bet);
        StartGame(playerid);
    }
    return 1;
}

Dialog:Blackjacks(playerid, response, listitem, inputtext[])
{   
    if(!response)
    {
        Stand(playerid);
    }

    Hit(playerid);
    return 1;
}

StartGame(playerid) 
{
    new businessid = IsPlayerInBusiness(playerid);

    for (new i = 0; i < 2; i++) {
        BlackJackCard[playerid][i][0] = random(10) + 1; // Card 1-10
        BlackJackCard[playerid][i][1] = BlackJackCard[playerid][i][0]; // Storing value
    }
    BlackJackCount[playerid] = 2;

    BusinessInfo[businessid][E_BUSINESS_DEALER_CARDCOUNT] = 0;
    BusinessInfo[businessid][E_BUSINESS_DEALER_SCORE] = 0;

    for (new i = 0; i < 2; i++) 
    {
        DealerCards[i][0] = random(10) + 1; // Card 1-10
        DealerCards[i][1] = DealerCards[i][0]; // Storing value
    }
    BusinessInfo[businessid][E_BUSINESS_DEALER_CARDCOUNT] = 2;

    ShowBlackjackStatus(playerid);
    return 1;
}

Hit(playerid) 
{
    if (BlackJackCount[playerid] < 5) 
    {
        ShowBlackjackStatus(playerid);
        return SendErrorMessage(playerid, "You can only have a maximum of 5 cards!");
    }

    BlackJackCard[playerid][BlackJackCount[playerid]][0] = random(10) + 1; // Card 1-10
    BlackJackCard[playerid][BlackJackCount[playerid]][1] = BlackJackCard[playerid][BlackJackCount[playerid]][0];
    BlackJackCount[playerid]++;
    ShowBlackjackStatus(playerid);

    // Check if the player loses
    if (GetPlayerBlackJackScore(playerid) > 21) 
    {
        SendServerMessage(playerid, "[Blackjack] {cdd0d1}You lossee! Your score exceeds 21.");
        ResetBlackjackVar(playerid);
    }
    return 1;
}

Stand(playerid) 
{
    new businessid = IsPlayerInBusiness(playerid);

    // Dealer draws cards until reaching 17
    while(BusinessInfo[businessid][E_BUSINESS_DEALER_SCORE] < 17) 
    {
        DealerCards[BusinessInfo[businessid][E_BUSINESS_DEALER_CARDCOUNT]][0] = random(10) + 1; // Card 1-10
        DealerCards[BusinessInfo[businessid][E_BUSINESS_DEALER_CARDCOUNT]][1] = DealerCards[BusinessInfo[businessid][E_BUSINESS_DEALER_CARDCOUNT]][0]; // Storing value
        BusinessInfo[businessid][E_BUSINESS_DEALER_CARDCOUNT]++;
    }

    BusinessInfo[businessid][E_BUSINESS_DEALER_SCORE] = GetDealerBlackJackScore(businessid);
    ShowBlackjackResult(playerid);
    return 1;
}

ShowBlackjackResult(playerid) 
{
    new businessid = IsPlayerInBusiness(playerid);

    SendServerMessage(playerid, "[Blackjack] {cdd0d1}Your final score: {d7d292}%d{cdd0d1} Dealer's final score: {d7d292}%d{cdd0d1}", GetPlayerBlackJackScore(playerid), BusinessInfo[businessid][E_BUSINESS_DEALER_SCORE]);

    if (GetPlayerBlackJackScore(playerid) > 21) 
    {
        SendServerMessage(playerid, "[Blackjack] {cdd0d1}You busted! You lose!");
    } 
    else if (BusinessInfo[businessid][E_BUSINESS_DEALER_SCORE] > 21 || GetPlayerBlackJackScore(playerid) > BusinessInfo[businessid][E_BUSINESS_DEALER_SCORE]) 
    {
        SendServerMessage(playerid, "[Blackjack] {cdd0d1}Congratulations! You win!");
    } 
    else if (GetPlayerBlackJackScore(playerid) < BusinessInfo[businessid][E_BUSINESS_DEALER_SCORE]) 
    {
        SendServerMessage(playerid, "[Blackjack] {cdd0d1}You lose! Better luck next time!");
    } 
    else 
    {
        SendServerMessage(playerid, "[Blackjack] {cdd0d1}It's a tie! No winners this time.");
    }

    ResetBlackjackVar(playerid);
}

stock ResetBlackjackVar(playerid) 
{
    new businessid = IsPlayerInBusiness(playerid);
    BlackJackBets[playerid] = 0;
    BlackJackCount[playerid] = 0;
    BlackJackPlay[playerid] = false;
    BusinessInfo[businessid][E_BUSINESS_DEALER_CARDCOUNT] = 0;
    BusinessInfo[businessid][E_BUSINESS_BLACKJACK] = false;
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

    StartBlackjack(playerid);
    return 1;
}