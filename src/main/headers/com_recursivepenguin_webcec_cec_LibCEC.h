/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class com_recursivepenguin_webcec_cec_LibCEC */

#ifndef _Included_com_recursivepenguin_webcec_cec_LibCEC
#define _Included_com_recursivepenguin_webcec_cec_LibCEC
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     com_recursivepenguin_webcec_cec_LibCEC
 * Method:    close
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_recursivepenguin_webcec_cec_LibCEC_close
  (JNIEnv *, jobject);

/*
 * Class:     com_recursivepenguin_webcec_cec_LibCEC
 * Method:    getActiveDevices
 * Signature: ()[I
 */
JNIEXPORT jintArray JNICALL Java_com_recursivepenguin_webcec_cec_LibCEC_getActiveDevices
  (JNIEnv *, jobject);

/*
 * Class:     com_recursivepenguin_webcec_cec_LibCEC
 * Method:    getDeviceVendorId
 * Signature: (I)J
 */
JNIEXPORT jlong JNICALL Java_com_recursivepenguin_webcec_cec_LibCEC_getDeviceVendorId
  (JNIEnv *, jobject, jint);

/*
 * Class:     com_recursivepenguin_webcec_cec_LibCEC
 * Method:    getDevicePowerStatus
 * Signature: (I)I
 */
JNIEXPORT jint JNICALL Java_com_recursivepenguin_webcec_cec_LibCEC_getDevicePowerStatus
  (JNIEnv *, jobject, jint);

/*
 * Class:     com_recursivepenguin_webcec_cec_LibCEC
 * Method:    setup
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_recursivepenguin_webcec_cec_LibCEC_setup
  (JNIEnv *, jobject);

/*
 * Class:     com_recursivepenguin_webcec_cec_LibCEC
 * Method:    detectAdaptersNative
 * Signature: ()[J
 */
JNIEXPORT jlongArray JNICALL Java_com_recursivepenguin_webcec_cec_LibCEC_detectAdaptersNative
  (JNIEnv *, jobject);

/*
 * Class:     com_recursivepenguin_webcec_cec_LibCEC
 * Method:    open
 * Signature: (Ljava/lang/String;)Z
 */
JNIEXPORT jboolean JNICALL Java_com_recursivepenguin_webcec_cec_LibCEC_open
  (JNIEnv *, jobject, jstring);

#ifdef __cplusplus
}
#endif
#endif
