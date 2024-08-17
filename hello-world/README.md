# Exercise 01: Hello, World!

## 📝 Description

This exercise involves creating a simple function that returns the string "Hello, World!". The main goal is to ensure that the function behaves as expected by comparing the returned string to the expected output.

## 🛠️ Solution Overview

The solution consists of implementing the function `hello()` that returns the string "Hello, World!". To validate the solution, a custom string comparator function, `string_test()`, is used. This function compares the returned string to the expected string, checking for any discrepancies.

### Key Points:
- **String Comparison**: Two approaches are used to compare the strings:
  1. **Fixed-Length Comparison**: Compares the first 13 characters directly.
  2. **Null-Terminated Comparison**: Compares the entire string up to the null terminator `\0`.

- **Test Output**: The program outputs whether the test passed or failed, and in case of failure, it provides details about where the mismatch occurred.

## 📂 File Structure

- `hello_world.h`: Header file containing the declaration of the `hello()` function.
- `hello_world.c`: Implementation file containing the definition of the `hello()` function.
- `main.c`: The main file where the test logic is implemented and executed.
- `Makefile`: Custom Makefile to automate the build process.

## 📋 How to Build and Run

1. **Build the program** using the provided `Makefile`:
   ```
   make
   ```

2. **Run the program**:
   ```
   make run
   ```

3. The program will output whether the test passed or failed. If it failed, it will show where the mismatch occurred.

### Build with Entire String Flag

If you want to compile the program to compare the entire string using the null terminator `\0`, use:
```
make entire-string-flag
```

Then, run the program:
```
make run
```

## 📜 Makefile Overview

- **CC**: The compiler to use (gcc).
- **CFLAGS**: Compilation flags, including `-Wall` for all warnings and `-g` for debugging information.
- **PROGRAM**: The output executable name.
- **OBJS**: Object files needed to build the program.

### Makefile Targets
- **all**: Default target to build the program.
- **entire-string-flag**: Compiles the program with the `ENTIRE_STRING` flag enabled.
- **run**: Executes the compiled program.
- **clean**: Removes object files.
- **purge**: Cleans and removes the compiled executable.

## 🧪 Example Output

If the test passes:
```
Test passed: Hello, World!
```

If the test fails:
```
Test failed!
Expected: Hello, World!
Got: Hello World!
Mismatch at index 5
Mismatched characters: ' ' != 'W'
```

## 🔗 Notes

- The first comparison method (`#ifndef ENTIRE_STRING`) focuses on the first 13 characters, which is the exact length of "Hello, World!".
- The second comparison method (`#ifdef ENTIRE_STRING`) validates the entire string based on the null terminator.

