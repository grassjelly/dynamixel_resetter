/*
    Name:       ax12_example.ino
    Created:	01/09/2019 17:39:45
    Author:     Sylvain Gaultier
*/


#include <DynamixelAX12.h>

/*
    This example is supposed to work as-is with Arduino UNO/Mega and Teensy 3.x 
    For other platforms, you may need to change the HardwareSerial used
*/

#if defined ARDUINO_AVR_MEGA2560 || defined ARDUINO_AVR_MEGA || defined ARDUINO_AVR_ADK || defined ARDUINO_AVR_LEONARDO || defined TEENSYDUINO
#define SERIAL_AX Serial1
#define SERIAL_DBG Serial
#define BAUDRATE_DBG 115200
#else
#define SERIAL_AX Serial
#endif

#define AX12_ID 1
#define TARGET_ID 13

#define AX12_BAUDRATE 1000000
OneWireMInterface ax12Interface(Serial1);
DynamixelAX12 ax12(ax12Interface, AX12_ID);

void setup() {
    pinMode(LED_BUILTIN, OUTPUT);
    digitalWrite(LED_BUILTIN, LOW);

    ax12Interface.begin(AX12_BAUDRATE, 20);

    for(int i = 0; i < 254; i++)
    {
        ax12.setId(i);
        delay(100);
        ax12.changeID(TARGET_ID);
        delay(100);

    }

    digitalWrite(LED_BUILTIN, HIGH);
}

void loop()
{
    ax12.goalPositionDegree(0);
}
