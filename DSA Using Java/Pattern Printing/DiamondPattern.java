import java.util.Scanner;

public class DiamondPattern {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter a number: ");
        int n = sc.nextInt();

        // First Half
        for (int i = 1; i <= n; i++){
            // Spaces
            for(int j = 1; j <= n-i; j++){
                System.out.print("  ");
            }

            // Stars
            for(int j = 1; j <= 2*i-1; j++){
                System.out.print("* ");
            }

            // Next line
            System.out.println();
        }

        // Second Half
        for (int i = n; i >= 1; i--){
            // Spaces
            for(int j = 1; j <= n-i; j++){
                System.out.print("  ");
            }

            // Stars
            for(int j = 1; j <= 2*i-1; j++){
                System.out.print("* ");
            }

            // Next line
            System.out.println();
        }
    }
}
