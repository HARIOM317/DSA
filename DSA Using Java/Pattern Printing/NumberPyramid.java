import java.util.Scanner;

public class NumberPyramid {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter a number : ");
        int n = sc.nextInt();

        for (int i = 1; i <= n; i++){
            // Spaces
            for (int j = 1; j <= n-i; j++){
                System.out.print(" ");
            }

            // Numbers
            for(int j = 1; j <= i; j++){
                System.out.print(i+" ");
            }

            // Next line
            System.out.println();
        }
    }
}
