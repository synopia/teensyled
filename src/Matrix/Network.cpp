//
// Created by synopia on 19.08.2015.
//

#include "Network.h"

Network::Network(int port) {
    server = new EthernetServer(port);
    server->begin();
}

void Network::connect() {
    client = server->available();
}

Packet* Network::update() {
    if( !connectionEstablished() ) {
        return 0;
    }
    int dataAvailable = client.available();
    if( current==0 ) {
        if( dataAvailable>=3 ) {
            client.read((uint8_t*) &packet, 3);
            current = packet.buffer;
            remaining = packet.width*packet.height* 3;
            dataAvailable -= 3;
        }
    }

    if( current!=0 && dataAvailable>0 && remaining>0 ) {
        int read = min(dataAvailable, remaining);
        read = client.read(current, read);
        current += read;
        remaining -= read;
    }

    if( remaining==0 ) {
        current = 0;
        return &packet;
    } else {
        return 0;
    }
}

