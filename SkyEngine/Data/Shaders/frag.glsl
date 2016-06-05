#version 150 core
uniform sampler2D tex0;

in Vertex	{
	vec2 texCoord;
	vec4 colour;
} IN;

out vec4 gl_FragColor;
uniform bool colourON;
uniform bool isPlayer;
uniform float colourVar;

void main(void)	{
	vec4 colour = texture(tex0,IN.texCoord);
	if (colour.rgb == vec3(0.0,0.0,0.0)) discard;
	if (isPlayer == true)
	{
		if (colourON) gl_FragColor = colour + (IN.colour + vec4(1.5,-0.3,-0.3,0));
		else gl_FragColor = colour;
	}
	else
	{
		if (colourON) gl_FragColor = colour + (IN.colour + vec4(colourVar,0,0,0));
		else gl_FragColor = colour;
	}
}