#include<stdio.h>
void main()
{// m
	int i, j, mtx, s, sr[99], sc[99], row, col;
	char q, m;
//freopen("input.txt","r",stdin);
	while(scanf("%d",&mtx)!=EOF)
	{	if(mtx==0)
			break;
		m=0;
		for(j=0;j<mtx;j++) sc[j]=0;

		for(i=0;i<mtx;i++)
		{//1f
			sr[i]=0;
			for(j=0;j<mtx;j++)
			{//2f
				scanf("%d",&s);
				if(m<2)
				{//1i  fd
					sr[i]=sr[i] + s;
					sc[j]=sc[j] + s;
				}//1i
			}//2f

			if( (m<2) && (sr[i]%2)!=0)
			{//2i
				row=i+1;
				m++;
				if(m==2)
				{//0i
					printf("Corrupt\n");
				}//0i
			}//2i

		}//1f
		if(m<2)
		{//3i
			m=0;
			for(i=0;i<mtx;i++)
			{//3f
				if( (sc[i]%2)!=0)
				{//2i
					col=i+1;
					m++;
					if(m==2)
					{//0i
						printf("Corrupt\n");
						break;
					}//0i
				}//2i
			}//3f
		}//3i
		if (m==1)
			printf("Change bit (%d,%d)\n",row,col);
		else if(m==0)
			printf("OK\n");
	}//w
}// m