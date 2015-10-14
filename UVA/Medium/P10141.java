import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

/**
 * 
 * @author Sanchit M. Bhatnagar
 * @see http://uhunt.felix-halim.net/id/74004
 * 
 */
public class P10141 {

  public static void main(String[] args) throws NumberFormatException, IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    PrintWriter out = new PrintWriter(System.out);
    StringTokenizer st = null;

    boolean first = true;
    int test = 1;
    String line = null;
    while ((line = br.readLine()) != null) {
      st = new StringTokenizer(line);
      int N = Integer.parseInt(st.nextToken());
      int P = Integer.parseInt(st.nextToken());
      if (N == 0 && P == 0)
        break;
      if (!first)
        out.println();
      ArrayList<String> requirements = new ArrayList<String>();
      for (int i = 0; i < N; i++) {
        requirements.add(br.readLine());
      }

      PriorityQueue<Offer> heap = new PriorityQueue<Offer>(P, new Comparator<Offer>() {
        @Override
        public int compare(Offer arg0, Offer arg1) {
          if (arg0.compliance == arg1.compliance) {
            if (arg0.price == arg1.price) {
              return Integer.compare(arg0.idx, arg1.idx);
            } else {
              return Double.compare(arg0.price, arg1.price);
            }
          } else {
            return Double.compare(arg1.compliance, arg0.compliance);
          }
        }
      });

      for (int i = 0; i < P; i++) {
        String name = br.readLine();
        st = new StringTokenizer(br.readLine());
        double price = Double.parseDouble(st.nextToken());
        int offer = Integer.parseInt(st.nextToken());
        int count = 0;
        for (int j = 0; j < offer; j++) {
          br.readLine();
          count++;
        }
        heap.add(new Offer(name, price, count, i));
      }
      out.println("RFP #" + test);
      out.println(heap.poll().name);
      test++;
      first = false;
    }

    out.close();
    br.close();
  }

  private static class Offer {
    int idx;
    String name;
    double price;
    double compliance;

    public Offer(String name, double price, double compliance, int idx) {
      this.name = name;
      this.price = price;
      this.compliance = compliance;
      this.idx = idx;
    }
  }

}