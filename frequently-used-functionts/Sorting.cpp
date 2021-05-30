/*-------------------Selection sort(int_array,element)--------------------*/
void selection_sort(int data[], int n)
{   
   int i,j, m=n-1, low,indx,tmp;
   for(i=0;i<m;i++)
   {   
      low=data[i]; indx=i;
      for(j=i+1;j<n;j++)
      {
         if(data[j]<low) { low=(data[j]); indx=j; }
      }
      //data[i]^=data[index]; data[indx]^=data[i]; data[i]^=data[index];
      tmp=data[i]; data[i]=data[index]; data[index]=tmp;
   }// for loop
}// end
/*----------------------Bubble sort(int_array, elements)--------------------*/
void bubble_sort(int data[],int n)
{   
   int c=0,i,tmp; 
   bool q=1;
   for(n--;n&&q;n-=c)
   {   
      q=0;
      for(i=0;i<n;i++)
      {   
         if(data[i]>data[i+1])
         {
            tmp=data[i]; data[i]=data[i+1]; data[i+1]=tmp;
            //data[i]^=data[i+1]; data[i+1]^=data[i];   data[i]^=data[i+1];            
            c=n-i; q=1;
         }
      }
   }//Loop End
} // Function End
/*-[Old Fasion] Quick Sort(int_array,element)[send element number as "element-1"]-*/
void q_sort(int data[],int n)
{
   char q=0; int i,j,k=0,tmp; //pivot,left,right,array1 start...
   for(i=n-1,j=0;(i-j)>-1;)
   {   
      if(q==0)
      {   
         if(data[k]>data[i])
         {
            data[k]^=data[i]; data[i]^=data[k]; data[k]^=data[i];
            k=i; q=1;
         }
         i--;
      }
      else
      {   
         if(data[k]<data[j])
         {
            data[j]^=data[k]; data[k]^=(data[j]); data[j]^=data[k];
            k=j; q=0;
         }
         j++;
      }
   }
   if(k>1) q_sort(data,k);
   if(n-k>1) q_sort(data[k+1], n-k-1);
}