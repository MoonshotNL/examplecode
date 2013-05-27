//
//  array.c
//
//
//  Created by W.A. Miltenburg on 08-05-13.
//
//

#include <stdio.h>
#include <stdlib.h>


/* Main function */

int main()
{
    
    int examplearray[100];
    char astring[10];
    int i = 0, x=0;
    char alfabet[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    
    printf ( "This program checks if some letters match the alphabet \n");
    
    printf ( "Please enter a word with the maximum length of 10: ");
    scanf ( "%s", astring );
    
    
    //printf ( "%d", scanf.length );
    
    for (i=0; i < 10; i++)
    {
        for (x=0; x<26; x++ )
        {
            if ( astring[i] == alfabet[x] )
            {
                printf  ( "You have entered an %c on position %d \n", alfabet[x], i+1 );
            }
        }
        
    }
    
    
    
    
    getchar();
    
}