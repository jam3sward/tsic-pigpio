This is a simple C++ class for interfacing to the TSIC-306 Digital Temperature Sensor.

Dependencies:
  * Requires PIGPIO, which can downloaded from: http://abyz.co.uk/rpi/pigpio
  * Uses C++11 features

Basic instructions:
  1. Connect up the TSIC sensor with 3V3, GND and the GPIO pin of your choice
  1. Edit 'main.cpp' to use the correct GPIO pin number in the open() call
  1. Compile and run

Compile and run as follows:
```
make
sudo ./main
```

See also:
  * TSIC 306 Kernel Driver: http://code.google.com/p/tsic-kernel