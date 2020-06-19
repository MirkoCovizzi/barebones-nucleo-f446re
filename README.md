# barebones-nucleo-f446re

Barebones project template for the **STM32F446RE** using **CMake**. It doesn't contain any HAL dependency. Useful for who likes to write
their own HAL from scratch using the microcontroller documentation. It is fully compatible with **CLion**.

* `/documentation` contains the datasheet and the reference

* `/examples/button_blinky.c` is a simple example that uses low level abstraction for button and LED interaction

# Installation Requirements

* [GNU Arm Embedded Toolchain](https://developer.arm.com/tools-and-software/open-source-software/developer-tools/gnu-toolchain/gnu-rm/downloads)

* [OpenOCD](https://xpack.github.io/openocd/)
