#include "engine/misc/typedefs.h"
#include "engine/math/vector.h"
#include "engine/math/polygon.h"
#include "game/misc/typedefs.h"
#include "game/gameworld.h"

#include <unordered_map>


namespace Game {
    //Every gameobject definitely has a collider, it just uses different ones 
    class GameObject {

        
    protected:
        inline static obj_id_t id_counter = 0;
        bool initialized = false;
        
        //remember to dynamically resolve the type of the collider and call the templated functions
        Engine::PolygonBase* p_collider = nullptr;
        //Remember to sync collider origin manually(lol)
        
    public:
        Engine::Vec2 origin;
        obj_id_t id;
        std::unordered_map<obj_id_t, GameObject*> gameObjects;

        //Must call this to explicitly initialize
        obj_id_t Init() {
            this->initialized = true;
            this->id = id_counter;
            id_counter++;
            GameWorld::_instance.AddObject(p_collider, this->id);
            return this->id;
        }
        GameObject(const Engine::Vec2& origin) {
            this->origin = origin;
        }

        std::optional<obj_id_t> MoveAndCollide(const Engine::Vec2& vec) {
            auto res = GameWorld::_instance.MoveObjectAndCollide(id, vec);
            this->origin = p_collider->origin;
            return res;
        }
        GameObject() {};
        virtual ~GameObject();
    };


    class UpdatedGameObject : public GameObject { 

    public:
    std::unordered_map<obj_id_t, UpdatedGameObject*> updatedGameObjects;
        Engine::Vec2 velocity, acceleration;
        double rotation;
        virtual void Update();

        UpdatedGameObject(const Engine::Vec2& origin) : GameObject(origin) {};
        UpdatedGameObject() : GameObject() {};
        virtual ~UpdatedGameObject();
    };
}
