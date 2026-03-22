#include<kui_vt100.h>
#include<stdio.h>
#include<string.h>
#include<unistd.h>
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
