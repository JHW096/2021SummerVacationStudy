import java.util.StringTokenizer;
public class test {
   public static void main (String args[]) {
      int sum=0;
      String cal = "2.0*3.0-((4.0+5.0)*2.0)-4.0)=";
      StringTokenizer str = new StringTokenizer(cal,"+-*/()=");
      String token;
      while(str.hasMoreTokens()) {
         token = str.nextToken();
         sum += (int)Double.parseDouble(token);
      }
      System.out.println(sum);
   }
}