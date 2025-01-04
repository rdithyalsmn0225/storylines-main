CMD:boombox(playerid, params[])
{
	new id = Item_Nearest(playerid);
	if(DroppedInfo[id][E_DROPPED_TYPE] != E_DROPPED_TYPE_BOOMBOX)
		return SendErrorMessage(playerid, "You aren't near boombox.");
		
    Dialog_Show(playerid, DialogBoombox, DIALOG_STYLE_LIST, "Radio:", "Add URL\nTurn Off", "Select", "Close");
    return 1;
}

Dialog:DialogBoombox(playerid, response, listitem, inputtext[])
{
    if (response)
	{
		new id = Item_Nearest(playerid);
		switch(listitem)
		{
			case 0:
			{
				Dialog_Show(playerid, DialogBoomboxUrl, DIALOG_STYLE_INPUT, "Radio Stations:", "Type a song or radio station URL.\nNote that year we roleplay in 1990.", "Input", "Close");
			}
			case 1:
			{
				StopAudioStreamForPlayer(playerid);
                
				BoomboxInfo[id][E_BOOMBOX_STATUS] = false;
			}
		}
	}
    return 1;
}

Dialog:DialogBoomboxUrl(playerid, response, listitem, inputtext[])
{
    if(response)
	{
        new id = Item_Nearest(playerid);

		if (isnull(inputtext))
		{
			Dialog_Show(playerid, DialogAddURL, DIALOG_STYLE_INPUT, "Radio Stations:", "Type a song or radio station URL.\nNote that year we roleplay in 1990.", "Input", "Close");
		}

        format(BoomboxInfo[id][E_BOOMBOX_STATUS], 256, inputtext);
		PlayAudioStreamForPlayer(playerid, inputtext, DroppedInfo[id][E_DROPPED_POS][0], DroppedInfo[id][E_DROPPED_POS][1], DroppedInfo[id][E_DROPPED_POS][2], 20.0, true);
		BoomboxInfo[id][E_BOOMBOX_STATUS] = true;
	}
    return 1;
}

CMD:getsprunk(playerid, params[])
{
	new id = Item_Nearest(playerid);
	if(DroppedInfo[id][E_DROPPED_TYPE] != E_DROPPED_TYPE_SPRUNK)
	{
		if(!DroppedInfo[id][E_DROPPED_AMOUNT])
			return SendErrorMessage(playerid, "Pack of sprunk is empty.");

		DroppedInfo[id][E_DROPPED_AMOUNT]--;
		SendInventoryMessage(playerid, "You take 1x of sprunk from pack of sprunk.");
		Inventory_Add(playerid, "Sprunk", 2601, 1);

		new string[256];
		format(string, sizeof(string), "UPDATE `dropped` SET `itemAmount` = %d WHERE `ID` = '%d'", DroppedInfo[id][E_DROPPED_AMOUNT], DroppedInfo[id][E_DROPPED_DBID]);
		mysql_pquery(ourConnection, string);
	}
	else if(DroppedInfo[id][E_DROPPED_TYPE] != E_DROPPED_TYPE_PISH)
	{
		if(!DroppedInfo[id][E_DROPPED_AMOUNT])
		return SendErrorMessage(playerid, "Pack of beer is empty.");

		DroppedInfo[id][E_DROPPED_AMOUNT]--;
		SendInventoryMessage(playerid, "You take 1x of pishwasher from pack of beer.");
		Inventory_Add(playerid, "Pisswasher", 2601, 1);

		new string[256];
		format(string, sizeof(string), "UPDATE `dropped` SET `itemAmount` = %d WHERE `ID` = '%d'", DroppedInfo[id][E_DROPPED_AMOUNT], DroppedInfo[id][E_DROPPED_DBID]);
		mysql_pquery(ourConnection, string);
	}
	else return SendErrorMessage(playerid, "You aren't near pack of drink.");
    return 1;
}