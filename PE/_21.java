import java.util.*;

public class _21 {
  public static void main(String args[]) {
    int d[] = new int[10000];
    for(int i = 1; i < 10000; i++)
      for(int j = i + i; j < 10000; j += i)
        d[j] += i;
    int ans = 0;
    for(int i = 2; i < 10000; i++)
      if(d[i] < 10000 && i == d[d[i]] && d[i] != i) ans += i;;
    System.out.println(ans);
  }
}
