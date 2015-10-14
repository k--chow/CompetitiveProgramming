import java.util.*;
import java.io.*;
public class B
{
    static boolean[] visited;
    static int[][] adj;
    static State state[];
    static int L;
    enum State {
        White, Gray, Black
    }
    public static void main(String [] args)
    {
        Scanner in = new Scanner(System.in);
        L = in.nextInt();
        int go = in.nextInt();
        adj =  new int[L][L];
        visited = new boolean[L];
        Arrays.fill(visited, false);
        Arrays.fill(state, State.White);
        for(int i=0; i<L; i++)
        {
            Arrays.fill(adj[i], 0);
        }
        for(int i=0; i<go; i++)
        {
            int a = in.nextInt();
            int b = in.nextInt();
            adj[a][b] = 1;
            adj[b][a] = 1;
        }
        //all set now compute cycles
        //find all edges that arent within the thing
        
    }
    
    void dfs(int[][] adj, int start)
    {
        //visited[start] = true;
        state[start] = State.Gray;
        for(int i=0; i<L; i++)
        {
            if (adj[start][i] == 1 && state[i] == State.White)
            {
                dfs(adj, i);
            }
            
        }
        state[start] = State.Black;
    }
    
}
