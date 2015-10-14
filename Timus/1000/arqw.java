import java.util.*;
import java.io.*;
public class arqw
{
    public static void main(String [] args) throws IOException
    {
        Scanner in = new Scanner(new File("System.in"));
        PrintWriter out = new PrintWriter(new File("System.out"));
        int N = in.nextInt();
       
        int counter = 1;
        int[] numbers = new int[N];
        for (int i=0; i<N; i++)
        {
            numbers[i] = in.nextInt();
            
        }
        
        for (int i=0; i<N; i++)
        {
            if (numbers[i] == numbers[i+1])
            {
                counter++;
                if (i == N-1)
                {
                    out.print(counter + " " + numbers[i] + " ");
                }
            }
            else 
            {
                out.print(counter + " " + numbers[i] + " ");
                counter = 1;
                if (i == N-1)
                {
                    out.print(counter + " " + numbers[i] + " ");
                }
            }
        }
        out.flush();
    }
}
