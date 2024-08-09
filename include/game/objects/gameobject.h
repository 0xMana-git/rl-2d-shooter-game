#include "engine/misc/typedefs.h"
#include "engine/math/vector.h"
#include "engine/math/polygon.h"
#include "game/misc/typedefs.h"

#include <unordered_map>


namespace Game {
    //Every gameobject definitely has a collider, it just uses different ones 
    class GameObject {

        
    protected:
        inline static obj_id_t id_counter = 0;
        obj_id_t id;
        //remember to dynamically resolve the type of the collider and call the templated functions
        Engine::PolygonBase* p_collider;
        //Remember to sync collider origin manually(lol)
        Engine::Vec2 origin;
    public:
        std::unordered_map<obj_id_t, GameObject*> gameObjects;
        GameObject(){
            this->id = id_counter;
            id_counter++;
        }
        virtual ~GameObject();
    };


    class UpdatedGameObject : public GameObject { 

    public:
    std::unordered_map<obj_id_t, UpdatedGameObject*> updatedGameObjects;
        Engine::Vec2 velocity, acceleration;
        virtual void Update();

        UpdatedGameObject() : GameObject() {};

        virtual ~UpdatedGameObject();
    };
}
