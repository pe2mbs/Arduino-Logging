#include <logging.h>


void Logging::debug( const void* ptr, size_t size )
{       
    this->hexDump( LEVEL_DEBUG, ptr, size );
    return;
}
