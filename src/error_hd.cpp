#include <logging.h>

void Logging::error( const void* ptr, size_t size )
{       
    this->hexDump( LEVEL_ERROR, ptr, size );
    return;
}