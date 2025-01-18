public class ReverseArray {
    public static void reverseArray(int[] arr){
        for (int i = 0; i < arr.length/2; i++){
            // Another solution for swapping
            // int temp = arr[arr.length-i-1];
            // arr[arr.length-i-1] = arr[i];
            // arr[i] = temp;

            // Optimal solution
            arr[i] = arr[i] + arr[arr.length-i-1];
            arr[arr.length-i-1] = arr[i] - arr[arr.length-i-1];
            arr[i] = arr[i] - arr[arr.length-i-1];
        }
    }

    public static void main(String[] args) {
        int[] numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 20, 30, 40, 50, 60, 70, 80, 90, 100};

        reverseArray(numbers);

        for (int i = 0; i < numbers.length; i++){
            System.out.print(numbers[i]+" ");
        }
    }
}
