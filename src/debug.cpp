#include <logging.h>


void Logging::debug( const char* msg )
{       
    log( LEVEL_DEBUG, msg );
    return;
}
