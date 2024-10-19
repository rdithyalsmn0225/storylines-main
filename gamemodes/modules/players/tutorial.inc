stock NextTutorial(playerid)
{
    PlayerInfo[playerid][E_CHARACTER_TUTORIALSTEP]++;
    ShowTutorial(playerid);

    if(PlayerInfo[playerid][E_CHARACTER_TUTORIALSTEP] >= 15)
    {
        PlayerInfo[playerid][E_CHARACTER_TUTORIALSTEP] = 0;
        PlayerInfo[playerid][E_CHARACTER_TUTORIAL] = 1;
        SaveCharacter(playerid);

        PlayerTextDrawHide(playerid, tutorialtext[playerid]);
        PlayerTextDrawHide(playerid, tutorialbox[playerid]);
        PlayerTextDrawHide(playerid, tutorialheader[playerid]);
        PlayerTextDrawHide(playerid, tutorialclick[playerid]);
        CancelSelectTextDraw(playerid);

        SetCameraBehindPlayer(playerid);
        LoadCharacter(playerid);
        TogglePlayerSpectating(playerid, false);
    }
    return 1;
}

ShowTutorial(playerid)
{
    switch(PlayerInfo[playerid][E_CHARACTER_TUTORIALSTEP])
    {
        case 1:
        {
            new text[2024];
            InterpolateCameraPos(playerid, 1413.479736, -1727.495483, 32.772384, 1551.484497, -1726.705932, 32.781917, 8000, 1);
            InterpolateCameraLookAt(playerid, 1415.520385, -1730.730590, 31.602050, 1548.272216, -1729.019531, 32.208690, 8000, 1);

            PlayerTextDrawSetString(playerid, tutorialheader[playerid], "The Introduction: Part 1");

            format(text, sizeof(text), "~w~Welcome to ~y~Los santos~w~, a city tearing itself apart with gang trouble, drugs and corruption.~n~~n~");
            format(text, sizeof(text), "%sWhere film stars and millionaires do their best to avoid the dealers and gangbangers.~n~~n~", text);
            format(text, sizeof(text), "%sIt's 1996, and the war for control of the streets rages as fiercely as ever.", text);
            PlayerTextDrawSetString(playerid, tutorialtext[playerid], text);
        }
        case 2:
        {
            new text[2024];
            InterpolateCameraPos(playerid, 2466.783447, -1645.420532, 30.787904, 2514.717041, -1633.347412, 30.357999, 8000, 1);
            InterpolateCameraLookAt(playerid, 2468.859130, -1648.307983, 28.956512, 2513.349609, -1636.968505, 29.349018, 8000, 1);

            PlayerTextDrawSetString(playerid, tutorialheader[playerid], "The Introduction: Part 2");

            format(text, sizeof(text), "~w~We pick up where the singleplayers protagonist left off, four years after the event of Carl Johnson.~n~~n~");
            format(text, sizeof(text), "%sThe server has exists ever 2024 in still developments, originally as ~p~'GTA Storylines'~w~(IDLS).~n~~n~", text);
            format(text, sizeof(text), "%sThe current owner is Radeetz / Bleeda (In-Game).", text);
            PlayerTextDrawSetString(playerid, tutorialtext[playerid], text);
        }
        case 3:
        {
            new text[2024];
            InterpolateCameraPos(playerid, 1938.430175, -1617.597656, 36.106594, 1839.665527, -1615.668334, 37.529151, 8000, 1);
            InterpolateCameraLookAt(playerid, 1935.654663, -1615.258544, 34.425868, 1842.909667, -1614.179565, 35.723739, 8000, 1);

            PlayerTextDrawSetString(playerid, tutorialheader[playerid], "The Introduction: Part 3");

            format(text, sizeof(text), "~w~In this brief tutorial you will learn about the server's features, theme and settings.~n~~n~");
            format(text, sizeof(text), "%sThis tutorial servers as an introduction - meaning only essential system will be explained.~n~~n~", text);
            format(text, sizeof(text), "%sThe rest is up to you to discover.", text);
            PlayerTextDrawSetString(playerid, tutorialtext[playerid], text);
        }
        case 4:
        {
            new text[2024];
            InterpolateCameraPos(playerid, 2206.365234, -1469.589477, 35.373554, 2213.208496, -1396.919555, 36.038364, 8000, 1);
            InterpolateCameraLookAt(playerid, 2209.201660, -1466.958496, 34.357521, 2215.659423, -1399.940429, 35.107196, 8000, 1);

            PlayerTextDrawSetString(playerid, tutorialheader[playerid], "Hood-life: Part 1");

            format(text, sizeof(text), "~w~If a life in the hood is for you, you won't last very long without joining one of the many gangs.~n~~n~");
            format(text, sizeof(text), "%sThey will take care of you, but you must first prove yourself as a hoodrat.~n~~n~", text);
            format(text, sizeof(text), "%sOnce the O.G's deem you fit you will gain your rag.", text);
            PlayerTextDrawSetString(playerid, tutorialtext[playerid], text);
        }
        case 5:
        {
            new text[2024];
            InterpolateCameraPos(playerid, 2513.955078, -1366.187866, 35.911403, 2512.737060, -1438.414672, 33.586414, 8000, 1);
            InterpolateCameraLookAt(playerid, 2511.511962, -1369.144531, 34.775981, 2510.291503, -1435.292846, 33.063747, 8000, 1);

            PlayerTextDrawSetString(playerid, tutorialheader[playerid], "Hood-life: Part 2");

            format(text, sizeof(text), "~w~You have the ~g~famillies~w~, the ~p~ballas~w~, the ~b~Aztecas ~w~and the ~y~Vagos~w~.~n~~n~");
            format(text, sizeof(text), "%sThere are more factions, however those four sets are the beating heart of the los santos.~n~~n~", text);
            format(text, sizeof(text), "%sWhich side will you pick?.", text);
            PlayerTextDrawSetString(playerid, tutorialtext[playerid], text);
        }
        case 6:
        {
            new text[2024];
            InterpolateCameraPos(playerid, 2124.582031, -1498.746826, 36.212779, 2173.653564, -1556.435913, 34.428169, 8000, 1);
            InterpolateCameraLookAt(playerid, 2127.849609, -1496.901123, 34.828281, 2172.727294, -1552.672119, 33.440372, 8000, 1);


            PlayerTextDrawSetString(playerid, tutorialheader[playerid], "Hood-life: Part 3");

            format(text, sizeof(text), "~w~As a hoodrat you must prove yourself.~n~~n~");
            format(text, sizeof(text), "%sJoin your gang in brawls, spraying graffiti on enemy turfs, host and join parties (BBQ, fight club, ...) and more.~n~~n~", text);
            format(text, sizeof(text), "%sOur server really tries to capture the hood roleplay moreso than any other server.", text);
            PlayerTextDrawSetString(playerid, tutorialtext[playerid], text);
        }
        case 7:
        {
            new text[2024];
            InterpolateCameraPos(playerid, 2458.533203, -1957.664184, 23.472000, 2457.515380, -1987.545654, 22.843036, 10000, 1);
            InterpolateCameraLookAt(playerid, 2455.841308, -1960.108276, 21.804517, 2455.253417, -1984.469238, 21.651803, 10000, 1);

            PlayerTextDrawSetString(playerid, tutorialheader[playerid], "Hood-life: Part 4");

            format(text, sizeof(text), "~w~There will come a day where you must defend your territory with your homies..~n~~n~");
            format(text, sizeof(text), "%sYou can stop by ~y~Emmet ~w~ to buy melee weapons or firearms after playing for less than 5 level.~n~~n~", text);
            format(text, sizeof(text), "%sEmmet only sells cheap, low quality weapons though so if you need something better, you'll have to look around.", text);
            PlayerTextDrawSetString(playerid, tutorialtext[playerid], text);
        }
        case 8:
        {
            new text[2024];
            InterpolateCameraPos(playerid, 2001.528686, -1446.165039, 14.902767, 2001.528686, -1446.165039, 38.552772, 8000, 1);
            InterpolateCameraLookAt(playerid, 2004.452026, -1443.478515, 14.416265, 2004.093383, -1443.901245, 36.479633, 8000, 1);

            PlayerTextDrawSetString(playerid, tutorialheader[playerid], "Streets-Life: Part 1");

            format(text, sizeof(text), "~w~If you get injured among the chaos at the strees, it won't hurt to eat at a ~y~restaurant~w~.~n~~n~");
            format(text, sizeof(text), "%sWe have an intricate injury system with different damages types (weapons).~n~~n~", text);
            format(text, sizeof(text), "%sTo heal these injuries you can visit the ~y~Hospital~w~.", text);
            PlayerTextDrawSetString(playerid, tutorialtext[playerid], text);
        }
        case 9:
        {
            new text[2024];
            InterpolateCameraPos(playerid, 1512.489013, -1600.724975, 30.028594, 1517.772338, -1723.045654, 30.310438, 8000, 1);
            InterpolateCameraLookAt(playerid, 1516.027832, -1602.182250, 28.865236, 1520.395629, -1720.173095, 29.379268, 8000, 1);


            PlayerTextDrawSetString(playerid, tutorialheader[playerid], "City-Politics: Part 1");

            format(text, sizeof(text), "~w~The ~b~Los Santos Police Departement~w~ is based harm in Pershing Square.~n~~n~");
            format(text, sizeof(text), "%sWhile admired as heroes by some, for most others they're just the biggest gang in town.~n~~n~", text);
            format(text, sizeof(text), "%sThanks to the horrible crime rate though, you can be sure that the LSPD is hiring all year round.", text);
            PlayerTextDrawSetString(playerid, tutorialtext[playerid], text);
        }
        case 10:
        {
            new text[2024];
            InterpolateCameraPos(playerid, 2088.558837, -1763.409301, 23.669414, 2080.964355, -1833.052368, 23.991256, 8000, 1);
            InterpolateCameraLookAt(playerid, 2090.654541, -1766.579956, 22.422624, 2083.775878, -1830.458984, 22.820924, 8000, 1);

            PlayerTextDrawSetString(playerid, tutorialheader[playerid], "Earning-Money: Part 1");

            format(text, sizeof(text), "~w~While a life at crime might not be for everyone, money definitely is.~n~~n~");
            format(text, sizeof(text), "%sVisit one of the many enterable stores around town to spend your paper.~n~~n~", text);
            format(text, sizeof(text), "%sJusr don't stick around in one for too long. they got robbed A lot.", text);
            PlayerTextDrawSetString(playerid, tutorialtext[playerid], text);
        }
        case 11:
        {
            new text[2024];
            InterpolateCameraPos(playerid, 2742.936523, -2392.722900, 32.227958, 2748.652587, -2513.919433, 31.913881, 8000, 1);
            InterpolateCameraLookAt(playerid, 2746.560058, -2393.331542, 30.647098, 2751.796630, -2511.838623, 30.577379, 8000, 1);

            PlayerTextDrawSetString(playerid, tutorialheader[playerid], "Earning-Money: Part 2");

            format(text, sizeof(text), "~w~The easiest way to make money, at course, is by gangbanging.~n~~n~");
            format(text, sizeof(text), "%sThat doesn't mean there aren't simpler alternatives howerver that pay out fast.~n~~n~", text);
            format(text, sizeof(text), "%sThe ~y~Trucking~w~, ~b~Taxi Driver~w~, ~g~Lumberjack, ~w~Etc. ~w~Will have you organize to earn some money.", text);
            PlayerTextDrawSetString(playerid, tutorialtext[playerid], text);
        }
        case 12:
        {
            new text[2024];
            InterpolateCameraPos(playerid, 1830.169067, -1733.915771, 36.338600, 1917.382324, -1747.835815, 36.338600, 8000, 1);
            InterpolateCameraLookAt(playerid, 1831.409423, -1737.286987, 34.578880, 1914.078491, -1749.531250, 34.852016, 8000, 1);

            PlayerTextDrawSetString(playerid, tutorialheader[playerid], "Getting-About: Part 1");

            format(text, sizeof(text), "~w~If you really want to fit in with the locals, you'll need a cars.~n~~n~");
            format(text, sizeof(text), "%sHundreds of different cars, motorcycles and bikes are available at the various ~y~dealership~w~.~n~~n~", text);
            format(text, sizeof(text), "%sYou can find dealership on the map, or use the GPS system.", text);
            PlayerTextDrawSetString(playerid, tutorialtext[playerid], text);
        }
        case 13:
        {
            new text[2024];
            InterpolateCameraPos(playerid, 1306.625854, -1524.384643, 28.650497, 1303.370361, -1572.435546, 29.553781, 8000, 1);
            InterpolateCameraLookAt(playerid, 1303.046142, -1525.567626, 27.313995, 1300.775634, -1569.602661, 28.439352, 8000, 1);

            PlayerTextDrawSetString(playerid, tutorialheader[playerid], "Getting-About: Part 2");

            format(text, sizeof(text), "~w~But you'll need a driver license to legally drive or buy a car of your own.~n~~n~");
            format(text, sizeof(text), "%sGet a license at the ~y~Departement of Motor Vehicles~w~.~n~~n~", text);
            format(text, sizeof(text), "%sReal gangsters drive without a license though.", text);
            PlayerTextDrawSetString(playerid, tutorialtext[playerid], text);
        }
        case 14:
        {
            new text[2024];
            InterpolateCameraPos(playerid, 2839.509521, -1670.011596, 10.978911, 2839.509521, -1670.011596, 53.218914, 8000, 1);
            InterpolateCameraLookAt(playerid, 2836.227539, -1672.127197, 10.111680, 2836.869628, -1672.138916, 51.096111, 8000, 1);

            PlayerTextDrawSetString(playerid, tutorialheader[playerid], "Conclusion: Part 1");

            format(text, sizeof(text), "~w~That concludes this short introduction, but with 20 percent of tho city remodelled there's so much more to explore.~n~~n~");
            format(text, sizeof(text), "%sType ~y~/help ~w~for more information.~n~~n~", text);
            format(text, sizeof(text), "%sType ~y~/report ~w~ for admin assistance.", text);
            PlayerTextDrawSetString(playerid, tutorialtext[playerid], text);
        }
        case 15:
        {
            new text[2024];
            InterpolateCameraPos(playerid, 1989.346435, -1464.555664, 30.808040, 1871.237426, -1470.027099, 30.808040, 8000, 1);
            InterpolateCameraLookAt(playerid, 1986.860595, -1461.811645, 29.294420, 1873.453857, -1466.899414, 29.665630, 8000, 1);

            PlayerTextDrawSetString(playerid, tutorialclick[playerid], "FINISH");
            PlayerTextDrawSetString(playerid, tutorialheader[playerid], "Conclusion: Part 2");

            format(text, sizeof(text), "~w~We are very active on ~p~Discord~w~ and highly recommend join of ~y~https://idlestreet.xyz/discord~w~.~n~~n~");
            format(text, sizeof(text), "%sHere you can vote on upcoming updates and most importantly become part of the community.~n~~n~", text);
            format(text, sizeof(text), "%sHave fun and enjoy your today!.", text);
            PlayerTextDrawSetString(playerid, tutorialtext[playerid], text);
        }
    }
    PlayerTextDrawShow(playerid, tutorialheader[playerid]);
	PlayerTextDrawShow(playerid, tutorialbox[playerid]);
	PlayerTextDrawShow(playerid, tutorialtext[playerid]);
	PlayerTextDrawShow(playerid, tutorialclick[playerid]);
    return 1;
}