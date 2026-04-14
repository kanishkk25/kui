#include<stdio.h>
#include<termios.h>
#include<stdlib.h>
#include<unistd.h>
#include "kui_vt100.h"
void err_exit(const char *message)
{
    printf("%s\n",message);
    exit(0);
}

int main()
{
    char *menu[]={"One","Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten"};
    int size=10;
    int page_size=4;
    int start,end;
    int i;
    int row,column;
    int selected;
    struct termios new_t,old_t;
    char a,b,c;
    if(tcgetattr(STDIN_FILENO,&old_t)==-1)
    {
        err_exit("Unable to get information using tcgetattr\n");
    }
    new_t=old_t;
    new_t.c_lflag=new_t.c_lflag & ~(ECHO | ICANON);
    new_t.c_cc[VTIME]=0;
    new_t.c_cc[VMIN]=1;
    if(tcsetattr(STDIN_FILENO,0,&new_t)==-1)
    {
        err_exit("Unable to set information using tcsetattr\n");
    }
    start=0;
    selected=0;
    while(1)
    {
        kui_clear();
        kui_draw_box(4,6,9,14);
        row=5;
        column=8;
        end=start+page_size;
        if(end>size) end=size;
        kui_go_to_xy(row,column);
        for(i=start;i<end;i++)
        {
            kui_go_to_xy(row,column);
            row++;
            if(i==selected)
            {
                kui_set_background_color("white");
                printf("%s\n",menu[i]);
                kui_remove_background_color();
            }
            else
            {
                printf("%s\n",menu[i]);
            }
        }
        printf("\n");
        a=getchar();
        if(a==10)
        {
            printf("Selected : %s\n",menu[selected]);
            break;
        }
        if(a==27)
        {
            b=getchar();
            c=getchar();
            if(b==91 && c==66)
            {
                selected++;
                if(selected==size)
                {
                    start=0;
                    selected=0;
                }
                else if(selected >=start+page_size)
                {
                    start++;
                }
            }
            if(b==91 && c==65)
            {
                selected--;
                if(selected<0)
                {
                    selected=size-1;
                    start=size-page_size;
                    if(start<0) start=0;
                }
                else if(selected<start)
                {
                    start--;
                }
                
            }
        }
    }
    if(tcsetattr(STDIN_FILENO,0,&old_t)==-1)
    {
        err_exit("Unable to set information using tcsetattr\n");
    }
    return 0;
}
