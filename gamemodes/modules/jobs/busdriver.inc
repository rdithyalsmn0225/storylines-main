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
                    if(PlayerBusDriverIndex[playerid] == 19)
                    {
                        GPS_SetPlayerRaceCheckPoint(playerid, 1, 1564.8461, -1235.1824, 17.4044, 0.0, 0.0, 0.0, GPS_BUSDRIVER);
                    }
                    if(PlayerBusDriverIndex[playerid] == 20)
                    {
                        new total = (PlayerBusDriverIndex[playerid] * BUSDRIVER_SALARY * 2);

                        GiveMoney(playerid, total);

                        ShowBoxMessage(playerid, "~r~Bus Driver job ended.", 5); 
                        SendServerMessage(playerid, "[Bus Driver] {cdd0d1}Bus Route Complete, current passenger {d7d292}%d{cdd0d1} x passenger and earn {93C47D}$%s{cdd0d1}.", PlayerBusDriverIndex[playerid], FormatMoney(total));

                        PlayerInfo[playerid][E_CHARACTER_BUSDRIVER] = false;
                        PlayerBusDriverIndex[playerid] = 0;
                            
                        GPS_DisablePlayerRaceCheckPoint(playerid);
                        DestroyVehicle(PlayerInfo[playerid][E_CHARACTER_JOBSVEHICLE]);
                    }
                }
            }
        }
    }
    Update3DTextLabelText(PlayerInfo[playerid][E_CHARACTER_LOADINGDISPLAY], COLOR_DARKGREEN, text); 
}