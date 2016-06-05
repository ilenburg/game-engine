#version 150 core

uniform mat4 modelMatrix;
uniform mat4 viewMatrix;
uniform mat4 projMatrix;

in  vec3 position;
in  vec2 texCoord;
in  vec4 colour;

out Vertex	{
	vec2 texCoord;
	vec4 colour;
} OUT;

uniform bool pFixed;

void main(void)	{
	if (pFixed) gl_Position = (projMatrix * modelMatrix ) * vec4(position, 1.0);
	else gl_Position = (projMatrix * viewMatrix * modelMatrix) * vec4(position, 1.0);
	//gl_Position = (projMatrix * modelMatrix ) * vec4(position, 1.0);
	//gl_Position = vec4(position, 1.0);
	OUT.texCoord	= texCoord;
	OUT.colour	= colour;
}