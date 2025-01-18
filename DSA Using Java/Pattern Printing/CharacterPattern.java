import java.util.Scanner;

public class CharacterPattern {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter a number : ");
        int n = sc.nextInt();
        char ch = 'A';
        for(int i = 0; i < n; i++){
            for(int j = 0; j <= i; j++){
                System.out.printf("%c ", ch);

                if(ch==90){
                    ch = 65;
                } else {
                    ch++;
                }
            }
            System.out.println();
        }
    }
}
