package nativeio;

import mindustry.mod.*;
import nativeio.jni.*;

import static mindustry.Vars.*;

public class Loader extends Mod {
    private NativesLoader loader;

    @Override
    public void init() {
        loader = new NativesLoader(mods.getMod("nativeio").file.absolutePath());
        loader.load("nativeio");

        // Natives.init();
    }

    @Override
    public void loadContent() {
        // Natives.loadContent();
    }
}
