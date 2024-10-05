new DEBUGGING;

stock Debugs(format[])
{
    if(DEBUGGING == 1)
    {
        print(format);
    }
    return 1;
}