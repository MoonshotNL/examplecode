//
//  shuffle.c
//  
//
//  Created by W.A. Miltenburg on 13-05-13.
//
//

#include <stdio.h>
#include <stdlib.h>


/* Create the arrays with the values given by user. */
void create_array(int creation[], int begin, int end)
{
    
    int i = 0;
    
    for (i = 0; i <= end; i++) {
        creation[i] = begin;
        printf ("Debug: %i\n", begin);
        begin++;
    }
    
}

void change_array(int change[], int roll, int last_array)
{
    
    change[roll] = change[last_array];
    change[last_array]=0;
    
    
}

int main()
{
    int first;
    int last;
    int roll;
    
    printf ("Please enter the first digit: ");
    scanf ( "%i", &first );
    
    printf ("Please enter the last digit: ");
    scanf ( "%i", &last );
    
    int interval = last - first;
    
    printf ("Debug, numbers chosen: %i, %i, %i\n", first, last, interval );
    
    int array[interval];
    create_array(array, first, interval);
    
    printf ("Debug array[0] %i\n", array[0]);
    
    int second_array[interval];
    int i = 0;
    
    for(i=0; i <= interval; i++)
    {
        printf ("Before shuffle. array[%i] %i\n", i, array[i]);
        printf ("Before shuffle. second_array[%i] %i\n", i, second_array[i]);
        printf ("Print interval %i\n Print i %i \n", interval, i);
    }
    
    for(i = 0; i <= interval; i++)
    {
        printf ("Please enter the digit you want to change: between 0 and %i: ", interval-i);
        scanf ( "%i", &roll );
        second_array[interval-i]=array[roll];
        change_array(array, roll, interval-i);
        printf ("Interval-i %i \n", interval-i);
    }
    
    for(i = 0; i <= interval; i++)
    {
        printf ("Shuffle completed. array[%i] %i\n", i, array[i]);
        printf ("Shuffle completed. second_array[%i] %i\n", i, second_array[i]);
        printf ("\n");
    }
    
    
    
    
}



