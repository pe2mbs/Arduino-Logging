#include <logging.h>

void Logging::critical( const char* msg )
{       
    log( LEVEL_CRITICAL, msg );
    return;
}

