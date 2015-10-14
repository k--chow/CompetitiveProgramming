import java.io.*;
import java.util.*;
class Snail
{
    public static void main(String [] args)
    {
        Scanner in = new Scanner(System.in);
        PrintWriter out= new PrintWriter(System.out);
        int H, U, D, F;
        while(true)
        {
            H = in.nextInt();
            if (H != 0)
            {
                U = in.nextInt();
                D = in.nextInt();
                F = in.nextInt();
                int day = 1;
                double Up = U;
                
                double two = ((double)F*Up)/100;
                //System.out.println(Up + " " + two);
                double current = 0;
                while(true)
                {
                    
                    
                    current+=Up;
                    
                    if (current > H)
                    {
                        out.println("success on day " + day);
                        break;
                    }
                    else if(current <= 0)
                    {
                        out.println("failure on day " + day);
                        break;
                    }
                    else
                    {
                        day++;
                        Up-=two;
                        current-=D;
                    }
                    
                }
            }
            else
            {
                break;
            }
        }
        out.close();
    }
}
