/**
 * @file kui_vt100.h
 * The functions of this library helps C programmers to implement simple and easy user interface on terminal 
 */

#ifndef __KUI_VT100_H
#define __KUI_VT100_H

/**
 * @enum KUI_COLOR
 *
 * @brief Represent the colors on terminal
 *
 * Each enum value indicate the color used by VT100 renderer.
 * 
 */
enum KUI_COLOR
{
    /** Black color indicator */
    KUI_COLOR_BLACK=101,

    /** Red color indicator */
    KUI_COLOR_RED=102,

    /** Green color indicator */
    KUI_COLOR_GREEN=103,

    /** Yellow color indicator */
    KUI_COLOR_YELLOW=104,

    /** Blue color indicator */
    KUI_COLOR_BLUE=105,

    /** Magenta color indicator */
    KUI_COLOR_MAGENTA=106,

    /** Cyan color indicator */
    KUI_COLOR_CYAN=107,

    /** White color indicator */
    KUI_COLOR_WHITE=108
};

/**
 * @brief Clears the terminal screen
 * 
 * See \ref kui_test1.c for a usage demonstration
 *
 * @note After clearing the terminal screen the cursor will be at position (0,0)
 */
void kui_clear();

/**
 * @brief Clears the specific portion of the terminal screen
 *
 * @param[in] row Row from which the portion should be cleared
 * @param[in] column Column from which the portionshould be cleared
 * @param[in] height Height of the portion that should be cleared
 * @param[in] width Width of the the portion that should be cleared
 *
 * @post User should use \ref kui_go_to_xy function
 *
 * @note The position of the cursor will be (row+height , column+widht) on the terminal screen
 */
void kui_clear_from_xy(int row,int column,int height,int width);


/**
 * @brief Moves the cursor to a specific screen position.
 *
 * @param[in] row Index of target row
 * @param[in] column Index of target column
 */
void kui_go_to_xy(int row,int column);

/**
 * @brief Prints text at a given position.
 *
 * @param[in] row Index of target row
 * @param[in] column Index of target column
 * @param[in] str Text to be printed
 *
 * @post User should use \ref kui_go_to_xy function
 *
 * @note The position of the cursor will be after the str, after printing that on given position
 */
void kui_say(int row,int column,char *str);

/**
 * @brief Prints a character at a given position
 *
 * @param[in] row Index of target row
 * @param[in] column Index of target column
 * @param[in] m Character to be printed
 *
 * @post User should use \ref kui_go_to_xy function
 *
 * @note The position of the cursor will after the m, after printing that on given position
 */
void kui_say_char(int row,int column,char m);

/**
 * @brief Draws a horizontal line
 *
 * @param[in] row Index of row where the horizontal line should be drawn
 * @param[in] column1 index of column from horizontal line should start
 * @param[in] column2 index of column where horizontal line should end
 *
 * @note The position of the cursor will be at (row+1)th row and 0th column\n
 * Make use of \ref kui_go_to_xy function to change the cursor position
 */
void kui_draw_horizontal_line(int row,int column1,int column2);

/**
 * @brief Draws a vertical line
 *
 * @param[in] column Index of column where the vertical line should be drawn
 * @param[in] row1 Index of row from where vertical line should start
 * @param[in] row2 Index of row where vertical line should end
 *
 * @note The position of the cursor will be at (row2+1)th row and 0th column\n
 * Make use of \ref kui_go_to_xy function to change the cursor position
 */
 void kui_draw_vertical_line(int column,int row1,int row2);

/**
 * @brief Draws a box
 *
 * @param[in] top_left_row Row of top-left corner
 * @param[in] top_left_column Column of top-left corner
 * @param[in] bottom_right_row Row of bottom-rigth corner
 * @param[in] bottom_right_column Colmn of bottom-right corner
 *
 * @note The position of the cursor will be at (bottom_right_row + 1)th row and 0th column\n
 * Make use of \ref kui_go_to_xy function to change the cursor position \n\n
 *
 * Make use of \ref kui_say function to write inside the box
 */
void kui_draw_box(int top_left_row,int top_left_column,int bottom_right_row,int bottom_right_column);


/**
 * @brief Draws a double horizontal line
 *
 * @param[in] row index of row where the double horizontal line should be drawn
 * @param[in] column1 index of column from double  horizontal line should start
 * @param[in] column2 index of column where double horizontal line should end
 *
 * @note The position of the cursor will be at (row+1)th row and 0th column\n
 * Make use of \ref kui_go_to_xy function to change the cursor position
 */
void kui_draw_double_horizontal_line(int row,int column1,int column2);

/**
 * @brief Draws a double vertical line
 *
 * @param[in] column index of column where the double vertical line should be drawn
 * @param[in] row1 index of row from where double vertical line should start
 * @param[in] row2 index of row where double vertical line should end
 *
 * @note The position of the cursor will be at (row+1)th row and 0th column\n
 * Make use of \ref kui_go_to_xy function to change the cursor position
 */
void kui_draw_double_vertical_line(int column,int row1,int row2);

/**
 * @brief Draws a double line box
 *
 * @param[in] top_left_row Row of top-left corner
 * @param[in] top_left_column Column of top-left corner
 * @param[in] bottom_right_row Row of bottom-rigth corner
 * @param[in] bottom_right_column Colmn of bottom-right corner
 *
 * @note The position of the cursor will be at (bottom_right_row + 1)th row and 0th column\n
 * Make use of \ref kui_go_to_xy function to change the cursor position \n\n
 *
 * Make use of \ref kui_say function to write inside the box
 */
void kui_draw_double_line_box(int top_left_row,int top_left_column,int bottom_right_row,int bottom_right_column);

/**
 * @brief Sets the background color
 *
 * @param[in] color Background color value from \ref KUI_COLOR
 *
 * @note The color remains active until another color or reset escape sequence is sent.
 */
void kui_set_background_color(enum KUI_COLOR color);

/**
 * @brief Sets the foreground color
 *
 * @param[in] color Foreground color value from \ref KUI_COLOR
 *
 * @note The color remains active until another color or reset escape sequence is sent.
 */
void kui_set_foreground_color(enum KUI_COLOR color);

/**
 * @brief Set foreground and background color
 *
 * @param[in] foreground_color Foreground color value from \ref KUI_COLOR
 * @param[in] background_color Background color value from \ref KUI_COLOR
 *
 * @note The color remains active until another color or reset escape sequence is sent.
 */
void kui_set_color(enum KUI_COLOR foreground_color,enum KUI_COLOR background_color);

/**
 * @brief Remove the background color
 *
 */
void kui_remove_background_color();

/**
 * @brief Remove the foreground color
 *
 */
void kui_remove_foreground_color();

/**
 * @brief Remove the foreground and background color
 */
void kui_remove_color();

/**
 * @brief Displays a fix-sized Menu list, allowing users to navigate additional options via scrolling
 * 
 * @param[in] menu base address of 2D array containing options in menu
 * @param[in] menu_size size of the menu list
 * @param[in] visible_size default number of options to display 
 * @param[in] row Row from where menu will be displayed
 * @param[in] column Column from where menu will be displayed
 * @param[in] height Height of the menu 
 * @param[in] width Width of the menu
 *
 * @return The index of the selected option
 * 
 * @note if some error occurend it will return -1
 */
int kui_menu(char *menu[],int menu_size,int visible_size,int row,int column,int height,int width);

/**
 * @brief Displays a fix-sized Choice list, allowing users to navigate using right / left arrow key
 *
 * @param[in] choices Base address of 2D array containing options in choice
 * @param[in] size Size of numbers of choices
 * @param[in] row Row from where the choice list will be displayed
 * @param[in] column Column from where the choice list will be displayed
 *
 * @return The index of the selected option
 *
 * @note if some error occurend it will return -1
 */
int kui_choice(char *choices[],int size,int row,int column);

/**
 * @brief Displays a fix-sized Checkbox list, allowing users to navigate additional options via scrolling
 * 
 * @param[in] list base address of 2D array containing options in checkbox list
 * @param[in] size size of the list
 * @param[in] visible_size default number of options to display 
 * @param[in] row Row from where menu will be displayed
 * @param[in] column Column from where menu will be displayed
 * @param[in] height Height of the menu 
 * @param[in] width Width of the menu
 * @param[out] result_size Base address of an int type variable where the number of selected items to be stored
 *
 * @return Base address of int type array where the list of selected indexes to be stored
 *
 * @note The user have to release the memory of the retured array when the work is done (if item has been selected the function will return NULL)
 */
int *  kui_checkbox(char *list[],int size, int visible_size,int row,int column,int height, int width,int *result_size);
#endif
