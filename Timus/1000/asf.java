import java.util.*;
import java.io.*;
public class asf
{
    public static void main(String [] args) 
    {
        Scanner in = new Scanner(System.in);
        PrintWriter out = new PrintWriter(System.out);
        
        int eigenvalues = 0;
        int n1 = in.nextInt();
        List<Integer>a = new ArrayList<Integer>();
        for (int i=0; i<n1; i++)
        {
            a.add(in.nextInt());
        }
        int n2 = in.nextInt();
        List<Integer>b = new ArrayList<Integer>();
        for (int i=0; i<n2; i++)
        {
            b.add(in.nextInt());
        }
        int n3 = in.nextInt();
        List<Integer>c = new ArrayList<Integer>();
        for(int i=0; i<n3; i++)
        {
            c.add(in.nextInt());
        }
        for (int i=0; i<n1; i++)
        {
            int test = a.get(i);
            boolean A = false;
            boolean B = false;
            for (int j=0; j<n2; j++)
            {
                if (b.get(j) == test)
                {
                    A = true;
                }
                
            }
            for (int k=0; k<n3; k++)
            {
                if (c.get(k) == test)
                {
                    B = true;
                }
            }
            if ( A && B)
            {
                eigenvalues++;
            }
        }
        
       out.println(eigenvalues);
        
        out.flush();
        
    }
}
