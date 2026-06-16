#pragma once

#include "subghz_keystore.h"
#include <m-array.h>

/* ARF-Shuka-Edition: expose SubGhzKeystore internals needed by keeloq.c */

struct SubGhzKeystore {
    SubGhzKeyArray_t data;
    const char* mfname;
    uint8_t kl_type;
};

void subghz_keystore_reset_kl(SubGhzKeystore* instance);
