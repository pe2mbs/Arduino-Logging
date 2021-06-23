#include <logging.h>

Logging::Logging( uint8_t level, const __FlashStringHelper* name ) : stream( Serial )
{
    this->log_level = level;
	this->name = name;
    return;
}

Logging::Logging( Stream& str, uint8_t level, const __FlashStringHelper* name ) : stream( str )
{
    this->log_level = level;
	this->name = name;
    return;
}

void Logging::setLevel( uint8_t level )
{
    this->log_level = level;
    return;
}

uint8_t Logging::getLevel( void )
{
	return ( this->log_level );
}

const __FlashStringHelper* Logging::levelToName( uint8_t level )
{
    if ( level == LEVEL_DEBUG )
    {
        return ( F( "DEBUG" ) );
    }
    if ( level == LEVEL_INFO )
    {
        return ( F( "INFO" ) );
    }
    if ( level == LEVEL_WARNING )
    {
        return ( F( "WARNING" ) );
    }
    if ( level == LEVEL_ERROR )
    {
        return ( F( "ERROR" ) );
    }
    if ( level == LEVEL_CRITICAL )
    {
        return ( F( "CRITICAL" ) );
    }
    return ( F( "NOTSET" ) );
} 

void Logging::logHead( uint8_t level, size_t size )
{
	if ( this->name != NULL )
	{
		this->stream.print( name );
		this->stream.print( " " );
	}
	this->stream.print( levelToName( level ) );
	if ( size > 0 ) 
	{
		this->stream.print( " (" );
		this->stream.print( size );
		this->stream.print( ")" );
	}
	this->stream.print( ": " );
	return;
}

void Logging::log( uint8_t level, const char* msg )
{
    if ( level <= this->log_level )
    {
		this->logHead( level, strlen( msg ) );
        this->stream.print( msg );
        this->stream.print( "\n" );
    }
    return;
}

size_t fstrlen( const __FlashStringHelper *ifsh )
{
  	PGM_P p = reinterpret_cast<PGM_P>( ifsh );
  	size_t n = 0;
  	while ( 1 ) 
	{
    	unsigned char c = pgm_read_byte( p++ );
    	if ( c == 0 ) 
		{
			break;
		}
    	n++;
  	}
  	return ( n );
}

void Logging::log( uint8_t level, const __FlashStringHelper* msg )
{
    if ( level <= this->log_level )
    {
		this->logHead( level, fstrlen( msg ) );
        this->stream.print( msg );
        this->stream.print( "\n" );
    }
    return;
}