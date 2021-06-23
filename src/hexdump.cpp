#include <Arduino.h>
#include <logging.h>

#define BYTES_PER_ROW	16

// void hexDump( uint8_t level, const void* buff, size_t len, uint8_t base = 0 );
void Logging::hexDump( uint8_t level, const void* buff, size_t len, uint8_t base )
{
	if ( level <= this->log_level )
    {
		uint8_t* p = reinterpret_cast<uint8_t*>( const_cast<void*>( buff ) );
		const size_t rows = ( len + BYTES_PER_ROW - 1 ) / BYTES_PER_ROW;
		for ( size_t r = 0; r < rows; ++r )
		{
			// Print the memory offset
			this->logHead( level, 0 );
			this->printHex<uint16_t>( base + p - reinterpret_cast<uint8_t*>( const_cast<void*>( buff ) ) );
			this->stream.print( F( ": " ) );
			char* pc = reinterpret_cast<char*>( p );
			const size_t cols = len < BYTES_PER_ROW ? len : BYTES_PER_ROW;
			// Print the HEX line
			for ( size_t c = 0; c < BYTES_PER_ROW; ++c )
			{
				if ( c < cols )
				{
					this->printHex<uint8_t>( *p++ );
				}
				else
				{
					this->stream.print( F( " " ) );
				}
				this->stream.print( F( " " ) );
			}
			this->stream.print( F( " " ) );
			yield();
			// Print the ASCII part
			for ( size_t i = 0; i < cols; ++i )
			{
				char c = *pc++;
				if ( c >= ' ' ) 
				{
					this->stream.print( c );
				}
				else
				{          
					this->stream.print( '.' );
				}
			}
			this->stream.println( F( "" ) );
			len -= BYTES_PER_ROW;
			yield();
		}
	} 
	return;
}

template <typename valueT> void Logging::printHex( const valueT val )
{
    const uint8_t digits = sizeof( valueT ) << 1;   
    for ( uint8_t i = 0; i < digits; i++ )
    {
		// Each nibble stores 1 digit
        valueT v = ( val >> ( ( digits - i - 1 ) << 2 ) ) & valueT( 0x0F );     
        this->stream.print( v, HEX );
    }
    return;
}
