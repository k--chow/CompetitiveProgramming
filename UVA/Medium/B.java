import java.util.*;
import java.io.*;
class B
{
    public static void main(String [] args) throws IOException
    {
        ArrayList<String> candidates = new ArrayList<String>();
        ArrayList<Integer> votes = new ArrayList<Integer>();
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int cases = Integer.parseInt(br.readLine());
        candidates.add("King23r2ur0923r2");
        votes.add(-1);
        for(int c=0; c<cases; c++)
        {
            String vote = br.readLine();
            int uni = candidates.indexOf(vote);
            if (uni == -1)
            {
                candidates.add(vote);
                votes.add(0);
                votes.set(votes.size()-1, 1);
            }
            else
            {
                votes.set(uni, votes.get(uni) +1);
                
            }
        }
        
        //output largest
        int largest = 0;
        ArrayList<String> refs = new ArrayList<String>();
        for (int i=1; i<candidates.size(); i++)
        {
            if (votes.get(i) >= largest)
            {
                largest = votes.get(i);
            }
        }
        
        for(int i=1; i<candidates.size(); i++)
        {
            if (votes.get(i) == largest)
            {
                refs.add(candidates.get(i));
            }
        }
        Collections.sort(refs);
        for (int i=0; i<refs.size(); i++)
        {
            System.out.println(refs.get(i));
        }
        br.close();
    }
}
