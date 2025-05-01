#include "MouseCollider.h"
#include <DxLib.h>
#include "../WindowSettingItems.h"
#include "../Common/Colors.h"

MouseCollider::MouseCollider() :
	ObjectBace(Transform2D()),
	m_Collider{Position2D(), 10.f, 10.f }
{
}

MouseCollider::~MouseCollider()
{
}

void MouseCollider::Initialize()
{
}

void MouseCollider::Update()
{
	int mousePosX{}, mousePosY{};

	GetMousePoint(&mousePosX, &mousePosY);

	m_Transform.SetPosition(Position2D(mousePosX, mousePosY));

	m_Collider.SetPosition(m_Transform.GetPosition());
}

void MouseCollider::Render(const Camera& camera)
{
	Collisions::Box box = m_Collider.GetBox();
	DrawBox(box.left, box.top, box.right, box.bottom, Colors::Cyan, true);

	if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0)
	{
		WSI& p_wsi{ WSI::GetInstance() };
		DrawString(p_wsi.ScreenCenterX(), p_wsi.ScreenCenterY() + 50.f, "Mouse L-Click!!", Colors::White);
	}
}

void MouseCollider::Finalize()
{
}
