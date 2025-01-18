public class PairsInArray {
    public static void getPairs(int[] arr){
        for (int i = 0; i < arr.length-1; i++){
            for (int j = i+1; j < arr.length; j++){
                System.out.printf("(%d, %d) ", arr[i], arr[j]);
            }
            System.out.println();
        }
    }

    public static void main(String[] args) {
        int[] arr = {1, 2, 3, 4, 5};
        getPairs(arr);
    }
}
