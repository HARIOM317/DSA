public class LinearSearch {
    public static int linearSearch(int[] arr, int key){
        for (int i = 0; i < arr.length; i++){
            if (arr[i] == key){
                return i;
            }
        }
        return -1;
    }
    public static void main(String[] args) {
        int[] arr = {1, 9, 8, 45, 7, 23, 11 , 10, 17, 6, 5, 3, 12};
        int ans = linearSearch(arr, 17);
        System.out.println("Index : "+ans);
    }
}
