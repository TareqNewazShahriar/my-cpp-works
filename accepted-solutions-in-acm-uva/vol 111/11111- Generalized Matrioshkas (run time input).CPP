//17 0:00.244 460  Tariq Shahriar [CS@DCC] C++ 2006/10/11-06:25:51.654 5027741   (H0)  
#include<stdio.h>
#include<stack>
#include<string.h>
#define SIZE 10000

using namespace std;
typedef stack<int> STK;

void main()
	{	
	//freopen("b.txt","r",stdin);
	//freopen("b_out.txt","w",stdout);

	int x,v;
	bool que,q,sign;
	char line[SIZE],t=1;

	while(scanf("%[ \t\n]",line)!=EOF) // entire program
		{
		q=0; que=1;
		STK mat,s;  //for(;mat.empty()==0;mat.pop());
		mat.push(10000001); s.push(0);
		t=sign=0;
		while(t!=10)
			{
			t=getchar();
			if(t>44) // 45 = '-'
				{
				if(t=='-') { sign=1; scanf("%d",&x); }
				else{ 
					for(x=0;t>44;t=getchar()) x=(x*10)+(t-48);
					}
				if(sign)	// push
					{
					mat.push(x);
					v=s.top(); s.pop();
					s.push(v+x); s.push(0); //*debug*/ int w=v+x;
					sign=0;
					}
				else		// pop
					{					//* debug*/ int w=mat.top();
					if(mat.top()==x) 
						{					//* debug*/ int w=mat.top(); int z=s.top();
						if(mat.top()>s.top()) 
							{
							mat.pop(); s.pop();
							}
						else { que=0; break; }
						}
					else { que=0; break; }
					}// else
				}// if
			}//while(t)
		if(que==0)
			{
			puts(":-( Try again.");
			if(t!='\n')
				do
				{	fgets(line,SIZE,stdin);
				}while(line[strlen(line)-1]!='\n');
			}
		else //if(t=='\n')
			{
			if(mat.size()==1) puts(":-) Matrioshka!");
			else  puts(":-( Try again.");
			}
		scanf("%[ \t\n]",line);
		}//while( program )
	}