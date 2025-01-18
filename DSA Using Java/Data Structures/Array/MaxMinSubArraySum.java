public class MaxMinSubArraySum {
    public static void getMaxAndMinSubArraySum(int[] arr){
        int max = Integer.MIN_VALUE;
        int min = Integer.MAX_VALUE;
        int sum = 0;

        for (int i = 0; i < arr.length; i++){
            for(int j = i; j < arr.length; j++){
                sum = 0;
                for(int k = i; k <= j; k++){
                    sum += arr[k];
                }
                if(sum > max) {
                    max = sum;
                }
                if (sum < min){
                    min = sum;
                }
            }
        }

        System.out.println("Min Sub Array Sum = "+min);
        System.out.println("Max Sub Array Sum = "+max);
    }
    public static void main(String[] args) {
        int[] arr = {-1, 92, 32, -4, 3, -5, -8, 11, -25};
        getMaxAndMinSubArraySum(arr);
    }
}
