#include "Network.h"
#include "Display.h"

Network *network = 0;
Display *display = 0;

void setup() {
    Serial.begin(9600);
    Serial.print("server is at ");
//    network = new Network(8888);
}

void loop() {
    Serial.print("Blub ");
//    if( !network->connectionEstablished() ) {
//        network->connect();
//    }
//    Packet *packet = network->update();
//    if( packet!=0 ) {
//        uint8_t width = packet->width;
//        uint8_t height = packet->height;
//        if( display!=0 && !display->matchesSize(width, height) ) {
//            delete display;
//            display = 0;
//        }
//        if( display==0 ) {
//             initialize display
//            display = new Display(width, height, packet->buffer);
//        }
//        display->update();
//        network->write(packet->id);
//    }
}