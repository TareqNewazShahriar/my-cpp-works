#include<stdio.h>
#include<math.h>
void main()
{//m
	int ul[2],m[2],ur[2],l[2],r[2],i,x,y;
	float p,p1,p2;
	char rr[200],q;
//freopen("input.txt","r",stdin);
	while(scanf("%d%d",&x,&y)!=EOF)
	{//1w
		if(x!=1&&y!=1)
		{//0i
			for(i=0;i<100;i++)	rr[i]='\0';
			i=0;	q='n';
			p=(float (x)/float (y))*100;
			ul[0]=0; ul[1]=1; m[0]=1; m[1]=1; ur[0]=1; ur[1]=0;
			l[0]=m[0]+ul[0];  l[1]=m[1]+ul[1];
			r[0]=m[0]+ur[0];  r[1]=m[1]+ur[1];
			p1=(float(l[0])/float(l[1]))*100;
			p2=(float(r[0])/float(r[1]))*100;
			if(x==l[0]&&y==l[1])  {  rr[i++]='L';   q='y';   }
			else if(x==r[0]&&y==r[1])    {    rr[i++]='R';  q='y';  }
			else if( (fabs(p-p1)) < (fabs(p-p2)) )
			{	rr[i++]='L';	m[1]=2;   ur[1]=1;    }//2ei
			else  {   rr[i++]='R';   ul[0]=1;   m[0]=2;    }//1e
			if(q=='n')
			{//1i
				if(rr[0]=='L')
				{//2i
					do
					{//d
						l[0]=m[0]+ul[0];  l[1]=m[1]+ul[1];
						r[0]=m[0]+ur[0];  r[1]=m[1]+ur[1];
						p1=(float(l[0])/float(l[1]))*100;
						p2=(float(r[0])/float(r[1]))*100;
						if(x==l[0]&&y==l[1]) {  rr[i++]='L'; q='y';   }
						else if(x==r[0]&&y==r[1]) { rr[i++]='R'; q='y';}
						else if( (fabs(p-p1)) < (fabs(p-p2)) )
						{	rr[i++]='L';
							ur[0]=m[0];    ur[1]=m[1];
							m[0]=l[0];    m[1]=l[1];
						}//3ei
						else
						{	rr[i++]='R';
							ul[0]=m[0];   ul[1]=m[1];
							m[0]=r[0];    m[1]=r[1];
						}//3e
					}while(q=='n');
				}//2i
				else
				{//1e
					do
					{//d
						l[0]=m[0]+ul[0];  l[1]=m[1]+ul[1];
						r[0]=m[0]+ur[0];  r[1]=m[1]+ur[1];
						p1=(float(l[0])/float(l[1]))*100;
						p2=(float(r[0])/float(r[1]))*100;
						if(x==l[0]&&y==l[1]) {  rr[i++]='L'; q='y'; }
						else if(x==r[0]&&y==r[1]) { rr[i++]='R'; q='y';}
						else if( (fabs(p-p1)) < (fabs(p-p2)) )
						{	rr[i++]='L';
							ur[0]=m[0];    ur[1]=m[1];
							m[0]=l[0];    m[1]=l[1];
						}//4ei
						else
						{	rr[i++]='R';
							ul[0]=m[0];    ul[1]=m[1];
							m[0]=r[0];    m[1]=r[1];
						}//3e
					}while(q=='n');
				}//1e
			}//1i
			rr[i]='\0';
			printf("%s\n",rr);
		}//0i
	}//1w
}//m