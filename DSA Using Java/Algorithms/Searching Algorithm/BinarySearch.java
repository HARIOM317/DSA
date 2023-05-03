public class BinarySearch {
    public static int binarySearch(int[] arr, int key){
        int startingIndex = 0;
        int endingIndex = arr.length;
        while (startingIndex <= endingIndex){
            int mid = (startingIndex+endingIndex)/2;
            if (arr[mid] == key){
                return mid;
            } else if (arr[mid] > key) {
                endingIndex = mid-1;
            } else {
                startingIndex = mid+1;
            }
        }
        return -1;
    }
    public static void main(String[] args) {
        int[] arr = {2, 3, 5, 7, 8, 9, 10, 12, 24, 34, 45, 56, 67, 88, 99, 100};
        int ans = binarySearch(arr, 45);
        System.out.println("Index : "+ans);
    }
}
