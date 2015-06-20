# Signal

Signaling for bikes.

## Development

This project uses PlatformIO for development.

### Dependencies

1. Install PlatformIO: `pip install platformio && pip install --egg scons`
    * Test: `platformio --version`
1. Install Adafruit NeoPixel library: `platformio lib install 28`

### Install

1. The following will compile the code, download environment parts, and upload to the Arduino Uno: `platformio run`

###

platformio init --board uno

`platformio run` - process/build project from the current directory
`platformio run --target upload` or `platformio run -t upload` - upload firmware to embedded board
`platformio run --target clean` - clean project (remove compiled files)

Neopixel lib: platformio lib install 28

platformio lib update
