# couldBison

Programming language class term project

## Member

## Prerequisites

You must have your compuer installed flex and gcc.

## Tutorial

1. compiling flex file (.l or .lex) using command

```sh
flex -v flex_file_name
```

2. compiling generated c source code using gcc

```sh
gcc lex.yy.c -o <desired_file_name> -ll
```

3. execute your program!

```sh
./<desired_file_name>
```

## Use Tiny

```sh
make
./tiny <source code>
```
