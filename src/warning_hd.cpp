#include <logging.h>

void Logging::warning( const void* ptr, size_t size )
{       
    this->hexDump( LEVEL_WARNING, ptr, size );
    return;
}