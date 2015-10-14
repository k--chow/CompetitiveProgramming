import java.util.*;
import java.io.*;
public class asd
{
    
    public static void main(String [] args) 
    {
        Scanner in = new Scanner(System.in);
        PrintWriter out = new PrintWriter(System.out);
        int n = in.nextInt();
        String number= "12345678";
        String letter = "abcdefgh";
        for (int i=0; i<n; i++)
        {
            String s = in.next();
            String l = s.substring(0, 1);
            String no = s.substring(1,2);
            int a = letter.indexOf(l);
            int b = number.indexOf(no);
            int count = 0;
            out.println(getCount(a, b, count));
        }
        out.flush();
        
    }
    public static int getCount(int a, int b, int count)
    {
        if (b+2 < 8)
        {
            if (a+1 <8)
            {
                count++;
            }
            if (a-1> -1)
            {
                count++;
            }
        }
        if(a+2 < 8)
        {
            if (b + 1 < 8)
            {
                count++;
            }
            if (b - 1 > -1)
            {
                count++;
            }
        }
        if (b-2 > -1)
        {
            if (a +1 <8)
            {
                count++;
            }
            if (a -1 > -1)
            {
                count++;
            }
            
        }
        if (a - 2> -1)
        {
            if (b +1 < 8)
            {
                count++;
            }
            if (b -1 > -1)
            {
                count++;
            }
        }
        return count;
    }
}
