# CIS 165 - Lab 7: Loops, Largest and Smallest Values

## How to Compile and Run
To compile and run this program from the terminal, use the following commands:

**Min/Max Program:**
`g++ -std=c++17 -Wall -Wextra min_max.cpp -o min_max`
`./min_max`

* Note: I use a Mac, and so my terminal compiles slightly differently than a Windows machine. More specifically, I use `clang++` instead of `g++`*

## Program Plan

**min_max.cpp Plan:**
1. Declare a named constant `SENTINEL` set to `-99`, integer variables for `number`, `smallest`, and `largest`, and a boolean variable `has_data` initialized to `false`.
2. Prompt the user and read the first integer into `number`.
3. Use a `while` loop that runs as long as `number != SENTINEL`.
4. On the first loop iteration (`!has_data`), set both `smallest` and `largest` equal to `number` and set `has_data` to `true`. On all following iterations, compare `number` against `smallest` and `largest` and update them if a smaller or larger value is found.
5. Read the next integer at the bottom of the loop.
6. After the loop ends, check `has_data`: if it is still `false`, output a message stating that no data values were entered; otherwise, output `smallest` and `largest` with labels.

## Test Tables

| Program and test | Test / data | Expected result | Actual output | Match or correction |
| :--- | :--- | :--- | :--- | :--- |
| **min_max.cpp** (all positive) | `8, 3, 12, -99` | Smallest 3; largest 12 | Smallest: 3, Largest: 12 | ✅ Match |
| **min_max.cpp** (all negative) | `-8, -3, -12, -99` | Smallest -12; largest -3 | Smallest: -12, Largest: -3 | ✅ Match |
| **min_max.cpp** (single value) | `5, -99` | Smallest 5; largest 5 | Smallest: 5, Largest: 5 | ✅ Match |
| **min_max.cpp** (zeros only) | `0, 0, -99` | Smallest 0; largest 0 | Smallest: 0, Largest: 0 | ✅ Match |
| **min_max.cpp** (empty series) | `-99` | Clear no-data message | No data values were entered. | ✅ Match |
| **min_max.cpp** (extra test: values below -99) | `-150, 42, -100, -99` | Smallest -150; largest 42 | Smallest: -150, Largest: 42 | ✅ Match |

*Extra Test Explanation:* I tested `-150, 42, -100, -99` to verify that the program handles mixed negative and positive integers properly, and that valid negative numbers smaller than `-99` (like `-150` and `-100`) are still accepted because the loop checks for `number != -99` rather than `number > -99`.

* Note: No temporary source code edits were needed since all test series were entered via standard input, and I completed a final compile and run of `min_max.cpp` before committing.*

## Code Explanations

**Trace one series through the loop, showing when the extrema are initialized and updated.**
For the series `8, 3, 12, -99`, the user first enters `8`. Because `8 != -99`, the loop starts. Since `has_data` is `false`, `smallest` and `largest` are both initialized to `8`, and `has_data` becomes `true`. Next, the user enters `3`; inside the loop, `3 < smallest` (`3 < 8`) is true, so `smallest` updates to `3` while `largest` stays `8`. Next, the user enters `12`; `12 > largest` (`12 > 8`) is true, so `largest` updates to `12` while `smallest` stays `3`. Finally, the user enters `-99`, which makes the loop condition `number != SENTINEL` false, ending the loop and printing `3` and `12`.

**How does your code keep -99 out of the calculations?**
The program reads each new input before the `while (number != SENTINEL)` condition is evaluated. As soon as `-99` is entered, the `while` condition immediately evaluates to `false` and exits the loop before anything inside the loop body can execute.

**Why is initializing both extrema to zero incorrect for some series?**
If both `smallest` and `largest` are initialized to `0`, an all-positive series (like `8, 3, 12`) would never find a number smaller than `0`, falsely reporting `0` as the smallest value. Similarly, an all-negative series (like `-8, -3, -12`) would never find a number larger than `0`, falsely reporting `0` as the largest value.

**How do you distinguish an empty series from a series containing zero?**
I use a separate boolean variable named `has_data` that starts as `false` and only turns `true` when the program enters the `while (number != SENTINEL)` loop. If the user enters `-99` immediately, the loop never runs and `has_data` remains `false`, whereas entering `0` runs the loop, sets `has_data` to `true`, and initializes both extrema to `0`.
