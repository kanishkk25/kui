/**
 * @example kui_test15.c
 *
 * Example for using \ref kui_menu function
 */

#include<kui_vt100.h>
#include<stdio.h>
int main()
{
    kui_clear();
    printf("This is a simple example of using a kui_menu function\n");

    char *menu[]={"One","Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten","Eleven","Twelve"};
    
    int selected=kui_menu(menu,12,3,4,5,5,7);
    printf("\n");
    if(selected!=-1) printf("Selected option is : %s\n",menu[selected]);
    return 0;
}
