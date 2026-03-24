import java.util.Scanner; // Import the Scanner class

public class EvenOdd {
    public static void main(String[] args) {
        // Create a Scanner object to read input from the user
        Scanner reader = new Scanner(System.in);

        // Prompt the user to enter a number
        System.out.print("Enter a number: ");
        
        // Read the integer input from the user and store it in the 'num' variable
        int num = reader.nextInt();

        // Check if the number is even or odd using the modulo operator
        // The modulo operator (%) returns the remainder of a division.
        if (num % 2 == 0) {
            // If the remainder is 0, the number is even
            System.out.println(num + " is even.");
        } else {
            // If the remainder is not 0, the number is odd
            System.out.println(num + " is odd.");
        }
        
        
        reader.close();
    }
}
