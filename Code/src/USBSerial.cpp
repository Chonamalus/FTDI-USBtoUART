#include "USBSerial.h"

USBSerial::USBSerial(const char *device) : fd(-1), isOpen(false) {
    this->device = device;
}

USBSerial::~USBSerial() { this->end(); }

void USBSerial::begin(long baudrate) {
    if (isOpen) {
        return;
    }
    fd = ::open(device, O_RDWR | O_NOCTTY);
    if (fd < 0) {
        perror("Failed to open serial port");
        return;
    }
    struct termios options;
    tcgetattr(fd, &options);
    cfsetispeed(&options, baudrate);
    cfsetospeed(&options, baudrate);
    options.c_cflag |= (CLOCAL | CREAD);
    options.c_cflag &= ~PARENB;
    options.c_cflag &= ~CSTOPB;
    options.c_cflag &= ~CSIZE;
    options.c_cflag |= CS8;
    options.c_lflag &= ~(ICANON | ECHO | ECHOE | ISIG);
    options.c_oflag &= ~OPOST;
    tcsetattr(fd, TCSANOW, &options);
    isOpen = true;
}

void USBSerial::end() {
    if (!isOpen) {
        return;
    }
    ::close(fd);
    isOpen = false;
}

int USBSerial::available() {
    if (!isOpen) {
        return 0;
    }
    uint8_t byte;
    ssize_t n = ::read(fd, &byte, 1);
    if (n <= 0) {
        return 0;
    }
    ::ungetc(byte, stdin); // put the byte back so it can be read again later
    return 1;
}

void USBSerial::read(uint8_t byte) {
    if (!isOpen) {
        return;
    }
    ssize_t n = ::read(fd, &byte, 1);
    if (n <= 0) {
        perror("Failed to read single byte");
        return;
    }
}

void USBSerial::read(uint8_t *buffer, size_t size) {
    if (!isOpen) {
        return;
    }
    ssize_t n = ::read(fd, buffer, size);
    if (n < 0) {
        perror("Failed to read bytes buffer");
        return;
    }
}

void USBSerial::write(uint8_t byte) {
    if (!isOpen) {
        return;
    }
    ssize_t n = ::write(fd, &byte, 1);
    if (n < 0) {
        perror("Failed to write single byte");
        return;
    }
}

void USBSerial::write(uint8_t *buffer, size_t size) {
    if (!isOpen) {
        return;
    }
    ssize_t n = ::write(fd, buffer, size);
    if (n < 0) {
        perror("Failed to write bytes buffer");
        return;
    }
}
