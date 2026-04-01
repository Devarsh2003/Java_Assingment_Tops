import java.util.*;

class _HashMap {
    public static void main(String[] args) {
        
        Map<Object, Object> map = new HashMap<>();
        map.put(10, "hello");
        map.put(20, "geek");
        map.put("hello", "world");
        map.put(2.0, 55);

        System.out.println(map);
    }
}