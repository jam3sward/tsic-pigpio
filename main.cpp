#include <iostream>
#include "tsic.h"
using namespace std;

int main( int argc, char **argv )
{
    TSIC tsic;

    if ( !tsic.open(24) ) {
        cerr << "open failed\n";
        return 1;
    }

    for (int i=0; i<10; ++i) {
        double temp = 0.0;
        if ( !tsic.getDegrees( temp ) )
            cerr << "getDegrees failed\n";

        cout << "temp = " << temp << endl;
    }

    tsic.close();

    return 0;
}
