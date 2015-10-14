import java.util.*;
import java.io.*;
public class TwoTeams11062
{
    static TreeMap<Integer, Integer> color = new TreeMap<Integer, Integer>();
    static TreeMap<Integer, Integer> pred = new TreeMap<Integer, Integer>();
    public static void main(String [] args) throws IOException
    {
        Scanner in = new Scanner(new File("System.in"));
        PrintWriter out = new PrintWriter(new File("System.out"));
        int N = in.nextInt();
        for(int i=1; i<N+1; i++)
        {
            
           color.put(i, -1);
            
            //pred.put(i, null);
        }
        color.put(1, 1);
        pred.put(1, null);
        
        for(int i=1; i<N+1; i++)//traverse
        {
            while(true)
            {
                int b = in.nextInt();
                if (b !=0)
                {
                    if (color.get(b) == -1)//unvisited
                    {
                        
                        pred.put(b, i);
                        if(color.get(i) != -1)
                        {
                            int check = color.get(i);
                            if (check == 1)
                            {
                                color.put(b, 2);
                            }
                            else
                            {
                                color.put(b, 1);
                            }
                        }
                        else
                        {
                            color.put(b, 1);
                        }
                        
                    }
                    else
                    {
                        
                    }
                }
                else
                {
                    break;
                }
            }
        }
         ArrayList<Integer> fiends = new ArrayList<Integer>();
        for (int i=1; i<N+1; i++)
        {
            int a = color.get(i);
            
            if (a == 2)
            {
                fiends.add(i);
            }
           
        }
        
        out.println(fiends.size());
        
        for(int i=0; i<fiends.size(); i++)
        {
            out.print(fiends.get(i) + " ");
        }
        out.close();
        
       
        
    }
    
}
