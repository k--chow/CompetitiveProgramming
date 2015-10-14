import java.util.*;
import java.io.*;
class K
{
    
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static void main(String [] args) throws IOException, NumberFormatException
    {
        while (true)
        {
            String pe = br.readLine();
            int p = Integer.parseInt(pe);
            
            if (pe.equals("0"))
            {
                break;
            }
            
            int length = pe.length();
            
            
                int partL = length/2;
                
                String have = pe.substring(length-partL);
                String reverse = pe.substring(0, partL);
                String rev = palindrome(reverse);
                //System.out.println (rev + " asd " + have);
                int have1 = Integer.parseInt(have);
                int rev1 = Integer.parseInt(rev);
                if (rev.equals(have))
                {
                    System.out.println(0);
                }
                else if (rev1 > have1) // larger so appropriate
                {
                    System.out.println(rev1-have1);
                }
                else if (have1 > rev1)
                {
                    int h =1;
                       for(int i=0; i<partL; i++)
                       {
                           h*=10;
                       }
                    //even
                    if (length % 2 == 0)
                    {
                        int ans = h-have1;
                        p+=ans;
                        pe = p + "";
                        have = pe.substring(partL);
                        reverse = pe.substring(0, partL);
                        rev = palindrome(reverse);
                        rev1 = Integer.parseInt(rev);
                        String rev2 = rev1 + "";
                        while (rev2.length() != partL)
                        {
                            rev2+="0";
                        }
                        int rev3 = Integer.parseInt(rev2);
                        ans+=rev3;
                        System.out.println(ans);
                    }
                    //odd
                    else
                    {
                       
                       System.out.println(h-have1+rev1);
                        
                    }
                
            }/*
            else //odd
            {
                int partL = length/2;
                int have = Integer.parseInt(pe.substring(partL));
            }*/
            
            
        }
        
        
    }
    
    public static String palindrome(String a)
    {
        String reverse = new StringBuffer(a).reverse().toString();
        return reverse;
    }
}
