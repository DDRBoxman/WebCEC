package com.recursivepenguin.webcec;

import com.recursivepenguin.webcec.cec.LibCEC;

public class Main {

    public static void main(String[] args) {

        System.out.println(System.getProperty("java.library.path"));

        LibCEC libCEC = LibCEC.init();
    }

}
