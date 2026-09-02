#pragma once

#include "Scripting/ScriptObjectTypeTags.h"

namespace ProceduralExplorationGamePlugin{

    //The engine assigns the backing integers on first use, so each tag is defined in
    //exactly one translation unit. @see AV::ScriptObjectTypeTag
    extern AV::ScriptObjectTypeTag VisitedPlaceMapDataTypeTag;
    extern AV::ScriptObjectTypeTag DataPointFileTypeTag;
    extern AV::ScriptObjectTypeTag MeshParticleEmitterTypeTag;

};
