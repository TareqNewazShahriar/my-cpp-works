/*--DP Longest Common Subsequence(sequence1_index, sequence2_index)--*/
int dp_lcs(int i,int j) /* s1 s2 len1 len2 and memo must be global */
{
   int u,v;
   
   if(i==len1||j==len2) return 0;
   if(memo[i][j]!=-1) return memo[i][j];
   if(s1[i]==s2[j])
   {
      memo[i][j]=dp_lcs(i+1,j+1)+1;
      return memo[i][j];
   }
   
   u=dp_lcs(i,j+1);
   v=dp_lcs(i+1,j);

   if(u>v)
   {   
      memo[i][j]=u;
      return u;
   }

   memo[i][j]=v;
   return v;
}
/*--------------DP Longest Increasing Subsequence--------------*/
/*--(data_array, LIS_freq_array, element, LIS_starting_index)--*/
int dp_lis(int n,int &index) //data freq assumed as global
{
   int i,j,x, maxlen=0;
   
   for(i=n-1;i>-1;i--)
   {
      x=data[i];
      for(j=i+1;j<n;j++)
      {
         if(x<data[j]&&freq[i]<freq[j])//to take last equal LIS "freq[i]<=freq[j]+1"
            freq[i]=freq[j]+1;         
      }
      if(freq[i]>=maxlen)
      {
         maxlen=freq[i]; index=i;
         //m=n-maxlen;
   }   }
   return maxlen;
}   
/*--Just display the L.I.Subsequence(sequence_length, starting_index)--*/
void display(int k,int i)  // data freq must be global
{
   int x;
   printf("L.I.S Length: %d\n%d\n",k+1,data[i]);
   k--;
   x=data[i];
   for(i++;k>=0;i++)
   {
      if(x<data[i]&&freq[i]==k)
      {
         printf("%d\n",data[i]);
         x=data[i];
         k--;
      }
   }
}   
/*---------------------------------------------------------*/
void show_lcs(int lcs_len)
   {
   int i=0,j=0;      // w1[] is global STL string
   while(disp[i][j]!=1)
      {
      if(disp[i][j]==2) j++;
      else  i++;
      }
   if(lcs_len) 
      {
      printf("%s",w1[i].c_str());
      i++; j++; lcs_len--;
      }
   while(lcs_len)
      {
      if(disp[i][j]==1) 
         {
         printf(" %s",w1[i].c_str()); /* cout<<w1[i]<<" "; //*/
         i++, j++; lcs_len--;
         }
      else if(disp[i][j]==2) j++;
      else  i++;
      }
   printf("\n");
   }
