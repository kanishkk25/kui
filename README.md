# KUI – VT100 Terminal UI Library (C)

KUI is a lightweight C library for building terminal-based user interfaces using VT100 escape sequences.

It provides APIs for cursor control, text rendering, drawing primitives, and color manipulation.

---

## Features

- Cursor positioning
- Screen clearing
- Single-line and double-line drawing
- Foreground and background color control

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
├── testcases/
│   └── eg1.c
│   └── eg2.c
│   └── eg3.c
│   └── eg4.c
├── Makefile
└── README.md



```

---

## Example

```
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
```

---

## Run / execute via Makefile

```
make buildeg1
./eg1.out

make buildeg2
./eg2.out

make buildeg3
./eg3.out

make buildeg4
./eg4.out

make clear -- removes all .out files
```
---
## Build Library

```
make build -- rebuilds the libkui.a file, updating the library with any changes
```


---

## API Overview

### Screen


```
* kui_clear()
* kui_go_to_xy(row, column)
```

### Text
```
* kui_say(row, column, str)
```
### Drawing
```
* kui_draw_horizontal_line()

* kui_draw_vertical_line()

* kui_draw_box()

* kui_draw_double_horizontal_line()

* kui_draw_double_vertical_line()

* kui_draw_double_line_box()
```
### Color
```
* kui_set_foreground_color()
* kui_set_background_color()
* kui_set_color()
* kui_remove_color()
```
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
```
* No bounds checking
* No input handling
* Requires VT100-compatible terminal
```
---

## Future Work
```
* Menu system (scrollable, interactive)
* Keyboard input handling
* Window/panel abstraction
```
---

## Author
```
Kanishk Chouhan
```
---
