/**
 * @example kui_test8.c
 *
 * Example of using \ref kui_draw_box function
 */

#include<kui_vt100.h>
#include<stdio.h>
int main()
{
    kui_clear();
    kui_draw_box(5,3,15,40);
    printf("Now we will write inside this box\n");
    kui_say(8,6,"I am inside the box");
    kui_say(17,0,"Now I am outside the box\n");
    return 0;
}
