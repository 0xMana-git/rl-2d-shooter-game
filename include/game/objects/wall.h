#pragma once

#include "engine/math/polygon.h"
#include "game/objects/gameobject.h"
#include "game/gameworld.h"
#include "game/misc/typedefs.h"


namespace Game {


    class Wall : public GameObject {

        
        Engine::QuadConvexPolygon* _collider;


        Wall(obj_id_t id) : GameObject(id){

        }
    };
}