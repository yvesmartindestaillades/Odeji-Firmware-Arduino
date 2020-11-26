#include "BluetoothSerial.h"
#include <bt.h>
#include <task.h>

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

#define bt_h

BluetoothSerial SerialBT;

void bt_setup()
{
    SerialBT.begin("ESP32test"); //Bluetooth device name
    Serial.println("The device started, now you can pair it with bluetooth!");
}

void bt_loop(void *pvParameters)
{
    while (1)
    {
        if (SerialBT.available())
        {
            Serial.write(SerialBT.read());
        }
        delay(200);
    }
}