/*
*
* Tag: DP
* Time: O(n)
* Space: O(n)
*/
import java.math.BigInteger;  
import java.util.Scanner;  

public class Main {

	final static int M = 30010;
	public static void main(String[] args){
		Scanner scanf = new Scanner(System.in);    
        int n, k;
        n = scanf.nextInt();
        k = scanf.nextInt();
        
        BigInteger []dp = new BigInteger[M];
        
        if(k == 0){
        	System.out.println("1");
        }else{
        	int top = 3;
        	dp[0] = BigInteger.ONE;
        	dp[1] = BigInteger.ONE;
        	BigInteger ans = dp[0].add(dp[1]);
        	dp[2] = ans;
        	for(int i = 1; i < n; ++ i){
        		if(i < k){
        			ans = ans.add(ans);
        		}else{
        			ans = ans.add(ans);
        			ans = ans.subtract(dp[top - k - 2]);
        		}
        		dp[top ++] = ans;
        	}
        	ans = dp[top - 1];
        	System.out.println(ans.toString());
        }
        
	}
}
