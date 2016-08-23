import java.util.*;
import java.math.*;

public class C
{
  public static void main(String [] args)
  {
      Scanner in = new Scanner(System.in);
      String input = in.next();
      BigInteger start = new BigInteger(input);
      BigInteger a = new BigInteger("3");
      BigInteger b = new BigInteger("4");
      BigInteger c = new BigInteger("5");
      BigInteger even = new BigInteger("2");

        if (start.mod(a) == BigInteger.ZERO)
        {
          BigInteger mult = start.divide(a);
          System.out.println(b.multiply(mult) + " " + c.multiply(mult));
        } else if (start.mod(b) == BigInteger.ZERO)
        {
          BigInteger mult = start.divide(b);
          System.out.println(a.multiply(mult) + " " + c.multiply(mult));
        } else if (start.mod(c) == BigInteger.ZERO)
        {
          BigInteger mult = start.divide(c);
          System.out.println(a.multiply(mult) + " " + b.multiply(mult));
        }
       else {
        if (start.equals(new BigInteger("1")) || start.equals(new BigInteger("2")))
        {
          System.out.println("-1");
        } else if (start.mod(even) != BigInteger.ZERO){// check odd
          System.out.println(start.pow(2).subtract(new BigInteger("1")).divide(even)+ " " + start.pow(2).subtract(new BigInteger("1")).divide(even).add(new BigInteger("1")));
        } else {
          System.out.println(start.pow(2).divide(b).subtract(new BigInteger("1")) + " " + start.pow(2).divide(b).add(new BigInteger("1")));
        }

      }

  }
}
