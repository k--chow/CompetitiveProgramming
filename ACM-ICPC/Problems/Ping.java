import java.util.*;
import java.io.*;
class Ping
{
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    int factors(int number, ArrayList<Integer> a)
    {
        int count = 0;
        //get half + 1
        int half = (int)(number/2) +1;
        for(int i=1; i<=half; i++)
        {
            if (number % i == 0)//a factor
            {
                if (a.contains(i))
                {
                count++;
                }
            }
        }
        return count;
    }
    
    void solve() throws IOException {
        
        while(true)
        {
            ArrayList<Integer> answers = new ArrayList<Integer>();
            String line = br.readLine();
            if (!(line.length() == 1 && line.charAt(0) == '0'))
            {
                for (int i=1; i<line.length(); i++)
                {
                    char c = line.charAt(i);
                    if(factors(i, answers) % 2 !=0)//not even
                    {
                        if (c == '0')
                        {
                            answers.add(i);
                        }
                    }
                    else { //even {
                        if (c == '1')
                        {
                            answers.add(i);
                        }
                    }
                }
            }
            else
            {
                break;
            }
            //print  answers
            
            for (int i=0; i<answers.size(); i++)
            {
                if(i !=answers.size()-1)
                {
                System.out.print(answers.get(i) + " ");
                }
                else
                {
                    System.out.print(answers.get(i));
                }
                
            }
            System.out.println();
        }
    }
    public static void main(String [] args) throws IOException
    {
        Main p = new Main();
        p.solve();
    }
}
