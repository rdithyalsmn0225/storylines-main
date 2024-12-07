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
        else if(PlayerInfo[i][E_CHARACTER_HUNGRY] < 30)
        {
            new Float: health;
            GetPlayerHealth(i, health);
            SetPlayerHealthEx(i, health-2.00);
            SendServerMessage(i, "[Hungry] {DEDEDE}You are hungry rightnow, immediately eat at the nearest restaurant or you will unconscius.");
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
        else if(PlayerInfo[i][E_CHARACTER_THIRSTY] < 30)
        {
            new Float: health;
            GetPlayerHealth(i, health);
            SetPlayerHealthEx(i, health-2.00);
            SendServerMessage(i, "[Thirsty] {DEDEDE}You are thirsty rightnow, immediately drink at the nearest restaurant or you will unconscius.");
        }
        else
        {
            PlayerInfo[i][E_CHARACTER_THIRSTY] = 0;
        }

        if(PlayerInfo[i][E_CHARACTER_TOGHUD] == false && PlayerInfo[i][E_CHARACTER_SPAWNED] == true)
	    {
            ShowPlayerNeeds(i);
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
    new str[6], str1[6];
    for(new i; i < 4; i++)
    {
        format(str, sizeof(str), "%0.1f", PlayerInfo[playerid][E_CHARACTER_HUNGRY]);
        format(str1, sizeof(str1), "%0.1f", PlayerInfo[playerid][E_CHARACTER_THIRSTY]);
        PlayerTextDrawSetString(playerid, HE[2][playerid], str);
        PlayerTextDrawSetString(playerid, HE[3][playerid], str1);
        PlayerTextDrawShow(playerid, HE[i][playerid]);
    }
    return 1;
}

HidePlayerNeeds(playerid)
{
    for(new i; i < 4; i++)
    {
        PlayerTextDrawHide(playerid, HE[i][playerid]);
    }
    return 1;
}