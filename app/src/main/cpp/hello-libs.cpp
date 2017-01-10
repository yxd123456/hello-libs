/*
 * Copyright (C) 2016 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */
#include <cstring>
#include <jni.h>
#include <android/log.h>
#include "FaceVeri.h"
#include <android/log.h>
#include <string>
using namespace std;

#define  LOG_TAG    "Test"
#define  LOGI(...)  __android_log_print(ANDROID_LOG_INFO,LOG_TAG,__VA_ARGS__)


extern "C"
JNIEXPORT jfloat JNICALL
Java_com_example_hellolibs_MainActivity_faceVeri(JNIEnv *env, jobject instance) {

    faceVeriInit("/storage/emulated/0/face/faceVeriConfig.yml");

    FACERC  facerc;
    float* f2[1];
    int i = faceFeatureExtractCamera("/storage/emulated/0/face/b1.jpg",
                             facerc,
                             &f2[0],
                             1);
    LOGI("something");
    int j = faceFeatureExtractIDCard("/storage/emulated/0/face/a1.jpg",
                                     facerc,
                               &f2[0]);

    float sc[1];

    int similar = faceFeatureCompare(sc);

    return (jfloat)i;
}

