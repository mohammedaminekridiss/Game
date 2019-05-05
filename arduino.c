


#include "header.h"

struct sp_port *serialPort = NULL;

int Arduino_connect(const char *serialPortName, int baudrate)
{
    struct sp_port_config *serialPortConfiguration;
    enum sp_return r;

    if(serialPort) sp_free_port(serialPort);

    // Find the specified serial port
    if(sp_get_port_by_name(serialPortName, &serialPort) != SP_OK)
    {
        fprintf(stderr, "Cannot find the serial port\n");
        return 0;
    }

    // Open the serial port
    if(sp_open(serialPort, SP_MODE_READ_WRITE) != SP_OK)
    {
        fprintf(stderr, "Cannot open the serial port\n");
        return 0;
    }

    // Configure the serial port
    sp_new_config(&serialPortConfiguration);
    sp_set_config_baudrate(serialPortConfiguration, 9600);
    sp_set_config_parity(serialPortConfiguration, SP_PARITY_NONE);
    sp_set_config_bits(serialPortConfiguration, 8);
    sp_set_config_stopbits(serialPortConfiguration, 1);
    sp_set_config_flowcontrol(serialPortConfiguration, SP_FLOWCONTROL_NONE);

    if(sp_set_config(serialPort, serialPortConfiguration) != SP_OK)
    {
        fprintf(stderr, "Cannot configure the serial port\n");
        return 0;
    }

    sp_free_config(serialPortConfiguration);

    return 1;
}

int Arduino_read(void *buffer, size_t bufferSize)
{
    if(!serialPort) return 0;
    return sp_nonblocking_read(serialPort, buffer, bufferSize);
}

int Arduino_write(const void *buffer, size_t bufferSize)
{
    if(!serialPort) return 0;
    return sp_nonblocking_write(serialPort, buffer, bufferSize) == SP_OK;
}

void Arduino_disconnect()
{
    if(serialPort)
    {
        // Close the serial port
        sp_close(serialPort);
        sp_free_port(serialPort);
        serialPort = NULL;
    }
}
