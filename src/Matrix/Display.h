//
// Created by synopia on 19.08.2015.
//

#ifndef TEENSYCMAKE_DISPLAY_H
#define TEENSYCMAKE_DISPLAY_H


#include <stdint.h>
#include <SPI.h>
#include <OctoWS2811.h>

extern uint8_t *displayMemory; // DMA memory cannot be part of a class

/**
 * Manages WS2811 strips using OctoWS2811 library.
 *
 *
 */
class Display {
private:
    uint16_t width;
    uint16_t height;

    uint8_t *drawingMemory;
    OctoWS2811 *leds;

public:
    Display(uint16_t width, uint16_t height, uint8_t *drawingMemory):width(width), height(height), drawingMemory(drawingMemory) {
        displayMemory = new uint8_t[width*height*3]; // 24 bit per LED
        leds = new OctoWS2811((uint32_t) width*height/8, displayMemory, drawingMemory);
        leds->begin();
    }

    ~Display() {
        delete displayMemory;
        delete leds;
    }

    void update() {
        leds->show();
    }

    bool matchesSize(uint16_t width, uint16_t height ) {
        return this->width==width && this->height==height;
    }
};


#endif //TEENSYCMAKE_DISPLAY_H
