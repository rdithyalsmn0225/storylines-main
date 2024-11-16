//Spraytags
stock Spraytags_Delete(spid)
{
	if (spid != -1 && SpraytagsInfo[spid][E_SPRAYTAGS_EXISTS])
	{
	    new
	        string[64];

		format(string, sizeof(string), "DELETE FROM `spray_tags` WHERE `id` = '%d'", SpraytagsInfo[spid][E_SPRAYTAGS_DBID]);
		mysql_pquery(ourConnection, string);

        for(new i = 0; i < 32; i++)
        {
            if (IsValidDynamicObject(SpraytagsInfo[spid][E_SPRAYTAGS_OBJECT]))
	            DestroyDynamicObject(SpraytagsInfo[spid][E_SPRAYTAGS_OBJECT]);
        }

	    SpraytagsInfo[spid][E_SPRAYTAGS_EXISTS] = false;
	    SpraytagsInfo[spid][E_SPRAYTAGS_DBID] = 0;
	}
	return 1;
}

Spraytags_Nearest(playerid)
{
    for (new i = 0; i != MAX_SPRAYTAGS; i ++) if (SpraytagsInfo[i][E_SPRAYTAGS_EXISTS] && IsPlayerInRangeOfPoint(playerid, 2.5, SpraytagsInfo[i][E_SPRAYTAGS_POS][0], SpraytagsInfo[i][E_SPRAYTAGS_POS][1], SpraytagsInfo[i][E_SPRAYTAGS_POS][2]))
	{
		if (GetPlayerInterior(playerid) == SpraytagsInfo[i][E_SPRAYTAGS_INTERIOR] && GetPlayerVirtualWorld(playerid) == SpraytagsInfo[i][E_SPRAYTAGS_WORLD])
			return i;
	}
	return -1;
}

stock Spraytags_Create(playerid, modelid, owner, text[], font, color, Float:x, Float:y, Float:z, Float:rx, Float:ry, Float:rz)
{
	DestroyDynamicObject(PlayerInfo[playerid][E_CHARACTER_ADDOBJECT]); 
	PlayerInfo[playerid][E_CHARACTER_EDITINGOBJECT] = 0; 
	PlayerInfo[playerid][E_CHARACTER_OBJECTID] = 0;
	PlayerInfo[playerid][E_CHARACTER_OBJECTTYPE] = 0;

	for (new i = 0; i < MAX_SPRAYTAGS; i ++) if (!SpraytagsInfo[i][E_SPRAYTAGS_EXISTS])
	{
	    SpraytagsInfo[i][E_SPRAYTAGS_EXISTS] = true;
	    SpraytagsInfo[i][E_SPRAYTAGS_OBJECTID]	= modelid;
	    SpraytagsInfo[i][E_SPRAYTAGS_TYPE]	= 1;
	    SpraytagsInfo[i][E_SPRAYTAGS_OWNER] = owner;
        format(SpraytagsInfo[i][E_SPRAYTAGS_TEXT], 128, "%s", text);
        format(SpraytagsInfo[i][E_SPRAYTAGS_FONT], 128, "%s", font);
        SpraytagsInfo[i][E_SPRAYTAGS_COLOR] = color;
        SpraytagsInfo[i][E_SPRAYTAGS_POS][0] = x;
        SpraytagsInfo[i][E_SPRAYTAGS_POS][1] = y;
        SpraytagsInfo[i][E_SPRAYTAGS_POS][2] = z;
        SpraytagsInfo[i][E_SPRAYTAGS_POS][3] = rx;
        SpraytagsInfo[i][E_SPRAYTAGS_POS][4] = ry;
        SpraytagsInfo[i][E_SPRAYTAGS_POS][5] = rz;
        SpraytagsInfo[i][E_SPRAYTAGS_TIMER] = 60;

        SpraytagsInfo[i][E_SPRAYTAGS_INTERIOR] = GetPlayerInterior(playerid);
        SpraytagsInfo[i][E_SPRAYTAGS_WORLD] = GetPlayerVirtualWorld(playerid);

		Spraytags_Refresh(i);
		mysql_pquery(ourConnection, "INSERT INTO `spray_tags` (`interior`) VALUES(0)", "OnSpraytagsCreated", "d", i);

		return i;
	}
	return -1;
}

stock Spraytags_Refresh(spid)
{
	if (spid != -1 && SpraytagsInfo[spid][E_SPRAYTAGS_EXISTS])
	{
        if (IsValidDynamicObject(SpraytagsInfo[spid][E_SPRAYTAGS_OBJECT]))
	        DestroyDynamicObject(SpraytagsInfo[spid][E_SPRAYTAGS_OBJECT]);

        if(SpraytagsInfo[spid][E_SPRAYTAGS_TYPE] == 1)
        {
            SpraytagsInfo[spid][E_SPRAYTAGS_OBJECT] = CreateDynamicObject(19482, SpraytagsInfo[spid][E_SPRAYTAGS_POS][0], SpraytagsInfo[spid][E_SPRAYTAGS_POS][1], SpraytagsInfo[spid][E_SPRAYTAGS_POS][2], SpraytagsInfo[spid][E_SPRAYTAGS_POS][3], SpraytagsInfo[spid][E_SPRAYTAGS_POS][4], SpraytagsInfo[spid][E_SPRAYTAGS_POS][5], SpraytagsInfo[spid][E_SPRAYTAGS_WORLD], SpraytagsInfo[spid][E_SPRAYTAGS_INTERIOR]);
            SetDynamicObjectMaterialText(SpraytagsInfo[spid][E_SPRAYTAGS_OBJECT], 0, SpraytagsInfo[spid][E_SPRAYTAGS_TEXT], OBJECT_MATERIAL_SIZE_512x256, SpraytagsInfo[spid][E_SPRAYTAGS_FONT], 40, 1, SpraytagsInfo[spid][E_SPRAYTAGS_COLOR], 0, OBJECT_MATERIAL_TEXT_ALIGN_CENTER);
        }
        return 1;
	}
	return 0;
}

function:Query_LoadSpraytags()
{
    static
	    rows,
	    fields;

	cache_get_row_count(rows);
	cache_get_field_count(fields);

	for (new i = 0; i < rows; i ++) if (i < MAX_SPRAYTAGS)
	{
	    SpraytagsInfo[i][E_SPRAYTAGS_EXISTS] = true;
	    cache_get_value_name_int(i, "id", SpraytagsInfo[i][E_SPRAYTAGS_DBID]);
	    cache_get_value_name_float(i, "posx", SpraytagsInfo[i][E_SPRAYTAGS_POS][0]);
        cache_get_value_name_float(i, "posy", SpraytagsInfo[i][E_SPRAYTAGS_POS][1]);
        cache_get_value_name_float(i, "posz", SpraytagsInfo[i][E_SPRAYTAGS_POS][2]);
        cache_get_value_name_float(i, "posrx", SpraytagsInfo[i][E_SPRAYTAGS_POS][3]);
        cache_get_value_name_float(i, "posry", SpraytagsInfo[i][E_SPRAYTAGS_POS][4]);
        cache_get_value_name_float(i, "posrz", SpraytagsInfo[i][E_SPRAYTAGS_POS][5]);
        cache_get_value_name_int(i, "interior", SpraytagsInfo[i][E_SPRAYTAGS_INTERIOR]);
		cache_get_value_name_int(i, "vw", SpraytagsInfo[i][E_SPRAYTAGS_WORLD]);
		cache_get_value_name_int(i, "models", SpraytagsInfo[i][E_SPRAYTAGS_OBJECTID]);
		cache_get_value_name_int(i, "type", SpraytagsInfo[i][E_SPRAYTAGS_TYPE]);
        cache_get_value_name(i, "text", SpraytagsInfo[i][E_SPRAYTAGS_TEXT], 128);
        cache_get_value_name(i, "font", SpraytagsInfo[i][E_SPRAYTAGS_FONT], 128);
        cache_get_value_name_int(i, "color", SpraytagsInfo[i][E_SPRAYTAGS_COLOR]);
		cache_get_value_name_int(i, "owner", SpraytagsInfo[i][E_SPRAYTAGS_OWNER]);

		Spraytags_Refresh(i);
	}
	return 1;
}

function:OnSpraytagsCreated(spid)
{
    if (spid == -1 || !SpraytagsInfo[spid][E_SPRAYTAGS_EXISTS])
		return 0;

	SpraytagsInfo[spid][E_SPRAYTAGS_DBID] = cache_insert_id();
 	Spraytags_Save(spid);

	return 1;
}

function:SprayingTags(playerid, inputtext[], type, Float:x, Float:y, Float:z, Float:rx, Float:ry, Float:rz)
{
    switch(type)
    {
        case 1: //CreateSpraytags
        {
            new idx = Spraytags_Nearest(playerid);
			idx = Spraytags_Create(playerid, PlayerInfo[playerid][E_CHARACTER_OBJECTID], PlayerInfo[playerid][E_CHARACTER_OBJECTOWN], PlayerInfo[playerid][E_CHARACTER_OBJECTSTRING], PlayerInfo[playerid][E_CHARACTER_OBJECTFONT], PlayerInfo[playerid][E_CHARACTER_OBJECTCOLOR], x, y, z, rx, ry, rz);
	    			
	    	if (idx == -1)
	    		return SendErrorMessage(playerid, "You can't make anymore spraytags.");	

            RemovePlayerAttachedObject(playerid, 8);
            RemovePlayerAttachedObject(playerid, 9);
            ClearAnimations(playerid);
			Inventory_Remove(playerid, "Spraycan", 1);

			if(PlayerInfo[playerid][E_CHARACTER_EQUIPITEMS] > INVENTORY_NONE)
			{
				ResetVarInventory(playerid);
			}
        }
    }
    return 1;
}

CMD:spray(playerid, params[])
{
	if(PlayerInfo[playerid][E_CHARACTER_EQUIPITEMS] != SPRAYCAN)
		return SendErrorMessage(playerid, "You must hold the spraycan in your hands.");

    if(PlayerInfo[playerid][E_CHARACTER_LEVEL] < 3)
        return SendErrorMessage(playerid, "You can't make spraytags because your level must be level 3."); 

    if(!Inventory_Count(playerid, "Spraycan"))
        return SendErrorMessage(playerid, "You don't have any spraycan in your inventory."); 
        
    Dialog_Show(playerid, SprayFont, DIALOG_STYLE_INPUT, "Spraytags:", "The font you input will only be visible to visual players that only have that font\nPlease input the font below:", "Input", "Cancel");
	return 1;
}

Dialog:SprayFont(playerid, response, listitem, inputtext[])
{
    if(response)
    {
        if (isnull(inputtext) || !FilterInputFont(inputtext) || strlen(inputtext) < 5)
            return Dialog_Show(playerid, SprayFont, DIALOG_STYLE_INPUT, "Spraytags Fonts:", "Your spraytags will replace the spraytags with custom font.\nThe font you input will only be visible to visual players that only have that font\nPlease input the font below:", "Input", "Cancel");

        format(PlayerInfo[playerid][E_CHARACTER_OBJECTFONT], 512, inputtext);

        new str[256];
        strcat(str, "{2C6B2F}Green\n");
        strcat(str, "{9EC9A0}Light Green\n");
        strcat(str, "{6D9D6F}Dark Green\n");
        strcat(str, "{6C1D8A}Purple\n");
        strcat(str, "{9B4F8F}Light Purple\n");
        strcat(str, "{8A2C7C}Medium Purple\n");
        strcat(str, "{AC09C7}Dark Purple\n");
        strcat(str, "{7BEDff}Cyan\n");
        strcat(str, "{FFDF7B}Yellow\n");
        strcat(str, "{D7A542}Orange\n");
        strcat(str, "{FF0000}Red\n");
        strcat(str, "{0055FF}Blue\n");
        
        Dialog_Show(playerid, SprayColor, DIALOG_STYLE_LIST, "Spraytags Colors:", str, "Select", "Cancel");
    }
    return 1;
}

Dialog:SprayColor(playerid, response, listitem, inputtext[])
{
    if(response)
    {
        switch(listitem)
        {
            case 0:
            {
                new iColor = HexToInt("0xFF2C6B2F");
                PlayerInfo[playerid][E_CHARACTER_OBJECTCOLOR] = iColor;
                Dialog_Show(playerid, SprayText, DIALOG_STYLE_INPUT, "Spraytags Texts:", "Allowed letter is A - Z and ( ) - = / ? \nTo break the letter use \"|\"\nPlease input the letter below:", "Input", "Cancel");
            }
            case 1:
            {
                new iColor = HexToInt("0xFF9EC9A0");
                PlayerInfo[playerid][E_CHARACTER_OBJECTCOLOR] = iColor;
                Dialog_Show(playerid, SprayText, DIALOG_STYLE_INPUT, "Spraytags Texts:", "Allowed letter is A - Z and ( ) - = / ? \nTo break the letter use \"|\"\nPlease input the letter below:", "Input", "Cancel");
            }
            case 2:
            {
                new iColor = HexToInt("0xFF6D9D6F");
                PlayerInfo[playerid][E_CHARACTER_OBJECTCOLOR] = iColor;
                Dialog_Show(playerid, SprayText, DIALOG_STYLE_INPUT, "Spraytags Texts:", "Allowed letter is A - Z and ( ) - = / ? \nTo break the letter use \"|\"\nPlease input the letter below:", "Input", "Cancel");
            }
            case 3:
            {
                new iColor = HexToInt("0xFF6C1D8A");
                PlayerInfo[playerid][E_CHARACTER_OBJECTCOLOR] = iColor;
                Dialog_Show(playerid, SprayText, DIALOG_STYLE_INPUT, "Spraytags Texts:", "Allowed letter is A - Z and ( ) - = / ? \nTo break the letter use \"|\"\nPlease input the letter below:", "Input", "Cancel");
            }
            case 4:
            {
                new iColor = HexToInt("0xFF9B4F8F");
                PlayerInfo[playerid][E_CHARACTER_OBJECTCOLOR] = iColor;
                Dialog_Show(playerid, SprayText, DIALOG_STYLE_INPUT, "Spraytags Texts:", "Allowed letter is A - Z and ( ) - = / ? \nTo break the letter use \"|\"\nPlease input the letter below:", "Input", "Cancel");
            }
            case 5:
            {
                new iColor = HexToInt("0xFF8A2C7C");
                PlayerInfo[playerid][E_CHARACTER_OBJECTCOLOR] = iColor;
                Dialog_Show(playerid, SprayText, DIALOG_STYLE_INPUT, "Spraytags Texts:", "Allowed letter is A - Z and ( ) - = / ? \nTo break the letter use \"|\"\nPlease input the letter below:", "Input", "Cancel");
            }
            case 6:
            {
                new iColor = HexToInt("0xFFAC09C7");
                PlayerInfo[playerid][E_CHARACTER_OBJECTCOLOR] = iColor;
                Dialog_Show(playerid, SprayText, DIALOG_STYLE_INPUT, "Spraytags Texts:", "Allowed letter is A - Z and ( ) - = / ? \nTo break the letter use \"|\"\nPlease input the letter below:", "Input", "Cancel");
            }
            case 7:
            {
                new iColor = HexToInt("0xFF7BEDff");
                PlayerInfo[playerid][E_CHARACTER_OBJECTCOLOR] = iColor;
                Dialog_Show(playerid, SprayText, DIALOG_STYLE_INPUT, "Spraytags Texts:", "Allowed letter is A - Z and ( ) - = / ? \nTo break the letter use \"|\"\nPlease input the letter below:", "Input", "Cancel");
            }
            case 8:
            {
                new iColor = HexToInt("0xFFFFDF7B");
                PlayerInfo[playerid][E_CHARACTER_OBJECTCOLOR] = iColor;
                Dialog_Show(playerid, SprayText, DIALOG_STYLE_INPUT, "Spraytags Texts:", "Allowed letter is A - Z and ( ) - = / ? \nTo break the letter use \"|\"\nPlease input the letter below:", "Input", "Cancel");
            }
            case 9:
            {
                new iColor = HexToInt("0xFFD7A542");
                PlayerInfo[playerid][E_CHARACTER_OBJECTCOLOR] = iColor;
                Dialog_Show(playerid, SprayText, DIALOG_STYLE_INPUT, "Spraytags Texts:", "Allowed letter is A - Z and ( ) - = / ? \nTo break the letter use \"|\"\nPlease input the letter below:", "Input", "Cancel");
            }
            case 10:
            {
                new iColor = HexToInt("0xFFFF0000");
                PlayerInfo[playerid][E_CHARACTER_OBJECTCOLOR] = iColor;
                Dialog_Show(playerid, SprayText, DIALOG_STYLE_INPUT, "Spraytags Texts:", "Allowed letter is A - Z and ( ) - = / ? \nTo break the letter use \"|\"\nPlease input the letter below:", "Input", "Cancel");
            }
            case 11:
            {
                new iColor = HexToInt("0xFF0055FF");
                PlayerInfo[playerid][E_CHARACTER_OBJECTCOLOR] = iColor;
                Dialog_Show(playerid, SprayText, DIALOG_STYLE_INPUT, "Spraytags Texts:", "Allowed letter is A - Z and ( ) - = / ? \nTo break the letter use \"|\"\nPlease input the letter below:", "Input", "Cancel");
            }
        }
    }
    return 1;
}

Dialog:SprayText(playerid, response, listitem, inputtext[])
{
    if (response) 
    {
        if (isnull(inputtext) || strlen(inputtext) < 5 || strlen(inputtext) > 32)
            return Dialog_Show(playerid, SprayText, DIALOG_STYLE_INPUT, "Spraytags Texts:", "Allowed letter is A - Z and * = / ? !\nTo break the letter use \"|\"\nPlease input the letter below:", "Input", "Cancel");

        new formattedText[512];
        format(formattedText, sizeof(formattedText), "%s", inputtext);

        for (new i = 0; i < strlen(formattedText); i++)
        {
            if (formattedText[i] == '|')
            {
                formattedText[i] = '\n'; 
            }
        }

        format(PlayerInfo[playerid][E_CHARACTER_OBJECTSTRING], 128, formattedText);

        new Float:x, Float:y, Float:z; 
        GetPlayerPos(playerid, x, y, z); 

        
        PlayerInfo[playerid][E_CHARACTER_ADDOBJECT] = CreateDynamicObject(19482, x, y, z, 0.0, 0.0, 0.0, GetPlayerVirtualWorld(playerid), GetPlayerInterior(playerid)); 
        SetDynamicObjectMaterialText(PlayerInfo[playerid][E_CHARACTER_ADDOBJECT], 0, formattedText, OBJECT_MATERIAL_SIZE_512x256, PlayerInfo[playerid][E_CHARACTER_OBJECTFONT], 40, 1, PlayerInfo[playerid][E_CHARACTER_OBJECTCOLOR], 0, OBJECT_MATERIAL_TEXT_ALIGN_CENTER);
        
        EditDynamicObject(playerid, PlayerInfo[playerid][E_CHARACTER_ADDOBJECT]); 
        PlayerInfo[playerid][E_CHARACTER_EDITINGOBJECT] = 1;
    }
    return 1;
}

function:OnSprayTagsUpdate()
{
    new queryBuffer[512];
    for(new i; i < MAX_SPRAYTAGS; i++)
    {
        if(SpraytagsInfo[i][E_SPRAYTAGS_TIMER])
        {
            SpraytagsInfo[i][E_SPRAYTAGS_TIMER]--;
        }
        else
        {
            mysql_format(ourConnection, queryBuffer, sizeof(queryBuffer), "DELETE FROM `spray_tags` WHERE `id` = '%i'", SpraytagsInfo[i][E_SPRAYTAGS_DBID]);
	        mysql_pquery(ourConnection, queryBuffer);

            Spraytags_Refresh(i);
        }
    }
}