#include <logging.h>

void Logging::critical( const __FlashStringHelper* msg )
{       
    log( LEVEL_CRITICAL, msg );
    return;
}

