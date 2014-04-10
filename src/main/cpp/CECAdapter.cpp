#include <cec.h>
#include "com_recursivepenguin_webcec_cec_CECAdapter.h"
#include "handle.h"

/*
 * Class:     com_recursivepenguin_webcec_cec_CECAdapter
 * Method:    getCommPath
 * Signature: ()Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_recursivepenguin_webcec_cec_CECAdapter_getCommPath
  (JNIEnv *env, jobject obj)
  {
    CEC::cec_adapter_descriptor *adapter = getHandle<CEC::cec_adapter_descriptor>(env, obj);
    return env->NewStringUTF(adapter->strComPath);
  }

/*
 * Class:     com_recursivepenguin_webcec_cec_CECAdapter
 * Method:    getCommName
 * Signature: ()Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_recursivepenguin_webcec_cec_CECAdapter_getCommName
  (JNIEnv *env, jobject obj)
  {
    CEC::cec_adapter_descriptor *adapter = getHandle<CEC::cec_adapter_descriptor>(env, obj);
    return env->NewStringUTF(adapter->strComName);
  }