public class SelectionSort {
    public static void printArray(int[] arr){
        for (int i:arr){
            System.out.print(i+" ");
        }
        System.out.println();
    }
    public static void main(String[] args) {
        int[] arr = {9, 5, 2, 3, 0, 12, 7, 8, 4, 11};
        System.out.println("Sorting in Ascending order");
        for (int i = 0; i < arr.length-1; i++){
            int smallest = i;
            for (int j = i+1; j < arr.length; j++){
                if (arr[smallest] > arr[j]){
                    smallest = j;
                }
            }
            int temp = arr[smallest];
            arr[smallest] = arr[i];
            arr[i] = temp;
        }
        printArray(arr);

        System.out.println("Sorting in Descending order");
        for (int i = 0; i < arr.length-1; i++){
            int greatest = i;
            for (int j = i+1; j < arr.length; j++){
                if (arr[greatest] < arr[j]){
                    greatest = j;
                }
            }
            int temp = arr[greatest];
            arr[greatest] = arr[i];
            arr[i] = temp;
        }
        printArray(arr);
    }
}
