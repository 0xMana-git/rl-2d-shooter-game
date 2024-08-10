#pragma once
#include <cstddef>


using mask_t = size_t;



namespace GameObjectTypeEnum {
    enum GameObjectTypeEnum{
        NONE = 0,
        WALL = 1,
        PLAYER = 2,
        BULLET = 3,
        
    };
    
}
using pixel_t = GameObjectTypeEnum::GameObjectTypeEnum;

namespace ObjectMaskEnum {
    //im just cramming all types here but it will be a problem if theres too many
    //i have 64 flags anyway kekekekek
    enum ObjectMaskEnum {
        UPDATE,
        TYPE_PLAYER,
        TYPE_BULLET,
        TYPE_WALL,

    };
}