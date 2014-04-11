package com.recursivepenguin.webcec.cec;

import java.util.HashMap;
import java.util.Map;

public enum CECVendorId {
    Toshiba      (0x000039),
    Samsung      (0x0000F0),
    Denon        (0x0005CD),
    Marantz      (0x000678),
    Loewe        (0x000982),
    Onkyo        (0x0009B0),
    Medion       (0x000CB8),
    Toshiba2     (0x000CE7),
    PulseEight   (0x001582),
    Akai         (0x0020C7),
    AOC          (0x002467),
    Panasonic    (0x008045),
    Philips      (0x00903E),
    Daewoo       (0x009053),
    Yamaha       (0x00A0DE),
    Grundig      (0x00D0D5),
    Pioneer      (0x00E036),
    LG           (0x00E091),
    Sharp        (0x08001F),
    Sony         (0x080046),
    Broadcom     (0x18C086),
    Vizio        (0x6B746D),
    Benq         (0x8065E9),
    HarmanKardon (0x9C645E),
    Unknown      (0);

    private long value;

    private CECVendorId(long value) {
        this.value = value;
    }

    private static final Map<Long, CECVendorId> longToTypeMap = new HashMap<>();
    static {
        for (CECVendorId type : CECVendorId.values()) {
            longToTypeMap.put(type.value, type);
        }
    }

    public static CECVendorId fromLong(long l) {
        CECVendorId type = longToTypeMap.get(l);
        if (type == null)
            return CECVendorId.Unknown;
        return type;
    }
}
