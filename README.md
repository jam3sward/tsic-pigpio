# tsic-pigpio

This is a simple C++ class for interfacing to the TSIC-306 Digital Temperature Sensor.

Dependencies:

* Requires PIGPIO, which can downloaded from: http://abyz.co.uk/rpi/pigpio
* Uses C++11 features

Basic instructions:

1. Connect up the TSIC sensor with 3V3, GND and the GPIO pin of your choice
2. Edit 'main.cpp' to use the correct GPIO pin number in the open() call
3. Compile and run

Compile and run as follows:

    make
    sudo ./tsic-temp

See also:

* TSIC 306 Kernel Driver: https://github.com/jam3sward/tsic-kernel
