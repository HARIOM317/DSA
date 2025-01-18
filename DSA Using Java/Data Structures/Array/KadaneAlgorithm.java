public class KadaneAlgorithm {
    /*
        According to Kadane's Algorithm if current sum is negative at any point then consider it as 0. It will not work if every element are negative in array, so we need to write special condition and loop for this.

        Ex. - If arr[] = {-2, -3, 4, -1, -2, 1, 5, -3}

        Current Sum : {0, 0, 4, 3, 1, 2, 7, 4}
        Maximum Sum : {0, 0, 4, 4, 4, 4, 7, 7}

        Hence, Maximum Sub Array Sum = 7
        Time Complexity = O(n)
     */

    public static void kadaneAlgo(int[] arr){
        int currentSum = 0;
        int maximumSum = Integer.MIN_VALUE;
        int maximumNumber = Integer.MIN_VALUE;
        
        // If all element are negative
        for (int i = 0; i < arr.length; i++){
            if(maximumNumber < arr[i]){
                maximumNumber = arr[i];
            }
        }

        // Kadane's Algorithm to find maximum sub-array sum
        if(maximumNumber > 0) {
            for (int i = 0; i < arr.length; i++){
                currentSum = currentSum + arr[i];
                if(currentSum < 0){
                    currentSum = 0;
                }
                if(currentSum > maximumSum){
                    maximumSum = currentSum;
                }
            }
        } else {
            maximumSum = maximumNumber;
        }

        System.out.println("Maximum Sub-Array Sum = "+maximumSum);
    }

    public static void main(String[] args) {
        int[] arr = {-2, -3, 4, -1, -2, 1, 5, -3};
        kadaneAlgo(arr);
    }
}
