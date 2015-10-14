import java.util.*;
import java.io.*;
public class TwoTeams1106
{
    //static int[][] adj = new int[100][100];
    static TreeMap<Integer, Integer> dist = new TreeMap<Integer, Integer>();
    static TreeMap<Integer, Integer> pred = new TreeMap<Integer, Integer>();
    static LinkedList<Integer> q = new LinkedList<Integer>();
    public static void main(String [] args) throws IOException
    {
        Scanner in = new Scanner(new File("System.in"));
        PrintWriter out = new PrintWriter(new File("System.out"));
        int N = in.nextInt();
        dist.put(1, 1);
        pred.put(1, null);
        q.add(1);
        for(int i=1; i<N+1; i++)
        {
            if (i != 1)
            {
            dist.put(i, -1);
            }
            //pred.put(i, null);
        }
        
        for(int i=1; i<N+1; i++)//traverse
        {
            while(true)
            {
                int b = in.nextInt();
                if (b !=0)
                {
                    if (dist.get(b) == -1)//unvisited
                    {
                        q.add(b);
                        pred.put(b, i);
                        if(dist.get(i) != -1)
                        {
                        dist.put(b, dist.get(i) +1);
                        }
                        else
                        {
                            dist.put(b, -1);
                        }
                    }
                }
                else
                {
                    break;
                }
            }
        }
        ArrayList<Integer> fiends = new ArrayList<Integer>();
        ArrayList<Integer> friends = new ArrayList<Integer>();
        for (int i=1; i<N+1; i++)
        {
            int a = dist.get(i);
            Integer aa = new Integer(a);
            if (fiends.indexOf(a) == -1)
            {
                fiends.add(a);
                friends.add(i);
            }
        }
        out.println(friends.size());
        
        for(int i=0; i<fiends.size(); i++)
        {
            out.print(friends.get(i) + " ");
        }
        out.close();
    }
}
