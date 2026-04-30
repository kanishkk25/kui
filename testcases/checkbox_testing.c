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
    char *hobbies[]={"Cricket","Badminton","Movies","Reading","Swimming","Cooking"};
    int size=6;
    int selected[6]={-1,-1,-1,-1,-1,-1};
    int row,column;
    int i;
    int focus;
    struct termios new_t,old_t;
    char a,b,c;
    int page_size=4;
    int start,end;
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
    focus=0;
    while(1)
    {
        kui_clear();
        row=5;
        column=6;
        kui_draw_box(4,4,11,20);
        
        end=start+page_size;
        if(end>size) end=size;

        for(i=start;i<end;i++)
        {
            kui_go_to_xy(row,column);
            row++;
            if(i==focus)
            {
                kui_set_background_color("white");
                printf("%s ",hobbies[i]);
                if(selected[i]==-1) printf("[ ]");
                else printf("[X]");
                kui_remove_background_color();
                printf("\n");
            }
            else
            {
                printf("%s ",hobbies[i]);
                if(selected[i]==-1) printf("[ ]");
                else printf("[X]");
                printf("\n");
            }
        }
        printf("\n");
        a=getchar();
        if(a==10)
        {
            printf("Selected options are : ");
            for(int i=0;i<size;i++)
            {
                if(selected[i]!=-1) printf("%s ",hobbies[i]);
            }
            printf("\n");
            break;
        }
        if(a==32)
        {
            if(selected[focus]==-1) selected[focus]=1;
            else if(selected[i]!=-1) selected[focus]=-1;
        }
        if(a==27)
        {
            b=getchar();
            c=getchar();
            if(b==91 && c==66)
            {
                focus++;
                if(focus==size)
                {
                    start=0;
                    focus=0;
                }
                else if(focus>=start+page_size);
                {
                    start++;
                }
            }
            if(b==91 && c==65)
            {
                focus--;
                if(focus<0)
                {
                    focus=size-1;
                    start=size-page_size;
                    if(start<0) start=0;
                }
                else if(focus<start)
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
