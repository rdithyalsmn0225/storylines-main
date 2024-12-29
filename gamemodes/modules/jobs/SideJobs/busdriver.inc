function:BusDrivers(playerid, type)
{
    new text[256];
    switch(type)
    {
        case 0:
        {
            PlayerInfo[playerid][E_CHARACTER_LOADINGCOUNT]++;

            switch(PlayerInfo[playerid][E_CHARACTER_LOADINGCOUNT])
            {
                case 2: text = "Loading passenger entering process\n(( ||----- ))";
                case 3: text = "Loading passenger entering process\n(( |||---- ))";
                case 4: text = "Loading passenger entering process\n(( ||||--- ))";
                case 5: text = "Loading passenger entering process\n(( |||||-- ))";
                case 6: text = "Loading passenger entering process\n(( ||||||- ))";
                case 7: text = "Loading passenger entering process\n(( ||||||| ))";
                case 8:
                {
                    PlayerBusDriverIndex[playerid]++;
                    GPS_SetPlayerRaceCheckPoint(playerid, 1, BusDriver_Index[PlayerBusDriverIndex[playerid]][0],BusDriver_Index[PlayerBusDriverIndex[playerid]][1], BusDriver_Index[PlayerBusDriverIndex[playerid]][2], 0.0, 0.0, 0.0, GPS_BUSDRIVER);
                    TogglePlayerControllable(playerid, true);

                    SendJobsMessage(playerid, "[Bus Driver] Current route : %s | Next Route : %s.", ReturnLocation(playerid), GetZoneName(BusDriver_Index[PlayerBusDriverIndex[playerid]][0],BusDriver_Index[PlayerBusDriverIndex[playerid]][1], BusDriver_Index[PlayerBusDriverIndex[playerid]][2]));
                    
                    PlayerInfo[playerid][E_CHARACTER_LOADING] = false;
                    PlayerInfo[playerid][E_CHARACTER_LOADINGCOUNT] = 0;

                    Delete3DTextLabel(PlayerInfo[playerid][E_CHARACTER_LOADINGDISPLAY]); 
                    KillTimer(PlayerInfo[playerid][E_CHARACTER_LOADINGTIMER]);

                    SetPlayerNeeds(playerid, -0.2);

                    new gstr[128];
                    format(gstr, sizeof(gstr),"~w~Passanger Entering~n~~r~%i~w~/~g~22", PlayerBusDriverIndex[playerid]);
                    ShowBoxMessage(playerid, gstr, 5);
                    
                    if(PlayerBusDriverIndex[playerid] == 21)
                    {
                        new randx = randomEx(3, 5);
                        new total = (PlayerBusDriverIndex[playerid] * randx);

                        new Cents = floatround(total * 100, floatround_round);

	                    GiveMoney(playerid, Cents);

                        ShowBoxMessage(playerid, "~r~Bus Driver job ended.", 5); 
                        SendJobsMessage(playerid, "[Bus Driver] Bus Route Complete, current passenger %d x passenger and earn $%s.", PlayerBusDriverIndex[playerid], FormatMoney(Cents));

                        PlayerInfo[playerid][E_CHARACTER_BUSDRIVER] = false;
                        PlayerBusDriverIndex[playerid] = 0;
                        PlayerInfo[playerid][E_CHARACTER_BUSDRIVERCD] = 12;
                            
                        GPS_DisablePlayerRaceCheckPoint(playerid);
                        DestroyVehicle(PlayerInfo[playerid][E_CHARACTER_JOBSVEHICLE]);
                        PlayerInfo[playerid][E_CHARACTER_LOADING] = false;
                        PlayerInfo[playerid][E_CHARACTER_LOADINGCOUNT] = 0;

                        Delete3DTextLabel(PlayerInfo[playerid][E_CHARACTER_LOADINGDISPLAY]); 
                        KillTimer(PlayerInfo[playerid][E_CHARACTER_LOADINGTIMER]);
                    }
                }
            }
        }
    }
    Update3DTextLabelText(PlayerInfo[playerid][E_CHARACTER_LOADINGDISPLAY], COLOR_3DTEXT, text); 
}

CMD:viewroute(playerid, params[])
{
    new str[2024];
    for(new i; i < sizeof(BusStop_Index); i++)
	{
        if(IsPlayerInRangeOfPoint(playerid, 3.0, BusStop_Index[i][0], BusStop_Index[i][1], BusStop_Index[i][2]))
        {
            for(new a; a < sizeof(BusStop_Index); a++)
	        {
                format(str, sizeof(str), "%s%s\n", str, GetZoneName(BusStop_Index[a][0], BusStop_Index[a][1], BusStop_Index[a][2]));
            }
            ShowPlayerDialog(playerid, DIALOG_DEFAULT, DIALOG_STYLE_LIST, "View Route:", str, "Close", "");
        }
    }
    return 1;
}