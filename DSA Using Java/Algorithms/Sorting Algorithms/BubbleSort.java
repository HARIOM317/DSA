public class BubbleSort {
    public static void printArray(int[] arr){
        for (int j : arr) {
            System.out.print(j + " ");
        }
        System.out.println();
    }
    public static void main(String[] args) {
        int[] arr = {7, 8, 3, 1, 2, 11, 9};
        System.out.println("Ascending Order");
        for (int i = 0; i < arr.length-1; i++){
            for (int j = 0; j < arr.length-i-1; j++){
                if(arr[j] > arr[j+1]){
                    // swapping using a third variable
                    int temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
                }
            }
        }
        printArray(arr);
        System.out.println("Descending Order");
        for (int i = 0; i < arr.length-1; i++){
            for (int j = 0; j < arr.length-i-1; j++){
                if (arr[j] < arr[j+1]){
                    // swapping without using a third variable
                    arr[j] = arr[j] + arr[j+1];
                    arr[j+1] = arr[j]-arr[j+1];
                    arr[j] = arr[j] - arr[j+1];
                }
            }
        }
        printArray(arr);
    }
}
