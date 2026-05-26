/**
 * @example kui_test12.c
 *
 * Example of using \ref kui_set_background_color function and kui_remove_background_color function
 */

#include<kui_vt100.h>
#include<stdio.h>
int main()
{
    kui_clear();
    kui_set_background_color(KUI_COLOR_RED);
    printf("Background of this text is in red color\n");
    kui_remove_background_color();
    printf("There is no background color set in this text\n");
    kui_set_background_color(KUI_COLOR_MAGENTA);
    printf("Background of this text is in magenta color\n");
    kui_remove_background_color();
    printf("There is no background color set in this text\n");

    kui_set_background_color(KUI_COLOR_WHITE);
    printf("Background of this text is in white color");
    kui_remove_background_color();
    return 0;
}
