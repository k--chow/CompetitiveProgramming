import java.util.*;
import java.io.*;
public class Hexspeak {

private List<Integer> N = new ArrayList<Integer>();


private String[] M = {"A", "B", "C", "D", "E", "F", "I", "O"};
	public static void main(String[] args) throws IOException {
	    Hexspeak t = new Hexspeak();
		
		Scanner in = new Scanner(System.in);
		long a = in.nextLong();
		System.out.println(t.decode(a));
	}
	
	public String decode(long a)
	{
	    N.add(10);
        N.add(11);
        N.add(12);
        N.add(13);
        N.add(14);
        N.add(15);
        N.add(1);
        N.add(0);
		String answer = "";
		boolean done = false;
		boolean no = false;
		while (!done)
		{
			long r = (a % 16);
			Integer rint = (int)(long)r;
			int index = N.indexOf(rint);
			a = a/16;
			if (index > -1)
			{
			    answer=M[index] + answer;
			    if (a < 16)
			    {
			        r = (a %16);
			        rint = (int)(long)r;
			        index = N.indexOf(rint);
			        if (index >-1)
			        {
			            answer=M[index] + answer;
			         }
			        else
			        {
			            no = true;
    			     done = true;
    			     answer = "Error!";
			         }
			        done = true;
			     }
			 }
			 else
			 {
			     no = true;
			     done = true;
			     answer = "Error!";
			 }
		}
		return answer;
	} 
	


}