public class CallByReference {
    public static void updateMarks(int[] marks, int nonChangeable){
        nonChangeable = 20;
        for (int i = 0; i < marks.length; i++){
            marks[i] = marks[i] + 3;
        }
    }
    public static void main(String[] args) {
        int[] marks = {97, 85, 92, 91, 96};
        int nonChangeable = 10;

        updateMarks(marks, nonChangeable);

        System.out.println("nonChangeable = "+nonChangeable);

        // Updated marks
        for (int mark : marks) {
            System.out.print(mark + " ");
        }
    }
}
