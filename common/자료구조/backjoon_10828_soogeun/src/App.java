import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;

public class App {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int lineCounts = Integer.parseInt(br.readLine());

        Stack stack = new Stack();

        for (int i = 0; i < lineCounts; i++) {
            String command = br.readLine();
            String[] argments = command.split(" ");

            switch (argments[0]) {
                case "push":
                    int pushItem = Integer.parseInt(argments[1]);
                    stack.push(pushItem);
                    break;
                case "pop":
                    System.out.println( stack.pop() );
                    break;
                case "size":
                    System.out.println( stack.size() );
                    break;
                case "empty":
                    System.out.println( stack.empty() );
                    break;
                case "top":
                    System.out.println( stack.top() );
                    break;
                default:
                    System.out.println("Wrong command");
            }
        }

        br.close();
    }
}

class Stack {
    private int size;
    private StackItem topItem;

    public Stack() {
        this.size = 0;
        this.topItem = null;
    }

    public void push(int input) {
    }

    public int pop() {
        return 0;
    }

    public int size() {
        return 1;
    }

    public int empty() {
        return 2;
    }

    public int top() {
        return 3;
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