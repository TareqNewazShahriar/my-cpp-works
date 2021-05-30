#include<stdio.h>
#include<math.h>
void main()
{	long ul[2],m[2],ur[2], l[2],r[2], x,y;
float p,p1,p2; char q;
//freopen("input.txt","w",stdout);
	while(scanf("%ld%ld",&x,&y)!=EOF)
	{/*1w*/if(x==1&&y==1) break;

		p=(float(x)/float(y));/*100;*/ q=0;
		ul[0]=0; ul[1]=1;  m[0]=1; m[1]=1;  ur[0]=1; ur[1]=0;
		l[0]=m[0]+ul[0]; l[1]=m[1]+ul[1];
		r[0]=m[0]+ur[0]; r[1]=m[1]+ur[1];
		p1=(float(l[0])/float(l[1]));//*100;
		p2=(float(r[0])/float(r[1]));//*100;
		if(x==l[0]&&y==l[1]) { printf("L"); q=1; }
		else if(x==r[0]&&y==r[1]) { printf("R"); q=1; }
		else if(x<y) {	printf("L"); m[1]=2; ur[1]=1; q=2; }
		else { printf("R"); ul[0]=1; m[0]=2; q=3; }
		if(q!=1)
		{//1i
			if(q==2)
			{	do{//d
					l[0]=m[0]+ul[0];  l[1]=m[1]+ul[1];
					r[0]=m[0]+ur[0];  r[1]=m[1]+ur[1];
					p1=(float(l[0])/float(l[1]));//*100;
					p2=(float(r[0])/float(r[1]));//*100;
					if(x==l[0]&&y==l[1]) { printf("L"); q=1; }
					else if(x==r[0]&&y==r[1]){ printf("R"); q=1;}
					else if( (fabs(p-p1)) < (fabs(p-p2)) )
					{	printf("L");
						ur[0]=m[0];    ur[1]=m[1];
						m[0]=l[0];    m[1]=l[1];
					}//3ei
					else
					{	printf("R");
						ul[0]=m[0];   ul[1]=m[1];
						m[0]=r[0];    m[1]=r[1];
					}//3e
				}while(q!=1);
			}//2i
			else
			{	do{//d
					l[0]=m[0]+ul[0];  l[1]=m[1]+ul[1];
					r[0]=m[0]+ur[0];  r[1]=m[1]+ur[1];
					p1=(float(l[0])/float(l[1]));//*100;
					p2=(float(r[0])/float(r[1]));//*100;
					if(x==l[0]&&y==l[1]) { printf("L"); q=1; }
					else if(x==r[0]&&y==r[1]) {printf("R"); q=1;}
					else if( (fabs(p-p1)) < (fabs(p-p2)) )
					{	printf("L");
						ur[0]=m[0];    ur[1]=m[1];
						m[0]=l[0];    m[1]=l[1];
					}//4ei
					else
					{	printf("R");
						ul[0]=m[0]; ul[1]=m[1];
						m[0]=r[0]; m[1]=r[1];
					}//3e
				}while(q!=1);
			}//1e
		}/*1i*/printf("\n");
	}//1w
}//m