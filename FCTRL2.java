import java.util.Scanner;
import java.math.BigInteger;
public class Main {
	public static void main(String[] args)throws java.lang.Exception
	{
		Scanner in=new Scanner(System.in);
		
		BigInteger facts[]=new BigInteger[100];int n,i,t;
		
		for(i=0;i<100;i++)
			facts[i]=BigInteger.ZERO;
		
		t=in.nextInt();
		
		for(i=0;i<t;i++)
		{
			n=in.nextInt();
			
			System.out.println(fact(n,facts));
			
		}
		in.close();
	}
	
	public static BigInteger fact(int n,BigInteger[] facts)
	{
		BigInteger temp;
		
		if(facts[n-1]!=BigInteger.ZERO)
			return facts[n-1];
		
		if(n==1)return BigInteger.ONE;
		
		else
			{
			temp=new BigInteger(Integer.toString(n));
				facts[n-1]=temp.multiply(fact(n-1,facts));
				return facts[n-1];
			}
	}
}
