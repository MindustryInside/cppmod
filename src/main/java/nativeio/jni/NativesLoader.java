package nativeio.jni;

import arc.util.*;

import java.io.*;
import java.nio.file.*;

public class NativesLoader {
    private static final String tempPrefix = "nativeio";
    private static File temporaryDir;

    public NativesLoader() {
        super();
    }

    public void load(String path) throws IOException {
        path = mapLibraryName(path);

        temporaryDir = createTempDirectory(tempPrefix);
        temporaryDir.deleteOnExit();

        File temp = new File(temporaryDir, path);

        try (InputStream is = getClass().getResourceAsStream("/" + path)) {
            Files.copy(is, temp.toPath(), StandardCopyOption.REPLACE_EXISTING);
        } catch (IOException e) {
            temp.delete();
            throw e;
        } catch (NullPointerException e) {
            temp.delete();
            throw new FileNotFoundException();
        }

        try {
            System.load(temp.getAbsolutePath());
        } finally {
            temp.delete();
        }
    }

    private File createTempDirectory(String prefix) throws IOException {
        String tempDir = System.getProperty("java.io.tmpdir");
        File generatedDir = new File(tempDir, prefix + System.nanoTime());

        if (!generatedDir.mkdir())
            throw new IOException("Failed to create temp directory " + generatedDir.getName());

        return generatedDir;
    }

    public String mapLibraryName(String libraryName) {
        if (OS.isWindows) return libraryName + ".dll";
        if (OS.isLinux) return "lib" + libraryName + ".so";
        if (OS.isMac) return "lib" + libraryName + ".dylib";

        return libraryName;
    }
}
