#version 330 core
out vec4 FragColor;
in vec4 pColor;

uniform vec4 _color;

void main()
{
    FragColor = pColor * _color;
} 