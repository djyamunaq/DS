////////////////////////////////////////////////////////////////////////////////
//  SoftKinetic DepthSense Software Development Kit
//  Project Name      : DepthSenseSDK
//  Version           : 1.9.0
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
#pragma once
#ifndef DEPTHSENSE_VERSION_HXX
#define DEPTHSENSE_VERSION_HXX
#define DEPTHSENSE_VERSION_MAJOR            1
#define DEPTHSENSE_VERSION_MINOR            9
#define DEPTHSENSE_VERSION_PATCH            0
#define DEPTHSENSE_VERSION_BUILD            5
#define DEPTHSENSE_FILE_VERSION_STRING      "1.9.0.5"
#define DEPTHSENSE_PRODUCT_VERSION_STRING   "1.9.0-5 linux64 gcc (Release)"
#define DEPTHSENSE_PACKAGE_NAME             "DepthSenseSDK 1.9.0-5 linux64 gcc (Release)"
#define DEPTHSENSE_PACKAGE_TYPE             "Release"
#define DEPTHSENSE_PACKAGE_SUB_TYPE         "Release"
#define DEPTHSENSE_PACKAGE_BRANCH           "release/1.9.0"
#define DEPTHSENSE_PACKAGE_REVISION         "release/1.9.0"
#define DEPTHSENSE_PACKAGE_COMMIT_ID        "b6a51e39f7ce"
#define DEPTHSENSE_PACKAGE_FLAGS            "-DENABLE_MULTI_CLIENT=1 -DENABLE_REMOTE_CLIENT_SERVER=0 -DENABLE_DELPHI_CAMERA=0 -DSKFILTER=ON -DSOFTWARE_BINNING=ON -DWITH_CONDA_ENV_CREATION=ON"
#define DEPTHSENSE_VERSION_CODE             (((1)<<24)|((9)<<16)|((0)))
#define DEPTHSENSE_VERSION(a,b,c)           (((a)<<24)|((b)<<16)|((c)))
#endif /* DEPTHSENSE_VERSION_HXX */