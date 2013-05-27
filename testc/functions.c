//
//  functions.c
//  
//
//  Created by W.A. Miltenburg on 07-05-13.
//
//

#include <stdio.h>
#include <stdlib.h>

int multi(int x, int y)
{
    return x * y;
}

/* Main functie */


int main()
{
    int x, y;
    int multi_return;
    
    printf ( "Please enter your first number: ");
    scanf ( "%d", &x );
    printf ( "Please enter your second number: ");
    scanf ( "%d", &y );
    
    printf ( "The product of the two numbers is: ");
    printf ( "%d", multi(x, y));
    printf ( "\n" );
    
    multi_return = multi(x,y);
    
    switch ( multi_return )
    {
            
        case 80:
            printf ( "The answer is 80. " );
            break;
            
        case 90:
            printf ( "The answer is 90. " );
            break;
            
        default:
            printf ( "The answer is not 80 or 90. " );
            
    }
    
    
    
    getchar();
}

