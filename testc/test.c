//
//  test.c
//  
//
//  Created by W.A. Miltenburg on 07-05-13.
//
//

#include <stdio.h>

/* Dit is een test functie. */

int main()
{
    char test[50];
    
    printf( "I am alive! Beware.\n" );
    printf ( "Please enter something \n");
    scanf ( "%s", &test);
    printf ( "%s", test );
    printf ( "\n" );
    
    getchar();
    return 0;
}