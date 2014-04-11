package com.recursivepenguin.webcec;

import com.recursivepenguin.webcec.cec.LibCEC;

public class Main {

    public static void main(String[] args) {
        LibCEC libCEC = LibCEC.init();
        String[] adapterList = libCEC.detectAdapters();
        for (String adapter : adapterList) {
            System.out.println(adapter);
        }

        if (adapterList.length > 0) {
            boolean success = libCEC.open(adapterList[0]);
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
