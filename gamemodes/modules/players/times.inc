SetClock(hour, minute, second)
{
    new timestr[256];
    new weekday_str[10], month[12], date[6];
    new suffix[3]; // Untuk menampung akhiran (st, nd, rd, th)

    getdate(date[2], date[1], date[0]);
    gettime(date[3], date[4], date[5]);

    if (date[1] <= 2)
    {
        date[1] += 12;
        --date[2];
    } 

    // Menentukan akhiran tanggal
    switch (date[0] % 10)
    {
        case 1: suffix = (date[0] == 11) ? "th" : "st";
        case 2: suffix = (date[0] == 12) ? "th" : "nd";
        case 3: suffix = (date[0] == 13) ? "th" : "rd";
        default: suffix = "th";
    }

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

    switch ((date[0] + (date[1] + 1) * 26 / 10 + (date[2] % 100) + (date[2] % 100) / 4 + (date[2] / 100) / 4 - 2 * (date[2] / 100)) % 7)
    {
        case 0: weekday_str = "Saturday";
        case 1: weekday_str = "Sunday";
        case 2: weekday_str = "Monday";
        case 3: weekday_str = "Tuesday";
        case 4: weekday_str = "Wednesday";
        case 5: weekday_str = "Thursday";
        case 6: weekday_str = "Friday";
    } 

    format(timestr, sizeof(timestr), "%02d:%02d:%02d, %s~n~%d%s of %s %02d", hour, minute, second, weekday_str, date[0], suffix, month, date[2]);
    TextDrawSetString(Times, timestr);
}


ShowClock(playerid)
{
    if(PlayerInfo[playerid][E_CHARACTER_TOGHUD] == false)
    {
        TextDrawShowForPlayer(playerid, Times);
    }
    return 1;
}

HideClock(playerid)
{
    TextDrawHideForPlayer(playerid, Times);
    return 1;
}