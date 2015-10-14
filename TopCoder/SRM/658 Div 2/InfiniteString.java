
public class InfiniteString
{
    public static String equal(String s, String t)
    {
        int a = s.length();
        int b = t.length();
        String c = "";
        String d =  "";
        for(int i=0; i<b; i++)
        {
            c+=s;
        }
        for (int i=0; i<a; i++)
        {
            d+=t;
        }
        if (c.equals(d))
        {
            System.out.println(s + " " + t);
            return "Equal";
            
        }
        else
        {
            System.out.println(c + " " + d);
            return "Not equal";
            
        }
        
    }
    
    public static void main(String [] args)
    {
        equal("ab", "abab");
    }
}
