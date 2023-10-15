# Making Embedded Systems

## Hardware:
Pico Breakboard Kit with 3.5" TFT Capacitive Touch Screen

This is Full Demo Code for Pico Breakboard Kit with 3.5" TFT Capacitive Touch Screen
## TFT Features
* Resolution: 320x480 Pixels
* Screen IC: ST7796SU1
* Input Voltage: 3.3V 
* Touch Type: Capacitive Touch Screen
* TFT screen communication protocol: SPI (SPI0)
* TFT Capacitive touch screen communication protocol: I2C (I2C0 SDA: GP8, SCL: GP9)
## Pinout 
| Components | Pinout|
|---|---|
| Buzzer | GP13 |
| LEDs | D1: GP16, D2: GP17, D3: 3V3, D4: 5V |
| RGB LED| GP12|
| Joystick| X-axis: ADC0, Y-axis: ADC1 
|Button | BTN1: GP15, BTN2: GP14|

### TFT screen Pinout
|Raspberry Pi Pico | 3.5 TFT Screen |
|---|---|
| GP2 | CLK |
| GP3 | DIN |
| GP5 | CS |
| GP6 | DC |
| GP7 | RST |
### Touch Screen Pinout
|Raspberry Pi Pico | Capacitive Touch screen |
|---|---|
| I2C0 SDA GP8 | SDA |
| I2C0 SCL GP9 | SCL |
