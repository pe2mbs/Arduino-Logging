#include <logging.h>


void Logging::debug( const __FlashStringHelper* msg )
{       
    log( LEVEL_DEBUG, msg );
    return;
}
