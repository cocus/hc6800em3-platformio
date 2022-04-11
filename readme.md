# Project information
This is a port and translation of the original C examples provided in Chinese on the DVD that comes with the hc6800em3 kit to a PlatformIO project. These C code examples are the ones used on the 8051 MCU (STC 90C516RD+).

The examples have categories, ranging from easy experiments to quite advanced functions.

Original code provided by Prechin, the creators of this development kit, used Keil's C51 IDE and compiler. This codebase uses PlatformIO with the MCS51 platform toolchain. It doesn't require any additional applications to load the code to the board, since `stcgal` is used to load and flash the programs on the STC MCU via a serial port.

# How to use this project
1. Install Visual Studio Code from [the official site](https://code.visualstudio.com/download).
2. Install PlatformIO extension into Visual Studio Code, following [these official instructions](https://platformio.org/install/ide?install=vscode).
3. Install the MCS-51 platform on the PlatformIO Home (PlatformIO Home -> Platforms -> "Embedded" tab -> search for mcs-51 and install).
4. Either clone this repository or download the zipped version and unzip it to a specific directory (without spaces on its path).
5. Open the directory from Visual Studio Code.
6. Select the PlatformIO icon on the bar, and exapnd the node with the example you want to load, for instance `leds-marquee`, then hit `Upload`. PlatformIO will select the appropriate serial port. If that doesn't work, add the [`upload_port` on the `[env]` section of platformio.ini](https://docs.platformio.org/en/stable/projectconf/section_env_upload.html#upload-port) stating the device you want to use. Once you see `Cycling power: done` on the console, power-cycle the development kit so `stcgal` is able to flash the STC MCU. The reset key/button doesn't work for this, you need to do a full power-cycle.
7. Check on the example category directory under the `src` directory for the wiring diagram and wiring instructions.

# Resources
1. [HC6800EM3 SourceForge](https://sourceforge.net/p/hc6800em3/wiki/Home/#start) project, maintained by mgruber.
2. [MCS51 PlatformIO GitHub](https://github.com/platformio/platform-intel_mcs51).
3. [STC micro 90C516RD+ Datasheet](https://www.stcmicro.com/datasheet/STC90C51RC-en.pdf).

# Examples
## 1 - LEDs
1. Blinking: Toggles all the pins of the Port0 each 500ms.
2. Binary Adder: Outputs an incrementing binary number on the pins of the Port0.
3. Light Water: "Progress bar"-like effect on the 8 pins of the Port0.
4. Marquee: Shifts a fixed pattern from right to left.
5. Marquee2: Same as `Marquee` but using a different code approach.