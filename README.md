# KUI – VT100 Terminal UI Library (C)

KUI is a lightweight C library for building terminal-based user interfaces using VT100 escape sequences.

It provides APIs for cursor control, text rendering, drawing primitives, and color manipulation.

---

## Features

- Cursor positioning
- Screen clearing
- Text rendering at coordinates
- Single-line and double-line drawing
- Box rendering
- Foreground and background color control
- Minimal and dependency-free

---

## Project Structure

```

kui/
├── include/
│   └── kui_vt100.h
├── src/
│   └── kui.c
├── lib/
│   └── libkui.a
└── README.md

```

---

## Run

```

./eg1.out

````

---

## Example

```c
#include "kui_vt100.h"

int main()
{
    kui_clear();

    kui_set_color("white", "blue");

    kui_draw_double_line_box(2, 5, 10, 50);

    kui_say(4, 10, "KUI Terminal UI");

    kui_remove_color();

    kui_go_to_xy(12, 1);

    return 0;
}
````

---

## Run / execute

```

gcc eg1.c -o eg1.out -I kui/include -L kui/lib -lkui

./eg1.out

```

---

## API Overview

### Screen

* kui_clear()
* kui_go_to_xy(row, column)

### Text

* kui_say(row, column, str)

### Drawing

* kui_draw_horizontal_line()

* kui_draw_vertical_line()

* kui_draw_box()

* kui_draw_double_horizontal_line()

* kui_draw_double_vertical_line()

* kui_draw_double_line_box()

### Color

* kui_set_foreground_color()
* kui_set_background_color()
* kui_set_color()
* kui_remove_color()

---

## How It Works

Uses VT100 escape sequences:

```
\033[2J        -> Clear screen
\033[row;colH  -> Move cursor
\033[31m       -> Red text
\033[0m        -> Reset
```

---

## Limitations

* Only for Unix-based OS
* 1-based coordinate system
* No bounds checking
* No input handling
* Requires VT100-compatible terminal

---

## Future Work

* Menu system (scrollable, interactive)
* Keyboard input handling
* Window/panel abstraction

---

## Author

Kanishk Chouhan

---
