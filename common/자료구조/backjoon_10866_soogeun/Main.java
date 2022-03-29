import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main (String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int numsOfCommandLines = Integer.parseInt(br.readLine());
        SooDequq dequq = new SooDequq();

        for (int i = 0; i < numsOfCommandLines; i++) {
            String command = br.readLine();

            switch (command) {
                case Constants.POP_FRONT:
                    System.out.println(dequq.popFront());
                    break;

                case Constants.POP_BACK:
                    System.out.println(dequq.popBack());
                    break;

                case Constants.SIZE:
                    System.out.println(dequq.size());
                    break;

                case Constants.EMPTY:
                    System.out.println(dequq.empty() ? "1" : "0");
                    break;

                case Constants.FRONT:
                    System.out.println(dequq.front());
                    break;

                case Constants.BACK:
                    System.out.println(dequq.back());
                    break;

                /**
                 * Push_front, Push_back case와, 에러 헨들링을 포함.
                 */
                default:
                    String[] arguments = command.split(" ");
                    assert arguments.length == 2: Constants.COMMAND_ERROR;
                    
                    command = arguments[0];
                    int inputValue = Integer.parseInt(arguments[1]);

                    if ( command.equals(Constants.PUSH_FRONT) ) {
                        dequq.pushFront(inputValue);
                    }
                    else if ( command.equals(Constants.PUSH_BACK) ) {
                        dequq.pushBack(inputValue);
                    }
                    else 
                        throw new Error(Constants.COMMAND_ERROR);
            }
        }

        br.close();
    }    
}

/**
 * Generics로 구현하려 했으나, empty일 때 -1을 출력하게끔 반환하는 부분에서 막혀서 구현하지 못함.
 */
class SooDequq {
    private SooItem head;
    private SooItem tail;
    private int size;

    public SooDequq() {
        this.initiateDeque();
    }

    private void initiateDeque() {
        this.head = null;
        this.tail = null;
        this.size = 0;
    }

    public void pushFront(int inputValue) {
        SooItem newItem = new SooItem(inputValue, this.head, null);
        if (this.empty()) 
            this.tail = newItem;
        else 
            this.head.next = newItem;
        this.head = newItem;
        this.size += 1;
    }

    public void pushBack(int inputValue) {
        SooItem newItem = new SooItem(inputValue, null, this.tail);
        if (this.empty()) 
            this.head = newItem;
        else
            this.tail.prev = newItem;
        this.tail = newItem;
        this.size += 1;
    }

    public int popFront() {
        if (this.empty())
            return -1;

        int returnValue = this.head.getValue();

        if (this.size == 1) {
            this.initiateDeque();
        }
        else {
            this.head = this.head.prev;
            this.head.next = null;
            this.size -= 1;
        }

        return returnValue;
    }

    public int popBack() {
        if (this.empty())
            return -1;

        int returnValue = this.tail.getValue();
        
        if (this.size == 1) {
            this.initiateDeque();
        }
        else {
            this.tail = this.tail.next;
            this.tail.prev = null;
            this.size -= 1;
        }

        return returnValue;
    }

    public int size() { 
        return this.size; 
    }

    public boolean empty() { 
        return this.size == 0; 
    }

    public int front() {
        return this.empty() ? -1 : this.head.getValue();
    }

    public int back() {
        return this.empty() ? -1 : this.tail.getValue();
    }
}

class SooItem {
    /**
     * prev와 next를 default로 선언한 이유는, 해당 property들이 getter, setter 
     * 모두 정의 되어야 하며 이 두 method 외에는 사용되는 경우가 없기 때문에, default로
     * 선언했을 때와 차이가 없기 때문입니다.
     * 따라서 코드의 가독성을 높이기 위해 default로 선언하였습니다. 하지만, 두 property 모두 
     * 변경될 때, Deque 전체에 영향을 주기 때문에, 같은 패키지 내에서만 접근을 허용할 수 있도록
     * public이 아닌 default로 선언하였습니다.  
     */
    SooItem prev;
    SooItem next;
    private int value;

    public SooItem(int value, SooItem prev, SooItem next) {
        this.value = value;
        this.prev = prev;
        this.next = next;
    }

    public int getValue() {
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