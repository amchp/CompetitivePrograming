import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
  

  class TestClass {
    public static void main(String args[]) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        ArrayList<Integer> outputs = new ArrayList<Integer>();
        String str;
        while((str = br.readLine()) != null) {
            int n = Integer.parseInt(str);
            int[] s = new int[n];
            String sLine = br.readLine();
            int k = 0;
            for(int j = 0; j < n; j++){
                s[j] = Integer.parseInt(sLine.substring(k, k+1));
                k += 2;
            }
            String dmLine = br.readLine();
            int d = Integer.parseInt(dmLine.substring(0, 1));
            int m = Integer.parseInt(dmLine.substring(2, 3));
            outputs.add(birthday(s, d, m));
        }
        for(Integer result: outputs){
              System.out.println(result);
        }
    }

    public static int birthday(int[] s, int d, int m){
        int count = 0;
        int sum = 0;
        for(int i = 0; i <= s.length - m; i++){
            sum = 0;
            for(int j = 0; j < m ; j++){
                sum += s[i+j];
            } 
            if(sum == d){
                count++;
            }           
        }
        return count;
    }
}