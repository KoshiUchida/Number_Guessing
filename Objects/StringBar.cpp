/**
 * @file   StringBar.cpp
 *
 * @brief  ������\���I�u�W�F�N�g�̃\�[�X�t�@�C��
 *
 * @author CatCode
 * 
 * @date   2025/05/04
 */
#include "StringBar.h"

#include <DxLib.h>
#include "../Manager/ObjectManager.h"
#include "../WindowSettingItems.h"
#include "../Common/CCRandom.h"
#include "../Common/Colors.h"

StringBar::StringBar() noexcept :
	ObjectBace(Transform2D()),
	m_Answer{}
{
}

StringBar::~StringBar() noexcept = default;

void StringBar::Initialize()
{
	// ���̂̎擾
	ObjectManager& om { ObjectManager::GetInstance() };
	CCRandom&      ccr{ CCRandom::GetInstane() };
	WSI&           wsi{ WSI::GetInstance() };

	m_Transform = Position2D(wsi.ScreenCenterX(), wsi.ScreenCenterY());

	// 0�`9�̃{�^���I�u�W�F�N�g�̐���
	float PosX{ static_cast<float>(wsi.ScreenCenterX() - 300.f) };
	for (int i = 0; i < 10; i++, PosX += 65.f)
	{
		std::string Num{ std::to_string(i) };
		om.AddObject(Num, std::make_unique<Botton>(Num, Position2D(PosX, wsi.ScreenCenterY() + 80.f)));
		p_Bottons.push_back(static_cast<Botton*>(om.GetObjectPtr(Num)));
	}

	// �G���^�[�{�^���I�u�W�F�N�g�̐���
	om.AddObject("��", std::make_unique<Botton>("��", Position2D(PosX, wsi.ScreenCenterY() + 80.f)));
	p_Bottons.push_back(static_cast<Botton*>(om.GetObjectPtr("��")));

	// �����̎擾
	m_Answer = ccr.Rand(0, 100);

	// �q���g������֓���
	m_Hint = "0�`100�܂ł̐����𓖂Ă悤�I";
}

void StringBar::Update()
{
	for (int i{ 0 }; i < p_Bottons.size(); i++)
	{
		// �{�^���������ꂽ��
		if (p_Bottons[i]->GetPressed())
		{
			// �G���^�[�{�^���͐��ۂ̔��ʂ�����
			if (p_Bottons[i]->GetString() == "��")
			{
				int num = std::stoi(m_InputString);

				if (num == m_Answer)
				{
					m_Hint = "�����I";

					for (int i{ 0 }; i < p_Bottons.size(); i++)
						p_Bottons[i]->Destroy();
					p_Bottons.clear();
					break;
				}
				else if (num > m_Answer)
					m_Hint = "��������I";
				else if(num < m_Answer)
					m_Hint = "�傫����I";


				m_InputString = std::string();
			}

			// �����{�^���͕�����ɐ��������
			else
				m_InputString += p_Bottons[i]->GetString();
		}
	}
}

void StringBar::Render(const Camera& camera)
{
	WSI& wsi = { WSI::GetInstance() };

#if defined(_DEBUG)
	DrawString(wsi.ScreenCenterX(), wsi.ScreenCenterY() - 200.f, std::to_string(m_Answer).c_str(), Colors::White);
#endif

	DrawString(wsi.ScreenCenterX() - 80.f, wsi.ScreenCenterY() - 100.f, m_Hint.c_str(), Colors::White);

	DrawString(m_Transform.GetPositionX(), m_Transform.GetPositionY(), m_InputString.c_str(), Colors::White);
}

void StringBar::Finalize()
{
	p_Bottons.clear();
}
