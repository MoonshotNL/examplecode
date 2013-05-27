//
//  example.c
//  
//
//  Created by W.A. Miltenburg on 07-05-13.
//
//

#include <stdio.h>

int main()
{
    int this_is_a_number;
    int x;
    
    printf( "Please enter a number: " );
    scanf( "%d", &this_is_a_number );
    printf( "You entered %d \n", this_is_a_number );
    
    if ( this_is_a_number < 10 )
    {
        printf ( " Number is less than 10 \n" );
    }
    else if ( this_is_a_number < 100 )
    {
        printf ( " Number is less than 100 \n");
    }
    else
    {
        printf ( " Number is bigger than 100 \n");
    }
    
    
    if ( this_is_a_number < 1000 && this_is_a_number > 100 )
    {
        printf ( " Less than 1000 and bigger than 100 \n");
    }
    
    printf ( "\n Printing loop 1 \n" );
    
    for (x = 0; x < 100; x++ )
    {
        printf ( "%d, ", x);
    }
    if ( x <= 100 )
    {
        printf ( "%d \n", x);
    }
    
    x = 0;
    
    printf ( "\n Printing loop 2 \n" );
    
    while ( x < 10 )
    {
        printf ( "%d, ", x);
        x++;
    }
    if ( x <= 10 )
    {
        printf ( "%d \n", x);
    }
    
    x = 0;
    
    printf ( "\n Printing loop 3 \n");
    
    do {
        printf ( "%d, ", x);
        x++;
    } while (x < 10);
    if ( x <= 10 )
    {
        printf ( "%d \n", x);
    }
    
    
    printf ( "End of program \n");
    getchar();
    return 0;
}