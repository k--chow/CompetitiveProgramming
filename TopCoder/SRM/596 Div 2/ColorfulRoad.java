import java.util.*;
public class ColorfulRoad
{
   public static int getMin(String road)
   {
       int L = road.length();
       int inf = 10000;
       HashMap<String, String> next = new HashMap<String, String>();
       next.put("R", "G");
       next.put("G", "B");
       next.put("B", "R");
       int[] f = new int[L];
       f[L-1] = 0;
       for(int j=L-2; j<0; j++)
       {
           f[j] = inf;
           for (int i=0; i<L-1; i++)
           {
               if (road.substring(j-1, j).equals(next.get(road.substring(i, i+1))))
               {
                   
                }
            }
        }
    }
}
