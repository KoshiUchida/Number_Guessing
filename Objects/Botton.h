#pragma once
#include "ObjectBace.h"

#include "../Common/Collisions.h"

class Botton :
    public ObjectBace
{
private:
	std::string m_String;

	float m_FontSize;

	Collisions::BoxCollision m_Collider;

	Collisions::BoxCollision* p_PlayerCollider;

	bool m_IsPressing;
	bool m_IsPressedB;
	bool m_IsPressed;

public:
    Botton(const std::string& string, const Position2D& pos) noexcept;
    ~Botton() noexcept;
	void Initialize() override;
	void Update() override;
	void Render(const Camera& camera) override;
	void Finalize() override;

	bool GetPressed() const;
	std::string GetString() const { return m_String; }
};

