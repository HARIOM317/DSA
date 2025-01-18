public class BinaryToDecimal {
    public static int getDecimal(int n){
        int decimal = 0;
        int power = 0;

        while (n > 0) {
            int lastDigit = n % 10;
            lastDigit = (int) (lastDigit * Math.pow(2, power));
            decimal += lastDigit;
            n /= 10;
            power++;
        }
        return decimal;
    }
    public static void main(String[] args) {
        int decimal = getDecimal(100);

        System.out.println("Decimal = "+decimal);
    }
}
