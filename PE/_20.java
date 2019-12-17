import java.util.*;
import java.math.*;

public class _20 {
  public static void main(String args[]) {
    BigInteger num = new BigInteger("3628800");
    for(long i = 11; i < 101; i++) {
      num = num.multiply(BigInteger.valueOf(i));
    }
    long ans = 0;
    for(char x : num.toString().toCharArray()) 
      ans += x - '0';
    System.out.println(ans);
  }
}
