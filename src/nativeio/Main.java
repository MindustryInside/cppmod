package nativeio;

import nativeio.jni.*;

public class Main {
    static {
        System.loadLibrary("nativeio");
    }

    public static void main(String[] args) {
        Natives.nativeInit();
    }

    public static void print(String str) {
        System.out.println(str);
    }
}
