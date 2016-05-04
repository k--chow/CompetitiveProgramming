import java.util.*;
import java.io.BufferedReader;
import java.io.BufferedInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;

public class dsfwet
{
    public static void main(String [] args) throws IOException
    {
        Reader.init(System.in);
        int N = Reader.nextInt();
        String answer = "";
        int[] ints = new int[N];
        String[] parts = new String[N-1];
        boolean yes = false;
        String test= "";
        for(int i=0; i<N; i++)
        {
            ints[i] = Reader.nextInt();
            answer+=Integer.toString(i);
            test+=Integer.toString(ints[i]);
        }
        if (test.equals(answer))
        {
            System.out.println("Yes");
        }
        else
        {
        for (int n=0; n<N-1; n++)
        {
            parts[n] = "";
            for (int i=0; i<N; i++)
            {
                if (i %2 == 0)
                {
                    ints[i]++;
                    if (ints[i] == N)
                    {
                        ints[i] = 0;
                    }
                    parts[n]+=Integer.toString(ints[i]);
                }
                else 
                {
                    ints[i]--;
                    if (ints[i] == -1)
                    {
                        ints[i] = N-1;
                    }
                    parts[n]+=Integer.toString(ints[i]);
                }
            }
            
        }
        for (int i=0; i<N-1; i++)
        {
            if (parts[i].equals(answer))
            {
                yes = true;
            }
        }
        
        
        if (yes)
        {
            System.out.println("Yes");
        }
        else
        {
            System.out.println("No");
        }
    }
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
