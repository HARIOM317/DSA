import java.util.Scanner;

public class PalindromicPyramidPattern {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter a number : ");
        int n = sc.nextInt();

        // ===== Logic 1 =====
//        for (int i = 1; i <= n; i++){
//            // Spaces
//            for(int j = 1; j <= n-i; j++){
//                System.out.print("  ");
//            }
//
//            // Numbers
//            for (int j = 1; j <= 2*i-1; j++){
//                if(j <= i){
//                    System.out.print((i-j+1) + " ");
//                } else {
//                    System.out.print((j-i+1)+" ");
//                }
//            }
//
//            // Next line
//            System.out.println();
//        }

        // ===== Logic 2 =====
        for (int i = 1; i <= n; i++){
            // Spaces
            for(int j = 1; j <= n-i; j++){
                System.out.print("  ");
            }

            // Decreasing Numbers
            for(int j = i; j >= 1; j--){
                System.out.print(j+" ");
            }

            // Increasing Numbers
            for(int j = 2; j <= i; j++){
                System.out.print(j+" ");
            }

            // New line
            System.out.println();
        }
    }
}
