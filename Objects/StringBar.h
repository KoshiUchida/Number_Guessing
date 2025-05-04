/**
 * @file   StringBar.h
 *
 * @brief  ������\���I�u�W�F�N�g�̃w�b�_�[�t�@�C��
 *
 * @author CatCode
 *
 * @date   2025/05/04
 */
#pragma once
#include "ObjectBace.h"

#include <vector>
#include "Botton.h"

class StringBar final:
    public ObjectBace
{
private:
	// �{�^���I�u�W�F�N�g�ւ̃|�C���^
	std::vector<Botton*> p_Bottons;

	// ���͕�����
	std::string m_InputString;

	// ����
	int m_Answer;

	// �q���g
	std::string m_Hint;

public:
	/*Main System*/
    StringBar() noexcept;
    ~StringBar() noexcept;
	void Initialize() override;
	void Update() override;
	void Render(const Camera& camera) override;
	void Finalize() override;
};

