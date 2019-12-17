import java.util.*;

public class _216 {
  public static void main(String args[]) {
    boolean prime[] = new boolean[50000001];
    boolean ok[] = new boolean[50000001];
    ArrayList<Integer> primes = new ArrayList<>();
    for(int i = 2; i < 50000001; i++) prime[i] = true;
    for(int i = 2; i < 50000001; i++) {
      if(prime[i] == true) primes.add(i);
      for(int x : primes)
      {
        if(x * i > 50000000) break;
        prime[x * i] = false;
        if(i % x == 0) break;
      }
    }
    for(int x : primes) {
      if(x == 2) continue;
      int c = (x + 1) / 2;
      for(int i = c; i < 50000001; i += x) {
        int w = (int) Math.sqrt(i);
        if(w * w == i) ok[w] = true;
      }
    }
    int cnt = 0;
    for(int i = 2; i < 10000; i++)
      if(ok[i] == false) cnt++;
    System.out.println(cnt);
  }
}
