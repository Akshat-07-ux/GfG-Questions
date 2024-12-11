//{ Driver Code Starts

// } Driver Code Ends
//Back-end complete function Template for Java
import java.util.*;

public class Main {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt(); // Read the input number
        int i = 10; // Start from 10

        while (i >= 1) { // Loop until i is greater than or equal to 1
            System.out.print(n * i + " "); // Print the table in reverse order
            i--; // Decrement the counter
        }
    }
}


//{ Driver Code Starts.
// } Driver Code Ends