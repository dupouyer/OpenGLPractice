#version 330 core
out vec4 FragColor;

in vec4 pColor;
in vec2 texCoord;

uniform vec4 _color;

uniform sampler2D ourTexture;

void main()
{
    FragColor = texture(ourTexture,texCoord) * _color;
} 