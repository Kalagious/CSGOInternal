// Created with ReClass.NET 1.2 by KN4CK3R
class Vector3 {
public:
	float x, y, z;
};

class ClientPlayer
{
public:
	char pad_0000[160]; //0x0000
	Vector3 v_Position1; //0x00A0
	Vector3 v_Position2; //0x00AC
	char pad_00B8[60]; //0x00B8
	uint32_t i_Team; //0x00F4
	char pad_00F8[5]; //0x00F8
	bool b_Dormant; //0x00FD
	char pad_00FE[2]; //0x00FE
	int32_t i_Health; //0x0100
	char pad_0104[16]; //0x0104
	Vector3 v_Velocity; //0x0114
	char pad_0120[16]; //0x0120
	float f_Yaw; //0x0130
	char pad_0134[7960]; //0x0134
}; //Size: 0x204C
