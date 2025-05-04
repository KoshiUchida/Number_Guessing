/**
 * @file   StringBar.h
 *
 * @brief  文字列表示オブジェクトのヘッダーファイル
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
	// ボタンオブジェクトへのポインタ
	std::vector<Botton*> p_Bottons;

	// 入力文字列
	std::string m_InputString;

	// 答え
	int m_Answer;

	// ヒント
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

