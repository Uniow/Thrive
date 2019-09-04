#include "microbe_stage/patch.h"
#include "simulation_parameters.h"

using namespace thrive;

Patch::Patch(std::string name)
{
    this->name = name;
}

Patch::~Patch() {}

std::string
    Patch::getName()
{
    return this->name;
}

void
    Patch::setName(std::string name)
{
    this->name = name;
}

size_t
    Patch::getBiome()
{
    return this->patchBiome;
}

void
    Patch::setBiome(size_t patchBiome)
{
    this->patchBiome = patchBiome;
}

size_t
    Patch::getId()
{
    return this->patchId;
}

// Patch manager
PatchManager::PatchManager()
{
    this->currentPatchId = generatePatchMap();
}

PatchManager::~PatchManager()
{
    patchMap.clear();
}
/// Generate patch map and return the id of the starting patch
size_t
    PatchManager::generatePatchMap()
{

    // Initialize names array 
    std::string patchNames[4] = {"Pangonian Vents", "Pangonian Bathypelagic", "Pangonian Mesopelagic", "Pangonian Epipelagic"}; 

    std::shared_ptr<Patch> p;
    for (int i = 0; i < 4; i++)  
    {    
        p = std::make_shared<Patch>(patchNames[i]); 
        p.get()->setBiome(0);
        p.get()->patchId = 0;
        p.get()->screenCoordinates.X = 100;
        p.get()->screenCoordinates.Y = 100 + 100*i;
        patchMap[i] = p;
    }
    
/*
    // TODO: add proper map generator
    std::shared_ptr<Patch> p = std::make_shared<Patch>("Pangonian vents");
    p.get()->setBiome(0);
    p.get()->patchId = 0;
    p.get()->screenCoordinates.X = 100;
    p.get()->screenCoordinates.Y = 100;
    patchMap[0] = p;

    p = std::make_shared<Patch>("Trangonian vents");
    p.get()->setBiome(0);
    p.get()->patchId = 0;
    p.get()->screenCoordinates.X = 300;
    p.get()->screenCoordinates.Y = 100;
    patchMap[1] = p;*/

    LOG_INFO("**************");
    LOG_INFO("**************");
    LOG_INFO("patches created");
    for (int i = 0; i < 4; i++)  
    {
        LOG_INFO("patchMap[i].name " + patchMap[i].get()->name)
        LOG_INFO("patchMap[i].coords " + Convert::ToString(patchMap[i].get()->screenCoordinates));
    }

    return 0;
}
Patch*
    PatchManager::getCurrentPatch()
{
    return patchMap[this->currentPatchId].get();
}

Patch*
    PatchManager::getPatchFromKey(size_t key)
{
    return patchMap[key].get();
}
