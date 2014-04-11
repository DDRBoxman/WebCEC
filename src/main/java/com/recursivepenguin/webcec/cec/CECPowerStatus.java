package com.recursivepenguin.webcec.cec;

import java.util.HashMap;
import java.util.Map;

public enum CECPowerStatus {
    On                      (0x00),
    Standby                 (0x01),
    InTransitionStandbyToOn (0x02),
    InTransitionOnToStandby (0x03),
    Unknown                 (0x99);

    private int value;

    private CECPowerStatus(int value) {
        this.value = value;
    }

    private static final Map<Integer, CECPowerStatus> intToTypeMap = new HashMap<>();
    static {
        for (CECPowerStatus type : CECPowerStatus.values()) {
            intToTypeMap.put(type.value, type);
        }
    }

    public static CECPowerStatus fromInt(int i) {
        CECPowerStatus type = intToTypeMap.get(i);
        if (type == null)
            return CECPowerStatus.Unknown;
        return type;
    }
}
