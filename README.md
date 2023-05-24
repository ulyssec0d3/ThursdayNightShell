# ThursayNightShell

Welcome to Minishell, a project developed as part of the curriculum at 42 School. Minishell is a simplified shell implementation that allows users to execute basic shell commands, manage processes, and perform other shell-related operations.

## Table of Contents
- [Features](#features)
- [Getting Started](#getting-started)
  - [Prerequisites](#prerequisites)
  - [Installation](#installation)
- [Usage](#usage)
- [Command Overview](#command-overview)
- [Contributing](#contributing)
- [License](#license)

## Features

Minishell offers the following features:

- Execution of shell commands (e.g., `ls`, `cd`, `echo`, etc.)
- Support for built-in commands (e.g., `env`, `export`, `unset`, etc.)
- Simple command execution and process management
- Redirection of input/output streams using `<` and `>`
- Pipelining commands using `|`
- Environment variable expansion
- Error handling and exit codes
- Signal handling (e.g., `Ctrl-C`, `Ctrl-D`, etc.)
- Command history using arrow keys
- Path resolution using `PATH` environment variable
- Quoting and escaping characters
- Line editing with basic line editing capabilities (e.g., arrow keys, backspace)

## Getting Started

To get started with Minishell, follow the instructions below.

### Prerequisites

Minishell has the following prerequisites:

- UNIX-like operating system (e.g., Linux, macOS)
- C compiler (e.g., GCC, Clang)
- GNU Make

### Installation

1. Clone the Minishell repository:

   ```bash
   $ git clone git@github.com:ulyssec0d3/ThursdayNightShell.git
   ```

2. Navigate to the project directory:

   ```bash
   $ cd minishell
   ```

3. Build the project using `make`:

   ```bash
   $ make
   ```

   This will compile the source files and generate the executable `minishell`.

4. Run the Minishell:

   ```bash
   $ ./minishell
   ```

   Now you're ready to use Minishell!

## Usage

Minishell provides a command-line interface where you can enter various shell commands. You can execute standard shell commands, built-in commands, and utilize the various features mentioned in the [Features](#features) section.

Here are a few examples to get you started:

- Execute a standard shell command:
  ```
  $ ls -l
  ```

- Use a built-in command:
  ```
  $ export MY_VAR=Hello
  ```

- Redirect output to a file:
  ```
  $ echo "Hello, World!" > output.txt
  ```

- Pipe commands:
  ```
  $ ls -l | grep myfile
  ```

For more information on available commands and features, refer to the [Command Overview](#command-overview) section.

## Command Overview

Minishell supports a variety of shell commands and features. Here's an overview of the available commands and some key features:

- **Standard Shell Commands**: Minishell supports executing standard shell commands like `ls`, `cat`, `echo`, `mkdir`, `rm`, etc.

- **Built-in Commands**: Minishell provides a set of built-in commands that can be executed directly by the shell, including:
  - `cd`: Change directory
  - `env`: Print environment variables
  - `export`: Set environment variable
  - `unset`: Unset environment variable
  - `exit`: Exit the shell

- **Redirection**: You can redirect input/output streams using `<

` and `>` symbols. For example:
  ```
  $ cat input.txt > output.txt
  ```

- **Pipelining**: Minishell supports piping multiple commands together using the `|` symbol. For example:
  ```
  $ ls -l | grep myfile
  ```

- **Environment Variable Expansion**: Minishell supports expanding environment variables using the `$` symbol. For example:
  ```
  $ echo $HOME
  ```

- **Error Handling**: Minishell provides error handling and returns appropriate exit codes when a command fails.

- **Signal Handling**: Minishell handles signals like `Ctrl-C` and `Ctrl-D` to ensure proper termination and interruption of processes.

- **Command History**: Minishell supports command history, allowing you to navigate through previously entered commands using the arrow keys.

For more detailed information on available commands and their usage, please refer to the project documentation or consult the source code.

## Contributing

Contributions to Minishell are welcome! If you would like to contribute, please follow these steps:

1. Fork the repository.
2. Create a new branch for your feature or bug fix.
3. Make your changes and test thoroughly.
4. Commit your changes with clear and descriptive commit messages.
5. Push your changes to your forked repository.
6. Submit a pull request detailing your changes.

Thank you for contributing to Minishell!

## License

Minishell is open-source software released under the [MIT License](https://opensource.org/licenses/MIT). Feel free to modify and distribute the code as per the terms of the license.
