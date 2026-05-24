/**
 * @example kui_test4.c
 *
 * Example of using \ref kui_say function
 */

#include<kui_vt100.h>
#include<stdio.h>
int main()
{
    printf("Printing a NULL terminated string on a specific position of the screen\n");
    kui_say(8,20,"This is printed from 8th and 10th column of the screen");
    return 0;
}
