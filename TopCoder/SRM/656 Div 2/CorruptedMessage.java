import java.util.*;
import java.io.*;
import java.lang.*;
public class CorruptedMessage
{
    public String reconstructMessage(String s, int k)
    {
        int right = s.length() - k-1;
        String test = "";
        boolean noAnswer = true;
        String record = "";
        for(int i=0; i<s.length(); i++)
        {
            test = s.substring(i, i+1);
            int count = 0;
            if (record.indexOf(test) == -1)
            {
            for(int j=i+1; j<s.length(); j++)
            {
                if (test.equals(s.substring(j,j+1)))
                {
                    count++;
                }
            }
            System.out.println(test + " " + count);
            record+=test;
            if (count == right)
            {
                noAnswer = false;
                break;
            }
            }
        }
        
        String answer="";
        for(int i=0; i<s.length() && !noAnswer; i++)
        {
            answer+=test;
        }
        
        for(char a = 'a'; a <= 'z' && noAnswer; a++)
        {
            if (s.indexOf(a) == -1)
            {
                for(int i=0; i<s.length(); i++)
                {
                    answer+=a;
                }
                break;
            }
        }
        return answer;
    }
}
