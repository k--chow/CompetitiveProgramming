import java.util.*;
import java.io.*;
public class hashsettest
{
    public static void main(String [] args)
    {
        HashSet<Integer>[] ed = new HashSet[10];
        ed[0] = new HashSet<Integer>();
        ed[0].add(5);
        ed[0].add(5);
        System.out.println(ed[0]);
    }
}
