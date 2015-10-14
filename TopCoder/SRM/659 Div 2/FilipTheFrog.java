import java.util.*;
public class FilipTheFrog
{
    public static int countReachableIslands(int[] positions, int L)
    {
        int start = positions[0];
        int count = 1;
        Arrays.sort(positions);
        int upstart = start;
        int downstart = start;
        int index = -1;
        for (int i=0; i<positions.length; i++)
        {
            System.out.println(positions[i]);
            if (start == positions[i])
            {
                index = i;
            }
        }
        //up
        for (int i=index;i<positions.length-1; i++)
        {
            if (positions[i+1] <= upstart+L)//does upstart go
            {
                upstart = positions[i+1];
                count++;
                System.out.println("up " + positions[i+1]);
            }
            else
            {
                break;
            }
            
           
        }
        
        for (int i=index;i>0; i--)
        {
            if (positions[i-1] >= downstart-L)//does upstart go
            {
                downstart = positions[i-1];
                System.out.println("down " + positions[i-1]);
                count++;
            }
            else
            {
                break;
            }
            
           
        }
        
        return count;
    }
    
    
}
