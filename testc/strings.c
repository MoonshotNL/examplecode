//
//  strings.c
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
    //A nice long string
    char string[10];
    
    
    printf ( "String is stored size-1, because a \\0 character needs to be placed at the end \n" );
    
    printf ( "Please enter a long string: ");
    
    //notice stdin being passed in
    fgets (string, 10, stdin );
    int i = 0;
    
    for ( i = 0; i < 10 ; i++ )
    {
        if ( string[i] == '\n' )
        {
            
            
            printf ( "\\n detected, now changing it to the end character" );
            
            string[i] = '\0';
            break;
        }
    }
    
    
    
    
    
    printf ( "\n %s \n", string );
    
    getchar();
}