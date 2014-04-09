#include <jni.h>
#include "cec.h"
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
JNIEXPORT jobject JNICALL Java_com_recursivepenguin_webcec_cec_LibCEC_detectAdapters
  (JNIEnv *env, jobject obj)
  {
      CEC::ICECAdapter *adapter = getHandle<CEC::ICECAdapter>(env, obj);

      CEC::cec_adapter_descriptor devices[10];
      int8_t iDevicesFound = adapter->DetectAdapters(devices, 10, NULL);
      return NULL;
  }

/*
 * Class:     com_recursivepenguin_webcec_cec_LibCEC
 * Method:    open
 * Signature: (Lcom/recursivepenguin/webcec/cec/CECAdapter;)V
 */
JNIEXPORT void JNICALL Java_com_recursivepenguin_webcec_cec_LibCEC_open
  (JNIEnv *, jobject, jobject)
  {

  }

/*
 * Class:     com_recursivepenguin_webcec_cec_LibCEC
 * Method:    close
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_recursivepenguin_webcec_cec_LibCEC_close
  (JNIEnv *, jobject)
  {

  }