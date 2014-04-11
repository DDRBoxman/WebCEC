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

  config->Clear();
  snprintf(config->strDeviceName, 13, "CECTester");
  config->clientVersion       = CEC::CEC_CLIENT_VERSION_CURRENT;
  config->bActivateSource     = 0;

  config->deviceTypes.Add(CEC::CEC_DEVICE_TYPE_RECORDING_DEVICE);

  CEC::ICECAdapter* adapter = (CEC::ICECAdapter *) CECInitialise(config);
  setHandle(env, obj, adapter);
}

/*
 * Class:     com_recursivepenguin_webcec_cec_LibCEC
 * Method:    detectAdapters
 * Signature: ()[Ljava/lang/String;
 */
JNIEXPORT jobjectArray JNICALL Java_com_recursivepenguin_webcec_cec_LibCEC_detectAdapters
  (JNIEnv *env, jobject obj)
  {
      CEC::ICECAdapter *adapter = getHandle<CEC::ICECAdapter>(env, obj);

      CEC::cec_adapter_descriptor devices[10];
      int8_t iDevicesFound = adapter->DetectAdapters(devices, 10, NULL);

      jstring str = NULL;
      jclass strCls = env->FindClass("Ljava/lang/String;");
      jobjectArray strarray = env->NewObjectArray(iDevicesFound,strCls,NULL);
      for(int i=0; i<iDevicesFound; i++)
      {
        str = env->NewStringUTF(devices[i].strComPath);
        env->SetObjectArrayElement(strarray,i,str);
        env->DeleteLocalRef(str);
      }

      return strarray;
  }

/*
 * Class:     com_recursivepenguin_webcec_cec_LibCEC
 * Method:    getActiveDevices
 * Signature: ()[I
 */
JNIEXPORT jintArray JNICALL Java_com_recursivepenguin_webcec_cec_LibCEC_getActiveDevices
  (JNIEnv *env, jobject obj)
  {
    CEC::ICECAdapter *adapter = getHandle<CEC::ICECAdapter>(env, obj);
    CEC::cec_logical_addresses addresses = adapter->GetActiveDevices();

    jintArray jAddresses = env->NewIntArray(sizeof(addresses.addresses));
    env->SetIntArrayRegion(jAddresses, 0, sizeof(addresses.addresses), addresses.addresses);

    return jAddresses;
  }

/*
 * Class:     com_recursivepenguin_webcec_cec_LibCEC
 * Method:    getDeviceVendorId
 * Signature: (I)J
 */
JNIEXPORT jlong JNICALL Java_com_recursivepenguin_webcec_cec_LibCEC_getDeviceVendorId
  (JNIEnv *env, jobject obj, jint jDeviceAddress)
  {
     CEC::ICECAdapter *adapter = getHandle<CEC::ICECAdapter>(env, obj);
     return adapter->GetDeviceVendorId((CEC::cec_logical_address)jDeviceAddress);
  }

/*
 * Class:     com_recursivepenguin_webcec_cec_LibCEC
 * Method:    getDevicePowerStatus
 * Signature: (I)I
 */
JNIEXPORT jint JNICALL Java_com_recursivepenguin_webcec_cec_LibCEC_getDevicePowerStatus
  (JNIEnv *env, jobject obj, jint jDeviceAddress)
  {
     CEC::ICECAdapter *adapter = getHandle<CEC::ICECAdapter>(env, obj);
     return adapter->GetDevicePowerStatus((CEC::cec_logical_address)jDeviceAddress);
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

     return result ? JNI_TRUE : JNI_FALSE;
  }

/*
 * Class:     com_recursivepenguin_webcec_cec_LibCEC
 * Method:    close
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_recursivepenguin_webcec_cec_LibCEC_close
  (JNIEnv *env, jobject obj)
  {
    CEC::ICECAdapter *adapter = getHandle<CEC::ICECAdapter>(env, obj);
    adapter->Close();
  }