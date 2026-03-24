#include<stdio.h>
#include<termios.h>
#include<stdlib.h>
#include<unistd.h>
#include<kui_vt100.h>
void err_exit(const char *message)
{
    printf("%s\n",message);
    exit(0);
}

int main()
{
    char *gender[]={"Male","Female","Other"};
    int size=3;
    int start,end;
    int i;
    int selected;
    int focus;
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
    selected=-1;
    focus=0;
    while(1)
    {
        kui_go_to_xy(4,4);
        kui_clear(); 
        for(i=0;i<size;i++)
        {
            if(i==focus)
            {
                kui_set_background_color("white");
                printf("%s ",gender[i]);
                if(i==selected) printf("(*)");
                else printf("( )");
                kui_remove_background_color();
                printf("   ");
            }
            else
            {
                printf("%s ",gender[i]);
                if(i==selected) printf("(*)");
                else printf("( )");
                printf("   ");
            }
        }
        printf("\n");
        a=getchar();
        if(a==10)
        {
            if(selected==-1) printf("Gender : Not selected\n");
            else printf("Gender : %s\n",gender[selected]);
            break;
        }
        if(a==32)
        {
            if(selected!=focus) selected=focus;
            else if(selected==focus) selected=-1;
        }
        if(a==27)
        {
            b=getchar();
            c=getchar();
            if(b==91 && c==67)
            {
                focus++;
                if(focus==size)
                {
                    focus=0;
                }
            }
            if(b==91 && c==68)
            {
                focus--;
                if(focus<0)
                {
                    focus=size-1;
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
