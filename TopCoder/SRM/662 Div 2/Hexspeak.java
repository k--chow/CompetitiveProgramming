import java.util.*;
public class Hexspeak
{
    public static String decode(long ciphertext)
    {
        long input = ciphertext;
        
        long[] n = {10L, 11L, 12L, 13L, 14L, 15L, 1L, 0L};
        List<Long> nm = new ArrayList<Long>();
        for (int i=0; i<n.length; i++)
        {
            nm.add(n[i]);
        }
        String[] m = {"A", "B", "C", "D", "E", "F", "I", "O"};
        String answer = "";
        while (input >=1)
        {
            long r = input % 16;
            int remainder = (int)r;
            
            input = input/16;
            int index = -1;
            for(int i=0; i<n.length; i++)
            {
                if (n[i] == remainder)
                {
                    index = i;
                }
            }
            
            if (index== -1)
            {
                answer = "Error!";
                
                break;
                
            }
            else
            {
            answer= m[index]+ answer;
            }
            
        }
        return answer;
    }
}
