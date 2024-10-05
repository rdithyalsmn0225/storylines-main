stock GetLogsName(logType)
{
    new str[512];
    if(logType == LOGS_PM) format(str, sizeof(str), "Logs PM");
    else if(logType == LOGS_PAY) format(str, sizeof(str), "Logs Pays");
    else if(logType == LOGS_ADMIN) format(str, sizeof(str), "Logs Admins");
    else if(logType == LOGS_ADVERT) format(str, sizeof(str), "Logs Advertise");
    return str;
}

CreateLogs(playerid, type, result[])
{
    new query[512], str[512];
    mysql_format(ourConnection, query, sizeof(query), "INSERT INTO logs (type, name, result) VALUES('%s', '%s', '%s')", GetLogsName(type), ReturnSettingsName(playerid, playerid), result); 
    mysql_pquery(ourConnection, query); 

    format(str, sizeof(str), "%s has using %s (%s)", ReturnSettingsName(playerid, playerid), GetLogsName(type), result);
    SendAdminMessage(1, str);
    return 1;
}