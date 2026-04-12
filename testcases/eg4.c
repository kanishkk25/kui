#include<kui_vt100.h>
#include<stdio.h>
#include<string.h>
#include<termios.h>
#include<unistd.h>
void kui_input_box(int row,int column,char *array,int char_width,int screen_width,char ld,char rd)
{
    struct termios new_t,old_t;
    int maxLenght=char_width;
    int i;
    char m;
    int r,c;
    int bb,cc;
    int j;
    if(row<1 || column<1) return;
    if(array==NULL) return;
    if(char_width<1) return;
    if(screen_width<1) return;
    if(strlen(array)>0)
    {
        array[0]='\0';
    }

    tcgetattr(fileno(stdout),&old_t);
    new_t=old_t;

    new_t.c_lflag = new_t.c_lflag & ~(ECHO | ICANON);

    new_t.c_cc[VMIN]=1;
    new_t.c_cc[VTIME]=0;

    tcsetattr(fileno(stdout),0,&new_t);
    i=0;
    while(1)
    {
        r=row;
        c=column;
        kui_clear();

        kui_say_char(r,c,ld);
        //kui_go_to_xy(r,c+screen_width+1);
        //printf("%c",rd);
        kui_say_char(r,c+screen_width+1,rd);
        kui_go_to_xy(r,c+1);
        j=0;
        while(j<i)
        {
            write(fileno(stdout),array+j,1);
            j++;
            if(j % screen_width==0)
            {
                r++;
                kui_say_char(r,c,ld);
                kui_say_char(r,c+screen_width+1,rd);
                kui_go_to_xy(r,c+1);
            }
        }
        m=getchar();
        fflush(stdin);
        if(i+1 == char_width) break;
        if(m==10) break;
        if(m==127 && i>0)
        {
            write(fileno(stdout),"\033nC",3);
            i--;
            continue;
        }
        if(m==27)
        {
            bb=getchar();
            cc=getchar();
            if(bb==91 && cc==65)
            {
                // up arrow key
            }
            if(bb==91 && cc==66)
            {
                // down arrow key
            }
            if(bb==91 && cc==67)
            {
                // right arrow key
            }
            if(bb==91 && cc==68)
            {
                // left arrow key
            }
        }
        array[i]=m;
        array[i+1]='\0';
        i++;
    }
    tcsetattr(fileno(stdout),0,&old_t);
}

int main()
{
    char a[501];
    kui_input_box(4,6,a,500,20,'[',']');
    return 0;
}
