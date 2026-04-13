import java.util.*;

public class Main {

    public static String reverseWords(String s) {

        s = s.trim();

        int i = s.length() - 1;
        StringBuilder sb = new StringBuilder();

        while(i >= 0){

            if(s.charAt(i) != ' '){

                int end = i;

                while(i >= 0 && s.charAt(i) != ' '){
                    i--;
                }

                sb.append(s, i + 1, end + 1);

            } else {
                while(i >= 0 && s.charAt(i) == ' '){
                    i--;
                }

                sb.append(' ');
            }
        }

        return sb.toString();
    }

    public static void main(String[] args) {

        System.out.println(reverseWords("  hello world  "));
    }

}
