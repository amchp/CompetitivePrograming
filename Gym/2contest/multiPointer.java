public class multiPointer {
    public static void main(String[] args){
        int[] s = {1, 2, 1, 3, 2};
        int d = 3;
        int m = 2;
        System.out.println(birthday(s, d, m));
    }

    public static int birthday(int[] s, int d, int m){
        int count = 0;
        int[] pointer = new int[m];
        for(int i = 0; i < pointer.length; i++){
            pointer[i] = i;
        }
        int p = m - 1;
        while(true){
            if(pointer[p] + (m - 1 - p) >= s.length - 1){
                if(checkSum(s, pointer) == d) count++;
                p -=2;
                if(p < 0) break;
            }
            while(pointer[p] < s.length){
                if(checkSum(s, pointer) == d) count++;
                pointer[p]++;
            }
            pointer[p-1]++;
            pointer[p] = pointer[p-1] + 1;
        }
        return count;
    }

    public static int checkSum(int[] s, int[] pointer){
        int sum = 0;
        for(int j = 0; j < pointer.length; j++){
            sum += s[pointer[j]];
        }
        return sum;
    }
}