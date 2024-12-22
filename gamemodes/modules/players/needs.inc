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

        if(PlayerInfo[i][E_CHARACTER_THIRSTY])
        {
            new Float:rand = randomFloat(1.00);
            PlayerInfo[i][E_CHARACTER_THIRSTY] -= rand;
        }
        else if(PlayerInfo[i][E_CHARACTER_THIRSTY] > 100.0)
        {
            PlayerInfo[i][E_CHARACTER_THIRSTY] = 100.0;
        }
        else if(PlayerInfo[i][E_CHARACTER_THIRSTY] < 30.0)
        {
            new Float: health;
            GetPlayerHealth(i, health);
            SetPlayerHealthEx(i, health-2.00);
            SendInfoMessage(i, "[THIRSTY] You are thirsty rightnow, immediately drink at the nearest restaurant or you will unconscius.");
        }
        else
        {
            PlayerInfo[i][E_CHARACTER_THIRSTY] = 0;
        }

        if(PlayerInfo[i][E_CHARACTER_TOGHUD] == false && PlayerInfo[i][E_CHARACTER_SPAWNED] == true)
	    {
            SetPlayerProgressBarValue(i, HEBAR[0][i], PlayerInfo[i][E_CHARACTER_HUNGRY]);
            SetPlayerProgressBarValue(i, HEBAR[1][i], PlayerInfo[i][E_CHARACTER_THIRSTY]);
            SetPlayerProgressBarColour(i, HEBAR[0][i], ConvertHBEColor(PlayerInfo[i][E_CHARACTER_HUNGRY]));
            SetPlayerProgressBarColour(i, HEBAR[1][i], ConvertHBEColor(PlayerInfo[i][E_CHARACTER_THIRSTY]));
            ShowPlayerProgressBar(i, HEBAR[0][i]);
            ShowPlayerProgressBar(i, HEBAR[1][i]);
        }
        SaveCharacter(i); SaveCharacterPos(i);
    }
    return 1;
}

SetPlayerNeeds(playerid, Float:hungry, Float:thirsty)
{
    PlayerInfo[playerid][E_CHARACTER_HUNGRY] += hungry;
    PlayerInfo[playerid][E_CHARACTER_THIRSTY] += thirsty;

    if(PlayerInfo[playerid][E_CHARACTER_THIRSTY] > 100.0)
    {
        PlayerInfo[playerid][E_CHARACTER_THIRSTY] = 100.0;
    }
    if(PlayerInfo[playerid][E_CHARACTER_THIRSTY] < 0)
    {
        PlayerInfo[playerid][E_CHARACTER_THIRSTY] = 0;
    }

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
    for(new i; i < 4; i++)
    {
        SetPlayerProgressBarValue(playerid, HEBAR[0][playerid], PlayerInfo[playerid][E_CHARACTER_HUNGRY]);
        SetPlayerProgressBarValue(playerid, HEBAR[1][playerid], PlayerInfo[playerid][E_CHARACTER_THIRSTY]);
        SetPlayerProgressBarColour(playerid, HEBAR[0][playerid], ConvertHBEColor(PlayerInfo[playerid][E_CHARACTER_HUNGRY]));
        SetPlayerProgressBarColour(playerid, HEBAR[1][playerid], ConvertHBEColor(PlayerInfo[playerid][E_CHARACTER_THIRSTY]));
        PlayerTextDrawShow(playerid, HE[i][playerid]);
        ShowPlayerProgressBar(playerid, HEBAR[0][playerid]);
        ShowPlayerProgressBar(playerid, HEBAR[1][playerid]);
    }
    return 1;
}

HidePlayerNeeds(playerid)
{
    for(new i; i < 4; i++)
    {
        PlayerTextDrawHide(playerid, HE[i][playerid]);
        HidePlayerProgressBar(playerid, HEBAR[0][playerid]);
        HidePlayerProgressBar(playerid, HEBAR[1][playerid]);
    }
    return 1;
}