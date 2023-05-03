public class Update_Bit {
    public static int operationOne(int n, int pos){
        int bitMask = 1 << pos;
        int newNumber = bitMask | n;
        return newNumber;
    }

    public static int operationZero(int n, int pos){
        int bitMask = 1 << pos;
        int newNumber = ~(bitMask) & n;
        return newNumber;
    }

    public static void main(String[] args) {
        int n = 5;  // 0101
        int pos = 2;
        int operation = 0;

        if (operation == 1){
            System.out.println(operationOne(n, pos));
        }
        else {
            System.out.println(operationZero(n, pos));
        }
    }
}
