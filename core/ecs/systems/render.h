#ifndef ECS_SYSTEMS_RENDER_H
#define ECS_SYSTEMS_RENDER_H

#include "../manager.h"


class RenderSystem: public System {
    const int _mask = (Components::POSITION|Components::TEXTURE);

    public:

    void handle_events() {}

    void update() {
        SDL_RenderClear(ECSManager::ctx.renderer());
        for(auto const entity_id : SystemManager::get_system_entities(this->id()))
            render_texture(entity_id);
        SDL_RenderPresent(ECSManager::ctx.renderer());
    }

    void render_texture(const int entity_id) {
        auto texture_component = (TextureComponent*)ComponentManager::get(entity_id, Components::TEXTURE);
        auto position_component = (PositionComponent*)ComponentManager::get(entity_id, Components::POSITION);
        auto texture = ECSManager::textures_db[texture_component->texture_id];

        texture_component->dst_rect.x = (int) position_component->coordinates.x;
        texture_component->dst_rect.y = (int) position_component->coordinates.y;
        
        SDL_RenderCopy(ECSManager::ctx.renderer(), texture, NULL, &texture_component->dst_rect);
    }

}; 

#endif
