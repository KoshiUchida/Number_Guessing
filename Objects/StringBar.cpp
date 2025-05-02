#include "StringBar.h"

#include "../Manager/ObjectManager.h"
#include "../WindowSettingItems.h"
#include "../Common/CCRandom.h"

#include <DxLib.h>

#include "../Common/Colors.h"

StringBar::StringBar() noexcept :
	ObjectBace(Transform2D()),
	m_Answer{}
{
}

StringBar::~StringBar() noexcept = default;

void StringBar::Initialize()
{
	ObjectManager& om = { ObjectManager::GetInstance() };
	WSI& wsi = { WSI::GetInstance() };

	m_Transform = Position2D(wsi.ScreenCenterX(), wsi.ScreenCenterY());

	float PosX{ static_cast<float>(wsi.ScreenCenterX() - 300.f) };

	for (int i = 0; i < 10; i++, PosX += 65.f)
	{
		std::string Num{ std::to_string(i) };
		om.AddObject(Num, std::make_unique<Botton>(Num, Position2D(PosX, wsi.ScreenCenterY() + 80.f)));
		p_Bottons.push_back(static_cast<Botton*>(om.GetObjectPtr(Num)));
	}

	om.AddObject("←", std::make_unique<Botton>("←", Position2D(PosX, wsi.ScreenCenterY() + 80.f)));
	p_Bottons.push_back(static_cast<Botton*>(om.GetObjectPtr("←")));

	CCRandom& ccr{ CCRandom::GetInstane() };

	m_Answer = ccr.Rand(0, 100);

	m_Hint = "数当てゲーム！";
}

void StringBar::Update()
{
	for (int i{ 0 }; i < p_Bottons.size(); i++)
	{
		if (p_Bottons[i]->GetPressed())
		{
			if (p_Bottons[i]->GetString() == "←")
			{
				int num = std::stoi(m_InputString);

				if (num == m_Answer)
				{
					m_Hint = "正解！";

					for (int i{ 0 }; i < p_Bottons.size(); i++)
						p_Bottons[i]->Destroy();
					p_Bottons.clear();
					break;
				}
				else if (num > m_Answer)
					m_Hint = "小さいよ！";
				else if(num < m_Answer)
					m_Hint = "大きいよ！";


				m_InputString = std::string();
			}
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

	DrawString(wsi.ScreenCenterX(), wsi.ScreenCenterY() - 100.f, m_Hint.c_str(), Colors::White);

	DrawString(m_Transform.GetPositionX(), m_Transform.GetPositionY(), m_InputString.c_str(), Colors::White);
}

void StringBar::Finalize()
{
	p_Bottons.clear();
}
