import java.util.*;
public class Hexspeak
{
    public String decode(long ciphertext)
    {
        int input = (int)(ciphertext);
        int[] n = {10, 11, 12, 13, 14, 15, 1, 0};
        List<Integer> nm = new ArrayList<Integer>();
        for (int i=0; i<n.length; i++)
        {
            nm.add(n[i]);
        }
        String[] m = {"A", "B", "C", "D", "E", "F", "I", "O"};
        String answer = "";
        while (input !=0)
        {
            int r = input % 16;
            input/= 16;
            int i= nm.indexOf(r);
            if (i== -1)
            {
                answer = "Error!";
                break;
                
            }
            answer+= m[i];
            
        }
        return answer;
    }
}
