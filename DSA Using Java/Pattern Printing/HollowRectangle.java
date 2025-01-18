import java.util.Scanner;

public class HollowRectangle {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter row and column : ");
        int row = sc.nextInt();
        int column = sc.nextInt();

        // Hollow Rectangle
        for (int i = 1; i <= row; i++){
            for(int j = 1; j <= column; j++){
                if(i == 1 || i == row || j == 1 || j == column){
                    System.out.print("* ");
                } else {
                    System.out.print("  ");
                }
            }
            System.out.println();
        }
    }
}
