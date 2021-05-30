/*----------------Multiply all the value 1 to parameter(num)---------------------*/
long long multi_all(int n)
{   
   long long x=1;
   if(n!=0)
   {   
      for(;n>0;n--)  x*=n;
      return x;
   }
   else return 0;
}
/*------------Multiply all in all value 1 to parameter(num)---------------------*/
long long multi_all_in_all(int n)
{   
   int  i;
   long double x=1;
   if(n!=0)
   {   
      for(;n>0;n--)
      {
         for(i=n;i>0;i--)
            x*=i;
      }
      return x;
   }
   else  return 0;
}
