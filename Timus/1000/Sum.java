import java.util.*;
import java.io.*;
public class Sum
{
    public static void main(String [] args) 
    {
        Scanner in = new Scanner(System.in);
        PrintWriter out = new PrintWriter(System.out);
        int a= in.nextInt();
        int b= in.nextInt();
        int r = (2*a) % b;
        if ((double)(a)/b <= 1 )
        {
            out.println(2);
        }
        else
        {
            if (r == 0)
            {
                out.println((2*a)/b);
            }
            else
            {
                out.println(((2*a)/b) + 1);
            }
        }
        
        out.flush();
        
    }
}
