package com.recursivepenguin.webcec;

import com.recursivepenguin.webcec.cec.CECAdapter;
import com.recursivepenguin.webcec.cec.LibCEC;

import java.util.List;

public class Main {

    public static void main(String[] args) {
        LibCEC libCEC = LibCEC.init();
        List<CECAdapter> adapterList = libCEC.detectAdapters();
        for (CECAdapter adapter : adapterList) {
            System.out.println(adapter.getCommPath());
        }

        if (adapterList.size() > 0) {
            boolean success = libCEC.open(adapterList.get(0));
            System.out.println("Connection - " + (success ? "Successful" : "Failed"));
            if (success) {

                int[] devices = libCEC.getActiveDevices();
                for (int deviceAddress : devices) {
                    System.out.println(deviceAddress);
                    System.out.println(libCEC.getDeviceVendorId(deviceAddress));
                    System.out.println(libCEC.getDevicePowerStatus(deviceAddress));
                }

                libCEC.close();
            }
        }
    }

}
