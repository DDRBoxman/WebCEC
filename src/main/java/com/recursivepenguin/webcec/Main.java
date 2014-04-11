package com.recursivepenguin.webcec;

import com.recursivepenguin.webcec.cec.CECLogicalAddress;
import com.recursivepenguin.webcec.cec.CECPowerStatus;
import com.recursivepenguin.webcec.cec.CECVendorId;
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
                    CECLogicalAddress address = CECLogicalAddress.fromInt(deviceAddress);
                    System.out.println(address.name());
                    CECVendorId vendorId = CECVendorId.fromLong(libCEC.getDeviceVendorId(deviceAddress));
                    System.out.println(vendorId.name());
                    CECPowerStatus powerStatus = CECPowerStatus.fromInt(libCEC.getDevicePowerStatus(deviceAddress));
                    System.out.println(powerStatus.name());
                }

                libCEC.close();
            }
        }
    }

}
