InsertModshops()
{
    CreateDynamic3DTextLabel("[ModShops]\n{ffffff}Available Commands: '/mods'", COLOR_3DTEXT, 2331.8369,-1991.6169,13.5745, 5.0);
    CreateDynamicPickup(1239, 1, 2331.8369,-1991.6169,13.5745, -1, -1, -1, 5.0);
    CreateDynamic3DTextLabel("[ModShops]\n{ffffff}Available Commands: '/mods'", COLOR_3DTEXT, 1619.4454,-1889.9126,13.5482, 5.0);
    CreateDynamicPickup(1239, 1, 1619.4454,-1889.9126,13.5482, -1, -1, -1, 5.0);
    CreateDynamic3DTextLabel("[ModShops]\n{ffffff}Available Commands: '/mods'", COLOR_3DTEXT, 1828.9535,-1398.1777,13.4297, 5.0);
    CreateDynamicPickup(1239, 1, 1828.9535,-1398.1777,13.4297, -1, -1, -1, 5.0);
}

CMD:mods(playerid, params[])
{
    if(!IsPlayerInRangeOfPoint(playerid, 2.0,2331.8369,-1991.6169,13.5745) && !IsPlayerInRangeOfPoint(playerid, 2.0,1619.4454,-1889.9126,13.5482) && !IsPlayerInRangeOfPoint(playerid, 2.0,1828.9535,-1398.1777,13.4297))
        return SendErrorMessage(playerid, "You aren't near modshop.");

    if(IsPlayerInVehicle(playerid, GetPlayerVehicleID(playerid)))
    {
        Dialog_Show(playerid, ModShops, DIALOG_STYLE_TABLIST, "Pay n Spray:", "Add Modifications", "Select", "Close");
    }
    return 1;
}

Dialog:ModShops(playerid, response, listitem, inputtext[])
{
	switch(listitem)
	{
		case 0: 
		{
			if (!response) {
				return TogglePlayerControllable(playerid, true);
			}

			if (!IsPlayerInAnyVehicle(playerid)) {
				return SendErrorMessage(playerid, "You aren't in any vehicle.");
			}

			new modname[50][32], v = GetPlayerVehicleID(playerid), mods[50], count = 0;
			new modlist[1024]; 

			for(new m = 1000; m < 1193; m++)
			{
				if(IsVehicleUpgradeCompatible(VehicleInfo[v][E_VEHICLE_MODEL], m) && IsActualVehicleMod(m))
				{
					mods[count] = m;
					format(modname[count], 32, "%s", GetVehicleModName(m));
					
					if(count == 0)
						format(modlist, sizeof(modlist), "%s%d\t%s~g~$%s\n", modlist, m, modname[count], FormatMoney(floatround(GetVehicleComponentPrice(m) * 100, floatround_round)));
					else
						format(modlist, sizeof(modlist), "%s%d\t%s~g~$%s\n", modlist, m, modname[count], FormatMoney(floatround(GetVehicleComponentPrice(m) * 100, floatround_round)));
					
					SubVehicleComponentArr[playerid][count] = m; 
					count++;
				}
			}

			if(count == 0) return SendErrorMessage(playerid, "This vehicle does not support any bodywork modifications.");
			
			Dialog_Show(playerid, PaynSpray, DIALOG_STYLE_PREVIEW_MODEL, "ModShop:", modlist, "Select", "Close");

			TogglePlayerControllable(playerid, true); 
			PlayerInfo[playerid][E_CHARACTER_TOGMENU] = false; 
		}
	}
	return 1;
}

Dialog:PaynSpray(playerid, response, listitem, inputtext[])
{
	if(response)
	{
		new vehicleid = GetPlayerVehicleID(playerid), 
			str[512],
			modelid = SubVehicleComponentArr[playerid][listitem];
		
		format(str, sizeof(str), "Hope you like new mods!!");
		ShowBoxMessage(playerid, str, 5);
		VehicleInfo[vehicleid][E_VEHICLE_MODS][GetVehicleComponentType(modelid)] = modelid;
		SaveVehicle(vehicleid);
		AddVehicleComponent(vehicleid, modelid);
		new Cents = floatround(GetVehicleComponentPrice(modelid) * 100, floatround_round);

		GiveMoney(playerid, -Cents);
		PauseAC(playerid);
		PlayerPlaySound(playerid, 1133, 0.0, 0.0, 0.0);
	}
	return 1;
}