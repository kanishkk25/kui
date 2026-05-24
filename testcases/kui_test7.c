/**
 * @example kui_test7.c
 *
 * Example of using \ref kui_draw_vertical_line function
 */

#include<kui_vt100.h>
#include<stdio.h>
int main()
{
    kui_clear();
    kui_draw_vertical_line(6,4,14);
    printf("This is printing after the vertical line\n");
    return 0;
}
