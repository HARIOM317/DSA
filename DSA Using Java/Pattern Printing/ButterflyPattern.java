import java.util.Scanner;

public class ButterflyPattern {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter a number : ");
        int n = sc.nextInt();

        // First Half
        for (int i = 1; i <= n; i++){
            // stars - i
            for(int j = 1; j <= i; j++){
                System.out.print("* ");
            }

            // spaces - 2*(n-i)
            for(int j = 1; j <= 2*(n-i); j++){
                System.out.print("  ");
            }

            // stars - i
            for(int j = 1; j <= i; j++){
                System.out.print("* ");
            }

            // Next line
            System.out.println();
        }

        // Second Half
        for (int i = n; i >= 1; i--){
            // stars - i
            for(int j = 1; j <= i; j++){
                System.out.print("* ");
            }

            // spaces - 2*(n-i)
            for(int j = 1; j <= 2*(n-i); j++){
                System.out.print("  ");
            }

            // stars - i
            for(int j = 1; j <= i; j++){
                System.out.print("* ");
            }

            // Next line
            System.out.println();
        }
    }
}
