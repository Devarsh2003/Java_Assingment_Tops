import java.util.*;

class _Queue {
    public static void main(String[] args){
        
        Queue<String> queue = new LinkedList<>();
        queue.add("g");
        queue.add("f");
        queue.add("g");

        System.out.println("Initial queue: " + queue);
        System.out.println("Dequeued: " + queue.remove());
        System.out.println("Queue after dequeue: " + queue);
    }
}