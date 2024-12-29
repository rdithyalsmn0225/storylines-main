
// FUNCTION PLAYER:
function:PlayerGYMTimers(playerid, type)
{
    new businessid = IsPlayerInBusiness(playerid);
    PlayerPointGym[playerid] -= 1.0;
    SetPlayerGameBar(playerid, PlayerPointGym[playerid]);

    if(type == 1)
    {
        if(PlayerPointGym[playerid] < 0)
        {
            PlayerPointGym[playerid] = 0;  
            ApplyAnimation(playerid, "gymnasium", "gym_tread_falloff", 4.1, 0, 0, 0, 0, 0, 1 );  
            KillTimer(PlayerTimerGym[playerid]);
            KillTimer(PlayerTimerUsingGym[playerid]);
            PlayerGymMachine[playerid] = -1;
            PlayerUsingGym[playerid] = false;
            DestroyGameBar(playerid);
            ClearAnimations(playerid, 1);
            SetCameraBehindPlayer(playerid);
            PlayerPlaySound(playerid, 0, 0.0, 0.0, 0.0);
            TogglePlayerControllable(playerid, true);
            BusinessInfo[businessid][E_BUSINESS_TREADMILL] = false;
            RemovePlayerAttachedObject(playerid, ATTACH_HAND);
            RemovePlayerAttachedObject(playerid, ATTACH_HAND2);
            PlayerPlaySound(playerid, 0, 0.0, 0.0, 0.0);
        }
    }
    else
    {
        if(PlayerPointGym[playerid] < 0)
        {
            if(PlayerGymMachine[playerid] == GYM_DUMBELLS)
            {
                ApplyAnimation(playerid, "freeweights", "gym_free_putdown", 4.1, 0, 0, 0, 0, 0, 1 );  
                BusinessInfo[businessid][E_BUSINESS_DUMBELL] = false;
            }
            else if(PlayerGymMachine[playerid] == GYM_BENCH)
            {
                ApplyAnimation(playerid, "benchpress", "gym_bp_getoff", 4.1, 0, 0, 0, 0, 0, 1 );  
                BusinessInfo[businessid][E_BUSINESS_BENCH] = false;
            }
            else if(PlayerGymMachine[playerid] == GYM_BICYLE)
            {
                ApplyAnimation(playerid, "gymnasium", "gym_bike_getoff", 4.1, 0, 0, 0, 0, 0, 1 ); 
                BusinessInfo[businessid][E_BUSINESS_BYCICLE] = false; 
            }
            PlayerPointGym[playerid] = 0;  
            KillTimer(PlayerTimerGym[playerid]);
            KillTimer(PlayerTimerUsingGym[playerid]);
            PlayerGymMachine[playerid] = -1;
            PlayerUsingGym[playerid] = false;
            SetCameraBehindPlayer(playerid);
            DestroyGameBar(playerid);
            ClearAnimations(playerid, 1);
            PlayerPlaySound(playerid, 0, 0.0, 0.0, 0.0);
            TogglePlayerControllable(playerid, true);
            RemovePlayerAttachedObject(playerid, ATTACH_HAND);
            RemovePlayerAttachedObject(playerid, ATTACH_HAND2);
            PlayerPlaySound(playerid, 0, 0.0, 0.0, 0.0);
        }
    }
    return 1;
}

stock IsPlayerUsingMachine(playerid, type)
{
    switch(type)
    {
        case GYM_DUMBELLS: //Dumbells
        {
            ApplyAnimation(playerid, "freeweights", "gym_free_down", 4.1, 0, 0, 0, 1, 0, 1 );

            SetPlayerAttachedObject(playerid, ATTACH_HAND, -2505, 6);
			SetPlayerAttachedObject(playerid, ATTACH_HAND2, -2506, 5);

            PlayerGymMachine[playerid] = GYM_DUMBELLS;
            PlayerPointGym[playerid] = 10.0;
        }
        case GYM_TREADMILLS: //Treadmills
        {
            ApplyAnimation(playerid, "gymnasium", "gym_tread_jog", 4.1, 1, 0, 0, 1, 1, 1);
			PlayerPlaySound(playerid, 17800, 0, 0, 0);

            PlayerGymMachine[playerid] = GYM_TREADMILLS;
            PlayerPointGym[playerid] = 10.0;
        }
        case GYM_BICYLE: //Bicycle
        {
            ApplyAnimation(playerid, "gymnasium", "gym_bike_still", 4.1, 1, 0, 0, 1, 1, 1);	

            PlayerGymMachine[playerid] = GYM_BICYLE;
            PlayerPointGym[playerid] = 10.0;
        }
        case GYM_BENCH: //Bench
        {
            ApplyAnimation(playerid, "benchpress", "gym_bp_down", 4.1, 0, 0, 0, 1, 0, 1);
            SetPlayerAttachedObject(playerid, ATTACH_HAND, -2504, 6, 0.0, 0.0, -0.1);
            
            PlayerGymMachine[playerid] = GYM_BENCH;
            PlayerPointGym[playerid] = 10.0;
        }
    }
    return 1;
}

stock IsPlayerPlayingMachine(playerid)
{
    if(PlayerGymMachine[playerid] == GYM_DUMBELLS)
    {
        PlayerPointGym[playerid] += 5.0;  

        if(PlayerPointGym[playerid] >= 100)
        {
            switch(random(2)) 
            {
				case 0: 
                {
					ApplyAnimation(playerid, "freeweights", "gym_free_a", 4.1, 0, 0, 0, 1, 0, 1);
				}
				case 1: 
                {
					ApplyAnimation(playerid, "freeweights", "gym_free_b", 4.1, 0, 0, 0, 1, 0, 1);
				}
			}
            PlayerPointGym[playerid] = 10.0;
            SetPlayerNeeds(playerid, -0.1);
        }
        else if(PlayerPointGym[playerid] == 10.0)
        {
            ApplyAnimation(playerid, "freeweights", "gym_free_putdown", 4.1, 0, 0, 0, 1, 0, 1);
        }
    }
    else if(PlayerGymMachine[playerid] == GYM_TREADMILLS)
    {
        PlayerPointGym[playerid] += 2.0;   

        if(PlayerPointGym[playerid] >= 100.0)
        {
			ApplyAnimation(playerid, "gymnasium", "gym_tread_sprint", 4.1, 1, 0, 0, 1, 1, 1);	
            PlayerPointGym[playerid] = 100.0;
            SetPlayerNeeds(playerid, -0.1);
        }
        else if(PlayerPointGym[playerid] >= 30.0)
        {
            ApplyAnimation(playerid, "gymnasium", "gym_tread_jog", 4.1, 1, 0, 0, 1, 1, 1);	
        }
        else if(PlayerPointGym[playerid] >= 0)
        {
            ApplyAnimation(playerid, "gymnasium", "gym_tread_alt", 4.1, 1, 0, 0, 1, 1, 1);	
        }
        
    }
    else if(PlayerGymMachine[playerid] == GYM_BICYLE)
    {
        PlayerPointGym[playerid] += 2.0;  

        if(PlayerPointGym[playerid] >= 100.0)
        {
			PlayerPlaySound(playerid, 17801, 0, 0, 0);
			ApplyAnimation(playerid, "gymnasium", "gym_bike_faster", 4.1, 1, 0, 0, 1, 1, 1);	
            PlayerPointGym[playerid] = 100.0;
            SetPlayerNeeds(playerid, -0.1);
        }
        else if(PlayerPointGym[playerid] >= 0)
        {
            ApplyAnimation(playerid, "gymnasium", "gym_bike_slow", 4.1, 1, 0, 0, 1, 1, 1);	
            PlayerPlaySound(playerid, 17801, 0, 0, 0);
        }
        
    }
    else if(PlayerGymMachine[playerid] == GYM_BENCH)
    {
        PlayerPointGym[playerid] += 5.0;  

        if(PlayerPointGym[playerid] >= 100.0)
        {
            switch(random(2)) 
            {
				case 0: 
                {
					ApplyAnimation(playerid, "benchpress", "gym_bp_up_A", 4.1, 0, 0, 0, 1, 0, 1 );
				}
				case 1: 
                {
					ApplyAnimation(playerid, "benchpress", "gym_bp_up_B", 4.1, 0, 0, 0, 1, 0, 1 );
				}
			}
            SetPlayerNeeds(playerid, -0.1);
            PlayerPlaySound(playerid, 17807, 0, 0, 0);
            PlayerPointGym[playerid] = 10.0;
        }
        else if(PlayerPointGym[playerid] == 10.0)
        {
            ApplyAnimation(playerid, "benchpress", "gym_bp_down", 4.1, 0, 0, 0, 1, 0, 1);
        }
    }
    
    SetPlayerGameBar(playerid, PlayerPointGym[playerid]);
    return 1;
}

function:IsPlayerUsingGymTimers(playerid)
{
    if(PlayerGymMachine[playerid] == GYM_DUMBELLS)
    {
        if(PlayerPointGym[playerid] == 5.0)
        {
            ApplyAnimation(playerid, "freeweights", "gym_free_down", 4.1, 0, 0, 0, 1, 0, 1);
        }
        else if(PlayerPointGym[playerid] >= 100)
        {
            switch(random(2)) 
            {
				case 0: 
                {
					ApplyAnimation(playerid, "freeweights", "gym_free_a", 4.1, 0, 0, 0, 1, 0, 1);
				}
				case 1: 
                {
					ApplyAnimation(playerid, "freeweights", "gym_free_b", 4.1, 0, 0, 0, 1, 0, 1);
				}
			}
        }
        
    }
    else if(PlayerGymMachine[playerid] == GYM_TREADMILLS)
    {
        if(PlayerPointGym[playerid] >= 100.0)
        {
			ApplyAnimation(playerid, "gymnasium", "gym_tread_sprint", 4.1, 1, 0, 0, 1, 1, 1);	
        }
        else if(PlayerPointGym[playerid] >= 30.0)
        {
            ApplyAnimation(playerid, "gymnasium", "gym_tread_jog", 4.1, 1, 0, 0, 1, 1, 1);	
        }
        else if(PlayerPointGym[playerid] >= 0)
        {
            ApplyAnimation(playerid, "gymnasium", "gym_tread_alt", 4.1, 1, 0, 0, 1, 1, 1);	
        }
    }
    else if(PlayerGymMachine[playerid] == GYM_BICYLE)
    {
        if(PlayerPointGym[playerid] >= 100.0)
        {
			ApplyAnimation(playerid, "gymnasium", "gym_bike_faster", 4.1, 1, 0, 0, 1, 1, 1);	
        }
        else if(PlayerPointGym[playerid] >= 0)
        {
            ApplyAnimation(playerid, "gymnasium", "gym_bike_slow", 4.1, 1, 0, 0, 1, 1, 1);	
        }
    }
    else if(PlayerGymMachine[playerid] == GYM_BENCH)
    {
        if(PlayerPointGym[playerid] == 5.0)
        {
            ApplyAnimation(playerid, "benchpress", "gym_bp_getoff", 4.1, 0, 0, 0, 1, 0, 1);
        }
        else if(PlayerPointGym[playerid] >= 100.0)
        {
            switch(random(2)) 
            {
				case 0: 
                {
					ApplyAnimation(playerid, "benchpress", "gym_bp_up_A", 4.1, 0, 0, 0, 1, 0, 1 );
				}
				case 1: 
                {
					ApplyAnimation(playerid, "benchpress", "gym_bp_up_B", 4.1, 0, 0, 0, 1, 0, 1 );
				}
			}
        }
    }
    return 1;
}

stock IsPlayerExitMachine(playerid)
{
    new businessid = IsPlayerInBusiness(playerid);
    if(PlayerGymMachine[playerid] == GYM_DUMBELLS)
    {
        ApplyAnimation(playerid, "freeweights", "gym_free_putdown", 4.1, 0, 0, 0, 0, 0, 1 );
        KillTimer(PlayerTimerGym[playerid]);
        KillTimer(PlayerTimerUsingGym[playerid]);
        PlayerGymMachine[playerid] = -1;
        PlayerPointGym[playerid] = 0;  
        PlayerUsingGym[playerid] = false;
        DestroyGameBar(playerid);
        BusinessInfo[businessid][E_BUSINESS_DUMBELL] = false;
    }
    else if(PlayerGymMachine[playerid] == GYM_TREADMILLS)
    {
        ApplyAnimation(playerid, "gymnasium", "gym_tread_getoff", 4.1, 0, 0, 0, 0, 0, 1 );
        KillTimer(PlayerTimerGym[playerid]);
        KillTimer(PlayerTimerUsingGym[playerid]);
        PlayerGymMachine[playerid] = -1;
        PlayerPointGym[playerid] = 0;  
        PlayerUsingGym[playerid] = false;
        DestroyGameBar(playerid);
        BusinessInfo[businessid][E_BUSINESS_TREADMILL] = false;
    }
    else if(PlayerGymMachine[playerid] == GYM_BICYLE)
    {
        ApplyAnimation(playerid, "gymnasium", "gym_bike_getoff", 4.1, 0, 0, 0, 0, 0, 1);
        KillTimer(PlayerTimerGym[playerid]);
        KillTimer(PlayerTimerUsingGym[playerid]);
        PlayerGymMachine[playerid] = -1;
        PlayerPointGym[playerid] = 0;  
        PlayerUsingGym[playerid] = false;
        DestroyGameBar(playerid);
        BusinessInfo[businessid][E_BUSINESS_BYCICLE] = false;
    }
    else if(PlayerGymMachine[playerid] == GYM_BENCH)
    {
        ApplyAnimation(playerid, "benchpress", "gym_bp_getoff", 4.1, 0, 0, 0, 0, 0, 1 );
        KillTimer(PlayerTimerGym[playerid]);
        KillTimer(PlayerTimerUsingGym[playerid]);
        PlayerGymMachine[playerid] = -1;
        PlayerPointGym[playerid] = 0;  
        PlayerUsingGym[playerid] = false;
        DestroyGameBar(playerid);
        BusinessInfo[businessid][E_BUSINESS_BENCH] = false;
    }

    RemovePlayerAttachedObject(playerid, ATTACH_HAND);
    RemovePlayerAttachedObject(playerid, ATTACH_HAND2);
    ClearAnimations(playerid, 0);
    SetCameraBehindPlayer(playerid);
    PlayerPlaySound(playerid, 0, 0.0, 0.0, 0.0);
    TogglePlayerControllable(playerid, true);
    return 1;
}

// FUNCTION USING MACHINE:
stock IsPlayerUsingDumbell(playerid, businessid, area)
{
    switch(area)
    {
        case 1: //Business
        {
            if(BusinessInfo[businessid][E_BUSINESS_DUMBELL] == true)
                return SendErrorMessage(playerid, "This machine is already being used. Try again later");

            SetPlayerCameraPos(playerid, 775.8257, 5.3062, 1001.4611);
			SetPlayerCameraLookAt(playerid, 774.8271, 5.3044, 1001.0967);

			SetPlayerPos(playerid,  772.0784, 5.3704, 1000.3983);
			SetPlayerFacingAngle(playerid, 270);

            BusinessInfo[businessid][E_BUSINESS_DUMBELL] = true;
            ShowHeaderMessage(playerid, "GYM", "To lift the dumbbells, use ALT rapidly.");

            ApplyAnimation(playerid, "freeweights", "gym_free_down", 4.1, 0, 0, 0, 0, 0, 1);

            PlayerPointGym[playerid] = 0;
            ShowGameBar(playerid, PlayerPointGym[playerid], "Dumbbells");
        }
        case 2: //Verona Beach
        {
            SetPlayerCameraPos(playerid, 657.1807, -1869.5812, 5.5981);
			SetPlayerCameraLookAt(playerid, 656.1824, -1869.5773, 5.4134);

			SetPlayerPos(playerid, 653.0922,-1869.6189,5.5537);
			SetPlayerFacingAngle(playerid, 270);
            ShowHeaderMessage(playerid, "GYM", "To lift the dumbbells, use ALT rapidly.");

            ApplyAnimation(playerid, "freeweights", "gym_free_down", 4.1, 0, 0, 0, 0, 0, 1);

            PlayerPointGym[playerid] = 0;
            ShowGameBar(playerid, PlayerPointGym[playerid], "Dumbbells");
        }
    }

    PlayerUsingGym[playerid] = true;
    IsPlayerUsingMachine(playerid, GYM_DUMBELLS);
    TogglePlayerControllable(playerid, false);
    PlayerTimerGym[playerid] = SetTimerEx("PlayerGYMTimers", 1000, true, "ii", playerid, 0);
    PlayerTimerUsingGym[playerid] = SetTimerEx("IsPlayerUsingGymTimers", 1000, true, "i", playerid);
    
    return 1;
}

stock IsPlayerUsingTreadMill(playerid, businessid, area)
{

    switch(area)
    {
        case 1: //Business
        {
            if(BusinessInfo[businessid][E_BUSINESS_TREADMILL] == true)
                return SendErrorMessage(playerid, "This machine is already being used. Try again later");

            SetPlayerCameraPos(playerid, 774.5929, -4.9924, 1001.2608);
			SetPlayerCameraLookAt(playerid, 774.1505, -4.0972, 1001.0863);

			SetPlayerPos(playerid,  773.5308, -1.0291, 1000.6784);
			SetPlayerFacingAngle(playerid, 180);

            BusinessInfo[businessid][E_BUSINESS_TREADMILL] = true;
            ShowHeaderMessage(playerid, "GYM", "To begin running, use ALT rapidly. Do not allow your power bar to empty or you will fall off the treadmill.");

            ApplyAnimation(playerid, "gymnasium", "gym_tread_alt", 4.1, 0, 0, 0, 0, 0, 1);	

            PlayerPointGym[playerid] = 10.0;
            ShowGameBar(playerid, PlayerPointGym[playerid], "Treadmill");
        }
        case 2: //Verona Beach
        {
            SetPlayerCameraPos(playerid, 657.0516, -1871.5090, 5.3537);
			SetPlayerCameraLookAt(playerid, 657.9062, -1870.9904, 5.3740);

			SetPlayerPos(playerid,  661.3871, -1869.5911, 5.1775);
			SetPlayerFacingAngle(playerid, 90);
            ShowHeaderMessage(playerid, "GYM", "To begin running, use ALT rapidly. Do not allow your power bar to empty or you will fall off the treadmill.");

            ApplyAnimation(playerid, "gymnasium", "gym_tread_alt", 4.1, 0, 0, 0, 0, 0, 1);	

            PlayerPointGym[playerid] = 10.0;
            ShowGameBar(playerid, PlayerPointGym[playerid], "Treadmill");
        }
    }

    PlayerUsingGym[playerid] = true;
    IsPlayerUsingMachine(playerid, GYM_TREADMILLS);
    TogglePlayerControllable(playerid, false);
    PlayerTimerGym[playerid] = SetTimerEx("PlayerGYMTimers", 1000, true, "ii", playerid, 1);
    PlayerTimerUsingGym[playerid] = SetTimerEx("IsPlayerUsingGymTimers", 1000, true, "i", playerid);
    
    return 1;
}

stock IsPlayerUsingBycle(playerid, businessid, area)
{
    switch(area)
    {
        case 1: //Business
        {
            if(BusinessInfo[businessid][E_BUSINESS_BYCICLE] == true)
                return SendErrorMessage(playerid, "This machine is already being used. Try again later");

            SetPlayerCameraPos(playerid, 770.4507, 6.9657, 1000.5566);
			SetPlayerCameraLookAt(playerid, 770.9837, 7.8102, 1000.5074);

			SetPlayerPos(playerid,  772.7556,8.8882,1000.7065);
			SetPlayerFacingAngle(playerid, 90);

            BusinessInfo[businessid][E_BUSINESS_BYCICLE] = true;
            ShowHeaderMessage(playerid, "GYM", "Use ALT rapidly to begin pedalling the bicycle.");

            PlayerPointGym[playerid] = 10.0;
            ShowGameBar(playerid, PlayerPointGym[playerid], "Bicycle");
        }
        case 2: //Verona Beach
        {
            SetPlayerCameraPos(playerid, 660.9541, -1866.1726, 5.0874);
			SetPlayerCameraLookAt(playerid, 660.3044, -1865.4131, 5.0777);

			SetPlayerPos(playerid,  659.8035,-1863.9368,5.4609);
			SetPlayerFacingAngle(playerid, 180);
            ShowHeaderMessage(playerid, "GYM", "Use ALT rapidly to begin pedalling the bicycle.");
        
            PlayerPointGym[playerid] = 10.0;
            ShowGameBar(playerid, PlayerPointGym[playerid], "Bicycle");
        }
    }

    PlayerUsingGym[playerid] = true;
    IsPlayerUsingMachine(playerid, GYM_BICYLE);
    TogglePlayerControllable(playerid, false);
    PlayerTimerGym[playerid] = SetTimerEx("PlayerGYMTimers", 1000, true, "ii", playerid, 0);
    PlayerTimerUsingGym[playerid] = SetTimerEx("IsPlayerUsingGymTimers", 1000, true, "i", playerid);
    
    return 1;
}

stock IsPlayerUsingBench(playerid, businessid, area)
{
    switch(area)
    {
        case 1: //Business
        {
            if(BusinessInfo[businessid][E_BUSINESS_BENCH] == true)
                return SendErrorMessage(playerid, "This machine is already being used. Try again later");

            SetPlayerCameraPos(playerid, 771.5958, 1.5447, 1001.8984);
			SetPlayerCameraLookAt(playerid, 772.5945, 1.5482, 1001.2219);

			SetPlayerPos(playerid,  772.8870,1.4399,1000.7209);
			SetPlayerFacingAngle(playerid, 270);

            BusinessInfo[businessid][E_BUSINESS_BENCH] = true;
            ShowHeaderMessage(playerid, "GYM", "To lift the weight, use ALT rapidly.");

            ApplyAnimation(playerid, "benchpress", "gym_bp_down", 4.1, 0, 0, 0, 1, 0, 1 );

            PlayerPointGym[playerid] = 10.0;
            ShowGameBar(playerid, PlayerPointGym[playerid], "Benchpress");
        }
        case 2: //Verona Beach
        {
            SetPlayerCameraPos(playerid, 653.9464, -1866.5159, 5.6205);
			SetPlayerCameraLookAt(playerid, 653.9478, -1865.5164, 5.3958);

			SetPlayerPos(playerid, 653.9518,-1865.0546,5.4609);
			SetPlayerFacingAngle(playerid, 0);
            ShowHeaderMessage(playerid, "GYM", "To lift the weight, use ALT rapidly.");

            ApplyAnimation(playerid, "benchpress", "gym_bp_down", 4.1, 0, 0, 0, 1, 0, 1 );

            PlayerPointGym[playerid] = 10.0;
            ShowGameBar(playerid, PlayerPointGym[playerid], "Benchpress");
        }
    }

    PlayerUsingGym[playerid] = true;
    IsPlayerUsingMachine(playerid, GYM_BENCH);
    TogglePlayerControllable(playerid, false);
    PlayerTimerGym[playerid] = SetTimerEx("PlayerGYMTimers", 1000, true, "ii", playerid, 0);
    PlayerTimerUsingGym[playerid] = SetTimerEx("IsPlayerUsingGymTimers", 1000, true, "i", playerid);

    return 1;
}

//Commands:
CMD:gym(playerid, params[])
{
    if(PlayerUsingGym[playerid] == false)
    {
        new businessid = IsPlayerInBusiness(playerid);
        if(!IsPlayerInBusiness(playerid) && BusinessInfo[businessid][E_BUSINESS_TYPE != BUSINESS_TYPE_GYM])
            return SendErrorMessage(playerid, "You aren't in business.");
            
        if(PlayerInfo[playerid][E_CHARACTER_HUNGRY] < 20)
            return SendErrorMessage(playerid, "You're hungry or thirsty right now.");

        if(IsPlayerInRangeOfPoint(playerid, 2.0, 772.6528,5.4322,1000.7802)) 
        {
            IsPlayerUsingDumbell(playerid, IsPlayerInBusiness(playerid), 1);
        }
        else if(IsPlayerInRangeOfPoint(playerid, 2.0, 773.4765,-1.3899,1000.7261)) 
        {
            IsPlayerUsingTreadMill(playerid, IsPlayerInBusiness(playerid), 1);
        }
        else if(IsPlayerInRangeOfPoint(playerid, 2.0, 773.1308,8.9508,1000.7061)) 
        {
            IsPlayerUsingBycle(playerid, IsPlayerInBusiness(playerid), 1);
        }
        else if(IsPlayerInRangeOfPoint(playerid, 2.0, 773.1153,1.3875,1000.7209)) 
        {
            IsPlayerUsingBench(playerid, IsPlayerInBusiness(playerid), 1);
        }
    }
    else if(PlayerUsingGym[playerid] == true)
    {
        IsPlayerExitMachine(playerid);
    }
    return 1;
}