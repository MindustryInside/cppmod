package nativeio.jni;

public class Natives {
    static {
        System.loadLibrary("nativeio");
    }

    public static native void init();
}
