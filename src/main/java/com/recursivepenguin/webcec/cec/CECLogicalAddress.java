package com.recursivepenguin.webcec.cec;

import java.util.HashMap;
import java.util.Map;

public enum CECLogicalAddress {
    Unknown          (-1),
    Tv               (0),
    RecordingDevice1 (1),
    RecordingDevice2 (2),
    Tuner1           (3),
    PlaybackDevice1  (4),
    AudioSystem      (5),
    Tuner2           (6),
    Tuner3           (7),
    PlaybackDevice2  (8),
    RecordingDevice3 (9),
    Tuner4           (10),
    PlaybackDevice3  (11),
    Reserved1        (12),
    Reserved2        (13),
    FreeUse          (14),
    Unregistered     (15),
    Broadcast        (15);

    private int value;

    private CECLogicalAddress(int value) {
        this.value = value;
    }

    private static final Map<Integer, CECLogicalAddress> intToTypeMap = new HashMap<>();
    static {
        for (CECLogicalAddress type : CECLogicalAddress.values()) {
            intToTypeMap.put(type.value, type);
        }
    }

    public static CECLogicalAddress fromInt(int i) {
        CECLogicalAddress type = intToTypeMap.get(i);
        if (type == null)
            return CECLogicalAddress.Unknown;
        return type;
    }
}
