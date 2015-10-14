import java.util.*;
import java.io.*;
public class Fragile2
{
    int vertexCount;
    int[][] edge;
    int[] num;
    int[] low;
    boolean[] visited;
    int[] predecessor;
    boolean[] AP;
    
    
    
    public void runDFS(int u)
    {
        int dfsCount = 0;
        int children = 0;
        visited[u] = true;
        num[u] = low[u] = dfsCount++;
        for (int v=0; v<vertexCount; v++)
        {
            if (edge[u][v] == 1 && visited[v] == false)
            {
                predecessor[v] = u;
                children++;
                runDFS(v);
                
                low[u] = Math.min(low[u], low[v]);
                
                if (predecessor[u] == -1 && children >1)
                {
                    AP[u] = true;
                }
                
                if (predecessor[u] != -1 && low[v] >=num[v])
                {
                    AP[u] = true;
                }
            }
            else if(v != predecessor[u] && edge[u][v] == 1)//shouldn't it be equal to pred?
            {
                low[u] = Math.min(low[u], num[v]);//not sure what's going on here?
            }
            
        }
        
    }
    
    public int countPairs(String[] graph)
    {
        vertexCount = graph.length;
        //set edges
        edge = new int[vertexCount][vertexCount];
        num = new int[vertexCount];
        low = new int[vertexCount];
        predecessor = new int[vertexCount];
        visited = new boolean[vertexCount];
        AP = new boolean[vertexCount];
        HashMap<Integer, Integer> answer = new HashMap<Integer, Integer>();
        ArrayList<Integer> a = new ArrayList<Integer>();
        ArrayList<Integer> b = new ArrayList<Integer>();
        int extra = 0;
        for (int r=0; r<vertexCount; r++)
        {
            Arrays.fill(edge[r], 0);
            predecessor[r] = -1;
            visited[r] = false;
        }
        for(int r=0; r<vertexCount; r++)
        {
            int former = 0;
            while (true)
            {
                int index = graph[r].indexOf("Y", former+1);
                former = index;
                if (index  >=0)
                {
                    edge[r][index] = 1;
                    edge[index][r] = 1;
                }
                else
                {
                    break;
                }
                
            }
        }
        for (int u=0; u<vertexCount; u++)
        {
            runDFS(u);
        }
        for(int i=0; i<vertexCount; i++)
        {
            for(int j=0; j<vertexCount; j++)
            {
                if (i != j)
                {
                    if (AP[i] == true && AP[j] == true)
                    {
                        a.add(i);
                        b.add(j);
                        
                            
                        
                        
                        
                            
                        
                    }
                    else if(AP[i] == true)
                    {
                       if (predecessor[i] != j && predecessor[j] != i)
                       {
                         a.add(i);
                         b.add(j);
                        
                        
                            
                        
                        }
                    }
                    else if(AP[j] == true)
                    {
                        if (predecessor[j] != i && predecessor[i] != j)
                        {
                        a.add(i);
                        b.add(j);
                        
                        
                        
                        }
                    }
                }
            }
        }
        //sort answer though
        
        for (int i=0; i< a.size(); i++)
        {
            for (int j=0; j< b.size(); j++)
            {
                if (a.get(i) == b.get(j) && a != b)
                {
                    if (a.get(j) == b.get(i))
                    {
                        a.remove(j);
                        b.remove(j);
                    }
                }
            }
        }
        for(int i=0; i<a.size(); i++)
        {
            System.out.println(a.get(i) + " " +b.get(i));
        }
        return a.size();
    }
    
    public static void main(String[] args)
    {
        String[] graph =         
{"NYNYNNYYNN", "YNNNYNYYNN", "NNNNYNNNYN", "YNNNYYNNNN", "NYYYNNNNYN",
 "NNNYNNNNYN", "YYNNNNNNNN", "YYNNNNNNYN", "NNYNYYNYNY", "NNNNNNNNYN"}
;

        Fragile2 test = new Fragile2();
        System.out.println(test.countPairs(graph));

    }
    
}
