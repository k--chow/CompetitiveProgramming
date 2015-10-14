import java.util.*;
public class PrivateD2party
{
    int[] a;
    int[] visited;
    boolean dfs(int u)
    {
        if (a[u] == u)
        {
            return false;
        }
        else if(a[visited[u]] == 0)
        {
            
        }
        else if(visited[u] == 2)
        {
            return true;
        }
        return false;
    }
    
    int newdfs(int u)
    {
        if(a[u] == u)
            {
                return 0;
            }
        if (visited[u] == 0)//unvisited node
        {
            visited[u] = 1; //set to currently working
            
            if (visited[a[u]] == 1)//if visited
            {
                
                return 1;
            }
            
            else
            {
                int rem = newdfs(a[u]);
                return rem;
                
                
            }
            
            
        }
        
        return 2;
    }
    
    public int getsz(int[] a)
    {
        this.a = a;
        int N = a.length;
        int cycleCount = 0;
        visited = new int[a.length];
        Arrays.fill(visited, 0);
        
        for(int u=0; u<a.length; u++)
        {
            int b = newdfs(u);
            
            if (b == 1)
            {
                cycleCount++;
            }
            System.out.println(b);
            for(int i=0; i<a.length; i++)
            {
                if (visited[i] == 1)
                {
                    visited[i] = 2;
                }
            }
        }
        
        return N - cycleCount;
        
    }
}
