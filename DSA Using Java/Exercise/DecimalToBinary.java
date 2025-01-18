public class DecimalToBinary {
    public static void getBinary(int n){
        int binary = 0;
        int pow = 0;
        while(n > 0){
            int lastDigit = n%2;
            binary = binary + (int)(lastDigit*Math.pow(10, pow));
            n /= 2;
            pow++;
        }

        System.out.println("Binary = "+binary);
    }
    public static void main(String[] args) {
        int decimal = 5;
        getBinary(decimal);
    }
}
