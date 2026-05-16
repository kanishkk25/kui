#include<stdio.h>
#include<kui_vt100.h>
int main()
{
    kui_set_foreground_color(KUI_COLOR_CYAN);
    printf("Kanishk Chouhan\n");
    kui_remove_foreground_color();
    return 0;
}
