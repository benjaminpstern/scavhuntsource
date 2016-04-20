import java.util.ArrayList;
import java.io.FileInputStream;
import java.io.ObjectInputStream;
import java.io.IOException;
import java.lang.ClassNotFoundException;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.util.Scanner;
public class Decode {
    public static ArrayList<Character> getList(String filename) {
        try {
            FileInputStream file = new FileInputStream(filename);
            ObjectInputStream obj = new ObjectInputStream(file);
            Object o = obj.readObject();
            ArrayList<Character> chars = (ArrayList<Character>)o;
            file.close();
            obj.close();
            return chars;
        }
        catch (IOException i) {
            System.out.println("Could not decode file");
            System.exit(1);
        }
        catch (ClassNotFoundException e) {
            System.out.println("Could not find file");
            System.exit(1);
        }
        return null;
    }
    public static void main(String[] args) {
        if (args.length < 1) {
            System.out.println("Please enter a filename to decode");
        }
        else {
            String filename = args[0];
            ArrayList<Character> list = getList(filename);
            File f = new File(".n");
            int n = 0;
            if (f.exists() && !f.isDirectory()) {
                try {
                    Scanner sc = new Scanner(f);
                    sc.useDelimiter("");
                    if (sc.hasNext()) {
                        String s = sc.next();
                        if (s.length() > 0) {
                            n = (int)s.charAt(0);
                        }
                        sc.close();
                    }
                    else {
                        sc.close();
                    }
                }
                catch (FileNotFoundException e) {
                    System.out.println("There is a problem");
                }
            }
            System.out.print(list.get(n));
            try {
                FileWriter writer = new FileWriter(".n", false);
                n++;
                n %= list.size();
                writer.write((char)n);
                writer.close();
            }
            catch (IOException e) {
                System.out.println("Unable to get next character");
            }
        }
    }
}
