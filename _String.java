class Geeks {
    public static void main(String[] args) {
        
        // Immutable String
        String s = "Hello Geeks";
        System.out.println(s);
        
        // Mutable StringBuilder
        StringBuilder sb = new StringBuilder("Hello");
        sb.append(" Geeks");
        System.out.println(sb.toString());
    }
}