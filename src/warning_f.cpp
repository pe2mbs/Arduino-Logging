#include <logging.h>

void Logging::warning( const __FlashStringHelper* msg )
{       
    log( LEVEL_WARNING, msg );
    return;
}