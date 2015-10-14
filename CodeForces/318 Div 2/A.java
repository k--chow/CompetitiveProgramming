import java.util.*;
import java.io.*;
public class A
{
    public static void main(String [] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = null;
        
        String line = br.readLine();
        st = new StringTokenizer(line);
        int N = Integer.parseInt(st.nextToken());
        int[] data = new int[N];
        line = br.readLine();
        st = new StringTokenizer(line);
        int j=0;
        int start;
        while(st.hasMoreTokens())
        {
            data[j] = Integer.parseInt(st.nextToken());
            j++;
        }
        start = data[0];
        //find largest
        int count = 0;
        int ref = -1;
        //System.out.println(data.length);
        while (true)
        {
            
            int largest = 0;
            //System.out.println("datalength : " + data.length);
            for (int i=0; i<data.length; i++)
            {
                
                if (data[i] >=largest)
                {
                    largest = data[i];
                    ref = i;
                    //System.out.println("ref " + ref);
                }
            }
            
            if (ref == 0)
            {
                System.out.println(count);
                break;
            }
            else
            {
                data[ref]--;
                data[0]++;
                count++;
            }
        }
        
        
            
        
    }
    
    
}
