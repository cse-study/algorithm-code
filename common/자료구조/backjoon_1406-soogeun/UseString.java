/**
 * 하나의 문자열과 index를 의미하는 cursor를 이용하여 구현
 * 하지만 String의 내장 method를 사용할 때, time complexity가 높아서 
 * 시간 효용성에서 Fail 되었습니다.
 */

import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;

public class UseString {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
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

        System.out.println(editor.getText());
        br.close();
    }
}

class Editor {
    private String text;    // 만약 문자열 이외의 item을 담는 editor였다면, LinkedList를 이용했어야 할 듯
    private int cursorIdx;

    public Editor (String text) {
        this.text = text;
        this.cursorIdx = text.length();
    }

    public String getText() {
        return text;
    }

    public void moveCursorLeft() {
        if ( this.isLeftMost() )
            return;
        this.cursorIdx -= 1;
        return;
    }

    public void moveCursorRight() {
        if ( this.isRightMost() )
            return;
        this.cursorIdx += 1;
        return;
    }

    public void deleteChar() {
        if ( this.isLeftMost() )
            return;
        this.text = this.text.substring(0, cursorIdx - 1) + this.text.substring(cursorIdx);
        this.cursorIdx -= 1;
        return;
    }
    public void inputChar(char c) {
        this.text = this.text.substring(0, cursorIdx) + c + this.text.substring(cursorIdx);
        this.cursorIdx += 1;
        return;
    }

    private boolean isLeftMost() {
        return this.cursorIdx == 0;
    }
    private boolean isRightMost() {
        return this.cursorIdx == this.text.length();
    }
}