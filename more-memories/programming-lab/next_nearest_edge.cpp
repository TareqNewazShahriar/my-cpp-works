/******Finding the next nearest edge from the graph********/
int next_nearest_edge(int j,int n,int cost[R][R],int adjacent[R])
{
	int i,t,kost=INF;
	t=j;
	for(i=1;i<=n;i++)
		if(adjacent[i]!=0 && cost[t][i]!=INF && cost[t][i]<kost)
		{	
			kost=cost[j][i];
			j=i;
		}
	return j;
}