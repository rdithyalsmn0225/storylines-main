//Cook Meat into BBQ
function:CookBBQ(playerid, id)
{
	new text[256];
    DroppedInfo[id][E_DROPPED_LOADINGCOUNT]++;

	switch(DroppedInfo[id][E_DROPPED_LOADINGCOUNT])
	{
		case 2: text = "BBQ COOK IN PROCESS\nSupplied Meat: 180 grams\nTime Left: ((||-----))";
		case 3: text = "BBQ COOK IN PROCESS\nSupplied Meat: 180 grams\nTime Left: ((|||----))";
		case 4: text = "BBQ COOK IN PROCESS\nSupplied Meat: 180 grams\nTime Left: ((||||---))";
		case 5: text = "BBQ COOK IN PROCESS\nSupplied Meat: 180 grams\nTime Left: ((|||||--))";
		case 6: text = "BBQ COOK IN PROCESS\nSupplied Meat: 180 grams\nTime Left: ((||||||-))";
		case 7: text = "BBQ COOK IN PROCESS\nSupplied Meat: 180 grams\nTime Left: ((|||||||))";
		case 8:
		{
			Delete3DTextLabel(DroppedInfo[id][E_DROPPED_LOADINGDISPLAY]); 
			KillTimer(DroppedInfo[id][E_DROPPED_LOADINGTIMER]);
			DroppedInfo[id][E_DROPPED_LOADINGCOUNT] = 0;
			DroppedInfo[id][E_DROPPED_LOADING] = true;
					
			DroppedInfo[id][E_DROPPED_AMOUNT] = 1;
        }
    }
    Update3DTextLabelText(DroppedInfo[id][E_DROPPED_LOADINGDISPLAY], COLOR_DARKGREEN, text); 
}