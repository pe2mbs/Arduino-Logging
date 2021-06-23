#include <logging.h>

void Logging::warning( const char* msg )
{       
    log( LEVEL_WARNING, msg );
    return;
}