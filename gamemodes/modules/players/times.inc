void:SetClock(hour, minute)
{
    new timestr[512];
    new weekday_str[10], j, e, month[12], date[6];

	getdate(date[2], date[1], date[0]);
	gettime(date[3], date[4], date[5]);

    if (date[1] <= 2)
    {
        date[1] += 12;
        --date[2];
    } 

    j = date[2] % 100;
    e = date[2] / 100;

	switch (date[1]) {
	    case 1: month = "January";
	    case 2: month = "February";
	    case 3: month = "March";
	    case 4: month = "April";
	    case 5: month = "May";
	    case 6: month = "June";
	    case 7: month = "July";
	    case 8: month = "August";
	    case 9: month = "September";
	    case 10: month = "October";
	    case 11: month = "November";
	    case 12: month = "December";
	}

    switch ((date[0] + (date[1]+1)*26/10 + j + j/4 + e/4 - 2*e) % 7)
    {
        case 0: weekday_str = "Saturday";
        case 1: weekday_str = "Sunday";
        case 2: weekday_str = "Monday";
        case 3: weekday_str = "Tuesday";
        case 4: weekday_str = "Wednesday";
        case 5: weekday_str = "Thursday";
        case 6: weekday_str = "Friday";
    } 

    format(timestr, sizeof(timestr), "%02d:%02d, %s~n~%02dth of %s %02d", hour, minute, weekday_str, date[0], month, date[2]);
    TextDrawSetString(Times, timestr);
}

ShowClock(playerid)
{
    if (!IsPlayerConnected(playerid))
    {
       return 0;
    }
    return TextDrawShowForPlayer(playerid, Times);
}