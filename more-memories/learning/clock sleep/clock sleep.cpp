/* CLOCK.C: This example prompts for how long
 * the program is to run and then continuously
 * displays the elapsed time for that period.
 */
#include <stdio.h>
#include <time.h>

void sleep( clock_t wait );

void main( void )
{
	clock_t start, finish;
	start = clock();
   __int64    i = 60000000;   
   double  duration;

   duration=CLOCKS_PER_SEC ;

   /* Delay for a specified time. */
   printf( "Delay for three seconds\n" );
   sleep( 3 * CLOCKS_PER_SEC );
   printf( "Done!\n" );

   /* Measure the duration of an event. */
   printf( "Time to do %I64d empty loops is ", i );
   start = clock();
//   while( i-- );
   finish = clock();
   duration = (double)(finish - start) / CLOCKS_PER_SEC;
   printf( "%.1f seconds\n", duration );
}

/* Pauses for a specified number of milliseconds. */
void sleep( clock_t wait )
{
   clock_t goal;
   goal = wait + clock();
   while( goal > clock() )
      ;
}		