import java.io.*;
import java.lang.String;
import java.math.BigInteger;
import java.util.Scanner;
import java.util.StringTokenizer;
class Main
{
    public static void main(String [] args)throws IOException
    {
    	BigInteger n,two=new BigInteger("2"),one=BigInteger.ONE;
    	
    	Scanner in=new Scanner(System.in);
    	
    	while(in.hasNextBigInteger())
    	{
    		n=in.nextBigInteger();
    		if(n.equals(one))
    		System.out.println("1");
    		
    		else
    		System.out.println(n.subtract(one).multiply(two));
    	}
    }
}
