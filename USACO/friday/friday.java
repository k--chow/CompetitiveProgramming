/*
ID: k__chow1
LANG: JAVA
PROG: friday
 */
import java.util.*;
import java.io.*;
public class friday
{
    public static void main(String [] args) throws IOException
    {
        Scanner in = new Scanner(new File("friday.in"));
        PrintWriter out = new PrintWriter(new File("friday.out"));
        
        String[] days = {"M", "T", "W", "Th", "F", "SAT", "SUN"};
        String[] months = {"J", "F", "M", "A", "M", "JUN", "JUL", "S", "AUG", "O", "N", "D"};
        int[] daysPerMonth = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int[] daysPerMonthLeap = {31, 29, 31, 30, 31, 30, 31, 31, 30 ,31 ,30, 31};
        int[] answer = {0, 0, 0, 0, 0, 0, 0};
        List<String> firstDay = new ArrayList<String>();
        
        int years = in.nextInt();
        int year = 1900;
        getDays(firstDay, years, year, daysPerMonth, daysPerMonthLeap, days, months);
        firstDay.remove(firstDay.size()-1);
        for (String i : firstDay)
        {
            System.out.println(i);
            for (int g =0; g<7; g++)
            {
                if (days[g].equals(i))
                {
                    answer[g]++;
                }
                
            }
        }
        
        for (int l=0; l<7; l++)
        {
            out.print(answer[l] + " ");
        }
        out.close();
    }
    
    public static void getDays(List xdays, int years, int year, int[] daysPerMonth, int[] daysPerMonthLeap, String[] days,
    String[] months)
    {
        String before = days[5];
        for (int a=0; a<years+1; a++)
        {
            year=1900 + a;
            for (int b=0; b<13; b++)
            {
                if (a == 0 && b == 0)
                {
                    xdays.add(before);
                }
                
                if(b >0)
                {
                
                if (getLeap(a, year))
                {
                    int ref = daysPerMonthLeap[b-1] - 28;
                    int position = 0;
                    
                    for (int c=0; c<7; c++)
                    {
                        if (before.equals(days[c]))
                        {
                            position = c;
                            
                        }
                        
                    }
                    int newPosition = position + ref;
                    if (newPosition > 6)
                    {
                        int opposite = 7- ref;
                        newPosition = position;
                        newPosition -=opposite;
                    }
                    before = days[newPosition];
                    
                    xdays.add(before);
                
             }
             
                
                else
                {
                    int ref = daysPerMonth[b -1] - 28;
                    int position = 0;
             
                    for (int c=0; c<7; c++)
                    {
                        if (before.equals(days[c]))
                        {
                            position = c;
                            
                        }
                        
                    }
                   int newPosition = position + ref;
                    if (newPosition > 6)
                    {
                        int opposite = 7- ref;
                        newPosition = position;
                        newPosition -=opposite;
                    }
                    //3 points missed last one on new position and else
                    before = days[newPosition];
                    
                    xdays.add(before);
                    
                    
                }
            }
            }
        }
    }

    
    public static boolean getLeap(int years, int year)
    {
        
        if (years % 4 == 0)
        {
                if (year % 400 != 0 && year % 100 == 0)
                {
                    return false;
                }
                return true;
        }
        return false;
    }
}
