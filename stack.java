import java.util.*;

class _Stack {
    public static void main(String[] args) {
       
        ArrayDeque<String> dequeStack = new ArrayDeque<>();
        dequeStack.push("g");
        dequeStack.push("f");
        dequeStack.push("h");

        System.out.println("Initial ArrayDeque Stack: " + dequeStack);
        System.out.println("Popped from ArrayDeque: " + dequeStack.pop());
        System.out.println("ArrayDeque Stack after pop: " + dequeStack);
    }
}