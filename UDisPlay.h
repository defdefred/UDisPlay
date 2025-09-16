#include <NetworkUdp.h>

NetworkUDP UDisPlay_UDP;
#define UDisPlay_MAX 1461
char UDisPlay[UDisPlay_MAX];

#define UDisPlayFill( T ) snprintf( &UDisPlay[0], UDisPlay_MAX, T )

void UDisPlayStart( char *ip, uint16_t port) {
  UDisPlay_UDP.beginPacket( ip, port );
  UDisPlayFill( "Hello world" );
  UDisPlay_UDP.write( (uint8_t*)&UDisPlay[0], UDisPlay_MAX-1 );
  UDisPlay_UDP.endPacket();
}

void UDisPlaySend() {
  if (WiFiWrap.connected) {
    UDisPlay_UDP.beginPacket();
    UDisPlay_UDP.write( (uint8_t*)&UDisPlay[0], UDisPlay_MAX-1 );
    UDisPlay_UDP.endPacket();
  }
}
