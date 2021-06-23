#include <logging.h>

void Logging::error( const __FlashStringHelper* msg )
{       
    log( LEVEL_ERROR, msg );
    return;
}