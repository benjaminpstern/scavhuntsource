import java.util.Scanner;
import java.util.ArrayList;
import java.io.FileOutputStream;
import java.io.ObjectOutputStream;
import java.io.IOException;
public class Encode {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        ArrayList<Character> a = new ArrayList<Character>();
        while (sc.hasNextLine()) {
            String s = sc.nextLine();
            for (int i = 0; i < s.length(); i++) {
                a.add(s.charAt(i));
                a.add('\n');
            }
        }
        try {
            FileOutputStream f = new FileOutputStream("code.encoded");
            ObjectOutputStream ob = new ObjectOutputStream(f);
            ob.writeObject(a);
            ob.close();
            f.close();
        }
        catch (IOException i) {
            System.out.println("Could not encode your text");
        }
    }
}
