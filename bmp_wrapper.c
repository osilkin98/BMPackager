#include <stdio.h>
#include "bmp_wrapper.h"



#define BMAP_HEADER_SIZE 14           /* Length of the main header in bytes */
#define BMAP_INFO_HEADER_SIZE 40      /* Length of the info header in bytes */



/* all of these will be 0, however they can be changed at a later time
   should whoever is modifying it find it valuable to do so. */
#define COMPRESSION 0
#define IMAGE_SIZE 0
#define X_PIXELS_PER_M 0
#define Y_PIXELS_PER_M 0
#define COLORS_USED 0
#define IMPORTANT_COLORS 0


