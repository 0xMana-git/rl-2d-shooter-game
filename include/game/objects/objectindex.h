#pragma once

#include "game/misc/typedefs.h"
#include "engine/misc/typedefs.h"
#include <unordered_map>

namespace Game {
    template<typename T>
    class ObjectIndex {
    public:
        inline static std::unordered_map<obj_id_t, T> objects_index;


    };
}
