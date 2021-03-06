#pragma once
#include <vector>
#include <glm/glm.hpp>
#include "Renderable.h"
#include "Moving.h"
#include "SFML/Graphics.hpp"
#include "Path.h"

class Agent;

class Formation : public Renderable, public Moving
{
public:
	struct Location
	{
		float orientation;
		float distance;
	};

	Formation();
	~Formation();
	
	int registerSoldier(Agent* ag);
	glm::vec2 GetPositionForIndex(int index);
	void SetPath(Path* newpath);
	
	void Render(sf::RenderWindow* window) override;
	void DebugDraw(sf::RenderWindow* window) override;

	void Move(sf::Time delta) override;
	void SetRotation(float rot);
	void SetPosition(glm::vec2 pos);

	void AddSlot(Location tmp);
	void AddSlot(float orient, float dist);

	glm::vec2 Seek(const glm::vec2 currentVelocity, glm::vec2 currentTarget);
	glm::vec2 truncate(glm::vec2 totrunc, float) const;

protected:
	std::vector<Location> slots;
	int currIndex;

	glm::vec2 position;
	glm::vec2 velocity;
	float maxSpeed = 120.0f;
	float steeringForce = 6.0f;
	glm::vec2 target;

	glm::vec2 leaderPos;
	float orientation;

	Path* pathtofollow;
	int currentWaypoint = 0;
	float tolerance = 5.0f;

	std::vector<Agent*> agents;
};
