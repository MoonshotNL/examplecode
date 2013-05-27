//
//  struct.c
//  
//
//  Created by W.A. Miltenburg on 08-05-13.
//
//

#include <stdio.h>
#include <stdlib.h>


/* Main function */

struct database_users{
    int id;
    int age;
};


int main()
{
    
    struct database_users user;
    user.id = 8;
    user.age = 18;
    
    printf ( "%d, %d \n", user.id, user.age );
    
    /* Pointers and structures */
    
    struct database_users structure;
    struct database_users *ptr;
    
    structure.id = 12;
    ptr = &structure;
    
    printf ( "Using a pointer: %d", ptr->id ); /* The -> acts somewhat like the * when
                                                does when it is used with pointers
                                                It says, get whatever is at that memory
                                                address Not "get what that memory address
                                                is"*/
    
    getchar();
    
    
}

