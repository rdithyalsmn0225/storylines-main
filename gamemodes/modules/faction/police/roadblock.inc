// SPIKE:
CMD:spike(playerid, params[])
{
	if (ReturnFactionType(playerid) != FACTION_TYPE_POLICE)
	    return SendErrorMessage(playerid, "You are not a police officer.");

	if (isnull(params))
 	{
	 	SendUsageMessage(playerid, "/spike [option]");
	    SendTipMessage(playerid, "drop, destroy, destroyall");
		return 1;
	}

	new
        Float:fX,
        Float:fY,
        Float:fZ,
        Float:fA;

    GetPlayerPos(playerid, fX, fY, fZ);
    GetPlayerFacingAngle(playerid, fA);

	if (!strcmp(params, "drop", true))
	{
	    if (IsPlayerInAnyVehicle(playerid))
	        return SendErrorMessage(playerid, "You must exit the vehicle first.");

	    for (new i = 0; i != MAX_BARRICADES; i ++) if (!BarricadeInfo[i][E_CADE_EXISTS])
	    {
            BarricadeInfo[i][E_CADE_EXISTS] = true;
            BarricadeInfo[i][E_CADE_TYPE] = 1;

            BarricadeInfo[i][E_CADE_POS][0] = fX;
            BarricadeInfo[i][E_CADE_POS][1] = fY;
            BarricadeInfo[i][E_CADE_POS][2] = fZ;

            BarricadeInfo[i][E_CADE_OBJECTS] = CreateDynamicObject(2899, fX, fY, fZ - 0.8, 0.0, 0.0, fA + 90.0);

			SendNearbyMessage(playerid, 30.0, COLOR_EMOTE, "** %s has dropped a spikestrip.", ReturnName(playerid, 0));
			SendPoliceMessage(COLOR_COP, "** HQ: %s has dropped a spikestrip at %s.", ReturnName(playerid, 0), ReturnLocation(playerid));

			return 1;
		}
		SendErrorMessage(playerid, "You can't make anymore spikestrips.");
	}
	else if (!strcmp(params, "destroy", true))
	{
        for (new i = 0; i != MAX_BARRICADES; i ++) if (BarricadeInfo[i][E_CADE_EXISTS] && BarricadeInfo[i][E_CADE_TYPE] == 1 && IsPlayerInRangeOfPoint(playerid, 3.0, BarricadeInfo[i][E_CADE_POS][0], BarricadeInfo[i][E_CADE_POS][1], BarricadeInfo[i][E_CADE_POS][2]))
	    {
            BarricadeInfo[i][E_CADE_EXISTS] = 0;
            BarricadeInfo[i][E_CADE_TYPE] = 0;

            DestroyDynamicObject(BarricadeInfo[i][E_CADE_OBJECTS]);

            SendNearbyMessage(playerid, 30.0, COLOR_EMOTE, "** %s has picked up a spikestrip.", ReturnName(playerid, 0));
			SendPoliceMessage(COLOR_COP, "** HQ: %s has picked up a spikestrip at %s.", ReturnName(playerid, 0), ReturnLocation(playerid));
			return 1;
		}
		SendErrorMessage(playerid, "You are not in range of any spikestrip.");
	}
	else if (!strcmp(params, "destroyall", true))
	{
        for (new i = 0; i != MAX_BARRICADES; i ++) if (BarricadeInfo[i][E_CADE_EXISTS] && BarricadeInfo[i][E_CADE_TYPE] == 1)
	    {
            BarricadeInfo[i][E_CADE_EXISTS] = 0;
            BarricadeInfo[i][E_CADE_TYPE] = 0;

			DestroyDynamicObject(BarricadeInfo[i][E_CADE_OBJECTS]);
		}
		SendPoliceMessage(COLOR_COP, "** HQ: %s has destroyed all of the spikestrips.", ReturnName(playerid, 0));
	}
	return 1;
}

// ROADBLOCK:
CMD:roadblock(playerid, params[])
{
	if (ReturnFactionType(playerid) != FACTION_TYPE_POLICE)
	    return SendErrorMessage(playerid, "You can't use this command."); 

	if (isnull(params))
 	{
	 	SendUsageMessage(playerid, "/roadblock [option]");
	    SendTipMessage(playerid, "drop, destroy, destroyall");
		return 1;
	}

	new
        Float:fX,
        Float:fY,
        Float:fZ,
        Float:fA;

    GetPlayerPos(playerid, fX, fY, fZ);
    GetPlayerFacingAngle(playerid, fA);

	if (!strcmp(params, "drop", true))
	{
	    if (IsPlayerInAnyVehicle(playerid))
	        return SendErrorMessage(playerid, "You must exit the vehicle first.");

	    for (new i = 0; i != MAX_BARRICADES; i ++) if (!BarricadeInfo[i][E_CADE_EXISTS])
	    {
            BarricadeInfo[i][E_CADE_EXISTS] = true;
            BarricadeInfo[i][E_CADE_TYPE] = 2;

            BarricadeInfo[i][E_CADE_POS][0] = fX;
            BarricadeInfo[i][E_CADE_POS][1] = fY;
            BarricadeInfo[i][E_CADE_POS][2] = fZ;

            BarricadeInfo[i][E_CADE_OBJECTS] = CreateDynamicObject(981, fX, fY, fZ, 0.0, 0.0, fA);
            SetPlayerPos(playerid, fX + 2, fY + 2, fZ + 2);

			SendNearbyMessage(playerid, 30.0, COLOR_EMOTE, "** %s has dropped a roadblock.", ReturnName(playerid, 0));
			SendPoliceMessage(COLOR_COP, "** HQ: %s has dropped a roadblock at %s.", ReturnName(playerid, 0), ReturnLocation(playerid));

			return 1;
		}
		SendErrorMessage(playerid, "You can't make anymore roadblock.");
	}
	else if (!strcmp(params, "destroy", true))
	{
        for (new i = 0; i != MAX_BARRICADES; i ++) if (BarricadeInfo[i][E_CADE_EXISTS] && BarricadeInfo[i][E_CADE_TYPE] == 2 && IsPlayerInRangeOfPoint(playerid, 5.0, BarricadeInfo[i][E_CADE_POS][0], BarricadeInfo[i][E_CADE_POS][1], BarricadeInfo[i][E_CADE_POS][2]))
	    {
            BarricadeInfo[i][E_CADE_EXISTS] = 0;
            BarricadeInfo[i][E_CADE_TYPE] = 0;

            DestroyDynamicObject(BarricadeInfo[i][E_CADE_OBJECTS]);

            SendNearbyMessage(playerid, 30.0, COLOR_EMOTE, "** %s has picked up a roadblock.", ReturnName(playerid, 0));
			SendPoliceMessage(COLOR_COP, "** HQ: %s has picked up a roadblock at %s.", ReturnName(playerid, 0), ReturnLocation(playerid));
			return 1;
		}
		SendErrorMessage(playerid, "You aren't near of any roadblock.");
	}
	else if (!strcmp(params, "destroyall", true))
	{
        for (new i = 0; i != MAX_BARRICADES; i ++) if (BarricadeInfo[i][E_CADE_EXISTS] && BarricadeInfo[i][E_CADE_TYPE] == 2)
	    {
            BarricadeInfo[i][E_CADE_EXISTS] = 0;
            BarricadeInfo[i][E_CADE_TYPE] = 0;

			DestroyDynamicObject(BarricadeInfo[i][E_CADE_OBJECTS]);
		}
		SendPoliceMessage(COLOR_COP, "** HQ: %s has destroyed all of the roadblocks.", ReturnName(playerid, 0));
	}
	return 1;
}