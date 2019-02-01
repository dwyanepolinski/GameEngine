#pragma once

#include "../System.h"
#include "../Entity.h"

#define ANIMATION_MASK (COMPONENT_ANIMATION)

namespace AnimationSystem
{
//zwracamy indeks pierwszego wystąpienia danego eventu
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

anim_params& getAnimationParams(unsigned int entity,int event_index){
	return Entity::animation_params[entity][event_index];//wyciągamy parametry animacji
}

void resetTimerForAnimationStep(anim_params& animationParams){

	animationParams.timer = animationParams.period;
	/* 	animationParams.timer = animationParams.period+ animationParams.timer; <-- być może trzeba by startować od period 
		już pomniejszonego o aktualną wartość timera (reset następuje gdy jest ona ujemna)
		takie podejście skraca czas który musi upłynąć aby następna tekstura została ustawiona
	*/
}

void endOfAnimationStep(anim_params& animationParams){
	animationParams.ttl--;
	resetTimerForAnimationStep(animationParams);
}

bool if_endOfAnimation(anim_params& animationParams){
	bool end_anim = animationParams.ttl==0? true : false;
	if(end_anim) animationParams.ttl = 2;
	return end_anim;
}

bool if_timeForStepOfAnimation(anim_params& animationParams){
	return animationParams.timer > 0 ? false : true;
}

void updateAnimationTimer(anim_params& animationParams){
	animationParams.timer -= Game::dt;
}

void animationTimerHandling(event_obj& event){

	int event_index = getEventIndex(event.entity_id,event.event_t);
	anim_params &ap =getAnimationParams(event.entity_id,event_index);
	updateAnimationTimer(ap);
		
    if (if_timeForStepOfAnimation(ap)){
		setNextTexture(event.entity_id, event.event_t);
		endOfAnimationStep(ap);
		if (if_endOfAnimation(ap)) event.alive = false;
	}	
}

void eventsHandling(event_obj& event)
{
	switch (event.event_t)
	{
	case Event::START_MOVE_RIGHT_ANIM:
		animationTimerHandling(event);
		break;
	case Event::START_MOVE_LEFT:
		animationTimerHandling(event);
		break;
	case Event::IDLE:
		break;
	default:
		break;
	}
}


event_obj createEvent(unsigned int entity, Event event_type){
	event_obj e;
    e.entity_id = entity;
    e.event_t = event_type;
    e.alive = true;
	return std::move(e);
}

void addEventAnimation(unsigned int entity, Event e)
{
	Entity::events[entity].push_back(e);
	Entity::animation[entity].animations.push_back(std::vector<unsigned int>());//ten dodawany wektor jest na tekstury animacji
	Entity::animation_params[entity].emplace_back();
}

} // namespace AnimationSystem