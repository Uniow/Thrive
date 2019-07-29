#include "microbe_editor_hud.as"

int freeBuilding = 1;

// Called from ThriveGame when the editor has been entered and it should be setup
void onEditorEntry(MicrobeEditorWorld@ world)
{
    freeBuilding = 1;
    LOG_INFO("Running microbe editor script setup");

    // This doesn't overwrite the object when called again so
    // setupHUDAfterEditorEntry must succeed when called again on
    // future edit sessions
    world.RegisterScriptSystem("MicrobeEditorHudSystem", MicrobeEditorHudSystem());

    // The world is cleared by the C++ code so we setup all of our entities again each time
    cast<MicrobeEditorHudSystem>(world.GetScriptSystem("MicrobeEditorHudSystem")).
        setupHUDAfterEditorEntry();
}

void onFreebuildEditorEntry(MicrobeEditorWorld@ world)
{
    freeBuilding = 0;
    LOG_INFO("Running microbe editor script setup");

    // This doesn't overwrite the object when called again so
    // setupHUDAfterEditorEntry must succeed when called again on
    // future edit sessions
    world.RegisterScriptSystem("MicrobeEditorHudSystem", MicrobeEditorHudSystem());

    // The world is cleared by the C++ code so we setup all of our entities again each time
    cast<MicrobeEditorHudSystem>(world.GetScriptSystem("MicrobeEditorHudSystem")).
        setupHUDAfterEditorEntry();
}
