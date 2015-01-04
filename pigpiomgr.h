#ifndef __pigpiomgr_h
#define __pigpiomgr_h

//-----------------------------------------------------------------------------

#include <iostream>
#include "pigpio.h"

//-----------------------------------------------------------------------------

/// Singleton class to manage initialisation of PIGPIO
class PIGPIOManager {
public:
    /// Returns the single instance
    static PIGPIOManager & get();

    /// Returns true if PIPGIO is available
    bool ready() const;

    /// Returns the PIGPIO version number
    int version() const;

private:
    /// Constructor
    PIGPIOManager();

    /// Destructor
    ~PIGPIOManager();

    int m_version;  ///< PIGPIO version number (or PI_INIT_FAILED)
};

//-----------------------------------------------------------------------------

inline PIGPIOManager & PIGPIOManager::get() {
    static PIGPIOManager instance;
    return instance;
}

//-----------------------------------------------------------------------------

inline bool PIGPIOManager::ready() const {
    return (m_version != PI_INIT_FAILED);
}

//-----------------------------------------------------------------------------

inline int PIGPIOManager::version() const {
    return ready() ? m_version : 0;
}

//-----------------------------------------------------------------------------

inline PIGPIOManager::PIGPIOManager()
{
    m_version = gpioInitialise();
}

//-----------------------------------------------------------------------------

inline PIGPIOManager::~PIGPIOManager()
{
    gpioTerminate();
}

//-----------------------------------------------------------------------------

#endif//__pigpiomgr_h

