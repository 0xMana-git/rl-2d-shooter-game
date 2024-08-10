#pragma once

#include "engine/math/polygon.h"
#include "game/objects/gameobject.h"
#include "game/gameworld.h"
#include "game/misc/typedefs.h"

#include "game/objects/objectindex.h"

namespace Game
{

    class Player : public UpdatedGameObject, public ObjectIndex<Player>
    {

        Engine::TrianglePolygon collider;

    public:
        struct PlayerView
        {
            constexpr static size_t n_pixels = 16;
            struct Pixel
            {
                double depth;
                pixel_t type;
            };
            std::array<Pixel, n_pixels> _data;
        };
        PlayerView _player_view;
        // Dont use this
        Player() {};

        Player(const Engine::Vec2 &origin) : UpdatedGameObject(origin)
        {
            collider = Engine::TrianglePolygon(origin, {origin + Engine::Vec2(0, 1.6), origin + Engine::Vec2(-1.6, -3.2), origin + Engine::Vec2(1.6, -3.2)});
            p_collider = &collider;
        }

        void Rotate(double rad);
        virtual ~Player();

        PlayerView &GetView();
    };
}