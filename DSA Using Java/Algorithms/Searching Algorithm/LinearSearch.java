public class LinearSearch {
    public static int linearSearch(String[] arr, String key){
        for (int i = 0; i < arr.length; i++){
            if(arr[i] == key){
                return i;
            }
        }
        return -1;
    }

    public static void main(String[] args) {
        String[] colors = {"Red", "Pink", "Blue", "Purple", "White", "Black", "Orange", "Brown", "Indigo", "Yellow"};

        int isFound = linearSearch(colors, "Purple");

        if(isFound == -1){
            System.out.println("Color is not available!");
        } else {
            System.out.println("Color Found at Index "+isFound);
        }
    }
}
