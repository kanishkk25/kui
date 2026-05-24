/**
 * @example kui_test3.c
 *
 * Example of using \ref kui_go_to_xy function
 */

#include<kui_vt100.h>
#include<stdio.h>
int main()
{
    kui_go_to_xy(7,13);
    printf("Position of the cursor is changed using kui_go_to_xy\n");
    return 0;
}
