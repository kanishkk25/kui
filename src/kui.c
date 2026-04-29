#include<kui_vt100.h>
#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<termios.h>
/**
 * to clear the screen
 */
void kui_clear()
{
    write(fileno(stdout),"\033[2J",4);
}

/**
 * to go to any perticular location at screen
 */
void kui_go_to_xy(int row,int column)
{
    char buffer[10];
    int x=sprintf(buffer,"\033[%d;%dH",row,column);
    write(fileno(stdout),buffer,x);
}

/**
 * to print a string at the givan location
 */
void kui_say(int row,int column,char *str)
{
    kui_go_to_xy(row,column);
    write(fileno(stdout),str,strlen(str));
}

/**
 * to pint a char at a given location
 */
void kui_say_char(int row,int column,char m)
{
    char str[2];
    str[0]=m;
    str[1]='\0';
    kui_go_to_xy(row,column);
    write(fileno(stdout),str,1);
}

/**
 * to draw a horizontal line, in a perticular row from column1 to column2 
 */
void kui_draw_horizontal_line(int row,int column1,int column2)
{
    int start=column1;
    kui_go_to_xy(row,column1);
    while(start<=column2)
    {
        printf("\u2500");
        start++;
    }
    fflush(stdout);
}

/**
 * to draw a vertical line, in a perticular column from row1 to row2
 */
void kui_draw_vertical_line(int column,int row1,int row2)
{
    int start=row1;
    while(start<=row2)
    {
        kui_say(start,column,"\u2502");
        start++;
    }
}


/**
 * to draw a box with 
 */
void kui_draw_box(int top_left_row,int top_left_column,int bottom_right_row,int bottom_right_column)
{
    kui_say(top_left_row,top_left_column,"\u250c");
    
    kui_say(top_left_row,bottom_right_column,"\u2510");

    kui_say(bottom_right_row,top_left_column,"\u2514");

    kui_draw_horizontal_line(top_left_row,top_left_column+1,bottom_right_column-1);
    kui_draw_horizontal_line(bottom_right_row,top_left_column+1,bottom_right_column-1);

    kui_draw_vertical_line(top_left_column,top_left_row+1,bottom_right_row-1);
    kui_draw_vertical_line(bottom_right_column,top_left_row+1,bottom_right_row-1);

    kui_say(bottom_right_row,bottom_right_column,"\u2518");
}

void kui_draw_double_horizontal_line(int row,int column1,int column2)
{
    int start=column1;
    kui_go_to_xy(row,column1);
    while(start<=column2)
    {
        printf("\u2550");
        start++;
    }
    fflush(stdout);
}

void kui_draw_double_vertical_line(int column,int row1,int row2)
{
    int start=row1;
    while(start<=row2)
    {
        kui_say(start,column,"\u2551");
        start++;
    }
}
void kui_draw_double_line_box(int top_left_row,int top_left_column,int bottom_right_row,int bottom_right_column)
{
    kui_say(top_left_row,top_left_column,"\u2554");
    
    kui_say(top_left_row,bottom_right_column,"\u2557");

    kui_say(bottom_right_row,top_left_column,"\u255a");

    kui_draw_double_horizontal_line(top_left_row,top_left_column+1,bottom_right_column-1);
    kui_draw_double_horizontal_line(bottom_right_row,top_left_column+1,bottom_right_column-1);

    kui_draw_double_vertical_line(top_left_column,top_left_row+1,bottom_right_row-1);
    kui_draw_double_vertical_line(bottom_right_column,top_left_row+1,bottom_right_row-1);

    kui_say(bottom_right_row,bottom_right_column,"\u255d");
}
void kui_set_foreground_color(char *color)
{
    if(strcmp(color,"black")==0) printf("\033[30m");
    else if(strcmp(color,"red")==0) printf("\033[31m");
    else if(strcmp(color,"green")==0) printf("\033[32m");
    else if(strcmp(color,"yellow")==0) printf("\033[33m");
    else if(strcmp(color,"blue")==0) printf("\033[34m");
    else if(strcmp(color,"magenta")==0) printf("\033[35m");
    else if(strcmp(color,"cyan")==0) printf("\033[36m");
    else if(strcmp(color,"white")==0) printf("\033[37m");
}

void kui_set_background_color(char *color)
{
    if(strcmp(color,"black")==0) printf("\033[40m");
    else if(strcmp(color,"red")==0) printf("\033[41m");
    else if(strcmp(color,"green")==0) printf("\033[42m");
    else if(strcmp(color,"yellow")==0) printf("\033[43m");
    else if(strcmp(color,"blue")==0) printf("\033[44m");
    else if(strcmp(color,"magenta")==0) printf("\033[45m");
    else if(strcmp(color,"cyan")==0) printf("\033[46m");
    else if(strcmp(color,"white")==0) printf("\033[47m");
}
void kui_set_color(char *foreground_color,char *background_color)
{
    kui_set_foreground_color(foreground_color);
    kui_set_background_color(background_color);
}

void kui_remove_background_color()
{
    printf("\033[49m");
}
void kui_remove_foreground_color()
{
    printf("\033[39m");
}
void kui_remove_color()
{
    printf("\033[0m");
}


int kui_menu(char *menu[],int menu_size,int visible_size,int row,int column,int height,int width)
{
    int start,end;
    int i;
    int top_left_row,top_right_column,bottom_left_row,bottom_right_column;
    int selected;
    int r,col;
    struct termios new_t,old_t;
    char a,b,c;
    if(tcgetattr(STDIN_FILENO,&old_t)==-1)
    {
        return -1;
    }
    new_t=old_t;
    new_t.c_lflag=new_t.c_lflag & ~(ECHO | ICANON);
    new_t.c_cc[VTIME]=0;
    new_t.c_cc[VMIN]=1;
    if(tcsetattr(STDIN_FILENO,0,&new_t)==-1)
    {
        return -1;
    }
    top_left_row=row;
    top_right_column=column;
    bottom_left_row=row+height;
    bottom_right_column=column+width;

    start=0;
    selected=0;
    while(1)
    {
        kui_clear();
        kui_draw_box(top_left_row,top_right_column,bottom_left_row,bottom_right_column);
        r=row+1;
        col=column+1;
        end=start+visible_size;
        if(end>menu_size) end=menu_size;
        kui_go_to_xy(r,col);
        for(i=start;i<end;i++)
        {
            kui_go_to_xy(r,col);
            r++;
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
            if(tcsetattr(STDIN_FILENO,0,&old_t)==-1)
            {
                return -1;
            }
            return selected;
        }
        if(a==27)
        {
            b=getchar();
            c=getchar();
            if(b==91 && c==66)
            {
                selected++;
                if(selected==menu_size)
                {
                    start=0;
                    selected=0;
                }
                else if(selected >=start+visible_size)
                {
                    start++;
                }
            }
            if(b==91 && c==65)
            {
                selected--;
                if(selected<0)
                {
                    selected=menu_size-1;
                    start=menu_size-visible_size;
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
        return -1;
    }
}


int kui_choice(char *choices[],int size,int row,int column)
{
    int start,end;
    int i;
    int selected;
    int focus;
    struct termios new_t,old_t;
    char a,b,c;
    if(tcgetattr(STDIN_FILENO,&old_t)==-1)
    {
        //err_exit("Unable to get information using tcgetattr\n");
        return -1;
    }
    new_t=old_t;
    new_t.c_lflag=new_t.c_lflag & ~(ECHO | ICANON);
    new_t.c_cc[VTIME]=0;
    new_t.c_cc[VMIN]=1;
    if(tcsetattr(STDIN_FILENO,0,&new_t)==-1)
    {
        //err_exit("Unable to set information using tcsetattr\n");
        return -1;
    }
    selected=-1;
    focus=0;
    while(1)
    {
        kui_go_to_xy(row,column);
        kui_clear(); 
        for(i=0;i<size;i++)
        {
            if(i==focus)
            {
                kui_set_background_color("white");
                printf("%s ",choices[i]);
                if(i==selected) printf("(*)");
                else printf("( )");
                kui_remove_background_color();
                printf("   ");
            }
            else
            {
                printf("%s ",choices[i]);
                if(i==selected) printf("(*)");
                else printf("( )");
                printf("   ");
            }
        }
        printf("\n");
        a=getchar();
        if(a==10)
        {

            if(tcsetattr(STDIN_FILENO,0,&old_t)==-1)
            {
                //err_exit("Unable to set information using tcsetattr\n");
                return -1;
            }
            if(selected==-1)
            {
                return -1;
            }
            else
            {
                return selected;
            }
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
        //err_exit("Unable to set information using tcsetattr\n");
        return -1;
    }
    return 0;
}
