#include "wifiwrap.h"
#include "udisplay.h"
 
void setup()
{
  WiFiWrapStart("fred", "XXXXXXXXXXXXXXXXXXXXXXXXXXX");
  UDisPlayStart("192.168.3.177", 4567);
}

void loop()
{
  sprintf( &UDisPlay[0], 
"----------------------------------------\n\
|                                      |\n\
|                                      |\n\
|                                      |\n\
|                                      |\n\
|                                      |\n\
|                                      |\n\
|                                      |\n\
|                                      |\n\
|                                      |\n\
|                                      |\n\
|                                      |\n\
|                                      |\n\
|                                      |\n\
|                                      |\n\
|                                      |\n\
|                                      |\n\
|                                      |\n\
|                                      |\n\
----------------------------------------");
  UDisPlaySend();
  delay(1000);
}
