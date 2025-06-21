# ESP32 MQTT Setup Guide

## Hardware Requirements
- **ESP32 microcontroller**
- **Micro-USB cable** (data cable to connect laptop to ESP32)

## Software Setup

### 1. Install Arduino IDE
Install the Arduino IDE successfully on your system.

### 2. Get Code Editor
Install a code editor, generally **VS Code**.

### 3. Repository Setup
Either clone the repository or study the code and make changes in your system by copy-pasting files.

### 4. Create Project Directory
Create one working directory on the terminal named as **`MQTT_basics`**

### 5. Save Python File
Save the python file in your working directory.

## Arduino IDE Configuration

### 6. Open Arduino IDE
Launch the Arduino IDE application.

### 7. Board Selection
Search for the **ESP32 DEVKIT module** as the board on top-left corner of the home page of IDE. Also find the port option in **Tools → Port → COM5/6** (it will auto detect).

### 8. Library Installation
Search for the library **PicoMQTT by Michal Lesniewski** and install it.

### 9. Upload Code
Run the code file on this repository with **.ino extension**.

### 10. Serial Monitor Setup
- Open the Serial Monitor by pressing **Ctrl+Shift+M**
- Set baud rate to **115200** (otherwise you will get some garbage value)

### 11. WiFi Credentials
Provide with the WiFi credentials:
- Your WiFi name is your **`#define MyWiFi`**
- Password is the password you enter while connecting to that hotspot

### 12. Upload Successfully
Complete the upload process to your ESP32.

## MQTT Broker Configuration

### 13. ESP32 as MQTT Broker
Now you have set-up the ESP32 as a remote MQTT broker. You don't need to use any external public broker for IoT related tasks.

### 14. Get ESP32 IP Address
See with what IP your ESP32 is connected to, as visible on the serial monitor.

### 15. Python Code Configuration
- Add that IP in your python code as **`broker_address`**
- Remember to keep the **`broker_port`** as **1883**, not any other number, as the MQTT broker running on ESP32 is open on port 1883 by default in the library PicoMQTT

## LED Control Implementation

### 16. Edit Callback Function
Try editing the callback function inside `mqtt.subscribe` function to blink an LED light and print the status on the serial monitor by following these hints:

1. **Setup GPIO Pin**: First inside the setup, set a pinMode to any GPIO pin as OUTPUT

2. **Python Code Modification**: Edit the python code to send once the string 'ON' then `time.delay(1)`, then send 'OFF'

3. **Conditional Logic**: Apply the conditional if-else statement in the callback function, to print on serial the LED status and then digitalWrite the LED_pin as HIGH or LOW

## Advanced Implementation

You can experiment with more deeper execution of the code by using only **`<WiFi.h>`** and **`<MQTT.h>`** libraries, coming soon!!
