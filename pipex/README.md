# Pipex

Pipex is a project that simulates the behavior of the shell pipe (`|`). It takes two commands and executes them in a way that the output of the first command is passed as input to the second command.

## Table of Contents

- [Installation](#installation)
- [Usage](#usage)
- [Project Structure](#project-structure)
- [Functions](#functions)
- [License](#license)

## Installation

To build the project, navigate to the project directory and run `make`:

```sh
cd /home/thaer/Desktop/42journey/pipex
make
```

This will compile the source files and create the `pipex` executable.

## Usage

To use the `pipex` program, run it with the following syntax:

```sh
./pipex file1 cmd1 cmd2 file2
```

- `file1`: The input file.
- `cmd1`: The first command to execute.
- `cmd2`: The second command to execute.
- `file2`: The output file.

Example:

```sh
./pipex infile "ls -l" "grep pipex" outfile
```

This will execute `ls -l` on `infile`, pipe the output to `grep pipex`, and write the result to `outfile`.

## Project Structure

- `pipex.h`: Header file containing function prototypes and the `t_cmd` structure.
- `pipex.c`: Main file containing the `main` function and the `open_files` and `get_path` functions.
- `end_process.c`: Contains functions for error handling and resource cleanup.
- `child_process.c`: Contains functions for creating child processes and executing commands.
- `Makefile`: Makefile for building the project.

## Functions

- `open_files(t_cmd *cmd, char **argv)`: Opens the input and output files.
- `get_path(char **env, t_cmd *cmd)`: Retrieves the PATH environment variable.
- `get_command(char **cmd_path, char *cmd)`: Finds the full path of a command.
- `create_child1(t_cmd *cmd, char **argv, char **env)`: Creates the first child process.
- `create_child2(t_cmd *cmd, char **argv, char **env)`: Creates the second child process.
- `child1(t_cmd *cmd, char **argv, char **env)`: Executes the first command in the first child process.
- `child2(t_cmd *cmd, char **argv, char **env)`: Executes the second command in the second child process.
- `error_message(char *message, t_cmd *cmd)`: Prints an error message and exits.
- `child_free(t_cmd *cmd)`: Frees resources allocated for the child processes.
- `parent_free(t_cmd *cmd)`: Frees resources allocated for the parent process.
- `close_command(t_cmd *cmd)`: Closes file descriptors and pipes.
- `error_process(char *message, t_cmd *cmd)`: Handles errors during process creation.

## License

This project is licensed under the MIT License.