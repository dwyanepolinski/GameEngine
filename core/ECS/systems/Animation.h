#pragma once

#include "../System.h"
#include "../Entity.h"

#define ANIMATION_MASK (COMPONENT_ANIMATION)

namespace AnimationSystem
{

unsigned int getEventIndex(unsigned int entity, Event e)
{
	for (unsigned int i = 0, end = Entity::events[entity].size(); i < end; ++i)
	{
		if (Entity::events[entity][i] == e)
			return i;
	}
	return -1;
}

void setNextTexture(unsigned int entity, Event e)
{
	static unsigned int i = 0;
	unsigned int eventIndex = getEventIndex(entity, e);
	unsigned int size = Entity::animation[entity].animations[eventIndex].size();
	Entity::texture[entity].texture = Entity::textures[Entity::animation[entity].animations[eventIndex][i]];
	unsigned int n = Entity::animation[entity].animations[eventIndex][i];
	Entity::texture[entity].texture_id = n;
	i = (i + 1) % size;
}

void eventsHandling(event_obj event)
{
	switch (event.event_t)
	{
	case Event::START_MOVE_RIGHT:
		setNextTexture(event.entity_id, START_MOVE_RIGHT);
		break;
	case Event::START_MOVE_LEFT:
		setNextTexture(event.entity_id, START_MOVE_LEFT);
		break;
	case Event::IDLE:
		break;
	default:
		break;
	}
}

void addEventAnimation(unsigned int entity, Event e)
{
	Entity::events[entity].push_back(e);
	Entity::animation[entity].animations.push_back(std::vector<unsigned int>());
}

} // namespace AnimationSystem