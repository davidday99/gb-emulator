# DGB
DGB is a WIP Gameboy emulator written in C.

## Compiling

There are four different executables available that can be built using Make. Generated executables can be run from the **build** directory.

- *gb-gui*: What you probably want to run. Contains a GUI for viewing and interacting with the GameBoy and whatever ROM is loaded.

- *gb-cli*: Similar to gb-gui but without the GUI. Prints out a byte array representation of the LCD every time the scan line reaches the bottom of the screen. Useful for debugging.

- *sim*: Simulator for a standalone SM83 CPU, controllable through command line. Provides various options for stepping through instructions, dumping memory, and viewing the CPU state.

- *test*: Test suite for testing each of the opcodes the SM83 supports. The tests aren't exhaustive, and it would be wise to look more into potential sign-extension and flag-setting bugs. The test runner is executed automatically when built.

Run *make all* to generate all of these at once.

## Dependencies

- GTK+ 3 (GUI)

## Misc

- Run *make* with the additional argument *debug=1* to print each instruction to stdout as it executes.