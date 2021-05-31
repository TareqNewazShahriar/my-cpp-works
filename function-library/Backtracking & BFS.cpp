/*--Find number of region from a surface(row, column)-Oil Deposite---*/
void breadth_of_pocket(char i,char j)
{   char mi=i-1,mj=j-1,pi=i+1, pj=j+1;

   if(field[mi][mj]==64)   { field[mi][mj]=0;   breadth_of_pocket(mi,mj); }
   if(field[mi][j]==64)   { field[mi][j]=0;   breadth_of_pocket(mi,j); }
   if(field[mi][pj]==64)   { field[mi][pj]=0;   breadth_of_pocket(mi,pj); }
   if(field[i][pj]==64)   { field[i][pj]=0;   breadth_of_pocket(i,pj); }
   if(field[pi][pj]==64)   { field[pi][pj]=0;   breadth_of_pocket(pi,pj); }
   if(field[pi][j]==64)   { field[pi][j]=0;   breadth_of_pocket(pi,j); }
   if(field[pi][mj]==64)   { field[pi][mj]=0;   breadth_of_pocket(pi,mj); }
   if(field[i][mj]==64)   { field[i][mj]=0;   breadth_of_pocket(i,mj); }
}      
/*--Find number of region from a surface(row, column)-Oil Deposite---*/
void pocket_breadth(char i,char j)
{
   if(field[i-1][j-1]==64)   { field[i-1][j-1]=0;   readth_of_pocket(i-1,j-1); }
   if(field[i-1][j]==64)   { field[i-1][j]=0;      readth_of_pocket(i-1,j); }
   if(field[i-1][j+1]==64)   { field[i-1][j+1]=0;   readth_of_pocket(i-1,j+1); }
   if(field[i][j+1]==64)   { field[i][j+1]=0;      readth_of_pocket(i,j+1); }
   if(field[i+1][j+1]==64)   { field[i+1][j+1]=0;   readth_of_pocket(i+1,j+1); }
   if(field[i+1][j]==64)   { field[i+1][j]=0;      readth_of_pocket(i+1,j); }
   if(field[i+1][j-1]==64)   { field[i+1][j-1]=0;   readth_of_pocket(i+1,j-1); }
   if(field[i][j-1]==64)   { field[i][j-1]=0;      readth_of_pocket(i,j-1); }
}      
/*--Find number of region from a surface(row, column)-Oil Deposite---*/
void bfs(char i,char j)
{
   char nr,nc,k;
   for(k=0;k<8;k++)
   {
      nr=i+dr[k]; nc=j+dc[k];
      if(field[nr][nc]==64) { field[nr][nc]=0;   BFS(nr,nc); }
   }

}
/*longest region that's numbers are in descending ordar(row,col,previous_grid's_number)*/
short BFS_longest_run(char r,char c,short val)
{   
   char i=0,nr,nc;
   short var=0;
   while(i<4)
   {   nr=r+dr[i]; nc=c+dc[i];
      if(board[nr][nc]<val)
      {   
         if(!visit[nr][nc])
         {   
            if( (visit[nr][nc]=BFS_longest_run(nr,nc,board[nr][nc]))>var)
               var=visit[nr][nc];
         }
         else if(visit[nr][nc]>var) var=visit[nr][nc];
      }
      i++;
   }
   return var+1;
}   
/*----Clear surrounding region of a 2D region(2D_array,tot_row,tot_col)----*/
void clear_surround(int visit[R][R],int row,int col)
   {
   for(r=1;r<row;r++)
      {
      for(c=1;c<col;c++)
         visit[r][c]=0;
      }
   if(row>col) c=row;
   while(c>-1)   { board[c][0]=board[0][c]=board[row][c]=board[c][col]=110; c--; }
   }
/*--Find the ring there sum of consecutive number is prime(previous_evaluated_number)--*/
void prime_ring(int m)
{   int i; n++;
   if(n==x)
   {   
      for(i=2;fill[i]&&i<=x;i++);
      if(fill[i]==0&&svprm[i+1]==0&&svprm[prime[x-1]+i]==0)
      {   
         prime[n]=i;
         printf("1");
         for(i=2;i<=x;printf(" %d",prime[i]),i++);
         putchar(10);
   }   }
   else
   {   i=m%2==0 ? 3 : 2 ;
      while(i<=x)
      {   
         if(fill[i]==0&&svprm[m+i]==0)
         {
            fill[i]=1; prime[n]=i;
            prime_ring(i);
            fill[i]=0;
         }
         i+=2;
      }
   }
   n--;
}
/*------It tells done by one and not done by zero()-------*/
void eight_queen_backtracking(char depth)
{   tot++;
   int row,col, hold=depth;
   if(c<=depth) col=depth+1;  else col=depth;
   for(row=1;row<9;row++)
   {   depth=hold;
      while(depth)
      {   if( (row-col==rows[depth]-column[depth])||(row==rows[depth])
               ||(row-rows[depth]==column[depth]-col) )
            break;
         depth--;
      }
      if(!depth)
      {   rows[hold+1]=sorted[col]=row; column[hold+1]=col;
         if(tot<8)
            eight_queen_backtracking(hold+1);
         else
         {   printf("%2d     ",++sn);
            for(k=1;k<9;printf(" %d",sorted[k]),k++);
            putchar(10);
      }   }
   }
   tot--;
}
/*--Evaluate given 5 number can create 23 or not(numbers_taken,current_total_value)--*/
bool _23_out_of_5(int n,int tot)
   {
   //if(tot==23) return 1;
   if(n==5)
      {
      if(tot==23) return 1;
      return 0;
      }
   for(int i=0;i<5;i++)
      {
      if(fill[i]) continue;
      fill[i]=1;
      if(_23_out_of_5(n+1,tot+num[i])) return 1;
      if(_23_out_of_5(n+1,tot-num[i])) return 1;
      if(_23_out_of_5(n+1,tot*num[i])) return 1;
      fill[i]=0;
      }
   return 0;
   }
