/**
 * @file kui_vt100.h
 * @brief VT-100 terminal utility functions for UI.
 */

#ifndef __KUI_VT100_H
#define __KUI_VT100_H


/**
 * @brief Clears the terminal screen
 */
void kui_clear();

/**
 * @brief Moves the cursor to a specific screen position.
 *
 * @param row index of target row
 * @param column index of target column
 */
void kui_go_to_xy(int row,int column);

/**
 * @brief Prints text at a given position.
 *
 * @param row index of target row
 * @param column index of target column
 * @param str text to be print
 */
void kui_say(int row,int column,char *str);


/* *
 * @brief Prints a char at a given position
 *
 * @param row index of target row
 * @param column index of target column
 * @param m char to be print
 */
void kui_say_char(int row,int column,char m);


/**
 * @brief Draws a horizontal line
 *
 * @param row index of row where the horizontal line should be drawn
 * @param column1 index of column from horizontal line should start
 * @param column2 index of column where horizontal line should end
 */
void kui_draw_horizontal_line(int row,int column1,int column2);

/**
 * @brief Draws a vertical line
 *
 * @param column index of column where the vertical line should be drawn
 * @param row1 index of row from where vertical line should start
 * @param row2 index of row where vertical line should end
 */
void kui_draw_vertical_line(int column,int row1,int row2);

/**
 * @brief Draws a box
 *
 * @param top_left_row Row of top-left corner
 * @param top_left_column Column of top-left corner
 * @param bottom_right_row Row of bottom-rigth corner
 * @param bottom_right_column Colmn of bottom-right corner
 */
void kui_draw_box(int top_left_row,int top_left_column,int bottom_right_row,int bottom_right_column);


/**
 * @brief Draws a double horizontal line
 *
 * @param row index of row where the double horizontal line should be drawn
 * @param column1 index of column from double  horizontal line should start
 * @param column2 index of column where double horizontal line should end
 */
void kui_draw_double_horizontal_line(int row,int column1,int column2);

/**
 * @brief Draws a double vertical line
 *
 * @param column index of column where the double vertical line should be drawn
 * @param row1 index of row from where double vertical line should start
 * @param row2 index of row where double vertical line should end
 */
void kui_draw_double_vertical_line(int column,int row1,int row2);

/**
 * @brief Draws a double line box
 *
 * @param top_left_row Row of top-left corner
 * @param top_left_column Column of top-left corner
 * @param bottom_right_row Row of bottom-rigth corner
 * @param bottom_right_column Colmn of bottom-right corner
 */
void kui_draw_double_line_box(int top_left_row,int top_left_column,int bottom_right_row,int bottom_right_column);


/*
 * Acceptable color list
 * - black
 * - red
 * - green
 * - yellow
 * - blue
 * - magenta
 * - cyan
 * - white
 *
 * NOTE: you have to pass one of these color name with as it is, because we are performing case-sensitive
 * string comparison under the hood.
 */

/**
 * @brief Set background color
 *
 * @param color background color
 */
void kui_set_background_color(char *color);

/**
 * @brief Set foreground color
 *
 * @param color foreground color
 */
void kui_set_foreground_color(char *color);

/**
 * @brief Set foreground and background color
 *
 * @param foregounrd_color foreground color
 * @param background_color background color
 */
void kui_set_color(char *foreground_color,char *background_color);

/**
 * @brief Resets background color
 */
void kui_remove_background_color();

/**
 * @brief Resets foreground color
 */
void kui_remove_foreground_color();

/**
 * @brief Resets foreground and background color
 */
void kui_remove_color();

/**
 * @brief Displays a fix-sized Menu list, allowing users to navigate additional options via scrolling
 * 
 * @param menu base address of 2D array containing options in menu
 * @param menu_size size of the menu list
 * @param visible_size default number of options to display 
 * @param row Row from where menu will be displayed
 * @param column Column from where menu will be displayed
 * @param height Height of the menu 
 * @param width Width of the menu
 *
 * @return The index of the selected option
 *
 */
int kui_menu(char *menu[],int menu_size,int visible_size,int row,int column,int height,int width);

/**
 * @brief Displays a fix-sized Choice list, allowing users to navigate using right / left arrow key
 *
 * @param choices Base address of 2D array containing options in choice
 * @param size Size of numbers of choices
 * @param row Row from where the choice list will be displayed
 * @param column Column from where the choice list will be displayed
 *
 * @return The index of the selected option
 *
 */
int kui_choice(char *choices[],int size,int row,int column);

#endif
