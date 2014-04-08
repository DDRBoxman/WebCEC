package com.recursivepenguin.webcec.cec;

import java.util.List;

public class LibCEC {

    private long nativeHandle;

    public native void audioMute();

    public native void audioUnMute();

    public native List<CECAdapter> detectAdapters();

    public native void open(CECAdapter adapter);

    public native void close();
}
