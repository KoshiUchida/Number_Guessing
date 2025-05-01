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

#include "../Common/CCRandom.h"

#include "../Objects/MouseCollider.h"

using namespace std;

/// <summary>
/// Constructor
/// </summary>
Gameplay::Gameplay() :
	SceneBace() ,
	m_FontSize{},
	m_Answer{}
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

	om.AddObject("Mouse", make_unique<MouseCollider>());

	CCRandom& ccr{ CCRandom::GetInstane() };

	m_Answer = ccr.Rand(0, 100);
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

	DrawString(p_wsi->ScreenCenterX(), p_wsi->ScreenCenterY(), to_string(m_Answer).c_str(), Colors::White);

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