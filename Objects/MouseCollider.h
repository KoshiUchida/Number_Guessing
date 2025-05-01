#pragma once
#include "ObjectBace.h"
#include "../Common/Collisions.h"

class MouseCollider final:
    public ObjectBace
{
private:
	Collisions::BoxCollision m_Collider;

public:
	MouseCollider();
	~MouseCollider();
	void Initialize() override final;
	void Update() override final;
	void Render(const Camera& camera) override final;
	void Finalize() override final;
};

