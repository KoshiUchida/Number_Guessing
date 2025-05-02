#include "Botton.h"

#include "../Common/Camera.h"
#include <DxLib.h>
#include "../Common/Colors.h"
#include "../Manager/ObjectManager.h"
#include "MouseCollider.h"
#include "../WindowSettingItems.h"

Botton::Botton(const std::string& string, const Position2D& pos) noexcept :
	ObjectBace(Transform2D(pos, 0.f)),
	m_String{ string },
	m_FontSize{},
	m_Collider{ pos, 50.f, 50.f },
	m_IsPressing{},
	m_IsPressed{},
	m_IsPressedB{},
	p_PlayerCollider{ nullptr }
{
}

Botton::~Botton() noexcept = default;

void Botton::Initialize()
{
	p_PlayerCollider = static_cast<MouseCollider*>(ObjectManager::GetInstance().GetObjectPtr("Mouse"))->GetCollider();
	m_FontSize = WSI::GetInstance().GetWindowSetting().FontSize;
}

void Botton::Update()
{
	m_IsPressing = Collisions::Detection(*p_PlayerCollider, m_Collider);

	m_IsPressed = m_IsPressing && !m_IsPressedB && (GetMouseInput() & MOUSE_INPUT_LEFT) != 0;

	m_IsPressedB = m_IsPressing && (GetMouseInput() & MOUSE_INPUT_LEFT) != 0;

}

static constexpr unsigned int Color{ Colors::White };
static constexpr unsigned int OverColor{ Colors::Gray };

void Botton::Render(const Camera& camera)
{
	Position2D pos = m_Transform.GetPosition();

	Collisions::Box box = m_Collider.GetBox();
	if (m_IsPressing)
	{
		if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0)
			DrawBox(box.left, box.top, box.right, box.bottom, Color, true);
		else
			DrawBox(box.left, box.top, box.right, box.bottom, OverColor, true);
	}

	DrawString(pos.x() - m_FontSize / 2.7f, pos.y() - m_FontSize / 2.2f, m_String.c_str(), Color);

	DrawBox(box.left, box.top, box.right, box.bottom, Color, false);
}

void Botton::Finalize()
{
}

bool Botton::GetPressed() const
{
	return m_IsPressed;
}
