package com.recursivepenguin.webcec.cec;

import java.util.List;

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

    private native void setup();

    public native void audioMute();

    public native void audioUnMute();

    public native List<CECAdapter> detectAdapters();

    public native void open(CECAdapter adapter);

    public native void close();
}
