# USBSerial

This repository contains the source code for a USBSerial class, which provides a simple interface for communicating with a USB serial device in a Linux environment.

## Table of Contents

1. [Features](#features)
2. [Requirements](#requirements)
3. [Installation](#installation)
4. [Usage](#usage)
5. [Project Genesis](#project-genesis)
6. [Roadmap for Enhancements](#roadmap-for-enhancements)
7. [Contributing](#contributing)
8. [License](#license)

## Features

- Open and close a USB serial device
- Set the baud rate
- Check if data is available to read
- Read a single byte or a buffer of bytes
- Write a single byte or a buffer of bytes

## Requirements

- A Linux-based operating system
- A USB serial device

## Installation

1. Clone this repository: `git clone https://github.com/yourusername/USBSerial.git`
2. Navigate to the project directory: `cd USBSerial`
3. The library is header-only, so no build step is required.

## Usage

Here's a simple example of how to use the USBSerial class:

```cpp
#include "USBSerial.h"

int main() {
    USBSerial serial("/dev/ttyUSB0");
    serial.begin(9600);
    uint8_t byte = 'H';
    serial.write(byte);
    serial.end();
    return 0;
}
```

## Project Genesis

The inception of this project was motivated by a challenging endeavor involving the ADuC7061 chip, a component equipped with an ADC Σ-Δ converter. The primary objective was to establish control over this chip via a UART interface. The chip was integrated into a board that also housed an FTDI chip, facilitating USB-to-UART conversion.

Initially, the plan was to communicate with the ADuC7061 exclusively through the UART interface to access and manipulate values within its registers. However, it became apparent that the ADuC7061's embedded ARM7TDMI microprocessor required programming from within.

This project has since proven to be an invaluable tool for future UART communication over USB on Linux devices. It offers a streamlined and user-friendly interface that has become my preferred choice for such tasks.

## Roadmap for Enhancements

Looking ahead, there are plans to augment the interface with additional features, primarily for debugging purposes.

## Bibliography

1. **AN_220** (2017). *FTDI Drivers Installation Guide for Linux*. FTDI Chip.
2. **D2XX** (2023). *D2XX Programmers Guide - Provide API for FTD2XX DLL function library*. FTDI Chip.
3. **FT232R** (2021). *FT232R USB UART IC Datasheet*. FTDI Chip.
4. **Robert Murphy**. *USB 101: An Introduction to Universal Serial Bus 2.0*. Cypress.

## License
GNU GPLv3