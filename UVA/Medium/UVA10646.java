import java.util.*;
import java.io.*;
public class UVA10646
{
    String[] cards = new String[52];
    ArrayList<String> face = new ArrayList<String>();
    int Y;
    int c;
    void solve()
    {
        
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = null;
        Scanner in = new Scanner(System.in);
        int N = in.nextInt();
        face.add("2");
        face.add("3");
        face.add("4");
        face.add("5");
        face.add("6");
        face.add("7");
        face.add("8");
        face.add("9");
    
        for(int i=0; i<N; i++)//run through cases
        {
            for(int j=0; j<52; j++)//run through cards in cases
            {
                cards[j] = in.next();
            }
            Y = 0;
            c = 0; //current
            //process 3 times
            process();
            System.out.println(Y + " " + c);
            process();
            System.out.println(Y + " " + c);
            process();
            System.out.println(Y + " " + c);
            System.out.println(cards[52-Y]);
        }
        System.out.println(c);
    }
    
    void process()
    {
        String X = cards[c].substring(0, 1);
        int XX=0;
        if (face.contains(X))
        {
            XX = Integer.parseInt(X);
        }
        else
        {
            XX = 10;
        }
        Y+=XX;
        c+=(10-XX);
        c++;
        
        
        
    }
    
    public void main(String [] args)
    {/*
        UVA10646 problem = new UVA10646();
        problem.solve();*/
        
        
        
        
        
    }
}
