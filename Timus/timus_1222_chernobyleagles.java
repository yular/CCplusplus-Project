/*
*
* Tag: Math
* Time: O(n)
* Space: O(1)
*/
import java.math.BigInteger;  
import java.util.Scanner;  

public class Main {

	final static BigInteger Four = new BigInteger("4");
	final static BigInteger Three = new BigInteger("3");
	final static BigInteger Two = new BigInteger("2");
	
	public static void main(String[] args){
		Scanner scanf = new Scanner(System.in);    
        int n;
        n = scanf.nextInt();
        
        BigInteger ans = new BigInteger("1");
        
        while(n > 4){
        	ans = ans.multiply(Three);
        	n -= 3;
        }
        if(n == 4)
        	ans = ans.multiply(Four);
        else if(n == 3)
        	ans = ans.multiply(Three);
        else if(n == 2)
        	ans = ans.multiply(Two);
        
        System.out.println(ans.toString());
        
	}
}
