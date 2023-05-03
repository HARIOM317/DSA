public class MergeSort {
    public static void printArray(int[] arr){
        for (int element: arr){
            System.out.print(element+" ");
        }
        System.out.println();
    }
    public static void conquer(int[] arr, int startingIndex, int mid, int endingIndex){
        int[] mergedArray = new int[endingIndex-startingIndex+1];
        int index1 = startingIndex;
        int index2 = mid+1;
        int x = 0;
        while (index1 <= mid && index2 <= endingIndex){
            if (arr[index1] <= arr[index2]){
                mergedArray[x] = arr[index1];
                x++;
                index1++;
            }
            else {
                mergedArray[x] = arr[index2];
                x++;
                index2++;
            }
        }

        while (index1 <= mid){
            mergedArray[x] = arr[index1];
            x++;
            index1++;
        }

        while (index2 <= endingIndex){
            mergedArray[x] = arr[index2];
            x++;
            index2++;
        }

        // copying elements
        for (int i = 0, j = startingIndex; i < mergedArray.length; i++, j++){
            arr[j] = mergedArray[i];
        }
    }
    public static void divide(int[] arr, int startingIndex, int endingIndex){
        if (startingIndex >= endingIndex){
            return;
        }
        int mid = startingIndex + (endingIndex - startingIndex)/2;
        // int mid = (startingIndex+endingIndex)/2; // containing more space for larger values
        divide(arr, startingIndex, mid);
        divide(arr, mid+1, endingIndex);
        conquer(arr, startingIndex, mid, endingIndex);
    }
    public static void main(String[] args) {
        int[] arr = {7, 4, 9, 1, 2, 98, 0, 3, 4, 17, 97, 32, 11, 39};
        int n = arr.length;
        divide(arr, 0, n-1);
        printArray(arr);
    }
}
