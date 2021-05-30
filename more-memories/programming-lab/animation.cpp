#include<stdio.h>

#include<conio.h>

#include<string_animation.h>     //  Line#3

 

void main()

{

     int x;

     char sentence[500], q=1;

     char option[5][25]={"marging_string",

                          "spreding_string",

                          "cyclic_string",

                          "All"};

     while(q)

     {

           printf("\n\nType anything :");

           gets(sentence);

           

           printf("\n\n");

           x=menu( 4, option, 25, 2 );

           printf("\n\n");

           

           if(x==0) marging_string( sentence, 40, 20 );

           else if(x==1) spreding_string( sentence, 40, 20 );

           else if(x==2) cyclic_string( sentence, 50, 20 );

           else

           {     marging_string( sentence, 40, 20 );

                 spreding_string( sentence, 40, 20 );

                 cyclic_string( sentence, 50, 20 );

           }

           printf("\n\nContinue? [Y/N] ");

           do

           {     q=getch();

           }while(q!='Y'&& q!='y'&& q!='N'&& q!='n');

           

            if(q=='Y'||q=='y')

                 q=1;

           else 

                 q=0;

     }

}

