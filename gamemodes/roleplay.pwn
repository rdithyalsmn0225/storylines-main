
/*==================================================================================================
   ______                _   _   _____                           _         _____  _____   _____ 
  |  ____|              | \ | | |  __ \                         | |       |  __ \|  __ \ / ____|
  | |__ ___  __ _ _ __  |  \| | | |__) |___  ___ _ __   ___  ___| |_      | |__) | |__) | |  __ 
  |  __/ _ \/ _` | '__| | . ` | |  _  // _ \/ __| '_ \ / _ \/ __| __|     |  _  /|  ___/| | |_ |
  | | |  __/ (_| | |    | |\  | | | \ \  __/\__ \ |_) |  __/ (__| |_   _  | | \ \| |    | |__| |
  |_|  \___|\__,_|_|    |_| \_| |_|  \_\___||___/ .__/ \___|\___|\__| (_) |_|  \_\_|     \_____|
                                                | |                                             
                                                |_|  

  #Thanks to Radeetz for making this script.
  #Special thanks to GTA-Chronicles / SP-RP / SOLS for credits the Environment.
================================================================================================== */


#include <a_samp>
#include <a_mysql>
#include <a_http>
#include <streamer>
#include <progress2>
#include <easyDialog>
#include <PreviewModelDialog>
#include <strlib>
#include <foreach>
#include <zcmd>
#include <sscanf2>
#include <rSelection>
#include <map-zones>
#include <fader>
#include <Pawn.RakNet>
#include <realtime-clock>

//Database establisher:
new MySQL:ourConnection; 

#include "modules\config\macro.inc"
#include "modules\config\color.inc"
#include "modules\config\variable.inc"
#include "modules\config\vardialog.inc"

main ()  {}

//Modules Headers
#include "modules\visuals\enviroment.inc"
#include "modules\visuals\textdraws.inc"
#include "modules\visuals\gamebar.inc"
#include "modules\config\modelselections.inc"
#include "modules\config\types.inc"
#include "modules\config\messages.inc"
#include "modules\config\economy.inc"
#include "modules\config\dialogs.inc"
#include "modules\config\savemysql.inc"
#include "modules\config\return.inc"
#include "modules\config\player.inc"
#include "modules\config\weapon.inc"
#include "modules\config\anticheat.inc"
#include "modules\config\bunnyhop.inc"
#include "modules\config\toggle.inc"
#include "modules\config\timer.inc"
#include "modules\config\zones.inc"

#include "modules\serverlogs\serverlogs.inc"

#include "modules\tags\tablist.inc"

#include "modules\anims\anims.inc"

#include "modules\voicelines\voicelines.inc"

#include "modules\players\damages.inc"
#include "modules\players\phone.inc"
#include "modules\players\paycheck.inc"
#include "modules\players\report.inc"
#include "modules\players\antibunny.inc"
#include "modules\players\selection.inc"
#include "modules\players\prison.inc"
#include "modules\players\tutorial.inc"
#include "modules\players\times.inc"
#include "modules\players\stamina.inc"
#include "modules\players\gps.inc"
#include "modules\players\accessories.inc"
#include "modules\players\afk.inc"

//#include "modules\turfs\turfs.inc"

#include "modules\emmet\emmet.inc"

#include "modules\business\business.inc"
#include "modules\business\dmv.inc"
#include "modules\business\gym.inc"
#include "modules\business\buyskin.inc"
#include "modules\business\buyhair.inc"
#include "modules\business\extortion.inc"
#include "modules\business\robbery.inc"

#include "modules\properties\property.inc"
#include "modules\properties\property_storage.inc"
#include "modules\properties\property_furniture.inc"

#include "modules\entrance\entrance.inc"

#include "modules\vehicles\vehicles.inc"
#include "modules\vehicles\vehicles_timer.inc"
#include "modules\vehicles\vehicles_storage.inc"
#include "modules\vehicles\vehicles_dealership.inc"
#include "modules\vehicles\vehicles_commands.inc"
#include "modules\vehicles\vehicle_repair.inc"

#include "modules\faction\factions.inc"
#include "modules\faction\mdc.inc"

#include "modules\props\spraytags.inc"
#include "modules\props\bbq.inc"
#include "modules\props\advertise.inc"
#include "modules\props\props.inc"
#include "modules\props\tree.inc"

#include "modules\drugs\drugs.inc"
#include "modules\drugs\drugsdealing.inc"

#include "modules\inventory\inventory.inc"
#include "modules\inventory\dropitem.inc"

#include "modules\minigames\basketball.inc"

#include "modules\industry\industry.inc"

#include "modules\jobs\header.inc"
#include "modules\jobs\trucker.inc"
#include "modules\jobs\lumberjack.inc"
#include "modules\jobs\taxi.inc"
#include "modules\jobs\smuggler.inc"
#include "modules\jobs\fishing.inc"
#include "modules\jobs\trashmaster.inc"
#include "modules\jobs\dockworker.inc"

#include "modules\commands\globalooc.inc"
#include "modules\commands\cmd_admins.inc"
#include "modules\commands\cmd_player.inc"
#include "modules\commands\cmd_faction.inc"

//Start of functions:
public OnGameModeInit()
{
	new MySQLOpt:ourOptions = mysql_init_options();

	SetGameModeText(SCRIPT_REV); 

	mysql_set_option(ourOptions, AUTO_RECONNECT, true);
	mysql_set_option(ourOptions, POOL_SIZE, 16);

	ourConnection = mysql_connect(SQL_HOSTNAME, SQL_USERNAME, SQL_PASSWORD, SQL_DATABASE, ourOptions);
	
	if (ourConnection == MYSQL_INVALID_HANDLE || mysql_errno(ourConnection) != 0)
	{
		printf ("[DATABASE]: Connection failed to '%s'...", SQL_DATABASE);
		SendRconCommand("exit");
		return 1;
	}
	else printf ("[DATABASE]: Connection established to '%s'...", SQL_DATABASE);

	mysql_log(ERROR | WARNING);
	
	//Load Custommodels:
	LoadCustomModels();

	//Disabling singleplayer entities:
	ShowPlayerMarkers(PLAYER_MARKERS_MODE_OFF);
	SetNameTagDrawDistance(20.0);
	ShowNameTags(true);
	EnableStuntBonusForAll(0);
	ManualVehicleEngineAndLights();
	DisableInteriorEnterExits();
	
	//Insert:
	InsertObjects();
	InsertSideJobs();
	InsertASGHMaps();
	InsertEmmetInit();
	InsertJobsPoint();
	InsertAntiCheat();
	InsertEmmetMaps();
	InsertAdvertise();
	InsertDealership();
	InsertStaticArea();
	InsertAcidGunLabs();
	InsertDocksWorkers();
	InsertDonatorStars();
	Insert3DTextLabel();
	InsertSelectionMaps();
	InsertStaticVehicles();
	InsertProjectPropsData();

	//Timer:
	RealTime_SetInterval(10000, false);
	RealTime_Sync();
	SetClock(RealTime_GetHour(), RealTime_GetMinute());
	SetWorldTime(RealTime_GetHour()); 
	GetWeekDay();

	//Global timers:
	SetTimer("PlayersUpdates", 1000, true); 
	SetTimer("FunctionPaychecks", 60000, true);
	SetTimer("OnPlayerNearPickup", 5000, true);
	SetTimer("OnVehicleFuelUpdate", 30000, true);
	SetTimer("OnVehicleUpdate", 1000, true);
	SetTimer("MinutesTimes", 60000, true);
	SetTimer("WeaponUpdate", 1000, true);
	SetTimer("SprayTagsTimer", 60000, true);
	SetTimer("AntiCheatCheck", 500, true);
	SetTimer("IndustryTimer", 600000, true);
	SetTimer("TreeTimers", 1000, true);
	SetTimer("TaxiTimers", 1000, true);
	SetTimer("PacketTimers", 1800000, true);
	//SetTimer("GarbageTimers", 180000, true);
	GarbageTimers();

	//Loading systems:
	mysql_pquery(ourConnection, "SELECT * FROM factions ORDER BY dbid ASC", "Query_LoadFactions"); 
	mysql_pquery(ourConnection, "SELECT * FROM properties ORDER BY PropertyDBID", "Query_LoadProperties");
	mysql_pquery(ourConnection, "SELECT * FROM furniture", "Query_LoadFurniture", "i", 0);
	mysql_pquery(ourConnection, "SELECT * FROM businesses ORDER BY BusinessDBID ASC", "Query_LoadBusinesses"); 
	mysql_pquery(ourConnection, "SELECT * FROM entrance ORDER BY ID", "Query_LoadEntrance");
	mysql_pquery(ourConnection, "SELECT * FROM `court`", "Query_CourtLoad", "");
	mysql_pquery(ourConnection, "SELECT * FROM `tree`", "Query_LoadTree", ""); 
	mysql_pquery(ourConnection, "SELECT * FROM `dropped`", "Query_DroppedLoad", "");
	mysql_pquery(ourConnection, "SELECT * FROM `spray_tags`", "Query_SpraytagsLoad", "");
	mysql_pquery(ourConnection, "SELECT * FROM `server_data`", "Query_ServerDataLoad", "");

	SetWeather(1);

	Times = TextDrawCreate(68.000000, 426.000000, "");
	TextDrawFont(Times, 1);
	TextDrawLetterSize(Times, 0.199993, 1.050000);
	TextDrawTextSize(Times, 400.000000, 93.500000);
	TextDrawSetOutline(Times, 1);
	TextDrawSetShadow(Times, 0);
	TextDrawAlignment(Times, 2);
	TextDrawColor(Times, -1);
	TextDrawBackgroundColor(Times, 255);
	TextDrawBoxColor(Times, 50);
	TextDrawUseBox(Times, 0);
	TextDrawSetProportional(Times, 1);
	TextDrawSetSelectable(Times, 0);

	phonetimes = TextDrawCreate(472.000000, 378.000000, "10:00");
	TextDrawFont(phonetimes, 1);
	TextDrawLetterSize(phonetimes, 0.154164, 0.750000);
	TextDrawTextSize(phonetimes, 400.000000, 17.000000);
	TextDrawSetOutline(phonetimes, 1);
	TextDrawSetShadow(phonetimes, 0);
	TextDrawAlignment(phonetimes, 1);
	TextDrawColor(phonetimes, -1);
	TextDrawBackgroundColor(phonetimes, 255);
	TextDrawBoxColor(phonetimes, 50);
	TextDrawUseBox(phonetimes, 0);
	TextDrawSetProportional(phonetimes, 1);
	TextDrawSetSelectable(phonetimes, 0);
	return 1;
}

public OnGameModeExit()
{
	foreach (new i : Player)
	{
		SetPlayerName(i, AccountInfo[i][E_MASTERS_ACCNAME]);
		if(PlayerInfo[i][E_CHARACTER_TUTORIAL])
		{
			SaveCharacter(i); SaveCharacterPos(i);
		}
		
	}
	
	//Saving systems:
	SaveFactions();
	SaveProperties();
	SaveBusinesses();
	RealTime_StopTime();

	forex(i, MAX_TREES) if(TreeInfo[i][E_TREE_EXISTS])
	{
		Tree_Save(i);
	}
	
	//Closing database:
	mysql_close(ourConnection);
	return 1;
}

public OnPlayerConnect(playerid)
{
	PlayAudioStreamForPlayer(playerid, "https://j.top4top.io/m_3186mo2bk1.mp3");

	ShowClock(playerid);
	ResetPlayer(playerid);
	PreloadAnimations(playerid); 
	RemoveObjects(playerid);

	//Visuals:
	CreateTextdraws(playerid);
	CreateHUDTextDraws(playerid);
	CreatePhoneTextDraws(playerid);
	CreateVehicleTextDraws(playerid);
	CreateBarInfoTextDraws(playerid);
	CreateTutorialTextDraws(playerid);
	CreateSpectatorTextDraws(playerid);
	CreateNotificationTextDraws(playerid);
	CreateSelectFactionTextDraws(playerid);
	
	HideVehicleSpeedometer(playerid);
	DestroyGameBar(playerid);

	//Player:
	SetPlayerHealthEx(playerid, PlayerInfo[playerid][E_CHARACTER_HEALTH]);
	SetPlayerArmourEx(playerid, PlayerInfo[playerid][E_CHARACTER_ARMOUR]);
	SetPlayerColor(playerid, COLOR_GREY);

	LastEnteredVehicle[playerid] = INVALID_VEHICLE_ID;

	EnablePlayerCameraTarget(playerid, true);

	Streamer_SetVisibleItems(STREAMER_TYPE_OBJECT, 5000, playerid);

	if(PlayerInfo[playerid][E_CHARACTER_INJURED] == 1)
	{
		SetPlayerTeam(playerid, PLAYER_STATE_WOUNDED);
	}
	else if(PlayerInfo[playerid][E_CHARACTER_DEATH] == 1)
	{
		SetPlayerTeam(playerid, PLAYER_STATE_DEAD);
	}
	else
	{
		SetPlayerTeam(playerid, PLAYER_STATE_ALIVE);
	}

	if(!IsPlayerNPC(playerid))
	{
		PlayerInfo[playerid][E_CHARACTER_ROBBERYACTOR] = -1;
		PlayerInfo[playerid][E_CHARACTER_HASROBBIZ] = false;
	}
	return 1;
}

public OnPlayerDisconnect(playerid, reason)
{
	for (new i = 0; i < sizeof(ReportInfo); i ++)
	{
		if(ReportInfo[i][E_REPORT_BY] == playerid)
		{
			ReportInfo[i][E_REPORT_EXISTS] = false; 
			ReportInfo[i][E_REPORT_BY] = INVALID_PLAYER_ID;
		}
	}

	if(PlayerInfo[playerid][E_CHARACTER_TAKEPACKET] == true)
	{
		new Float:x, Float:y, Float:z;
		GetPlayerPos(playerid, x, y, z);

		PlayerInfo[playerid][E_CHARACTER_TAKEPACKET] = false;
		InsertPacket(x, y, z-1);
		foreach(new p : Player) if(PlayerInfo[p][E_CHARACTER_JOBS] == JOB_SMUGGLER)
		{
			SendClientMessage(p, COLOR_DARKGREEN, "[Word on the Streetz] Smuggler packet has been spawned '/findpacket' to track packet");
		}
	}
	
	if (PlayerInfo[playerid][E_CHARACTER_TAXIPLAYER] != INVALID_PLAYER_ID)
	    LeaveTaxi(playerid, PlayerInfo[playerid][E_CHARACTER_TAXIPLAYER]);

	foreach(new i : Player)
	{
		if(PlayerInfo[i][E_CHARACTER_FACTIONINVITED] == playerid)
		{
			PlayerInfo[i][E_CHARACTER_FACTIONINVITE] = 0;
			PlayerInfo[i][E_CHARACTER_FACTIONINVITED] = INVALID_PLAYER_ID;
			SendClientMessage(i, COLOR_FACTION, "Your faction invitation was disregarded. Your inviter disconnected.");
		}
	}

	KillTimer(cameraTimer[playerid]);

	new playerTime = NetStats_GetConnectedTime(playerid);
	new secondsConnection = (playerTime % (1000*60*60)) / (1000*60);
	
	PlayerInfo[playerid][E_CHARACTER_LASTONLINE] = secondsConnection;

	if(PlayerInfo[playerid][E_CHARACTER_SPAWNED] == true && PlayerInfo[playerid][E_CHARACTER_TUTORIAL])
	{
		SaveCharacter(playerid); SaveCharacterPos(playerid);
	}

	if(PlayerInfo[playerid][E_CHARACTER_POLICEDUTY] == true)
	{
		if(Inventory_Count(playerid, "Night Hawk"))
		{
			Inventory_Remove(playerid, "Night Hawk", 1);
		}
		Inventory_Remove(playerid, "9mm", 50);
	}

	KillTimer(PlayerInfo[playerid][E_CHARACTER_LOADINGTIMER]);

	ResetPlayerJump(playerid);

	PlayerInfo[playerid][E_CHARACTER_COURT] = 0;
	PlayerInfo[playerid][E_CHARACTER_HAVEBALL] = 0;
    PlayerInfo[playerid][E_CHARACTER_ANIMBALL] = 0;
	PlayerInfo[playerid][E_CHARACTER_COURTTEAM] = 0;
    if(PlayerInfo[playerid][E_CHARACTER_HAVEBALL]) CourtInfo[PlayerInfo[playerid][E_CHARACTER_COURT]][E_BALLER] = 999;

	switch(reason)
	{
	    case 0: SendNearbyMessage(playerid, 20.0, COLOR_DARKGREEN, "** %s has left the GTA Storylines. (Timeout)", ReturnSettingsName(playerid, playerid));
	    case 1: SendNearbyMessage(playerid, 20.0, COLOR_DARKGREEN, "** %s has left the GTA Storylines. (Leaving)", ReturnSettingsName(playerid, playerid));
	    case 2: SendNearbyMessage(playerid, 20.0, COLOR_DARKGREEN, "** %s has left the GTA Storylines. (Kicked)", ReturnSettingsName(playerid, playerid));
	}
	return 1; 
}

function:LoginTimer(playerid)
{
	cameraIndex[playerid] = 0;
	InterpolateCameraPos(playerid, 2467.694091, -1680.678100, 22.207088, 2470.404296, -1640.607177, 23.310541, 15000, 1);
	InterpolateCameraLookAt(playerid, 2471.343017, -1681.534667, 20.810289, 2472.477294, -1643.914062, 22.434955, 15000, 1);
	cameraTimer[playerid] = SetTimerEx("SetPlayerCamera", 10000, true, "i", playerid);

	new existCheck[256]; 
	mysql_format(ourConnection, existCheck, sizeof(existCheck), "SELECT * FROM bannedlist WHERE IpAddress = '%e'", ReturnIP(playerid));
	mysql_pquery(ourConnection, existCheck, "CheckBanList", "i", playerid);
	return 1;
}

function:CheckBanList(playerid)
{	
	if(!cache_num_rows())
	{
		new existCheck[512];
		//for(new i = 0; i < 3; i ++) {PlayerTextDrawShow(playerid, loginscreen[i][playerid]);}
		
		mysql_format(ourConnection, existCheck, sizeof(existCheck), "SELECT acc_dbid, secret_word, verified FROM masters WHERE acc_name = '%e'", ReturnSettingsName(playerid, playerid));
		mysql_pquery(ourConnection, existCheck, "LogPlayerIn", "i", playerid);
	}
	else
	{
		SendServerMessage(playerid, "Your IP \"%s\" is banned from our servers.", ReturnIP(playerid));
		SendServerMessage(playerid, "You may appeal your ban on our forums."); 
		return KickEx(playerid);
	}
	return 1;
}

function:LogPlayerIn(playerid)
{		
	if(cache_num_rows())
	{
		loginTime[playerid] = 1; 
		for(new i = 0; i < 20; i ++) { SendClientMessage(playerid, -1, " "); }
		
		new str[1024];
		format(str, sizeof(str), "{ffffff}Welcome to {297183}Storylines{DEDEDE}, {FFFFFF}%s!\n\n{DEDEDE}Failure to authenticate three times will result in a {E03232}kick{DEDEDE}.\nYou have a total of {EEC650}five minutes{DEDEDE} to authenticate.\n\nIn order to proceed, enter a {EEC650}password{DEDEDE} below to authenticate (or register).", ReturnSettingsName(playerid, playerid));
		ShowPlayerDialog(playerid, DIALOG_LOGIN, DIALOG_STYLE_PASSWORD, "Login:", str, "Confirm", "");
	}
	else
	{
		for(new i = 0; i < 20; i ++) { SendClientMessage(playerid, -1, " "); }	
		registerTime[playerid] = 1;	
		//ShowPlayerDialog(playerid, DIALOG_REGISTER, DIALOG_STYLE_MSGBOX, "Connection:", "Your account was not registered, Please registration in official discord Storylines.", "Close", "");
		new str[1024];
		format(str, sizeof(str), "{ffffff}Welcome to {297183}Storylines{DEDEDE}, {FFFFFF}%s!\n\n{DEDEDE}Failure to authenticate three times will result in a {E03232}kick{DEDEDE}.\nYou have a total of {EEC650}five minutes{DEDEDE} to authenticate.\n\nIn order to proceed, enter a {EEC650}password{DEDEDE} below to authenticate (or register).", ReturnSettingsName(playerid, playerid));
		ShowPlayerDialog(playerid, DIALOG_REGISTER, DIALOG_STYLE_PASSWORD, "Register:", str, "Confirm", "");
	}
	return 1;
}

public OnPlayerEnterRaceCheckpoint(playerid)
{
	if(GetPlayerState(playerid) == PLAYER_STATE_DRIVER)
    {
		if(PlayerTakingLicense[playerid])
		{
			if(PlayerCheckpoint[playerid] == GPS_DMVFINISH)
			{
				StopDriverstest(playerid);
				SendServerMessage(playerid, "Congratulations %s, you've passed your test.", ReturnSettingsName(playerid, playerid)); 
				
				PlayerInfo[playerid][E_CHARACTER_DRIVELICENSE] = 1;
				SaveCharacter(playerid);
				
				PlayerCheckpoint[playerid] = GPS_NONE; 
				return 1; 
			}
		}

		if(PlayerLicensePoint[playerid] < sizeof LicensetestInfo && PlayerCheckpoint[playerid] == GPS_DMV)
		{
			SendClientMessage(playerid, COLOR_GREY, "License instructor says: Head to the next checkpoint."); 
			PlayerLicensePoint[playerid]++; 
			
			new idx = PlayerLicensePoint[playerid];
			
			GPS_SetPlayerRaceCheckPoint(playerid, 1, LicensetestInfo[idx][E_CHECKPOINTX], LicensetestInfo[idx][E_CHECKPOINTY], LicensetestInfo[idx][E_CHECKPOINTZ], 0.0, 0.0, 0.0, GPS_DMV);
			if(LicensetestInfo[idx][E_CHECKPOINT_FINISH])
			{
				PlayerCheckpoint[playerid] = GPS_DMVFINISH;
			}
		}
    }

	if(PlayerCheckpoint[playerid] == GPS_NONE)
	{
    	GPS_DisablePlayerRaceCheckPoint(playerid);
		PlayerPlaySound(playerid, 1138, 0.0, 0.0, 0.0);
	}
    return 1;
}

public OnPlayerEnterDynamicArea(playerid, areaid)
{
	forex(i, MAX_TREES) if(TreeInfo[i][E_TREE_EXISTS])
	{
		if(areaid == TreeInfo[i][E_TREE_AREA])
		{
			new str[152];
			if(PlayerInfo[playerid][E_CHARACTER_JOBS] == JOB_LUMBERJACK)
			{
				if(TreeInfo[i][E_TREE_CUTTED])
				{
					format(str, sizeof(str), "Press ALT to load the timber.");
				}
				else
				{
					if(TreeInfo[i][E_TREE_TIMER] < 1)
					{
						format(str, sizeof(str), "Available to cut~n~Press ALT to begin.");
					}
					else
					{
						format(str, sizeof(str), "Available in: %d seconds", TreeInfo[i][E_TREE_TIMER]);
					}
				}
				ShowBoxMessage(playerid, str, 5);
			}
		}
	}
	return 1;
}

public OnPlayerEnterDynamicCP(playerid, checkpointid)
{
	if(checkpointid == ModShop[0])
    {
    	if(IsPlayerInVehicle(playerid, GetPlayerVehicleID(playerid)))
    	{
			Dialog_Show(playerid, ModShops, DIALOG_STYLE_TABLIST, "Pay n Spray:", "Respray Exterior\t$150\nRespray Interior\t$150\nRespray Paintjob type 1\t$300\nRespray Paintjob type 2\t$300\nRespray Paintjob type 3\t$300\nRepair Bodywork\t$250\nRepair Engine\t$500\nRepair Tires\t$250\nAdd Modifications\t$350\nAdd Wheels\t$350\nAdd Hydraulics\t$500", "Select", "Close");
    		TogglePlayerControllable(playerid, false);
    		PlayerInfo[playerid][E_CHARACTER_TOGMENU] = true;
    	}
    }
    else if(checkpointid == ModShop[1])
    {
    	if(IsPlayerInVehicle(playerid, GetPlayerVehicleID(playerid)))
    	{
			Dialog_Show(playerid, ModShops, DIALOG_STYLE_TABLIST, "Pay n Spray:", "Respray Exterior\t$150\nRespray Interior\t$150\nRespray Paintjob type 1\t$300\nRespray Paintjob type 2\t$300\nRespray Paintjob type 3\t$300\nRepair Bodywork\t$250\nRepair Engine\t$500\nRepair Tires\t$250\nAdd Modifications\t$350\nAdd Wheels\t$350\nAdd Hydraulics\t$500", "Select", "Close");
    		TogglePlayerControllable(playerid, false);
    		PlayerInfo[playerid][E_CHARACTER_TOGMENU] = true;
    	}
    }
    else if(checkpointid == ModShop[2])
    {
    	if(IsPlayerInVehicle(playerid, GetPlayerVehicleID(playerid)))
    	{
			Dialog_Show(playerid, ModShops, DIALOG_STYLE_TABLIST, "Pay n Spray:", "Respray Exterior\t$150\nRespray Interior\t$150\nRespray Paintjob type 1\t$300\nRespray Paintjob type 2\t$300\nRespray Paintjob type 3\t$300\nRepair Bodywork\t$250\nRepair Engine\t$500\nRepair Tires\t$250\nAdd Modifications\t$350\nAdd Wheels\t$350\nAdd Hydraulics\t$500", "Select", "Close");
    		TogglePlayerControllable(playerid, false);
    		PlayerInfo[playerid][E_CHARACTER_TOGMENU] = true;
    	}
    }
	return 1;
}

Dialog:ModShops(playerid, response, listitem, inputtext[])
{
	new vehicleid = GetPlayerVehicleID(playerid);
	switch(listitem)
	{
		case 0: 
		{
			if(!response)
				return TogglePlayerControllable(playerid, true);

			if (!IsPlayerInAnyVehicle(playerid))
				return SendErrorMessage(playerid, "You aren't in any vehicle.");

			static
				colors[256];

			for (new i = 0; i < sizeof(colors); i ++) {
				colors[i] = i;
			}
			ShowColorSelectionMenu(playerid, MODEL_SELECTION_COLOR1, colors);
			TogglePlayerControllable(playerid, true);
			PlayerInfo[playerid][E_CHARACTER_TOGMENU] = false;
		}
		case 1: 
		{
			if(!response)
				return TogglePlayerControllable(playerid, true);

			if (!IsPlayerInAnyVehicle(playerid))
				return SendErrorMessage(playerid, "You aren't in any vehicle.");

			static
				colors[256];

			for (new i = 0; i < sizeof(colors); i ++) {
				colors[i] = i;
			}
			ShowColorSelectionMenu(playerid, MODEL_SELECTION_COLOR2, colors);
			TogglePlayerControllable(playerid, true);
			PlayerInfo[playerid][E_CHARACTER_TOGMENU] = false;
		}
		case 2: 
		{
			if(!response)
				return TogglePlayerControllable(playerid, true);

			if (!IsPlayerInAnyVehicle(playerid))
				return SendErrorMessage(playerid, "You aren't in any vehicle.");

			if(!IsSuitablePaintjobCar(GetPlayerVehicleID(playerid))) 
			{
				TogglePlayerControllable(playerid, true);
				SendErrorMessage(playerid, "Your current vehicle does not natively support paintjobs.");
			}
			else 
			{
				ShowBoxMessage(playerid, "Hope you like new paintjob!!", 5);
				
				ChangeVehiclePaintjob(GetPlayerVehicleID(playerid), 0);
				VehicleInfo[GetPlayerVehicleID(playerid)][E_VEHICLE_PAINTJOB] = 0;
				SaveVehicle(GetPlayerVehicleID(playerid));
				PlayerPlaySound(playerid, 1134, 0.0, 0.0, 0.0);

				GiveMoney(playerid, -300);
				PauseAC(playerid);
				TogglePlayerControllable(playerid, true);
				PlayerInfo[playerid][E_CHARACTER_TOGMENU] = false;
			}
		}
		case 3: 
		{
			if(!response)
				return TogglePlayerControllable(playerid, true);

			if (!IsPlayerInAnyVehicle(playerid))
				return SendErrorMessage(playerid, "You aren't in any vehicle.");

			if(!IsSuitablePaintjobCar(GetPlayerVehicleID(playerid))) 
			{
				TogglePlayerControllable(playerid, true);
				SendErrorMessage(playerid, "Your current vehicle does not natively support paintjobs.");
			}
			else 
			{
				ShowBoxMessage(playerid, "Hope you like new paintjob!!", 5);
				
				ChangeVehiclePaintjob(GetPlayerVehicleID(playerid), 1);
				VehicleInfo[GetPlayerVehicleID(playerid)][E_VEHICLE_PAINTJOB] = 1;
				SaveVehicle(GetPlayerVehicleID(playerid));
				PlayerPlaySound(playerid, 1134, 0.0, 0.0, 0.0);

				GiveMoney(playerid, -300);
				PauseAC(playerid);
				TogglePlayerControllable(playerid, true);
				PlayerInfo[playerid][E_CHARACTER_TOGMENU] = false;
			}
		}
		case 4: 
		{
			if(!response)
				return TogglePlayerControllable(playerid, true);

			if (!IsPlayerInAnyVehicle(playerid))
				return SendErrorMessage(playerid, "You aren't in any vehicle.");

			if(!IsSuitablePaintjobCar(GetPlayerVehicleID(playerid))) 
			{
				TogglePlayerControllable(playerid, true);
				SendErrorMessage(playerid, "Your current vehicle does not natively support paintjobs.");
			}
			else 
			{
				ShowBoxMessage(playerid, "Hope you like new paintjob!!", 5);
				
				ChangeVehiclePaintjob(GetPlayerVehicleID(playerid), 2);
				VehicleInfo[GetPlayerVehicleID(playerid)][E_VEHICLE_PAINTJOB] = 2;
				SaveVehicle(GetPlayerVehicleID(playerid));

				PlayerPlaySound(playerid, 1134, 0.0, 0.0, 0.0);
				GiveMoney(playerid, -300);
				PauseAC(playerid);
				TogglePlayerControllable(playerid, true);
				PlayerInfo[playerid][E_CHARACTER_TOGMENU] = false;
			}
				
		}
		case 5: 
		{
			if(!response)
				return TogglePlayerControllable(playerid, true);

			if (!IsPlayerInAnyVehicle(playerid))
				return SendErrorMessage(playerid, "You aren't in any vehicle.");

			new panels, doors, lights, tires;
			GetVehicleDamageStatus(vehicleid, panels, doors, lights, tires);
			UpdateVehicleDamageStatus(vehicleid, 0, 0, 0, tires);
			PlayerPlaySound(playerid,1133,0.0,0.0,0.0);
			SaveVehicle(vehicleid);
			GiveMoney(playerid, -250);
			PauseAC(playerid);
			TogglePlayerControllable(playerid, true);
			PlayerInfo[playerid][E_CHARACTER_TOGMENU] = false;
		}
		case 6: 
		{
			if (!IsPlayerInAnyVehicle(playerid))
				return SendErrorMessage(playerid, "You aren't in any vehicle.");

			SetVehicleHealthEx(vehicleid, 1000.0);
			PlayerPlaySound(playerid,1133,0.0,0.0,0.0);
			SaveVehicle(vehicleid);
			GiveMoney(playerid, -500);
			PauseAC(playerid);
			TogglePlayerControllable(playerid, true);
			PlayerInfo[playerid][E_CHARACTER_TOGMENU] = false;
		}
		case 7: 
		{
			if(!response)
				return TogglePlayerControllable(playerid, true);

			if (!IsPlayerInAnyVehicle(playerid))
				return SendErrorMessage(playerid, "You aren't in any vehicle.");

			new panels, doors, lights, tires;
			GetVehicleDamageStatus(vehicleid, panels, doors, lights, tires);
			UpdateVehicleDamageStatus(vehicleid, panels, doors, lights, 0);
			PlayerPlaySound(playerid,1133,0.0,0.0,0.0);
			SaveVehicle(vehicleid);
			GiveMoney(playerid, -250);
			PauseAC(playerid);
			TogglePlayerControllable(playerid, true);
			PlayerInfo[playerid][E_CHARACTER_TOGMENU] = false;
		}
		case 8: 
		{
			if(!response)
				return TogglePlayerControllable(playerid, true);

			if (!IsPlayerInAnyVehicle(playerid))
				return SendErrorMessage(playerid, "You aren't in any vehicle.");

			new modname[50][32], v = GetPlayerVehicleID(playerid), mods[50], count = 0;
			for(new m = 1000; m < 1193; m++)
			{
				if(IsVehicleUpgradeCompatible(VehicleInfo[v][E_VEHICLE_MODEL], m) && IsActualVehicleMod(m))
				{
					mods[count] = m;
					format(modname[count], 32, "%s", GetVehicleModName(m));
					count ++;
				}
			}
			if(count == 0) return SendErrorMessage(playerid, "This vehicle does not support any bodywork modifications."); TogglePlayerControllable(playerid, true);

			ShowModelSelectionMenu(playerid, "Add Modifications", MODEL_SELECTION_MODS, mods, count, 0.0, 0.0, 0.0);

			TogglePlayerControllable(playerid, true);
			PlayerInfo[playerid][E_CHARACTER_TOGMENU] = false;
		}
		case 9: 
		{
			if(!response)
				return TogglePlayerControllable(playerid, true);

			if (!IsPlayerInAnyVehicle(playerid))
				return SendErrorMessage(playerid, "You aren't in any vehicle.");

			ShowModelSelectionMenu(playerid, "Add Wheels", MODEL_SELECTION_WHEELS, {1025, 1073, 1074, 1075, 1076, 1077, 1078, 1079, 1080, 1081, 1082, 1083, 1084, 1085, 1096, 1097, 1098}, 17, 0.0, 0.0, 90.0);

			TogglePlayerControllable(playerid, true);
			PlayerInfo[playerid][E_CHARACTER_TOGMENU] = false;
		}
		case 10: 
		{
			if(!response)
				return TogglePlayerControllable(playerid, true);

			if (!IsPlayerInAnyVehicle(playerid))
				return SendErrorMessage(playerid, "You aren't in any vehicle.");

			AddVehicleComponent(GetPlayerVehicleID(playerid), 1087);
			VehicleInfo[GetPlayerVehicleID(playerid)][E_VEHICLE_HYDRAULICS] = 1087;

			PauseAC(playerid);
			GiveMoney(playerid, -500);
			SaveVehicle(GetPlayerVehicleID(playerid));
			TogglePlayerControllable(playerid, true);
			PlayerInfo[playerid][E_CHARACTER_TOGMENU] = false;
		}
	}
	return 1;
}

function:OnPlayerRegister(playerid)
{
	AccountInfo[playerid][E_MASTERS_DBID] = cache_insert_id(); 
	format(AccountInfo[playerid][E_MASTERS_ACCNAME], 32, "%s", ReturnSettingsName(playerid, playerid)); 
	
	registerTime[playerid] = 0;
	loginTime[playerid] = 1; 
	
	new str[1024];
	format(str, sizeof(str), "{ffffff}Welcome to {297183}Storylines{DEDEDE}, {FFFFFF}%s!\n\n{DEDEDE}Failure to authenticate three times will result in a {E03232}kick{DEDEDE}.\nYou have a total of {EEC650}five minutes{DEDEDE} to authenticate.\n\nIn order to proceed, enter a {EEC650}password{DEDEDE} below to authenticate (or register).", ReturnSettingsName(playerid, playerid));
	SendServerMessage(playerid, "You successfully registered as %s. You need to login to continue:", ReturnSettingsName(playerid, playerid)); 
	return ShowPlayerDialog(playerid, DIALOG_LOGIN, DIALOG_STYLE_PASSWORD, "Login:", str, "Confirm", "");
}

function:LoggingIn(playerid)
{
	if (!IsPlayerConnected(playerid))
	    return 0;

	if(!cache_num_rows())
	{
		playerLogin[playerid]++;
		if(playerLogin[playerid] == 3)
		{
			SendErrorMessage(playerid, "You were kicked for bad password attempts.");
			return KickEx(playerid);
		}
		
		new str[1024];
		format(str, sizeof(str), "{ffffff}Welcome to {297183}Storylines{DEDEDE}, {FFFFFF}%s!\n\n{DEDEDE}Failure to authenticate three times will result in a {E03232}kick{DEDEDE}.\nYou have a total of {EEC650}five minutes{DEDEDE} to authenticate.\n\nIn order to proceed, enter a {EEC650}password{DEDEDE} below to authenticate (or register).", ReturnSettingsName(playerid, playerid));
		return ShowPlayerDialog(playerid, DIALOG_LOGIN, DIALOG_STYLE_PASSWORD, "Login:", str, "Confirm", "");
	}
	
	new rows, fields, fetchChars[128];
	cache_get_row_count(rows);
	cache_get_field_count(fields);
	
	new ActiveIP[60];
	
	cache_get_value_name_int(0, "acc_dbid", AccountInfo[playerid][E_MASTERS_DBID]); 
	cache_get_value_name(0, "forum_name", AccountInfo[playerid][E_MASTERS_FORUMNAME], 60);

	cache_get_value_name_int(0, "secret_word", AccountInfo[playerid][E_MASTERS_CODE]);
	cache_get_value_name(0, "active_ip", ActiveIP);
	
	format(AccountInfo[playerid][E_MASTERS_ACCNAME], 32, "%s", ReturnSettingsName(playerid, playerid));

	if (AccountInfo[playerid][E_MASTERS_LOGGED] == false)
	{
		AccountInfo[playerid][E_MASTERS_LOGGED] = true;
	}
	KillTimer(cameraTimer[playerid]);
	SetCameraBehindPlayer(playerid); 

	mysql_format(ourConnection, fetchChars, sizeof(fetchChars), "SELECT * FROM bannedlist WHERE MasterDBID = %d", AccountInfo[playerid][E_MASTERS_DBID]);
	mysql_pquery(ourConnection, fetchChars, "Query_CheckBannedAccount", "i", playerid); 
	return 1;
}

function:Query_CheckBannedAccount(playerid)
{
	new rows, fields;
	cache_get_row_count(rows);
	cache_get_field_count(fields);

	if(!cache_num_rows())
	{
		loginTime[playerid] = 0; 
		characterPickTime[playerid] = 1;
		
		new fetchChars[512];
	
		mysql_format(ourConnection, fetchChars, sizeof(fetchChars), "SELECT * FROM characters WHERE `master_dbid` = '%d' LIMIT 4", AccountInfo[playerid][E_MASTERS_DBID]);
		mysql_pquery(ourConnection, fetchChars, "DB_ListCharacters", "i", playerid);
	}
	else
	{	
		new banDate[90], banner[32];
		
		cache_get_value_name(0, "Date", banDate, 90);
		cache_get_value_name(0, "BannedBy", banner, 32);
	
		SendServerMessage(playerid, "{ffffff}Your account \"%s\" is banned from our server.", ReturnSettingsName(playerid, playerid));
		SendServerMessage(playerid, "You were banned on %s by %s.", banDate, banner); 
		return KickEx(playerid);
	}
	return 1;
}

function:DB_ListCharacters(playerid)
{
	new rows;
	cache_get_row_count(rows);
	
	new vwid = AccountInfo[playerid][E_MASTERS_DBID];
	SetPlayerVirtualWorld(playerid, vwid);
	SetPlayerInterior(playerid, 0);

	if(!rows)
	{
		SendServerMessage(playerid, "You don't have any existing characters.");
		
		PlayerTextDrawSetString(playerid, SelectFactionName[playerid], "Hoodrats");
		PlayerTextDrawSetString(playerid, SelectFactionLocation[playerid], "Empty_Characters");
		PlayerTextDrawColor(playerid,SelectFactionName[playerid], COLOR_WHITE);
	}

	for (new i = 0; i < 4; i ++)
	{
		characterLister[playerid][i][0] = EOS;
	}

	for (new i = 0; i < cache_num_rows(); i ++)
	{
		cache_get_value_name(i, "char_name", characterLister[playerid][i], 128); 
		cache_get_value_name_int(i, "pLastSkin", characterSkin[playerid][i]);
		cache_get_value_name_int(i, "pFaction", characterFaction[playerid][i]);
	}

	CreatePlayerActor(playerid, characterSkin[playerid][0]);
	ShowCharacterSelection(playerid);
	
	KillTimer(cameraTimer[playerid]);
	return 1;
}

function:Query_SelectCharacter(playerid)
{
	new rows, fields, thread[512]; 
	cache_get_row_count(rows);
	cache_get_field_count(fields);

	if (!rows)
	{
		SendErrorMessage(playerid, "An error occurred processing your character. Returning you to your character list...");
			
		return ShowCharacterSelection(playerid);
	}
	
	if(rows)
	{
		mysql_format(ourConnection, thread, sizeof(thread), "SELECT * FROM characters WHERE char_name = '%e'", ReturnSettingsName(playerid, playerid));
		mysql_pquery(ourConnection, thread, "Query_LoadCharacter", "i", playerid);
	}
	return 1;
}

function:Query_LoadCharacter(playerid)
{
	cache_get_value_name_int(0, "char_dbid", PlayerInfo[playerid][E_CHARACTER_DBID]);
	cache_get_value_name(0, "char_name", PlayerInfo[playerid][E_CHARACTER_NAME], 32);
	cache_get_value_name(0, "char_masters", PlayerInfo[playerid][E_CHARACTER_STREETNAME], 32);
	cache_get_value_name_int(0, "pAdmin", PlayerInfo[playerid][E_CHARACTER_ADMIN]);
	cache_get_value_name_int(0, "pLastSkin", PlayerInfo[playerid][E_CHARACTER_LASTSKIN]);
	cache_get_value_name_int(0, "pFacSkin", PlayerInfo[playerid][E_CHARACTER_FACSKIN]);
	cache_get_value_name_float(0, "pLastPosX", PlayerInfo[playerid][E_CHARACTER_LASTPOS][0]);
	cache_get_value_name_float(0, "pLastPosY", PlayerInfo[playerid][E_CHARACTER_LASTPOS][1]);
	cache_get_value_name_float(0, "pLastPosZ", PlayerInfo[playerid][E_CHARACTER_LASTPOS][2]);
	cache_get_value_name_int(0, "pLastInterior", PlayerInfo[playerid][E_CHARACTER_LASTINTERIOR]);
	cache_get_value_name_int(0, "pLastWorld", PlayerInfo[playerid][E_CHARACTER_LASTWORLD]);
	cache_get_value_name_int(0, "pLevel", PlayerInfo[playerid][E_CHARACTER_LEVEL]);
	cache_get_value_name(0, "pAge", PlayerInfo[playerid][E_CHARACTER_AGE], 20);
	cache_get_value_name(0, "pStory", PlayerInfo[playerid][E_CHARACTER_STORY], 90);
	cache_get_value_name(0, "pStoryTwo", PlayerInfo[playerid][E_CHARACTER_STORYTWO], 90);
	cache_get_value_name_int(0, "pMoney", PlayerInfo[playerid][E_CHARACTER_MONEY]);
	cache_get_value_name_int(0, "pBank", PlayerInfo[playerid][E_CHARACTER_BANK]); 
	cache_get_value_name_int(0, "pPaycheck", PlayerInfo[playerid][E_CHARACTER_PAYCHECK]);
	cache_get_value_name_int(0, "pPhone", PlayerInfo[playerid][E_CHARACTER_PHONE]); 
	cache_get_value_name(0, "pLastOnline", PlayerInfo[playerid][E_CHARACTER_LASTONLINEDATE], 90);
	cache_get_value_name_int(0, "pLastOnlineTime", PlayerInfo[playerid][E_CHARACTER_LASTONLINE]); 
	cache_get_value_name_bool(0, "pAdminjailed", PlayerInfo[playerid][E_CHARACTER_ADMINJAILED]);
	cache_get_value_name_int(0, "pAdminJailTime", PlayerInfo[playerid][E_CHARACTER_ADMINJAIL]);
	cache_get_value_name_bool(0, "pOfflinejailed", PlayerInfo[playerid][E_CHARACTER_OFFJAILED]);
	cache_get_value_name(0, "pOfflinejailedReason", PlayerInfo[playerid][E_CHARACTER_OFFJAILREASON], 128);
	cache_get_value_name_int(0, "pFaction", PlayerInfo[playerid][E_CHARACTER_FACTION]);
	cache_get_value_name_int(0, "pFactionRank", PlayerInfo[playerid][E_CHARACTER_FACTIONRANK]);
	cache_get_value_name_int(0, "pFactionSubsets", PlayerInfo[playerid][E_CHARACTER_FACTIONSUBSETS]);
	cache_get_value_name_bool(0, "pVehicleSpawned", PlayerInfo[playerid][E_CHARACTER_VEHICLESPAWNED]);
	cache_get_value_name_int(0, "pVehicleSpawnedID", PlayerInfo[playerid][E_CHARACTER_VEHICLESPAWN]);
	cache_get_value_name_int(0, "pTimeplayed", PlayerInfo[playerid][E_CHARACTER_TIMEPLAYED]);
	cache_get_value_name_int(0, "pMaskID", PlayerInfo[playerid][E_CHARACTER_MASKID][0]);
	cache_get_value_name_int(0, "pMaskIDEx", PlayerInfo[playerid][E_CHARACTER_MASKID][1]);
	cache_get_value_name_int(0, "pInProperty", PlayerInfo[playerid][E_CHARACTER_INSIDEPROP]);
	cache_get_value_name_int(0, "pInBusiness", PlayerInfo[playerid][E_CHARACTER_INSIDEBIZ]);
	cache_get_value_name_int(0, "pMainSlot", PlayerInfo[playerid][E_CHARACTER_MAINSLOT]);
	cache_get_value_name_int(0, "pRobberyCooldown", PlayerInfo[playerid][E_CHARACTER_ROBBERYCD]);
	cache_get_value_name_int(0, "pSpawnPoint", PlayerInfo[playerid][E_CHARACTER_SPAWNPOINT]);
	cache_get_value_name_int(0, "pWeaponsLicense", PlayerInfo[playerid][E_CHARACTER_WEAPLICENSE]);
	cache_get_value_name_int(0, "pDriversLicense", PlayerInfo[playerid][E_CHARACTER_DRIVELICENSE]); 
	cache_get_value_name_int(0, "pActiveListings", PlayerInfo[playerid][E_CHARACTER_ACTIVELIST]); 
	cache_get_value_name_bool(0, "pPrison", PlayerInfo[playerid][E_CHARACTER_PRISONED]);
	cache_get_value_name_int(0, "pPrisonTimes", PlayerInfo[playerid][E_CHARACTER_PRISON]); 
	cache_get_value_name_int(0, "pHasInjured", PlayerInfo[playerid][E_CHARACTER_INJURED]); 
	cache_get_value_name_int(0, "pHasDeath", PlayerInfo[playerid][E_CHARACTER_DEATH]); 
	cache_get_value_name_float(0, "pHealth", PlayerInfo[playerid][E_CHARACTER_HEALTH]); 
	cache_get_value_name_float(0, "pArmor", PlayerInfo[playerid][E_CHARACTER_ARMOUR]); 
	cache_get_value_name_int(0, "pFightstyle", PlayerInfo[playerid][E_CHARACTER_FIGHTSTYLE]); 
	cache_get_value_name_int(0, "pHasAoe", PlayerInfo[playerid][E_CHARACTER_AOE]); 
	cache_get_value_name_int(0, "pHungry", PlayerInfo[playerid][E_CHARACTER_HUNGRY]); 
	cache_get_value_name_int(0, "pThirsty", PlayerInfo[playerid][E_CHARACTER_THIRSTY]); 
	cache_get_value_name_int(0, "pStamina", PlayerInfo[playerid][E_CHARACTER_STAMINA]); 
	cache_get_value_name_int(0, "pMuscle", PlayerInfo[playerid][E_CHARACTER_MUSCLE]); 
	cache_get_value_name_int(0, "pEXP", PlayerInfo[playerid][E_CHARACTER_EXP]); 
	cache_get_value_name_int(0, "pFear", PlayerInfo[playerid][E_CHARACTER_FEAR]); 
	cache_get_value_name_int(0, "pRespect", PlayerInfo[playerid][E_CHARACTER_RESPECT]); 
	cache_get_value_name_int(0, "pJobs", PlayerInfo[playerid][E_CHARACTER_JOBS]); 
	cache_get_value_name_int(0, "pTutorial", PlayerInfo[playerid][E_CHARACTER_TUTORIAL]); 

	new str[128];
	
	for(new i = 1; i < 3; i++)
	{
		format(str, sizeof(str), "pRadio%i", i);
		cache_get_value_name_int(0, str, PlayerInfo[playerid][E_CHARACTER_RADIO][i]);
	}
	
	for(new i = 1; i < MAX_PLAYER_VEHICLES; i++)
	{	
		format(str, sizeof(str), "pOwnedVehicles%d", i);
		cache_get_value_name_int(0, str, PlayerInfo[playerid][E_CHARACTER_OWNEDVEHICLE][i]); 
	}
	
	if(!PlayerInfo[playerid][E_CHARACTER_MASKID])
	{
		PlayerInfo[playerid][E_CHARACTER_MASKID][0] = 200000+random(199991);
		PlayerInfo[playerid][E_CHARACTER_MASKID][1] = 40+random(59);
	}
	new query[256];
	mysql_format(ourConnection, query, sizeof(query), "SELECT * FROM `inventory` WHERE `ID` = '%d'", PlayerInfo[playerid][E_CHARACTER_DBID]);
	mysql_pquery(ourConnection, query, "LoadPlayerItems", "d", playerid);

	new qquery[256];
	mysql_format(ourConnection, qquery, sizeof(qquery), "SELECT * FROM `contacts` WHERE `ID` = '%d'", PlayerInfo[playerid][E_CHARACTER_DBID]);
	mysql_pquery(ourConnection, qquery, "LoadPlayerContacts", "d", playerid);

	new pquery[256];
	mysql_format(ourConnection, pquery, sizeof(qquery), "SELECT * FROM `relations` WHERE `relationsID` = '%i'", PlayerInfo[playerid][E_CHARACTER_DBID]);
	mysql_pquery(ourConnection, pquery, "LoadPlayerRelations", "d", playerid);
	
	TogglePlayerSpectating(playerid, false);
	return Dialog_Show(playerid, Spawns, DIALOG_STYLE_TABLIST, "Spawn Option:", "#1\tLos Santos Airport\t{5B9460}PUBLIC{ffffff}\n#2\tLast Position\t{5B9460}PUBLIC{ffffff}\n#3\tFaction Spawn\t{5B9460}FACTION{ffffff}", "Select", "Close");
}

Dialog:Spawns(playerid, response, listitem, inputtext[])
{
	if (!response)
	{
		SendErrorMessage(playerid, "You were kicked for not selection spawn."); 
		return KickEx(playerid);
	}
	switch(listitem)
	{
		case 0:
		{
			PlayerInfo[playerid][E_CHARACTER_SPAWNPOINT] = 0; 
			LoadCharacter(playerid);
		}
		case 1:
		{
			PlayerInfo[playerid][E_CHARACTER_SPAWNPOINT] = 1; 
			LoadCharacter(playerid);
		}
		case 2:
		{
			if(!PlayerInfo[playerid][E_CHARACTER_FACTION])
				return Dialog_Show(playerid, Spawns, DIALOG_STYLE_TABLIST, "Spawn Option:", "#1\tLos Santos Airport\t{5B9460}PUBLIC{ffffff}\n#2\tLast Position\t{5B9460}PUBLIC{ffffff}\n#3\tFaction Spawn\t{5B9460}FACTION{ffffff}", "Select", "Close");

			PlayerInfo[playerid][E_CHARACTER_SPAWNPOINT] = 2;
			LoadCharacter(playerid);
		}
	}
	return 1;
}

stock LoadCharacter(playerid)
{
	SetPlayerScore(playerid, PlayerInfo[playerid][E_CHARACTER_LEVEL]);

	if(PlayerInfo[playerid][E_CHARACTER_INJURED] == 1)
	{
		SetPlayerTeam(playerid, PLAYER_STATE_WOUNDED);
	}
	else if(PlayerInfo[playerid][E_CHARACTER_DEATH] == 1)
	{
		SetPlayerTeam(playerid, PLAYER_STATE_DEAD);
	}
	else
	{
		SetPlayerTeam(playerid, PLAYER_STATE_ALIVE);
	}
	
	SetPlayerSkillLevel(playerid, WEAPONSKILL_PISTOL, 200);
	SetPlayerSkillLevel(playerid, WEAPONSKILL_PISTOL_SILENCED, 500);
	SetPlayerSkillLevel(playerid, WEAPONSKILL_DESERT_EAGLE, 200);
	SetPlayerSkillLevel(playerid, WEAPONSKILL_SHOTGUN, 200);
	SetPlayerSkillLevel(playerid, WEAPONSKILL_SAWNOFF_SHOTGUN, 200);
	SetPlayerSkillLevel(playerid, WEAPONSKILL_SPAS12_SHOTGUN, 200);
	SetPlayerSkillLevel(playerid, WEAPONSKILL_MICRO_UZI, 50);
	SetPlayerSkillLevel(playerid, WEAPONSKILL_MP5, 250);
	SetPlayerSkillLevel(playerid, WEAPONSKILL_AK47, 200);
	SetPlayerSkillLevel(playerid, WEAPONSKILL_M4, 200);
	SetPlayerSkillLevel(playerid, WEAPONSKILL_SNIPERRIFLE, 300);

	SetPlayerHealthEx(playerid, PlayerInfo[playerid][E_CHARACTER_HEALTH]);
	SetPlayerArmourEx(playerid, PlayerInfo[playerid][E_CHARACTER_ARMOUR]);

	PauseAC(playerid);

	StopAudioStreamForPlayer(playerid);

	ResetPlayerMoney(playerid); 
	GivePlayerMoney(playerid, PlayerInfo[playerid][E_CHARACTER_MONEY]);

	new stri[256];
	format(stri, sizeof stri, ".:. %s has joined the GTA Storylines (joined)", AccountInfo[playerid][E_MASTERS_ACCNAME]);
	if(PlayerInfo[playerid][E_CHARACTER_TOGJOIN] == false)
	{
		SendClientMessageToAll(COLOR_DARKGREEN, stri);
	}	

	for(new i = 0; i < 20; i ++) { SendClientMessage(playerid, -1, " "); }
	SendClientMessageEx(playerid, COLOR_WHITE, "Welcome to the {5B9460}GTA Storylines{ffffff}, You logged in as {5B9460}%s{ffffff}.", AccountInfo[playerid][E_MASTERS_ACCNAME]);
	SendClientMessage(playerid, COLOR_WHITE, "The first thing we suggest you to do is to read /help or read the rules in discord server!");
	SendClientMessage(playerid, COLOR_WHITE, "Visit us and register on our discord at sa-mp.co.id to stay updated.");
	SendClientMessageEx(playerid, COLOR_WHITE, "[Player MOTD]: {5B9460}%s", PLAYER_MOTD);

	if(PlayerInfo[playerid][E_CHARACTER_VEHICLESPAWNED] == true)
	{
		if(!IsValidVehicle(PlayerInfo[playerid][E_CHARACTER_VEHICLESPAWN]))
			PlayerInfo[playerid][E_CHARACTER_VEHICLESPAWNED] = false; 
			
		else
			SendServerMessage(playerid, "Your vehicle is still spawned.");
	}
	
	SetCameraBehindPlayer(playerid);
	SetPlayerSkin(playerid, PlayerInfo[playerid][E_CHARACTER_LASTSKIN]);
	SetPlayerPosEx(playerid, PlayerInfo[playerid][E_CHARACTER_LASTPOS][0], PlayerInfo[playerid][E_CHARACTER_LASTPOS][1], PlayerInfo[playerid][E_CHARACTER_LASTPOS][2]);
	
	if(PlayerInfo[playerid][E_CHARACTER_OFFJAILED])
	{
		if(strlen(PlayerInfo[playerid][E_CHARACTER_OFFJAILREASON]) > 1)
		{
			SendClientMessageToAllEx(COLOR_RED, "AdmCmd: %s was admin jailed by SYSTEM for %d minutes, Reason: %.56s", ReturnSettingsName(playerid, playerid), PlayerInfo[playerid][E_CHARACTER_ADMINJAIL] / 60, PlayerInfo[playerid][E_CHARACTER_OFFJAILREASON]);
			SendClientMessageToAllEx(COLOR_RED, "AdmCmd: ...%s", PlayerInfo[playerid][E_CHARACTER_OFFJAILREASON][56]); 
		}
		else SendClientMessageToAllEx(COLOR_RED, "AdmCmd: %s was admin jailed by SYSTEM for %d minutes, Reason: %s", ReturnSettingsName(playerid, playerid), PlayerInfo[playerid][E_CHARACTER_ADMINJAIL] / 60, PlayerInfo[playerid][E_CHARACTER_OFFJAILREASON]);
		
		ClearAnimations(playerid);
		
		SetPlayerPosEx(playerid, 264.4271,78.0998,1001.0391);
		SetPlayerInterior(playerid, 0); SetPlayerVirtualWorld(playerid, 999);
		
		PlayerInfo[playerid][E_CHARACTER_OFFJAILED] = false; 
		PlayerInfo[playerid][E_CHARACTER_ADMINJAILED] = true; 
		SaveCharacter(playerid);
	}
	
	SetPlayerFightingStyle(playerid, PlayerInfo[playerid][E_CHARACTER_FIGHTSTYLE]);
	format(PlayerInfo[playerid][E_CHARACTER_ACTIVEIP], 60, "%s", ReturnIP(playerid)); 

	/*new str[1024];
    format(str, sizeof(str), "%s%s", IsPlayerStreetName(playerid), PlayerInfo[playerid][E_CHARACTER_STREETNAME]);
    SetPlayerName(playerid, str);*/

	UpdateTabListForOthers(playerid);
	UpdateTabListForPlayer(playerid);

	KillTimer(cameraTimer[playerid]);
	SetCameraBehindPlayer(playerid); 

	TogglePlayerControllable(playerid, true);

	if(PlayerInfo[playerid][E_CHARACTER_AOE] == 0)
	{
		CreatePlayerToy(playerid);
	}
	LoadPlayerToys(playerid);
	
	return 1;
}

public OnPlayerRequestClass(playerid, classid)
{
	if (AccountInfo[playerid][E_MASTERS_LOGGED] == false)
	{
		TogglePlayerSpectating(playerid, true);
		SetTimerEx("LoginTimer", 1000, false, "i", playerid);
		return 0;
	}
	else if(AccountInfo[playerid][E_MASTERS_LOGGED] == true)
	{
		SetSpawnInfo(playerid, 0, PlayerInfo[playerid][E_CHARACTER_LASTSKIN], PlayerInfo[playerid][E_CHARACTER_LASTPOS][0], PlayerInfo[playerid][E_CHARACTER_LASTPOS][1], PlayerInfo[playerid][E_CHARACTER_LASTPOS][2], 0, 0, 0, 0, 0, 0, 0);
		SpawnPlayer(playerid);
		return 0;
	}
	else return 0;
}

public OnVehicleDeath(vehicleid, killerid)
{
	new Float: vehicle_health;
	GetVehicleHealth(vehicleid, vehicle_health); 
	TotalledCheck();

	printf("[DEBUG] Vehicle ID: %i (%s) (Health: %.2f) destroyed by %s", vehicleid, ReturnVehicleName(vehicleid), vehicle_health, ReturnSettingsName(killerid, killerid)); 
		
	foreach(new i : Player) if(PlayerInfo[i][E_CHARACTER_DBID] == VehicleInfo[vehicleid][E_VEHICLE_OWNERDBID])
	{
		SendClientMessageEx(i, COLOR_RED, "Your %s was destroyed.", ReturnVehicleName(vehicleid)); 
			
		PlayerInfo[i][E_CHARACTER_VEHICLESPAWNED] = false;
		PlayerInfo[i][E_CHARACTER_VEHICLESPAWN] = INVALID_VEHICLE_ID; 
	}
	else
	{
		new
			chanquery[128];
			
		mysql_format(ourConnection, chanquery, sizeof(chanquery), "UPDATE characters SET pVehicleSpawned = 0, pVehicleSpawnedID = %i WHERE char_dbid = %i", INVALID_VEHICLE_ID, VehicleInfo[vehicleid][E_VEHICLE_OWNERDBID]);
		mysql_pquery(ourConnection, chanquery); 
	}	
		
	return 1; 
}

public OnPlayerDeath(playerid, killerid, reason)
{
	PlayerInfo[playerid][E_CHARACTER_SPAWNED] = false;

	printf("Callback OnPlayerDeath called for player %s (ID: %i)", ReturnSettingsName(playerid, playerid), playerid); 

	if(killerid == INVALID_PLAYER_ID && reason >= 49)
	{
		if((gettime() - LastSpawn[playerid]) < 15)
		{
		    PlayerInfo[playerid][E_CHARACTER_HEALTH] = 100.0;

			SendClientMessage(playerid, COLOR_RED, "Died at spawn.[Just logged in]");

			SetPlayerPosEx(playerid, 2248.5664,-1260.5315,23.9566);
			SetPlayerVirtualWorld(playerid, 0);
			SetPlayerInterior(playerid, 0);
		}
		else
		{
		    if(reason == 49)
			{
				if(GetPlayerTeam(playerid) == PLAYER_STATE_ALIVE)
				{	
					CallLocalFunction("OnPlayerWounded", "ddd", playerid, killerid, reason); 
					return 0;
				}
				SendServerMessage(killerid, "You have been killed %s at %s.", ReturnSettingsName(playerid, playerid), ReturnLocationStreet(playerid));
				SendServerMessage(playerid, "You has been killed by %s at %s.", ReturnSettingsName(killerid, killerid), ReturnLocationStreet(playerid));
			}
			else
			{
				if(killerid == INVALID_PLAYER_ID)
				{
					SendServerMessage(playerid, "You has been killed by unknown at %s.", ReturnSettingsName(killerid, killerid), ReturnLocationStreet(playerid));
				}
				else
				{
					SendServerMessage(killerid, "You have been killed %s at %s.", ReturnSettingsName(playerid, playerid), ReturnLocationStreet(playerid));
					SendServerMessage(playerid, "You has been killed by %s at %s.", ReturnSettingsName(killerid, killerid), ReturnLocationStreet(playerid));
				}
				PlayerInfo[playerid][E_CHARACTER_DIEUNKNOWN] = true;
			}
		}
	}
	PlayerInfo[playerid][E_CHARACTER_COURT] = 0;
	PlayerInfo[playerid][E_CHARACTER_HAVEBALL] = 0;
    PlayerInfo[playerid][E_CHARACTER_ANIMBALL] = 0;
	PlayerInfo[playerid][E_CHARACTER_COURTTEAM] = 0;
    if(PlayerInfo[playerid][E_CHARACTER_HAVEBALL]) CourtInfo[PlayerInfo[playerid][E_CHARACTER_COURT]][E_BALLER] = 999;
	
	//SetTimerEx("SetPlayersSpawn", 2100, false, "i", playerid); 
	return 1; 
}	


public OnPlayerTakeDamage(playerid, issuerid, Float:amount, weaponid, bodypart)
{
	switch(weaponid)
	{
		case 0:
		{
			amount = 2.0;
		}
		//Baseball bat
		case 4:
		{
			if (PlayerInfo[issuerid][E_CHARACTER_WEAPONTYPE] == 1)
			{
				amount = 4.0;
			}
			if (PlayerInfo[issuerid][E_CHARACTER_WEAPONTYPE] == 2)
			{
				amount = 4.0;
			}
			if (PlayerInfo[issuerid][E_CHARACTER_WEAPONTYPE] == 3)
			{
				amount = 5.0;
			}
		}
		//Knife
		case 5:
		{
			if (PlayerInfo[issuerid][E_CHARACTER_WEAPONTYPE] == 1)
			{
				
				amount = 6.0;
			}
			if (PlayerInfo[issuerid][E_CHARACTER_WEAPONTYPE] == 2)
			{
				amount = 6.0;
			}
			if (PlayerInfo[issuerid][E_CHARACTER_WEAPONTYPE] == 3)
			{
				amount = 5.0;
			}
		}
		//Colt
		case 22:
		{
			if (PlayerInfo[issuerid][E_CHARACTER_WEAPONTYPE] == 1)
			{
				switch(bodypart)
				{
					case BODY_PART_CHEST:
					{
						amount = 10.0;
					}
					case BODY_PART_GROIN:
					{
						amount = 6.0;
					}
					case BODY_PART_LEFT_ARM:
					{
						amount = 6.0;
					}
					case BODY_PART_RIGHT_ARM:
					{
						amount = 6.0;
					}
					case BODY_PART_LEFT_LEG:
					{
						amount = 5.0;
					}
					case BODY_PART_RIGHT_LEG:
					{
						amount = 5.0;
					}
					case BODY_PART_HEAD:
					{
						amount = 50.0;
					}
				}
			}
			if (PlayerInfo[issuerid][E_CHARACTER_WEAPONTYPE] == 2)
			{
				switch(bodypart)
				{
					case BODY_PART_CHEST:
					{
						amount = 10.0;
					}
					case BODY_PART_GROIN:
					{
						amount = 7.0;
					}
					case BODY_PART_LEFT_ARM:
					{
						amount = 7.0;
					}
					case BODY_PART_RIGHT_ARM:
					{
						amount = 7.0;
					}
					case BODY_PART_LEFT_LEG:
					{
						amount = 6.0;
					}
					case BODY_PART_RIGHT_LEG:
					{
						amount = 6.0;
					}
					case BODY_PART_HEAD:
					{
						amount = 50.0;
					}
				}
			}
			if (PlayerInfo[issuerid][E_CHARACTER_WEAPONTYPE] == 3)
			{
				switch(bodypart)
				{
					case BODY_PART_CHEST:
					{
						amount = 10.0;
					}
					case BODY_PART_GROIN:
					{
						amount = 7.0;
					}
					case BODY_PART_LEFT_ARM:
					{
						amount = 7.0;
					}
					case BODY_PART_RIGHT_ARM:
					{
						amount = 7.0;
					}
					case BODY_PART_LEFT_LEG:
					{
						amount = 6.0;
					}
					case BODY_PART_RIGHT_LEG:
					{
						amount = 6.0;
					}
					case BODY_PART_HEAD:
					{
						amount = 50.0;
					}
				}
			}
		}
		//Silence
	    case 23:
		{
			if (PlayerInfo[issuerid][E_CHARACTER_WEAPONTYPE] == 1)
			{
				switch(bodypart)
				{
					case BODY_PART_CHEST:
					{
						amount = 10.0;
					}
					case BODY_PART_GROIN:
					{
						amount = 7.0;
					}
					case BODY_PART_LEFT_ARM:
					{
						amount = 7.0;
					}
					case BODY_PART_RIGHT_ARM:
					{
						amount = 7.0;
					}
					case BODY_PART_LEFT_LEG:
					{
						amount = 6.0;
					}
					case BODY_PART_RIGHT_LEG:
					{
						amount = 6.0;
					}
					case BODY_PART_HEAD:
					{
						amount = 50.0;
					}
				}
			}
			if (PlayerInfo[issuerid][E_CHARACTER_WEAPONTYPE] == 2)
			{
				switch(bodypart)
				{
					case BODY_PART_CHEST:
					{
						amount = 10.0;
					}
					case BODY_PART_GROIN:
					{
						amount = 7.0;
					}
					case BODY_PART_LEFT_ARM:
					{
						amount = 7.0;
					}
					case BODY_PART_RIGHT_ARM:
					{
						amount = 7.0;
					}
					case BODY_PART_LEFT_LEG:
					{
						amount = 6.0;
					}
					case BODY_PART_RIGHT_LEG:
					{
						amount = 6.0;
					}
					case BODY_PART_HEAD:
					{
						amount = 50.0;
					}
				}
			}
			if (PlayerInfo[issuerid][E_CHARACTER_WEAPONTYPE] == 3)
			{
				switch(bodypart)
				{
					case BODY_PART_CHEST:
					{
						amount = 10.0;
					}
					case BODY_PART_GROIN:
					{
						amount = 7.0;
					}
					case BODY_PART_LEFT_ARM:
					{
						amount = 7.0;
					}
					case BODY_PART_RIGHT_ARM:
					{
						amount = 7.0;
					}
					case BODY_PART_LEFT_LEG:
					{
						amount = 6.0;
					}
					case BODY_PART_RIGHT_LEG:
					{
						amount = 6.0;
					}
					case BODY_PART_HEAD:
					{
						amount = 50.0;
					}
				}
			}
		}
		//Deagle
		case 24:
		{
			if (PlayerInfo[issuerid][E_CHARACTER_WEAPONTYPE] == 1)
			{
				switch(bodypart)
				{
					case BODY_PART_CHEST:
					{
						amount = 10.0;
					}
					case BODY_PART_GROIN:
					{
						amount = 7.0;
					}
					case BODY_PART_LEFT_ARM:
					{
						amount = 7.0;
					}
					case BODY_PART_RIGHT_ARM:
					{
						amount = 7.0;
					}
					case BODY_PART_LEFT_LEG:
					{
						amount = 6.0;
					}
					case BODY_PART_RIGHT_LEG:
					{
						amount = 6.0;
					}
					case BODY_PART_HEAD:
					{
						amount = 50.0;
					}
				}
			}
			if (PlayerInfo[issuerid][E_CHARACTER_WEAPONTYPE] == 2)
			{
				switch(bodypart)
				{
					case BODY_PART_CHEST:
					{
						amount = 10.0;
					}
					case BODY_PART_GROIN:
					{
						amount = 7.0;
					}
					case BODY_PART_LEFT_ARM:
					{
						amount = 7.0;
					}
					case BODY_PART_RIGHT_ARM:
					{
						amount = 7.0;
					}
					case BODY_PART_LEFT_LEG:
					{
						amount = 6.0;
					}
					case BODY_PART_RIGHT_LEG:
					{
						amount = 6.0;
					}
					case BODY_PART_HEAD:
					{
						amount = 50.0;
					}
				}
			}
			if (PlayerInfo[issuerid][E_CHARACTER_WEAPONTYPE] == 3)
			{
				switch(bodypart)
				{
					case BODY_PART_CHEST:
					{
						amount = 10.0;
					}
					case BODY_PART_GROIN:
					{
						amount = 7.0;
					}
					case BODY_PART_LEFT_ARM:
					{
						amount = 7.0;
					}
					case BODY_PART_RIGHT_ARM:
					{
						amount = 7.0;
					}
					case BODY_PART_LEFT_LEG:
					{
						amount = 6.0;
					}
					case BODY_PART_RIGHT_LEG:
					{
						amount = 6.0;
					}
					case BODY_PART_HEAD:
					{
						amount = 50.0;
					}
				}
			}
		}
		//Uzi
		case 28:
		{
			if (PlayerInfo[issuerid][E_CHARACTER_WEAPONTYPE] == 1)
			{
				switch(bodypart)
				{
					case BODY_PART_CHEST:
					{
						amount = 12.0;
					}
					case BODY_PART_GROIN:
					{
						amount = 8.0;
					}
					case BODY_PART_LEFT_ARM:
					{
						amount = 6.0;
					}
					case BODY_PART_RIGHT_ARM:
					{
						amount = 6.0;
					}
					case BODY_PART_LEFT_LEG:
					{
						amount = 5.0;
					}
					case BODY_PART_RIGHT_LEG:
					{
						amount = 5.0;
					}
					case BODY_PART_HEAD:
					{
						amount = 30.0;
					}
				}
			}
			if (PlayerInfo[issuerid][E_CHARACTER_WEAPONTYPE] == 2)
			{
				switch(bodypart)
				{
					case BODY_PART_CHEST:
					{
						amount = 13.0;
					}
					case BODY_PART_GROIN:
					{
						amount = 7.0;
					}
					case BODY_PART_LEFT_ARM:
					{
						amount = 8.0;
					}
					case BODY_PART_RIGHT_ARM:
					{
						amount = 8.0;
					}
					case BODY_PART_LEFT_LEG:
					{
						amount = 6.0;
					}
					case BODY_PART_RIGHT_LEG:
					{
						amount = 6.0;
					}
					case BODY_PART_HEAD:
					{
						amount = 30.0;
					}
				}
			}
			if (PlayerInfo[issuerid][E_CHARACTER_WEAPONTYPE] == 3)
			{
				switch(bodypart)
				{
					case BODY_PART_CHEST:
					{
						amount = 13.0;
					}
					case BODY_PART_GROIN:
					{
						amount = 7.0;
					}
					case BODY_PART_LEFT_ARM:
					{
						amount = 8.0;
					}
					case BODY_PART_RIGHT_ARM:
					{
						amount = 8.0;
					}
					case BODY_PART_LEFT_LEG:
					{
						amount = 6.0;
					}
					case BODY_PART_RIGHT_LEG:
					{
						amount = 6.0;
					}
					case BODY_PART_HEAD:
					{
						amount = 30.0;
					}
				}
			}
		}
		//TEC9
		case 32:
		{
			if (PlayerInfo[issuerid][E_CHARACTER_WEAPONTYPE] == 1)
			{
				switch(bodypart)
				{
					case BODY_PART_CHEST:
					{
						amount = 13.0;
					}
					case BODY_PART_GROIN:
					{
						amount = 7.0;
					}
					case BODY_PART_LEFT_ARM:
					{
						amount = 8.0;
					}
					case BODY_PART_RIGHT_ARM:
					{
						amount = 8.0;
					}
					case BODY_PART_LEFT_LEG:
					{
						amount = 6.0;
					}
					case BODY_PART_RIGHT_LEG:
					{
						amount = 6.0;
					}
					case BODY_PART_HEAD:
					{
						amount = 30.0;
					}
				}
			}
			if (PlayerInfo[issuerid][E_CHARACTER_WEAPONTYPE] == 2)
			{
				switch(bodypart)
				{
					case BODY_PART_CHEST:
					{
						amount = 13.0;
					}
					case BODY_PART_GROIN:
					{
						amount = 7.0;
					}
					case BODY_PART_LEFT_ARM:
					{
						amount = 8.0;
					}
					case BODY_PART_RIGHT_ARM:
					{
						amount = 8.0;
					}
					case BODY_PART_LEFT_LEG:
					{
						amount = 6.0;
					}
					case BODY_PART_RIGHT_LEG:
					{
						amount = 6.0;
					}
					case BODY_PART_HEAD:
					{
						amount = 30.0;
					}
				}
			}
			if (PlayerInfo[issuerid][E_CHARACTER_WEAPONTYPE] == 3)
			{
				switch(bodypart)
				{
					case BODY_PART_CHEST:
					{
						amount = 13.0;
					}
					case BODY_PART_GROIN:
					{
						amount = 7.0;
					}
					case BODY_PART_LEFT_ARM:
					{
						amount = 8.0;
					}
					case BODY_PART_RIGHT_ARM:
					{
						amount = 8.0;
					}
					case BODY_PART_LEFT_LEG:
					{
						amount = 6.0;
					}
					case BODY_PART_RIGHT_LEG:
					{
						amount = 6.0;
					}
					case BODY_PART_HEAD:
					{
						amount = 30.0;
					}
				}
			}
		}
		//MP5
		case 29:
		{
			if (PlayerInfo[issuerid][E_CHARACTER_WEAPONTYPE] == 1)
			{
				switch(bodypart)
				{
					case BODY_PART_CHEST:
					{
						amount = 13.0;
					}
					case BODY_PART_GROIN:
					{
						amount = 7.0;
					}
					case BODY_PART_LEFT_ARM:
					{
						amount = 8.0;
					}
					case BODY_PART_RIGHT_ARM:
					{
						amount = 8.0;
					}
					case BODY_PART_LEFT_LEG:
					{
						amount = 6.0;
					}
					case BODY_PART_RIGHT_LEG:
					{
						amount = 6.0;
					}
					case BODY_PART_HEAD:
					{
						amount = 30.0;
					}
				}
			}
			if (PlayerInfo[issuerid][E_CHARACTER_WEAPONTYPE] == 2)
			{
				switch(bodypart)
				{
					case BODY_PART_CHEST:
					{
						amount = 13.0;
					}
					case BODY_PART_GROIN:
					{
						amount = 7.0;
					}
					case BODY_PART_LEFT_ARM:
					{
						amount = 8.0;
					}
					case BODY_PART_RIGHT_ARM:
					{
						amount = 8.0;
					}
					case BODY_PART_LEFT_LEG:
					{
						amount = 6.0;
					}
					case BODY_PART_RIGHT_LEG:
					{
						amount = 6.0;
					}
					case BODY_PART_HEAD:
					{
						amount = 30.0;
					}
				}
			}
			if (PlayerInfo[issuerid][E_CHARACTER_WEAPONTYPE] == 3)
			{
				switch(bodypart)
				{
					case BODY_PART_CHEST:
					{
						amount = 13.0;
					}
					case BODY_PART_GROIN:
					{
						amount = 7.0;
					}
					case BODY_PART_LEFT_ARM:
					{
						amount = 8.0;
					}
					case BODY_PART_RIGHT_ARM:
					{
						amount = 8.0;
					}
					case BODY_PART_LEFT_LEG:
					{
						amount = 6.0;
					}
					case BODY_PART_RIGHT_LEG:
					{
						amount = 6.0;
					}
					case BODY_PART_HEAD:
					{
						amount = 30.0;
					}
				}
			}
		}
	}

	if(issuerid != INVALID_PLAYER_ID)
	{
		new
			Float:health
		;
		
		PlayerInfo[playerid][E_CHARACTER_LASTDAMAGE] = gettime();
		GetPlayerHealth(playerid, health); 
		
		if(GetPlayerTeam(playerid) != PLAYER_STATE_ALIVE && PlayerInfo[playerid][E_CHARACTER_DEATHFIX])
			SetPlayerHealthEx(playerid, health); 
		
		if(GetPlayerTeam(playerid) == PLAYER_STATE_ALIVE)
		{
			SetPlayerHealthEx(playerid, health - amount); 
			CallbackDamages(playerid, issuerid, bodypart, weaponid, amount); 
		}
		
		if(health - amount <= 4)
		{
			if(GetPlayerTeam(playerid) == PLAYER_STATE_ALIVE)
			{	
				CallLocalFunction("OnPlayerWounded", "ddd", playerid, issuerid, weaponid); 
				return 0;
			}
			
			return 0;
		}
		
		if(GetPlayerTeam(playerid) == PLAYER_STATE_WOUNDED)
		{
			if(!PlayerInfo[playerid][E_CHARACTER_DEATHFIX])
			{				
				CallLocalFunction("OnPlayerDead", "dddd", playerid, issuerid, weaponid, 1);
				return 0;
			}
			
			return 0;
		}
		
		if(GetPlayerTeam(playerid) != PLAYER_STATE_ALIVE)
		{
			SetPlayerHealthEx(playerid, health);
			return 0;
		}
	}
	return 1;
}

public OnPlayerWeaponShot(playerid, weaponid, hittype, hitid, Float:fX, Float:fY, Float:fZ)
{
	if(hittype != BULLET_HIT_TYPE_NONE) // Bullet Crashing uses just this hittype
    {
        if(!(-1000.0 <= fX <= 1000.0) || !(-1000.0 <= fY <= 1000.0) || !(-1000.0 <= fZ <= 1000.0) )
        {
            KickEx(playerid);
            return false;
        }
    }

	if(hittype == BULLET_HIT_TYPE_PLAYER) //Death system; 
	{	
		if(GetPlayerTeam(hitid) == PLAYER_STATE_WOUNDED && !PlayerInfo[hitid][E_CHARACTER_DEATHFIX])
		{	
			CallLocalFunction("OnPlayerDead", "ddd", hitid, playerid, weaponid);
			return 0;
		} 
		else if(GetPlayerTeam(hitid) != PLAYER_STATE_ALIVE)
			return 0; 	
	}
	
	if(GetPlayerWeapon(playerid) == 22)
	{
		new tstr[128];
		if(Inventory_Count(playerid, "9mm"))
		{
			Inventory_Remove(playerid, "9mm", 1);
			format(tstr, sizeof(tstr), "%d", Inventory_Count(playerid, "9mm"));
			PlayerTextDrawSetString(playerid, WeaponAmmo[playerid], tstr);
			PlayerTextDrawShow(playerid, WeaponAmmo[playerid]);
		}
		else
		{
			PlayerInfo[playerid][E_CHARACTER_EQUIPITEMS] = INVENTORY_NONE;
			ResetPlayerWeapons(playerid);
			PlayerTextDrawHide(playerid, WeaponAmmo[playerid]);
		}
	}
	if(GetPlayerWeapon(playerid) == 24)
	{
		new tstr[128];
		if(Inventory_Count(playerid, "9mm"))
		{
			Inventory_Remove(playerid, "9mm", 1);
			format(tstr, sizeof(tstr), "%d", Inventory_Count(playerid, "9mm"));
			PlayerTextDrawSetString(playerid, WeaponAmmo[playerid], tstr);
			PlayerTextDrawShow(playerid, WeaponAmmo[playerid]);
		}
		else
		{
			PlayerInfo[playerid][E_CHARACTER_EQUIPITEMS] = INVENTORY_NONE;
			ResetPlayerWeapons(playerid);
			PlayerTextDrawHide(playerid, WeaponAmmo[playerid]);
		}
	}

	if(GetPlayerWeapon(playerid) == 28)
	{
		new tstr[128];
		if(Inventory_Count(playerid, "9x19mm"))
		{
			Inventory_Remove(playerid, "9x19mm", 1);
			format(tstr, sizeof(tstr), "%d", Inventory_Count(playerid, "9x19mm"));
			PlayerTextDrawSetString(playerid, WeaponAmmo[playerid], tstr);
			PlayerTextDrawShow(playerid, WeaponAmmo[playerid]);
		}
		else
		{
			PlayerInfo[playerid][E_CHARACTER_EQUIPITEMS] = INVENTORY_NONE;
			ResetPlayerWeapons(playerid);
			PlayerTextDrawHide(playerid, WeaponAmmo[playerid]);
		}
	}
	if(PlayerInfo[playerid][E_CHARACTER_POLICEGUN] && weaponid == 23)
	{
		SetPlayerArmedWeapon(playerid, 0); 
		
		ApplyAnimation(playerid, "SILENCED", "Silence_reload", 4.1, 0, 1, 1, 1, 1, 1);
		ApplyAnimation(playerid, "SILENCED", "Silence_reload", 4.1, 0, 1, 1, 1, 1, 1);
		
		SetTimerEx("OnTaserShoot", 1100, false, "i", playerid); 
	}
	
	if(hittype == BULLET_HIT_TYPE_PLAYER) //Taser system; 
	{
		if(PlayerInfo[playerid][E_CHARACTER_POLICEGUN] && weaponid == 23)
		{
			if(!IsPlayerNearPlayer(playerid, hitid, 15.0))
			{
				SendServerMessage(playerid, "You aren't close enough to hit %s with your taser.", ReturnSettingsName(hitid, hitid));
				return 0;
			}
			
			SetPlayerDrunkLevel(hitid, 4000); 
			TogglePlayerControllable(playerid, true);
			
			SendNearbyMessage(hitid, 20.0, COLOR_EMOTE, "* %s falls on the ground after being hit by %s's taser.", ReturnSettingsName(hitid, hitid), ReturnSettingsName(playerid, playerid)); 
			GameTextForPlayer(hitid, "~b~You Are Tasered", 2500, 3);
			
			SendServerMessage(hitid, "You were just hit by a taser. 10,000 volts go through your body.");
			SendServerMessage(playerid, "You hit %s with your taser!", ReturnSettingsName(hitid, hitid)); 
			
			ClearAnimations(playerid, 1);
			SetTimerEx("OnPlayerTasered", 1200, false, "i", hitid); 
			return 0;
		}
	}
	else if(hittype == BULLET_HIT_TYPE_PLAYER) //Taser system; 
	{
		if(PlayerInfo[playerid][E_CHARACTER_POLICEGUN] && weaponid == 25)
		{
			if(!IsPlayerNearPlayer(playerid, hitid, 15.0))
			{
				SendServerMessage(playerid, "You aren't close enough to hit %s with your riot gun.", ReturnSettingsName(hitid, hitid));
				return 0;
			}
			
			TogglePlayerControllable(playerid, true);
			
			SendNearbyMessage(hitid, 20.0, COLOR_EMOTE, "* %s falls on the ground after being hit by %s's riot gun.", ReturnSettingsName(hitid, hitid), ReturnSettingsName(playerid, playerid)); 
			
			SendServerMessage(hitid, "You were just hit by a riot gun. rubber bullet go through your body.");
			SendServerMessage(playerid, "You hit %s with your taser!", ReturnSettingsName(hitid, hitid)); 
			
			ClearAnimations(playerid, 1);
			SetTimerEx("OnPlayerRubber", 1200, false, "i", hitid); 
			return 0;
		}
	}

	if(IsPlayerInProperty(playerid) != -1)
	{
		new i = IsPlayerInProperty(playerid);

		if((gettime() - PropertyInfo[i][E_PROPERTY_SHOOTINGTIMER]) >= 180)
		{
			PropertyInfo[i][E_PROPERTY_SHOOTINGTIMER] = gettime();
			
			new street[60];
			Get2DPosZone(PropertyInfo[i][E_PROPERTY_ENTRANCEPOS][0], PropertyInfo[i][E_PROPERTY_ENTRANCEPOS][1], street, MAX_ZONE_NAME);

			foreach (new x : Player)
			{
				if(IsPlayerInProperty(x) == i) continue;

				if(IsPlayerInRangeOfPoint(x, 30.0, PropertyInfo[i][E_PROPERTY_ENTRANCEPOS][0], PropertyInfo[i][E_PROPERTY_ENTRANCEPOS][1], PropertyInfo[i][E_PROPERTY_ENTRANCEPOS][2]))
				{
					SendClientMessageEx(x, COLOR_EMOTE, "* [%s %s] A gun goes off inside and the shot being fired is heard.", PropertyInfo[i][E_PROPERTY_ADDRESS], street);
				}
			}
		}
	}
	if(IsPlayerInBusiness(playerid) != -1)
	{
		new i = IsPlayerInBusiness(playerid);

		if((gettime() - BusinessInfo[i][E_BUSINESS_SHOOTINGTIMER]) >= 180)
		{
			BusinessInfo[i][E_BUSINESS_SHOOTINGTIMER] = gettime();
			
			foreach (new x : Player)
			{
				if(IsPlayerInBusiness(x) == i) continue;

				if(IsPlayerInRangeOfPoint(x, 30.0, BusinessInfo[i][E_BUSINESS_ENTRANCEPOS][0], BusinessInfo[i][E_BUSINESS_ENTRANCEPOS][1], BusinessInfo[i][E_BUSINESS_ENTRANCEPOS][2]))
				{
					SendClientMessageEx(x, COLOR_PURPLE, "* [%s] A gun goes off inside and the shot being fired is heard.", BusinessInfo[i][E_BUSINESS_NAME]);
				}
			}
		}
	}
	return 1;
}

public OnPlayerGiveDamage(playerid, damagedid, Float:amount, weaponid, bodypart)
{
	switch(weaponid)
	{
		case 0:
		{
			amount = 2.0;
		}
		//Baseball bat
		case 4:
		{
			if (PlayerInfo[playerid][E_CHARACTER_WEAPONTYPE] == 1)
			{
				amount = 4.0;
			}
			if (PlayerInfo[playerid][E_CHARACTER_WEAPONTYPE] == 2)
			{
				amount = 4.0;
			}
			if (PlayerInfo[playerid][E_CHARACTER_WEAPONTYPE] == 3)
			{
				amount = 5.0;
			}
		}
		//Knife
		case 5:
		{
			if (PlayerInfo[playerid][E_CHARACTER_WEAPONTYPE] == 1)
			{
				amount = 6.0;
			}
			if (PlayerInfo[playerid][E_CHARACTER_WEAPONTYPE] == 2)
			{
				amount = 6.0;
			}
			if (PlayerInfo[playerid][E_CHARACTER_WEAPONTYPE] == 3)
			{
				amount = 5.0;
			}
		}
		//Colt
		case 22:
		{
			if (PlayerInfo[playerid][E_CHARACTER_WEAPONTYPE] == 1)
			{
				switch(bodypart)
				{
					case BODY_PART_CHEST:
					{
						amount = 10.0;
					}
					case BODY_PART_GROIN:
					{
						amount = 6.0;
					}
					case BODY_PART_LEFT_ARM:
					{
						amount = 6.0;
					}
					case BODY_PART_RIGHT_ARM:
					{
						amount = 6.0;
					}
					case BODY_PART_LEFT_LEG:
					{
						amount = 5.0;
					}
					case BODY_PART_RIGHT_LEG:
					{
						amount = 5.0;
					}
					case BODY_PART_HEAD:
					{
						amount = 50.0;
					}
				}
			}
			if (PlayerInfo[playerid][E_CHARACTER_WEAPONTYPE] == 2)
			{
				switch(bodypart)
				{
					case BODY_PART_CHEST:
					{
						amount = 10.0;
					}
					case BODY_PART_GROIN:
					{
						amount = 7.0;
					}
					case BODY_PART_LEFT_ARM:
					{
						amount = 7.0;
					}
					case BODY_PART_RIGHT_ARM:
					{
						amount = 7.0;
					}
					case BODY_PART_LEFT_LEG:
					{
						amount = 6.0;
					}
					case BODY_PART_RIGHT_LEG:
					{
						amount = 6.0;
					}
					case BODY_PART_HEAD:
					{
						amount = 50.0;
					}
				}
			}
			if (PlayerInfo[playerid][E_CHARACTER_WEAPONTYPE] == 3)
			{
				switch(bodypart)
				{
					case BODY_PART_CHEST:
					{
						amount = 10.0;
					}
					case BODY_PART_GROIN:
					{
						amount = 7.0;
					}
					case BODY_PART_LEFT_ARM:
					{
						amount = 7.0;
					}
					case BODY_PART_RIGHT_ARM:
					{
						amount = 7.0;
					}
					case BODY_PART_LEFT_LEG:
					{
						amount = 6.0;
					}
					case BODY_PART_RIGHT_LEG:
					{
						amount = 6.0;
					}
					case BODY_PART_HEAD:
					{
						amount = 50.0;
					}
				}
			}
		}
		//Silence
	    case 23:
		{
			if (PlayerInfo[playerid][E_CHARACTER_WEAPONTYPE] == 1)
			{
				switch(bodypart)
				{
					case BODY_PART_CHEST:
					{
						amount = 10.0;
					}
					case BODY_PART_GROIN:
					{
						amount = 7.0;
					}
					case BODY_PART_LEFT_ARM:
					{
						amount = 7.0;
					}
					case BODY_PART_RIGHT_ARM:
					{
						amount = 7.0;
					}
					case BODY_PART_LEFT_LEG:
					{
						amount = 6.0;
					}
					case BODY_PART_RIGHT_LEG:
					{
						amount = 6.0;
					}
					case BODY_PART_HEAD:
					{
						amount = 50.0;
					}
				}
			}
			if (PlayerInfo[playerid][E_CHARACTER_WEAPONTYPE] == 2)
			{
				switch(bodypart)
				{
					case BODY_PART_CHEST:
					{
						amount = 10.0;
					}
					case BODY_PART_GROIN:
					{
						amount = 7.0;
					}
					case BODY_PART_LEFT_ARM:
					{
						amount = 7.0;
					}
					case BODY_PART_RIGHT_ARM:
					{
						amount = 7.0;
					}
					case BODY_PART_LEFT_LEG:
					{
						amount = 6.0;
					}
					case BODY_PART_RIGHT_LEG:
					{
						amount = 6.0;
					}
					case BODY_PART_HEAD:
					{
						amount = 50.0;
					}
				}
			}
			if (PlayerInfo[playerid][E_CHARACTER_WEAPONTYPE] == 3)
			{
				switch(bodypart)
				{
					case BODY_PART_CHEST:
					{
						amount = 10.0;
					}
					case BODY_PART_GROIN:
					{
						amount = 7.0;
					}
					case BODY_PART_LEFT_ARM:
					{
						amount = 7.0;
					}
					case BODY_PART_RIGHT_ARM:
					{
						amount = 7.0;
					}
					case BODY_PART_LEFT_LEG:
					{
						amount = 6.0;
					}
					case BODY_PART_RIGHT_LEG:
					{
						amount = 6.0;
					}
					case BODY_PART_HEAD:
					{
						amount = 50.0;
					}
				}
			}
		}
		//Deagle
		case 24:
		{
			if (PlayerInfo[playerid][E_CHARACTER_WEAPONTYPE] == 1)
			{
				switch(bodypart)
				{
					case BODY_PART_CHEST:
					{
						amount = 10.0;
					}
					case BODY_PART_GROIN:
					{
						amount = 7.0;
					}
					case BODY_PART_LEFT_ARM:
					{
						amount = 7.0;
					}
					case BODY_PART_RIGHT_ARM:
					{
						amount = 7.0;
					}
					case BODY_PART_LEFT_LEG:
					{
						amount = 6.0;
					}
					case BODY_PART_RIGHT_LEG:
					{
						amount = 6.0;
					}
					case BODY_PART_HEAD:
					{
						amount = 50.0;
					}
				}
			}
			if (PlayerInfo[playerid][E_CHARACTER_WEAPONTYPE] == 2)
			{
				switch(bodypart)
				{
					case BODY_PART_CHEST:
					{
						amount = 10.0;
					}
					case BODY_PART_GROIN:
					{
						amount = 7.0;
					}
					case BODY_PART_LEFT_ARM:
					{
						amount = 7.0;
					}
					case BODY_PART_RIGHT_ARM:
					{
						amount = 7.0;
					}
					case BODY_PART_LEFT_LEG:
					{
						amount = 6.0;
					}
					case BODY_PART_RIGHT_LEG:
					{
						amount = 6.0;
					}
					case BODY_PART_HEAD:
					{
						amount = 50.0;
					}
				}
			}
			if (PlayerInfo[playerid][E_CHARACTER_WEAPONTYPE] == 3)
			{
				switch(bodypart)
				{
					case BODY_PART_CHEST:
					{
						amount = 10.0;
					}
					case BODY_PART_GROIN:
					{
						amount = 7.0;
					}
					case BODY_PART_LEFT_ARM:
					{
						amount = 7.0;
					}
					case BODY_PART_RIGHT_ARM:
					{
						amount = 7.0;
					}
					case BODY_PART_LEFT_LEG:
					{
						amount = 6.0;
					}
					case BODY_PART_RIGHT_LEG:
					{
						amount = 6.0;
					}
					case BODY_PART_HEAD:
					{
						amount = 50.0;
					}
				}
			}
		}
		//Uzi
		case 28:
		{
			if (PlayerInfo[playerid][E_CHARACTER_WEAPONTYPE] == 1)
			{
				switch(bodypart)
				{
					case BODY_PART_CHEST:
					{
						amount = 12.0;
					}
					case BODY_PART_GROIN:
					{
						amount = 8.0;
					}
					case BODY_PART_LEFT_ARM:
					{
						amount = 6.0;
					}
					case BODY_PART_RIGHT_ARM:
					{
						amount = 6.0;
					}
					case BODY_PART_LEFT_LEG:
					{
						amount = 5.0;
					}
					case BODY_PART_RIGHT_LEG:
					{
						amount = 5.0;
					}
					case BODY_PART_HEAD:
					{
						amount = 30.0;
					}
				}
			}
			if (PlayerInfo[playerid][E_CHARACTER_WEAPONTYPE] == 2)
			{
				switch(bodypart)
				{
					case BODY_PART_CHEST:
					{
						amount = 13.0;
					}
					case BODY_PART_GROIN:
					{
						amount = 7.0;
					}
					case BODY_PART_LEFT_ARM:
					{
						amount = 8.0;
					}
					case BODY_PART_RIGHT_ARM:
					{
						amount = 8.0;
					}
					case BODY_PART_LEFT_LEG:
					{
						amount = 6.0;
					}
					case BODY_PART_RIGHT_LEG:
					{
						amount = 6.0;
					}
					case BODY_PART_HEAD:
					{
						amount = 30.0;
					}
				}
			}
			if (PlayerInfo[playerid][E_CHARACTER_WEAPONTYPE] == 3)
			{
				switch(bodypart)
				{
					case BODY_PART_CHEST:
					{
						amount = 13.0;
					}
					case BODY_PART_GROIN:
					{
						amount = 7.0;
					}
					case BODY_PART_LEFT_ARM:
					{
						amount = 8.0;
					}
					case BODY_PART_RIGHT_ARM:
					{
						amount = 8.0;
					}
					case BODY_PART_LEFT_LEG:
					{
						amount = 6.0;
					}
					case BODY_PART_RIGHT_LEG:
					{
						amount = 6.0;
					}
					case BODY_PART_HEAD:
					{
						amount = 30.0;
					}
				}
			}
		}
		//TEC9
		case 32:
		{
			if (PlayerInfo[playerid][E_CHARACTER_WEAPONTYPE] == 1)
			{
				switch(bodypart)
				{
					case BODY_PART_CHEST:
					{
						amount = 13.0;
					}
					case BODY_PART_GROIN:
					{
						amount = 7.0;
					}
					case BODY_PART_LEFT_ARM:
					{
						amount = 8.0;
					}
					case BODY_PART_RIGHT_ARM:
					{
						amount = 8.0;
					}
					case BODY_PART_LEFT_LEG:
					{
						amount = 6.0;
					}
					case BODY_PART_RIGHT_LEG:
					{
						amount = 6.0;
					}
					case BODY_PART_HEAD:
					{
						amount = 30.0;
					}
				}
			}
			if (PlayerInfo[playerid][E_CHARACTER_WEAPONTYPE] == 2)
			{
				switch(bodypart)
				{
					case BODY_PART_CHEST:
					{
						amount = 13.0;
					}
					case BODY_PART_GROIN:
					{
						amount = 7.0;
					}
					case BODY_PART_LEFT_ARM:
					{
						amount = 8.0;
					}
					case BODY_PART_RIGHT_ARM:
					{
						amount = 8.0;
					}
					case BODY_PART_LEFT_LEG:
					{
						amount = 6.0;
					}
					case BODY_PART_RIGHT_LEG:
					{
						amount = 6.0;
					}
					case BODY_PART_HEAD:
					{
						amount = 30.0;
					}
				}
			}
			if (PlayerInfo[playerid][E_CHARACTER_WEAPONTYPE] == 3)
			{
				switch(bodypart)
				{
					case BODY_PART_CHEST:
					{
						amount = 13.0;
					}
					case BODY_PART_GROIN:
					{
						amount = 7.0;
					}
					case BODY_PART_LEFT_ARM:
					{
						amount = 8.0;
					}
					case BODY_PART_RIGHT_ARM:
					{
						amount = 8.0;
					}
					case BODY_PART_LEFT_LEG:
					{
						amount = 6.0;
					}
					case BODY_PART_RIGHT_LEG:
					{
						amount = 6.0;
					}
					case BODY_PART_HEAD:
					{
						amount = 30.0;
					}
				}
			}
		}
		//MP5
		case 29:
		{
			if (PlayerInfo[playerid][E_CHARACTER_WEAPONTYPE] == 1)
			{
				switch(bodypart)
				{
					case BODY_PART_CHEST:
					{
						amount = 13.0;
					}
					case BODY_PART_GROIN:
					{
						amount = 7.0;
					}
					case BODY_PART_LEFT_ARM:
					{
						amount = 8.0;
					}
					case BODY_PART_RIGHT_ARM:
					{
						amount = 8.0;
					}
					case BODY_PART_LEFT_LEG:
					{
						amount = 6.0;
					}
					case BODY_PART_RIGHT_LEG:
					{
						amount = 6.0;
					}
					case BODY_PART_HEAD:
					{
						amount = 30.0;
					}
				}
			}
			if (PlayerInfo[playerid][E_CHARACTER_WEAPONTYPE] == 2)
			{
				switch(bodypart)
				{
					case BODY_PART_CHEST:
					{
						amount = 13.0;
					}
					case BODY_PART_GROIN:
					{
						amount = 7.0;
					}
					case BODY_PART_LEFT_ARM:
					{
						amount = 8.0;
					}
					case BODY_PART_RIGHT_ARM:
					{
						amount = 8.0;
					}
					case BODY_PART_LEFT_LEG:
					{
						amount = 6.0;
					}
					case BODY_PART_RIGHT_LEG:
					{
						amount = 6.0;
					}
					case BODY_PART_HEAD:
					{
						amount = 30.0;
					}
				}
			}
			if (PlayerInfo[playerid][E_CHARACTER_WEAPONTYPE] == 3)
			{
				switch(bodypart)
				{
					case BODY_PART_CHEST:
					{
						amount = 13.0;
					}
					case BODY_PART_GROIN:
					{
						amount = 7.0;
					}
					case BODY_PART_LEFT_ARM:
					{
						amount = 8.0;
					}
					case BODY_PART_RIGHT_ARM:
					{
						amount = 8.0;
					}
					case BODY_PART_LEFT_LEG:
					{
						amount = 6.0;
					}
					case BODY_PART_RIGHT_LEG:
					{
						amount = 6.0;
					}
					case BODY_PART_HEAD:
					{
						amount = 30.0;
					}
				}
			}
		}
	}

	if(PlayerInfo[playerid][E_CHARACTER_TOGDMS] == false)
	{
		if(GetPlayerWeapon(playerid) > 21)
		{
			switch(bodypart)
			{
				case 3:
				{
					new string[128], victim[MAX_PLAYER_NAME];
					GetPlayerName(damagedid, victim, sizeof (victim));
					format(string, sizeof(string), "* You shot at %s on Torso and made him loose %.0f health.", victim, amount);
					SendClientMessageEx(playerid, COLOR_WHITE, string);
				}
				case 4:
				{
					new string[128], victim[MAX_PLAYER_NAME];
					GetPlayerName(damagedid, victim, sizeof (victim));
					format(string, sizeof(string), "* You shot at %s on Groin and made him loose %.0f health.", victim, amount);
					SendClientMessageEx(playerid, COLOR_WHITE, string);
				}
				case 5:
				{
					new string[128], victim[MAX_PLAYER_NAME];
					GetPlayerName(damagedid, victim, sizeof (victim));
					format(string, sizeof(string), "* You shot at %s on LeftArm and made him loose %.0f health.", victim, amount);
					SendClientMessageEx(playerid, COLOR_WHITE, string);
				}
				case 6:
				{
					new string[128], victim[MAX_PLAYER_NAME];
					GetPlayerName(damagedid, victim, sizeof (victim));
					format(string, sizeof(string), "* You shot at %s on RightArm and made him loose %.0f health.", victim, amount);
					SendClientMessageEx(playerid, COLOR_WHITE, string);
				}
				case 7:
				{
					new string[128], victim[MAX_PLAYER_NAME];
					GetPlayerName(damagedid, victim, sizeof (victim));
					format(string, sizeof(string), "* You shot at %s on LeftLeg and made him loose %.0f health.", victim, amount);
					SendClientMessageEx(playerid, COLOR_WHITE, string);
				}
				case 8:
				{
					new string[128], victim[MAX_PLAYER_NAME];
					GetPlayerName(damagedid, victim, sizeof (victim));
					format(string, sizeof(string), "* You shot at %s on RightLeg and made him loose %.0f health.", victim, amount);
					SendClientMessageEx(playerid, COLOR_WHITE, string);
				}
				case 9:
				{
					new string[128], victim[MAX_PLAYER_NAME];
					GetPlayerName(damagedid, victim, sizeof (victim));
					format(string, sizeof(string), "* You shot at %s on Head and made him loose %.0f health.", victim, amount);
					SendClientMessageEx(playerid, COLOR_WHITE, string);
				}
			}
		}	
	}
	return 1;
}

public OnPlayerSpawn(playerid)
{	
	Streamer_Update(playerid);

	LastSpawn[playerid] = gettime();
	
	if(PlayerInfo[playerid][E_CHARACTER_INJURED] == 1)
	{
		SetPlayerTeam(playerid, PLAYER_STATE_WOUNDED);
	}
	else if(PlayerInfo[playerid][E_CHARACTER_DEATH] == 1)
	{
		SetPlayerTeam(playerid, PLAYER_STATE_DEAD);
	}
	else
	{
		SetPlayerTeam(playerid, PLAYER_STATE_ALIVE);
	}

	SetPlayerSkillLevel(playerid, WEAPONSKILL_PISTOL, 250);
	SetPlayerSkillLevel(playerid, WEAPONSKILL_PISTOL_SILENCED, 250);
	SetPlayerSkillLevel(playerid, WEAPONSKILL_DESERT_EAGLE, 200);
	SetPlayerSkillLevel(playerid, WEAPONSKILL_SHOTGUN, 500);
	SetPlayerSkillLevel(playerid, WEAPONSKILL_SAWNOFF_SHOTGUN, 500);
	SetPlayerSkillLevel(playerid, WEAPONSKILL_SPAS12_SHOTGUN, 500);
	SetPlayerSkillLevel(playerid, WEAPONSKILL_MICRO_UZI, 50);
	SetPlayerSkillLevel(playerid, WEAPONSKILL_MP5, 250);
	SetPlayerSkillLevel(playerid, WEAPONSKILL_AK47, 300);
	SetPlayerSkillLevel(playerid, WEAPONSKILL_M4, 200);
	SetPlayerSkillLevel(playerid, WEAPONSKILL_SNIPERRIFLE, 300);
	
	SetPlayerHealthEx(playerid, PlayerInfo[playerid][E_CHARACTER_HEALTH]);
	SetPlayerArmourEx(playerid, PlayerInfo[playerid][E_CHARACTER_ARMOUR]);

	SetWeather(1);

	KillTimer(cameraTimer[playerid]);
	SetCameraBehindPlayer(playerid); 

	if(PlayerInfo[playerid][E_CHARACTER_ADMINJAILED] == true)
	{
		ClearAnimations(playerid); 
		
		SetPlayerPosEx(playerid, -10.5146,2337.2961,24.3034);
		SetPlayerInterior(playerid, 0); SetPlayerVirtualWorld(playerid, 1338);
		
		SendServerMessage(playerid, "You're currently admin jailed. You have %i minutes left.", PlayerInfo[playerid][E_CHARACTER_ADMINJAIL] / 60);
	}
	else if(PlayerInfo[playerid][E_CHARACTER_PRISONED] == true)
	{
		ClearAnimations(playerid); 
		
		SetPlayerInPrison(playerid);
		
		SendServerMessage(playerid, "You're currently prison. You have %i minutes left.", PlayerInfo[playerid][E_CHARACTER_PRISON] / 60);
	}
	else
	{
		if(PlayerInfo[playerid][E_CHARACTER_SPECTATE] != INVALID_PLAYER_ID)
		{
			SetPlayerPosEx(playerid, PlayerInfo[playerid][E_CHARACTER_LASTPOS][0], PlayerInfo[playerid][E_CHARACTER_LASTPOS][1], PlayerInfo[playerid][E_CHARACTER_LASTPOS][2]);
			PlayerInfo[playerid][E_CHARACTER_SPECTATE] = INVALID_PLAYER_ID;
		}
		if(PlayerInfo[playerid][E_CHARACTER_DIEUNKNOWN] == true)
		{
			SetPlayerHealthEx(playerid, 100);
			SetPlayerPosEx(playerid, 2032.9578,-1416.1289,16.9922);
			SetPlayerInterior(playerid, 0);
			SetPlayerVirtualWorld(playerid, 0);
			PlayerInfo[playerid][E_CHARACTER_DIEUNKNOWN] = false;
			SetPlayerTeam(playerid, PLAYER_STATE_ALIVE); 
		}
		else SetPlayersSpawn(playerid); 
	}
	
	PlayerInfo[playerid][E_CHARACTER_SPAWNED] = true;

	if(PlayerInfo[playerid][E_CHARACTER_TOGHUD] == false && PlayerInfo[playerid][E_CHARACTER_SPAWNED] == true)
	{
		PlayerTextDrawShow(playerid, Street[0][playerid]);
		PlayerTextDrawShow(playerid, Street[1][playerid]);
		p_Direction[playerid] = true;
	}

	if(!PlayerInfo[playerid][E_CHARACTER_TUTORIAL])
	{
		TogglePlayerSpectating(playerid, true);
		
		InterpolateCameraPos(playerid, 1413.479736, -1727.495483, 32.772384, 1551.484497, -1726.705932, 32.781917, 8000, 1);
        InterpolateCameraLookAt(playerid, 1415.520385, -1730.730590, 31.602050, 1548.272216, -1729.019531, 32.208690, 8000, 1);

		PlayerInfo[playerid][E_CHARACTER_TUTORIALSTEP] = 1;
		TogglePlayerControllable(playerid, false);
		SelectTextDraw(playerid, COLOR_YELLOW);
		ShowTutorial(playerid);
	}
	return 1;
}

public OnPlayerText(playerid, text[])
{
	SendPlayerChatText(playerid, text);

	PlayerInfo[playerid][E_CHARACTER_AFKPOS][0] = 0.0;
	PlayerInfo[playerid][E_CHARACTER_AFKPOS][1] = 0.0;
	PlayerInfo[playerid][E_CHARACTER_AFKPOS][2] = 0.0;
	return 0;
}

public OnPlayerUpdate(playerid)
{
	UpdateNametagsTick(playerid);

	if(PlayerInfo[playerid][E_CHARACTER_ADMINDUTY])
	{
		PauseAC(playerid);
	}
	
	if(GetPlayerMoney(playerid) > PlayerInfo[playerid][E_CHARACTER_MONEY])
		SetMoney(playerid, PlayerInfo[playerid][E_CHARACTER_MONEY]);

	new string[128];

	if(GetPlayerTeam(playerid) == PLAYER_STATE_WOUNDED)
	{
		format(string, sizeof(string), "(( Has been injured %d times, /damages %d for more information. ))", TotalPlayerDamages[playerid], playerid);
		SetPlayerChatBubble(playerid, string, COLOR_POINT, 30.0, 2500); 
		
		ShowBoxMessage(playerid, "Injury", 5);
		if(IsPlayerInAnyVehicle(playerid))
		{
			ApplyAnimation(playerid, "ped", "CAR_dead_LHS", 4.1, 0, 0, 0, 1, 0, 1);
		}
		else
		{
			ApplyAnimation(playerid, "WUZI", "CS_Dead_Guy", 4.1, 0, 1, 1, 1, 0, 1);	
		}	
	}
	else if(GetPlayerTeam(playerid) == PLAYER_STATE_DEAD)
	{
		SetPlayerChatBubble(playerid, "(( THIS PLAYER IS DEAD ))", COLOR_POINT, 30.0, 2500); 
	}
	
	if(!IsPlayerInAnyVehicle(playerid))
	{
		if(IsPlayerRunning(playerid))
		{
			if(PlayerInfo[playerid][E_CHARACTER_STAMINA] > 0)
			{
				if(!IsPlayerExhausted(playerid))
				{
					PlayerInfo[playerid][E_CHARACTER_STAMINA] -= 10;
				}

				if(PlayerInfo[playerid][E_CHARACTER_STAMINA] < 1)
				{
					SetTimerEx("SetPlayerExhausted", 4000, false, "ib", playerid, true);
				}
			}
		}
	}

	if(PlayerInfo[playerid][E_CHARACTER_SPAWNED] == true)
	{
		if(PlayerJump[playerid][JumpPressed])
		{
			if (gettime() - PlayerJump[playerid][JumpPressed] >= 5)
			{
				PlayerJump[playerid][JumpPressed] = 0;
				return 1;
			}
		
			if (GetPlayerAnimationIndex(playerid) == 1197 || GetPlayerAnimationIndex(playerid) == 1198)
			{
				PlayerJump[playerid][JumpAt] = gettime();
				PlayerJump[playerid][JumpPressed] = 0;
			}
		}
		
		if (PlayerJump[playerid][JumpAt])
		{
			if (GetPlayerAnimationIndex(playerid) == 1196)
			{
				if (PlayerJump[playerid][JumpCD] && gettime() - PlayerJump[playerid][JumpCD] < 5)
				{
					PauseAC(playerid);
					ClearAnimations(playerid);
					ApplyAnimation(playerid, "ped", "fall_collapse", 4.1, 0, 1, 1, 0, 0);
				}
				
				PlayerJump[playerid][JumpAt] = 0;
				PlayerJump[playerid][JumpCD] = gettime();
			}
		}
	}

	if(PlayerInfo[playerid][E_CHARACTER_SPAWNED] == true)
	{
		if(Inventory_Count(playerid, "Fabric Cargo") || Inventory_Count(playerid, "Steel Cargo") || Inventory_Count(playerid, "Woods Cargo") 
		|| Inventory_Count(playerid, "Foods Cargo") || Inventory_Count(playerid, "Clothes Cargo") || Inventory_Count(playerid, "Appliances Cargo")
		|| Inventory_Count(playerid, "Fish Cargo"))
		{
			if(PlayerInfo[playerid][E_CHARACTER_EQUIPITEMS] == INVENTORY_NONE)
			{
				PlayerInfo[playerid][E_CHARACTER_EQUIPITEMS] = CRATES;
				RemovePlayerAttachedObject(playerid, ATTACH_HAND);
				SetPlayerSpecialAction(playerid, SPECIAL_ACTION_CARRY);
				SetPlayerAttachedObject(playerid, ATTACH_CARGO, 2912, 1, -0.019, 0.713999, -0.076, 0, 87.1, -9.4, 1.0000, 1.0000, 1.0000);
			}
		}
		else if(Inventory_Count(playerid, "Woods"))
		{
			if(PlayerInfo[playerid][E_CHARACTER_EQUIPITEMS] == INVENTORY_NONE)
			{
				PlayerInfo[playerid][E_CHARACTER_EQUIPITEMS] = WOODS;
				RemovePlayerAttachedObject(playerid, ATTACH_HAND);
				SetPlayerSpecialAction(playerid, SPECIAL_ACTION_CARRY);
				SetPlayerAttachedObject(playerid, ATTACH_CARGO, 1463, 1, -0.019, 0.713999, -0.076, 0, 87.1, -9.4, 1.0000, 1.0000, 1.0000);
			}
		}
		else
		{
			if(PlayerInfo[playerid][E_CHARACTER_EQUIPITEMS] == CRATES || PlayerInfo[playerid][E_CHARACTER_EQUIPITEMS] == WOODS)
			{
				RemovePlayerAttachedObject(playerid, ATTACH_CARGO);
				RemovePlayerAttachedObject(playerid, ATTACH_HAND);
				SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
				PlayerInfo[playerid][E_CHARACTER_EQUIPITEMS] = INVENTORY_NONE;
			}
		}
	}

	if(PlayerInfo[playerid][E_CHARACTER_SPAWNED] == true)
	{
		new Float:rz;
		new p_PreviousDirection[8];

		strcat((p_PreviousDirection[0] = EOS, p_PreviousDirection), PlayerDirection[playerid]);

		if(IsPlayerInAnyVehicle(playerid)) 
		{
			GetVehicleZAngle(GetPlayerVehicleID(playerid), rz);
		}
		else 
		{
			GetPlayerFacingAngle(playerid, rz);
		}

		if(rz >= 348.75 && rz < 11.25) PlayerDirection[playerid] = "North~n~~y~N";
		else if(rz >= 303.75 && rz < 326.25) PlayerDirection[playerid] = "North East~n~~y~NE";
		else if(rz >= 258.75 && rz < 281.25) PlayerDirection[playerid] = "East~n~~y~E";
		else if(rz >= 213.75 && rz < 236.25) PlayerDirection[playerid] = "South East~n~~y~SE";
		else if(rz >= 168.75 && rz < 191.25) PlayerDirection[playerid] = "South~n~~y~S";
		else if(rz >= 123.25 && rz < 146.25) PlayerDirection[playerid] = "South West~n~~y~SW";
		else if(rz >= 78.75 && rz < 101.25) PlayerDirection[playerid] = "West~n~~y~W";
		else if(rz >= 33.75 && rz < 56.25) PlayerDirection[playerid] = "North West~n~~y~NW";

		PlayerTextDrawSetString(playerid, Street[0][playerid], PlayerDirection[playerid]);

		new str[128];
		format(str, sizeof(str), "%s~n~%s~n~San Andreas", ReturnLocationStreet(playerid), ReturnLocation(playerid));
		PlayerTextDrawSetString(playerid, Street[1][playerid], str);
	}

	return 1;
}

public OnPlayerClickPlayerTextDraw(playerid, PlayerText:playertextid)
{

	// CHARACTER SELECTIONS:
	if (playertextid == SelectFactionClick[0][playerid]) //PREV
	{
		SwitchPrevCharacterSelection(playerid);
	}
	if (playertextid == SelectFactionClick[1][playerid]) //NEXT
	{	
		SwitchNextCharacterSelection(playerid);
	}
	if (playertextid == SelectFactionClick[2][playerid]) //SELECT
	{
		if(characterSelection[playerid])
		{
			if(PlayerInfo[playerid][E_CHARACTER_SELECTCHAR] == 0)
			{
				SelectCharacter(playerid, 0);
			}
			else if(PlayerInfo[playerid][E_CHARACTER_SELECTCHAR] == 1)
			{
				SelectCharacter(playerid, 1);
			}
			else if(PlayerInfo[playerid][E_CHARACTER_SELECTCHAR] == 2)
			{
				SelectCharacter(playerid, 2);
			}
			else if(PlayerInfo[playerid][E_CHARACTER_SELECTCHAR] == 3)
			{
				SelectCharacter(playerid, 3);
			}
		}
	}
	// TUTORIAL:
	if (playertextid == tutorialclick[playerid])
    {
		if(PlayerInfo[playerid][E_CHARACTER_TUTORIAL] == 0 && PlayerInfo[playerid][E_CHARACTER_TUTORIALSTEP] != 16)
		{
			NextTutorial(playerid);
		}
		return 1;
    }
	// PHONE:
	if (playertextid == phone[6][playerid])
    {
		new str[60];
		format(str, sizeof(str), "Phone Config #%d", PlayerInfo[playerid][E_CHARACTER_PHONE]);
        ShowPlayerDialog(playerid, DIALOG_PHONE, DIALOG_STYLE_LIST, str, "Dial Number\nSend Text Message\nChange background\nMy Contacts\nTurn on/off", "Select", "Close");
        return 1;
    }
	if (playertextid == phone[3][playerid])
    {
        cmd_pickup(playerid, "");
        return 1;
    }
	if (playertextid == phone[4][playerid])
    {
        cmd_hangup(playerid, "");
        return 1;
    }
	if (playertextid == phone[8][playerid])
    {
        HidePhone(playerid);
		CancelSelectTextDraw(playerid);

		ResetVarInventory(playerid);
        return 1;
    }
	if (playertextid == VehicleClose[playerid])
    {
		PlayerTextDrawHide(playerid, VehicleBox[playerid]);
		PlayerTextDrawHide(playerid, VehicleHeader[playerid]);
		PlayerTextDrawHide(playerid, VehicleClose[playerid]);
		PlayerTextDrawHide(playerid, VehicleModels[0][playerid]);
		PlayerTextDrawHide(playerid, VehiclePlate[0][playerid]);
		PlayerTextDrawHide(playerid, VehicleClick[0][playerid]);
		PlayerTextDrawHide(playerid, VehicleModels[1][playerid]);
		PlayerTextDrawHide(playerid, VehiclePlate[1][playerid]);
		PlayerTextDrawHide(playerid, VehicleClick[1][playerid]);
		PlayerTextDrawHide(playerid, VehicleModels[2][playerid]);
		PlayerTextDrawHide(playerid, VehiclePlate[2][playerid]);
		PlayerTextDrawHide(playerid, VehicleClick[2][playerid]);

		CancelSelectTextDraw(playerid);
	}
	return 1;
}


public OnModelSelectionResponse(playerid, extraid, index, modelid, response)
{
	if ((response) && (extraid == MODEL_SELECTION_COLOR1))
	{
		new vehicleid = GetPlayerVehicleID(playerid);
		if (!IsPlayerInAnyVehicle(playerid))
	    	return SendErrorMessage(playerid, "You aren't in any vehicle.");

	    PlayerPlaySound(playerid, 1134, 0, 0, 0);
	    new color = VehicleInfo[vehicleid][E_VEHICLE_COLOR2];
		ChangeVehicleColor(vehicleid, modelid, color);
		VehicleInfo[vehicleid][E_VEHICLE_COLOR1] = modelid;
		VehicleInfo[vehicleid][E_VEHICLE_COLOR2] = color;
		SaveVehicle(vehicleid);
		ShowBoxMessage(playerid, "Hope you like new color!!", 5);
		GiveMoney(playerid, -150);
		PauseAC(playerid);
		TogglePlayerControllable(playerid, true);
		PlayerInfo[playerid][E_CHARACTER_TOGMENU] = false;
	}
	if ((response) && (extraid == MODEL_SELECTION_COLOR2))
	{
		new vehicleid = GetPlayerVehicleID(playerid);
		if (!IsPlayerInAnyVehicle(playerid))
	    	return SendErrorMessage(playerid, "You aren't in any vehicle.");

	    PlayerPlaySound(playerid, 1134, 0, 0, 0);
	    new color = VehicleInfo[vehicleid][E_VEHICLE_COLOR1];
		ChangeVehicleColor(vehicleid, color, modelid);
		VehicleInfo[vehicleid][E_VEHICLE_COLOR1] = color;
		VehicleInfo[vehicleid][E_VEHICLE_COLOR2] = modelid;
		SaveVehicle(vehicleid);
		ShowBoxMessage(playerid, "Hope you like new color!!", 5);
		GiveMoney(playerid, -150);
		PauseAC(playerid);
		TogglePlayerControllable(playerid, true);
		PlayerInfo[playerid][E_CHARACTER_TOGMENU] = false;
	}
	if((response) && (extraid == MODEL_SELECTION_MODS))
	{
		new vehicleid = GetPlayerVehicleID(playerid), str[512];
		format(str, sizeof(str), "Hope you like new mods!!");
		ShowBoxMessage(playerid, str, 5);
		VehicleInfo[vehicleid][E_VEHICLE_MODS][GetVehicleComponentType(modelid)] = modelid;
		SaveVehicle(vehicleid);
		AddVehicleComponent(vehicleid, modelid);
		GiveMoney(playerid, -350);
		PauseAC(playerid);
		PlayerPlaySound(playerid, 1133, 0.0, 0.0, 0.0);
		return true;
	}
	if((response) && (extraid == MODEL_SELECTION_WHEELS))
	{
		new str[60];
		new v = GetPlayerVehicleID(playerid);
		AddVehicleComponent(v, modelid);
		VehicleInfo[v][E_VEHICLE_WHEELS] = modelid;
		SaveVehicle(v);
		format(str, sizeof(str), "Hope you like new wheels!!");
		GiveMoney(playerid, -350);
		PauseAC(playerid);
		ShowBoxMessage(playerid, str, 5);
		PlayerPlaySound(playerid, 1133, 0.0, 0.0, 0.0);
		return true;
	}
	else
	{
		SetCameraBehindPlayer(playerid);
		TogglePlayerControllable(playerid, true);
	}
	return 1;
}

public OnPlayerCommandReceived(playerid, cmdtext[])
{
	if(AccountInfo[playerid][E_MASTERS_LOGGED] == true)
	{
		if(AntiSpam[playerid]-gettime() > 0)
	    {
	        SendErrorMessage(playerid, "DON'T SPAM FOO!.");
	        return 0;
	    }
	    AntiSpam[playerid] = gettime() + 1;

	    PlayerInfo[playerid][E_CHARACTER_AFKPOS][0] = 0.0;
    	PlayerInfo[playerid][E_CHARACTER_AFKPOS][1] = 0.0;
    	PlayerInfo[playerid][E_CHARACTER_AFKPOS][2] = 0.0;
		printf("Player [%s] sent command: %s", ReturnSettingsName(playerid, playerid), cmdtext);
		return 1;
	}
	else
	{
		SendErrorMessage(playerid, "You need to be logged in to use commands.");
		printf("Player [%s] tried to send command: %s (During login, denied access)", ReturnSettingsName(playerid, playerid), cmdtext);
		return 0;
	}
}

public OnPlayerCommandPerformed(playerid, cmdtext[], success)
{
	if(!success)
	{
		if(strlen(cmdtext) > 50)
		{
			SendClientMessage(playerid, COLOR_RED, "ERROR: The command you entered doesn't exist. Use /help to see a list of available commands."); 
			PlayerInfo[playerid][E_CHARACTER_AFKPOS][0] = 0.0;
    		PlayerInfo[playerid][E_CHARACTER_AFKPOS][1] = 0.0;
    		PlayerInfo[playerid][E_CHARACTER_AFKPOS][2] = 0.0;
		}
			
		else
		{
			PlayerInfo[playerid][E_CHARACTER_AFKPOS][0] = 0.0;
    		PlayerInfo[playerid][E_CHARACTER_AFKPOS][1] = 0.0;
    		PlayerInfo[playerid][E_CHARACTER_AFKPOS][2] = 0.0;
			SendClientMessageEx(playerid, COLOR_RED, "ERROR: The command you entered \"%s\" doesn't exist. Use /help to see a list of available commands.", cmdtext);
		}
	}
	return 1;
}


public OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
	if(newkeys & KEY_WALK)
	{
		if(IsPlayerInRangeOfPoint(playerid, 2.0, packetpos[0], packetpos[1], packetpos[2]))
		{
			if(PlayerInfo[playerid][E_CHARACTER_JOBS] != JOB_SMUGGLER) 
        		return SendErrorMessage(playerid, "You aren't smugglers.");

			if(IsValidDynamic3DTextLabel(packetLabel))
				DestroyDynamic3DTextLabel(packetLabel), packetLabel = Text3D: -1;

			if(IsValidDynamicObject(packetObject))
				DestroyDynamicObject(packetObject), packetObject = INVALID_OBJECT_ID;

			PlayerInfo[playerid][E_CHARACTER_TAKEPACKET] = true;
			RemovePlayerAttachedObject(playerid, ATTACH_HAND);
			PlayerInfo[playerid][E_CHARACTER_EQUIPITEMS] = INVENTORY_NONE;
			SetPlayerAttachedObject(playerid, ATTACH_HAND, 11745, 6, 0.129999, 0.051000, 0.000000, 103.700004, -64.600059, 0.000000, 0.501999, 1.0, 1.0);

			SendNearbyMessage(playerid, 30.0, COLOR_PURPLE, "* %s has picked up a Packet.", ReturnSettingsName(playerid, playerid));

			SendTipMessage(playerid, "You've picked up packet, Type '/deliverypacket' to materials / drugs point.");
			ApplyAnimation(playerid, "BOMBER", "BOM_Plant", 4.1, 0, 0, 0, 0, 0, 1);
			packetpos[0] = 0.0;
			packetpos[1] = 0.0;
			packetpos[2] = -10.0;
		}

		if(IsPlayerNearestTree(playerid) != -1)
		{
			new Float:x, Float:y, Float:z;
			GetPlayerPos(playerid, x, y, z);

			new id;
			id = IsPlayerNearestTree(playerid);

			if(PlayerInfo[playerid][E_CHARACTER_JOBS] != JOB_LUMBERJACK)
				return SendErrorMessage(playerid, "You aren't lumberjack.");

			if(!Inventory_Count(playerid, "Axe"))
				return SendErrorMessage(playerid, "You don't have any axe in inventory.");

			if(PlayerInfo[playerid][E_CHARACTER_EQUIPITEMS] != AXE)
				return SendErrorMessage(playerid, "You must hold the axe in your hands.");

			if(TreeInfo[id][E_TREE_TIMER] > 0)
				return SendErrorMessage(playerid, "This tree still unavailable.");

			if(TreeInfo[id][E_TREE_CUT])
				return SendErrorMessage(playerid, "Unable to execute this tree! (being interacted with another player)");

			if(PlayerInfo[playerid][E_CHARACTER_LOADING] == true)
				return SendErrorMessage(playerid, "You're can't use this right now."); 

			if(!TreeInfo[id][E_TREE_CUTTED])
			{
				if(TreeInfo[id][E_TREE_PROGRESS] < 100)
				{
					PlayerInfo[playerid][E_CHARACTER_LOADING] = true;
					PlayerInfo[playerid][E_CHARACTER_LOADINGCOUNT] = 1;
					PlayerInfo[playerid][E_CHARACTER_LOADINGDISPLAY] = Create3DTextLabel("Loading cutting trees process\n(( |------ ))", COLOR_POINT, x, y, z, 25.0, 0, 1);
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
				PlayerInfo[playerid][E_CHARACTER_LOADINGDISPLAY] = Create3DTextLabel("Loading take timber process\n(( |------ ))", COLOR_POINT, x, y, z, 25.0, 0, 1);
				PlayerInfo[playerid][E_CHARACTER_LOADINGTIMER] = SetTimerEx("CreateTimber", 1000, true, "dd", playerid, id);
				TogglePlayerControllable(playerid, false);
				TreeInfo[id][E_TREE_CUT] = true;
				ApplyAnimation(playerid,"BOMBER","BOM_Plant_Loop", 4.1, 1, 0, 0, 1, 0, 1);
			}
		}
	}
	if((newkeys & KEY_AIM) == KEY_AIM && GetPlayerState(playerid) == PLAYER_STATE_ONFOOT && BusinessInfo[IsPlayerInBusiness(playerid)][E_BUSINESS_CASH] > 500 && BusinessInfo[IsPlayerInBusiness(playerid)][E_BUSINESS_ROBBERYCASH] == false)
	{
		if(GetPlayerWeapon(playerid) >= 22 && GetPlayerWeapon(playerid) <= 33)
		{
			new id = IsPlayerInBusiness(playerid);
			if(IsPlayerInBusiness(playerid))
			{
				if(PlayerInfo[playerid][E_CHARACTER_ROBBERYCD] == 0)
				{	
					if(PlayerInfo[playerid][E_CHARACTER_HASROBBIZ] == true)
						return SendErrorMessage(playerid, "You already robbery at this time.");

					if(BusinessInfo[IsPlayerInBusiness(playerid)][E_BUSINESS_ROBBERYTIME] > 0)
						return SendErrorMessage(playerid, "This Business has been robbery.");

					CallLocalFunction("OnPlayerStartRobbery", "dd", playerid, BusinessInfo[id][E_BUSINESS_ACTOR]);
					SetTimerEx("RunActorAnimationSequence", 1000, false, "iii", playerid, BusinessInfo[id][E_BUSINESS_ACTOR], 0);
				}
			}
		}
	}
	// GARBAGEMAN:
	if (newkeys & KEY_WALK && !IsPlayerInAnyVehicle(playerid))
	{
		if(PlayerInfo[playerid][E_CHARACTER_GARBAGEMAN])
		{
			CollectGarbage(playerid);
		}
	}
	// PLAYER GYM:
	if(newkeys == KEY_SECONDARY_ATTACK && !IsPlayerInAnyVehicle(playerid))
    {
		if(PlayerUsingGym[playerid] == false)
		{
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
	}

	if(newkeys == KEY_SPRINT && !IsPlayerInAnyVehicle(playerid))
    {
		if(PlayerUsingGym[playerid] == true)
		{
			IsPlayerPlayingMachine(playerid);
		}
	}

	// FISHING:
	if(newkeys == KEY_SPRINT && !IsPlayerInAnyVehicle(playerid))
    {
		if(PlayerInfo[playerid][E_CHARACTER_FISHINGSTART] == true)
		{
			if(PlayerInfo[playerid][E_CHARACTER_FISHINGVALUE] < 100.0)
			{
				PlayerInfo[playerid][E_CHARACTER_FISHINGVALUE] += 10.0;
				SetPlayerGameBar(playerid, PlayerInfo[playerid][E_CHARACTER_FISHINGVALUE]);
			}
			if(PlayerInfo[playerid][E_CHARACTER_FISHINGVALUE] == 100.0)
			{
				ClearAnimations(playerid);
				Inventory_Add(playerid, "Fish", 19630, 1);
				PlayerInfo[playerid][E_CHARACTER_FISHING] = false;
				PlayerInfo[playerid][E_CHARACTER_FISHINGSTART] = false;
				PlayerInfo[playerid][E_CHARACTER_FISHINGVALUE] = 0;

				DestroyGameBar(playerid);
				KillTimer(PlayerInfo[playerid][E_CHARACTER_FISHINGTIMER]);
				TogglePlayerControllable(playerid, true);
				
				ApplyAnimation(playerid, "CARRY", "crry_prtial", 4.0, 0, 0, 0, 0, 0, 1);
				SendServerMessage(playerid, "You caught a 1.kg of fish.");
				
			}
		}
	}

	// BUNNY HOP:
	if(PRESSED(KEY_JUMP) && !PlayerInfo[playerid][E_CHARACTER_ADMINDUTY])
	{
	    PlayerJump[playerid][JumpPressed] = gettime();
	}

	// CBUG:
	if(!pCBugging[playerid] && GetPlayerState(playerid) == PLAYER_STATE_ONFOOT)
	{
		if(PRESSED(KEY_FIRE))
		{
			switch(GetPlayerWeapon(playerid))
			{
				case WEAPON_DEAGLE, WEAPON_SHOTGUN, WEAPON_SNIPER:
				{
					ptsLastFiredWeapon[playerid] = gettime();
				}
			}
		}
		else if(PRESSED(KEY_CROUCH))
		{
			if((gettime() - ptsLastFiredWeapon[playerid]) < 1)
			{
				TogglePlayerControllable(playerid, false);
				ApplyAnimation(playerid, "PAULNMAC", "wank_loop", 4.1, 0, 0, 0, 0, 0, 1);
				pCBugging[playerid] = true;

				ShowBoxMessage(playerid, "CBUG FOO!", 5);

				KillTimer(ptmCBugFreezeOver[playerid]);
				ptmCBugFreezeOver[playerid] = SetTimerEx("CBugFreezeOver", 1500, false, "i", playerid);
			}
		}
	}
	// Basketball:
	if ((newkeys & KEY_WALK) && !(oldkeys & KEY_WALK) && !IsPlayerInAnyVehicle(playerid))
    {
		if(PlayerInfo[playerid][E_CHARACTER_COURT])
		{	
			if(PlayerInfo[playerid][E_CHARACTER_HAVEBALL])
			{
				ApplyAnimation(playerid,"BSKTBALL","BBALL_idleloop",4.1,1,1,1,1,1);
			}
			else
			{
				ApplyAnimation(playerid,"BSKTBALL","BBALL_def_loop",4.0,1,0,0,0,0);
			}
			PlayerInfo[playerid][E_CHARACTER_ANIMBALL] = 1;
		}
    }
    if (!(newkeys & KEY_WALK) && (oldkeys & KEY_WALK) && !IsPlayerInAnyVehicle(playerid))
    {
		if(PlayerInfo[playerid][E_CHARACTER_COURT])
		{	
			ClearAnimations(playerid);
			PlayerInfo[playerid][E_CHARACTER_ANIMBALL] = 0;
		}
    }
	if(newkeys & KEY_FIRE && !IsPlayerInAnyVehicle(playerid))
    {
		if(PlayerInfo[playerid][E_CHARACTER_COURT])
		{	
			if(!PlayerInfo[playerid][E_CHARACTER_HAVEBALL])
			{
				new Float:x, Float:y, Float:z;
				GetDynamicObjectPos(CourtInfo[PlayerInfo[playerid][E_CHARACTER_COURT]][E_BALL_OBJECT], x, y, z);

				if(IsPlayerInRangeOfPoint(playerid, 1.5, x, y, z))
				{
					PlayerInfo[playerid][E_CHARACTER_HAVEBALL] = 1;
					ApplyAnimation(playerid,"BSKTBALL","BBALL_pickup",4.0,0,0,0,0,0);

					if(CourtInfo[PlayerInfo[playerid][E_CHARACTER_COURT]][E_BALLER] != 999)
					{
						PlayerInfo[CourtInfo[PlayerInfo[playerid][E_CHARACTER_COURT]][E_BALLER]][E_CHARACTER_HAVEBALL] = 0;
						ClearAnimations(CourtInfo[PlayerInfo[playerid][E_CHARACTER_COURT]][E_BALLER]);
						ApplyAnimation(CourtInfo[PlayerInfo[playerid][E_CHARACTER_COURT]][E_BALLER], "CARRY", "crry_prtial", 1.0, 0, 0, 0, 0, 0);
						ApplyAnimation(playerid,"BSKTBALL","BBALL_walk",4.1,1,1,1,1,1);
					}

					CourtInfo[PlayerInfo[playerid][E_CHARACTER_COURT]][E_BALLER] = playerid;
					CourtInfo[PlayerInfo[playerid][E_CHARACTER_COURT]][E_BALL_STATUS] = 1;
					new Float:x2, Float:y2;
					GetXYInFrontOfPlayer(playerid, x2, y2, 0.8);
					GetPlayerPos(playerid, x, y, z);
					StopDynamicObject(CourtInfo[PlayerInfo[playerid][E_CHARACTER_COURT]][E_BALL_OBJECT]);
					MoveDynamicObject(CourtInfo[PlayerInfo[playerid][E_CHARACTER_COURT]][E_BALL_OBJECT], x2, y2, z, 2.5);
					PlayerInfo[playerid][E_CHARACTER_ANIMBALL] = 0;
					CourtInfo[PlayerInfo[playerid][E_CHARACTER_COURT]][E_BALL_BOUNCE] = 0;
				}
			}
			else
			{
				// Blue Team:
				if(IsPlayerInRangeOfPoint(playerid, 2, CourtInfo[PlayerInfo[playerid][E_CHARACTER_COURT]][E_BLUE_POS][0], CourtInfo[PlayerInfo[playerid][E_CHARACTER_COURT]][E_BLUE_POS][1], CourtInfo[PlayerInfo[playerid][E_CHARACTER_COURT]][E_BLUE_POS][2]))
				{
					MoveDynamicObject(CourtInfo[PlayerInfo[playerid][E_CHARACTER_COURT]][E_BALL_OBJECT], CourtInfo[PlayerInfo[playerid][E_CHARACTER_COURT]][E_BLUE_BALL][0], CourtInfo[PlayerInfo[playerid][E_CHARACTER_COURT]][E_BLUE_BALL][1], CourtInfo[PlayerInfo[playerid][E_CHARACTER_COURT]][E_BLUE_BALL][2], 7.5);
					SetPlayerPosEx(playerid, CourtInfo[PlayerInfo[playerid][E_CHARACTER_COURT]][E_BLUE_POS][0], CourtInfo[PlayerInfo[playerid][E_CHARACTER_COURT]][E_BLUE_POS][1], CourtInfo[PlayerInfo[playerid][E_CHARACTER_COURT]][E_BLUE_POS][2]);
					ApplyAnimation(playerid,"BSKTBALL","BBALL_Dnk",4.0,1,0,0,0,0);
					PlayerInfo[playerid][E_CHARACTER_HAVEBALL] = 0;
					SetTimerEx("ClearAnim", 1100, 0, "d", playerid);
					SetTimerEx("BallDowns", 1100, 0, "dd", playerid, 1);
					return 1;
				}
				else if(IsPlayerInRangeOfPoint(playerid, 4, CourtInfo[PlayerInfo[playerid][E_CHARACTER_COURT]][E_BLUE_POS][0], CourtInfo[PlayerInfo[playerid][E_CHARACTER_COURT]][E_BLUE_POS][1], CourtInfo[PlayerInfo[playerid][E_CHARACTER_COURT]][E_BLUE_POS][2]) && IsPlayerFacingPoint(playerid, 20, CourtInfo[PlayerInfo[playerid][E_CHARACTER_COURT]][E_BLUE_POS][0], CourtInfo[PlayerInfo[playerid][E_CHARACTER_COURT]][E_BLUE_POS][1], CourtInfo[PlayerInfo[playerid][E_CHARACTER_COURT]][E_BLUE_POS][2]))
				{
					new rand = random(1);
					if(rand == 0)
					{
						MoveDynamicObject(CourtInfo[PlayerInfo[playerid][E_CHARACTER_COURT]][E_BALL_OBJECT], CourtInfo[PlayerInfo[playerid][E_CHARACTER_COURT]][E_BLUE_POS][0]-1, CourtInfo[PlayerInfo[playerid][E_CHARACTER_COURT]][E_BLUE_POS][1], CourtInfo[PlayerInfo[playerid][E_CHARACTER_COURT]][E_BLUE_POS][2]+2, 10.5+random(4));
						ApplyAnimation(playerid,"BSKTBALL","BBALL_Jump_Shot",4.0,0,0,0,0,0);
						CourtInfo[PlayerInfo[playerid][E_CHARACTER_COURT]][E_BALL_SHOOT] = 2;
						PlayerInfo[playerid][E_CHARACTER_HAVEBALL] = 0;
						return 1;
					}
					ShootMiss(playerid, 1);
					return 1;
				}
				else if(IsPlayerInRangeOfPoint(playerid, 7, CourtInfo[PlayerInfo[playerid][E_CHARACTER_COURT]][E_BLUE_POS][0], CourtInfo[PlayerInfo[playerid][E_CHARACTER_COURT]][E_BLUE_POS][1], CourtInfo[PlayerInfo[playerid][E_CHARACTER_COURT]][E_BLUE_POS][2]) && IsPlayerFacingPoint(playerid, 20, CourtInfo[PlayerInfo[playerid][E_CHARACTER_COURT]][E_BLUE_POS][0], CourtInfo[PlayerInfo[playerid][E_CHARACTER_COURT]][E_BLUE_POS][1], CourtInfo[PlayerInfo[playerid][E_CHARACTER_COURT]][E_BLUE_POS][2]))
				{
					new rand = random(2);
					if(rand == 0)
					{
						MoveDynamicObject(CourtInfo[PlayerInfo[playerid][E_CHARACTER_COURT]][E_BALL_OBJECT], CourtInfo[PlayerInfo[playerid][E_CHARACTER_COURT]][E_BLUE_POS][0]-1, CourtInfo[PlayerInfo[playerid][E_CHARACTER_COURT]][E_BLUE_POS][1], CourtInfo[PlayerInfo[playerid][E_CHARACTER_COURT]][E_BLUE_POS][2]+2, 11.0+random(4));
						ApplyAnimation(playerid,"BSKTBALL","BBALL_Jump_Shot",4.0,0,0,0,0,0);
						CourtInfo[PlayerInfo[playerid][E_CHARACTER_COURT]][E_BALL_SHOOT] = 2;
						PlayerInfo[playerid][E_CHARACTER_HAVEBALL] = 0;
						return 1;
					}
					ShootMiss(playerid, 1);
					return 1;
				}
				else if(IsPlayerInRangeOfPoint(playerid, 10, CourtInfo[PlayerInfo[playerid][E_CHARACTER_COURT]][E_BLUE_POS][0], CourtInfo[PlayerInfo[playerid][E_CHARACTER_COURT]][E_BLUE_POS][1], CourtInfo[PlayerInfo[playerid][E_CHARACTER_COURT]][E_BLUE_POS][2]) && IsPlayerFacingPoint(playerid, 20, CourtInfo[PlayerInfo[playerid][E_CHARACTER_COURT]][E_BLUE_POS][0], CourtInfo[PlayerInfo[playerid][E_CHARACTER_COURT]][E_BLUE_POS][1], CourtInfo[PlayerInfo[playerid][E_CHARACTER_COURT]][E_BLUE_POS][2]))
				{
					new rand = random(3);
					if(rand == 0)
					{
						MoveDynamicObject(CourtInfo[PlayerInfo[playerid][E_CHARACTER_COURT]][E_BALL_OBJECT], CourtInfo[PlayerInfo[playerid][E_CHARACTER_COURT]][E_BLUE_POS][0]-1, CourtInfo[PlayerInfo[playerid][E_CHARACTER_COURT]][E_BLUE_POS][1], CourtInfo[PlayerInfo[playerid][E_CHARACTER_COURT]][E_BLUE_POS][2]+2, 11.5+random(4));
						ApplyAnimation(playerid,"BSKTBALL","BBALL_Jump_Shot",4.0,0,0,0,0,0);
						CourtInfo[PlayerInfo[playerid][E_CHARACTER_COURT]][E_BALL_SHOOT] = 2;
						PlayerInfo[playerid][E_CHARACTER_HAVEBALL] = 0;
						return 1;
					}
					ShootMiss(playerid, 1);
					return 1;
				}

				// Red Team:
				else if(IsPlayerInRangeOfPoint(playerid, 2, CourtInfo[PlayerInfo[playerid][E_CHARACTER_COURT]][E_RED_POS][0], CourtInfo[PlayerInfo[playerid][E_CHARACTER_COURT]][E_RED_POS][1], CourtInfo[PlayerInfo[playerid][E_CHARACTER_COURT]][E_RED_POS][2]))
				{
					MoveDynamicObject(CourtInfo[PlayerInfo[playerid][E_CHARACTER_COURT]][E_BALL_OBJECT], CourtInfo[PlayerInfo[playerid][E_CHARACTER_COURT]][E_RED_BALL][0], CourtInfo[PlayerInfo[playerid][E_CHARACTER_COURT]][E_RED_BALL][1], CourtInfo[PlayerInfo[playerid][E_CHARACTER_COURT]][E_RED_BALL][2], 7.5);
					SetPlayerPosEx(playerid, CourtInfo[PlayerInfo[playerid][E_CHARACTER_COURT]][E_RED_POS][0], CourtInfo[PlayerInfo[playerid][E_CHARACTER_COURT]][E_RED_POS][1], CourtInfo[PlayerInfo[playerid][E_CHARACTER_COURT]][E_RED_POS][2]);
					ApplyAnimation(playerid,"BSKTBALL","BBALL_Dnk",4.0,1,0,0,0,0);
					PlayerInfo[playerid][E_CHARACTER_HAVEBALL] = 0;
					SetTimerEx("ClearAnim", 1100, 0, "d", playerid);
					SetTimerEx("BallDowns", 1100, 0, "dd", playerid, 2);
					return 1;
				}
				else if(IsPlayerInRangeOfPoint(playerid, 4, CourtInfo[PlayerInfo[playerid][E_CHARACTER_COURT]][E_RED_POS][0], CourtInfo[PlayerInfo[playerid][E_CHARACTER_COURT]][E_RED_POS][1], CourtInfo[PlayerInfo[playerid][E_CHARACTER_COURT]][E_RED_POS][2]) && IsPlayerFacingPoint(playerid, 20, CourtInfo[PlayerInfo[playerid][E_CHARACTER_COURT]][E_RED_POS][0], CourtInfo[PlayerInfo[playerid][E_CHARACTER_COURT]][E_RED_POS][1], CourtInfo[PlayerInfo[playerid][E_CHARACTER_COURT]][E_RED_POS][2]))
				{
					new rand = random(1);
					if(rand == 0)
					{
						MoveDynamicObject(CourtInfo[PlayerInfo[playerid][E_CHARACTER_COURT]][E_BALL_OBJECT], CourtInfo[PlayerInfo[playerid][E_CHARACTER_COURT]][E_RED_POS][0], CourtInfo[PlayerInfo[playerid][E_CHARACTER_COURT]][E_RED_POS][1], CourtInfo[PlayerInfo[playerid][E_CHARACTER_COURT]][E_RED_POS][2]+2, 10.5+random(4));
						ApplyAnimation(playerid,"BSKTBALL","BBALL_Jump_Shot",4.0,0,0,0,0,0);
						CourtInfo[PlayerInfo[playerid][E_CHARACTER_COURT]][E_BALL_SHOOT] = 3;
						PlayerInfo[playerid][E_CHARACTER_HAVEBALL] = 0;
						return 1;
					}
					ShootMiss(playerid, 2);
					return 1;
				}
				else if(IsPlayerInRangeOfPoint(playerid, 7, CourtInfo[PlayerInfo[playerid][E_CHARACTER_COURT]][E_RED_POS][0], CourtInfo[PlayerInfo[playerid][E_CHARACTER_COURT]][E_RED_POS][1], CourtInfo[PlayerInfo[playerid][E_CHARACTER_COURT]][E_RED_POS][2]) && IsPlayerFacingPoint(playerid, 20, CourtInfo[PlayerInfo[playerid][E_CHARACTER_COURT]][E_RED_POS][0], CourtInfo[PlayerInfo[playerid][E_CHARACTER_COURT]][E_RED_POS][1], CourtInfo[PlayerInfo[playerid][E_CHARACTER_COURT]][E_RED_POS][2]))
				{
					new rand = random(2);
					if(rand == 0)
					{
						MoveDynamicObject(CourtInfo[PlayerInfo[playerid][E_CHARACTER_COURT]][E_BALL_OBJECT], CourtInfo[PlayerInfo[playerid][E_CHARACTER_COURT]][E_RED_POS][0], CourtInfo[PlayerInfo[playerid][E_CHARACTER_COURT]][E_RED_POS][1], CourtInfo[PlayerInfo[playerid][E_CHARACTER_COURT]][E_RED_POS][2]+2, 11.0+random(4));
						ApplyAnimation(playerid,"BSKTBALL","BBALL_Jump_Shot",4.0,0,0,0,0,0);
						CourtInfo[PlayerInfo[playerid][E_CHARACTER_COURT]][E_BALL_SHOOT] = 3;
						PlayerInfo[playerid][E_CHARACTER_HAVEBALL] = 0;
						return 1;
					}
					ShootMiss(playerid, 2);
					return 1;
				}
				else if(IsPlayerInRangeOfPoint(playerid, 10, CourtInfo[PlayerInfo[playerid][E_CHARACTER_COURT]][E_RED_POS][0], CourtInfo[PlayerInfo[playerid][E_CHARACTER_COURT]][E_RED_POS][1], CourtInfo[PlayerInfo[playerid][E_CHARACTER_COURT]][E_RED_POS][2]) && IsPlayerFacingPoint(playerid, 20, CourtInfo[PlayerInfo[playerid][E_CHARACTER_COURT]][E_RED_POS][0], CourtInfo[PlayerInfo[playerid][E_CHARACTER_COURT]][E_RED_POS][1], CourtInfo[PlayerInfo[playerid][E_CHARACTER_COURT]][E_RED_POS][2]))
				{
					new rand = random(3);
					if(rand == 0)
					{
						MoveDynamicObject(CourtInfo[PlayerInfo[playerid][E_CHARACTER_COURT]][E_BALL_OBJECT], CourtInfo[PlayerInfo[playerid][E_CHARACTER_COURT]][E_RED_POS][0], CourtInfo[PlayerInfo[playerid][E_CHARACTER_COURT]][E_RED_POS][1], CourtInfo[PlayerInfo[playerid][E_CHARACTER_COURT]][E_RED_POS][2]+2, 11.5+random(4));
						ApplyAnimation(playerid,"BSKTBALL","BBALL_Jump_Shot",4.0,0,0,0,0,0);
						CourtInfo[PlayerInfo[playerid][E_CHARACTER_COURT]][E_BALL_SHOOT] = 3;
						PlayerInfo[playerid][E_CHARACTER_HAVEBALL] = 0;
						return 1;
					}
					ShootMiss(playerid, 2);
					return 1;
				}
				// PASS & STEAL:
				for(new i; i < MAX_PLAYERS; i++)
				{
					if(IsPlayerConnected(i))
					{
						if(IsPlayerFacingPlayer(playerid, i, 15))
						{
							new Float:x, Float:y, Float:z;
							GetPlayerPos(i, x, y, z);
							if(IsPlayerInRangeOfPoint(playerid, 20.0, x, y, z))
							{
								CourtInfo[PlayerInfo[i][E_CHARACTER_COURT]][E_BALLER] = i;
								PlayerInfo[playerid][E_CHARACTER_HAVEBALL] = 0;
								ClearAnimations(playerid);
								ApplyAnimation(playerid,"BSKTBALL","BBALL_def_loop",4.0,1,0,0,0,0);
								SetTimerEx("ClearAnim", 700, 0, "d", playerid);
								MoveDynamicObject(CourtInfo[PlayerInfo[i][E_CHARACTER_COURT]][E_BALL_OBJECT], x, y, z, 13+random(4));
								PlayerInfo[i][E_CHARACTER_ANIMBALL] = 0;
								CourtInfo[PlayerInfo[i][E_CHARACTER_COURT]][E_BALL_SHOOT] = 6;
								ApplyAnimation(i,"BSKTBALL","BBALL_def_loop",4.0,1,0,0,0,0);
								return 1;
							}
						}
					}
				}
				// THROW:
				new Float:x, Float:y, Float:z;
				GetPlayerPos(playerid, x, y, z);
				PlayerInfo[playerid][E_CHARACTER_HAVEBALL] = 0;
				new Float:x2, Float:y2;
				GetXYInFrontOfPlayer(playerid, x2, y2, 6.0);
				SetTimerEx("BallDown", 600, 0, "df", playerid, z);
				MoveDynamicObject(CourtInfo[PlayerInfo[playerid][E_CHARACTER_COURT]][E_BALL_OBJECT], x2, y2, z+1.2, 10.0+random(4));
				ApplyAnimation(playerid,"BSKTBALL","BBALL_Jump_Shot",4.0,0,0,0,0,0);
				CourtInfo[PlayerInfo[playerid][E_CHARACTER_COURT]][E_BALL_SHOOT] = 0;
			}
		}
	}
	if ((newkeys & KEY_FIRE) && (newkeys & KEY_LOOK_BEHIND) && (IsPlayerInAnyVehicle(playerid)))
	{
		new vehicleid = GetPlayerVehicleID(playerid);
		if(GetPlayerState(playerid) == PLAYER_STATE_DRIVER)
        {
			if (!IsEngineVehicle(vehicleid))
				return SendErrorMessage(playerid, "You are not in any vehicle.");

			if(VehicleInfo[vehicleid][E_VEHICLE_IMPOUND])
				return SendErrorMessage(playerid, "Your vehicle is impounded.");

			if(VehicleInfo[vehicleid][E_VEHICLE_FUEL] < 1 && !VehicleInfo[vehicleid][E_VEHICLE_ADMIN])
				return SendClientMessage(playerid, COLOR_RED, "Vehicle is out of fuel!"); 

			if (ReturnVehicleHealth(vehicleid) > 350)
			{
				if(!VehicleInfo[vehicleid][E_VEHICLE_ENGINE])
				{
					SendNearbyMessage(playerid, 20.0, COLOR_EMOTE, "* %s started the engine of the %s.", ReturnSettingsName(playerid, playerid), ReturnVehicleName(vehicleid)); 
					SetTimerEx("TurnEngine", 2000, false, "d", vehicleid);
				}
				else
				{
					SendNearbyMessage(playerid, 20.0, COLOR_EMOTE, "* %s stopped the engine of the %s.", ReturnSettingsName(playerid, playerid), ReturnVehicleName(vehicleid)); 
					ToggleVehicleEngine(vehicleid, false); VehicleInfo[vehicleid][E_VEHICLE_ENGINE] = false;
				}
			}
		}
	}
	if(newkeys == KEY_FIRE)
	{
		if(PlayerInfo[playerid][E_CHARACTER_DRINKING] > 0)
		{
			PlayerInfo[playerid][E_CHARACTER_DRINKING]--;
			
			/*new turfid = IsPlayerNearTurf(playerid);
			if(turfid)
			{
				if(GetPlayerTeam(playerid) != PLAYER_STATE_WOUNDED && GlobalTurf == 0 && TurfInfo[turfid][E_FACTION_TURFTYPE] == 0 && FactionInfo[PlayerInfo[playerid][E_CHARACTER_FACTION]][E_FACTION_TYPE] == FACTION_TYPE_ILLEGAL)
				{
				    TurfsPoints(playerid, turfid);
				}
			}*/
			if(PlayerInfo[playerid][E_CHARACTER_DRINKING] < 0)
			{
				PlayerInfo[playerid][E_CHARACTER_DRINKCD] = gettime();
				PlayerInfo[playerid][E_CHARACTER_DRINKING] = 0;
				SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
			}
		}
	}
	if (newkeys & KEY_SECONDARY_ATTACK && !IsPlayerInAnyVehicle(playerid))
	{
		if(PlayerInfo[playerid][E_CHARACTER_DRINKING] > 0)
		{
			PlayerInfo[playerid][E_CHARACTER_DRINKCD] = gettime();
			PlayerInfo[playerid][E_CHARACTER_DRINKING] = 0;
			SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
		}
		if(PlayerInfo[playerid][E_CHARACTER_LOOPANIM])
		{
			cmd_stopanim(playerid, "");
		}
		if(PlayerInfo[playerid][E_CHARACTER_EQUIPITEMS] > INVENTORY_NONE)
		{
			ResetVarInventory(playerid);
		}

		new id, b_id, e_id, str[128]; 
		//Enter
		if((id = IsPlayerNearProperty(playerid)) != 0)
		{
			if(PlayerInfo[playerid][E_CHARACTER_EDITINGOBJECT])
				return SendErrorMessage(playerid, "You can't leave while editing an object.");
					
			if(PropertyInfo[id][E_PROPERTY_LOCKED])
				return GameTextForPlayer(playerid, "~r~Locked", 3000, 3);
					
			PlayerInfo[playerid][E_CHARACTER_INSIDEPROP] = id;

			SetPlayerPosEx(playerid, PropertyInfo[id][E_PROPERTY_INTERIORPOS][0], PropertyInfo[id][E_PROPERTY_INTERIORPOS][1], PropertyInfo[id][E_PROPERTY_INTERIORPOS][2]);
				
			SetPlayerVirtualWorld(playerid, PropertyInfo[id][E_PROPERTY_INTERIORWORLD]);
			SetPlayerInterior(playerid, PropertyInfo[id][E_PROPERTY_INTERIORINTERIOR]);
		}
		if((e_id = IsPlayerNearEntrance(playerid)) != 0)
		{
			if(PlayerInfo[playerid][E_CHARACTER_EDITINGOBJECT])
				return SendErrorMessage(playerid, "You can't leave while editing an object.");
					
			PlayerInfo[playerid][E_CHARACTER_INSIDEENT] = e_id;

			SetPlayerPosEx(playerid, EntranceInfo[e_id][E_ENTRANCE_INT][0], EntranceInfo[e_id][E_ENTRANCE_INT][1], EntranceInfo[e_id][E_ENTRANCE_INT][2]);
				
			SetPlayerVirtualWorld(playerid, EntranceInfo[e_id][E_ENTRANCE_WORLD]);
			SetPlayerInterior(playerid, EntranceInfo[e_id][E_ENTRANCE_INTERIOR]); 
				
			TogglePlayerControllable(playerid, false);	
		}

		if((b_id = IsPlayerNearBusiness(playerid)) != 0)
		{
			if(PlayerInfo[playerid][E_CHARACTER_EDITINGOBJECT])
				return SendErrorMessage(playerid, "You can't leave while editing an object.");

			if(BusinessInfo[b_id][E_BUSINESS_LOCKED])
				return GameTextForPlayer(playerid, "~r~Locked", 3000, 3); 
				
			if(BusinessInfo[b_id][E_BUSINESS_TYPE] == BUSINESS_TYPE_DEALERSHIP || BusinessInfo[b_id][E_BUSINESS_TYPE] == BUSINESS_TYPE_DMV)
				return GameTextForPlayer(playerid, "~r~Closed", 3000, 3); 
				
			if(BusinessInfo[b_id][E_BUSINESS_ENTRANCEFEE] > PlayerInfo[playerid][E_CHARACTER_MONEY])
				return GameTextForPlayer(playerid, "~r~You can't afford this.", 3000, 1); 
				
			if(PlayerInfo[playerid][E_CHARACTER_DBID] != BusinessInfo[b_id][E_BUSINESS_OWNERDBID] && BusinessInfo[b_id][E_BUSINESS_TYPE] != BUSINESS_TYPE_BANK)
			{
				GiveMoney(playerid, -BusinessInfo[b_id][E_BUSINESS_ENTRANCEFEE]); 
				BusinessInfo[b_id][E_BUSINESS_CASH]+= BusinessInfo[b_id][E_BUSINESS_ENTRANCEFEE]; 
			}
				
			format(str, sizeof(str), "%s", BusinessInfo[b_id][E_BUSINESS_NAME]); 
			GameTextForPlayer(playerid, str, 3000, 1); 
			
			SetPlayerPosEx(playerid, BusinessInfo[b_id][E_BUSINESS_INTERIORPOS][0], BusinessInfo[b_id][E_BUSINESS_INTERIORPOS][1], BusinessInfo[b_id][E_BUSINESS_INTERIORPOS][2]); 
			
			SetPlayerInterior(playerid, BusinessInfo[b_id][E_BUSINESS_INTERIORPOSINTERIOR]); 
			SetPlayerVirtualWorld(playerid, BusinessInfo[b_id][E_BUSINESS_INTERIORPOSWORLD]); 
			
			PlayerInfo[playerid][E_CHARACTER_INSIDEBIZ] = b_id; 
			
			SendBusinessType(playerid, b_id);
			return 1;
		}

		//Exit
		if((id = IsPlayerInProperty(playerid)) != 0)
		{
			if(PlayerInfo[playerid][E_CHARACTER_EDITINGOBJECT])
				return SendErrorMessage(playerid, "You can't leave while editing an object.");

			if(IsPlayerInRangeOfPoint(playerid, 3.0, PropertyInfo[id][E_PROPERTY_INTERIORPOS][0], PropertyInfo[id][E_PROPERTY_INTERIORPOS][1], PropertyInfo[id][E_PROPERTY_INTERIORPOS][2]))
			{
				SetPlayerPosEx(playerid, PropertyInfo[id][E_PROPERTY_ENTRANCEPOS][0], PropertyInfo[id][E_PROPERTY_ENTRANCEPOS][1], PropertyInfo[id][E_PROPERTY_ENTRANCEPOS][2]);
				
				SetPlayerVirtualWorld(playerid, PropertyInfo[id][E_PROPERTY_ENTRANCEWORLD]);
				SetPlayerInterior(playerid, PropertyInfo[id][E_PROPERTY_ENTRANCEINTERIOR]); 
				
				PlayerInfo[playerid][E_CHARACTER_INSIDEENT] = 0;
			}
			return 1;
		}

		if((e_id = IsPlayerInEntrance(playerid)) != 0)
		{
			if(PlayerInfo[playerid][E_CHARACTER_EDITINGOBJECT])
				return SendErrorMessage(playerid, "You can't leave while editing an object.");

			if(IsPlayerInRangeOfPoint(playerid, 2.0, EntranceInfo[e_id][E_ENTRANCE_INT][0], EntranceInfo[e_id][E_ENTRANCE_INT][1], EntranceInfo[e_id][E_ENTRANCE_INT][2]))
			{
				SetPlayerPosEx(playerid, EntranceInfo[e_id][E_ENTRANCE_POS][0], EntranceInfo[e_id][E_ENTRANCE_POS][1], EntranceInfo[e_id][E_ENTRANCE_POS][2]);
				
				SetPlayerVirtualWorld(playerid, 0);
				SetPlayerInterior(playerid, 0); 
				
				PlayerInfo[playerid][E_CHARACTER_INSIDEPROP] = 0;
			}
			return 1;
		}
		
		if((b_id = IsPlayerInBusiness(playerid)) != 0)
		{
			if(PlayerInfo[playerid][E_CHARACTER_EDITINGOBJECT])
				return SendErrorMessage(playerid, "You can't leave while editing an object.");

			if(IsPlayerInRangeOfPoint(playerid, 3.0, BusinessInfo[b_id][E_BUSINESS_INTERIORPOS][0], BusinessInfo[b_id][E_BUSINESS_INTERIORPOS][1], BusinessInfo[b_id][E_BUSINESS_INTERIORPOS][2]))
			{
				if(PlayerInfo[playerid][E_CHARACTER_PURCHASE] > 0)
				{
					SaveCharacter(playerid);
				}
			
				SetPlayerPosEx(playerid, BusinessInfo[b_id][E_BUSINESS_ENTRANCEPOS][0], BusinessInfo[b_id][E_BUSINESS_ENTRANCEPOS][1], BusinessInfo[b_id][E_BUSINESS_ENTRANCEPOS][2]);
				
				SetPlayerVirtualWorld(playerid, 0);
				SetPlayerInterior(playerid, 0);
				
				PlayerInfo[playerid][E_CHARACTER_INSIDEBIZ] = 0;
				if(PlayerInfo[playerid][E_CHARACTER_PURCHASE] > 0)
				{
					Relations_Remove(playerid, BusinessInfo[b_id][E_BUSINESS_NAME], 30);
					PlayerInfo[playerid][E_CHARACTER_PURCHASE] = 0;
				}
			}
			return 1;
		}
	}
	if (newkeys & KEY_YES)
	{
		cmd_inventory(playerid, "");
	}
	else if (newkeys & KEY_NO && GetPlayerState(playerid) == PLAYER_STATE_ONFOOT)
	{
		if (GetPlayerSpecialAction(playerid) == SPECIAL_ACTION_DUCK)
		{
		   	new
				count = 0,
				id = Item_Nearest(playerid);
			new string[512];

			if (id != -1)
			{
				if(DroppedInfo[id][E_DROPPED_LOADING] == true)
					return SendErrorMessage(playerid, "You can't pickup this items.");

				string = "";

				for (new i = 0; i < MAX_DROPPED_ITEMS; i ++) if (count < MAX_LISTED_ITEMS && DroppedInfo[i][E_DROPPED_MODEL] && IsPlayerInRangeOfPoint(playerid, 1.5, DroppedInfo[i][E_DROPPED_POS][0], DroppedInfo[i][E_DROPPED_POS][1], DroppedInfo[i][E_DROPPED_POS][2]) && GetPlayerInterior(playerid) == DroppedInfo[i][E_DROPPED_INTERIOR] && GetPlayerVirtualWorld(playerid) == DroppedInfo[i][E_DROPPED_WORLD]) {
					NearestItems[playerid][count++] = i;

					strcat(string, DroppedInfo[i][E_DROPPED_ITEM]);
					strcat(string, "\n");
				}
				if (count == 1)
				{
					if (PickupItem(playerid, id))
					{
						format(string, sizeof(string), "%s added to inventory!", DroppedInfo[id][E_DROPPED_ITEM]);
						ShowBoxMessage(playerid, string, 5);
					}
					else
						SendErrorMessage(playerid, "You don't have any slot in your inventory.");
				}
				else ShowPlayerDialog(playerid, DIALOG_PICKUPITEM, DIALOG_STYLE_LIST, "Pickup Items:", string, "Pickup", "Cancel");
			}
		}
		else
		{
			if(IsPlayerInBusiness(playerid) && IsPlayerNearCashiers(playerid)) //Payclerk Pawnshop
			{
				if(BusinessInfo[IsPlayerInBusiness(playerid)][E_BUSINESS_ROBBERYCASH])
				{
					ShowPlayerDialog(playerid, DIALOG_CLERK, DIALOG_STYLE_LIST, "Choose an option:", "Pay to clerk\nTake Cash", "Select", "Close");
				}
				else
				{
					if(PlayerInfo[playerid][E_CHARACTER_PURCHASE] == 0)
						return SendErrorMessage(playerid, "You don't have a bill to pay to the clerk.");

					if(PlayerInfo[playerid][E_CHARACTER_PURCHASE] > PlayerInfo[playerid][E_CHARACTER_MONEY])
					{
						return SendErrorMessage(playerid, "You can't afford a bills.");
					}
					GiveMoney(playerid, -PlayerInfo[playerid][E_CHARACTER_PURCHASE]);
					PlayerInfo[playerid][E_CHARACTER_PURCHASE] = 0;

					Relations_Add(playerid, BusinessInfo[IsPlayerInBusiness(playerid)][E_BUSINESS_NAME]);
				}
			}
			if(!BusinessInfo[IsPlayerInBusiness(playerid)][E_BUSINESS_ROBBERYTIME])
			{
				if(IsPlayerInRangeOfPoint(playerid, 2.0, -48.1108,5.5907,203.2633))
				{
					ShowGeneralList(playerid, 1);
				}
				else if(IsPlayerInRangeOfPoint(playerid, 2.0, -51.4530,5.4811,203.2633))
				{
					ShowGeneralList(playerid, 2);
				}
				else if(IsPlayerInRangeOfPoint(playerid, 2.0, -53.7646,5.2118,203.2633))
				{
					ShowGeneralList(playerid, 3);
				}
				else if(IsPlayerInRangeOfPoint(playerid, 2.0, -48.4748,-1.1597,203.2633))
				{
					ShowGeneralList(playerid, 4);
				}
				else if(IsPlayerInRangeOfPoint(playerid, 2.0, -53.7980,2.8393,203.2633))
				{
					ShowGeneralList(playerid, 5);
				}
			}
		}
	}
	return 1;
}

public OnPlayerStateChange(playerid, newstate, oldstate)
{
	new vehicleid = GetPlayerVehicleID(playerid);
	if(newstate == PLAYER_STATE_DRIVER)
	{
		if(!VehicleInfo[GetPlayerVehicleID(playerid)][E_VEHICLE_ENGINE] && IsEngineVehicle(vehicleid)){
			SendTipMessage(playerid, "The engine is off press 'ALT' + '2' or /engine to turn on vehicle");
	   	}

	   	if (ReturnVehicleHealth(vehicleid) <= 350){
			SendTipMessage(playerid, "This vehicle is totalled and needs repairing call mechanic or buy repairkits in pawnshop.");
		}
	
		if(VehicleInfo[GetPlayerVehicleID(playerid)][E_VEHICLE_OWNERDBID] == PlayerInfo[playerid][E_CHARACTER_DBID])
			SendClientMessageEx(playerid, COLOR_WHITE, "Welcome to your %s.", ReturnVehicleName(GetPlayerVehicleID(playerid)));
			
		for(new i = 0; i < sizeof dmv_vehicles; i++) if(GetPlayerVehicleID(playerid) == dmv_vehicles[i])
			SendTipMessage(playerid, "This vehicle is part of departement of motor vehicles. in order to start it '/licenseexam'.");

		if((Jobs_vehicles[7] <= vehicleid <= Jobs_vehicles[11]))
			SendTipMessage(playerid, "This vehicle is part of dockworker job. in order to start it '/jobduty'.");

		if(IsABoat(vehicleid))
		{
			SendTipMessage(playerid, "You are now entering boat, /fish to start fishing.");
		}
	}

	if (newstate == PLAYER_STATE_PASSENGER && IsPlayerInsideTaxi(playerid))
	{
	    new driverid = GetVehicleDriver(GetPlayerVehicleID(playerid));

	    PlayerInfo[playerid][E_CHARACTER_TAXIFARE] = 1;
	    PlayerInfo[playerid][E_CHARACTER_TAXITIMER] = 0;
	    PlayerInfo[playerid][E_CHARACTER_TAXIPLAYER] = driverid;

	    SendServerMessage(driverid, "%s has entered your taxi as a passenger.", ReturnSettingsName(playerid, driverid));
		SendServerMessage(playerid, "You have entered %s's taxi.", ReturnSettingsName(driverid, playerid));
	}
 	if (oldstate == PLAYER_STATE_PASSENGER && PlayerInfo[playerid][E_CHARACTER_TAXITIMER] != 0 && PlayerInfo[playerid][E_CHARACTER_TAXIPLAYER] != INVALID_PLAYER_ID)
	{
	    LeaveTaxi(playerid, PlayerInfo[playerid][E_CHARACTER_TAXIPLAYER]);
	}
	
	if(newstate == PLAYER_STATE_DRIVER || newstate == PLAYER_STATE_PASSENGER)
	{
		if(VehicleInfo[GetPlayerVehicleID(playerid)][E_VEHICLE_RADIO] == true)
		{
			PlayAudioStreamForPlayer(playerid, VehicleInfo[GetPlayerVehicleID(playerid)][E_VEHICLE_RADIOURL]);
		}

		new str[256];
		format(str, sizeof(str), "%s", ReturnVehicleName(GetPlayerVehicleID(playerid)));
		PlayerTextDrawSetString(playerid, VehicleName[playerid], str);
		PlayerTextDrawFade(playerid, VehicleName[playerid], COLOR_DARKGREEN, 0x00000000, fade_type_text, 50, 5, 255, 0x00000000);
	}
	
	if(!IsEngineVehicle(GetPlayerVehicleID(playerid)))
		ToggleVehicleEngine(GetPlayerVehicleID(playerid), true); 

	if(oldstate == PLAYER_STATE_DRIVER || oldstate == PLAYER_STATE_PASSENGER && newstate == PLAYER_STATE_ONFOOT)
	{
		StopAudioStreamForPlayer(playerid); 
		HideVehicleSpeedometer(playerid);

		forex(i, 12)
		{
			DestroyDynamicMapIcon(FishAreaMap[playerid][i]);
		}
	}
	
	if(oldstate == PLAYER_STATE_DRIVER)
	{
		if(DealershipPlayerCar[playerid] != INVALID_VEHICLE_ID)
		{
			if(IsValidVehicle(DealershipPlayerCar[playerid]) && !VehicleInfo[DealershipPlayerCar[playerid]][E_VEHICLE_DBID])
			{
				DestroyVehicle(DealershipPlayerCar[playerid]); 
			}
			
			if(!PlayerPurchasingVehicle[playerid])
				ResetDealershipVars(playerid); 
		}
		
		if(PlayerTakingLicense[playerid])
			StopDriverstest(playerid);
	}
	
	return 1; 
}

public OnPlayerExitVehicle(playerid, vehicleid)
{
	if (PlayerInfo[playerid][E_CHARACTER_TAXIDUTY])
	{
        foreach (new i : Player) if (PlayerInfo[i][E_CHARACTER_TAXIPLAYER] == playerid && IsPlayerInVehicle(i, GetPlayerVehicleID(playerid))) {
	        LeaveTaxi(i, playerid);
	    }
	    
        PlayerInfo[playerid][E_CHARACTER_TAXIDUTY] = false;
        SendServerMessage(playerid, "You are no longer on taxi duty!");
	}

    if(Jobs_vehicles[7] <= vehicleid <= Jobs_vehicles[11])
    {
        PlayerInfo[playerid][E_CHARACTER_DOCKSWORK] = false;
        ShowBoxMessage(playerid, "~r~Dockworker job stopped.", 5); 
		SetVehicleToRespawnEx(vehicleid);
    }   
	else if(Jobs_vehicles[12] <= vehicleid <= Jobs_vehicles[14])
    {
        PlayerInfo[playerid][E_CHARACTER_JOBSTIME] = 60;
    } 
	return 1;
}

public OnPlayerEnterVehicle(playerid, vehicleid, ispassenger)
{
	if(!ispassenger)
	{
		for(new i = 0; i < sizeof dmv_vehicles; i++) if(vehicleid == dmv_vehicles[i])
		{
			if(PlayerInfo[playerid][E_CHARACTER_DRIVELICENSE])
			{
				SendErrorMessage(playerid, "You already have a driver's license.");
				return ClearAnimations(playerid);
			}
		}
	}

	LastEnteredVehicle[playerid] = vehicleid;
	return 1;
}

public OnPlayerEditAttachedObject(playerid, response, index, modelid, boneid, Float:fOffsetX, Float:fOffsetY, Float:fOffsetZ, Float:fRotX, Float:fRotY, Float:fRotZ, Float:fScaleX, Float:fScaleY, Float:fScaleZ)
{
	if(response == 1)
	{
		pToys[playerid][index][E_TOY_TYPE] = ACC_TOYS;
		pToys[playerid][index][E_TOY_X] = fOffsetX;
		pToys[playerid][index][E_TOY_Y] = fOffsetY;
		pToys[playerid][index][E_TOY_Z] = fOffsetZ;
		pToys[playerid][index][E_TOY_RX] = fRotX;
		pToys[playerid][index][E_TOY_RY] = fRotY;
		pToys[playerid][index][E_TOY_RZ] = fRotZ;
		pToys[playerid][index][E_TOY_SX] = fScaleX;
		pToys[playerid][index][E_TOY_SY] = fScaleY;
		pToys[playerid][index][E_TOY_SZ] = fScaleZ;
			
		SavePlayerToys(playerid);
	}
	else if(response == 0)
	{
		SetPlayerAttachedObject(playerid,
			index,
			modelid,
			boneid,
			pToys[playerid][index][E_TOY_X],
			pToys[playerid][index][E_TOY_Y],
			pToys[playerid][index][E_TOY_Z],
			pToys[playerid][index][E_TOY_RX],
			pToys[playerid][index][E_TOY_RY],
			pToys[playerid][index][E_TOY_RZ],
			pToys[playerid][index][E_TOY_SX],
			pToys[playerid][index][E_TOY_SY],
			pToys[playerid][index][E_TOY_SZ]);
	}
    return 1;
}

public OnPlayerEditDynamicObject(playerid, objectid, response, Float:x, Float:y, Float:z, Float:rx, Float:ry, Float:rz)
{
	if(PlayerInfo[playerid][E_CHARACTER_EDITINGOBJECT])
	{
		switch(PlayerInfo[playerid][E_CHARACTER_EDITINGOBJECT])
		{
			case 1:
			{
				if(response == EDIT_RESPONSE_CANCEL)
				{
					PlayerInfo[playerid][E_CHARACTER_EDITINGOBJECT] = 0; 
					PlayerInfo[playerid][E_CHARACTER_OBJECTID] = 0;
					PlayerInfo[playerid][E_CHARACTER_OBJECTTYPE] = 0;
					PlayerInfo[playerid][E_CHARACTER_OBJECTOWN] = 0;
		
					DestroyDynamicObject(PlayerInfo[playerid][E_CHARACTER_ADDOBJECT]);
		
					SendErrorMessage(playerid, "You're no longer place a spraytags."); 
					return 1;
				}

				if(response == EDIT_RESPONSE_FINAL)
				{
					new str[32];
					format(str, sizeof(str), "Static");
					SetTimerEx("SprayingTags", 10000, false, "isiffffff", playerid, str, 1, x, y, z, rx, ry, rz);
						
					ApplyAnimation(playerid, "GRAFFITI", "null", 4.0, 0, 0, 0, 0, 0, 0);
					ApplyAnimation(playerid, "GRAFFITI", "spraycan_fire", 4.0, 1, 0, 0, 0, 0, 1);
				    ApplyAnimation(playerid, "GRAFFITI", "spraycan_fire", 4.0, 1, 0, 0, 0, 0, 1);

					SetPlayerAttachedObject(playerid, ATTACH_HAND, 365, 6, 0.0000, 0.0000, 0.0360, 0.0000, 0.0000, 0.0000, 1.0000, 1.0000, 1.0000, 0xFFFFFFFF, 0xFFFFFFFF); // spraycan
					SetPlayerAttachedObject(playerid, ATTACH_HAND2, 18729, 6, 0.0460, 1.6179, 0.1640, 92.2999, 0.0000, -78.4000, 1.0000, 1.0000, 1.0000, 0xFFFFFFFF, 0xFFFFFFFF); //spraycan	
				}
			}
			
			case 2:
			{
				if(response == EDIT_RESPONSE_CANCEL)
				{
					PlayerInfo[playerid][E_CHARACTER_EDITINGOBJECT] = 0; 
					PlayerInfo[playerid][E_CHARACTER_OBJECTID] = 0;
					PlayerInfo[playerid][E_CHARACTER_OBJECTTYPE] = 0;
					PlayerInfo[playerid][E_CHARACTER_OBJECTOWN] = 0;
		
					DestroyDynamicObject(PlayerInfo[playerid][E_CHARACTER_ADDOBJECT]);
		
					SendErrorMessage(playerid, "You're no longer editing a shooting ball blue team."); 
					return 1;
				}
				
				if(response == EDIT_RESPONSE_FINAL)
				{
					CourtInfo[PlayerInfo[playerid][E_CHARACTER_OBJECTID]][E_BLUE_BALL][0] = x;
					CourtInfo[PlayerInfo[playerid][E_CHARACTER_OBJECTID]][E_BLUE_BALL][1] = y;
					CourtInfo[PlayerInfo[playerid][E_CHARACTER_OBJECTID]][E_BLUE_BALL][2] = z;
					Court_Save(PlayerInfo[playerid][E_CHARACTER_OBJECTID]);
					Court_Refresh(PlayerInfo[playerid][E_CHARACTER_OBJECTID]);

					PlayerInfo[playerid][E_CHARACTER_EDITINGOBJECT] = 0; 
					PlayerInfo[playerid][E_CHARACTER_OBJECTID] = 0;
					PlayerInfo[playerid][E_CHARACTER_OBJECTTYPE] = 0;
					PlayerInfo[playerid][E_CHARACTER_OBJECTOWN] = 0;
					DestroyDynamicObject(PlayerInfo[playerid][E_CHARACTER_ADDOBJECT]);

					SendServerMessage(playerid, "You're set shooting ball red team."); 
					return 1;
				}
			}
			case 3:
			{
				if(response == EDIT_RESPONSE_CANCEL)
				{
					PlayerInfo[playerid][E_CHARACTER_EDITINGOBJECT] = 0; 
					PlayerInfo[playerid][E_CHARACTER_OBJECTID] = 0;
					PlayerInfo[playerid][E_CHARACTER_OBJECTTYPE] = 0;
					PlayerInfo[playerid][E_CHARACTER_OBJECTOWN] = 0;
					DestroyDynamicObject(PlayerInfo[playerid][E_CHARACTER_ADDOBJECT]);

					SendErrorMessage(playerid, "You're no longer editing a shooting ball blue team."); 
					return 1;
				}
				if(response == EDIT_RESPONSE_FINAL)
				{
					CourtInfo[PlayerInfo[playerid][E_CHARACTER_OBJECTID]][E_RED_BALL][0] = x;
					CourtInfo[PlayerInfo[playerid][E_CHARACTER_OBJECTID]][E_RED_BALL][1] = y;
					CourtInfo[PlayerInfo[playerid][E_CHARACTER_OBJECTID]][E_RED_BALL][2] = z;
					Court_Save(PlayerInfo[playerid][E_CHARACTER_OBJECTID]);
					Court_Refresh(PlayerInfo[playerid][E_CHARACTER_OBJECTID]);

					PlayerInfo[playerid][E_CHARACTER_EDITINGOBJECT] = 0; 
					PlayerInfo[playerid][E_CHARACTER_OBJECTID] = 0;
					PlayerInfo[playerid][E_CHARACTER_OBJECTTYPE] = 0;
					PlayerInfo[playerid][E_CHARACTER_OBJECTOWN] = 0;

					DestroyDynamicObject(PlayerInfo[playerid][E_CHARACTER_ADDOBJECT]);
					SendServerMessage(playerid, "You're set shooting ball blue team."); 
					return 1;
				}
			}
			case 4:
			{
				if(response == EDIT_RESPONSE_CANCEL)
				{
					PlayerInfo[playerid][E_CHARACTER_EDITINGOBJECT] = 0; 
					PlayerInfo[playerid][E_CHARACTER_OBJECTID] = 0;
					PlayerInfo[playerid][E_CHARACTER_OBJECTTYPE] = 0;
					PlayerInfo[playerid][E_CHARACTER_OBJECTOWN] = 0;
		
					DestroyDynamicObject(PlayerInfo[playerid][E_CHARACTER_ADDOBJECT]);
		
					SendErrorMessage(playerid, "You're no longer editing tree."); 
					return 1;
				}

				if(response == EDIT_RESPONSE_FINAL)
				{
					PlayerInfo[playerid][E_CHARACTER_EDITINGOBJECT] = 0; 

					TreeInfo[PlayerInfo[playerid][E_CHARACTER_OBJECTID]][E_TREE_POS][0] = x;
					TreeInfo[PlayerInfo[playerid][E_CHARACTER_OBJECTID]][E_TREE_POS][1] = y;
					TreeInfo[PlayerInfo[playerid][E_CHARACTER_OBJECTID]][E_TREE_POS][2] = z;
					TreeInfo[PlayerInfo[playerid][E_CHARACTER_OBJECTID]][E_TREE_POS][3] = rx;
					TreeInfo[PlayerInfo[playerid][E_CHARACTER_OBJECTID]][E_TREE_POS][4] = ry;
					TreeInfo[PlayerInfo[playerid][E_CHARACTER_OBJECTID]][E_TREE_POS][5] = rz;

					Tree_Save(PlayerInfo[playerid][E_CHARACTER_OBJECTID]);
					Tree_Refresh(PlayerInfo[playerid][E_CHARACTER_OBJECTID]);
					SendServerMessage(playerid, "You're created tree ID #%d", PlayerInfo[playerid][E_CHARACTER_OBJECTID]);
					return 1;
				}
			}
			case 5:
			{
				if(response == EDIT_RESPONSE_CANCEL)
				{
					PlayerInfo[playerid][E_CHARACTER_EDITINGOBJECT] = 0; 
					PlayerInfo[playerid][E_CHARACTER_OBJECTID] = 0;
					PlayerInfo[playerid][E_CHARACTER_OBJECTTYPE] = 0;
					PlayerInfo[playerid][E_CHARACTER_OBJECTQUANTITY] = 0;
					PlayerInfo[playerid][E_CHARACTER_OBJECTOWN] = 0;
					format(PlayerInfo[playerid][E_CHARACTER_OBJECTSTRING], 512, "");

					DestroyDynamicObject(PlayerInfo[playerid][E_CHARACTER_ADDOBJECT]);
					SendErrorMessage(playerid, "You're no longer moved a dropped items."); 
					return 1;
				}

				if(response == EDIT_RESPONSE_FINAL)
				{
					DropItem(PlayerInfo[playerid][E_CHARACTER_OBJECTSTRING], ReturnSettingsName(playerid, playerid), PlayerInfo[playerid][E_CHARACTER_OBJECTID], PlayerInfo[playerid][E_CHARACTER_OBJECTQUANTITY], x, y, z, rx, ry, rz, GetPlayerInterior(playerid), GetPlayerVirtualWorld(playerid), PlayerInfo[playerid][E_CHARACTER_OBJECTTYPE]);
					Inventory_Remove(playerid, PlayerInfo[playerid][E_CHARACTER_OBJECTSTRING], PlayerInfo[playerid][E_CHARACTER_OBJECTQUANTITY]);
					ApplyAnimation(playerid, "GRENADE", "WEAPON_throwu", 4.1, 0, 0, 0, 0, 0, 1);

					PlayerInfo[playerid][E_CHARACTER_EDITINGOBJECT] = 0; 
					PlayerInfo[playerid][E_CHARACTER_OBJECTID] = 0;
					PlayerInfo[playerid][E_CHARACTER_OBJECTTYPE] = 0;
					PlayerInfo[playerid][E_CHARACTER_OBJECTQUANTITY] = 0;
					PlayerInfo[playerid][E_CHARACTER_OBJECTOWN] = 0;
					format(PlayerInfo[playerid][E_CHARACTER_OBJECTSTRING], 512, "");
					DestroyDynamicObject(PlayerInfo[playerid][E_CHARACTER_ADDOBJECT]);
					SendServerMessage(playerid, "You're moved dropped items."); 
					return 1;
				}
			}
			case 6:
			{
				if(response == EDIT_RESPONSE_CANCEL)
				{
					PlayerInfo[playerid][E_CHARACTER_EDITINGOBJECT] = 0; 
					PlayerInfo[playerid][E_CHARACTER_OBJECTID] = 0;
					PlayerInfo[playerid][E_CHARACTER_OBJECTTYPE] = 0;
					PlayerInfo[playerid][E_CHARACTER_OBJECTQUANTITY] = 0;
					PlayerInfo[playerid][E_CHARACTER_OBJECTOWN] = 0;
					format(PlayerInfo[playerid][E_CHARACTER_OBJECTSTRING], 512, "");

					DestroyDynamicObject(PlayerInfo[playerid][E_CHARACTER_ADDOBJECT]);
					SendErrorMessage(playerid, "You're no longer moved a business point."); 
				}
				if(response == EDIT_RESPONSE_FINAL)
				{
					ConfirmDialog(playerid, "Confirmation", "Are you sure you want to change this businesses point?", "OnBusinessPointChange", IsPlayerInBusiness(playerid), x, y, z); 

					PlayerInfo[playerid][E_CHARACTER_EDITINGOBJECT] = 0; 
					PlayerInfo[playerid][E_CHARACTER_OBJECTID] = 0;
					PlayerInfo[playerid][E_CHARACTER_OBJECTTYPE] = 0;
					PlayerInfo[playerid][E_CHARACTER_OBJECTQUANTITY] = 0;
					PlayerInfo[playerid][E_CHARACTER_OBJECTOWN] = 0;
					format(PlayerInfo[playerid][E_CHARACTER_OBJECTSTRING], 512, "");

					DestroyDynamicObject(PlayerInfo[playerid][E_CHARACTER_ADDOBJECT]);
					SendServerMessage(playerid, "You're moved business point."); 
				}
			}
			case 7:
			{
				if(response == EDIT_RESPONSE_CANCEL)
				{
					PlayerInfo[playerid][E_CHARACTER_EDITINGOBJECT] = 0; 
					PlayerInfo[playerid][E_CHARACTER_OBJECTID] = 0;
					PlayerInfo[playerid][E_CHARACTER_OBJECTTYPE] = 0;
					PlayerInfo[playerid][E_CHARACTER_OBJECTQUANTITY] = 0;
					PlayerInfo[playerid][E_CHARACTER_OBJECTOWN] = 0;
					format(PlayerInfo[playerid][E_CHARACTER_OBJECTSTRING], 512, "");

					DestroyDynamicObject(PlayerInfo[playerid][E_CHARACTER_ADDOBJECT]);
					SendErrorMessage(playerid, "You're no longer moved a furniture."); 
				}
				if(response == EDIT_RESPONSE_FINAL)
				{
					new houseid = IsPlayerInProperty(playerid);

					if(houseid >= 0 && PropertyInfo[houseid][E_PROPERTY_OWNERDBID] == PlayerInfo[playerid][E_CHARACTER_DBID])
					{
					    if(PlayerInfo[playerid][E_CHARACTER_MONEY] < g_aFurnitureArray[PlayerInfo[playerid][E_CHARACTER_LISTITEM]][E_FURNITUREVAR_PRICE])
		                    return SendErrorMessage(playerid, "You can't afford this. (Cost: $%s, Total: $%s)", FormatMoney(g_aFurnitureArray[PlayerInfo[playerid][E_CHARACTER_LISTITEM]][E_FURNITUREVAR_PRICE]), FormatMoney(PlayerInfo[playerid][E_CHARACTER_MONEY]));

					    new
					        queryBuffer[512];

					    GiveMoney(playerid, -g_aFurnitureArray[PlayerInfo[playerid][E_CHARACTER_LISTITEM]][E_FURNITUREVAR_PRICE]);

						mysql_format(ourConnection, queryBuffer, sizeof(queryBuffer), "INSERT INTO furniture (`propertydbid`, `modelid`, `name`, `price`, `pos_x`, `pos_y`, `pos_z`, `rot_x`, `rot_y`, `rot_z`, `interior`, `world`) VALUES(%i, %i, '%e', %i, '%f', '%f', '%f', '%f', '%f', '%f', %i, %i)", PropertyInfo[houseid][E_PROPERTY_DBID], g_aFurnitureArray[PlayerInfo[playerid][E_CHARACTER_LISTITEM]][E_FURNITUREVAR_MODEL], g_aFurnitureArray[PlayerInfo[playerid][E_CHARACTER_LISTITEM]][E_FURNITUREVAR_NAME], g_aFurnitureArray[PlayerInfo[playerid][E_CHARACTER_LISTITEM]][E_FURNITUREVAR_PRICE], x, y, z, rx, ry, rz, PropertyInfo[houseid][E_PROPERTY_INTERIORINTERIOR], PropertyInfo[houseid][E_PROPERTY_INTERIORWORLD]);
						mysql_pquery(ourConnection, queryBuffer);

						mysql_pquery(ourConnection, "SELECT * FROM furniture WHERE id = LAST_INSERT_ID()", "Query_LoadFurniture", "i", PropertyInfo[houseid][E_PROPERTY_LABELS]);
					}
					
					PlayerInfo[playerid][E_CHARACTER_EDITINGOBJECT] = 0; 
					PlayerInfo[playerid][E_CHARACTER_OBJECTID] = 0;
					PlayerInfo[playerid][E_CHARACTER_OBJECTTYPE] = 0;
					PlayerInfo[playerid][E_CHARACTER_OBJECTQUANTITY] = 0;
					PlayerInfo[playerid][E_CHARACTER_OBJECTOWN] = 0;
					format(PlayerInfo[playerid][E_CHARACTER_OBJECTSTRING], 512, "");
				}
			}
			case 8:
			{
				if(response == EDIT_RESPONSE_FINAL)
				{
					new queryBuffer[512];
					mysql_format(ourConnection, queryBuffer, sizeof(queryBuffer), "UPDATE furniture SET pos_x = '%f', pos_y = '%f', pos_z = '%f', rot_x = '%f', rot_y = '%f', rot_z = '%f' WHERE id = %i", x, y, z, rx, ry, rz, Streamer_GetExtraInt(objectid, E_OBJECT_INDEX_ID));
					mysql_tquery(ourConnection, queryBuffer);

					ReloadFurniture(objectid, PropertyInfo[PlayerInfo[playerid][E_CHARACTER_SELECTINDEX]][E_PROPERTY_LABELS]);
				}
				if(response == EDIT_RESPONSE_CANCEL)
				{
					ReloadFurniture(objectid, PropertyInfo[PlayerInfo[playerid][E_CHARACTER_SELECTINDEX]][E_PROPERTY_LABELS]);
				}
			}
		}
		
	}

	return 1;
}

public OnVehicleSpawn(vehicleid)
{
	if(HasNoEngine(vehicleid))
		ToggleVehicleEngine(vehicleid, true);
		
	printf("[DEBUG] Vehicle ID %i was respawned.", vehicleid);
	return 1;
}

function:RefreshCharacters(playerid)
{
	if (!IsPlayerConnected(playerid))
	    return 0;

	SendServerMessage(playerid, "Your character list has been refreshed."); 
	
	new 
		fetchChars[128];
	
	mysql_format(ourConnection, fetchChars, sizeof(fetchChars), "SELECT * FROM characters WHERE `master_dbid` = '%d' LIMIT 4", AccountInfo[playerid][E_MASTERS_DBID]);
	mysql_pquery(ourConnection, fetchChars, "DB_ListCharacters", "i", playerid);
	return 1; 
}

function:Query_CreateStreetNames(playerid)
{
	if(cache_num_rows())
	{
		return SendClientMessage(playerid, COLOR_RED, "[ERROR]: That streetname already exists. Please try again."); 
	}
	else
	{
		new
			string[128]
		;
		
		for (new i = 0; i < 20; i++){SendClientMessage(playerid, -1, " "); }
		
		format (string, sizeof(string), "Your new characters street name will be: {5B9460}%s", playerCharactersStreetName[playerid]);
		SendClientMessage(playerid, -1, string); 

		SendClientMessage(playerid, -1, " "); 
		SendClientMessage(playerid, -1, "The next steps will require a background for your new character.");
		SendClientMessage(playerid, -1, "Please provide your characters date of birth. The format: {5B9460}02/02/1960");
		SendClientMessage(playerid, -1, "Press {5B9460}'T'{ffffff} to inputtext for character creation.");
		playerCharacterStep[playerid] = 3; 
	}
	return 1;
}

function:Query_CreateCharacter(playerid)
{
	if(cache_num_rows())
	{
		return SendClientMessage(playerid, COLOR_RED, "[ERROR]: That character already exists. Please try again."); 
	}
	else
	{
		new
			string[128]
		;
		
		for (new i = 0; i < 20; i++){SendClientMessage(playerid, -1, " "); }
		
		format (string, sizeof(string), "Your new characters name will be: {5B9460}%s", playerCharactersName[playerid]);
		SendClientMessage(playerid, -1, string); 

		SendClientMessage(playerid, -1, " "); 
		SendClientMessage(playerid, -1, "The next steps will require a creating characters street name.");
		SendClientMessage(playerid, -1, "Please begin by typing your characters street name. i.e: {5B9460}RayRay");
		SendClientMessage(playerid, -1, "Your characters name must be in 'Streetname' format with no numbers or special characters.");
		SendClientMessage(playerid, -1, "Press {5B9460}'T'{ffffff} to inputtext for character creation.");
		playerCharacterStep[playerid] = 2; 
	}
	return 1;
}

function:SaveCharacterPos(playerid)
{
	new thread[512]; 
	
	if(PlayerInfo[playerid][E_CHARACTER_ADMINDUTY])
		return 0;

	GetPlayerPos(playerid, PlayerInfo[playerid][E_CHARACTER_LASTPOS][0], PlayerInfo[playerid][E_CHARACTER_LASTPOS][1], PlayerInfo[playerid][E_CHARACTER_LASTPOS][2]);
	
	GetPlayerHealth(playerid, PlayerInfo[playerid][E_CHARACTER_HEALTH]);
	GetPlayerArmour(playerid, PlayerInfo[playerid][E_CHARACTER_ARMOUR]);

	mysql_format(ourConnection, thread, sizeof(thread), "UPDATE characters SET pLastPosX = %f, pLastPosY = %f, pLastPosZ = %f, pLastInterior = %i, pLastWorld = %i, pInProperty = %i, pInBusiness = %i, pHasInjured = %i, pHasDeath = %i, pHealth = %f, pArmor = %f WHERE char_dbid = %i",
		PlayerInfo[playerid][E_CHARACTER_LASTPOS][0],
		PlayerInfo[playerid][E_CHARACTER_LASTPOS][1],
		PlayerInfo[playerid][E_CHARACTER_LASTPOS][2],
		GetPlayerInterior(playerid),
		GetPlayerVirtualWorld(playerid),
		PlayerInfo[playerid][E_CHARACTER_INSIDEPROP],
		PlayerInfo[playerid][E_CHARACTER_INSIDEBIZ],
		PlayerInfo[playerid][E_CHARACTER_INJURED],
		PlayerInfo[playerid][E_CHARACTER_DEATH],
		PlayerInfo[playerid][E_CHARACTER_HEALTH],
		PlayerInfo[playerid][E_CHARACTER_ARMOUR],
		PlayerInfo[playerid][E_CHARACTER_DBID]);
	
	return mysql_pquery(ourConnection, thread);
}

function:SaveCharacter(playerid)
{
	new query[1024];
	
	mysql_format(ourConnection, query, sizeof(query), "UPDATE masters SET forum_name = '%e', active_ip = '%e' WHERE acc_dbid = %i",	
		AccountInfo[playerid][E_MASTERS_FORUMNAME],
		PlayerInfo[playerid][E_CHARACTER_ACTIVEIP],
		AccountInfo[playerid][E_MASTERS_DBID]);
	mysql_pquery(ourConnection, query);
	
	mysql_format(ourConnection, query, sizeof(query), "UPDATE characters SET pAdmin = %i, pLastSkin = %i, pFacSkin = %i, pLevel = %i, pMoney = %i, pBank = %i, pPaycheck = %i, pPhone = %i, pLastOnline = '%e', pLastOnlineTime = %i, pAdminjailed = %i, pAdminJailTime = %i WHERE char_dbid = %i",
		PlayerInfo[playerid][E_CHARACTER_ADMIN],
		PlayerInfo[playerid][E_CHARACTER_LASTSKIN],
		PlayerInfo[playerid][E_CHARACTER_FACSKIN],
		PlayerInfo[playerid][E_CHARACTER_LEVEL],
		PlayerInfo[playerid][E_CHARACTER_MONEY],
		PlayerInfo[playerid][E_CHARACTER_BANK],
		PlayerInfo[playerid][E_CHARACTER_PAYCHECK],
		PlayerInfo[playerid][E_CHARACTER_PHONE],
		ReturnDate(),
		PlayerInfo[playerid][E_CHARACTER_LASTONLINE],
		PlayerInfo[playerid][E_CHARACTER_ADMINJAILED],
		PlayerInfo[playerid][E_CHARACTER_ADMINJAIL],
		PlayerInfo[playerid][E_CHARACTER_DBID]);
	mysql_pquery(ourConnection, query);
	
	mysql_format(ourConnection, query, sizeof(query), "UPDATE characters SET pFaction = %i, pFactionRank = %i, pFactionSubsets = %i, pVehicleSpawned = %i, pVehicleSpawnedID = %i, pTimeplayed = %i, pMaskID = %i, pMaskIDEx = %i, pOfflinejailed = 0, pHasAoe = %i WHERE char_dbid = %i", 
		PlayerInfo[playerid][E_CHARACTER_FACTION], 
		PlayerInfo[playerid][E_CHARACTER_FACTIONRANK], 
		PlayerInfo[playerid][E_CHARACTER_FACTIONSUBSETS], 
		PlayerInfo[playerid][E_CHARACTER_VEHICLESPAWNED],
		PlayerInfo[playerid][E_CHARACTER_VEHICLESPAWN],
		PlayerInfo[playerid][E_CHARACTER_TIMEPLAYED],
		PlayerInfo[playerid][E_CHARACTER_MASKID][0],
		PlayerInfo[playerid][E_CHARACTER_MASKID][1],
		PlayerInfo[playerid][E_CHARACTER_AOE],
		PlayerInfo[playerid][E_CHARACTER_DBID]);
	mysql_pquery(ourConnection, query);
	
	mysql_format(ourConnection, query, sizeof(query), "UPDATE characters SET pMainSlot = %i, pRobberyCooldown = %i, pSpawnPoint = %i, pWeaponsLicense = %i, pDriversLicense = %i, pPrison = %i, pPrisonTimes = %i, pFightstyle = %i WHERE char_dbid = %i",
		PlayerInfo[playerid][E_CHARACTER_MAINSLOT],
		PlayerInfo[playerid][E_CHARACTER_ROBBERYCD],
		PlayerInfo[playerid][E_CHARACTER_SPAWNPOINT],
		PlayerInfo[playerid][E_CHARACTER_WEAPLICENSE],
		PlayerInfo[playerid][E_CHARACTER_DRIVELICENSE],
		PlayerInfo[playerid][E_CHARACTER_PRISON],
		PlayerInfo[playerid][E_CHARACTER_PRISON],
		PlayerInfo[playerid][E_CHARACTER_FIGHTSTYLE],
		PlayerInfo[playerid][E_CHARACTER_DBID]);
	mysql_pquery(ourConnection, query);

	mysql_format(ourConnection, query, sizeof(query), "UPDATE characters SET pHungry = %d, pThirsty = %d, pStamina = %d, pMuscle = %d, pEXP = %d, pFear = %d, pRespect = %d, pJobs = %d, pTutorial = %d WHERE char_dbid = %i",
		PlayerInfo[playerid][E_CHARACTER_HUNGRY],
		PlayerInfo[playerid][E_CHARACTER_THIRSTY],
		PlayerInfo[playerid][E_CHARACTER_STAMINA],
		PlayerInfo[playerid][E_CHARACTER_MUSCLE],
		PlayerInfo[playerid][E_CHARACTER_EXP],
		PlayerInfo[playerid][E_CHARACTER_FEAR],
		PlayerInfo[playerid][E_CHARACTER_RESPECT],
		PlayerInfo[playerid][E_CHARACTER_JOBS],
		PlayerInfo[playerid][E_CHARACTER_TUTORIAL],
		PlayerInfo[playerid][E_CHARACTER_DBID]);
	mysql_pquery(ourConnection, query);
	
	for(new i = 1; i < 3; i++)
	{
		mysql_format(ourConnection, query, sizeof(query), "UPDATE characters SET pRadio%i = %i WHERE char_dbid = %i", 
			i, 
			PlayerInfo[playerid][E_CHARACTER_RADIO][i],
			PlayerInfo[playerid][E_CHARACTER_DBID]);
		mysql_pquery(ourConnection, query);
	}
	
	for(new i = 1; i < MAX_PLAYER_VEHICLES; i++)
	{
		mysql_format(ourConnection, query, sizeof(query), "UPDATE characters SET pOwnedVehicles%d = %i WHERE char_dbid = %i", i, PlayerInfo[playerid][E_CHARACTER_OWNEDVEHICLE][i], PlayerInfo[playerid][E_CHARACTER_DBID]);
		mysql_pquery(ourConnection, query);
	}
	return 1;
}

public OnWorldTimeUpdate(hour, minute)
{
  	SetClock(hour, minute);

  	new str[16];

  	format(str, sizeof(str), "worldtime %02d:%02d", hour, minute);
 	SendRconCommand(str);
  	return 1;
}

//ObjectMove
public OnObjectMoved(objectid)
{
    return 1;
}

public OnIncomingRPC(playerid, rpcid, BitStream:bs)
{
    if (rpcid == 136)
    {
        new currentTime = GetTickCount();

        if (player_rpc_count[playerid] == 0)
        {
            player_rpc_count[playerid] = 1;
            player_rpc_last_time[playerid] = currentTime;
        }
        else
        {
            if (currentTime - player_rpc_last_time[playerid] <= 3000)
            {
                player_rpc_count[playerid]++;
                if (player_rpc_count[playerid] >= 5)
                {
                    new gstr[512];
                    format(gstr, sizeof(gstr), "[ANTI-CHEAT] %s has been detected for using program hack [Rem.cs]", ReturnSettingsName(playerid, playerid));
                    SendClientMessageToAll(COLOR_YELLOW, gstr);

                    player_rpc_count[playerid] = 0;
                    player_rpc_last_time[playerid] = 0;
                }
            }
            else
            {

                player_rpc_count[playerid] = 1;
                player_rpc_last_time[playerid] = currentTime;
            }
        }
    }
    return 1;
}

public OnDynamicObjectMoved(objectid)
{
	// Basketball:
	foreach(new pid : Player)
	{
		new i = CourtInfo[PlayerInfo[pid][E_CHARACTER_COURT]][E_BALLER];
		if(CourtInfo[PlayerInfo[pid][E_CHARACTER_COURT]][E_BALL_SHOOT] == 2)
		{
			BallDowns(i, 1);
			return 1;
		}
		else if(CourtInfo[PlayerInfo[pid][E_CHARACTER_COURT]][E_BALL_SHOOT] == 3)
		{
			BallDowns(i, 2);
			return 1;
		}
		else if(CourtInfo[PlayerInfo[pid][E_CHARACTER_COURT]][E_BALL_SHOOT] == 4)
		{
			BallDowns(i, 3);
			return 1;
		}
		else if(CourtInfo[PlayerInfo[pid][E_CHARACTER_COURT]][E_BALL_SHOOT] == 5)
		{
			BallDowns(i, 4);
			return 1;
		}
		else if(CourtInfo[PlayerInfo[pid][E_CHARACTER_COURT]][E_BALL_SHOOT] == 6)
		{
			ApplyAnimation(i,"BSKTBALL","BBALL_walk",4.1,1,1,1,1,1);
			PlayerInfo[i][E_CHARACTER_HAVEBALL] = 1;
			PlayerInfo[i][E_CHARACTER_ANIMBALL] = 0;
		}
		if(CourtInfo[PlayerInfo[pid][E_CHARACTER_COURT]][E_BALL_BOUNCE] == 1)
		{
			new Float:x, Float:y, Float:z;
			GetDynamicObjectPos(CourtInfo[PlayerInfo[pid][E_CHARACTER_COURT]][E_BALL_OBJECT], x, y, z);
			MoveDynamicObject(CourtInfo[PlayerInfo[pid][E_CHARACTER_COURT]][E_BALL_OBJECT], x, y, z+1.2, 6);
			CourtInfo[PlayerInfo[pid][E_CHARACTER_COURT]][E_BALL_BOUNCE] = 2;
		}
		else if(CourtInfo[PlayerInfo[pid][E_CHARACTER_COURT]][E_BALL_BOUNCE] == 2)
		{
			new Float:x, Float:y, Float:z;
			GetDynamicObjectPos(CourtInfo[PlayerInfo[pid][E_CHARACTER_COURT]][E_BALL_OBJECT], x, y, z);
			MoveDynamicObject(CourtInfo[PlayerInfo[pid][E_CHARACTER_COURT]][E_BALL_OBJECT], x, y, z-1.2, 6);
			CourtInfo[PlayerInfo[pid][E_CHARACTER_COURT]][E_BALL_BOUNCE] = 3;
		}
		else if(CourtInfo[PlayerInfo[pid][E_CHARACTER_COURT]][E_BALL_BOUNCE] == 3)
		{
			new Float:x, Float:y, Float:z;
			GetDynamicObjectPos(CourtInfo[PlayerInfo[pid][E_CHARACTER_COURT]][E_BALL_OBJECT], x, y, z);
			MoveDynamicObject(CourtInfo[PlayerInfo[pid][E_CHARACTER_COURT]][E_BALL_OBJECT], x, y, z+1.0, 6);
			CourtInfo[PlayerInfo[pid][E_CHARACTER_COURT]][E_BALL_BOUNCE] = 4;
		}
		else if(CourtInfo[PlayerInfo[pid][E_CHARACTER_COURT]][E_BALL_BOUNCE] == 4)
		{
			new Float:x, Float:y, Float:z;
			GetDynamicObjectPos(CourtInfo[PlayerInfo[pid][E_CHARACTER_COURT]][E_BALL_OBJECT], x, y, z);
			MoveDynamicObject(CourtInfo[PlayerInfo[pid][E_CHARACTER_COURT]][E_BALL_OBJECT], x, y, z-1.0, 6);
			CourtInfo[PlayerInfo[pid][E_CHARACTER_COURT]][E_BALL_BOUNCE] = 5;
		}
		else if(CourtInfo[PlayerInfo[pid][E_CHARACTER_COURT]][E_BALL_BOUNCE] == 5)
		{
			new Float:x, Float:y, Float:z;
			GetDynamicObjectPos(CourtInfo[PlayerInfo[pid][E_CHARACTER_COURT]][E_BALL_OBJECT], x, y, z);
			MoveDynamicObject(CourtInfo[PlayerInfo[pid][E_CHARACTER_COURT]][E_BALL_OBJECT], x, y, z+0.9, 6);
			CourtInfo[PlayerInfo[pid][E_CHARACTER_COURT]][E_BALL_BOUNCE] = 6;
		}
		else if(CourtInfo[PlayerInfo[pid][E_CHARACTER_COURT]][E_BALL_BOUNCE] == 6)
		{
			new Float:x, Float:y, Float:z;
			GetDynamicObjectPos(CourtInfo[PlayerInfo[pid][E_CHARACTER_COURT]][E_BALL_OBJECT], x, y, z);
			MoveDynamicObject(CourtInfo[PlayerInfo[pid][E_CHARACTER_COURT]][E_BALL_OBJECT], x, y, z-0.9, 6);
			CourtInfo[PlayerInfo[pid][E_CHARACTER_COURT]][E_BALL_BOUNCE] = 7;
		}
		else if(CourtInfo[PlayerInfo[pid][E_CHARACTER_COURT]][E_BALL_BOUNCE] == 7)
		{
			new Float:x, Float:y, Float:z;
			GetDynamicObjectPos(CourtInfo[PlayerInfo[pid][E_CHARACTER_COURT]][E_BALL_OBJECT], x, y, z);
			MoveDynamicObject(CourtInfo[PlayerInfo[pid][E_CHARACTER_COURT]][E_BALL_OBJECT], x, y, z+0.8, 6);
			CourtInfo[PlayerInfo[pid][E_CHARACTER_COURT]][E_BALL_BOUNCE] = 8;
		}
		else if(CourtInfo[PlayerInfo[pid][E_CHARACTER_COURT]][E_BALL_BOUNCE] == 8)
		{
			new Float:x, Float:y, Float:z;
			GetDynamicObjectPos(CourtInfo[PlayerInfo[pid][E_CHARACTER_COURT]][E_BALL_OBJECT], x, y, z);
			MoveDynamicObject(CourtInfo[PlayerInfo[pid][E_CHARACTER_COURT]][E_BALL_OBJECT], x, y, z-0.8, 6);
			CourtInfo[PlayerInfo[pid][E_CHARACTER_COURT]][E_BALL_BOUNCE] = 0;
		}
		else if(CourtInfo[PlayerInfo[pid][E_CHARACTER_COURT]][E_BALL_BOUNCE] == 9)
		{
			new Float:x, Float:y, Float:z;
			GetDynamicObjectPos(CourtInfo[PlayerInfo[pid][E_CHARACTER_COURT]][E_BALL_OBJECT], x, y, z);
			MoveDynamicObject(CourtInfo[PlayerInfo[pid][E_CHARACTER_COURT]][E_BALL_OBJECT], x, y, z-2.6, 6);
			CourtInfo[PlayerInfo[pid][E_CHARACTER_COURT]][E_BALL_BOUNCE] = 1;
		}

		// Have Ball:
		if(!PlayerInfo[i][E_CHARACTER_HAVEBALL]) return 1;
		new Keys, ud, lr;
		GetPlayerKeys(i, Keys, ud, lr);
		if(PlayerInfo[i][E_CHARACTER_ANIMBALL])
		{
			switch(CourtInfo[PlayerInfo[pid][E_CHARACTER_COURT]][E_BALL_STATUS])
			{
				case 0:
				{
					CourtInfo[PlayerInfo[pid][E_CHARACTER_COURT]][E_BALL_STATUS] = 1;
					new Float:x, Float:y, Float:z;
					GetPlayerPos(i, x, y, z);
					StopDynamicObject(CourtInfo[PlayerInfo[pid][E_CHARACTER_COURT]][E_BALL_OBJECT]);
					new Float:x2, Float:y2;
					GetXYInFrontOfPlayer(i, x2, y2, 0.4);
					MoveDynamicObject(CourtInfo[PlayerInfo[pid][E_CHARACTER_COURT]][E_BALL_OBJECT], x2, y2, z+0.1, 10);
					PlayNearbySound(PlayerInfo[pid][E_CHARACTER_COURT], 4600);
				}
				case 1:
				{
					CourtInfo[PlayerInfo[pid][E_CHARACTER_COURT]][E_BALL_STATUS] = 0;
					new Float:x, Float:y, Float:z;
					GetPlayerPos(i, x, y, z);
					StopDynamicObject(CourtInfo[PlayerInfo[pid][E_CHARACTER_COURT]][E_BALL_OBJECT]);
					new Float:x2, Float:y2;
					GetXYInFrontOfPlayer(i, x2, y2, 0.4);
					MoveDynamicObject(CourtInfo[PlayerInfo[pid][E_CHARACTER_COURT]][E_BALL_OBJECT], x2, y2, z-0.8, 10);
					PlayNearbySound(PlayerInfo[pid][E_CHARACTER_COURT], 4600);
				}
			}
			return 1;
		}
		if(Keys & KEY_SPRINT)
		{
			ApplyAnimation(i,"BSKTBALL","BBALL_run",4.1,1,1,1,1,1);
			switch(CourtInfo[PlayerInfo[pid][E_CHARACTER_COURT]][E_BALL_STATUS])
			{
				case 0:
				{
					CourtInfo[PlayerInfo[pid][E_CHARACTER_COURT]][E_BALL_STATUS] = 1;
					new Float:x, Float:y, Float:z;
					GetPlayerPos(i, x, y, z);
					StopDynamicObject(CourtInfo[PlayerInfo[pid][E_CHARACTER_COURT]][E_BALL_OBJECT]);
					new Float:x2, Float:y2;
					GetXYInFrontOfPlayer(i, x2, y2, 1.5);
					MoveDynamicObject(CourtInfo[PlayerInfo[pid][E_CHARACTER_COURT]][E_BALL_OBJECT], x2, y2, z+0.1, 10);
					PlayNearbySound(PlayerInfo[pid][E_CHARACTER_COURT], 4600);
				}
				case 1:
				{
					CourtInfo[PlayerInfo[pid][E_CHARACTER_COURT]][E_BALL_STATUS] = 0;
					new Float:x, Float:y, Float:z;
					GetPlayerPos(i, x, y, z);
					StopDynamicObject(CourtInfo[PlayerInfo[pid][E_CHARACTER_COURT]][E_BALL_OBJECT]);
					new Float:x2, Float:y2;
					GetXYInFrontOfPlayer(i, x2, y2, 1.5);
					MoveDynamicObject(CourtInfo[PlayerInfo[pid][E_CHARACTER_COURT]][E_BALL_OBJECT], x2, y2, z-0.8, 10);
					PlayNearbySound(PlayerInfo[pid][E_CHARACTER_COURT], 4600);
				}
			}
			return 1;
		}
		else
		{
			ApplyAnimation(i, "BSKTBALL","BBALL_walk",4.1,1,1,1,1,1);
		}
		switch(CourtInfo[PlayerInfo[pid][E_CHARACTER_COURT]][E_BALL_STATUS])
		{
			case 0:
			{
				CourtInfo[PlayerInfo[pid][E_CHARACTER_COURT]][E_BALL_STATUS] = 1;
				new Float:x, Float:y, Float:z;
				GetPlayerPos(i, x, y, z);
				StopDynamicObject(CourtInfo[PlayerInfo[pid][E_CHARACTER_COURT]][E_BALL_OBJECT]);
				new Float:x2, Float:y2;
				GetXYInFrontOfPlayer(i, x2, y2, 1.2);
				MoveDynamicObject(CourtInfo[PlayerInfo[pid][E_CHARACTER_COURT]][E_BALL_OBJECT], x2, y2, z+0.1, 10);
				PlayNearbySound(PlayerInfo[pid][E_CHARACTER_COURT], 4600);
			}
			case 1:
			{
				CourtInfo[PlayerInfo[pid][E_CHARACTER_COURT]][E_BALL_STATUS] = 0;
				new Float:x, Float:y, Float:z;
				GetPlayerPos(i, x, y, z);
				StopDynamicObject(CourtInfo[PlayerInfo[pid][E_CHARACTER_COURT]][E_BALL_OBJECT]);
				new Float:x2, Float:y2;
				GetXYInFrontOfPlayer(i, x2, y2, 1.2);
				MoveDynamicObject(CourtInfo[PlayerInfo[pid][E_CHARACTER_COURT]][E_BALL_OBJECT], x2, y2, z-0.8, 10);
				PlayNearbySound(PlayerInfo[pid][E_CHARACTER_COURT], 4600);
			}
		}
	}
	return 1;
}

public OnPlayerGiveDamageDynamicActor(playerid, actorid, Float:amount, weaponid, bodypart)
{
	if(BusinessInfo[IsPlayerInBusiness(playerid)][E_BUSINESS_ACTOR] == actorid  && PlayerInfo[playerid][E_CHARACTER_EXTORTION] == true)
	{
		if(PlayerInfo[playerid][E_CHARACTER_EXTORTIONPOINT] < 100.0)
			PlayerInfo[playerid][E_CHARACTER_EXTORTIONPOINT] += 10.0;

		else if(PlayerInfo[playerid][E_CHARACTER_EXTORTIONPOINT] > 100.0)
			PlayerInfo[playerid][E_CHARACTER_EXTORTIONPOINT] = 100.0;

		SetPlayerGameBar(playerid, PlayerInfo[playerid][E_CHARACTER_EXTORTIONPOINT]);
	}
	return 1;
}

public OnVehicleMod(playerid, vehicleid, componentid)
{
	new str1[512];
	new vehicleide = GetVehicleModel(vehicleid);
    new modok = islegalcarmod(vehicleide, componentid);
    if (!modok && ACPauseTimer[playerid] == 0 && PlayerInfo[playerid][E_CHARACTER_SPAWNED] == true) {
        format(str1, sizeof(str1), "%s has been detected for using program hack [Vehicle Mod Hack]", ReturnSettingsName(playerid, playerid)); 
		SendAdminMessage(1, str1);
        return 0; 
    }
	return 1;
}