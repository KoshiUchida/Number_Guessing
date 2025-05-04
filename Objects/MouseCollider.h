/**
 * @file   MouseCollider.h
 *
 * @brief  �}�E�X�I�u�W�F�N�g�̃w�b�_�t�@�C��
 *
 * @author CatCode
 *
 * @date   2025/05/04
 */
#pragma once
#include "ObjectBace.h"

#include "../Common/Collisions.h"

class MouseCollider final:
    public ObjectBace
{
private:
	// ���^�̂����蔻��
	Collisions::BoxCollision m_Collider;

public:
	/*Main System*/
	MouseCollider();
	~MouseCollider();
	void Initialize() override final;
	void Update() override final;
	void Render(const Camera& camera) override final;
	void Finalize() override final;

	Collisions::BoxCollision* GetCollider();
};

