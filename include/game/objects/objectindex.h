#pragma once

#include "game/misc/typedefs.h"
#include "engine/misc/typedefs.h"
#include "engine/math/vector.h"
#include "lib/MemoryPool.h"
#include <memory>
namespace Game {
    template<typename T>
    class ObjectIndex {
        // using internal_id_t = size_t;
        // internal_id_t _internal_id = 0;
        // inline static internal_id_t _internal_ctr = 0;

        //4096 elems by default
        
        //static std::vector<T> _pool;
    protected:
        //when object is destroyed, free memory
        ~ObjectIndex();
    public:
        
        //Only creates, does not call init
        static T& Create(const Engine::Vec2& origin);

        static T& Create() {
            return Create(Engine::Vec2(0,0));
        }

    };
    namespace StaticMemoryPool {
        template<typename T>
        inline static MemoryPool<T> _pool;
    }
    template<typename T>
    T& ObjectIndex<T>::Create(const Engine::Vec2& origin) {
            
            T* new_obj = StaticMemoryPool::_pool<T>.allocate();
            //amazing
            std::construct_at(new_obj, origin);
            //idk dude, i feel like theres no reason not to call here
            new_obj->Init();
            return *new_obj;
            
        }
    template<typename T>
    ObjectIndex<T>::~ObjectIndex() {
            StaticMemoryPool::_pool<T>.deallocate(static_cast<T*>(this));
        }
}
