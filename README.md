
## **1. The Norm 4.1 – C Coding Standard (42 School)**

> The **Norm** is a coding standard that all C projects at **42 School** must follow.

### **Key Constraints**

1. **Readability and Maintainability**
    - Code must be **clear, structured, and uniform** to ensure collaboration and ease of debugging.
    - Function names, variables, and struct identifiers must follow `snake_case` notation.
    - Global variables must start with `g_`, structs with `s_`, enums with `e_`, and unions with `u_`.

2. **Strict Formatting Rules**
    - **Function Length:** Max **25 lines** per function.
    - **Line Length:** Max **80 characters**.
    - **Indentation:** **4-space tabs** (ASCII 9).
    - **File Structure:** A `.c` file **must not** include another `.c` file.
    - **Header Files:** Must prevent multiple inclusions using header guards.

3. **Function Constraints**
    - **Maximum 4 parameters** per function.
    - **Maximum 5 variable declarations** per function.
    - **No inline comments** inside function bodies.

4. **Prohibited Elements**
    - `for`, `do...while`, `switch/case`, `goto`, ternary operators (`? :`).
    - Variable-Length Arrays (VLAs).
    - Implicit types (all variables must have explicit types).

5. **Compilation & Makefile**
    - The **Makefile** must include `all`, `clean`, `fclean`, `re`, and `bonus` rules.
    - Source files must be **explicitly listed** (wildcards like `*.c` are not allowed).
    - The project must **not recompile unnecessarily** (`make` should avoid redundant recompilation).

These strict guidelines ensure that **cub3D** maintains **readability, structure, and modularity**, making debugging and
reviewing code easier.

---

## **2. Mandatory Features of `cub3D`**

> `cub3D` is a **3D maze navigation game** using a **ray-casting engine**, inspired by *Wolfenstein 3D*.

### **2.1. Project Setup & Compilation**

- The **executable must be named `cub3D`**.
- Compilation should produce no **warnings or errors** using the flags:
  ```shell
  gcc -Wall -Wextra -Werror
  ```
- Running the game:
  ```shell
  ./cub3D map.cub
  ```
- The game **must not crash unexpectedly** (e.g., segmentation faults, memory leaks).

---

### **2.2. Configuration File (`.cub` Format)**

- The **map and settings** are defined in a `.cub` file.
- **Required elements**:
  ```
  NO ./path_to_north_texture
  SO ./path_to_south_texture
  WE ./path_to_west_texture
  EA ./path_to_east_texture
  F 220,100,0  # Floor color (RGB)
  C 225,30,0   # Ceiling color (RGB)
  ```
- The **map must be fully enclosed** by walls (`1`), and **player starts at `N/S/E/W`**.

#### **Error Handling**

- The program **must exit with an error message** if:
    - The configuration file is **misformatted**.
    - The filename **does not end with `.cub`**.
    - There are **missing or duplicated** keys.
    - Paths to textures **are invalid**.

---

### **2.3. Game Display & User Interaction**

- The game must use **miniLibX** for graphical rendering.
- **Ray-casting must render a 3D view of the maze** from a first-person perspective.
- **The game window must remain consistent** when minimized/restored.

#### **Basic User Inputs**

| Action | Key |
|--------|------|
| **Move Forward** | `W` / `Z` |
| **Move Backward** | `S` |
| **Move Left** | `A` / `Q` |
| **Move Right** | `D` |
| **Rotate Left** | Left Arrow (`←`) |
| **Rotate Right** | Right Arrow (`→`) |
| **Exit Game** | `ESC` or `X` button |

- Pressing **W/A/S/D (or ZQSD)** should result in **smooth** movement.
- Pressing the **left/right arrows** should rotate the player's view correctly.

---

### **2.4. Walls & Textures**

- **Wall textures** must vary depending on the **compass direction** (North, South, East, West).
- **Modifying the texture path** in the `.cub` file must update the rendering.
- **Invalid texture paths must result in an error**.
- **Floor & ceiling colors must be configurable** via the `.cub` file.

---

### **2.5. Error Management & Stability**

- The game **must handle incorrect inputs** gracefully:
    - **Unexpected arguments** should not crash the program.
    - **Rolling a random set of keys** should not cause **undefined behavior**.
- **Memory leaks must be prevented**:
    - Using tools like `valgrind` or `leaks` to check memory usage.

---

## **3. Summary of `cub3D_mandatory`**

This document further elaborates on **strict requirements** that must be met before any **bonus features** are
considered.

### **3.1. Display & Stability**

- The **game window must open properly** upon execution.
- **Hiding/minimizing the window** should not corrupt the display.
- **Clicking the window's close button must exit the program cleanly**.

### **3.2. Movement & Gameplay**

- The player's **starting position must match the `.cub` file**.
- **Rotations and movements** (`WASD` / `ZQSD`) should work **smoothly**.
- **Display lag or unresponsiveness** is unacceptable.

### **3.3. Walls & Rendering**

- **Wall textures must align properly** with their compass direction.
- **Modifying wall textures in the configuration file must update the game**.
- **Incorrect texture paths should trigger an error message**.

### **3.4. Error Handling**

- Running the program with **invalid arguments** should display an error.
- The **game should not crash** under unexpected input (e.g., spamming keyboard keys).
- **Modifying the map file must not cause undefined behavior**.

---

## **4. Key Takeaways**

| Aspect | Requirements |
|--------|-------------|
| **Coding Standard** | Must follow **42 School Norm (v4.1)**, with strict function/variable rules. |
| **Game Functionality** | Must render a **3D maze** with proper **textures, colors, and movement**. |
| **Error Handling** | The game must **handle invalid inputs and configuration errors gracefully**. |
| **Memory Safety** | No memory leaks, proper **resource cleanup required** before exiting. |
| **User Experience** | **Smooth movement, clear UI, and proper responsiveness**. |

---

## **Conclusion**

This project, **cub3D**, is a **42 School** assignment requiring a **ray-casting 3D rendering engine** built in **C with
miniLibX**, following strict **Norm coding rules**. It must **display a maze, allow player movement, and manage errors
efficiently**. Stability, readability, and compliance with guidelines are **critical** for successful implementation.