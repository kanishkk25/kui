/**
 * @example kui_test9.c
 *
 * Example of using \ref kui_draw_double_horizontal_line function
 */

#include<kui_vt100.h>
#include<stdio.h>
int main()
{
    kui_clear();
    kui_draw_double_horizontal_line(6,4,14);
    printf("This is printing after the double horizontal line\n");
    return 0;
}
