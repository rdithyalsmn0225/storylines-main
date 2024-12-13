new gFires, gFireObjects[MAX_FIRES] = {INVALID_OBJECT_ID, ...}, Float:gFireHealth[MAX_FIRES];

IsFireActive()
{
	for(new i = 0; i < MAX_FIRES; i ++)
	{
	    if(IsValidDynamicObject(gFireObjects[i]))
	    {
	        return 1;
		}
	}

	return 0;
}

function:RandomFire(check)
{
	new count, index, announced, rand = random(10);

	if(!IsFireActive())
	{
	    if(check)
	    {
			foreach(new i : Player)
			{
			    if(ReturnFactionType(i) == FACTION_TYPE_MEDICAL)
		    	{
		        	count++;
	        	}
	    	}
	    }
	    else
	    {
	        count = 3;
	    }

	    if(count >= 3)
	    {
	        for(new i = 0; i < sizeof(randomFireSpawns); i ++)
	        {
	            if(randomFireSpawns[i][E_FIRE_INDEX] == rand)
	            {
	                if(!announced)
	                {
	                    foreach(new x : Player)
	                    {
	                        if(IsPlayerInRangeOfPoint(x, 30.0, randomFireSpawns[i][E_FIRE_POSX], randomFireSpawns[i][E_FIRE_POSY], randomFireSpawns[i][E_FIRE_POSZ]))
	                        {
	                            SendServerMessage(x, "[Fire] {cdcdcd}An explosion can be heard. Smoke is rising from a building nearby.");
	                        }
	                        if(ReturnFactionType(x) == FACTION_TYPE_MEDICAL)
	                        {
	                            GPS_SetPlayerRaceCheckPoint(x, 1, randomFireSpawns[i][E_FIRE_POSX], randomFireSpawns[i][E_FIRE_POSY], randomFireSpawns[i][E_FIRE_POSZ], 0.0, 0.0, 0.0);
	                            SendServerMessage(x, "[Fire] {cdcdcd}All units, a fire has been reported in %s. Please head to the beacon on your map.", GetZoneName(randomFireSpawns[i][E_FIRE_POSX], randomFireSpawns[i][E_FIRE_POSY], randomFireSpawns[i][E_FIRE_POSZ]));
							}
	                    }

						announced = 1;
					}

	                gFireObjects[index] = CreateDynamicObject(18691, randomFireSpawns[i][E_FIRE_POSX], randomFireSpawns[i][E_FIRE_POSY], randomFireSpawns[i][E_FIRE_POSZ], 0.0, 0.0, randomFireSpawns[i][E_FIRE_POSA], .streamdistance = 50.0);
	                gFireHealth[index++] = 50.0;
	            }
	        }

	        gFires = index;
	    }
	}
}

function:DestroyWater(objectid)
{
	DestroyDynamicObject(objectid);
	return 1;
}

CMD:randomfire(playerid, params[])
{
    if(IsPlayerAdmins(playerid) < ADMINS_OPERATOR)
	    return 0;

	if(IsFireActive())
	    return SendErrorMessage(playerid, "There is a fire active already. /destroyfire to kill it!");

	new
	    Float:x,
	    Float:y,
	    Float:z;

	RandomFire(0);

	GetDynamicObjectPos(gFireObjects[0], x, y, z);
	
	new str[128];
	format(str, sizeof(str), "%s has started a random fire in %s.", ReturnName(playerid), GetZoneName(x, y, z));
	SendAdminMessage(4, str);
	return 1;
}

CMD:destroyfire(playerid, params[])
{
    if(IsPlayerAdmins(playerid) < ADMINS_OPERATOR)
	    return 0;

	if(!IsFireActive())
	    return SendErrorMessage(playerid, "There is currently no fire active.");

	for(new i = 0; i < MAX_FIRES; i ++)
	{
	    DestroyDynamicObject(gFireObjects[i]);
	    gFireObjects[i] = INVALID_OBJECT_ID;
	    gFireHealth[i] = 0.0;
	}

	gFires = 0;
	SendServerMessage(playerid, "[Fire] {cdcdcd}You has destroyed fire.");
	return 1;
}