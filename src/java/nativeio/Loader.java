package nativeio;

import mindustry.mod.*;
import nativeio.jni.*;

public class Loader extends Mod {
    @Override
    public void init() {
        Natives.init();
    }

    @Override
    public void loadContent() {
        Natives.loadContent();
    }
}
