import java.util.*;

class _Heap {
    public static void main(String[] args) {

        PriorityQueue<Integer> minHeap = new PriorityQueue<>();
        minHeap.add(5);
        minHeap.add(7);
        minHeap.add(9);
        minHeap.add(1);

        System.out.println("Heap: " + minHeap);
        System.out.println("Smallest element: " + minHeap.poll());
        System.out.println("Heap after poll: " + minHeap);
    }
}