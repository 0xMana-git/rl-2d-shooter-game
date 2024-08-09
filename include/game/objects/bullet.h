#pragma once

#include "engine/math/polygon.h"
#include "game/objects/gameobject.h"
#include "game/gameworld.h"
#include "game/misc/typedefs.h"


namespace Game {


    class Bullet : public UpdatedGameObject {

        
        Engine::TrianglePolygon* _collider;



        Bullet(obj_id_t id) : UpdatedGameObject(id){

        }
    };
}