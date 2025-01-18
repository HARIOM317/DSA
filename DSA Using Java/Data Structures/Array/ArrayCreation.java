public class ArrayCreation {
    public static void main(String[] args) {
        // Array Creation
        // First way
        int[] marks = new int[50];      // store by default 0 in all index
        marks[0] = 10;
        marks[1] = 20;
        marks[2] = 30;
        for (int num : marks){
            System.out.print(num+" ");
        }
        System.out.println();

        // Second way
        int[] numbers = {1,2,3,4,5,6,7,8,9,10};
        for (int number : numbers) {
            System.out.print(number + " ");
        }

        String[] fruits = {"Apple", "Mango", "Banana", "Orange", "Papaya"};

        System.out.println();
        for (String element : fruits){
            System.out.print(element+" ");
        }


    }
}
