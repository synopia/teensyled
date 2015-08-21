//
// Created by synopia on 19.08.2015.
//

#ifndef TEENSYCMAKE_NETWORK_H
#define TEENSYCMAKE_NETWORK_H

#include <SPI.h>
#include <Ethernet.h>
#include <EthernetServer.h>
#include <EthernetClient.h>
#include <util.h>
#include <utility/w5100.h>
#include <stdint.h>

#define MAX_PACKET_SIZE (256*8*3)

struct Packet {
    uint8_t id;
    uint8_t width;
    uint8_t height;
    uint8_t buffer[MAX_PACKET_SIZE];
};

/**
 * Manages incoming network data. All data is stored into one buffer. Use structs above, to access data.
 */
class Network {
private:
    EthernetClient client;
    EthernetServer *server = 0;

    Packet packet;
    int remaining;
    uint8_t *current;
public:
    Network(int port);
    void connect();
    void shutdown() {}

    /**
     * Stores incoming data to packet structure. Once a packet is fully received, this method returns the packet
     */
    Packet* update();
    void write(uint8_t data) {

    }
    bool connectionEstablished() {
        return true;
    }
};


#endif //TEENSYCMAKE_NETWORK_H
