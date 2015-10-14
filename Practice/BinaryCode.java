
public class BinaryCode
{/*
    public String[] decode(String message)
    {
        
    }
    */
    public static void code(String message)
    {
        String[] temp = new String[message.length()];
        int i,j;
        for (i=0, j=1; i<message.length(); i++, j++)
        {
            temp[i] = message.substring(i, j);
        }
        

        int before, index = 0, after;
        String finale = "";
        int sum;
        for (; index<message.length(); index++)
        {
            if (index == 0)
            {
                before = 0;
            }
            
            else
            {
                before = Integer.parseInt(temp[index - 1]);
            }
            
            if (index == message.length()-1)
            {
                after = 0;
            }
            
            else
            {
                after = Integer.parseInt(temp[index + 1]);
            }
            
            sum = before + Integer.parseInt(temp[index]) + after;
            finale += sum;
        }
        System.out.println(finale);
    }
    
    public static void main(String [] args)
    {
        code("011100011");
    }
}
