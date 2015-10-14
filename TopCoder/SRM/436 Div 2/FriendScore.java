import java.util.*;
public class FriendScore
{
    int[] dist;
    int[] predecessor;
    String[][] friendsa;
    LinkedList<Integer> queue = new LinkedList<Integer>();
    int max = 0;
    
    public int highestScore(String[] friends)
    {
        int L = friends.length;
        friendsa = new String[L][L];
        for(int r=0; r<L; r++)
        {
            for (int c=0; c<L; c++)
            {
                friendsa[r][c] = friends[r].substring(c, c+1);
            }
        }
    
    int count = 0;
    int max = 0;
    for (int a=0; a<L; a++)
    {
        count = 0;
        for (int b=0; b<L; b++)
        {
            if (friendsa[a][b].equals("Y"))
            {
                count++;
            }
            else if(a !=b)
            {
                

            for (int c=0; c<L; c++)
            {
                if(a != c && b != c)
                {
            
                if (friendsa[a][c].equals("Y") && friendsa[b][c].equals("Y"))
                {
                    count++;
                    break;
                }
            }
        }
            }
        }
        if (count >max)
        {
            max = count;
        }
        
        
       }
        
            return max;
        
        
    
}
    
}
