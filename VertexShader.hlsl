struct VS_INPUT
{
	float4 position : POSITION;
	float4 position1 : POSITION1;
	float3 color : COLOR;
	float3 color1 : COLOR1;
};

struct VS_OUTPUT
{
	float4 position : SV_POSITION;
	float3 color : COLOR;
	float3 color1 : COLOR1;
};

cbuffer constant : register(b0)
{
	float m_angle;
}

VS_OUTPUT vsmain(VS_INPUT input)
{
	VS_OUTPUT output = (VS_OUTPUT)0;

	output.position = lerp(input.position, input.position1, (sin(m_angle) + 1.0f) / 2.0f);
	output.color = input.color;
	output.color1 = input.color1;

	return output;
}