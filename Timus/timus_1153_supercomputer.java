/*
*
* Tag: Binary Search
* Time: O(lgn)
* Space: O(1)
*/
package timus;

import java.math.BigInteger;  
import java.util.Scanner;  

public class Main {

	private static BigInteger negOne = new BigInteger("-1");
	private static BigInteger one = new BigInteger("1");
	private static BigInteger two = new BigInteger("2");
	private static BigInteger four = new BigInteger("4");
	private static BigInteger eight = new BigInteger("8");
	private static BigInteger ten = new BigInteger("10");
	
	public static void main(String[] args){
		Scanner scanf = new Scanner(System.in);    
        String n = scanf.next();
        
        BigInteger v = new BigInteger(n), u = BigInteger.ONE;
        BigInteger ans = v.multiply(eight).add(one);
        BigInteger l = BigInteger.ONE, r = ans, mid = new BigInteger(n);
        while(l.compareTo(r) <= 0){
        	mid = l.add(r);
        	mid = mid.divide(two);
        	u = mid.pow(2);
        	int cmp = u.compareTo(ans); 
        	if (cmp == 0)
        		break;
        	else if(cmp < 0)
        		l = mid.add(one);
        	else
        		r = mid.subtract(one);
        }
        ans = mid.subtract(one);
        ans = ans.divide(two);
        
        System.out.println(ans.toString());
        
	}
}
