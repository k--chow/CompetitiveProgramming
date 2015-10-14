
public class TheAirTripDivTwo
{
   public int find(int[] flights, int fuel)
   {
       int count = 0;
       int fuel2 = fuel;
       for(int i=0; i<flights.length; i++)
       {
           if (fuel2 >=flights[i])
           {
               count++;
               fuel2-=flights[i];
            }
            else
            {
                break;
            }
        }
        return count;
    }
   
}
