#pragma once

#include "Scripting/ScriptNamespace/ScriptUtils.h"

namespace ProceduralExplorationGameCore{
    class ExplorationMapData;

    class ExplorationMapDataUserData{
    public:
        ExplorationMapDataUserData() = delete;
        ~ExplorationMapDataUserData() = delete;

        static void setupDelegateTable(HSQUIRRELVM vm);

        static void ExplorationMapDataToUserData(HSQUIRRELVM vm, ExplorationMapData* mapData);

        static AV::UserDataGetResult readExplorationMapDataFromUserData(HSQUIRRELVM vm, SQInteger stackInx, ExplorationMapData** outMapData);

    private:
        static SQObject ExplorationMapDataDelegateTableObject;

        static SQInteger explorationMapDataToTable(HSQUIRRELVM vm);
        static SQInteger getAltitudeForPos(HSQUIRRELVM vm);
        static SQInteger getLandmassForPos(HSQUIRRELVM vm);
        static SQInteger getIsWaterForPos(HSQUIRRELVM vm);
        static SQInteger getRegionForPos(HSQUIRRELVM vm);
        static SQInteger getWaterGroupForPos(HSQUIRRELVM vm);
        static SQInteger randomIntMinMax(HSQUIRRELVM vm);

        static SQInteger ExplorationMapDataObjectReleaseHook(SQUserPointer p, SQInteger size);
    };
}
