#pragma once

#include "engine/math/polygon.h"
#include "game/objects/gameobject.h"
#include "game/gameworld.h"
#include "game/misc/typedefs.h"

#include "game/objects/objectindex.h"

namespace Game {


    class Player : public UpdatedGameObject, public ObjectIndex<Player> {

        Engine::TrianglePolygon collider;

        

        

    public:
        Player() : UpdatedGameObject(){
            p_collider = &collider;
        }
        static Player& Create() {
            objects_index.emplace(id_counter - 1, Player());
            return objects_index[id_counter - 1];
        }
        void Rotate(double rad) {
            
        };
        virtual ~Player();
    };
}