//
//  strings_new.c
//  
//
//  Created by W.A. Miltenburg on 08-05-13.
//
//

#include <stdio.h>
#include <string.h>

void remove_new_line (char *str, int size)
{
    int i =0;
    
    for (i =0; i < size; i++)
    {
        if (str[i] == '\n')
        {
            str[i] = '\0';
            return;
        }
    }
}

int main()
{
    char name[50];
    char lastname[50];
    char fullname[100]; //Hold both name and lastname
    
    printf ("Please enter your name: ");
    fgets (name, 50, stdin);
    
    //remove new lines from char name
    remove_new_line(name, 50);
    
    if ( strcmp(name, "Alex") == 0)
    {
        printf ("\nYour name is Alex.");
    }
    else
    {
        printf ("\nYour name is not Alex");
    }
    
    //Length of name
    printf ("\nThe length of your name is %d characters", strlen(name));
    
    printf ("\nEnter your last name: ");
    fgets (lastname, 50, stdin);
    remove_new_line(lastname, 50);
    
    //now fill fullname
    strcat(fullname, name);
    strcat(fullname, " ");
    strcat(fullname, lastname);
    
    //print full name
    printf ("\nYour full name is: %s", fullname);
    
    getchar();
    
    return 0;
    
    
}