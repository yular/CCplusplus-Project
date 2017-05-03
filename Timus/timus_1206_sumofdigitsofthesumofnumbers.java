/*
*
* Tag: Math
* Time: O(n)
* Space: O(1)
*/
import java.math.BigInteger;  
import java.util.Scanner;  

public class Main {

	public static void main(String[] args){
		Scanner scanf = new Scanner(System.in);    
        int n;
        n = scanf.nextInt();
        
        BigInteger ans = new BigInteger("36"), fact = new BigInteger("55");
        
        for(int i = 1; i < n; ++ i){
        	ans = ans.multiply(fact);
        }
        
        System.out.println(ans.toString());
        
	}
}
