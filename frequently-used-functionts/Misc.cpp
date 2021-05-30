/*-----------------------------------------------------------------------*/
void sleep( clock_t wait )
{
   clock_t goal;
   goal = wait + clock();
   while( goal > clock() ) ;
}
/*-----------------------------swap(*num1,*num2)---------------------------*/
void swap(int a,int b)
{ a^=b; b^=a; a^=b; }
/*--Converting int to string and return the lenth without adding_48--*/
/*----------(unsigned  number,char *string)------------*/
int num_alpha_48(long n,char *str)
{   
   int i;
   for(i=0;n>0;i++)
   {
      *(str+i)=n%10; n/=10;
   }
   *(str+i)=0;
   return i;
}
/*----Check whether this result is unique or not-----*/
/*-(data_2D_array, this_row's_element, previuos_rows_elements_array, total_row)-*/
void display(int output[],int ele,int p[],int m)
{
   int u,v;
   for(u=0,v=0;u<m;u++,v=0)
      {
      if(output[u][0]==output[m][0]&&ele==p[u])
         for(v=1;output[m][v]==output[u][v]&&v<p[u];v++);
      if(v==p[u]) break;
      }
   if(u==m)
      {   
      printf("%d",output[m][0]);
      for(u=1;u<ele;printf("+%d",output[m][u]),u++);
      putchar(10);  p[m++]=ele;
      }
}   
/*------Load (2^n)-1 in a global array (dest_array)--------*/
void power_of_two(long power[])
{
   unsigned long pow=1;
   for(int i=0;i<31;i++)
   {
      power[i]=(pow*=2)-1;
   }
}   
/*--String to Floating value with decimal point(str, des_float)--*/
void str_float(char str[],float &f,char str2[],float &f2)
{   
   int i=0;  
   long k;
   
   if(*str==45) i=1;
   for(f=0;str[i]&&str[i]!=46;i++)
      f=f*10+str[i]-48;
   if(str2[i])
      for(k=10,i++;str[i];i++,k*=10)
      {   f+=(float)(str[i]-48)/k;   }
   if(*str==45) f*=-1;
}
