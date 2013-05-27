//
//  pointers.c
//  
//
//  Created by W.A. Miltenburg on 08-05-13.
//
//

#include <stdio.h>
#include <stdlib.h>

/* Main functie */

int main()
{
    int x; //A normal integer
    int *p; //A pointer to an integer ("*p" us ab ubteger, so p must be a pointer to an integer)
    
    p = &x;
    
    scanf ( "%d", &x );
    printf ( "*p %d \n", *p );
    
    int *ptr = mallox ( sizeof(*ptr) );
    
    free ( ptr ); //The free function returns memory to the opreating system
    
    
    
    
    getchar ();
    
}
