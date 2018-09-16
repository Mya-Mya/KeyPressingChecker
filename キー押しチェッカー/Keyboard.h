#pragma once

template <typename _T>
class Singleton {

protected:
	Singleton() {}
	virtual ~Singleton() {}
	Singleton(const Singleton& r) {}
	Singleton& operator=(const Singleton& r) {}

public:
	static _T* Instance() {
		static _T inst;
		return &inst;
	};

};

class Keyboard : public Singleton<Keyboard> {

	friend Singleton< Keyboard >;

public:
	//�L�[�̓��͏�Ԃ��X�V
	void Update();

	//�����̃L�[�R�[�h�̃L�[�̓��͏�Ԃ�Ԃ�
	int Get(int KeyCode);

private:
	int m_Key[256];  // �L�[�̓��͏�Ԋi�[�p�ϐ�
};