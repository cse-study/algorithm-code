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
                    System.out.println( stack.empty() ? "1" : "0" );
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

    /**
     * X: 정수 X를 스택에 넣는 연산이다.
     * @param input
     */
    public void push(int value) {
        StackItem newItem = new StackItem(value, topItem);
        this.size += 1;
        this.topItem = newItem;
    }

    /**
     * 스택에서 가장 위에 있는 정수를 빼고, 그 수를 출력한다. 만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력한다.
     * @return
     */
    public int pop() {
        if (this.empty()) {
            return -1;
        }
        else {
            int popValue = this.topItem.getValue();
            StackItem prevItem = this.topItem.getPrevItem();
            this.topItem = null;
            this.topItem = prevItem;
            this.size -= 1;
            return popValue;
        }
    }

    /**
     * 스택에 들어있는 정수의 개수를 출력한다.
     * @return
     */
    public int size() {
        return this.size;
    }

    /**
     * 스택이 비어있으면 1, 아니면 0을 출력한다.
     * @return
     */
    public boolean empty() {
        return this.size == 0;
    }

    /**
     * 스택의 가장 위에 있는 정수를 출력한다. 만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력한다.
     * @return
     */
    public int top() {
        return this.empty()
            ? -1 
            : this.topItem.getValue();
    }
}

class StackItem {
    private int value;
    private StackItem prevItem;

    public StackItem(int value, StackItem prevItem) {
        this.value = value;
        this.prevItem = prevItem;
    }

    public int getValue() {
        return this.value;
    }

    public StackItem getPrevItem() {
        return this.prevItem;
    }
}