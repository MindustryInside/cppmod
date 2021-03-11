package nativeio;

import arc.util.*;
import mindustry.mod.*;
import nativeio.jni.*;

import java.io.*;

import static mindustry.Vars.*;

public class Loader extends Mod {
    private static NativesLoader loader = new NativesLoader();

    static {
        try {
            loader.load("nativeio");
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    @Override
    public void init() {
        Natives.init();
    }

    @Override
    public void loadContent() {
        Natives.loadContent();
    }
}
