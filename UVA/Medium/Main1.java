import java.util.*;
import java.io.*;
class Main1
{
    ArrayList<String> names = new ArrayList<String>();
    ArrayList<Integer> comp = new ArrayList<Integer>();
    ArrayList<Double> price = new ArrayList<Double>();
    ArrayList<String> answer = new ArrayList<String>();
    int count = 0;
    void solve()
    {
        Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        names.add("");
        comp.add(-1);
        price.add(100000.0);
        while (true)
        {
            if (count > 0)
            {
                in.nextLine();
            }
            int n= in.nextInt();
            int p = in.nextInt();
            if (n == 0 && p == 0)
            {
                break;
            }
            else
            {
                count++;
                for(int i=0; i<n; i++)
                {
                    in.nextLine();//get rid of garbo
                }
                
                for(int i=0; i<p; i++)
                {
                    in.nextLine();//still? wtf bitch?
                    //String a = in.next();
                    String a = in.next();
                    //System.out.println(in.next());
                    double b = Double.parseDouble(in.next());//price
                    
                    int c = Integer.parseInt(in.next());//compliances
                    if (i== 0) names.set(0, a);
                     if (i== 0) price.set(0, b);
                      if (i== 0) comp.set(0, c);
                      if (i !=0)
                      {
                          if (c>comp.get(0))
                          {
                              names.set(0, a);
                              price.set(0, b);
                              comp.set(0, c);
                            }
                            else if (c == comp.get(0))
                            {
                                if (b < price.get(0))
                                {
                                    names.set(0, a);
                                    price.set(0, b);
                                    comp.set(0, c);
                                }
                            }
                        }
                        //get rid of more garbo
                        for (int z=0; z<c; z++)
                        {
                            in.nextLine();
                        }
                        
                }
                //for loop over.
                answer.add(names.get(0));
            }
            
        }
        for (int i=0; i<count; i++)
            {
                System.out.println("RFP #" + (i+1));
                System.out.println(answer.get(i));
                //System.out.println(price.get(i-1));
                System.out.println();
                
            }
    }
    public static void main(String [] args) throws NumberFormatException
    {
       Main1 problem = new Main1();
       problem.solve();
    }
}
