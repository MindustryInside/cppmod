package nativeio.jni;

public class Natives2 {
    static {
        System.loadLibrary("nativeio");
    }

    public static native void init2();
}
