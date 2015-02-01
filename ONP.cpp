#include<stdio.h>
#include<stack>
#include<algorithm>
#include<ctype.h>
using namespace std;
int precedence(char op)
{
	//operators: +,-,/,*,^
	if(op=='^')return 5;
	if(op=='*' || op=='/')return 4;
	if(op=='+' || op=='-')return 3;
	return -1;
}
int main()
{
	char str[500];
	int i,prec,t;
	stack<char> s;
	scanf("%d",&t);
	while(t--){
	scanf("%s",str);
	i=0;
	while(str[i]!='\0')
	{
		//scanning the string..
		//if the character is a letter or number..
		if(isalnum(str[i]))
		{
			putchar(str[i]);
		}
		//if character is a bracket:
		else if(str[i]=='(')
				s.push('(');
		else if(str[i]==')')
		{
			while(s.top()!='(')
			{
				putchar(s.top());
				s.pop();
			}
			s.pop();///to pop the bracket out..
		}
		//if character is an operator:
		else
		{
			//remove all operands which have a greater precedence than str[i]:
			prec=precedence(str[i]);
			while(!s.empty() && precedence(s.top())>=prec)
			{
				putchar(s.top());
				s.pop();
			}
			s.push(str[i]);
		}
		i++;
	}
	while(!s.empty())
	{
		putchar(s.top());
		s.pop();
	}
	putchar('\n');
}
	return 0;
}
