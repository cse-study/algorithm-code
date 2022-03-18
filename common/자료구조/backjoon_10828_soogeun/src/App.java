import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;

public class App {

    private int size = 0;
    private StackItem topItem;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int lineCounts = Integer.parseInt(br.readLine());

        for (int i = 0; i < lineCounts; i++) {
            String command = br.readLine();
            String[] argments = command.split(" ");

            switch (argments[0]) {
                case "push":
                    int pushItem = Integer.parseInt(argments[1]);
                    System.out.println("command is push + " + pushItem);
                    break;
                case "pop":
                    System.out.println("command is pop");
                    break;
                case "size":
                    System.out.println("command is size");
                    break;
                case "empty":
                    System.out.println("command is empty");
                    break;
                case "top":
                    System.out.println("command is top");
                    break;
                default:
                    System.out.println("Wrong command");
            }
        }

        br.close();
    }

    private int push(int input) {
        return 0;
    }

    private int pop() {
        return 0;
    }

    private int size() {
        return 0;
    }

    private boolean empty() {
        return false;
    }

    private int top() {
        return 0;
    }
}


class StackItem {
    private int value;
    private StackItem prevItem;

    public int getValue() {
        return value;
    }

    public void pushItem(int value, StackItem prevItem) {
    }

    public StackItem popItem() {
        return prevItem;
    }
}