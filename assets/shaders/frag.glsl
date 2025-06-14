#version 330 core

in vec2 texCoord;
in float dist;

out vec4 FragColor;

uniform sampler2D tex;

void main()
{
	float fogStart = 100.0;
	float fogEnd = 200.0;

	float fogFactor = clamp((fogEnd - dist) / (fogEnd - fogStart), 0.0, 1.0);

	vec3 fogColor = vec3(0.623, 0.734, 0.785);

	vec4 color = texture(tex, texCoord);
	if (color.a == 0) { discard; }
	FragColor = vec4(mix(fogColor, color.rgb, fogFactor), color.a);
}