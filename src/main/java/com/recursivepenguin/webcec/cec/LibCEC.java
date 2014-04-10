package com.recursivepenguin.webcec.cec;

import java.util.ArrayList;
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

    public List<CECAdapter> detectAdapters() {
        List<CECAdapter> adapterList = new ArrayList<>();
        long[] adapters = detectAdaptersNative();
        for (long adapterHandle : adapters) {
            adapterList.add(new CECAdapter(adapterHandle));
        }

        return adapterList;
    }

    public boolean open(CECAdapter adapter) {
        return open(adapter.getCommPath());
    }

    public native void close();

    public native void audioMute();

    public native void audioUnMute();

    private native void setup();

    private native long[] detectAdaptersNative();

    private native boolean open(String string);
}
