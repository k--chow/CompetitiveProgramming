
/**
 * Write a description of class BridgeBuildingDiv2 here.
 * 
 * @author (your name) 
 * @version (a version number or a date)
 */
public class BridgeBuildingDiv2
{
    public int minDiameter(int[] a, int [] b, int k)
    {
        int N = a.length + 1;
        int answer = Integer.MAX_VALUE;
        for(int c=0; c<(1<<N); c++)
        {
            if (Integer.bitCount(c) == k)
            {
                String bi = Integer.toBinaryString(c);
                while (bi.length() != N)
                {
                    bi = "0" + bi;
                }
                int distance = 0;
                for (int i=0; i<N-1; i++)
                {
                    if (bi.substring(i, i+2).equals("11"))//both
                    {
                        if (a[i] < b[i])
                        {
                            distance+= a[i];
                        }
                        else
                        {
                            distance +=b[i];
                        }
                        
                    }
                    else//not both
                    {
                        if (a[i] > b[i])
                        {
                            distance += a[i];
                        }
                        else
                        {
                            distance += b[i];
                        }
                    }
                }
                if (distance < answer)
                {
                    answer = distance;
                }
            }//big if statement
        }
        return answer;
    }
}
