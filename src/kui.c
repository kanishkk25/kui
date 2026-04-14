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

/**
 * draws a double horizontal line at the given location
 */
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


/**
 * draws a double vertical line at the given location
 */
void kui_draw_double_vertical_line(int column,int row1,int row2)
{
    int start=row1;
    while(start<=row2)
    {
        kui_say(start,column,"\u2551");
        start++;
    }
}

/**
 * draws a double line box at the given location
 */
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

/**
 * sets the foreground color to the color given
 *
 * valid colors include "black", "red", "green", "yellow",
 * "blue", "magenta", "cyan", and "white"
 *
 * if an invalid color is passed an error message is thrown to stderr
 */
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
    else {
        fprintf(stderr, "kui_set_foreground_color: Invalid color");
    }
}

/*
 * sets the background color to the color given
 *
 * valid colors include "black", "red", "green", "yellow",
 * "blue", "magenta", "cyan", and "white"
 *
 * if an invalid color is passed an error message is thrown to stderr
 */
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
    else{
        fprintf(stderr, "kui_set_background_color: Invalid color");
    }
}

/*
 * sets both the background and foreground colors to the color given
 *
 * valid colors include "black", "red", "green", "yellow",
 * "blue", "magenta", "cyan", and "white"
 *
 * if an invalid color is passed an error message is thrown to stderr
 */
void kui_set_color(char *foreground_color,char *background_color)
{
    kui_set_foreground_color(foreground_color);
    kui_set_background_color(background_color);
}

/*
 * removes the current background color
 */
void kui_remove_background_color()
{
    printf("\033[49m");
}

/*
 * removes the current foreground color
 */
void kui_remove_foreground_color()
{
    printf("\033[39m");
}

/**
 * 
 */
void kui_remove_color()
{
    printf("\033[0m");
}
