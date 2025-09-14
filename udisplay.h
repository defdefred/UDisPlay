#include <NetworkUdp.h>

NetworkUDP UDisPlay_UDP;
#define UDisPlay_MAX 1460
char UDisPlay[UDisPlay_MAX];

void UDisPlayStart( char *ip, uint16_t port) {
  UDisPlay_UDP.beginPacket( ip, port );
  sprintf(&UDisPlay[0], "Hello world");
  UDisPlay_UDP.write((uint8_t*)&UDisPlay[0], UDisPlay_MAX);
  UDisPlay_UDP.endPacket();
}

void UDisPlaySend() {
  if (WiFiWrap.connected) {
    UDisPlay_UDP.beginPacket();
    UDisPlay_UDP.write((uint8_t*)&UDisPlay[0], UDisPlay_MAX);
    UDisPlay_UDP.endPacket();
  }
}
