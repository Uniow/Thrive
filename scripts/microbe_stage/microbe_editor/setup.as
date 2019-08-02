#include "microbe_editor_hud.as"
#include "microbe_editor.as"

// Called from ThriveGame when the editor has been entered and it should be setup
void onEditorEntry(MicrobeEditorWorld@ world)
{
    freeBuilding = false;
    enterEditor(world);
}

void onFreebuildEditorEntry(MicrobeEditorWorld@ world)
{
    freeBuilding = true;
    enterEditor(world);
}

void enterEditor(MicrobeEditorWorld@ world)
{
    LOG_INFO("Running microbe editor script setup");

    // This doesn't overwrite the object when called again so
    // setupHUDAfterEditorEntry must succeed when called again on
    // future edit sessions
    world.RegisterScriptSystem("MicrobeEditorHudSystem", MicrobeEditorHudSystem());

    // The world is cleared by the C++ code so we setup all of our entities again each time
    cast<MicrobeEditorHudSystem>(world.GetScriptSystem("MicrobeEditorHudSystem")).
        setupHUDAfterEditorEntry();
}
