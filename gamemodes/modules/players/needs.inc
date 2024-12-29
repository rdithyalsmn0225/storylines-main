function:OnPlayerNeedUpdate()
{
    foreach(new i : Player)
    {
        if(PlayerInfo[i][E_CHARACTER_SPAWNED] == false)
            return 0;

        if(PlayerInfo[i][E_CHARACTER_HUNGRY])
        {
            new Float:rand = randomFloat(1.00);
            PlayerInfo[i][E_CHARACTER_HUNGRY] -= rand;
        }
        else if(PlayerInfo[i][E_CHARACTER_HUNGRY] > 100.0)
        {
            PlayerInfo[i][E_CHARACTER_HUNGRY] = 100.0;
        }
        else if(PlayerInfo[i][E_CHARACTER_HUNGRY] < 30)
        {
            new Float: health;
            GetPlayerHealth(i, health);
            SetPlayerHealthEx(i, health-2.00);
            SendInfoMessage(i, "[HUNGRY] You are hungry rightnow, immediately eat at the nearest restaurant or you will unconscius.");
        }
        else
        {
            PlayerInfo[i][E_CHARACTER_HUNGRY] = 0;
        }

        if(PlayerInfo[i][E_CHARACTER_TOGHUD] == false && PlayerInfo[i][E_CHARACTER_SPAWNED] == true)
	    {
            SetPlayerProgressBarValue(i, HEBAR[0][i], PlayerInfo[i][E_CHARACTER_HUNGRY]);
            SetPlayerProgressBarColour(i, HEBAR[0][i], ConvertHBEColor(PlayerInfo[i][E_CHARACTER_HUNGRY]));
            ShowPlayerProgressBar(i, HEBAR[0][i]);
        }
        SaveCharacter(i); SaveCharacterPos(i);
    }
    return 1;
}

SetPlayerNeeds(playerid, Float:hungry)
{
    PlayerInfo[playerid][E_CHARACTER_HUNGRY] += hungry;
    if(PlayerInfo[playerid][E_CHARACTER_HUNGRY] > 100.0)
    {
        PlayerInfo[playerid][E_CHARACTER_HUNGRY] = 100.0;
    }
    if(PlayerInfo[playerid][E_CHARACTER_HUNGRY] < 0)
    {
        PlayerInfo[playerid][E_CHARACTER_HUNGRY] = 0;
    }
    return 1;
}

ShowPlayerNeeds(playerid)
{
    for(new i; i < 2; i++)
    {
        SetPlayerProgressBarValue(playerid, HEBAR[0][playerid], PlayerInfo[playerid][E_CHARACTER_HUNGRY]);
        SetPlayerProgressBarColour(playerid, HEBAR[0][playerid], ConvertHBEColor(PlayerInfo[playerid][E_CHARACTER_HUNGRY]));
        PlayerTextDrawShow(playerid, HE[i][playerid]);
        ShowPlayerProgressBar(playerid, HEBAR[0][playerid]);
    }
    return 1;
}

HidePlayerNeeds(playerid)
{
    for(new i; i < 2; i++)
    {
        PlayerTextDrawHide(playerid, HE[i][playerid]);
        HidePlayerProgressBar(playerid, HEBAR[0][playerid]);
    }
    return 1;
}

ConvertTextDrawsToDots(Float:value)
{
    new dots[24];
    if(value >= 100.0)
        dots = "~g~IIIIIIIIII";
    else if(value >= 90.0)
        dots = "~g~IIIIIIIII";
    else if(value >= 80.0)
        dots = "~g~IIIIIIII";
    else if(value >= 70.0)
        dots = "~g~IIIIIII";
    else if(value >= 60.0)
        dots = "~y~IIIIII";
    else if(value >= 50.0)
        dots = "~y~IIIII";
    else if(value >= 40.0)
        dots = "~y~IIII";
    else if(value >= 30.0)
        dots = "~r~III";
    else if(value >= 20.0)
        dots = "~r~II";
    else if(value >= 10.0)
        dots = "~r~I";
    else if(value >= 0.0)
        dots = "";

    return dots;
}