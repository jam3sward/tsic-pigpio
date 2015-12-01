# tsic-pigpio

This is a simple C++ class for reading values from TSIC 206 & TSIC 306 digital temperature sensors.

**Dependencies**

* Requires PIGPIO
  * Download from: http://abyz.co.uk/rpi/pigpio
  * Extract, ``make && make install`` on your system
* Uses C++11 features

**Basic instructions**

Connect up the TSIC sensor with 3V3, GND and the GPIO pin of your choice, then compile and run as follows:

    make
    sudo ./tsic-temp -h         # get help
    sudo ./tsic-temp -g20       # -g specifies that the sensor is connected to GPIO20, change accordingly!
    
 Optional: install system-wide
 
    sudo make install
    sudo tsic-temp
    
 Uninstall:
 
    sudo make distclean

See also:

* TSIC 306 Kernel Driver: https://github.com/jam3sward/tsic-kernel
