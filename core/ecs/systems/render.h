#ifndef ECS_SYSTEMS_RENDER_H
#define ECS_SYSTEMS_RENDER_H

#include "../manager.h"
#include <map>
#include <algorithm>


bool texture_component_pointer_comp(TextureComponent* tx1, TextureComponent* tx2) {
    return tx1->layer < tx2->layer;
}

class RenderSystem: public System {
    private:
    
    bool renderables_sorted = false;
    std::vector<TextureComponent*> texture_components;
    std::map<TextureComponent*, PositionComponent*> texture_position_rel;

    void sort_renderables() {
        std::vector<int> renderables = SystemManager::get_system_entities(this->id());
        for(auto const enitity_id : renderables)
            texture_components.emplace_back((TextureComponent*)ComponentManager::get(enitity_id, Components::TEXTURE));

        std::sort(texture_components.begin(), texture_components.end(), texture_component_pointer_comp);
        texture_position_rel.clear();
        for(auto const texture_component : texture_components) {
            std::sort(texture_component->rects.begin(), texture_component->rects.end());
            auto position_component = (PositionComponent*)ComponentManager::get(texture_component->get_entity_id(), Components::POSITION);
            texture_position_rel.insert({texture_component, position_component});
        }
        renderables_sorted = true;
    }

    public:

    RenderSystem() : System() {
        _mask = (Components::POSITION|Components::TEXTURE);
    }

    void handle_events() {}

    void update() {
        if(!renderables_sorted)
            sort_renderables();
        SDL_RenderClear(ECSManager::ctx->renderer());
        for(const auto& kv : texture_position_rel)
            render_textures(kv.first, kv.second);
        SDL_RenderPresent(ECSManager::ctx->renderer());
    }

    void render_textures(const TextureComponent* tx_cmp, const PositionComponent* pos_cmp) {
        auto texture = ECSManager::textures_db[tx_cmp->texture_id];

        for(auto pair : tx_cmp->rects) {
            pair.dst_rect.x += pos_cmp->coordinates.x;
            pair.dst_rect.y += pos_cmp->coordinates.y;
            SDL_RenderCopy(ECSManager::ctx->renderer(), texture, pair.src_rect, &pair.dst_rect);
        }
    }

}; 

#endif
