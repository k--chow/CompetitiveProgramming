import java.util.*;
public class ChessFloor
{
    public static int minimumChanges(String[] floor)
    {
        int N = floor.length;
        String e = "";
        String o = "";
        
        ArrayList<String>a = new ArrayList<String>();
        ArrayList<String>b = new ArrayList<String>();
        for(int r=0; r<N; r++)
        {
            for(int c=0;c<N; c++)
            {
                String test = floor[r].substring(c, c+1);
                if (r%2 ==0 && c%2 ==0)
                {
                    e+=test;
                    a.add(test);
                }
                else
                {
                    if (o.indexOf(test) == -1)
                    {
                        o+=test;
                        b.add(test);
                    }
                }
                
            
            }
        }
        int[] y = new int[a.size()];
        int[] z = new int[b.size()];
        //evens
        for(int i=0; i<y.length; i++)
        {
            String test = a.get(i);
            int count=0;
        for(int r=0; r<N; r++)
        {
            for (int c=0; c<N; c++)
            {
                if (r%2 == 0 && c%2 ==0)
                {
                    if (floor[r].substring(c,c+1).equals(test))
                    {
                        count++;
                    }
                }
                else if (r%2 != 0 && c%2 !=0)
                {
                    if (floor[r].substring(c,c+1).equals(test))
                    {
                        count++;
                    }
                }
            }
        }
        y[i] = count;
    }
    
    //odds
    for(int i=0; i<z.length; i++)
        {
            String test = b.get(i);
            int count=0;
        for(int r=0; r<N; r++)
        {
            for (int c=0; c<N; c++)
            {
                if (r%2 == 0 && c%2 !=0)
                {
                    if (floor[r].substring(c, c+1).equals(test))
                    {
                        count++;
                    }
                }
                else if (r%2 !=0 && c%2 ==0)
                {
                    if (floor[r].substring(c, c+1).equals(test))
                    {
                        count++;
                    }
                }
            }
        }
        z[i] = count;
    }
    
    //return
    int max = 0;
    for (int i=0; i<y.length; i++)
    {
        
        for (int j=0; j<z.length; j++)
        {
            int test=0;
            if (!a.get(i).equals(b.get(j)))
            {
                test+=y[i];
                test+=z[j];
            }
            else
            {
                test = Math.max(y[i], z[j]);
            }
            if (test>max)
            {
                max = test;
            }
        }
    }
    
    for (int i=0; i<y.length; i++)
    {
        System.out.println("even " + a.get(i) + " " +y[i]);
    }
    
    for (int i=0; i<z.length; i++)
    {
        System.out.println("odd " + b.get(i) + " " + z[i]);
    }
    return (N*N) - max;
    }
    public static void main(String [] args)
    {
        String[] a = {"aaaaaaaaaaaaaaaaaaaa", "aaaaaaaaaaaaaaaaaaaa", "aaaaaaaaaaaaaaaaaaaa", "aaaaaaaaaaaaaaaaaaaa", "aaaaaaaaaaaaaaaaaaaa", "aaaaaaaaaaaaaaaaaaaa", "aaaaaaaaaaaaaaaaaaaa", "aaaaaaaaaaaaaaaaaaaa", "aaaaaaaaaaaaaaaaaaaa", "aaaaaaaaaaaaaaaaaaaa", "aaaaaaaaaaaaaaaaaaaa", "aaaaaaaaaaaaaaaaaaaa", "aaaaaaaaaaaaaaaaaaaa", "aaaaaaaaaaaaaaaaaaaa", "aaaaaaaaaaaaaaaaaaaa", "aaaaaaaaaaaaaaaaaaaa", "aaaaaaaaaaaaaaaaaaaa", "aaaaaaaaaaaaaaaaaaaa", "aaaaaaaaaaaaaaaaaaaa", "aaaaaaaaaaaaaaaaaaaa"};
        System.out.println(minimumChanges(a));
    }
    
}
