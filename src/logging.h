#ifndef __LOGGING_H__
#define __LOGGING_H__
#include <Arduino.h>

#define LEVEL_DEBUG         50
#define LEVEL_INFO          40
#define LEVEL_WARNING       30
#define LEVEL_ERROR         20
#define LEVEL_CRITICAL      10
#define LEVEL_NOTSET        0

class Logging
{
private:
    uint8_t log_level;
	Stream&	stream;	
	const __FlashStringHelper* name;
public:
    Logging( uint8_t level = LEVEL_NOTSET, const __FlashStringHelper* name = NULL );
	Logging( Stream& str, uint8_t level = LEVEL_NOTSET, const __FlashStringHelper* name = NULL );
    void setLevel( uint8_t level );
	uint8_t getLevel( void );
    const __FlashStringHelper* levelToName( uint8_t level );
    void log( uint8_t level, const char* msg );
	void log( uint8_t level, const __FlashStringHelper* msg );

    void critical( const char* msg );
    void critical( const __FlashStringHelper* msg );
	void critical( const void* ptr, size_t size ) ;

    void error( const char* msg );
    void error( const __FlashStringHelper* msg );
	void error( const void* ptr, size_t size ) ;

    void warning( const char* msg );
    void warning( const __FlashStringHelper* msg );
	void warning( const void* ptr, size_t size ) ;

    void info( const char* msg );
    void info( const __FlashStringHelper* msg );
	void info( const void* ptr, size_t size ) ;

    void debug( const char* msg );
    void debug( const __FlashStringHelper* msg );
	void debug( const void* ptr, size_t size ) ;

	void hexDump( uint8_t level, const void* buff, size_t len, uint8_t base = 0 );
protected:
	template <typename valueT> void Logging::printHex( const valueT val );
	void logHead( uint8_t level, size_t size );
};

#endif
