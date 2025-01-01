## Getting Start

1. Install CMake (at least version 3.13), and GCC cross compiler

```bash 
sudo apt install cmake gcc-arm-none-eabi libnewlib-arm-none-eabi libstdc++-arm-none-eabi-newlib
```

2. Set up your project to point to use the Raspberry Pi Pico SDK

  * Either by cloning the SDK locally (most common) :

    a. git clone this Raspberry Pi Pico SDK repository

    b. Copy [pico_sdk_import.cmake](https://github.com/raspberrypi/pico-sdk/blob/master/external/pico_sdk_import.cmake) from the SDK into your project directory

    c. Set `PICO_SDK_PATH` to the SDK location in your environment, or pass it (`-DPICO_SDK_PATH=`) to cmake later.

    d. Setup a CMakeLists.txt like:
    ```bash
    cmake_minimum_required(VERSION 3.13)

    # initialize the SDK based on PICO_SDK_PATH
    # note: this must happen before project()
    include(pico_sdk_import.cmake)

    project(my_project)

    # initialize the Raspberry Pi Pico SDK
    pico_sdk_init()

    # rest of your project
    ```

 * Build Projects
```bash
cd pico_breakboard_kit/
mkdir build
cd build/
cmake --no-warn-unused-cli -DPICO_OPTIMIZED_DEBUG=1 -DCMAKE_EXPORT_COMPILE_COMMANDS:BOOL=TRUE -DCMAKE_BUILD_TYPE:STRING=Debug ../
make -j4
```

* Upload firmware to Pico 
Unplug Raspberry Pi Pico from Raspberry Pi and press `boot_sel` button and then connect the Raspberry Pi Pico back to Raspberry Pi.
Execute following command to copy the `*.uf2` file to Pico. 
```bash
cp firmware.uf2 /media/pi/RPI-RP2/
```
After a while, when the firmware has been uploaded to Pico, it will restart automatically, you can test the demo code according to the information on screen. 

Export path 
```
export PICO_SDK_PATH=/home/george/Documents/Pico/pico-sdk 
```

minicom -b 115200 -o -D /dev/ttyS0 
exit 'Ctr-A, then X'
sudo cat /proc/tty/driver/serial