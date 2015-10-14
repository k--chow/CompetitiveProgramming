import java.util.*;
import java.io.*;
public class sad
{
    public static void main(String [] args) throws IOException
    {
        Scanner in = new Scanner(System.in);
        PrintWriter out = new PrintWriter(System.out);
        int n = in.nextInt();
        for(int i=0; i<n;i++)
        {
            int ns = in.nextInt();
            int ref =1;
            for(int check =1; ref<ns; check++)
            {
                
                ref+=check;
                
            }
            if (ref==ns)
             {
                    out.print("1 ");
              }
               else 
              {
                   out.print("0 ");
              }
                   
        }
        
        out.flush();
    }
}
