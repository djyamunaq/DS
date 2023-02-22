////////////////////////////////////////////////////////////////////////////////
// SoftKinetic DepthSense SDK
//
// COPYRIGHT AND CONFIDENTIALITY NOTICE - SOFTKINETIC CONFIDENTIAL
// INFORMATION
//
// All rights reserved to SOFTKINETIC SENSORS NV (a
// company incorporated and existing under the laws of Belgium, with
// its principal place of business at Boulevard de la Plainelaan 11,
// 1050 Brussels (Belgium), registered with the Crossroads bank for
// enterprises under company number 0811 341 454 - "Softkinetic
// Sensors").
//
// The source code of the SoftKinetic DepthSense Camera Drivers is
// proprietary and confidential information of Softkinetic Sensors NV.
//
// For any question about terms and conditions, please contact:
// info@softkinetic.com Copyright (c) 2002-2015 Softkinetic Sensors NV
////////////////////////////////////////////////////////////////////////////////


#ifndef _DEPTHSENSETYPES_H
#define	_DEPTHSENSETYPES_H

#ifdef __cplusplus
extern "C" {
#endif

#ifdef _MSC_VER

    // 1) cinttypes is available only for > VS2012 i.e. MSC_VER >= 1800
    //    This bug is fixed in VS2013 (not fixed in VS2012 as mentioned somewhere on web)
    // 2) in VS2010, including stdint.h and intsafe.h generated macro redifinition warnings.
    //    This bug is fixed in VS2013 (possibly in VS2012)

    #if _MSC_VER < 1800

        typedef signed   __int8   int8_t;
        typedef signed   __int16  int16_t;
        typedef signed   __int32  int32_t;
        typedef signed   __int64  int64_t;
        typedef unsigned __int8   uint8_t;
        typedef unsigned __int16  uint16_t;
        typedef unsigned __int32  uint32_t;
        typedef unsigned __int64  uint64_t;

        #define PRId64         "I64d"
        #define PRIi64         "I64i"
        #define PRIu64         "I64u"
        #define PRIx64         "I64x"

        #ifdef _WIN64
            #define INT64_C(c)  c ## L
            #define UINT64_C(c) c ## UL
        #else
            #define INT64_C(c)  c ## LL
            #define UINT64_C(c) c ## ULL
        #endif

    #else // ! _MSC_VER < 1800

        #include <cstdint>
        #include <cinttypes>

    #endif // _MSC_VER < 1800

    #define SK_NO_RETURN __declspec(noreturn)
    #define SK_MAY_ALIAS

#else // !_MSC_VER

    // Warning: this will break if <stdint.h> has already been included from elsewhere
    //          without __STDC_CONSTANT_MACROS and __STDC_FORMAT_MACROS defined in the first place.

    // We need these two macros if we compile DSSDK with Android or on Ubuntu without -std=c++0x flag.
    // Note that even with the same compiler (e.g. gcc4.8*), we have different stdint.h and inttypes.h
    // used in Ubuntu and Android compilation
    #ifndef __STDC_CONSTANT_MACROS
        #define _UNDEF__STDC_CONSTANT_MACROS
        #define __STDC_CONSTANT_MACROS // for UINT64_C(c) and friends
    #endif
    #include <stdint.h>
    // this undef may not be needed, but it is probably safer and is done similarly in system include files
    #ifdef _UNDEF__STDC_CONSTANT_MACROS
        #undef __STDC_CONSTANT_MACROS
        #undef _UNDEF__STDC_CONSTANT_MACROS
    #endif

    #ifndef __STDC_FORMAT_MACROS
        #define _UNDEF__STDC_FORMAT_MACROS
        #define __STDC_FORMAT_MACROS // for PRIi64 and friends
    #endif
    #include <inttypes.h>
    // this undef may not be needed, but it is probably safer and is done similarly in system include files
    #ifdef _UNDEF__STDC_FORMAT_MACROS
        #undef __STDC_FORMAT_MACROS
        #undef _UNDEF__STDC_FORMAT_MACROS
    #endif

    #define SK_NO_RETURN __attribute__ ((noreturn))
    #define SK_MAY_ALIAS __attribute__ ((__may_alias__))

#endif // _MSC_VER

// detect std::hash availability:
//
//   - gcc defines the __GXX_EXPERIMENTAL_CXX0X__ symbol when C++11
//     support is available, see
//
//     http://gcc.gnu.org/onlinedocs/libstdc++/manual/status.html#status.iso.200x
//   - Visual Studio 2010 and later versions support std::hash
#if defined(__GXX_EXPERIMENTAL_CXX0X__) || (_MSC_VER >= 1600)
    #define __DS_HAVE_STD_HASH
#endif

#ifdef __cplusplus
}
#endif

#endif	// _DEPTHSENSETYPES_H
