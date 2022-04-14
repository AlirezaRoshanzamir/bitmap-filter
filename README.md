# Description
Educational project for reading, filtering and writing bitmap images using C++ language.

I did this project in the second semester of university to learn "vector" and "reference" in C++. In this project, it reads a bitmap image of the standard input and according to the argument input, it does the graying and horizontal flipping filters on it and writes it in the standard output.

# Compilation

```
make out
```

# Usage

Graying:

```
./out 1 < input.bmp > output.bmp
```

Horizontal flipping:

```
./out 2 < input.bmp > output.bmp
```
