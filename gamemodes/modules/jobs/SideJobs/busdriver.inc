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
                    
                    new rand = random(sizeof(BusDriver_Index));

                    GPS_SetPlayerRaceCheckPoint(playerid, 1, BusDriver_Index[rand][0],BusDriver_Index[rand][1], BusDriver_Index[rand][2], 0.0, 0.0, 0.0, GPS_BUSDRIVER);
                    TogglePlayerControllable(playerid, true);

                    SendServerMessage(playerid, "[Bus Driver] {cdd0d1}Current route : %s | Next Route : %s.", ReturnLocation(playerid), GetZoneName(BusDriver_Index[rand][0],BusDriver_Index[rand][1], BusDriver_Index[rand][2]));
                    
                    PlayerInfo[playerid][E_CHARACTER_LOADING] = false;
                    PlayerInfo[playerid][E_CHARACTER_LOADINGCOUNT] = 0;

                    Delete3DTextLabel(PlayerInfo[playerid][E_CHARACTER_LOADINGDISPLAY]); 
                    KillTimer(PlayerInfo[playerid][E_CHARACTER_LOADINGTIMER]);

                    PlayerBusDriverIndex[playerid]++;

                    new gstr[128];
                    format(gstr, sizeof(gstr),"~w~Passanger Entering~n~~r~%i~w~/~g~20", PlayerBusDriverIndex[playerid]);
                    ShowBoxMessage(playerid, gstr, 5);
                    
                    if(PlayerBusDriverIndex[playerid] == 19)
                    {
                        GPS_SetPlayerRaceCheckPoint(playerid, 1, 1696.8093,-1527.8206,13.4835, 0.0, 0.0, 0.0, GPS_BUSDRIVER);
                    }
                    if(PlayerBusDriverIndex[playerid] == 20)
                    {
                        new total = (PlayerBusDriverIndex[playerid] * BUSDRIVER_SALARY);

                        new Cents = floatround(total * 100, floatround_round);

	                    GiveMoney(playerid, Cents);

                        ShowBoxMessage(playerid, "~r~Bus Driver job ended.", 5); 
                        SendServerMessage(playerid, "[Bus Driver] {cdd0d1}Bus Route Complete, current passenger {d7d292}%d{cdd0d1} x passenger and earn {93C47D}$%s{cdd0d1}.", PlayerBusDriverIndex[playerid], FormatMoney(Cents));

                        PlayerInfo[playerid][E_CHARACTER_BUSDRIVER] = false;
                        PlayerBusDriverIndex[playerid] = 0;
                        PlayerInfo[playerid][E_CHARACTER_BUSDRIVERCD] = 12;
                            
                        GPS_DisablePlayerRaceCheckPoint(playerid);
                        DestroyVehicle(PlayerInfo[playerid][E_CHARACTER_JOBSVEHICLE]);
                    }
                }
            }
        }
    }
    Update3DTextLabelText(PlayerInfo[playerid][E_CHARACTER_LOADINGDISPLAY], COLOR_DARKGREEN, text); 
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
            Dialog_Show(playerid, DIALOG_NONE, DIALOG_STYLE_LIST, "View Route:", str, "Close", "");
        }
    }
    return 1;
}