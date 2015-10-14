/*
ID: k__chow1
LANG: JAVA
PROG: gift1
 */

import java.io.*;
import java.util.*;
class gift1
{
    public static void main(String [] args) throws IOException
    {
        Scanner in = new Scanner(new File("gift1.in"));
        PrintWriter out = new PrintWriter(new File("gift1.out"));
        int people = in.nextInt();
        String[] names = new String[people];
        int[] accounts = new int[people];
        for (int b=0; b<people; b++)
        {
            names[b] = in.next();
            
        }
        for (int a =0; a<people; a++)
        {
            accounts[a] = 0;
        }
        
        while (in.hasNext())
        {
            String giver = in.next();
            System.out.println(giver);
            int amount = in.nextInt();
            int receivers = in.nextInt();
           
            if(receivers != 0)
            {
            int actual = (amount/receivers);
            String[] recipients = new String[receivers];
            for (int c =0; c<receivers; c++)
            {
                recipients[c] = in.next();
                for (int d =0; d<people; d++)
                {
                    if (recipients[c].equals(names[d]))
                    {
                        accounts[d]+=actual;
                    }
                }
                
            }
            
            for (int e =0; e<people; e++)
            {
                if (giver.equals(names[e]))
                {
                    accounts[e] -= actual*receivers;
                }
            }
        }
        
        
    }
    for(int f=0; f <people; f++)
        {
            out.println(names[f] + " " + accounts[f]);
        }
        out.close();
    }
}
