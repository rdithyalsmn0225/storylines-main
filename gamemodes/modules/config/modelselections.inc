//Selection Character
#define SELECT_HOODRATS		(0)
#define SELECT_TDB			(11)

//Selection Skin
enum
{
    SELECT_MALESKIN,
    SELECT_FEMALESKIN,
    SELECT_POLICEMALESKIN,
    SELECT_POLICEFEMALESKIN,
    SELECT_MEDICMALESKIN,
    SELECT_MEDICFEMALESKIN,
    SELECT_ACCESSORIES,
    SELECT_DEALERSHIP,
    SELECT_FURNITURE
};


ShowSelectionModel(playerid, type)
{
    new List:skins = list_new();
    switch(type)
    {
        case SELECT_MALESKIN:
        {
            for(new i; i < sizeof(g_aMaleSkins); i++)
            {
                AddModelMenuItem(skins, g_aMaleSkins[i]);
            }

            new response[E_MODEL_SELECTION_INFO];

            await_arr(response) ShowAsyncModelSelectionMenu(playerid, "Choose Skins", skins);

            if(response[E_MODEL_SELECTION_RESPONSE] == MODEL_RESPONSE_SELECT)
            {
                new businessid = IsPlayerInBusiness(playerid);
				if(BusinessInfo[businessid][E_BUSINESS_PRODUCTS][1] > PlayerInfo[playerid][E_CHARACTER_MONEY])
				{
					SetCameraBehindPlayer(playerid);
					SendErrorMessage(playerid, "You can't afford a clothes.");
					return 1;
				}

				if(BusinessInfo[businessid][E_BUSINESS_STOCK] < 1)
				{
					SetCameraBehindPlayer(playerid);
					return SendErrorMessage(playerid, "This business is out of stock");
				}

				SetTimerEx("EnterFittingRoom", 1000, false, "ii", playerid, response[E_MODEL_SELECTION_MODELID]);
            }
            else
            {
                SetCameraBehindPlayer(playerid);
				TogglePlayerControllable(playerid, true);
            }
        }
        case SELECT_FEMALESKIN:
        {
            for(new i; i < sizeof(g_aFemaleSkins); i++)
            {
                AddModelMenuItem(skins, g_aFemaleSkins[i]);
            }

            new response[E_MODEL_SELECTION_INFO];

            await_arr(response) ShowAsyncModelSelectionMenu(playerid, "Choose Skins", skins);

            if(response[E_MODEL_SELECTION_RESPONSE] == MODEL_RESPONSE_SELECT)
            {
                new businessid = IsPlayerInBusiness(playerid);
				if(BusinessInfo[businessid][E_BUSINESS_PRODUCTS][1] > PlayerInfo[playerid][E_CHARACTER_MONEY])
				{
                    TogglePlayerControllable(playerid, true);
					SetCameraBehindPlayer(playerid);
					SendErrorMessage(playerid, "You can't afford a clothes.");
					return 1;
				}

				if(BusinessInfo[businessid][E_BUSINESS_STOCK] < 1)
				{
                    TogglePlayerControllable(playerid, true);
					SetCameraBehindPlayer(playerid);
					return SendErrorMessage(playerid, "This business is out of stock");
				}

				SetTimerEx("EnterFittingRoom", 1000, false, "ii", playerid, g_aFemaleSkins[E_MODEL_SELECTION_MODELID]);
            }
            else
            {
                SetCameraBehindPlayer(playerid);
				TogglePlayerControllable(playerid, true);
            }
        }
        case SELECT_ACCESSORIES:
        {
            SetPlayerPos(playerid, 217.5163,-98.4308,1005.2578);
            SetPlayerFacingAngle(playerid, 94.6310);

            SetPlayerCameraPos(playerid, 214.387527, -99.966537, 1005.545410);
            SetPlayerCameraLookAt(playerid, 217.848388, -97.962821, 1005.458129, 1);

            for(new i; i < sizeof(g_aClothingCustom); i++)
            {
                AddModelMenuItem(skins, g_aClothingCustom[i]);
            }

            new response[E_MODEL_SELECTION_INFO];

            await_arr(response) ShowAsyncModelSelectionMenu(playerid, "Choose accessories", skins);

            if(response[E_MODEL_SELECTION_RESPONSE] == MODEL_RESPONSE_SELECT)
            {
                new businessid = IsPlayerInBusiness(playerid);
				if(BusinessInfo[businessid][E_BUSINESS_PRODUCTS][2] > PlayerInfo[playerid][E_CHARACTER_MONEY])
				{
                    TogglePlayerControllable(playerid, true);
					SetCameraBehindPlayer(playerid);
					SendErrorMessage(playerid, "You can't afford a clothing.");
					return 1;
				}

				if(BusinessInfo[IsPlayerInBusiness(playerid)][E_BUSINESS_STOCK] < 1)
				{
                    TogglePlayerControllable(playerid, true);
					SetCameraBehindPlayer(playerid);
					return SendErrorMessage(playerid, "This business is out of stock");
				}
				if(GetPlayerFreeToySlot(playerid) == -1)
				{
                    TogglePlayerControllable(playerid, true);
					SetCameraBehindPlayer(playerid);
					return SendErrorMessage(playerid, "You already have full slot of accessories!");
				}

				GiveMoney(playerid, -BusinessInfo[businessid][E_BUSINESS_PRODUCTS][2]);
				ApplyAnimation(playerid, "CLOTHES", "CLO_Buy", 4.0, 0, 0, 0, 0, 0);
				SetCameraBehindPlayer(playerid);
				BusinessInfo[IsPlayerInBusiness(playerid)][E_BUSINESS_STOCK]--;
				BusinessInfo[businessid][E_BUSINESS_CASH] += BusinessInfo[businessid][E_BUSINESS_PRODUCTS][2];
				ShowPlayerDialog(playerid, DIALOG_BUYCLOTHING, DIALOG_STYLE_LIST, "Bone Selection:", "Spine\nHead\nLeft upper arm\nRight upper arm\nLeft hand\nRight hand\nLeft thigh\nRight thigh\nLeft foot\nRight foot\nRight calf\nLeft calf\nLeft forearm\nRight forearm\nLeft shoulder\nRight shoulder\nNeck\nJaw", "Choose", "Cancel");
				PlayerInfo[playerid][E_CHARACTER_TEMPMODEL] = g_aClothingCustom[E_MODEL_SELECTION_MODELID];
            }
            else
			{
				SetCameraBehindPlayer(playerid);
				TogglePlayerControllable(playerid, true);
			}
        }
        case SELECT_POLICEMALESKIN:
        {
            for(new i; i < sizeof(g_aLspdSkins); i++)
            {
                AddModelMenuItem(skins, g_aLspdSkins[i]);
            }

            new response[E_MODEL_SELECTION_INFO];

            await_arr(response) ShowAsyncModelSelectionMenu(playerid, "Choose Skins", skins);

            if(response[E_MODEL_SELECTION_RESPONSE] == MODEL_RESPONSE_SELECT)
            {
                SetPlayerSkin(playerid, g_aLspdSkins[E_MODEL_SELECTION_MODELID]);
				PlayerInfo[playerid][E_CHARACTER_FACSKIN] = g_aLspdSkins[E_MODEL_SELECTION_MODELID];
				SaveCharacter(playerid);
            }
        }
        case SELECT_POLICEFEMALESKIN:
        {
            for(new i; i < sizeof(g_aLspdFemSkins); i++)
            {
                AddModelMenuItem(skins, g_aLspdFemSkins[i]);
            }

            new response[E_MODEL_SELECTION_INFO];

            await_arr(response) ShowAsyncModelSelectionMenu(playerid, "Choose Skins", skins);

            if(response[E_MODEL_SELECTION_RESPONSE] == MODEL_RESPONSE_SELECT)
            {
                SetPlayerSkin(playerid, g_aLspdFemSkins[E_MODEL_SELECTION_MODELID]);
				PlayerInfo[playerid][E_CHARACTER_FACSKIN] = g_aLspdFemSkins[E_MODEL_SELECTION_MODELID];
				SaveCharacter(playerid);
            }
        }
        case SELECT_MEDICMALESKIN:
        {
            for(new i; i < sizeof(g_aLsmdSkins); i++)
            {
                AddModelMenuItem(skins, g_aLsmdSkins[i]);
            }

            new response[E_MODEL_SELECTION_INFO];

            await_arr(response) ShowAsyncModelSelectionMenu(playerid, "Choose Skins", skins);

            if(response[E_MODEL_SELECTION_RESPONSE] == MODEL_RESPONSE_SELECT)
            {
                SetPlayerSkin(playerid, g_aLsmdSkins[E_MODEL_SELECTION_MODELID]);
				PlayerInfo[playerid][E_CHARACTER_FACSKIN] = g_aLsmdSkins[E_MODEL_SELECTION_MODELID];
				SaveCharacter(playerid);
            }
        }
        case SELECT_MEDICFEMALESKIN:
        {
            
            AddModelMenuItem(skins, 308);
        
            new response[E_MODEL_SELECTION_INFO];

            await_arr(response) ShowAsyncModelSelectionMenu(playerid, "Choose Skins", skins);

            if(response[E_MODEL_SELECTION_RESPONSE] == MODEL_RESPONSE_SELECT)
            {
                SetPlayerSkin(playerid, 308);
				PlayerInfo[playerid][E_CHARACTER_FACSKIN] = 308;
				SaveCharacter(playerid);
            }
        }
    }
    return 1;
}