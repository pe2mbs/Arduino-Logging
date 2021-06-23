# Arduino-Logging
This library implements a simple but effective logging interface. 

## Building the library
First you need to clone the repository

    # git clone https://github.com/pe2mbs/Arduino-Logging.git

    # python build-package.py


Now in ARDUINO ide 
    > select Scetch > Include library >  Add .ZIP library 
    > Find the folder where the repository is and step into the build folder
    > select logging.zip


## Using the library
To setup a logger, simply instanciate the Logging class with/without paramaters.  
The following defines a logger on the Serial device, with level set to NOTSET.

	Logging	logger = Logging();

Next defines a logger on the Serial device, with level set to LEVEL_WARNING

	Logging	logger = Logging( LEVEL_WARNING );

Next defines a logger on a device (Serial) with level set to LEVEL_INFO and also a name

	const char logName[] PROGMEM = "MAIN";
	Logging	logger = Logging( Serial, LEVEL_INFO, logName );

To change to log level runtime, simply call

	logger.setLevel( LEVEL_DEBUG );

This sets the highest logging level.

To log a message to to logger can be done via the common functions log() abnd hexDump() or the specific functions critical(), error(), warning(), info() and debug(). 

### Common log functions
The common function log() uses two parameters, first the level and second the message.
Both flash and RAM pointers are accepted. 

	logger.log( LEVEL_INFO, "This is a RAM message" );

	logger.log( LEVEL_INFO, F( "This is a FLASH message" ) );

The common function hexDump() user three paramaters first the level and second the pointer to the block of memory to dump and third the length of the block.

	logger.hexDump( LEVEL_DEBUG, some_pointer, some_length );

### Specific log functions
All the specific functions have the same calling interface. 

	logger.error( "This is a RAM message" );

This logs a error message from RAM.

	logger.error( F( "This is a FLASH message" ) );

This logs a error message from FLASH.

	logger.error( some_pointer, some_length )

This logs a error hex dump.

## Speed and size
Using the logging specific functions shall increase the FLASH size for each function, as they are separated the compiler/linker shall include them when required. Those specific functions are some instructions slower. Each functions uses 13 bytes of flash memory, therfore the break even point is 13 calls to a specific function.


## Example
In the menu File->Examples->Logging the example log_example.ino can be found. 

## API

### constructors
    Logging( uint8_t level = LEVEL_NOTSET, const __FlashStringHelper* name = NULL );
	Logging( Stream& str, uint8_t level = LEVEL_NOTSET, const __FlashStringHelper* name = NULL );

### set and get level	
    void setLevel( uint8_t level );
	uint8_t getLevel( void );

### common log 
    void log( uint8_t level, const char* msg );
	void log( uint8_t level, const __FlashStringHelper* msg );

### critical log 
    void critical( const char* msg );
    void critical( const __FlashStringHelper* msg );
	void critical( const void* ptr, size_t size ) ;

### error log 
    void error( const char* msg );
    void error( const __FlashStringHelper* msg );
	void error( const void* ptr, size_t size ) ;

### warning log 
    void warning( const char* msg );
    void warning( const __FlashStringHelper* msg );
	void warning( const void* ptr, size_t size ) ;

### info log 
    void info( const char* msg );
    void info( const __FlashStringHelper* msg );
	void info( const void* ptr, size_t size ) ;

### debug log 
    void debug( const char* msg );
    void debug( const __FlashStringHelper* msg );
	void debug( const void* ptr, size_t size ) ;

### hex dump
	void hexDump( uint8_t level, const void* buff, size_t len, uint8_t base = 0 );

### helper
    const __FlashStringHelper* levelToName( uint8_t level );
