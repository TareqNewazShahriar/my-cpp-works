/******************Decimal to Banary( des str, decimal num)*****************/
int dec_bin(char *bin,long dec)
{   
   int i, k=0;   
   *bin=48; *bin=0;
   for(i=0;dec;i++)
   {
      *(bin+i)=dec%2+48;
      dec/=2;   
      //if(*(bin+i)==1) k++; //How many one's;
   }
   *(bin+i)=0;
   return i;
}
/*-------Convert Binary to Decimal(binary_str, decimal_num_destination)---*/
void bin_decimal(char *bin,unsigned long &dec)
{   
   int i,len_val=strlen(bin)-1;
   for(i=0,dec=0;len_val>-1;len_val--,i++)
   {
      //for(j=i-1,res=2; j>0; res*=2,j--); //power; alternate of pow()
      dec+=(bin[len_val]-48)*pow(2,i);
   }
}
/*Convert the alpha chars to number ASCII equivalent (num_string) (e.g. A -> 58)*/
void conv_decimal_digit(char *s)
{
   int i;
   for(i=0;*(s+i);i++)
   {
      if(*(s+i)>64 && *(s+i)<71)
         *(s+i)-=7;
   }
}
/******Convert the digits in Alpha digit form. (e.g. 58 -> A)******/
void conv_alpha_digit(char *s)
{
   int i;
   for(i=0;*(s+i);i++)
   {
      if(*(s+i)>57)
         *(s+i)+=7;
}   }
/**Convert the val from "from" to "to". Size is the array size of 'load'***/
/**(res_str, base_from, base_to, inputted_string)**It can Handle 0-1,A-Z; 2-36 base**/
int base_conv(char *v,int from,int to,char *load)
{   
   int i,j,len_val=strlen(v),unit,power;
   char *s,val[Size];
   strcpy(val,v);

   if(from>10)            // Convert the alpha digits to
      for(s=val;*s;s++)   // decimal digit; e.g. A -> 58
         {
         if(*s>64)
            (*s)-=7;
         }
   for(len_val--,i=0,unit=0;len_val>-1;len_val--,i++) 
   {                              // convert 'val' to 10 base
      if(i==0) power=1;
      else for(j=i-1,power=from; j; power*=from,j--);
      
      unit+=(val[len_val]-48)*power;
   }
   i=j=Size-1;
   do            // convert unit to desired base
   {
      load[--i]=unit%to +48;
      unit/=to;
   }while(unit);
   load[j]=0;
   strcpy(load,load+i);

   if(to>10)      // Convert the digits in Alpha digit form
      for(s=load;*s;s++)
         {
            if(*s>57)
               (*s)+=7;
         }   
   return j-i;
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
/*---Skew Binary {base 3 & power is (2^n)-1, where n>=1}---*/
/*----------(inputted_str) Require- power_of_two()---------*/
long skew_binary_to_decimal(char *in)
{
   long out=0, i=strlen(in)-1, j=0;
   for(;i>-1;i--)
   {
      out+=(in[i]-48)*power[j++];
   }
   return out;
}