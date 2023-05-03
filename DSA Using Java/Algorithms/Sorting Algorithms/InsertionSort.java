public class InsertionSort {
    public static void printArray(int[] arr){
        for (int i : arr){
            System.out.print(i+" ");
        }
        System.out.println();
    }
    public static void main(String[] args) {
        int[] arr = {12, 76, 9, 3, 4, 7, 1, 2, 87, 34, 2, 3};
        for (int i = 0; i < arr.length; i++){
            int current = arr[i];
            int j = i-1;
            while (j >= 0 && current < arr[j]){
                arr[j+1] = arr[j];
                j--;
            }
            arr[j+1] = current;
        }
        printArray(arr);
    }
}
