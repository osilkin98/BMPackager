#ifndef BINARY_BMP_WRAPPER_H
#define BINARY_BMP_WRAPPER_H

/* for using universal definitions of fixed length variables */
#include <stdint.h>



#define FOUR_BYTES uint32_t /* for 4-Byte long descriptors */
#define TWO_BYTES uint16_t  /* for 2-Byte long descriptors */
#define ONE_BYTE uint8_t    /* for 1-Byte long descriptors */


/* struct to contain the headers for the bitmap */
struct BMapHeader {

  /* this is the only variable which will actually differ */
  FOUR_BYTES file_size;

  /* since signature is known, it can be set here  */
  const ONE_BYTE signature[2];
  /* the reservation will ALWAYS be 0 */
  const FOUR_BYTES reserved;

  /* the offset for the data will be the sum 
     of the size of both headers in bytes */
  const FOUR_BYTES data_offset;
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
struct BMapInfoHeader {
  /* this is the total size, in bytes, */
  const FOUR_BYTES size;

  /* we're only using one plane, I'm fairly sure that you cannot use 
     more than one, though I might be wrong. */
  const TWO_BYTES planes;

    
  FOUR_BYTES width;   /* horizontal length of bitmap image in pixels */
  FOUR_BYTES height;  /* vertical length of bitmap image in pixels */

  /* must be either 8, 16 or 24. This determines numColors */
  TWO_BYTES bits_per_pixel;

  FOUR_BYTES num_colors;

  /* this is a list of values which all appear as 4-byte long constants 
     set to 0, as they are never actually needed. Some of these may be changed,
     however when doing so, you must remove them from this list and put them 
     into their own FOUR_BYTES container. 
  */
  const FOUR_BYTES zero_constants[6];
    
    
  /* the compression is something that is assumed to be 0, 
   * however I'm unsure if compression would corrupt the executable 
   * being transported by the bitmap image
   */
};


#undef COMPRESSION
#undef IMAGE_SIZE
#undef X_PIXELS_PER_M
#undef Y_PIXELS_PER_M
#undef COLORS_USED
#undef IMPORTANT_COLORS



/* color table is not something that will be included, as the number
   of bits per pixels will ALWAYS be greater than or equal to 8.
*/

struct BitmapImage {
  

};


#endif
