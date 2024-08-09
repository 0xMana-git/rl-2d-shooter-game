#pragma once

#include "engine/world.h"
#include "engine/misc/typedefs.h"
#include "game/misc/typedefs.h"
#include <unordered_map>




namespace Game {
    class GameWorld : public Engine::World {
    //this should share the same uid system as base class
    //I know its kinda messy but eh i dont wanna trade performance
    std::unordered_map<obj_id_t, mask_t> gameobject_map;

public:
    static GameWorld _instance;
    void Update() {

    }
};
}
