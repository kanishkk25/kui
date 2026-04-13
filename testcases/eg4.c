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
    char bb,cc;
    int j;
    int k;
    int z;
    int cursor_row,cursor_column;
    int cursorMoved=0;
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
    k=0;
    i=0;
    while(1)
    {
        if(cursorMoved==0)
        {
            r=row;
            c=column;
            kui_clear();

            kui_say_char(r,c,ld);
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
            if(i!=k)
            {
                kui_go_to_xy(cursor_row,cursor_column);
            }
            else
            {
                cursor_row=r;
                cursor_column=column + (k%screen_width)+1;
            }
        }
        m=getchar();
        fflush(stdin);
        if(i+1 == char_width) break;
        if(m==10) break;
        if(m==127 && i>0 && k>0)
        {
            // write(fileno(stdout),"\033[1D",3);
            for(z=k-1;z<i;z++)
            {
                array[z]=array[z+1];
            }
            array[z]='\0';
            i--;
            k--;

            if((k+1)%screen_width==0) cursor_row=cursor_row-1;
            cursor_column=column + (k%screen_width) + 1;
            cursorMoved=0;
            continue;
        }
        else if(m==27)
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
                if(k<i)
                {   
                    k++;
                    if(k%screen_width==0)
                    {
                        cursor_row=cursor_row+1;
                        cursor_column=column+1;
                        kui_go_to_xy(cursor_row,cursor_column);
                    }
                    else
                    {
                        write(fileno(stdout),"\033[1C",4);
                    }
                }
                cursorMoved=1;
            }
            if(bb==91 && cc==68)
            {
                // left arrow key
                if(k>0)
                {
                    if(k%screen_width==0)
                    {
                        cursor_row=cursor_row-1;
                        cursor_column=column+screen_width;
                        kui_go_to_xy(cursor_row,cursor_column);
                    }
                    else
                    {
                        write(fileno(stdout),"\033[1D",4);
                    }
                    k--;
                }
                cursorMoved=1;
            }
        }
        else
        {
            if(i==k)
            {
                array[i]=m;
                array[i+1]='\0';
                i++;
                k=i;
            }
            else
            {
                array[i]='\0';
                i++;
                for(z=i-1;z>=k;z--)
                {
                    array[z+1]=array[z];
                }
                array[k]=m;
                k++;
                if(k%screen_width==0) cursor_row=cursor_row+1;
                cursor_column=column + (k%screen_width)+1;
            }
            cursorMoved=0;
        }
    }
    tcsetattr(fileno(stdout),0,&old_t);
    printf("\n");
}

int main()
{
    char a[501];
    kui_input_box(4,6,a,500,20,'[',']');
    return 0;
}
