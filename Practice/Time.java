
public class Time
{
    public static String whatTime(int seconds)
    {
        int h = (int)seconds/3600;
        int m = (int)((seconds%3600)/60);
        int s = seconds % 60;
        
        return h + ":" + m + ":" + s;
    }
    
    
}
