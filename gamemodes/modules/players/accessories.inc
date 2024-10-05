stock GetPlayerFreeToySlot(playerid)
{
	forex(i, 4)
	{
		if(pToys[playerid][i][E_TOY_MODEL] == 0)
		{
			return i;
		}
	}
	return -1;
}
function:Load_LoadPlayerToys(playerid)
{
	new rows = cache_num_rows();
	if(rows)
	{
		cache_get_value_name_int(0, "Slot0_Model", pToys[playerid][0][E_TOY_MODEL]);
		cache_get_value_name_int(0, "Slot0_Bone", pToys[playerid][0][E_TOY_BONE]);
		cache_get_value_name_int(0, "Slot0_Type", pToys[playerid][0][E_TOY_TYPE]);

		cache_get_value_name_float(0, "Slot0_XPos", pToys[playerid][0][E_TOY_X]);
		cache_get_value_name_float(0, "Slot0_YPos", pToys[playerid][0][E_TOY_Y]);
		cache_get_value_name_float(0, "Slot0_ZPos", pToys[playerid][0][E_TOY_Z]);

		cache_get_value_name_float(0, "Slot0_XRot", pToys[playerid][0][E_TOY_RX]);
		cache_get_value_name_float(0, "Slot0_YRot", pToys[playerid][0][E_TOY_RY]);
		cache_get_value_name_float(0, "Slot0_ZRot", pToys[playerid][0][E_TOY_RZ]);

		cache_get_value_name_float(0, "Slot0_XScale", pToys[playerid][0][E_TOY_SX]);
		cache_get_value_name_float(0, "Slot0_YScale", pToys[playerid][0][E_TOY_SY]);
		cache_get_value_name_float(0, "Slot0_ZScale", pToys[playerid][0][E_TOY_SZ]);

		cache_get_value_name_int(0, "Slot1_Model", pToys[playerid][1][E_TOY_MODEL]);
		cache_get_value_name_int(0, "Slot1_Bone", pToys[playerid][1][E_TOY_BONE]);
		cache_get_value_name_int(0, "Slot1_Type", pToys[playerid][1][E_TOY_TYPE]);

		cache_get_value_name_float(0, "Slot1_XPos", pToys[playerid][1][E_TOY_X]);
		cache_get_value_name_float(0, "Slot1_YPos", pToys[playerid][1][E_TOY_Y]);
		cache_get_value_name_float(0, "Slot1_ZPos", pToys[playerid][1][E_TOY_Z]);

		cache_get_value_name_float(0, "Slot1_XRot", pToys[playerid][1][E_TOY_RX]);
		cache_get_value_name_float(0, "Slot1_YRot", pToys[playerid][1][E_TOY_RY]);
		cache_get_value_name_float(0, "Slot1_ZRot", pToys[playerid][1][E_TOY_RZ]);

		cache_get_value_name_float(0, "Slot1_XScale", pToys[playerid][1][E_TOY_SX]);
		cache_get_value_name_float(0, "Slot1_YScale", pToys[playerid][1][E_TOY_SY]);
		cache_get_value_name_float(0, "Slot1_ZScale", pToys[playerid][1][E_TOY_SZ]);

		cache_get_value_name_int(0, "Slot2_Model", pToys[playerid][2][E_TOY_MODEL]);
		cache_get_value_name_int(0, "Slot2_Bone", pToys[playerid][2][E_TOY_BONE]);
		cache_get_value_name_int(0, "Slot2_Type", pToys[playerid][2][E_TOY_TYPE]);

		cache_get_value_name_float(0, "Slot2_XPos", pToys[playerid][2][E_TOY_X]);
		cache_get_value_name_float(0, "Slot2_YPos", pToys[playerid][2][E_TOY_Y]);
		cache_get_value_name_float(0, "Slot2_ZPos", pToys[playerid][2][E_TOY_Z]);

		cache_get_value_name_float(0, "Slot2_XRot", pToys[playerid][2][E_TOY_RX]);
		cache_get_value_name_float(0, "Slot2_YRot", pToys[playerid][2][E_TOY_RY]);
		cache_get_value_name_float(0, "Slot2_ZRot", pToys[playerid][2][E_TOY_RZ]);

		cache_get_value_name_float(0, "Slot2_XScale", pToys[playerid][2][E_TOY_SX]);
		cache_get_value_name_float(0, "Slot2_YScale", pToys[playerid][2][E_TOY_SY]);
		cache_get_value_name_float(0, "Slot2_ZScale", pToys[playerid][2][E_TOY_SZ]);

		cache_get_value_name_int(0, "Slot3_Model", pToys[playerid][3][E_TOY_MODEL]);
		cache_get_value_name_int(0, "Slot3_Bone", pToys[playerid][3][E_TOY_BONE]);
		cache_get_value_name_int(0, "Slot3_Type", pToys[playerid][3][E_TOY_TYPE]);

		cache_get_value_name_float(0, "Slot3_XPos", pToys[playerid][3][E_TOY_X]);
		cache_get_value_name_float(0, "Slot3_YPos", pToys[playerid][3][E_TOY_Y]);
		cache_get_value_name_float(0, "Slot3_ZPos", pToys[playerid][3][E_TOY_Z]);

		cache_get_value_name_float(0, "Slot3_XRot", pToys[playerid][3][E_TOY_RX]);
		cache_get_value_name_float(0, "Slot3_YRot", pToys[playerid][3][E_TOY_RY]);
		cache_get_value_name_float(0, "Slot3_ZRot", pToys[playerid][3][E_TOY_RZ]);

		cache_get_value_name_float(0, "Slot3_XScale", pToys[playerid][3][E_TOY_SX]);
		cache_get_value_name_float(0, "Slot3_YScale", pToys[playerid][3][E_TOY_SY]);
		cache_get_value_name_float(0, "Slot3_ZScale", pToys[playerid][3][E_TOY_SZ]);
	}
	return 1;
}
stock LoadPlayerToys(playerid)
{
	new tstr[156];
	mysql_format(ourConnection, tstr, sizeof(tstr), "SELECT * FROM toys WHERE Owner='%d' LIMIT 1", PlayerInfo[playerid][E_CHARACTER_DBID]);
	mysql_pquery(ourConnection, tstr, "Load_LoadPlayerToys", "i", playerid);
}

stock CreatePlayerToy(playerid)
{
	new query[156];
	mysql_format(ourConnection, query, sizeof(query), "INSERT INTO `toys` (`Owner`) VALUES ('%d');", PlayerInfo[playerid][E_CHARACTER_DBID]);
	mysql_pquery(ourConnection, query);

	for(new i = 0; i < 4; i++)
	{
		pToys[playerid][i][E_TOY_MODEL] = 0;
		pToys[playerid][i][E_TOY_BONE] = 1;
		pToys[playerid][i][E_TOY_TYPE] = 0;
		pToys[playerid][i][E_TOY_X] = 0.0;
		pToys[playerid][i][E_TOY_Y] = 0.0;
		pToys[playerid][i][E_TOY_Z] = 0.0;
		pToys[playerid][i][E_TOY_RX] = 0.0;
		pToys[playerid][i][E_TOY_RY] = 0.0;
		pToys[playerid][i][E_TOY_RZ] = 0.0;
		pToys[playerid][i][E_TOY_SX] = 1.0;
		pToys[playerid][i][E_TOY_SY] = 1.0;
		pToys[playerid][i][E_TOY_SZ] = 1.0;
	}
	PlayerInfo[playerid][E_CHARACTER_AOE] = 1;
}

stock GetFreeToySlot(playerid, slot)
{
	for(new i=MAX_PLAYER_ATTACHED_OBJECTS-1; i!=0; i--)
	{
		if(!IsPlayerAttachedObjectSlotUsed(playerid, i))
		{
			toySlot[playerid][slot] = i;
			return i;
		}
	}
	return -1;
}

stock SavePlayerToys(playerid)
{
	new line4[1524], lstr[1524];

	mysql_format(ourConnection, lstr, sizeof(lstr),
	"UPDATE `toys` SET \
	`Slot0_Model` = %i, `Slot0_Bone` = %i, `Slot0_Type` = %i, `Slot0_XPos` = %.3f, `Slot0_YPos` = %.3f, `Slot0_ZPos` = %.3f, `Slot0_XRot` = %.3f, `Slot0_YRot` = %.3f, `Slot0_ZRot` = %.3f, `Slot0_XScale` = %.3f, `Slot0_YScale` = %.3f, `Slot0_ZScale` = %.3f,",
		pToys[playerid][0][E_TOY_MODEL],
        pToys[playerid][0][E_TOY_BONE],
		pToys[playerid][0][E_TOY_TYPE],
        pToys[playerid][0][E_TOY_X],
        pToys[playerid][0][E_TOY_Y],
        pToys[playerid][0][E_TOY_Z],
        pToys[playerid][0][E_TOY_RX],
        pToys[playerid][0][E_TOY_RY],
        pToys[playerid][0][E_TOY_RZ],
        pToys[playerid][0][E_TOY_SX],
        pToys[playerid][0][E_TOY_SY],
        pToys[playerid][0][E_TOY_SZ]);
	strcat(line4, lstr);

	mysql_format(ourConnection, lstr, sizeof(lstr),
	" `Slot1_Model` = %i, `Slot1_Bone` = %i, `Slot1_Type` = %i, `Slot1_XPos` = %.3f, `Slot1_YPos` = %.3f, `Slot1_ZPos` = %.3f, `Slot1_XRot` = %.3f, `Slot1_YRot` = %.3f, `Slot1_ZRot` = %.3f, `Slot1_XScale` = %.3f, `Slot1_YScale` = %.3f, `Slot1_ZScale` = %.3f,",
		pToys[playerid][1][E_TOY_MODEL],
        pToys[playerid][1][E_TOY_BONE],
		pToys[playerid][1][E_TOY_TYPE],
        pToys[playerid][1][E_TOY_X],
        pToys[playerid][1][E_TOY_Y],
        pToys[playerid][1][E_TOY_Z],
        pToys[playerid][1][E_TOY_RX],
        pToys[playerid][1][E_TOY_RY],
        pToys[playerid][1][E_TOY_RZ],
        pToys[playerid][1][E_TOY_SX],
        pToys[playerid][1][E_TOY_SY],
        pToys[playerid][1][E_TOY_SZ]);
  	strcat(line4, lstr);

    mysql_format(ourConnection, lstr, sizeof(lstr),
	" `Slot2_Model` = %i, `Slot2_Bone` = %i, `Slot2_Type` = %i, `Slot2_XPos` = %.3f, `Slot2_YPos` = %.3f, `Slot2_ZPos` = %.3f, `Slot2_XRot` = %.3f, `Slot2_YRot` = %.3f, `Slot2_ZRot` = %.3f, `Slot2_XScale` = %.3f, `Slot2_YScale` = %.3f, `Slot2_ZScale` = %.3f,",
		pToys[playerid][2][E_TOY_MODEL],
        pToys[playerid][2][E_TOY_BONE],
		pToys[playerid][2][E_TOY_TYPE],
        pToys[playerid][2][E_TOY_X],
        pToys[playerid][2][E_TOY_Y],
        pToys[playerid][2][E_TOY_Z],
        pToys[playerid][2][E_TOY_RX],
        pToys[playerid][2][E_TOY_RY],
        pToys[playerid][2][E_TOY_RZ],
        pToys[playerid][2][E_TOY_SX],
        pToys[playerid][2][E_TOY_SY],
        pToys[playerid][2][E_TOY_SZ]);
  	strcat(line4, lstr);

    mysql_format(ourConnection, lstr, sizeof(lstr),
	" `Slot3_Model` = %i, `Slot3_Bone` = %i, `Slot3_Type` = %i, `Slot3_XPos` = %.3f, `Slot3_YPos` = %.3f, `Slot3_ZPos` = %.3f, `Slot3_XRot` = %.3f, `Slot3_YRot` = %.3f, `Slot3_ZRot` = %.3f, `Slot3_XScale` = %.3f, `Slot3_YScale` = %.3f, `Slot3_ZScale` = %.3f WHERE `Owner` = '%d'",
		pToys[playerid][3][E_TOY_MODEL],
        pToys[playerid][3][E_TOY_BONE],
		pToys[playerid][3][E_TOY_TYPE],
        pToys[playerid][3][E_TOY_X],
        pToys[playerid][3][E_TOY_Y],
        pToys[playerid][3][E_TOY_Z],
        pToys[playerid][3][E_TOY_RX],
        pToys[playerid][3][E_TOY_RY],
        pToys[playerid][3][E_TOY_RZ],
        pToys[playerid][3][E_TOY_SX],
        pToys[playerid][3][E_TOY_SY],
        pToys[playerid][3][E_TOY_SZ],
		PlayerInfo[playerid][E_CHARACTER_DBID]);
  	strcat(line4, lstr);

    mysql_pquery(ourConnection, line4);
    return 1;
}
stock AttachPlayerToys(playerid)
{
	if(pToys[playerid][0][E_TOY_MODEL] != 0)
	{
		SetPlayerAttachedObject(playerid,
		ATTACH_TOYS1,
		pToys[playerid][0][E_TOY_MODEL],
		pToys[playerid][0][E_TOY_BONE],
		pToys[playerid][0][E_TOY_X],
		pToys[playerid][0][E_TOY_Y],
		pToys[playerid][0][E_TOY_Z],
		pToys[playerid][0][E_TOY_RX],
		pToys[playerid][0][E_TOY_RY],
		pToys[playerid][0][E_TOY_RZ],
		pToys[playerid][0][E_TOY_SX],
		pToys[playerid][0][E_TOY_SY],
		pToys[playerid][0][E_TOY_SZ]);
	}
	
	if(pToys[playerid][1][E_TOY_MODEL] != 0)
	{
		SetPlayerAttachedObject(playerid,
		ATTACH_TOYS2,
		pToys[playerid][1][E_TOY_MODEL],
		pToys[playerid][1][E_TOY_BONE],
		pToys[playerid][1][E_TOY_X],
		pToys[playerid][1][E_TOY_Y],
		pToys[playerid][1][E_TOY_Z],
		pToys[playerid][1][E_TOY_RX],
		pToys[playerid][1][E_TOY_RY],
		pToys[playerid][1][E_TOY_RZ],
		pToys[playerid][1][E_TOY_SX],
		pToys[playerid][1][E_TOY_SY],
		pToys[playerid][1][E_TOY_SZ]);
	}
	
	if(pToys[playerid][2][E_TOY_MODEL] != 0)
	{
		SetPlayerAttachedObject(playerid,
		ATTACH_TOYS3,
		pToys[playerid][2][E_TOY_MODEL],
		pToys[playerid][2][E_TOY_BONE],
		pToys[playerid][2][E_TOY_X],
		pToys[playerid][2][E_TOY_Y],
		pToys[playerid][2][E_TOY_Z],
		pToys[playerid][2][E_TOY_RX],
		pToys[playerid][2][E_TOY_RY],
		pToys[playerid][2][E_TOY_RZ],
		pToys[playerid][2][E_TOY_SX],
		pToys[playerid][2][E_TOY_SY],
		pToys[playerid][2][E_TOY_SZ]);
	}
	
	if(pToys[playerid][3][E_TOY_MODEL] != 0)
	{
		SetPlayerAttachedObject(playerid,
		ATTACH_TOYS4,
		pToys[playerid][3][E_TOY_MODEL],
		pToys[playerid][3][E_TOY_BONE],
		pToys[playerid][3][E_TOY_X],
		pToys[playerid][3][E_TOY_Y],
		pToys[playerid][3][E_TOY_Z],
		pToys[playerid][3][E_TOY_RX],
		pToys[playerid][3][E_TOY_RY],
		pToys[playerid][3][E_TOY_RZ],
		pToys[playerid][3][E_TOY_SX],
		pToys[playerid][3][E_TOY_SY],
		pToys[playerid][3][E_TOY_SZ]);
	}
	return 1;
}
