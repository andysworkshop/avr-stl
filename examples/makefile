CXX=avr-g++

ARDUINO_DIR=/opt/arduino
ARDUINO_CORE_DIR=/home/gionata/workspace_Arduino/Core/ArduinoCore
PROJECT_DIR=..

# avr tools path
AVR_OBJCOPY=avr-objcopy
AVR_SIZE=avr-size
AVRDUDE=$(ARDUINO_DIR)/hardware/tools/avrdude


# CPU type and speed
MCU=atmega328p
CPU_SPEED=16000000UL

# Arduino USB port for Linux
PORT=/dev/ttyACM0


# Include (dependencies: avr-stl, arduino)
INCLUDE=-I../include -I$(ARDUINO_CORE_DIR)

# Libraries (dependencies: unocore)
LIBS=-L$(ARDUINO_CORE_DIR)/Arduino_Uno -lunocore

# Executable name
TARGET=testSTL

CFLAGS=-Wall -Wno-unused-local-typedefs -Os -fpack-struct -fshort-enums -funsigned-char -funsigned-bitfields\
-fno-exceptions -ffunction-sections -fdata-sections -fno-use-cxa-atexit -mmcu=$(MCU) -DF_CPU=$(CPU_SPEED) \
-MMD -MP -MF"$(OBJ).d" -MT"$(OBJ).d"

CLINKFLAGS=-Wl,-Map,$(TARGET).map,--cref -Wl,-gc-sections -mmcu=$(MCU)

vector: OBJ=test_vector
vector: clean build sizedummy upload

string: OBJ=test_string
string: clean build sizedummy upload

serial: OBJ=test_serial
serial: clean build sizedummy upload

stack: OBJ=test_stack
stack: clean build sizedummy upload

bitset: OBJ=test_bitset
bitset: clean build sizedummy upload

list: OBJ=test_list
list: clean build sizedummy upload

set: OBJ=test_set
set: clean build sizedummy upload

map: OBJ=test_map
map: clean build sizedummy upload

build: $(TARGET).hex

$(TARGET).hex: $(TARGET).elf
	@echo 'Create Flash image (ihex format)'
	$(AVR_OBJCOPY) -R .eeprom -O ihex $< $@
	@echo 'Finished building target: $@'
	@echo ' '

$(TARGET).elf: 
	make -e $(OBJ).o
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C++ Linker'
	$(CXX) $(CLINKFLAGS) $(INCLUDE) $(OBJ).o -o $@ $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '
	
%.o: %.cpp
	$(CXX) $< $(CFLAGS) $(INCLUDE) -c -o $@
	
upload:
	@echo 'Invoking: AVRDude'
	$(AVRDUDE) -C $(AVRDUDE).conf -pm328p -carduino -P$(PORT) -b115200 -Uflash:w:$(TARGET).hex:a
	@echo 'Finished building: $@'
	@echo ' '
	
sizedummy: $(TARGET).elf
	@echo 'Invoking: Print Size'
	$(AVR_SIZE) --format=avr --mcu=$(MCU) $(TARGET).elf
	@echo 'Finished building: $@'
	@echo ' '	
	
clean:
	@echo -n Cleaning ...
	$(shell rm $(TARGET).elf 2> /dev/null)
	$(shell rm $(TARGET).hex 2> /dev/null)
	$(shell rm $(TARGET).map 2> /dev/null)
	$(shell rm *.o 2> /dev/null)
	$(shell rm *.d 2> /dev/null)
	@echo " done"
	
