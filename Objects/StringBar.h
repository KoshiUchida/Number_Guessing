#pragma once
#include "ObjectBace.h"

#include <vector>
#include "Botton.h"

class StringBar final:
    public ObjectBace
{
private:
	std::vector<Botton*> p_Bottons;

	std::string m_InputString;

	int m_Answer;

	std::string m_Hint;

public:
    StringBar() noexcept;
    ~StringBar() noexcept;
	void Initialize() override;
	void Update() override;
	void Render(const Camera& camera) override;
	void Finalize() override;
};

