# DGBE
DGBE is a WIP Gameboy emulator written in C.

## Compiling

There are four different executables available that can be built using Make. Resulting executables can be run from the **build** directory.

- *make gb-gui*: What you probably want to run. Contains a GUI for viewing and interacting with the GameBoy and whatever ROM it's running.

- *make gb-cli*: Similar to gb-gui but without the GUI. Prints out a byte array representation of the LCD every time the scan line reaches the bottom of the screen. Useful for debugging.

- *make sim* (default): Simulator for a standalone SM83 CPU, controllable through command line. Provides various options for stepping instructions, dumping memory, and viewing the CPU state.

- *make test*: Test suite for testing each of the opcodes the SM83 provides. The tests aren't exhaustive, and it would be wise to look more into potential sign-extension and flag-setting bugs. The test runner will be executed automatically when built.

## Dependencies

- GTK+ 3 (GUI)

## Misc

- Run *make* with the argument *debug=1* to print each instruction to stdin as it executes.