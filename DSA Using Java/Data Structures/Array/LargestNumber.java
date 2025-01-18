public class LargestNumber {
    public static int getLargestNumber(int[] arr){
        int max = Integer.MIN_VALUE; // storing -infinity in max variable
        for (int i = 0; i < arr.length; i++){
            if(arr[i] > max){
                max = arr[i];
            }
        }

        return max;
    }
    public static void main(String[] args) {
        int[] numbers = {23, 12, 76, 98, 87, 97, 43, 65, 88, 98, 12, 76, 54, 32};

        int max = getLargestNumber(numbers);
        System.out.println("Maximum number = "+max);
    }
}
