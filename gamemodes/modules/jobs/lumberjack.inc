VehicleLumberUpdates(vehicleid)
{
    if(IsValidDynamicObject(VehicleInfo[vehicleid][E_VEHICLE_OBJECTS][0]))
        DestroyDynamicObject(VehicleInfo[vehicleid][E_VEHICLE_OBJECTS][0]);

    switch(GetVehicleModel(vehicleid))
    {
        case 422:
        {
            if(VS_Count(vehicleid, "Woods"))
            {
                VehicleInfo[vehicleid][E_VEHICLE_OBJECTS][0] = CreateDynamicObject(1463,0.0,0.0,-1000.0,0.0,0.0,0.0,-1,-1,-1,300.0,300.0);
                AttachDynamicObjectToVehicle(VehicleInfo[vehicleid][E_VEHICLE_OBJECTS][0], vehicleid, 0.000, -1.280, 0.270, 0.000, 0.000, 89.400);
            }
        }
        case 543:
        {
            if(VS_Count(vehicleid, "Woods"))
            {
                VehicleInfo[vehicleid][E_VEHICLE_OBJECTS][0] = CreateDynamicObject(1463,0.0,0.0,-1000.0,0.0,0.0,0.0,-1,-1,-1,300.0,300.0);
                AttachDynamicObjectToVehicle(VehicleInfo[vehicleid][E_VEHICLE_OBJECTS][0], vehicleid, 0.000, -1.531, 0.440, 0.000, 0.000, 90.000);
            }
        }
        case 478:
        {
            if(VS_Count(vehicleid, "Woods"))
            {
                VehicleInfo[vehicleid][E_VEHICLE_OBJECTS][0] = CreateDynamicObject(1463,0.0,0.0,-1000.0,0.0,0.0,0.0,-1,-1,-1,300.0,300.0);
                AttachDynamicObjectToVehicle(VehicleInfo[vehicleid][E_VEHICLE_OBJECTS][0], vehicleid, 0.000, -1.731, 0.300, 0.000, 0.000, 0.000);
            }
        }
        case 554:
        {
            if(VS_Count(vehicleid, "Woods"))
            {
                VehicleInfo[vehicleid][E_VEHICLE_OBJECTS][0] = CreateDynamicObject(1463,0.0,0.0,-1000.0,0.0,0.0,0.0,-1,-1,-1,300.0,300.0);
                AttachDynamicObjectToVehicle(VehicleInfo[vehicleid][E_VEHICLE_OBJECTS][0], vehicleid, 0.000, -1.651, 0.290, 0.000, 0.000, -89.399);
            }
        }
    }
    return 1;
}
function:CutTree(playerid, id)
{
    new text[256];

    PlayerInfo[playerid][E_CHARACTER_LOADINGCOUNT]++;

    switch(PlayerInfo[playerid][E_CHARACTER_LOADINGCOUNT])
    {
        case 2: text = "Loading cutting trees process\n(( ||----- ))";
        case 3: text = "Loading cutting trees process\n(( |||---- ))";
        case 4: text = "Loading cutting trees process\n(( ||||--- ))";
        case 5: text = "Loading cutting trees process\n(( |||||-- ))";
        case 6: text = "Loading cutting trees process\n(( ||||||- ))";
        case 7: text = "Loading cutting trees process\n(( ||||||| ))";
        case 8:
        {
            TreeInfo[id][E_TREE_CUT] = false;
            new rand = randomEx(5, 12);
            ClearAnimations(playerid, 1);
            TogglePlayerControllable(playerid, true);
                    
            PlayerInfo[playerid][E_CHARACTER_LOADING] = false;
            PlayerInfo[playerid][E_CHARACTER_LOADINGCOUNT] = 0;

            Delete3DTextLabel(PlayerInfo[playerid][E_CHARACTER_LOADINGDISPLAY]); 
            KillTimer(PlayerInfo[playerid][E_CHARACTER_LOADINGTIMER]);

            if(TreeInfo[id][E_TREE_PROGRESS] + rand >= 100)
            {
                TreeInfo[id][E_TREE_PROGRESS] = 0;
                SendClientMessage(playerid, COLOR_JOBS, "[Jobs]:{d7d7d7} You've successfully cutting down the Tree.");
                SendClientMessage(playerid, COLOR_JOBS, "[Jobs]:{d7d7d7} Press 'LMB' to create the wood timber.");
                TreeInfo[id][E_TREE_CUTTED] = true;

                MoveDynamicObject(TreeInfo[id][E_TREE_OBJECT], TreeInfo[id][E_TREE_POS][0], TreeInfo[id][E_TREE_POS][1], TreeInfo[id][E_TREE_POS][2], 4.0,  TreeInfo[id][E_TREE_POS][3] + 90.0,  TreeInfo[id][E_TREE_POS][4],  TreeInfo[id][E_TREE_POS][5]);
            }
            else
            {
                TreeInfo[id][E_TREE_PROGRESS] += rand;
                SendClientMessageEx(playerid, COLOR_JOBS, "[Jobs]:{d7d7d7} The tree cutting progress now is %d percent", TreeInfo[id][E_TREE_PROGRESS]);
                SendClientMessage(playerid, COLOR_JOBS, "[Jobs]:{d7d7d7} Keep cut the tree until the progress is 100 percent");
            }
        }
    }
    Update3DTextLabelText(PlayerInfo[playerid][E_CHARACTER_LOADINGDISPLAY], COLOR_DARKGREEN, text); 
	return 1;
}

function:CreateTimber(playerid, id)
{
    new text[256];

    PlayerInfo[playerid][E_CHARACTER_LOADINGCOUNT]++;

    switch(PlayerInfo[playerid][E_CHARACTER_LOADINGCOUNT])
    {
        case 2: text = "Loading take timber process\n(( ||----- ))";
        case 3: text = "Loading take timber process\n(( |||---- ))";
        case 4: text = "Loading take timber process\n(( ||||--- ))";
        case 5: text = "Loading take timber process\n(( |||||-- ))";
        case 6: text = "Loading take timber process\n(( ||||||- ))";
        case 7: text = "Loading take timber process\n(( ||||||| ))";
        case 8:
        {
            ClearAnimations(playerid, 1);
            TogglePlayerControllable(playerid, true);
                    
            PlayerInfo[playerid][E_CHARACTER_LOADING] = false;
            PlayerInfo[playerid][E_CHARACTER_LOADINGCOUNT] = 0;

            Delete3DTextLabel(PlayerInfo[playerid][E_CHARACTER_LOADINGDISPLAY]); 
            KillTimer(PlayerInfo[playerid][E_CHARACTER_LOADINGTIMER]);

            TreeInfo[id][E_TREE_CUT] = false;

            Inventory_Add(playerid, "Woods", 1463, 1);

            SendClientMessageEx(playerid, COLOR_JOBS, "[Jobs]:{d7d7d7} You've successfully take woods timber.");
            SendClientMessageEx(playerid, COLOR_JOBS, "[Jobs]:{d7d7d7} Place the timber into your pickup vehicle.");

            TreeInfo[id][E_TREE_TIMER] = 3600;
            TreeInfo[id][E_TREE_CUTTED] = false;
            TreeInfo[id][E_TREE_PROGRESS] = 0;

            if(IsValidDynamicObject(TreeInfo[id][E_TREE_OBJECT]))
                DestroyDynamicObject(TreeInfo[id][E_TREE_OBJECT]);
        }
    }
    Update3DTextLabelText(PlayerInfo[playerid][E_CHARACTER_LOADINGDISPLAY], COLOR_DARKGREEN, text); 
	return 1;
}

CMD:sellwood(playerid, params[])
{
	if(PlayerInfo[playerid][E_CHARACTER_JOBS] != JOB_LUMBERJACK)
        return SendErrorMessage(playerid, "You aren't lumberjack.");

	else if(IsPlayerInRangeOfPoint(playerid, 3.0, IndustryInfo[2][Posx], IndustryInfo[2][Posy], IndustryInfo[2][Posz])) //sellwood
	{
		if(!Inventory_Count(playerid, "Woods"))
			return SendErrorMessage(playerid, "You are not carrying your woods.");

		if(!ServerInfo[0][E_SERVER_WOODS] >= 100)
			return SendErrorMessage(playerid, "This cargo storage is full of stock.");

		Inventory_Remove(playerid, "Woods Cargo", 1);
		SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
		RemovePlayerAttachedObject(playerid, 7);
		GiveMoney(playerid, LUMBERJACK_SALARY*2);

		ServerData_Plus(INDUSTRY_WOODS, 1);
		
		SendClientMessageEx(playerid, COLOR_JOBS, "[Jobs]:{d7d7d7} You has sell woods cargo for %s into oceandocks ships.", FormatMoney(PRICE_WOODS*5));
	}
	return 1;
}