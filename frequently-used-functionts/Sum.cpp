/*----------------sum all the value 0 to paramiter---------------------*/
long sum_all(int n)
{   
   long long x=0;
   for(;n>0;n--)  x+=n;
   return x;
}
/*------------sum all in all value 0 to paramiter---------------------*/
long sum_all_in_all(int n)
{   
   int i;  long x=0;
   for(;n>0;n--)  for(i=n;i>0;i--)   x+=i;
   return x;
}