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
    }

}
