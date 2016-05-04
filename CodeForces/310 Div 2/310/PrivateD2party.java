import java.util.*;
public class PrivateD2party
{
    private int[] a;
    private int[] status;
    private int count = 0;
    public void dfs(int i)
    {
        if (a[i] == i && status[i] == 0)
        {
            count++;
            status[i] = 1;
        }
        else if (status[i] == 0)
        {
            
            status[i] = 1;
            if (status[a[i]] == 0)
            {
                count++;
                //status[a[i]] = 1;
                dfs(a[i]);
            }
            
        }
    }
    
    public int getsz(int[] a)
    {
        this.a = a;
        status = new int[a.length];
        Arrays.fill(status, 0);
        
        for(int i=0; i<a.length; i++)
        {
            dfs(i);
        }
        return count;
    }
}
