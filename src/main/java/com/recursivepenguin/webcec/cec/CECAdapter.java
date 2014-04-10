package com.recursivepenguin.webcec.cec;

public class CECAdapter {

    private long nativeHandle;

    public CECAdapter(long handle) {
        nativeHandle = handle;
    }

    public native String getCommPath();

    public native String getCommName();

}
