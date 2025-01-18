public class BubbleSort {
    public static void bubbleSort(int[] arr){
        int swap = 0;
        for (int i = 0; i < arr.length-2; i++){
            for(int j = 0; j < arr.length-1-i; j++){
                if(arr[j] > arr[j+1]){
                    int temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
                    swap++;
                }
            }

            if(swap == 0){
                break;
            }
        }

        System.out.println("No. of Swapping Performed: "+ swap);
    }

    public static void main(String[] args) {
        int[] arr = {5, 4, 1, 3, 2, 7, 6, 12, 8, 7};
        // int[] arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

        bubbleSort(arr);

        // Printing sorted elements
        for (int i : arr) {
            System.out.print(i + " ");
        }
    }
}