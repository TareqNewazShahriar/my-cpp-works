#include<stdio.h>
#include<stack>
#include<vector>
#include<string.h>
#define SIZE 1000000

using namespace std;
typedef stack<int> STK;
typedef vector<int> VECT;

void main()
	{	
	freopen("b.txt","r",stdin);
	int x,v;
	bool que,q,sign;
	char line[SIZE],*t=line;
		
	while(t) // entire program
		{
		q=0; que=1;
		while(t)// one test case
			{
			t=fgets(line, SIZE, stdin);
			if(t==0) { t=0; break; }
			
			STK mat,s;  //for(;mat.empty()==0;mat.pop());
			
			if(q)
				{
				for(;*t>44;t++) x=(x*10)+(*t-48);
				mat.push(x);  q=0;
				}
			sign=0;
			while(*t)
				{
				if(*t>44) // 45 = '-'
					{
					if(*t=='-') sign=1, t++;
					for(x=0;*t>44;t++) x=(x*10)+(*t-48);
					
					if(sign)	// push
						{
						mat.push(x); s.push(x);
						sign=0;
						}
					else		// pop
						{
						if(mat.size()&&mat.top()==x)
							{
							while(s.top()!=mat.top()) s.pop();
							mat.pop();
							v=0;
							if(mat.size())
								{
								while(s.top()!=mat.top())
									{ v+=s.top(); s.pop(); }
								if( mat.top()>v ) s.push(v);
								else { que=0; break; }
								}
							}
						else { que=0; break; }
						}// else
					}// if
				else t++;
				}//while(*t)
			if(*(t-1)>47)
				{
				for(;*t>47;t--);
				for(;*t>44;t++) x=(x*10)+(*t-48);
				que=1; q=1; continue;
				}
			
			if(que==0)
				{
				puts(":-( Try again.");
				while(t[strlen(t)-1]!='\n') t=fgets(line,SIZE,stdin); 
				}
			else if(*(t-1)=='\n')
				{
				if(mat.size()==0) puts(":-) Matrioshka!");
				else  puts(":-( Try again.");
				break;
				}
			}//while( case )
		}//while( program )
	}
