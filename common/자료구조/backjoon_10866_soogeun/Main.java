import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main (String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int numsOfCommandLines = Integer.parseInt(br.readLine());

        for (int i = 0; i < numsOfCommandLines; i++) {
            String command = br.readLine();

            switch (command) {
                case Constants.POP_FRONT:
                    System.out.println(command);
                    break;

                case Constants.POP_BACK:
                    System.out.println(command);
                    break;

                case Constants.SIZE:
                    System.out.println(command);
                    break;

                case Constants.EMPTY:
                    System.out.println(command);
                    break;

                case Constants.FRONT:
                    System.out.println(command);
                    break;

                case Constants.BACK:
                    System.out.println(command);
                    break;

                /**
                 * Push_front, Push_back case와, 에러 헨들링을 포함.
                 */
                default:
                    String[] arguments = command.split(" ");
                    assert arguments.length == 2: Constants.COMMAND_ERROR;
                    
                    command = arguments[0];
                    int InputValue = Integer.parseInt(arguments[1]);

                    if ( command.equals(Constants.PUSH_FRONT) ) {
                        System.out.println(command + InputValue);
                    }
                    else if ( command.equals(Constants.PUSH_BACK) ) {
                        System.out.println(command + InputValue);
                    }
                    else 
                        throw new Error(Constants.COMMAND_ERROR);
            }
        }

        br.close();
    }    
}

class SooDequq <T> {
    private SooItem<T> head;
    private SooItem<T> tail;
    private int size;

    public SooDequq() {
        this.head = null;
        this.tail = null;
        this.size = 0;
    }

    public void pushFront(T inputValue) {}
    public void pushBack(T inputValue) {}
    public T popFront() {
    }
    public T popBack() {}

    public int size() { 
        return this.size; 
    }

    public boolean empty() { 
        return this.size == 0; 
    }

    public T front() {}
    public T back() {}
}

class SooItem <T> {
    /**
     * prev와 next를 default로 선언한 이유는, 해당 property들이 getter, setter 
     * 모두 정의 되어야 하며 이 두 method 외에는 사용되는 경우가 없기 때문에, default로
     * 선언했을 때와 차이가 없기 때문입니다.
     * 따라서 코드의 가독성을 높이기 위해 default로 선언하였습니다. 하지만, 두 property 모두 
     * 변경될 때, Deque 전체에 영향을 주기 때문에, 같은 패키지 내에서만 접근을 허용할 수 있도록
     * public이 아닌 default로 선언하였습니다.  
     */
    SooItem<T> prev;
    SooItem<T> next;
    private T value;

    public SooItem(T value, SooItem prev, SooItem next) {
        this.value = value;
        this.prev = prev;
        this.next = next;
    }

    public T getValue() {
        return value;
    }
}


/**
 * class that defines the constants.
 */
final class Constants {
    public static final String PUSH_FRONT      = "push_front";
    public static final String PUSH_BACK       = "push_back";
    public static final String POP_FRONT       = "pop_front";
    public static final String POP_BACK        = "pop_back";
    public static final String SIZE            = "size";
    public static final String EMPTY           = "empty";
    public static final String FRONT           = "front";
    public static final String BACK            = "back";

    public static final String COMMAND_ERROR   = "This command is invaild.";
}