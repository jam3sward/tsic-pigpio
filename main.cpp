#include <iostream>
#include "tsic.h"
using namespace std;

int main( int argc, char **argv )
{
    TSIC tsic;
    bool bShowFahrenheit(false);
    char *cvalue = NULL;
    int iGpio = 20;
    int c;

    opterr = 0;
    while ((c = getopt (argc, argv, "hg::f")) != -1)
      switch (c)
        {
        case 'h':
          cout << "TSIC 206/306 temperature sensor application" << endl;
          cout << "  usage:    tsic-temp [arguments]" << endl;
          cout << "   -f    show temperature in Fahrenheit" << endl;
          cout << "   -gN   Read data from GPIO pin N (default is 20)" << endl;
          cout << "   -h    Show this help" << endl;
          return 0;
        case 'f':
          bShowFahrenheit = true;
          break;
        case 'g':
          cvalue = optarg;
        try   {
          iGpio = std::stoi(optarg);
          if (iGpio < 0 || iGpio > 27) {
            throw;
          }
       }
        catch(...) {
          cerr << "GPIO option -g requires an argument between 1 and 27" << endl;
          cerr << "Example: -g24   -- see -h for help." << endl;
          return 1;
        }
          break;
        case '?':
          if (optopt == 'g')
            fprintf (stderr, "Option -%c requires an argument.\n", optopt);
          else if (isprint (optopt))
            fprintf (stderr, "Unknown option `-%c'. Check -h for help\n", optopt);
          else
            fprintf (stderr,
                     "Unknown option character `\\x%x'.\n",
                     optopt);
          return 1;
        default:
          abort ();
        }

      if ( !tsic.open(iGpio) ) {
          cerr << "open failed\n";
          return 1;
      }

      double temp = 0.0;
      if ( !tsic.getDegrees( temp ) )
          cerr << "getDegrees failed\n";

      if  (bShowFahrenheit) {
              temp = temp*1.8 + 32;
      }
      cout << temp << endl;

    tsic.close();

    return 0;
}
