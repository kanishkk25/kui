/**
 * @example kui_test5.c
 *
 * Example of using \ref kui_say_char function
 */

#include<kui_vt100.h>
#include<stdio.h>
int main()
{
    printf("Printing characters on a specific position of the screen\n");
    
    kui_say_char(8,20,'K');

    kui_say_char(8,20,'K');
    
    kui_say_char(6,15,'N');
    
    kui_say_char(15,20,'Z');
    
    kui_say_char(13,13,'S');
    return 0;
}
