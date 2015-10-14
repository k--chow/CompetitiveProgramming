import java.util.*;
import java.io.BufferedReader;
import java.io.BufferedInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;

public class sd
{
    
    public static void main(String [] args) throws IOException
    {
       Reader.init(System.in);
       
       int l = Reader.nextInt();
       
       String a = Reader.next();
       
       ArrayList<String> n = new ArrayList<String>();
       boolean noMore = false;
       for (int i=0; i<l; i++)
       {
           n.add(a.substring(i, i+1));
        }
        
       int x=0;
       int y=1;
       
       
       
       while (!noMore)
       {
           if (n.size() <2)
           {
               noMore = true;
               
            }
           else
           {
           if (n.get(x).equals("0"))
           {
                if (n.get(y).equals("1"))
                {
                    n.remove(x);
                    n.remove(x);
                    x=0;
                    y=1;
                }
                else
           {
               x++;
               y++;
               if(y == n.size())
               {
                   noMore = true;
                }
                
           }
           }
           else
           {
               if (n.get(y).equals("0"))
               {
                   n.remove(x);
                   n.remove(x);
                   x=0;
                   y=1;
                }
                else
           {
               x++;
               y++;
               if(y == n.size())
               {
                   noMore = true;
                }
                
           }
           }
           
       
    
       
    }
}
    System.out.println(n.size());
       
       
    }
}

class Reader {
    static BufferedReader reader;
    static StringTokenizer tokenizer;

    /** call this method to initialize reader for InputStream */
    static void init(InputStream input) {
        reader = new BufferedReader(
                     new InputStreamReader(input) );
        tokenizer = new StringTokenizer("");
    }

    /** get next word */
    static String next() throws IOException {
        while ( ! tokenizer.hasMoreTokens() ) {
            //TODO add check for eof if necessary
            tokenizer = new StringTokenizer(
                   reader.readLine() );
        }
        return tokenizer.nextToken();
    }

    static int nextInt() throws IOException {
        return Integer.parseInt( next() );
    }
	
    static double nextDouble() throws IOException {
        return Double.parseDouble( next() );
    }
}
