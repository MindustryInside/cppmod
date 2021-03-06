package nativeio.jni;

import arc.util.*;

public class NativesLoader extends SharedLibraryLoader {
    public NativesLoader(String nativesJar) {
        super(nativesJar);
    }

    @Override
    public String mapLibraryName(String libraryName) {
        if (OS.isWindows) return libraryName + ".dll";
        if (OS.isLinux) return "lib" + libraryName + ".so";
        if (OS.isMac) return "lib" + libraryName + ".dylib";

        return libraryName;
    }
}
