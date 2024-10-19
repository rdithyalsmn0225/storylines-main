enum
{
    GAMEBAR_PLUS = 1,
    GAMEBAR_MINUS = 2
};

stock SetPlayerGameBar(playerid, Float: value)
{    
    SetPlayerProgressBarValue(playerid, HeaderBar[playerid], value);
    SetPlayerProgressBarColour(playerid, HeaderBar[playerid], ConvertHBEColor(value));
    return 1;
}

