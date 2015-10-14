import java.util.*;
public class Stack
{
    public static void main(String [] args)
    {
        Deque<Integer> stack = new ArrayDeque<Integer>();
        stack.push(5);
        stack.push(4);
        System.out.println(stack.peek());
        System.out.println(stack.pop());
        System.out.println(stack.peek());
    }
}
