#include <logging.h>

void Logging::error( const char* msg )
{       
    log( LEVEL_ERROR, msg );
    return;
}