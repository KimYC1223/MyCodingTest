import java.math.BigInteger;
import java.util.Scanner;
public class Main {
    public static void main(String[] args)
    { 
        Scanner sc = new Scanner(System.in); 
        int num = sc.nextInt(); 
        for (int i = 0; i < num; i++) { 
            int r = sc.nextInt(); 
            int n = sc.nextInt(); 
            System.out.println(combination(r,n)); 
        } 
    } 
    
    public static BigInteger combination(int r, int n) { 
        BigInteger sum = new BigInteger("1");
        int temp = r; 
        
        while(r > 0) {
            
            sum = sum.multiply(BigInteger.valueOf(n)); 
            --r; --n; 
        
        } 
        
        while(temp > 0) { 
            
            sum = sum.divide(BigInteger.valueOf(temp)); 
            --temp; 
        } 
        
        return sum; 
    } 
}