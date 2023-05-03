public class QuickSort {
    public static void printArray(int[] arr){
        for (int element:arr){
            System.out.print(element+" ");
        }
        System.out.println();
    }
    public static int partition(int[] arr, int low, int high){
        int pivot = arr[high];
        int i = low-1;

        for (int j = low; j < high; j++){
            if (arr[j] < pivot){
                i++;
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        i++;
        int temp = arr[i];
        arr[i] = arr[high];
        arr[high] = temp;
        return i;   // pivot index
    }
    public static void quickSort(int[] arr, int low, int high){
        if (low < high){
            int pivotIndex = partition(arr, low, high);
            quickSort(arr, low, pivotIndex-1);
            quickSort(arr, pivotIndex+1, high);
        }
    }
    public static void main(String[] args) {
        int[] arr = {10, 8, 5, 3, 12, 98, 0, 54, 67, 11, 23, 9, 34, 15};
        int n = arr.length;

        quickSort(arr, 0, n-1);
        printArray(arr);
    }
}
