/**
 * @example kui_test6.c
 *
 * Example of using \ref kui_draw_horizontal_line function
 */

#include<kui_vt100.h>
#include<stdio.h>
int main()
{
    kui_clear();
    kui_draw_horizontal_line(6,4,14);
    printf("This is printing after the horizontal line\n");
    return 0;
}
