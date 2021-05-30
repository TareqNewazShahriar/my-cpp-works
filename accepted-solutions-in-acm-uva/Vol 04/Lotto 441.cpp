#include<stdio.h>
#include<time.h>

#define T 13
void main()
{
//char t1[10],t2[10]; _strtime(t1);

int a,b,c,d,e,f, t,u,v,w,x,y, num, n[T];   char q=0;
//freopen("in2.txt","r",stdin);
while(scanf("%d",&num)!=EOF)
{	if(num==0) break;
	if(q) 	putchar(10); q=1;
	for(a=0;a<num;a++)	scanf("%d",&n[a]);
	a=0,b=1,c=2,d=3,e=4,f=5;
	t=num-6,u=t+1,v=u+1,w=v+1,x=w+1,y=x+1;
		while(a<=t)
		{
			while(b<=u)
			{
				while(c<=v)
				{
					while(d<=w)
					{
						while(e<=x)
						{
							while(f<=y)
							{
								printf("%d %d %d %d %d %d\n",n[a],n[b],n[c],n[d],n[e],n[f]);
								if(f<y) f++;
								else  break;
							}//wh f
							if(e<x) { e++; f=e+1;  }
							else break;
						}//wh e
						if(d<w) {  d++; e=d+1; f=e+1; }
						else break;
					}//wh d
					if(c<v) {  c++;  d=c+1;  e=d+1; f=e+1; }
					else break;
				}//wh c
				if(b<u) {  b++;  c=b+1;   d=c+1;  e=d+1; f=e+1; }
				else  break;
			}//wh b
			a++;  b=a+1; c=b+1;   d=c+1;  e=d+1; f=e+1;
		}//wh a
}
//_strtime(t2); printf("OS time: %s\n",t1); printf("OS time: %s\n",t2);	
}