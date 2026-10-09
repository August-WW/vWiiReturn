#include <stdio.h>
#include <stdlib.h>
#include <gccore.h>
#include <ogc/system.h>
#include <unistd.h>

static u32 *xfb;
static GXRModeObj *rmode;

void Initialise() {
  
	VIDEO_Init();
 
	rmode = VIDEO_GetPreferredMode(NULL);

	xfb = MEM_K0_TO_K1(SYS_AllocateFramebuffer(rmode));
	console_init(xfb,20,20,rmode->fbWidth,rmode->xfbHeight,rmode->fbWidth*VI_DISPLAY_PIX_SZ);
 
	VIDEO_Configure(rmode);
	VIDEO_SetNextFramebuffer(xfb);
	VIDEO_SetBlack(FALSE);
	VIDEO_Flush();
	VIDEO_WaitVSync();
	if(rmode->viTVMode&VI_NON_INTERLACE) VIDEO_WaitVSync();
}

int main() {
	Initialise();
	
	printf("\x1b[36;1m");
	
	printf("\n");
	printf("\n");
	printf("\n");
	printf("				      ++++++++++    ++++++++++++    ++++++++++    \n");
	printf("				     +++++++++++    ++++++++++++    +++++++++++   \n");
	printf("				    ++++++++++++    ++++++++++++    ++++++++++++  \n");
	printf("				    ++++++++++++    ++++++++++++    ++++++++++++  \n");
	printf("				    ++++++++++++    ++++++++++++    ++++++++++++  \n");
	printf("				    ++++++++++++    ++++++++++++    ++++++++++++  \n");
	printf("				    ++++++++++++    ++++++++++++    ++++++++++++  \n");
	printf("				    ++++++++++++    ++++++++++++    ++++++++++++  \n");
	printf("				    +++++++++++++    ++++++++++    +++++++++++++  \n");
	printf("				    ++++++++++++++    ++++++++     +++++++++++++  \n");
	printf("				    ++++++++++++++                ++++++++++++++  \n");
	printf("				    ++++++++++++++++            ++++++++++++++++  \n");
	printf("				    +++++++++++++++++++      +++++++++++++++++++  \n");
	printf("				    ++++++++++++++++++++++++++++++++++++++++++++  \n");
	printf("				     ++++++++++++++++++++++++++++++++++++++++++   \n");
	printf("				      ++++++++++++++++++++++++++++++++++++++++    \n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");

    // Set a blue background and white text for the header
    printf("\x1b[37;46m  Returning to the Wii U Menu                               Please wait...  \x1b[37m\n");
    printf("\x1b[37;46m                                                                            \x1b[40;37m\n");
    printf("\x1b[37;46m                                [august wolf]                               \x1b[40;37m\n");
	
	sleep(5);
	
	SYS_ResetSystem(SYS_RESTART, 0, 0);
	
	return 0;
}