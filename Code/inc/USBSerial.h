#pragma once

#include <fcntl.h>
#include <iostream>
#include <stdint.h>
// #include <string.h>
#include <termios.h>
#include <unistd.h>

class USBSerial {
  public:
    USBSerial(const char *device);
    ~USBSerial();
    void begin(long baudrate);
    void end();
    int available();
    void read(uint8_t byte);
    void read(uint8_t *buffer, size_t size);
    void write(uint8_t byte);
    void write(uint8_t *buffer, size_t size);

  private:
    int fd;
    bool isOpen;
    const char *device;
};
