package com.gameturbo.core;

public class Memory {
    // Кітапхананы жүктеу
    static {
        System.loadLibrary("native-lib");
    }

    // C++ функцияларын анықтау
    public native long readLong(int pid, long address);
    public native void writeFloat(int pid, long address, float value);
}
