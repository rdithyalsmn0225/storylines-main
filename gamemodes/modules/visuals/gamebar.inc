enum
{
    GAMEBAR_PLUS = 1,
    GAMEBAR_MINUS = 2
};

stock SetPlayerGameBar(playerid, PlayerText:playertextid, value, type)
{
    new result[256];
    if(type == GAMEBAR_PLUS)
    {
        if(value >= 100)
            format(result, sizeof(result), "mdl-2001:25");
        else if(value >= 96)
            format(result, sizeof(result), "mdl-2001:24");
        else if(value >= 92)
            format(result, sizeof(result), "mdl-2001:23");
        else if(value >= 88)
            format(result, sizeof(result), "mdl-2001:22");
        else if(value >= 84)
            format(result, sizeof(result), "mdl-2001:21");
        else if(value >= 80)
            format(result, sizeof(result), "mdl-2001:20");
        else if(value >= 76)
            format(result, sizeof(result), "mdl-2001:19");
        else if(value >= 72)
            format(result, sizeof(result), "mdl-2001:18");
        else if(value >= 68)
            format(result, sizeof(result), "mdl-2001:17");
        else if(value >= 64)
            format(result, sizeof(result), "mdl-2001:16");
        else if(value >= 60)
            format(result, sizeof(result), "mdl-2001:15");
        else if(value >= 56)
            format(result, sizeof(result), "mdl-2001:14");
        else if(value >= 52)
            format(result, sizeof(result), "mdl-2001:13");
        else if(value >= 48)
            format(result, sizeof(result), "mdl-2001:12");
        else if(value >= 44)
            format(result, sizeof(result), "mdl-2001:11");
        else if(value >= 40)
            format(result, sizeof(result), "mdl-2001:10");
        else if(value >= 36)
            format(result, sizeof(result), "mdl-2001:9");
        else if(value >= 32)
            format(result, sizeof(result), "mdl-2001:8");
        else if(value >= 28)
            format(result, sizeof(result), "mdl-2001:7");
        else if(value >= 24)
            format(result, sizeof(result), "mdl-2001:6");
        else if(value >= 20)
            format(result, sizeof(result), "mdl-2001:5");
        else if(value >= 16)
            format(result, sizeof(result), "mdl-2001:4");
        else if(value >= 12)
            format(result, sizeof(result), "mdl-2001:3");
        else if(value >= 8)
            format(result, sizeof(result), "mdl-2001:2");
        else if(value >= 4)
            format(result, sizeof(result), "mdl-2001:1");
        else if(value >= 0)
            format(result, sizeof(result), "mdl-2001:0");
    }
    else if(type == GAMEBAR_MINUS)
    {
       if(value >= 100)
            format(result, sizeof(result), "mdl-2001:-25");
        else if(value >= 96)
            format(result, sizeof(result), "mdl-2001:-24");
        else if(value >= 92)
            format(result, sizeof(result), "mdl-2001:-23");
        else if(value >= 88)
            format(result, sizeof(result), "mdl-2001:-22");
        else if(value >= 84)
            format(result, sizeof(result), "mdl-2001:-21");
        else if(value >= 80)
            format(result, sizeof(result), "mdl-2001:-20");
        else if(value >= 76)
            format(result, sizeof(result), "mdl-2001:-19");
        else if(value >= 72)
            format(result, sizeof(result), "mdl-2001:-18");
        else if(value >= 68)
            format(result, sizeof(result), "mdl-2001:-17");
        else if(value >= 64)
            format(result, sizeof(result), "mdl-2001:-16");
        else if(value >= 60)
            format(result, sizeof(result), "mdl-2001:-15");
        else if(value >= 56)
            format(result, sizeof(result), "mdl-2001:-14");
        else if(value >= 52)
            format(result, sizeof(result), "mdl-2001:-13");
        else if(value >= 48)
            format(result, sizeof(result), "mdl-2001:-12");
        else if(value >= 44)
            format(result, sizeof(result), "mdl-2001:-11");
        else if(value >= 40)
            format(result, sizeof(result), "mdl-2001:-10");
        else if(value >= 36)
            format(result, sizeof(result), "mdl-2001:-9");
        else if(value >= 32)
            format(result, sizeof(result), "mdl-2001:-8");
        else if(value >= 28)
            format(result, sizeof(result), "mdl-2001:-7");
        else if(value >= 24)
            format(result, sizeof(result), "mdl-2001:-6");
        else if(value >= 20)
            format(result, sizeof(result), "mdl-2001:-5");
        else if(value >= 16)
            format(result, sizeof(result), "mdl-2001:-4");
        else if(value >= 12)
            format(result, sizeof(result), "mdl-2001:-3");
        else if(value >= 8)
            format(result, sizeof(result), "mdl-2001:-2");
        else if(value >= 4)
            format(result, sizeof(result), "mdl-2001:-1");
        else if(value >= 0)
            format(result, sizeof(result), "mdl-2001:-0");
    }
    PlayerTextDrawSetString(playerid, playertextid, result);
    PlayerTextDrawShow(playerid, playertextid);
    return 1;
}

