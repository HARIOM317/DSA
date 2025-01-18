public class TrappingRainwater {
    /*
        Problem - Given a non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.
     */

    public static int calculateTotalTrappingRainWater(int[] arr){
        int[] leftMaxBoundary = new int[arr.length];
        int[] rightMaxBoundary = new int[arr.length];
        int totalTrappedWater = 0;

        leftMaxBoundary[0] = arr[0];
        rightMaxBoundary[arr.length-1] = arr[arr.length-1];

        // Calculating maximum boundary of left side
        for (int i = 1; i < arr.length; i++){
            leftMaxBoundary[i] = Math.max(leftMaxBoundary[i-1], arr[i]);
        }

        // Calculating maximum boundary of right side
        for (int i = arr.length-2; i >= 0; i--){
            rightMaxBoundary[i] = Math.max(rightMaxBoundary[i+1], arr[i]);
        }

        // Calculating total trapped water
        for (int i = 0; i < arr.length; i++){
            int waterLevel = Math.min(leftMaxBoundary[i], rightMaxBoundary[i]);
            if(arr[i] < waterLevel){
                totalTrappedWater += waterLevel - arr[i];
            }
        }
        return totalTrappedWater;
    }
    public static void main(String[] args) {
        int[] height = {4, 2, 0, 6, 3, 2, 5};
        System.out.println("Total Trapped Rain Water = "+calculateTotalTrappingRainWater(height));
    }
}
