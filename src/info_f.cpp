#include <logging.h>

void Logging::info( const __FlashStringHelper* msg )
{       
    log( LEVEL_INFO, msg );
    return;
}