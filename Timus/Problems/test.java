import java.util.*;
import java.io.*;
public class test
{
    
    public static void main(String [] args) throws IOException
    {
        int count = 0;
        int[] p = new int[3];
        for(int i=0; i<3; i++)
        {
            p[i] = i+1;
        }
        for(int i=0; i<(1<<3); i++)
        {
            for(int j=0; j<3; j++)
            {
                String test = Integer.toBinaryString(i);
                while (test.length() <3)
                {
                    test = "0" + test;
                }
                String test2 = test.substring(j, j+1);
                if (test2.equals("1"))//(i & (i << j))!= 0)
                {
                    System.out.printf("%d ", p[j]);
        }
        }
        System.out.println();
        }
        
    }
}
