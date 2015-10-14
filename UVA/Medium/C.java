
import java.util.*;
import java.io.*;
import java.math.*;
class C
{
    static BigInteger[] a = new BigInteger[1000001];
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static void main(String [] args) throws IOException, NumberFormatException
    {
        a[1] = new BigInteger("1");
        
        
        
        while (true)
    {
        int next = Integer.parseInt(br.readLine());
        if (next == 0)
        {
            break;
        }
        else
        {
            if (a[next] == (null))
            {
            for(int i=2; i<=next; i++)
            {
                String ib = i + "";
                BigInteger b = new BigInteger(ib);
                a[i] = calculate(b, i-1);
                //System.out.println(ib + " " + a[i]);
                
                
                
            }
            }
            
            System.out.println(a[next]);
        }
    }
    }
    
    public static BigInteger calculate(BigInteger i, int past)
    {
        //MathContext mc = new MathContext(4);
        BigInteger answer = i;
        
        BigInteger b3 = answer.multiply(answer);
        
        BigInteger b4 = b3.add(i);
        BigInteger d = new BigInteger("2");
        BigInteger b5 = b4.divide(d);
        BigInteger b6 = b5.add(a[past]);
        return b6;
    }
    
    
    
}
