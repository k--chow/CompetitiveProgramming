import java.util.*;
public class BridgeBuildingDiv2
{
    public static int minDiameter(int[] a, int[] b, int K)
    {
        
        int N = a.length+1;
        int INF = 1000000;
        int[][] dist = new int[2*N][2*N];
        
        char[] charArray = new char[N];
        Arrays.fill(charArray, '1');
        String bb = new String(charArray);
        int maxmin = INF; //answer
        //int bbe = Integer.parseInt(bb);
        //int bbee = Integer.parseInt(bb, 10);
        
        for (int i=0; i<(1<<N); i++)//not sure
        {
            if (Integer.bitCount(i) == K)
            {
                String bed = Integer.toBinaryString(i);
                while (bed.length() <N)
                {
                    bed = "0" + bed;
                }
                
                for(int r=0; r<2*N; r++)
                {
                    Arrays.fill(dist[r], INF);
                    //System.out.println(dist[r][0]);
                }
                //System.out.println(bed);
                for(int j=0; j<N; j++)
                {
                    String chart = bed.substring(j, j+1);
                    //System.out.println(chart);
                    if (Integer.parseInt(chart) == 1)
                    {
                        dist[j][j+N] = 0;//not sure
                        dist[j+N][j] = 0;
                        //System.out.println(j + " " + j+N);
                    }
                    
                }
                
                for (int j=0; j<N-1; j++)
                {
                    dist[j][j+1] = a[j];
                    dist[j+1][j] = a[j];
                }
                
                for (int j=0; j<N-1; j++)
                {
                    dist[j+N][j+N+1] = b[j];
                    dist[j+N+1][j+N] = b[j];
                }
                
                for(int x=0; x<2*N; x++)
                {
                    for (int y=0; y<2*N; y++)
                    {
                        for (int z=0; z<2*N; z++)
                        {
                            dist[y][z] = Math.min(dist[y][z], dist[y][x] + dist[x][z]);
                            
                        }
                    }
                }
                int max=0;
                for(int k=0; k<(2*N); k++)
                {
                    for(int j=k+1; j<(2*N); j++)
                    {
                    
                    max = Math.max(max, dist[k][j]);
                
                    
                }
                }
                
                maxmin = Math.min(maxmin, max);
                
            }
        }
        return maxmin;
    }
    
    public static void main(String [] args)
    {
        int[] a = {50,10,15,31,20,23,7,48,5,50};
        int[] b = {2,5,1,8,3,2,16,11,9,1};

        int k = 3;
        System.out.println(minDiameter(a, b, k));
    }
}
