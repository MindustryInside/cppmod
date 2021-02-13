package nativeio;

import static nativeio.jni.Natives.*;
import static nativeio.jni.Natives2.*;

public class Main {
    static {
        System.loadLibrary("nativeio");
    }

    public static void main(String[] args) {
        init();
        init2();
    }
}
