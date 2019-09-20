### Moved to: https://gitlab.com/simoesusp/ESP32_Projects


# ESP32_Projects
Colection of ESP32 software and hardware

To install ESP32 Board into the Arduino IDE do the following (addapted from: https://randomnerdtutorials.com/installing-the-esp32-board-in-arduino-ide-windows-instructions/):

1) Open the preferences window from the Arduino IDE. Go to File> Preferences

2) Enter https://dl.espressif.com/dl/package_esp32_index.json into the “Additional Board Manager URLs” field

3) Open boards manager. Go to Tools > Board > Boards Manage and Search for ESP32 and press install button for the “ESP32 by Espressif Systems“:

4) Select your Board in Tools > Board menu > DOIT ESP32 DEVKIT V1

5) Select the Port
--> if you don’t see the COM Port in your Arduino IDE, you need to install the ESP32 CP210x USB to UART Bridge VCP Drivers (I did not needed to do this!!)

6) Open an example under File > Examples and test the instalation --> Good Luck!!!!!

I GOT A PROBLEM!!!! --> In my Ubuntu, it did not compile (Error: import serial.tools.list_ports as list_ports)

    --> it needed: python-serial

    --> just install it with: sudo apt install python-serial

---------------x--------------------x------------------

WARNINGS:

0) ESSA PLACA RESETA QUANDO PROGRAMA... SOMENTE NO TERMINAL TEM QUE APERTAR O BOTAOZINHO DA ESQUERDA DO CABO USB

1) Led pin is now 2

2) Led turn on with 1, not with 0 as ESP8266 (They finally fix that stupidity!!)

3) Digital pins are Written in the board, just use it as D15 ==> 15 (did not test all of them!!)

4) Analog pins tested so far: 36 and 39 are working!  15 and 13 ARE NOT working!!

