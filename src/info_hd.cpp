#include <logging.h>

void Logging::info( const void* ptr, size_t size )
{       
    this->hexDump( LEVEL_INFO, ptr, size );
    return;
}