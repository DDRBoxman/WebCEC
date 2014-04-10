#include <cec.h>
#include "com_recursivepenguin_webcec_cec_LibCEC.h"
#include "handle.h"

/*
 * Class:     com_recursivepenguin_webcec_cec_LibCEC
 * Method:    setup
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_recursivepenguin_webcec_cec_LibCEC_setup
  (JNIEnv *env, jobject obj)
{
  CEC::libcec_configuration *config = new CEC::libcec_configuration();
  CEC::ICECAdapter* adapter = (CEC::ICECAdapter *) CECInitialise(config);
  setHandle(env, obj, adapter);
}

/*
 * Class:     com_recursivepenguin_webcec_cec_LibCEC
 * Method:    audioMute
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_recursivepenguin_webcec_cec_LibCEC_audioMute
  (JNIEnv *, jobject)
  {

  }

/*
 * Class:     com_recursivepenguin_webcec_cec_LibCEC
 * Method:    audioUnMute
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_recursivepenguin_webcec_cec_LibCEC_audioUnMute
  (JNIEnv *, jobject)
  {

  }

/*
 * Class:     com_recursivepenguin_webcec_cec_LibCEC
 * Method:    detectAdapters
 * Signature: ()Ljava/util/List;
 */
JNIEXPORT jlongArray JNICALL Java_com_recursivepenguin_webcec_cec_LibCEC_detectAdaptersNative
  (JNIEnv *env, jobject obj)
  {
      CEC::ICECAdapter *adapter = getHandle<CEC::ICECAdapter>(env, obj);

      CEC::cec_adapter_descriptor devices[10];
      int8_t iDevicesFound = adapter->DetectAdapters(devices, 10, NULL);

      jlong tempArray[iDevicesFound];
      for (int i=0; i<iDevicesFound; i++) {
        tempArray[i] = (jlong) &(devices[i]);
      }

      jlongArray handles = env->NewLongArray(iDevicesFound);
      env->SetLongArrayRegion(handles, 0, iDevicesFound, tempArray);

      return handles;
  }

/*
 * Class:     com_recursivepenguin_webcec_cec_LibCEC
 * Method:    open
 * Signature: (Ljava/lang/String;)Z
 */
JNIEXPORT jboolean JNICALL Java_com_recursivepenguin_webcec_cec_LibCEC_open
  (JNIEnv *env, jobject obj, jstring javaPathString)
  {
     CEC::ICECAdapter *adapter = getHandle<CEC::ICECAdapter>(env, obj);
     const char *nativeString = env->GetStringUTFChars(javaPathString, 0);

     bool result = adapter->Open(nativeString);

     env->ReleaseStringUTFChars(javaPathString, nativeString);

     return result;
  }

/*
 * Class:     com_recursivepenguin_webcec_cec_LibCEC
 * Method:    close
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_recursivepenguin_webcec_cec_LibCEC_close
  (JNIEnv *, jobject)
  {
    CEC::ICECAdapter *adapter = getHandle<CEC::ICECAdapter>(env, obj);
    adapter->Close();
  }