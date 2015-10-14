import java.util.*;
import java.io.*;
 class Main
{
    
    void solve() 
    {
        Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        int count = 0;
        while(true)
        {
            count++;
            String a = in.next();
            if (a.equals("Hajj"))
            {
                System.out.println("Case " + count + ": Hajj-e-Akbar");
            }
            else if (a.equals("Umrah"))
            {
                System.out.println("Case " + count + ": Hajj-e-Asghar");
            }
            else if (a.equals("*"))
            {
                break;
            }
        }
    }
    
    public static void main(String [] args)
    {
        Main problem = new Main();
        problem.solve();
        
    }
}
