#ifndef BINARY_BMP_WRAPPER_H
#define BINARY_BMP_WRAPPER_H

#include <stdint.h>


/* struct to contain the headers for the bitmap */
struct bmap_header {

    /* this is the only variable which will actually differ */
    uint32_t file_size;

    
    /* since signature is known, it can be set here  */
    const uint8_t signature[] = {'B', 'M'};
    /* the reservation will ALWAYS be 0 */
    const uint32_t reserved = 0;
    /* the offset for the data will ALWAYS be 54, 
       which is really wasteful when you think about it */
    const uint32_t data_offset = 54;
};

/* all of these will be 0, however they can be changed at a later time
   should whoever is modifying it find it valuable to do so. */
#define COMPRESSION 0
#define IMAGE_SIZE 0
#define X_PIXELS_PER_M 0
#define Y_PIXELS_PER_M 0
#define COLORS_USED 0
#define IMPORTANT_COLORS 0



/* this is the meta-data header, which defines values necessary
   to be rendered correctly as a BMP file. 
 */
struct bmap_info_header {
    /* this is the total size, in bytes, */
    const uint32_t size = 40;

    /* we're only using one plane, I'm fairly sure that you cannot use 
     more than one, though I might be wrong. */
    const uint16_t planes = 1;

    
    uint32_t width;   /* horizontal length of bitmap image in pixels */
    uint32_t height;  /* vertical length of bitmap image in pixels */

    /* must be either 8, 16 or 24. This determines numColors */
    uint16_t bits_per_pixel;

    uint32_t num_colors;

    /* this is a list of values which all appear as 4-byte long constants 
       set to 0, as they are never actually needed. Some of these may be changed,
       however when doing so, you must remove them from this list and put them 
       into their own uint32_t container. 
    */
    const uint32_t zero_constants[] = { COMPRESSION, IMAGE_SIZE, X_PIXELS_PER_M,
				   Y_PIXELS_PER_M, COLORS_USED, IMPORTANT_COLORS };
    
    
    /* the comprssion is something that is assumed to be 0, 
     * however I'm unsure if compression would corrupt the executable 
     * being transported by the bitmap image
     */
};

#endif
