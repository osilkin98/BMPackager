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

/* this is the meta-data header, which defines values necessary
   to be rendered correctly as a BMP file. 
 */
struct bmap_info_header {
    
};

#endif
