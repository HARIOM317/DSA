public class BinarySearch {
    public static int binarySearch(int[] arr, int key){
        int startingPoint = 0;
        int endingPoint = arr.length-1;

        while (startingPoint <= endingPoint){
            int midPoint = (startingPoint + endingPoint)/2;

            if(arr[midPoint] == key){
                return midPoint;
            } else if (arr[midPoint] > key) {
                endingPoint = midPoint - 1;
            } else {
                startingPoint = midPoint + 1;
            }
        }

        return -1;
    }

    public static void main(String[] args) {
        int[] marks = {89, 92, 98, 76, 67, 99, 88, 100, 91, 89};

        int isFound = binarySearch(marks, 99);

        if(isFound == -1){
            System.out.println("Not Found!");
        } else {
            System.out.println("Element Found at Index "+isFound);
        }
    }
}
