//Functions
CreateBurglary(propertyid)
{
	for(new p = 0; p < sizeof(BurglaryInfo); p++)
	{
		if(IsValidDynamicObject(BurglaryInfo[p][E_BURGLARY_PROPERTY]))
			DestroyDynamicObject(BurglaryInfo[p][E_BURGLARY_PROPERTY]);

		BurglaryInfo[p][E_BURGLARY_PROPERTYEXISTS] = true;
		BurglaryInfo[p][E_BURGLARY_PROPERTYID] = propertyid;
		BurglaryInfo[p][E_BURGLARY_PROPERTY] = CreateDynamicObject(BurglaryInfo[p][E_BURGLARY_MODEL], BurglaryInfo[p][E_BURGLARY_X], BurglaryInfo[p][E_BURGLARY_Y], BurglaryInfo[p][E_BURGLARY_Z], BurglaryInfo[p][E_BURGLARY_RX], BurglaryInfo[p][E_BURGLARY_RY], BurglaryInfo[p][E_BURGLARY_RZ], -1, -1, -1, 300.00, 300.00); 
	}
	return 1;
}