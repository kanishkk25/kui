#include<stdio.h>
#include<termios.h>
#include<stdlib.h>
#include<unistd.h>
#include<kui_vt100.h>
int main()
{
    char *menu[]={"One","Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten","Eleven","Twelve"};
    
    int selected=kui_menu(menu,12,3,4,5,5,7);
    printf("\n");
    if(selected!=-1) printf("Selected option is : %s\n",menu[selected]);
    return 0;
}
