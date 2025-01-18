public class PrefixSum {
    public static void getMaxSubArraySum(int[] arr){
        int sum = 0;
        int maxSum = Integer.MIN_VALUE;

        // Creating a prefix array
        int[] prefix = new int[arr.length];

        // Calculating Prefix Array
        prefix[0] = arr[0];
        for (int i = 1; i < prefix.length; i++){
            prefix[i] = prefix[i-1] + arr[i];
        }

        // Finding max sum
        for (int i = 0; i < arr.length; i++){
            int start = i;
            for (int j = i; j < arr.length; j++){
                int end = j;
                sum = start == 0 ? prefix[end] : prefix[end] - prefix[start-1];

                if(sum > maxSum){
                    maxSum = sum;
                }
            }
        }

        System.out.println("Maximum Sub-Array Sum = "+maxSum);

    }
    public static void main(String[] args) {
        int[] arr = {2, 7, -10, 11, 22};
        getMaxSubArraySum(arr);
    }
}
