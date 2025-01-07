new Text3D:PlayerNameTags[MAX_PLAYERS];

stock GetHealthDots(playerid)
{
    new dots[64];
    new Float:HP;
 
    GetPlayerHealth(playerid, HP);
 
    if(HP == 100)
        dots = "oooooooooo";
    else if(HP >= 90 && HP < 100)
        dots = "ooooooooo{660000}o";
    else if(HP >= 80 && HP < 90)
        dots = "oooooooo{660000}oo";
    else if(HP >= 70 && HP < 80)
        dots = "ooooooo{660000}ooo";
    else if(HP >= 60 && HP < 70)
        dots = "oooooo{660000}oooo";
    else if(HP >= 50 && HP < 60)
        dots = "ooooo{660000}ooooo";
    else if(HP >= 40 && HP < 50)
        dots = "oooo{660000}oooooo";
    else if(HP >= 30 && HP < 40)
        dots = "ooo{660000}ooooooo";
    else if(HP >= 20 && HP < 30)
        dots = "oo{660000}oooooooo";
    else if(HP >= 10 && HP < 20)
        dots = "oo{660000}oooooooo";
    else if(HP >= 0 && HP < 10)
        dots = "{660000}oooooooooo";
 
    return dots;
}
stock GetArmorDots(playerid)
{
    new dots[64];
    new Float:AR;
 
    GetPlayerArmour(playerid, AR);
 
    if(AR == 100)
        dots = "oooooooooo";
    else if(AR >= 90 && AR < 100)
        dots = "ooooooooo{666666}o";
    else if(AR >= 80 && AR < 90)
        dots = "oooooooo{666666}oo";
    else if(AR >= 70 && AR < 80)
        dots = "ooooooo{666666}ooo";
    else if(AR >= 60 && AR < 70)
        dots = "oooooo{666666}oooo";
    else if(AR >= 50 && AR < 60)
        dots = "ooooo{666666}ooooo";
    else if(AR >= 40 && AR < 50)
        dots = "oooo{666666}oooooo";
    else if(AR >= 30 && AR < 40)
        dots = "ooo{666666}ooooooo";
    else if(AR >= 20 && AR < 30)
        dots = "oo{666666}oooooooo";
    else if(AR >= 10 && AR < 20)
        dots = "oo{666666}oooooooo";
    else if(AR >= 0 && AR < 10)
        dots = "{666666}oooooooooo";
 
    return dots;
}

NameTagsConnect(playerid)
{
    PlayerNameTags[playerid] = CreateDynamic3DTextLabel("Loading nametag...", 0xFFFFFFFF, 0.0, 0.0, 0.1, 20.0, .attachedplayer = playerid, .testlos = 1);
    return 1;
}

NameTagsDisconnect(playerid)
{
    if(IsValidDynamic3DTextLabel(PlayerNameTags[playerid])) 
        DestroyDynamic3DTextLabel(PlayerNameTags[playerid]); 
    return 1;
}

function:UpdateNameTagsTicks(playerid)
{
    new i = playerid;
    
    if(IsPlayerConnected(i))
    {
        new nametag[128], Float:armour;
        GetPlayerArmour(i, armour);
        
        if(PlayerInfo[i][E_CHARACTER_ADMINDUTY])
        {
            format(nametag, sizeof(nametag), "{F9CB9C}[ADMIN DUTY]\n{%06x}%s (%i)", GetPlayerColor(i) >>> 8, ReturnName(i, 0), i);
        }
        else
        {
            format(nametag, sizeof(nametag), "{%06x}%s (%i)", GetPlayerColor(i) >>> 8, ReturnName(i, 0), i, GetHealthDots(i));
        }
        UpdateDynamic3DTextLabelText(PlayerNameTags[i], 0xFFFFFFFF, nametag);
    }
    return 1;
}