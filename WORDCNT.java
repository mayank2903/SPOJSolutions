import java.lang.String;
import java.util.StringTokenizer;
import java.io.*;
public class Main {
	
	static final long serialVersionUID=1L;
	
	static BufferedReader stdin=new BufferedReader(new InputStreamReader(System.in));
	
	public static void main(String[] args)throws IOException
	{
		int t,curlen,maxcount,curcount,prevlen,i;
		String s;
		
		t=Integer.parseInt(stdin.readLine());
		
		for(i=0;i<t;i++)
		{
			s=stdin.readLine();
			
			StringTokenizer tokenizer = new StringTokenizer(s);
			
			maxcount=0;curcount=0;prevlen=0;
			while(tokenizer.hasMoreElements())
			{
				curlen=tokenizer.nextToken().length();
				
				if(curlen==prevlen)
					curcount++;
				
				else
					curcount=1;
				
				prevlen=curlen;
				
				if(curcount>maxcount)
					maxcount=curcount;
			}
			
			System.out.println(maxcount);
		}
		
	}
}
