import java.util.*;

public class _14 {
  public static int pos[];
  public static void main(String args[]) {
    pos = new int[100000000];
    for(int i = 0; i < 100000000; i++)
      pos[i] = -1;
    pos[1] = 1;
    for(int i = 2; i < 1000000; i++)
      if(-1 == pos[i]) backtrack(i);
    int mx = 0;
    int ans = -1;
    for(int i = 1; i < 1000000; i++)
      if(pos[i] >= mx) {
        mx = pos[i];
        ans = i;
        System.out.printf("%d %d\n", ans, mx);
      }
    System.out.println(ans);
  }

  public static int backtrack(long x) {
    long xx = (x % 2 == 1 ? 3 * x + 1 : x / 2);
    if(x >= 100000000L) return 1 + backtrack(xx);
    if(-1 != pos[(int) x]) return pos[(int) x];
    return pos[(int) x] = 1 + backtrack(xx);
  }
}
