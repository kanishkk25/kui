#include<kui_vt100.h>
#include<stdio.h>
#include<string.h>
#include<termios.h>
#include<unistd.h>

// for tesing 
void print_cursor_index(int k)
{
    char a[11];
    sprintf(a,"%d",k);
    kui_say(20,2,a);
}
// for tesing 
void print_size(int i)
{
    char a[11];
    sprintf(a,"%d",i);
    kui_say(20,6,a);
}
// for tesing 
void print_cursor_row(int cursor_row)
{
    char a[11];
    sprintf(a,"%d",cursor_row);
    kui_say(20,10,a);
}
// for tesing 
void print_cursor_column(int cursor_column)
{
    char a[11];
    sprintf(a,"%d",cursor_column);
    kui_say(20,14,a);
}

void kui_input_box(int row,int column,char *array,int size,int screen_width,char ld,char rd)
{
    struct termios new_t,old_t;
    int i;
    char m;
    int r,c;
    char bb,cc;
    int j;
    int k;
    int z;
    int cursor_row,cursor_column;
    if(row<1 || column<1) return;
    if(array==NULL) return;
    if(size<1) return;
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

    cursor_row=row;
    cursor_column=column+1; 
    k=0;
    i=0;
    while(1)
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
        
        write(fileno(stdout),"\033[s",3); // for testing
        if(i!=k)
        {
            cursor_row=row+(k/screen_width);
            cursor_column=column+(k%screen_width)+1;
            kui_go_to_xy(cursor_row,cursor_column);
            write(fileno(stdout),"\033[s",3);
        }
        else
        {
            cursor_row=row+(i/screen_width);
            cursor_column=column+(i%screen_width)+1;
        }
        print_cursor_index(k);                  // for testing
        print_size(i);                          // for testing
        print_cursor_row(cursor_row);           // for testing
        print_cursor_column(cursor_column);     // for testing

        write(fileno(stdout),"\033[u",3);   // for testing

        m=getchar();
        fflush(stdin);
        if(i==size) break;
        if(m==10) break;
        if(m==127)
        {
            if(k>0)
            {
            // write(fileno(stdout),"\033[1D",3);
                for(z=k-1;z<i;z++)
                {
                    array[z]=array[z+1];
                }
                i--;
                array[i]='\0';
                k--;
            }
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
                }
               // cursorMoved=1;
            }
            if(bb==91 && cc==68)
            {
                // left arrow key
                if(k>0 && i>0)
                {
                    k--;
                }
            }
        }
        else
        {
            if(i==k)
            {
                array[i]=m;
                i++;
                array[i]='\0';
                k=i;
            }
            else
            {
                for(z=i;z>k;z--)
                {
                    array[z]=array[z-1];
                }
                array[k]=m;
                k++;
                i++;
                array[i]='\0';
            }
        }
    }
    tcsetattr(fileno(stdout),0,&old_t);
    printf("\n");
}

int main()
{
    char a[501];
    kui_input_box(4,6,a,501,20,'[',']'); // 1st argument - row index
                                         // 2nd argument - column index
                                         // 3rd argument - base address of the array
                                         // 4th argument - size of the array including '\0'
                                         // 5th argument - screen width for input
                                         // 6th argument - left delimeter
                                         // 7th argument - right delimeter
    printf("Text in box is : (%s)\n",a);
    printf("Length is : %ld\n",strlen(a));
    return 0;
}
