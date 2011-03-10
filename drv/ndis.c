#include <ntifs.h>

#include <tdi.h>
#include <tdiinfo.h>
#include <tdikrnl.h>
#include <ndis.h>
#include <sys/types.h>
#include <sys/systm.h>

#if NTDDI_VERSION < NTDDI_LONGHORN
    #include "ndis5.c"
#else
    #include "ndis6.c"
#endif