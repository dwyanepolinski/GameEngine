#ifndef ECS_COMPONENT_H
#define ECS_COMPONENT_H

#include "../../context.h"
#include "../../../math/vect.h"

#define MAX_MAP_SIZE 64

namespace Components {
    int 
    NONE         = 0,
    POSITION     = 1 << 0,
    DISPLACEMENT = 1 << 1,
    SIZE         = 1 << 2,
    TEXTURE      = 1 << 3,
    COLLISION    = 1 << 4;
}

class Component {
    public:

    virtual bool set(const int variable, std::string value) {};
};

typedef Component* ComponentCreator();

template<class T> Component* create() { return new T; };

class PositionComponent: public Component {
    const int id = Components::POSITION;
    enum Vars { X = 0, Y = 1 };

    public:

    bool set(const int variable, std::string value) {
        switch (variable) {
        case Vars::X: {
            coordinates.x = std::stoi(value);
            return true;    
        }
        case Vars::Y: {
            coordinates.y = std::stoi(value);
            return true;    
        }
        default:
            return false;
        }
    }

    vect coordinates;
};

class DisplacementComponent: public Component {
    const int id = Components::DISPLACEMENT;
    enum Vars { V = 0, CONTROL = 1 };

    public:

    bool set(const int variable, std::string value) {
        switch (variable) {
        case Vars::V: {
            v = std::stof(value);
            return true;    
        }
        case Vars::CONTROL: {
            controllable = (bool)std::stoi(value);
            return true;    
        }
        default:
            return false;
        }
    }

    vect velocity;
    double v;
    bool controllable = false;
};

class SizeComponent: public Component {
    const int id = Components::SIZE;
    enum Vars { W = 0, H = 1 };

    public:

    bool set(const int variable, std::string value) {
        switch (variable) {
        case Vars::W: {
            w = std::stoi(value);
            return true;    
        }
        case Vars::H: {
            h = std::stoi(value);
            return true;    
        }
        default:
            return false;
        }
    }

    int w;
    int h;
};

class TextureComponent: public Component {
    // remember to set dst_rect x y from entity position
    const int id = Components::TEXTURE;
    enum Vars { W = 0, H = 1, TEXTURE = 2, LAYER = 3 };

    public:

    bool set(const int variable, std::string value) {
        switch (variable) {
        case Vars::W: {
            dst_rect.w = std::stoi(value);
            return true;    
        }
        case Vars::H: {
            dst_rect.h = std::stoi(value);
            return true;    
        }
        case Vars::TEXTURE: {
            texture_id = std::stoi(value);
            return true;    
        }
        case Vars::LAYER: {
            layer = std::stoi(value);
            return true;    
        }
        default:
            return false;
        }
    }

    SDL_Rect src_rect;
    SDL_Rect dst_rect;
    int layer;
    int texture_id;
};

class CollisionComponent: public Component {
    const int id = Components::COLLISION;
    enum Vars { 
        BBX = 0, 
        BBY = 1, 
        BBW = 2, 
        BBH = 3,
        BB_INHERIT_SIZE = 4,
        GROUP = 5
    };

    public:

    bool set(const int variable, std::string value) {
        switch (variable) {
        case Vars::BBX: {
            bbx = std::stoi(value);
            return true;    
        }
        case Vars::BBY: {
            bby = std::stoi(value);
            return true;    
        }
        case Vars::BBW: {
            bbw = std::stoi(value);
            return true;    
        }
        case Vars::BBH: {
            bbh = std::stoi(value);
            return true;    
        }
        case Vars::BB_INHERIT_SIZE: {
            bb_inherit_size = (bool)std::stoi(value);
            return true;    
        }
        case Vars::GROUP: {
            group = std::stoi(value);
            return true;    
        }
        default:
            return false;
        }
    }

    int bbx, bby, bbw, bbh;
    bool bb_inherit_size = false;
    int group;
};

namespace ComponentManager {
    namespace {

        ComponentCreator* component_creators[] = {
            create<PositionComponent>,
            create<DisplacementComponent>,
            create<SizeComponent>,
            create<TextureComponent>,
            create<CollisionComponent>
        };

        IList<IList<Component*>*> component_entity_rel;
        GameContext* ctx;
    }

    void init(GameContext* c) {
        // component_entity_rel = IList<IList<Component*>*>();
        ctx = c;
    }

    const int count() { return component_entity_rel.count(); }

    void add(const int entity_id, const int component_id) {
        if(component_id == Components::NONE || entity_id < 0)
            return;
        if(!component_entity_rel.exists(entity_id)) {
            component_entity_rel.add_with_id(new IList<Component*>(), entity_id);
        }
        component_entity_rel[entity_id]->add_with_id(component_creators[(int)(log(component_id)/log(2))](), component_id);
    }

    void remove(const int entity_id, const int component_id) {
        if(component_id == Components::NONE || entity_id < 0)
            return;
        if(component_entity_rel.exists(entity_id)) 
            component_entity_rel[entity_id]->remove(component_id);
    }

    void remove_all(int entity_id) {
        component_entity_rel.remove(entity_id);
    }

    Component* get(const int entity_id, const int component_id) {
        if(component_entity_rel.exists(entity_id) && component_entity_rel[entity_id]->exists(component_id))
            return (*component_entity_rel[entity_id])[component_id];
        return nullptr;
    }
}

#endif