#include <logging.h>

void Logging::critical( const void* ptr, size_t size )
{       
    this->hexDump( LEVEL_CRITICAL, ptr, size );
    return;
}

