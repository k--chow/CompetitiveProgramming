import java.util.*;
import java.io.*;
class PRIME1
{
    
    public static void main(String [] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = null;
        int i = Integer.parseInt(br.readLine());
        for(int a=0; a<i; a++)
        {
            String line = br.readLine();
            st = new StringTokenizer(line);
            int m = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            double n = (int)Math.sqrt(b) + 1;
            ArrayList<Integer> primes = new ArrayList<Integer>();
            for(int s = 2; s<=b; s++)
            {
                primes.add(s);
                
            }//primes are in arraylist
            //sieve up to sqrt n
            for(int c=2; c<n; c++)
            {
                //if c is in primes, continue
                if (primes.indexOf(c) != -1)
                {
                    for(int l=c+c; l<=b; l+=c)
                    {
                        int index = primes.indexOf(l);
                        //if there, delte
                        if (index != -1)
                        {
                            //System.out.println("Remove " + primes.get(index));
                            primes.remove(index);
                        }
                    }
                }
            }
            /*
            for(int c = 0; c<primes.size(); c++)
            {
                int test = primes.get(c);
                //delete if its there!
                for(int l=test+test; l<=n; l+=test)
                {
                    
                    int index = primes.indexOf(l);
                    
                    if (index != -1)
                    {
                        //System.out.println("REMOVED:" + primes.get(l));
                        primes.remove(index);
                    }
                    
                        //primes.remove(index);
                    
                }
                
               
            }*/
            
            /*
            for(int p=0; p<primes.size(); p++)
            {
                primes.add(primes.get(p))
            }*/
            //print
            for(int p = 0; p<primes.size(); p++)
            {
                if (primes.get(p) >=m && primes.get(p) <=b)
                {
                System.out.println(primes.get(p));
            }
            }
            System.out.println();
            
        }
        
        br.close();
    }
    
    
}
