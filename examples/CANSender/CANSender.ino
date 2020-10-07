// Copyright (c) Sandeep Mistry. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for full license information.

// Selección del hardware a utilizar
// #define HW_RTLS_V4_0_X
#define HW_RTLS_V4_1_X

#include <CAN.h>
#include "boards.h"

void setup() {
  Serial.begin(57600);

  Serial.println("CAN Sender");

  CAN.setPins( A_GPIO_5, GPIO_INT1 );

  // start the CAN bus at 500 kbps
  if (!CAN.begin(500E3)) {
    Serial.println("Starting CAN failed!");
    while (1);
  }
}

void loop() {
  // send packet: id is 11 bits, packet can contain up to 8 bytes of data
  Serial.print("Sending packet ... ");

  CAN.beginPacket(0x12);
  CAN.write('h');
  CAN.write('e');
  CAN.write('l');
  CAN.write('l');
  CAN.write('o');
  CAN.endPacket();

  Serial.println("done");

  delay(1000);

  // send extended packet: id is 29 bits, packet can contain up to 8 bytes of data
  Serial.print("Sending extended packet ... ");

  CAN.beginExtendedPacket(0xabcdef);
  CAN.write('W');
  CAN.write('I');
  CAN.write('T');
  CAN.write('R');
  CAN.write('A');
  CAN.write('C');
  CAN.endPacket();

  Serial.println("done");

  delay(1000);
}

