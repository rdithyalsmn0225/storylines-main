enum
{
    GAMEBAR_PLUS = 1,
    GAMEBAR_MINUS = 2
};

stock SetPlayerGameBar(playerid, Float: value)
{    
    SetPlayerProgressBarColour(playerid, HeaderBar[playerid], ConvertHBEColor(value));
    SetPlayerProgressBarValue(playerid, HeaderBar[playerid], value);
    ShowPlayerProgressBar(playerid, HeaderBar[playerid]);
    return 1;
}

