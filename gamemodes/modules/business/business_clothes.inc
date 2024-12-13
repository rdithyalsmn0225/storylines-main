function:EnterFittingRoom(playerid, skinid)
{
    ApplyAnimation(playerid, "CLOTHES", "CLO_In", 4.0, 0, 0, 0, 0, 0);
    MoveDynamicObject(fittingRoomDoor, 216.760360, -97.310455, 1005.337768, 0.01, 0.0, 0.0, 450.0); //buka
    SetTimerEx("SetPlayerSkinAndExit", 2000, false, "ii", playerid, skinid);
}

function:CloseFittingRoomDoor(playerid)
{
    ApplyAnimation(playerid, "CLOTHES", "CLO_Buy", 4.0, 0, 0, 0, 0, 0);
    SetCameraBehindPlayer(playerid);
    MoveDynamicObject(fittingRoomDoor, 216.760360, -97.310455, 1005.337768, 0.01, 0.0, 0.0, 360.0); //tutup
    SaveCharacter(playerid);
}

function:SetPlayerSkinAndExit(playerid, skinid)
{
    new businessid = IsPlayerInBusiness(playerid);
    SetPlayerPos(playerid, 217.6465,-96.5580,1005.2578);
    MoveDynamicObject(fittingRoomDoor, 216.760360, -97.310455, 1005.337768, 0.01, 0.0, 0.0, 360.0); //tutup
    ApplyAnimation(playerid, "CLOTHES", "CLO_Pose_In_O", 4.0, 0, 0, 0, 0, 0);
    
    SendPropertyMessage(playerid, "[Business] {cdcdcd}You bought clothes and wear it."); 
	SetPlayerSkin(playerid, skinid);
	PlayerInfo[playerid][E_CHARACTER_LASTSKIN] = skinid;

	BusinessInfo[businessid][E_BUSINESS_STOCK]--;
	GiveMoney(playerid, -BusinessInfo[businessid][E_BUSINESS_PRODUCTS][1]);
    BusinessInfo[businessid][E_BUSINESS_CASH]+= BusinessInfo[businessid][E_BUSINESS_PRODUCTS][1];
	SaveCharacter(playerid);
    
    SetTimerEx("ExitFittingRoom", 2500, false, "i", playerid);
    return 1;
}

function:ExitFittingRoom(playerid)
{
    SetPlayerPos(playerid, 217.5163,-98.4308,1005.2578);
	SetPlayerFacingAngle(playerid, 94.6310);
    ApplyAnimation(playerid, "CLOTHES", "CLO_Out", 4.0, 0, 0, 0, 0, 0);
    MoveDynamicObject(fittingRoomDoor, 216.760360, -97.310455, 1005.337768, 0.01, 0.0, 0.0, 450.0); //buka
    SetTimerEx("CloseFittingRoomDoor", 2000, false, "i", playerid);
}