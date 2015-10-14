import java.util.*;
import java.io.*;
class Snail3
{
    ArrayList<String> names = new ArrayList<String>();
    ArrayList<Integer> comp = new ArrayList<Integer>();
    ArrayList<Double> price = new ArrayList<Double>();
    ArrayList<String> answer = new ArrayList<String>();
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = null;
    int count = 0;
    void solve() throws IOException, NumberFormatException
    {
        //Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        
        
        names.add("");
        comp.add(-1);
        price.add(100000.0);
        String line = null;
        while ((line=br.readLine()) != null)
        {
            st = new StringTokenizer(line);
            
            int n= Integer.parseInt(st.nextToken());
            int p = Integer.parseInt(st.nextToken());
            if (n == 0 && p == 0)
            {
                break;
            }
            else
            {
                count++;
                for(int i=0; i<n; i++)
                {
                    br.readLine();//get rid of requirements
                }
                
                for(int i=0; i<p; i++)
                {
                    
                    String a = br.readLine();
                    //System.out.println(in.next());
                    st = new StringTokenizer(br.readLine());
                    double b = Double.parseDouble(st.nextToken());//price
                    
                    int c = Integer.parseInt(st.nextToken());//compliances
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
                            br.readLine();
                        }
                        
                }
                //for loop over.
                answer.add(names.get(0));
                //print answer
            }
            System.out.println("RFP #" + count);
            System.out.println(names.get(0));
            System.out.println();
            //br.close();
        }
        /*for (int i=0; i<count; i++)
            {
                System.out.println("RFP #" + (i+1));
                System.out.println(answer.get(i));
                //System.out.println(price.get(i-1));
                System.out.println();
                
            }*/
    }
    public static void main(String [] args) throws IOException
    {
       Snail3 problem = new Snail3();
       problem.solve();
       
    }
}
