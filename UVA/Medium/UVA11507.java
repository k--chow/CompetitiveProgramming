import java.util.*;
import java.io.*;
class UVA11507
{
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = null;
    String current = "+x";
    String line = null;
    void solve() throws IOException
    {
        while((line=br.readLine()) != null)
        {
            st = new StringTokenizer(line);
            int n = Integer.parseInt(st.nextToken());
            if (n == 0)
            {
                break;
            }
            st = new StringTokenizer(br.readLine());
            current = "+x";
            for(int i=0; i<n-1; i++)
            {
                String next = st.nextToken();
                if (current.equals("+x"))
                {
                    if (!next.equals("No"))
                    {
                    current = next;
                    }
                }
                else if(current.equals("-x"))
                {
                    if(next.equals("+y"))
                    {
                        current = "-y";
                    }
                    else if(next.equals("-y"))
                    {
                        current = "+y";
                    }
                    else if(next.equals("+z"))
                    {
                        current = "-z";
                    }
                    else if(next.equals("-z"))
                    {
                        current = "+z";
                    }
                }
                else if(current.equals("+y"))
                {
                    if (next.equals("+y"))
                    {
                        current= "-x";
                    }
                    else if(next.equals("-y"))
                    {
                        current = "+x";
                    }
                    else if(next.equals("+z"))
                    {
                        
                    }
                    else if(next.equals("-z"))
                    {
                        
                    }
                }
                else if(current.equals("-y"))
                {
                    if (next.equals("+y"))
                    {
                        current= "+x";
                    }
                    else if(next.equals("-y"))
                    {
                        current = "-x";
                    }
                    else if(next.equals("+z"))
                    {
                        
                    }
                    else if(next.equals("-z"))
                    {
                        
                    }
                }
                else if(current.equals("+z"))
                {
                    
                    if(next.equals("+z"))
                    {
                        current = "-x";
                    }
                    else if(next.equals("-z"))
                    {
                        current = "+x";
                    }
                }
                else if(current.equals("-z"))
                {
                    if (next.equals("+y"))
                    {
                        current= "-z";
                    }
                    else if(next.equals("-y"))
                    {
                        current = "-z";
                    }
                    else if(next.equals("+z"))
                    {
                        current = "+x";
                    }
                    else if(next.equals("-z"))
                    {
                        current = "-x";
                    }
                }
                
            }
            System.out.println(current);
        }
    }
    
    public static void main(String [] args) throws IOException
    {
        UVA11507 problem = new UVA11507();
        problem.solve();
    }
}
