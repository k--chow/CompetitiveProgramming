import java.util.*;
import java.io.*;
public class SimpleGame
{
    public static void main(String [] args)
    {
        Scanner in = new Scanner(System.in);
        int N = in.nextInt();
        int M = in.nextInt();
        int left = M-1;
        int right = N-M;
        if (left > right)
        {
            System.out.println(M-1);
        }
        else if(right > left)
        {
            System.out.println(M+1);
        }
        else if (right == left && M != 1)
        {
            System.out.println(M-1);
        }
        else
        {
            System.out.println(1);
        }
        
        
    }
}
