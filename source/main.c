#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <3ds.h>

int main()
{
  // Initializations
  srvInit();        // services
  aptInit();        // applets
  gfxInitDefault(); // graphics
  gfxSet3D(false);  // stereoscopy (true: enabled / false: disabled)
  u32 kDown;        // keys down
  u32 kHeld;        // keys pressed
  u32 kUp;          // keys up

  //Initialize GFX (note: not needed if you're using SF2Dlib)  
  gfxInitDefault();    
  consoleInit(GFX_TOP, NULL);    
  printf("\x1b[15;10HGeekShop is in Under construction");
  printf("\x1b[18;15HPlease Wait!");

  // Main loop
  while (aptMainLoop())
  {

    // Wait for next frame
    gspWaitForVBlank();

    // Read which buttons are currently pressed or not
    hidScanInput();
    kDown = hidKeysDown();
    kHeld = hidKeysHeld();
    kUp = hidKeysUp();

   u32 kDown = hidKeysDown();
		if (kDown & KEY_TOUCH)
			break; // break in order to return to hbmenu



    /** Your code goes here **/


    // Flush and swap framebuffers
    gfxFlushBuffers();
    gfxSwapBuffers();
  }

  // Exit
  gfxExit();
  hidExit();
  aptExit();
  srvExit();

  // Return to hbmenu
  return 0;
}