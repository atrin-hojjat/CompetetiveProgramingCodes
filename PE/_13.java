import java.util.*;
import java.math.BigInteger;

public class _13 {
  public static void main(String args[]) {
    Scanner in = new Scanner(System.in);
    BigInteger ans = new BigInteger("0");
    for(int i = 0; i < 100; i++)
    {
      String s = in.nextLine();
      ans = ans.add(new BigInteger(s));
    }
    String ss = ans.toString();
    for(int i = 0; i < 10; i++) System.out.print(ss.charAt(i));
  }
}
