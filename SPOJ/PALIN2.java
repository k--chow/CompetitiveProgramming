import java.util.*;
import java.io.*;
import java.math.*;
public class PALIN2
{
	public static String reverse(String s)
	{
		String newString = "";
		for(int i = s.length()-1; i >=0; i-- )
		{
			newString+=s.substring(i, i+1);
		}
		return newString;
	}
 
	public static void main(String [] args) throws IOException
	{
		Scanner in = new Scanner(System.in);
		int cases = in.nextInt();
		for(int i=0; i<cases; i++)
		{
			String input = in.next();
			Boolean odd = false;
			String half;
			if (input.length() == 1 && input != "9")
			{
				int secondInput = (Integer.parseInt(input) + 1);
				input = String.valueOf(secondInput);
			}
			else
			{
 
 
			while(true)
			{
				if (input.length() % 2 != 0)//odd
				{
					half = input.substring(0, (input.length()/2)+1);
					odd = true;
				}
				else //even
				{
					half = input.substring(0, (input.length()/2));
				}
				
				String replaceHalf = reverse(half);
				String secondHalf = input.substring(input.length()/2, input.length());
				BigInteger replaceHalfInt = new BigInteger(replaceHalf);
				BigInteger secondHalfInt = new BigInteger(secondHalf);
				if (replaceHalfInt.compareTo(secondHalfInt) == 1)
				{
					input = half.substring(0, (input.length()/2))+ replaceHalf;
					break;
				}
				else
				{
					BigInteger halfInt = new BigInteger(half);
					BigInteger newHalfInt = halfInt.add(new BigInteger("1"));
					half = newHalfInt.toString();
					String newInput;
					if (odd)
					{
						newInput = input.substring(input.length()/2 +1, input.length());
					}
					else
					{
						newInput = input.substring(input.length()/2, input.length());
					}
					
					String realNewInput = "";
					for(int j=0; j<newInput.length(); j++)
					{
						realNewInput += "0";
					}
					input = half + realNewInput;
					
					//System.out.println(newHalfInt);
				}
 
 
				
			}
		}
			System.out.println(input);
 
			
		}
 
	}
}