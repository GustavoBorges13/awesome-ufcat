#ifndef SYSTEM_H
#define SYSTEM_H
#include "types.h"

extern uint8 inportb (uint16 _port);
void outportb (uint16 _port, uint8 _data);

#endif
