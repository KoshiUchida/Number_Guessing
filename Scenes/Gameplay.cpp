/**
 * @file   GameplayScene.cpp
 *
 * @brief  �Q�[���v���C�V�[���̃\�[�X�t�@�C��
 *
 * @author CatCode
 *
 * @date   2025/04/21
 */

#include "Gameplay.h"

#include <DxLib.h>
#include "../WindowSettingItems.h"
#include "../Common/Colors.h"

#include "../Common/Collisions.h"

#include "../Manager/ObjectManager.h"

using namespace std;

/// <summary>
/// Constructor
/// </summary>
Gameplay::Gameplay()
	: SceneBace()
	, m_FontSize{}
{
}

/// <summary>
/// Destructor
/// </summary>
Gameplay::~Gameplay() noexcept = default;

/// <summary>
/// ����������
/// </summary>
void Gameplay::Initialize()
{
	// Font Size
	m_FontSize = p_wsi->GetWindowSetting().FontSize;
	SetFontSize(m_FontSize);

	// Object Set
	ObjectManager& om{ ObjectManager::GetInstance() };

	//process Uchida
	//process Watanabe
}

/// <summary>
/// �X�V����
/// </summary>
void Gameplay::Update()
{
}

/// <summary>
/// �`�揈��
/// </summary>
void Gameplay::Render()
{
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255);

#if defined(_DEBUG)
	DrawString(p_wsi->ScreenRight() - m_FontSize * 13, p_wsi->ScreenBottom() - m_FontSize * 2, "GameplayScene", Colors::Cyan);
#endif
}

/// <summary>
/// �I������
/// </summary>
void Gameplay::Finalize()
{
}