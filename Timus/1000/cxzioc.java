import java.util.*;
import java.io.*;
import java.math.*;
import java.text.*;
public class cxzioc
{
    public static void main(String [] args) 
    {
        Scanner in = new Scanner(System.in);
        PrintWriter out = new PrintWriter(System.out);
        String n = in.next();
        String[] m = new String[6];
        m = (n.split("(?!^)"));
        int[] x = new int[6];
        
        for (int i=0; i<6; i++)
        {
            x[i] = Integer.parseInt(m[i]);
        }
        int a = x[0] + x[1] + x[2];
        int eg = Integer.parseInt(n.substring(3, 6));
        int egb = eg+1;
        int egc = eg-1;
        String egb1 = Integer.toString(egb);
        String egc1 = Integer.toString(egc);
        int egbr = Integer.parseInt(egb1.substring(0, 1)) + Integer.parseInt(egb1.substring(1, 2)) +
        Integer.parseInt(egb1.substring(2, 3));
        int egcr = Integer.parseInt(egc1.substring(0, 1)) + Integer.parseInt(egc1.substring(1, 2)) +
        Integer.parseInt(egc1.substring(2, 3));
        
        System.out.println(egbr + " " + egcr);
        if (a == egbr || a == egcr)
        {
            out.println("Yes");
        }
        else
        {
            out.println("No");
        }
        
        
        out.flush();
    }
    
    
}
