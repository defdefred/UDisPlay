#include "WiFiWrap.h"
#include "UDisPlay.h"
 
void setup()
{
  WiFiWrapStart("IOT", "frederic");
  UDisPlayStart("192.168.2.2", 4567); // IP is you display server 
}

void loop()
{
  // UDP packet up to 1460 should'nt be fragmented
  UDisPlayFill( "wLabore ipsum ut lorem magna sit. Ea ex ea elit dolor commodo consequat dolor ipsum ipsum ut labore labore aliqua. Do exercitation commodo tempor ad nisi ex magna elit. Enim ullamco tempor quis consectetur lorem dolore. Magna exercitation ad enim eiusmod nostrud ex exercitation sed. Ut commodo ullamco minim dolor aliqua commodo. Eiusmod consequat lorem aliqua dolor ullamco nisi ut aliquip dolor consequat laboris consequat et. Consectetur commodo amet commodo minim quis quis ipsum dolore incididunt minim. Ut nisi ipsum adipiscing et aliquip ut lorem laboris ipsum aliquip incididunt. Ipsum tempor exercitation exercitation ullamco labore ut ea enim quis adipiscing ut lorem.\nBOOTED SINCE %.4u\n sed labore enim dolore ut enim laboris veniam aliquip. Ad ipsum sit elit aliqua consectetur ut do laboris enim commodo elit lorem. Ad adipiscing sed magna consectetur laboris dolor tempor nostrud consectetur dolor veniam. Dolor minim sed magna labore laboris. Minim aliquip adipiscing sed do laboris. Lorem dolore dolore quis et enim ullamco sit exercitation ut ut elit. Enim sit ut quis magna ut. Ullamco quis ut minim eiusmod minim do ut ad ut nisi. Labore commodo elit ipsum tempor sed lorem. Nostrud magna aliqua exercitation do exercitation sit magna ea dolore ad ea adipiscing minim. Ex adipiscing enim do eiusmod ullamco labore laboris ex adipiscing ea adipiscing dolor. Amet veniam ipsum amet laboris ut ullamco adipiscing lorem. Ex enim dolor nostrud", milli()/1000 );
  UDisPlaySend();
  delay(1000);
}
