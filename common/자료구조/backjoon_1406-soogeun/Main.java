import java.io.IOException;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Stack;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringBuilder stringBuilder = new StringBuilder();

        String initialString = br.readLine();
        Editor editor = new Editor(initialString);
        int numOfCommandLines = Integer.parseInt(br.readLine());

        for(int i = 0; i < numOfCommandLines; i++) {
            String commandLine = br.readLine();
            String[] arguments = commandLine.split(" ");
            String command = arguments[0];

            String invaildCommandError = "command is invalid.";     // Error Message

            switch( command ) {
                case "L":
                    editor.moveCursorLeft();;
                    break;

                case "D":
                    editor.moveCursorRight();
                    break;

                case "B":
                    editor.deleteChar();
                    break;

                case "P":
                    assert arguments.length == 2: invaildCommandError;
                    assert arguments[1].length() == 1: invaildCommandError;
                    char inputLetter = arguments[1].charAt(0);
                    editor.inputChar(inputLetter);
                    break;

                default:
                    throw new Error(invaildCommandError);
            }
        }

        bw.write(editor.getText(stringBuilder) + "\n");

        br.close();
        bw.flush();
        bw.close();
    }
}

class Editor {
    private Stack<Character> leftText;     // cursor의 왼쪽 text 영역
    private Stack<Character> rightText;    // cursor의 오른쪽 text 영역

    public Editor (String text) {
        leftText = new Stack<Character>();
        rightText = new Stack<Character>();
        for (char c : text.toCharArray()) {
            leftText.push(c);
        }
    }

    public String getText(StringBuilder stringBuilder) {
        // string builder를 인자로 받았지만, 여기서 선언해서 사용해도 됩니다.
        while (!this.leftText.empty()) {
            this.rightText.push(this.leftText.pop());
        }
        while (!this.rightText.empty()) {
            stringBuilder.append(this.rightText.pop());
        }

        return stringBuilder.toString();
    }

    public void moveCursorLeft() {
        if ( this.isLeftMost() )
            return;
        this.rightText.push(this.leftText.pop());
        return;
    }

    public void moveCursorRight() {
        if ( this.isRightMost() )
            return;
        this.leftText.push(this.rightText.pop());
        return;
    }

    public void deleteChar() {
        if ( this.isLeftMost() )
            return;
        this.leftText.pop();
        return;
    }
    public void inputChar(char c) {
        this.leftText.push(c);
        return;
    }

    private boolean isLeftMost() {
        return this.leftText.isEmpty();
    }
    private boolean isRightMost() {
        return this.rightText.isEmpty();
    }
}