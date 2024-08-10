#include <numbers>
#include <iostream>

#include "engine/math/triangle.h"
#include "engine/math/polygon.h"
#include "engine/math/matrix.h"
#include "engine/utils/tostrs.h"
#include "engine/world.h"
#include "game/gameworld.h"

#include "game/objects/player.h"

using namespace Engine;
using namespace Game;
int main() { 
    Player& p = Player::Create();
    Player& p2 = Player::Create(Vec2(0, 10));
    p.Init();
    p2.Init();

    while(1){
        p.MoveAndCollide(Vec2(0,0.5));
        std::cout << p.origin << "\n";
        std::string a;
        std::cin >> a;
    }
    
    //std::cout << r2 << "\n";
    //r1.Rotate(std::numbers::pi * 0.25);
    //std::cout << r1 << "\n";
}