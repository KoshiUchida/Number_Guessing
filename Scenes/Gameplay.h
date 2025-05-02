/**
 * @file   Gameplay.h
 *
 * @brief  �Q�[���v���C�V�[���̃w�b�_�t�@�C��
 *
 * @author CatCode
 * @date   2025/04/27
 */

#pragma once
#include "SceneBace.h"
#include <memory>

/// <summary>
/// �Q�[���v���C�V�[��
/// </summary>
class Gameplay
	: public SceneBace
{
private:
	int m_FontSize;

public:
	// Main System
	Gameplay();
	~Gameplay() noexcept;
	void Initialize() override final;
	void Update()     override final;
	void Render()     override final;
	void Finalize()   override final;
};

