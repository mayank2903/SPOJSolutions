import java.io.*;
import java.math.BigInteger;
import java.util.Scanner;
class Main
{
    public static void main(String [] args)throws IOException
    {
        int i;
        BigInteger total, diff, half, rem, two=new BigInteger("2");
        
        Scanner in = new Scanner(System.in);
        
        for(i=0;i<10;i++)
        {
            total=new BigInteger(in.next());
            diff=new BigInteger(in.next()).divide(new BigInteger("2"));
            rem=new BigInteger(total.mod(two).toString());
            
            half=total.divide(new BigInteger("2"));
            System.out.println(half.add(diff).add(rem));
            System.out.println(half.subtract(diff));
            
        }
    }
}
