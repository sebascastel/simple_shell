[![Build Status](https://travis-ci.org/joemccann/dillinger.svg?branch=master)](https://travis-ci.org/joemccann/dillinger)
# Simple_Shell Project
<a name="top"></a>
# SHELL'S BELLS ! :fire: :fire:
Welcome to the `Robert-Martin Simple Shell Project` this shell can be compiled and run from the command line, it includes basic features, as well as some advanced features found in most shell programs.

## Table of contents
* [Quick Start](#item1)
* [Syntax](#item2)
* [Example Usage](#item3)
* [Builtins](#item4)
* [Files](#item5)
 
<a name="item1"></a>
### Quick Start
 - git clone this repository to your local machine.
 ```sh
 $ git clone https://github.com/sebascastel/simple_shell
 ```
 - `cd` into `simple_shell/` directory. 
```sh
$ cd simple_shell/
```
 - Compile the program.
```sh 
 $ gcc -Wall -Werror -Wextra -pedantic *.c -o hsh
```
or
```sh
$ make 
```
- Execute the Shell's Bells !
```sh
$ ./hsh
```
Note: **Shell's Bells** can also be run in non-interactive mode:
```sh
$ echo "/bin/ls" | ./hsh
```

<a name="item2"></a>
### Syntax
This Shell, has a familiar syntax when running commands, as other common Shells:
 ```s
 †Shell's Bells† <command> <flags>
 ```
 
 - non-interactive mode:
 ```sh
 $ echo "<command>" | ./hsh
 ```
 <a name="item3"></a>
 ### Example Usage
 interactive mode
  - `ls` command:
 ```s
 †Shell's Bells† ls -1
 ``` 
 - `pwd`command:
 ```s
 †Shell's Bells† pwd
 ``` 
 - `cd` command:
 ```s
 †Shell's Bells† cd ..
 ``` 
 - `help` command:
 ```s
 †Shell's Bells† help <builtin command>
 ``` 
 - `# comments`
  ```s
 †Shell's Bells† echo Hello # World
 Hello
 ``` 
 <a name="item4"></a>
### Builtins

Our Shell supports a variety of builtin commands:  

`exit` - exits the Shell  

`env` - prints the environment variables.  

`setenv` - sets an environment variable.  

`unsetenv` - unsets an environment variable.  

`cd` - changes directory.  

`help` - displays help for builtin commands.  

#### Bonus
`welcome` - displays a welcome message :smile:  

`bart` - shows Bart Simpson :smile:
 
  <a name="item5"></a>
### Files

A short description of every file used in this project.

| File Name | Description   | 
|---- | ------------ | 
| **AUTHORS**  | file containing the **contributing authors**    | 
| **README.md**  | readme file explainig wht this project is about  |
| `_getline.c`  | implementation of getline function |
| `_help.c` | implementation of builtin `help` function          |
| `_realloc.c` | `realloc` reallocates memory          |
| `_strcat.c` | function that concatenates three strings          |
| `_strcmp.c` | compares two strings          |
| `_strcpy.c` | copies the string pointed by `src` to pointer `dest`        |
| `_strdup.c` | duplicates a string          |
| `_strtok.c` | implemetation of builtin `strtok` function          |
| `add_node_end.c` | adds a new node at the end of a linked list         |
| `bart.c` | builtin function that prints bart          |
| `bart.txt` | text file which contains `ASCII` bart          |
| `cd.c` | implementation of `cd` builtin function          |
| `ch_pwd.c` | changes current working directory
| `colors.c` | a set of colors used to bring to life our `Shell` :boom: |
| `colors_2.c` | another set of colors       |
| `cp_env.c` | makes a copy of the environment variables        |
| `create_arg_list.c` | takes the input buffer and creates argument list    |
| `delete_node_ind.c` | deletes a node at a given index   |
| `error.c` | writes error message to standard output    |
| `exec.c` | forks and execute command |
| `exit_built.c` | builtin `exit` function    |
| `free_list.c` | frees memory for linked lists  | 
| `handler.c` |  handles the `ctrl-c` key to keep looping |
| `help_options.c` | a collection of helper builtin functions    |
| `holberton.h` | header file    |
| `not_builtin.c` | core function of our Shell :joy:    |
| `path.c` | searches the correct path of command and concatenates the path with '/' and command   |
| `perm.c` | checks permisions |
| `print_env.c` | builtin function of `env` prints the environment|
| `search_env.c` | searches for the environment string pointed to by name |
| `set.c` | sets or updates environment variable builtin `setenv` function |
| `shell.c` | main fucntion of our `†Shell's Bells†` shell |
| `split.c` | takes a string and splits it into key value pair |
| `struct_builtin.c` | function to find builtins functions |
| `to_str.c` | converts an integer into a string |
| `unset.c` |  removes environment variable builtin `unsetenv` function |
| `welcome.c` | builtin function that prints welcome message |
| `welcome.txt` | text file which contains `ASCII` welcome message |


[Back to Top](#top)

#### AUTHORS 
This project was created by -  [Robert Castellanos](https://github.com/sebascastel) and [Andres Martin](https://github.com/andres-martin) at Holberton School Colombia cohort 0.
 
