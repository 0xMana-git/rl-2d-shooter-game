#include "game/objects/gameobject.h"


using namespace Game;


GameObject::~GameObject() {
    gameObjects.erase(id);
}   

void UpdatedGameObject::Update()
{
    velocity += acceleration;
    origin += velocity;
        
};


UpdatedGameObject::~UpdatedGameObject() {
    updatedGameObjects.erase(id);
}

