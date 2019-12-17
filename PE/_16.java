import java.util.*;
import java.math.*;

public class _16 {
  public static void main(String args[]) {
    BigInteger x = new BigInteger("2");
    x = x.pow(1000);
    String s = x.toString();
    int ans = 0;
    for(char a : s.toCharArray()) ans += a - '0';
    System.out.println(ans);
  }
}
