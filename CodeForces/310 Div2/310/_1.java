import java.util.*;
public class _1
{
    
    public static void main(String [] args)
    {
       Scanner in = new Scanner(System.in);
       int l = in.nextInt();
       String a = in.next();
       ArrayList<String> n = new ArrayList<String>();
       boolean noMore = false;
       for (int i=0; i<l; i++)
       {
           n.add(a.substring(i, i+1));
        }
        
       while (!noMore)
       {
               if (n.size() <2)
            {
                noMore = true;
            }
           int x = 0;
           int y = 1;
           if (n.get(x).equals("0"))
           {
                if (n.get(y).equals("1"))
                {
                    n.remove(x);
                    n.remove(x);
                }
           }
           else if (n.get(x).equals("1"))
           {
               if (n.get(y).equals("0"))
               {
                   n.remove(x);
                   n.remove(x);
                }
           }
           else 
           {
               if (n.size() >2)
               {
                   x+=1;
                   y+=1;
                           if (n.get(x).equals("0"))
                   {
                        if (n.get(y).equals("1"))
                        {
                            n.remove(x);
                            n.remove(x);
                        }
                   }
                   else if (n.get(x).equals("1"))
                   {
                       if (n.get(y).equals("0"))
                       {
                           n.remove(x);
                           n.remove(x);
                        }
                   }
                }
                else
                {
                    noMore = true;
                }
            }
           
          
       }
       System.out.println
       
       
       in.close();
    }
}
