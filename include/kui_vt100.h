#ifndef __KUI_VT100_H
#define __KUI_VT100_h

/**
 * to clear the screen
 */
void kui_clear();

/**
 * to go to any perticular location at screen
 */
void kui_go_to_xy(int row,int column);

/**
 * to print a string at the givan location
 */
void kui_say(int row,int column,char *str);


/**
 * to draw a horizontal line, in a perticular row from column1 to column2 
 */
void kui_draw_horizontal_line(int row,int column1,int column2);

/**
 * to draw a vertical line, in a perticular column from row1 to row2
 */
void kui_draw_vertical_line(int column1,int row1,int row2);

/**
 * to draw a box with 
 */
void kui_draw_box(int top_left,int top_right,int bottom_left,int bottom_right);


void kui_draw_double_horizontal_line(int row,int column1,int column2);

void kui_draw_double_vertical_line(int column,int row1,int row2);

void kui_draw_double_line_box(int top_left_row,int top_left_column,int bottom_right_row,int bottom_right_column);

void kui_set_background_color(char *color);
void kui_set_foreground_color(char *color);
void kui_set_color(char *foreground_color,char *background_color);

void kui_remove_background_color();
void kui_remove_foreground_color();
void kui_remove_color();

#endif
