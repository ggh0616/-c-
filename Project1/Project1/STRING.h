//------------------------------------------------------------------
// STRING.h
// ǥ�� string�� ���� ������ �ϴ� class
// 2022�� 11�� 7�� c++										9���� 2��
// 2022�� 11�� 7�� �̵�����
//------------------------------------------------------------------

#pragma once

class STRING {
	size_t num;							// ������ ���� ��
	char* p;							// ���ڰ� ����� �޸� ����
public:
	STRING();							// ����Ʈ ������
	STRING(const char*);				
	~STRING();							// �Ҹ���

	STRING(const STRING&);				// ���������
	STRING& operator=(const STRING&);	// �����Ҵ翬����			

	// 2022.11.07 �̵������� �ڵ�
	STRING(STRING&&);					// �̵�������, && = r-value reference
	STRING& operator=(STRING&&);		// �̵��Ҵ翬����

	// 2022.11.07 getter
	int getNum() const;

	friend std::ostream& operator<<(std::ostream&, const STRING&);
};