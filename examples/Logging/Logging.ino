#include <logging.h>

const char loggerName[] PROGMEM 	= "MAIN";
const char loggerAppName[] PROGMEM 	= "TEST";

Logging logger      = Logging( Serial, LEVEL_ERROR, (const __FlashStringHelper*)loggerName );
Logging logger_app  = Logging( Serial, LEVEL_ERROR, (const __FlashStringHelper*)loggerAppName );


void setup()
{
	Serial.begin( 115200 );
    while ( !Serial ) 
    {
        ; // wait for serial port to connect. Needed for native USB port only
    }
	return;
}

void loop()
{
	uint8_t	hex[ 128 ];
	for( uint8_t i = 0; i< 128; i++ )
	{
		hex[ i ] = i;
	}
	logger.setLevel( LEVEL_DEBUG );
	logger_app.critical( "This is a CRITCAL message" );
	logger_app.error( "This is a ERROR message" );
	logger_app.warning( "This is a WARNING message" );
	logger_app.info( "This is a INFO message" );
	logger_app.debug( "This is a DEBUG message" );

	logger.critical( F( "This is a flash CRITCAL message" ) );
	logger.error( F( "This is a flash ERROR message" ) );
	logger.warning( F( "This is a flash WARNING message" ) );
	logger.info( F( "This is a flash INFO message" ) );
	logger.debug( F( "This is a flash DEBUG message" ) );

	logger.hexDump( LEVEL_INFO, (void const*)hex, sizeof( hex ) );
	delay( 5000 );
	return;
}
