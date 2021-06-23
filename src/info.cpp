#include <logging.h>

void Logging::info( const char* msg )
{       
    log( LEVEL_INFO, msg );
    return;
}