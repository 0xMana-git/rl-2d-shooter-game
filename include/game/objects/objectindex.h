#pragma once

#include "game/misc/typedefs.h"
#include "engine/misc/typedefs.h"
#include "engine/math/vector.h"
#include <unordered_map>

namespace Game {
    template<typename T>
    class ObjectIndex {
    public:
        inline static std::unordered_map<obj_id_t, T> objects_index;
        static T& Create(const Engine::Vec2& origin) {
            T obj(origin);
            objects_index.emplace(obj.Init(), obj);
            return objects_index[obj.id];
        }

        static T& Create() {
            return Create(Engine::Vec2(0,0));
        }

    };
}
