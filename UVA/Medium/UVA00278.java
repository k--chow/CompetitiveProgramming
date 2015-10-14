//UVA00278
import java.util.*;
import java.io.*;
class UVA00278
{
    
    void solve() throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = null;
        String a = br.readLine();
        int b = Integer.parseInt(a);
        for(int i=0; i<b; i++)
        {
            String line = br.readLine();
            st = new StringTokenizer(line);
            String next = st.nextToken();
            int r = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());
            if (next.equals("r"))
            {
                int min = Math.min(r, c);
                System.out.println(min);
            }
            else if (next.equals("k") )
            {
                int rc = (r * c)/2;
                System.out.println(rc);
            }
            else if (next.equals("Q"))
            {
                int min = Math.min(r, c);
                System.out.println(min);
            }
            else if(next.equals("K"))
            {
                if (r % 2 != 0)
                {
                    r /= 2;
                    r++;
                }
                else
                {
                    r/=2;
                }
                if (c % 2 !=0)
                {
                    c/=2;
                    c++;
                }
                else
                {
                    c/=2;
                }
                System.out.println(r *c);
            }
            
        }
        br.close();
    }
    public static void main(String [] args) throws IOException
    {
        UVA00278 problem = new UVA00278();
        problem.solve();
    }
}
