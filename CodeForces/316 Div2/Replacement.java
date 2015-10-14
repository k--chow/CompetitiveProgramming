import java.util.*;
import java.io.*;
public class Replacement
{
    public static void main(String [] args)
    {
        Scanner in = new Scanner(System.in);
        int N = in.nextInt();
        int M = in.nextInt();
        String s = in.next();
        String original = s;
        int[] answer = new int[M];
        for(int i=0; i<M; i++)
        {
            int index = in.nextInt() -1;
            String insert = in.next();
            original = original.substring(0, index) + insert + original.substring(index+1);
            String yolo = original;
            //System.out.println("Originals: " + yolo);
            int count = 0;
            
            int ab =0;
            /*
            while (original.indexOf("..", starter) != -1)
            {
                starter = original.indexOf("..", starter)+1;
                count++;
                if(dotIndex != -1)
                {
                count++;
                original = original.substring(0, dotIndex) + "." + original.substring(dotIndex+2);
                //System.out.println("Case: " + original);
                }
                else
                {
                    break;
                }
                
            }*/
            for (int j=0; j<N; j++)
            {
                String t = original.substring(j, j+1);
                //System.out.println(t);
                if (t.equals("."))
                {
                    count++;
                    if (j+1 == N)
                {
                    ab+=count-1;
                    
                }
                }
                else if (count > 0 )
                {
                    ab+=(count-1);
                    count = 0;
                
                }
                
                
            }
            
            System.out.println(ab);
            original = yolo;
        }
        
    }
}
