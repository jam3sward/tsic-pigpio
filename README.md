# tsic-pigpio

This is a simple C++ class for interfacing to the TSIC-306 Digital Temperature Sensor.

Dependencies:

* Requires PIGPIO
  * Download from: http://abyz.co.uk/rpi/pigpio
  * Extract, ``make && make install`` on your system
* Uses C++11 features

Basic instructions:

1. Connect up the TSIC sensor with 3V3, GND and the GPIO pin of your choice
2. Edit 'main.cpp' to use the correct GPIO pin number in the open() call
3. Compile and run

Compile and run as follows:

    make
    sudo ./tsic-temp -h         # Get Help
    sudo ./tsic-temp -g20       # -g defines that the sensor is connected to GPIO20
    
 Optional: install system-wide
 
    sudo make install
    sudo tsic-temp
    
 Uninstall:
 
    sudo make distclean

See also:

* TSIC 306 Kernel Driver: https://github.com/jam3sward/tsic-kernel
