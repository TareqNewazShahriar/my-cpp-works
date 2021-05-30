#include<stdio.h>
#include<math.h>
#define SIZE 105
#define CON 5000000000
#define ERR 0.0001
/****************************Global Variables***************************/
int rib,nail;
double dist;
class Type
	{
	public:
	double x,y;
	} xy[SIZE];
/*************************User Defined Functions************************ /
bool compare( const Type &a, const Type &b )
{
	if(a.y==b.y) 
	{
		if(a.x<b.x) return true;
		return false;
	}
	if(a.y<b.y) return true;
	return false;
}
/*--------------------------------------------------------------------*/
int distance(double x,double y,int k)
	{
	int i,index;
	double u,v, d,max=CON;
	for(i=0;i<nail;i++)
		{
		if( fabs(xy[i].x-CON)>ERR && i!=k )
			{
			u=xy[i].x-x;
			v=xy[i].y-y;
			d=sqrt( (u*u) + (v*v) );
			//d=(u*u) + (v*v);  // is not applicable. Test by 1st Sample I/O
			if(d<max) { max=d; index=i; }
			}
		}
	dist+=max;
	xy[k].x=CON;
	xy[k].y=CON;	
	
	return index;
	}
/*****************************main Function*****************************/
void main()
	{
	//freopen("C.txt","r",stdin);
	int cs,i,j,m;
	double u,v;
	scanf("%d",&cs);
	for(;cs;cs--)
		{
		scanf("%d%d",&rib,&nail);
		
		for(i=0;i<nail;i++)	scanf("%lf%lf",&xy[i].x,&xy[i].y);
		
		dist=0; u=xy[0].x; v=xy[0].y;
		
		m=nail-1;
		for(i=j=0;i<m;i++)
			{
			j=distance(xy[j].x, xy[j].y, j);
			}
		u=xy[j].x-u;
		v=xy[j].y-v;
		dist+=sqrt( (u*u) + (v*v) );
		//dist=(u*u) + (v*v);  // is not applicable. Test by 1st Sample I/O
		//dist=sqrt(dist);
		if(dist<rib) dist=(double)rib;
		printf("%.4lf\n",dist);

		//sort(xy,xy+i,compare);
		}
	}