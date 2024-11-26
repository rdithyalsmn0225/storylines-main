VehicleObjectUpdates(vehicleid)
{
    switch(GetVehicleModel(vehicleid))
    {
        case 422:
        {
            if(VS_Count(vehicleid, "Woods"))
            {
                VehicleInfo[vehicleid][E_VEHICLE_OBJECTS][0] = CreateDynamicObject(1463,0.0,0.0,-1000.0,0.0,0.0,0.0,-1,-1,-1,300.0,300.0);
                AttachDynamicObjectToVehicle(VehicleInfo[vehicleid][E_VEHICLE_OBJECTS][0], vehicleid, 0.000, -1.280, 0.270, 0.000, 0.000, 89.400);
            }
            else
            {
                DestroyDynamicObject(VehicleInfo[vehicleid][E_VEHICLE_OBJECTS][0]);
            }
        }
        case 543:
        {
            if(VS_Count(vehicleid, "Woods"))
            {
                VehicleInfo[vehicleid][E_VEHICLE_OBJECTS][0] = CreateDynamicObject(1463,0.0,0.0,-1000.0,0.0,0.0,0.0,-1,-1,-1,300.0,300.0);
                AttachDynamicObjectToVehicle(VehicleInfo[vehicleid][E_VEHICLE_OBJECTS][0], vehicleid, 0.000, -1.531, 0.440, 0.000, 0.000, 90.000);
            }
            else
            {
                DestroyDynamicObject(VehicleInfo[vehicleid][E_VEHICLE_OBJECTS][0]);
            }
        }
        case 478:
        {
            if(VS_Count(vehicleid, "Woods"))
            {
                VehicleInfo[vehicleid][E_VEHICLE_OBJECTS][0] = CreateDynamicObject(1463,0.0,0.0,-1000.0,0.0,0.0,0.0,-1,-1,-1,300.0,300.0);
                AttachDynamicObjectToVehicle(VehicleInfo[vehicleid][E_VEHICLE_OBJECTS][0], vehicleid, 0.000, -1.731, 0.300, 0.000, 0.000, 0.000);
            }
            else
            {
                DestroyDynamicObject(VehicleInfo[vehicleid][E_VEHICLE_OBJECTS][0]);
            }
        }
        case 554:
        {
            if(VS_Count(vehicleid, "Woods"))
            {
                VehicleInfo[vehicleid][E_VEHICLE_OBJECTS][0] = CreateDynamicObject(1463,0.0,0.0,-1000.0,0.0,0.0,0.0,-1,-1,-1,300.0,300.0);
                AttachDynamicObjectToVehicle(VehicleInfo[vehicleid][E_VEHICLE_OBJECTS][0], vehicleid, 0.000, -1.651, 0.290, 0.000, 0.000, -89.399);
            }
            else
            {
                DestroyDynamicObject(VehicleInfo[vehicleid][E_VEHICLE_OBJECTS][0]);
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
                SendServerMessage(playerid, "[Lumberjack] {a4a4a4}You've successfully cutting down the Tree.");
                SendTipMessage(playerid, "Press 'ALT' to create the wood timber.");
                TreeInfo[id][E_TREE_CUTTED] = true;

                MoveDynamicObject(TreeInfo[id][E_TREE_OBJECT], TreeInfo[id][E_TREE_POS][0], TreeInfo[id][E_TREE_POS][1], TreeInfo[id][E_TREE_POS][2], 4.0,  TreeInfo[id][E_TREE_POS][3] + 90.0,  TreeInfo[id][E_TREE_POS][4],  TreeInfo[id][E_TREE_POS][5]);
            }
            else
            {
                TreeInfo[id][E_TREE_PROGRESS] += rand;
                SendServerMessage(playerid, "[Lumberjack] {a4a4a4}The tree cutting progress now is %d percent", TreeInfo[id][E_TREE_PROGRESS]);
                SendTipMessage(playerid, "Keep cut the tree until the progress is 100 percent");
            }
        }
    }
    Update3DTextLabelText(PlayerInfo[playerid][E_CHARACTER_LOADINGDISPLAY], COLOR_3DTEXT, text); 
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

            SendServerMessage(playerid, "[Lumberjack] {a4a4a4}You've successfully take woods timber.");
            SendTipMessage(playerid, "Place the timber into your pickup vehicle.");

            TreeInfo[id][E_TREE_TIMER] = 10;
            TreeInfo[id][E_TREE_CUTTED] = false;
            TreeInfo[id][E_TREE_PROGRESS] = 0;

            if(IsValidDynamicObject(TreeInfo[id][E_TREE_OBJECT]))
                DestroyDynamicObject(TreeInfo[id][E_TREE_OBJECT]);
        }
    }
    Update3DTextLabelText(PlayerInfo[playerid][E_CHARACTER_LOADINGDISPLAY], COLOR_3DTEXT, text); 
	return 1;
}

CMD:timbercut(playerid, params[])
{
    if(IsPlayerNearestTree(playerid) != -1)
    {
        new Float:x, Float:y, Float:z;
        GetPlayerPos(playerid, x, y, z);

        new id;
        id = IsPlayerNearestTree(playerid);

        if(PlayerInfo[playerid][E_CHARACTER_JOBS] != JOB_LUMBERJACK)
            return SendErrorMessage(playerid, "You aren't lumberjack.");

        if(!Inventory_Count(playerid, "Chainsaw"))
            return SendErrorMessage(playerid, "You don't have any axe in inventory.");

        if(PlayerInfo[playerid][E_CHARACTER_EQUIPITEMS] != CHAINSAW)
            return SendErrorMessage(playerid, "You must hold the axe in your hands.");

        if(TreeInfo[id][E_TREE_TIMER] > 0)
            return SendErrorMessage(playerid, "This tree still unavailable.");

        if(TreeInfo[id][E_TREE_CUT])
            return SendErrorMessage(playerid, "Unable to execute this tree! (being interacted with another player)");

        if(PlayerInfo[playerid][E_CHARACTER_LOADING] == true)
            return SendErrorMessage(playerid, "You can't use this right now."); 

        if(!TreeInfo[id][E_TREE_CUTTED])
        {
            if(TreeInfo[id][E_TREE_PROGRESS] < 100)
            {
                PlayerInfo[playerid][E_CHARACTER_LOADING] = true;
                PlayerInfo[playerid][E_CHARACTER_LOADINGCOUNT] = 1;
                PlayerInfo[playerid][E_CHARACTER_LOADINGDISPLAY] = Create3DTextLabel("Loading cutting trees process\n(( |------ ))", COLOR_3DTEXT, x, y, z, 25.0, 0, 1);
                PlayerInfo[playerid][E_CHARACTER_LOADINGTIMER] = SetTimerEx("CutTree", 500, true, "dd", playerid, id);
                TogglePlayerControllable(playerid, false);
                ApplyAnimation(playerid,"BASEBALL", "Bat_M", 4.1, 1, 0, 0, 1, 0, 1);
                TreeInfo[id][E_TREE_CUT] = true;
            }
        }
        else
        {
            if(Inventory_Count(playerid, "Woods"))
                return SendErrorMessage(playerid, "You already carrying woods");

            PlayerInfo[playerid][E_CHARACTER_LOADING] = true;
            PlayerInfo[playerid][E_CHARACTER_LOADINGCOUNT] = 1;
            PlayerInfo[playerid][E_CHARACTER_LOADINGDISPLAY] = Create3DTextLabel("Loading take timber process\n(( |------ ))", COLOR_3DTEXT, x, y, z, 25.0, 0, 1);
            PlayerInfo[playerid][E_CHARACTER_LOADINGTIMER] = SetTimerEx("CreateTimber", 1000, true, "dd", playerid, id);
            TogglePlayerControllable(playerid, false);
            TreeInfo[id][E_TREE_CUT] = true;
            ApplyAnimation(playerid,"BOMBER","BOM_Plant_Loop", 4.1, 1, 0, 0, 1, 0, 1);
        }
    }
    return 1;
}
CMD:timbersell(playerid, params[])
{
	if(PlayerInfo[playerid][E_CHARACTER_JOBS] != JOB_LUMBERJACK)
        return SendErrorMessage(playerid, "You aren't lumberjack.");

	else if(IsPlayerInRangeOfPoint(playerid, 3.0, IndustryInfo[2][Posx], IndustryInfo[2][Posy], IndustryInfo[2][Posz])) //timbersell
	{
		if(!Inventory_Count(playerid, "Woods"))
			return SendErrorMessage(playerid, "You are not carrying your woods.");

		if(!ServerInfo[0][E_SERVER_WOODS] >= 100)
			return SendErrorMessage(playerid, "This cargo storage is full of stock.");

		Inventory_Remove(playerid, "Woods", 1);
		SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
		RemovePlayerAttachedObject(playerid, ATTACH_CARGO);
        new Cents = floatround(LUMBERJACK_SALARY*2 * 100, floatround_round);

		GiveMoney(playerid, Cents);

		ServerData_Plus(INDUSTRY_WOODS, 1);
		
		SendServerMessage(playerid, "[Lumberjack] {a4a4a4}You has sell woods for $%s into leafy hollow barn.", FormatMoney(Cents));
	}
	return 1;
}

CMD:buysaw(playerid, params[])
{
    if(!IsPlayerInRangeOfPoint(playerid, 3.0, -1448.7738,-1530.5585,101.7578))
        return SendErrorMessage(playerid, "You aren't near leafy hollow barn.");

    if(PlayerInfo[playerid][E_CHARACTER_JOBS] != JOB_LUMBERJACK)
        return SendErrorMessage(playerid, "You aren't lumberjack.");

    if(Inventory_Count(playerid, "Chainsaw"))
        return SendErrorMessage(playerid, "You already own a axe.");

    if(8000 > PlayerInfo[playerid][E_CHARACTER_MONEY])
        return SendErrorMessage(playerid, "You can't afford axe.");

    Inventory_Add(playerid, "Chainsaw", 341, 1);
    new Cents = floatround(80 * 100, floatround_round);

	GiveMoney(playerid, -Cents);
    SendServerMessage(playerid, "[Lumberjack] {a4a4a4}You bought a axe for {93C47D}$80.00{a4a4a4}.");
    SendTipMessage(playerid, "To start cutting the tree(s) /timbercut using axe.");
    return 1;
}