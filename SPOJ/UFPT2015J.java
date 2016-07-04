import java.util.*;
import java.io.*;
import java.math.*;
class PALIN 
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
		while (1)
		{
			String input = in.next();
			if (input == "0") break;
			Boolean odd = false;
			String half;
			
			if (isPalindrome(intput))//already palin
			{
				input = "0";
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
				long replaceHalfInt = Long.parseLong(replaceHalf);
				long secondHalfInt = Long.parseLong(secondHalf);
				if (replaceHalfInt.compareTo(secondHalfInt) == 1)
				{
					input = half.substring(0, (input.length()/2))+ replaceHalf;
					break;
				}
				else
				{
					long halfInt = Long.parseLong(half);
					long newHalfInt = halfInt + 1;
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
}



