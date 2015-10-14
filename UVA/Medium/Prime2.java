import java.util.*;
import java.io.*;
public class Prime2
{
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st = null;;
    public static void main(String [] args) throws IOException, NumberFormatException
    {
        
        
        int cases = Integer.parseInt(br.readLine());
        String line;
        for(int cas = 0; cas<cases; cas++)
        {
        line = br.readLine();
        st = new StringTokenizer(line);
        int a = Integer.parseInt(st.nextToken());
        int b = Integer.parseInt(st.nextToken());
        boolean prime[] = new boolean[b+2];
        //set all to true
        Arrays.fill(prime, true);
        //sieve values!
        for(int s = 2; s*s<=b; s++)//test up to sq rt
        {
            //only if s is prime
            if (prime[s] == true)
            {
                for(int go=s+s; go<=b; go+=s)
                {
                    prime[go] = false;
                }
            }
        }
        //print primes in between
        int start = 2;
        if (a > 2)
        {
            start = a;
        }
        
        for(int p = start; p<=b; p++)
        {
            if (prime[p] == true)
            {
                System.out.println(p);
            }
            

        }
        System.out.println();
        
        }
        //br.close();
        
    }
}
