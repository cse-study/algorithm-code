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