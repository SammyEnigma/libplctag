#include <stdio.h>
#include "../lib/libplctag2.h"
#include "utils.h"


#define TAG_PATH "protocol=ab_eip&gateway=10.206.1.38&cpu=PLC5&elem_size=4&elem_count=5&name=F8:10&debug=4"
#define ELEM_COUNT 5
#define ELEM_SIZE 4
#define DATA_TIMEOUT 5000


int main(int argc, char **argv)
{
    int32_t tag = 0;
    int rc;
    int i;

    (void)argc;
    (void)argv;

    /* create the tag */
    tag = plc_tag_create(TAG_PATH, DATA_TIMEOUT);

    /* everything OK? */
    if(tag < 0) {
        fprintf(stderr,"ERROR %s: Could not create tag!\n", plc_tag_decode_error(tag));
        return 0;
    }

    if(plc_tag_status(tag) != PLCTAG_STATUS_OK) {
        fprintf(stderr,"Error setting up tag internal state. %s\n", plc_tag_decode_error(plc_tag_status(tag)));
        plc_tag_destroy(tag);
        return 0;
    }

    /* get the data */
    rc = plc_tag_read(tag, DATA_TIMEOUT);
    if(rc != PLCTAG_STATUS_OK) {
        fprintf(stderr,"ERROR: Unable to read the data! Got error code %d: %s\n",rc, plc_tag_decode_error(rc));
        plc_tag_destroy(tag);
        return 0;
    }

    /* print out the data */
    for(i=0; i < ELEM_COUNT; i++) {
        fprintf(stderr,"data[%d]=%f\n",i,plc_tag_get_float32(tag,(i*ELEM_SIZE)));
    }

    /* now test a write */
    for(i=0; i < ELEM_COUNT; i++) {
        float val = plc_tag_get_float32(tag,(i*ELEM_SIZE));

        val = val+1.5f;

        fprintf(stderr,"Setting element %d to %f\n",i,val);

        plc_tag_set_float32(tag,(i*ELEM_SIZE),val);
    }

    rc = plc_tag_write(tag, DATA_TIMEOUT);
    if(rc != PLCTAG_STATUS_OK) {
        fprintf(stderr,"ERROR: Unable to read the data! Got error code %d: %s\n",rc, plc_tag_decode_error(rc));
        plc_tag_destroy(tag);
        return 0;
    }


    /* get the data again*/
    rc = plc_tag_read(tag, DATA_TIMEOUT);
    if(rc != PLCTAG_STATUS_OK) {
        fprintf(stderr,"ERROR: Unable to read the data! Got error code %d: %s\n",rc, plc_tag_decode_error(rc));
        plc_tag_destroy(tag);
        return 0;
    }

    /* print out the data */
    for(i=0; i < ELEM_COUNT; i++) {
        fprintf(stderr,"data[%d]=%f\n",i,plc_tag_get_float32(tag,(i*ELEM_SIZE)));
    }

    /* we are done */
    plc_tag_destroy(tag);

    return 0;
}


