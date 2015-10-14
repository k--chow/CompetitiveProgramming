import java.util.*;
import java.io.*;

public class Isanbaev
{
    static String[][] adj = new String[100][3];
    static TreeMap<String, Integer> dist = new TreeMap<String, Integer>();
    static TreeMap<String, String> pred = new TreeMap<String, String>();
    static LinkedList<String> q = new LinkedList<String>();
    
    public static void main(String [] args) throws IOException
    {
        Scanner in = new Scanner(new File("System.in"));
        PrintWriter out = new PrintWriter(new File("System.out"));
        int R = in.nextInt();
        int C = 3;
        
        
        for(int r=0; r<R; r++)
        {
            for (int c=0; c<C; c++)
            {
                adj[r][c] = in.next();
                
                if (adj[r][c].equalsIgnoreCase("Isenbaev") && !q.contains("Isenbaev"))
                {
                    q.add("Isenbaev");
                    dist.put(adj[r][c], 0);
                    pred.put(adj[r][c], null);
                    //System.out.println("yolo");
                }
                else
                {
                    dist.put(adj[r][c], -1);
                    pred.put(adj[r][c], null);
                }
            }
        }
        
        while (!q.isEmpty())
        {/*
            if (q.isEmpty())
            {
                break;
            }*/
            //System.out.println(q.peek());
            String source = q.remove();
            bfs(adj, source);
            
        }
       
        for (Map.Entry<String, Integer> entry: dist.entrySet())
        {
            String key = entry.getKey();
            String value = entry.getValue().toString();
            if (value.equals("-1"))
            {
                value = "undefined";
            }
            out.println(key + " " + value);
        }
        
        out.close();
    }
    
    public static void bfs(String[][] adj, String source)
    {
        for(int r=0; r<adj.length; r++)
        {
            boolean yes = Arrays.asList(adj[r]).contains(source);
            for (int c=0; c<adj[0].length && yes; c++)
            {
                if (adj[r][c] != source && !q.contains(source) && dist.get(adj[r][c]) == -1)
                {
                    q.add(adj[r][c]);
                    int d = dist.get(source)+1;
                    dist.put(adj[r][c], d);
                    pred.put(adj[r][c], source);
                }
            }
            
               
            
        }
    }
    
    public static class MyScanner {
      BufferedReader br;
      StringTokenizer st;
 
      public MyScanner() {
         br = new BufferedReader(new InputStreamReader(System.in));
      }
 
      String next() {
          while (st == null || !st.hasMoreElements()) {
              try {
                  st = new StringTokenizer(br.readLine());
              } catch (IOException e) {
                  e.printStackTrace();
              }
          }
          return st.nextToken();
      }
 
      int nextInt() {
          return Integer.parseInt(next());
      }
 
      long nextLong() {
          return Long.parseLong(next());
      }
 
      double nextDouble() {
          return Double.parseDouble(next());
      }
 
      String nextLine(){
          String str = "";
	  try {
	     str = br.readLine();
	  } catch (IOException e) {
	     e.printStackTrace();
	  }
	  return str;
      }

   }
}

