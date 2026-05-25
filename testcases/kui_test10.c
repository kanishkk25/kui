/**
 * @example kui_test10.c
 *
 * Example of using \ref kui_draw_double_vertical_line function
 */

#include<kui_vt100.h>
#include<stdio.h>
int main()
{
    kui_clear();
    kui_draw_double_vertical_line(6,4,14);
    printf("This is printing after the double vertical line\n");
    return 0;
}
