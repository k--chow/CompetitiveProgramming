import java.util.*;
import java.io.*;
public class Elections
{
    public static void main(String [] args)
    {
        Scanner in = new Scanner(System.in);
        int N = in.nextInt();
        int M = in.nextInt();
        int[] c = new int[N+1];
        Arrays.fill(c, 0);
        c[0] = -1;
        for(int i=0; i<M; i++)
        {
            int max = -1;
            int index = -1;
            for(int j=1; j<=N; j++)
            {
                int test = in.nextInt();
                if (test>max)
                {
                    max = test;
                    index = j;
                }
            }
            if (index != -1)
            {
            c[index]++;
            }
            
        }
        int answer = -1;
        int a2 = 0;
        for (int i=1; i<N+1; i++)
        {
            //System.out.println(c[i]);
            if (c[i] > answer)
            {
                answer = c[i];
                a2 = i;
            }
        }
        if (a2 != 0)
        {
        System.out.println(a2);
    }
    }
}
