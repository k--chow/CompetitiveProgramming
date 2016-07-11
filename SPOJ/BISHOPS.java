import java.util.*;
import java.io.*;
import java.math.*;
class BISHOPS
{
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	//static PrintWriter out = new PrintWriter(System.out);
	public static void main(String [] args) throws IOException
	{
		
		String line;
		while((line = br.readLine()) != null)
		{
			BigInteger a = new BigInteger(line);
			BigInteger one = new BigInteger("1");
			if (a.equals(one))
			{
				System.out.println(line);
			}
			else
			{
				a = a.subtract(one);
				a = a.multiply(new BigInteger("2"));
				System.out.println(a);
			}
			
		}
		//out.flush();
		br.close();


	}

}