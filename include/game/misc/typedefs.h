#pragma once
#include <cstddef>


using mask_t = size_t;

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