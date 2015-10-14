import java.util.*;
public class CostOfDancing
{
    public int minimum(int K, int[] danceCost)
    {
        int[] test = danceCost;
        
        Arrays.sort(test);
        
        int total = 0;
        for(int i=0; i<K; i++)
        {
            total+=test[i];
        }
        return total;
    }
}
