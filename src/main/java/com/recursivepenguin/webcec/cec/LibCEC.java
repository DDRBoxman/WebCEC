package com.recursivepenguin.webcec.cec;

public class LibCEC {

    static {
        System.loadLibrary("cec");
    }

    private long nativeHandle;

    private LibCEC() {

    }

    public static LibCEC init() {
        LibCEC libCEC = new LibCEC();
        libCEC.setup();
        return libCEC;
    }

    public native String[] detectAdapters();

    public native boolean open(String string);

    public native void close();

    public native int[] getActiveDevices();

    public native long getDeviceVendorId(int address);

    public native int getDevicePowerStatus(int address);

    private native void setup();
}
